/* Generated from modules.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: modules.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file modules.c
   unit: modules
   uses: chicken-syntax extras data-structures expand internal library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_chicken_2dsyntax_toplevel)
C_externimport void C_ccall C_chicken_2dsyntax_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_data_2dstructures_toplevel)
C_externimport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_expand_toplevel)
C_externimport void C_ccall C_expand_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_internal_toplevel)
C_externimport void C_ccall C_internal_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[277];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,108,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,19),40,100,101,108,101,116,101,32,120,32,108,115,116,32,116,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,6),40,103,51,52,57,41,0,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,10),40,103,51,51,57,32,120,32,114,41,0,0,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,15),40,102,111,108,100,114,51,51,52,32,103,51,51,53,41,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,21),40,102,105,108,116,101,114,45,109,97,112,32,112,114,101,100,32,108,115,116,41,0,0,0};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,15),40,109,111,100,117,108,101,45,110,97,109,101,32,120,41,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,25),40,109,111,100,117,108,101,45,117,110,100,101,102,105,110,101,100,45,108,105,115,116,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,32),40,115,101,116,45,109,111,100,117,108,101,45,117,110,100,101,102,105,110,101,100,45,108,105,115,116,33,32,120,32,121,41};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,24),40,35,35,115,121,115,35,109,111,100,117,108,101,45,101,120,112,111,114,116,115,32,109,41};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,57),40,109,97,107,101,45,109,111,100,117,108,101,32,108,105,98,32,101,120,112,108,105,115,116,32,118,101,120,112,111,114,116,115,32,115,101,120,112,111,114,116,115,32,105,101,120,112,111,114,116,115,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,40),40,35,35,115,121,115,35,114,101,103,105,115,116,101,114,45,109,111,100,117,108,101,45,97,108,105,97,115,32,97,108,105,97,115,32,110,97,109,101,41};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,7),40,97,54,48,49,48,41,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,7),40,97,54,48,50,55,41,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,7),40,97,54,48,51,51,41,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,57,52,52,32,103,57,53,54,41,0,0,0,0,0,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,42),40,35,35,115,121,115,35,119,105,116,104,45,109,111,100,117,108,101,45,97,108,105,97,115,101,115,32,98,105,110,100,105,110,103,115,32,116,104,117,110,107,41,0,0,0,0,0,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,8),40,103,57,56,56,32,97,41};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,13),40,108,111,111,112,32,110,32,100,111,110,101,41,0,0,0};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,36),40,35,35,115,121,115,35,114,101,115,111,108,118,101,45,109,111,100,117,108,101,45,110,97,109,101,32,110,97,109,101,32,108,111,99,41,0,0,0,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,31),40,35,35,115,121,115,35,102,105,110,100,45,109,111,100,117,108,101,32,110,97,109,101,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,9),40,103,49,48,50,54,32,109,41,0,0,0,0,0,0,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,25),40,35,35,115,121,115,35,115,119,105,116,99,104,45,109,111,100,117,108,101,32,109,111,100,41,0,0,0,0,0,0,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,7),40,103,49,48,53,57,41,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,7),40,103,49,48,52,51,41,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,48,52,50,32,103,49,48,52,57,41,0,0,0,0,0,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,35),40,35,35,115,121,115,35,97,100,100,45,116,111,45,101,120,112,111,114,116,45,108,105,115,116,32,109,111,100,32,101,120,112,115,41,0,0,0,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,48,55,53,32,103,49,48,56,55,41,0,0,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,45),40,35,35,115,121,115,35,97,100,100,45,116,111,45,101,120,112,111,114,116,47,114,101,110,97,109,101,45,108,105,115,116,32,109,111,100,32,114,101,110,97,109,101,115,41,0,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,54),40,35,35,115,121,115,35,116,111,112,108,101,118,101,108,45,100,101,102,105,110,105,116,105,111,110,45,104,111,111,107,32,115,121,109,32,114,101,110,97,109,101,100,32,101,120,112,111,114,116,101,100,63,41,0,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,36),40,35,35,115,121,115,35,114,101,103,105,115,116,101,114,45,109,101,116,97,45,101,120,112,114,101,115,115,105,111,110,32,101,120,112,41,0,0,0,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,30),40,99,104,101,99,107,45,102,111,114,45,114,101,100,101,102,32,115,121,109,32,101,110,118,32,115,101,110,118,41,0,0};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,31),40,35,35,115,121,115,35,114,101,103,105,115,116,101,114,45,101,120,112,111,114,116,32,115,121,109,32,109,111,100,41,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,42),40,35,35,115,121,115,35,114,101,103,105,115,116,101,114,45,115,121,110,116,97,120,45,101,120,112,111,114,116,32,115,121,109,32,109,111,100,32,118,97,108,41,0,0,0,0,0,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,11),40,97,54,54,51,56,32,120,32,121,41,0,0,0,0,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,40),40,35,35,115,121,115,35,117,110,114,101,103,105,115,116,101,114,45,115,121,110,116,97,120,45,101,120,112,111,114,116,32,115,121,109,32,109,111,100,41};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,47),40,35,35,115,121,115,35,114,101,103,105,115,116,101,114,45,109,111,100,117,108,101,32,110,97,109,101,32,108,105,98,32,101,120,112,108,105,115,116,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,9),40,103,49,50,54,50,32,101,41,0,0,0,0,0,0,0};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,50,54,49,32,103,49,50,54,56,41,0,0,0,0,0,0,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,11),40,108,112,32,115,101,32,115,101,50,41,0,0,0,0,0};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,22),40,108,111,111,112,32,115,101,115,32,108,97,115,116,45,115,101,32,115,101,50,41,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,15),40,109,101,114,103,101,45,115,101,32,115,101,115,42,41,0};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,15),40,103,49,51,57,52,32,115,101,120,112,111,114,116,41,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,52,52,49,32,103,49,52,53,51,41,0,0,0,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,9),40,108,111,111,112,32,115,100,41,0,0,0,0,0,0,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,51,56,56,32,103,49,52,48,48,41,0,0,0,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,51,53,53,32,103,49,51,54,55,41,0,0,0,0};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,50,57,55,32,103,49,51,48,57,41,0,0,0,0};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,108,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,7),40,97,55,50,52,48,41,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,13),40,97,55,50,52,54,32,46,32,116,109,112,41,0,0,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,9),40,97,55,50,51,52,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,53),40,35,35,115,121,115,35,99,111,109,112,105,108,101,100,45,109,111,100,117,108,101,45,114,101,103,105,115,116,114,97,116,105,111,110,32,109,111,100,32,99,111,109,112,105,108,101,45,109,111,100,101,41,0,0,0};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,12),40,103,49,53,51,54,32,115,101,120,112,41,0,0,0,0};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,12),40,103,49,53,52,54,32,110,101,120,112,41,0,0,0,0};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,53,52,53,32,103,49,53,53,50,41,0,0,0,0,0,0,0};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,53,51,53,32,103,49,53,52,50,41,0,0,0,0,0,0,0};
static C_char C_TLS li57[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,53,48,51,32,103,49,53,49,53,41,0,0,0,0};
static C_char C_TLS li58[] C_aligned={C_lihdr(0,0,10),40,97,56,48,50,53,32,115,101,41,0,0,0,0,0,0};
static C_char C_TLS li59[] C_aligned={C_lihdr(0,0,10),40,97,56,48,51,55,32,115,101,41,0,0,0,0,0,0};
static C_char C_TLS li60[] C_aligned={C_lihdr(0,0,75),40,35,35,115,121,115,35,114,101,103,105,115,116,101,114,45,99,111,109,112,105,108,101,100,45,109,111,100,117,108,101,32,110,97,109,101,32,108,105,98,32,105,101,120,112,111,114,116,115,32,118,101,120,112,111,114,116,115,32,115,101,120,112,111,114,116,115,32,46,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li61[] C_aligned={C_lihdr(0,0,10),40,103,49,54,48,52,32,115,101,41,0,0,0,0,0,0};
static C_char C_TLS li62[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,53,57,56,32,103,49,54,49,48,41,0,0,0,0};
static C_char C_TLS li63[] C_aligned={C_lihdr(0,0,53),40,35,35,115,121,115,35,114,101,103,105,115,116,101,114,45,99,111,114,101,45,109,111,100,117,108,101,32,110,97,109,101,32,108,105,98,32,118,101,120,112,111,114,116,115,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li64[] C_aligned={C_lihdr(0,0,54),40,35,35,115,121,115,35,114,101,103,105,115,116,101,114,45,112,114,105,109,105,116,105,118,101,45,109,111,100,117,108,101,32,110,97,109,101,32,118,101,120,112,111,114,116,115,32,46,32,114,101,115,116,41,0,0};
static C_char C_TLS li65[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li66[] C_aligned={C_lihdr(0,0,30),40,102,105,110,100,45,101,120,112,111,114,116,32,115,121,109,32,109,111,100,32,105,110,100,105,114,101,99,116,41,0,0};
static C_char C_TLS li67[] C_aligned={C_lihdr(0,0,12),40,102,95,57,51,49,50,32,46,32,95,41,0,0,0,0};
static C_char C_TLS li68[] C_aligned={C_lihdr(0,0,12),40,108,110,45,62,110,117,109,32,108,110,41,0,0,0,0};
static C_char C_TLS li69[] C_aligned={C_lihdr(0,0,10),40,103,49,55,56,51,32,108,110,41,0,0,0,0,0,0};
static C_char C_TLS li70[] C_aligned={C_lihdr(0,0,11),40,103,49,55,53,54,32,108,111,99,41,0,0,0,0,0};
static C_char C_TLS li71[] C_aligned={C_lihdr(0,0,9),40,103,49,56,54,54,32,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li72[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,56,54,53,32,103,49,56,55,50,41,0,0,0,0,0,0,0};
static C_char C_TLS li73[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,55,53,53,32,103,49,55,54,50,41,0,0,0,0,0,0,0};
static C_char C_TLS li74[] C_aligned={C_lihdr(0,0,15),40,103,49,54,56,56,32,105,100,46,108,111,99,115,41,0};
static C_char C_TLS li75[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,54,56,55,32,103,49,54,57,52,41,0,0,0,0,0,0,0};
static C_char C_TLS li76[] C_aligned={C_lihdr(0,0,9),40,108,112,32,108,111,99,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li77[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,55,50,51,32,103,49,55,51,53,41,0,0,0,0};
static C_char C_TLS li78[] C_aligned={C_lihdr(0,0,40),40,114,101,112,111,114,116,45,117,110,114,101,115,111,108,118,101,100,45,105,100,101,110,116,105,102,105,101,114,115,32,117,110,107,110,111,119,110,115,41};
static C_char C_TLS li79[] C_aligned={C_lihdr(0,0,7),40,103,49,57,53,56,41,0};
static C_char C_TLS li80[] C_aligned={C_lihdr(0,0,9),40,103,50,48,49,51,32,109,41,0,0,0,0,0,0,0};
static C_char C_TLS li81[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,48,49,50,32,103,50,48,49,57,41,0,0,0,0,0,0,0};
static C_char C_TLS li82[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,57,55,55,32,103,49,57,56,57,41,0,0,0,0};
static C_char C_TLS li83[] C_aligned={C_lihdr(0,0,13),40,119,97,114,110,32,109,115,103,32,105,100,41,0,0,0};
static C_char C_TLS li84[] C_aligned={C_lihdr(0,0,9),40,103,49,50,50,52,32,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li85[] C_aligned={C_lihdr(0,0,9),40,103,49,50,51,49,32,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li86[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,50,32,105,101,120,112,111,114,116,115,41};
static C_char C_TLS li87[] C_aligned={C_lihdr(0,0,14),40,108,111,111,112,32,101,120,112,111,114,116,115,41,0,0};
static C_char C_TLS li88[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,49,57,53,55,32,103,49,57,54,52,41,0,0,0,0,0,0,0};
static C_char C_TLS li89[] C_aligned={C_lihdr(0,0,10),40,102,97,105,108,32,109,115,103,41,0,0,0,0,0,0};
static C_char C_TLS li90[] C_aligned={C_lihdr(0,0,11),40,105,100,45,115,116,114,105,110,103,41,0,0,0,0,0};
static C_char C_TLS li91[] C_aligned={C_lihdr(0,0,12),40,103,49,57,52,56,32,116,121,112,101,41,0,0,0,0};
static C_char C_TLS li92[] C_aligned={C_lihdr(0,0,9),40,108,111,111,112,32,120,108,41,0,0,0,0,0,0,0};
static C_char C_TLS li93[] C_aligned={C_lihdr(0,0,9),40,108,111,111,112,32,109,101,41,0,0,0,0,0,0,0};
static C_char C_TLS li94[] C_aligned={C_lihdr(0,0,11),40,108,111,111,112,32,115,121,109,115,41,0,0,0,0,0};
static C_char C_TLS li95[] C_aligned={C_lihdr(0,0,34),40,35,35,115,121,115,35,102,105,110,97,108,105,122,101,45,109,111,100,117,108,101,32,109,111,100,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li96[] C_aligned={C_lihdr(0,0,7),40,97,57,51,51,48,41,0};
static C_char C_TLS li97[] C_aligned={C_lihdr(0,0,7),40,97,57,51,56,54,41,0};
static C_char C_TLS li98[] C_aligned={C_lihdr(0,0,7),40,97,57,51,57,50,41,0};
static C_char C_TLS li99[] C_aligned={C_lihdr(0,0,30),40,35,35,115,121,115,35,119,105,116,104,45,101,110,118,105,114,111,110,109,101,110,116,32,116,104,117,110,107,41,0,0};
static C_char C_TLS li100[] C_aligned={C_lihdr(0,0,7),40,97,57,52,52,49,41,0};
static C_char C_TLS li101[] C_aligned={C_lihdr(0,0,7),40,97,57,52,52,54,41,0};
static C_char C_TLS li102[] C_aligned={C_lihdr(0,0,7),40,97,57,52,53,53,41,0};
static C_char C_TLS li103[] C_aligned={C_lihdr(0,0,7),40,97,57,52,51,53,41,0};
static C_char C_TLS li104[] C_aligned={C_lihdr(0,0,33),40,35,35,115,121,115,35,105,109,112,111,114,116,45,108,105,98,114,97,114,121,45,104,111,111,107,32,109,110,97,109,101,41,0,0,0,0,0,0,0};
static C_char C_TLS li105[] C_aligned={C_lihdr(0,0,36),40,102,105,110,100,45,109,111,100,117,108,101,47,105,109,112,111,114,116,45,108,105,98,114,97,114,121,32,108,105,98,32,108,111,99,41,0,0,0,0};
static C_char C_TLS li106[] C_aligned={C_lihdr(0,0,17),40,119,97,114,110,32,109,115,103,32,109,111,100,32,105,100,41,0,0,0,0,0,0,0};
static C_char C_TLS li107[] C_aligned={C_lihdr(0,0,9),40,116,111,115,116,114,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li108[] C_aligned={C_lihdr(0,0,7),40,103,50,49,55,52,41,0};
static C_char C_TLS li109[] C_aligned={C_lihdr(0,0,9),40,103,50,49,53,54,32,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li110[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,49,53,48,32,103,50,49,54,50,41,0,0,0,0};
static C_char C_TLS li111[] C_aligned={C_lihdr(0,0,23),40,101,120,112,111,114,116,45,114,101,110,97,109,101,32,109,111,100,32,108,115,116,41,0};
static C_char C_TLS li112[] C_aligned={C_lihdr(0,0,21),40,109,111,100,117,108,101,45,105,109,112,111,114,116,115,32,110,97,109,101,41,0,0,0};
static C_char C_TLS li113[] C_aligned={C_lihdr(0,0,7),40,97,57,55,52,50,41,0};
static C_char C_TLS li114[] C_aligned={C_lihdr(0,0,10),40,103,50,50,52,49,32,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li115[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,50,52,48,32,103,50,50,52,55,41,0,0,0,0,0,0,0};
static C_char C_TLS li116[] C_aligned={C_lihdr(0,0,9),40,103,50,50,54,49,32,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li117[] C_aligned={C_lihdr(0,0,9),40,103,50,50,54,53,32,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li118[] C_aligned={C_lihdr(0,0,22),40,108,111,111,112,32,105,100,115,32,118,32,115,32,109,105,115,115,105,110,103,41,0,0};
static C_char C_TLS li119[] C_aligned={C_lihdr(0,0,60),40,97,57,55,53,50,32,110,97,109,101,50,50,48,50,32,108,105,98,50,50,48,52,32,115,112,101,99,50,50,48,54,32,105,109,112,118,50,50,48,56,32,105,109,112,115,50,50,49,48,32,105,109,112,105,50,50,49,50,41,0,0,0,0};
static C_char C_TLS li120[] C_aligned={C_lihdr(0,0,7),40,97,57,56,57,50,41,0};
static C_char C_TLS li121[] C_aligned={C_lihdr(0,0,10),40,103,50,51,49,57,32,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li122[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,51,49,56,32,103,50,51,50,53,41,0,0,0,0,0,0,0};
static C_char C_TLS li123[] C_aligned={C_lihdr(0,0,10),40,103,50,51,51,57,32,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li124[] C_aligned={C_lihdr(0,0,18),40,108,111,111,112,115,32,105,109,112,115,32,115,32,105,100,115,41,0,0,0,0,0,0};
static C_char C_TLS li125[] C_aligned={C_lihdr(0,0,10),40,103,50,51,52,52,32,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li126[] C_aligned={C_lihdr(0,0,18),40,108,111,111,112,118,32,105,109,112,118,32,118,32,105,100,115,41,0,0,0,0,0,0};
static C_char C_TLS li127[] C_aligned={C_lihdr(0,0,60),40,97,57,57,48,50,32,110,97,109,101,50,50,55,50,32,108,105,98,50,50,55,52,32,115,112,101,99,50,50,55,54,32,105,109,112,118,50,50,55,56,32,105,109,112,115,50,50,56,48,32,105,109,112,105,50,50,56,50,41,0,0,0,0};
static C_char C_TLS li128[] C_aligned={C_lihdr(0,0,8),40,97,49,48,48,55,53,41};
static C_char C_TLS li129[] C_aligned={C_lihdr(0,0,10),40,103,50,51,57,56,32,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li130[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,51,57,55,32,103,50,52,48,52,41,0,0,0,0,0,0,0};
static C_char C_TLS li131[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,52,49,48,32,103,50,52,50,50,41,0,0,0,0};
static C_char C_TLS li132[] C_aligned={C_lihdr(0,0,9),40,103,50,52,52,52,32,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li133[] C_aligned={C_lihdr(0,0,18),40,108,111,111,112,115,32,105,109,112,115,32,115,32,105,100,115,41,0,0,0,0,0,0};
static C_char C_TLS li134[] C_aligned={C_lihdr(0,0,9),40,103,50,52,52,57,32,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li135[] C_aligned={C_lihdr(0,0,18),40,108,111,111,112,118,32,105,109,112,118,32,118,32,105,100,115,41,0,0,0,0,0,0};
static C_char C_TLS li136[] C_aligned={C_lihdr(0,0,61),40,97,49,48,48,56,53,32,110,97,109,101,50,51,53,49,32,108,105,98,50,51,53,51,32,115,112,101,99,50,51,53,53,32,105,109,112,118,50,51,53,55,32,105,109,112,115,50,51,53,57,32,105,109,112,105,50,51,54,49,41,0,0,0};
static C_char C_TLS li137[] C_aligned={C_lihdr(0,0,8),40,97,49,48,51,50,53,41};
static C_char C_TLS li138[] C_aligned={C_lihdr(0,0,12),40,114,101,110,97,109,101,32,105,109,112,41,0,0,0,0};
static C_char C_TLS li139[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,53,49,53,32,103,50,53,50,55,41,0,0,0,0};
static C_char C_TLS li140[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,52,56,57,32,103,50,53,48,49,41,0,0,0,0};
static C_char C_TLS li141[] C_aligned={C_lihdr(0,0,61),40,97,49,48,51,51,53,32,110,97,109,101,50,52,53,54,32,108,105,98,50,52,53,56,32,115,112,101,99,50,52,54,48,32,105,109,112,118,50,52,54,50,32,105,109,112,115,50,52,54,52,32,105,109,112,105,50,52,54,54,41,0,0,0};
static C_char C_TLS li142[] C_aligned={C_lihdr(0,0,9),40,111,117,116,101,114,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li143[] C_aligned={C_lihdr(0,0,9),40,97,57,54,52,51,32,107,41,0,0,0,0,0,0,0};
static C_char C_TLS li144[] C_aligned={C_lihdr(0,0,34),40,35,35,115,121,115,35,100,101,99,111,109,112,111,115,101,45,105,109,112,111,114,116,32,120,32,114,32,99,32,108,111,99,41,0,0,0,0,0,0};
static C_char C_TLS li145[] C_aligned={C_lihdr(0,0,8),40,97,49,48,52,57,48,41};
static C_char C_TLS li146[] C_aligned={C_lihdr(0,0,50),40,97,49,48,52,57,54,32,110,97,109,101,50,53,54,56,32,95,50,53,55,48,32,115,112,101,99,50,53,55,50,32,118,50,53,55,52,32,115,50,53,55,54,32,105,50,53,55,56,41,0,0,0,0,0,0};
static C_char C_TLS li147[] C_aligned={C_lihdr(0,0,9),40,103,50,53,53,56,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li148[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,53,53,55,32,103,50,53,54,52,41,0,0,0,0,0,0,0};
static C_char C_TLS li149[] C_aligned={C_lihdr(0,0,65),40,35,35,115,121,115,35,101,120,112,97,110,100,45,105,109,112,111,114,116,32,120,32,114,32,99,32,105,109,112,111,114,116,45,101,110,118,32,109,97,99,114,111,45,101,110,118,32,109,101,116,97,63,32,114,101,101,120,112,63,32,108,111,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li150[] C_aligned={C_lihdr(0,0,11),40,103,50,54,49,57,32,105,109,112,41,0,0,0,0,0};
static C_char C_TLS li151[] C_aligned={C_lihdr(0,0,11),40,103,50,54,50,57,32,105,109,112,41,0,0,0,0,0};
static C_char C_TLS li152[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,55,48,48,32,103,50,55,49,50,41,0,0,0,0};
static C_char C_TLS li153[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,54,55,52,32,103,50,54,56,54,41,0,0,0,0};
static C_char C_TLS li154[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,55,53,52,32,103,50,55,54,54,41,0,0,0,0};
static C_char C_TLS li155[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,55,50,56,32,103,50,55,52,48,41,0,0,0,0};
static C_char C_TLS li156[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,54,50,56,32,103,50,54,51,53,41,0,0,0,0,0,0,0};
static C_char C_TLS li157[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,54,49,56,32,103,50,54,50,53,41,0,0,0,0,0,0,0};
static C_char C_TLS li158[] C_aligned={C_lihdr(0,0,69),40,35,35,115,121,115,35,105,109,112,111,114,116,32,115,112,101,99,32,118,115,118,32,118,115,115,32,118,115,105,32,105,109,112,111,114,116,45,101,110,118,32,109,97,99,114,111,45,101,110,118,32,109,101,116,97,63,32,114,101,101,120,112,63,32,108,111,99,41,0,0,0};
static C_char C_TLS li159[] C_aligned={C_lihdr(0,0,26),40,109,111,100,117,108,101,45,114,101,110,97,109,101,32,115,121,109,32,112,114,101,102,105,120,41,0,0,0,0,0,0};
static C_char C_TLS li160[] C_aligned={C_lihdr(0,0,9),40,103,49,49,54,54,32,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li161[] C_aligned={C_lihdr(0,0,11),40,103,50,56,49,49,32,109,111,100,41,0,0,0,0,0};
static C_char C_TLS li162[] C_aligned={C_lihdr(0,0,13),40,109,114,101,110,97,109,101,32,115,121,109,41,0,0,0};
static C_char C_TLS li163[] C_aligned={C_lihdr(0,0,9),40,103,50,56,50,50,32,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li164[] C_aligned={C_lihdr(0,0,42),40,35,35,115,121,115,35,97,108,105,97,115,45,103,108,111,98,97,108,45,104,111,111,107,32,115,121,109,32,97,115,115,105,103,110,32,119,104,101,114,101,41,0,0,0,0,0,0};
static C_char C_TLS li165[] C_aligned={C_lihdr(0,0,10),40,101,114,114,32,97,114,103,115,41,0,0,0,0,0,0};
static C_char C_TLS li166[] C_aligned={C_lihdr(0,0,12),40,105,102,97,99,101,32,110,97,109,101,41,0,0,0,0};
static C_char C_TLS li167[] C_aligned={C_lihdr(0,0,11),40,108,111,111,112,50,32,108,115,116,41,0,0,0,0,0};
static C_char C_TLS li168[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,120,112,115,41,0,0,0,0,0,0};
static C_char C_TLS li169[] C_aligned={C_lihdr(0,0,33),40,35,35,115,121,115,35,118,97,108,105,100,97,116,101,45,101,120,112,111,114,116,115,32,101,120,112,115,32,108,111,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li170[] C_aligned={C_lihdr(0,0,46),40,35,35,115,121,115,35,114,101,103,105,115,116,101,114,45,102,117,110,99,116,111,114,32,110,97,109,101,32,102,97,114,103,115,32,102,101,120,112,115,32,98,111,100,121,41,0,0};
static C_char C_TLS li171[] C_aligned={C_lihdr(0,0,10),40,101,114,114,32,97,114,103,115,41,0,0,0,0,0,0};
static C_char C_TLS li172[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,57,48,48,32,103,50,57,49,50,41,0,0,0,0};
static C_char C_TLS li173[] C_aligned={C_lihdr(0,0,6),40,109,101,114,114,41,0,0};
static C_char C_TLS li174[] C_aligned={C_lihdr(0,0,11),40,108,111,111,112,50,32,102,97,115,41,0,0,0,0,0};
static C_char C_TLS li175[] C_aligned={C_lihdr(0,0,13),40,108,111,111,112,32,97,115,32,102,97,115,41,0,0,0};
static C_char C_TLS li176[] C_aligned={C_lihdr(0,0,43),40,35,35,115,121,115,35,105,110,115,116,97,110,116,105,97,116,101,45,102,117,110,99,116,111,114,32,110,97,109,101,32,102,110,97,109,101,32,97,114,103,115,41,0,0,0,0,0};
static C_char C_TLS li177[] C_aligned={C_lihdr(0,0,11),40,103,50,57,54,49,32,101,120,112,41,0,0,0,0,0};
static C_char C_TLS li178[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,57,56,50,32,103,50,57,57,52,41,0,0,0,0};
static C_char C_TLS li179[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,57,54,48,32,103,50,57,54,55,41,0,0,0,0,0,0,0};
static C_char C_TLS li180[] C_aligned={C_lihdr(0,0,46),40,109,97,116,99,104,45,102,117,110,99,116,111,114,45,97,114,103,117,109,101,110,116,32,110,97,109,101,32,109,110,97,109,101,32,101,120,112,115,32,102,110,97,109,101,41,0,0};
static C_char C_TLS li181[] C_aligned={C_lihdr(0,0,48),40,99,104,105,99,107,101,110,46,109,111,100,117,108,101,35,109,111,100,117,108,101,45,101,110,118,105,114,111,110,109,101,110,116,32,109,110,97,109,101,32,46,32,114,101,115,116,41};
static C_char C_TLS li182[] C_aligned={C_lihdr(0,0,7),40,103,51,52,56,49,41,0};
static C_char C_TLS li183[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,52,55,53,32,103,51,52,56,55,41,0,0,0,0};
static C_char C_TLS li184[] C_aligned={C_lihdr(0,0,7),40,103,51,52,52,51,41,0};
static C_char C_TLS li185[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,52,51,55,32,103,51,52,52,57,41,0,0,0,0};
static C_char C_TLS li186[] C_aligned={C_lihdr(0,0,7),40,103,51,52,48,53,41,0};
static C_char C_TLS li187[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,51,57,57,32,103,51,52,49,49,41,0,0,0,0};
static C_char C_TLS li188[] C_aligned={C_lihdr(0,0,7),40,103,51,51,54,55,41,0};
static C_char C_TLS li189[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,51,54,49,32,103,51,51,55,51,41,0,0,0,0};
static C_char C_TLS li190[] C_aligned={C_lihdr(0,0,7),40,103,51,51,50,57,41,0};
static C_char C_TLS li191[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,51,50,51,32,103,51,51,51,53,41,0,0,0,0};
static C_char C_TLS li192[] C_aligned={C_lihdr(0,0,7),40,103,51,50,57,49,41,0};
static C_char C_TLS li193[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,50,56,53,32,103,51,50,57,55,41,0,0,0,0};
static C_char C_TLS li194[] C_aligned={C_lihdr(0,0,7),40,103,51,50,53,51,41,0};
static C_char C_TLS li195[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,50,52,55,32,103,51,50,53,57,41,0,0,0,0};
static C_char C_TLS li196[] C_aligned={C_lihdr(0,0,7),40,103,51,50,49,53,41,0};
static C_char C_TLS li197[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,50,48,57,32,103,51,50,50,49,41,0,0,0,0};
static C_char C_TLS li198[] C_aligned={C_lihdr(0,0,7),40,103,51,49,55,55,41,0};
static C_char C_TLS li199[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,49,55,49,32,103,51,49,56,51,41,0,0,0,0};
static C_char C_TLS li200[] C_aligned={C_lihdr(0,0,7),40,103,51,49,51,57,41,0};
static C_char C_TLS li201[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,49,51,51,32,103,51,49,52,53,41,0,0,0,0};
static C_char C_TLS li202[] C_aligned={C_lihdr(0,0,7),40,103,51,49,48,49,41,0};
static C_char C_TLS li203[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,48,57,53,32,103,51,49,48,55,41,0,0,0,0};
static C_char C_TLS li204[] C_aligned={C_lihdr(0,0,7),40,103,51,48,54,51,41,0};
static C_char C_TLS li205[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,48,53,55,32,103,51,48,54,57,41,0,0,0,0};
static C_char C_TLS li206[] C_aligned={C_lihdr(0,0,7),40,103,51,48,50,53,41,0};
static C_char C_TLS li207[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,48,49,57,32,103,51,48,51,49,41,0,0,0,0};
static C_char C_TLS li208[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f14085)
static void C_ccall f14085(C_word c,C_word *av) C_noret;
C_noret_decl(f14089)
static void C_ccall f14089(C_word c,C_word *av) C_noret;
C_noret_decl(f_10024)
static void C_fcall f_10024(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10036)
static void C_ccall f_10036(C_word c,C_word *av) C_noret;
C_noret_decl(f_10068)
static void C_ccall f_10068(C_word c,C_word *av) C_noret;
C_noret_decl(f_10071)
static void C_ccall f_10071(C_word c,C_word *av) C_noret;
C_noret_decl(f_10076)
static void C_ccall f_10076(C_word c,C_word *av) C_noret;
C_noret_decl(f_10086)
static void C_ccall f_10086(C_word c,C_word *av) C_noret;
C_noret_decl(f_10090)
static void C_ccall f_10090(C_word c,C_word *av) C_noret;
C_noret_decl(f_10095)
static void C_fcall f_10095(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_10107)
static void C_fcall f_10107(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_10115)
static void C_fcall f_10115(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10128)
static void C_ccall f_10128(C_word c,C_word *av) C_noret;
C_noret_decl(f_10134)
static void C_ccall f_10134(C_word c,C_word *av) C_noret;
C_noret_decl(f_10147)
static void C_fcall f_10147(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10157)
static void C_ccall f_10157(C_word c,C_word *av) C_noret;
C_noret_decl(f_10170)
static void C_fcall f_10170(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10209)
static void C_fcall f_10209(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10225)
static void C_ccall f_10225(C_word c,C_word *av) C_noret;
C_noret_decl(f_10262)
static void C_fcall f_10262(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10278)
static void C_ccall f_10278(C_word c,C_word *av) C_noret;
C_noret_decl(f_10318)
static void C_ccall f_10318(C_word c,C_word *av) C_noret;
C_noret_decl(f_10321)
static void C_ccall f_10321(C_word c,C_word *av) C_noret;
C_noret_decl(f_10326)
static void C_ccall f_10326(C_word c,C_word *av) C_noret;
C_noret_decl(f_10336)
static void C_ccall f_10336(C_word c,C_word *av) C_noret;
C_noret_decl(f_10340)
static void C_ccall f_10340(C_word c,C_word *av) C_noret;
C_noret_decl(f_10342)
static void C_fcall f_10342(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10350)
static void C_ccall f_10350(C_word c,C_word *av) C_noret;
C_noret_decl(f_10356)
static void C_ccall f_10356(C_word c,C_word *av) C_noret;
C_noret_decl(f_10360)
static void C_ccall f_10360(C_word c,C_word *av) C_noret;
C_noret_decl(f_10364)
static void C_ccall f_10364(C_word c,C_word *av) C_noret;
C_noret_decl(f_10385)
static void C_ccall f_10385(C_word c,C_word *av) C_noret;
C_noret_decl(f_10395)
static void C_ccall f_10395(C_word c,C_word *av) C_noret;
C_noret_decl(f_10397)
static void C_fcall f_10397(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10422)
static void C_ccall f_10422(C_word c,C_word *av) C_noret;
C_noret_decl(f_10431)
static void C_fcall f_10431(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10456)
static void C_ccall f_10456(C_word c,C_word *av) C_noret;
C_noret_decl(f_10474)
static void C_ccall f_10474(C_word c,C_word *av) C_noret;
C_noret_decl(f_10480)
static void C_ccall f_10480(C_word c,C_word *av) C_noret;
C_noret_decl(f_10484)
static void C_ccall f_10484(C_word c,C_word *av) C_noret;
C_noret_decl(f_10485)
static void C_fcall f_10485(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10491)
static void C_ccall f_10491(C_word c,C_word *av) C_noret;
C_noret_decl(f_10497)
static void C_ccall f_10497(C_word c,C_word *av) C_noret;
C_noret_decl(f_10519)
static void C_ccall f_10519(C_word c,C_word *av) C_noret;
C_noret_decl(f_10521)
static void C_fcall f_10521(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10531)
static void C_ccall f_10531(C_word c,C_word *av) C_noret;
C_noret_decl(f_10544)
static void C_ccall f_10544(C_word c,C_word *av) C_noret;
C_noret_decl(f_10548)
static void C_ccall f_10548(C_word c,C_word *av) C_noret;
C_noret_decl(f_10551)
static void C_ccall f_10551(C_word c,C_word *av) C_noret;
C_noret_decl(f_10561)
static void C_fcall f_10561(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10568)
static void C_ccall f_10568(C_word c,C_word *av) C_noret;
C_noret_decl(f_10599)
static void C_ccall f_10599(C_word c,C_word *av) C_noret;
C_noret_decl(f_10605)
static void C_ccall f_10605(C_word c,C_word *av) C_noret;
C_noret_decl(f_10606)
static void C_fcall f_10606(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10613)
static void C_ccall f_10613(C_word c,C_word *av) C_noret;
C_noret_decl(f_10646)
static void C_ccall f_10646(C_word c,C_word *av) C_noret;
C_noret_decl(f_10652)
static void C_ccall f_10652(C_word c,C_word *av) C_noret;
C_noret_decl(f_10655)
static void C_fcall f_10655(C_word t0,C_word t1) C_noret;
C_noret_decl(f_10658)
static void C_ccall f_10658(C_word c,C_word *av) C_noret;
C_noret_decl(f_10665)
static void C_ccall f_10665(C_word c,C_word *av) C_noret;
C_noret_decl(f_10669)
static void C_ccall f_10669(C_word c,C_word *av) C_noret;
C_noret_decl(f_10673)
static void C_ccall f_10673(C_word c,C_word *av) C_noret;
C_noret_decl(f_10677)
static void C_ccall f_10677(C_word c,C_word *av) C_noret;
C_noret_decl(f_10680)
static void C_ccall f_10680(C_word c,C_word *av) C_noret;
C_noret_decl(f_10686)
static void C_ccall f_10686(C_word c,C_word *av) C_noret;
C_noret_decl(f_10689)
static void C_ccall f_10689(C_word c,C_word *av) C_noret;
C_noret_decl(f_10696)
static void C_ccall f_10696(C_word c,C_word *av) C_noret;
C_noret_decl(f_10706)
static void C_ccall f_10706(C_word c,C_word *av) C_noret;
C_noret_decl(f_10713)
static void C_ccall f_10713(C_word c,C_word *av) C_noret;
C_noret_decl(f_10724)
static void C_ccall f_10724(C_word c,C_word *av) C_noret;
C_noret_decl(f_10731)
static void C_ccall f_10731(C_word c,C_word *av) C_noret;
C_noret_decl(f_10733)
static void C_fcall f_10733(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10767)
static void C_fcall f_10767(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10803)
static void C_ccall f_10803(C_word c,C_word *av) C_noret;
C_noret_decl(f_10814)
static void C_ccall f_10814(C_word c,C_word *av) C_noret;
C_noret_decl(f_10828)
static void C_ccall f_10828(C_word c,C_word *av) C_noret;
C_noret_decl(f_10835)
static void C_ccall f_10835(C_word c,C_word *av) C_noret;
C_noret_decl(f_10837)
static void C_fcall f_10837(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10871)
static void C_fcall f_10871(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10911)
static void C_fcall f_10911(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10921)
static void C_ccall f_10921(C_word c,C_word *av) C_noret;
C_noret_decl(f_10934)
static void C_fcall f_10934(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10944)
static void C_ccall f_10944(C_word c,C_word *av) C_noret;
C_noret_decl(f_10965)
static void C_ccall f_10965(C_word c,C_word *av) C_noret;
C_noret_decl(f_10980)
static void C_ccall f_10980(C_word c,C_word *av) C_noret;
C_noret_decl(f_10990)
static void C_fcall f_10990(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10998)
static void C_ccall f_10998(C_word c,C_word *av) C_noret;
C_noret_decl(f_11008)
static void C_ccall f_11008(C_word c,C_word *av) C_noret;
C_noret_decl(f_11011)
static void C_fcall f_11011(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11015)
static void C_ccall f_11015(C_word c,C_word *av) C_noret;
C_noret_decl(f_11019)
static void C_fcall f_11019(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11026)
static void C_ccall f_11026(C_word c,C_word *av) C_noret;
C_noret_decl(f_11054)
static void C_fcall f_11054(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11080)
static void C_ccall f_11080(C_word c,C_word *av) C_noret;
C_noret_decl(f_11082)
static void C_ccall f_11082(C_word c,C_word *av) C_noret;
C_noret_decl(f_11085)
static void C_fcall f_11085(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11091)
static void C_fcall f_11091(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11132)
static void C_fcall f_11132(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11164)
static void C_ccall f_11164(C_word c,C_word *av) C_noret;
C_noret_decl(f_11190)
static void C_ccall f_11190(C_word c,C_word *av) C_noret;
C_noret_decl(f_11211)
static void C_ccall f_11211(C_word c,C_word *av) C_noret;
C_noret_decl(f_11215)
static void C_ccall f_11215(C_word c,C_word *av) C_noret;
C_noret_decl(f_11241)
static void C_fcall f_11241(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11255)
static void C_ccall f_11255(C_word c,C_word *av) C_noret;
C_noret_decl(f_11297)
static void C_ccall f_11297(C_word c,C_word *av) C_noret;
C_noret_decl(f_11313)
static void C_ccall f_11313(C_word c,C_word *av) C_noret;
C_noret_decl(f_11321)
static void C_fcall f_11321(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11328)
static void C_ccall f_11328(C_word c,C_word *av) C_noret;
C_noret_decl(f_11338)
static void C_fcall f_11338(C_word t0,C_word t1) C_noret;
C_noret_decl(f_11360)
static void C_ccall f_11360(C_word c,C_word *av) C_noret;
C_noret_decl(f_11362)
static void C_fcall f_11362(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11401)
static void C_ccall f_11401(C_word c,C_word *av) C_noret;
C_noret_decl(f_11422)
static void C_fcall f_11422(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_11434)
static void C_fcall f_11434(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11457)
static void C_ccall f_11457(C_word c,C_word *av) C_noret;
C_noret_decl(f_11460)
static void C_ccall f_11460(C_word c,C_word *av) C_noret;
C_noret_decl(f_11471)
static void C_ccall f_11471(C_word c,C_word *av) C_noret;
C_noret_decl(f_11477)
static void C_ccall f_11477(C_word c,C_word *av) C_noret;
C_noret_decl(f_11509)
static void C_ccall f_11509(C_word c,C_word *av) C_noret;
C_noret_decl(f_11512)
static void C_ccall f_11512(C_word c,C_word *av) C_noret;
C_noret_decl(f_11523)
static void C_ccall f_11523(C_word c,C_word *av) C_noret;
C_noret_decl(f_11539)
static void C_fcall f_11539(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_11543)
static void C_ccall f_11543(C_word c,C_word *av) C_noret;
C_noret_decl(f_11550)
static void C_fcall f_11550(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11563)
static void C_fcall f_11563(C_word t0,C_word t1) C_noret;
C_noret_decl(f_11590)
static void C_ccall f_11590(C_word c,C_word *av) C_noret;
C_noret_decl(f_11603)
static void C_ccall f_11603(C_word c,C_word *av) C_noret;
C_noret_decl(f_11607)
static void C_ccall f_11607(C_word c,C_word *av) C_noret;
C_noret_decl(f_11611)
static void C_ccall f_11611(C_word c,C_word *av) C_noret;
C_noret_decl(f_11615)
static void C_ccall f_11615(C_word c,C_word *av) C_noret;
C_noret_decl(f_11629)
static void C_ccall f_11629(C_word c,C_word *av) C_noret;
C_noret_decl(f_11635)
static void C_ccall f_11635(C_word c,C_word *av) C_noret;
C_noret_decl(f_11637)
static void C_fcall f_11637(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11662)
static void C_ccall f_11662(C_word c,C_word *av) C_noret;
C_noret_decl(f_11671)
static void C_fcall f_11671(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11681)
static void C_ccall f_11681(C_word c,C_word *av) C_noret;
C_noret_decl(f_11696)
static void C_ccall f_11696(C_word c,C_word *av) C_noret;
C_noret_decl(f_11699)
static void C_ccall f_11699(C_word c,C_word *av) C_noret;
C_noret_decl(f_11702)
static void C_ccall f_11702(C_word c,C_word *av) C_noret;
C_noret_decl(f_11705)
static void C_ccall f_11705(C_word c,C_word *av) C_noret;
C_noret_decl(f_11708)
static void C_ccall f_11708(C_word c,C_word *av) C_noret;
C_noret_decl(f_11711)
static void C_ccall f_11711(C_word c,C_word *av) C_noret;
C_noret_decl(f_11714)
static void C_ccall f_11714(C_word c,C_word *av) C_noret;
C_noret_decl(f_11717)
static void C_ccall f_11717(C_word c,C_word *av) C_noret;
C_noret_decl(f_11720)
static void C_ccall f_11720(C_word c,C_word *av) C_noret;
C_noret_decl(f_11723)
static void C_ccall f_11723(C_word c,C_word *av) C_noret;
C_noret_decl(f_11726)
static void C_ccall f_11726(C_word c,C_word *av) C_noret;
C_noret_decl(f_11729)
static void C_ccall f_11729(C_word c,C_word *av) C_noret;
C_noret_decl(f_11732)
static void C_ccall f_11732(C_word c,C_word *av) C_noret;
C_noret_decl(f_11735)
static void C_ccall f_11735(C_word c,C_word *av) C_noret;
C_noret_decl(f_11738)
static void C_ccall f_11738(C_word c,C_word *av) C_noret;
C_noret_decl(f_11741)
static void C_ccall f_11741(C_word c,C_word *av) C_noret;
C_noret_decl(f_11744)
static void C_ccall f_11744(C_word c,C_word *av) C_noret;
C_noret_decl(f_11747)
static void C_ccall f_11747(C_word c,C_word *av) C_noret;
C_noret_decl(f_11750)
static void C_ccall f_11750(C_word c,C_word *av) C_noret;
C_noret_decl(f_11753)
static void C_ccall f_11753(C_word c,C_word *av) C_noret;
C_noret_decl(f_11756)
static void C_ccall f_11756(C_word c,C_word *av) C_noret;
C_noret_decl(f_11759)
static void C_ccall f_11759(C_word c,C_word *av) C_noret;
C_noret_decl(f_11762)
static void C_ccall f_11762(C_word c,C_word *av) C_noret;
C_noret_decl(f_11765)
static void C_ccall f_11765(C_word c,C_word *av) C_noret;
C_noret_decl(f_11768)
static void C_ccall f_11768(C_word c,C_word *av) C_noret;
C_noret_decl(f_11771)
static void C_ccall f_11771(C_word c,C_word *av) C_noret;
C_noret_decl(f_11774)
static void C_ccall f_11774(C_word c,C_word *av) C_noret;
C_noret_decl(f_11777)
static void C_ccall f_11777(C_word c,C_word *av) C_noret;
C_noret_decl(f_11779)
static void C_ccall f_11779(C_word c,C_word *av) C_noret;
C_noret_decl(f_11786)
static void C_ccall f_11786(C_word c,C_word *av) C_noret;
C_noret_decl(f_11815)
static void C_ccall f_11815(C_word c,C_word *av) C_noret;
C_noret_decl(f_11818)
static void C_ccall f_11818(C_word c,C_word *av) C_noret;
C_noret_decl(f_11825)
static C_word C_fcall f_11825(C_word t0,C_word t1);
C_noret_decl(f_11837)
static void C_fcall f_11837(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11872)
static void C_ccall f_11872(C_word c,C_word *av) C_noret;
C_noret_decl(f_11879)
static C_word C_fcall f_11879(C_word t0,C_word t1);
C_noret_decl(f_11891)
static void C_fcall f_11891(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11926)
static void C_ccall f_11926(C_word c,C_word *av) C_noret;
C_noret_decl(f_11933)
static C_word C_fcall f_11933(C_word t0,C_word t1);
C_noret_decl(f_11945)
static void C_fcall f_11945(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11980)
static void C_ccall f_11980(C_word c,C_word *av) C_noret;
C_noret_decl(f_11987)
static C_word C_fcall f_11987(C_word t0,C_word t1);
C_noret_decl(f_11999)
static void C_fcall f_11999(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12034)
static void C_ccall f_12034(C_word c,C_word *av) C_noret;
C_noret_decl(f_12041)
static C_word C_fcall f_12041(C_word t0,C_word t1);
C_noret_decl(f_12053)
static void C_fcall f_12053(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12088)
static void C_ccall f_12088(C_word c,C_word *av) C_noret;
C_noret_decl(f_12095)
static C_word C_fcall f_12095(C_word t0,C_word t1);
C_noret_decl(f_12107)
static void C_fcall f_12107(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12142)
static void C_ccall f_12142(C_word c,C_word *av) C_noret;
C_noret_decl(f_12149)
static C_word C_fcall f_12149(C_word t0,C_word t1);
C_noret_decl(f_12161)
static void C_fcall f_12161(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12196)
static void C_ccall f_12196(C_word c,C_word *av) C_noret;
C_noret_decl(f_12203)
static C_word C_fcall f_12203(C_word t0,C_word t1);
C_noret_decl(f_12215)
static void C_fcall f_12215(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12250)
static void C_ccall f_12250(C_word c,C_word *av) C_noret;
C_noret_decl(f_12257)
static C_word C_fcall f_12257(C_word t0,C_word t1);
C_noret_decl(f_12269)
static void C_fcall f_12269(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12304)
static void C_ccall f_12304(C_word c,C_word *av) C_noret;
C_noret_decl(f_12311)
static C_word C_fcall f_12311(C_word t0,C_word t1);
C_noret_decl(f_12323)
static void C_fcall f_12323(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12358)
static void C_ccall f_12358(C_word c,C_word *av) C_noret;
C_noret_decl(f_12365)
static C_word C_fcall f_12365(C_word t0,C_word t1);
C_noret_decl(f_12377)
static void C_fcall f_12377(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12412)
static void C_ccall f_12412(C_word c,C_word *av) C_noret;
C_noret_decl(f_12419)
static C_word C_fcall f_12419(C_word t0,C_word t1);
C_noret_decl(f_12431)
static void C_fcall f_12431(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12466)
static void C_ccall f_12466(C_word c,C_word *av) C_noret;
C_noret_decl(f_12473)
static C_word C_fcall f_12473(C_word t0,C_word t1);
C_noret_decl(f_12485)
static void C_fcall f_12485(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12520)
static void C_ccall f_12520(C_word c,C_word *av) C_noret;
C_noret_decl(f_12524)
static void C_ccall f_12524(C_word c,C_word *av) C_noret;
C_noret_decl(f_12528)
static void C_ccall f_12528(C_word c,C_word *av) C_noret;
C_noret_decl(f_4382)
static void C_ccall f_4382(C_word c,C_word *av) C_noret;
C_noret_decl(f_4385)
static void C_ccall f_4385(C_word c,C_word *av) C_noret;
C_noret_decl(f_4388)
static void C_ccall f_4388(C_word c,C_word *av) C_noret;
C_noret_decl(f_4391)
static void C_ccall f_4391(C_word c,C_word *av) C_noret;
C_noret_decl(f_4394)
static void C_ccall f_4394(C_word c,C_word *av) C_noret;
C_noret_decl(f_4397)
static void C_ccall f_4397(C_word c,C_word *av) C_noret;
C_noret_decl(f_4888)
static void C_fcall f_4888(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_4894)
static void C_fcall f_4894(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4907)
static void C_ccall f_4907(C_word c,C_word *av) C_noret;
C_noret_decl(f_4921)
static void C_ccall f_4921(C_word c,C_word *av) C_noret;
C_noret_decl(f_4969)
static void C_fcall f_4969(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4983)
static void C_ccall f_4983(C_word c,C_word *av) C_noret;
C_noret_decl(f_4996)
static void C_ccall f_4996(C_word c,C_word *av) C_noret;
C_noret_decl(f_5052)
static void C_fcall f_5052(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5061)
static void C_fcall f_5061(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5069)
static void C_fcall f_5069(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_5073)
static void C_ccall f_5073(C_word c,C_word *av) C_noret;
C_noret_decl(f_5077)
static C_word C_fcall f_5077(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_5095)
static void C_ccall f_5095(C_word c,C_word *av) C_noret;
C_noret_decl(f_5679)
static void C_ccall f_5679(C_word c,C_word *av) C_noret;
C_noret_decl(f_5683)
static void C_ccall f_5683(C_word c,C_word *av) C_noret;
C_noret_decl(f_5698)
static void C_ccall f_5698(C_word c,C_word *av) C_noret;
C_noret_decl(f_5788)
static void C_ccall f_5788(C_word c,C_word *av) C_noret;
C_noret_decl(f_5797)
static void C_ccall f_5797(C_word c,C_word *av) C_noret;
C_noret_decl(f_5951)
static void C_ccall f_5951(C_word c,C_word *av) C_noret;
C_noret_decl(f_5969)
static C_word C_fcall f_5969(C_word *a,C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6);
C_noret_decl(f_5984)
static void C_ccall f_5984(C_word c,C_word *av) C_noret;
C_noret_decl(f_6000)
static void C_ccall f_6000(C_word c,C_word *av) C_noret;
C_noret_decl(f_6002)
static void C_ccall f_6002(C_word c,C_word *av) C_noret;
C_noret_decl(f_6006)
static void C_ccall f_6006(C_word c,C_word *av) C_noret;
C_noret_decl(f_6011)
static void C_ccall f_6011(C_word c,C_word *av) C_noret;
C_noret_decl(f_6015)
static void C_ccall f_6015(C_word c,C_word *av) C_noret;
C_noret_decl(f_6019)
static void C_ccall f_6019(C_word c,C_word *av) C_noret;
C_noret_decl(f_6022)
static void C_ccall f_6022(C_word c,C_word *av) C_noret;
C_noret_decl(f_6028)
static void C_ccall f_6028(C_word c,C_word *av) C_noret;
C_noret_decl(f_6034)
static void C_ccall f_6034(C_word c,C_word *av) C_noret;
C_noret_decl(f_6038)
static void C_ccall f_6038(C_word c,C_word *av) C_noret;
C_noret_decl(f_6041)
static void C_ccall f_6041(C_word c,C_word *av) C_noret;
C_noret_decl(f_6065)
static void C_ccall f_6065(C_word c,C_word *av) C_noret;
C_noret_decl(f_6069)
static void C_ccall f_6069(C_word c,C_word *av) C_noret;
C_noret_decl(f_6071)
static void C_fcall f_6071(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6105)
static void C_ccall f_6105(C_word c,C_word *av) C_noret;
C_noret_decl(f_6113)
static void C_ccall f_6113(C_word c,C_word *av) C_noret;
C_noret_decl(f_6115)
static void C_fcall f_6115(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6123)
static void C_fcall f_6123(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6150)
static void C_ccall f_6150(C_word c,C_word *av) C_noret;
C_noret_decl(f_6152)
static void C_ccall f_6152(C_word c,C_word *av) C_noret;
C_noret_decl(f_6206)
static void C_ccall f_6206(C_word c,C_word *av) C_noret;
C_noret_decl(f_6213)
static void C_ccall f_6213(C_word c,C_word *av) C_noret;
C_noret_decl(f_6216)
static void C_ccall f_6216(C_word c,C_word *av) C_noret;
C_noret_decl(f_6219)
static void C_fcall f_6219(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6222)
static void C_ccall f_6222(C_word c,C_word *av) C_noret;
C_noret_decl(f_6228)
static void C_ccall f_6228(C_word c,C_word *av) C_noret;
C_noret_decl(f_6241)
static void C_fcall f_6241(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6253)
static void C_ccall f_6253(C_word c,C_word *av) C_noret;
C_noret_decl(f_6257)
static void C_ccall f_6257(C_word c,C_word *av) C_noret;
C_noret_decl(f_6259)
static void C_ccall f_6259(C_word c,C_word *av) C_noret;
C_noret_decl(f_6275)
static void C_ccall f_6275(C_word c,C_word *av) C_noret;
C_noret_decl(f_6276)
static C_word C_fcall f_6276(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_6284)
static C_word C_fcall f_6284(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_6298)
static void C_ccall f_6298(C_word c,C_word *av) C_noret;
C_noret_decl(f_6301)
static void C_ccall f_6301(C_word c,C_word *av) C_noret;
C_noret_decl(f_6308)
static void C_ccall f_6308(C_word c,C_word *av) C_noret;
C_noret_decl(f_6312)
static void C_ccall f_6312(C_word c,C_word *av) C_noret;
C_noret_decl(f_6318)
static void C_fcall f_6318(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6346)
static void C_ccall f_6346(C_word c,C_word *av) C_noret;
C_noret_decl(f_6348)
static void C_ccall f_6348(C_word c,C_word *av) C_noret;
C_noret_decl(f_6355)
static void C_ccall f_6355(C_word c,C_word *av) C_noret;
C_noret_decl(f_6368)
static void C_ccall f_6368(C_word c,C_word *av) C_noret;
C_noret_decl(f_6370)
static void C_fcall f_6370(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6406)
static void C_ccall f_6406(C_word c,C_word *av) C_noret;
C_noret_decl(f_6408)
static void C_ccall f_6408(C_word c,C_word *av) C_noret;
C_noret_decl(f_6411)
static void C_ccall f_6411(C_word c,C_word *av) C_noret;
C_noret_decl(f_6415)
static void C_ccall f_6415(C_word c,C_word *av) C_noret;
C_noret_decl(f_6431)
static void C_fcall f_6431(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6438)
static void C_ccall f_6438(C_word c,C_word *av) C_noret;
C_noret_decl(f_6452)
static void C_ccall f_6452(C_word c,C_word *av) C_noret;
C_noret_decl(f_6462)
static void C_ccall f_6462(C_word c,C_word *av) C_noret;
C_noret_decl(f_6465)
static void C_ccall f_6465(C_word c,C_word *av) C_noret;
C_noret_decl(f_6468)
static void C_ccall f_6468(C_word c,C_word *av) C_noret;
C_noret_decl(f_6474)
static void C_ccall f_6474(C_word c,C_word *av) C_noret;
C_noret_decl(f_6477)
static void C_ccall f_6477(C_word c,C_word *av) C_noret;
C_noret_decl(f_6480)
static void C_ccall f_6480(C_word c,C_word *av) C_noret;
C_noret_decl(f_6513)
static void C_ccall f_6513(C_word c,C_word *av) C_noret;
C_noret_decl(f_6517)
static void C_ccall f_6517(C_word c,C_word *av) C_noret;
C_noret_decl(f_6524)
static void C_ccall f_6524(C_word c,C_word *av) C_noret;
C_noret_decl(f_6528)
static void C_ccall f_6528(C_word c,C_word *av) C_noret;
C_noret_decl(f_6541)
static void C_ccall f_6541(C_word c,C_word *av) C_noret;
C_noret_decl(f_6551)
static void C_ccall f_6551(C_word c,C_word *av) C_noret;
C_noret_decl(f_6554)
static void C_ccall f_6554(C_word c,C_word *av) C_noret;
C_noret_decl(f_6560)
static void C_ccall f_6560(C_word c,C_word *av) C_noret;
C_noret_decl(f_6563)
static void C_ccall f_6563(C_word c,C_word *av) C_noret;
C_noret_decl(f_6569)
static void C_ccall f_6569(C_word c,C_word *av) C_noret;
C_noret_decl(f_6603)
static void C_ccall f_6603(C_word c,C_word *av) C_noret;
C_noret_decl(f_6607)
static void C_ccall f_6607(C_word c,C_word *av) C_noret;
C_noret_decl(f_6622)
static void C_ccall f_6622(C_word c,C_word *av) C_noret;
C_noret_decl(f_6633)
static void C_ccall f_6633(C_word c,C_word *av) C_noret;
C_noret_decl(f_6639)
static void C_ccall f_6639(C_word c,C_word *av) C_noret;
C_noret_decl(f_6656)
static void C_ccall f_6656(C_word c,C_word *av) C_noret;
C_noret_decl(f_6663)
static void C_fcall f_6663(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6670)
static void C_fcall f_6670(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6715)
static void C_ccall f_6715(C_word c,C_word *av) C_noret;
C_noret_decl(f_6821)
static void C_fcall f_6821(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6829)
static void C_ccall f_6829(C_word c,C_word *av) C_noret;
C_noret_decl(f_6833)
static void C_ccall f_6833(C_word c,C_word *av) C_noret;
C_noret_decl(f_6844)
static void C_fcall f_6844(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6871)
static void C_fcall f_6871(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6894)
static void C_ccall f_6894(C_word c,C_word *av) C_noret;
C_noret_decl(f_6908)
static void C_fcall f_6908(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6933)
static void C_ccall f_6933(C_word c,C_word *av) C_noret;
C_noret_decl(f_6948)
static void C_fcall f_6948(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6966)
static void C_ccall f_6966(C_word c,C_word *av) C_noret;
C_noret_decl(f_6977)
static void C_ccall f_6977(C_word c,C_word *av) C_noret;
C_noret_decl(f_6996)
static void C_ccall f_6996(C_word c,C_word *av) C_noret;
C_noret_decl(f_7009)
static void C_ccall f_7009(C_word c,C_word *av) C_noret;
C_noret_decl(f_7019)
static void C_ccall f_7019(C_word c,C_word *av) C_noret;
C_noret_decl(f_7025)
static void C_fcall f_7025(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7029)
static void C_ccall f_7029(C_word c,C_word *av) C_noret;
C_noret_decl(f_7032)
static void C_ccall f_7032(C_word c,C_word *av) C_noret;
C_noret_decl(f_7043)
static void C_fcall f_7043(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_7071)
static void C_fcall f_7071(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7085)
static void C_ccall f_7085(C_word c,C_word *av) C_noret;
C_noret_decl(f_7090)
static void C_fcall f_7090(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7100)
static void C_ccall f_7100(C_word c,C_word *av) C_noret;
C_noret_decl(f_7118)
static void C_fcall f_7118(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7140)
static void C_ccall f_7140(C_word c,C_word *av) C_noret;
C_noret_decl(f_7148)
static void C_ccall f_7148(C_word c,C_word *av) C_noret;
C_noret_decl(f_7182)
static void C_ccall f_7182(C_word c,C_word *av) C_noret;
C_noret_decl(f_7193)
static void C_ccall f_7193(C_word c,C_word *av) C_noret;
C_noret_decl(f_7201)
static void C_fcall f_7201(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7235)
static void C_ccall f_7235(C_word c,C_word *av) C_noret;
C_noret_decl(f_7241)
static void C_ccall f_7241(C_word c,C_word *av) C_noret;
C_noret_decl(f_7247)
static void C_ccall f_7247(C_word c,C_word *av) C_noret;
C_noret_decl(f_7257)
static void C_ccall f_7257(C_word c,C_word *av) C_noret;
C_noret_decl(f_7292)
static void C_ccall f_7292(C_word c,C_word *av) C_noret;
C_noret_decl(f_7296)
static void C_ccall f_7296(C_word c,C_word *av) C_noret;
C_noret_decl(f_7300)
static void C_ccall f_7300(C_word c,C_word *av) C_noret;
C_noret_decl(f_7304)
static void C_fcall f_7304(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7308)
static void C_ccall f_7308(C_word c,C_word *av) C_noret;
C_noret_decl(f_7312)
static void C_fcall f_7312(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7316)
static void C_ccall f_7316(C_word c,C_word *av) C_noret;
C_noret_decl(f_7320)
static void C_ccall f_7320(C_word c,C_word *av) C_noret;
C_noret_decl(f_7352)
static void C_fcall f_7352(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7388)
static void C_ccall f_7388(C_word c,C_word *av) C_noret;
C_noret_decl(f_7390)
static void C_fcall f_7390(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7426)
static void C_ccall f_7426(C_word c,C_word *av) C_noret;
C_noret_decl(f_7438)
static void C_fcall f_7438(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7470)
static void C_ccall f_7470(C_word c,C_word *av) C_noret;
C_noret_decl(f_7480)
static void C_ccall f_7480(C_word c,C_word *av) C_noret;
C_noret_decl(f_7495)
static void C_fcall f_7495(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7519)
static void C_ccall f_7519(C_word c,C_word *av) C_noret;
C_noret_decl(f_7535)
static void C_ccall f_7535(C_word c,C_word *av) C_noret;
C_noret_decl(f_7537)
static void C_fcall f_7537(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7562)
static void C_ccall f_7562(C_word c,C_word *av) C_noret;
C_noret_decl(f_7624)
static void C_ccall f_7624(C_word c,C_word *av) C_noret;
C_noret_decl(f_7626)
static void C_fcall f_7626(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7651)
static void C_fcall f_7651(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7681)
static void C_ccall f_7681(C_word c,C_word *av) C_noret;
C_noret_decl(f_7702)
static void C_ccall f_7702(C_word c,C_word *av) C_noret;
C_noret_decl(f_7730)
static void C_ccall f_7730(C_word c,C_word *av) C_noret;
C_noret_decl(f_7739)
static void C_fcall f_7739(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7756)
static void C_ccall f_7756(C_word c,C_word *av) C_noret;
C_noret_decl(f_7795)
static void C_ccall f_7795(C_word c,C_word *av) C_noret;
C_noret_decl(f_7798)
static void C_ccall f_7798(C_word c,C_word *av) C_noret;
C_noret_decl(f_7801)
static void C_ccall f_7801(C_word c,C_word *av) C_noret;
C_noret_decl(f_7817)
static void C_ccall f_7817(C_word c,C_word *av) C_noret;
C_noret_decl(f_7827)
static void C_ccall f_7827(C_word c,C_word *av) C_noret;
C_noret_decl(f_7833)
static void C_ccall f_7833(C_word c,C_word *av) C_noret;
C_noret_decl(f_7834)
static void C_fcall f_7834(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7846)
static void C_ccall f_7846(C_word c,C_word *av) C_noret;
C_noret_decl(f_7859)
static void C_ccall f_7859(C_word c,C_word *av) C_noret;
C_noret_decl(f_7860)
static void C_fcall f_7860(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7872)
static void C_ccall f_7872(C_word c,C_word *av) C_noret;
C_noret_decl(f_7885)
static void C_ccall f_7885(C_word c,C_word *av) C_noret;
C_noret_decl(f_7888)
static void C_ccall f_7888(C_word c,C_word *av) C_noret;
C_noret_decl(f_7904)
static void C_ccall f_7904(C_word c,C_word *av) C_noret;
C_noret_decl(f_7908)
static void C_ccall f_7908(C_word c,C_word *av) C_noret;
C_noret_decl(f_7912)
static void C_ccall f_7912(C_word c,C_word *av) C_noret;
C_noret_decl(f_7914)
static void C_fcall f_7914(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7924)
static void C_ccall f_7924(C_word c,C_word *av) C_noret;
C_noret_decl(f_7937)
static void C_fcall f_7937(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7947)
static void C_ccall f_7947(C_word c,C_word *av) C_noret;
C_noret_decl(f_7971)
static void C_ccall f_7971(C_word c,C_word *av) C_noret;
C_noret_decl(f_7975)
static void C_ccall f_7975(C_word c,C_word *av) C_noret;
C_noret_decl(f_7990)
static void C_ccall f_7990(C_word c,C_word *av) C_noret;
C_noret_decl(f_7992)
static void C_fcall f_7992(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8026)
static void C_ccall f_8026(C_word c,C_word *av) C_noret;
C_noret_decl(f_8038)
static void C_ccall f_8038(C_word c,C_word *av) C_noret;
C_noret_decl(f_8056)
static void C_ccall f_8056(C_word c,C_word *av) C_noret;
C_noret_decl(f_8090)
static void C_ccall f_8090(C_word c,C_word *av) C_noret;
C_noret_decl(f_8097)
static void C_ccall f_8097(C_word c,C_word *av) C_noret;
C_noret_decl(f_8103)
static void C_ccall f_8103(C_word c,C_word *av) C_noret;
C_noret_decl(f_8119)
static void C_ccall f_8119(C_word c,C_word *av) C_noret;
C_noret_decl(f_8123)
static void C_ccall f_8123(C_word c,C_word *av) C_noret;
C_noret_decl(f_8127)
static void C_ccall f_8127(C_word c,C_word *av) C_noret;
C_noret_decl(f_8140)
static void C_fcall f_8140(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8162)
static void C_ccall f_8162(C_word c,C_word *av) C_noret;
C_noret_decl(f_8164)
static void C_fcall f_8164(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8189)
static void C_ccall f_8189(C_word c,C_word *av) C_noret;
C_noret_decl(f_8204)
static void C_ccall f_8204(C_word c,C_word *av) C_noret;
C_noret_decl(f_8219)
static void C_fcall f_8219(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_8230)
static void C_fcall f_8230(C_word t0,C_word t1) C_noret;
C_noret_decl(f_8232)
static C_word C_fcall f_8232(C_word t0,C_word t1);
C_noret_decl(f_8297)
static void C_ccall f_8297(C_word c,C_word *av) C_noret;
C_noret_decl(f_8303)
static void C_fcall f_8303(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8307)
static void C_ccall f_8307(C_word c,C_word *av) C_noret;
C_noret_decl(f_8313)
static void C_ccall f_8313(C_word c,C_word *av) C_noret;
C_noret_decl(f_8316)
static void C_ccall f_8316(C_word c,C_word *av) C_noret;
C_noret_decl(f_8319)
static void C_ccall f_8319(C_word c,C_word *av) C_noret;
C_noret_decl(f_8322)
static void C_ccall f_8322(C_word c,C_word *av) C_noret;
C_noret_decl(f_8323)
static void C_fcall f_8323(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8330)
static void C_ccall f_8330(C_word c,C_word *av) C_noret;
C_noret_decl(f_8333)
static void C_ccall f_8333(C_word c,C_word *av) C_noret;
C_noret_decl(f_8336)
static void C_ccall f_8336(C_word c,C_word *av) C_noret;
C_noret_decl(f_8337)
static void C_fcall f_8337(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8340)
static void C_fcall f_8340(C_word t0,C_word t1) C_noret;
C_noret_decl(f_8344)
static void C_ccall f_8344(C_word c,C_word *av) C_noret;
C_noret_decl(f_8370)
static void C_ccall f_8370(C_word c,C_word *av) C_noret;
C_noret_decl(f_8376)
static void C_ccall f_8376(C_word c,C_word *av) C_noret;
C_noret_decl(f_8380)
static void C_fcall f_8380(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8384)
static void C_ccall f_8384(C_word c,C_word *av) C_noret;
C_noret_decl(f_8390)
static void C_ccall f_8390(C_word c,C_word *av) C_noret;
C_noret_decl(f_8393)
static void C_ccall f_8393(C_word c,C_word *av) C_noret;
C_noret_decl(f_8396)
static void C_ccall f_8396(C_word c,C_word *av) C_noret;
C_noret_decl(f_8399)
static void C_ccall f_8399(C_word c,C_word *av) C_noret;
C_noret_decl(f_8406)
static void C_ccall f_8406(C_word c,C_word *av) C_noret;
C_noret_decl(f_8422)
static void C_ccall f_8422(C_word c,C_word *av) C_noret;
C_noret_decl(f_8428)
static void C_ccall f_8428(C_word c,C_word *av) C_noret;
C_noret_decl(f_8431)
static void C_ccall f_8431(C_word c,C_word *av) C_noret;
C_noret_decl(f_8438)
static void C_ccall f_8438(C_word c,C_word *av) C_noret;
C_noret_decl(f_8445)
static void C_ccall f_8445(C_word c,C_word *av) C_noret;
C_noret_decl(f_8451)
static void C_ccall f_8451(C_word c,C_word *av) C_noret;
C_noret_decl(f_8454)
static void C_ccall f_8454(C_word c,C_word *av) C_noret;
C_noret_decl(f_8457)
static void C_ccall f_8457(C_word c,C_word *av) C_noret;
C_noret_decl(f_8475)
static void C_ccall f_8475(C_word c,C_word *av) C_noret;
C_noret_decl(f_8478)
static void C_ccall f_8478(C_word c,C_word *av) C_noret;
C_noret_decl(f_8496)
static void C_ccall f_8496(C_word c,C_word *av) C_noret;
C_noret_decl(f_8508)
static void C_ccall f_8508(C_word c,C_word *av) C_noret;
C_noret_decl(f_8511)
static void C_ccall f_8511(C_word c,C_word *av) C_noret;
C_noret_decl(f_8518)
static void C_ccall f_8518(C_word c,C_word *av) C_noret;
C_noret_decl(f_8524)
static void C_ccall f_8524(C_word c,C_word *av) C_noret;
C_noret_decl(f_8525)
static void C_fcall f_8525(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8532)
static void C_ccall f_8532(C_word c,C_word *av) C_noret;
C_noret_decl(f_8544)
static void C_fcall f_8544(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8554)
static void C_ccall f_8554(C_word c,C_word *av) C_noret;
C_noret_decl(f_8572)
static void C_fcall f_8572(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8582)
static void C_ccall f_8582(C_word c,C_word *av) C_noret;
C_noret_decl(f_8602)
static void C_ccall f_8602(C_word c,C_word *av) C_noret;
C_noret_decl(f_8609)
static void C_ccall f_8609(C_word c,C_word *av) C_noret;
C_noret_decl(f_8611)
static void C_fcall f_8611(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8621)
static void C_ccall f_8621(C_word c,C_word *av) C_noret;
C_noret_decl(f_8636)
static void C_ccall f_8636(C_word c,C_word *av) C_noret;
C_noret_decl(f_8638)
static void C_fcall f_8638(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8668)
static void C_ccall f_8668(C_word c,C_word *av) C_noret;
C_noret_decl(f_8680)
static void C_ccall f_8680(C_word c,C_word *av) C_noret;
C_noret_decl(f_8683)
static void C_ccall f_8683(C_word c,C_word *av) C_noret;
C_noret_decl(f_8686)
static void C_ccall f_8686(C_word c,C_word *av) C_noret;
C_noret_decl(f_8707)
static void C_ccall f_8707(C_word c,C_word *av) C_noret;
C_noret_decl(f_8709)
static void C_fcall f_8709(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8757)
static void C_fcall f_8757(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8786)
static void C_ccall f_8786(C_word c,C_word *av) C_noret;
C_noret_decl(f_8796)
static void C_ccall f_8796(C_word c,C_word *av) C_noret;
C_noret_decl(f_8800)
static void C_ccall f_8800(C_word c,C_word *av) C_noret;
C_noret_decl(f_8819)
static void C_ccall f_8819(C_word c,C_word *av) C_noret;
C_noret_decl(f_8822)
static void C_ccall f_8822(C_word c,C_word *av) C_noret;
C_noret_decl(f_8825)
static void C_ccall f_8825(C_word c,C_word *av) C_noret;
C_noret_decl(f_8826)
static C_word C_fcall f_8826(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_8844)
static void C_ccall f_8844(C_word c,C_word *av) C_noret;
C_noret_decl(f_8850)
static void C_ccall f_8850(C_word c,C_word *av) C_noret;
C_noret_decl(f_8853)
static void C_ccall f_8853(C_word c,C_word *av) C_noret;
C_noret_decl(f_8856)
static void C_ccall f_8856(C_word c,C_word *av) C_noret;
C_noret_decl(f_8884)
static void C_ccall f_8884(C_word c,C_word *av) C_noret;
C_noret_decl(f_8891)
static void C_ccall f_8891(C_word c,C_word *av) C_noret;
C_noret_decl(f_8897)
static void C_ccall f_8897(C_word c,C_word *av) C_noret;
C_noret_decl(f_8900)
static void C_ccall f_8900(C_word c,C_word *av) C_noret;
C_noret_decl(f_8901)
static void C_fcall f_8901(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8905)
static void C_ccall f_8905(C_word c,C_word *av) C_noret;
C_noret_decl(f_8923)
static void C_ccall f_8923(C_word c,C_word *av) C_noret;
C_noret_decl(f_8929)
static void C_ccall f_8929(C_word c,C_word *av) C_noret;
C_noret_decl(f_8932)
static void C_ccall f_8932(C_word c,C_word *av) C_noret;
C_noret_decl(f_8935)
static void C_ccall f_8935(C_word c,C_word *av) C_noret;
C_noret_decl(f_8946)
static void C_ccall f_8946(C_word c,C_word *av) C_noret;
C_noret_decl(f_8950)
static void C_ccall f_8950(C_word c,C_word *av) C_noret;
C_noret_decl(f_8954)
static void C_ccall f_8954(C_word c,C_word *av) C_noret;
C_noret_decl(f_8958)
static void C_ccall f_8958(C_word c,C_word *av) C_noret;
C_noret_decl(f_8964)
static void C_fcall f_8964(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8974)
static void C_ccall f_8974(C_word c,C_word *av) C_noret;
C_noret_decl(f_8989)
static void C_ccall f_8989(C_word c,C_word *av) C_noret;
C_noret_decl(f_8993)
static void C_ccall f_8993(C_word c,C_word *av) C_noret;
C_noret_decl(f_8995)
static void C_fcall f_8995(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9005)
static void C_fcall f_9005(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9020)
static void C_ccall f_9020(C_word c,C_word *av) C_noret;
C_noret_decl(f_9038)
static void C_fcall f_9038(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9065)
static void C_fcall f_9065(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9111)
static void C_ccall f_9111(C_word c,C_word *av) C_noret;
C_noret_decl(f_9120)
static void C_ccall f_9120(C_word c,C_word *av) C_noret;
C_noret_decl(f_9131)
static void C_fcall f_9131(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9135)
static void C_ccall f_9135(C_word c,C_word *av) C_noret;
C_noret_decl(f_9138)
static void C_fcall f_9138(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9146)
static void C_ccall f_9146(C_word c,C_word *av) C_noret;
C_noret_decl(f_9167)
static void C_ccall f_9167(C_word c,C_word *av) C_noret;
C_noret_decl(f_9171)
static void C_fcall f_9171(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9179)
static void C_ccall f_9179(C_word c,C_word *av) C_noret;
C_noret_decl(f_9183)
static void C_ccall f_9183(C_word c,C_word *av) C_noret;
C_noret_decl(f_9199)
static void C_ccall f_9199(C_word c,C_word *av) C_noret;
C_noret_decl(f_9203)
static void C_ccall f_9203(C_word c,C_word *av) C_noret;
C_noret_decl(f_9217)
static void C_ccall f_9217(C_word c,C_word *av) C_noret;
C_noret_decl(f_9228)
static void C_ccall f_9228(C_word c,C_word *av) C_noret;
C_noret_decl(f_9254)
static void C_ccall f_9254(C_word c,C_word *av) C_noret;
C_noret_decl(f_9256)
static void C_fcall f_9256(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9280)
static void C_ccall f_9280(C_word c,C_word *av) C_noret;
C_noret_decl(f_9289)
static void C_ccall f_9289(C_word c,C_word *av) C_noret;
C_noret_decl(f_9304)
static void C_ccall f_9304(C_word c,C_word *av) C_noret;
C_noret_decl(f_9312)
static void C_ccall f_9312(C_word c,C_word *av) C_noret;
C_noret_decl(f_9319)
static void C_ccall f_9319(C_word c,C_word *av) C_noret;
C_noret_decl(f_9323)
static void C_ccall f_9323(C_word c,C_word *av) C_noret;
C_noret_decl(f_9326)
static void C_ccall f_9326(C_word c,C_word *av) C_noret;
C_noret_decl(f_9331)
static void C_ccall f_9331(C_word c,C_word *av) C_noret;
C_noret_decl(f_9335)
static void C_ccall f_9335(C_word c,C_word *av) C_noret;
C_noret_decl(f_9338)
static void C_ccall f_9338(C_word c,C_word *av) C_noret;
C_noret_decl(f_9341)
static void C_ccall f_9341(C_word c,C_word *av) C_noret;
C_noret_decl(f_9344)
static void C_ccall f_9344(C_word c,C_word *av) C_noret;
C_noret_decl(f_9348)
static void C_ccall f_9348(C_word c,C_word *av) C_noret;
C_noret_decl(f_9352)
static void C_ccall f_9352(C_word c,C_word *av) C_noret;
C_noret_decl(f_9356)
static void C_ccall f_9356(C_word c,C_word *av) C_noret;
C_noret_decl(f_9360)
static void C_ccall f_9360(C_word c,C_word *av) C_noret;
C_noret_decl(f_9363)
static void C_ccall f_9363(C_word c,C_word *av) C_noret;
C_noret_decl(f_9366)
static void C_ccall f_9366(C_word c,C_word *av) C_noret;
C_noret_decl(f_9369)
static void C_ccall f_9369(C_word c,C_word *av) C_noret;
C_noret_decl(f_9372)
static void C_ccall f_9372(C_word c,C_word *av) C_noret;
C_noret_decl(f_9387)
static void C_ccall f_9387(C_word c,C_word *av) C_noret;
C_noret_decl(f_9393)
static void C_ccall f_9393(C_word c,C_word *av) C_noret;
C_noret_decl(f_9397)
static void C_ccall f_9397(C_word c,C_word *av) C_noret;
C_noret_decl(f_9400)
static void C_ccall f_9400(C_word c,C_word *av) C_noret;
C_noret_decl(f_9403)
static void C_ccall f_9403(C_word c,C_word *av) C_noret;
C_noret_decl(f_9406)
static void C_ccall f_9406(C_word c,C_word *av) C_noret;
C_noret_decl(f_9409)
static void C_ccall f_9409(C_word c,C_word *av) C_noret;
C_noret_decl(f_9412)
static void C_ccall f_9412(C_word c,C_word *av) C_noret;
C_noret_decl(f_9415)
static void C_ccall f_9415(C_word c,C_word *av) C_noret;
C_noret_decl(f_9418)
static void C_ccall f_9418(C_word c,C_word *av) C_noret;
C_noret_decl(f_9424)
static void C_ccall f_9424(C_word c,C_word *av) C_noret;
C_noret_decl(f_9428)
static void C_ccall f_9428(C_word c,C_word *av) C_noret;
C_noret_decl(f_9436)
static void C_ccall f_9436(C_word c,C_word *av) C_noret;
C_noret_decl(f_9442)
static void C_ccall f_9442(C_word c,C_word *av) C_noret;
C_noret_decl(f_9447)
static void C_ccall f_9447(C_word c,C_word *av) C_noret;
C_noret_decl(f_9451)
static void C_ccall f_9451(C_word c,C_word *av) C_noret;
C_noret_decl(f_9456)
static void C_ccall f_9456(C_word c,C_word *av) C_noret;
C_noret_decl(f_9463)
static void C_ccall f_9463(C_word c,C_word *av) C_noret;
C_noret_decl(f_9467)
static void C_ccall f_9467(C_word c,C_word *av) C_noret;
C_noret_decl(f_9470)
static void C_fcall f_9470(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9474)
static void C_ccall f_9474(C_word c,C_word *av) C_noret;
C_noret_decl(f_9477)
static void C_ccall f_9477(C_word c,C_word *av) C_noret;
C_noret_decl(f_9485)
static void C_ccall f_9485(C_word c,C_word *av) C_noret;
C_noret_decl(f_9489)
static void C_ccall f_9489(C_word c,C_word *av) C_noret;
C_noret_decl(f_9492)
static void C_ccall f_9492(C_word c,C_word *av) C_noret;
C_noret_decl(f_9495)
static void C_ccall f_9495(C_word c,C_word *av) C_noret;
C_noret_decl(f_9498)
static void C_ccall f_9498(C_word c,C_word *av) C_noret;
C_noret_decl(f_9500)
static void C_fcall f_9500(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_9508)
static void C_ccall f_9508(C_word c,C_word *av) C_noret;
C_noret_decl(f_9512)
static void C_ccall f_9512(C_word c,C_word *av) C_noret;
C_noret_decl(f_9514)
static void C_fcall f_9514(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9527)
static void C_ccall f_9527(C_word c,C_word *av) C_noret;
C_noret_decl(f_9534)
static void C_ccall f_9534(C_word c,C_word *av) C_noret;
C_noret_decl(f_9558)
static void C_fcall f_9558(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9572)
static void C_fcall f_9572(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9580)
static C_word C_fcall f_9580(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_9607)
static void C_fcall f_9607(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9632)
static void C_ccall f_9632(C_word c,C_word *av) C_noret;
C_noret_decl(f_9644)
static void C_ccall f_9644(C_word c,C_word *av) C_noret;
C_noret_decl(f_9647)
static void C_fcall f_9647(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9651)
static void C_ccall f_9651(C_word c,C_word *av) C_noret;
C_noret_decl(f_9654)
static void C_ccall f_9654(C_word c,C_word *av) C_noret;
C_noret_decl(f_9682)
static void C_ccall f_9682(C_word c,C_word *av) C_noret;
C_noret_decl(f_9686)
static void C_ccall f_9686(C_word c,C_word *av) C_noret;
C_noret_decl(f_9703)
static void C_fcall f_9703(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9717)
static void C_ccall f_9717(C_word c,C_word *av) C_noret;
C_noret_decl(f_9735)
static void C_ccall f_9735(C_word c,C_word *av) C_noret;
C_noret_decl(f_9738)
static void C_ccall f_9738(C_word c,C_word *av) C_noret;
C_noret_decl(f_9743)
static void C_ccall f_9743(C_word c,C_word *av) C_noret;
C_noret_decl(f_9753)
static void C_ccall f_9753(C_word c,C_word *av) C_noret;
C_noret_decl(f_9757)
static void C_ccall f_9757(C_word c,C_word *av) C_noret;
C_noret_decl(f_9762)
static void C_fcall f_9762(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_9770)
static void C_fcall f_9770(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9780)
static void C_ccall f_9780(C_word c,C_word *av) C_noret;
C_noret_decl(f_9793)
static void C_fcall f_9793(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9803)
static void C_ccall f_9803(C_word c,C_word *av) C_noret;
C_noret_decl(f_9821)
static void C_fcall f_9821(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9843)
static void C_fcall f_9843(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9885)
static void C_ccall f_9885(C_word c,C_word *av) C_noret;
C_noret_decl(f_9888)
static void C_ccall f_9888(C_word c,C_word *av) C_noret;
C_noret_decl(f_9893)
static void C_ccall f_9893(C_word c,C_word *av) C_noret;
C_noret_decl(f_9903)
static void C_ccall f_9903(C_word c,C_word *av) C_noret;
C_noret_decl(f_9907)
static void C_ccall f_9907(C_word c,C_word *av) C_noret;
C_noret_decl(f_9912)
static void C_fcall f_9912(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_9924)
static void C_fcall f_9924(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_9932)
static void C_fcall f_9932(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9942)
static void C_ccall f_9942(C_word c,C_word *av) C_noret;
C_noret_decl(f_9955)
static void C_fcall f_9955(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9965)
static void C_ccall f_9965(C_word c,C_word *av) C_noret;
C_noret_decl(f_9983)
static void C_fcall f_9983(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9995)
static void C_ccall f_9995(C_word c,C_word *av) C_noret;
C_noret_decl(C_modules_toplevel)
C_externexport void C_ccall C_modules_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_10024)
static void C_ccall trf_10024(C_word c,C_word *av) C_noret;
static void C_ccall trf_10024(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10024(t0,t1,t2);}

C_noret_decl(trf_10095)
static void C_ccall trf_10095(C_word c,C_word *av) C_noret;
static void C_ccall trf_10095(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_10095(t0,t1,t2,t3,t4);}

C_noret_decl(trf_10107)
static void C_ccall trf_10107(C_word c,C_word *av) C_noret;
static void C_ccall trf_10107(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_10107(t0,t1,t2,t3,t4);}

C_noret_decl(trf_10115)
static void C_ccall trf_10115(C_word c,C_word *av) C_noret;
static void C_ccall trf_10115(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10115(t0,t1,t2);}

C_noret_decl(trf_10147)
static void C_ccall trf_10147(C_word c,C_word *av) C_noret;
static void C_ccall trf_10147(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10147(t0,t1,t2);}

C_noret_decl(trf_10170)
static void C_ccall trf_10170(C_word c,C_word *av) C_noret;
static void C_ccall trf_10170(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10170(t0,t1,t2);}

C_noret_decl(trf_10209)
static void C_ccall trf_10209(C_word c,C_word *av) C_noret;
static void C_ccall trf_10209(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10209(t0,t1,t2);}

C_noret_decl(trf_10262)
static void C_ccall trf_10262(C_word c,C_word *av) C_noret;
static void C_ccall trf_10262(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10262(t0,t1,t2);}

C_noret_decl(trf_10342)
static void C_ccall trf_10342(C_word c,C_word *av) C_noret;
static void C_ccall trf_10342(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10342(t0,t1,t2);}

C_noret_decl(trf_10397)
static void C_ccall trf_10397(C_word c,C_word *av) C_noret;
static void C_ccall trf_10397(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10397(t0,t1,t2);}

C_noret_decl(trf_10431)
static void C_ccall trf_10431(C_word c,C_word *av) C_noret;
static void C_ccall trf_10431(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10431(t0,t1,t2);}

C_noret_decl(trf_10485)
static void C_ccall trf_10485(C_word c,C_word *av) C_noret;
static void C_ccall trf_10485(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10485(t0,t1,t2);}

C_noret_decl(trf_10521)
static void C_ccall trf_10521(C_word c,C_word *av) C_noret;
static void C_ccall trf_10521(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10521(t0,t1,t2);}

C_noret_decl(trf_10561)
static void C_ccall trf_10561(C_word c,C_word *av) C_noret;
static void C_ccall trf_10561(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10561(t0,t1,t2);}

C_noret_decl(trf_10606)
static void C_ccall trf_10606(C_word c,C_word *av) C_noret;
static void C_ccall trf_10606(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10606(t0,t1,t2);}

C_noret_decl(trf_10655)
static void C_ccall trf_10655(C_word c,C_word *av) C_noret;
static void C_ccall trf_10655(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_10655(t0,t1);}

C_noret_decl(trf_10733)
static void C_ccall trf_10733(C_word c,C_word *av) C_noret;
static void C_ccall trf_10733(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10733(t0,t1,t2);}

C_noret_decl(trf_10767)
static void C_ccall trf_10767(C_word c,C_word *av) C_noret;
static void C_ccall trf_10767(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10767(t0,t1,t2);}

C_noret_decl(trf_10837)
static void C_ccall trf_10837(C_word c,C_word *av) C_noret;
static void C_ccall trf_10837(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10837(t0,t1,t2);}

C_noret_decl(trf_10871)
static void C_ccall trf_10871(C_word c,C_word *av) C_noret;
static void C_ccall trf_10871(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10871(t0,t1,t2);}

C_noret_decl(trf_10911)
static void C_ccall trf_10911(C_word c,C_word *av) C_noret;
static void C_ccall trf_10911(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10911(t0,t1,t2);}

C_noret_decl(trf_10934)
static void C_ccall trf_10934(C_word c,C_word *av) C_noret;
static void C_ccall trf_10934(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10934(t0,t1,t2);}

C_noret_decl(trf_10990)
static void C_ccall trf_10990(C_word c,C_word *av) C_noret;
static void C_ccall trf_10990(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10990(t0,t1,t2);}

C_noret_decl(trf_11011)
static void C_ccall trf_11011(C_word c,C_word *av) C_noret;
static void C_ccall trf_11011(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11011(t0,t1,t2);}

C_noret_decl(trf_11019)
static void C_ccall trf_11019(C_word c,C_word *av) C_noret;
static void C_ccall trf_11019(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11019(t0,t1,t2);}

C_noret_decl(trf_11054)
static void C_ccall trf_11054(C_word c,C_word *av) C_noret;
static void C_ccall trf_11054(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11054(t0,t1,t2);}

C_noret_decl(trf_11085)
static void C_ccall trf_11085(C_word c,C_word *av) C_noret;
static void C_ccall trf_11085(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11085(t0,t1,t2);}

C_noret_decl(trf_11091)
static void C_ccall trf_11091(C_word c,C_word *av) C_noret;
static void C_ccall trf_11091(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11091(t0,t1,t2);}

C_noret_decl(trf_11132)
static void C_ccall trf_11132(C_word c,C_word *av) C_noret;
static void C_ccall trf_11132(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11132(t0,t1,t2);}

C_noret_decl(trf_11241)
static void C_ccall trf_11241(C_word c,C_word *av) C_noret;
static void C_ccall trf_11241(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11241(t0,t1,t2);}

C_noret_decl(trf_11321)
static void C_ccall trf_11321(C_word c,C_word *av) C_noret;
static void C_ccall trf_11321(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11321(t0,t1,t2);}

C_noret_decl(trf_11338)
static void C_ccall trf_11338(C_word c,C_word *av) C_noret;
static void C_ccall trf_11338(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_11338(t0,t1);}

C_noret_decl(trf_11362)
static void C_ccall trf_11362(C_word c,C_word *av) C_noret;
static void C_ccall trf_11362(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11362(t0,t1,t2);}

C_noret_decl(trf_11422)
static void C_ccall trf_11422(C_word c,C_word *av) C_noret;
static void C_ccall trf_11422(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_11422(t0,t1,t2,t3);}

C_noret_decl(trf_11434)
static void C_ccall trf_11434(C_word c,C_word *av) C_noret;
static void C_ccall trf_11434(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11434(t0,t1,t2);}

C_noret_decl(trf_11539)
static void C_ccall trf_11539(C_word c,C_word *av) C_noret;
static void C_ccall trf_11539(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_11539(t0,t1,t2,t3,t4);}

C_noret_decl(trf_11550)
static void C_ccall trf_11550(C_word c,C_word *av) C_noret;
static void C_ccall trf_11550(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11550(t0,t1,t2);}

C_noret_decl(trf_11563)
static void C_ccall trf_11563(C_word c,C_word *av) C_noret;
static void C_ccall trf_11563(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_11563(t0,t1);}

C_noret_decl(trf_11637)
static void C_ccall trf_11637(C_word c,C_word *av) C_noret;
static void C_ccall trf_11637(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11637(t0,t1,t2);}

C_noret_decl(trf_11671)
static void C_ccall trf_11671(C_word c,C_word *av) C_noret;
static void C_ccall trf_11671(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11671(t0,t1,t2);}

C_noret_decl(trf_11837)
static void C_ccall trf_11837(C_word c,C_word *av) C_noret;
static void C_ccall trf_11837(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11837(t0,t1,t2);}

C_noret_decl(trf_11891)
static void C_ccall trf_11891(C_word c,C_word *av) C_noret;
static void C_ccall trf_11891(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11891(t0,t1,t2);}

C_noret_decl(trf_11945)
static void C_ccall trf_11945(C_word c,C_word *av) C_noret;
static void C_ccall trf_11945(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11945(t0,t1,t2);}

C_noret_decl(trf_11999)
static void C_ccall trf_11999(C_word c,C_word *av) C_noret;
static void C_ccall trf_11999(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11999(t0,t1,t2);}

C_noret_decl(trf_12053)
static void C_ccall trf_12053(C_word c,C_word *av) C_noret;
static void C_ccall trf_12053(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12053(t0,t1,t2);}

C_noret_decl(trf_12107)
static void C_ccall trf_12107(C_word c,C_word *av) C_noret;
static void C_ccall trf_12107(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12107(t0,t1,t2);}

C_noret_decl(trf_12161)
static void C_ccall trf_12161(C_word c,C_word *av) C_noret;
static void C_ccall trf_12161(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12161(t0,t1,t2);}

C_noret_decl(trf_12215)
static void C_ccall trf_12215(C_word c,C_word *av) C_noret;
static void C_ccall trf_12215(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12215(t0,t1,t2);}

C_noret_decl(trf_12269)
static void C_ccall trf_12269(C_word c,C_word *av) C_noret;
static void C_ccall trf_12269(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12269(t0,t1,t2);}

C_noret_decl(trf_12323)
static void C_ccall trf_12323(C_word c,C_word *av) C_noret;
static void C_ccall trf_12323(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12323(t0,t1,t2);}

C_noret_decl(trf_12377)
static void C_ccall trf_12377(C_word c,C_word *av) C_noret;
static void C_ccall trf_12377(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12377(t0,t1,t2);}

C_noret_decl(trf_12431)
static void C_ccall trf_12431(C_word c,C_word *av) C_noret;
static void C_ccall trf_12431(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12431(t0,t1,t2);}

C_noret_decl(trf_12485)
static void C_ccall trf_12485(C_word c,C_word *av) C_noret;
static void C_ccall trf_12485(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12485(t0,t1,t2);}

C_noret_decl(trf_4888)
static void C_ccall trf_4888(C_word c,C_word *av) C_noret;
static void C_ccall trf_4888(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_4888(t0,t1,t2,t3);}

C_noret_decl(trf_4894)
static void C_ccall trf_4894(C_word c,C_word *av) C_noret;
static void C_ccall trf_4894(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4894(t0,t1,t2);}

C_noret_decl(trf_4969)
static void C_ccall trf_4969(C_word c,C_word *av) C_noret;
static void C_ccall trf_4969(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4969(t0,t1,t2);}

C_noret_decl(trf_5052)
static void C_ccall trf_5052(C_word c,C_word *av) C_noret;
static void C_ccall trf_5052(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5052(t0,t1,t2);}

C_noret_decl(trf_5061)
static void C_ccall trf_5061(C_word c,C_word *av) C_noret;
static void C_ccall trf_5061(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5061(t0,t1,t2);}

C_noret_decl(trf_5069)
static void C_ccall trf_5069(C_word c,C_word *av) C_noret;
static void C_ccall trf_5069(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_5069(t0,t1,t2,t3);}

C_noret_decl(trf_6071)
static void C_ccall trf_6071(C_word c,C_word *av) C_noret;
static void C_ccall trf_6071(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6071(t0,t1,t2);}

C_noret_decl(trf_6115)
static void C_ccall trf_6115(C_word c,C_word *av) C_noret;
static void C_ccall trf_6115(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6115(t0,t1,t2,t3);}

C_noret_decl(trf_6123)
static void C_ccall trf_6123(C_word c,C_word *av) C_noret;
static void C_ccall trf_6123(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6123(t0,t1,t2);}

C_noret_decl(trf_6219)
static void C_ccall trf_6219(C_word c,C_word *av) C_noret;
static void C_ccall trf_6219(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6219(t0,t1);}

C_noret_decl(trf_6241)
static void C_ccall trf_6241(C_word c,C_word *av) C_noret;
static void C_ccall trf_6241(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6241(t0,t1,t2);}

C_noret_decl(trf_6318)
static void C_ccall trf_6318(C_word c,C_word *av) C_noret;
static void C_ccall trf_6318(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6318(t0,t1,t2);}

C_noret_decl(trf_6370)
static void C_ccall trf_6370(C_word c,C_word *av) C_noret;
static void C_ccall trf_6370(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6370(t0,t1,t2);}

C_noret_decl(trf_6431)
static void C_ccall trf_6431(C_word c,C_word *av) C_noret;
static void C_ccall trf_6431(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6431(t0,t1,t2,t3);}

C_noret_decl(trf_6663)
static void C_ccall trf_6663(C_word c,C_word *av) C_noret;
static void C_ccall trf_6663(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6663(t0,t1,t2);}

C_noret_decl(trf_6670)
static void C_ccall trf_6670(C_word c,C_word *av) C_noret;
static void C_ccall trf_6670(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6670(t0,t1);}

C_noret_decl(trf_6821)
static void C_ccall trf_6821(C_word c,C_word *av) C_noret;
static void C_ccall trf_6821(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6821(t0,t1,t2,t3);}

C_noret_decl(trf_6844)
static void C_ccall trf_6844(C_word c,C_word *av) C_noret;
static void C_ccall trf_6844(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6844(t0,t1,t2);}

C_noret_decl(trf_6871)
static void C_ccall trf_6871(C_word c,C_word *av) C_noret;
static void C_ccall trf_6871(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6871(t0,t1,t2);}

C_noret_decl(trf_6908)
static void C_ccall trf_6908(C_word c,C_word *av) C_noret;
static void C_ccall trf_6908(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6908(t0,t1,t2);}

C_noret_decl(trf_6948)
static void C_ccall trf_6948(C_word c,C_word *av) C_noret;
static void C_ccall trf_6948(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6948(t0,t1,t2);}

C_noret_decl(trf_7025)
static void C_ccall trf_7025(C_word c,C_word *av) C_noret;
static void C_ccall trf_7025(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7025(t0,t1);}

C_noret_decl(trf_7043)
static void C_ccall trf_7043(C_word c,C_word *av) C_noret;
static void C_ccall trf_7043(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_7043(t0,t1,t2,t3,t4);}

C_noret_decl(trf_7071)
static void C_ccall trf_7071(C_word c,C_word *av) C_noret;
static void C_ccall trf_7071(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7071(t0,t1,t2);}

C_noret_decl(trf_7090)
static void C_ccall trf_7090(C_word c,C_word *av) C_noret;
static void C_ccall trf_7090(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7090(t0,t1,t2);}

C_noret_decl(trf_7118)
static void C_ccall trf_7118(C_word c,C_word *av) C_noret;
static void C_ccall trf_7118(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7118(t0,t1,t2,t3);}

C_noret_decl(trf_7201)
static void C_ccall trf_7201(C_word c,C_word *av) C_noret;
static void C_ccall trf_7201(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7201(t0,t1,t2);}

C_noret_decl(trf_7304)
static void C_ccall trf_7304(C_word c,C_word *av) C_noret;
static void C_ccall trf_7304(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7304(t0,t1);}

C_noret_decl(trf_7312)
static void C_ccall trf_7312(C_word c,C_word *av) C_noret;
static void C_ccall trf_7312(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7312(t0,t1);}

C_noret_decl(trf_7352)
static void C_ccall trf_7352(C_word c,C_word *av) C_noret;
static void C_ccall trf_7352(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7352(t0,t1);}

C_noret_decl(trf_7390)
static void C_ccall trf_7390(C_word c,C_word *av) C_noret;
static void C_ccall trf_7390(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7390(t0,t1,t2);}

C_noret_decl(trf_7438)
static void C_ccall trf_7438(C_word c,C_word *av) C_noret;
static void C_ccall trf_7438(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7438(t0,t1,t2);}

C_noret_decl(trf_7495)
static void C_ccall trf_7495(C_word c,C_word *av) C_noret;
static void C_ccall trf_7495(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7495(t0,t1,t2);}

C_noret_decl(trf_7537)
static void C_ccall trf_7537(C_word c,C_word *av) C_noret;
static void C_ccall trf_7537(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7537(t0,t1,t2);}

C_noret_decl(trf_7626)
static void C_ccall trf_7626(C_word c,C_word *av) C_noret;
static void C_ccall trf_7626(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7626(t0,t1,t2);}

C_noret_decl(trf_7651)
static void C_ccall trf_7651(C_word c,C_word *av) C_noret;
static void C_ccall trf_7651(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7651(t0,t1);}

C_noret_decl(trf_7739)
static void C_ccall trf_7739(C_word c,C_word *av) C_noret;
static void C_ccall trf_7739(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7739(t0,t1);}

C_noret_decl(trf_7834)
static void C_ccall trf_7834(C_word c,C_word *av) C_noret;
static void C_ccall trf_7834(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7834(t0,t1,t2);}

C_noret_decl(trf_7860)
static void C_ccall trf_7860(C_word c,C_word *av) C_noret;
static void C_ccall trf_7860(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7860(t0,t1,t2);}

C_noret_decl(trf_7914)
static void C_ccall trf_7914(C_word c,C_word *av) C_noret;
static void C_ccall trf_7914(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7914(t0,t1,t2);}

C_noret_decl(trf_7937)
static void C_ccall trf_7937(C_word c,C_word *av) C_noret;
static void C_ccall trf_7937(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7937(t0,t1,t2);}

C_noret_decl(trf_7992)
static void C_ccall trf_7992(C_word c,C_word *av) C_noret;
static void C_ccall trf_7992(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7992(t0,t1,t2);}

C_noret_decl(trf_8140)
static void C_ccall trf_8140(C_word c,C_word *av) C_noret;
static void C_ccall trf_8140(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8140(t0,t1,t2);}

C_noret_decl(trf_8164)
static void C_ccall trf_8164(C_word c,C_word *av) C_noret;
static void C_ccall trf_8164(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8164(t0,t1,t2);}

C_noret_decl(trf_8219)
static void C_ccall trf_8219(C_word c,C_word *av) C_noret;
static void C_ccall trf_8219(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_8219(t0,t1,t2,t3);}

C_noret_decl(trf_8230)
static void C_ccall trf_8230(C_word c,C_word *av) C_noret;
static void C_ccall trf_8230(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_8230(t0,t1);}

C_noret_decl(trf_8303)
static void C_ccall trf_8303(C_word c,C_word *av) C_noret;
static void C_ccall trf_8303(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8303(t0,t1,t2);}

C_noret_decl(trf_8323)
static void C_ccall trf_8323(C_word c,C_word *av) C_noret;
static void C_ccall trf_8323(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8323(t0,t1,t2);}

C_noret_decl(trf_8337)
static void C_ccall trf_8337(C_word c,C_word *av) C_noret;
static void C_ccall trf_8337(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8337(t0,t1,t2);}

C_noret_decl(trf_8340)
static void C_ccall trf_8340(C_word c,C_word *av) C_noret;
static void C_ccall trf_8340(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_8340(t0,t1);}

C_noret_decl(trf_8380)
static void C_ccall trf_8380(C_word c,C_word *av) C_noret;
static void C_ccall trf_8380(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8380(t0,t1,t2);}

C_noret_decl(trf_8525)
static void C_ccall trf_8525(C_word c,C_word *av) C_noret;
static void C_ccall trf_8525(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8525(t0,t1,t2);}

C_noret_decl(trf_8544)
static void C_ccall trf_8544(C_word c,C_word *av) C_noret;
static void C_ccall trf_8544(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8544(t0,t1,t2);}

C_noret_decl(trf_8572)
static void C_ccall trf_8572(C_word c,C_word *av) C_noret;
static void C_ccall trf_8572(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8572(t0,t1,t2);}

C_noret_decl(trf_8611)
static void C_ccall trf_8611(C_word c,C_word *av) C_noret;
static void C_ccall trf_8611(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8611(t0,t1,t2);}

C_noret_decl(trf_8638)
static void C_ccall trf_8638(C_word c,C_word *av) C_noret;
static void C_ccall trf_8638(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8638(t0,t1,t2);}

C_noret_decl(trf_8709)
static void C_ccall trf_8709(C_word c,C_word *av) C_noret;
static void C_ccall trf_8709(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8709(t0,t1,t2);}

C_noret_decl(trf_8757)
static void C_ccall trf_8757(C_word c,C_word *av) C_noret;
static void C_ccall trf_8757(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8757(t0,t1,t2);}

C_noret_decl(trf_8901)
static void C_ccall trf_8901(C_word c,C_word *av) C_noret;
static void C_ccall trf_8901(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8901(t0,t1,t2);}

C_noret_decl(trf_8964)
static void C_ccall trf_8964(C_word c,C_word *av) C_noret;
static void C_ccall trf_8964(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8964(t0,t1,t2);}

C_noret_decl(trf_8995)
static void C_ccall trf_8995(C_word c,C_word *av) C_noret;
static void C_ccall trf_8995(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8995(t0,t1,t2);}

C_noret_decl(trf_9005)
static void C_ccall trf_9005(C_word c,C_word *av) C_noret;
static void C_ccall trf_9005(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9005(t0,t1);}

C_noret_decl(trf_9038)
static void C_ccall trf_9038(C_word c,C_word *av) C_noret;
static void C_ccall trf_9038(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9038(t0,t1,t2);}

C_noret_decl(trf_9065)
static void C_ccall trf_9065(C_word c,C_word *av) C_noret;
static void C_ccall trf_9065(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9065(t0,t1,t2);}

C_noret_decl(trf_9131)
static void C_ccall trf_9131(C_word c,C_word *av) C_noret;
static void C_ccall trf_9131(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9131(t0,t1,t2);}

C_noret_decl(trf_9138)
static void C_ccall trf_9138(C_word c,C_word *av) C_noret;
static void C_ccall trf_9138(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9138(t0,t1);}

C_noret_decl(trf_9171)
static void C_ccall trf_9171(C_word c,C_word *av) C_noret;
static void C_ccall trf_9171(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9171(t0,t1,t2);}

C_noret_decl(trf_9256)
static void C_ccall trf_9256(C_word c,C_word *av) C_noret;
static void C_ccall trf_9256(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9256(t0,t1,t2);}

C_noret_decl(trf_9470)
static void C_ccall trf_9470(C_word c,C_word *av) C_noret;
static void C_ccall trf_9470(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9470(t0,t1,t2);}

C_noret_decl(trf_9500)
static void C_ccall trf_9500(C_word c,C_word *av) C_noret;
static void C_ccall trf_9500(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_9500(t0,t1,t2,t3);}

C_noret_decl(trf_9514)
static void C_ccall trf_9514(C_word c,C_word *av) C_noret;
static void C_ccall trf_9514(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9514(t0,t1,t2);}

C_noret_decl(trf_9558)
static void C_ccall trf_9558(C_word c,C_word *av) C_noret;
static void C_ccall trf_9558(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9558(t0,t1,t2);}

C_noret_decl(trf_9572)
static void C_ccall trf_9572(C_word c,C_word *av) C_noret;
static void C_ccall trf_9572(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9572(t0,t1,t2);}

C_noret_decl(trf_9607)
static void C_ccall trf_9607(C_word c,C_word *av) C_noret;
static void C_ccall trf_9607(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9607(t0,t1,t2);}

C_noret_decl(trf_9647)
static void C_ccall trf_9647(C_word c,C_word *av) C_noret;
static void C_ccall trf_9647(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9647(t0,t1,t2);}

C_noret_decl(trf_9703)
static void C_ccall trf_9703(C_word c,C_word *av) C_noret;
static void C_ccall trf_9703(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9703(t0,t1,t2);}

C_noret_decl(trf_9762)
static void C_ccall trf_9762(C_word c,C_word *av) C_noret;
static void C_ccall trf_9762(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_9762(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_9770)
static void C_ccall trf_9770(C_word c,C_word *av) C_noret;
static void C_ccall trf_9770(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9770(t0,t1,t2);}

C_noret_decl(trf_9793)
static void C_ccall trf_9793(C_word c,C_word *av) C_noret;
static void C_ccall trf_9793(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9793(t0,t1,t2);}

C_noret_decl(trf_9821)
static void C_ccall trf_9821(C_word c,C_word *av) C_noret;
static void C_ccall trf_9821(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9821(t0,t1,t2);}

C_noret_decl(trf_9843)
static void C_ccall trf_9843(C_word c,C_word *av) C_noret;
static void C_ccall trf_9843(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9843(t0,t1,t2);}

C_noret_decl(trf_9912)
static void C_ccall trf_9912(C_word c,C_word *av) C_noret;
static void C_ccall trf_9912(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_9912(t0,t1,t2,t3,t4);}

C_noret_decl(trf_9924)
static void C_ccall trf_9924(C_word c,C_word *av) C_noret;
static void C_ccall trf_9924(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_9924(t0,t1,t2,t3,t4);}

C_noret_decl(trf_9932)
static void C_ccall trf_9932(C_word c,C_word *av) C_noret;
static void C_ccall trf_9932(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9932(t0,t1,t2);}

C_noret_decl(trf_9955)
static void C_ccall trf_9955(C_word c,C_word *av) C_noret;
static void C_ccall trf_9955(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9955(t0,t1,t2);}

C_noret_decl(trf_9983)
static void C_ccall trf_9983(C_word c,C_word *av) C_noret;
static void C_ccall trf_9983(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9983(t0,t1,t2);}

/* f14085 in k6931 in g1224 in k7017 in loop2 in loop in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f14085(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f14085,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f14089 in g1224 in k7017 in loop2 in loop in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f14089(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f14089,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* g2344 in loopv in k9905 in a9902 in k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_fcall f_10024(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_10024,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_i_cdr(((C_word*)t0)[2]);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10036,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t3,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:755: delete */
f_4888(t4,C_i_car(t2),((C_word*)t0)[5],*((C_word*)lf[48]+1));}

/* k10034 in g2344 in loopv in k9905 in a9902 in k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_10036(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10036,c,av);}
/* modules.scm:755: loopv */
t2=((C_word*)((C_word*)t0)[2])[1];
f_9912(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10068(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_10068,c,av);}
a=C_alloc(9);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10071,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* modules.scm:759: ##sys#check-syntax */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[156]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[156]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=((C_word*)t0)[3];
av2[4]=lf[161];
tp(5,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_10318,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[9],tmp=(C_word)a,a+=9,tmp);
/* modules.scm:785: c */
t3=((C_word*)t0)[10];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[11];
av2[3]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}}

/* k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10071(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,8)))){
C_save_and_reclaim((void *)f_10071,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10076,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li128),tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10086,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[3],a[5]=((C_word)li136),tmp=(C_word)a,a+=6,tmp);
/* modules.scm:760: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[6];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a10075 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10076(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10076,c,av);}
/* modules.scm:760: outer */
t2=((C_word*)((C_word*)t0)[2])[1];
f_9703(t2,t1,C_i_cadr(((C_word*)t0)[3]));}

/* a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10086(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_10086,c,av);}
a=C_alloc(11);
t8=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_10090,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t4,a[5]=((C_word*)t0)[3],a[6]=t3,a[7]=t7,a[8]=t6,a[9]=t1,a[10]=t5,tmp=(C_word)a,a+=11,tmp);
/* modules.scm:761: chicken.syntax#strip-syntax */
t9=*((C_word*)lf[72]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=C_i_cddr(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* k10088 in a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10090(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,5)))){
C_save_and_reclaim((void *)f_10090,c,av);}
a=C_alloc(14);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_10095,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=t3,a[11]=((C_word)li135),tmp=(C_word)a,a+=12,tmp));
t5=((C_word*)t3)[1];
f_10095(t5,((C_word*)t0)[9],((C_word*)t0)[10],C_SCHEME_END_OF_LIST,t1);}

/* loopv in k10088 in a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_fcall f_10095(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(14,0,5)))){
C_save_and_reclaim_args((void *)trf_10095,5,t0,t1,t2,t3,t4);}
a=C_alloc(14);
if(C_truep(C_i_nullp(t2))){
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_10107,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t3,a[9]=((C_word*)t0)[8],a[10]=t6,a[11]=((C_word)li133),tmp=(C_word)a,a+=12,tmp));
t8=((C_word*)t6)[1];
f_10107(t8,t1,((C_word*)t0)[9],C_SCHEME_END_OF_LIST,t4);}
else{
t5=C_i_caar(t2);
t6=C_i_assq(t5,t4);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10262,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[10],a[5]=t4,a[6]=((C_word)li134),tmp=(C_word)a,a+=7,tmp);
/* modules.scm:763: g2449 */
t8=t7;
f_10262(t8,t1,t6);}
else{
t7=C_u_i_cdr(t2);
t8=C_u_i_car(t2);
t9=C_a_i_cons(&a,2,t8,t3);
/* modules.scm:784: loopv */
t11=t1;
t12=t7;
t13=t9;
t14=t4;
t1=t11;
t2=t12;
t3=t13;
t4=t14;
goto loop;}}}

/* loops in loopv in k10088 in a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_fcall f_10107(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
if(C_unlikely(!C_demand(C_calculate_demand(30,0,4)))){
C_save_and_reclaim_args((void *)trf_10107,5,t0,t1,t2,t3,t4);}
a=C_alloc(30);
if(C_truep(C_i_nullp(t2))){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10115,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li129),tmp=(C_word)a,a+=5,tmp);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=C_i_check_list_2(t4,lf[21]);
t11=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_10128,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=t1,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t3,a[10]=((C_word*)t0)[9],a[11]=t5,tmp=(C_word)a,a+=12,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10170,a[2]=t8,a[3]=t13,a[4]=t9,a[5]=((C_word)li131),tmp=(C_word)a,a+=6,tmp));
t15=((C_word*)t13)[1];
f_10170(t15,t11,t4);}
else{
t5=C_i_caar(t2);
t6=C_i_assq(t5,t4);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10209,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[10],a[5]=t4,a[6]=((C_word)li132),tmp=(C_word)a,a+=7,tmp);
/* modules.scm:765: g2444 */
t8=t7;
f_10209(t8,t1,t6);}
else{
t7=C_u_i_cdr(t2);
t8=C_u_i_car(t2);
t9=C_a_i_cons(&a,2,t8,t3);
/* modules.scm:777: loops */
t16=t1;
t17=t7;
t18=t9;
t19=t4;
t1=t16;
t2=t17;
t3=t18;
t4=t19;
goto loop;}}}

/* g2398 in loops in loopv in k10088 in a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_fcall f_10115(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_10115,3,t0,t1,t2);}
/* modules.scm:768: warn */
f_9500(t1,lf[160],((C_word*)t0)[3],t2);}

/* k10126 in loops in loopv in k10088 in a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_10128(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10128,c,av);}
a=C_alloc(18);
t2=C_i_check_list_2(t1,lf[36]);
t3=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_10134,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10147,a[2]=t5,a[3]=((C_word*)t0)[11],a[4]=((C_word)li130),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_10147(t7,t3,t1);}

/* k10132 in k10126 in loops in loopv in k10088 in a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in ... */
static void C_ccall f_10134(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,7)))){
C_save_and_reclaim((void *)f_10134,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_cons(&a,2,((C_word*)t0)[4],t2);
/* modules.scm:770: scheme#values */{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=0;
av2[1]=((C_word*)t0)[5];
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)t0)[7];
av2[4]=t3;
av2[5]=((C_word*)t0)[8];
av2[6]=((C_word*)t0)[9];
av2[7]=((C_word*)t0)[10];
C_values(8,av2);}}

/* for-each-loop2397 in k10126 in loops in loopv in k10088 in a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in ... */
static void C_fcall f_10147(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_10147,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10157,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:766: g2398 */
t4=((C_word*)t0)[3];
f_10115(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k10155 in for-each-loop2397 in k10126 in loops in loopv in k10088 in a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in ... */
static void C_ccall f_10157(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10157,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_10147(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* map-loop2410 in loops in loopv in k10088 in a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_fcall f_10170(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_10170,3,t0,t1,t2);}
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

/* g2444 in loops in loopv in k10088 in a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_fcall f_10209(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,4)))){
C_save_and_reclaim_args((void *)trf_10209,3,t0,t1,t2);}
a=C_alloc(12);
t3=C_i_cdr(((C_word*)t0)[2]);
t4=C_i_cadr(t2);
t5=C_i_cdar(((C_word*)t0)[2]);
t6=C_a_i_cons(&a,2,t4,t5);
t7=C_a_i_cons(&a,2,t6,((C_word*)t0)[3]);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10225,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t3,a[5]=t7,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:775: delete */
f_4888(t8,t2,((C_word*)t0)[5],*((C_word*)lf[48]+1));}

/* k10223 in g2444 in loops in loopv in k10088 in a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in ... */
static void C_ccall f_10225(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10225,c,av);}
/* modules.scm:773: loops */
t2=((C_word*)((C_word*)t0)[2])[1];
f_10107(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* g2449 in loopv in k10088 in a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_fcall f_10262(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,4)))){
C_save_and_reclaim_args((void *)trf_10262,3,t0,t1,t2);}
a=C_alloc(12);
t3=C_i_cdr(((C_word*)t0)[2]);
t4=C_i_cadr(t2);
t5=C_i_cdar(((C_word*)t0)[2]);
t6=C_a_i_cons(&a,2,t4,t5);
t7=C_a_i_cons(&a,2,t6,((C_word*)t0)[3]);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10278,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t3,a[5]=t7,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:782: delete */
f_4888(t8,t2,((C_word*)t0)[5],*((C_word*)lf[48]+1));}

/* k10276 in g2449 in loopv in k10088 in a10085 in k10069 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_10278(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10278,c,av);}
/* modules.scm:780: loopv */
t2=((C_word*)((C_word*)t0)[2])[1];
f_10095(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10318(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_10318,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10321,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* modules.scm:786: ##sys#check-syntax */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[156]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[156]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=((C_word*)t0)[3];
av2[4]=lf[163];
tp(5,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10474,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:796: chicken.syntax#strip-syntax */
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
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10321(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,8)))){
C_save_and_reclaim((void *)f_10321,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10326,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li137),tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10336,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[3],a[5]=((C_word)li141),tmp=(C_word)a,a+=6,tmp);
/* modules.scm:787: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[6];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a10325 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10326(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10326,c,av);}
/* modules.scm:787: outer */
t2=((C_word*)((C_word*)t0)[2])[1];
f_9703(t2,t1,C_i_cadr(((C_word*)t0)[3]));}

/* a10335 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10336(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_10336,c,av);}
a=C_alloc(11);
t8=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_10340,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t4,a[5]=t5,a[6]=t6,a[7]=t1,a[8]=t2,a[9]=t3,a[10]=t7,tmp=(C_word)a,a+=11,tmp);
/* modules.scm:788: chicken.syntax#strip-syntax */
t9=*((C_word*)lf[72]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=C_i_caddr(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* k10338 in a10335 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_10340(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(37,c,3)))){
C_save_and_reclaim((void *)f_10340,c,av);}
a=C_alloc(37);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10342,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word)li138),tmp=(C_word)a,a+=5,tmp);
t3=C_a_i_list(&a,3,((C_word*)t0)[3],((C_word*)t0)[4],t1);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_i_check_list_2(((C_word*)t0)[5],lf[21]);
t9=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_10385,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[9],a[6]=t3,a[7]=((C_word*)t0)[10],a[8]=t2,tmp=(C_word)a,a+=9,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10431,a[2]=t6,a[3]=t11,a[4]=t2,a[5]=t7,a[6]=((C_word)li140),tmp=(C_word)a,a+=7,tmp));
t13=((C_word*)t11)[1];
f_10431(t13,t9,((C_word*)t0)[5]);}

/* rename in k10338 in a10335 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_fcall f_10342(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,2)))){
C_save_and_reclaim_args((void *)trf_10342,3,t0,t1,t2);}
a=C_alloc(11);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10350,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10356,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10360,a[2]=t4,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:792: tostr */
t6=((C_word*)((C_word*)t0)[2])[1];
f_9514(t6,t5,((C_word*)t0)[3]);}

/* k10348 in rename in k10338 in a10335 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_10350(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_10350,c,av);}
a=C_alloc(3);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,t1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k10354 in rename in k10338 in a10335 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_10356(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10356,c,av);}
/* modules.scm:791: ##sys#string->symbol */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[162]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[162]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
tp(3,av2);}}

/* k10358 in rename in k10338 in a10335 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_10360(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_10360,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10364,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:792: ##sys#symbol->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[149]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[149]+1);
av2[1]=t2;
av2[2]=C_i_car(((C_word*)t0)[3]);
tp(3,av2);}}

/* k10362 in k10358 in rename in k10338 in a10335 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in ... */
static void C_ccall f_10364(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10364,c,av);}
/* modules.scm:792: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[143]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[143]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
tp(4,av2);}}

/* k10383 in k10338 in a10335 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_10385(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10385,c,av);}
a=C_alloc(22);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[21]);
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_10395,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=t1,a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10397,a[2]=t4,a[3]=t9,a[4]=((C_word*)t0)[8],a[5]=t5,a[6]=((C_word)li139),tmp=(C_word)a,a+=7,tmp));
t11=((C_word*)t9)[1];
f_10397(t11,t7,((C_word*)t0)[2]);}

/* k10393 in k10383 in k10338 in a10335 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_10395(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_10395,c,av);}
/* modules.scm:794: scheme#values */{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
av2[5]=((C_word*)t0)[6];
av2[6]=t1;
av2[7]=((C_word*)t0)[7];
C_values(8,av2);}}

/* map-loop2515 in k10383 in k10338 in a10335 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_fcall f_10397(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10397,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10422,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:794: g2521 */
t4=((C_word*)t0)[4];
f_10342(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10420 in map-loop2515 in k10383 in k10338 in a10335 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in ... */
static void C_ccall f_10422(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10422,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10397(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop2489 in k10338 in a10335 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_fcall f_10431(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10431,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10456,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:794: g2495 */
t4=((C_word*)t0)[4];
f_10342(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10454 in map-loop2489 in k10338 in a10335 in k10319 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_10456(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10456,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10431(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k10472 in k10316 in k10066 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10474(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10474,c,av);}
/* modules.scm:796: module-imports */
t2=((C_word*)t0)[2];
f_9647(t2,((C_word*)t0)[3],t1);}

/* ##sys#expand-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10480(C_word c,C_word *av){
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
C_word t9=av[9];
C_word t10;
C_word t11;
C_word *a;
if(c!=10) C_bad_argc_2(c,10,t0);
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_10480,c,av);}
a=C_alloc(11);
t10=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_10484,a[2]=t3,a[3]=t4,a[4]=t9,a[5]=t5,a[6]=t6,a[7]=t7,a[8]=t8,a[9]=t2,a[10]=t1,tmp=(C_word)a,a+=11,tmp);
/* modules.scm:799: ##sys#check-syntax */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[156]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[156]+1);
av2[1]=t10;
av2[2]=t9;
av2[3]=t2;
av2[4]=lf[173];
tp(5,av2);}}

/* k10482 in ##sys#expand-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10484(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(20,c,3)))){
C_save_and_reclaim((void *)f_10484,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_10485,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word)li147),tmp=(C_word)a,a+=10,tmp);
t3=C_i_cdr(((C_word*)t0)[9]);
t4=C_i_check_list_2(t3,lf[36]);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10519,a[2]=((C_word*)t0)[10],tmp=(C_word)a,a+=3,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10521,a[2]=t7,a[3]=t2,a[4]=((C_word)li148),tmp=(C_word)a,a+=5,tmp));
t9=((C_word*)t7)[1];
f_10521(t9,t5,t3);}

/* g2558 in k10482 in ##sys#expand-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_10485(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,0,8)))){
C_save_and_reclaim_args((void *)trf_10485,3,t0,t1,t2);}
a=C_alloc(16);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10491,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word)li145),tmp=(C_word)a,a+=7,tmp);
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_10497,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word)li146),tmp=(C_word)a,a+=9,tmp);
/* modules.scm:802: ##sys#call-with-values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}

/* a10490 in g2558 in k10482 in ##sys#expand-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10491(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_10491,c,av);}
/* modules.scm:802: ##sys#decompose-import */
t2=*((C_word*)lf[79]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
av2[5]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* a10496 in g2558 in k10482 in ##sys#expand-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10497(C_word c,C_word *av){
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
C_word *a;
if(c!=8) C_bad_argc_2(c,8,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,10)))){
C_save_and_reclaim((void *)f_10497,c,av);}
if(C_truep(C_i_not(t4))){
/* modules.scm:804: ##sys#syntax-error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[151]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[151]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[170];
av2[4]=t2;
av2[5]=((C_word*)t0)[3];
tp(6,av2);}}
else{
/* modules.scm:805: ##sys#import */
t8=*((C_word*)lf[171]+1);{
C_word *av2;
if(c >= 11) {
  av2=av;
} else {
  av2=C_alloc(11);
}
av2[0]=t8;
av2[1]=t1;
av2[2]=t4;
av2[3]=t5;
av2[4]=t6;
av2[5]=t7;
av2[6]=((C_word*)t0)[4];
av2[7]=((C_word*)t0)[5];
av2[8]=((C_word*)t0)[6];
av2[9]=((C_word*)t0)[7];
av2[10]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t8+1)))(11,av2);}}}

/* k10517 in k10482 in ##sys#expand-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10519(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10519,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[172];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* for-each-loop2557 in k10482 in ##sys#expand-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_10521(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_10521,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10531,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:800: g2558 */
t4=((C_word*)t0)[3];
f_10485(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k10529 in for-each-loop2557 in k10482 in ##sys#expand-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10531(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10531,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_10521(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10544(C_word c,C_word *av){
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
C_word t9=av[9];
C_word t10=av[10];
C_word t11;
C_word t12;
C_word *a;
if(c!=11) C_bad_argc_2(c,11,t0);
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_10544,c,av);}
a=C_alloc(12);
t11=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_10548,a[2]=t6,a[3]=t3,a[4]=t7,a[5]=t4,a[6]=t1,a[7]=t9,a[8]=t5,a[9]=t10,a[10]=t8,a[11]=t2,tmp=(C_word)a,a+=12,tmp);
/* modules.scm:810: ##sys#current-module */
t12=*((C_word*)lf[4]+1);{
C_word *av2=av;
av2[0]=t12;
av2[1]=t11;
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}

/* k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10548(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10548,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_10551,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
if(C_truep(t1)){
if(C_truep(((C_word*)t0)[10])){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10965,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_i_check_structure_2(t1,lf[6],lf[63]);
t5=C_i_block_ref(t1,C_fix(9));
t6=C_a_i_list1(&a,1,((C_word*)t0)[11]);
/* modules.scm:815: scheme#append */
t7=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t3;
av2[2]=t5;
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10980,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_i_check_structure_2(t1,lf[6],lf[62]);
t5=C_i_block_ref(t1,C_fix(8));
t6=C_a_i_list1(&a,1,((C_word*)t0)[11]);
/* modules.scm:818: scheme#append */
t7=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t3;
av2[2]=t5;
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_10551(2,av2);}}}

/* k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10551(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_10551,c,av);}
a=C_alloc(22);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10561,a[2]=((C_word*)t0)[2],a[3]=((C_word)li150),tmp=(C_word)a,a+=4,tmp);
t3=C_i_check_list_2(((C_word*)t0)[3],lf[36]);
t4=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_10605,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10934,a[2]=t6,a[3]=t2,a[4]=((C_word)li157),tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_10934(t8,t4,((C_word*)t0)[3]);}

/* g2619 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_10561(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_10561,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_i_car(t2);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10568,a[2]=t3,a[3]=t2,a[4]=t1,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:825: ##sys#put! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[176]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[176]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[135];
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k10566 in g2619 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10568(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_10568,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10599,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:826: import-env */
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k10597 in k10566 in g2619 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10599(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10599,c,av);}
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=C_u_i_cdr(((C_word*)t0)[3]);
if(C_truep(t3)){
t4=C_i_cdr(t2);
t5=C_eqp(t3,t4);
if(C_truep(C_i_not(t5))){
/* modules.scm:829: ##sys#notice */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[174]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[174]+1);
av2[1]=((C_word*)t0)[4];
av2[2]=lf[175];
av2[3]=((C_word*)t0)[2];
tp(4,av2);}}
else{
t6=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}
else{
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10605(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_10605,c,av);}
a=C_alloc(22);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10606,a[2]=((C_word*)t0)[2],a[3]=((C_word)li151),tmp=(C_word)a,a+=4,tmp);
t3=C_i_check_list_2(((C_word*)t0)[3],lf[36]);
t4=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_10652,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10911,a[2]=t6,a[3]=t2,a[4]=((C_word)li156),tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_10911(t8,t4,((C_word*)t0)[3]);}

/* g2629 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_10606(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_10606,3,t0,t1,t2);}
a=C_alloc(5);
t3=C_i_car(t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10613,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:834: ##sys#put! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[176]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[176]+1);
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[135];
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k10611 in g2629 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10613(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_10613,c,av);}
a=C_alloc(5);
t2=C_u_i_car(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10646,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:835: macro-env */
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* k10644 in k10611 in g2629 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10646(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10646,c,av);}
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=C_u_i_cdr(((C_word*)t0)[3]);
t4=C_i_cdr(t2);
t5=C_eqp(t3,t4);
if(C_truep(C_i_not(t5))){
/* modules.scm:837: ##sys#notice */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[174]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[174]+1);
av2[1]=((C_word*)t0)[4];
av2[2]=lf[177];
av2[3]=C_u_i_car(((C_word*)t0)[3]);
tp(4,av2);}}
else{
t6=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}
else{
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10652(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_10652,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10655,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)t0)[7])){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10680,a[2]=((C_word*)t0)[8],a[3]=t2,a[4]=((C_word*)t0)[9],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)t0)[8])){
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_10680(2,av2);}}
else{
/* modules.scm:841: ##sys#syntax-error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[151]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[151]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[10];
av2[3]=lf[178];
tp(4,av2);}}}
else{
t3=t2;
f_10655(t3,C_SCHEME_UNDEFINED);}}

/* k10653 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_10655(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,0,2)))){
C_save_and_reclaim_args((void *)trf_10655,2,t0,t1);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10658,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10673,a[2]=((C_word*)t0)[5],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10677,a[2]=t3,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:862: import-env */
t5=((C_word*)t0)[5];{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)C_fast_retrieve_proc(t5))(2,av2);}}

/* k10656 in k10653 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10658(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_10658,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10665,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10669,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:863: macro-env */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* k10663 in k10656 in k10653 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10665(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10665,c,av);}
/* modules.scm:863: macro-env */
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

/* k10667 in k10656 in k10653 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10669(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_10669,c,av);}
a=C_alloc(6);
/* modules.scm:863: merge-se */
f_7025(((C_word*)t0)[2],C_a_i_list(&a,2,t1,((C_word*)t0)[3]));}

/* k10671 in k10653 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10673(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10673,c,av);}
/* modules.scm:862: import-env */
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

/* k10675 in k10653 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10677(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_10677,c,av);}
a=C_alloc(6);
/* modules.scm:862: merge-se */
f_7025(((C_word*)t0)[2],C_a_i_list(&a,2,t1,((C_word*)t0)[3]));}

/* k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10680(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,3)))){
C_save_and_reclaim((void *)f_10680,c,av);}
a=C_alloc(27);
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[14]);
t3=C_i_block_ref(((C_word*)t0)[2],C_fix(3));
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10686,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t5=C_eqp(C_SCHEME_TRUE,t3);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10706,a[2]=((C_word*)t0)[2],a[3]=t4,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10803,a[2]=((C_word*)t0)[2],a[3]=t6,tmp=(C_word)a,a+=4,tmp);
t8=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[16]);
/* modules.scm:844: scheme#append */
t9=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t9;
av2[1]=t7;
av2[2]=((C_word*)t0)[5];
av2[3]=C_i_block_ref(((C_word*)t0)[2],C_fix(12));
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10814,a[2]=((C_word*)t0)[2],a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t7=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[14]);
t8=C_i_block_ref(((C_word*)t0)[2],C_fix(3));
t9=C_eqp(C_SCHEME_TRUE,t8);
t10=(C_truep(t9)?C_SCHEME_END_OF_LIST:t8);
t11=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t12=t11;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=((C_word*)t13)[1];
t15=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10828,a[2]=t6,a[3]=t10,a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
t16=C_SCHEME_UNDEFINED;
t17=(*a=C_VECTOR_TYPE|1,a[1]=t16,tmp=(C_word)a,a+=2,tmp);
t18=C_set_block_item(t17,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10871,a[2]=t13,a[3]=t17,a[4]=t14,a[5]=((C_word)li155),tmp=(C_word)a,a+=6,tmp));
t19=((C_word*)t17)[1];
f_10871(t19,t15,((C_word*)t0)[6]);}}

/* k10684 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10686(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10686,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10689,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10696,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_i_check_structure_2(((C_word*)t0)[3],lf[6],lf[69]);
t5=C_i_block_ref(((C_word*)t0)[3],C_fix(13));
/* modules.scm:860: merge-se */
f_7025(t3,C_a_i_list(&a,2,t5,((C_word*)t0)[4]));}

/* k10687 in k10684 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10689(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10689,c,av);}
t2=((C_word*)t0)[2];
f_10655(t2,C_SCHEME_UNDEFINED);}

/* k10694 in k10684 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10696(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10696,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(13);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k10704 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10706(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_10706,c,av);}
a=C_alloc(22);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10713,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[35]);
t4=C_i_block_ref(((C_word*)t0)[2],C_fix(5));
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10724,a[2]=t2,a[3]=t4,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10767,a[2]=t7,a[3]=t11,a[4]=t8,a[5]=((C_word)li153),tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_10767(t13,t9,((C_word*)t0)[5]);}

/* k10711 in k10704 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10713(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10713,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(5);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k10722 in k10704 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10724(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_10724,c,av);}
a=C_alloc(18);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10731,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10733,a[2]=t4,a[3]=t8,a[4]=t5,a[5]=((C_word)li152),tmp=(C_word)a,a+=6,tmp));
t10=((C_word*)t8)[1];
f_10733(t10,t6,((C_word*)t0)[4]);}

/* k10729 in k10722 in k10704 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10731(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10731,c,av);}
/* modules.scm:847: scheme#append */
t2=*((C_word*)lf[22]+1);{
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

/* map-loop2700 in k10722 in k10704 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_10733(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_10733,3,t0,t1,t2);}
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

/* map-loop2674 in k10704 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_10767(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_10767,3,t0,t1,t2);}
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

/* k10801 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10803(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10803,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(12);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k10812 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10814(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10814,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(3);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k10826 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10828(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_10828,c,av);}
a=C_alloc(18);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10835,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10837,a[2]=t4,a[3]=t8,a[4]=t5,a[5]=((C_word)li154),tmp=(C_word)a,a+=6,tmp));
t10=((C_word*)t8)[1];
f_10837(t10,t6,((C_word*)t0)[4]);}

/* k10833 in k10826 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10835(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10835,c,av);}
/* modules.scm:853: scheme#append */
t2=*((C_word*)lf[22]+1);{
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

/* map-loop2754 in k10826 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_10837(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_10837,3,t0,t1,t2);}
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

/* map-loop2728 in k10678 in k10650 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_10871(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_10871,3,t0,t1,t2);}
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

/* for-each-loop2628 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_10911(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_10911,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10921,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:831: g2629 */
t4=((C_word*)t0)[3];
f_10606(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k10919 in for-each-loop2628 in k10603 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10921(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10921,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_10911(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop2618 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_10934(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_10934,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10944,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:822: g2619 */
t4=((C_word*)t0)[3];
f_10561(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k10942 in for-each-loop2618 in k10549 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10944(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10944,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_10934(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k10963 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10965(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10965,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(9);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k10978 in k10546 in ##sys#import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10980(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10980,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(8);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* module-rename in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_10990(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,4)))){
C_save_and_reclaim_args((void *)trf_10990,3,t1,t2,t3);}
a=C_alloc(3);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10998,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* modules.scm:867: scheme#string-append */
t5=*((C_word*)lf[116]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t4;
av2[2]=C_slot(t3,C_fix(1));
av2[3]=lf[179];
av2[4]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k10996 in module-rename in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_10998(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10998,c,av);}
/* modules.scm:866: ##sys#string->symbol */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[162]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[162]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
tp(3,av2);}}

/* ##sys#alias-global-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11008(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_11008,c,av);}
a=C_alloc(10);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11011,a[2]=t3,a[3]=t4,a[4]=((C_word)li162),tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_u_i_namespaced_symbolp(t2))){
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11080,a[2]=t2,a[3]=t5,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:882: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[32]+1);
av2[1]=t6;
tp(2,av2);}}}

/* mrename in ##sys#alias-global-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11011(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_11011,3,t0,t1,t2);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11015,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:874: ##sys#current-module */
t4=*((C_word*)lf[4]+1);{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k11013 in mrename in ##sys#alias-global-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11015(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_11015,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11019,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li161),tmp=(C_word)a,a+=6,tmp);
/* modules.scm:874: g2811 */
t3=t2;
f_11019(t3,((C_word*)t0)[5],t1);}
else{
t2=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* g2811 in k11013 in mrename in ##sys#alias-global-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11019(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,3)))){
C_save_and_reclaim_args((void *)trf_11019,3,t0,t1,t2);}
a=C_alloc(11);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11026,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[3])){
t4=C_i_check_structure_2(t2,lf[6],lf[8]);
/* modules.scm:879: module-rename */
f_10990(t1,((C_word*)t0)[2],C_i_block_ref(t2,C_fix(1)));}
else{
if(C_truep(t2)){
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6656,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=t3,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:249: module-undefined-list */
t5=*((C_word*)lf[9]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t4=C_i_check_structure_2(t2,lf[6],lf[8]);
/* modules.scm:879: module-rename */
f_10990(t1,((C_word*)t0)[2],C_i_block_ref(t2,C_fix(1)));}}}

/* k11024 in g2811 in k11013 in mrename in ##sys#alias-global-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11026(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11026,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[8]);
/* modules.scm:879: module-rename */
f_10990(((C_word*)t0)[3],((C_word*)t0)[4],C_i_block_ref(((C_word*)t0)[2],C_fix(1)));}

/* g2822 in k11078 in ##sys#alias-global-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11054(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_11054,3,t0,t1,t2);}
t3=C_i_cdr(t2);
if(C_truep(C_i_pairp(t3))){
/* modules.scm:887: mrename */
t4=((C_word*)t0)[2];
f_11011(t4,t1,((C_word*)t0)[3]);}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k11078 in ##sys#alias-global-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11080(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_11080,c,av);}
a=C_alloc(5);
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11054,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word)li163),tmp=(C_word)a,a+=5,tmp);
/* modules.scm:881: g2822 */
t4=t3;
f_11054(t4,((C_word*)t0)[4],t2);}
else{
/* modules.scm:888: mrename */
t3=((C_word*)t0)[3];
f_11011(t3,((C_word*)t0)[4],((C_word*)t0)[2]);}}

/* ##sys#validate-exports in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11082(C_word c,C_word *av){
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
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_11082,c,av);}
a=C_alloc(22);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11085,a[2]=t3,a[3]=((C_word)li165),tmp=(C_word)a,a+=4,tmp));
t9=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11091,a[2]=t5,a[3]=t2,a[4]=((C_word)li166),tmp=(C_word)a,a+=5,tmp));
t10=C_eqp(lf[184],t2);
if(C_truep(t10)){
t11=t1;{
C_word *av2=av;
av2[0]=t11;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}
else{
if(C_truep(C_i_symbolp(t2))){
/* modules.scm:898: iface */
t11=((C_word*)t7)[1];
f_11091(t11,t1,t2);}
else{
t11=C_i_listp(t2);
if(C_truep(C_i_not(t11))){
/* modules.scm:900: err */
t12=((C_word*)t5)[1];
f_11085(t12,t1,C_a_i_list(&a,2,lf[185],t2));}
else{
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11132,a[2]=t5,a[3]=t2,a[4]=t13,a[5]=t7,a[6]=((C_word)li168),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_11132(t15,t1,t2);}}}}

/* err in ##sys#validate-exports in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11085(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_11085,3,t0,t1,t2);}{
C_word av2[5];
av2[0]=0;
av2[1]=t1;
av2[2]=*((C_word*)lf[151]+1);
av2[3]=((C_word*)t0)[2];
av2[4]=t2;
C_apply(5,av2);}}

/* iface in ##sys#validate-exports in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11091(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_11091,3,t0,t1,t2);}
a=C_alloc(9);
t3=C_i_getprop(t2,lf[182],C_SCHEME_FALSE);
if(C_truep(t3)){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* modules.scm:896: err */
t4=((C_word*)((C_word*)t0)[2])[1];
f_11085(t4,t1,C_a_i_list(&a,3,lf[183],t2,((C_word*)t0)[3]));}}

/* loop in ##sys#validate-exports in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11132(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,0,3)))){
C_save_and_reclaim_args((void *)trf_11132,3,t0,t1,t2);}
a=C_alloc(11);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_pairp(t2);
if(C_truep(C_i_not(t3))){
/* modules.scm:905: err */
t4=((C_word*)((C_word*)t0)[2])[1];
f_11085(t4,t1,C_a_i_list(&a,2,lf[186],((C_word*)t0)[3]));}
else{
t4=C_i_car(t2);
if(C_truep(C_i_symbolp(t4))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11164,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:908: loop */
t13=t5;
t14=C_u_i_cdr(t2);
t1=t13;
t2=t14;
goto loop;}
else{
t5=C_i_listp(t4);
if(C_truep(C_i_not(t5))){
/* modules.scm:910: err */
t6=((C_word*)((C_word*)t0)[2])[1];
f_11085(t6,t1,C_a_i_list(&a,3,lf[187],t4,((C_word*)t0)[3]));}
else{
t6=C_i_car(t4);
t7=C_eqp(lf[188],t6);
if(C_truep(t7)){
t8=C_u_i_cdr(t4);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11190,a[2]=t1,a[3]=t8,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:912: loop */
t13=t9;
t14=C_u_i_cdr(t2);
t1=t13;
t2=t14;
goto loop;}
else{
t8=C_eqp(lf[189],C_u_i_car(t4));
if(C_truep(t8)){
t9=C_i_pairp(C_u_i_cdr(t4));
t10=(C_truep(t9)?C_i_symbolp(C_i_cadr(t4)):C_SCHEME_FALSE);
if(C_truep(t10)){
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11211,a[2]=t1,a[3]=((C_word*)t0)[4],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:915: iface */
t12=((C_word*)((C_word*)t0)[5])[1];
f_11091(t12,t11,C_i_cadr(t4));}
else{
/* modules.scm:916: err */
t11=((C_word*)((C_word*)t0)[2])[1];
f_11085(t11,t1,C_a_i_list(&a,3,lf[190],t4,((C_word*)t0)[3]));}}
else{
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_11241,a[2]=t4,a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=t10,a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[3],a[8]=((C_word)li167),tmp=(C_word)a,a+=9,tmp));
t12=((C_word*)t10)[1];
f_11241(t12,t1,t4);}}}}}}}

/* k11162 in loop in ##sys#validate-exports in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11164(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_11164,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k11188 in loop in ##sys#validate-exports in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11190(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_11190,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k11209 in loop in ##sys#validate-exports in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11211(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_11211,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11215,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:915: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_11132(t3,t2,C_u_i_cdr(((C_word*)t0)[4]));}

/* k11213 in k11209 in loop in ##sys#validate-exports in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11215(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11215,c,av);}
/* modules.scm:915: scheme#append */
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

/* loop2 in loop in ##sys#validate-exports in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11241(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_11241,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t2))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11255,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:919: loop */
t4=((C_word*)((C_word*)t0)[3])[1];
f_11132(t4,t3,C_i_cdr(((C_word*)t0)[4]));}
else{
t3=C_i_car(t2);
if(C_truep(C_i_symbolp(t3))){
/* modules.scm:920: loop2 */
t5=t1;
t6=C_u_i_cdr(t2);
t1=t5;
t2=t6;
goto loop;}
else{
/* modules.scm:921: err */
t4=((C_word*)((C_word*)t0)[6])[1];
f_11085(t4,t1,C_a_i_list(&a,3,lf[191],((C_word*)t0)[2],((C_word*)t0)[7]));}}}

/* k11253 in loop2 in loop in ##sys#validate-exports in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11255(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_11255,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#register-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11297(C_word c,C_word *av){
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
if(c!=6) C_bad_argc_2(c,6,t0);
if(C_unlikely(!C_demand(C_calculate_demand(14,c,1)))){
C_save_and_reclaim((void *)f_11297,c,av);}
a=C_alloc(14);
t6=C_a_i_cons(&a,2,t4,t5);
t7=C_a_i_cons(&a,2,t3,t6);
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_a_i_putprop(&a,3,t2,lf[74],t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11313(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_11313,c,av);}
a=C_alloc(18);
t5=C_i_getprop(t3,lf[74],C_SCHEME_FALSE);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11321,a[2]=t2,a[3]=((C_word)li171),tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11328,a[2]=t5,a[3]=t2,a[4]=t4,a[5]=t3,a[6]=t6,a[7]=t1,tmp=(C_word)a,a+=8,tmp);
if(C_truep(t5)){
t8=t7;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_UNDEFINED;
f_11328(2,av2);}}
else{
/* modules.scm:930: err */
t8=t6;
f_11321(t8,t7,C_a_i_list(&a,2,lf[198],t3));}}

/* err in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11321(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_11321,3,t0,t1,t2);}{
C_word av2[5];
av2[0]=0;
av2[1]=t1;
av2[2]=*((C_word*)lf[151]+1);
av2[3]=((C_word*)t0)[2];
av2[4]=t2;
C_apply(5,av2);}}

/* k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11328(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11328,c,av);}
a=C_alloc(23);
t2=C_i_car(((C_word*)t0)[2]);
t3=C_i_cadr(((C_word*)t0)[2]);
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=C_u_i_cdr(t4);
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11338,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word)li173),tmp=(C_word)a,a+=8,tmp);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11401,a[2]=t3,a[3]=t5,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[7],tmp=(C_word)a,a+=6,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11422,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[5],a[4]=t6,a[5]=t9,a[6]=((C_word)li175),tmp=(C_word)a,a+=7,tmp));
t11=((C_word*)t9)[1];
f_11422(t11,t7,((C_word*)t0)[4],t2);}

/* merr in k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11338(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,0,3)))){
C_save_and_reclaim_args((void *)trf_11338,2,t0,t1);}
a=C_alloc(22);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(((C_word*)t0)[4],lf[21]);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11360,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11362,a[2]=t5,a[3]=t10,a[4]=t6,a[5]=((C_word)li172),tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_11362(t12,t8,((C_word*)t0)[4]);}

/* k11358 in merr in k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11360(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_11360,c,av);}
a=C_alloc(12);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
/* modules.scm:935: err */
t3=((C_word*)t0)[3];
f_11321(t3,((C_word*)t0)[4],C_a_i_list(&a,3,lf[194],((C_word*)t0)[5],t2));}

/* map-loop2900 in merr in k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11362(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_11362,3,t0,t1,t2);}
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

/* k11399 in k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11401(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,1)))){
C_save_and_reclaim((void *)f_11401,c,av);}
a=C_alloc(18);
t2=C_eqp(lf[184],((C_word*)t0)[2]);
t3=(C_truep(t2)?C_a_i_cons(&a,2,C_SCHEME_TRUE,((C_word*)t0)[3]):C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]));
t4=C_a_i_cons(&a,2,((C_word*)t0)[4],t3);
t5=C_a_i_cons(&a,2,lf[195],t4);
t6=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,3,lf[196],t1,t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* loop in k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11422(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,3)))){
C_save_and_reclaim_args((void *)trf_11422,4,t0,t1,t2,t3);}
a=C_alloc(10);
if(C_truep(C_i_nullp(t2))){
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11434,a[2]=t5,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word)li174),tmp=(C_word)a,a+=7,tmp));
t7=((C_word*)t5)[1];
f_11434(t7,t1,t3);}
else{
if(C_truep(C_i_nullp(t3))){
/* modules.scm:954: merr */
t4=((C_word*)t0)[4];
f_11338(t4,t1);}
else{
t4=C_i_car(t3);
t5=C_i_car(t4);
t6=C_u_i_cdr(t4);
t7=C_i_pairp(t5);
t8=(C_truep(t7)?C_i_car(t5):t5);
t9=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_11509,a[2]=t8,a[3]=t1,a[4]=((C_word*)t0)[5],a[5]=t2,a[6]=t3,a[7]=((C_word*)t0)[2],a[8]=t6,a[9]=((C_word*)t0)[3],tmp=(C_word)a,a+=10,tmp);
/* modules.scm:962: chicken.internal#library-id */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[26]+1);
av2[1]=t9;
av2[2]=C_i_car(t2);
tp(3,av2);}}}}

/* loop2 in loop in k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11434(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_11434,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=C_i_car(t3);
if(C_truep(C_i_pairp(t4))){
t5=C_u_i_cdr(t3);
t6=C_i_caar(t3);
t7=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_11457,a[2]=t6,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=t2,a[6]=((C_word*)t0)[3],a[7]=t5,a[8]=((C_word*)t0)[4],tmp=(C_word)a,a+=9,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11477,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
/* modules.scm:948: scheme#cadar */
t9=*((C_word*)lf[104]+1);{
C_word av2[3];
av2[0]=t9;
av2[1]=t8;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
/* modules.scm:952: merr */
t5=((C_word*)t0)[5];
f_11338(t5,t1);}}}

/* k11455 in loop2 in loop in k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11457(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_11457,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11460,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* modules.scm:949: match-functor-argument */
f_11539(t2,((C_word*)t0)[6],t1,((C_word*)t0)[7],((C_word*)t0)[8]);}

/* k11458 in k11455 in loop2 in loop in k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11460(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_11460,c,av);}
a=C_alloc(10);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11471,a[2]=((C_word*)t0)[4],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:950: loop2 */
t4=((C_word*)((C_word*)t0)[5])[1];
f_11434(t4,t3,C_u_i_cdr(((C_word*)t0)[6]));}

/* k11469 in k11458 in k11455 in loop2 in loop in k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11471(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_11471,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k11475 in loop2 in loop in k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11477(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11477,c,av);}
/* modules.scm:948: chicken.internal#library-id */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[26]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
tp(3,av2);}}

/* k11507 in loop in k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11509(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_11509,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11512,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* modules.scm:963: match-functor-argument */
f_11539(t2,((C_word*)t0)[7],t1,((C_word*)t0)[8],((C_word*)t0)[9]);}

/* k11510 in k11507 in loop in k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11512(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_11512,c,av);}
a=C_alloc(10);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11523,a[2]=((C_word*)t0)[4],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:965: loop */
t4=((C_word*)((C_word*)t0)[5])[1];
f_11422(t4,t3,C_u_i_cdr(((C_word*)t0)[6]),C_u_i_cdr(((C_word*)t0)[7]));}

/* k11521 in k11510 in k11507 in loop in k11326 in ##sys#instantiate-functor in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11523(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_11523,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11539(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,3)))){
C_save_and_reclaim_args((void *)trf_11539,5,t1,t2,t3,t4,t5);}
a=C_alloc(10);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11543,a[2]=t4,a[3]=t1,a[4]=t5,a[5]=t2,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11696,a[2]=t6,tmp=(C_word)a,a+=3,tmp);
/* modules.scm:972: ##sys#resolve-module-name */
t8=*((C_word*)lf[23]+1);{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=t3;
av2[3]=lf[6];
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}

/* k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11543(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11543,c,av);}
a=C_alloc(21);
t2=C_eqp(((C_word*)t0)[2],lf[184]);
if(C_truep(t2)){
t3=C_SCHEME_UNDEFINED;
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=C_SCHEME_END_OF_LIST;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11550,a[2]=t1,a[3]=t4,a[4]=((C_word)li177),tmp=(C_word)a,a+=5,tmp);
t6=C_i_check_list_2(((C_word*)t0)[2],lf[36]);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11590,a[2]=t4,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11671,a[2]=t9,a[3]=t5,a[4]=((C_word)li179),tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_11671(t11,t7,((C_word*)t0)[2]);}}

/* g2961 in k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11550(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_11550,3,t0,t1,t2);}
a=C_alloc(5);
t3=C_i_symbolp(t2);
t4=(C_truep(t3)?t2:C_i_car(t2));
t5=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[15]);
t6=C_i_block_ref(((C_word*)t0)[2],C_fix(11));
t7=C_i_assq(t4,t6);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11563,a[2]=t1,a[3]=t4,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t7)){
t9=t8;
f_11563(t9,t7);}
else{
t9=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[16]);
t10=t8;
f_11563(t10,C_i_assq(t4,C_i_block_ref(((C_word*)t0)[2],C_fix(12))));}}

/* k11561 in g2961 in k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11563(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,1)))){
C_save_and_reclaim_args((void *)trf_11563,2,t0,t1);}
a=C_alloc(3);
if(C_truep(t1)){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[4])+1,t2);
t4=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k11588 in k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11590(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_11590,c,av);}
a=C_alloc(9);
if(C_truep(C_i_pairp(((C_word*)((C_word*)t0)[2])[1]))){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11603,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11607,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:987: scheme#symbol->string */
t4=*((C_word*)lf[119]+1);{
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
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k11601 in k11588 in k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11603(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11603,c,av);}
/* modules.scm:983: ##sys#syntax-error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[151]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[151]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[6];
av2[3]=t1;
tp(4,av2);}}

/* k11605 in k11588 in k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11607(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_11607,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11611,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:988: scheme#symbol->string */
t3=*((C_word*)lf[119]+1);{
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

/* k11609 in k11605 in k11588 in k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11611(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_11611,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11615,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:989: scheme#symbol->string */
t3=*((C_word*)lf[119]+1);{
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

/* k11613 in k11609 in k11605 in k11588 in k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11615(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11615,c,av);}
a=C_alloc(19);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=((C_word*)((C_word*)t0)[2])[1];
t7=C_i_check_list_2(t6,lf[21]);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11635,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11637,a[2]=t4,a[3]=t10,a[4]=t5,a[5]=((C_word)li178),tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_11637(t12,t8,t6);}

/* k11627 in map-loop2982 in k11613 in k11609 in k11605 in k11588 in k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11629(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11629,c,av);}
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[143]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[143]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[204];
av2[3]=t1;
tp(4,av2);}}

/* k11633 in k11613 in k11609 in k11605 in k11588 in k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11635(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,11)))){
C_save_and_reclaim((void *)f_11635,c,av);}{
C_word *av2;
if(c >= 12) {
  av2=av;
} else {
  av2=C_alloc(12);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[116]+1);
av2[3]=lf[199];
av2[4]=((C_word*)t0)[3];
av2[5]=lf[200];
av2[6]=lf[201];
av2[7]=((C_word*)t0)[4];
av2[8]=lf[202];
av2[9]=((C_word*)t0)[5];
av2[10]=lf[203];
av2[11]=t1;
C_apply(12,av2);}}

/* map-loop2982 in k11613 in k11609 in k11605 in k11588 in k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11637(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_11637,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11662,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11629,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* modules.scm:990: scheme#symbol->string */
t6=*((C_word*)lf[119]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k11660 in map-loop2982 in k11613 in k11609 in k11605 in k11588 in k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11662(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11662,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_11637(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* for-each-loop2960 in k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_11671(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_11671,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11681,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:975: g2961 */
t4=((C_word*)t0)[3];
f_11550(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k11679 in for-each-loop2960 in k11541 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11681(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11681,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_11671(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k11694 in match-functor-argument in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11696(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11696,c,av);}
/* modules.scm:972: ##sys#find-module */
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
av2[4]=lf[6];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11699(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_11699,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11702,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12528,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:1125: scheme#append */
t4=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[274];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11702(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_11702,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11705,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:1131: ##sys#register-core-module */
t3=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[273];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11705(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_11705,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11708,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:1132: ##sys#register-core-module */
t3=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[272];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11708(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_11708,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11711,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:1134: ##sys#register-module-alias */
t3=*((C_word*)lf[18]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[270];
av2[3]=lf[271];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11711(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_11711,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11714,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12524,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* modules.scm:1140: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t3;
tp(2,av2);}}

/* k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11714(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_11714,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11717,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:1142: ##sys#register-primitive-module */
t3=*((C_word*)lf[88]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[267];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=*((C_word*)lf[268]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11717(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_11717,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11720,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:1145: ##sys#register-primitive-module */
t3=*((C_word*)lf[88]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[265];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=*((C_word*)lf[266]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11720(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11720,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11723,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12520,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=lf[264];
t5=*((C_word*)lf[241]+1);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12473,a[2]=t5,a[3]=((C_word)li206),tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12485,a[2]=t10,a[3]=t8,a[4]=t13,a[5]=t9,a[6]=((C_word)li207),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_12485(t15,t3,t4);}

/* k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11723(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11723,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11726,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12466,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=lf[262];
t5=*((C_word*)lf[218]+1);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12419,a[2]=t5,a[3]=((C_word)li204),tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12431,a[2]=t10,a[3]=t8,a[4]=t13,a[5]=t9,a[6]=((C_word)li205),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_12431(t15,t3,t4);}

/* k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11726(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_11726,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11729,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:1154: ##sys#register-core-module */
t3=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[259];
av2[3]=lf[216];
av2[4]=lf[260];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11729(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11729,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11732,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12412,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=lf[258];
t5=*((C_word*)lf[218]+1);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12365,a[2]=t5,a[3]=((C_word)li202),tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12377,a[2]=t10,a[3]=t8,a[4]=t13,a[5]=t9,a[6]=((C_word)li203),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_12377(t15,t3,t4);}

/* k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11732(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11732,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11735,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12358,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=lf[256];
t5=*((C_word*)lf[218]+1);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12311,a[2]=t5,a[3]=((C_word)li200),tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12323,a[2]=t10,a[3]=t8,a[4]=t13,a[5]=t9,a[6]=((C_word)li201),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_12323(t15,t3,t4);}

/* k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_11735(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_11735,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11738,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:1166: ##sys#register-core-module */
t3=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[252];
av2[3]=lf[253];
av2[4]=lf[254];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_11738(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11738,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11741,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12304,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=lf[251];
t5=*((C_word*)lf[218]+1);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12257,a[2]=t5,a[3]=((C_word)li198),tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12269,a[2]=t10,a[3]=t8,a[4]=t13,a[5]=t9,a[6]=((C_word)li199),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_12269(t15,t3,t4);}

/* k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_11741(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11741,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11744,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12250,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=lf[248];
t5=*((C_word*)lf[249]+1);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12203,a[2]=t5,a[3]=((C_word)li196),tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12215,a[2]=t10,a[3]=t8,a[4]=t13,a[5]=t9,a[6]=((C_word)li197),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_12215(t15,t3,t4);}

/* k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_11744(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11744,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11747,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12196,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=lf[245];
t5=*((C_word*)lf[218]+1);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12149,a[2]=t5,a[3]=((C_word)li194),tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12161,a[2]=t10,a[3]=t8,a[4]=t13,a[5]=t9,a[6]=((C_word)li195),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_12161(t15,t3,t4);}

/* k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in ... */
static void C_ccall f_11747(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11747,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11750,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12142,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=lf[243];
t5=*((C_word*)lf[218]+1);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12095,a[2]=t5,a[3]=((C_word)li192),tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12107,a[2]=t10,a[3]=t8,a[4]=t13,a[5]=t9,a[6]=((C_word)li193),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_12107(t15,t3,t4);}

/* k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in ... */
static void C_ccall f_11750(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11750,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11753,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12088,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=lf[240];
t5=*((C_word*)lf[241]+1);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12041,a[2]=t5,a[3]=((C_word)li190),tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12053,a[2]=t10,a[3]=t8,a[4]=t13,a[5]=t9,a[6]=((C_word)li191),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_12053(t15,t3,t4);}

/* k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in ... */
static void C_ccall f_11753(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_11753,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11756,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:1197: ##sys#register-core-module */
t3=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[236];
av2[3]=lf[216];
av2[4]=lf[237];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in ... */
static void C_ccall f_11756(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11756,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11759,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12034,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=lf[235];
t5=*((C_word*)lf[218]+1);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11987,a[2]=t5,a[3]=((C_word)li188),tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11999,a[2]=t10,a[3]=t8,a[4]=t13,a[5]=t9,a[6]=((C_word)li189),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_11999(t15,t3,t4);}

/* k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in ... */
static void C_ccall f_11759(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_11759,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11762,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:1203: ##sys#register-core-module */
t3=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[231];
av2[3]=lf[232];
av2[4]=lf[233];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in ... */
static void C_ccall f_11762(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11762,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11765,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11980,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=lf[230];
t5=*((C_word*)lf[218]+1);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11933,a[2]=t5,a[3]=((C_word)li186),tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11945,a[2]=t10,a[3]=t8,a[4]=t13,a[5]=t9,a[6]=((C_word)li187),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_11945(t15,t3,t4);}

/* k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in ... */
static void C_ccall f_11765(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11765,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11768,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11926,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=lf[228];
t5=*((C_word*)lf[218]+1);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11879,a[2]=t5,a[3]=((C_word)li184),tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11891,a[2]=t10,a[3]=t8,a[4]=t13,a[5]=t9,a[6]=((C_word)li185),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_11891(t15,t3,t4);}

/* k11766 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in ... */
static void C_ccall f_11768(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11768,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11771,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11872,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=lf[225];
t5=*((C_word*)lf[218]+1);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11825,a[2]=t5,a[3]=((C_word)li182),tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11837,a[2]=t10,a[3]=t8,a[4]=t13,a[5]=t9,a[6]=((C_word)li183),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_11837(t15,t3,t4);}

/* k11769 in k11766 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in ... */
static void C_ccall f_11771(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_11771,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11774,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:1216: ##sys#register-core-module */
t3=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[222];
av2[3]=lf[216];
av2[4]=lf[223];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k11772 in k11769 in k11766 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in ... */
static void C_ccall f_11774(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_11774,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11777,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:1222: ##sys#register-core-module */
t3=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[219];
av2[3]=lf[220];
av2[4]=lf[221];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k11775 in k11772 in k11769 in k11766 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in ... */
static void C_ccall f_11777(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_11777,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[207]+1 /* (set! chicken.module#module-environment ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11779,a[2]=((C_word)li181),tmp=(C_word)a,a+=3,tmp));
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11815,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken.base.import.scm:26: ##sys#register-core-module */
t4=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[215];
av2[3]=lf[216];
av2[4]=lf[217];
av2[5]=*((C_word*)lf[218]+1);
((C_proc)(void*)(*((C_word*)t4+1)))(6,av2);}}

/* chicken.module#module-environment in k11775 in k11772 in k11769 in k11766 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in ... */
static void C_ccall f_11779(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_11779,c,av);}
a=C_alloc(5);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?t2:C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11786,a[2]=t1,a[3]=t2,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:1228: find-module/import-library */
f_9470(t5,t2,lf[208]);}

/* k11784 in chicken.module#module-environment in k11775 in k11772 in k11769 in k11766 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in ... */
static void C_ccall f_11786(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_11786,c,av);}
a=C_alloc(5);
if(C_truep(C_i_not(t1))){
/* modules.scm:1230: ##sys#syntax-error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[151]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[151]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[208];
av2[3]=lf[209];
av2[4]=((C_word*)t0)[3];
tp(5,av2);}}
else{
t2=C_i_check_structure_2(t1,lf[6],lf[33]);
t3=C_i_block_ref(t1,C_fix(14));
t4=C_i_car(t3);
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_record4(&a,4,lf[210],((C_word*)t0)[4],t4,C_SCHEME_TRUE);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k11813 in k11775 in k11772 in k11769 in k11766 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in ... */
static void C_ccall f_11815(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_11815,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11818,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken.syntax.import.scm:30: ##sys#register-core-module */
t3=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[211];
av2[3]=lf[212];
av2[4]=lf[213];
av2[5]=*((C_word*)lf[214]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k11816 in k11813 in k11775 in k11772 in k11769 in k11766 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in ... */
static void C_ccall f_11818(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11818,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* g3481 in k11766 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in ... */
static C_word C_fcall f_11825(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* map-loop3475 in k11766 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in ... */
static void C_fcall f_11837(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_11837,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:1136: g3481 */
  f_11825(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k11870 in k11766 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in ... */
static void C_ccall f_11872(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11872,c,av);}
/* modules.scm:1213: ##sys#register-primitive-module */
t2=*((C_word*)lf[88]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[224];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* g3443 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in ... */
static C_word C_fcall f_11879(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* map-loop3437 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in ... */
static void C_fcall f_11891(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_11891,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:1136: g3443 */
  f_11879(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k11924 in k11763 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in ... */
static void C_ccall f_11926(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_11926,c,av);}
/* modules.scm:1209: ##sys#register-core-module */
t2=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[226];
av2[3]=lf[216];
av2[4]=lf[227];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* g3405 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in ... */
static C_word C_fcall f_11933(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* map-loop3399 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in ... */
static void C_fcall f_11945(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_11945,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:1136: g3405 */
  f_11933(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k11978 in k11760 in k11757 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in ... */
static void C_ccall f_11980(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11980,c,av);}
/* modules.scm:1206: ##sys#register-primitive-module */
t2=*((C_word*)lf[88]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[229];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* g3367 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in ... */
static C_word C_fcall f_11987(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* map-loop3361 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in ... */
static void C_fcall f_11999(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_11999,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:1136: g3367 */
  f_11987(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k12032 in k11754 in k11751 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in ... */
static void C_ccall f_12034(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12034,c,av);}
/* modules.scm:1200: ##sys#register-primitive-module */
t2=*((C_word*)lf[88]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[234];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* g3329 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in ... */
static C_word C_fcall f_12041(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* map-loop3323 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in ... */
static void C_fcall f_12053(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_12053,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:1136: g3329 */
  f_12041(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k12086 in k11748 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in ... */
static void C_ccall f_12088(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_12088,c,av);}
/* modules.scm:1191: ##sys#register-core-module */
t2=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[238];
av2[3]=lf[216];
av2[4]=lf[239];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* g3291 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in ... */
static C_word C_fcall f_12095(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* map-loop3285 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in ... */
static void C_fcall f_12107(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_12107,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:1136: g3291 */
  f_12095(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k12140 in k11745 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in ... */
static void C_ccall f_12142(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12142,c,av);}
/* modules.scm:1188: ##sys#register-primitive-module */
t2=*((C_word*)lf[88]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[242];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* g3253 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in ... */
static C_word C_fcall f_12149(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* map-loop3247 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in ... */
static void C_fcall f_12161(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_12161,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:1136: g3253 */
  f_12149(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k12194 in k11742 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in ... */
static void C_ccall f_12196(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12196,c,av);}
/* modules.scm:1185: ##sys#register-primitive-module */
t2=*((C_word*)lf[88]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[244];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* g3215 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static C_word C_fcall f_12203(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* map-loop3209 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_fcall f_12215(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_12215,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:1136: g3215 */
  f_12203(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k12248 in k11739 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_12250(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_12250,c,av);}
/* modules.scm:1172: ##sys#register-core-module */
t2=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[246];
av2[3]=lf[216];
av2[4]=lf[247];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* g3177 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static C_word C_fcall f_12257(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* map-loop3171 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_fcall f_12269(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_12269,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:1136: g3177 */
  f_12257(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k12302 in k11736 in k11733 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_12304(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12304,c,av);}
/* modules.scm:1169: ##sys#register-primitive-module */
t2=*((C_word*)lf[88]+1);{
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

/* g3139 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static C_word C_fcall f_12311(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* map-loop3133 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_12323(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_12323,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:1136: g3139 */
  f_12311(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k12356 in k11730 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_12358(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12358,c,av);}
/* modules.scm:1163: ##sys#register-primitive-module */
t2=*((C_word*)lf[88]+1);{
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

/* g3101 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static C_word C_fcall f_12365(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* map-loop3095 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_12377(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_12377,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:1136: g3101 */
  f_12365(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k12410 in k11727 in k11724 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_12412(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12412,c,av);}
/* modules.scm:1160: ##sys#register-primitive-module */
t2=*((C_word*)lf[88]+1);{
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

/* g3063 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static C_word C_fcall f_12419(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* map-loop3057 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_12431(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_12431,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:1136: g3063 */
  f_12419(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k12464 in k11721 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_12466(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12466,c,av);}
/* modules.scm:1151: ##sys#register-primitive-module */
t2=*((C_word*)lf[88]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[261];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* g3025 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static C_word C_fcall f_12473(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* map-loop3019 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_12485(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_12485,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:1136: g3025 */
  f_12473(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k12518 in k11718 in k11715 in k11712 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_12520(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12520,c,av);}
/* modules.scm:1148: ##sys#register-primitive-module */
t2=*((C_word*)lf[88]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[263];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k12522 in k11709 in k11706 in k11703 in k11700 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_12524(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12524,c,av);}
/* modules.scm:1139: ##sys#register-primitive-module */
t2=*((C_word*)lf[88]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[269];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k12526 in k11697 in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_12528(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_12528,c,av);}
/* modules.scm:1123: ##sys#register-core-module */
t2=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[271];
av2[3]=lf[216];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k4380 */
static void C_ccall f_4382(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_4382,c,av);}
a=C_alloc(11);
t2=C_a_i_provide(&a,1,lf[0]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4385,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t3;
C_library_toplevel(2,av2);}}

/* k4383 in k4380 */
static void C_ccall f_4385(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4385,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4388,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_internal_toplevel(2,av2);}}

/* k4386 in k4383 in k4380 */
static void C_ccall f_4388(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4388,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4391,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_expand_toplevel(2,av2);}}

/* k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_4391(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4391,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4394,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

/* k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_4394(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4394,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4397,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_4397(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_4397,c,av);}
a=C_alloc(9);
t2=C_mutate(&lf[1] /* (set! delete ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4888,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t3=C_mutate(&lf[2] /* (set! filter-map ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5052,a[2]=((C_word)li5),tmp=(C_word)a,a+=3,tmp));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5679,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:77: chicken.base#make-parameter */
t5=*((C_word*)lf[276]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* delete in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_4888(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_4888,4,t1,t2,t3,t4);}
a=C_alloc(8);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4894,a[2]=t6,a[3]=t4,a[4]=t2,a[5]=((C_word)li0),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_4894(t8,t1,t3);}

/* loop in delete in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_4894(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_4894,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4907,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* mini-srfi-1.scm:106: test */
t4=((C_word*)t0)[3];{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
av2[3]=C_i_car(t2);
((C_proc)C_fast_retrieve_proc(t4))(4,av2);}}}

/* k4905 in loop in delete in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_4907(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4907,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
/* mini-srfi-1.scm:107: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_4894(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}
else{
t2=C_u_i_car(((C_word*)t0)[4]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4921,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:109: loop */
t4=((C_word*)((C_word*)t0)[2])[1];
f_4894(t4,t3,C_u_i_cdr(((C_word*)t0)[4]));}}

/* k4919 in k4905 in loop in delete in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_4921(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_4921,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in k7180 in k7737 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_4969(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_4969,3,t0,t1,t2);}
a=C_alloc(10);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=C_u_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4983,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4996,a[2]=((C_word*)t0)[2],a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:123: delete */
f_4888(t6,t3,t4,((C_word*)t0)[3]);}}

/* k4981 in loop in k7180 in k7737 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_4983(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_4983,c,av);}
a=C_alloc(3);
t2=C_i_equalp(((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?((C_word*)t0)[4]:C_a_i_cons(&a,2,((C_word*)t0)[5],t1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4994 in loop in k7180 in k7737 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_4996(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4996,c,av);}
/* mini-srfi-1.scm:123: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_4969(t2,((C_word*)t0)[3],t1);}

/* filter-map in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_5052(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_5052,3,t1,t2,t3);}
a=C_alloc(7);
t4=C_i_check_list_2(t3,lf[3]);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5061,a[2]=t2,a[3]=t6,a[4]=((C_word)li4),tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_5061(t8,t1,t3);}

/* foldr334 in filter-map in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_5061(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_5061,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5069,a[2]=((C_word*)t0)[2],a[3]=((C_word)li3),tmp=(C_word)a,a+=4,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5095,a[2]=t3,a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
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

/* g339 in foldr334 in filter-map in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_5069(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_5069,4,t0,t1,t2,t3);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5073,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:135: pred */
t5=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}

/* k5071 in g339 in foldr334 in filter-map in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_5073(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_5073,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5077,a[2]=((C_word*)t0)[2],a[3]=((C_word)li2),tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:135: g349 */
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
/* mini-srfi-1.scm:135: g349 */
  f_5077(C_a_i(&a,3),t2,t1)
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* g349 in k5071 in g339 in foldr334 in filter-map in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static C_word C_fcall f_5077(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_a_i_cons(&a,2,t1,((C_word*)t0)[2]));}

/* k5093 in foldr334 in filter-map in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_5095(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5095,c,av);}
/* mini-srfi-1.scm:134: g339 */
t2=((C_word*)t0)[2];
f_5069(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_5679(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5679,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[4]+1 /* (set! ##sys#current-module ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5683,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:78: chicken.base#make-parameter */
t4=*((C_word*)lf[276]+1);{
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

/* k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_5683(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(122,c,11)))){
C_save_and_reclaim((void *)f_5683,c,av);}
a=C_alloc(122);
t2=C_mutate((C_word*)lf[5]+1 /* (set! ##sys#module-alias-environment ...) */,t1);
t3=C_mutate((C_word*)lf[6]+1 /* (set! module ...) */,lf[6]);
t4=C_mutate(&lf[7] /* (set! module-name ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5698,a[2]=((C_word)li6),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[9]+1 /* (set! module-undefined-list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5788,a[2]=((C_word)li7),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[10]+1 /* (set! set-module-undefined-list! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5797,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[12]+1 /* (set! ##sys#module-name ...) */,lf[7]);
t8=C_mutate((C_word*)lf[13]+1 /* (set! ##sys#module-exports ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5951,a[2]=((C_word)li9),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate(&lf[17] /* (set! make-module ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5969,a[2]=((C_word)li10),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[18]+1 /* (set! ##sys#register-module-alias ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5984,a[2]=((C_word)li11),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[19]+1 /* (set! ##sys#with-module-aliases ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6002,a[2]=((C_word)li16),tmp=(C_word)a,a+=3,tmp));
t12=C_mutate((C_word*)lf[23]+1 /* (set! ##sys#resolve-module-name ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6105,a[2]=((C_word)li19),tmp=(C_word)a,a+=3,tmp));
t13=C_mutate((C_word*)lf[27]+1 /* (set! ##sys#find-module ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6152,a[2]=((C_word)li20),tmp=(C_word)a,a+=3,tmp));
t14=C_SCHEME_FALSE;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=C_mutate((C_word*)lf[30]+1 /* (set! ##sys#switch-module ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6206,a[2]=t15,a[3]=((C_word)li22),tmp=(C_word)a,a+=4,tmp));
t17=C_mutate((C_word*)lf[34]+1 /* (set! ##sys#add-to-export-list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6259,a[2]=((C_word)li26),tmp=(C_word)a,a+=3,tmp));
t18=C_mutate((C_word*)lf[37]+1 /* (set! ##sys#add-to-export/rename-list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6348,a[2]=((C_word)li28),tmp=(C_word)a,a+=3,tmp));
t19=C_mutate((C_word*)lf[39]+1 /* (set! ##sys#toplevel-definition-hook ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6408,a[2]=((C_word)li29),tmp=(C_word)a,a+=3,tmp));
t20=C_mutate((C_word*)lf[40]+1 /* (set! ##sys#register-meta-expression ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6411,a[2]=((C_word)li30),tmp=(C_word)a,a+=3,tmp));
t21=C_mutate(&lf[42] /* (set! check-for-redef ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6431,a[2]=((C_word)li31),tmp=(C_word)a,a+=3,tmp));
t22=C_mutate((C_word*)lf[46]+1 /* (set! ##sys#register-export ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6452,a[2]=((C_word)li32),tmp=(C_word)a,a+=3,tmp));
t23=C_mutate((C_word*)lf[51]+1 /* (set! ##sys#register-syntax-export ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6541,a[2]=((C_word)li33),tmp=(C_word)a,a+=3,tmp));
t24=C_mutate((C_word*)lf[54]+1 /* (set! ##sys#unregister-syntax-export ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6622,a[2]=((C_word)li35),tmp=(C_word)a,a+=3,tmp));
t25=C_mutate((C_word*)lf[55]+1 /* (set! ##sys#register-module ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6715,a[2]=((C_word)li36),tmp=(C_word)a,a+=3,tmp));
t26=C_mutate(&lf[56] /* (set! merge-se ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7025,a[2]=((C_word)li41),tmp=(C_word)a,a+=3,tmp));
t27=C_mutate((C_word*)lf[61]+1 /* (set! ##sys#compiled-module-registration ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7257,a[2]=((C_word)li52),tmp=(C_word)a,a+=3,tmp));
t28=C_mutate((C_word*)lf[73]+1 /* (set! ##sys#register-compiled-module ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7756,a[2]=((C_word)li60),tmp=(C_word)a,a+=3,tmp));
t29=C_mutate((C_word*)lf[86]+1 /* (set! ##sys#register-core-module ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8090,a[2]=((C_word)li63),tmp=(C_word)a,a+=3,tmp));
t30=C_mutate((C_word*)lf[88]+1 /* (set! ##sys#register-primitive-module ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8204,a[2]=((C_word)li64),tmp=(C_word)a,a+=3,tmp));
t31=C_mutate(&lf[50] /* (set! find-export ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8219,a[2]=((C_word)li66),tmp=(C_word)a,a+=3,tmp));
t32=C_mutate((C_word*)lf[89]+1 /* (set! ##sys#finalize-module ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8297,a[2]=((C_word)li95),tmp=(C_word)a,a+=3,tmp));
t33=C_set_block_item(lf[28] /* ##sys#module-table */,0,C_SCHEME_END_OF_LIST);
t34=C_mutate((C_word*)lf[65]+1 /* (set! ##sys#with-environment ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9319,a[2]=((C_word)li99),tmp=(C_word)a,a+=3,tmp));
t35=C_mutate((C_word*)lf[139]+1 /* (set! ##sys#import-library-hook ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9424,a[2]=((C_word)li104),tmp=(C_word)a,a+=3,tmp));
t36=C_mutate(&lf[145] /* (set! find-module/import-library ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9470,a[2]=((C_word)li105),tmp=(C_word)a,a+=3,tmp));
t37=C_mutate((C_word*)lf[79]+1 /* (set! ##sys#decompose-import ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9485,a[2]=((C_word)li144),tmp=(C_word)a,a+=3,tmp));
t38=C_mutate((C_word*)lf[169]+1 /* (set! ##sys#expand-import ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10480,a[2]=((C_word)li149),tmp=(C_word)a,a+=3,tmp));
t39=C_mutate((C_word*)lf[171]+1 /* (set! ##sys#import ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10544,a[2]=((C_word)li158),tmp=(C_word)a,a+=3,tmp));
t40=C_mutate(&lf[49] /* (set! module-rename ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10990,a[2]=((C_word)li159),tmp=(C_word)a,a+=3,tmp));
t41=C_mutate((C_word*)lf[180]+1 /* (set! ##sys#alias-global-hook ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11008,a[2]=((C_word)li164),tmp=(C_word)a,a+=3,tmp));
t42=C_mutate((C_word*)lf[181]+1 /* (set! ##sys#validate-exports ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11082,a[2]=((C_word)li169),tmp=(C_word)a,a+=3,tmp));
t43=C_mutate((C_word*)lf[192]+1 /* (set! ##sys#register-functor ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11297,a[2]=((C_word)li170),tmp=(C_word)a,a+=3,tmp));
t44=C_mutate((C_word*)lf[193]+1 /* (set! ##sys#instantiate-functor ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11313,a[2]=((C_word)li176),tmp=(C_word)a,a+=3,tmp));
t45=C_mutate(&lf[197] /* (set! match-functor-argument ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11539,a[2]=((C_word)li180),tmp=(C_word)a,a+=3,tmp));
t46=lf[205];
t47=*((C_word*)lf[206]+1);
t48=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11699,a[2]=((C_word*)t0)[2],a[3]=t47,a[4]=t46,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:1122: ##sys#register-core-module */
t49=*((C_word*)lf[86]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t49;
av2[1]=t48;
av2[2]=lf[275];
av2[3]=lf[216];
av2[4]=t46;
av2[5]=*((C_word*)lf[206]+1);
((C_proc)(void*)(*((C_word*)t49+1)))(6,av2);}}

/* module-name in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_5698(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5698,c,av);}
t3=C_i_check_structure_2(t2,lf[6],lf[8]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_block_ref(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* module-undefined-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_5788(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5788,c,av);}
t3=C_i_check_structure_2(t2,lf[6],lf[9]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_block_ref(t2,C_fix(7));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* set-module-undefined-list! in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_5797(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5797,c,av);}
t4=C_i_check_structure_2(t2,lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t5=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_fix(7);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* ##sys#module-exports in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_5951(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5951,c,av);}
t3=C_i_check_structure_2(t2,lf[6],lf[14]);
t4=C_i_block_ref(t2,C_fix(3));
t5=C_i_check_structure_2(t2,lf[6],lf[15]);
t6=C_i_block_ref(t2,C_fix(11));
t7=C_i_check_structure_2(t2,lf[6],lf[16]);
/* modules.scm:121: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t1;
av2[2]=t4;
av2[3]=t6;
av2[4]=C_i_block_ref(t2,C_fix(12));
C_values(5,av2);}}

/* make-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static C_word C_fcall f_5969(C_word *a,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7){
C_word tmp;
C_word t8;
C_word t9;
C_word t10;
C_stack_overflow_check;{}
t8=C_i_nullp(t7);
t9=(C_truep(t8)?C_SCHEME_END_OF_LIST:C_i_car(t7));
return(C_a_i_record(&a,16,lf[6],t1,t2,t3,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,t4,t5,t6,C_SCHEME_FALSE,t9));}

/* ##sys#register-module-alias in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_5984(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_5984,c,av);}
a=C_alloc(7);
t4=C_a_i_cons(&a,2,t2,t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6000,a[2]=t4,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:132: ##sys#module-alias-environment */
t6=*((C_word*)lf[5]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k5998 in ##sys#register-module-alias in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6000(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6000,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
/* modules.scm:131: ##sys#module-alias-environment */
t3=*((C_word*)lf[5]+1);{
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

/* ##sys#with-module-aliases in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6002(C_word c,C_word *av){
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
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(21,c,3)))){
C_save_and_reclaim((void *)f_6002,c,av);}
a=C_alloc(21);
t4=*((C_word*)lf[5]+1);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6006,a[2]=t4,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=C_i_check_list_2(t2,lf[21]);
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6065,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6071,a[2]=t8,a[3]=t13,a[4]=t9,a[5]=((C_word)li15),tmp=(C_word)a,a+=6,tmp));
t15=((C_word*)t13)[1];
f_6071(t15,t11,t2);}

/* k6004 in ##sys#with-module-aliases in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6006(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(19,c,4)))){
C_save_and_reclaim((void *)f_6006,c,av);}
a=C_alloc(19);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_TRUE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6011,a[2]=t3,a[3]=t5,a[4]=((C_word*)t0)[2],a[5]=((C_word)li12),tmp=(C_word)a,a+=6,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6028,a[2]=((C_word*)t0)[3],a[3]=((C_word)li13),tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6034,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word)li14),tmp=(C_word)a,a+=5,tmp);
/* modules.scm:135: ##sys#dynamic-wind */
t9=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t9;
av2[1]=((C_word*)t0)[4];
av2[2]=t6;
av2[3]=t7;
av2[4]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}

/* a6010 in k6004 in ##sys#with-module-aliases in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6011(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6011,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6015,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)((C_word*)t0)[3])[1])){
/* modules.scm:135: ##sys#module-alias-environment935 */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[2])[1];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)((C_word*)t0)[2])[1];
f_6015(2,av2);}}}

/* k6013 in a6010 in k6004 in ##sys#with-module-aliases in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6015(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_6015,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6019,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* modules.scm:135: ##sys#module-alias-environment935 */
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k6017 in k6013 in a6010 in k6004 in ##sys#with-module-aliases in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6019(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_6019,c,av);}
a=C_alloc(4);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6022,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:135: ##sys#module-alias-environment935 */
t4=((C_word*)t0)[5];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[6];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t4))(5,av2);}}

/* k6020 in k6017 in k6013 in a6010 in k6004 in ##sys#with-module-aliases in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6022(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6022,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a6027 in k6004 in ##sys#with-module-aliases in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6028(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6028,c,av);}
/* modules.scm:139: thunk */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a6033 in k6004 in ##sys#with-module-aliases in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6034(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6034,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6038,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:135: ##sys#module-alias-environment935 */
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k6036 in a6033 in k6004 in ##sys#with-module-aliases in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6038(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_6038,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6041,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:135: ##sys#module-alias-environment935 */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[2])[1];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}

/* k6039 in k6036 in a6033 in k6004 in ##sys#with-module-aliases in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6041(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6041,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)t0)[3]);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k6063 in ##sys#with-module-aliases in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6065(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6065,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6069,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:138: ##sys#module-alias-environment */
t3=*((C_word*)lf[5]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k6067 in k6063 in ##sys#with-module-aliases in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6069(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6069,c,av);}
/* modules.scm:136: scheme#append */
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

/* map-loop944 in ##sys#with-module-aliases in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6071(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_6071,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_car(t3);
t5=C_i_cadr(t3);
t6=C_a_i_cons(&a,2,t4,t5);
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

/* ##sys#resolve-module-name in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6105(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6105,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6113,a[2]=t3,a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:142: chicken.internal#library-id */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[26]+1);
av2[1]=t4;
av2[2]=t2;
tp(3,av2);}}

/* k6111 in ##sys#resolve-module-name in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6113(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_6113,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6115,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=((C_word)li18),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_6115(t5,((C_word*)t0)[4],t1,C_SCHEME_END_OF_LIST);}

/* loop in k6111 in ##sys#resolve-module-name in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6115(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_6115,4,t0,t1,t2,t3);}
a=C_alloc(8);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6150,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=t1,tmp=(C_word)a,a+=8,tmp);
/* modules.scm:143: ##sys#module-alias-environment */
t5=*((C_word*)lf[5]+1);{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* g988 in k6148 in loop in k6111 in ##sys#resolve-module-name in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6123(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,4)))){
C_save_and_reclaim_args((void *)trf_6123,3,t0,t1,t2);}
a=C_alloc(3);
t3=C_i_cdr(t2);
if(C_truep(C_i_memq(t3,((C_word*)t0)[2]))){
/* modules.scm:147: chicken.base#error */
t4=*((C_word*)lf[24]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[25];
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[2]);
/* modules.scm:148: loop */
t5=((C_word*)((C_word*)t0)[5])[1];
f_6115(t5,t1,t3,t4);}}

/* k6148 in loop in k6111 in ##sys#resolve-module-name in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6150(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_6150,c,av);}
a=C_alloc(7);
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6123,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word)li17),tmp=(C_word)a,a+=7,tmp);
/* modules.scm:143: g988 */
t4=t3;
f_6123(t4,((C_word*)t0)[7],t2);}
else{
t3=((C_word*)t0)[7];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* ##sys#find-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6152(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6152,c,av);}
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_TRUE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_i_assq(t2,*((C_word*)lf[28]+1));
if(C_truep(t9)){
t10=t1;{
C_word *av2=av;
av2[0]=t10;
av2[1]=C_i_cdr(t9);
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
if(C_truep(t4)){
/* modules.scm:153: chicken.base#error */
t10=*((C_word*)lf[24]+1);{
C_word av2[5];
av2[0]=t10;
av2[1]=t1;
av2[2]=t7;
av2[3]=lf[29];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t10+1)))(5,av2);}}
else{
t10=t1;{
C_word *av2=av;
av2[0]=t10;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}}}

/* ##sys#switch-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6206(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6206,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6253,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:159: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[32]+1);
av2[1]=t3;
tp(2,av2);}}

/* k6211 in k6255 in k6251 in ##sys#switch-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6213(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_6213,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6216,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6241,a[2]=((C_word*)t0)[5],a[3]=((C_word)li21),tmp=(C_word)a,a+=4,tmp);
/* modules.scm:160: g1026 */
t4=t3;
f_6241(t4,t2,t1);}
else{
t3=C_mutate(((C_word *)((C_word*)t0)[4])+1,((C_word*)t0)[5]);
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
f_6216(2,av2);}}}

/* k6214 in k6211 in k6255 in k6251 in ##sys#switch-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6216(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6216,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6219,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)t0)[3])){
t3=C_i_check_structure_2(((C_word*)t0)[3],lf[6],lf[33]);
t4=t2;
f_6219(t4,C_i_block_ref(((C_word*)t0)[3],C_fix(14)));}
else{
t3=t2;
f_6219(t3,((C_word*)((C_word*)t0)[4])[1]);}}

/* k6217 in k6214 in k6211 in k6255 in k6251 in ##sys#switch-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6219(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_6219,2,t0,t1);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6222,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6228,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:167: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[32]+1);
av2[1]=t3;
av2[2]=C_i_car(t1);
tp(3,av2);}}
else{
/* modules.scm:169: ##sys#current-module */
t3=*((C_word*)lf[4]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k6220 in k6217 in k6214 in k6211 in k6255 in k6251 in ##sys#switch-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6222(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6222,c,av);}
/* modules.scm:169: ##sys#current-module */
t2=*((C_word*)lf[4]+1);{
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

/* k6226 in k6217 in k6214 in k6211 in k6255 in k6251 in ##sys#switch-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6228(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6228,c,av);}
/* modules.scm:168: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[31]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=C_u_i_cdr(((C_word*)t0)[3]);
tp(3,av2);}}

/* g1026 in k6211 in k6255 in k6251 in ##sys#switch-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6241(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_6241,3,t0,t1,t2);}
t3=C_i_check_structure_2(t2,lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t4=*((C_word*)lf[11]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_fix(14);
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k6251 in ##sys#switch-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6253(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6253,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6257,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:159: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t2;
tp(2,av2);}}

/* k6255 in k6251 in ##sys#switch-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6257(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_6257,c,av);}
a=C_alloc(9);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6213,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:160: ##sys#current-module */
t4=*((C_word*)lf[4]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* ##sys#add-to-export-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6259(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_6259,c,av);}
a=C_alloc(6);
t4=C_i_check_structure_2(t2,lf[6],lf[14]);
t5=C_i_block_ref(t2,C_fix(3));
t6=C_eqp(t5,C_SCHEME_TRUE);
if(C_truep(t6)){
t7=C_i_check_structure_2(t2,lf[6],lf[35]);
t8=C_i_block_ref(t2,C_fix(5));
t9=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6275,a[2]=t3,a[3]=t2,a[4]=t1,a[5]=t8,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:175: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t9;
tp(2,av2);}}
else{
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6346,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:185: scheme#append */
t8=*((C_word*)lf[22]+1);{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
av2[2]=t5;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}}

/* k6273 in ##sys#add-to-export-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6275(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,c,3)))){
C_save_and_reclaim((void *)f_6275,c,av);}
a=C_alloc(25);
t2=C_SCHEME_END_OF_LIST;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6284,a[2]=t3,a[3]=((C_word)li23),tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6276,a[2]=t1,a[3]=t4,a[4]=((C_word)li24),tmp=(C_word)a,a+=5,tmp);
t6=C_i_check_list_2(((C_word*)t0)[2],lf[36]);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6298,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],a[6]=t3,tmp=(C_word)a,a+=7,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6318,a[2]=t5,a[3]=t9,a[4]=((C_word)li25),tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_6318(t11,t7,((C_word*)t0)[2]);}

/* g1043 in k6273 in ##sys#add-to-export-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static C_word C_fcall f_6276(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t2=C_i_assq(t1,((C_word*)t0)[2]);
if(C_truep(t2)){
return((
/* modules.scm:179: g1059 */
  f_6284(C_a_i(&a,3),((C_word*)t0)[3],t2)
));}
else{
t3=C_SCHEME_UNDEFINED;
return(t3);}}

/* g1059 in k6273 in ##sys#add-to-export-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static C_word C_fcall f_6284(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t2=C_a_i_cons(&a,2,t1,((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
return(t3);}

/* k6296 in k6273 in ##sys#add-to-export-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6298(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_6298,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6301,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6312,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[16]);
/* modules.scm:183: scheme#append */
t5=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=((C_word*)((C_word*)t0)[6])[1];
av2[3]=C_i_block_ref(((C_word*)t0)[2],C_fix(12));
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k6299 in k6296 in k6273 in ##sys#add-to-export-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6301(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_6301,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6308,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:184: scheme#append */
t3=*((C_word*)lf[22]+1);{
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

/* k6306 in k6299 in k6296 in k6273 in ##sys#add-to-export-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6308(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6308,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(5);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6310 in k6296 in k6273 in ##sys#add-to-export-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6312(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6312,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(12);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* for-each-loop1042 in k6273 in ##sys#add-to-export-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6318(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_6318,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:177: g1043 */
  f_6276(C_a_i(&a,3),((C_word*)t0)[2],C_slot(t2,C_fix(0)))
);
t5=t1;
t6=C_slot(t2,C_fix(1));
t1=t5;
t2=t6;
goto loop;}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6344 in ##sys#add-to-export-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6346(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6346,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(3);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* ##sys#add-to-export/rename-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6348(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_6348,c,av);}
a=C_alloc(9);
t4=C_i_check_structure_2(t2,lf[6],lf[38]);
t5=C_i_block_ref(t2,C_fix(15));
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6355,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6406,a[2]=t2,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:189: scheme#append */
t8=*((C_word*)lf[22]+1);{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
av2[2]=t5;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}

/* k6353 in ##sys#add-to-export/rename-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6355(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6355,c,av);}
a=C_alloc(17);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[21]);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6368,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6370,a[2]=t4,a[3]=t9,a[4]=t5,a[5]=((C_word)li27),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_6370(t11,t7,((C_word*)t0)[2]);}

/* k6366 in k6353 in ##sys#add-to-export/rename-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6368(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6368,c,av);}
/* modules.scm:190: ##sys#add-to-export-list */
t2=*((C_word*)lf[34]+1);{
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

/* map-loop1075 in k6353 in ##sys#add-to-export/rename-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6370(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_6370,3,t0,t1,t2);}
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

/* k6404 in ##sys#add-to-export/rename-list in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6406(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6406,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(15);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* ##sys#toplevel-definition-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6408(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6408,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* ##sys#register-meta-expression in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6411(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6411,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6415,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:195: ##sys#current-module */
t4=*((C_word*)lf[4]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k6413 in ##sys#register-meta-expression in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6415(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6415,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=C_i_check_structure_2(t1,lf[6],lf[41]);
t3=C_i_block_ref(t1,C_fix(10));
t4=C_a_i_cons(&a,2,((C_word*)t0)[2],t3);
t5=C_i_check_structure_2(t1,lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t6=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=C_fix(10);
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* check-for-redef in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6431(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_6431,4,t1,t2,t3,t4);}
a=C_alloc(5);
t5=C_i_assq(t2,t3);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6438,a[2]=t2,a[3]=t4,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t5)){
/* modules.scm:200: ##sys#warn */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[43]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[43]+1);
av2[1]=t6;
av2[2]=lf[45];
av2[3]=t2;
tp(4,av2);}}
else{
t7=t6;{
C_word av2[2];
av2[0]=t7;
av2[1]=C_SCHEME_FALSE;
f_6438(2,av2);}}}

/* k6436 in check-for-redef in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6438(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6438,c,av);}
if(C_truep(C_i_assq(((C_word*)t0)[2],((C_word*)t0)[3]))){
/* modules.scm:202: ##sys#warn */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[43]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[43]+1);
av2[1]=((C_word*)t0)[4];
av2[2]=lf[44];
av2[3]=((C_word*)t0)[2];
tp(4,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* ##sys#register-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6452(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_6452,c,av);}
a=C_alloc(5);
if(C_truep(t3)){
t4=C_i_check_structure_2(t3,lf[6],lf[14]);
t5=C_i_block_ref(t3,C_fix(3));
t6=C_eqp(C_SCHEME_TRUE,t5);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6462,a[2]=t2,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t6)){
t8=t7;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t6;
f_6462(2,av2);}}
else{
/* modules.scm:207: find-export */
f_8219(t7,t2,t3,C_SCHEME_TRUE);}}
else{
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k6460 in ##sys#register-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6462(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6462,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6465,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:208: module-undefined-list */
t3=*((C_word*)lf[9]+1);{
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

/* k6463 in k6460 in ##sys#register-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6465(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_6465,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6468,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6528,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t4=C_i_check_structure_2(((C_word*)t0)[4],lf[6],lf[8]);
/* modules.scm:210: module-rename */
f_10990(t3,((C_word*)t0)[2],C_i_block_ref(((C_word*)t0)[4],C_fix(1)));}

/* k6466 in k6463 in k6460 in ##sys#register-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6468(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_6468,c,av);}
a=C_alloc(10);
t2=C_i_assq(((C_word*)t0)[2],((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6474,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t2)){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6524,a[2]=t3,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:212: delete */
f_4888(t4,t2,((C_word*)t0)[3],*((C_word*)lf[48]+1));}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_6474(2,av2);}}}

/* k6472 in k6466 in k6463 in k6460 in ##sys#register-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6474(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_6474,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6477,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6513,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:213: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[32]+1);
av2[1]=t3;
tp(2,av2);}}

/* k6475 in k6472 in k6466 in k6463 in k6460 in ##sys#register-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_6477,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6480,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_i_check_structure_2(((C_word*)t0)[4],lf[6],lf[35]);
t4=C_i_block_ref(((C_word*)t0)[4],C_fix(5));
t5=C_a_i_cons(&a,2,((C_word*)t0)[3],t4);
t6=C_i_check_structure_2(((C_word*)t0)[4],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t7=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t7;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(5);
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}

/* k6478 in k6475 in k6472 in k6466 in k6463 in k6460 in ##sys#register-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6480(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6480,c,av);}
a=C_alloc(6);
if(C_truep(((C_word*)t0)[2])){
t2=C_a_i_cons(&a,2,((C_word*)t0)[3],C_SCHEME_FALSE);
t3=C_i_check_structure_2(((C_word*)t0)[4],lf[6],lf[47]);
t4=C_i_block_ref(((C_word*)t0)[4],C_fix(4));
t5=C_a_i_cons(&a,2,t2,t4);
t6=C_i_check_structure_2(((C_word*)t0)[4],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t7=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t7;
av2[1]=((C_word*)t0)[5];
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(4);
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}
else{
t2=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k6511 in k6472 in k6466 in k6463 in k6460 in ##sys#register-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6513(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6513,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6517,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:213: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t2;
tp(2,av2);}}

/* k6515 in k6511 in k6472 in k6466 in k6463 in k6460 in ##sys#register-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6517(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6517,c,av);}
/* modules.scm:213: check-for-redef */
f_6431(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k6522 in k6466 in k6463 in k6460 in ##sys#register-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6524(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6524,c,av);}
/* modules.scm:212: set-module-undefined-list! */
t2=*((C_word*)lf[10]+1);{
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

/* k6526 in k6463 in k6460 in ##sys#register-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6528(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6528,c,av);}
/* modules.scm:209: ##sys#toplevel-definition-hook */
t2=*((C_word*)lf[39]+1);{
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

/* ##sys#register-syntax-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6541(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6541,c,av);}
a=C_alloc(6);
if(C_truep(t3)){
t5=C_i_check_structure_2(t3,lf[6],lf[14]);
t6=C_i_block_ref(t3,C_fix(3));
t7=C_eqp(C_SCHEME_TRUE,t6);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6551,a[2]=t3,a[3]=t2,a[4]=t4,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
if(C_truep(t7)){
t9=t8;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t7;
f_6551(2,av2);}}
else{
/* modules.scm:225: find-export */
f_8219(t8,t2,t3,C_SCHEME_TRUE);}}
else{
t5=C_SCHEME_UNDEFINED;
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k6549 in ##sys#register-syntax-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6551(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_6551,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6554,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* modules.scm:226: module-undefined-list */
t3=*((C_word*)lf[9]+1);{
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

/* k6552 in k6549 in ##sys#register-syntax-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6554(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_6554,c,av);}
a=C_alloc(7);
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[8]);
t3=C_i_block_ref(((C_word*)t0)[2],C_fix(1));
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6560,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_i_assq(((C_word*)t0)[3],t1))){
/* modules.scm:229: ##sys#warn */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[43]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[43]+1);
av2[1]=t4;
av2[2]=lf[53];
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_6560(2,av2);}}}

/* k6558 in k6552 in k6549 in ##sys#register-syntax-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6560(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_6560,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6563,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6603,a[2]=t2,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:230: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[32]+1);
av2[1]=t3;
tp(2,av2);}}

/* k6561 in k6558 in k6552 in k6549 in ##sys#register-syntax-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6563(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6563,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6569,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[6])){
t3=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t4=C_i_check_structure_2(((C_word*)t0)[4],lf[6],lf[47]);
t5=C_i_block_ref(((C_word*)t0)[4],C_fix(4));
t6=C_a_i_cons(&a,2,t3,t5);
t7=C_i_check_structure_2(((C_word*)t0)[4],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t8=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t8;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(4);
av2[4]=t6;
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6569(2,av2);}}}

/* k6567 in k6561 in k6558 in k6552 in k6549 in ##sys#register-syntax-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6569(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6569,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_i_check_structure_2(((C_word*)t0)[4],lf[6],lf[52]);
t4=C_i_block_ref(((C_word*)t0)[4],C_fix(6));
t5=C_a_i_cons(&a,2,t2,t4);
t6=C_i_check_structure_2(((C_word*)t0)[4],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t7=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t7;
av2[1]=((C_word*)t0)[5];
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(6);
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}

/* k6601 in k6558 in k6552 in k6549 in ##sys#register-syntax-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6603(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6603,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6607,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:230: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t2;
tp(2,av2);}}

/* k6605 in k6601 in k6558 in k6552 in k6549 in ##sys#register-syntax-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6607(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6607,c,av);}
/* modules.scm:230: check-for-redef */
f_6431(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* ##sys#unregister-syntax-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6622(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6622,c,av);}
a=C_alloc(7);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6633,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t5=C_i_check_structure_2(t3,lf[6],lf[52]);
t6=C_i_block_ref(t3,C_fix(6));
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6639,a[2]=((C_word)li34),tmp=(C_word)a,a+=3,tmp);
/* modules.scm:245: delete */
f_4888(t4,t2,t6,t7);}
else{
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k6631 in ##sys#unregister-syntax-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6633(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6633,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(6);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* a6638 in ##sys#unregister-syntax-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6639(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6639,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_eqp(t2,C_i_car(t3));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k6654 in g2811 in k11013 in mrename in ##sys#alias-global-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6656(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6656,c,av);}
a=C_alloc(9);
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6663,a[2]=((C_word*)t0)[3],a[3]=((C_word)li160),tmp=(C_word)a,a+=4,tmp);
/* modules.scm:250: g1166 */
t4=t3;
f_6663(t4,((C_word*)t0)[4],t2);}
else{
if(C_truep(((C_word*)t0)[3])){
t3=C_a_i_list1(&a,1,((C_word*)t0)[3]);
t4=C_a_i_cons(&a,2,((C_word*)t0)[2],t3);
t5=C_a_i_cons(&a,2,t4,t1);
/* modules.scm:255: set-module-undefined-list! */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[5];
av2[3]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t3=C_a_i_cons(&a,2,((C_word*)t0)[2],C_SCHEME_END_OF_LIST);
t4=C_a_i_cons(&a,2,t3,t1);
/* modules.scm:255: set-module-undefined-list! */
t5=*((C_word*)lf[10]+1);{
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
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}}

/* g1166 in k6654 in g2811 in k11013 in mrename in ##sys#alias-global-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6663(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_6663,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6670,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[2])){
t4=C_i_cdr(t2);
t5=t3;
f_6670(t5,C_i_not(C_i_memq(((C_word*)t0)[2],t4)));}
else{
t4=t3;
f_6670(t4,C_SCHEME_FALSE);}}

/* k6668 in g1166 in k6654 in g2811 in k11013 in mrename in ##sys#alias-global-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6670(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,1)))){
C_save_and_reclaim_args((void *)trf_6670,2,t0,t1);}
a=C_alloc(3);
if(C_truep(t1)){
t2=C_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_i_set_cdr(((C_word*)t0)[2],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* ##sys#register-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6715(C_word c,C_word *av){
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
if(c<5) C_bad_min_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(23,c,1)))){
C_save_and_reclaim((void *)f_6715,c,av);}
a=C_alloc(23);
t5=C_rest_nullp(c,5);
t6=(C_truep(t5)?C_SCHEME_END_OF_LIST:C_get_rest_arg(c,5,av,5,t0));
t7=C_rest_nullp(c,5);
t8=C_rest_nullp(c,6);
t9=(C_truep(t8)?C_SCHEME_END_OF_LIST:C_get_rest_arg(c,6,av,5,t0));
t10=C_rest_nullp(c,6);
t11=(
/* modules.scm:260: make-module */
  f_5969(C_a_i(&a,17),t2,t3,t4,t6,t9,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST)
);
t12=C_a_i_cons(&a,2,t2,t11);
t13=C_a_i_cons(&a,2,t12,*((C_word*)lf[28]+1));
t14=C_mutate((C_word*)lf[28]+1 /* (set! ##sys#module-table ...) */,t13);
t15=t1;{
C_word *av2=av;
av2[0]=t15;
av2[1]=t11;
((C_proc)(void*)(*((C_word*)t15+1)))(2,av2);}}

/* warn in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6821(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_6821,4,t0,t1,t2,t3);}
a=C_alloc(8);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6829,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6833,a[2]=t4,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:276: scheme#symbol->string */
t6=*((C_word*)lf[119]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k6827 in warn in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6829(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6829,c,av);}
/* modules.scm:275: ##sys#warn */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[43]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[43]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k6831 in warn in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6833(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_6833,c,av);}
/* modules.scm:276: scheme#string-append */
t2=*((C_word*)lf[116]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[117];
av2[4]=t1;
av2[5]=lf[118];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* loop in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6844(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,0,3)))){
C_save_and_reclaim_args((void *)trf_6844,3,t0,t1,t2);}
a=C_alloc(11);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
if(C_truep(C_i_symbolp(t3))){
/* modules.scm:282: loop */
t9=t1;
t10=C_u_i_cdr(t2);
t1=t9;
t2=t10;
goto loop;}
else{
t4=C_i_cdar(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6871,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t6,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word)li86),tmp=(C_word)a,a+=9,tmp));
t8=((C_word*)t6)[1];
f_6871(t8,t1,t4);}}}

/* loop2 in loop in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6871(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_6871,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t2))){
/* modules.scm:285: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_6844(t3,t1,C_i_cdr(((C_word*)t0)[3]));}
else{
t3=C_i_car(t2);
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7019,a[2]=t3,a[3]=((C_word*)t0)[4],a[4]=t1,a[5]=t2,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* modules.scm:286: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word av2[2];
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t4;
tp(2,av2);}}}

/* k6892 in k7017 in loop2 in loop in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6894(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6894,c,av);}
/* modules.scm:288: loop2 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_6871(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}

/* g1224 in k7017 in loop2 in loop in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6908(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,0,3)))){
C_save_and_reclaim_args((void *)trf_6908,3,t0,t1,t2);}
a=C_alloc(13);
t3=C_i_car(((C_word*)t0)[2]);
t4=C_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6933,a[2]=t3,a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t4)){
t6=C_a_i_cons(&a,2,t3,t4);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f14089,a[2]=t1,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:295: loop2 */
t8=((C_word*)((C_word*)t0)[3])[1];
f_6871(t8,t7,C_u_i_cdr(((C_word*)t0)[2]));}
else{
/* modules.scm:294: module-rename */
f_10990(t5,C_u_i_car(((C_word*)t0)[2]),((C_word*)t0)[4]);}}

/* k6931 in g1224 in k7017 in loop2 in loop in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6933(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_6933,c,av);}
a=C_alloc(7);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f14085,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:295: loop2 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_6871(t4,t3,C_u_i_cdr(((C_word*)t0)[5]));}

/* g1231 in k7007 in k7017 in loop2 in loop in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_6948(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_6948,3,t0,t1,t2);}
a=C_alloc(7);
t3=C_i_cdr(t2);
if(C_truep(C_i_symbolp(t3))){
t4=C_i_car(((C_word*)t0)[2]);
t5=C_u_i_cdr(t2);
t6=C_a_i_cons(&a,2,t4,t5);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6966,a[2]=t1,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:299: loop2 */
t8=((C_word*)((C_word*)t0)[3])[1];
f_6871(t8,t7,C_u_i_cdr(((C_word*)t0)[2]));}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6977,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:301: warn */
t5=((C_word*)t0)[4];
f_6821(t5,t4,lf[121],C_i_car(((C_word*)t0)[2]));}}

/* k6964 in g1231 in k7007 in k7017 in loop2 in loop in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_6966(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_6966,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k6975 in g1231 in k7007 in k7017 in loop2 in loop in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_6977(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6977,c,av);}
/* modules.scm:302: loop2 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_6871(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}

/* k6994 in k7007 in k7017 in loop2 in loop in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_6996(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6996,c,av);}
/* modules.scm:305: loop2 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_6871(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}

/* k7007 in k7017 in loop2 in loop in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7009(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_7009,c,av);}
a=C_alloc(6);
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6948,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word)li85),tmp=(C_word)a,a+=6,tmp);
/* modules.scm:285: g1231 */
t4=t3;
f_6948(t4,((C_word*)t0)[6],t2);}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6996,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:304: warn */
t4=((C_word*)t0)[5];
f_6821(t4,t3,lf[122],C_u_i_car(((C_word*)t0)[3]));}}

/* k7017 in loop2 in loop in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7019(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_7019,c,av);}
a=C_alloc(7);
if(C_truep(C_i_assq(((C_word*)t0)[2],t1))){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6894,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:287: warn */
t3=((C_word*)t0)[6];
f_6821(t3,t2,lf[120],C_u_i_car(((C_word*)t0)[5]));}
else{
t2=C_i_assq(C_u_i_car(((C_word*)t0)[5]),((C_word*)t0)[7]);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6908,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[8],a[5]=((C_word)li84),tmp=(C_word)a,a+=6,tmp);
/* modules.scm:285: g1224 */
t4=t3;
f_6908(t4,((C_word*)t0)[4],t2);}
else{
t3=C_u_i_car(((C_word*)t0)[5]);
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7009,a[2]=t3,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
/* modules.scm:296: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[32]+1);
av2[1]=t4;
tp(2,av2);}}}}

/* merge-se in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7025(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_7025,2,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7029,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:308: chicken.internal#make-hash-table */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[60]+1));
C_word av2[2];
av2[0]=*((C_word*)lf[60]+1);
av2[1]=t3;
tp(2,av2);}}

/* k7027 in merge-se in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7029(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7029,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7032,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:308: scheme#reverse */
t3=*((C_word*)lf[59]+1);{
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

/* k7030 in k7027 in merge-se in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7032(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_7032,c,av);}
a=C_alloc(7);
t2=C_i_cdr(t1);
t3=C_u_i_car(t1);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7043,a[2]=t5,a[3]=((C_word*)t0)[2],a[4]=((C_word)li40),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_7043(t7,((C_word*)t0)[3],t2,C_SCHEME_FALSE,t3);}

/* loop in k7030 in k7027 in merge-se in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7043(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(17,0,4)))){
C_save_and_reclaim_args((void *)trf_7043,5,t0,t1,t2,t3,t4);}
a=C_alloc(17);
if(C_truep(C_i_nullp(t2))){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_i_car(t2);
t6=C_eqp(t3,t5);
t7=(C_truep(t6)?t6:C_i_nullp(C_u_i_car(t2)));
if(C_truep(t7)){
/* modules.scm:312: loop */
t15=t1;
t16=C_u_i_cdr(t2);
t17=t3;
t18=t4;
t1=t15;
t2=t16;
t3=t17;
t4=t18;
goto loop;}
else{
if(C_truep(C_i_not(t3))){
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7071,a[2]=((C_word*)t0)[3],a[3]=((C_word)li37),tmp=(C_word)a,a+=4,tmp);
t9=C_i_check_list_2(t4,lf[36]);
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7085,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7090,a[2]=t12,a[3]=t8,a[4]=((C_word)li38),tmp=(C_word)a,a+=5,tmp));
t14=((C_word*)t12)[1];
f_7090(t14,t10,t4);}
else{
t8=C_u_i_car(t2);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7118,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t10,a[5]=((C_word*)t0)[3],a[6]=((C_word)li39),tmp=(C_word)a,a+=7,tmp));
t12=((C_word*)t10)[1];
f_7118(t12,t1,t8,t4);}}}}

/* g1262 in loop in k7030 in k7027 in merge-se in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7071(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_7071,3,t0,t1,t2);}
/* modules.scm:314: chicken.internal#hash-table-set! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[57]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[57]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=C_i_car(t2);
av2[4]=C_SCHEME_TRUE;
tp(5,av2);}}

/* k7083 in loop in k7030 in k7027 in merge-se in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7085(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7085,c,av);}
/* modules.scm:315: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_7043(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[5]);}

/* for-each-loop1261 in loop in k7030 in k7027 in merge-se in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7090(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_7090,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7100,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:314: g1262 */
t4=((C_word*)t0)[3];
f_7071(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k7098 in for-each-loop1261 in loop in k7030 in k7027 in merge-se in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7100(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7100,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7090(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* lp in loop in k7030 in k7027 in merge-se in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7118(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,4)))){
C_save_and_reclaim_args((void *)trf_7118,4,t0,t1,t2,t3);}
a=C_alloc(7);
if(C_truep(C_i_nullp(t2))){
/* modules.scm:317: loop */
t4=((C_word*)((C_word*)t0)[2])[1];
f_7043(t4,t1,C_i_cdr(((C_word*)t0)[3]),C_u_i_car(((C_word*)t0)[3]),t3);}
else{
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7140,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* modules.scm:318: chicken.internal#hash-table-ref */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[58]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[58]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[5];
av2[3]=C_i_caar(t2);
tp(4,av2);}}}

/* k7138 in lp in loop in k7030 in k7027 in merge-se in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7140(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_7140,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
/* modules.scm:319: lp */
t2=((C_word*)((C_word*)t0)[2])[1];
f_7118(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]),((C_word*)t0)[5]);}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7148,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:320: chicken.internal#hash-table-set! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[57]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[57]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=C_i_caar(((C_word*)t0)[4]);
av2[4]=C_SCHEME_TRUE;
tp(5,av2);}}}

/* k7146 in k7138 in lp in loop in k7030 in k7027 in merge-se in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7148(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_7148,c,av);}
a=C_alloc(3);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_u_i_car(((C_word*)t0)[2]);
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[3]);
/* modules.scm:321: lp */
t5=((C_word*)((C_word*)t0)[4])[1];
f_7118(t5,((C_word*)t0)[5],t2,t4);}

/* k7180 in k7737 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7182(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7182,c,av);}
a=C_alloc(17);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7193,a[2]=t4,a[3]=t5,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
t7=*((C_word*)lf[48]+1);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4969,a[2]=t9,a[3]=t7,a[4]=((C_word)li48),tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_4969(t11,t6,t1);}

/* k7191 in k7180 in k7737 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7193(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7193,c,av);}
a=C_alloc(8);
t2=C_i_check_list_2(t1,lf[21]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7201,a[2]=((C_word*)t0)[2],a[3]=t4,a[4]=((C_word*)t0)[3],a[5]=((C_word)li47),tmp=(C_word)a,a+=6,tmp));
t6=((C_word*)t4)[1];
f_7201(t6,((C_word*)t0)[4],t1);}

/* map-loop1297 in k7191 in k7180 in k7737 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7201(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_7201,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_a_i_list(&a,2,lf[78],t3);
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

/* a7234 in k7737 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7235(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_7235,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7241,a[2]=t2,a[3]=((C_word)li49),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7247,a[2]=((C_word)li50),tmp=(C_word)a,a+=3,tmp);
/* modules.scm:325: ##sys#call-with-values */{
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

/* a7240 in a7234 in k7737 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7241(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7241,c,av);}
/* modules.scm:325: ##sys#decompose-import */
t2=*((C_word*)lf[79]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=*((C_word*)lf[80]+1);
av2[4]=*((C_word*)lf[48]+1);
av2[5]=lf[6];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* a7246 in a7234 in k7737 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7247(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,1)))){
C_save_and_reclaim((void*)f_7247,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_list_ref(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7257(C_word c,C_word *av){
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
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_7257,c,av);}
a=C_alloc(16);
t4=C_i_check_structure_2(t2,lf[6],lf[47]);
t5=C_i_block_ref(t2,C_fix(4));
t6=C_i_check_structure_2(t2,lf[6],lf[8]);
t7=C_i_block_ref(t2,C_fix(1));
t8=C_i_check_structure_2(t2,lf[6],lf[62]);
t9=C_i_block_ref(t2,C_fix(8));
t10=C_i_check_structure_2(t2,lf[6],lf[16]);
t11=C_i_block_ref(t2,C_fix(12));
t12=C_i_check_structure_2(t2,lf[6],lf[63]);
t13=C_i_block_ref(t2,C_fix(9));
t14=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7292,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t15=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7296,a[2]=t14,a[3]=t2,a[4]=t5,a[5]=t11,a[6]=t7,a[7]=t13,a[8]=t9,tmp=(C_word)a,a+=9,tmp);
t16=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7739,a[2]=t15,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t17=C_eqp(t3,lf[81]);
if(C_truep(t17)){
t18=C_i_pairp(t9);
t19=t16;
f_7739(t19,(C_truep(t18)?C_i_pairp(t11):C_SCHEME_FALSE));}
else{
t18=t16;
f_7739(t18,C_SCHEME_FALSE);}}

/* k7290 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7292(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,1)))){
C_save_and_reclaim((void *)f_7292,c,av);}
a=C_alloc(15);
t2=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,t1);
t3=C_a_i_cons(&a,2,lf[64],t2);
t4=C_a_i_list(&a,2,lf[65],t3);
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,1,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7296(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7296,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7300,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7304,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t4=C_i_pairp(((C_word*)t0)[8]);
t5=(C_truep(t4)?C_i_pairp(((C_word*)t0)[5]):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7730,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* modules.scm:342: chicken.syntax#strip-syntax */
t7=*((C_word*)lf[72]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t6=t3;
f_7304(t6,C_SCHEME_END_OF_LIST);}}

/* k7298 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7300(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7300,c,av);}
/* modules.scm:336: ##sys#append */
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

/* k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7304(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,0,2)))){
C_save_and_reclaim_args((void *)trf_7304,2,t0,t1);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7308,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7312,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t4=C_i_pairp(((C_word*)t0)[7]);
t5=(C_truep(t4)?C_i_pairp(((C_word*)t0)[5]):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7702,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* modules.scm:345: chicken.syntax#strip-syntax */
t7=*((C_word*)lf[72]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t6=t3;
f_7312(t6,C_SCHEME_END_OF_LIST);}}

/* k7306 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7308(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7308,c,av);}
/* modules.scm:336: ##sys#append */
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

/* k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7312(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,0,2)))){
C_save_and_reclaim_args((void *)trf_7312,2,t0,t1);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7316,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7320,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_i_getprop(((C_word*)t0)[6],lf[74],C_SCHEME_FALSE);
t5=(C_truep(t4)?t4:C_i_pairp(((C_word*)t0)[5]));
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7681,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t7=C_i_check_structure_2(((C_word*)t0)[3],lf[6],lf[41]);
/* modules.scm:348: chicken.syntax#strip-syntax */
t8=*((C_word*)lf[72]+1);{
C_word av2[3];
av2[0]=t8;
av2[1]=t6;
av2[2]=C_i_block_ref(((C_word*)t0)[3],C_fix(10));
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
t6=t3;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_SCHEME_END_OF_LIST;
f_7320(2,av2);}}}

/* k7314 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7316(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7316,c,av);}
/* modules.scm:336: ##sys#append */
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

/* k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7320(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,c,3)))){
C_save_and_reclaim((void *)f_7320,c,av);}
a=C_alloc(34);
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[8]);
t3=C_i_block_ref(((C_word*)t0)[2],C_fix(1));
t4=C_a_i_list(&a,2,lf[67],t3);
t5=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[68]);
t6=C_i_block_ref(((C_word*)t0)[2],C_fix(2));
t7=C_a_i_list(&a,2,lf[67],t6);
t8=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t9=t8;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=((C_word*)t10)[1];
t12=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[69]);
t13=C_i_block_ref(((C_word*)t0)[2],C_fix(13));
t14=C_i_check_list_2(t13,lf[21]);
t15=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7624,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t4,a[6]=t7,a[7]=((C_word*)t0)[5],a[8]=t1,tmp=(C_word)a,a+=9,tmp);
t16=C_SCHEME_UNDEFINED;
t17=(*a=C_VECTOR_TYPE|1,a[1]=t16,tmp=(C_word)a,a+=2,tmp);
t18=C_set_block_item(t17,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7626,a[2]=t10,a[3]=t17,a[4]=t11,a[5]=((C_word)li46),tmp=(C_word)a,a+=6,tmp));
t19=((C_word*)t17)[1];
f_7626(t19,t15,t13);}

/* k7350 in k7533 in k7622 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7352(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,0,3)))){
C_save_and_reclaim_args((void *)trf_7352,2,t0,t1);}
a=C_alloc(23);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[38]);
t7=C_i_block_ref(((C_word*)t0)[2],C_fix(15));
t8=C_i_check_list_2(t7,lf[21]);
t9=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7388,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=t1,a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7390,a[2]=t4,a[3]=t11,a[4]=t5,a[5]=((C_word)li43),tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_7390(t13,t9,t7);}

/* k7386 in k7350 in k7533 in k7622 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7388(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(30,c,3)))){
C_save_and_reclaim((void *)f_7388,c,av);}
a=C_alloc(30);
t2=C_a_i_cons(&a,2,lf[70],t1);
t3=C_a_i_list(&a,8,lf[73],((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],t2);
t4=C_a_i_list(&a,1,t3);
/* modules.scm:336: ##sys#append */
t5=*((C_word*)lf[66]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[8];
av2[2]=((C_word*)t0)[9];
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* map-loop1441 in k7350 in k7533 in k7622 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7390(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,0,2)))){
C_save_and_reclaim_args((void *)trf_7390,3,t0,t1,t2);}
a=C_alloc(24);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_car(t3);
t5=C_a_i_list(&a,2,lf[67],t4);
t6=C_u_i_cdr(t3);
t7=C_a_i_list(&a,2,lf[67],t6);
t8=C_a_i_list(&a,3,lf[71],t5,t7);
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

/* k7424 in k7533 in k7622 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7426(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7426,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];
f_7352(t2,C_a_i_cons(&a,2,lf[70],t1));}

/* loop in k7533 in k7622 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7438(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_7438,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_caar(t2);
if(C_truep(C_i_assq(t3,((C_word*)t0)[2]))){
/* modules.scm:375: loop */
t11=t1;
t12=C_u_i_cdr(t2);
t1=t11;
t2=t12;
goto loop;}
else{
t4=C_i_caar(t2);
t5=C_u_i_car(t2);
t6=C_u_i_car(t5);
t7=C_a_i_list(&a,2,lf[67],t6);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7480,a[2]=t7,a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t9=C_u_i_car(t2);
/* modules.scm:378: chicken.syntax#strip-syntax */
t10=*((C_word*)lf[72]+1);{
C_word av2[3];
av2[0]=t10;
av2[1]=t8;
av2[2]=C_u_i_cdr(t9);
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}}}

/* k7468 in k7478 in loop in k7533 in k7622 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7470(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7470,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7478 in loop in k7533 in k7622 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7480(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_7480,c,av);}
a=C_alloc(13);
t2=C_a_i_list(&a,3,lf[71],((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7470,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:379: loop */
t4=((C_word*)((C_word*)t0)[4])[1];
f_7438(t4,t3,C_u_i_cdr(((C_word*)t0)[5]));}

/* g1394 in k7622 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7495(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_7495,3,t0,t1,t2);}
a=C_alloc(10);
t3=C_i_car(t2);
t4=C_i_assq(t3,((C_word*)t0)[2]);
if(C_truep(C_i_pairp(t4))){
t5=C_u_i_car(t2);
t6=C_a_i_list(&a,2,lf[67],t5);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7519,a[2]=t1,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:365: chicken.syntax#strip-syntax */
t8=*((C_word*)lf[72]+1);{
C_word av2[3];
av2[0]=t8;
av2[1]=t7;
av2[2]=C_u_i_cdr(t4);
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_a_i_list(&a,2,lf[67],t3);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k7517 in g1394 in k7622 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7519(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_7519,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[71],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7533 in k7622 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7535(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,c,3)))){
C_save_and_reclaim((void *)f_7535,c,av);}
a=C_alloc(23);
t2=C_a_i_cons(&a,2,lf[70],t1);
t3=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7352,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t2,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7426,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_nullp(((C_word*)t0)[9]))){
t5=t3;
f_7352(t5,C_a_i_cons(&a,2,lf[70],C_SCHEME_END_OF_LIST));}
else{
t5=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[52]);
t6=C_i_block_ref(((C_word*)t0)[2],C_fix(6));
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7438,a[2]=((C_word*)t0)[9],a[3]=t8,a[4]=((C_word)li44),tmp=(C_word)a,a+=5,tmp));
t10=((C_word*)t8)[1];
f_7438(t10,t4,t6);}}

/* map-loop1388 in k7622 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7537(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7537,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7562,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:361: g1394 */
t4=((C_word*)t0)[4];
f_7495(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7560 in map-loop1388 in k7622 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7562(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7562,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7537(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7622 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7624(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(37,c,3)))){
C_save_and_reclaim((void *)f_7624,c,av);}
a=C_alloc(37);
t2=C_a_i_cons(&a,2,lf[70],t1);
t3=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[15]);
t4=C_i_block_ref(((C_word*)t0)[2],C_fix(11));
t5=C_a_i_list(&a,2,lf[67],t4);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7495,a[2]=((C_word*)t0)[3],a[3]=((C_word)li42),tmp=(C_word)a,a+=4,tmp);
t11=C_i_check_list_2(((C_word*)t0)[4],lf[21]);
t12=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7535,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=t2,a[6]=t5,a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[4],tmp=(C_word)a,a+=10,tmp);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_set_block_item(t14,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7537,a[2]=t8,a[3]=t14,a[4]=t10,a[5]=t9,a[6]=((C_word)li45),tmp=(C_word)a,a+=7,tmp));
t16=((C_word*)t14)[1];
f_7537(t16,t12,((C_word*)t0)[4]);}

/* map-loop1355 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7626(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(30,0,2)))){
C_save_and_reclaim_args((void *)trf_7626,3,t0,t1,t2);}
a=C_alloc(30);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7651,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
t5=C_i_cdr(t4);
if(C_truep(C_i_symbolp(t5))){
t6=C_u_i_car(t4);
t7=C_u_i_cdr(t4);
t8=C_a_i_cons(&a,2,t6,t7);
t9=t3;
f_7651(t9,C_a_i_list(&a,2,lf[67],t8));}
else{
t6=C_u_i_car(t4);
t7=C_a_i_list(&a,2,lf[67],t6);
t8=C_a_i_list(&a,2,lf[67],C_SCHEME_END_OF_LIST);
t9=C_u_i_cdr(t4);
t10=t3;
f_7651(t10,C_a_i_list(&a,4,lf[70],t7,t8,t9));}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7649 in map-loop1355 in k7318 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7651(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_7651,2,t0,t1);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7626(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7679 in k7310 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7681(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7681,c,av);}
/* modules.scm:348: ##sys#fast-reverse */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[75]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[75]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
tp(3,av2);}}

/* k7700 in k7302 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7702(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_7702,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,lf[76],t1);
t3=((C_word*)t0)[2];
f_7312(t3,C_a_i_list(&a,1,t2));}

/* k7728 in k7294 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7730(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,1)))){
C_save_and_reclaim((void *)f_7730,c,av);}
a=C_alloc(18);
t2=C_a_i_cons(&a,2,lf[76],t1);
t3=C_a_i_list(&a,2,lf[67],t2);
t4=C_a_i_list(&a,2,lf[77],t3);
t5=((C_word*)t0)[2];
f_7304(t5,C_a_i_list(&a,1,t4));}

/* k7737 in ##sys#compiled-module-registration in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7739(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_7739,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7182,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7235,a[2]=((C_word)li51),tmp=(C_word)a,a+=3,tmp);
t4=C_i_check_structure_2(((C_word*)t0)[3],lf[6],lf[62]);
/* modules.scm:324: filter-map */
f_5052(t2,t3,C_i_block_ref(((C_word*)t0)[3],C_fix(8)));}
else{
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_END_OF_LIST;
f_7296(2,av2);}}}

/* ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7756(C_word c,C_word *av){
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
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word *a;
if(c<7) C_bad_min_argc_2(c,7,t0);
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_7756,c,av);}
a=C_alloc(13);
t7=C_rest_nullp(c,7);
t8=(C_truep(t7)?C_SCHEME_END_OF_LIST:C_get_rest_arg(c,7,av,7,t0));
t9=C_rest_nullp(c,7);
t10=C_rest_nullp(c,8);
t11=(C_truep(t10)?C_SCHEME_END_OF_LIST:C_get_rest_arg(c,8,av,7,t0));
t12=C_rest_nullp(c,8);
t13=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7798,a[2]=t8,a[3]=t2,a[4]=t3,a[5]=t5,a[6]=t4,a[7]=t11,a[8]=t1,a[9]=t6,tmp=(C_word)a,a+=10,tmp);
t14=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8038,a[2]=((C_word)li59),tmp=(C_word)a,a+=3,tmp);
/* modules.scm:399: filter-map */
f_5052(t13,t14,t6);}

/* k7793 in a8025 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7795(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7795,c,av);}
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=C_i_cdr(t2);
if(C_truep(C_i_pairp(t3))){
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* modules.scm:395: ##sys#error */
t4=*((C_word*)lf[83]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[84];
av2[3]=lf[85];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}
else{
/* modules.scm:395: ##sys#error */
t3=*((C_word*)lf[83]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[84];
av2[3]=lf[85];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7798(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_7798,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7801,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8026,a[2]=((C_word)li58),tmp=(C_word)a,a+=3,tmp);
/* modules.scm:404: filter-map */
f_5052(t2,t3,((C_word*)t0)[9]);}

/* k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
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
if(C_unlikely(!C_demand(C_calculate_demand(23,c,3)))){
C_save_and_reclaim((void *)f_7801,c,av);}
a=C_alloc(23);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[21]);
t7=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7827,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=t1,tmp=(C_word)a,a+=10,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7992,a[2]=t4,a[3]=t9,a[4]=t5,a[5]=((C_word)li57),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_7992(t11,t7,((C_word*)t0)[2]);}

/* k7815 in map-loop1503 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7817(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7817,c,av);}
a=C_alloc(12);
t2=C_a_i_list3(&a,3,((C_word*)t0)[2],C_SCHEME_FALSE,t1);
t3=C_a_i_cons(&a,2,t2,C_SCHEME_END_OF_LIST);
t4=C_i_setslot(((C_word*)((C_word*)t0)[3])[1],C_fix(1),t3);
t5=C_mutate(((C_word *)((C_word*)t0)[3])+1,t3);
t6=((C_word*)((C_word*)t0)[4])[1];
f_7992(t6,((C_word*)t0)[5],C_slot(((C_word*)t0)[6],C_fix(1)));}

/* k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7827(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_7827,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7990,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* modules.scm:410: scheme#append */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=((C_word*)t0)[9];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7833(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(20,c,3)))){
C_save_and_reclaim((void *)f_7833,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7834,a[2]=t1,a[3]=((C_word)li53),tmp=(C_word)a,a+=4,tmp);
t3=C_i_check_list_2(((C_word*)t0)[2],lf[36]);
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7859,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[2],tmp=(C_word)a,a+=9,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7937,a[2]=t6,a[3]=t2,a[4]=((C_word)li56),tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_7937(t8,t4,((C_word*)t0)[2]);}

/* g1536 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7834(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_7834,3,t0,t1,t2);}
a=C_alloc(10);
t3=C_i_cdr(t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7846,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=C_i_cadr(t2);
if(C_truep(t5)){
/* modules.scm:421: merge-se */
f_7025(t4,C_a_i_list(&a,2,t5,((C_word*)t0)[2]));}
else{
/* modules.scm:421: merge-se */
f_7025(t4,C_a_i_list(&a,2,C_SCHEME_END_OF_LIST,((C_word*)t0)[2]));}}

/* k7844 in g1536 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7846(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7846,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_set_car(((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7857 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7859(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_7859,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7860,a[2]=((C_word*)t0)[2],a[3]=((C_word)li54),tmp=(C_word)a,a+=4,tmp);
t3=C_i_check_list_2(((C_word*)t0)[3],lf[36]);
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7885,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],tmp=(C_word)a,a+=7,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7914,a[2]=t6,a[3]=t2,a[4]=((C_word)li55),tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_7914(t8,t4,((C_word*)t0)[3]);}

/* g1546 in k7857 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7860(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_7860,3,t0,t1,t2);}
a=C_alloc(10);
t3=C_i_cdr(t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7872,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=C_i_cadr(t2);
if(C_truep(t5)){
/* modules.scm:425: merge-se */
f_7025(t4,C_a_i_list(&a,2,t5,((C_word*)t0)[2]));}
else{
/* modules.scm:425: merge-se */
f_7025(t4,C_a_i_list(&a,2,C_SCHEME_END_OF_LIST,((C_word*)t0)[2]));}}

/* k7870 in g1546 in k7857 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7872(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7872,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_set_car(((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7883 in k7857 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_7885,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7888,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7904,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7912,a[2]=t3,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:429: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[32]+1);
av2[1]=t4;
tp(2,av2);}}

/* k7886 in k7883 in k7857 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7888(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_7888,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_cons(&a,2,t2,*((C_word*)lf[28]+1));
t4=C_mutate((C_word*)lf[28]+1 /* (set! ##sys#module-table ...) */,t3);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k7902 in k7883 in k7857 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7904(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_7904,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7908,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:430: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t2;
tp(2,av2);}}

/* k7906 in k7902 in k7883 in k7857 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7908(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_7908,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_i_check_structure_2(((C_word*)t0)[3],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t4=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[3];
av2[3]=C_fix(14);
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k7910 in k7883 in k7857 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7912(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_7912,c,av);}
a=C_alloc(9);
/* modules.scm:429: merge-se */
f_7025(((C_word*)t0)[2],C_a_i_list(&a,3,t1,((C_word*)t0)[3],((C_word*)t0)[4]));}

/* for-each-loop1545 in k7857 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7914(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_7914,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7924,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:423: g1546 */
t4=((C_word*)t0)[3];
f_7860(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k7922 in for-each-loop1545 in k7857 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7924(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7924,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7914(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop1535 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7937(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_7937,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7947,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:419: g1536 */
t4=((C_word*)t0)[3];
f_7834(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k7945 in for-each-loop1535 in k7831 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7947(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7947,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7937(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k7969 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7971(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7971,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7975,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* modules.scm:416: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[32]+1);
av2[1]=t2;
tp(2,av2);}}

/* k7973 in k7969 in k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7975(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_7975,c,av);}
a=C_alloc(18);
/* modules.scm:414: merge-se */
f_7025(((C_word*)t0)[2],C_a_i_list(&a,6,((C_word*)t0)[3],t1,((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]));}

/* k7988 in k7825 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_7990(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(35,c,2)))){
C_save_and_reclaim((void *)f_7990,c,av);}
a=C_alloc(35);
t2=(
/* modules.scm:410: make-module */
  f_5969(C_a_i(&a,17),((C_word*)t0)[2],((C_word*)t0)[3],C_SCHEME_END_OF_LIST,((C_word*)t0)[4],t1,((C_word*)t0)[5],C_a_i_list(&a,1,((C_word*)t0)[6]))
);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7833,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[2],a[5]=t2,a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[4],tmp=(C_word)a,a+=8,tmp);
t4=C_i_nullp(((C_word*)t0)[7]);
t5=C_i_not(t4);
t6=(C_truep(t5)?t5:C_i_not(C_i_nullp(((C_word*)t0)[8])));
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7971,a[2]=t3,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],tmp=(C_word)a,a+=7,tmp);
/* modules.scm:415: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t7;
tp(2,av2);}}
else{
t7=t3;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_END_OF_LIST;
f_7833(2,av2);}}}

/* map-loop1503 in k7799 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_7992(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_7992,3,t0,t1,t2);}
a=C_alloc(7);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_car(t3);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7817,a[2]=t4,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=t2,tmp=(C_word)a,a+=7,tmp);
/* modules.scm:408: ##sys#ensure-transformer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[82]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[82]+1);
av2[1]=t5;
av2[2]=C_u_i_cdr(t3);
av2[3]=C_u_i_car(t3);
tp(4,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* a8025 in k7796 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8026(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_8026,c,av);}
a=C_alloc(4);
if(C_truep(C_i_symbolp(t2))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7795,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:392: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t3;
tp(2,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* a8037 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8038(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_8038,c,av);}
a=C_alloc(4);
t3=C_i_symbolp(t2);
if(C_truep(C_i_not(t3))){
t4=C_i_car(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8056,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:401: ##sys#ensure-transformer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[82]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[82]+1);
av2[1]=t5;
av2[2]=C_u_i_cdr(t2);
av2[3]=C_u_i_car(t2);
tp(4,av2);}}
else{
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k8054 in a8037 in ##sys#register-compiled-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8056(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_8056,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list3(&a,3,((C_word*)t0)[3],C_SCHEME_FALSE,t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#register-core-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8090(C_word c,C_word *av){
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
if(c<5) C_bad_min_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_8090,c,av);}
a=C_alloc(7);
t5=C_rest_nullp(c,5);
t6=(C_truep(t5)?C_SCHEME_END_OF_LIST:C_get_rest_arg(c,5,av,5,t0));
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8097,a[2]=t2,a[3]=t6,a[4]=t3,a[5]=t4,a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* modules.scm:435: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t7;
tp(2,av2);}}

/* k8095 in ##sys#register-core-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8097(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,c,3)))){
C_save_and_reclaim((void *)f_8097,c,av);}
a=C_alloc(25);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8140,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word)li61),tmp=(C_word)a,a+=5,tmp);
t7=C_i_check_list_2(((C_word*)t0)[3],lf[21]);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8162,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8164,a[2]=t4,a[3]=t10,a[4]=t6,a[5]=t5,a[6]=((C_word)li62),tmp=(C_word)a,a+=7,tmp));
t12=((C_word*)t10)[1];
f_8164(t12,t8,((C_word*)t0)[3]);}

/* k8101 in k8160 in k8095 in ##sys#register-core-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8103(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_8103,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_cons(&a,2,t2,*((C_word*)lf[28]+1));
t4=C_mutate((C_word*)lf[28]+1 /* (set! ##sys#module-table ...) */,t3);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k8117 in k8160 in k8095 in ##sys#register-core-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8119(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_8119,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8123,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:453: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t2;
tp(2,av2);}}

/* k8121 in k8117 in k8160 in k8095 in ##sys#register-core-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8123(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_8123,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_i_check_structure_2(((C_word*)t0)[3],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t4=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[3];
av2[3]=C_fix(14);
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k8125 in k8160 in k8095 in ##sys#register-core-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8127(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8127,c,av);}
a=C_alloc(9);
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[15]);
t3=C_i_block_ref(((C_word*)t0)[2],C_fix(11));
t4=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[16]);
t5=C_i_block_ref(((C_word*)t0)[2],C_fix(12));
/* modules.scm:450: merge-se */
f_7025(((C_word*)t0)[3],C_a_i_list(&a,3,t1,t3,t5));}

/* g1604 in k8095 in ##sys#register-core-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8140(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_8140,3,t0,t1,t2);}
if(C_truep(C_i_symbolp(t2))){
t3=C_i_assq(t2,((C_word*)t0)[2]);
if(C_truep(t3)){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* modules.scm:442: ##sys#error */
t4=*((C_word*)lf[83]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=lf[87];
av2[3]=t2;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8160 in k8095 in ##sys#register-core-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8162(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(30,c,2)))){
C_save_and_reclaim((void *)f_8162,c,av);}
a=C_alloc(30);
t2=(
/* modules.scm:436: make-module */
  f_5969(C_a_i(&a,17),((C_word*)t0)[2],((C_word*)t0)[3],C_SCHEME_END_OF_LIST,((C_word*)t0)[4],t1,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST)
);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8103,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8119,a[2]=t2,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8127,a[2]=t2,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:450: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[32]+1);
av2[1]=t5;
tp(2,av2);}}

/* map-loop1598 in k8095 in ##sys#register-core-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8164(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_8164,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8189,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:439: g1604 */
t4=((C_word*)t0)[4];
f_8140(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8187 in map-loop1598 in k8095 in ##sys#register-core-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8189(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8189,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_8164(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* ##sys#register-primitive-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8204(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_8204,c,av);}
if(C_truep(C_rest_nullp(c,4))){
/* modules.scm:460: ##sys#register-core-module */
t4=*((C_word*)lf[86]+1);{
C_word av2[6];
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_SCHEME_FALSE;
av2[4]=t3;
av2[5]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(6,av2);}}
else{
/* modules.scm:460: ##sys#register-core-module */
t4=*((C_word*)lf[86]+1);{
C_word av2[6];
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_SCHEME_FALSE;
av2[4]=t3;
av2[5]=C_get_rest_arg(c,4,av,4,t0);
((C_proc)(void*)(*((C_word*)t4+1)))(6,av2);}}}

/* find-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8219(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_8219,4,t1,t2,t3,t4);}
a=C_alloc(5);
t5=C_i_check_structure_2(t3,lf[6],lf[14]);
t6=C_i_block_ref(t3,C_fix(3));
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8230,a[2]=t2,a[3]=t4,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t8=C_eqp(C_SCHEME_TRUE,t6);
if(C_truep(t8)){
t9=C_i_check_structure_2(t3,lf[6],lf[35]);
t10=t7;
f_8230(t10,C_i_block_ref(t3,C_fix(5)));}
else{
t9=t7;
f_8230(t9,t6);}}

/* k8228 in find-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8230(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_8230,2,t0,t1);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8232,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li65),tmp=(C_word)a,a+=5,tmp);
t3=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t3;
av2[1]=(
  f_8232(t2,t1)
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* loop in k8228 in find-export in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static C_word C_fcall f_8232(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_nullp(t1))){
return(C_SCHEME_FALSE);}
else{
t2=C_i_car(t1);
t3=C_eqp(((C_word*)t0)[2],t2);
if(C_truep(t3)){
return(t3);}
else{
if(C_truep(C_i_pairp(C_u_i_car(t1)))){
t4=C_i_caar(t1);
t5=C_eqp(((C_word*)t0)[2],t4);
if(C_truep(t5)){
return(t5);}
else{
if(C_truep(((C_word*)t0)[3])){
t6=C_u_i_car(t1);
t7=C_i_memq(((C_word*)t0)[2],C_u_i_cdr(t6));
if(C_truep(t7)){
return(t7);}
else{
t9=C_u_i_cdr(t1);
t1=t9;
goto loop;}}
else{
t9=C_u_i_cdr(t1);
t1=t9;
goto loop;}}}
else{
t9=C_u_i_cdr(t1);
t1=t9;
goto loop;}}}}

/* ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8297(C_word c,C_word *av){
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
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(26,c,3)))){
C_save_and_reclaim((void *)f_8297,c,av);}
a=C_alloc(26);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9312,a[2]=((C_word)li67),tmp=(C_word)a,a+=3,tmp):C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8303,a[2]=t2,a[3]=((C_word)li78),tmp=(C_word)a,a+=4,tmp);
t6=C_i_check_structure_2(t2,lf[6],lf[14]);
t7=C_i_block_ref(t2,C_fix(3));
t8=C_i_check_structure_2(t2,lf[6],lf[8]);
t9=C_i_block_ref(t2,C_fix(1));
t10=C_i_check_structure_2(t2,lf[6],lf[47]);
t11=C_i_block_ref(t2,C_fix(4));
t12=C_i_check_structure_2(t2,lf[6],lf[35]);
t13=C_i_block_ref(t2,C_fix(5));
t14=C_SCHEME_FALSE;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_8819,a[2]=t13,a[3]=t2,a[4]=t1,a[5]=t15,a[6]=t9,a[7]=t5,a[8]=t7,a[9]=t11,a[10]=t4,tmp=(C_word)a,a+=11,tmp);
t17=C_i_check_structure_2(t2,lf[6],lf[52]);
t18=C_i_block_ref(t2,C_fix(6));
t19=C_SCHEME_UNDEFINED;
t20=(*a=C_VECTOR_TYPE|1,a[1]=t19,tmp=(C_word)a,a+=2,tmp);
t21=C_set_block_item(t20,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8757,a[2]=t20,a[3]=((C_word)li94),tmp=(C_word)a,a+=4,tmp));
t22=((C_word*)t20)[1];
f_8757(t22,t16,t18);}

/* report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8303(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_8303,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8307,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:484: chicken.base#open-output-string */
t4=*((C_word*)lf[99]+1);{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8307(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_8307,c,av);}
a=C_alloc(6);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[90]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8313,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:485: ##sys#print */
t4=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[114];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8313(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_8313,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8316,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_i_check_structure_2(((C_word*)t0)[5],lf[6],lf[8]);
/* modules.scm:485: ##sys#print */
t4=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=C_i_block_ref(((C_word*)t0)[5],C_fix(1));
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8316(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_8316,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8319,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:485: ##sys#print */
t3=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[113];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8319(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,c,3)))){
C_save_and_reclaim((void *)f_8319,c,av);}
a=C_alloc(25);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8322,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8636,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_i_check_list_2(((C_word*)t0)[4],lf[21]);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8707,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8709,a[2]=t6,a[3]=t11,a[4]=t7,a[5]=((C_word)li77),tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_8709(t13,t9,((C_word*)t0)[4]);}

/* k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8322(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8322,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8323,a[2]=((C_word*)t0)[2],a[3]=((C_word)li74),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8602,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8611,a[2]=t5,a[3]=t2,a[4]=((C_word)li75),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_8611(t7,t3,((C_word*)t0)[4]);}

/* g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8323(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_8323,3,t0,t1,t2);}
a=C_alloc(5);
t3=C_i_check_port_2(((C_word*)t0)[2],C_fix(2),C_SCHEME_TRUE,lf[90]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8330,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:500: ##sys#print */
t5=*((C_word*)lf[93]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[109];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8330(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_8330,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8333,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:500: ##sys#print */
t3=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_car(((C_word*)t0)[3]);
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8333(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_8333,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8336,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:500: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[101]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[101]+1);
av2[1]=t2;
av2[2]=C_make_character(39);
av2[3]=((C_word*)t0)[2];
tp(4,av2);}}

/* k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8336(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_8336,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8337,a[2]=((C_word*)t0)[2],a[3]=((C_word)li70),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8475,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:518: scheme#reverse */
t4=*((C_word*)lf[59]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_u_i_cdr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8337(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_8337,3,t0,t1,t2);}
a=C_alloc(12);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8340,a[2]=((C_word)li68),tmp=(C_word)a,a+=3,tmp);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?(C_truep(C_u_i_car(t2))?C_u_i_cdr(t2):C_SCHEME_FALSE):C_SCHEME_FALSE);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8370,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t5)){
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8380,a[2]=t3,a[3]=t2,a[4]=((C_word)li69),tmp=(C_word)a,a+=5,tmp);
/* modules.scm:510: g1783 */
t8=t7;
f_8380(t8,t6,t5);}
else{
t7=C_i_pairp(t2);
t8=(C_truep(t7)?C_u_i_cdr(t2):C_SCHEME_FALSE);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8422,a[2]=t6,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:515: chicken.base#open-output-string */
t10=*((C_word*)lf[99]+1);{
C_word av2[2];
av2[0]=t10;
av2[1]=t9;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8445,a[2]=t6,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:516: chicken.base#open-output-string */
t10=*((C_word*)lf[99]+1);{
C_word av2[2];
av2[0]=t10;
av2[1]=t9;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}}}

/* ln->num in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8340(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_8340,2,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8344,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:505: chicken.string#string-split */
t4=*((C_word*)lf[91]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[92];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k8342 in ln->num in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_8344(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8344,c,av);}
if(C_truep(C_i_pairp(t1))){
t2=C_i_length(t1);
t3=C_eqp(C_fix(2),t2);
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?C_i_cadr(t1):((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k8368 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8370(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_8370,c,av);}
a=C_alloc(5);
t2=C_i_check_port_2(((C_word*)t0)[2],C_fix(2),C_SCHEME_TRUE,lf[90]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8376,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:517: ##sys#print */
t4=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[94];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k8374 in k8368 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_8376(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8376,c,av);}
/* modules.scm:517: ##sys#print */
t2=*((C_word*)lf[93]+1);{
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

/* g1783 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8380(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_8380,3,t0,t1,t2);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8384,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:513: chicken.base#open-output-string */
t4=*((C_word*)lf[99]+1);{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k8382 in g1783 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_8384(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_8384,c,av);}
a=C_alloc(7);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[95]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8390,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* modules.scm:513: ##sys#print */
t4=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[98];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k8388 in k8382 in g1783 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_8390(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_8390,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8393,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:513: ##sys#print */
t3=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_car(((C_word*)t0)[6]);
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k8391 in k8388 in k8382 in g1783 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_8393(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_8393,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8396,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:513: ##sys#print */
t3=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[97];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k8394 in k8391 in k8388 in k8382 in g1783 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in ... */
static void C_ccall f_8396(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_8396,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8399,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8406,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:513: ln->num */
f_8340(t3,((C_word*)t0)[5]);}

/* k8397 in k8394 in k8391 in k8388 in k8382 in g1783 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in ... */
static void C_ccall f_8399(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8399,c,av);}
/* modules.scm:513: chicken.base#get-output-string */
t2=*((C_word*)lf[96]+1);{
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

/* k8404 in k8394 in k8391 in k8388 in k8382 in g1783 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in ... */
static void C_ccall f_8406(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8406,c,av);}
/* modules.scm:513: ##sys#print */
t2=*((C_word*)lf[93]+1);{
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

/* k8420 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8422(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_8422,c,av);}
a=C_alloc(6);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[95]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8428,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:515: ##sys#print */
t4=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[100];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k8426 in k8420 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_8428(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_8428,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8431,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8438,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:515: ln->num */
f_8340(t3,C_i_cdr(((C_word*)t0)[5]));}

/* k8429 in k8426 in k8420 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_8431(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8431,c,av);}
/* modules.scm:515: chicken.base#get-output-string */
t2=*((C_word*)lf[96]+1);{
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

/* k8436 in k8426 in k8420 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_8438(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8438,c,av);}
/* modules.scm:515: ##sys#print */
t2=*((C_word*)lf[93]+1);{
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

/* k8443 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8445(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_8445,c,av);}
a=C_alloc(5);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[95]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8451,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:516: ##sys#print */
t4=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[102];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k8449 in k8443 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_8451(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_8451,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8454,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:516: ##sys#print */
t3=*((C_word*)lf[93]+1);{
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

/* k8452 in k8449 in k8443 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_8454(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_8454,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8457,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:516: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[101]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[101]+1);
av2[1]=t2;
av2[2]=C_make_character(39);
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k8455 in k8452 in k8449 in k8443 in g1756 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_8457(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8457,c,av);}
/* modules.scm:516: chicken.base#get-output-string */
t2=*((C_word*)lf[96]+1);{
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

/* k8473 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8475(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8475,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8478,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8572,a[2]=t4,a[3]=((C_word*)t0)[5],a[4]=((C_word)li73),tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_8572(t6,t2,t1);}

/* k8476 in k8473 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8478(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8478,c,av);}
a=C_alloc(5);
t2=C_u_i_car(((C_word*)t0)[2]);
if(C_truep(t2)){
t3=C_i_getprop(t2,lf[103],C_SCHEME_FALSE);
if(C_truep(t3)){
t4=C_i_check_port_2(((C_word*)t0)[3],C_fix(2),C_SCHEME_TRUE,lf[90]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8496,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:523: ##sys#print */
t6=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[108];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8494 in k8476 in k8473 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_8496(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8496,c,av);}
a=C_alloc(5);
t2=C_i_length(((C_word*)t0)[2]);
t3=C_eqp(C_fix(1),t2);
if(C_truep(t3)){
t4=C_i_check_port_2(((C_word*)t0)[3],C_fix(2),C_SCHEME_TRUE,lf[90]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8508,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:526: ##sys#print */
t6=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[105];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t4=C_i_check_port_2(((C_word*)t0)[3],C_fix(2),C_SCHEME_TRUE,lf[90]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8524,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:528: ##sys#print */
t6=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[107];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}}

/* k8506 in k8494 in k8476 in k8473 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_8508(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_8508,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8511,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8518,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:526: scheme#cadar */
t4=*((C_word*)lf[104]+1);{
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

/* k8509 in k8506 in k8494 in k8476 in k8473 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_8511(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8511,c,av);}
/* modules.scm:526: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[101]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[101]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(39);
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k8516 in k8506 in k8494 in k8476 in k8473 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_8518(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8518,c,av);}
/* modules.scm:526: ##sys#print */
t2=*((C_word*)lf[93]+1);{
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

/* k8522 in k8494 in k8476 in k8473 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_8524(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8524,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8525,a[2]=((C_word*)t0)[2],a[3]=((C_word)li71),tmp=(C_word)a,a+=4,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8544,a[2]=t4,a[3]=t2,a[4]=((C_word)li72),tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_8544(t6,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* g1866 in k8522 in k8494 in k8476 in k8473 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_fcall f_8525(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_8525,3,t0,t1,t2);}
a=C_alloc(5);
t3=C_i_check_port_2(((C_word*)t0)[2],C_fix(2),C_SCHEME_TRUE,lf[90]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8532,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:531: ##sys#print */
t5=*((C_word*)lf[93]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[106];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k8530 in g1866 in k8522 in k8494 in k8476 in k8473 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in ... */
static void C_ccall f_8532(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8532,c,av);}
/* modules.scm:531: ##sys#print */
t2=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_i_cadr(((C_word*)t0)[3]);
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* for-each-loop1865 in k8522 in k8494 in k8476 in k8473 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_fcall f_8544(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_8544,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8554,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:529: g1866 */
t4=((C_word*)t0)[3];
f_8525(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k8552 in for-each-loop1865 in k8522 in k8494 in k8476 in k8473 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in ... */
static void C_ccall f_8554(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8554,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_8544(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop1755 in k8473 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8572(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_8572,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8582,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:503: g1756 */
t4=((C_word*)t0)[3];
f_8337(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k8580 in for-each-loop1755 in k8473 in k8334 in k8331 in k8328 in g1688 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_8582(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8582,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_8572(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k8600 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8602(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8602,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8609,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:535: chicken.base#get-output-string */
t3=*((C_word*)lf[96]+1);{
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

/* k8607 in k8600 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8609(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8609,c,av);}
/* modules.scm:535: ##sys#error */
t2=*((C_word*)lf[83]+1);{
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

/* for-each-loop1687 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8611(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_8611,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8621,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:498: g1688 */
t4=((C_word*)t0)[3];
f_8323(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k8619 in for-each-loop1687 in k8320 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8621(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8621,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_8611(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k8634 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8636(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_8636,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8638,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word)li76),tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_8638(t5,((C_word*)t0)[3],t1);}

/* lp in k8634 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8638(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_8638,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=C_i_car(t2);
if(C_truep(t3)){
t4=C_i_pairp(t3);
t5=(C_truep(t4)?C_u_i_cdr(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8668,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:492: chicken.string#string-split */
t7=*((C_word*)lf[91]+1);{
C_word av2[4];
av2[0]=t7;
av2[1]=t6;
av2[2]=t5;
av2[3]=lf[112];
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
/* modules.scm:496: lp */
t8=t1;
t9=C_u_i_cdr(t2);
t1=t8;
t2=t9;
goto loop;}}
else{
/* modules.scm:496: lp */
t8=t1;
t9=C_u_i_cdr(t2);
t1=t8;
t2=t9;
goto loop;}}}

/* k8666 in lp in k8634 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8668(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_8668,c,av);}
a=C_alloc(5);
t2=C_eqp(C_fix(2),C_u_i_length(t1));
if(C_truep(t2)){
t3=C_i_check_port_2(((C_word*)t0)[2],C_fix(2),C_SCHEME_TRUE,lf[90]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8680,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:494: ##sys#print */
t5=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[111];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
/* modules.scm:496: lp */
t3=((C_word*)((C_word*)t0)[4])[1];
f_8638(t3,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[5]));}}

/* k8678 in k8666 in lp in k8634 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8680(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_8680,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8683,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:494: ##sys#print */
t3=*((C_word*)lf[93]+1);{
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

/* k8681 in k8678 in k8666 in lp in k8634 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8683(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_8683,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8686,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:494: ##sys#print */
t3=*((C_word*)lf[93]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[110];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k8684 in k8681 in k8678 in k8666 in lp in k8634 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8686(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8686,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8705 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8707(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8707,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[22]+1);
av2[3]=t1;
C_apply(4,av2);}}

/* map-loop1723 in k8317 in k8314 in k8311 in k8305 in report-unresolved-identifiers in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8709(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_8709,3,t0,t1,t2);}
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

/* loop in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8757(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_8757,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8800,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:540: ##sys#get */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[134]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[134]+1);
av2[1]=t3;
av2[2]=C_i_caar(t2);
av2[3]=lf[135];
tp(4,av2);}}}

/* k8784 in k8794 in k8798 in loop in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8786(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_8786,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8794 in k8798 in loop in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8796(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_8796,c,av);}
a=C_alloc(4);
t2=C_i_assq(((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8786,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:543: loop */
t4=((C_word*)((C_word*)t0)[4])[1];
f_8757(t4,t3,C_u_i_cdr(((C_word*)t0)[5]));}

/* k8798 in loop in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8800(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_8800,c,av);}
a=C_alloc(6);
t2=C_eqp(t1,lf[136]);
if(C_truep(t2)){
/* modules.scm:541: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_8757(t3,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}
else{
t3=C_i_caar(((C_word*)t0)[4]);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8796,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:542: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t4;
tp(2,av2);}}}

/* k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8819(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_8819,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_8822,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
t3=C_eqp(C_SCHEME_TRUE,((C_word*)t0)[8]);
if(C_truep(t3)){
t4=C_i_check_structure_2(((C_word*)t0)[3],lf[6],lf[16]);
t5=C_i_block_ref(((C_word*)t0)[3],C_fix(12));
/* modules.scm:553: merge-se */
f_7025(t2,C_a_i_list(&a,2,t5,t1));}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9254,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:554: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t4;
tp(2,av2);}}}

/* k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8822(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8822,c,av);}
a=C_alloc(21);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_8825,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t3=C_eqp(C_SCHEME_TRUE,((C_word*)t0)[9]);
t4=(C_truep(t3)?((C_word*)t0)[2]:((C_word*)t0)[9]);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9065,a[2]=t6,a[3]=t1,a[4]=((C_word*)t0)[10],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[11],a[8]=((C_word)li92),tmp=(C_word)a,a+=9,tmp));
t8=((C_word*)t6)[1];
f_9065(t8,t2,t4);}

/* k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8825(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_8825,c,av);}
a=C_alloc(19);
t2=C_SCHEME_END_OF_LIST;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8826,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word)li79),tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_8844,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=t1,a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t3,a[10]=((C_word*)t0)[9],a[11]=t4,tmp=(C_word)a,a+=12,tmp);
/* modules.scm:605: module-undefined-list */
t6=*((C_word*)lf[9]+1);{
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

/* g1958 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static C_word C_fcall f_8826(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;{}
t2=C_i_car(t1);
if(C_truep(C_i_memq(t2,((C_word*)t0)[2]))){
t3=C_SCHEME_UNDEFINED;
return(t3);}
else{
t3=C_a_i_cons(&a,2,t1,((C_word*)((C_word*)t0)[3])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[3])+1,t3);
return(t4);}}

/* k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8844(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8844,c,av);}
a=C_alloc(18);
t2=C_i_check_list_2(t1,lf[36]);
t3=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_8850,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9038,a[2]=((C_word*)t0)[11],a[3]=t5,a[4]=((C_word)li88),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_9038(t7,t3,t1);}

/* k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8850(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_8850,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_8853,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_i_nullp(((C_word*)((C_word*)t0)[9])[1]))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_8853(2,av2);}}
else{
/* modules.scm:607: report-unresolved-identifiers */
t3=((C_word*)t0)[10];
f_8303(t3,t2,((C_word*)((C_word*)t0)[9])[1]);}}

/* k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8853(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_8853,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8856,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)((C_word*)t0)[7])[1])){
/* modules.scm:610: ##sys#error */
t3=*((C_word*)lf[83]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[123];
av2[3]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_8856(2,av2);}}}

/* k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8856(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(27,c,4)))){
C_save_and_reclaim((void *)f_8856,c,av);}
a=C_alloc(27);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_8891,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t4,a[8]=t5,tmp=(C_word)a,a+=9,tmp);
t7=C_i_check_structure_2(((C_word*)t0)[3],lf[6],lf[14]);
t8=C_i_block_ref(((C_word*)t0)[3],C_fix(3));
t9=C_i_check_structure_2(((C_word*)t0)[3],lf[6],lf[8]);
t10=C_i_block_ref(((C_word*)t0)[3],C_fix(1));
t11=C_i_check_structure_2(((C_word*)t0)[3],lf[6],lf[47]);
t12=C_i_block_ref(((C_word*)t0)[3],C_fix(4));
t13=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6821,a[2]=t10,a[3]=((C_word)li83),tmp=(C_word)a,a+=4,tmp);
t14=C_eqp(C_SCHEME_TRUE,t8);
if(C_truep(t14)){
t15=t6;{
C_word *av2=av;
av2[0]=t15;
av2[1]=C_SCHEME_END_OF_LIST;
f_8891(2,av2);}}
else{
t15=C_SCHEME_UNDEFINED;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_set_block_item(t16,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6844,a[2]=t16,a[3]=t13,a[4]=t12,a[5]=t10,a[6]=((C_word)li87),tmp=(C_word)a,a+=7,tmp));
t18=((C_word*)t16)[1];
f_6844(t18,t6,t8);}}

/* k8882 in map-loop1977 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8884(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_8884,c,av);}
a=C_alloc(3);
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=((C_word*)t0)[3];
f_9005(t3,C_a_i_cons(&a,2,t2,C_SCHEME_END_OF_LIST));}
else{
/* modules.scm:615: ##sys#error */
t3=*((C_word*)lf[83]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
av2[2]=lf[115];
av2[3]=C_u_i_car(((C_word*)t0)[5]);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8891(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8891,c,av);}
a=C_alloc(15);
t2=C_i_check_list_2(t1,lf[21]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8897,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8995,a[2]=((C_word*)t0)[7],a[3]=t5,a[4]=((C_word*)t0)[8],a[5]=((C_word)li82),tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_8995(t7,t3,t1);}

/* k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8897(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_8897,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8900,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,tmp=(C_word)a,a+=8,tmp);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8989,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
/* modules.scm:618: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t3;
tp(2,av2);}}

/* k8898 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8900(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_8900,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8901,a[2]=t1,a[3]=((C_word)li80),tmp=(C_word)a,a+=4,tmp);
t3=C_i_check_list_2(((C_word*)t0)[2],lf[36]);
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8923,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],tmp=(C_word)a,a+=7,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8964,a[2]=t6,a[3]=t2,a[4]=((C_word)li81),tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_8964(t8,t4,((C_word*)t0)[2]);}

/* g2013 in k8898 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8901(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_8901,3,t0,t1,t2);}
a=C_alloc(10);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8905,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_i_cadr(t2);
/* modules.scm:623: merge-se */
f_7025(t3,C_a_i_list(&a,2,t4,((C_word*)t0)[2]));}

/* k8903 in g2013 in k8898 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8905(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8905,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_set_car(C_u_i_cdr(((C_word*)t0)[3]),t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8921 in k8898 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8923(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_8923,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8929,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t4=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(11);
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k8927 in k8921 in k8898 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8929(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_8929,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8932,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t4=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(12);
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k8930 in k8927 in k8921 in k8898 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_8932(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_8932,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8935,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8958,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[69]);
t5=C_i_block_ref(((C_word*)t0)[2],C_fix(13));
/* modules.scm:638: merge-se */
f_7025(t3,C_a_i_list(&a,2,t5,((C_word*)t0)[6]));}

/* k8933 in k8930 in k8927 in k8921 in k8898 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_8935(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_8935,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8946,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8954,a[2]=t2,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:641: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[32]+1);
av2[1]=t3;
tp(2,av2);}}

/* k8944 in k8933 in k8930 in k8927 in k8921 in k8898 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_8946(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_8946,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8950,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:642: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t2;
tp(2,av2);}}

/* k8948 in k8944 in k8933 in k8930 in k8927 in k8921 in k8898 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in ... */
static void C_ccall f_8950(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_8950,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_i_check_structure_2(((C_word*)t0)[3],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t4=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[3];
av2[3]=C_fix(14);
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k8952 in k8933 in k8930 in k8927 in k8921 in k8898 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_8954(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_8954,c,av);}
a=C_alloc(9);
/* modules.scm:641: merge-se */
f_7025(((C_word*)t0)[2],C_a_i_list(&a,3,t1,((C_word*)t0)[3],((C_word*)t0)[4]));}

/* k8956 in k8930 in k8927 in k8921 in k8898 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_8958(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8958,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
/* modules.scm:96: ##sys#block-set! */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(13);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* for-each-loop2012 in k8898 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8964(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_8964,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8974,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:621: g2013 */
t4=((C_word*)t0)[3];
f_8901(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k8972 in for-each-loop2012 in k8898 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8974(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8974,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_8964(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k8987 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8989(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_8989,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8993,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* modules.scm:619: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[32]+1);
av2[1]=t2;
tp(2,av2);}}

/* k8991 in k8987 in k8895 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_8993(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_8993,c,av);}
a=C_alloc(18);
/* modules.scm:617: merge-se */
f_7025(((C_word*)t0)[2],C_a_i_list(&a,6,((C_word*)t0)[3],t1,((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]));}

/* map-loop1977 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_8995(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,2)))){
C_save_and_reclaim_args((void *)trf_8995,3,t0,t1,t2);}
a=C_alloc(15);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9005,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9020,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=C_slot(t2,C_fix(0));
t6=C_i_cdr(t5);
if(C_truep(C_i_symbolp(t6))){
t7=t3;
f_9005(t7,C_a_i_cons(&a,2,t5,C_SCHEME_END_OF_LIST));}
else{
t7=C_u_i_car(t5);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8884,a[2]=t7,a[3]=t3,a[4]=t4,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:614: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word av2[2];
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t8;
tp(2,av2);}}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k9003 in map-loop1977 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9005(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_9005,2,t0,t1);}
t2=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t1);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t4=((C_word*)((C_word*)t0)[3])[1];
f_8995(t4,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k9018 in map-loop1977 in k8889 in k8854 in k8851 in k8848 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9020(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_9020,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];
f_9005(t2,C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST));}

/* for-each-loop1957 in k8842 in k8823 in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9038(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_9038,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* modules.scm:602: g1958 */
  f_8826(C_a_i(&a,3),((C_word*)t0)[2],C_slot(t2,C_fix(0)))
);
t5=t1;
t6=C_slot(t2,C_fix(1));
t1=t5;
t2=t6;
goto loop;}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9065(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,3)))){
C_save_and_reclaim_args((void *)trf_9065,3,t0,t1,t2);}
a=C_alloc(11);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=C_i_symbolp(t3);
t5=(C_truep(t4)?t3:C_i_car(t3));
t6=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_9228,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t5,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],a[10]=((C_word*)t0)[7],tmp=(C_word)a,a+=11,tmp);
/* modules.scm:567: ##sys#get */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[134]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[134]+1);
av2[1]=t6;
av2[2]=t5;
av2[3]=lf[135];
tp(4,av2);}}}

/* k9109 in k9118 in k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9111(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_9111,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k9118 in k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9120(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_9120,c,av);}
a=C_alloc(7);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9111,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:598: loop */
t4=((C_word*)((C_word*)t0)[4])[1];
f_9065(t4,t3,C_u_i_cdr(((C_word*)t0)[5]));}

/* fail in k9215 in k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9131(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_9131,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9135,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:579: ##sys#warn */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[43]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[43]+1);
av2[1]=t3;
av2[2]=t2;
tp(3,av2);}}

/* k9133 in fail in k9215 in k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9135(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9135,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_TRUE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* id-string in k9215 in k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9138(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_9138,2,t0,t1);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9146,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* modules.scm:582: scheme#symbol->string */
t3=*((C_word*)lf[119]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k9144 in id-string in k9215 in k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9146(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9146,c,av);}
/* modules.scm:582: scheme#string-append */
t2=*((C_word*)lf[116]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[125];
av2[3]=t1;
av2[4]=lf[126];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k9165 in k9215 in k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9167(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_9167,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9171,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li91),tmp=(C_word)a,a+=5,tmp);
/* modules.scm:583: g1948 */
t3=t2;
f_9171(t3,((C_word*)t0)[4],t1);}
else{
if(C_truep(C_i_not(((C_word*)t0)[5]))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9199,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9203,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* modules.scm:595: id-string */
t4=((C_word*)((C_word*)t0)[3])[1];
f_9138(t4,t3);}
else{
/* modules.scm:597: bomb */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[132]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[132]+1);
av2[1]=((C_word*)t0)[4];
av2[2]=lf[133];
tp(3,av2);}}}}

/* g1948 in k9165 in k9215 in k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9171(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_9171,3,t0,t1,t2);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9179,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9183,a[2]=t3,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:591: id-string */
t5=((C_word*)((C_word*)t0)[3])[1];
f_9138(t5,t4);}

/* k9177 in g1948 in k9165 in k9215 in k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9179(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9179,c,av);}
/* modules.scm:590: fail */
t2=((C_word*)((C_word*)t0)[2])[1];
f_9131(t2,((C_word*)t0)[3],t1);}

/* k9181 in g1948 in k9165 in k9215 in k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9183(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_9183,c,av);}
/* modules.scm:590: scheme#string-append */
t2=*((C_word*)lf[116]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[127];
av2[3]=t1;
av2[4]=lf[128];
av2[5]=((C_word*)t0)[3];
av2[6]=lf[129];
((C_proc)(void*)(*((C_word*)t2+1)))(7,av2);}}

/* k9197 in k9165 in k9215 in k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9199(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9199,c,av);}
/* modules.scm:594: fail */
t2=((C_word*)((C_word*)t0)[2])[1];
f_9131(t2,((C_word*)t0)[3],t1);}

/* k9201 in k9165 in k9215 in k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9203(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9203,c,av);}
/* modules.scm:594: scheme#string-append */
t2=*((C_word*)lf[116]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[130];
av2[3]=t1;
av2[4]=lf[131];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k9215 in k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9217(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9217,c,av);}
a=C_alloc(18);
t2=C_i_assq(((C_word*)t0)[2],t1);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9131,a[2]=((C_word*)t0)[3],a[3]=((C_word)li89),tmp=(C_word)a,a+=4,tmp));
t8=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9138,a[2]=((C_word*)t0)[2],a[3]=((C_word)li90),tmp=(C_word)a,a+=4,tmp));
t9=(C_truep(t2)?C_i_symbolp(C_i_cdr(t2)):C_SCHEME_FALSE);
if(C_truep(t9)){
t10=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t10;
av2[1]=C_i_cdr(t2);
f_9120(2,av2);}}
else{
if(C_truep(((C_word*)t0)[5])){
/* modules.scm:586: module-rename */
f_10990(((C_word*)t0)[4],((C_word*)t0)[2],((C_word*)t0)[6]);}
else{
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9167,a[2]=t4,a[3]=t6,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:587: invalid-export */
t11=((C_word*)t0)[7];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t11;
av2[1]=t10;
av2[2]=((C_word*)t0)[2];
((C_proc)C_fast_retrieve_proc(t11))(3,av2);}}}}

/* k9226 in loop in k8820 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9228(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_9228,c,av);}
a=C_alloc(14);
t2=C_eqp(t1,lf[124]);
if(C_truep(t2)){
/* modules.scm:568: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_9065(t3,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}
else{
if(C_truep(C_i_assq(((C_word*)t0)[5],((C_word*)t0)[6]))){
/* modules.scm:569: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_9065(t3,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}
else{
t3=C_i_assq(((C_word*)t0)[5],((C_word*)t0)[7]);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9120,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t5=(C_truep(t3)?C_i_symbolp(C_i_cdr(t3)):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=t4;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_i_cdr(t3);
f_9120(2,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9217,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[8],a[4]=t4,a[5]=t3,a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[10],tmp=(C_word)a,a+=8,tmp);
/* modules.scm:577: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[32]+1);
av2[1]=t6;
tp(2,av2);}}}}}

/* k9252 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9254(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_9254,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9256,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word)li93),tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_9256(t5,((C_word*)t0)[3],t1);}

/* loop in k9252 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9256(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_9256,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9304,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:556: ##sys#get */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[134]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[134]+1);
av2[1]=t3;
av2[2]=C_i_caar(t2);
av2[3]=lf[135];
tp(4,av2);}}}

/* k9278 in k9302 in loop in k9252 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9280(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_9280,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=C_u_i_car(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9289,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:559: loop */
t4=((C_word*)((C_word*)t0)[4])[1];
f_9256(t4,t3,C_u_i_cdr(((C_word*)t0)[2]));}
else{
/* modules.scm:560: loop */
t2=((C_word*)((C_word*)t0)[4])[1];
f_9256(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[2]));}}

/* k9287 in k9278 in k9302 in loop in k9252 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9289(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_9289,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k9302 in loop in k9252 in k8817 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9304(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_9304,c,av);}
a=C_alloc(5);
t2=C_eqp(t1,lf[136]);
if(C_truep(t2)){
/* modules.scm:557: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_9256(t3,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9280,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:558: find-export */
f_8219(t3,C_i_caar(((C_word*)t0)[4]),((C_word*)t0)[5],C_SCHEME_FALSE);}}

/* f_9312 in ##sys#finalize-module in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9312(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9312,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9319(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_9319,c,av);}
a=C_alloc(8);
t3=*((C_word*)lf[4]+1);
t4=*((C_word*)lf[32]+1);
t5=*((C_word*)lf[137]+1);
t6=*((C_word*)lf[31]+1);
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9323,a[2]=t6,a[3]=t5,a[4]=t4,a[5]=t3,a[6]=t2,a[7]=t1,tmp=(C_word)a,a+=8,tmp);
/* modules.scm:653: ##sys#current-meta-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[137]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[137]+1);
av2[1]=t7;
tp(2,av2);}}

/* k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9323(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_9323,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9326,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* modules.scm:655: ##sys#meta-macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[138]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[138]+1);
av2[1]=t2;
tp(2,av2);}}

/* k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9326(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(37,c,4)))){
C_save_and_reclaim((void *)f_9326,c,av);}
a=C_alloc(37);
t2=C_SCHEME_FALSE;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_END_OF_LIST;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t0)[2];
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=t1;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_SCHEME_TRUE;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_9331,a[2]=t3,a[3]=t5,a[4]=t7,a[5]=t9,a[6]=t11,a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[5],a[10]=((C_word*)t0)[6],a[11]=((C_word)li96),tmp=(C_word)a,a+=12,tmp);
t13=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9387,a[2]=((C_word*)t0)[7],a[3]=((C_word)li97),tmp=(C_word)a,a+=4,tmp);
t14=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_9393,a[2]=t3,a[3]=t5,a[4]=t7,a[5]=t9,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],a[10]=((C_word)li98),tmp=(C_word)a,a+=11,tmp);
/* modules.scm:650: ##sys#dynamic-wind */
t15=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t15;
av2[1]=((C_word*)t0)[8];
av2[2]=t12;
av2[3]=t13;
av2[4]=t14;
((C_proc)(void*)(*((C_word*)t15+1)))(5,av2);}}

/* a9330 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9331(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_9331,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_9335,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
if(C_truep(((C_word*)((C_word*)t0)[6])[1])){
/* modules.scm:650: ##sys#current-module2047 */
t3=((C_word*)t0)[10];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[2])[1];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)((C_word*)t0)[2])[1];
f_9335(2,av2);}}}

/* k9333 in a9330 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9335(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_9335,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_9338,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=t1,tmp=(C_word)a,a+=13,tmp);
if(C_truep(((C_word*)((C_word*)t0)[6])[1])){
/* modules.scm:650: ##sys#current-environment2048 */
t3=((C_word*)t0)[10];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)((C_word*)t0)[3])[1];
f_9338(2,av2);}}}

/* k9336 in k9333 in a9330 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9338(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,4)))){
C_save_and_reclaim((void *)f_9338,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_9341,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=t1,a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
if(C_truep(((C_word*)((C_word*)t0)[6])[1])){
/* modules.scm:650: ##sys#current-meta-environment2049 */
t3=((C_word*)t0)[9];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[4])[1];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)((C_word*)t0)[4])[1];
f_9341(2,av2);}}}

/* k9339 in k9336 in k9333 in a9330 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9341(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,4)))){
C_save_and_reclaim((void *)f_9341,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_9344,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t1,a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],tmp=(C_word)a,a+=15,tmp);
if(C_truep(((C_word*)((C_word*)t0)[6])[1])){
/* modules.scm:650: ##sys#macro-environment2050 */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[5])[1];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)((C_word*)t0)[5])[1];
f_9344(2,av2);}}}

/* k9342 in k9339 in k9336 in k9333 in a9330 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9344(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_9344,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_9348,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],a[15]=((C_word*)t0)[14],tmp=(C_word)a,a+=16,tmp);
/* modules.scm:650: ##sys#current-module2047 */
t3=((C_word*)t0)[13];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k9346 in k9342 in k9339 in k9336 in k9333 in a9330 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9348(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_9348,c,av);}
a=C_alloc(15);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_9352,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],tmp=(C_word)a,a+=15,tmp);
/* modules.scm:650: ##sys#current-environment2048 */
t4=((C_word*)t0)[12];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* k9350 in k9346 in k9342 in k9339 in k9336 in k9333 in a9330 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9352(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_9352,c,av);}
a=C_alloc(14);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_9356,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],tmp=(C_word)a,a+=14,tmp);
/* modules.scm:650: ##sys#current-meta-environment2049 */
t4=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* k9354 in k9350 in k9346 in k9342 in k9339 in k9336 in k9333 in a9330 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9356(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_9356,c,av);}
a=C_alloc(13);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_9360,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],tmp=(C_word)a,a+=13,tmp);
/* modules.scm:650: ##sys#macro-environment2050 */
t4=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* k9358 in k9354 in k9350 in k9346 in k9342 in k9339 in k9336 in k9333 in a9330 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9360(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_9360,c,av);}
a=C_alloc(10);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_9363,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],tmp=(C_word)a,a+=10,tmp);
/* modules.scm:650: ##sys#current-module2047 */
t4=((C_word*)t0)[11];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[12];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t4))(5,av2);}}

/* k9361 in k9358 in k9354 in k9350 in k9346 in k9342 in k9339 in k9336 in k9333 in a9330 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9363(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_9363,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9366,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* modules.scm:650: ##sys#current-environment2048 */
t3=((C_word*)t0)[8];{
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
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}

/* k9364 in k9361 in k9358 in k9354 in k9350 in k9346 in k9342 in k9339 in k9336 in k9333 in a9330 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_9366(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_9366,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9369,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:650: ##sys#current-meta-environment2049 */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}

/* k9367 in k9364 in k9361 in k9358 in k9354 in k9350 in k9346 in k9342 in k9339 in k9336 in k9333 in a9330 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_9369(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_9369,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9372,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:650: ##sys#macro-environment2050 */
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
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}

/* k9370 in k9367 in k9364 in k9361 in k9358 in k9354 in k9350 in k9346 in k9342 in k9339 in k9336 in k9333 in a9330 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_9372(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9372,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a9386 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9387(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9387,c,av);}
/* modules.scm:656: thunk */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a9392 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9393(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_9393,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_9397,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* modules.scm:650: ##sys#current-module2047 */
t3=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k9395 in a9392 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9397(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_9397,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_9400,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* modules.scm:650: ##sys#current-environment2048 */
t3=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k9398 in k9395 in a9392 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9400(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_9400,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_9403,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* modules.scm:650: ##sys#current-meta-environment2049 */
t3=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k9401 in k9398 in k9395 in a9392 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9403(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_9403,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_9406,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
/* modules.scm:650: ##sys#macro-environment2050 */
t3=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k9404 in k9401 in k9398 in k9395 in a9392 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9406(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,4)))){
C_save_and_reclaim((void *)f_9406,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_9409,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
/* modules.scm:650: ##sys#current-module2047 */
t3=((C_word*)t0)[13];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[2])[1];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}

/* k9407 in k9404 in k9401 in k9398 in k9395 in a9392 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9409(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_9409,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_9412,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],tmp=(C_word)a,a+=13,tmp);
/* modules.scm:650: ##sys#current-environment2048 */
t3=((C_word*)t0)[13];{
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
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}

/* k9410 in k9407 in k9404 in k9401 in k9398 in k9395 in a9392 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9412(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_9412,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_9415,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
/* modules.scm:650: ##sys#current-meta-environment2049 */
t3=((C_word*)t0)[12];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[6])[1];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}

/* k9413 in k9410 in k9407 in k9404 in k9401 in k9398 in k9395 in a9392 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9415(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_9415,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_9418,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
/* modules.scm:650: ##sys#macro-environment2050 */
t3=((C_word*)t0)[11];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[8])[1];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}

/* k9416 in k9413 in k9410 in k9407 in k9404 in k9401 in k9398 in k9395 in a9392 in k9324 in k9321 in ##sys#with-environment in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9418(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9418,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)t0)[3]);
t3=C_mutate(((C_word *)((C_word*)t0)[4])+1,((C_word*)t0)[5]);
t4=C_mutate(((C_word *)((C_word*)t0)[6])+1,((C_word*)t0)[7]);
t5=C_mutate(((C_word *)((C_word*)t0)[8])+1,((C_word*)t0)[9]);
t6=((C_word*)t0)[10];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* ##sys#import-library-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9424(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_9424,c,av);}
a=C_alloc(10);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9428,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9463,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9467,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* modules.scm:660: scheme#symbol->string */
t6=*((C_word*)lf[119]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k9426 in ##sys#import-library-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9428(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_9428,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9436,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word)li103),tmp=(C_word)a,a+=5,tmp);
/* modules.scm:662: ##sys#with-environment */
t3=*((C_word*)lf[65]+1);{
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
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* a9435 in k9426 in ##sys#import-library-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9436(C_word c,C_word *av){
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
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(19,c,4)))){
C_save_and_reclaim((void *)f_9436,c,av);}
a=C_alloc(19);
t2=C_SCHEME_FALSE;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9442,a[2]=t5,a[3]=t3,a[4]=((C_word)li100),tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9447,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li101),tmp=(C_word)a,a+=5,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9456,a[2]=t3,a[3]=t5,a[4]=((C_word)li102),tmp=(C_word)a,a+=5,tmp);
/* modules.scm:664: ##sys#dynamic-wind */
t9=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t9;
av2[1]=t1;
av2[2]=t6;
av2[3]=t7;
av2[4]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}

/* a9441 in a9435 in k9426 in ##sys#import-library-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9442(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9442,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[140]+1));
t3=C_mutate((C_word*)lf[140]+1 /* (set! ##sys#notices-enabled ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a9446 in a9435 in k9426 in ##sys#import-library-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9447(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_9447,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9451,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* modules.scm:665: scheme#load */
t3=*((C_word*)lf[141]+1);{
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

/* k9449 in a9446 in a9435 in k9426 in ##sys#import-library-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9451(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9451,c,av);}
/* modules.scm:666: ##sys#find-module */
t2=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[84];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* a9455 in a9435 in k9426 in ##sys#import-library-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9456(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9456,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[140]+1));
t3=C_mutate((C_word*)lf[140]+1 /* (set! ##sys#notices-enabled ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k9461 in ##sys#import-library-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9463(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9463,c,av);}
/* modules.scm:659: chicken.load#find-dynamic-extension */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[142]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[142]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_SCHEME_TRUE;
tp(4,av2);}}

/* k9465 in ##sys#import-library-hook in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9467(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9467,c,av);}
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[143]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[143]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[144];
tp(4,av2);}}

/* find-module/import-library in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9470(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_9470,3,t1,t2,t3);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9474,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:669: ##sys#resolve-module-name */
t5=*((C_word*)lf[23]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k9472 in find-module/import-library in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9474(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_9474,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9477,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:670: ##sys#find-module */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k9475 in k9472 in find-module/import-library in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9477(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9477,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* modules.scm:671: ##sys#import-library-hook */
t2=*((C_word*)lf[139]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}}

/* ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9485(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_9485,c,av);}
a=C_alloc(7);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9489,a[2]=t5,a[3]=t4,a[4]=t2,a[5]=t1,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* modules.scm:674: r */
t7=t3;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[168];
((C_proc)C_fast_retrieve_proc(t7))(3,av2);}}

/* k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9489(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_9489,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9492,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* modules.scm:675: r */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[167];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9492(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_9492,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9495,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* modules.scm:676: r */
t3=((C_word*)t0)[7];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[166];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9495(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_9495,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9498,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* modules.scm:677: r */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[165];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9498(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(29,c,5)))){
C_save_and_reclaim((void *)f_9498,c,av);}
a=C_alloc(29);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9500,a[2]=((C_word)li106),tmp=(C_word)a,a+=3,tmp));
t9=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9514,a[2]=((C_word*)t0)[2],a[3]=((C_word)li107),tmp=(C_word)a,a+=4,tmp));
t10=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9558,a[2]=((C_word)li111),tmp=(C_word)a,a+=3,tmp));
t11=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_9644,a[2]=t7,a[3]=((C_word*)t0)[2],a[4]=t3,a[5]=t5,a[6]=((C_word*)t0)[3],a[7]=t1,a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[5],a[10]=((C_word*)t0)[6],a[11]=((C_word*)t0)[7],a[12]=((C_word)li143),tmp=(C_word)a,a+=13,tmp);
/* modules.scm:696: scheme#call-with-current-continuation */
t12=*((C_word*)lf[164]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t12;
av2[1]=((C_word*)t0)[8];
av2[2]=t11;
((C_proc)(void*)(*((C_word*)t12+1)))(3,av2);}}

/* warn in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9500(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_9500,4,t1,t2,t3,t4);}
a=C_alloc(8);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9508,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9512,a[2]=t5,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:679: scheme#symbol->string */
t7=*((C_word*)lf[119]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k9506 in warn in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9508(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9508,c,av);}
/* modules.scm:679: ##sys#warn */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[43]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[43]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k9510 in warn in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9512(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_9512,c,av);}
/* modules.scm:679: scheme#string-append */
t2=*((C_word*)lf[116]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[146];
av2[4]=t1;
av2[5]=lf[147];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* tostr in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9514(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_9514,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_stringp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9527,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* modules.scm:682: chicken.keyword#keyword? */
t4=*((C_word*)lf[153]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k9525 in tostr in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9527(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_9527,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9534,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* modules.scm:682: ##sys#symbol->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[149]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[149]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}
else{
if(C_truep(C_i_symbolp(((C_word*)t0)[3]))){
/* modules.scm:683: ##sys#symbol->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[149]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[149]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}
else{
if(C_truep(C_i_numberp(((C_word*)t0)[3]))){
/* ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[150]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[150]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_fix(10);
tp(4,av2);}}
else{
/* modules.scm:685: ##sys#syntax-error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[151]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[151]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[152];
tp(4,av2);}}}}}

/* k9532 in k9525 in tostr in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9534(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9534,c,av);}
/* modules.scm:682: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[143]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[143]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[148];
tp(4,av2);}}

/* export-rename in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9558(C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,0,3)))){
C_save_and_reclaim_args((void *)trf_9558,3,t1,t2,t3);}
a=C_alloc(18);
t4=C_i_check_structure_2(t2,lf[6],lf[38]);
t5=C_i_block_ref(t2,C_fix(15));
if(C_truep(C_i_nullp(t5))){
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9572,a[2]=t5,a[3]=((C_word)li109),tmp=(C_word)a,a+=4,tmp);
t11=C_i_check_list_2(t3,lf[21]);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9607,a[2]=t8,a[3]=t13,a[4]=t10,a[5]=t9,a[6]=((C_word)li110),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_9607(t15,t1,t3);}}

/* g2156 in export-rename in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9572(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_9572,3,t0,t1,t2);}
a=C_alloc(7);
t3=C_i_car(t2);
t4=C_i_assq(t3,((C_word*)t0)[2]);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9580,a[2]=t2,a[3]=((C_word)li108),tmp=(C_word)a,a+=4,tmp);
/* modules.scm:691: g2174 */
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=(
/* modules.scm:691: g2174 */
  f_9580(C_a_i(&a,3),t5,t4)
);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* g2174 in g2156 in export-rename in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static C_word C_fcall f_9580(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t2=C_i_cdr(t1);
t3=C_i_cdr(((C_word*)t0)[2]);
return(C_a_i_cons(&a,2,t2,t3));}

/* map-loop2150 in export-rename in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9607(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_9607,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9632,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* modules.scm:690: g2156 */
t4=((C_word*)t0)[4];
f_9572(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k9630 in map-loop2150 in export-rename in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9632(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9632,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_9607(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9644(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,3)))){
C_save_and_reclaim((void *)f_9644,c,av);}
a=C_alloc(21);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9647,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word)li112),tmp=(C_word)a,a+=6,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_9703,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=t5,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word)li142),tmp=(C_word)a,a+=13,tmp));
t7=((C_word*)t5)[1];
f_9703(t7,t1,((C_word*)t0)[11]);}

/* module-imports in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9647(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_9647,3,t0,t1,t2);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9651,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:699: chicken.internal#library-id */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[26]+1);
av2[1]=t3;
av2[2]=t2;
tp(3,av2);}}

/* k9649 in module-imports in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9651(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_9651,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9654,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:700: find-module/import-library */
f_9470(t2,t1,((C_word*)t0)[5]);}

/* k9652 in k9649 in module-imports in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9654(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,7)))){
C_save_and_reclaim((void *)f_9654,c,av);}
a=C_alloc(8);
if(C_truep(C_i_not(t1))){
/* modules.scm:702: k */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[4];
av2[4]=C_SCHEME_FALSE;
av2[5]=C_SCHEME_FALSE;
av2[6]=C_SCHEME_FALSE;
av2[7]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t2))(8,av2);}}
else{
t2=C_i_check_structure_2(t1,lf[6],lf[8]);
t3=C_i_block_ref(t1,C_fix(1));
t4=C_i_check_structure_2(t1,lf[6],lf[68]);
t5=C_i_block_ref(t1,C_fix(2));
t6=C_i_check_structure_2(t1,lf[6],lf[8]);
t7=C_i_block_ref(t1,C_fix(1));
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9682,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=t5,a[6]=t7,a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
t9=C_i_check_structure_2(t1,lf[6],lf[15]);
/* modules.scm:706: export-rename */
f_9558(t8,t1,C_i_block_ref(t1,C_fix(11)));}}

/* k9680 in k9652 in k9649 in module-imports in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9682(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_9682,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9686,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,tmp=(C_word)a,a+=8,tmp);
t3=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[16]);
/* modules.scm:707: export-rename */
f_9558(t2,((C_word*)t0)[2],C_i_block_ref(((C_word*)t0)[2],C_fix(12)));}

/* k9684 in k9680 in k9652 in k9649 in module-imports in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9686(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_9686,c,av);}
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[6],lf[69]);
/* modules.scm:703: scheme#values */{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[6];
av2[5]=((C_word*)t0)[7];
av2[6]=t1;
av2[7]=C_i_block_ref(((C_word*)t0)[2],C_fix(13));
C_values(8,av2);}}

/* outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9703(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,0,4)))){
C_save_and_reclaim_args((void *)trf_9703,3,t0,t1,t2);}
a=C_alloc(14);
if(C_truep(C_i_symbolp(t2))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9717,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* modules.scm:711: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[72]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=C_i_pairp(t2);
if(C_truep(C_i_not(t3))){
/* modules.scm:713: ##sys#syntax-error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[151]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[151]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[154];
av2[4]=t2;
tp(5,av2);}}
else{
t4=C_i_car(t2);
t5=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_9735,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=t4,a[6]=t1,a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[2],a[10]=((C_word*)t0)[7],a[11]=((C_word*)t0)[8],a[12]=((C_word*)t0)[9],a[13]=((C_word*)t0)[10],tmp=(C_word)a,a+=14,tmp);
/* modules.scm:716: c */
t6=((C_word*)t0)[7];{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[11];
av2[3]=t4;
((C_proc)C_fast_retrieve_proc(t6))(4,av2);}}}}

/* k9715 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9717(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9717,c,av);}
/* modules.scm:711: module-imports */
t2=((C_word*)t0)[2];
f_9647(t2,((C_word*)t0)[3],t1);}

/* k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9735(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_9735,c,av);}
a=C_alloc(13);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9738,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* modules.scm:717: ##sys#check-syntax */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[156]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[156]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=((C_word*)t0)[3];
av2[4]=lf[157];
tp(5,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_9885,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],tmp=(C_word)a,a+=13,tmp);
/* modules.scm:735: c */
t3=((C_word*)t0)[10];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[13];
av2[3]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}}

/* k9736 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9738(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,8)))){
C_save_and_reclaim((void *)f_9738,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9743,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li113),tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9753,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[3],a[5]=((C_word)li119),tmp=(C_word)a,a+=6,tmp);
/* modules.scm:718: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[6];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a9742 in k9736 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9743(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9743,c,av);}
/* modules.scm:718: outer */
t2=((C_word*)((C_word*)t0)[2])[1];
f_9703(t2,t1,C_i_cadr(((C_word*)t0)[3]));}

/* a9752 in k9736 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9753(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_9753,c,av);}
a=C_alloc(11);
t8=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_9757,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t4,a[5]=((C_word*)t0)[3],a[6]=t3,a[7]=t7,a[8]=t5,a[9]=t6,a[10]=t1,tmp=(C_word)a,a+=11,tmp);
/* modules.scm:719: chicken.syntax#strip-syntax */
t9=*((C_word*)lf[72]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=C_i_cddr(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* k9755 in a9752 in k9736 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9757(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,6)))){
C_save_and_reclaim((void *)f_9757,c,av);}
a=C_alloc(15);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_9762,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=t3,a[11]=((C_word*)t0)[9],a[12]=((C_word)li118),tmp=(C_word)a,a+=13,tmp));
t5=((C_word*)t3)[1];
f_9762(t5,((C_word*)t0)[10],t1,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST);}

/* loop in k9755 in a9752 in k9736 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9762(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(23,0,5)))){
C_save_and_reclaim_args((void *)trf_9762,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(23);
if(C_truep(C_i_nullp(t2))){
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9770,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li114),tmp=(C_word)a,a+=5,tmp);
t7=C_i_check_list_2(t5,lf[36]);
t8=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_9780,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=t1,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[7],a[8]=t3,a[9]=t4,a[10]=((C_word*)t0)[8],tmp=(C_word)a,a+=11,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9793,a[2]=t10,a[3]=t6,a[4]=((C_word)li115),tmp=(C_word)a,a+=5,tmp));
t12=((C_word*)t10)[1];
f_9793(t12,t8,t5);}
else{
t6=C_i_car(t2);
t7=C_i_assq(t6,((C_word*)t0)[9]);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9821,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[10],a[5]=t4,a[6]=t5,a[7]=((C_word)li116),tmp=(C_word)a,a+=8,tmp);
/* modules.scm:721: g2261 */
t9=t8;
f_9821(t9,t1,t7);}
else{
t8=C_i_assq(C_u_i_car(t2),((C_word*)t0)[11]);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9843,a[2]=t2,a[3]=t4,a[4]=((C_word*)t0)[10],a[5]=t3,a[6]=t5,a[7]=((C_word)li117),tmp=(C_word)a,a+=8,tmp);
/* modules.scm:721: g2265 */
t10=t9;
f_9843(t10,t1,t8);}
else{
t9=C_u_i_cdr(t2);
t10=C_u_i_car(t2);
t11=C_a_i_cons(&a,2,t10,t5);
/* modules.scm:734: loop */
t13=t1;
t14=t9;
t15=t3;
t16=t4;
t17=t11;
t1=t13;
t2=t14;
t3=t15;
t4=t16;
t5=t17;
goto loop;}}}}

/* g2241 in loop in k9755 in a9752 in k9736 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9770(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_9770,3,t0,t1,t2);}
/* modules.scm:724: warn */
f_9500(t1,lf[155],((C_word*)t0)[3],t2);}

/* k9778 in loop in k9755 in a9752 in k9736 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9780(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,7)))){
C_save_and_reclaim((void *)f_9780,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_cons(&a,2,((C_word*)t0)[4],t2);
/* modules.scm:726: scheme#values */{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=0;
av2[1]=((C_word*)t0)[5];
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)t0)[7];
av2[4]=t3;
av2[5]=((C_word*)t0)[8];
av2[6]=((C_word*)t0)[9];
av2[7]=((C_word*)t0)[10];
C_values(8,av2);}}

/* for-each-loop2240 in loop in k9755 in a9752 in k9736 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9793(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_9793,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9803,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:722: g2241 */
t4=((C_word*)t0)[3];
f_9770(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k9801 in for-each-loop2240 in loop in k9755 in a9752 in k9736 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_ccall f_9803(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9803,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_9793(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* g2261 in loop in k9755 in a9752 in k9736 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9821(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,5)))){
C_save_and_reclaim_args((void *)trf_9821,3,t0,t1,t2);}
a=C_alloc(3);
t3=C_i_cdr(((C_word*)t0)[2]);
t4=C_a_i_cons(&a,2,t2,((C_word*)t0)[3]);
/* modules.scm:729: loop */
t5=((C_word*)((C_word*)t0)[4])[1];
f_9762(t5,t1,t3,t4,((C_word*)t0)[5],((C_word*)t0)[6]);}

/* g2265 in loop in k9755 in a9752 in k9736 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9843(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,5)))){
C_save_and_reclaim_args((void *)trf_9843,3,t0,t1,t2);}
a=C_alloc(3);
t3=C_i_cdr(((C_word*)t0)[2]);
t4=C_a_i_cons(&a,2,t2,((C_word*)t0)[3]);
/* modules.scm:732: loop */
t5=((C_word*)((C_word*)t0)[4])[1];
f_9762(t5,t1,t3,((C_word*)t0)[5],t4,((C_word*)t0)[6]);}

/* k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_9885,c,av);}
a=C_alloc(12);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9888,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* modules.scm:736: ##sys#check-syntax */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[156]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[156]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=((C_word*)t0)[3];
av2[4]=lf[159];
tp(5,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_10068,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
/* modules.scm:758: c */
t3=((C_word*)t0)[10];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[12];
av2[3]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}}

/* k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9888(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,8)))){
C_save_and_reclaim((void *)f_9888,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9893,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li120),tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9903,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[3],a[5]=((C_word)li127),tmp=(C_word)a,a+=6,tmp);
/* modules.scm:737: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[6];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a9892 in k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9893(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9893,c,av);}
/* modules.scm:737: outer */
t2=((C_word*)((C_word*)t0)[2])[1];
f_9703(t2,t1,C_i_cadr(((C_word*)t0)[3]));}

/* a9902 in k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9903(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_9903,c,av);}
a=C_alloc(11);
t8=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_9907,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t4,a[5]=((C_word*)t0)[3],a[6]=t3,a[7]=t7,a[8]=t6,a[9]=t1,a[10]=t5,tmp=(C_word)a,a+=11,tmp);
/* modules.scm:738: chicken.syntax#strip-syntax */
t9=*((C_word*)lf[72]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=C_i_cddr(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* k9905 in a9902 in k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_ccall f_9907(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,5)))){
C_save_and_reclaim((void *)f_9907,c,av);}
a=C_alloc(14);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_9912,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=t3,a[11]=((C_word)li126),tmp=(C_word)a,a+=12,tmp));
t5=((C_word*)t3)[1];
f_9912(t5,((C_word*)t0)[9],((C_word*)t0)[10],C_SCHEME_END_OF_LIST,t1);}

/* loopv in k9905 in a9902 in k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 */
static void C_fcall f_9912(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(14,0,5)))){
C_save_and_reclaim_args((void *)trf_9912,5,t0,t1,t2,t3,t4);}
a=C_alloc(14);
if(C_truep(C_i_nullp(t2))){
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_9924,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t3,a[9]=((C_word*)t0)[8],a[10]=t6,a[11]=((C_word)li124),tmp=(C_word)a,a+=12,tmp));
t8=((C_word*)t6)[1];
f_9924(t8,t1,((C_word*)t0)[9],C_SCHEME_END_OF_LIST,t4);}
else{
t5=C_i_caar(t2);
t6=C_i_memq(t5,t4);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10024,a[2]=t2,a[3]=((C_word*)t0)[10],a[4]=t3,a[5]=t4,a[6]=((C_word)li125),tmp=(C_word)a,a+=7,tmp);
/* modules.scm:740: g2344 */
t8=t7;
f_10024(t8,t1,t6);}
else{
t7=C_u_i_cdr(t2);
t8=C_u_i_car(t2);
t9=C_a_i_cons(&a,2,t8,t3);
/* modules.scm:757: loopv */
t11=t1;
t12=t7;
t13=t9;
t14=t4;
t1=t11;
t2=t12;
t3=t13;
t4=t14;
goto loop;}}}

/* loops in loopv in k9905 in a9902 in k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in k4380 in ... */
static void C_fcall f_9924(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,0,4)))){
C_save_and_reclaim_args((void *)trf_9924,5,t0,t1,t2,t3,t4);}
a=C_alloc(23);
if(C_truep(C_i_nullp(t2))){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9932,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li121),tmp=(C_word)a,a+=5,tmp);
t6=C_i_check_list_2(t4,lf[36]);
t7=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_9942,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=t1,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t3,a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9955,a[2]=t9,a[3]=t5,a[4]=((C_word)li122),tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_9955(t11,t7,t4);}
else{
t5=C_i_caar(t2);
t6=C_i_memq(t5,t4);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9983,a[2]=t2,a[3]=((C_word*)t0)[10],a[4]=t3,a[5]=t4,a[6]=((C_word)li123),tmp=(C_word)a,a+=7,tmp);
/* modules.scm:742: g2339 */
t8=t7;
f_9983(t8,t1,t6);}
else{
t7=C_u_i_cdr(t2);
t8=C_u_i_car(t2);
t9=C_a_i_cons(&a,2,t8,t3);
/* modules.scm:752: loops */
t12=t1;
t13=t7;
t14=t9;
t15=t4;
t1=t12;
t2=t13;
t3=t14;
t4=t15;
goto loop;}}}

/* g2319 in loops in loopv in k9905 in a9902 in k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_fcall f_9932(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_9932,3,t0,t1,t2);}
/* modules.scm:745: warn */
f_9500(t1,lf[158],((C_word*)t0)[3],t2);}

/* k9940 in loops in loopv in k9905 in a9902 in k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_ccall f_9942(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,7)))){
C_save_and_reclaim((void *)f_9942,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_cons(&a,2,((C_word*)t0)[4],t2);
/* modules.scm:747: scheme#values */{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=0;
av2[1]=((C_word*)t0)[5];
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)t0)[7];
av2[4]=t3;
av2[5]=((C_word*)t0)[8];
av2[6]=((C_word*)t0)[9];
av2[7]=((C_word*)t0)[10];
C_values(8,av2);}}

/* for-each-loop2318 in loops in loopv in k9905 in a9902 in k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_fcall f_9955(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_9955,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9965,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* modules.scm:743: g2319 */
t4=((C_word*)t0)[3];
f_9932(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k9963 in for-each-loop2318 in loops in loopv in k9905 in a9902 in k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_9965(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9965,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_9955(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* g2339 in loops in loopv in k9905 in a9902 in k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in k4383 in ... */
static void C_fcall f_9983(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_9983,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_i_cdr(((C_word*)t0)[2]);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9995,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t3,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* modules.scm:750: delete */
f_4888(t4,C_i_car(t2),((C_word*)t0)[5],*((C_word*)lf[48]+1));}

/* k9993 in g2339 in loops in loopv in k9905 in a9902 in k9886 in k9883 in k9733 in outer in a9643 in k9496 in k9493 in k9490 in k9487 in ##sys#decompose-import in k5681 in k5677 in k4395 in k4392 in k4389 in k4386 in ... */
static void C_ccall f_9995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9995,c,av);}
/* modules.scm:750: loops */
t2=((C_word*)((C_word*)t0)[2])[1];
f_9924(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_modules_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("modules"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_modules_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(7809))){
C_save(t1);
C_rereclaim2(7809*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,277);
lf[0]=C_h_intern(&lf[0],7, C_text("modules"));
lf[3]=C_h_intern(&lf[3],5, C_text("foldr"));
lf[4]=C_h_intern(&lf[4],20, C_text("##sys#current-module"));
lf[5]=C_h_intern(&lf[5],30, C_text("##sys#module-alias-environment"));
lf[6]=C_h_intern(&lf[6],6, C_text("module"));
lf[8]=C_h_intern(&lf[8],11, C_text("module-name"));
lf[9]=C_h_intern(&lf[9],21, C_text("module-undefined-list"));
lf[10]=C_h_intern(&lf[10],26, C_text("set-module-undefined-list!"));
lf[11]=C_h_intern(&lf[11],16, C_text("##sys#block-set!"));
lf[12]=C_h_intern(&lf[12],17, C_text("##sys#module-name"));
lf[13]=C_h_intern(&lf[13],20, C_text("##sys#module-exports"));
lf[14]=C_h_intern(&lf[14],18, C_text("module-export-list"));
lf[15]=C_h_intern(&lf[15],15, C_text("module-vexports"));
lf[16]=C_h_intern(&lf[16],15, C_text("module-sexports"));
lf[18]=C_h_intern(&lf[18],27, C_text("##sys#register-module-alias"));
lf[19]=C_h_intern(&lf[19],25, C_text("##sys#with-module-aliases"));
lf[20]=C_h_intern(&lf[20],18, C_text("##sys#dynamic-wind"));
lf[21]=C_h_intern(&lf[21],3, C_text("map"));
lf[22]=C_h_intern(&lf[22],13, C_text("scheme#append"));
lf[23]=C_h_intern(&lf[23],25, C_text("##sys#resolve-module-name"));
lf[24]=C_h_intern(&lf[24],18, C_text("chicken.base#error"));
lf[25]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035module alias refers to itself"));
lf[26]=C_h_intern(&lf[26],27, C_text("chicken.internal#library-id"));
lf[27]=C_h_intern(&lf[27],17, C_text("##sys#find-module"));
lf[28]=C_h_intern(&lf[28],18, C_text("##sys#module-table"));
lf[29]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020module not found"));
lf[30]=C_h_intern(&lf[30],19, C_text("##sys#switch-module"));
lf[31]=C_h_intern(&lf[31],23, C_text("##sys#macro-environment"));
lf[32]=C_h_intern(&lf[32],25, C_text("##sys#current-environment"));
lf[33]=C_h_intern(&lf[33],25, C_text("module-saved-environments"));
lf[34]=C_h_intern(&lf[34],24, C_text("##sys#add-to-export-list"));
lf[35]=C_h_intern(&lf[35],17, C_text("module-exist-list"));
lf[36]=C_h_intern(&lf[36],8, C_text("for-each"));
lf[37]=C_h_intern(&lf[37],31, C_text("##sys#add-to-export/rename-list"));
lf[38]=C_h_intern(&lf[38],18, C_text("module-rename-list"));
lf[39]=C_h_intern(&lf[39],30, C_text("##sys#toplevel-definition-hook"));
lf[40]=C_h_intern(&lf[40],30, C_text("##sys#register-meta-expression"));
lf[41]=C_h_intern(&lf[41],23, C_text("module-meta-expressions"));
lf[43]=C_h_intern(&lf[43],10, C_text("##sys#warn"));
lf[44]=C_decode_literal(C_heaptop,C_text("\376B\000\000\047redefinition of imported syntax binding"));
lf[45]=C_decode_literal(C_heaptop,C_text("\376B\000\000&redefinition of imported value binding"));
lf[46]=C_h_intern(&lf[46],21, C_text("##sys#register-export"));
lf[47]=C_h_intern(&lf[47],19, C_text("module-defined-list"));
lf[48]=C_h_intern(&lf[48],10, C_text("scheme#eq\077"));
lf[51]=C_h_intern(&lf[51],28, C_text("##sys#register-syntax-export"));
lf[52]=C_h_intern(&lf[52],26, C_text("module-defined-syntax-list"));
lf[53]=C_decode_literal(C_heaptop,C_text("\376B\000\000!use of syntax precedes definition"));
lf[54]=C_h_intern(&lf[54],30, C_text("##sys#unregister-syntax-export"));
lf[55]=C_h_intern(&lf[55],21, C_text("##sys#register-module"));
lf[57]=C_h_intern(&lf[57],32, C_text("chicken.internal#hash-table-set!"));
lf[58]=C_h_intern(&lf[58],31, C_text("chicken.internal#hash-table-ref"));
lf[59]=C_h_intern(&lf[59],14, C_text("scheme#reverse"));
lf[60]=C_h_intern(&lf[60],32, C_text("chicken.internal#make-hash-table"));
lf[61]=C_h_intern(&lf[61],34, C_text("##sys#compiled-module-registration"));
lf[62]=C_h_intern(&lf[62],19, C_text("module-import-forms"));
lf[63]=C_h_intern(&lf[63],24, C_text("module-meta-import-forms"));
lf[64]=C_h_intern(&lf[64],6, C_text("lambda"));
lf[65]=C_h_intern(&lf[65],22, C_text("##sys#with-environment"));
lf[66]=C_h_intern(&lf[66],12, C_text("##sys#append"));
lf[67]=C_h_intern(&lf[67],5, C_text("quote"));
lf[68]=C_h_intern(&lf[68],14, C_text("module-library"));
lf[69]=C_h_intern(&lf[69],15, C_text("module-iexports"));
lf[70]=C_h_intern(&lf[70],11, C_text("scheme#list"));
lf[71]=C_h_intern(&lf[71],11, C_text("scheme#cons"));
lf[72]=C_h_intern(&lf[72],27, C_text("chicken.syntax#strip-syntax"));
lf[73]=C_h_intern(&lf[73],30, C_text("##sys#register-compiled-module"));
lf[74]=C_h_intern(&lf[74],14, C_text("##core#functor"));
lf[75]=C_h_intern(&lf[75],18, C_text("##sys#fast-reverse"));
lf[76]=C_h_intern(&lf[76],13, C_text("import-syntax"));
lf[77]=C_h_intern(&lf[77],11, C_text("scheme#eval"));
lf[78]=C_h_intern(&lf[78],14, C_text("##core#require"));
lf[79]=C_h_intern(&lf[79],22, C_text("##sys#decompose-import"));
lf[80]=C_h_intern(&lf[80],14, C_text("chicken.base#o"));
lf[81]=C_h_intern(&lf[81],6, C_text("static"));
lf[82]=C_h_intern(&lf[82],24, C_text("##sys#ensure-transformer"));
lf[83]=C_h_intern(&lf[83],11, C_text("##sys#error"));
lf[84]=C_h_intern(&lf[84],6, C_text("import"));
lf[85]=C_decode_literal(C_heaptop,C_text("\376B\000\0000cannot find implementation of re-exported syntax"));
lf[86]=C_h_intern(&lf[86],26, C_text("##sys#register-core-module"));
lf[87]=C_decode_literal(C_heaptop,C_text("\376B\000\0002unknown syntax referenced while registering module"));
lf[88]=C_h_intern(&lf[88],31, C_text("##sys#register-primitive-module"));
lf[89]=C_h_intern(&lf[89],21, C_text("##sys#finalize-module"));
lf[90]=C_h_intern(&lf[90],7, C_text("fprintf"));
lf[91]=C_h_intern(&lf[91],27, C_text("chicken.string#string-split"));
lf[92]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001:"));
lf[93]=C_h_intern(&lf[93],11, C_text("##sys#print"));
lf[94]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005\012    "));
lf[95]=C_h_intern(&lf[95],6, C_text("format"));
lf[96]=C_h_intern(&lf[96],30, C_text("chicken.base#get-output-string"));
lf[97]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012\047 on line "));
lf[98]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016In procedure `"));
lf[99]=C_h_intern(&lf[99],31, C_text("chicken.base#open-output-string"));
lf[100]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010On line "));
lf[101]=C_h_intern(&lf[101],18, C_text("##sys#write-char-0"));
lf[102]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016In procedure `"));
lf[103]=C_h_intern(&lf[103],9, C_text("##core#db"));
lf[104]=C_h_intern(&lf[104],12, C_text("scheme#cadar"));
lf[105]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010module `"));
lf[106]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005\012    "));
lf[107]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025one of these modules:"));
lf[108]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035\012  Suggestion: try importing "));
lf[109]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030\012\012  Unknown identifier `"));
lf[110]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002\047:"));
lf[111]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014\012  In file `"));
lf[112]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001:"));
lf[113]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034\047 has unresolved identifiers"));
lf[114]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010Module `"));
lf[115]=C_decode_literal(C_heaptop,C_text("\376B\000\000$(internal) indirect export not found"));
lf[116]=C_h_intern(&lf[116],20, C_text("scheme#string-append"));
lf[117]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014 in module `"));
lf[118]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\047"));
lf[119]=C_h_intern(&lf[119],21, C_text("scheme#symbol->string"));
lf[120]=C_decode_literal(C_heaptop,C_text("\376B\000\000!indirect export of syntax binding"));
lf[121]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033indirect reexport of syntax"));
lf[122]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042indirect export of unknown binding"));
lf[123]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021module unresolved"));
lf[124]=C_h_intern(&lf[124],6, C_text("syntax"));
lf[125]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001`"));
lf[126]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\047"));
lf[127]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016Cannot export "));
lf[128]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017 because it is "));
lf[129]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[130]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024Exported identifier "));
lf[131]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026 has not been defined."));
lf[132]=C_h_intern(&lf[132],4, C_text("bomb"));
lf[133]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004fail"));
lf[134]=C_h_intern(&lf[134],9, C_text("##sys#get"));
lf[135]=C_h_intern(&lf[135],14, C_text("##sys#override"));
lf[136]=C_h_intern(&lf[136],5, C_text("value"));
lf[137]=C_h_intern(&lf[137],30, C_text("##sys#current-meta-environment"));
lf[138]=C_h_intern(&lf[138],28, C_text("##sys#meta-macro-environment"));
lf[139]=C_h_intern(&lf[139],25, C_text("##sys#import-library-hook"));
lf[140]=C_h_intern(&lf[140],21, C_text("##sys#notices-enabled"));
lf[141]=C_h_intern(&lf[141],11, C_text("scheme#load"));
lf[142]=C_h_intern(&lf[142],35, C_text("chicken.load#find-dynamic-extension"));
lf[143]=C_h_intern(&lf[143],19, C_text("##sys#string-append"));
lf[144]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007.import"));
lf[146]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014 in module `"));
lf[147]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\047"));
lf[148]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001:"));
lf[149]=C_h_intern(&lf[149],20, C_text("##sys#symbol->string"));
lf[150]=C_h_intern(&lf[150],20, C_text("##sys#number->string"));
lf[151]=C_h_intern(&lf[151],23, C_text("##sys#syntax-error-hook"));
lf[152]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016invalid prefix"));
lf[153]=C_h_intern(&lf[153],24, C_text("chicken.keyword#keyword\077"));
lf[154]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034invalid import specification"));
lf[155]=C_decode_literal(C_heaptop,C_text("\376B\000\000!imported identifier doesn\047t exist"));
lf[156]=C_h_intern(&lf[156],18, C_text("##sys#check-syntax"));
lf[157]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\006\001symbol\376\377\001\000\000\000\000"));
lf[158]=C_decode_literal(C_heaptop,C_text("\376B\000\000!excluded identifier doesn\047t exist"));
lf[159]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\006\001symbol\376\377\001\000\000\000\000"));
lf[160]=C_decode_literal(C_heaptop,C_text("\376B\000\000 renamed identifier doesn\047t exist"));
lf[161]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\003\000\000\002\376\001\000\000\006\001symbol\376\003\000\000\002\376\001\000\000\006\001symbol\376\377\016\376\377\001\000\000\000\000"));
lf[162]=C_h_intern(&lf[162],20, C_text("##sys#string->symbol"));
lf[163]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[164]=C_h_intern(&lf[164],37, C_text("scheme#call-with-current-continuation"));
lf[165]=C_h_intern(&lf[165],6, C_text("prefix"));
lf[166]=C_h_intern(&lf[166],6, C_text("except"));
lf[167]=C_h_intern(&lf[167],6, C_text("rename"));
lf[168]=C_h_intern(&lf[168],4, C_text("only"));
lf[169]=C_h_intern(&lf[169],19, C_text("##sys#expand-import"));
lf[170]=C_decode_literal(C_heaptop,C_text("\376B\000\000#cannot import from undefined module"));
lf[171]=C_h_intern(&lf[171],12, C_text("##sys#import"));
lf[172]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[173]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[174]=C_h_intern(&lf[174],12, C_text("##sys#notice"));
lf[175]=C_decode_literal(C_heaptop,C_text("\376B\000\000(re-importing already imported identifier"));
lf[176]=C_h_intern(&lf[176],10, C_text("##sys#put!"));
lf[177]=C_decode_literal(C_heaptop,C_text("\376B\000\000$re-importing already imported syntax"));
lf[178]=C_decode_literal(C_heaptop,C_text("\376B\000\000%`reexport\047 only valid inside a module"));
lf[179]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001#"));
lf[180]=C_h_intern(&lf[180],23, C_text("##sys#alias-global-hook"));
lf[181]=C_h_intern(&lf[181],22, C_text("##sys#validate-exports"));
lf[182]=C_h_intern(&lf[182],16, C_text("##core#interface"));
lf[183]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021unknown interface"));
lf[184]=C_h_intern(&lf[184],1, C_text("\052"));
lf[185]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017invalid exports"));
lf[186]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017invalid exports"));
lf[187]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016invalid export"));
lf[188]=C_h_intern_kw(&lf[188],6, C_text("syntax"));
lf[189]=C_h_intern_kw(&lf[189],9, C_text("interface"));
lf[190]=C_decode_literal(C_heaptop,C_text("\376B\000\000\037invalid interface specification"));
lf[191]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016invalid export"));
lf[192]=C_h_intern(&lf[192],22, C_text("##sys#register-functor"));
lf[193]=C_h_intern(&lf[193],25, C_text("##sys#instantiate-functor"));
lf[194]=C_decode_literal(C_heaptop,C_text("\376B\000\000/argument list mismatch in functor instantiation"));
lf[195]=C_h_intern(&lf[195],13, C_text("##core#module"));
lf[196]=C_h_intern(&lf[196],23, C_text("##core#let-module-alias"));
lf[198]=C_decode_literal(C_heaptop,C_text("\376B\000\000!instantation of undefined functor"));
lf[199]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021argument module `"));
lf[200]=C_decode_literal(C_heaptop,C_text("\376B\000\000$\047 does not match required signature\012"));
lf[201]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022in instantiation `"));
lf[202]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016\047 of functor `"));
lf[203]=C_decode_literal(C_heaptop,C_text("\376B\000\0007\047, because the following required exports are missing:\012"));
lf[204]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003\012  "));
lf[205]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001not\376\001\000\000\012\001scheme#not\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001boolean\077\376\001\000\000\017\001scheme#boolean\077"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001eq\077\376\001\000\000\012\001scheme#eq\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001eqv\077\376\001\000\000\013\001scheme#eqv\077\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\006\001equal\077\376\001\000\000\015\001scheme#equal\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001pair\077\376\001\000\000\014\001scheme#pair\077\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\004\001cons\376\001\000\000\013\001scheme#cons\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001car\376\001\000\000\012\001scheme#car\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001"
"cdr\376\001\000\000\012\001scheme#cdr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001caar\376\001\000\000\013\001scheme#caar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001cadr\376\001\000\000"
"\013\001scheme#cadr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001cdar\376\001\000\000\013\001scheme#cdar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001cddr\376\001\000\000\013\001sche"
"me#cddr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001caaar\376\001\000\000\014\001scheme#caaar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001caadr\376\001\000\000\014\001scheme#"
"caadr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001cadar\376\001\000\000\014\001scheme#cadar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001caddr\376\001\000\000\014\001scheme#ca"
"ddr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001cdaar\376\001\000\000\014\001scheme#cdaar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001cdadr\376\001\000\000\014\001scheme#cdad"
"r\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001cddar\376\001\000\000\014\001scheme#cddar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001cdddr\376\001\000\000\014\001scheme#cdddr\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001caaaar\376\001\000\000\015\001scheme#caaaar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001caaadr\376\001\000\000\015\001scheme#caaad"
"r\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001caadar\376\001\000\000\015\001scheme#caadar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001caaddr\376\001\000\000\015\001scheme#caa"
"ddr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001cadaar\376\001\000\000\015\001scheme#cadaar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001cadadr\376\001\000\000\015\001scheme#c"
"adadr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001caddar\376\001\000\000\015\001scheme#caddar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001cadddr\376\001\000\000\015\001scheme"
"#cadddr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001cdaaar\376\001\000\000\015\001scheme#cdaaar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001cdaadr\376\001\000\000\015\001sche"
"me#cdaadr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001cdadar\376\001\000\000\015\001scheme#cdadar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001cdaddr\376\001\000\000\015\001sc"
"heme#cdaddr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001cddaar\376\001\000\000\015\001scheme#cddaar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001cddadr\376\001\000\000\015\001"
"scheme#cddadr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001cdddar\376\001\000\000\015\001scheme#cdddar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001cddddr\376\001\000\000"
"\015\001scheme#cddddr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001set-car!\376\001\000\000\017\001scheme#set-car!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001set-"
"cdr!\376\001\000\000\017\001scheme#set-cdr!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001null\077\376\001\000\000\014\001scheme#null\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001"
"list\077\376\001\000\000\014\001scheme#list\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001list\376\001\000\000\013\001scheme#list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001leng"
"th\376\001\000\000\015\001scheme#length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001list-tail\376\001\000\000\020\001scheme#list-tail\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\010\001list-ref\376\001\000\000\017\001scheme#list-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001append\376\001\000\000\015\001scheme#append\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\007\001reverse\376\001\000\000\016\001scheme#reverse\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001memq\376\001\000\000\013\001scheme#memq\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\004\001memv\376\001\000\000\013\001scheme#memv\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001member\376\001\000\000\015\001scheme#member\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\004\001assq\376\001\000\000\013\001scheme#assq\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001assv\376\001\000\000\013\001scheme#assv\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\005\001assoc\376\001\000\000\014\001scheme#assoc\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001symbol\077\376\001\000\000\016\001scheme#symbol\077\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\016\001symbol->string\376\001\000\000\025\001scheme#symbol->string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001string->symbol\376\001\000\000\025"
"\001scheme#string->symbol\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001number\077\376\001\000\000\016\001scheme#number\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010"
"\001integer\077\376\001\000\000\017\001scheme#integer\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001exact\077\376\001\000\000\015\001scheme#exact\077\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\005\001real\077\376\001\000\000\014\001scheme#real\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001complex\077\376\001\000\000\017\001scheme#complex\077\376\003\000\000\002"
"\376\003\000\000\002\376\001\000\000\010\001inexact\077\376\001\000\000\017\001scheme#inexact\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001rational\077\376\001\000\000\020\001scheme#ra"
"tional\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001zero\077\376\001\000\000\014\001scheme#zero\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001odd\077\376\001\000\000\013\001scheme#o"
"dd\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001even\077\376\001\000\000\014\001scheme#even\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001positive\077\376\001\000\000\020\001scheme#"
"positive\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001negative\077\376\001\000\000\020\001scheme#negative\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001max\376\001\000\000\012"
"\001scheme#max\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001min\376\001\000\000\012\001scheme#min\376\003\000\000\002\376\003\000\000\002\376\001\000\000\001\001+\376\001\000\000\010\001scheme#+\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\001\001-\376\001\000\000\010\001scheme#-\376\003\000\000\002\376\003\000\000\002\376\001\000\000\001\001\052\376\001\000\000\010\001scheme#\052\376\003\000\000\002\376\003\000\000\002\376\001\000\000\001\001/\376\001\000\000"
"\010\001scheme#/\376\003\000\000\002\376\003\000\000\002\376\001\000\000\001\001=\376\001\000\000\010\001scheme#=\376\003\000\000\002\376\003\000\000\002\376\001\000\000\001\001>\376\001\000\000\010\001scheme#>\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\001\001<\376\001\000\000\010\001scheme#<\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001>=\376\001\000\000\011\001scheme#>=\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001<=\376\001\000\000\011\001"
"scheme#<=\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001quotient\376\001\000\000\017\001scheme#quotient\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001remainder\376"
"\001\000\000\020\001scheme#remainder\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001modulo\376\001\000\000\015\001scheme#modulo\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001gc"
"d\376\001\000\000\012\001scheme#gcd\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001lcm\376\001\000\000\012\001scheme#lcm\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001abs\376\001\000\000\012\001sch"
"eme#abs\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001floor\376\001\000\000\014\001scheme#floor\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001ceiling\376\001\000\000\016\001schem"
"e#ceiling\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001truncate\376\001\000\000\017\001scheme#truncate\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001round\376\001\000\000\014"
"\001scheme#round\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001rationalize\376\001\000\000\022\001scheme#rationalize\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001"
"exact->inexact\376\001\000\000\025\001scheme#exact->inexact\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001inexact->exact\376\001\000\000\025\001sch"
"eme#inexact->exact\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001exp\376\001\000\000\012\001scheme#exp\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001log\376\001\000\000\012\001sc"
"heme#log\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001expt\376\001\000\000\013\001scheme#expt\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001sqrt\376\001\000\000\013\001scheme#sq"
"rt\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001sin\376\001\000\000\012\001scheme#sin\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001cos\376\001\000\000\012\001scheme#cos\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\003\001tan\376\001\000\000\012\001scheme#tan\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001asin\376\001\000\000\013\001scheme#asin\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001"
"acos\376\001\000\000\013\001scheme#acos\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001atan\376\001\000\000\013\001scheme#atan\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001number"
"->string\376\001\000\000\025\001scheme#number->string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001string->number\376\001\000\000\025\001scheme#st"
"ring->number\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001char\077\376\001\000\000\014\001scheme#char\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001char=\077\376\001\000\000\015\001s"
"cheme#char=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001char>\077\376\001\000\000\015\001scheme#char>\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001char<\077\376\001\000\000\015"
"\001scheme#char<\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001char>=\077\376\001\000\000\016\001scheme#char>=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001char<=\077"
"\376\001\000\000\016\001scheme#char<=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001char-ci=\077\376\001\000\000\020\001scheme#char-ci=\077\376\003\000\000\002\376\003\000\000\002\376\001\000"
"\000\011\001char-ci<\077\376\001\000\000\020\001scheme#char-ci<\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001char-ci>\077\376\001\000\000\020\001scheme#char-ci>"
"\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001char-ci>=\077\376\001\000\000\021\001scheme#char-ci>=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001char-ci<=\077\376\001\000\000"
"\021\001scheme#char-ci<=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001char-alphabetic\077\376\001\000\000\027\001scheme#char-alphabetic\077"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001char-whitespace\077\376\001\000\000\027\001scheme#char-whitespace\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001cha"
"r-numeric\077\376\001\000\000\024\001scheme#char-numeric\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001char-upper-case\077\376\001\000\000\027\001scheme"
"#char-upper-case\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001char-lower-case\077\376\001\000\000\027\001scheme#char-lower-case\077\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\013\001char-upcase\376\001\000\000\022\001scheme#char-upcase\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001char-downcase\376\001"
"\000\000\024\001scheme#char-downcase\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001char->integer\376\001\000\000\024\001scheme#char->integer\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001integer->char\376\001\000\000\024\001scheme#integer->char\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001string\077\376\001\000"
"\000\016\001scheme#string\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001string=\077\376\001\000\000\017\001scheme#string=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001st"
"ring>\077\376\001\000\000\017\001scheme#string>\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001string<\077\376\001\000\000\017\001scheme#string<\077\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\011\001string>=\077\376\001\000\000\020\001scheme#string>=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001string<=\077\376\001\000\000\020\001scheme#str"
"ing<=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001string-ci=\077\376\001\000\000\022\001scheme#string-ci=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001string-"
"ci<\077\376\001\000\000\022\001scheme#string-ci<\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001string-ci>\077\376\001\000\000\022\001scheme#string-ci>\077\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001string-ci>=\077\376\001\000\000\023\001scheme#string-ci>=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001string-ci<=\077"
"\376\001\000\000\023\001scheme#string-ci<=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001make-string\376\001\000\000\022\001scheme#make-string\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\015\001string-length\376\001\000\000\024\001scheme#string-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001string-ref\376\001\000"
"\000\021\001scheme#string-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001string-set!\376\001\000\000\022\001scheme#string-set!\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\015\001string-append\376\001\000\000\024\001scheme#string-append\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001string-copy\376\001\000\000\022\001s"
"cheme#string-copy\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001string->list\376\001\000\000\023\001scheme#string->list\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\014\001list->string\376\001\000\000\023\001scheme#list->string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001substring\376\001\000\000\020\001scheme"
"#substring\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001string-fill!\376\001\000\000\023\001scheme#string-fill!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001v"
"ector\077\376\001\000\000\016\001scheme#vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001make-vector\376\001\000\000\022\001scheme#make-vector\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\012\001vector-ref\376\001\000\000\021\001scheme#vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001vector-set!\376\001\000\000\022\001s"
"cheme#vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001string\376\001\000\000\015\001scheme#string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001vector"
"\376\001\000\000\015\001scheme#vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001vector-length\376\001\000\000\024\001scheme#vector-length\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\014\001vector->list\376\001\000\000\023\001scheme#vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001list->vector\376\001\000\000\023"
"\001scheme#list->vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001vector-fill!\376\001\000\000\023\001scheme#vector-fill!\376\003\000\000\002\376\003"
"\000\000\002\376\001\000\000\012\001procedure\077\376\001\000\000\021\001scheme#procedure\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001map\376\001\000\000\012\001scheme#map\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\010\001for-each\376\001\000\000\017\001scheme#for-each\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001apply\376\001\000\000\014\001scheme#appl"
"y\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001force\376\001\000\000\014\001scheme#force\376\003\000\000\002\376\003\000\000\002\376\001\000\000\036\001call-with-current-contin"
"uation\376\001\000\000%\001scheme#call-with-current-continuation\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001input-port\077\376\001\000\000"
"\022\001scheme#input-port\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001output-port\077\376\001\000\000\023\001scheme#output-port\077\376\003\000\000\002\376\003"
"\000\000\002\376\001\000\000\022\001current-input-port\376\001\000\000\031\001scheme#current-input-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001curren"
"t-output-port\376\001\000\000\032\001scheme#current-output-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001call-with-input-fil"
"e\376\001\000\000\033\001scheme#call-with-input-file\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001call-with-output-file\376\001\000\000\034\001sch"
"eme#call-with-output-file\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001open-input-file\376\001\000\000\026\001scheme#open-input-"
"file\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001open-output-file\376\001\000\000\027\001scheme#open-output-file\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020"
"\001close-input-port\376\001\000\000\027\001scheme#close-input-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001close-output-port\376"
"\001\000\000\030\001scheme#close-output-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001load\376\001\000\000\013\001scheme#load\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\004\001read\376\001\000\000\013\001scheme#read\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001read-char\376\001\000\000\020\001scheme#read-char\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\011\001peek-char\376\001\000\000\020\001scheme#peek-char\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001write\376\001\000\000\014\001scheme#write\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\007\001display\376\001\000\000\016\001scheme#display\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001write-char\376\001\000\000\021\001scheme#wr"
"ite-char\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001newline\376\001\000\000\016\001scheme#newline\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001eof-object\077\376\001"
"\000\000\022\001scheme#eof-object\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001with-input-from-file\376\001\000\000\033\001scheme#with-inpu"
"t-from-file\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001with-output-to-file\376\001\000\000\032\001scheme#with-output-to-file\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\013\001char-ready\077\376\001\000\000\022\001scheme#char-ready\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001imag-part\376\001\000\000\020\001"
"scheme#imag-part\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001real-part\376\001\000\000\020\001scheme#real-part\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001m"
"ake-rectangular\376\001\000\000\027\001scheme#make-rectangular\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001make-polar\376\001\000\000\021\001sche"
"me#make-polar\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001angle\376\001\000\000\014\001scheme#angle\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001magnitude\376\001\000"
"\000\020\001scheme#magnitude\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001numerator\376\001\000\000\020\001scheme#numerator\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\013\001denominator\376\001\000\000\022\001scheme#denominator\376\003\000\000\002\376\003\000\000\002\376\001\000\000\031\001scheme-report-environment\376\001"
"\000\000 \001scheme#scheme-report-environment\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001null-environment\376\001\000\000\027\001scheme"
"#null-environment\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001interaction-environment\376\001\000\000\036\001scheme#interaction"
"-environment\376\377\016"));
lf[206]=C_h_intern(&lf[206],30, C_text("##sys#scheme-macro-environment"));
lf[207]=C_h_intern(&lf[207],33, C_text("chicken.module#module-environment"));
lf[208]=C_h_intern(&lf[208],18, C_text("module-environment"));
lf[209]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020undefined module"));
lf[210]=C_h_intern(&lf[210],11, C_text("environment"));
lf[211]=C_h_intern(&lf[211],14, C_text("chicken.syntax"));
lf[212]=C_h_intern(&lf[212],6, C_text("expand"));
lf[213]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001expand\376\001\000\000\025\001chicken.syntax#expand\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001get-line-number"
"\376\001\000\000\036\001chicken.syntax#get-line-number\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001read-with-source-info\376\001\000\000$\001c"
"hicken.syntax#read-with-source-info\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001strip-syntax\376\001\000\000\033\001chicken.syn"
"tax#strip-syntax\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001syntax-error\376\001\000\000\033\001chicken.syntax#syntax-error\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\024\001er-macro-transformer\376\001\000\000#\001chicken.syntax#er-macro-transformer\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\024\001ir-macro-transformer\376\001\000\000#\001chicken.syntax#ir-macro-transformer\376\377\016"));
lf[214]=C_h_intern(&lf[214],38, C_text("##sys#chicken.syntax-macro-environment"));
lf[215]=C_h_intern(&lf[215],12, C_text("chicken.base"));
lf[216]=C_h_intern(&lf[216],7, C_text("library"));
lf[217]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001add1\376\001\000\000\021\001chicken.base#add1\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001alist-ref\376\001\000\000\026\001chicke"
"n.base#alist-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001alist-update\376\001\000\000\031\001chicken.base#alist-update\376\003\000\000\002"
"\376\003\000\000\002\376\001\000\000\015\001alist-update!\376\001\000\000\032\001chicken.base#alist-update!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001atom\077\376\001\000"
"\000\022\001chicken.base#atom\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001bignum\077\376\001\000\000\024\001chicken.base#bignum\077\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\013\001bwp-object\077\376\001\000\000\030\001chicken.base#bwp-object\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001butlast\376\001\000\000\024\001chic"
"ken.base#butlast\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001call/cc\376\001\000\000\024\001chicken.base#call/cc\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016"
"\001case-sensitive\376\001\000\000\033\001chicken.base#case-sensitive\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001char-name\376\001\000\000\026\001c"
"hicken.base#char-name\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001chop\376\001\000\000\021\001chicken.base#chop\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001"
"complement\376\001\000\000\027\001chicken.base#complement\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001compose\376\001\000\000\024\001chicken.base"
"#compose\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001compress\376\001\000\000\025\001chicken.base#compress\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001conjo"
"in\376\001\000\000\024\001chicken.base#conjoin\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001constantly\376\001\000\000\027\001chicken.base#constan"
"tly\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001cplxnum\077\376\001\000\000\025\001chicken.base#cplxnum\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001current-er"
"ror-port\376\001\000\000\037\001chicken.base#current-error-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001disjoin\376\001\000\000\024\001chicke"
"n.base#disjoin\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001each\376\001\000\000\021\001chicken.base#each\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001emergen"
"cy-exit\376\001\000\000\033\001chicken.base#emergency-exit\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001enable-warnings\376\001\000\000\034\001chi"
"cken.base#enable-warnings\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001equal=\077\376\001\000\000\024\001chicken.base#equal=\077\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\005\001error\376\001\000\000\022\001chicken.base#error\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001exact-integer\077\376\001\000\000\033\001chick"
"en.base#exact-integer\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001exact-integer-nth-root\376\001\000\000#\001chicken.base#e"
"xact-integer-nth-root\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001exact-integer-sqrt\376\001\000\000\037\001chicken.base#exact-"
"integer-sqrt\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001exit\376\001\000\000\021\001chicken.base#exit\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001exit-hand"
"ler\376\001\000\000\031\001chicken.base#exit-handler\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001finite\077\376\001\000\000\024\001chicken.base#fini"
"te\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001fixnum\077\376\001\000\000\024\001chicken.base#fixnum\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001flatten\376\001\000\000\024"
"\001chicken.base#flatten\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001flip\376\001\000\000\021\001chicken.base#flip\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001"
"flonum\077\376\001\000\000\024\001chicken.base#flonum\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001flush-output\376\001\000\000\031\001chicken.base#"
"flush-output\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001foldl\376\001\000\000\022\001chicken.base#foldl\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001foldr\376\001"
"\000\000\022\001chicken.base#foldr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001gensym\376\001\000\000\023\001chicken.base#gensym\376\003\000\000\002\376\003\000\000\002\376"
"\001\000\000\016\001get-call-chain\376\001\000\000\033\001chicken.base#get-call-chain\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001get-output-s"
"tring\376\001\000\000\036\001chicken.base#get-output-string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001getter-with-setter\376\001\000\000\037"
"\001chicken.base#getter-with-setter\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001identity\376\001\000\000\025\001chicken.base#ident"
"ity\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001implicit-exit-handler\376\001\000\000\042\001chicken.base#implicit-exit-handler"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001infinite\077\376\001\000\000\026\001chicken.base#infinite\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001input-port-"
"open\077\376\001\000\000\035\001chicken.base#input-port-open\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001intersperse\376\001\000\000\030\001chicken"
".base#intersperse\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001join\376\001\000\000\021\001chicken.base#join\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001keyw"
"ord-style\376\001\000\000\032\001chicken.base#keyword-style\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001list-of\077\376\001\000\000\025\001chicken.b"
"ase#list-of\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001make-parameter\376\001\000\000\033\001chicken.base#make-parameter\376\003\000\000\002"
"\376\003\000\000\002\376\001\000\000\014\001make-promise\376\001\000\000\031\001chicken.base#make-promise\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001nan\077\376\001\000\000\021\001"
"chicken.base#nan\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001notice\376\001\000\000\023\001chicken.base#notice\376\003\000\000\002\376\003\000\000\002\376\001\000\000\001\001"
"o\376\001\000\000\016\001chicken.base#o\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001on-exit\376\001\000\000\024\001chicken.base#on-exit\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\021\001open-input-string\376\001\000\000\036\001chicken.base#open-input-string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001open-"
"output-string\376\001\000\000\037\001chicken.base#open-output-string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001output-port-op"
"en\077\376\001\000\000\036\001chicken.base#output-port-open\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001parentheses-synonyms\376\001\000\000!"
"\001chicken.base#parentheses-synonyms\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001port\077\376\001\000\000\022\001chicken.base#port\077\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001port-closed\077\376\001\000\000\031\001chicken.base#port-closed\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001print-"
"call-chain\376\001\000\000\035\001chicken.base#print-call-chain\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001print\376\001\000\000\022\001chicken."
"base#print\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001print\052\376\001\000\000\023\001chicken.base#print\052\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001procedu"
"re-information\376\001\000\000\042\001chicken.base#procedure-information\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001promise\077\376\001"
"\000\000\025\001chicken.base#promise\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001quotient&modulo\376\001\000\000\034\001chicken.base#quoti"
"ent&modulo\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001quotient&remainder\376\001\000\000\037\001chicken.base#quotient&remainde"
"r\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001rassoc\376\001\000\000\023\001chicken.base#rassoc\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001ratnum\077\376\001\000\000\024\001chi"
"cken.base#ratnum\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001record-printer\376\001\000\000\033\001chicken.base#record-printer"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001set-record-printer!\376\001\000\000 \001chicken.base#set-record-printer!\376\003\000\000\002\376\003"
"\000\000\002\376\001\000\000\006\001setter\376\001\000\000\023\001chicken.base#setter\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001signum\376\001\000\000\023\001chicken.base"
"#signum\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001sleep\376\001\000\000\022\001chicken.base#sleep\376\003\000\000\002\376\003\000\000\002\376\001\000\000\031\001string->unin"
"terned-symbol\376\001\000\000&\001chicken.base#string->uninterned-symbol\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001sub1\376\001\000"
"\000\021\001chicken.base#sub1\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001subvector\376\001\000\000\026\001chicken.base#subvector\376\003\000\000\002\376\003"
"\000\000\002\376\001\000\000\015\001symbol-append\376\001\000\000\032\001chicken.base#symbol-append\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001symbol-esc"
"ape\376\001\000\000\032\001chicken.base#symbol-escape\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001tail\077\376\001\000\000\022\001chicken.base#tail\077"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001vector-copy!\376\001\000\000\031\001chicken.base#vector-copy!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001vecto"
"r-resize\376\001\000\000\032\001chicken.base#vector-resize\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001void\376\001\000\000\021\001chicken.base#v"
"oid\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001warning\376\001\000\000\024\001chicken.base#warning\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001weak-cons\376\001\000"
"\000\026\001chicken.base#weak-cons\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001weak-pair\077\376\001\000\000\027\001chicken.base#weak-pair\077"
"\376\377\016"));
lf[218]=C_h_intern(&lf[218],36, C_text("##sys#chicken.base-macro-environment"));
lf[219]=C_h_intern(&lf[219],7, C_text("srfi-98"));
lf[220]=C_h_intern(&lf[220],5, C_text("posix"));
lf[221]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\030\001get-environment-variable\376\001\000\0000\001chicken.process-context#get-enviro"
"nment-variable\376\003\000\000\002\376\003\000\000\002\376\001\000\000\031\001get-environment-variables\376\001\000\0001\001chicken.process-con"
"text#get-environment-variables\376\377\016"));
lf[222]=C_h_intern(&lf[222],7, C_text("srfi-88"));
lf[223]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001keyword\077\376\001\000\000\030\001chicken.keyword#keyword\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001keyword->s"
"tring\376\001\000\000\037\001chicken.keyword#keyword->string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001string->keyword\376\001\000\000\037\001c"
"hicken.keyword#string->keyword\376\377\016"));
lf[224]=C_h_intern(&lf[224],7, C_text("srfi-55"));
lf[225]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\021\001require-extension\376\377\016"));
lf[226]=C_h_intern(&lf[226],7, C_text("srfi-39"));
lf[227]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001make-parameter\376\001\000\000\033\001chicken.base#make-parameter\376\377\016"));
lf[228]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\014\001parameterize\376\377\016"));
lf[229]=C_h_intern(&lf[229],7, C_text("srfi-31"));
lf[230]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\003\001rec\376\377\016"));
lf[231]=C_h_intern(&lf[231],7, C_text("srfi-28"));
lf[232]=C_h_intern(&lf[232],6, C_text("extras"));
lf[233]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001format\376\001\000\000\025\001chicken.format#format\376\377\016"));
lf[234]=C_h_intern(&lf[234],7, C_text("srfi-26"));
lf[235]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\003\001cut\376\003\000\000\002\376\001\000\000\004\001cute\376\377\016"));
lf[236]=C_h_intern(&lf[236],7, C_text("srfi-23"));
lf[237]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001error\376\001\000\000\022\001chicken.base#error\376\377\016"));
lf[238]=C_h_intern(&lf[238],7, C_text("srfi-17"));
lf[239]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001getter-with-setter\376\001\000\000\037\001chicken.base#getter-with-setter\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\006\001setter\376\001\000\000\023\001chicken.base#setter\376\377\016"));
lf[240]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\004\001set!\376\377\016"));
lf[241]=C_h_intern(&lf[241],31, C_text("##sys#default-macro-environment"));
lf[242]=C_h_intern(&lf[242],7, C_text("srfi-16"));
lf[243]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\013\001case-lambda\376\377\016"));
lf[244]=C_h_intern(&lf[244],7, C_text("srfi-15"));
lf[245]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\011\001fluid-let\376\377\016"));
lf[246]=C_h_intern(&lf[246],7, C_text("srfi-12"));
lf[247]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001abort\376\001\000\000\027\001chicken.condition#abort\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001condition\077\376\001\000\000"
"\034\001chicken.condition#condition\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001condition-predicate\376\001\000\000%\001chicken.c"
"ondition#condition-predicate\376\003\000\000\002\376\003\000\000\002\376\001\000\000\033\001condition-property-accessor\376\001\000\000-\001chi"
"cken.condition#condition-property-accessor\376\003\000\000\002\376\003\000\000\002\376\001\000\000\031\001current-exception-hand"
"ler\376\001\000\000+\001chicken.condition#current-exception-handler\376\003\000\000\002\376\003\000\000\002\376\001\000\000\030\001make-composi"
"te-condition\376\001\000\000\052\001chicken.condition#make-composite-condition\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001make"
"-property-condition\376\001\000\000)\001chicken.condition#make-property-condition\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\006\001signal\376\001\000\000\030\001chicken.condition#signal\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001with-exception-handler\376\001\000\000"
"(\001chicken.condition#with-exception-handler\376\377\016"));
lf[248]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\021\001handle-exceptions\376\377\016"));
lf[249]=C_h_intern(&lf[249],41, C_text("##sys#chicken.condition-macro-environment"));
lf[250]=C_h_intern(&lf[250],7, C_text("srfi-11"));
lf[251]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\012\001let-values\376\003\000\000\002\376\001\000\000\013\001let\052-values\376\377\016"));
lf[252]=C_h_intern(&lf[252],7, C_text("srfi-10"));
lf[253]=C_h_intern(&lf[253],11, C_text("read-syntax"));
lf[254]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001define-reader-ctor\376\001\000\000&\001chicken.read-syntax#define-reader-ctor\376\377"
"\016"));
lf[255]=C_h_intern(&lf[255],6, C_text("srfi-9"));
lf[256]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\022\001define-record-type\376\377\016"));
lf[257]=C_h_intern(&lf[257],6, C_text("srfi-8"));
lf[258]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\007\001receive\376\377\016"));
lf[259]=C_h_intern(&lf[259],6, C_text("srfi-6"));
lf[260]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001get-output-string\376\001\000\000\036\001chicken.base#get-output-string\376\003\000\000\002\376\003\000\000\002\376"
"\001\000\000\021\001open-input-string\376\001\000\000\036\001chicken.base#open-input-string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001open-o"
"utput-string\376\001\000\000\037\001chicken.base#open-output-string\376\377\016"));
lf[261]=C_h_intern(&lf[261],6, C_text("srfi-2"));
lf[262]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\010\001and-let\052\376\377\016"));
lf[263]=C_h_intern(&lf[263],6, C_text("srfi-0"));
lf[264]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\013\001cond-expand\376\377\016"));
lf[265]=C_h_intern(&lf[265],12, C_text("chicken.type"));
lf[266]=C_h_intern(&lf[266],36, C_text("##sys#chicken.type-macro-environment"));
lf[267]=C_h_intern(&lf[267],14, C_text("chicken.module"));
lf[268]=C_h_intern(&lf[268],38, C_text("##sys#chicken.module-macro-environment"));
lf[269]=C_h_intern(&lf[269],23, C_text("chicken.internal.syntax"));
lf[270]=C_h_intern(&lf[270],4, C_text("r5rs"));
lf[271]=C_h_intern(&lf[271],6, C_text("scheme"));
lf[272]=C_h_intern(&lf[272],9, C_text("r5rs-null"));
lf[273]=C_h_intern(&lf[273],9, C_text("r4rs-null"));
lf[274]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001dynamic-wind\376\001\000\000\023\001scheme#dynamic-wind\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001eval\376\001\000\000\013\001s"
"cheme#eval\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001values\376\001\000\000\015\001scheme#values\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001call-with-val"
"ues\376\001\000\000\027\001scheme#call-with-values\376\377\016"));
lf[275]=C_h_intern(&lf[275],4, C_text("r4rs"));
lf[276]=C_h_intern(&lf[276],27, C_text("chicken.base#make-parameter"));
C_register_lf2(lf,277,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4382,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_chicken_2dsyntax_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[612] = {
{C_text("f14085:modules_2escm"),(void*)f14085},
{C_text("f14089:modules_2escm"),(void*)f14089},
{C_text("f_10024:modules_2escm"),(void*)f_10024},
{C_text("f_10036:modules_2escm"),(void*)f_10036},
{C_text("f_10068:modules_2escm"),(void*)f_10068},
{C_text("f_10071:modules_2escm"),(void*)f_10071},
{C_text("f_10076:modules_2escm"),(void*)f_10076},
{C_text("f_10086:modules_2escm"),(void*)f_10086},
{C_text("f_10090:modules_2escm"),(void*)f_10090},
{C_text("f_10095:modules_2escm"),(void*)f_10095},
{C_text("f_10107:modules_2escm"),(void*)f_10107},
{C_text("f_10115:modules_2escm"),(void*)f_10115},
{C_text("f_10128:modules_2escm"),(void*)f_10128},
{C_text("f_10134:modules_2escm"),(void*)f_10134},
{C_text("f_10147:modules_2escm"),(void*)f_10147},
{C_text("f_10157:modules_2escm"),(void*)f_10157},
{C_text("f_10170:modules_2escm"),(void*)f_10170},
{C_text("f_10209:modules_2escm"),(void*)f_10209},
{C_text("f_10225:modules_2escm"),(void*)f_10225},
{C_text("f_10262:modules_2escm"),(void*)f_10262},
{C_text("f_10278:modules_2escm"),(void*)f_10278},
{C_text("f_10318:modules_2escm"),(void*)f_10318},
{C_text("f_10321:modules_2escm"),(void*)f_10321},
{C_text("f_10326:modules_2escm"),(void*)f_10326},
{C_text("f_10336:modules_2escm"),(void*)f_10336},
{C_text("f_10340:modules_2escm"),(void*)f_10340},
{C_text("f_10342:modules_2escm"),(void*)f_10342},
{C_text("f_10350:modules_2escm"),(void*)f_10350},
{C_text("f_10356:modules_2escm"),(void*)f_10356},
{C_text("f_10360:modules_2escm"),(void*)f_10360},
{C_text("f_10364:modules_2escm"),(void*)f_10364},
{C_text("f_10385:modules_2escm"),(void*)f_10385},
{C_text("f_10395:modules_2escm"),(void*)f_10395},
{C_text("f_10397:modules_2escm"),(void*)f_10397},
{C_text("f_10422:modules_2escm"),(void*)f_10422},
{C_text("f_10431:modules_2escm"),(void*)f_10431},
{C_text("f_10456:modules_2escm"),(void*)f_10456},
{C_text("f_10474:modules_2escm"),(void*)f_10474},
{C_text("f_10480:modules_2escm"),(void*)f_10480},
{C_text("f_10484:modules_2escm"),(void*)f_10484},
{C_text("f_10485:modules_2escm"),(void*)f_10485},
{C_text("f_10491:modules_2escm"),(void*)f_10491},
{C_text("f_10497:modules_2escm"),(void*)f_10497},
{C_text("f_10519:modules_2escm"),(void*)f_10519},
{C_text("f_10521:modules_2escm"),(void*)f_10521},
{C_text("f_10531:modules_2escm"),(void*)f_10531},
{C_text("f_10544:modules_2escm"),(void*)f_10544},
{C_text("f_10548:modules_2escm"),(void*)f_10548},
{C_text("f_10551:modules_2escm"),(void*)f_10551},
{C_text("f_10561:modules_2escm"),(void*)f_10561},
{C_text("f_10568:modules_2escm"),(void*)f_10568},
{C_text("f_10599:modules_2escm"),(void*)f_10599},
{C_text("f_10605:modules_2escm"),(void*)f_10605},
{C_text("f_10606:modules_2escm"),(void*)f_10606},
{C_text("f_10613:modules_2escm"),(void*)f_10613},
{C_text("f_10646:modules_2escm"),(void*)f_10646},
{C_text("f_10652:modules_2escm"),(void*)f_10652},
{C_text("f_10655:modules_2escm"),(void*)f_10655},
{C_text("f_10658:modules_2escm"),(void*)f_10658},
{C_text("f_10665:modules_2escm"),(void*)f_10665},
{C_text("f_10669:modules_2escm"),(void*)f_10669},
{C_text("f_10673:modules_2escm"),(void*)f_10673},
{C_text("f_10677:modules_2escm"),(void*)f_10677},
{C_text("f_10680:modules_2escm"),(void*)f_10680},
{C_text("f_10686:modules_2escm"),(void*)f_10686},
{C_text("f_10689:modules_2escm"),(void*)f_10689},
{C_text("f_10696:modules_2escm"),(void*)f_10696},
{C_text("f_10706:modules_2escm"),(void*)f_10706},
{C_text("f_10713:modules_2escm"),(void*)f_10713},
{C_text("f_10724:modules_2escm"),(void*)f_10724},
{C_text("f_10731:modules_2escm"),(void*)f_10731},
{C_text("f_10733:modules_2escm"),(void*)f_10733},
{C_text("f_10767:modules_2escm"),(void*)f_10767},
{C_text("f_10803:modules_2escm"),(void*)f_10803},
{C_text("f_10814:modules_2escm"),(void*)f_10814},
{C_text("f_10828:modules_2escm"),(void*)f_10828},
{C_text("f_10835:modules_2escm"),(void*)f_10835},
{C_text("f_10837:modules_2escm"),(void*)f_10837},
{C_text("f_10871:modules_2escm"),(void*)f_10871},
{C_text("f_10911:modules_2escm"),(void*)f_10911},
{C_text("f_10921:modules_2escm"),(void*)f_10921},
{C_text("f_10934:modules_2escm"),(void*)f_10934},
{C_text("f_10944:modules_2escm"),(void*)f_10944},
{C_text("f_10965:modules_2escm"),(void*)f_10965},
{C_text("f_10980:modules_2escm"),(void*)f_10980},
{C_text("f_10990:modules_2escm"),(void*)f_10990},
{C_text("f_10998:modules_2escm"),(void*)f_10998},
{C_text("f_11008:modules_2escm"),(void*)f_11008},
{C_text("f_11011:modules_2escm"),(void*)f_11011},
{C_text("f_11015:modules_2escm"),(void*)f_11015},
{C_text("f_11019:modules_2escm"),(void*)f_11019},
{C_text("f_11026:modules_2escm"),(void*)f_11026},
{C_text("f_11054:modules_2escm"),(void*)f_11054},
{C_text("f_11080:modules_2escm"),(void*)f_11080},
{C_text("f_11082:modules_2escm"),(void*)f_11082},
{C_text("f_11085:modules_2escm"),(void*)f_11085},
{C_text("f_11091:modules_2escm"),(void*)f_11091},
{C_text("f_11132:modules_2escm"),(void*)f_11132},
{C_text("f_11164:modules_2escm"),(void*)f_11164},
{C_text("f_11190:modules_2escm"),(void*)f_11190},
{C_text("f_11211:modules_2escm"),(void*)f_11211},
{C_text("f_11215:modules_2escm"),(void*)f_11215},
{C_text("f_11241:modules_2escm"),(void*)f_11241},
{C_text("f_11255:modules_2escm"),(void*)f_11255},
{C_text("f_11297:modules_2escm"),(void*)f_11297},
{C_text("f_11313:modules_2escm"),(void*)f_11313},
{C_text("f_11321:modules_2escm"),(void*)f_11321},
{C_text("f_11328:modules_2escm"),(void*)f_11328},
{C_text("f_11338:modules_2escm"),(void*)f_11338},
{C_text("f_11360:modules_2escm"),(void*)f_11360},
{C_text("f_11362:modules_2escm"),(void*)f_11362},
{C_text("f_11401:modules_2escm"),(void*)f_11401},
{C_text("f_11422:modules_2escm"),(void*)f_11422},
{C_text("f_11434:modules_2escm"),(void*)f_11434},
{C_text("f_11457:modules_2escm"),(void*)f_11457},
{C_text("f_11460:modules_2escm"),(void*)f_11460},
{C_text("f_11471:modules_2escm"),(void*)f_11471},
{C_text("f_11477:modules_2escm"),(void*)f_11477},
{C_text("f_11509:modules_2escm"),(void*)f_11509},
{C_text("f_11512:modules_2escm"),(void*)f_11512},
{C_text("f_11523:modules_2escm"),(void*)f_11523},
{C_text("f_11539:modules_2escm"),(void*)f_11539},
{C_text("f_11543:modules_2escm"),(void*)f_11543},
{C_text("f_11550:modules_2escm"),(void*)f_11550},
{C_text("f_11563:modules_2escm"),(void*)f_11563},
{C_text("f_11590:modules_2escm"),(void*)f_11590},
{C_text("f_11603:modules_2escm"),(void*)f_11603},
{C_text("f_11607:modules_2escm"),(void*)f_11607},
{C_text("f_11611:modules_2escm"),(void*)f_11611},
{C_text("f_11615:modules_2escm"),(void*)f_11615},
{C_text("f_11629:modules_2escm"),(void*)f_11629},
{C_text("f_11635:modules_2escm"),(void*)f_11635},
{C_text("f_11637:modules_2escm"),(void*)f_11637},
{C_text("f_11662:modules_2escm"),(void*)f_11662},
{C_text("f_11671:modules_2escm"),(void*)f_11671},
{C_text("f_11681:modules_2escm"),(void*)f_11681},
{C_text("f_11696:modules_2escm"),(void*)f_11696},
{C_text("f_11699:modules_2escm"),(void*)f_11699},
{C_text("f_11702:modules_2escm"),(void*)f_11702},
{C_text("f_11705:modules_2escm"),(void*)f_11705},
{C_text("f_11708:modules_2escm"),(void*)f_11708},
{C_text("f_11711:modules_2escm"),(void*)f_11711},
{C_text("f_11714:modules_2escm"),(void*)f_11714},
{C_text("f_11717:modules_2escm"),(void*)f_11717},
{C_text("f_11720:modules_2escm"),(void*)f_11720},
{C_text("f_11723:modules_2escm"),(void*)f_11723},
{C_text("f_11726:modules_2escm"),(void*)f_11726},
{C_text("f_11729:modules_2escm"),(void*)f_11729},
{C_text("f_11732:modules_2escm"),(void*)f_11732},
{C_text("f_11735:modules_2escm"),(void*)f_11735},
{C_text("f_11738:modules_2escm"),(void*)f_11738},
{C_text("f_11741:modules_2escm"),(void*)f_11741},
{C_text("f_11744:modules_2escm"),(void*)f_11744},
{C_text("f_11747:modules_2escm"),(void*)f_11747},
{C_text("f_11750:modules_2escm"),(void*)f_11750},
{C_text("f_11753:modules_2escm"),(void*)f_11753},
{C_text("f_11756:modules_2escm"),(void*)f_11756},
{C_text("f_11759:modules_2escm"),(void*)f_11759},
{C_text("f_11762:modules_2escm"),(void*)f_11762},
{C_text("f_11765:modules_2escm"),(void*)f_11765},
{C_text("f_11768:modules_2escm"),(void*)f_11768},
{C_text("f_11771:modules_2escm"),(void*)f_11771},
{C_text("f_11774:modules_2escm"),(void*)f_11774},
{C_text("f_11777:modules_2escm"),(void*)f_11777},
{C_text("f_11779:modules_2escm"),(void*)f_11779},
{C_text("f_11786:modules_2escm"),(void*)f_11786},
{C_text("f_11815:modules_2escm"),(void*)f_11815},
{C_text("f_11818:modules_2escm"),(void*)f_11818},
{C_text("f_11825:modules_2escm"),(void*)f_11825},
{C_text("f_11837:modules_2escm"),(void*)f_11837},
{C_text("f_11872:modules_2escm"),(void*)f_11872},
{C_text("f_11879:modules_2escm"),(void*)f_11879},
{C_text("f_11891:modules_2escm"),(void*)f_11891},
{C_text("f_11926:modules_2escm"),(void*)f_11926},
{C_text("f_11933:modules_2escm"),(void*)f_11933},
{C_text("f_11945:modules_2escm"),(void*)f_11945},
{C_text("f_11980:modules_2escm"),(void*)f_11980},
{C_text("f_11987:modules_2escm"),(void*)f_11987},
{C_text("f_11999:modules_2escm"),(void*)f_11999},
{C_text("f_12034:modules_2escm"),(void*)f_12034},
{C_text("f_12041:modules_2escm"),(void*)f_12041},
{C_text("f_12053:modules_2escm"),(void*)f_12053},
{C_text("f_12088:modules_2escm"),(void*)f_12088},
{C_text("f_12095:modules_2escm"),(void*)f_12095},
{C_text("f_12107:modules_2escm"),(void*)f_12107},
{C_text("f_12142:modules_2escm"),(void*)f_12142},
{C_text("f_12149:modules_2escm"),(void*)f_12149},
{C_text("f_12161:modules_2escm"),(void*)f_12161},
{C_text("f_12196:modules_2escm"),(void*)f_12196},
{C_text("f_12203:modules_2escm"),(void*)f_12203},
{C_text("f_12215:modules_2escm"),(void*)f_12215},
{C_text("f_12250:modules_2escm"),(void*)f_12250},
{C_text("f_12257:modules_2escm"),(void*)f_12257},
{C_text("f_12269:modules_2escm"),(void*)f_12269},
{C_text("f_12304:modules_2escm"),(void*)f_12304},
{C_text("f_12311:modules_2escm"),(void*)f_12311},
{C_text("f_12323:modules_2escm"),(void*)f_12323},
{C_text("f_12358:modules_2escm"),(void*)f_12358},
{C_text("f_12365:modules_2escm"),(void*)f_12365},
{C_text("f_12377:modules_2escm"),(void*)f_12377},
{C_text("f_12412:modules_2escm"),(void*)f_12412},
{C_text("f_12419:modules_2escm"),(void*)f_12419},
{C_text("f_12431:modules_2escm"),(void*)f_12431},
{C_text("f_12466:modules_2escm"),(void*)f_12466},
{C_text("f_12473:modules_2escm"),(void*)f_12473},
{C_text("f_12485:modules_2escm"),(void*)f_12485},
{C_text("f_12520:modules_2escm"),(void*)f_12520},
{C_text("f_12524:modules_2escm"),(void*)f_12524},
{C_text("f_12528:modules_2escm"),(void*)f_12528},
{C_text("f_4382:modules_2escm"),(void*)f_4382},
{C_text("f_4385:modules_2escm"),(void*)f_4385},
{C_text("f_4388:modules_2escm"),(void*)f_4388},
{C_text("f_4391:modules_2escm"),(void*)f_4391},
{C_text("f_4394:modules_2escm"),(void*)f_4394},
{C_text("f_4397:modules_2escm"),(void*)f_4397},
{C_text("f_4888:modules_2escm"),(void*)f_4888},
{C_text("f_4894:modules_2escm"),(void*)f_4894},
{C_text("f_4907:modules_2escm"),(void*)f_4907},
{C_text("f_4921:modules_2escm"),(void*)f_4921},
{C_text("f_4969:modules_2escm"),(void*)f_4969},
{C_text("f_4983:modules_2escm"),(void*)f_4983},
{C_text("f_4996:modules_2escm"),(void*)f_4996},
{C_text("f_5052:modules_2escm"),(void*)f_5052},
{C_text("f_5061:modules_2escm"),(void*)f_5061},
{C_text("f_5069:modules_2escm"),(void*)f_5069},
{C_text("f_5073:modules_2escm"),(void*)f_5073},
{C_text("f_5077:modules_2escm"),(void*)f_5077},
{C_text("f_5095:modules_2escm"),(void*)f_5095},
{C_text("f_5679:modules_2escm"),(void*)f_5679},
{C_text("f_5683:modules_2escm"),(void*)f_5683},
{C_text("f_5698:modules_2escm"),(void*)f_5698},
{C_text("f_5788:modules_2escm"),(void*)f_5788},
{C_text("f_5797:modules_2escm"),(void*)f_5797},
{C_text("f_5951:modules_2escm"),(void*)f_5951},
{C_text("f_5969:modules_2escm"),(void*)f_5969},
{C_text("f_5984:modules_2escm"),(void*)f_5984},
{C_text("f_6000:modules_2escm"),(void*)f_6000},
{C_text("f_6002:modules_2escm"),(void*)f_6002},
{C_text("f_6006:modules_2escm"),(void*)f_6006},
{C_text("f_6011:modules_2escm"),(void*)f_6011},
{C_text("f_6015:modules_2escm"),(void*)f_6015},
{C_text("f_6019:modules_2escm"),(void*)f_6019},
{C_text("f_6022:modules_2escm"),(void*)f_6022},
{C_text("f_6028:modules_2escm"),(void*)f_6028},
{C_text("f_6034:modules_2escm"),(void*)f_6034},
{C_text("f_6038:modules_2escm"),(void*)f_6038},
{C_text("f_6041:modules_2escm"),(void*)f_6041},
{C_text("f_6065:modules_2escm"),(void*)f_6065},
{C_text("f_6069:modules_2escm"),(void*)f_6069},
{C_text("f_6071:modules_2escm"),(void*)f_6071},
{C_text("f_6105:modules_2escm"),(void*)f_6105},
{C_text("f_6113:modules_2escm"),(void*)f_6113},
{C_text("f_6115:modules_2escm"),(void*)f_6115},
{C_text("f_6123:modules_2escm"),(void*)f_6123},
{C_text("f_6150:modules_2escm"),(void*)f_6150},
{C_text("f_6152:modules_2escm"),(void*)f_6152},
{C_text("f_6206:modules_2escm"),(void*)f_6206},
{C_text("f_6213:modules_2escm"),(void*)f_6213},
{C_text("f_6216:modules_2escm"),(void*)f_6216},
{C_text("f_6219:modules_2escm"),(void*)f_6219},
{C_text("f_6222:modules_2escm"),(void*)f_6222},
{C_text("f_6228:modules_2escm"),(void*)f_6228},
{C_text("f_6241:modules_2escm"),(void*)f_6241},
{C_text("f_6253:modules_2escm"),(void*)f_6253},
{C_text("f_6257:modules_2escm"),(void*)f_6257},
{C_text("f_6259:modules_2escm"),(void*)f_6259},
{C_text("f_6275:modules_2escm"),(void*)f_6275},
{C_text("f_6276:modules_2escm"),(void*)f_6276},
{C_text("f_6284:modules_2escm"),(void*)f_6284},
{C_text("f_6298:modules_2escm"),(void*)f_6298},
{C_text("f_6301:modules_2escm"),(void*)f_6301},
{C_text("f_6308:modules_2escm"),(void*)f_6308},
{C_text("f_6312:modules_2escm"),(void*)f_6312},
{C_text("f_6318:modules_2escm"),(void*)f_6318},
{C_text("f_6346:modules_2escm"),(void*)f_6346},
{C_text("f_6348:modules_2escm"),(void*)f_6348},
{C_text("f_6355:modules_2escm"),(void*)f_6355},
{C_text("f_6368:modules_2escm"),(void*)f_6368},
{C_text("f_6370:modules_2escm"),(void*)f_6370},
{C_text("f_6406:modules_2escm"),(void*)f_6406},
{C_text("f_6408:modules_2escm"),(void*)f_6408},
{C_text("f_6411:modules_2escm"),(void*)f_6411},
{C_text("f_6415:modules_2escm"),(void*)f_6415},
{C_text("f_6431:modules_2escm"),(void*)f_6431},
{C_text("f_6438:modules_2escm"),(void*)f_6438},
{C_text("f_6452:modules_2escm"),(void*)f_6452},
{C_text("f_6462:modules_2escm"),(void*)f_6462},
{C_text("f_6465:modules_2escm"),(void*)f_6465},
{C_text("f_6468:modules_2escm"),(void*)f_6468},
{C_text("f_6474:modules_2escm"),(void*)f_6474},
{C_text("f_6477:modules_2escm"),(void*)f_6477},
{C_text("f_6480:modules_2escm"),(void*)f_6480},
{C_text("f_6513:modules_2escm"),(void*)f_6513},
{C_text("f_6517:modules_2escm"),(void*)f_6517},
{C_text("f_6524:modules_2escm"),(void*)f_6524},
{C_text("f_6528:modules_2escm"),(void*)f_6528},
{C_text("f_6541:modules_2escm"),(void*)f_6541},
{C_text("f_6551:modules_2escm"),(void*)f_6551},
{C_text("f_6554:modules_2escm"),(void*)f_6554},
{C_text("f_6560:modules_2escm"),(void*)f_6560},
{C_text("f_6563:modules_2escm"),(void*)f_6563},
{C_text("f_6569:modules_2escm"),(void*)f_6569},
{C_text("f_6603:modules_2escm"),(void*)f_6603},
{C_text("f_6607:modules_2escm"),(void*)f_6607},
{C_text("f_6622:modules_2escm"),(void*)f_6622},
{C_text("f_6633:modules_2escm"),(void*)f_6633},
{C_text("f_6639:modules_2escm"),(void*)f_6639},
{C_text("f_6656:modules_2escm"),(void*)f_6656},
{C_text("f_6663:modules_2escm"),(void*)f_6663},
{C_text("f_6670:modules_2escm"),(void*)f_6670},
{C_text("f_6715:modules_2escm"),(void*)f_6715},
{C_text("f_6821:modules_2escm"),(void*)f_6821},
{C_text("f_6829:modules_2escm"),(void*)f_6829},
{C_text("f_6833:modules_2escm"),(void*)f_6833},
{C_text("f_6844:modules_2escm"),(void*)f_6844},
{C_text("f_6871:modules_2escm"),(void*)f_6871},
{C_text("f_6894:modules_2escm"),(void*)f_6894},
{C_text("f_6908:modules_2escm"),(void*)f_6908},
{C_text("f_6933:modules_2escm"),(void*)f_6933},
{C_text("f_6948:modules_2escm"),(void*)f_6948},
{C_text("f_6966:modules_2escm"),(void*)f_6966},
{C_text("f_6977:modules_2escm"),(void*)f_6977},
{C_text("f_6996:modules_2escm"),(void*)f_6996},
{C_text("f_7009:modules_2escm"),(void*)f_7009},
{C_text("f_7019:modules_2escm"),(void*)f_7019},
{C_text("f_7025:modules_2escm"),(void*)f_7025},
{C_text("f_7029:modules_2escm"),(void*)f_7029},
{C_text("f_7032:modules_2escm"),(void*)f_7032},
{C_text("f_7043:modules_2escm"),(void*)f_7043},
{C_text("f_7071:modules_2escm"),(void*)f_7071},
{C_text("f_7085:modules_2escm"),(void*)f_7085},
{C_text("f_7090:modules_2escm"),(void*)f_7090},
{C_text("f_7100:modules_2escm"),(void*)f_7100},
{C_text("f_7118:modules_2escm"),(void*)f_7118},
{C_text("f_7140:modules_2escm"),(void*)f_7140},
{C_text("f_7148:modules_2escm"),(void*)f_7148},
{C_text("f_7182:modules_2escm"),(void*)f_7182},
{C_text("f_7193:modules_2escm"),(void*)f_7193},
{C_text("f_7201:modules_2escm"),(void*)f_7201},
{C_text("f_7235:modules_2escm"),(void*)f_7235},
{C_text("f_7241:modules_2escm"),(void*)f_7241},
{C_text("f_7247:modules_2escm"),(void*)f_7247},
{C_text("f_7257:modules_2escm"),(void*)f_7257},
{C_text("f_7292:modules_2escm"),(void*)f_7292},
{C_text("f_7296:modules_2escm"),(void*)f_7296},
{C_text("f_7300:modules_2escm"),(void*)f_7300},
{C_text("f_7304:modules_2escm"),(void*)f_7304},
{C_text("f_7308:modules_2escm"),(void*)f_7308},
{C_text("f_7312:modules_2escm"),(void*)f_7312},
{C_text("f_7316:modules_2escm"),(void*)f_7316},
{C_text("f_7320:modules_2escm"),(void*)f_7320},
{C_text("f_7352:modules_2escm"),(void*)f_7352},
{C_text("f_7388:modules_2escm"),(void*)f_7388},
{C_text("f_7390:modules_2escm"),(void*)f_7390},
{C_text("f_7426:modules_2escm"),(void*)f_7426},
{C_text("f_7438:modules_2escm"),(void*)f_7438},
{C_text("f_7470:modules_2escm"),(void*)f_7470},
{C_text("f_7480:modules_2escm"),(void*)f_7480},
{C_text("f_7495:modules_2escm"),(void*)f_7495},
{C_text("f_7519:modules_2escm"),(void*)f_7519},
{C_text("f_7535:modules_2escm"),(void*)f_7535},
{C_text("f_7537:modules_2escm"),(void*)f_7537},
{C_text("f_7562:modules_2escm"),(void*)f_7562},
{C_text("f_7624:modules_2escm"),(void*)f_7624},
{C_text("f_7626:modules_2escm"),(void*)f_7626},
{C_text("f_7651:modules_2escm"),(void*)f_7651},
{C_text("f_7681:modules_2escm"),(void*)f_7681},
{C_text("f_7702:modules_2escm"),(void*)f_7702},
{C_text("f_7730:modules_2escm"),(void*)f_7730},
{C_text("f_7739:modules_2escm"),(void*)f_7739},
{C_text("f_7756:modules_2escm"),(void*)f_7756},
{C_text("f_7795:modules_2escm"),(void*)f_7795},
{C_text("f_7798:modules_2escm"),(void*)f_7798},
{C_text("f_7801:modules_2escm"),(void*)f_7801},
{C_text("f_7817:modules_2escm"),(void*)f_7817},
{C_text("f_7827:modules_2escm"),(void*)f_7827},
{C_text("f_7833:modules_2escm"),(void*)f_7833},
{C_text("f_7834:modules_2escm"),(void*)f_7834},
{C_text("f_7846:modules_2escm"),(void*)f_7846},
{C_text("f_7859:modules_2escm"),(void*)f_7859},
{C_text("f_7860:modules_2escm"),(void*)f_7860},
{C_text("f_7872:modules_2escm"),(void*)f_7872},
{C_text("f_7885:modules_2escm"),(void*)f_7885},
{C_text("f_7888:modules_2escm"),(void*)f_7888},
{C_text("f_7904:modules_2escm"),(void*)f_7904},
{C_text("f_7908:modules_2escm"),(void*)f_7908},
{C_text("f_7912:modules_2escm"),(void*)f_7912},
{C_text("f_7914:modules_2escm"),(void*)f_7914},
{C_text("f_7924:modules_2escm"),(void*)f_7924},
{C_text("f_7937:modules_2escm"),(void*)f_7937},
{C_text("f_7947:modules_2escm"),(void*)f_7947},
{C_text("f_7971:modules_2escm"),(void*)f_7971},
{C_text("f_7975:modules_2escm"),(void*)f_7975},
{C_text("f_7990:modules_2escm"),(void*)f_7990},
{C_text("f_7992:modules_2escm"),(void*)f_7992},
{C_text("f_8026:modules_2escm"),(void*)f_8026},
{C_text("f_8038:modules_2escm"),(void*)f_8038},
{C_text("f_8056:modules_2escm"),(void*)f_8056},
{C_text("f_8090:modules_2escm"),(void*)f_8090},
{C_text("f_8097:modules_2escm"),(void*)f_8097},
{C_text("f_8103:modules_2escm"),(void*)f_8103},
{C_text("f_8119:modules_2escm"),(void*)f_8119},
{C_text("f_8123:modules_2escm"),(void*)f_8123},
{C_text("f_8127:modules_2escm"),(void*)f_8127},
{C_text("f_8140:modules_2escm"),(void*)f_8140},
{C_text("f_8162:modules_2escm"),(void*)f_8162},
{C_text("f_8164:modules_2escm"),(void*)f_8164},
{C_text("f_8189:modules_2escm"),(void*)f_8189},
{C_text("f_8204:modules_2escm"),(void*)f_8204},
{C_text("f_8219:modules_2escm"),(void*)f_8219},
{C_text("f_8230:modules_2escm"),(void*)f_8230},
{C_text("f_8232:modules_2escm"),(void*)f_8232},
{C_text("f_8297:modules_2escm"),(void*)f_8297},
{C_text("f_8303:modules_2escm"),(void*)f_8303},
{C_text("f_8307:modules_2escm"),(void*)f_8307},
{C_text("f_8313:modules_2escm"),(void*)f_8313},
{C_text("f_8316:modules_2escm"),(void*)f_8316},
{C_text("f_8319:modules_2escm"),(void*)f_8319},
{C_text("f_8322:modules_2escm"),(void*)f_8322},
{C_text("f_8323:modules_2escm"),(void*)f_8323},
{C_text("f_8330:modules_2escm"),(void*)f_8330},
{C_text("f_8333:modules_2escm"),(void*)f_8333},
{C_text("f_8336:modules_2escm"),(void*)f_8336},
{C_text("f_8337:modules_2escm"),(void*)f_8337},
{C_text("f_8340:modules_2escm"),(void*)f_8340},
{C_text("f_8344:modules_2escm"),(void*)f_8344},
{C_text("f_8370:modules_2escm"),(void*)f_8370},
{C_text("f_8376:modules_2escm"),(void*)f_8376},
{C_text("f_8380:modules_2escm"),(void*)f_8380},
{C_text("f_8384:modules_2escm"),(void*)f_8384},
{C_text("f_8390:modules_2escm"),(void*)f_8390},
{C_text("f_8393:modules_2escm"),(void*)f_8393},
{C_text("f_8396:modules_2escm"),(void*)f_8396},
{C_text("f_8399:modules_2escm"),(void*)f_8399},
{C_text("f_8406:modules_2escm"),(void*)f_8406},
{C_text("f_8422:modules_2escm"),(void*)f_8422},
{C_text("f_8428:modules_2escm"),(void*)f_8428},
{C_text("f_8431:modules_2escm"),(void*)f_8431},
{C_text("f_8438:modules_2escm"),(void*)f_8438},
{C_text("f_8445:modules_2escm"),(void*)f_8445},
{C_text("f_8451:modules_2escm"),(void*)f_8451},
{C_text("f_8454:modules_2escm"),(void*)f_8454},
{C_text("f_8457:modules_2escm"),(void*)f_8457},
{C_text("f_8475:modules_2escm"),(void*)f_8475},
{C_text("f_8478:modules_2escm"),(void*)f_8478},
{C_text("f_8496:modules_2escm"),(void*)f_8496},
{C_text("f_8508:modules_2escm"),(void*)f_8508},
{C_text("f_8511:modules_2escm"),(void*)f_8511},
{C_text("f_8518:modules_2escm"),(void*)f_8518},
{C_text("f_8524:modules_2escm"),(void*)f_8524},
{C_text("f_8525:modules_2escm"),(void*)f_8525},
{C_text("f_8532:modules_2escm"),(void*)f_8532},
{C_text("f_8544:modules_2escm"),(void*)f_8544},
{C_text("f_8554:modules_2escm"),(void*)f_8554},
{C_text("f_8572:modules_2escm"),(void*)f_8572},
{C_text("f_8582:modules_2escm"),(void*)f_8582},
{C_text("f_8602:modules_2escm"),(void*)f_8602},
{C_text("f_8609:modules_2escm"),(void*)f_8609},
{C_text("f_8611:modules_2escm"),(void*)f_8611},
{C_text("f_8621:modules_2escm"),(void*)f_8621},
{C_text("f_8636:modules_2escm"),(void*)f_8636},
{C_text("f_8638:modules_2escm"),(void*)f_8638},
{C_text("f_8668:modules_2escm"),(void*)f_8668},
{C_text("f_8680:modules_2escm"),(void*)f_8680},
{C_text("f_8683:modules_2escm"),(void*)f_8683},
{C_text("f_8686:modules_2escm"),(void*)f_8686},
{C_text("f_8707:modules_2escm"),(void*)f_8707},
{C_text("f_8709:modules_2escm"),(void*)f_8709},
{C_text("f_8757:modules_2escm"),(void*)f_8757},
{C_text("f_8786:modules_2escm"),(void*)f_8786},
{C_text("f_8796:modules_2escm"),(void*)f_8796},
{C_text("f_8800:modules_2escm"),(void*)f_8800},
{C_text("f_8819:modules_2escm"),(void*)f_8819},
{C_text("f_8822:modules_2escm"),(void*)f_8822},
{C_text("f_8825:modules_2escm"),(void*)f_8825},
{C_text("f_8826:modules_2escm"),(void*)f_8826},
{C_text("f_8844:modules_2escm"),(void*)f_8844},
{C_text("f_8850:modules_2escm"),(void*)f_8850},
{C_text("f_8853:modules_2escm"),(void*)f_8853},
{C_text("f_8856:modules_2escm"),(void*)f_8856},
{C_text("f_8884:modules_2escm"),(void*)f_8884},
{C_text("f_8891:modules_2escm"),(void*)f_8891},
{C_text("f_8897:modules_2escm"),(void*)f_8897},
{C_text("f_8900:modules_2escm"),(void*)f_8900},
{C_text("f_8901:modules_2escm"),(void*)f_8901},
{C_text("f_8905:modules_2escm"),(void*)f_8905},
{C_text("f_8923:modules_2escm"),(void*)f_8923},
{C_text("f_8929:modules_2escm"),(void*)f_8929},
{C_text("f_8932:modules_2escm"),(void*)f_8932},
{C_text("f_8935:modules_2escm"),(void*)f_8935},
{C_text("f_8946:modules_2escm"),(void*)f_8946},
{C_text("f_8950:modules_2escm"),(void*)f_8950},
{C_text("f_8954:modules_2escm"),(void*)f_8954},
{C_text("f_8958:modules_2escm"),(void*)f_8958},
{C_text("f_8964:modules_2escm"),(void*)f_8964},
{C_text("f_8974:modules_2escm"),(void*)f_8974},
{C_text("f_8989:modules_2escm"),(void*)f_8989},
{C_text("f_8993:modules_2escm"),(void*)f_8993},
{C_text("f_8995:modules_2escm"),(void*)f_8995},
{C_text("f_9005:modules_2escm"),(void*)f_9005},
{C_text("f_9020:modules_2escm"),(void*)f_9020},
{C_text("f_9038:modules_2escm"),(void*)f_9038},
{C_text("f_9065:modules_2escm"),(void*)f_9065},
{C_text("f_9111:modules_2escm"),(void*)f_9111},
{C_text("f_9120:modules_2escm"),(void*)f_9120},
{C_text("f_9131:modules_2escm"),(void*)f_9131},
{C_text("f_9135:modules_2escm"),(void*)f_9135},
{C_text("f_9138:modules_2escm"),(void*)f_9138},
{C_text("f_9146:modules_2escm"),(void*)f_9146},
{C_text("f_9167:modules_2escm"),(void*)f_9167},
{C_text("f_9171:modules_2escm"),(void*)f_9171},
{C_text("f_9179:modules_2escm"),(void*)f_9179},
{C_text("f_9183:modules_2escm"),(void*)f_9183},
{C_text("f_9199:modules_2escm"),(void*)f_9199},
{C_text("f_9203:modules_2escm"),(void*)f_9203},
{C_text("f_9217:modules_2escm"),(void*)f_9217},
{C_text("f_9228:modules_2escm"),(void*)f_9228},
{C_text("f_9254:modules_2escm"),(void*)f_9254},
{C_text("f_9256:modules_2escm"),(void*)f_9256},
{C_text("f_9280:modules_2escm"),(void*)f_9280},
{C_text("f_9289:modules_2escm"),(void*)f_9289},
{C_text("f_9304:modules_2escm"),(void*)f_9304},
{C_text("f_9312:modules_2escm"),(void*)f_9312},
{C_text("f_9319:modules_2escm"),(void*)f_9319},
{C_text("f_9323:modules_2escm"),(void*)f_9323},
{C_text("f_9326:modules_2escm"),(void*)f_9326},
{C_text("f_9331:modules_2escm"),(void*)f_9331},
{C_text("f_9335:modules_2escm"),(void*)f_9335},
{C_text("f_9338:modules_2escm"),(void*)f_9338},
{C_text("f_9341:modules_2escm"),(void*)f_9341},
{C_text("f_9344:modules_2escm"),(void*)f_9344},
{C_text("f_9348:modules_2escm"),(void*)f_9348},
{C_text("f_9352:modules_2escm"),(void*)f_9352},
{C_text("f_9356:modules_2escm"),(void*)f_9356},
{C_text("f_9360:modules_2escm"),(void*)f_9360},
{C_text("f_9363:modules_2escm"),(void*)f_9363},
{C_text("f_9366:modules_2escm"),(void*)f_9366},
{C_text("f_9369:modules_2escm"),(void*)f_9369},
{C_text("f_9372:modules_2escm"),(void*)f_9372},
{C_text("f_9387:modules_2escm"),(void*)f_9387},
{C_text("f_9393:modules_2escm"),(void*)f_9393},
{C_text("f_9397:modules_2escm"),(void*)f_9397},
{C_text("f_9400:modules_2escm"),(void*)f_9400},
{C_text("f_9403:modules_2escm"),(void*)f_9403},
{C_text("f_9406:modules_2escm"),(void*)f_9406},
{C_text("f_9409:modules_2escm"),(void*)f_9409},
{C_text("f_9412:modules_2escm"),(void*)f_9412},
{C_text("f_9415:modules_2escm"),(void*)f_9415},
{C_text("f_9418:modules_2escm"),(void*)f_9418},
{C_text("f_9424:modules_2escm"),(void*)f_9424},
{C_text("f_9428:modules_2escm"),(void*)f_9428},
{C_text("f_9436:modules_2escm"),(void*)f_9436},
{C_text("f_9442:modules_2escm"),(void*)f_9442},
{C_text("f_9447:modules_2escm"),(void*)f_9447},
{C_text("f_9451:modules_2escm"),(void*)f_9451},
{C_text("f_9456:modules_2escm"),(void*)f_9456},
{C_text("f_9463:modules_2escm"),(void*)f_9463},
{C_text("f_9467:modules_2escm"),(void*)f_9467},
{C_text("f_9470:modules_2escm"),(void*)f_9470},
{C_text("f_9474:modules_2escm"),(void*)f_9474},
{C_text("f_9477:modules_2escm"),(void*)f_9477},
{C_text("f_9485:modules_2escm"),(void*)f_9485},
{C_text("f_9489:modules_2escm"),(void*)f_9489},
{C_text("f_9492:modules_2escm"),(void*)f_9492},
{C_text("f_9495:modules_2escm"),(void*)f_9495},
{C_text("f_9498:modules_2escm"),(void*)f_9498},
{C_text("f_9500:modules_2escm"),(void*)f_9500},
{C_text("f_9508:modules_2escm"),(void*)f_9508},
{C_text("f_9512:modules_2escm"),(void*)f_9512},
{C_text("f_9514:modules_2escm"),(void*)f_9514},
{C_text("f_9527:modules_2escm"),(void*)f_9527},
{C_text("f_9534:modules_2escm"),(void*)f_9534},
{C_text("f_9558:modules_2escm"),(void*)f_9558},
{C_text("f_9572:modules_2escm"),(void*)f_9572},
{C_text("f_9580:modules_2escm"),(void*)f_9580},
{C_text("f_9607:modules_2escm"),(void*)f_9607},
{C_text("f_9632:modules_2escm"),(void*)f_9632},
{C_text("f_9644:modules_2escm"),(void*)f_9644},
{C_text("f_9647:modules_2escm"),(void*)f_9647},
{C_text("f_9651:modules_2escm"),(void*)f_9651},
{C_text("f_9654:modules_2escm"),(void*)f_9654},
{C_text("f_9682:modules_2escm"),(void*)f_9682},
{C_text("f_9686:modules_2escm"),(void*)f_9686},
{C_text("f_9703:modules_2escm"),(void*)f_9703},
{C_text("f_9717:modules_2escm"),(void*)f_9717},
{C_text("f_9735:modules_2escm"),(void*)f_9735},
{C_text("f_9738:modules_2escm"),(void*)f_9738},
{C_text("f_9743:modules_2escm"),(void*)f_9743},
{C_text("f_9753:modules_2escm"),(void*)f_9753},
{C_text("f_9757:modules_2escm"),(void*)f_9757},
{C_text("f_9762:modules_2escm"),(void*)f_9762},
{C_text("f_9770:modules_2escm"),(void*)f_9770},
{C_text("f_9780:modules_2escm"),(void*)f_9780},
{C_text("f_9793:modules_2escm"),(void*)f_9793},
{C_text("f_9803:modules_2escm"),(void*)f_9803},
{C_text("f_9821:modules_2escm"),(void*)f_9821},
{C_text("f_9843:modules_2escm"),(void*)f_9843},
{C_text("f_9885:modules_2escm"),(void*)f_9885},
{C_text("f_9888:modules_2escm"),(void*)f_9888},
{C_text("f_9893:modules_2escm"),(void*)f_9893},
{C_text("f_9903:modules_2escm"),(void*)f_9903},
{C_text("f_9907:modules_2escm"),(void*)f_9907},
{C_text("f_9912:modules_2escm"),(void*)f_9912},
{C_text("f_9924:modules_2escm"),(void*)f_9924},
{C_text("f_9932:modules_2escm"),(void*)f_9932},
{C_text("f_9942:modules_2escm"),(void*)f_9942},
{C_text("f_9955:modules_2escm"),(void*)f_9955},
{C_text("f_9965:modules_2escm"),(void*)f_9965},
{C_text("f_9983:modules_2escm"),(void*)f_9983},
{C_text("f_9995:modules_2escm"),(void*)f_9995},
{C_text("toplevel:modules_2escm"),(void*)C_modules_toplevel},
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
S|  chicken.format#format		3
S|  chicken.format#fprintf		8
S|  scheme#for-each		16
S|  chicken.base#foldl		3
S|  scheme#map		36
S|  chicken.base#foldr		3
o|eliminated procedure checks: 504 
o|specializations:
o|  1 (scheme#cddr (pair * pair))
o|  1 (scheme#number->string *)
o|  2 (scheme#string-append string string)
o|  3 (scheme#= fixnum fixnum)
o|  1 (scheme#length list)
o|  11 (##sys#check-output-port * * *)
o|  2 (scheme#cdar (pair pair *))
o|  1 (scheme#caar (pair pair *))
o|  1 (scheme#eqv? * *)
o|  10 (##sys#check-list (or pair list) *)
o|  77 (scheme#cdr pair)
o|  37 (scheme#car pair)
(o e)|safe calls: 1214 
(o e)|dropped branches: 2 
(o e)|assignments to immediate values: 1 
o|safe globals: (posv posq make-list iota find-tail find length+ lset=/eq? lset<=/eq? list-tabulate lset-intersection/eq? lset-union/eq? lset-difference/eq? lset-adjoin/eq? list-index last unzip1 remove filter-map filter alist-cons delete-duplicates fifth fourth third second first delete concatenate cons* any every append-map split-at drop take span partition) 
o|removed side-effect free assignment to unused variable: partition 
o|removed side-effect free assignment to unused variable: span 
o|removed side-effect free assignment to unused variable: drop 
o|removed side-effect free assignment to unused variable: split-at 
o|removed side-effect free assignment to unused variable: append-map 
o|inlining procedure: k4779 
o|inlining procedure: k4779 
o|inlining procedure: k4810 
o|inlining procedure: k4810 
o|removed side-effect free assignment to unused variable: cons* 
o|removed side-effect free assignment to unused variable: concatenate 
o|inlining procedure: k4896 
o|inlining procedure: k4896 
o|removed side-effect free assignment to unused variable: first 
o|removed side-effect free assignment to unused variable: second 
o|removed side-effect free assignment to unused variable: third 
o|removed side-effect free assignment to unused variable: fourth 
o|removed side-effect free assignment to unused variable: fifth 
o|removed side-effect free assignment to unused variable: alist-cons 
o|inlining procedure: k5027 
o|inlining procedure: k5027 
o|inlining procedure: k5019 
o|inlining procedure: k5019 
o|inlining procedure: k5074 
o|inlining procedure: k5074 
o|inlining procedure: k5063 
o|inlining procedure: k5063 
o|removed side-effect free assignment to unused variable: remove 
o|removed side-effect free assignment to unused variable: unzip1 
o|removed side-effect free assignment to unused variable: last 
o|removed side-effect free assignment to unused variable: list-index 
o|removed side-effect free assignment to unused variable: lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: lset-difference/eq? 
o|removed side-effect free assignment to unused variable: lset-union/eq? 
o|removed side-effect free assignment to unused variable: lset-intersection/eq? 
o|inlining procedure: k5418 
o|inlining procedure: k5418 
o|removed side-effect free assignment to unused variable: lset<=/eq? 
o|removed side-effect free assignment to unused variable: lset=/eq? 
o|removed side-effect free assignment to unused variable: length+ 
o|removed side-effect free assignment to unused variable: find 
o|removed side-effect free assignment to unused variable: find-tail 
o|removed side-effect free assignment to unused variable: iota 
o|removed side-effect free assignment to unused variable: make-list 
o|removed side-effect free assignment to unused variable: posq 
o|removed side-effect free assignment to unused variable: posv 
o|removed side-effect free assignment to unused variable: module? 
o|merged explicitly consed rest parameter: rest915922 
o|contracted procedure: "(modules.scm:127) %make-module" 
o|inlining procedure: k6073 
o|contracted procedure: "(modules.scm:137) g950959" 
o|inlining procedure: k6073 
o|inlining procedure: k6128 
o|inlining procedure: k6128 
o|inlining procedure: k6120 
o|inlining procedure: k6120 
o|inlining procedure: k6169 
o|inlining procedure: k6169 
o|inlining procedure: k6220 
o|inlining procedure: k6220 
o|inlining procedure: k6281 
o|inlining procedure: k6281 
o|inlining procedure: k6264 
o|inlining procedure: k6320 
o|inlining procedure: k6320 
o|inlining procedure: k6264 
o|inlining procedure: k6372 
o|inlining procedure: k6372 
o|contracted procedure: "(modules.scm:189) set-module-rename-list!" 
o|inlining procedure: k6416 
o|contracted procedure: "(modules.scm:196) set-module-meta-expressions!" 
o|inlining procedure: k6416 
o|inlining procedure: k6442 
o|inlining procedure: k6442 
o|inlining procedure: k6454 
o|inlining procedure: k6454 
o|inlining procedure: k6543 
o|inlining procedure: k6543 
o|inlining procedure: k6624 
o|inlining procedure: k6624 
o|consed rest parameter at call site: "(modules.scm:260) make-module" 7 
o|merged explicitly consed rest parameter: ses*1245 
o|inlining procedure: k7045 
o|inlining procedure: k7045 
o|inlining procedure: k7065 
o|inlining procedure: k7092 
o|inlining procedure: k7092 
o|inlining procedure: k7065 
o|inlining procedure: k7120 
o|inlining procedure: k7120 
o|inlining procedure: k7392 
o|contracted procedure: "(modules.scm:381) g14471456" 
o|inlining procedure: k7392 
o|inlining procedure: k7424 
o|inlining procedure: k7424 
o|inlining procedure: k7440 
o|inlining procedure: k7440 
o|inlining procedure: k7503 
o|inlining procedure: k7503 
o|inlining procedure: k7539 
o|inlining procedure: k7539 
o|inlining procedure: k7628 
o|contracted procedure: "(modules.scm:354) g13611370" 
o|inlining procedure: k7580 
o|inlining procedure: k7580 
o|inlining procedure: k7628 
o|contracted procedure: "(modules.scm:347) g13491350" 
o|contracted procedure: "(modules.scm:339) compiled-module-dependencies" 
o|inlining procedure: k7203 
o|contracted procedure: "(modules.scm:327) g13031312" 
o|inlining procedure: k7203 
o|contracted procedure: "(modules.scm:328) delete-duplicates" 
o|inlining procedure: k4971 
o|inlining procedure: k4971 
o|inlining procedure: k7746 
o|inlining procedure: k7746 
o|consed rest parameter at call site: "(modules.scm:421) merge-se" 1 
o|inlining procedure: k7851 
o|consed rest parameter at call site: "(modules.scm:421) merge-se" 1 
o|inlining procedure: k7851 
o|consed rest parameter at call site: "(modules.scm:421) merge-se" 1 
o|consed rest parameter at call site: "(modules.scm:425) merge-se" 1 
o|inlining procedure: k7877 
o|consed rest parameter at call site: "(modules.scm:425) merge-se" 1 
o|inlining procedure: k7877 
o|consed rest parameter at call site: "(modules.scm:425) merge-se" 1 
o|consed rest parameter at call site: "(modules.scm:429) merge-se" 1 
o|inlining procedure: k7916 
o|inlining procedure: k7916 
o|inlining procedure: k7939 
o|inlining procedure: k7939 
o|consed rest parameter at call site: "(modules.scm:414) merge-se" 1 
o|consed rest parameter at call site: "(modules.scm:410) make-module" 7 
o|inlining procedure: k7994 
o|contracted procedure: "(modules.scm:407) g15091518" 
o|inlining procedure: k7994 
o|inlining procedure: k8028 
o|contracted procedure: "(modules.scm:404) find-reexport1490" 
o|inlining procedure: k7776 
o|inlining procedure: k7776 
o|inlining procedure: k8028 
o|inlining procedure: k8040 
o|inlining procedure: k8040 
o|consed rest parameter at call site: "(modules.scm:450) merge-se" 1 
o|inlining procedure: k8142 
o|inlining procedure: k8142 
o|consed rest parameter at call site: "(modules.scm:436) make-module" 7 
o|inlining procedure: k8166 
o|inlining procedure: k8166 
o|inlining procedure: k8234 
o|inlining procedure: k8234 
o|inlining procedure: k8246 
o|inlining procedure: k8261 
o|inlining procedure: k8261 
o|inlining procedure: k8246 
o|substituted constant variable: a8309 
o|substituted constant variable: a8310 
o|substituted constant variable: a8326 
o|substituted constant variable: a8327 
o|inlining procedure: k8345 
o|inlining procedure: k8345 
o|substituted constant variable: a8360 
o|substituted constant variable: a8372 
o|substituted constant variable: a8373 
o|substituted constant variable: a8386 
o|substituted constant variable: a8387 
o|substituted constant variable: a8424 
o|substituted constant variable: a8425 
o|inlining procedure: k8414 
o|substituted constant variable: a8447 
o|substituted constant variable: a8448 
o|inlining procedure: k8414 
o|inlining procedure: k8468 
o|inlining procedure: k8468 
o|inlining procedure: k8480 
o|substituted constant variable: a8492 
o|substituted constant variable: a8493 
o|substituted constant variable: a8504 
o|substituted constant variable: a8505 
o|inlining procedure: k8497 
o|substituted constant variable: a8520 
o|substituted constant variable: a8521 
o|substituted constant variable: a8528 
o|substituted constant variable: a8529 
o|inlining procedure: k8497 
o|inlining procedure: k8546 
o|inlining procedure: k8546 
o|substituted constant variable: a8566 
o|contracted procedure: "(modules.scm:522) g18381839" 
o|inlining procedure: k8480 
o|inlining procedure: k8574 
o|inlining procedure: k8574 
o|inlining procedure: k8613 
o|inlining procedure: k8613 
o|inlining procedure: k8640 
o|inlining procedure: k8640 
o|inlining procedure: k8663 
o|substituted constant variable: a8676 
o|substituted constant variable: a8677 
o|substituted constant variable: a8691 
o|inlining procedure: k8663 
o|inlining procedure: k8711 
o|inlining procedure: k8711 
o|inlining procedure: k8828 
o|inlining procedure: k8828 
o|consed rest parameter at call site: "(modules.scm:623) merge-se" 1 
o|consed rest parameter at call site: "(modules.scm:641) merge-se" 1 
o|consed rest parameter at call site: "(modules.scm:638) merge-se" 1 
o|contracted procedure: "(modules.scm:634) set-module-vexports!" 
o|inlining procedure: k8966 
o|inlining procedure: k8966 
o|consed rest parameter at call site: "(modules.scm:617) merge-se" 1 
o|inlining procedure: k8997 
o|contracted procedure: "(modules.scm:612) g19831992" 
o|inlining procedure: k8862 
o|inlining procedure: k8862 
o|inlining procedure: k8997 
o|contracted procedure: "(modules.scm:616) module-indirect-exports" 
o|removed side-effect free assignment to unused variable: indirect?1196 
o|inlining procedure: k6834 
o|inlining procedure: k6834 
o|inlining procedure: k6846 
o|inlining procedure: k6846 
o|inlining procedure: k6873 
o|inlining procedure: k6873 
o|inlining procedure: k6931 
o|inlining procedure: k6931 
o|inlining procedure: k6905 
o|inlining procedure: k6905 
o|inlining procedure: k6950 
o|inlining procedure: k6950 
o|inlining procedure: k9040 
o|inlining procedure: k9040 
o|inlining procedure: k9067 
o|inlining procedure: k9067 
o|inlining procedure: k9090 
o|inlining procedure: k9090 
o|inlining procedure: k9118 
o|inlining procedure: k9118 
o|inlining procedure: k9159 
o|inlining procedure: k9159 
o|inlining procedure: k9187 
o|inlining procedure: k9187 
o|consed rest parameter at call site: "(modules.scm:553) merge-se" 1 
o|inlining procedure: k9258 
o|inlining procedure: k9258 
o|inlining procedure: k9275 
o|inlining procedure: k9275 
o|contracted procedure: "(modules.scm:550) filter-sdlist1679" 
o|inlining procedure: k8759 
o|inlining procedure: k8759 
o|substituted constant variable: saved205120522071 
o|substituted constant variable: saved205320542072 
o|inlining procedure: k9429 
o|inlining procedure: k9429 
o|substituted constant variable: a9468 
o|inlining procedure: k9478 
o|inlining procedure: k9478 
o|inlining procedure: k9516 
o|inlining procedure: k9516 
o|inlining procedure: k9535 
o|inlining procedure: k9535 
o|inlining procedure: k9563 
o|inlining procedure: k9577 
o|inlining procedure: k9577 
o|inlining procedure: k9563 
o|inlining procedure: k9609 
o|inlining procedure: k9609 
o|inlining procedure: k9655 
o|inlining procedure: k9655 
o|inlining procedure: k9705 
o|inlining procedure: k9705 
o|inlining procedure: k9730 
o|inlining procedure: k9764 
o|inlining procedure: k9795 
o|inlining procedure: k9795 
o|inlining procedure: k9764 
o|inlining procedure: k9840 
o|inlining procedure: k9840 
o|inlining procedure: k9730 
o|inlining procedure: k9914 
o|inlining procedure: k9926 
o|inlining procedure: k9957 
o|inlining procedure: k9957 
o|inlining procedure: k9926 
o|inlining procedure: k9914 
o|inlining procedure: k10063 
o|inlining procedure: k10097 
o|inlining procedure: k10109 
o|inlining procedure: k10149 
o|inlining procedure: k10149 
o|inlining procedure: k10172 
o|inlining procedure: k10172 
o|inlining procedure: k10109 
o|inlining procedure: k10097 
o|inlining procedure: k10063 
o|inlining procedure: k10399 
o|inlining procedure: k10399 
o|inlining procedure: k10433 
o|inlining procedure: k10433 
o|inlining procedure: k10499 
o|inlining procedure: k10499 
o|inlining procedure: k10523 
o|inlining procedure: k10523 
o|inlining procedure: k10572 
o|inlining procedure: k10582 
o|inlining procedure: k10582 
o|inlining procedure: k10572 
o|inlining procedure: k10617 
o|inlining procedure: k10617 
o|consed rest parameter at call site: "(modules.scm:863) merge-se" 1 
o|consed rest parameter at call site: "(modules.scm:862) merge-se" 1 
o|consed rest parameter at call site: "(modules.scm:860) merge-se" 1 
o|inlining procedure: k10735 
o|inlining procedure: k10735 
o|inlining procedure: k10769 
o|inlining procedure: k10769 
o|inlining procedure: k10839 
o|inlining procedure: k10839 
o|inlining procedure: k10873 
o|inlining procedure: k10873 
o|inlining procedure: k10913 
o|inlining procedure: k10913 
o|inlining procedure: k10936 
o|inlining procedure: k10936 
o|inlining procedure: k10956 
o|contracted procedure: "(modules.scm:813) set-module-meta-import-forms!" 
o|inlining procedure: k10956 
o|contracted procedure: "(modules.scm:816) set-module-import-forms!" 
o|contracted procedure: "(modules.scm:878) register-undefined" 
o|inlining procedure: k6651 
o|inlining procedure: k6665 
o|inlining procedure: k6665 
o|inlining procedure: k6708 
o|inlining procedure: k6708 
o|inlining procedure: k6651 
o|inlining procedure: k11016 
o|inlining procedure: k11016 
o|inlining procedure: k11040 
o|inlining procedure: k11040 
o|inlining procedure: k11062 
o|inlining procedure: k11062 
o|contracted procedure: "(modules.scm:881) g28182819" 
o|merged explicitly consed rest parameter: args2839 
o|inlining procedure: k11098 
o|inlining procedure: k11098 
o|consed rest parameter at call site: "(modules.scm:896) err2837" 1 
o|contracted procedure: "(modules.scm:895) g28442845" 
o|inlining procedure: k11104 
o|inlining procedure: k11104 
o|inlining procedure: k11119 
o|consed rest parameter at call site: "(modules.scm:900) err2837" 1 
o|inlining procedure: k11119 
o|inlining procedure: k11134 
o|inlining procedure: k11134 
o|consed rest parameter at call site: "(modules.scm:905) err2837" 1 
o|inlining procedure: k11152 
o|inlining procedure: k11152 
o|consed rest parameter at call site: "(modules.scm:910) err2837" 1 
o|inlining procedure: k11176 
o|inlining procedure: k11176 
o|inlining procedure: k11199 
o|inlining procedure: k11199 
o|consed rest parameter at call site: "(modules.scm:916) err2837" 1 
o|inlining procedure: k11243 
o|inlining procedure: k11243 
o|consed rest parameter at call site: "(modules.scm:921) err2837" 1 
o|contracted procedure: "(modules.scm:924) g28752876" 
o|merged explicitly consed rest parameter: args2890 
o|consed rest parameter at call site: "(modules.scm:935) err2889" 1 
o|inlining procedure: k11364 
o|inlining procedure: k11364 
o|inlining procedure: k11415 
o|inlining procedure: k11415 
o|inlining procedure: k11424 
o|inlining procedure: k11436 
o|inlining procedure: k11436 
o|removed unused parameter to known procedure: alias2951 "(modules.scm:949) match-functor-argument" 
o|inlining procedure: k11424 
o|removed unused parameter to known procedure: alias2951 "(modules.scm:963) match-functor-argument" 
o|consed rest parameter at call site: "(modules.scm:930) err2889" 1 
o|contracted procedure: "(modules.scm:927) g28852886" 
o|removed unused formal parameters: (alias2951) 
o|inlining procedure: k11544 
o|inlining procedure: k11555 
o|inlining procedure: k11555 
o|inlining procedure: k11544 
o|inlining procedure: k11639 
o|contracted procedure: "(modules.scm:990) g29882997" 
o|substituted constant variable: a11625 
o|inlining procedure: k11639 
o|inlining procedure: k11673 
o|inlining procedure: k11673 
o|inlining procedure: k11787 
o|inlining procedure: k11787 
o|contracted procedure: "(modules.scm:1214) g34693470" 
o|inlining procedure: k11839 
o|inlining procedure: k11839 
o|contracted procedure: "(modules.scm:1211) g34313432" 
o|inlining procedure: k11893 
o|inlining procedure: k11893 
o|contracted procedure: "(modules.scm:1207) g33933394" 
o|inlining procedure: k11947 
o|inlining procedure: k11947 
o|contracted procedure: "(modules.scm:1201) g33553356" 
o|inlining procedure: k12001 
o|inlining procedure: k12001 
o|contracted procedure: "(modules.scm:1195) g33173318" 
o|inlining procedure: k12055 
o|inlining procedure: k12055 
o|contracted procedure: "(modules.scm:1189) g32793280" 
o|inlining procedure: k12109 
o|inlining procedure: k12109 
o|contracted procedure: "(modules.scm:1186) g32413242" 
o|inlining procedure: k12163 
o|inlining procedure: k12163 
o|contracted procedure: "(modules.scm:1183) g32033204" 
o|inlining procedure: k12217 
o|inlining procedure: k12217 
o|contracted procedure: "(modules.scm:1170) g31653166" 
o|inlining procedure: k12271 
o|inlining procedure: k12271 
o|contracted procedure: "(modules.scm:1164) g31273128" 
o|inlining procedure: k12325 
o|inlining procedure: k12325 
o|contracted procedure: "(modules.scm:1161) g30893090" 
o|inlining procedure: k12379 
o|inlining procedure: k12379 
o|contracted procedure: "(modules.scm:1152) g30513052" 
o|inlining procedure: k12433 
o|inlining procedure: k12433 
o|contracted procedure: "(modules.scm:1149) g30133014" 
o|inlining procedure: k12487 
o|inlining procedure: k12487 
o|propagated global variable: r4rs-syntax3009 ##sys#scheme-macro-environment 
o|replaced variables: 1836 
o|removed binding forms: 581 
o|removed side-effect free assignment to unused variable: every 
o|removed side-effect free assignment to unused variable: any 
o|removed side-effect free assignment to unused variable: filter 
o|substituted constant variable: r506412542 
o|removed side-effect free assignment to unused variable: list-tabulate 
o|substituted constant variable: defined-list767 
o|substituted constant variable: exist-list768 
o|substituted constant variable: defined-syntax-list769 
o|substituted constant variable: undefined-list770 
o|substituted constant variable: import-forms771 
o|substituted constant variable: meta-import-forms772 
o|substituted constant variable: meta-expressions773 
o|substituted constant variable: saved-environments777 
o|substituted constant variable: r641712572 
o|substituted constant variable: r644312574 
o|removed call to pure procedure with unused result: "(modules.scm:216) chicken.base#void" 
o|removed call to pure procedure with unused result: "(modules.scm:231) chicken.base#void" 
o|substituted constant variable: r742512591 
o|substituted constant variable: r742512591 
o|substituted constant variable: r744112595 
o|removed call to pure procedure with unused result: "(modules.scm:367) chicken.base#void" 
o|substituted constant variable: prop1352 
o|substituted constant variable: r774712610 
o|substituted constant variable: r785212613 
o|substituted constant variable: r785212613 
o|substituted constant variable: r787812617 
o|substituted constant variable: r787812617 
o|substituted constant variable: r802912628 
o|substituted constant variable: r804112630 
o|substituted constant variable: r823512635 
o|substituted constant variable: r846912646 
o|converted assignments to bindings: (ln->num1770) 
o|substituted constant variable: prop1841 
o|substituted constant variable: r848112652 
o|substituted constant variable: r866412660 
o|removed call to pure procedure with unused result: "(modules.scm:624) chicken.base#void" 
o|removed call to pure procedure with unused result: "(modules.scm:627) chicken.base#void" 
o|substituted constant variable: r683512671 
o|substituted constant variable: r684712673 
o|converted assignments to bindings: (warn1197) 
o|substituted constant variable: r906812687 
o|removed call to pure procedure with unused result: "(modules.scm:584) chicken.base#void" 
o|substituted constant variable: r925912699 
o|substituted constant variable: r876012703 
o|converted assignments to bindings: (report-unresolved-identifiers1678) 
o|substituted constant variable: r943012706 
o|converted assignments to bindings: (rename2482) 
o|converted assignments to bindings: (module-imports2185) 
o|substituted constant variable: r1058312757 
o|substituted constant variable: r1057312758 
o|substituted constant variable: r1061812760 
o|removed call to pure procedure with unused result: "(modules.scm:861) chicken.base#void" 
o|removed call to pure procedure with unused result: "(modules.scm:821) chicken.base#void" 
o|removed call to pure procedure with unused result: "(modules.scm:820) chicken.base#void" 
o|removed call to pure procedure with unused result: "(modules.scm:819) chicken.base#void" 
o|substituted constant variable: r670912780 
o|substituted constant variable: r670912780 
o|removed call to pure procedure with unused result: "(modules.scm:876) chicken.base#void" 
o|removed call to pure procedure with unused result: "(modules.scm:885) chicken.base#void" 
o|converted assignments to bindings: (mrename2803) 
o|substituted constant variable: prop2847 
o|substituted constant variable: r1113512795 
o|substituted constant variable: prop2878 
o|substituted constant variable: r1141612807 
o|substituted constant variable: r1141612807 
o|substituted constant variable: r1143712812 
o|converted assignments to bindings: (merr2897) 
o|converted assignments to bindings: (err2889) 
o|substituted constant variable: prop2888 
o|simplifications: ((let . 8)) 
o|replaced variables: 141 
o|removed binding forms: 1619 
o|contracted procedure: k6484 
o|contracted procedure: k6564 
o|contracted procedure: k7524 
o|inlining procedure: k8206 
o|inlining procedure: k8348 
o|inlining procedure: k8649 
o|inlining procedure: k8649 
o|inlining procedure: k8649 
o|inlining procedure: k8649 
o|contracted procedure: k8906 
o|contracted procedure: k8924 
o|inlining procedure: k9018 
o|inlining procedure: k9018 
o|contracted procedure: k9153 
o|contracted procedure: k10552 
o|contracted procedure: k10555 
o|contracted procedure: k10558 
o|contracted procedure: k11021 
o|inlining procedure: k11024 
o|inlining procedure: k11024 
o|contracted procedure: k11059 
o|removed binding forms: 168 
o|contracted procedure: k7669 
o|inlining procedure: k7779 
o|substituted constant variable: r820713167 
o|inlining procedure: k8258 
o|substituted constant variable: r834913170 
o|contracted procedure: k8485 
o|substituted constant variable: r865013178 
o|substituted constant variable: r865013178 
o|substituted constant variable: r865013180 
o|substituted constant variable: r865013180 
o|substituted constant variable: r865013182 
o|substituted constant variable: r865013182 
o|substituted constant variable: r865013184 
o|substituted constant variable: r865013184 
o|contracted procedure: k11045 
o|contracted procedure: k11095 
o|contracted procedure: k11317 
o|simplifications: ((let . 1)) 
o|replaced variables: 2 
o|removed binding forms: 20 
o|removed conditional forms: 5 
o|substituted constant variable: r778013332 
o|substituted constant variable: r825913335 
o|substituted constant variable: r825913335 
o|removed binding forms: 9 
o|removed conditional forms: 2 
o|removed binding forms: 2 
o|simplifications: ((if . 33) (##core#call . 831) (let . 57)) 
o|  call simplifications:
o|    scheme#list?	2
o|    scheme#set-cdr!
o|    scheme#caddr
o|    scheme#cddr	3
o|    scheme#string?
o|    scheme#number?
o|    scheme#cdar	3
o|    scheme#apply	4
o|    scheme#length	2
o|    scheme#list	7
o|    scheme#set-car!	3
o|    ##sys#call-with-values	6
o|    scheme#list-ref
o|    scheme#equal?
o|    scheme#symbol?	17
o|    ##sys#cons	20
o|    ##sys#list	26
o|    scheme#not	15
o|    scheme#caar	14
o|    scheme#eq?	27
o|    scheme#assq	43
o|    scheme#cdr	39
o|    scheme#memq	6
o|    scheme#cadr	15
o|    ##sys#setslot	33
o|    ##sys#make-structure	2
o|    scheme#values	6
o|    ##sys#check-structure	28
o|    ##sys#block-ref	15
o|    ##sys#check-list	43
o|    scheme#pair?	71
o|    ##sys#slot	135
o|    scheme#null?	45
o|    scheme#car	62
o|    scheme#cons	133
o|contracted procedure: k4899 
o|contracted procedure: k4925 
o|contracted procedure: k5054 
o|contracted procedure: k5066 
o|contracted procedure: k5089 
o|contracted procedure: k5097 
o|contracted procedure: k5700 
o|contracted procedure: k5709 
o|contracted procedure: k5718 
o|contracted procedure: k5727 
o|contracted procedure: k5736 
o|contracted procedure: k5745 
o|contracted procedure: k5754 
o|contracted procedure: k5763 
o|contracted procedure: k5772 
o|contracted procedure: k5781 
o|contracted procedure: k5790 
o|contracted procedure: k5799 
o|contracted procedure: k5808 
o|contracted procedure: k5826 
o|contracted procedure: k5844 
o|contracted procedure: k5862 
o|contracted procedure: k5880 
o|contracted procedure: k5889 
o|contracted procedure: k5898 
o|contracted procedure: k5907 
o|contracted procedure: k5916 
o|contracted procedure: k5925 
o|contracted procedure: k5934 
o|contracted procedure: k5977 
o|contracted procedure: k5971 
o|contracted procedure: k5994 
o|contracted procedure: k5990 
o|contracted procedure: k6044 
o|contracted procedure: k6060 
o|contracted procedure: k6076 
o|contracted procedure: k6098 
o|contracted procedure: k6053 
o|contracted procedure: k6057 
o|contracted procedure: k6094 
o|contracted procedure: k6079 
o|contracted procedure: k6082 
o|contracted procedure: k6090 
o|contracted procedure: k6117 
o|contracted procedure: k6125 
o|contracted procedure: k6131 
o|contracted procedure: k6141 
o|contracted procedure: k6199 
o|contracted procedure: k6154 
o|contracted procedure: k6193 
o|contracted procedure: k6157 
o|contracted procedure: k6187 
o|contracted procedure: k6160 
o|contracted procedure: k6181 
o|contracted procedure: k6163 
o|contracted procedure: k6166 
o|contracted procedure: k6208 
o|contracted procedure: k6235 
o|contracted procedure: k6267 
o|contracted procedure: k6278 
o|contracted procedure: k6287 
o|contracted procedure: k6293 
o|contracted procedure: k6323 
o|contracted procedure: k6333 
o|contracted procedure: k6337 
o|contracted procedure: k6360 
o|contracted procedure: k6363 
o|contracted procedure: k6375 
o|contracted procedure: k6397 
o|contracted procedure: k6393 
o|contracted procedure: k6378 
o|contracted procedure: k6381 
o|contracted procedure: k6389 
o|contracted procedure: k5943 
o|contracted procedure: k6423 
o|contracted procedure: k5853 
o|contracted procedure: k6433 
o|contracted procedure: k6439 
o|contracted procedure: k6457 
o|contracted procedure: k6469 
o|contracted procedure: k6495 
o|contracted procedure: k6491 
o|contracted procedure: k6503 
o|contracted procedure: k6546 
o|contracted procedure: k6578 
o|contracted procedure: k6574 
o|contracted procedure: k6593 
o|contracted procedure: k6589 
o|contracted procedure: k6608 
o|contracted procedure: k6645 
o|contracted procedure: k6758 
o|contracted procedure: k6717 
o|contracted procedure: k6752 
o|contracted procedure: k6720 
o|contracted procedure: k6746 
o|contracted procedure: k6723 
o|contracted procedure: k6740 
o|contracted procedure: k6726 
o|contracted procedure: k6737 
o|contracted procedure: k6733 
o|contracted procedure: k7037 
o|contracted procedure: k7048 
o|contracted procedure: k7174 
o|contracted procedure: k7054 
o|contracted procedure: k7057 
o|contracted procedure: k7068 
o|contracted procedure: k7077 
o|contracted procedure: k7080 
o|contracted procedure: k7095 
o|contracted procedure: k7105 
o|contracted procedure: k7109 
o|contracted procedure: k7123 
o|contracted procedure: k7130 
o|contracted procedure: k7155 
o|contracted procedure: k7161 
o|contracted procedure: k7165 
o|contracted procedure: k7286 
o|contracted procedure: k7282 
o|contracted procedure: k7278 
o|contracted procedure: k7330 
o|contracted procedure: k7334 
o|contracted procedure: k7575 
o|contracted procedure: k7619 
o|contracted procedure: k7338 
o|contracted procedure: k7342 
o|contracted procedure: k7492 
o|contracted procedure: k7497 
o|contracted procedure: k7500 
o|contracted procedure: k7506 
o|contracted procedure: k7513 
o|contracted procedure: k7530 
o|contracted procedure: k7346 
o|contracted procedure: k7358 
o|contracted procedure: k7383 
o|contracted procedure: k7354 
o|contracted procedure: k7326 
o|contracted procedure: k7322 
o|contracted procedure: k7395 
o|contracted procedure: k7417 
o|contracted procedure: k7377 
o|contracted procedure: k7367 
o|contracted procedure: k7371 
o|contracted procedure: k7413 
o|contracted procedure: k7398 
o|contracted procedure: k7401 
o|contracted procedure: k7409 
o|contracted procedure: k7427 
o|contracted procedure: k7443 
o|contracted procedure: k7488 
o|contracted procedure: k7449 
o|contracted procedure: k7457 
o|contracted procedure: k7474 
o|contracted procedure: k7464 
o|contracted procedure: k7542 
o|contracted procedure: k7545 
o|contracted procedure: k7548 
o|contracted procedure: k7556 
o|contracted procedure: k7564 
o|contracted procedure: k7631 
o|contracted procedure: k7634 
o|contracted procedure: k7637 
o|contracted procedure: k7645 
o|contracted procedure: k7653 
o|contracted procedure: k7613 
o|contracted procedure: k7583 
o|contracted procedure: k7590 
o|contracted procedure: k7601 
o|contracted procedure: k7605 
o|contracted procedure: k7672 
o|contracted procedure: k7703 
o|contracted procedure: k7689 
o|contracted procedure: k7696 
o|contracted procedure: k7731 
o|contracted procedure: k7709 
o|contracted procedure: k7724 
o|contracted procedure: k7720 
o|contracted procedure: k7716 
o|contracted procedure: k7183 
o|contracted procedure: k7194 
o|contracted procedure: k7206 
o|contracted procedure: k7228 
o|contracted procedure: k7224 
o|contracted procedure: k7209 
o|contracted procedure: k7212 
o|contracted procedure: k7220 
o|contracted procedure: k4974 
o|contracted procedure: k4977 
o|contracted procedure: k4987 
o|contracted procedure: k7743 
o|contracted procedure: k7749 
o|contracted procedure: k8083 
o|contracted procedure: k7758 
o|contracted procedure: k8077 
o|contracted procedure: k7761 
o|contracted procedure: k8071 
o|contracted procedure: k7764 
o|contracted procedure: k8065 
o|contracted procedure: k7767 
o|contracted procedure: k7802 
o|contracted procedure: k7822 
o|contracted procedure: k7840 
o|contracted procedure: k7848 
o|contracted procedure: k7854 
o|contracted procedure: k7866 
o|contracted procedure: k7874 
o|contracted procedure: k7880 
o|contracted procedure: k7894 
o|contracted procedure: k7890 
o|contracted procedure: k7898 
o|contracted procedure: k7919 
o|contracted procedure: k7929 
o|contracted procedure: k7933 
o|contracted procedure: k7942 
o|contracted procedure: k7952 
o|contracted procedure: k7956 
o|contracted procedure: k7984 
o|contracted procedure: k7959 
o|contracted procedure: k7980 
o|contracted procedure: k7997 
o|contracted procedure: k8019 
o|contracted procedure: k7811 
o|contracted procedure: k8015 
o|contracted procedure: k8000 
o|contracted procedure: k8003 
o|contracted procedure: k8011 
o|contracted procedure: k8031 
o|contracted procedure: k7773 
o|contracted procedure: k7789 
o|contracted procedure: k7779 
o|contracted procedure: k8062 
o|contracted procedure: k8043 
o|contracted procedure: k8050 
o|contracted procedure: k8197 
o|contracted procedure: k8092 
o|contracted procedure: k8109 
o|contracted procedure: k8105 
o|contracted procedure: k8113 
o|contracted procedure: k8137 
o|contracted procedure: k8145 
o|contracted procedure: k8148 
o|contracted procedure: k8157 
o|contracted procedure: k8169 
o|contracted procedure: k8172 
o|contracted procedure: k8175 
o|contracted procedure: k8183 
o|contracted procedure: k8191 
o|contracted procedure: k8212 
o|contracted procedure: k8206 
o|contracted procedure: k8237 
o|contracted procedure: k8287 
o|contracted procedure: k8240 
o|contracted procedure: k8249 
o|contracted procedure: k8276 
o|contracted procedure: k8252 
o|contracted procedure: k8258 
o|contracted procedure: k8290 
o|contracted procedure: k9309 
o|contracted procedure: k8299 
o|contracted procedure: k8354 
o|contracted procedure: k8362 
o|contracted procedure: k8348 
o|contracted procedure: k8465 
o|contracted procedure: k8365 
o|contracted procedure: k8408 
o|contracted procedure: k8461 
o|contracted procedure: k8417 
o|contracted procedure: k8440 
o|contracted procedure: k8568 
o|contracted procedure: k8500 
o|contracted procedure: k8537 
o|contracted procedure: k8549 
o|contracted procedure: k8559 
o|contracted procedure: k8563 
o|contracted procedure: k8577 
o|contracted procedure: k8587 
o|contracted procedure: k8591 
o|contracted procedure: k8597 
o|contracted procedure: k8616 
o|contracted procedure: k8626 
o|contracted procedure: k8630 
o|contracted procedure: k8643 
o|contracted procedure: k8646 
o|contracted procedure: k8694 
o|contracted procedure: k8660 
o|contracted procedure: k8669 
o|contracted procedure: k8688 
o|contracted procedure: k8699 
o|contracted procedure: k8702 
o|contracted procedure: k8714 
o|contracted procedure: k8736 
o|contracted procedure: k8732 
o|contracted procedure: k8717 
o|contracted procedure: k8720 
o|contracted procedure: k8728 
o|contracted procedure: k8839 
o|contracted procedure: k8831 
o|contracted procedure: k8835 
o|contracted procedure: k8845 
o|contracted procedure: k8857 
o|contracted procedure: k8892 
o|contracted procedure: k8915 
o|contracted procedure: k8918 
o|contracted procedure: k8940 
o|contracted procedure: k5871 
o|contracted procedure: k8969 
o|contracted procedure: k8979 
o|contracted procedure: k8983 
o|contracted procedure: k9000 
o|contracted procedure: k9006 
o|contracted procedure: k9014 
o|contracted procedure: k9022 
o|contracted procedure: k8886 
o|contracted procedure: k8865 
o|contracted procedure: k8868 
o|contracted procedure: k6837 
o|contracted procedure: k6849 
o|contracted procedure: k7021 
o|contracted procedure: k6855 
o|contracted procedure: k6867 
o|contracted procedure: k6876 
o|contracted procedure: k6883 
o|contracted procedure: k7013 
o|contracted procedure: k6889 
o|contracted procedure: k6902 
o|contracted procedure: k6924 
o|contracted procedure: k6928 
o|inlining procedure: k6914 
o|inlining procedure: k6914 
o|contracted procedure: k6942 
o|contracted procedure: k6988 
o|contracted procedure: k6953 
o|contracted procedure: k6970 
o|contracted procedure: k6960 
o|contracted procedure: k6984 
o|contracted procedure: k9031 
o|contracted procedure: k9043 
o|contracted procedure: k9053 
o|contracted procedure: k9057 
o|contracted procedure: k9235 
o|contracted procedure: k9061 
o|contracted procedure: k9070 
o|contracted procedure: k9073 
o|contracted procedure: k9229 
o|contracted procedure: k9076 
o|contracted procedure: k9082 
o|contracted procedure: k9093 
o|contracted procedure: k9115 
o|contracted procedure: k9105 
o|contracted procedure: k9127 
o|contracted procedure: k9190 
o|contracted procedure: k9211 
o|contracted procedure: k9222 
o|contracted procedure: k9238 
o|contracted procedure: k9261 
o|contracted procedure: k9267 
o|contracted procedure: k9298 
o|contracted procedure: k9306 
o|contracted procedure: k8762 
o|contracted procedure: k8768 
o|contracted procedure: k8790 
o|contracted procedure: k8780 
o|contracted procedure: k8802 
o|contracted procedure: k9519 
o|contracted procedure: k9538 
o|contracted procedure: k9547 
o|contracted procedure: k9566 
o|contracted procedure: k9569 
o|contracted procedure: k9597 
o|contracted procedure: k9574 
o|contracted procedure: k9586 
o|contracted procedure: k9590 
o|contracted procedure: k9600 
o|contracted procedure: k9612 
o|contracted procedure: k9615 
o|contracted procedure: k9618 
o|contracted procedure: k9626 
o|contracted procedure: k9634 
o|contracted procedure: k9658 
o|contracted procedure: k9708 
o|contracted procedure: k10476 
o|contracted procedure: k9721 
o|contracted procedure: k9727 
o|contracted procedure: k9749 
o|contracted procedure: k9767 
o|contracted procedure: k9775 
o|contracted procedure: k9789 
o|contracted procedure: k9785 
o|contracted procedure: k9798 
o|contracted procedure: k9808 
o|contracted procedure: k9812 
o|contracted procedure: k9873 
o|contracted procedure: k9815 
o|contracted procedure: k9827 
o|contracted procedure: k9831 
o|contracted procedure: k9837 
o|contracted procedure: k9849 
o|contracted procedure: k9853 
o|contracted procedure: k9865 
o|contracted procedure: k9877 
o|contracted procedure: k9899 
o|contracted procedure: k9917 
o|contracted procedure: k9929 
o|contracted procedure: k9937 
o|contracted procedure: k9951 
o|contracted procedure: k9947 
o|contracted procedure: k9960 
o|contracted procedure: k9970 
o|contracted procedure: k9974 
o|contracted procedure: k10015 
o|contracted procedure: k9977 
o|contracted procedure: k9989 
o|contracted procedure: k9997 
o|contracted procedure: k10009 
o|contracted procedure: k10056 
o|contracted procedure: k10018 
o|contracted procedure: k10030 
o|contracted procedure: k10038 
o|contracted procedure: k10050 
o|contracted procedure: k10060 
o|contracted procedure: k10082 
o|contracted procedure: k10100 
o|contracted procedure: k10112 
o|contracted procedure: k10120 
o|contracted procedure: k10123 
o|contracted procedure: k10129 
o|contracted procedure: k10143 
o|contracted procedure: k10139 
o|contracted procedure: k10152 
o|contracted procedure: k10162 
o|contracted procedure: k10166 
o|contracted procedure: k10175 
o|contracted procedure: k10197 
o|contracted procedure: k10193 
o|contracted procedure: k10178 
o|contracted procedure: k10181 
o|contracted procedure: k10189 
o|contracted procedure: k10253 
o|contracted procedure: k10203 
o|contracted procedure: k10215 
o|contracted procedure: k10231 
o|contracted procedure: k10235 
o|contracted procedure: k10227 
o|contracted procedure: k10219 
o|contracted procedure: k10247 
o|contracted procedure: k10306 
o|contracted procedure: k10256 
o|contracted procedure: k10268 
o|contracted procedure: k10284 
o|contracted procedure: k10288 
o|contracted procedure: k10280 
o|contracted procedure: k10272 
o|contracted procedure: k10300 
o|contracted procedure: k10310 
o|contracted procedure: k10332 
o|contracted procedure: k10366 
o|contracted procedure: k10373 
o|contracted procedure: k10377 
o|contracted procedure: k10380 
o|contracted procedure: k10387 
o|contracted procedure: k10390 
o|contracted procedure: k10402 
o|contracted procedure: k10405 
o|contracted procedure: k10408 
o|contracted procedure: k10416 
o|contracted procedure: k10424 
o|contracted procedure: k10436 
o|contracted procedure: k10439 
o|contracted procedure: k10442 
o|contracted procedure: k10450 
o|contracted procedure: k10458 
o|contracted procedure: k10465 
o|contracted procedure: k10502 
o|contracted procedure: k10511 
o|contracted procedure: k10514 
o|contracted procedure: k10526 
o|contracted procedure: k10536 
o|contracted procedure: k10540 
o|contracted procedure: k10563 
o|contracted procedure: k10569 
o|contracted procedure: k10593 
o|contracted procedure: k10589 
o|contracted procedure: k10579 
o|contracted procedure: k10600 
o|contracted procedure: k10608 
o|contracted procedure: k10614 
o|contracted procedure: k10638 
o|contracted procedure: k10632 
o|contracted procedure: k10620 
o|contracted procedure: k10647 
o|contracted procedure: k10701 
o|contracted procedure: k10719 
o|contracted procedure: k10726 
o|contracted procedure: k10738 
o|contracted procedure: k10760 
o|contracted procedure: k10756 
o|contracted procedure: k10741 
o|contracted procedure: k10744 
o|contracted procedure: k10752 
o|contracted procedure: k10772 
o|contracted procedure: k10794 
o|contracted procedure: k10790 
o|contracted procedure: k10775 
o|contracted procedure: k10778 
o|contracted procedure: k10786 
o|contracted procedure: k10904 
o|contracted procedure: k10819 
o|contracted procedure: k10823 
o|contracted procedure: k10830 
o|contracted procedure: k10842 
o|contracted procedure: k10864 
o|contracted procedure: k10860 
o|contracted procedure: k10845 
o|contracted procedure: k10848 
o|contracted procedure: k10856 
o|contracted procedure: k10876 
o|contracted procedure: k10898 
o|contracted procedure: k10894 
o|contracted procedure: k10879 
o|contracted procedure: k10882 
o|contracted procedure: k10890 
o|contracted procedure: k10916 
o|contracted procedure: k10926 
o|contracted procedure: k10930 
o|contracted procedure: k10939 
o|contracted procedure: k10949 
o|contracted procedure: k10953 
o|contracted procedure: k5835 
o|contracted procedure: k10971 
o|contracted procedure: k5817 
o|contracted procedure: k10986 
o|contracted procedure: k11000 
o|contracted procedure: k11004 
o|contracted procedure: k6657 
o|contracted procedure: k6679 
o|contracted procedure: k6675 
o|contracted procedure: k6690 
o|contracted procedure: k6686 
o|contracted procedure: k6700 
o|contracted procedure: k6708 
o|contracted procedure: k11048 
o|contracted procedure: k11056 
o|contracted procedure: k11065 
o|contracted procedure: k11107 
o|contracted procedure: k11113 
o|contracted procedure: k11293 
o|contracted procedure: k11122 
o|contracted procedure: k11137 
o|contracted procedure: k11289 
o|contracted procedure: k11143 
o|contracted procedure: k11149 
o|contracted procedure: k11155 
o|contracted procedure: k11285 
o|contracted procedure: k11170 
o|contracted procedure: k11281 
o|contracted procedure: k11179 
o|contracted procedure: k11196 
o|contracted procedure: k11219 
o|contracted procedure: k11225 
o|contracted procedure: k11232 
o|contracted procedure: k11246 
o|contracted procedure: k11257 
o|contracted procedure: k11275 
o|contracted procedure: k11263 
o|contracted procedure: k11309 
o|contracted procedure: k11305 
o|contracted procedure: k11329 
o|contracted procedure: k11332 
o|contracted procedure: k11344 
o|contracted procedure: k11352 
o|contracted procedure: k11355 
o|contracted procedure: k11348 
o|contracted procedure: k11367 
o|contracted procedure: k11389 
o|contracted procedure: k11385 
o|contracted procedure: k11370 
o|contracted procedure: k11373 
o|contracted procedure: k11381 
o|contracted procedure: k11418 
o|contracted procedure: k11411 
o|contracted procedure: k11407 
o|contracted procedure: k11403 
o|contracted procedure: k11427 
o|contracted procedure: k11439 
o|contracted procedure: k11442 
o|contracted procedure: k11482 
o|contracted procedure: k11448 
o|contracted procedure: k11452 
o|contracted procedure: k11465 
o|contracted procedure: k11488 
o|contracted procedure: k11494 
o|contracted procedure: k11497 
o|contracted procedure: k11501 
o|contracted procedure: k11504 
o|contracted procedure: k11517 
o|contracted procedure: k11529 
o|contracted procedure: k11547 
o|contracted procedure: k11579 
o|contracted procedure: k11552 
o|contracted procedure: k11558 
o|contracted procedure: k11565 
o|contracted procedure: k11585 
o|contracted procedure: k11594 
o|contracted procedure: k11617 
o|contracted procedure: k11630 
o|contracted procedure: k11642 
o|contracted procedure: k11645 
o|contracted procedure: k11648 
o|contracted procedure: k11656 
o|contracted procedure: k11664 
o|contracted procedure: k11676 
o|contracted procedure: k11686 
o|contracted procedure: k11690 
o|contracted procedure: k11807 
o|contracted procedure: k11781 
o|contracted procedure: k11790 
o|contracted procedure: k11800 
o|contracted procedure: k11822 
o|contracted procedure: k11830 
o|contracted procedure: k11842 
o|contracted procedure: k11845 
o|contracted procedure: k11848 
o|contracted procedure: k11856 
o|contracted procedure: k11864 
o|contracted procedure: k11876 
o|contracted procedure: k11884 
o|contracted procedure: k11896 
o|contracted procedure: k11899 
o|contracted procedure: k11902 
o|contracted procedure: k11910 
o|contracted procedure: k11918 
o|contracted procedure: k11930 
o|contracted procedure: k11938 
o|contracted procedure: k11950 
o|contracted procedure: k11953 
o|contracted procedure: k11956 
o|contracted procedure: k11964 
o|contracted procedure: k11972 
o|contracted procedure: k11984 
o|contracted procedure: k11992 
o|contracted procedure: k12004 
o|contracted procedure: k12007 
o|contracted procedure: k12010 
o|contracted procedure: k12018 
o|contracted procedure: k12026 
o|contracted procedure: k12038 
o|contracted procedure: k12046 
o|contracted procedure: k12058 
o|contracted procedure: k12061 
o|contracted procedure: k12064 
o|contracted procedure: k12072 
o|contracted procedure: k12080 
o|contracted procedure: k12092 
o|contracted procedure: k12100 
o|contracted procedure: k12112 
o|contracted procedure: k12115 
o|contracted procedure: k12118 
o|contracted procedure: k12126 
o|contracted procedure: k12134 
o|contracted procedure: k12146 
o|contracted procedure: k12154 
o|contracted procedure: k12166 
o|contracted procedure: k12169 
o|contracted procedure: k12172 
o|contracted procedure: k12180 
o|contracted procedure: k12188 
o|contracted procedure: k12200 
o|contracted procedure: k12208 
o|contracted procedure: k12220 
o|contracted procedure: k12223 
o|contracted procedure: k12226 
o|contracted procedure: k12234 
o|contracted procedure: k12242 
o|contracted procedure: k12254 
o|contracted procedure: k12262 
o|contracted procedure: k12274 
o|contracted procedure: k12277 
o|contracted procedure: k12280 
o|contracted procedure: k12288 
o|contracted procedure: k12296 
o|contracted procedure: k12308 
o|contracted procedure: k12316 
o|contracted procedure: k12328 
o|contracted procedure: k12331 
o|contracted procedure: k12334 
o|contracted procedure: k12342 
o|contracted procedure: k12350 
o|contracted procedure: k12362 
o|contracted procedure: k12370 
o|contracted procedure: k12382 
o|contracted procedure: k12385 
o|contracted procedure: k12388 
o|contracted procedure: k12396 
o|contracted procedure: k12404 
o|contracted procedure: k12416 
o|contracted procedure: k12424 
o|contracted procedure: k12436 
o|contracted procedure: k12439 
o|contracted procedure: k12442 
o|contracted procedure: k12450 
o|contracted procedure: k12458 
o|contracted procedure: k12470 
o|contracted procedure: k12478 
o|contracted procedure: k12490 
o|contracted procedure: k12493 
o|contracted procedure: k12496 
o|contracted procedure: k12504 
o|contracted procedure: k12512 
o|simplifications: ((if . 4) (let . 238)) 
o|removed binding forms: 705 
o|inlining procedure: "(modules.scm:124) module-sexports" 
o|inlining procedure: "(modules.scm:123) module-vexports" 
o|inlining procedure: "(modules.scm:122) module-export-list" 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest997999 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest997999 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest997999 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest997999 0 
o|inlining procedure: "(modules.scm:165) module-saved-environments" 
o|inlining procedure: "(modules.scm:162) set-module-saved-environments!" 
o|inlining procedure: "(modules.scm:184) set-module-exist-list!" 
o|inlining procedure: "(modules.scm:183) set-module-sexports!" 
o|inlining procedure: "(modules.scm:183) module-sexports" 
o|inlining procedure: "(modules.scm:174) module-exist-list" 
o|inlining procedure: "(modules.scm:185) set-module-export-list!" 
o|inlining procedure: "(modules.scm:172) module-export-list" 
o|inlining procedure: "(modules.scm:188) module-rename-list" 
o|inlining procedure: "(modules.scm:196) module-meta-expressions" 
o|inlining procedure: "(modules.scm:217) set-module-defined-list!" 
o|inlining procedure: "(modules.scm:220) module-defined-list" 
o|inlining procedure: "(modules.scm:214) set-module-exist-list!" 
o|inlining procedure: "(modules.scm:214) module-exist-list" 
o|inlining procedure: "(modules.scm:210) module-name" 
o|inlining procedure: "(modules.scm:206) module-export-list" 
o|inlining procedure: "(modules.scm:237) set-module-defined-syntax-list!" 
o|inlining procedure: "(modules.scm:239) module-defined-syntax-list" 
o|inlining procedure: "(modules.scm:233) set-module-defined-list!" 
o|inlining procedure: "(modules.scm:236) module-defined-list" 
o|inlining procedure: "(modules.scm:227) module-name" 
o|inlining procedure: "(modules.scm:224) module-export-list" 
o|inlining procedure: "(modules.scm:243) set-module-defined-syntax-list!" 
o|inlining procedure: "(modules.scm:245) module-defined-syntax-list" 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest11741178 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest11741178 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest11741178 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest11741178 0 
o|inlining procedure: "(modules.scm:383) module-rename-list" 
o|inlining procedure: "(modules.scm:373) module-defined-syntax-list" 
o|inlining procedure: "(modules.scm:359) module-vexports" 
o|inlining procedure: "(modules.scm:358) module-iexports" 
o|inlining procedure: "(modules.scm:352) module-library" 
o|inlining procedure: "(modules.scm:351) module-name" 
o|inlining procedure: "(modules.scm:348) module-meta-expressions" 
o|inlining procedure: "(modules.scm:326) module-import-forms" 
o|inlining procedure: "(modules.scm:335) module-meta-import-forms" 
o|inlining procedure: "(modules.scm:334) module-sexports" 
o|inlining procedure: "(modules.scm:333) module-import-forms" 
o|inlining procedure: "(modules.scm:332) module-name" 
o|inlining procedure: "(modules.scm:331) module-defined-list" 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest14731479 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest14731479 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest14731479 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest14731479 0 
o|inlining procedure: "(modules.scm:427) set-module-saved-environments!" 
o|contracted procedure: k7962 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest15841588 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest15841588 0 
o|inlining procedure: "(modules.scm:448) set-module-saved-environments!" 
o|inlining procedure: "(modules.scm:452) module-sexports" 
o|inlining procedure: "(modules.scm:451) module-vexports" 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest16321635 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest16321635 0 
o|inlining procedure: "(modules.scm:464) module-exist-list" 
o|inlining procedure: "(modules.scm:463) module-export-list" 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest16691671 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest16691671 0 
o|inlining procedure: "(modules.scm:485) module-name" 
o|inlining procedure: "(modules.scm:639) set-module-saved-environments!" 
o|inlining procedure: "(modules.scm:636) set-module-iexports!" 
o|inlining procedure: "(modules.scm:638) module-iexports" 
o|inlining procedure: "(modules.scm:635) set-module-sexports!" 
o|inlining procedure: "(modules.scm:267) module-defined-list" 
o|inlining procedure: "(modules.scm:266) module-name" 
o|inlining procedure: "(modules.scm:265) module-export-list" 
o|contracted procedure: k9121 
o|contracted procedure: k9150 
o|inlining procedure: "(modules.scm:553) module-sexports" 
o|inlining procedure: "(modules.scm:538) module-defined-syntax-list" 
o|inlining procedure: "(modules.scm:548) module-exist-list" 
o|inlining procedure: "(modules.scm:547) module-defined-list" 
o|inlining procedure: "(modules.scm:546) module-name" 
o|inlining procedure: "(modules.scm:545) module-export-list" 
o|inlining procedure: "(modules.scm:687) module-rename-list" 
o|inlining procedure: "(modules.scm:708) module-iexports" 
o|inlining procedure: "(modules.scm:707) module-sexports" 
o|inlining procedure: "(modules.scm:706) module-vexports" 
o|inlining procedure: "(modules.scm:705) module-name" 
o|inlining procedure: "(modules.scm:704) module-library" 
o|inlining procedure: "(modules.scm:703) module-name" 
o|inlining procedure: "(modules.scm:858) set-module-iexports!" 
o|inlining procedure: "(modules.scm:860) module-iexports" 
o|inlining procedure: "(modules.scm:845) set-module-exist-list!" 
o|inlining procedure: "(modules.scm:847) module-exist-list" 
o|inlining procedure: "(modules.scm:844) set-module-sexports!" 
o|inlining procedure: "(modules.scm:844) module-sexports" 
o|inlining procedure: "(modules.scm:851) set-module-export-list!" 
o|inlining procedure: "(modules.scm:854) module-export-list" 
o|inlining procedure: "(modules.scm:842) module-export-list" 
o|inlining procedure: "(modules.scm:815) module-meta-import-forms" 
o|inlining procedure: "(modules.scm:818) module-import-forms" 
o|inlining procedure: "(modules.scm:879) module-name" 
o|inlining procedure: "(modules.scm:879) module-name" 
o|inlining procedure: k6704 
o|inlining procedure: k6704 
o|inlining procedure: "(modules.scm:879) module-name" 
o|contracted procedure: k11202 
o|inlining procedure: "(modules.scm:979) module-sexports" 
o|inlining procedure: "(modules.scm:978) module-vexports" 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest35113513 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest35113513 0 
o|inlining procedure: "(modules.scm:1233) module-saved-environments" 
o|removed binding forms: 5 
o|removed side-effect free assignment to unused variable: module-library 
o|removed side-effect free assignment to unused variable: module-export-list 
o|removed side-effect free assignment to unused variable: set-module-export-list! 
o|removed side-effect free assignment to unused variable: module-defined-list 
o|removed side-effect free assignment to unused variable: set-module-defined-list! 
o|removed side-effect free assignment to unused variable: module-exist-list 
o|removed side-effect free assignment to unused variable: set-module-exist-list! 
o|removed side-effect free assignment to unused variable: module-defined-syntax-list 
o|removed side-effect free assignment to unused variable: set-module-defined-syntax-list! 
o|removed side-effect free assignment to unused variable: module-import-forms 
o|removed side-effect free assignment to unused variable: module-meta-import-forms 
o|removed side-effect free assignment to unused variable: module-meta-expressions 
o|removed side-effect free assignment to unused variable: module-vexports 
o|removed side-effect free assignment to unused variable: module-sexports 
o|removed side-effect free assignment to unused variable: set-module-sexports! 
o|removed side-effect free assignment to unused variable: module-iexports 
o|removed side-effect free assignment to unused variable: set-module-iexports! 
o|removed side-effect free assignment to unused variable: module-saved-environments 
o|removed side-effect free assignment to unused variable: set-module-saved-environments! 
o|removed side-effect free assignment to unused variable: module-rename-list 
(o x)|known list op on rest arg sublist: ##core#rest-null? r6158 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r6158 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r6158 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r6158 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r6721 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r6721 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r6721 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r6721 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7762 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r7762 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r7762 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r7762 1 
o|replaced variables: 270 
o|removed binding forms: 1 
o|inlining procedure: k5965 
o|inlining procedure: k6314 
o|inlining procedure: k6530 
o|inlining procedure: k7683 
o|inlining procedure: k7253 
o|inlining procedure: k8133 
o|inlining procedure: k8743 
o|inlining procedure: k8960 
o|inlining procedure: k9245 
o|inlining procedure: k9688 
o|inlining procedure: k9692 
o|inlining procedure: k9696 
o|inlining procedure: k10698 
o|inlining procedure: k10805 
o|inlining procedure: k10967 
o|inlining procedure: k10982 
o|inlining procedure: k11031 
o|inlining procedure: k1103113251 
o|inlining procedure: k1103113255 
o|inlining procedure: k11572 
o|inlining procedure: k11804 
o|removed binding forms: 212 
o|contracted procedure: k5957 
o|contracted procedure: k5961 
o|contracted procedure: k6261 
o|contracted procedure: k6270 
o|contracted procedure: k6350 
o|contracted procedure: k6427 
o|contracted procedure: k6537 
o|contracted procedure: k6499 
o|contracted procedure: k6507 
o|contracted procedure: k6618 
o|contracted procedure: k6555 
o|contracted procedure: k6582 
o|contracted procedure: k6597 
o|contracted procedure: k6635 
o|contracted procedure: k7259 
o|contracted procedure: k7262 
o|contracted procedure: k7265 
o|contracted procedure: k7268 
o|contracted procedure: k7271 
o|contracted procedure: k7664 
o|contracted procedure: k7660 
o|contracted procedure: k7616 
o|contracted procedure: k7571 
o|contracted procedure: k7380 
o|contracted procedure: k7434 
o|contracted procedure: k8129 
o|contracted procedure: k8221 
o|contracted procedure: k8805 
o|contracted procedure: k8808 
o|contracted procedure: k8811 
o|contracted procedure: k8814 
o|contracted procedure: k6767 
o|contracted procedure: k6770 
o|contracted procedure: k6773 
o|contracted procedure: k8753 
o|contracted procedure: k9560 
o|contracted procedure: k9668 
o|contracted procedure: k9672 
o|contracted procedure: k9676 
o|contracted procedure: k10681 
o|contracted procedure: k10715 
o|contracted procedure: k10816 
o|contracted procedure: k11576 
o|simplifications: ((let . 14)) 
o|removed binding forms: 64 
o|direct leaf routine/allocation: g349350 3 
o|direct leaf routine/allocation: make-module 17 
o|direct leaf routine/allocation: g10591060 3 
o|direct leaf routine/allocation: loop1646 0 
o|direct leaf routine/allocation: g19581965 3 
o|direct leaf routine/allocation: g21742175 3 
o|direct leaf routine/allocation: g34813490 0 
o|direct leaf routine/allocation: g34433452 0 
o|direct leaf routine/allocation: g34053414 0 
o|direct leaf routine/allocation: g33673376 0 
o|direct leaf routine/allocation: g33293338 0 
o|direct leaf routine/allocation: g32913300 0 
o|direct leaf routine/allocation: g32533262 0 
o|direct leaf routine/allocation: g32153224 0 
o|direct leaf routine/allocation: g31773186 0 
o|direct leaf routine/allocation: g31393148 0 
o|direct leaf routine/allocation: g31013110 0 
o|direct leaf routine/allocation: g30633072 0 
o|direct leaf routine/allocation: g30253034 0 
o|contracted procedure: "(modules.scm:260) k6729" 
o|contracted procedure: "(modules.scm:410) k7828" 
o|contracted procedure: "(modules.scm:436) k8098" 
o|converted assignments to bindings: (loop1646) 
o|contracted procedure: "(modules.scm:602) k9046" 
o|contracted procedure: "(modules.scm:1136) k11860" 
o|contracted procedure: "(modules.scm:1136) k11914" 
o|contracted procedure: "(modules.scm:1136) k11968" 
o|contracted procedure: "(modules.scm:1136) k12022" 
o|contracted procedure: "(modules.scm:1136) k12076" 
o|contracted procedure: "(modules.scm:1136) k12130" 
o|contracted procedure: "(modules.scm:1136) k12184" 
o|contracted procedure: "(modules.scm:1136) k12238" 
o|contracted procedure: "(modules.scm:1136) k12292" 
o|contracted procedure: "(modules.scm:1136) k12346" 
o|contracted procedure: "(modules.scm:1136) k12400" 
o|contracted procedure: "(modules.scm:1136) k12454" 
o|contracted procedure: "(modules.scm:1136) k12508" 
o|simplifications: ((let . 1)) 
o|removed binding forms: 17 
o|direct leaf routine with hoistable closures/allocation: g10431050 (g10591060) 3 
o|contracted procedure: "(modules.scm:177) k6326" 
o|removed binding forms: 2 
x|eliminated type checks:
x|  C_i_check_list_2:	13
o|customizable procedures: (map-loop30193044 map-loop30573082 map-loop30953120 map-loop31333158 map-loop31713196 map-loop32093234 map-loop32473272 map-loop32853310 map-loop33233348 map-loop33613386 map-loop33993424 map-loop34373462 map-loop34753500 g29612968 for-each-loop29602975 map-loop29823000 k11561 loop2924 merr2897 match-functor-argument loop22931 map-loop29002917 err2889 loop22860 loop2848 iface2838 err2837 g28222823 mrename2803 g28112812 g11661167 k6668 g26192636 for-each-loop26182647 g26292652 for-each-loop26282662 map-loop27282745 map-loop27542771 map-loop26742691 map-loop27002717 k10653 g25582565 for-each-loop25572592 map-loop24892506 rename2482 map-loop25152532 tostr2135 g24492450 loopv2377 g24442445 loops2386 map-loop24102427 g23982405 for-each-loop23972434 g23442345 loopv2298 g23392340 loops2307 g23192326 for-each-loop23182329 g22652266 g22612262 loop2228 g22412248 for-each-loop22402251 warn2134 outer2189 module-imports2185 find-module/import-library export-rename2136 g21562165 map-loop21502177 loop1901 loop1915 g19481949 id-string1940 fail1939 loop1923 for-each-loop19571968 report-unresolved-identifiers1678 g12311232 g12241225 warn1197 loop21215 loop1209 k9003 map-loop19772002 g20132022 for-each-loop20122029 map-loop17231740 lp1699 g16881747 for-each-loop16871892 g17561767 for-each-loop17551831 g18661873 for-each-loop18651882 g17831784 ln->num1770 k8228 g16041613 map-loop15981619 map-loop15031521 g15361553 for-each-loop15351559 g15461564 for-each-loop15451570 merge-se k7737 filter-map loop299 map-loop12971318 k7302 k7310 k7649 map-loop13551379 g13941403 map-loop13881421 loop1428 k7350 map-loop14411462 lp1278 g12621269 for-each-loop12611272 loop1248 find-export module-rename delete check-for-redef map-loop10751092 for-each-loop10421062 g10261027 k6217 g988989 loop979 map-loop944962 foldr334337 g339340 loop279) 
o|calls to known targets: 327 
o|identified direct recursive calls: f_5061 1 
o|identified direct recursive calls: f_6071 1 
o|unused rest argument: rest997999 f_6152 
o|identified direct recursive calls: f_6318 1 
o|identified direct recursive calls: f_6370 1 
o|unused rest argument: rest11741178 f_6715 
o|identified direct recursive calls: f_7043 1 
o|identified direct recursive calls: f_7390 1 
o|identified direct recursive calls: f_7438 1 
o|identified direct recursive calls: f_7201 1 
o|unused rest argument: rest14731479 f_7756 
o|unused rest argument: rest15841588 f_8090 
o|unused rest argument: rest16321635 f_8204 
o|identified direct recursive calls: f_8232 3 
o|unused rest argument: _1677 f_9312 
o|identified direct recursive calls: f_8638 2 
o|identified direct recursive calls: f_8709 1 
o|identified direct recursive calls: f_6844 1 
o|identified direct recursive calls: f_9038 1 
o|unused rest argument: rest16691671 f_8297 
o|identified direct recursive calls: f_9762 1 
o|identified direct recursive calls: f_9924 1 
o|identified direct recursive calls: f_9912 1 
o|identified direct recursive calls: f_10170 1 
o|identified direct recursive calls: f_10107 1 
o|identified direct recursive calls: f_10095 1 
o|identified direct recursive calls: f_10733 1 
o|identified direct recursive calls: f_10767 1 
o|identified direct recursive calls: f_10837 1 
o|identified direct recursive calls: f_10871 1 
o|identified direct recursive calls: f_11241 1 
o|identified direct recursive calls: f_11132 2 
o|identified direct recursive calls: f_11362 1 
o|unused rest argument: rest35113513 f_11779 
o|identified direct recursive calls: f_11837 1 
o|identified direct recursive calls: f_11891 1 
o|identified direct recursive calls: f_11945 1 
o|identified direct recursive calls: f_11999 1 
o|identified direct recursive calls: f_12053 1 
o|identified direct recursive calls: f_12107 1 
o|identified direct recursive calls: f_12161 1 
o|identified direct recursive calls: f_12215 1 
o|identified direct recursive calls: f_12269 1 
o|identified direct recursive calls: f_12323 1 
o|identified direct recursive calls: f_12377 1 
o|identified direct recursive calls: f_12431 1 
o|identified direct recursive calls: f_12485 1 
o|fast box initializations: 79 
o|fast global references: 44 
o|fast global assignments: 10 
o|dropping unused closure argument: f_10990 
o|dropping unused closure argument: f_11539 
o|dropping unused closure argument: f_4888 
o|dropping unused closure argument: f_5052 
o|dropping unused closure argument: f_5969 
o|dropping unused closure argument: f_6431 
o|dropping unused closure argument: f_7025 
o|dropping unused closure argument: f_8219 
o|dropping unused closure argument: f_8340 
o|dropping unused closure argument: f_9470 
o|dropping unused closure argument: f_9500 
o|dropping unused closure argument: f_9558 
*/
/* end of file */
