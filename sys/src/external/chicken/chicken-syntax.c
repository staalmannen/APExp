/* Generated from chicken-syntax.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: chicken-syntax.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file chicken-syntax.c
   unit: chicken-syntax
   uses: internal expand library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_internal_toplevel)
C_externimport void C_ccall C_internal_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_expand_toplevel)
C_externimport void C_ccall C_expand_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[285];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,12),40,116,97,107,101,32,108,115,116,32,110,41,0,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,16),40,97,53,54,57,55,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,16),40,97,53,55,52,54,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,13),40,97,53,56,51,53,32,120,32,114,32,99,41,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,16),40,97,53,56,53,51,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,27),40,108,111,111,112,32,120,115,32,118,97,114,115,32,98,115,32,118,97,108,115,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,16),40,97,53,57,49,56,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,24),40,108,111,111,112,32,120,115,32,118,97,114,115,32,118,97,108,115,32,114,101,115,116,41};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,16),40,97,54,49,49,51,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,13),40,103,51,48,52,56,32,118,110,97,109,101,41,0,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,7),40,103,51,48,55,52,41,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,14),40,108,111,111,112,32,115,108,111,116,115,32,105,41,0,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,48,54,56,32,103,51,48,56,48,41,0,0,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,51,48,52,55,32,103,51,48,53,52,41,0,0,0,0,0,0,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,48,50,49,32,103,51,48,51,51,41,0,0,0,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,16),40,97,54,50,56,53,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,16),40,97,54,55,50,52,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,11),40,103,101,110,118,97,114,115,32,110,41,0,0,0,0,0};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,18),40,108,111,111,112,32,110,32,112,114,101,118,32,110,111,100,101,41,0,0,0,0,0,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,7),40,97,54,57,54,56,41,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,50,57,52,52,32,103,50,57,53,54,32,103,50,57,53,55,41,0,0,0,0,0,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,19),40,98,117,105,108,100,32,118,97,114,115,50,32,118,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,19),40,97,54,57,55,56,32,118,97,114,115,49,32,118,97,114,115,50,41,0,0,0,0,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,22),40,97,54,57,52,56,32,118,97,114,115,32,97,114,103,99,32,114,101,115,116,41,0,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,14),40,103,50,57,48,49,32,99,32,98,111,100,121,41,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,17),40,102,111,108,100,114,50,56,57,54,32,103,50,56,57,55,41,0,0,0,0,0,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,22),40,97,55,50,49,48,32,118,97,114,115,32,97,114,103,99,32,114,101,115,116,41,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,56,53,51,32,103,50,56,54,53,41,0,0,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,16),40,97,54,56,52,48,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,19),40,108,111,111,112,32,97,114,103,115,32,118,97,114,100,101,102,115,41,0,0,0,0,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,16),40,97,55,50,56,52,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,16),40,97,55,52,52,52,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,36),40,114,101,99,117,114,32,118,97,114,115,32,100,101,102,97,117,108,116,101,114,115,32,110,111,110,45,100,101,102,97,117,108,116,115,41,0,0,0,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,45),40,109,97,107,101,45,105,102,45,116,114,101,101,32,118,97,114,115,32,100,101,102,97,117,108,116,101,114,115,32,98,111,100,121,45,112,114,111,99,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,23),40,112,114,101,102,105,120,45,115,121,109,32,112,114,101,102,105,120,32,115,121,109,41,0};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,9),40,103,50,55,48,54,32,118,41,0,0,0,0,0,0,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,11),40,103,50,55,54,51,32,118,97,114,41,0,0,0,0,0};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,42),40,114,101,99,117,114,32,118,97,114,115,32,100,101,102,97,117,108,116,101,114,45,110,97,109,101,115,32,100,101,102,115,32,110,101,120,116,45,103,117,121,41,0,0,0,0,0,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,55,53,55,32,103,50,55,54,57,41,0,0,0,0};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,55,50,56,32,103,50,55,52,48,41,0,0,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,55,48,48,32,103,50,55,49,50,41,0,0,0,0};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,54,55,48,32,103,50,54,56,50,41,0,0,0,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,16),40,97,55,53,50,49,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,14),40,102,111,108,100,32,98,115,32,108,97,115,116,41,0,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,16),40,97,55,57,54,57,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,24),40,113,117,111,116,105,102,121,45,112,114,111,99,50,53,55,48,32,120,115,32,105,100,41};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,16),40,97,56,49,49,49,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,16),40,97,56,50,49,53,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,13),40,97,56,50,53,57,32,120,32,114,32,99,41,0,0,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,50,53,49,56,32,103,50,53,51,48,32,103,50,53,51,49,41,0,0,0,0,0,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,52,55,48,32,103,50,52,56,50,41,0,0,0,0};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,13),40,97,56,52,53,55,32,97,32,95,32,95,41,0,0,0};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,23),40,102,111,108,100,108,50,52,57,51,32,103,50,52,57,52,32,103,50,52,57,50,41,0};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,52,52,49,32,103,50,52,53,51,41,0,0,0,0};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,52,49,53,32,103,50,52,50,55,41,0,0,0,0};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,16),40,97,56,50,56,49,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li57[] C_aligned={C_lihdr(0,0,16),40,102,111,108,100,32,118,98,105,110,100,105,110,103,115,41};
static C_char C_TLS li58[] C_aligned={C_lihdr(0,0,16),40,97,56,53,51,57,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li59[] C_aligned={C_lihdr(0,0,18),40,97,112,112,101,110,100,42,50,50,50,49,32,105,108,32,108,41,0,0,0,0,0,0};
static C_char C_TLS li60[] C_aligned={C_lihdr(0,0,17),40,109,97,112,42,50,50,50,50,32,112,114,111,99,32,108,41,0,0,0,0,0,0,0};
static C_char C_TLS li61[] C_aligned={C_lihdr(0,0,9),40,103,50,50,56,50,32,118,41,0,0,0,0,0,0,0};
static C_char C_TLS li62[] C_aligned={C_lihdr(0,0,10),40,108,111,111,107,117,112,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li63[] C_aligned={C_lihdr(0,0,9),40,103,50,51,51,51,32,118,41,0,0,0,0,0,0,0};
static C_char C_TLS li64[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,51,50,55,32,103,50,51,51,57,41,0,0,0,0};
static C_char C_TLS li65[] C_aligned={C_lihdr(0,0,26),40,102,111,108,100,32,108,108,105,115,116,115,32,101,120,112,115,32,108,108,105,115,116,115,50,41,0,0,0,0,0,0};
static C_char C_TLS li66[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,51,54,50,32,103,50,51,55,52,41,0,0,0,0};
static C_char C_TLS li67[] C_aligned={C_lihdr(0,0,17),40,108,111,111,112,32,108,108,105,115,116,115,32,97,99,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li68[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,50,55,54,32,103,50,50,56,56,41,0,0,0,0};
static C_char C_TLS li69[] C_aligned={C_lihdr(0,0,17),40,108,111,111,112,32,108,108,105,115,116,115,32,97,99,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li70[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,50,51,56,32,103,50,50,53,48,41,0,0,0,0};
static C_char C_TLS li71[] C_aligned={C_lihdr(0,0,16),40,97,56,53,57,51,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li72[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,49,55,55,32,103,50,49,56,57,41,0,0,0,0};
static C_char C_TLS li73[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,49,54,55,32,103,50,49,55,52,41,0,0,0,0,0,0,0};
static C_char C_TLS li74[] C_aligned={C_lihdr(0,0,22),40,97,57,49,48,55,32,118,97,114,115,32,97,114,103,99,32,114,101,115,116,41,0,0};
static C_char C_TLS li75[] C_aligned={C_lihdr(0,0,16),40,97,57,48,55,48,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li76[] C_aligned={C_lihdr(0,0,16),40,97,57,50,48,48,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li77[] C_aligned={C_lihdr(0,0,16),40,97,57,50,50,49,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li78[] C_aligned={C_lihdr(0,0,16),40,97,57,50,52,57,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li79[] C_aligned={C_lihdr(0,0,7),40,97,57,50,56,56,41,0};
static C_char C_TLS li80[] C_aligned={C_lihdr(0,0,48),40,97,57,50,57,52,32,110,97,109,101,50,49,48,52,32,108,105,98,50,49,48,54,32,95,50,49,48,56,32,95,50,49,48,56,32,95,50,49,48,56,32,95,50,49,48,56,41};
static C_char C_TLS li81[] C_aligned={C_lihdr(0,0,9),40,103,50,48,57,50,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li82[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,48,56,54,32,103,50,48,57,56,41,0,0,0,0};
static C_char C_TLS li83[] C_aligned={C_lihdr(0,0,13),40,97,57,50,55,51,32,120,32,114,32,99,41,0,0,0};
static C_char C_TLS li84[] C_aligned={C_lihdr(0,0,9),40,103,49,54,55,55,32,122,41,0,0,0,0,0,0,0};
static C_char C_TLS li85[] C_aligned={C_lihdr(0,0,7),40,103,49,55,48,53,41,0};
static C_char C_TLS li86[] C_aligned={C_lihdr(0,0,7),40,103,49,55,51,51,41,0};
static C_char C_TLS li87[] C_aligned={C_lihdr(0,0,14),40,103,49,56,53,54,32,115,32,116,101,109,112,41,0,0};
static C_char C_TLS li88[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,50,48,52,50,32,103,50,48,53,52,32,103,50,48,53,53,41,0,0,0,0,0,0};
static C_char C_TLS li89[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,50,48,48,54,32,103,50,48,49,56,32,103,50,48,49,57,41,0,0,0,0,0,0};
static C_char C_TLS li90[] C_aligned={C_lihdr(0,0,32),40,109,97,112,45,108,111,111,112,49,57,54,52,32,103,49,57,55,54,32,103,49,57,55,55,32,103,49,57,55,56,41};
static C_char C_TLS li91[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,49,57,50,56,32,103,49,57,52,48,32,103,49,57,52,49,41,0,0,0,0,0,0};
static C_char C_TLS li92[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,49,56,57,50,32,103,49,57,48,52,32,103,49,57,48,53,41,0,0,0,0,0,0};
static C_char C_TLS li93[] C_aligned={C_lihdr(0,0,32),40,109,97,112,45,108,111,111,112,49,56,53,48,32,103,49,56,54,50,32,103,49,56,54,51,32,103,49,56,54,52,41};
static C_char C_TLS li94[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,49,56,49,57,32,103,49,56,51,49,32,103,49,56,51,50,41,0,0,0,0,0,0};
static C_char C_TLS li95[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,49,55,56,56,32,103,49,56,48,48,32,103,49,56,48,49,41,0,0,0,0,0,0};
static C_char C_TLS li96[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,49,55,53,55,32,103,49,55,54,57,32,103,49,55,55,48,41,0,0,0,0,0,0};
static C_char C_TLS li97[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,55,50,55,32,103,49,55,51,57,41,0,0,0,0};
static C_char C_TLS li98[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,54,57,57,32,103,49,55,49,49,41,0,0,0,0};
static C_char C_TLS li99[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,54,55,49,32,103,49,54,56,51,41,0,0,0,0};
static C_char C_TLS li100[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,54,52,52,32,103,49,54,53,54,41,0,0,0,0};
static C_char C_TLS li101[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,54,49,55,32,103,49,54,50,57,41,0,0,0,0};
static C_char C_TLS li102[] C_aligned={C_lihdr(0,0,16),40,97,57,51,53,51,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li103[] C_aligned={C_lihdr(0,0,7),40,103,49,51,50,48,41,0};
static C_char C_TLS li104[] C_aligned={C_lihdr(0,0,7),40,103,49,51,52,56,41,0};
static C_char C_TLS li105[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,49,53,55,49,32,103,49,53,56,51,32,103,49,53,56,52,41,0,0,0,0,0,0};
static C_char C_TLS li106[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,49,53,51,53,32,103,49,53,52,55,32,103,49,53,52,56,41,0,0,0,0,0,0};
static C_char C_TLS li107[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,49,52,57,57,32,103,49,53,49,49,32,103,49,53,49,50,41,0,0,0,0,0,0};
static C_char C_TLS li108[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,49,52,54,51,32,103,49,52,55,53,32,103,49,52,55,54,41,0,0,0,0,0,0};
static C_char C_TLS li109[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,49,52,50,57,32,103,49,52,52,49,32,103,49,52,52,50,41,0,0,0,0,0,0};
static C_char C_TLS li110[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,110,41};
static C_char C_TLS li111[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,49,51,55,50,32,103,49,51,56,52,32,103,49,51,56,53,41,0,0,0,0,0,0};
static C_char C_TLS li112[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,51,57,51,32,103,49,52,48,53,41,0,0,0,0};
static C_char C_TLS li113[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,51,52,50,32,103,49,51,53,52,41,0,0,0,0};
static C_char C_TLS li114[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,51,49,52,32,103,49,51,50,54,41,0,0,0,0};
static C_char C_TLS li115[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,50,56,55,32,103,49,50,57,57,41,0,0,0,0};
static C_char C_TLS li116[] C_aligned={C_lihdr(0,0,17),40,97,49,48,50,56,51,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li117[] C_aligned={C_lihdr(0,0,17),40,97,49,48,57,51,54,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li118[] C_aligned={C_lihdr(0,0,17),40,97,49,48,57,53,51,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li119[] C_aligned={C_lihdr(0,0,17),40,97,49,48,57,55,48,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li120[] C_aligned={C_lihdr(0,0,17),40,97,49,48,57,57,49,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li121[] C_aligned={C_lihdr(0,0,17),40,97,49,49,48,48,53,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li122[] C_aligned={C_lihdr(0,0,12),40,103,49,49,55,52,32,115,108,111,116,41,0,0,0,0};
static C_char C_TLS li123[] C_aligned={C_lihdr(0,0,18),40,109,97,112,115,108,111,116,115,32,115,108,111,116,115,32,105,41,0,0,0,0,0,0};
static C_char C_TLS li124[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,49,54,56,32,103,49,49,56,48,41,0,0,0,0};
static C_char C_TLS li125[] C_aligned={C_lihdr(0,0,14),40,97,49,49,48,57,56,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li126[] C_aligned={C_lihdr(0,0,17),40,97,49,49,52,57,51,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li127[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,49,48,57,57,32,108,32,108,101,110,41};
static C_char C_TLS li128[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,49,48,57,57,32,108,32,108,101,110,41};
static C_char C_TLS li129[] C_aligned={C_lihdr(0,0,29),40,97,49,49,53,49,48,32,105,110,112,117,116,32,114,101,110,97,109,101,32,99,111,109,112,97,114,101,41,0,0,0};
static C_char C_TLS li130[] C_aligned={C_lihdr(0,0,29),40,97,49,49,54,53,56,32,105,110,112,117,116,32,114,101,110,97,109,101,32,99,111,109,112,97,114,101,41,0,0,0};
static C_char C_TLS li131[] C_aligned={C_lihdr(0,0,17),40,97,49,49,55,53,53,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li132[] C_aligned={C_lihdr(0,0,14),40,97,49,49,55,56,52,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li133[] C_aligned={C_lihdr(0,0,14),40,97,49,49,56,49,52,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li134[] C_aligned={C_lihdr(0,0,14),40,97,49,49,56,51,49,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li135[] C_aligned={C_lihdr(0,0,13),40,103,57,56,53,32,99,108,97,117,115,101,41,0,0,0};
static C_char C_TLS li136[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,57,55,57,32,103,57,57,49,41,0,0,0,0,0,0};
static C_char C_TLS li137[] C_aligned={C_lihdr(0,0,14),40,97,49,49,56,57,49,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li138[] C_aligned={C_lihdr(0,0,23),40,109,97,112,45,108,111,111,112,57,50,53,32,103,57,51,55,32,103,57,51,56,41,0};
static C_char C_TLS li139[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,56,57,49,32,103,57,48,51,41,0,0,0,0,0,0};
static C_char C_TLS li140[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,50,32,97,110,97,109,101,115,32,105,41};
static C_char C_TLS li141[] C_aligned={C_lihdr(0,0,25),40,108,111,111,112,32,97,114,103,115,32,97,110,97,109,101,115,32,97,116,121,112,101,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li142[] C_aligned={C_lihdr(0,0,14),40,97,49,50,48,49,52,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li143[] C_aligned={C_lihdr(0,0,17),40,97,49,50,52,51,50,32,116,121,112,101,32,118,97,114,41,0,0,0,0,0,0,0};
static C_char C_TLS li144[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,56,50,52,32,103,56,51,54,41,0,0,0,0,0,0};
static C_char C_TLS li145[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,55,57,54,32,103,56,48,56,41,0,0,0,0,0,0};
static C_char C_TLS li146[] C_aligned={C_lihdr(0,0,15),40,108,111,111,112,55,52,56,32,108,32,108,101,110,41,0};
static C_char C_TLS li147[] C_aligned={C_lihdr(0,0,15),40,108,111,111,112,55,52,56,32,108,32,108,101,110,41,0};
static C_char C_TLS li148[] C_aligned={C_lihdr(0,0,29),40,97,49,50,51,54,52,32,105,110,112,117,116,32,114,101,110,97,109,101,32,99,111,109,112,97,114,101,41,0,0,0};
static C_char C_TLS li149[] C_aligned={C_lihdr(0,0,14),40,97,49,50,54,55,51,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li150[] C_aligned={C_lihdr(0,0,8),40,97,49,50,55,51,49,41};
static C_char C_TLS li151[] C_aligned={C_lihdr(0,0,32),40,97,49,50,55,52,49,32,116,121,112,101,55,48,53,32,112,114,101,100,55,48,55,32,112,117,114,101,55,48,57,41};
static C_char C_TLS li152[] C_aligned={C_lihdr(0,0,14),40,97,49,50,55,49,49,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li153[] C_aligned={C_lihdr(0,0,6),40,103,54,51,55,41,0,0};
static C_char C_TLS li154[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,54,51,49,32,103,54,52,51,41,0,0,0,0,0,0};
static C_char C_TLS li155[] C_aligned={C_lihdr(0,0,16),40,112,97,114,115,101,45,99,108,97,117,115,101,32,99,41};
static C_char C_TLS li156[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,54,54,50,32,103,54,55,52,41,0,0,0,0,0,0};
static C_char C_TLS li157[] C_aligned={C_lihdr(0,0,17),40,97,49,50,56,50,50,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li158[] C_aligned={C_lihdr(0,0,17),40,97,49,51,48,57,53,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li159[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_10014)
static void C_fcall f_10014(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10062)
static void C_fcall f_10062(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10110)
static void C_fcall f_10110(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10135)
static void C_ccall f_10135(C_word c,C_word *av) C_noret;
C_noret_decl(f_10144)
static void C_fcall f_10144(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10169)
static void C_ccall f_10169(C_word c,C_word *av) C_noret;
C_noret_decl(f_10178)
static void C_fcall f_10178(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10203)
static void C_ccall f_10203(C_word c,C_word *av) C_noret;
C_noret_decl(f_10212)
static void C_fcall f_10212(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10246)
static void C_fcall f_10246(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10282)
static void C_ccall f_10282(C_word c,C_word *av) C_noret;
C_noret_decl(f_10284)
static void C_ccall f_10284(C_word c,C_word *av) C_noret;
C_noret_decl(f_10288)
static void C_ccall f_10288(C_word c,C_word *av) C_noret;
C_noret_decl(f_10302)
static void C_ccall f_10302(C_word c,C_word *av) C_noret;
C_noret_decl(f_10306)
static void C_fcall f_10306(C_word t0,C_word t1) C_noret;
C_noret_decl(f_10314)
static void C_ccall f_10314(C_word c,C_word *av) C_noret;
C_noret_decl(f_10317)
static void C_ccall f_10317(C_word c,C_word *av) C_noret;
C_noret_decl(f_10321)
static void C_fcall f_10321(C_word t0,C_word t1) C_noret;
C_noret_decl(f_10329)
static void C_ccall f_10329(C_word c,C_word *av) C_noret;
C_noret_decl(f_10332)
static void C_ccall f_10332(C_word c,C_word *av) C_noret;
C_noret_decl(f_10339)
static void C_ccall f_10339(C_word c,C_word *av) C_noret;
C_noret_decl(f_10363)
static void C_ccall f_10363(C_word c,C_word *av) C_noret;
C_noret_decl(f_10375)
static void C_ccall f_10375(C_word c,C_word *av) C_noret;
C_noret_decl(f_10379)
static void C_ccall f_10379(C_word c,C_word *av) C_noret;
C_noret_decl(f_10391)
static void C_ccall f_10391(C_word c,C_word *av) C_noret;
C_noret_decl(f_10401)
static void C_fcall f_10401(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10449)
static void C_fcall f_10449(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10507)
static void C_ccall f_10507(C_word c,C_word *av) C_noret;
C_noret_decl(f_10522)
static void C_ccall f_10522(C_word c,C_word *av) C_noret;
C_noret_decl(f_10526)
static void C_ccall f_10526(C_word c,C_word *av) C_noret;
C_noret_decl(f_10538)
static void C_ccall f_10538(C_word c,C_word *av) C_noret;
C_noret_decl(f_10548)
static void C_fcall f_10548(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10596)
static void C_fcall f_10596(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10652)
static void C_ccall f_10652(C_word c,C_word *av) C_noret;
C_noret_decl(f_10661)
static void C_ccall f_10661(C_word c,C_word *av) C_noret;
C_noret_decl(f_10668)
static void C_ccall f_10668(C_word c,C_word *av) C_noret;
C_noret_decl(f_10677)
static void C_ccall f_10677(C_word c,C_word *av) C_noret;
C_noret_decl(f_10679)
static void C_fcall f_10679(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10729)
static void C_fcall f_10729(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10743)
static void C_ccall f_10743(C_word c,C_word *av) C_noret;
C_noret_decl(f_10749)
static void C_fcall f_10749(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10797)
static void C_fcall f_10797(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10831)
static void C_fcall f_10831(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10856)
static void C_ccall f_10856(C_word c,C_word *av) C_noret;
C_noret_decl(f_10865)
static void C_fcall f_10865(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10890)
static void C_ccall f_10890(C_word c,C_word *av) C_noret;
C_noret_decl(f_10899)
static void C_fcall f_10899(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10935)
static void C_ccall f_10935(C_word c,C_word *av) C_noret;
C_noret_decl(f_10937)
static void C_ccall f_10937(C_word c,C_word *av) C_noret;
C_noret_decl(f_10941)
static void C_ccall f_10941(C_word c,C_word *av) C_noret;
C_noret_decl(f_10952)
static void C_ccall f_10952(C_word c,C_word *av) C_noret;
C_noret_decl(f_10954)
static void C_ccall f_10954(C_word c,C_word *av) C_noret;
C_noret_decl(f_10958)
static void C_ccall f_10958(C_word c,C_word *av) C_noret;
C_noret_decl(f_10969)
static void C_ccall f_10969(C_word c,C_word *av) C_noret;
C_noret_decl(f_10971)
static void C_ccall f_10971(C_word c,C_word *av) C_noret;
C_noret_decl(f_10975)
static void C_ccall f_10975(C_word c,C_word *av) C_noret;
C_noret_decl(f_10990)
static void C_ccall f_10990(C_word c,C_word *av) C_noret;
C_noret_decl(f_10992)
static void C_ccall f_10992(C_word c,C_word *av) C_noret;
C_noret_decl(f_11004)
static void C_ccall f_11004(C_word c,C_word *av) C_noret;
C_noret_decl(f_11006)
static void C_ccall f_11006(C_word c,C_word *av) C_noret;
C_noret_decl(f_11010)
static void C_ccall f_11010(C_word c,C_word *av) C_noret;
C_noret_decl(f_11032)
static void C_ccall f_11032(C_word c,C_word *av) C_noret;
C_noret_decl(f_11097)
static void C_ccall f_11097(C_word c,C_word *av) C_noret;
C_noret_decl(f_11099)
static void C_ccall f_11099(C_word c,C_word *av) C_noret;
C_noret_decl(f_11103)
static void C_ccall f_11103(C_word c,C_word *av) C_noret;
C_noret_decl(f_11109)
static void C_ccall f_11109(C_word c,C_word *av) C_noret;
C_noret_decl(f_11112)
static void C_ccall f_11112(C_word c,C_word *av) C_noret;
C_noret_decl(f_11115)
static void C_ccall f_11115(C_word c,C_word *av) C_noret;
C_noret_decl(f_11121)
static void C_ccall f_11121(C_word c,C_word *av) C_noret;
C_noret_decl(f_11124)
static void C_ccall f_11124(C_word c,C_word *av) C_noret;
C_noret_decl(f_11127)
static void C_ccall f_11127(C_word c,C_word *av) C_noret;
C_noret_decl(f_11131)
static void C_fcall f_11131(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11144)
static void C_fcall f_11144(C_word t0,C_word t1) C_noret;
C_noret_decl(f_11159)
static void C_ccall f_11159(C_word c,C_word *av) C_noret;
C_noret_decl(f_11191)
static void C_ccall f_11191(C_word c,C_word *av) C_noret;
C_noret_decl(f_11222)
static void C_ccall f_11222(C_word c,C_word *av) C_noret;
C_noret_decl(f_11224)
static void C_fcall f_11224(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_11240)
static void C_ccall f_11240(C_word c,C_word *av) C_noret;
C_noret_decl(f_11243)
static void C_ccall f_11243(C_word c,C_word *av) C_noret;
C_noret_decl(f_11246)
static void C_ccall f_11246(C_word c,C_word *av) C_noret;
C_noret_decl(f_11260)
static void C_ccall f_11260(C_word c,C_word *av) C_noret;
C_noret_decl(f_11272)
static void C_ccall f_11272(C_word c,C_word *av) C_noret;
C_noret_decl(f_11276)
static void C_fcall f_11276(C_word t0,C_word t1) C_noret;
C_noret_decl(f_11369)
static void C_ccall f_11369(C_word c,C_word *av) C_noret;
C_noret_decl(f_11373)
static void C_ccall f_11373(C_word c,C_word *av) C_noret;
C_noret_decl(f_11388)
static void C_ccall f_11388(C_word c,C_word *av) C_noret;
C_noret_decl(f_11408)
static void C_ccall f_11408(C_word c,C_word *av) C_noret;
C_noret_decl(f_11414)
static void C_ccall f_11414(C_word c,C_word *av) C_noret;
C_noret_decl(f_11434)
static void C_ccall f_11434(C_word c,C_word *av) C_noret;
C_noret_decl(f_11442)
static void C_fcall f_11442(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11467)
static void C_ccall f_11467(C_word c,C_word *av) C_noret;
C_noret_decl(f_11477)
static void C_ccall f_11477(C_word c,C_word *av) C_noret;
C_noret_decl(f_11484)
static void C_ccall f_11484(C_word c,C_word *av) C_noret;
C_noret_decl(f_11488)
static void C_ccall f_11488(C_word c,C_word *av) C_noret;
C_noret_decl(f_11492)
static void C_ccall f_11492(C_word c,C_word *av) C_noret;
C_noret_decl(f_11494)
static void C_ccall f_11494(C_word c,C_word *av) C_noret;
C_noret_decl(f_11498)
static void C_ccall f_11498(C_word c,C_word *av) C_noret;
C_noret_decl(f_11509)
static void C_ccall f_11509(C_word c,C_word *av) C_noret;
C_noret_decl(f_11511)
static void C_ccall f_11511(C_word c,C_word *av) C_noret;
C_noret_decl(f_11521)
static void C_ccall f_11521(C_word c,C_word *av) C_noret;
C_noret_decl(f_11534)
static void C_ccall f_11534(C_word c,C_word *av) C_noret;
C_noret_decl(f_11550)
static void C_ccall f_11550(C_word c,C_word *av) C_noret;
C_noret_decl(f_11556)
static void C_ccall f_11556(C_word c,C_word *av) C_noret;
C_noret_decl(f_11559)
static void C_ccall f_11559(C_word c,C_word *av) C_noret;
C_noret_decl(f_11565)
static void C_ccall f_11565(C_word c,C_word *av) C_noret;
C_noret_decl(f_11574)
static void C_fcall f_11574(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_11581)
static void C_ccall f_11581(C_word c,C_word *av) C_noret;
C_noret_decl(f_11595)
static void C_ccall f_11595(C_word c,C_word *av) C_noret;
C_noret_decl(f_11606)
static void C_ccall f_11606(C_word c,C_word *av) C_noret;
C_noret_decl(f_11609)
static void C_ccall f_11609(C_word c,C_word *av) C_noret;
C_noret_decl(f_11615)
static void C_ccall f_11615(C_word c,C_word *av) C_noret;
C_noret_decl(f_11624)
static void C_fcall f_11624(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_11631)
static void C_ccall f_11631(C_word c,C_word *av) C_noret;
C_noret_decl(f_11645)
static void C_ccall f_11645(C_word c,C_word *av) C_noret;
C_noret_decl(f_11657)
static void C_ccall f_11657(C_word c,C_word *av) C_noret;
C_noret_decl(f_11659)
static void C_ccall f_11659(C_word c,C_word *av) C_noret;
C_noret_decl(f_11679)
static void C_ccall f_11679(C_word c,C_word *av) C_noret;
C_noret_decl(f_11693)
static void C_fcall f_11693(C_word t0,C_word t1) C_noret;
C_noret_decl(f_11706)
static void C_ccall f_11706(C_word c,C_word *av) C_noret;
C_noret_decl(f_11754)
static void C_ccall f_11754(C_word c,C_word *av) C_noret;
C_noret_decl(f_11756)
static void C_ccall f_11756(C_word c,C_word *av) C_noret;
C_noret_decl(f_11760)
static void C_ccall f_11760(C_word c,C_word *av) C_noret;
C_noret_decl(f_11767)
static void C_ccall f_11767(C_word c,C_word *av) C_noret;
C_noret_decl(f_11775)
static void C_ccall f_11775(C_word c,C_word *av) C_noret;
C_noret_decl(f_11783)
static void C_ccall f_11783(C_word c,C_word *av) C_noret;
C_noret_decl(f_11785)
static void C_ccall f_11785(C_word c,C_word *av) C_noret;
C_noret_decl(f_11789)
static void C_ccall f_11789(C_word c,C_word *av) C_noret;
C_noret_decl(f_11792)
static void C_ccall f_11792(C_word c,C_word *av) C_noret;
C_noret_decl(f_11813)
static void C_ccall f_11813(C_word c,C_word *av) C_noret;
C_noret_decl(f_11815)
static void C_ccall f_11815(C_word c,C_word *av) C_noret;
C_noret_decl(f_11819)
static void C_ccall f_11819(C_word c,C_word *av) C_noret;
C_noret_decl(f_11830)
static void C_ccall f_11830(C_word c,C_word *av) C_noret;
C_noret_decl(f_11832)
static void C_ccall f_11832(C_word c,C_word *av) C_noret;
C_noret_decl(f_11836)
static void C_ccall f_11836(C_word c,C_word *av) C_noret;
C_noret_decl(f_11845)
static void C_ccall f_11845(C_word c,C_word *av) C_noret;
C_noret_decl(f_11848)
static void C_ccall f_11848(C_word c,C_word *av) C_noret;
C_noret_decl(f_11851)
static void C_ccall f_11851(C_word c,C_word *av) C_noret;
C_noret_decl(f_11874)
static void C_ccall f_11874(C_word c,C_word *av) C_noret;
C_noret_decl(f_11890)
static void C_ccall f_11890(C_word c,C_word *av) C_noret;
C_noret_decl(f_11892)
static void C_ccall f_11892(C_word c,C_word *av) C_noret;
C_noret_decl(f_11896)
static void C_ccall f_11896(C_word c,C_word *av) C_noret;
C_noret_decl(f_11902)
static void C_ccall f_11902(C_word c,C_word *av) C_noret;
C_noret_decl(f_11905)
static void C_ccall f_11905(C_word c,C_word *av) C_noret;
C_noret_decl(f_11929)
static void C_fcall f_11929(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11933)
static void C_ccall f_11933(C_word c,C_word *av) C_noret;
C_noret_decl(f_11940)
static void C_ccall f_11940(C_word c,C_word *av) C_noret;
C_noret_decl(f_11967)
static void C_ccall f_11967(C_word c,C_word *av) C_noret;
C_noret_decl(f_11969)
static void C_fcall f_11969(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11994)
static void C_ccall f_11994(C_word c,C_word *av) C_noret;
C_noret_decl(f_12013)
static void C_ccall f_12013(C_word c,C_word *av) C_noret;
C_noret_decl(f_12015)
static void C_ccall f_12015(C_word c,C_word *av) C_noret;
C_noret_decl(f_12025)
static void C_ccall f_12025(C_word c,C_word *av) C_noret;
C_noret_decl(f_12035)
static void C_ccall f_12035(C_word c,C_word *av) C_noret;
C_noret_decl(f_12038)
static void C_ccall f_12038(C_word c,C_word *av) C_noret;
C_noret_decl(f_12041)
static void C_ccall f_12041(C_word c,C_word *av) C_noret;
C_noret_decl(f_12049)
static void C_fcall f_12049(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_12059)
static void C_ccall f_12059(C_word c,C_word *av) C_noret;
C_noret_decl(f_12062)
static void C_ccall f_12062(C_word c,C_word *av) C_noret;
C_noret_decl(f_12104)
static void C_ccall f_12104(C_word c,C_word *av) C_noret;
C_noret_decl(f_12106)
static void C_fcall f_12106(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_12168)
static void C_fcall f_12168(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12189)
static void C_ccall f_12189(C_word c,C_word *av) C_noret;
C_noret_decl(f_12191)
static void C_fcall f_12191(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12216)
static void C_ccall f_12216(C_word c,C_word *av) C_noret;
C_noret_decl(f_12233)
static void C_ccall f_12233(C_word c,C_word *av) C_noret;
C_noret_decl(f_12235)
static void C_fcall f_12235(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_12253)
static void C_ccall f_12253(C_word c,C_word *av) C_noret;
C_noret_decl(f_12289)
static void C_fcall f_12289(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12306)
static void C_ccall f_12306(C_word c,C_word *av) C_noret;
C_noret_decl(f_12363)
static void C_ccall f_12363(C_word c,C_word *av) C_noret;
C_noret_decl(f_12365)
static void C_ccall f_12365(C_word c,C_word *av) C_noret;
C_noret_decl(f_12375)
static void C_ccall f_12375(C_word c,C_word *av) C_noret;
C_noret_decl(f_12392)
static void C_ccall f_12392(C_word c,C_word *av) C_noret;
C_noret_decl(f_12413)
static void C_ccall f_12413(C_word c,C_word *av) C_noret;
C_noret_decl(f_12423)
static void C_ccall f_12423(C_word c,C_word *av) C_noret;
C_noret_decl(f_12431)
static void C_ccall f_12431(C_word c,C_word *av) C_noret;
C_noret_decl(f_12433)
static void C_ccall f_12433(C_word c,C_word *av) C_noret;
C_noret_decl(f_12449)
static void C_ccall f_12449(C_word c,C_word *av) C_noret;
C_noret_decl(f_12459)
static void C_fcall f_12459(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12493)
static void C_fcall f_12493(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12537)
static void C_ccall f_12537(C_word c,C_word *av) C_noret;
C_noret_decl(f_12543)
static void C_ccall f_12543(C_word c,C_word *av) C_noret;
C_noret_decl(f_12546)
static void C_ccall f_12546(C_word c,C_word *av) C_noret;
C_noret_decl(f_12552)
static void C_ccall f_12552(C_word c,C_word *av) C_noret;
C_noret_decl(f_12561)
static void C_fcall f_12561(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_12568)
static void C_ccall f_12568(C_word c,C_word *av) C_noret;
C_noret_decl(f_12582)
static void C_ccall f_12582(C_word c,C_word *av) C_noret;
C_noret_decl(f_12593)
static void C_ccall f_12593(C_word c,C_word *av) C_noret;
C_noret_decl(f_12596)
static void C_ccall f_12596(C_word c,C_word *av) C_noret;
C_noret_decl(f_12602)
static void C_ccall f_12602(C_word c,C_word *av) C_noret;
C_noret_decl(f_12611)
static void C_fcall f_12611(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_12618)
static void C_ccall f_12618(C_word c,C_word *av) C_noret;
C_noret_decl(f_12630)
static void C_fcall f_12630(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12641)
static void C_ccall f_12641(C_word c,C_word *av) C_noret;
C_noret_decl(f_12672)
static void C_ccall f_12672(C_word c,C_word *av) C_noret;
C_noret_decl(f_12674)
static void C_ccall f_12674(C_word c,C_word *av) C_noret;
C_noret_decl(f_12678)
static void C_ccall f_12678(C_word c,C_word *av) C_noret;
C_noret_decl(f_12694)
static void C_ccall f_12694(C_word c,C_word *av) C_noret;
C_noret_decl(f_12710)
static void C_ccall f_12710(C_word c,C_word *av) C_noret;
C_noret_decl(f_12712)
static void C_ccall f_12712(C_word c,C_word *av) C_noret;
C_noret_decl(f_12716)
static void C_ccall f_12716(C_word c,C_word *av) C_noret;
C_noret_decl(f_12725)
static void C_ccall f_12725(C_word c,C_word *av) C_noret;
C_noret_decl(f_12732)
static void C_ccall f_12732(C_word c,C_word *av) C_noret;
C_noret_decl(f_12740)
static void C_ccall f_12740(C_word c,C_word *av) C_noret;
C_noret_decl(f_12742)
static void C_ccall f_12742(C_word c,C_word *av) C_noret;
C_noret_decl(f_12767)
static void C_ccall f_12767(C_word c,C_word *av) C_noret;
C_noret_decl(f_12771)
static void C_fcall f_12771(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12821)
static void C_ccall f_12821(C_word c,C_word *av) C_noret;
C_noret_decl(f_12823)
static void C_ccall f_12823(C_word c,C_word *av) C_noret;
C_noret_decl(f_12827)
static void C_ccall f_12827(C_word c,C_word *av) C_noret;
C_noret_decl(f_12830)
static void C_ccall f_12830(C_word c,C_word *av) C_noret;
C_noret_decl(f_12833)
static void C_ccall f_12833(C_word c,C_word *av) C_noret;
C_noret_decl(f_12836)
static void C_ccall f_12836(C_word c,C_word *av) C_noret;
C_noret_decl(f_12839)
static void C_ccall f_12839(C_word c,C_word *av) C_noret;
C_noret_decl(f_12842)
static void C_ccall f_12842(C_word c,C_word *av) C_noret;
C_noret_decl(f_12844)
static void C_fcall f_12844(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12854)
static void C_fcall f_12854(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12879)
static C_word C_fcall f_12879(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_12893)
static void C_ccall f_12893(C_word c,C_word *av) C_noret;
C_noret_decl(f_12895)
static void C_fcall f_12895(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12974)
static void C_ccall f_12974(C_word c,C_word *av) C_noret;
C_noret_decl(f_12999)
static void C_ccall f_12999(C_word c,C_word *av) C_noret;
C_noret_decl(f_13006)
static void C_ccall f_13006(C_word c,C_word *av) C_noret;
C_noret_decl(f_13010)
static void C_ccall f_13010(C_word c,C_word *av) C_noret;
C_noret_decl(f_13030)
static void C_fcall f_13030(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_13055)
static void C_ccall f_13055(C_word c,C_word *av) C_noret;
C_noret_decl(f_13094)
static void C_ccall f_13094(C_word c,C_word *av) C_noret;
C_noret_decl(f_13096)
static void C_ccall f_13096(C_word c,C_word *av) C_noret;
C_noret_decl(f_13100)
static void C_ccall f_13100(C_word c,C_word *av) C_noret;
C_noret_decl(f_13103)
static void C_ccall f_13103(C_word c,C_word *av) C_noret;
C_noret_decl(f_13106)
static void C_ccall f_13106(C_word c,C_word *av) C_noret;
C_noret_decl(f_13117)
static void C_ccall f_13117(C_word c,C_word *av) C_noret;
C_noret_decl(f_4231)
static void C_ccall f_4231(C_word c,C_word *av) C_noret;
C_noret_decl(f_4234)
static void C_ccall f_4234(C_word c,C_word *av) C_noret;
C_noret_decl(f_4237)
static void C_ccall f_4237(C_word c,C_word *av) C_noret;
C_noret_decl(f_4347)
static void C_fcall f_4347(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4365)
static void C_ccall f_4365(C_word c,C_word *av) C_noret;
C_noret_decl(f_4405)
static void C_fcall f_4405(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_4419)
static void C_ccall f_4419(C_word c,C_word *av) C_noret;
C_noret_decl(f_5519)
static void C_ccall f_5519(C_word c,C_word *av) C_noret;
C_noret_decl(f_5522)
static void C_ccall f_5522(C_word c,C_word *av) C_noret;
C_noret_decl(f_5525)
static void C_ccall f_5525(C_word c,C_word *av) C_noret;
C_noret_decl(f_5528)
static void C_ccall f_5528(C_word c,C_word *av) C_noret;
C_noret_decl(f_5532)
static void C_ccall f_5532(C_word c,C_word *av) C_noret;
C_noret_decl(f_5535)
static void C_ccall f_5535(C_word c,C_word *av) C_noret;
C_noret_decl(f_5538)
static void C_ccall f_5538(C_word c,C_word *av) C_noret;
C_noret_decl(f_5541)
static void C_ccall f_5541(C_word c,C_word *av) C_noret;
C_noret_decl(f_5544)
static void C_ccall f_5544(C_word c,C_word *av) C_noret;
C_noret_decl(f_5547)
static void C_ccall f_5547(C_word c,C_word *av) C_noret;
C_noret_decl(f_5550)
static void C_ccall f_5550(C_word c,C_word *av) C_noret;
C_noret_decl(f_5553)
static void C_ccall f_5553(C_word c,C_word *av) C_noret;
C_noret_decl(f_5557)
static void C_ccall f_5557(C_word c,C_word *av) C_noret;
C_noret_decl(f_5560)
static void C_ccall f_5560(C_word c,C_word *av) C_noret;
C_noret_decl(f_5563)
static void C_ccall f_5563(C_word c,C_word *av) C_noret;
C_noret_decl(f_5566)
static void C_ccall f_5566(C_word c,C_word *av) C_noret;
C_noret_decl(f_5569)
static void C_ccall f_5569(C_word c,C_word *av) C_noret;
C_noret_decl(f_5572)
static void C_ccall f_5572(C_word c,C_word *av) C_noret;
C_noret_decl(f_5575)
static void C_ccall f_5575(C_word c,C_word *av) C_noret;
C_noret_decl(f_5579)
static void C_ccall f_5579(C_word c,C_word *av) C_noret;
C_noret_decl(f_5582)
static void C_ccall f_5582(C_word c,C_word *av) C_noret;
C_noret_decl(f_5585)
static void C_ccall f_5585(C_word c,C_word *av) C_noret;
C_noret_decl(f_5588)
static void C_ccall f_5588(C_word c,C_word *av) C_noret;
C_noret_decl(f_5591)
static void C_ccall f_5591(C_word c,C_word *av) C_noret;
C_noret_decl(f_5594)
static void C_ccall f_5594(C_word c,C_word *av) C_noret;
C_noret_decl(f_5597)
static void C_ccall f_5597(C_word c,C_word *av) C_noret;
C_noret_decl(f_5600)
static void C_ccall f_5600(C_word c,C_word *av) C_noret;
C_noret_decl(f_5603)
static void C_ccall f_5603(C_word c,C_word *av) C_noret;
C_noret_decl(f_5606)
static void C_ccall f_5606(C_word c,C_word *av) C_noret;
C_noret_decl(f_5609)
static void C_ccall f_5609(C_word c,C_word *av) C_noret;
C_noret_decl(f_5612)
static void C_ccall f_5612(C_word c,C_word *av) C_noret;
C_noret_decl(f_5615)
static void C_ccall f_5615(C_word c,C_word *av) C_noret;
C_noret_decl(f_5618)
static void C_ccall f_5618(C_word c,C_word *av) C_noret;
C_noret_decl(f_5622)
static void C_ccall f_5622(C_word c,C_word *av) C_noret;
C_noret_decl(f_5625)
static void C_ccall f_5625(C_word c,C_word *av) C_noret;
C_noret_decl(f_5628)
static void C_ccall f_5628(C_word c,C_word *av) C_noret;
C_noret_decl(f_5631)
static void C_ccall f_5631(C_word c,C_word *av) C_noret;
C_noret_decl(f_5634)
static void C_ccall f_5634(C_word c,C_word *av) C_noret;
C_noret_decl(f_5637)
static void C_ccall f_5637(C_word c,C_word *av) C_noret;
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
C_noret_decl(f_5655)
static void C_ccall f_5655(C_word c,C_word *av) C_noret;
C_noret_decl(f_5658)
static void C_ccall f_5658(C_word c,C_word *av) C_noret;
C_noret_decl(f_5661)
static void C_ccall f_5661(C_word c,C_word *av) C_noret;
C_noret_decl(f_5664)
static void C_ccall f_5664(C_word c,C_word *av) C_noret;
C_noret_decl(f_5667)
static void C_ccall f_5667(C_word c,C_word *av) C_noret;
C_noret_decl(f_5670)
static void C_ccall f_5670(C_word c,C_word *av) C_noret;
C_noret_decl(f_5673)
static void C_ccall f_5673(C_word c,C_word *av) C_noret;
C_noret_decl(f_5676)
static void C_ccall f_5676(C_word c,C_word *av) C_noret;
C_noret_decl(f_5679)
static void C_ccall f_5679(C_word c,C_word *av) C_noret;
C_noret_decl(f_5683)
static void C_ccall f_5683(C_word c,C_word *av) C_noret;
C_noret_decl(f_5686)
static void C_ccall f_5686(C_word c,C_word *av) C_noret;
C_noret_decl(f_5689)
static void C_ccall f_5689(C_word c,C_word *av) C_noret;
C_noret_decl(f_5692)
static void C_ccall f_5692(C_word c,C_word *av) C_noret;
C_noret_decl(f_5696)
static void C_ccall f_5696(C_word c,C_word *av) C_noret;
C_noret_decl(f_5698)
static void C_ccall f_5698(C_word c,C_word *av) C_noret;
C_noret_decl(f_5702)
static void C_ccall f_5702(C_word c,C_word *av) C_noret;
C_noret_decl(f_5745)
static void C_ccall f_5745(C_word c,C_word *av) C_noret;
C_noret_decl(f_5747)
static void C_ccall f_5747(C_word c,C_word *av) C_noret;
C_noret_decl(f_5751)
static void C_ccall f_5751(C_word c,C_word *av) C_noret;
C_noret_decl(f_5762)
static void C_ccall f_5762(C_word c,C_word *av) C_noret;
C_noret_decl(f_5765)
static void C_fcall f_5765(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5788)
static void C_fcall f_5788(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5807)
static void C_ccall f_5807(C_word c,C_word *av) C_noret;
C_noret_decl(f_5817)
static void C_ccall f_5817(C_word c,C_word *av) C_noret;
C_noret_decl(f_5824)
static void C_ccall f_5824(C_word c,C_word *av) C_noret;
C_noret_decl(f_5834)
static void C_ccall f_5834(C_word c,C_word *av) C_noret;
C_noret_decl(f_5836)
static void C_ccall f_5836(C_word c,C_word *av) C_noret;
C_noret_decl(f_5844)
static void C_ccall f_5844(C_word c,C_word *av) C_noret;
C_noret_decl(f_5852)
static void C_ccall f_5852(C_word c,C_word *av) C_noret;
C_noret_decl(f_5854)
static void C_ccall f_5854(C_word c,C_word *av) C_noret;
C_noret_decl(f_5858)
static void C_ccall f_5858(C_word c,C_word *av) C_noret;
C_noret_decl(f_5917)
static void C_ccall f_5917(C_word c,C_word *av) C_noret;
C_noret_decl(f_5919)
static void C_ccall f_5919(C_word c,C_word *av) C_noret;
C_noret_decl(f_5923)
static void C_ccall f_5923(C_word c,C_word *av) C_noret;
C_noret_decl(f_5926)
static void C_ccall f_5926(C_word c,C_word *av) C_noret;
C_noret_decl(f_5929)
static void C_ccall f_5929(C_word c,C_word *av) C_noret;
C_noret_decl(f_5932)
static void C_ccall f_5932(C_word c,C_word *av) C_noret;
C_noret_decl(f_5939)
static void C_fcall f_5939(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_5949)
static void C_ccall f_5949(C_word c,C_word *av) C_noret;
C_noret_decl(f_5952)
static void C_ccall f_5952(C_word c,C_word *av) C_noret;
C_noret_decl(f_5958)
static void C_ccall f_5958(C_word c,C_word *av) C_noret;
C_noret_decl(f_5969)
static void C_ccall f_5969(C_word c,C_word *av) C_noret;
C_noret_decl(f_5985)
static void C_ccall f_5985(C_word c,C_word *av) C_noret;
C_noret_decl(f_5995)
static void C_ccall f_5995(C_word c,C_word *av) C_noret;
C_noret_decl(f_6018)
static void C_ccall f_6018(C_word c,C_word *av) C_noret;
C_noret_decl(f_6021)
static void C_ccall f_6021(C_word c,C_word *av) C_noret;
C_noret_decl(f_6038)
static void C_ccall f_6038(C_word c,C_word *av) C_noret;
C_noret_decl(f_6044)
static void C_ccall f_6044(C_word c,C_word *av) C_noret;
C_noret_decl(f_6061)
static void C_ccall f_6061(C_word c,C_word *av) C_noret;
C_noret_decl(f_6084)
static void C_ccall f_6084(C_word c,C_word *av) C_noret;
C_noret_decl(f_6112)
static void C_ccall f_6112(C_word c,C_word *av) C_noret;
C_noret_decl(f_6114)
static void C_ccall f_6114(C_word c,C_word *av) C_noret;
C_noret_decl(f_6118)
static void C_ccall f_6118(C_word c,C_word *av) C_noret;
C_noret_decl(f_6121)
static void C_ccall f_6121(C_word c,C_word *av) C_noret;
C_noret_decl(f_6124)
static void C_ccall f_6124(C_word c,C_word *av) C_noret;
C_noret_decl(f_6127)
static void C_ccall f_6127(C_word c,C_word *av) C_noret;
C_noret_decl(f_6134)
static void C_fcall f_6134(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_6144)
static void C_ccall f_6144(C_word c,C_word *av) C_noret;
C_noret_decl(f_6147)
static void C_ccall f_6147(C_word c,C_word *av) C_noret;
C_noret_decl(f_6153)
static void C_ccall f_6153(C_word c,C_word *av) C_noret;
C_noret_decl(f_6160)
static void C_ccall f_6160(C_word c,C_word *av) C_noret;
C_noret_decl(f_6176)
static void C_ccall f_6176(C_word c,C_word *av) C_noret;
C_noret_decl(f_6186)
static void C_ccall f_6186(C_word c,C_word *av) C_noret;
C_noret_decl(f_6209)
static void C_ccall f_6209(C_word c,C_word *av) C_noret;
C_noret_decl(f_6212)
static void C_ccall f_6212(C_word c,C_word *av) C_noret;
C_noret_decl(f_6229)
static void C_ccall f_6229(C_word c,C_word *av) C_noret;
C_noret_decl(f_6235)
static void C_ccall f_6235(C_word c,C_word *av) C_noret;
C_noret_decl(f_6284)
static void C_ccall f_6284(C_word c,C_word *av) C_noret;
C_noret_decl(f_6286)
static void C_ccall f_6286(C_word c,C_word *av) C_noret;
C_noret_decl(f_6290)
static void C_ccall f_6290(C_word c,C_word *av) C_noret;
C_noret_decl(f_6296)
static void C_ccall f_6296(C_word c,C_word *av) C_noret;
C_noret_decl(f_6299)
static void C_ccall f_6299(C_word c,C_word *av) C_noret;
C_noret_decl(f_6311)
static void C_ccall f_6311(C_word c,C_word *av) C_noret;
C_noret_decl(f_6314)
static void C_ccall f_6314(C_word c,C_word *av) C_noret;
C_noret_decl(f_6320)
static void C_ccall f_6320(C_word c,C_word *av) C_noret;
C_noret_decl(f_6323)
static void C_ccall f_6323(C_word c,C_word *av) C_noret;
C_noret_decl(f_6332)
static void C_ccall f_6332(C_word c,C_word *av) C_noret;
C_noret_decl(f_6333)
static void C_fcall f_6333(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6349)
static void C_ccall f_6349(C_word c,C_word *av) C_noret;
C_noret_decl(f_6380)
static void C_ccall f_6380(C_word c,C_word *av) C_noret;
C_noret_decl(f_6382)
static void C_fcall f_6382(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6401)
static void C_fcall f_6401(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6407)
static void C_fcall f_6407(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6414)
static void C_fcall f_6414(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6418)
static void C_ccall f_6418(C_word c,C_word *av) C_noret;
C_noret_decl(f_6422)
static void C_fcall f_6422(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6426)
static void C_ccall f_6426(C_word c,C_word *av) C_noret;
C_noret_decl(f_6454)
static void C_ccall f_6454(C_word c,C_word *av) C_noret;
C_noret_decl(f_6475)
static void C_ccall f_6475(C_word c,C_word *av) C_noret;
C_noret_decl(f_6554)
static void C_ccall f_6554(C_word c,C_word *av) C_noret;
C_noret_decl(f_6597)
static C_word C_fcall f_6597(C_word t0,C_word t1);
C_noret_decl(f_6610)
static void C_ccall f_6610(C_word c,C_word *av) C_noret;
C_noret_decl(f_6612)
static void C_fcall f_6612(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6650)
static void C_fcall f_6650(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6660)
static void C_ccall f_6660(C_word c,C_word *av) C_noret;
C_noret_decl(f_6673)
static void C_fcall f_6673(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6708)
static void C_ccall f_6708(C_word c,C_word *av) C_noret;
C_noret_decl(f_6715)
static void C_ccall f_6715(C_word c,C_word *av) C_noret;
C_noret_decl(f_6719)
static void C_ccall f_6719(C_word c,C_word *av) C_noret;
C_noret_decl(f_6723)
static void C_ccall f_6723(C_word c,C_word *av) C_noret;
C_noret_decl(f_6725)
static void C_ccall f_6725(C_word c,C_word *av) C_noret;
C_noret_decl(f_6729)
static void C_ccall f_6729(C_word c,C_word *av) C_noret;
C_noret_decl(f_6737)
static void C_ccall f_6737(C_word c,C_word *av) C_noret;
C_noret_decl(f_6746)
static void C_ccall f_6746(C_word c,C_word *av) C_noret;
C_noret_decl(f_6749)
static void C_ccall f_6749(C_word c,C_word *av) C_noret;
C_noret_decl(f_6752)
static void C_ccall f_6752(C_word c,C_word *av) C_noret;
C_noret_decl(f_6774)
static void C_ccall f_6774(C_word c,C_word *av) C_noret;
C_noret_decl(f_6781)
static void C_ccall f_6781(C_word c,C_word *av) C_noret;
C_noret_decl(f_6785)
static void C_ccall f_6785(C_word c,C_word *av) C_noret;
C_noret_decl(f_6796)
static void C_ccall f_6796(C_word c,C_word *av) C_noret;
C_noret_decl(f_6799)
static void C_ccall f_6799(C_word c,C_word *av) C_noret;
C_noret_decl(f_6802)
static void C_ccall f_6802(C_word c,C_word *av) C_noret;
C_noret_decl(f_6816)
static void C_ccall f_6816(C_word c,C_word *av) C_noret;
C_noret_decl(f_6823)
static void C_ccall f_6823(C_word c,C_word *av) C_noret;
C_noret_decl(f_6827)
static void C_ccall f_6827(C_word c,C_word *av) C_noret;
C_noret_decl(f_6839)
static void C_ccall f_6839(C_word c,C_word *av) C_noret;
C_noret_decl(f_6841)
static void C_ccall f_6841(C_word c,C_word *av) C_noret;
C_noret_decl(f_6845)
static void C_ccall f_6845(C_word c,C_word *av) C_noret;
C_noret_decl(f_6847)
static void C_fcall f_6847(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6853)
static void C_fcall f_6853(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6867)
static void C_ccall f_6867(C_word c,C_word *av) C_noret;
C_noret_decl(f_6871)
static void C_ccall f_6871(C_word c,C_word *av) C_noret;
C_noret_decl(f_6879)
static void C_ccall f_6879(C_word c,C_word *av) C_noret;
C_noret_decl(f_6882)
static void C_ccall f_6882(C_word c,C_word *av) C_noret;
C_noret_decl(f_6885)
static void C_ccall f_6885(C_word c,C_word *av) C_noret;
C_noret_decl(f_6888)
static void C_ccall f_6888(C_word c,C_word *av) C_noret;
C_noret_decl(f_6891)
static void C_ccall f_6891(C_word c,C_word *av) C_noret;
C_noret_decl(f_6894)
static void C_ccall f_6894(C_word c,C_word *av) C_noret;
C_noret_decl(f_6897)
static void C_ccall f_6897(C_word c,C_word *av) C_noret;
C_noret_decl(f_6900)
static void C_ccall f_6900(C_word c,C_word *av) C_noret;
C_noret_decl(f_6903)
static void C_ccall f_6903(C_word c,C_word *av) C_noret;
C_noret_decl(f_6906)
static void C_ccall f_6906(C_word c,C_word *av) C_noret;
C_noret_decl(f_6913)
static void C_ccall f_6913(C_word c,C_word *av) C_noret;
C_noret_decl(f_6929)
static void C_ccall f_6929(C_word c,C_word *av) C_noret;
C_noret_decl(f_6931)
static void C_fcall f_6931(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6939)
static void C_fcall f_6939(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6949)
static void C_ccall f_6949(C_word c,C_word *av) C_noret;
C_noret_decl(f_6953)
static void C_ccall f_6953(C_word c,C_word *av) C_noret;
C_noret_decl(f_6963)
static void C_fcall f_6963(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6967)
static void C_ccall f_6967(C_word c,C_word *av) C_noret;
C_noret_decl(f_6969)
static void C_ccall f_6969(C_word c,C_word *av) C_noret;
C_noret_decl(f_6977)
static void C_ccall f_6977(C_word c,C_word *av) C_noret;
C_noret_decl(f_6979)
static void C_ccall f_6979(C_word c,C_word *av) C_noret;
C_noret_decl(f_6983)
static void C_ccall f_6983(C_word c,C_word *av) C_noret;
C_noret_decl(f_7005)
static void C_ccall f_7005(C_word c,C_word *av) C_noret;
C_noret_decl(f_7007)
static void C_fcall f_7007(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7055)
static void C_fcall f_7055(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7108)
static void C_ccall f_7108(C_word c,C_word *av) C_noret;
C_noret_decl(f_7119)
static void C_ccall f_7119(C_word c,C_word *av) C_noret;
C_noret_decl(f_7156)
static void C_ccall f_7156(C_word c,C_word *av) C_noret;
C_noret_decl(f_7184)
static void C_ccall f_7184(C_word c,C_word *av) C_noret;
C_noret_decl(f_7211)
static void C_ccall f_7211(C_word c,C_word *av) C_noret;
C_noret_decl(f_7221)
static void C_ccall f_7221(C_word c,C_word *av) C_noret;
C_noret_decl(f_7223)
static void C_fcall f_7223(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7248)
static void C_ccall f_7248(C_word c,C_word *av) C_noret;
C_noret_decl(f_7283)
static void C_ccall f_7283(C_word c,C_word *av) C_noret;
C_noret_decl(f_7285)
static void C_ccall f_7285(C_word c,C_word *av) C_noret;
C_noret_decl(f_7289)
static void C_ccall f_7289(C_word c,C_word *av) C_noret;
C_noret_decl(f_7301)
static void C_ccall f_7301(C_word c,C_word *av) C_noret;
C_noret_decl(f_7304)
static void C_ccall f_7304(C_word c,C_word *av) C_noret;
C_noret_decl(f_7307)
static void C_ccall f_7307(C_word c,C_word *av) C_noret;
C_noret_decl(f_7310)
static void C_ccall f_7310(C_word c,C_word *av) C_noret;
C_noret_decl(f_7321)
static void C_ccall f_7321(C_word c,C_word *av) C_noret;
C_noret_decl(f_7323)
static void C_fcall f_7323(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7349)
static void C_ccall f_7349(C_word c,C_word *av) C_noret;
C_noret_decl(f_7360)
static void C_ccall f_7360(C_word c,C_word *av) C_noret;
C_noret_decl(f_7443)
static void C_ccall f_7443(C_word c,C_word *av) C_noret;
C_noret_decl(f_7445)
static void C_ccall f_7445(C_word c,C_word *av) C_noret;
C_noret_decl(f_7449)
static void C_ccall f_7449(C_word c,C_word *av) C_noret;
C_noret_decl(f_7452)
static void C_ccall f_7452(C_word c,C_word *av) C_noret;
C_noret_decl(f_7482)
static void C_ccall f_7482(C_word c,C_word *av) C_noret;
C_noret_decl(f_7492)
static void C_ccall f_7492(C_word c,C_word *av) C_noret;
C_noret_decl(f_7520)
static void C_ccall f_7520(C_word c,C_word *av) C_noret;
C_noret_decl(f_7522)
static void C_ccall f_7522(C_word c,C_word *av) C_noret;
C_noret_decl(f_7526)
static void C_ccall f_7526(C_word c,C_word *av) C_noret;
C_noret_decl(f_7545)
static void C_ccall f_7545(C_word c,C_word *av) C_noret;
C_noret_decl(f_7549)
static void C_ccall f_7549(C_word c,C_word *av) C_noret;
C_noret_decl(f_7553)
static void C_ccall f_7553(C_word c,C_word *av) C_noret;
C_noret_decl(f_7555)
static void C_fcall f_7555(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_7576)
static void C_ccall f_7576(C_word c,C_word *av) C_noret;
C_noret_decl(f_7594)
static void C_ccall f_7594(C_word c,C_word *av) C_noret;
C_noret_decl(f_7602)
static void C_ccall f_7602(C_word c,C_word *av) C_noret;
C_noret_decl(f_7606)
static void C_ccall f_7606(C_word c,C_word *av) C_noret;
C_noret_decl(f_7616)
static void C_fcall f_7616(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_7622)
static void C_fcall f_7622(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_7636)
static void C_ccall f_7636(C_word c,C_word *av) C_noret;
C_noret_decl(f_7662)
static void C_ccall f_7662(C_word c,C_word *av) C_noret;
C_noret_decl(f_7686)
static void C_ccall f_7686(C_word c,C_word *av) C_noret;
C_noret_decl(f_7694)
static void C_ccall f_7694(C_word c,C_word *av) C_noret;
C_noret_decl(f_7702)
static void C_ccall f_7702(C_word c,C_word *av) C_noret;
C_noret_decl(f_7706)
static void C_ccall f_7706(C_word c,C_word *av) C_noret;
C_noret_decl(f_7709)
static void C_ccall f_7709(C_word c,C_word *av) C_noret;
C_noret_decl(f_7712)
static void C_ccall f_7712(C_word c,C_word *av) C_noret;
C_noret_decl(f_7721)
static void C_ccall f_7721(C_word c,C_word *av) C_noret;
C_noret_decl(f_7722)
static void C_fcall f_7722(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7730)
static void C_ccall f_7730(C_word c,C_word *av) C_noret;
C_noret_decl(f_7734)
static void C_ccall f_7734(C_word c,C_word *av) C_noret;
C_noret_decl(f_7738)
static void C_fcall f_7738(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7746)
static void C_ccall f_7746(C_word c,C_word *av) C_noret;
C_noret_decl(f_7752)
static void C_ccall f_7752(C_word c,C_word *av) C_noret;
C_noret_decl(f_7758)
static void C_ccall f_7758(C_word c,C_word *av) C_noret;
C_noret_decl(f_7761)
static void C_ccall f_7761(C_word c,C_word *av) C_noret;
C_noret_decl(f_7764)
static void C_ccall f_7764(C_word c,C_word *av) C_noret;
C_noret_decl(f_7768)
static void C_fcall f_7768(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7776)
static void C_ccall f_7776(C_word c,C_word *av) C_noret;
C_noret_decl(f_7779)
static void C_ccall f_7779(C_word c,C_word *av) C_noret;
C_noret_decl(f_7782)
static void C_ccall f_7782(C_word c,C_word *av) C_noret;
C_noret_decl(f_7785)
static void C_ccall f_7785(C_word c,C_word *av) C_noret;
C_noret_decl(f_7792)
static void C_ccall f_7792(C_word c,C_word *av) C_noret;
C_noret_decl(f_7818)
static void C_fcall f_7818(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7843)
static void C_ccall f_7843(C_word c,C_word *av) C_noret;
C_noret_decl(f_7852)
static void C_fcall f_7852(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7886)
static void C_fcall f_7886(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7911)
static void C_ccall f_7911(C_word c,C_word *av) C_noret;
C_noret_decl(f_7920)
static void C_fcall f_7920(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7968)
static void C_ccall f_7968(C_word c,C_word *av) C_noret;
C_noret_decl(f_7970)
static void C_ccall f_7970(C_word c,C_word *av) C_noret;
C_noret_decl(f_7974)
static void C_ccall f_7974(C_word c,C_word *av) C_noret;
C_noret_decl(f_7984)
static void C_fcall f_7984(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_8011)
static void C_ccall f_8011(C_word c,C_word *av) C_noret;
C_noret_decl(f_8014)
static void C_ccall f_8014(C_word c,C_word *av) C_noret;
C_noret_decl(f_8029)
static void C_ccall f_8029(C_word c,C_word *av) C_noret;
C_noret_decl(f_8037)
static void C_ccall f_8037(C_word c,C_word *av) C_noret;
C_noret_decl(f_8046)
static void C_ccall f_8046(C_word c,C_word *av) C_noret;
C_noret_decl(f_8061)
static void C_ccall f_8061(C_word c,C_word *av) C_noret;
C_noret_decl(f_8071)
static void C_ccall f_8071(C_word c,C_word *av) C_noret;
C_noret_decl(f_8074)
static void C_ccall f_8074(C_word c,C_word *av) C_noret;
C_noret_decl(f_8090)
static void C_ccall f_8090(C_word c,C_word *av) C_noret;
C_noret_decl(f_8110)
static void C_ccall f_8110(C_word c,C_word *av) C_noret;
C_noret_decl(f_8112)
static void C_ccall f_8112(C_word c,C_word *av) C_noret;
C_noret_decl(f_8114)
static void C_ccall f_8114(C_word c,C_word *av) C_noret;
C_noret_decl(f_8118)
static void C_ccall f_8118(C_word c,C_word *av) C_noret;
C_noret_decl(f_8127)
static void C_fcall f_8127(C_word t0,C_word t1) C_noret;
C_noret_decl(f_8130)
static void C_ccall f_8130(C_word c,C_word *av) C_noret;
C_noret_decl(f_8139)
static void C_fcall f_8139(C_word t0,C_word t1) C_noret;
C_noret_decl(f_8155)
static void C_ccall f_8155(C_word c,C_word *av) C_noret;
C_noret_decl(f_8159)
static void C_ccall f_8159(C_word c,C_word *av) C_noret;
C_noret_decl(f_8202)
static void C_ccall f_8202(C_word c,C_word *av) C_noret;
C_noret_decl(f_8214)
static void C_ccall f_8214(C_word c,C_word *av) C_noret;
C_noret_decl(f_8216)
static void C_ccall f_8216(C_word c,C_word *av) C_noret;
C_noret_decl(f_8220)
static void C_ccall f_8220(C_word c,C_word *av) C_noret;
C_noret_decl(f_8223)
static void C_ccall f_8223(C_word c,C_word *av) C_noret;
C_noret_decl(f_8242)
static void C_ccall f_8242(C_word c,C_word *av) C_noret;
C_noret_decl(f_8258)
static void C_ccall f_8258(C_word c,C_word *av) C_noret;
C_noret_decl(f_8260)
static void C_ccall f_8260(C_word c,C_word *av) C_noret;
C_noret_decl(f_8264)
static void C_ccall f_8264(C_word c,C_word *av) C_noret;
C_noret_decl(f_8267)
static void C_ccall f_8267(C_word c,C_word *av) C_noret;
C_noret_decl(f_8280)
static void C_ccall f_8280(C_word c,C_word *av) C_noret;
C_noret_decl(f_8282)
static void C_ccall f_8282(C_word c,C_word *av) C_noret;
C_noret_decl(f_8286)
static void C_ccall f_8286(C_word c,C_word *av) C_noret;
C_noret_decl(f_8300)
static void C_ccall f_8300(C_word c,C_word *av) C_noret;
C_noret_decl(f_8306)
static void C_ccall f_8306(C_word c,C_word *av) C_noret;
C_noret_decl(f_8328)
static void C_ccall f_8328(C_word c,C_word *av) C_noret;
C_noret_decl(f_8334)
static void C_ccall f_8334(C_word c,C_word *av) C_noret;
C_noret_decl(f_8338)
static void C_ccall f_8338(C_word c,C_word *av) C_noret;
C_noret_decl(f_8348)
static void C_ccall f_8348(C_word c,C_word *av) C_noret;
C_noret_decl(f_8350)
static void C_fcall f_8350(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_8379)
static void C_ccall f_8379(C_word c,C_word *av) C_noret;
C_noret_decl(f_8398)
static void C_fcall f_8398(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8432)
static void C_fcall f_8432(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_8456)
static void C_ccall f_8456(C_word c,C_word *av) C_noret;
C_noret_decl(f_8458)
static void C_ccall f_8458(C_word c,C_word *av) C_noret;
C_noret_decl(f_8462)
static void C_ccall f_8462(C_word c,C_word *av) C_noret;
C_noret_decl(f_8468)
static void C_fcall f_8468(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8502)
static void C_fcall f_8502(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8538)
static void C_ccall f_8538(C_word c,C_word *av) C_noret;
C_noret_decl(f_8540)
static void C_ccall f_8540(C_word c,C_word *av) C_noret;
C_noret_decl(f_8544)
static void C_ccall f_8544(C_word c,C_word *av) C_noret;
C_noret_decl(f_8552)
static void C_ccall f_8552(C_word c,C_word *av) C_noret;
C_noret_decl(f_8557)
static void C_fcall f_8557(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8582)
static void C_ccall f_8582(C_word c,C_word *av) C_noret;
C_noret_decl(f_8592)
static void C_ccall f_8592(C_word c,C_word *av) C_noret;
C_noret_decl(f_8594)
static void C_ccall f_8594(C_word c,C_word *av) C_noret;
C_noret_decl(f_8598)
static void C_ccall f_8598(C_word c,C_word *av) C_noret;
C_noret_decl(f_8604)
static void C_ccall f_8604(C_word c,C_word *av) C_noret;
C_noret_decl(f_8625)
static void C_ccall f_8625(C_word c,C_word *av) C_noret;
C_noret_decl(f_8632)
static void C_ccall f_8632(C_word c,C_word *av) C_noret;
C_noret_decl(f_8655)
static void C_ccall f_8655(C_word c,C_word *av) C_noret;
C_noret_decl(f_8659)
static void C_ccall f_8659(C_word c,C_word *av) C_noret;
C_noret_decl(f_8680)
static void C_ccall f_8680(C_word c,C_word *av) C_noret;
C_noret_decl(f_8683)
static void C_ccall f_8683(C_word c,C_word *av) C_noret;
C_noret_decl(f_8687)
static void C_fcall f_8687(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8695)
static void C_ccall f_8695(C_word c,C_word *av) C_noret;
C_noret_decl(f_8699)
static void C_ccall f_8699(C_word c,C_word *av) C_noret;
C_noret_decl(f_8705)
static void C_ccall f_8705(C_word c,C_word *av) C_noret;
C_noret_decl(f_8706)
static void C_ccall f_8706(C_word c,C_word *av) C_noret;
C_noret_decl(f_8717)
static void C_ccall f_8717(C_word c,C_word *av) C_noret;
C_noret_decl(f_8732)
static void C_ccall f_8732(C_word c,C_word *av) C_noret;
C_noret_decl(f_8734)
static void C_fcall f_8734(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_8753)
static void C_fcall f_8753(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8761)
static void C_ccall f_8761(C_word c,C_word *av) C_noret;
C_noret_decl(f_8767)
static void C_ccall f_8767(C_word c,C_word *av) C_noret;
C_noret_decl(f_8769)
static void C_fcall f_8769(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8794)
static void C_ccall f_8794(C_word c,C_word *av) C_noret;
C_noret_decl(f_8818)
static void C_ccall f_8818(C_word c,C_word *av) C_noret;
C_noret_decl(f_8855)
static void C_ccall f_8855(C_word c,C_word *av) C_noret;
C_noret_decl(f_8883)
static void C_fcall f_8883(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8917)
static void C_fcall f_8917(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_8948)
static void C_ccall f_8948(C_word c,C_word *av) C_noret;
C_noret_decl(f_8955)
static void C_ccall f_8955(C_word c,C_word *av) C_noret;
C_noret_decl(f_8961)
static void C_fcall f_8961(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8986)
static void C_ccall f_8986(C_word c,C_word *av) C_noret;
C_noret_decl(f_8995)
static void C_fcall f_8995(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_9008)
static void C_ccall f_9008(C_word c,C_word *av) C_noret;
C_noret_decl(f_9033)
static void C_fcall f_9033(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9069)
static void C_ccall f_9069(C_word c,C_word *av) C_noret;
C_noret_decl(f_9071)
static void C_ccall f_9071(C_word c,C_word *av) C_noret;
C_noret_decl(f_9075)
static void C_ccall f_9075(C_word c,C_word *av) C_noret;
C_noret_decl(f_9082)
static void C_ccall f_9082(C_word c,C_word *av) C_noret;
C_noret_decl(f_9086)
static void C_ccall f_9086(C_word c,C_word *av) C_noret;
C_noret_decl(f_9094)
static void C_ccall f_9094(C_word c,C_word *av) C_noret;
C_noret_decl(f_9108)
static void C_ccall f_9108(C_word c,C_word *av) C_noret;
C_noret_decl(f_9114)
static void C_ccall f_9114(C_word c,C_word *av) C_noret;
C_noret_decl(f_9121)
static void C_ccall f_9121(C_word c,C_word *av) C_noret;
C_noret_decl(f_9127)
static void C_ccall f_9127(C_word c,C_word *av) C_noret;
C_noret_decl(f_9140)
static void C_fcall f_9140(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9174)
static void C_fcall f_9174(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9184)
static void C_ccall f_9184(C_word c,C_word *av) C_noret;
C_noret_decl(f_9199)
static void C_ccall f_9199(C_word c,C_word *av) C_noret;
C_noret_decl(f_9201)
static void C_ccall f_9201(C_word c,C_word *av) C_noret;
C_noret_decl(f_9205)
static void C_ccall f_9205(C_word c,C_word *av) C_noret;
C_noret_decl(f_9220)
static void C_ccall f_9220(C_word c,C_word *av) C_noret;
C_noret_decl(f_9222)
static void C_ccall f_9222(C_word c,C_word *av) C_noret;
C_noret_decl(f_9226)
static void C_ccall f_9226(C_word c,C_word *av) C_noret;
C_noret_decl(f_9248)
static void C_ccall f_9248(C_word c,C_word *av) C_noret;
C_noret_decl(f_9250)
static void C_ccall f_9250(C_word c,C_word *av) C_noret;
C_noret_decl(f_9254)
static void C_ccall f_9254(C_word c,C_word *av) C_noret;
C_noret_decl(f_9272)
static void C_ccall f_9272(C_word c,C_word *av) C_noret;
C_noret_decl(f_9274)
static void C_ccall f_9274(C_word c,C_word *av) C_noret;
C_noret_decl(f_9283)
static void C_fcall f_9283(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9289)
static void C_ccall f_9289(C_word c,C_word *av) C_noret;
C_noret_decl(f_9295)
static void C_ccall f_9295(C_word c,C_word *av) C_noret;
C_noret_decl(f_9314)
static void C_ccall f_9314(C_word c,C_word *av) C_noret;
C_noret_decl(f_9316)
static void C_fcall f_9316(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9341)
static void C_ccall f_9341(C_word c,C_word *av) C_noret;
C_noret_decl(f_9352)
static void C_ccall f_9352(C_word c,C_word *av) C_noret;
C_noret_decl(f_9354)
static void C_ccall f_9354(C_word c,C_word *av) C_noret;
C_noret_decl(f_9373)
static void C_ccall f_9373(C_word c,C_word *av) C_noret;
C_noret_decl(f_9381)
static void C_ccall f_9381(C_word c,C_word *av) C_noret;
C_noret_decl(f_9390)
static void C_ccall f_9390(C_word c,C_word *av) C_noret;
C_noret_decl(f_9396)
static void C_ccall f_9396(C_word c,C_word *av) C_noret;
C_noret_decl(f_9400)
static void C_fcall f_9400(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9408)
static void C_ccall f_9408(C_word c,C_word *av) C_noret;
C_noret_decl(f_9414)
static void C_ccall f_9414(C_word c,C_word *av) C_noret;
C_noret_decl(f_9418)
static void C_fcall f_9418(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9426)
static void C_ccall f_9426(C_word c,C_word *av) C_noret;
C_noret_decl(f_9429)
static void C_ccall f_9429(C_word c,C_word *av) C_noret;
C_noret_decl(f_9433)
static void C_fcall f_9433(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9441)
static void C_ccall f_9441(C_word c,C_word *av) C_noret;
C_noret_decl(f_9444)
static void C_ccall f_9444(C_word c,C_word *av) C_noret;
C_noret_decl(f_9457)
static void C_ccall f_9457(C_word c,C_word *av) C_noret;
C_noret_decl(f_9474)
static void C_ccall f_9474(C_word c,C_word *av) C_noret;
C_noret_decl(f_9485)
static void C_ccall f_9485(C_word c,C_word *av) C_noret;
C_noret_decl(f_9533)
static void C_ccall f_9533(C_word c,C_word *av) C_noret;
C_noret_decl(f_9537)
static void C_ccall f_9537(C_word c,C_word *av) C_noret;
C_noret_decl(f_9549)
static void C_ccall f_9549(C_word c,C_word *av) C_noret;
C_noret_decl(f_9561)
static void C_ccall f_9561(C_word c,C_word *av) C_noret;
C_noret_decl(f_9563)
static void C_fcall f_9563(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_9611)
static void C_fcall f_9611(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_9659)
static void C_fcall f_9659(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_9666)
static void C_fcall f_9666(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9736)
static C_word C_fcall f_9736(C_word *a,C_word t0,C_word t1,C_word t2,C_word t3);
C_noret_decl(f_9754)
static void C_ccall f_9754(C_word c,C_word *av) C_noret;
C_noret_decl(f_9758)
static void C_ccall f_9758(C_word c,C_word *av) C_noret;
C_noret_decl(f_9774)
static void C_ccall f_9774(C_word c,C_word *av) C_noret;
C_noret_decl(f_9778)
static void C_ccall f_9778(C_word c,C_word *av) C_noret;
C_noret_decl(f_9790)
static void C_ccall f_9790(C_word c,C_word *av) C_noret;
C_noret_decl(f_9800)
static void C_fcall f_9800(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_9848)
static void C_fcall f_9848(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_9896)
static void C_fcall f_9896(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_9903)
static void C_fcall f_9903(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9966)
static void C_fcall f_9966(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(C_chicken_2dsyntax_toplevel)
C_externexport void C_ccall C_chicken_2dsyntax_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_10014)
static void C_ccall trf_10014(C_word c,C_word *av) C_noret;
static void C_ccall trf_10014(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10014(t0,t1,t2,t3);}

C_noret_decl(trf_10062)
static void C_ccall trf_10062(C_word c,C_word *av) C_noret;
static void C_ccall trf_10062(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10062(t0,t1,t2,t3);}

C_noret_decl(trf_10110)
static void C_ccall trf_10110(C_word c,C_word *av) C_noret;
static void C_ccall trf_10110(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10110(t0,t1,t2);}

C_noret_decl(trf_10144)
static void C_ccall trf_10144(C_word c,C_word *av) C_noret;
static void C_ccall trf_10144(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10144(t0,t1,t2);}

C_noret_decl(trf_10178)
static void C_ccall trf_10178(C_word c,C_word *av) C_noret;
static void C_ccall trf_10178(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10178(t0,t1,t2);}

C_noret_decl(trf_10212)
static void C_ccall trf_10212(C_word c,C_word *av) C_noret;
static void C_ccall trf_10212(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10212(t0,t1,t2);}

C_noret_decl(trf_10246)
static void C_ccall trf_10246(C_word c,C_word *av) C_noret;
static void C_ccall trf_10246(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10246(t0,t1,t2);}

C_noret_decl(trf_10306)
static void C_ccall trf_10306(C_word c,C_word *av) C_noret;
static void C_ccall trf_10306(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_10306(t0,t1);}

C_noret_decl(trf_10321)
static void C_ccall trf_10321(C_word c,C_word *av) C_noret;
static void C_ccall trf_10321(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_10321(t0,t1);}

C_noret_decl(trf_10401)
static void C_ccall trf_10401(C_word c,C_word *av) C_noret;
static void C_ccall trf_10401(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10401(t0,t1,t2,t3);}

C_noret_decl(trf_10449)
static void C_ccall trf_10449(C_word c,C_word *av) C_noret;
static void C_ccall trf_10449(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10449(t0,t1,t2,t3);}

C_noret_decl(trf_10548)
static void C_ccall trf_10548(C_word c,C_word *av) C_noret;
static void C_ccall trf_10548(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10548(t0,t1,t2,t3);}

C_noret_decl(trf_10596)
static void C_ccall trf_10596(C_word c,C_word *av) C_noret;
static void C_ccall trf_10596(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10596(t0,t1,t2,t3);}

C_noret_decl(trf_10679)
static void C_ccall trf_10679(C_word c,C_word *av) C_noret;
static void C_ccall trf_10679(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10679(t0,t1,t2,t3);}

C_noret_decl(trf_10729)
static void C_ccall trf_10729(C_word c,C_word *av) C_noret;
static void C_ccall trf_10729(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10729(t0,t1,t2);}

C_noret_decl(trf_10749)
static void C_ccall trf_10749(C_word c,C_word *av) C_noret;
static void C_ccall trf_10749(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10749(t0,t1,t2,t3);}

C_noret_decl(trf_10797)
static void C_ccall trf_10797(C_word c,C_word *av) C_noret;
static void C_ccall trf_10797(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10797(t0,t1,t2);}

C_noret_decl(trf_10831)
static void C_ccall trf_10831(C_word c,C_word *av) C_noret;
static void C_ccall trf_10831(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10831(t0,t1,t2);}

C_noret_decl(trf_10865)
static void C_ccall trf_10865(C_word c,C_word *av) C_noret;
static void C_ccall trf_10865(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10865(t0,t1,t2);}

C_noret_decl(trf_10899)
static void C_ccall trf_10899(C_word c,C_word *av) C_noret;
static void C_ccall trf_10899(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10899(t0,t1,t2);}

C_noret_decl(trf_11131)
static void C_ccall trf_11131(C_word c,C_word *av) C_noret;
static void C_ccall trf_11131(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11131(t0,t1,t2);}

C_noret_decl(trf_11144)
static void C_ccall trf_11144(C_word c,C_word *av) C_noret;
static void C_ccall trf_11144(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_11144(t0,t1);}

C_noret_decl(trf_11224)
static void C_ccall trf_11224(C_word c,C_word *av) C_noret;
static void C_ccall trf_11224(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_11224(t0,t1,t2,t3);}

C_noret_decl(trf_11276)
static void C_ccall trf_11276(C_word c,C_word *av) C_noret;
static void C_ccall trf_11276(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_11276(t0,t1);}

C_noret_decl(trf_11442)
static void C_ccall trf_11442(C_word c,C_word *av) C_noret;
static void C_ccall trf_11442(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11442(t0,t1,t2);}

C_noret_decl(trf_11574)
static void C_ccall trf_11574(C_word c,C_word *av) C_noret;
static void C_ccall trf_11574(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_11574(t0,t1,t2,t3);}

C_noret_decl(trf_11624)
static void C_ccall trf_11624(C_word c,C_word *av) C_noret;
static void C_ccall trf_11624(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_11624(t0,t1,t2,t3);}

C_noret_decl(trf_11693)
static void C_ccall trf_11693(C_word c,C_word *av) C_noret;
static void C_ccall trf_11693(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_11693(t0,t1);}

C_noret_decl(trf_11929)
static void C_ccall trf_11929(C_word c,C_word *av) C_noret;
static void C_ccall trf_11929(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11929(t0,t1,t2);}

C_noret_decl(trf_11969)
static void C_ccall trf_11969(C_word c,C_word *av) C_noret;
static void C_ccall trf_11969(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11969(t0,t1,t2);}

C_noret_decl(trf_12049)
static void C_ccall trf_12049(C_word c,C_word *av) C_noret;
static void C_ccall trf_12049(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_12049(t0,t1,t2,t3,t4);}

C_noret_decl(trf_12106)
static void C_ccall trf_12106(C_word c,C_word *av) C_noret;
static void C_ccall trf_12106(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_12106(t0,t1,t2,t3);}

C_noret_decl(trf_12168)
static void C_ccall trf_12168(C_word c,C_word *av) C_noret;
static void C_ccall trf_12168(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12168(t0,t1);}

C_noret_decl(trf_12191)
static void C_ccall trf_12191(C_word c,C_word *av) C_noret;
static void C_ccall trf_12191(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12191(t0,t1,t2);}

C_noret_decl(trf_12235)
static void C_ccall trf_12235(C_word c,C_word *av) C_noret;
static void C_ccall trf_12235(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_12235(t0,t1,t2,t3);}

C_noret_decl(trf_12289)
static void C_ccall trf_12289(C_word c,C_word *av) C_noret;
static void C_ccall trf_12289(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12289(t0,t1);}

C_noret_decl(trf_12459)
static void C_ccall trf_12459(C_word c,C_word *av) C_noret;
static void C_ccall trf_12459(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12459(t0,t1,t2);}

C_noret_decl(trf_12493)
static void C_ccall trf_12493(C_word c,C_word *av) C_noret;
static void C_ccall trf_12493(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12493(t0,t1,t2);}

C_noret_decl(trf_12561)
static void C_ccall trf_12561(C_word c,C_word *av) C_noret;
static void C_ccall trf_12561(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_12561(t0,t1,t2,t3);}

C_noret_decl(trf_12611)
static void C_ccall trf_12611(C_word c,C_word *av) C_noret;
static void C_ccall trf_12611(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_12611(t0,t1,t2,t3);}

C_noret_decl(trf_12630)
static void C_ccall trf_12630(C_word c,C_word *av) C_noret;
static void C_ccall trf_12630(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12630(t0,t1);}

C_noret_decl(trf_12771)
static void C_ccall trf_12771(C_word c,C_word *av) C_noret;
static void C_ccall trf_12771(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12771(t0,t1);}

C_noret_decl(trf_12844)
static void C_ccall trf_12844(C_word c,C_word *av) C_noret;
static void C_ccall trf_12844(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12844(t0,t1,t2);}

C_noret_decl(trf_12854)
static void C_ccall trf_12854(C_word c,C_word *av) C_noret;
static void C_ccall trf_12854(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12854(t0,t1);}

C_noret_decl(trf_12895)
static void C_ccall trf_12895(C_word c,C_word *av) C_noret;
static void C_ccall trf_12895(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12895(t0,t1,t2);}

C_noret_decl(trf_13030)
static void C_ccall trf_13030(C_word c,C_word *av) C_noret;
static void C_ccall trf_13030(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_13030(t0,t1,t2);}

C_noret_decl(trf_4347)
static void C_ccall trf_4347(C_word c,C_word *av) C_noret;
static void C_ccall trf_4347(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4347(t0,t1,t2);}

C_noret_decl(trf_4405)
static void C_ccall trf_4405(C_word c,C_word *av) C_noret;
static void C_ccall trf_4405(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_4405(t0,t1,t2,t3,t4);}

C_noret_decl(trf_5765)
static void C_ccall trf_5765(C_word c,C_word *av) C_noret;
static void C_ccall trf_5765(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5765(t0,t1);}

C_noret_decl(trf_5788)
static void C_ccall trf_5788(C_word c,C_word *av) C_noret;
static void C_ccall trf_5788(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5788(t0,t1);}

C_noret_decl(trf_5939)
static void C_ccall trf_5939(C_word c,C_word *av) C_noret;
static void C_ccall trf_5939(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_5939(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_6134)
static void C_ccall trf_6134(C_word c,C_word *av) C_noret;
static void C_ccall trf_6134(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_6134(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_6333)
static void C_ccall trf_6333(C_word c,C_word *av) C_noret;
static void C_ccall trf_6333(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6333(t0,t1,t2);}

C_noret_decl(trf_6382)
static void C_ccall trf_6382(C_word c,C_word *av) C_noret;
static void C_ccall trf_6382(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6382(t0,t1,t2,t3);}

C_noret_decl(trf_6401)
static void C_ccall trf_6401(C_word c,C_word *av) C_noret;
static void C_ccall trf_6401(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6401(t0,t1);}

C_noret_decl(trf_6407)
static void C_ccall trf_6407(C_word c,C_word *av) C_noret;
static void C_ccall trf_6407(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6407(t0,t1);}

C_noret_decl(trf_6414)
static void C_ccall trf_6414(C_word c,C_word *av) C_noret;
static void C_ccall trf_6414(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6414(t0,t1);}

C_noret_decl(trf_6422)
static void C_ccall trf_6422(C_word c,C_word *av) C_noret;
static void C_ccall trf_6422(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6422(t0,t1);}

C_noret_decl(trf_6612)
static void C_ccall trf_6612(C_word c,C_word *av) C_noret;
static void C_ccall trf_6612(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6612(t0,t1,t2);}

C_noret_decl(trf_6650)
static void C_ccall trf_6650(C_word c,C_word *av) C_noret;
static void C_ccall trf_6650(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6650(t0,t1,t2);}

C_noret_decl(trf_6673)
static void C_ccall trf_6673(C_word c,C_word *av) C_noret;
static void C_ccall trf_6673(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6673(t0,t1,t2);}

C_noret_decl(trf_6847)
static void C_ccall trf_6847(C_word c,C_word *av) C_noret;
static void C_ccall trf_6847(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6847(t0,t1,t2);}

C_noret_decl(trf_6853)
static void C_ccall trf_6853(C_word c,C_word *av) C_noret;
static void C_ccall trf_6853(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6853(t0,t1,t2);}

C_noret_decl(trf_6931)
static void C_ccall trf_6931(C_word c,C_word *av) C_noret;
static void C_ccall trf_6931(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6931(t0,t1,t2);}

C_noret_decl(trf_6939)
static void C_ccall trf_6939(C_word c,C_word *av) C_noret;
static void C_ccall trf_6939(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6939(t0,t1,t2,t3);}

C_noret_decl(trf_6963)
static void C_ccall trf_6963(C_word c,C_word *av) C_noret;
static void C_ccall trf_6963(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6963(t0,t1);}

C_noret_decl(trf_7007)
static void C_ccall trf_7007(C_word c,C_word *av) C_noret;
static void C_ccall trf_7007(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7007(t0,t1,t2,t3);}

C_noret_decl(trf_7055)
static void C_ccall trf_7055(C_word c,C_word *av) C_noret;
static void C_ccall trf_7055(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7055(t0,t1,t2,t3);}

C_noret_decl(trf_7223)
static void C_ccall trf_7223(C_word c,C_word *av) C_noret;
static void C_ccall trf_7223(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7223(t0,t1,t2);}

C_noret_decl(trf_7323)
static void C_ccall trf_7323(C_word c,C_word *av) C_noret;
static void C_ccall trf_7323(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7323(t0,t1,t2,t3);}

C_noret_decl(trf_7555)
static void C_ccall trf_7555(C_word c,C_word *av) C_noret;
static void C_ccall trf_7555(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_7555(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_7616)
static void C_ccall trf_7616(C_word c,C_word *av) C_noret;
static void C_ccall trf_7616(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_7616(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_7622)
static void C_ccall trf_7622(C_word c,C_word *av) C_noret;
static void C_ccall trf_7622(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_7622(t0,t1,t2,t3,t4);}

C_noret_decl(trf_7722)
static void C_ccall trf_7722(C_word c,C_word *av) C_noret;
static void C_ccall trf_7722(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7722(t0,t1,t2);}

C_noret_decl(trf_7738)
static void C_ccall trf_7738(C_word c,C_word *av) C_noret;
static void C_ccall trf_7738(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7738(t0,t1,t2);}

C_noret_decl(trf_7768)
static void C_ccall trf_7768(C_word c,C_word *av) C_noret;
static void C_ccall trf_7768(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7768(t0,t1,t2);}

C_noret_decl(trf_7818)
static void C_ccall trf_7818(C_word c,C_word *av) C_noret;
static void C_ccall trf_7818(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7818(t0,t1,t2);}

C_noret_decl(trf_7852)
static void C_ccall trf_7852(C_word c,C_word *av) C_noret;
static void C_ccall trf_7852(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7852(t0,t1,t2);}

C_noret_decl(trf_7886)
static void C_ccall trf_7886(C_word c,C_word *av) C_noret;
static void C_ccall trf_7886(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7886(t0,t1,t2);}

C_noret_decl(trf_7920)
static void C_ccall trf_7920(C_word c,C_word *av) C_noret;
static void C_ccall trf_7920(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7920(t0,t1,t2);}

C_noret_decl(trf_7984)
static void C_ccall trf_7984(C_word c,C_word *av) C_noret;
static void C_ccall trf_7984(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7984(t0,t1,t2,t3);}

C_noret_decl(trf_8127)
static void C_ccall trf_8127(C_word c,C_word *av) C_noret;
static void C_ccall trf_8127(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_8127(t0,t1);}

C_noret_decl(trf_8139)
static void C_ccall trf_8139(C_word c,C_word *av) C_noret;
static void C_ccall trf_8139(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_8139(t0,t1);}

C_noret_decl(trf_8350)
static void C_ccall trf_8350(C_word c,C_word *av) C_noret;
static void C_ccall trf_8350(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_8350(t0,t1,t2,t3);}

C_noret_decl(trf_8398)
static void C_ccall trf_8398(C_word c,C_word *av) C_noret;
static void C_ccall trf_8398(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8398(t0,t1,t2);}

C_noret_decl(trf_8432)
static void C_ccall trf_8432(C_word c,C_word *av) C_noret;
static void C_ccall trf_8432(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_8432(t0,t1,t2,t3);}

C_noret_decl(trf_8468)
static void C_ccall trf_8468(C_word c,C_word *av) C_noret;
static void C_ccall trf_8468(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8468(t0,t1,t2);}

C_noret_decl(trf_8502)
static void C_ccall trf_8502(C_word c,C_word *av) C_noret;
static void C_ccall trf_8502(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8502(t0,t1,t2);}

C_noret_decl(trf_8557)
static void C_ccall trf_8557(C_word c,C_word *av) C_noret;
static void C_ccall trf_8557(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8557(t0,t1,t2);}

C_noret_decl(trf_8687)
static void C_ccall trf_8687(C_word c,C_word *av) C_noret;
static void C_ccall trf_8687(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8687(t0,t1,t2);}

C_noret_decl(trf_8734)
static void C_ccall trf_8734(C_word c,C_word *av) C_noret;
static void C_ccall trf_8734(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_8734(t0,t1,t2,t3,t4);}

C_noret_decl(trf_8753)
static void C_ccall trf_8753(C_word c,C_word *av) C_noret;
static void C_ccall trf_8753(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8753(t0,t1,t2);}

C_noret_decl(trf_8769)
static void C_ccall trf_8769(C_word c,C_word *av) C_noret;
static void C_ccall trf_8769(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8769(t0,t1,t2);}

C_noret_decl(trf_8883)
static void C_ccall trf_8883(C_word c,C_word *av) C_noret;
static void C_ccall trf_8883(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8883(t0,t1,t2);}

C_noret_decl(trf_8917)
static void C_ccall trf_8917(C_word c,C_word *av) C_noret;
static void C_ccall trf_8917(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_8917(t0,t1,t2,t3);}

C_noret_decl(trf_8961)
static void C_ccall trf_8961(C_word c,C_word *av) C_noret;
static void C_ccall trf_8961(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8961(t0,t1,t2);}

C_noret_decl(trf_8995)
static void C_ccall trf_8995(C_word c,C_word *av) C_noret;
static void C_ccall trf_8995(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_8995(t0,t1,t2,t3);}

C_noret_decl(trf_9033)
static void C_ccall trf_9033(C_word c,C_word *av) C_noret;
static void C_ccall trf_9033(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9033(t0,t1,t2);}

C_noret_decl(trf_9140)
static void C_ccall trf_9140(C_word c,C_word *av) C_noret;
static void C_ccall trf_9140(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9140(t0,t1,t2);}

C_noret_decl(trf_9174)
static void C_ccall trf_9174(C_word c,C_word *av) C_noret;
static void C_ccall trf_9174(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9174(t0,t1,t2);}

C_noret_decl(trf_9283)
static void C_ccall trf_9283(C_word c,C_word *av) C_noret;
static void C_ccall trf_9283(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9283(t0,t1,t2);}

C_noret_decl(trf_9316)
static void C_ccall trf_9316(C_word c,C_word *av) C_noret;
static void C_ccall trf_9316(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9316(t0,t1,t2);}

C_noret_decl(trf_9400)
static void C_ccall trf_9400(C_word c,C_word *av) C_noret;
static void C_ccall trf_9400(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9400(t0,t1,t2);}

C_noret_decl(trf_9418)
static void C_ccall trf_9418(C_word c,C_word *av) C_noret;
static void C_ccall trf_9418(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9418(t0,t1);}

C_noret_decl(trf_9433)
static void C_ccall trf_9433(C_word c,C_word *av) C_noret;
static void C_ccall trf_9433(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9433(t0,t1);}

C_noret_decl(trf_9563)
static void C_ccall trf_9563(C_word c,C_word *av) C_noret;
static void C_ccall trf_9563(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_9563(t0,t1,t2,t3);}

C_noret_decl(trf_9611)
static void C_ccall trf_9611(C_word c,C_word *av) C_noret;
static void C_ccall trf_9611(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_9611(t0,t1,t2,t3);}

C_noret_decl(trf_9659)
static void C_ccall trf_9659(C_word c,C_word *av) C_noret;
static void C_ccall trf_9659(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_9659(t0,t1,t2,t3,t4);}

C_noret_decl(trf_9666)
static void C_ccall trf_9666(C_word c,C_word *av) C_noret;
static void C_ccall trf_9666(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9666(t0,t1);}

C_noret_decl(trf_9800)
static void C_ccall trf_9800(C_word c,C_word *av) C_noret;
static void C_ccall trf_9800(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_9800(t0,t1,t2,t3);}

C_noret_decl(trf_9848)
static void C_ccall trf_9848(C_word c,C_word *av) C_noret;
static void C_ccall trf_9848(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_9848(t0,t1,t2,t3);}

C_noret_decl(trf_9896)
static void C_ccall trf_9896(C_word c,C_word *av) C_noret;
static void C_ccall trf_9896(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_9896(t0,t1,t2,t3,t4);}

C_noret_decl(trf_9903)
static void C_ccall trf_9903(C_word c,C_word *av) C_noret;
static void C_ccall trf_9903(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9903(t0,t1);}

C_noret_decl(trf_9966)
static void C_ccall trf_9966(C_word c,C_word *av) C_noret;
static void C_ccall trf_9966(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_9966(t0,t1,t2,t3);}

/* map-loop1788 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_fcall f_10014(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_10014,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,2,t6,t7);
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

/* map-loop1757 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_fcall f_10062(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_10062,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,2,t6,t7);
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

/* map-loop1727 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_fcall f_10110(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10110,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10135,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:493: g1733 */
t4=((C_word*)t0)[4];
f_9433(t4,t3);}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10133 in map-loop1727 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_ccall f_10135(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10135,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10110(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop1699 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_fcall f_10144(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10144,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10169,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:492: g1705 */
t4=((C_word*)t0)[4];
f_9418(t4,t3);}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10167 in map-loop1699 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_10169(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10169,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10144(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop1671 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in ... */
static void C_fcall f_10178(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10178,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10203,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:491: g1677 */
t4=((C_word*)t0)[4];
f_9400(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10201 in map-loop1671 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_10203(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10203,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10178(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop1644 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in ... */
static void C_fcall f_10212(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_10212,3,t0,t1,t2);}
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

/* map-loop1617 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_fcall f_10246(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_10246,3,t0,t1,t2);}
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

/* k10280 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in ... */
static void C_ccall f_10282(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10282,c,av);}
/* chicken-syntax.scm:445: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[183];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in ... */
static void C_ccall f_10284(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10284,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10288,a[2]=t2,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:449: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[183];
av2[3]=t2;
av2[4]=lf[184];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in ... */
static void C_ccall f_10288(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(19,c,3)))){
C_save_and_reclaim((void *)f_10288,c,av);}
a=C_alloc(19);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_u_i_cdr(t3);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=C_i_check_list_2(t2,lf[68]);
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10302,a[2]=((C_word*)t0)[3],a[3]=t4,a[4]=((C_word*)t0)[4],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10899,a[2]=t7,a[3]=t12,a[4]=t8,a[5]=((C_word)li115),tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_10899(t14,t10,t2);}

/* k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in ... */
static void C_ccall f_10302(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10302,c,av);}
a=C_alloc(25);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10306,a[2]=((C_word*)t0)[2],a[3]=((C_word)li103),tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10317,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10865,a[2]=t4,a[3]=t9,a[4]=t6,a[5]=t5,a[6]=((C_word)li114),tmp=(C_word)a,a+=7,tmp));
t11=((C_word*)t9)[1];
f_10865(t11,t7,((C_word*)t0)[5]);}

/* g1320 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_fcall f_10306(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_10306,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10314,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:453: chicken.base#gensym */
t3=*((C_word*)lf[57]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k10312 in g1320 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_ccall f_10314(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10314,c,av);}
/* chicken-syntax.scm:453: r */
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

/* k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_ccall f_10317(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10317,c,av);}
a=C_alloc(25);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10321,a[2]=((C_word*)t0)[2],a[3]=((C_word)li104),tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10332,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=t1,a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10831,a[2]=t4,a[3]=t9,a[4]=t6,a[5]=t5,a[6]=((C_word)li113),tmp=(C_word)a,a+=7,tmp));
t11=((C_word*)t9)[1];
f_10831(t11,t7,((C_word*)t0)[6]);}

/* g1348 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_fcall f_10321(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_10321,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10329,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:454: chicken.base#gensym */
t3=*((C_word*)lf[57]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k10327 in g1348 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in ... */
static void C_ccall f_10329(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10329,c,av);}
/* chicken-syntax.scm:454: r */
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

/* k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_ccall f_10332(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(33,c,3)))){
C_save_and_reclaim((void *)f_10332,c,av);}
a=C_alloc(33);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10339,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t8=t7;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=((C_word*)t9)[1];
t11=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_10652,a[2]=((C_word*)t0)[5],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[6],a[6]=t5,a[7]=t6,tmp=(C_word)a,a+=8,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10797,a[2]=t9,a[3]=t13,a[4]=t10,a[5]=((C_word)li112),tmp=(C_word)a,a+=6,tmp));
t15=((C_word*)t13)[1];
f_10797(t15,t11,((C_word*)t0)[6]);}

/* k10337 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in ... */
static void C_ccall f_10339(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(26,c,4)))){
C_save_and_reclaim((void *)f_10339,c,av);}
a=C_alloc(26);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_10507,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(((C_word*)t0)[4],lf[68]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10522,a[2]=t2,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10596,a[2]=t5,a[3]=t10,a[4]=t6,a[5]=((C_word)li108),tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_10596(t12,t8,((C_word*)t0)[5],((C_word*)t0)[4]);}

/* k10361 in k10505 in k10337 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_10363(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,1)))){
C_save_and_reclaim((void *)f_10363,c,av);}
a=C_alloc(27);
t2=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,t1);
t3=C_a_i_cons(&a,2,lf[23],t2);
t4=C_a_i_list(&a,4,lf[179],((C_word*)t0)[2],((C_word*)t0)[3],t3);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[5],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k10373 in k10505 in k10337 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_10375(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(20,c,4)))){
C_save_and_reclaim((void *)f_10375,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10379,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10391,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10401,a[2]=t5,a[3]=t9,a[4]=t6,a[5]=((C_word)li105),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_10401(t11,t7,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* k10377 in k10373 in k10505 in k10337 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_10379(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10379,c,av);}
/* chicken-syntax.scm:455: ##sys#append */
t2=*((C_word*)lf[56]+1);{
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

/* k10389 in k10373 in k10505 in k10337 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_10391(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_10391,c,av);}
a=C_alloc(6);
t2=C_a_i_list(&a,1,lf[166]);
t3=C_a_i_list(&a,1,t2);
/* chicken-syntax.scm:455: ##sys#append */
t4=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* map-loop1571 in k10373 in k10505 in k10337 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_fcall f_10401(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_10401,4,t0,t1,t2,t3);}
a=C_alloc(12);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,3,lf[180],t6,t7);
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

/* map-loop1535 in k10505 in k10337 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_fcall f_10449(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_10449,4,t0,t1,t2,t3);}
a=C_alloc(12);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,3,lf[180],t6,t7);
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

/* k10505 in k10337 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in ... */
static void C_ccall f_10507(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(36,c,4)))){
C_save_and_reclaim((void *)f_10507,c,av);}
a=C_alloc(36);
t2=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,t1);
t3=C_a_i_cons(&a,2,lf[23],t2);
t4=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,((C_word*)t0)[2]);
t5=C_a_i_cons(&a,2,lf[23],t4);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10363,a[2]=t3,a[3]=t5,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t7=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t8=t7;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=((C_word*)t9)[1];
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10375,a[2]=t6,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10449,a[2]=t9,a[3]=t13,a[4]=t10,a[5]=((C_word)li106),tmp=(C_word)a,a+=6,tmp));
t15=((C_word*)t13)[1];
f_10449(t15,t11,((C_word*)t0)[7],((C_word*)t0)[5]);}

/* k10520 in k10337 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in ... */
static void C_ccall f_10522(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(20,c,4)))){
C_save_and_reclaim((void *)f_10522,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10526,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10538,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10548,a[2]=t5,a[3]=t9,a[4]=t6,a[5]=((C_word)li107),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_10548(t11,t7,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* k10524 in k10520 in k10337 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_10526(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10526,c,av);}
/* chicken-syntax.scm:455: ##sys#append */
t2=*((C_word*)lf[56]+1);{
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

/* k10536 in k10520 in k10337 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_10538(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_10538,c,av);}
a=C_alloc(6);
t2=C_a_i_list(&a,1,lf[166]);
t3=C_a_i_list(&a,1,t2);
/* chicken-syntax.scm:455: ##sys#append */
t4=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* map-loop1499 in k10520 in k10337 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_fcall f_10548(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_10548,4,t0,t1,t2,t3);}
a=C_alloc(12);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,3,lf[180],t6,t7);
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

/* map-loop1463 in k10337 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in ... */
static void C_fcall f_10596(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_10596,4,t0,t1,t2,t3);}
a=C_alloc(12);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,3,lf[180],t6,t7);
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

/* k10650 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in ... */
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
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_10652,c,av);}
a=C_alloc(13);
t2=C_i_check_list_2(((C_word*)t0)[2],lf[68]);
t3=C_i_check_list_2(t1,lf[68]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10661,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10749,a[2]=((C_word*)t0)[6],a[3]=t6,a[4]=((C_word*)t0)[7],a[5]=((C_word)li111),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_10749(t8,t4,((C_word*)t0)[2],t1);}

/* k10659 in k10650 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in ... */
static void C_ccall f_10661(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10661,c,av);}
a=C_alloc(18);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10668,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t4,a[6]=t5,tmp=(C_word)a,a+=7,tmp);
t7=C_u_i_length(((C_word*)t0)[4]);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10729,a[2]=t9,a[3]=((C_word)li110),tmp=(C_word)a,a+=4,tmp));
t11=((C_word*)t9)[1];
f_10729(t11,t6,t7);}

/* k10666 in k10659 in k10650 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_10668(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10668,c,av);}
a=C_alloc(12);
t2=C_i_check_list_2(((C_word*)t0)[2],lf[68]);
t3=C_i_check_list_2(t1,lf[68]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10677,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10679,a[2]=((C_word*)t0)[5],a[3]=t6,a[4]=((C_word*)t0)[6],a[5]=((C_word)li109),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_10679(t8,t4,((C_word*)t0)[2],t1);}

/* k10675 in k10666 in k10659 in k10650 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_10677(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10677,c,av);}
/* chicken-syntax.scm:455: ##sys#append */
t2=*((C_word*)lf[56]+1);{
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

/* map-loop1429 in k10666 in k10659 in k10650 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_fcall f_10679(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_10679,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,2,t6,t7);
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

/* loop in k10659 in k10650 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_fcall f_10729(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_10729,3,t0,t1,t2);}
a=C_alloc(3);
t3=C_eqp(t2,C_fix(0));
if(C_truep(t3)){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10743,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:461: loop */
t6=t4;
t7=C_fixnum_difference(t2,C_fix(1));
t1=t6;
t2=t7;
goto loop;}}

/* k10741 in loop in k10659 in k10650 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_10743(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_10743,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,C_SCHEME_FALSE,t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop1372 in k10650 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in ... */
static void C_fcall f_10749(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_10749,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,2,t6,t7);
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

/* map-loop1393 in k10330 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in ... */
static void C_fcall f_10797(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_10797,3,t0,t1,t2);}
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

/* map-loop1342 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_fcall f_10831(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10831,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10856,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:454: g1348 */
t4=((C_word*)t0)[4];
f_10321(t4,t3);}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10854 in map-loop1342 in k10315 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in ... */
static void C_ccall f_10856(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10856,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10831(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop1314 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_fcall f_10865(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10865,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10890,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:453: g1320 */
t4=((C_word*)t0)[4];
f_10306(t4,t3);}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10888 in map-loop1314 in k10300 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_ccall f_10890(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10890,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10865(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop1287 in k10286 in a10283 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in ... */
static void C_fcall f_10899(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_10899,3,t0,t1,t2);}
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

/* k10933 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in ... */
static void C_ccall f_10935(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10935,c,av);}
/* chicken-syntax.scm:438: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[185];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a10936 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in ... */
static void C_ccall f_10937(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10937,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10941,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:442: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[185];
av2[3]=t2;
av2[4]=lf[188];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k10939 in a10936 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in ... */
static void C_ccall f_10941(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_10941,c,av);}
a=C_alloc(9);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,3,lf[186],t2,*((C_word*)lf[187]+1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k10950 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in ... */
static void C_ccall f_10952(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10952,c,av);}
/* chicken-syntax.scm:431: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[189];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a10953 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in ... */
static void C_ccall f_10954(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10954,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10958,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:435: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[189];
av2[3]=t2;
av2[4]=lf[190];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k10956 in a10953 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in ... */
static void C_ccall f_10958(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_10958,c,av);}
a=C_alloc(9);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,3,lf[186],t2,C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k10967 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in ... */
static void C_ccall f_10969(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10969,c,av);}
/* chicken-syntax.scm:423: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[191];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a10970 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in ... */
static void C_ccall f_10971(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10971,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10975,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:428: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[191];
av2[3]=t2;
av2[4]=lf[193];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k10973 in a10970 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in ... */
static void C_ccall f_10975(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,1)))){
C_save_and_reclaim((void *)f_10975,c,av);}
a=C_alloc(15);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_a_i_list(&a,3,lf[23],C_SCHEME_END_OF_LIST,t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,2,lf[192],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k10988 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in ... */
static void C_ccall f_10990(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10990,c,av);}
/* chicken-syntax.scm:417: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[194];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a10991 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in ... */
static void C_ccall f_10992(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_10992,c,av);}
a=C_alloc(3);
t5=C_i_cdr(t2);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_cons(&a,2,lf[195],t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k11002 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in ... */
static void C_ccall f_11004(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11004,c,av);}
/* chicken-syntax.scm:398: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[196];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a11005 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in ... */
static void C_ccall f_11006(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11006,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11010,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:403: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[196];
av2[3]=t2;
av2[4]=lf[199];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k11008 in a11005 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in ... */
static void C_ccall f_11010(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11010,c,av);}
a=C_alloc(15);
t2=C_i_cddr(((C_word*)t0)[2]);
if(C_truep(C_i_nullp(t2))){
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,t3);
t5=C_a_i_cons(&a,2,lf[23],t4);
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,3,lf[28],t5,lf[197]);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11032,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:407: ##sys#check-syntax */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[196];
av2[3]=((C_word*)t0)[2];
av2[4]=lf[198];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* k11030 in k11008 in a11005 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in ... */
static void C_ccall f_11032(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,1)))){
C_save_and_reclaim((void *)f_11032,c,av);}
a=C_alloc(24);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_i_caddr(((C_word*)t0)[2]);
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=C_u_i_cdr(t4);
t6=C_u_i_cdr(t5);
t7=C_i_pairp(t2);
t8=(C_truep(t7)?C_i_nullp(C_u_i_cdr(t2)):C_SCHEME_FALSE);
if(C_truep(t8)){
t9=C_i_car(t2);
t10=C_a_i_list(&a,2,t9,t3);
t11=C_a_i_list(&a,1,t10);
t12=C_a_i_cons(&a,2,t11,t6);
t13=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t13;
av2[1]=C_a_i_cons(&a,2,lf[38],t12);
((C_proc)(void*)(*((C_word*)t13+1)))(2,av2);}}
else{
t9=C_a_i_list(&a,3,lf[23],C_SCHEME_END_OF_LIST,t3);
t10=C_a_i_cons(&a,2,t2,t6);
t11=C_a_i_cons(&a,2,lf[23],t10);
t12=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t12;
av2[1]=C_a_i_list(&a,3,lf[28],t9,t11);
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}}

/* k11095 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in ... */
static void C_ccall f_11097(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11097,c,av);}
/* chicken-syntax.scm:326: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[200];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in ... */
static void C_ccall f_11099(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11099,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11103,a[2]=t2,a[3]=t4,a[4]=t1,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:330: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[200];
av2[3]=t2;
av2[4]=lf[210];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in ... */
static void C_ccall f_11103(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_11103,c,av);}
a=C_alloc(7);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11109,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:332: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[40]+1);{
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

/* k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in ... */
static void C_ccall f_11109(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_11109,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11112,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,tmp=(C_word)a,a+=8,tmp);
/* chicken-syntax.scm:333: scheme#symbol->string */
t3=*((C_word*)lf[122]+1);{
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

/* k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in ... */
static void C_ccall f_11112(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_11112,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11115,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11477,a[2]=t2,a[3]=((C_word*)t0)[7],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:334: ##sys#current-module */
t4=*((C_word*)lf[86]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in ... */
static void C_ccall f_11115(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_11115,c,av);}
a=C_alloc(9);
t2=C_i_cddr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_11121,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* chicken-syntax.scm:339: r */
t4=((C_word*)t0)[7];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[82];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in ... */
static void C_ccall f_11121(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_11121,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_11124,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:340: r */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[209];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in ... */
static void C_ccall f_11124(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_11124,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_11127,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:341: r */
t3=((C_word*)t0)[9];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[81];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in ... */
static void C_ccall f_11127(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(28,c,3)))){
C_save_and_reclaim((void *)f_11127,c,av);}
a=C_alloc(28);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11131,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li122),tmp=(C_word)a,a+=5,tmp);
t7=C_i_check_list_2(((C_word*)t0)[4],lf[68]);
t8=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_11191,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=t1,a[7]=((C_word*)t0)[9],a[8]=((C_word*)t0)[4],tmp=(C_word)a,a+=9,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11442,a[2]=t4,a[3]=t10,a[4]=t6,a[5]=t5,a[6]=((C_word)li124),tmp=(C_word)a,a+=7,tmp));
t12=((C_word*)t10)[1];
f_11442(t12,t8,((C_word*)t0)[4]);}

/* g1174 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in ... */
static void C_fcall f_11131(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,4)))){
C_save_and_reclaim_args((void *)trf_11131,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_symbolp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11144,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_pairp(t2))){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11159,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:346: c */
t5=((C_word*)t0)[2];{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=C_u_i_car(t2);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
/* chicken-syntax.scm:352: chicken.syntax#syntax-error */
t4=*((C_word*)lf[59]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=lf[200];
av2[3]=lf[201];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}}

/* k11142 in g1174 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_fcall f_11144(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_11144,2,t0,t1);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_i_cadr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* chicken-syntax.scm:352: chicken.syntax#syntax-error */
t2=*((C_word*)lf[59]+1);{
C_word av2[5];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[200];
av2[3]=lf[201];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* k11157 in g1174 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_ccall f_11159(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11159,c,av);}
if(C_truep(t1)){
if(C_truep(C_i_pairp(C_u_i_cdr(((C_word*)t0)[2])))){
t2=C_i_cadr(((C_word*)t0)[2]);
if(C_truep(C_i_symbolp(t2))){
t3=C_u_i_cdr(((C_word*)t0)[2]);
if(C_truep(C_i_nullp(C_u_i_cdr(t3)))){
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_cadr(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* chicken-syntax.scm:352: chicken.syntax#syntax-error */
t4=*((C_word*)lf[59]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[200];
av2[3]=lf[201];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}
else{
/* chicken-syntax.scm:352: chicken.syntax#syntax-error */
t3=*((C_word*)lf[59]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[200];
av2[3]=lf[201];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}
else{
t2=((C_word*)t0)[4];
f_11144(t2,C_SCHEME_FALSE);}}
else{
t2=((C_word*)t0)[4];
f_11144(t2,C_SCHEME_FALSE);}}

/* k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in ... */
static void C_ccall f_11191(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(28,c,3)))){
C_save_and_reclaim((void *)f_11191,c,av);}
a=C_alloc(28);
t2=C_a_i_list(&a,2,lf[39],((C_word*)t0)[2]);
t3=C_a_i_list(&a,3,((C_word*)t0)[3],((C_word*)t0)[4],t2);
t4=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_11414,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=t3,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11434,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
t6=*((C_word*)lf[206]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[208];
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k11220 in k11386 in k11412 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in ... */
static void C_ccall f_11222(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_11222,c,av);}
a=C_alloc(12);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=C_a_i_cons(&a,2,((C_word*)t0)[4],t3);
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_cons(&a,2,lf[29],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* mapslots in k11386 in k11412 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in ... */
static void C_fcall f_11224(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,2)))){
C_save_and_reclaim_args((void *)trf_11224,4,t0,t1,t2,t3);}
a=C_alloc(11);
t4=C_eqp(t2,C_SCHEME_END_OF_LIST);
if(C_truep(t4)){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_i_car(t2);
t6=C_i_symbolp(t5);
t7=C_i_not(t6);
t8=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_11240,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=t2,a[7]=t7,a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[5],a[10]=((C_word*)t0)[6],tmp=(C_word)a,a+=11,tmp);
if(C_truep(t7)){
/* chicken-syntax.scm:370: scheme#symbol->string */
t9=*((C_word*)lf[122]+1);{
C_word av2[3];
av2[0]=t9;
av2[1]=t8;
av2[2]=C_i_cadr(t5);
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
/* chicken-syntax.scm:370: scheme#symbol->string */
t9=*((C_word*)lf[122]+1);{
C_word av2[3];
av2[0]=t9;
av2[1]=t8;
av2[2]=t5;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}}}

/* k11238 in mapslots in k11386 in k11412 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in ... */
static void C_ccall f_11240(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,5)))){
C_save_and_reclaim((void *)f_11240,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_11243,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=t1,tmp=(C_word)a,a+=12,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11373,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:371: scheme#string-append */
t4=*((C_word*)lf[41]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[10];
av2[3]=lf[204];
av2[4]=t1;
av2[5]=lf[205];
((C_proc)(void*)(*((C_word*)t4+1)))(6,av2);}}

/* k11241 in k11238 in mapslots in k11386 in k11412 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_11243(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,4)))){
C_save_and_reclaim((void *)f_11243,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_11246,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t1,tmp=(C_word)a,a+=11,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11369,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:372: scheme#string-append */
t4=*((C_word*)lf[41]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[10];
av2[3]=lf[203];
av2[4]=((C_word*)t0)[11];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k11244 in k11241 in k11238 in mapslots in k11386 in k11412 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_11246(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(79,c,2)))){
C_save_and_reclaim((void *)f_11246,c,av);}
a=C_alloc(79);
t2=C_a_i_list(&a,2,lf[80],lf[202]);
t3=C_a_i_list(&a,2,lf[39],((C_word*)t0)[2]);
t4=C_a_i_list(&a,3,lf[74],lf[80],t3);
t5=C_a_i_list(&a,2,lf[35],t4);
t6=C_a_i_list(&a,4,lf[77],lf[80],((C_word*)t0)[3],lf[202]);
t7=C_a_i_list(&a,4,lf[23],t2,t5,t6);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11272,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t9=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_11276,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[8],a[6]=t7,a[7]=((C_word*)t0)[9],a[8]=t1,a[9]=t8,tmp=(C_word)a,a+=10,tmp);
if(C_truep(((C_word*)t0)[7])){
t10=t9;
f_11276(t10,C_SCHEME_END_OF_LIST);}
else{
t10=C_a_i_list(&a,3,((C_word*)t0)[9],((C_word*)t0)[10],t7);
t11=t9;
f_11276(t11,C_a_i_list(&a,1,t10));}}

/* k11258 in k11270 in k11244 in k11241 in k11238 in mapslots in k11386 in k11412 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_ccall f_11260(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_11260,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k11270 in k11244 in k11241 in k11238 in mapslots in k11386 in k11412 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_ccall f_11272(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_11272,c,av);}
a=C_alloc(7);
t2=C_a_i_cons(&a,2,lf[29],t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11260,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:396: mapslots */
t4=((C_word*)((C_word*)t0)[3])[1];
f_11224(t4,t3,C_slot(((C_word*)t0)[4],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* k11274 in k11244 in k11241 in k11238 in mapslots in k11386 in k11412 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_fcall f_11276(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(66,0,3)))){
C_save_and_reclaim_args((void *)trf_11276,2,t0,t1);}
a=C_alloc(66);
if(C_truep(((C_word*)t0)[2])){
t2=C_a_i_list(&a,1,lf[80]);
t3=C_a_i_list(&a,2,lf[39],((C_word*)t0)[3]);
t4=C_a_i_list(&a,3,lf[74],lf[80],t3);
t5=C_a_i_list(&a,2,lf[35],t4);
t6=C_a_i_list(&a,3,lf[75],lf[80],((C_word*)t0)[4]);
t7=C_a_i_list(&a,4,lf[23],t2,t5,t6);
t8=C_a_i_list(&a,3,((C_word*)t0)[5],t7,((C_word*)t0)[6]);
t9=C_a_i_list(&a,3,((C_word*)t0)[7],((C_word*)t0)[8],t8);
t10=C_a_i_list(&a,1,t9);
/* chicken-syntax.scm:379: ##sys#append */
t11=*((C_word*)lf[56]+1);{
C_word av2[4];
av2[0]=t11;
av2[1]=((C_word*)t0)[9];
av2[2]=t1;
av2[3]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(4,av2);}}
else{
t2=C_a_i_list(&a,1,lf[80]);
t3=C_a_i_list(&a,2,lf[39],((C_word*)t0)[3]);
t4=C_a_i_list(&a,3,lf[74],lf[80],t3);
t5=C_a_i_list(&a,2,lf[35],t4);
t6=C_a_i_list(&a,3,lf[75],lf[80],((C_word*)t0)[4]);
t7=C_a_i_list(&a,4,lf[23],t2,t5,t6);
t8=C_a_i_list(&a,3,((C_word*)t0)[7],((C_word*)t0)[8],t7);
t9=C_a_i_list(&a,1,t8);
/* chicken-syntax.scm:379: ##sys#append */
t10=*((C_word*)lf[56]+1);{
C_word av2[4];
av2[0]=t10;
av2[1]=((C_word*)t0)[9];
av2[2]=t1;
av2[3]=t9;
((C_proc)(void*)(*((C_word*)t10+1)))(4,av2);}}}

/* k11367 in k11241 in k11238 in mapslots in k11386 in k11412 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_11369(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11369,c,av);}
/* chicken-syntax.scm:372: scheme#string->symbol */
t2=*((C_word*)lf[121]+1);{
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

/* k11371 in k11238 in mapslots in k11386 in k11412 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_11373(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11373,c,av);}
/* chicken-syntax.scm:371: scheme#string->symbol */
t2=*((C_word*)lf[121]+1);{
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

/* k11386 in k11412 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_ccall f_11388(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(52,c,4)))){
C_save_and_reclaim((void *)f_11388,c,av);}
a=C_alloc(52);
t2=C_a_i_list(&a,1,lf[80]);
t3=C_a_i_list(&a,2,lf[39],((C_word*)t0)[2]);
t4=C_a_i_list(&a,3,lf[73],lf[80],t3);
t5=C_a_i_list(&a,3,lf[23],t2,t4);
t6=C_a_i_list(&a,3,((C_word*)t0)[3],t1,t5);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11222,a[2]=t6,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11224,a[2]=((C_word*)t0)[2],a[3]=t9,a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[8],a[7]=((C_word)li123),tmp=(C_word)a,a+=8,tmp));
t11=((C_word*)t9)[1];
f_11224(t11,t7,((C_word*)t0)[9],C_fix(1));}

/* k11406 in k11412 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_ccall f_11408(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11408,c,av);}
/* chicken-syntax.scm:363: scheme#string->symbol */
t2=*((C_word*)lf[121]+1);{
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

/* k11412 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_ccall f_11414(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(43,c,3)))){
C_save_and_reclaim((void *)f_11414,c,av);}
a=C_alloc(43);
t2=C_a_i_list(&a,2,lf[39],((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t2,((C_word*)t0)[3]);
t4=C_a_i_cons(&a,2,lf[72],t3);
t5=C_a_i_list(&a,3,lf[23],((C_word*)t0)[3],t4);
t6=C_a_i_list(&a,3,((C_word*)t0)[4],t1,t5);
t7=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_11388,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=t6,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11408,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
t9=*((C_word*)lf[206]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t9;
av2[1]=t8;
av2[2]=((C_word*)t0)[8];
av2[3]=lf[207];
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}

/* k11432 in k11189 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_ccall f_11434(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11434,c,av);}
/* chicken-syntax.scm:358: scheme#string->symbol */
t2=*((C_word*)lf[121]+1);{
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

/* map-loop1168 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in ... */
static void C_fcall f_11442(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_11442,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11467,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:343: g1174 */
t4=((C_word*)t0)[4];
f_11131(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k11465 in map-loop1168 in k11125 in k11122 in k11119 in k11113 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_ccall f_11467(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11467,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_11442(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k11475 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in ... */
static void C_ccall f_11477(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_11477,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11484,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11488,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:336: ##sys#current-module */
t4=*((C_word*)lf[86]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
f_11115(2,av2);}}}

/* k11482 in k11475 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in ... */
static void C_ccall f_11484(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11484,c,av);}
/* chicken-syntax.scm:335: chicken.base#symbol-append */
t2=*((C_word*)lf[83]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[84];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k11486 in k11475 in k11110 in k11107 in k11101 in a11098 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in ... */
static void C_ccall f_11488(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11488,c,av);}
/* chicken-syntax.scm:336: ##sys#module-name */
t2=*((C_word*)lf[85]+1);{
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

/* k11490 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in ... */
static void C_ccall f_11492(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11492,c,av);}
/* chicken-syntax.scm:318: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[211];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a11493 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in ... */
static void C_ccall f_11494(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11494,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11498,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:323: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[211];
av2[3]=t2;
av2[4]=lf[213];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k11496 in a11493 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in ... */
static void C_ccall f_11498(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_11498,c,av);}
a=C_alloc(3);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[212],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k11507 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11509(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11509,c,av);}
/* chicken-syntax.scm:304: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[214];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11511(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_11511,c,av);}
a=C_alloc(14);
t5=C_i_cdr(t2);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11521,a[2]=t5,a[3]=t1,a[4]=t3,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_pairp(t5))){
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11550,a[2]=t5,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11606,a[2]=t5,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:306: ##sys#list? */
t9=*((C_word*)lf[221]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=C_i_car(t5);
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
t7=t6;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_FALSE;
f_11521(2,av2);}}}

/* k11519 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 in ... */
static void C_ccall f_11521(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11521,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=C_i_car(((C_word*)t0)[2]);
t3=C_i_cdr(((C_word*)t0)[2]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11534,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:306: rename1102 */
t5=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[215];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
/* chicken-syntax.scm:306: chicken.internal.syntax-rules#syntax-rules-mismatch */
t2=*((C_word*)lf[216]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}}

/* k11532 in k11519 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in ... */
static void C_ccall f_11534(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_11534,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,t1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k11548 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 in ... */
static void C_ccall f_11550(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_11550,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11556,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:306: ##sys#list? */
t3=*((C_word*)lf[221]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cdr(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_11521(2,av2);}}}

/* k11554 in k11548 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in ... */
static void C_ccall f_11556(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_11556,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11559,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:306: ##sys#length */
t3=*((C_word*)lf[220]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cdr(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_11521(2,av2);}}}

/* k11557 in k11554 in k11548 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in ... */
static void C_ccall f_11559(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_11559,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11565,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:306: ##sys#>= */
t3=*((C_word*)lf[219]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k11563 in k11557 in k11554 in k11548 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in ... */
static void C_ccall f_11565(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11565,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=C_i_cdr(((C_word*)t0)[2]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11574,a[2]=t4,a[3]=((C_word)li127),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_11574(t6,((C_word*)t0)[3],t2,((C_word*)t0)[4]);}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_11521(2,av2);}}}

/* loop1099 in k11563 in k11557 in k11554 in k11548 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in ... */
static void C_fcall f_11574(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_11574,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11581,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:306: ##sys#= */
t5=*((C_word*)lf[218]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k11579 in loop1099 in k11563 in k11557 in k11554 in k11548 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in ... */
static void C_ccall f_11581(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_11581,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(((C_word*)t0)[3],C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_i_cdr(((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11595,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:306: ##sys#+ */
t4=*((C_word*)lf[217]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=C_fix(-1);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k11593 in k11579 in loop1099 in k11563 in k11557 in k11554 in k11548 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in ... */
static void C_ccall f_11595(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11595,c,av);}
/* chicken-syntax.scm:306: loop1099 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_11574(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k11604 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 in ... */
static void C_ccall f_11606(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_11606,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11609,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:306: ##sys#length */
t3=*((C_word*)lf[220]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_car(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_11550(2,av2);}}}

/* k11607 in k11604 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in ... */
static void C_ccall f_11609(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_11609,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11615,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:306: ##sys#>= */
t3=*((C_word*)lf[219]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k11613 in k11607 in k11604 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in ... */
static void C_ccall f_11615(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11615,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=C_i_car(((C_word*)t0)[2]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11624,a[2]=t4,a[3]=((C_word)li128),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_11624(t6,((C_word*)t0)[3],t2,((C_word*)t0)[4]);}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_11550(2,av2);}}}

/* loop1099 in k11613 in k11607 in k11604 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in ... */
static void C_fcall f_11624(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_11624,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11631,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:306: ##sys#= */
t5=*((C_word*)lf[218]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k11629 in loop1099 in k11613 in k11607 in k11604 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in ... */
static void C_ccall f_11631(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_11631,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(((C_word*)t0)[3],C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_i_cdr(((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11645,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:306: ##sys#+ */
t4=*((C_word*)lf[217]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=C_fix(-1);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k11643 in k11629 in loop1099 in k11613 in k11607 in k11604 in a11510 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in ... */
static void C_ccall f_11645(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11645,c,av);}
/* chicken-syntax.scm:306: loop1099 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_11624(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k11655 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11657(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11657,c,av);}
/* chicken-syntax.scm:296: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[222];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a11658 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11659(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_11659,c,av);}
a=C_alloc(6);
t5=C_i_cdr(t2);
t6=C_i_pairp(t5);
t7=(C_truep(t6)?C_eqp(C_i_cdr(t5),C_SCHEME_END_OF_LIST):C_SCHEME_FALSE);
if(C_truep(t7)){
t8=C_i_car(t5);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11679,a[2]=t8,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:298: rename1068 */
t10=t3;{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=lf[223];
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11693,a[2]=t5,a[3]=t1,a[4]=t3,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_pairp(t5))){
t9=C_i_cdr(t5);
t10=C_i_pairp(t9);
t11=t8;
f_11693(t11,(C_truep(t10)?C_eqp(C_i_cdr(t9),C_SCHEME_END_OF_LIST):C_SCHEME_FALSE));}
else{
t9=t8;
f_11693(t9,C_SCHEME_FALSE);}}}

/* k11677 in a11658 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11679(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_11679,c,av);}
a=C_alloc(9);
t2=C_a_i_cons(&a,2,C_SCHEME_FALSE,C_SCHEME_END_OF_LIST);
t3=C_a_i_cons(&a,2,((C_word*)t0)[2],t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_cons(&a,2,t1,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k11691 in a11658 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_11693(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_11693,2,t0,t1);}
a=C_alloc(5);
if(C_truep(t1)){
t2=C_i_car(((C_word*)t0)[2]);
t3=C_i_cdr(((C_word*)t0)[2]);
t4=C_i_car(t3);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11706,a[2]=t4,a[3]=t2,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:298: rename1068 */
t6=((C_word*)t0)[4];{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[223];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
/* chicken-syntax.scm:298: chicken.internal.syntax-rules#syntax-rules-mismatch */
t2=*((C_word*)lf[216]+1);{
C_word av2[3];
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}}

/* k11704 in k11691 in a11658 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 in ... */
static void C_ccall f_11706(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_11706,c,av);}
a=C_alloc(9);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],C_SCHEME_END_OF_LIST);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_cons(&a,2,t1,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k11752 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11754(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11754,c,av);}
/* chicken-syntax.scm:285: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
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

/* a11755 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11756(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11756,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11760,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:289: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[224];
av2[3]=t2;
av2[4]=lf[226];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k11758 in a11755 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11760(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11760,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11767,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:290: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[225];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k11765 in k11758 in a11755 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11767(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11767,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11775,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:291: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[82];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k11773 in k11765 in k11758 in a11755 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 in ... */
static void C_ccall f_11775(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_11775,c,av);}
a=C_alloc(9);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t1,t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,2,((C_word*)t0)[4],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k11781 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11783(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11783,c,av);}
/* chicken-syntax.scm:277: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[225];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a11784 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11785(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11785,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11789,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:281: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[225];
av2[3]=t2;
av2[4]=lf[229];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k11787 in a11784 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11789(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_11789,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11792,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_i_cdr(((C_word*)t0)[2]);
t4=C_a_i_cons(&a,2,lf[29],t3);
/* chicken-syntax.scm:282: ##sys#register-meta-expression */
t5=*((C_word*)lf[228]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k11790 in k11787 in a11784 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11792(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_11792,c,av);}
a=C_alloc(9);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[29],t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,2,lf[227],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k11811 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11813(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11813,c,av);}
/* chicken-syntax.scm:269: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[230];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a11814 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11815(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11815,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11819,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:274: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[230];
av2[3]=t2;
av2[4]=lf[232];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k11817 in a11814 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11819(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_11819,c,av);}
a=C_alloc(6);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,2,lf[231],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k11828 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11830(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11830,c,av);}
/* chicken-syntax.scm:244: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[233];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a11831 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11832(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11832,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11836,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:248: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[233];
av2[3]=t2;
av2[4]=lf[241];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k11834 in a11831 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11836(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11836,c,av);}
a=C_alloc(5);
t2=C_i_memq(lf[234],*((C_word*)lf[235]+1));
if(C_truep(C_i_not(t2))){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=lf[236];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11845,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:251: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[40]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_cadr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k11843 in k11834 in a11831 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11845(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11845,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11848,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:252: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[240];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k11846 in k11843 in k11834 in a11831 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11848(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11848,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11851,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:253: chicken.syntax#strip-syntax */
t3=*((C_word*)lf[40]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_caddr(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k11849 in k11846 in k11843 in k11834 in a11831 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11851(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,4)))){
C_save_and_reclaim((void *)f_11851,c,av);}
a=C_alloc(18);
t2=C_a_i_list(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_list(&a,2,((C_word*)t0)[2],lf[237]);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11874,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t3,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:259: chicken.compiler.scrutinizer#check-and-validate-type */
t5=*((C_word*)lf[239]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=t1;
av2[3]=lf[233];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k11872 in k11849 in k11846 in k11843 in k11834 in a11831 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11874(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,1)))){
C_save_and_reclaim((void *)f_11874,c,av);}
a=C_alloc(24);
t2=C_a_i_list(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_list(&a,4,lf[238],((C_word*)t0)[3],((C_word*)t0)[4],t2);
t4=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,2,lf[227],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k11888 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11890(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11890,c,av);}
/* chicken-syntax.scm:219: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
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

/* a11891 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11892(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11892,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11896,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:223: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[242];
av2[3]=t2;
av2[4]=lf[245];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k11894 in a11891 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11896(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11896,c,av);}
a=C_alloc(5);
t2=C_i_memq(lf[234],*((C_word*)lf[235]+1));
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11902,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:225: chicken.base#gensym */
t4=*((C_word*)lf[57]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k11900 in k11894 in a11891 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11902(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_11902,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11905,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:226: chicken.syntax#get-line-number */
t3=*((C_word*)lf[44]+1);{
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

/* k11903 in k11900 in k11894 in a11891 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11905(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(33,c,3)))){
C_save_and_reclaim((void *)f_11905,c,av);}
a=C_alloc(33);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_a_i_list(&a,2,((C_word*)t0)[3],t2);
t4=C_a_i_list(&a,1,t3);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11929,a[2]=((C_word*)t0)[4],a[3]=((C_word)li135),tmp=(C_word)a,a+=4,tmp);
t10=C_u_i_cdr(((C_word*)t0)[2]);
t11=C_u_i_cdr(t10);
t12=C_i_check_list_2(t11,lf[68]);
t13=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11967,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[5],a[5]=t4,tmp=(C_word)a,a+=6,tmp);
t14=C_SCHEME_UNDEFINED;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11969,a[2]=t7,a[3]=t15,a[4]=t9,a[5]=t8,a[6]=((C_word)li136),tmp=(C_word)a,a+=7,tmp));
t17=((C_word*)t15)[1];
f_11969(t17,t13,t11);}

/* g985 in k11903 in k11900 in k11894 in a11891 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_11929(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_11929,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11933,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:232: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[40]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_car(t2);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k11931 in g985 in k11903 in k11900 in k11894 in a11891 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11933(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_11933,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11940,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_eqp(t1,lf[243]);
if(C_truep(t3)){
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=C_a_i_cons(&a,2,lf[29],t4);
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list2(&a,2,lf[243],t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
if(C_truep(((C_word*)t0)[4])){
/* chicken-syntax.scm:237: chicken.compiler.scrutinizer#check-and-validate-type */
t4=*((C_word*)lf[239]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=t1;
av2[3]=lf[242];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=C_a_i_cons(&a,2,lf[29],t4);
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list2(&a,2,t1,t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}}

/* k11938 in k11931 in g985 in k11903 in k11900 in k11894 in a11891 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11940(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_11940,c,av);}
a=C_alloc(9);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[29],t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list2(&a,2,t1,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k11965 in k11903 in k11900 in k11894 in a11891 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11967(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,1)))){
C_save_and_reclaim((void *)f_11967,c,av);}
a=C_alloc(18);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=C_a_i_cons(&a,2,lf[244],t3);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[5],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* map-loop979 in k11903 in k11900 in k11894 in a11891 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_11969(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_11969,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11994,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:231: g985 */
t4=((C_word*)t0)[4];
f_11929(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k11992 in map-loop979 in k11903 in k11900 in k11894 in a11891 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_11994(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11994,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_11969(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k12011 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12013(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12013,c,av);}
/* chicken-syntax.scm:159: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[246];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12015(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_12015,c,av);}
a=C_alloc(5);
t5=C_i_memq(lf[234],*((C_word*)lf[235]+1));
if(C_truep(C_i_not(t5))){
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=lf[247];
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12025,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:165: ##sys#check-syntax */
t7=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[246];
av2[3]=t2;
av2[4]=lf[253];
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}}

/* k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12025(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_12025,c,av);}
a=C_alloc(8);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_i_car(t2);
t4=C_u_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_12035,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=t2,a[5]=((C_word*)t0)[3],a[6]=t4,a[7]=((C_word*)t0)[4],tmp=(C_word)a,a+=8,tmp);
/* chicken-syntax.scm:169: chicken.base#gensym */
t6=*((C_word*)lf[57]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12035(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12035,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_12038,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
t3=C_i_cdddr(((C_word*)t0)[2]);
if(C_truep(C_i_pairp(t3))){
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=C_u_i_cdr(t4);
/* chicken-syntax.scm:170: chicken.syntax#strip-syntax */
t6=*((C_word*)lf[40]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=C_u_i_car(t5);
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_12038(2,av2);}}}

/* k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12038(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_12038,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_12041,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* chicken-syntax.scm:171: r */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[82];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12041(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12041,c,av);}
a=C_alloc(12);
t2=(C_truep(((C_word*)t0)[2])?C_i_cadddr(((C_word*)t0)[3]):C_i_caddr(((C_word*)t0)[3]));
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_12049,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=t2,a[5]=t1,a[6]=((C_word*)t0)[2],a[7]=t4,a[8]=((C_word*)t0)[6],a[9]=((C_word)li141),tmp=(C_word)a,a+=10,tmp));
t6=((C_word*)t4)[1];
f_12049(t6,((C_word*)t0)[7],((C_word*)t0)[8],C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST);}

/* loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12049(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_12049,5,t0,t1,t2,t3,t4);}
a=C_alloc(10);
if(C_truep(C_i_nullp(t2))){
t5=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_12059,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=t3,a[9]=t4,tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:175: scheme#reverse */
t6=*((C_word*)lf[58]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=C_i_car(t2);
if(C_truep(C_i_symbolp(t5))){
t6=C_u_i_cdr(t2);
t7=C_a_i_cons(&a,2,t5,t3);
t8=C_a_i_cons(&a,2,lf[251],t4);
/* chicken-syntax.scm:205: loop */
t10=t1;
t11=t6;
t12=t7;
t13=t8;
t1=t10;
t2=t11;
t3=t12;
t4=t13;
goto loop;}
else{
t6=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_12289,a[2]=t2,a[3]=t5,a[4]=t3,a[5]=t4,a[6]=((C_word*)t0)[7],a[7]=t1,a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_i_listp(t5))){
t7=C_eqp(C_fix(2),C_u_i_length(t5));
t8=t6;
f_12289(t8,(C_truep(t7)?C_i_symbolp(C_i_car(t5)):C_SCHEME_FALSE));}
else{
t7=t6;
f_12289(t7,C_SCHEME_FALSE);}}}}

/* k12057 in loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12059(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_12059,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_12062,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:176: scheme#reverse */
t3=*((C_word*)lf[58]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[9];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k12060 in k12057 in loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12062(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,4)))){
C_save_and_reclaim((void *)f_12062,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_12233,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12235,a[2]=t4,a[3]=((C_word)li140),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_12235(t6,t2,((C_word*)t0)[9],C_fix(1));}

/* k12102 in k12166 in k12231 in k12060 in k12057 in loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 in ... */
static void C_ccall f_12104(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(30,c,1)))){
C_save_and_reclaim((void *)f_12104,c,av);}
a=C_alloc(30);
t2=C_a_i_list(&a,3,lf[38],t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,3,((C_word*)t0)[3],((C_word*)t0)[4],t2);
t4=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,4,lf[29],((C_word*)t0)[6],((C_word*)t0)[7],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* map-loop925 in k12166 in k12231 in k12060 in k12057 in loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 in ... */
static void C_fcall f_12106(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,0,3)))){
C_save_and_reclaim_args((void *)trf_12106,4,t0,t1,t2,t3);}
a=C_alloc(21);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,4,lf[177],t7,C_SCHEME_TRUE,t6);
t9=C_a_i_list2(&a,2,t6,t8);
t10=C_a_i_cons(&a,2,t9,C_SCHEME_END_OF_LIST);
t11=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t10);
t12=C_mutate(((C_word *)((C_word*)t0)[2])+1,t10);
t14=t1;
t15=C_slot(t2,C_fix(1));
t16=C_slot(t3,C_fix(1));
t1=t14;
t2=t15;
t3=t16;
goto loop;}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k12166 in k12231 in k12060 in k12057 in loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12168(C_word t0,C_word t1){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(60,0,4)))){
C_save_and_reclaim_args((void *)trf_12168,2,t0,t1);}
a=C_alloc(60);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_list(&a,4,lf[248],((C_word*)t0)[3],((C_word*)t0)[4],t2);
t4=C_a_i_list(&a,2,lf[249],((C_word*)t0)[4]);
t5=C_a_i_list(&a,2,lf[250],((C_word*)t0)[4]);
t6=C_a_i_list(&a,3,lf[195],t4,t5);
t7=C_a_i_cons(&a,2,((C_word*)t0)[4],((C_word*)t0)[5]);
t8=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t9=t8;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=((C_word*)t10)[1];
t12=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_12104,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=t7,a[5]=((C_word*)t0)[8],a[6]=t3,a[7]=t6,tmp=(C_word)a,a+=8,tmp);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_set_block_item(t14,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12106,a[2]=t10,a[3]=t14,a[4]=t11,a[5]=((C_word)li138),tmp=(C_word)a,a+=6,tmp));
t16=((C_word*)t14)[1];
f_12106(t16,t12,((C_word*)t0)[5],((C_word*)t0)[2]);}

/* k12187 in k12231 in k12060 in k12057 in loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12189(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_12189,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];
f_12168(t2,C_a_i_list2(&a,2,t1,((C_word*)t0)[3]));}

/* map-loop891 in k12231 in k12060 in k12057 in loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12191(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_12191,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12216,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
t5=*((C_word*)lf[239]+1);
/* chicken-syntax.scm:190: g914 */
t6=*((C_word*)lf[239]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t3;
av2[2]=t4;
av2[3]=lf[246];
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k12214 in map-loop891 in k12231 in k12060 in k12057 in loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 in ... */
static void C_ccall f_12216(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_12216,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_12191(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k12231 in k12060 in k12057 in loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12233(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(29,c,3)))){
C_save_and_reclaim((void *)f_12233,c,av);}
a=C_alloc(29);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_12168,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t4=(C_truep(((C_word*)t0)[9])?C_i_pairp(((C_word*)t0)[9]):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=C_i_check_list_2(((C_word*)t0)[9],lf[68]);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12189,a[2]=t3,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12191,a[2]=t7,a[3]=t12,a[4]=t8,a[5]=((C_word)li139),tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_12191(t14,t10,((C_word*)t0)[9]);}
else{
t5=t3;
f_12168(t5,C_a_i_list1(&a,1,t2));}}

/* loop2 in k12060 in k12057 in loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12235(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_12235,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_a_i_vector1(&a,1,t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12253,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:182: loop2 */
t7=t5;
t8=C_i_cdr(t2);
t9=C_fixnum_plus(t3,C_fix(1));
t1=t7;
t2=t8;
t3=t9;
goto loop;}}

/* k12251 in loop2 in k12060 in k12057 in loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12253(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_12253,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12287 in loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12289(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,5)))){
C_save_and_reclaim_args((void *)trf_12289,2,t0,t1);}
a=C_alloc(10);
if(C_truep(t1)){
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_i_car(((C_word*)t0)[3]);
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[4]);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12306,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],a[5]=t2,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:211: chicken.compiler.scrutinizer#check-and-validate-type */
t6=*((C_word*)lf[239]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=C_i_cadr(((C_word*)t0)[3]);
av2[3]=lf[246];
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
/* chicken-syntax.scm:215: chicken.syntax#syntax-error */
t2=*((C_word*)lf[59]+1);{
C_word av2[6];
av2[0]=t2;
av2[1]=((C_word*)t0)[7];
av2[2]=lf[246];
av2[3]=lf[252];
av2[4]=((C_word*)t0)[3];
av2[5]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}

/* k12304 in k12287 in loop in k12039 in k12036 in k12033 in k12023 in a12014 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12306(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_12306,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
/* chicken-syntax.scm:207: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_12049(t3,((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],t2);}

/* k12361 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12363(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12363,c,av);}
/* chicken-syntax.scm:153: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[254];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12365(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_12365,c,av);}
a=C_alloc(14);
t5=C_i_cdr(t2);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12375,a[2]=t5,a[3]=t1,a[4]=t3,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_pairp(t5))){
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12537,a[2]=t5,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12593,a[2]=t5,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:155: ##sys#list? */
t9=*((C_word*)lf[221]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=C_i_car(t5);
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
t7=t6;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_FALSE;
f_12375(2,av2);}}}

/* k12373 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12375(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12375,c,av);}
a=C_alloc(18);
if(C_truep(t1)){
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_car(((C_word*)t0)[2]);
t7=C_i_check_list_2(t6,lf[68]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12392,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12493,a[2]=t4,a[3]=t10,a[4]=t5,a[5]=((C_word)li145),tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_12493(t12,t8,t6);}
else{
/* chicken-syntax.scm:155: chicken.internal.syntax-rules#syntax-rules-mismatch */
t2=*((C_word*)lf[216]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}}

/* k12390 in k12373 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12392(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12392,c,av);}
a=C_alloc(19);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_car(((C_word*)t0)[2]);
t7=C_i_check_list_2(t6,lf[68]);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12413,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12459,a[2]=t4,a[3]=t10,a[4]=t5,a[5]=((C_word)li144),tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_12459(t12,t8,t6);}

/* k12411 in k12390 in k12373 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12413(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_12413,c,av);}
a=C_alloc(7);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12423,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:155: rename751 */
t4=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[257];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k12421 in k12411 in k12390 in k12373 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12423(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_12423,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12431,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12433,a[2]=((C_word*)t0)[4],a[3]=((C_word)li143),tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:155: ##sys#map-n */
t4=*((C_word*)lf[256]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=t3;
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k12429 in k12421 in k12411 in k12390 in k12373 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12431(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_12431,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a12432 in k12421 in k12411 in k12390 in k12373 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12433(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12433,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12449,a[2]=t3,a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:155: rename751 */
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[255];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k12447 in a12432 in k12421 in k12411 in k12390 in k12373 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12449(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12449,c,av);}
a=C_alloc(15);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],C_SCHEME_END_OF_LIST);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=C_a_i_cons(&a,2,t1,t3);
t5=C_a_i_cons(&a,2,t4,C_SCHEME_END_OF_LIST);
t6=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[2],t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* map-loop824 in k12390 in k12373 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12459(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_12459,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_cdr(t3);
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

/* map-loop796 in k12373 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12493(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_12493,3,t0,t1,t2);}
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

/* k12535 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12537(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_12537,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12543,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:155: ##sys#list? */
t3=*((C_word*)lf[221]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cdr(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_12375(2,av2);}}}

/* k12541 in k12535 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12543(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_12543,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12546,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:155: ##sys#length */
t3=*((C_word*)lf[220]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cdr(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_12375(2,av2);}}}

/* k12544 in k12541 in k12535 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12546(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_12546,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12552,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:155: ##sys#>= */
t3=*((C_word*)lf[219]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k12550 in k12544 in k12541 in k12535 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12552(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12552,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=C_i_cdr(((C_word*)t0)[2]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12561,a[2]=t4,a[3]=((C_word)li146),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_12561(t6,((C_word*)t0)[3],t2,((C_word*)t0)[4]);}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_12375(2,av2);}}}

/* loop748 in k12550 in k12544 in k12541 in k12535 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12561(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_12561,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12568,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:155: ##sys#= */
t5=*((C_word*)lf[218]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k12566 in loop748 in k12550 in k12544 in k12541 in k12535 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12568(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_12568,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(((C_word*)t0)[3],C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_i_cdr(((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12582,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:155: ##sys#+ */
t4=*((C_word*)lf[217]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=C_fix(-1);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k12580 in k12566 in loop748 in k12550 in k12544 in k12541 in k12535 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12582(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_12582,c,av);}
/* chicken-syntax.scm:155: loop748 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_12561(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k12591 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12593(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_12593,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12596,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:155: ##sys#length */
t3=*((C_word*)lf[220]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_car(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_12537(2,av2);}}}

/* k12594 in k12591 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12596(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_12596,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12602,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:155: ##sys#>= */
t3=*((C_word*)lf[219]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k12600 in k12594 in k12591 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12602(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12602,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=C_i_car(((C_word*)t0)[2]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12611,a[2]=t4,a[3]=((C_word)li147),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_12611(t6,((C_word*)t0)[3],t2,((C_word*)t0)[4]);}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_12537(2,av2);}}}

/* loop748 in k12600 in k12594 in k12591 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12611(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_12611,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12618,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:155: ##sys#= */
t5=*((C_word*)lf[218]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k12616 in loop748 in k12600 in k12594 in k12591 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12618(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12618,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(((C_word*)t0)[3],C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_i_car(((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12630,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_pairp(t2))){
t4=C_i_cdr(t2);
t5=C_i_pairp(t4);
t6=t3;
f_12630(t6,(C_truep(t5)?C_eqp(C_i_cdr(t4),C_SCHEME_END_OF_LIST):C_SCHEME_FALSE));}
else{
t4=t3;
f_12630(t4,C_SCHEME_FALSE);}}}

/* k12628 in k12616 in loop748 in k12600 in k12594 in k12591 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12630(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_12630,2,t0,t1);}
a=C_alloc(5);
if(C_truep(t1)){
t2=C_i_cdr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12641,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:155: ##sys#+ */
t4=*((C_word*)lf[217]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=C_fix(-1);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k12639 in k12628 in k12616 in loop748 in k12600 in k12594 in k12591 in a12364 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12641(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_12641,c,av);}
/* chicken-syntax.scm:155: loop748 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_12611(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k12670 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12672(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12672,c,av);}
/* chicken-syntax.scm:142: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
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

/* a12673 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12674(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12674,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12678,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:146: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[255];
av2[3]=t2;
av2[4]=lf[258];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k12676 in a12673 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12678(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_12678,c,av);}
a=C_alloc(4);
t2=C_i_memq(lf[234],*((C_word*)lf[235]+1));
if(C_truep(C_i_not(t2))){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_caddr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12694,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:149: chicken.compiler.scrutinizer#check-and-validate-type */
t4=*((C_word*)lf[239]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_cadr(((C_word*)t0)[3]);
av2[3]=lf[255];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k12692 in k12676 in a12673 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12694(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_12694,c,av);}
a=C_alloc(12);
t2=C_i_caddr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,4,lf[177],t1,C_SCHEME_TRUE,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k12708 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12710(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12710,c,av);}
/* chicken-syntax.scm:119: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[259];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a12711 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12712(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12712,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12716,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:123: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[259];
av2[3]=t2;
av2[4]=lf[266];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k12714 in a12711 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12716(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_12716,c,av);}
a=C_alloc(4);
t2=C_i_memq(lf[234],*((C_word*)lf[235]+1));
if(C_truep(C_i_not(t2))){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=lf[260];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12725,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:126: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[40]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_caddr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k12723 in k12714 in a12711 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12725(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,5)))){
C_save_and_reclaim((void *)f_12725,c,av);}
a=C_alloc(11);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_u_i_car(t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12732,a[2]=t1,a[3]=t3,a[4]=((C_word)li150),tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12742,a[2]=t3,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word)li151),tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:130: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=t4;
av2[3]=t5;
C_call_with_values(4,av2);}}

/* a12731 in k12723 in k12714 in a12711 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12732(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_12732,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12740,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:133: chicken.syntax#strip-syntax */
t3=*((C_word*)lf[40]+1);{
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

/* k12738 in a12731 in k12723 in k12714 in a12711 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12740(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_12740,c,av);}
/* chicken-syntax.scm:131: chicken.compiler.scrutinizer#validate-type */
t2=*((C_word*)lf[261]+1);{
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

/* a12741 in k12723 in k12714 in a12711 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12742(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(30,c,5)))){
C_save_and_reclaim((void *)f_12742,c,av);}
a=C_alloc(30);
if(C_truep(C_i_not(t2))){
/* chicken-syntax.scm:135: chicken.syntax#syntax-error */
t5=*((C_word*)lf[59]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=lf[259];
av2[3]=lf[262];
av2[4]=((C_word*)t0)[2];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}
else{
t5=C_i_cdddr(((C_word*)t0)[4]);
t6=C_a_i_cons(&a,2,((C_word*)t0)[3],t5);
t7=C_a_i_cons(&a,2,((C_word*)t0)[2],t6);
t8=C_a_i_list(&a,2,lf[263],t7);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12767,a[2]=t8,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12771,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t9,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t4)){
t11=C_a_i_list(&a,2,lf[265],((C_word*)t0)[2]);
t12=t10;
f_12771(t12,C_a_i_list(&a,1,t11));}
else{
t11=t10;
f_12771(t11,C_SCHEME_END_OF_LIST);}}}

/* k12765 in a12741 in k12723 in k12714 in a12711 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12767(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_12767,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[195],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k12769 in a12741 in k12723 in k12714 in a12711 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12771(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,3)))){
C_save_and_reclaim_args((void *)trf_12771,2,t0,t1);}
a=C_alloc(15);
if(C_truep(((C_word*)t0)[2])){
t2=C_a_i_list(&a,2,((C_word*)t0)[3],((C_word*)t0)[2]);
t3=C_a_i_list(&a,2,lf[264],t2);
t4=C_a_i_list(&a,1,t3);
/* chicken-syntax.scm:137: ##sys#append */
t5=*((C_word*)lf[56]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=((C_word*)t0)[4];
av2[2]=t1;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
/* chicken-syntax.scm:137: ##sys#append */
t2=*((C_word*)lf[56]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
av2[2]=t1;
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k12819 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12821(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12821,c,av);}
/* chicken-syntax.scm:77: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[269];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12823(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12823,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12827,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:82: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[269];
av2[3]=t2;
av2[4]=lf[278];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12827(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_12827,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12830,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:83: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[277];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12830(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_12830,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12833,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:84: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[276];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12833(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_12833,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12836,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:85: r */
t3=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[275];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12836(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_12836,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_12839,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* chicken-syntax.scm:86: r */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[267];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k12837 in k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12839(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_12839,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_12842,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* chicken-syntax.scm:87: r */
t3=((C_word*)t0)[7];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[243];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k12840 in k12837 in k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12842(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_12842,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_12844,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word)li155),tmp=(C_word)a,a+=8,tmp);
t3=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_12974,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=t1,a[8]=((C_word*)t0)[8],a[9]=t2,tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:99: r */
t4=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[274];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* parse-clause in k12840 in k12837 in k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12844(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,0,2)))){
C_save_and_reclaim_args((void *)trf_12844,3,t0,t1,t2);}
a=C_alloc(23);
t3=C_i_car(t2);
t4=C_i_symbolp(t3);
t5=(C_truep(t4)?C_u_i_car(t2):C_SCHEME_FALSE);
t6=(C_truep(t5)?C_i_cadr(t2):C_u_i_car(t2));
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_12854,a[2]=t6,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
if(C_truep(t5)){
t8=C_a_i_list(&a,2,t5,((C_word*)t0)[6]);
t9=C_a_i_list(&a,1,t8);
t10=C_i_cddr(t2);
t11=C_a_i_cons(&a,2,t9,t10);
t12=t7;
f_12854(t12,C_a_i_cons(&a,2,lf[38],t11));}
else{
t8=C_u_i_cdr(t2);
t9=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,t8);
t10=t7;
f_12854(t10,C_a_i_cons(&a,2,lf[38],t9));}}

/* k12852 in parse-clause in k12840 in k12837 in k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12854(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,0,3)))){
C_save_and_reclaim_args((void *)trf_12854,2,t0,t1);}
a=C_alloc(25);
if(C_truep(C_i_nullp(((C_word*)t0)[2]))){
t2=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_a_i_list(&a,2,((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12879,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word)li153),tmp=(C_word)a,a+=5,tmp);
t7=C_i_check_list_2(((C_word*)t0)[2],lf[68]);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12893,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[3],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12895,a[2]=t6,a[3]=t4,a[4]=t10,a[5]=t5,a[6]=((C_word)li154),tmp=(C_word)a,a+=7,tmp));
t12=((C_word*)t10)[1];
f_12895(t12,t8,((C_word*)t0)[2]);}}

/* g637 in k12852 in parse-clause in k12840 in k12837 in k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static C_word C_fcall f_12879(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_stack_overflow_check;{}
t2=C_a_i_list(&a,2,lf[39],t1);
return(C_a_i_list(&a,3,((C_word*)t0)[2],t2,((C_word*)t0)[3]));}

/* k12891 in k12852 in parse-clause in k12840 in k12837 in k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12893(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_12893,c,av);}
a=C_alloc(12);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,2,t3,((C_word*)t0)[5]);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* map-loop631 in k12852 in parse-clause in k12840 in k12837 in k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_12895(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_12895,3,t0,t1,t2);}
a=C_alloc(18);
if(C_truep(C_i_pairp(t2))){
t3=(
/* chicken-syntax.scm:96: g637 */
  f_12879(C_a_i(&a,15),((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k12972 in k12840 in k12837 in k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12974(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(65,c,3)))){
C_save_and_reclaim((void *)f_12974,c,av);}
a=C_alloc(65);
t2=C_a_i_list(&a,2,lf[39],lf[270]);
t3=C_a_i_list(&a,3,lf[73],((C_word*)t0)[2],t2);
t4=C_a_i_list(&a,3,lf[271],((C_word*)t0)[2],C_fix(1));
t5=C_a_i_list(&a,3,((C_word*)t0)[3],t3,t4);
t6=C_a_i_list(&a,2,((C_word*)t0)[4],t5);
t7=C_a_i_list(&a,1,t6);
t8=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t9=t8;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=((C_word*)t10)[1];
t12=C_i_cddr(((C_word*)t0)[5]);
t13=C_i_check_list_2(t12,lf[68]);
t14=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_12999,a[2]=t7,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=t1,a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t15=C_SCHEME_UNDEFINED;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_set_block_item(t16,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13030,a[2]=t10,a[3]=t16,a[4]=((C_word*)t0)[9],a[5]=t11,a[6]=((C_word)li156),tmp=(C_word)a,a+=7,tmp));
t18=((C_word*)t16)[1];
f_13030(t18,t14,t12);}

/* k12997 in k12972 in k12840 in k12837 in k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_12999(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_12999,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_13006,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,tmp=(C_word)a,a+=9,tmp);
/* chicken-syntax.scm:104: r */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[273];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k13004 in k12997 in k12972 in k12840 in k12837 in k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_13006(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(23,c,3)))){
C_save_and_reclaim((void *)f_13006,c,av);}
a=C_alloc(23);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_13010,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
if(C_truep(C_i_assq(((C_word*)t0)[7],((C_word*)t0)[8]))){
/* chicken-syntax.scm:104: ##sys#append */
t3=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[8];
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=C_a_i_list(&a,2,lf[272],((C_word*)t0)[6]);
t4=C_a_i_list(&a,2,((C_word*)t0)[7],t3);
t5=C_a_i_list(&a,1,t4);
/* chicken-syntax.scm:104: ##sys#append */
t6=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=((C_word*)t0)[8];
av2[3]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}}

/* k13008 in k13004 in k12997 in k12972 in k12840 in k12837 in k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_13010(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,1)))){
C_save_and_reclaim((void *)f_13010,c,av);}
a=C_alloc(24);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_list(&a,3,lf[38],((C_word*)t0)[3],t2);
t4=C_i_cadr(((C_word*)t0)[4]);
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,4,((C_word*)t0)[6],((C_word*)t0)[7],t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* map-loop662 in k12972 in k12840 in k12837 in k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_fcall f_13030(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_13030,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13055,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:103: g668 */
t4=((C_word*)t0)[4];
f_12844(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k13053 in map-loop662 in k12972 in k12840 in k12837 in k12834 in k12831 in k12828 in k12825 in a12822 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_13055(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_13055,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_13030(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k13092 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_13094(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13094,c,av);}
/* chicken-syntax.scm:56: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[274];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13095 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_13096(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13096,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13100,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:61: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[274];
av2[3]=t2;
av2[4]=lf[284];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13098 in a13095 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_13100(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_13100,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13103,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:62: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[283];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k13101 in k13098 in a13095 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_13103(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_13103,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13106,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:63: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[282];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k13104 in k13101 in k13098 in a13095 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_13106(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_13106,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13117,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:64: r */
t3=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[279];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k13115 in k13104 in k13101 in k13098 in a13095 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_13117(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(114,c,1)))){
C_save_and_reclaim((void *)f_13117,c,av);}
a=C_alloc(114);
t2=C_a_i_list(&a,1,((C_word*)t0)[2]);
t3=C_i_cadr(((C_word*)t0)[3]);
t4=C_a_i_list(&a,1,t3);
t5=C_i_caddr(((C_word*)t0)[3]);
t6=C_a_i_list(&a,3,lf[23],C_SCHEME_END_OF_LIST,t5);
t7=C_a_i_list(&a,2,((C_word*)t0)[2],t6);
t8=C_a_i_list(&a,3,lf[23],t4,t7);
t9=C_u_i_cdr(((C_word*)t0)[3]);
t10=C_u_i_cdr(t9);
t11=C_u_i_cdr(t10);
t12=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,t11);
t13=C_a_i_cons(&a,2,lf[23],t12);
t14=C_a_i_list(&a,3,lf[26],lf[27],((C_word*)t0)[4]);
t15=C_a_i_list(&a,3,lf[23],C_SCHEME_END_OF_LIST,t14);
t16=C_a_i_list(&a,2,((C_word*)t0)[2],t15);
t17=C_a_i_list(&a,3,lf[23],((C_word*)t0)[4],t16);
t18=C_a_i_list(&a,3,lf[28],t13,t17);
t19=C_a_i_list(&a,3,lf[23],C_SCHEME_END_OF_LIST,t18);
t20=C_a_i_list(&a,3,lf[281],t8,t19);
t21=C_a_i_list(&a,3,lf[23],t2,t20);
t22=C_a_i_list(&a,2,t1,t21);
t23=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t23;
av2[1]=C_a_i_list(&a,1,t22);
((C_proc)(void*)(*((C_word*)t23+1)))(2,av2);}}

/* k4229 */
static void C_ccall f_4231(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4231,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4234,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_internal_toplevel(2,av2);}}

/* k4232 in k4229 */
static void C_ccall f_4234(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_4234,c,av);}
a=C_alloc(11);
t2=C_a_i_provide(&a,1,lf[0]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4237,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t3;
C_library_toplevel(2,av2);}}

/* k4235 in k4232 in k4229 */
static void C_ccall f_4237(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4237,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[1] /* (set! take ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4347,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5519,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:54: ##sys#macro-environment */
t4=*((C_word*)lf[32]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* take in k4235 in k4232 in k4229 */
static void C_fcall f_4347(C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_4347,3,t1,t2,t3);}
a=C_alloc(4);
if(C_truep(C_fixnum_less_or_equal_p(t3,C_fix(0)))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_car(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4365,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:56: take */
t7=t5;
t8=C_u_i_cdr(t2);
t9=C_fixnum_difference(t3,C_fix(1));
t1=t7;
t2=t8;
t3=t9;
goto loop;}}

/* k4363 in take in k4235 in k4232 in k4229 */
static void C_ccall f_4365(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_4365,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in k6975 in a6968 in k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in ... */
static void C_fcall f_4405(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
C_save_and_reclaim_args((void *)trf_4405,5,t0,t1,t2,t3,t4);}
a=C_alloc(4);
if(C_truep(C_fixnum_less_or_equal_p(t2,C_fix(0)))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4419,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:67: scheme#reverse */
t6=*((C_word*)lf[58]+1);{
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

/* k4417 in loop in k6975 in a6968 in k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in ... */
static void C_ccall f_4419(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4419,c,av);}
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

/* k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5519(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,5)))){
C_save_and_reclaim((void *)f_5519,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5522,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,lf[279],lf[280]);
t4=C_a_i_list(&a,1,t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13094,a[2]=t2,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13096,a[2]=((C_word)li158),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:59: ##sys#er-transformer */
t7=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5522(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,5)))){
C_save_and_reclaim((void *)f_5522,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5525,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,lf[267],lf[268]);
t4=C_a_i_list(&a,1,t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12821,a[2]=t2,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12823,a[2]=((C_word)li157),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:80: ##sys#er-transformer */
t7=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5525(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_5525,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5528,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:111: chicken.internal#macro-subset */
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
av2[3]=*((C_word*)lf[19]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5528(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5528,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[2]+1 /* (set! ##sys#chicken.condition-macro-environment ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5532,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:117: ##sys#macro-environment */
t4=*((C_word*)lf[32]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5532(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5532,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5535,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12710,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12712,a[2]=((C_word)li152),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:121: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5535(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5535,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5538,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12672,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12674,a[2]=((C_word)li149),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:144: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5538(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5538,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5541,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12363,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12365,a[2]=((C_word)li148),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:155: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5541(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5541,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5544,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12013,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12015,a[2]=((C_word)li142),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:161: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5544(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5544,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5547,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11890,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11892,a[2]=((C_word)li137),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:221: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5547(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5547,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5550,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11830,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11832,a[2]=((C_word)li134),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:246: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5550(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_5550,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5553,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:262: chicken.internal#macro-subset */
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
av2[3]=*((C_word*)lf[19]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5553(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5553,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[3]+1 /* (set! ##sys#chicken.type-macro-environment ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5557,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:267: ##sys#macro-environment */
t4=*((C_word*)lf[32]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5557(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5557,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5560,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11813,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11815,a[2]=((C_word)li133),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:272: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5560(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5560,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5563,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11783,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11785,a[2]=((C_word)li132),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:279: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5563(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5563,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5566,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11754,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11756,a[2]=((C_word)li131),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:287: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5566(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5566,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5569,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11657,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11659,a[2]=((C_word)li130),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:298: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5569(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5569,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5572,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11509,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11511,a[2]=((C_word)li129),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:306: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 */
static void C_ccall f_5572(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_5572,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5575,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:310: chicken.internal#macro-subset */
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
av2[3]=*((C_word*)lf[19]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in k4229 in ... */
static void C_ccall f_5575(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5575,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[4]+1 /* (set! ##sys#chicken.syntax-macro-environment ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5579,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:316: ##sys#macro-environment */
t4=*((C_word*)lf[32]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in k4232 in ... */
static void C_ccall f_5579(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5579,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5582,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11492,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11494,a[2]=((C_word)li126),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:321: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in k4235 in ... */
static void C_ccall f_5582(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5582,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5585,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11097,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11099,a[2]=((C_word)li125),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:328: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in k5517 in ... */
static void C_ccall f_5585(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5585,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5588,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11004,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11006,a[2]=((C_word)li121),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:401: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in k5520 in ... */
static void C_ccall f_5588(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5588,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5591,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10990,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10992,a[2]=((C_word)li120),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:419: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in k5523 in ... */
static void C_ccall f_5591(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5591,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5594,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10969,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10971,a[2]=((C_word)li119),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:426: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in k5526 in ... */
static void C_ccall f_5594(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5594,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5597,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10952,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10954,a[2]=((C_word)li118),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:433: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in k5530 in ... */
static void C_ccall f_5597(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5597,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5600,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10935,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10937,a[2]=((C_word)li117),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:440: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in k5533 in ... */
static void C_ccall f_5600(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5600,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5603,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10282,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10284,a[2]=((C_word)li116),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:447: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in k5536 in ... */
static void C_ccall f_5603(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5603,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5606,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9352,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9354,a[2]=((C_word)li102),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:479: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in ... */
static void C_ccall f_5606(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5606,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5609,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9272,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9274,a[2]=((C_word)li83),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:534: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in ... */
static void C_ccall f_5609(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5609,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5612,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9248,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9250,a[2]=((C_word)li78),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:546: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_ccall f_5612(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5612,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5615,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9220,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9222,a[2]=((C_word)li77),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:554: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_ccall f_5615(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5615,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5618,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9199,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9201,a[2]=((C_word)li76),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:563: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in ... */
static void C_ccall f_5618(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5618,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5622,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9069,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9071,a[2]=((C_word)li75),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:571: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in ... */
static void C_ccall f_5622(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5622,c,av);}
a=C_alloc(10);
t2=C_mutate((C_word*)lf[5]+1 /* (set! chicken.syntax#define-values-definition ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5625,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8592,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8594,a[2]=((C_word)li71),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:588: ##sys#er-transformer */
t6=*((C_word*)lf[31]+1);{
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

/* k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_5625(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5625,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5628,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8538,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8540,a[2]=((C_word)li58),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:642: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_5628(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5628,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5631,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8280,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8282,a[2]=((C_word)li56),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:657: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_ccall f_5631(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5631,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5634,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8258,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8260,a[2]=((C_word)li49),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:677: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_ccall f_5634(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,5)))){
C_save_and_reclaim((void *)f_5634,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5637,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,lf[140],lf[141]);
t4=C_a_i_list(&a,1,t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8214,a[2]=t2,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8216,a[2]=((C_word)li48),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:686: ##sys#er-transformer */
t7=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_ccall f_5637(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5637,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5640,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8110,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8112,a[2]=((C_word)li47),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:696: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_ccall f_5640(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5640,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5643,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7968,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7970,a[2]=((C_word)li45),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:717: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_5643(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(29,c,5)))){
C_save_and_reclaim((void *)f_5643,c,av);}
a=C_alloc(29);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5646,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,lf[113],lf[114]);
t4=C_a_i_cons(&a,2,lf[95],lf[96]);
t5=C_a_i_cons(&a,2,lf[97],lf[98]);
t6=C_a_i_list(&a,3,t3,t4,t5);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7520,a[2]=t2,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7522,a[2]=((C_word)li43),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:824: ##sys#er-transformer */
t9=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t7;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_5646(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(29,c,5)))){
C_save_and_reclaim((void *)f_5646,c,av);}
a=C_alloc(29);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5649,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,lf[113],lf[114]);
t4=C_a_i_cons(&a,2,lf[95],lf[96]);
t5=C_a_i_cons(&a,2,lf[97],lf[98]);
t6=C_a_i_list(&a,3,t3,t4,t5);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7443,a[2]=t2,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7445,a[2]=((C_word)li32),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:913: ##sys#er-transformer */
t9=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t7;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_5649(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(29,c,5)))){
C_save_and_reclaim((void *)f_5649,c,av);}
a=C_alloc(29);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5652,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,lf[113],lf[114]);
t4=C_a_i_cons(&a,2,lf[95],lf[96]);
t5=C_a_i_cons(&a,2,lf[97],lf[98]);
t6=C_a_i_list(&a,3,t3,t4,t5);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7283,a[2]=t2,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7285,a[2]=((C_word)li31),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:941: ##sys#er-transformer */
t9=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t7;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
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
C_word t10;
C_word t11;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(41,c,5)))){
C_save_and_reclaim((void *)f_5652,c,av);}
a=C_alloc(41);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5655,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,lf[93],lf[94]);
t4=C_a_i_cons(&a,2,lf[95],lf[96]);
t5=C_a_i_cons(&a,2,lf[97],lf[98]);
t6=C_a_i_cons(&a,2,lf[99],lf[100]);
t7=C_a_i_cons(&a,2,lf[101],lf[102]);
t8=C_a_i_list(&a,5,t3,t4,t5,t6,t7);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6839,a[2]=t2,a[3]=t8,tmp=(C_word)a,a+=4,tmp);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6841,a[2]=((C_word)li29),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:978: ##sys#er-transformer */
t11=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t11;
av2[1]=t9;
av2[2]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(3,av2);}}

/* k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in ... */
static void C_ccall f_5655(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5655,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5658,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6723,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6725,a[2]=((C_word)li16),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1041: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in ... */
static void C_ccall f_5658(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5658,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5661,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6284,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6286,a[2]=((C_word)li15),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1076: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_ccall f_5661(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,5)))){
C_save_and_reclaim((void *)f_5661,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5664,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,lf[53],lf[54]);
t4=C_a_i_list(&a,1,t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6112,a[2]=t2,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6114,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1165: ##sys#er-transformer */
t7=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_5664(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,5)))){
C_save_and_reclaim((void *)f_5664,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5667,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,lf[53],lf[54]);
t4=C_a_i_list(&a,1,t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5917,a[2]=t2,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5919,a[2]=((C_word)li6),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1198: ##sys#er-transformer */
t7=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_5667(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5667,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5670,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5852,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5854,a[2]=((C_word)li4),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1239: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_5670(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5670,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5673,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5834,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5836,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1256: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_5673(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5673,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5676,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5745,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5747,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1265: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5674 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_5676(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_5676,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5679,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1285: chicken.internal#macro-subset */
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
av2[3]=*((C_word*)lf[19]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5677 in k5674 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in ... */
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
t2=C_mutate((C_word*)lf[6]+1 /* (set! ##sys#chicken.base-macro-environment ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5683,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1291: ##sys#macro-environment */
t4=*((C_word*)lf[32]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k5681 in k5677 in k5674 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in ... */
static void C_ccall f_5683(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_5683,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5686,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5696,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5698,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1295: ##sys#er-transformer */
t5=*((C_word*)lf[31]+1);{
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

/* k5684 in k5681 in k5677 in k5674 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_ccall f_5686(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_5686,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5689,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1307: chicken.internal#macro-subset */
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
av2[3]=*((C_word*)lf[19]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5687 in k5684 in k5681 in k5677 in k5674 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_ccall f_5689(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,10)))){
C_save_and_reclaim((void *)f_5689,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[7]+1 /* (set! ##sys#chicken.time-macro-environment ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5692,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1311: chicken.platform#register-feature! */
t4=*((C_word*)lf[8]+1);{
C_word *av2;
if(c >= 11) {
  av2=av;
} else {
  av2=C_alloc(11);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[9];
av2[3]=lf[10];
av2[4]=lf[11];
av2[5]=lf[12];
av2[6]=lf[13];
av2[7]=lf[14];
av2[8]=lf[15];
av2[9]=lf[16];
av2[10]=lf[17];
((C_proc)(void*)(*((C_word*)t4+1)))(11,av2);}}

/* k5690 in k5687 in k5684 in k5681 in k5677 in k5674 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static void C_ccall f_5692(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5692,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k5694 in k5681 in k5677 in k5674 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_ccall f_5696(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5696,c,av);}
/* chicken-syntax.scm:1293: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[21];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a5697 in k5681 in k5677 in k5674 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_ccall f_5698(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_5698,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5702,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1297: r */
t6=t3;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[30];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k5700 in a5697 in k5681 in k5677 in k5674 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_ccall f_5702(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(57,c,1)))){
C_save_and_reclaim((void *)f_5702,c,av);}
a=C_alloc(57);
t2=C_a_i_list(&a,1,lf[22]);
t3=C_i_cdr(((C_word*)t0)[2]);
t4=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,t3);
t5=C_a_i_cons(&a,2,lf[23],t4);
t6=C_a_i_list(&a,1,lf[24]);
t7=C_a_i_list(&a,2,lf[25],t6);
t8=C_a_i_list(&a,3,lf[26],lf[27],t1);
t9=C_a_i_list(&a,4,lf[23],t1,t7,t8);
t10=C_a_i_list(&a,3,lf[28],t5,t9);
t11=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t11;
av2[1]=C_a_i_list(&a,3,lf[29],t2,t10);
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}

/* k5743 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_5745(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5745,c,av);}
/* chicken-syntax.scm:1263: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[33];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a5746 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_5747(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5747,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5751,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:1268: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[33];
av2[3]=t2;
av2[4]=lf[47];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k5749 in a5746 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in ... */
static void C_ccall f_5751(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_5751,c,av);}
a=C_alloc(9);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_u_i_cdr(t3);
t5=C_i_nullp(t4);
t6=(C_truep(t5)?lf[34]:C_i_car(t4));
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5762,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=t4,a[5]=t8,a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:1272: r */
t10=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t10;
av2[1]=t9;
av2[2]=lf[45];
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}

/* k5760 in k5749 in a5746 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in ... */
static void C_ccall f_5762(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_5762,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5765,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_i_stringp(((C_word*)((C_word*)t0)[5])[1]))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5817,a[2]=((C_word*)t0)[5],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1274: chicken.syntax#get-line-number */
t4=*((C_word*)lf[44]+1);{
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
t3=t2;
f_5765(t3,C_SCHEME_UNDEFINED);}}

/* k5763 in k5760 in k5749 in a5746 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_fcall f_5765(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(25,0,2)))){
C_save_and_reclaim_args((void *)trf_5765,2,t0,t1);}
a=C_alloc(25);
t2=C_a_i_list(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_list(&a,1,t2);
t4=C_a_i_list(&a,2,lf[35],((C_word*)t0)[2]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5788,a[2]=t4,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=t3,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_pairp(((C_word*)t0)[5]))){
t6=C_u_i_cdr(((C_word*)t0)[5]);
t7=t5;
f_5788(t7,C_a_i_cons(&a,2,((C_word*)((C_word*)t0)[6])[1],t6));}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5807,a[2]=t5,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1283: chicken.syntax#strip-syntax */
t7=*((C_word*)lf[40]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}}

/* k5786 in k5763 in k5760 in k5749 in a5746 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_fcall f_5788(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,0,1)))){
C_save_and_reclaim_args((void *)trf_5788,2,t0,t1);}
a=C_alloc(24);
t2=C_a_i_cons(&a,2,lf[36],t1);
t3=C_a_i_list(&a,4,lf[37],((C_word*)t0)[2],((C_word*)t0)[3],t2);
t4=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[5],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k5805 in k5763 in k5760 in k5749 in a5746 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_ccall f_5807(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_5807,c,av);}
a=C_alloc(12);
t2=C_a_i_list(&a,2,lf[39],t1);
t3=C_a_i_list(&a,1,t2);
t4=((C_word*)t0)[2];
f_5788(t4,C_a_i_cons(&a,2,((C_word*)((C_word*)t0)[3])[1],t3));}

/* k5815 in k5760 in k5749 in a5746 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_ccall f_5817(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_5817,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5824,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1275: string-append */
t3=*((C_word*)lf[41]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[42];
av2[3]=t1;
av2[4]=lf[43];
av2[5]=((C_word*)((C_word*)t0)[2])[1];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}
else{
t2=((C_word*)t0)[3];
f_5765(t2,C_SCHEME_FALSE);}}

/* k5822 in k5815 in k5760 in k5749 in a5746 in k5671 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_ccall f_5824(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5824,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];
f_5765(t3,t2);}

/* k5832 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_5834(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5834,c,av);}
/* chicken-syntax.scm:1253: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
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

/* a5835 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_5836(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_5836,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5844,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1258: r */
t6=t3;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[49];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k5842 in a5835 in k5668 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_5844(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_5844,c,av);}
a=C_alloc(3);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,t1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5850 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_5852(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5852,c,av);}
/* chicken-syntax.scm:1237: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[50];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a5853 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_5854(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5854,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5858,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1241: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[50];
av2[3]=t2;
av2[4]=lf[52];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k5856 in a5853 in k5665 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_5858(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,1)))){
C_save_and_reclaim((void *)f_5858,c,av);}
a=C_alloc(24);
t2=C_i_cadr(((C_word*)t0)[2]);
if(C_truep(C_i_pairp(t2))){
t3=C_u_i_car(t2);
t4=C_u_i_cdr(t2);
t5=C_u_i_cdr(((C_word*)t0)[2]);
t6=C_u_i_cdr(t5);
t7=C_a_i_cons(&a,2,t4,t6);
t8=C_a_i_cons(&a,2,lf[23],t7);
t9=C_a_i_list(&a,2,t3,t8);
t10=C_a_i_list(&a,1,t9);
t11=C_u_i_car(t2);
t12=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t12;
av2[1]=C_a_i_list(&a,3,lf[51],t10,t11);
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}
else{
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_u_i_cdr(t3);
t5=C_a_i_cons(&a,2,t2,t4);
t6=C_a_i_list(&a,1,t5);
t7=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_a_i_list(&a,3,lf[51],t6,t2);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k5915 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_5917(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5917,c,av);}
/* chicken-syntax.scm:1195: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[55];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_5919(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5919,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5923,a[2]=t2,a[3]=t3,a[4]=t4,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:1200: r */
t6=t3;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[53];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_5923(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_5923,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5926,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:1201: r */
t3=((C_word*)t0)[3];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[63];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_5926(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_5926,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5929,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* chicken-syntax.scm:1202: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[62];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_5929(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_5929,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_5932,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
t3=C_i_cdr(((C_word*)t0)[2]);
if(C_truep(C_i_nullp(t3))){
/* chicken-syntax.scm:1204: chicken.syntax#syntax-error */
t4=*((C_word*)lf[59]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[55];
av2[3]=lf[61];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_5932(2,av2);}}}

/* k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in ... */
static void C_ccall f_5932(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5932,c,av);}
a=C_alloc(12);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_5939,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t4,a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word)li5),tmp=(C_word)a,a+=10,tmp));
t6=((C_word*)t4)[1];
f_5939(t6,((C_word*)t0)[8],t2,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,C_SCHEME_FALSE);}

/* loop in k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in ... */
static void C_fcall f_5939(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6){
C_word tmp;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_5939,7,t0,t1,t2,t3,t4,t5,t6);}
a=C_alloc(12);
if(C_truep(C_i_nullp(t2))){
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5949,a[2]=t6,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t4,a[6]=((C_word*)t0)[3],a[7]=t5,tmp=(C_word)a,a+=8,tmp);
/* chicken-syntax.scm:1207: scheme#reverse */
t8=*((C_word*)lf[58]+1);{
C_word av2[3];
av2[0]=t8;
av2[1]=t7;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
t7=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6018,a[2]=t2,a[3]=t3,a[4]=t5,a[5]=((C_word*)t0)[4],a[6]=t1,a[7]=t4,a[8]=((C_word*)t0)[3],a[9]=((C_word*)t0)[5],a[10]=((C_word*)t0)[6],a[11]=((C_word*)t0)[7],tmp=(C_word)a,a+=12,tmp);
/* chicken-syntax.scm:1217: c */
t8=((C_word*)t0)[6];{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=((C_word*)t0)[8];
av2[3]=C_i_car(t2);
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}}

/* k5947 in loop in k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_ccall f_5949(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_5949,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5952,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* chicken-syntax.scm:1208: scheme#reverse */
t3=*((C_word*)lf[58]+1);{
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

/* k5950 in k5947 in loop in k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_ccall f_5952(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,c,2)))){
C_save_and_reclaim((void *)f_5952,c,av);}
a=C_alloc(21);
if(C_truep(((C_word*)t0)[2])){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5958,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5995,a[2]=((C_word*)t0)[7],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1210: chicken.base#gensym */
t4=*((C_word*)lf[57]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=C_i_car(t1);
t3=C_u_i_cdr(t1);
t4=C_a_i_cons(&a,2,t2,t3);
t5=C_a_i_list(&a,3,lf[23],((C_word*)t0)[6],t4);
t6=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[5],t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k5956 in k5950 in k5947 in loop in k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static void C_ccall f_5958(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_5958,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5969,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:1211: ##sys#append */
t3=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5967 in k5956 in k5950 in k5947 in loop in k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in ... */
static void C_ccall f_5969(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5969,c,av);}
a=C_alloc(10);
t2=C_i_car(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5985,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=C_a_i_list(&a,1,((C_word*)t0)[6]);
/* chicken-syntax.scm:1211: ##sys#append */
t6=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=t4;
av2[3]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k5983 in k5967 in k5956 in k5950 in k5947 in loop in k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in ... */
static void C_ccall f_5985(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,1)))){
C_save_and_reclaim((void *)f_5985,c,av);}
a=C_alloc(24);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=C_a_i_list(&a,3,lf[23],((C_word*)t0)[4],t3);
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[6],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k5993 in k5950 in k5947 in loop in k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static void C_ccall f_5995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5995,c,av);}
/* chicken-syntax.scm:1210: r */
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

/* k6016 in loop in k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_ccall f_6018(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_6018,c,av);}
a=C_alloc(12);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6021,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6038,a[2]=((C_word*)t0)[8],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1218: chicken.base#gensym */
t4=*((C_word*)lf[57]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6044,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:1220: c */
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
av2[3]=C_u_i_car(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k6019 in k6016 in loop in k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_ccall f_6021(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,6)))){
C_save_and_reclaim((void *)f_6021,c,av);}
a=C_alloc(6);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t1,((C_word*)t0)[3]);
t4=C_a_i_cons(&a,2,t1,((C_word*)t0)[4]);
/* chicken-syntax.scm:1219: loop */
t5=((C_word*)((C_word*)t0)[5])[1];
f_5939(t5,((C_word*)t0)[6],t2,t3,((C_word*)t0)[7],t4,C_SCHEME_FALSE);}

/* k6036 in k6016 in loop in k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_ccall f_6038(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6038,c,av);}
/* chicken-syntax.scm:1218: r */
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

/* k6042 in k6016 in loop in k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_ccall f_6044(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,6)))){
C_save_and_reclaim((void *)f_6044,c,av);}
a=C_alloc(12);
if(C_truep(t1)){
if(C_truep(C_i_nullp(C_u_i_cdr(((C_word*)t0)[2])))){
/* chicken-syntax.scm:1222: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_5939(t2,((C_word*)t0)[4],C_SCHEME_END_OF_LIST,((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_TRUE);}
else{
/* chicken-syntax.scm:1223: chicken.syntax#syntax-error */
t2=*((C_word*)lf[59]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
av2[2]=lf[55];
av2[3]=lf[60];
av2[4]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}
else{
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6061,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6084,a[2]=((C_word*)t0)[9],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1228: chicken.base#gensym */
t4=*((C_word*)lf[57]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6059 in k6042 in k6016 in loop in k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static void C_ccall f_6061(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,6)))){
C_save_and_reclaim((void *)f_6061,c,av);}
a=C_alloc(12);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_u_i_car(((C_word*)t0)[2]);
t4=C_a_i_list2(&a,2,t1,t3);
t5=C_a_i_cons(&a,2,t4,((C_word*)t0)[3]);
t6=C_a_i_cons(&a,2,t1,((C_word*)t0)[4]);
/* chicken-syntax.scm:1229: loop */
t7=((C_word*)((C_word*)t0)[5])[1];
f_5939(t7,((C_word*)t0)[6],t2,((C_word*)t0)[7],t5,t6,C_SCHEME_FALSE);}

/* k6082 in k6042 in k6016 in loop in k5930 in k5927 in k5924 in k5921 in a5918 in k5662 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static void C_ccall f_6084(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6084,c,av);}
/* chicken-syntax.scm:1228: r */
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

/* k6110 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_6112(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6112,c,av);}
/* chicken-syntax.scm:1162: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
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

/* a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_6114(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6114,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6118,a[2]=t2,a[3]=t3,a[4]=t4,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:1167: r */
t6=t3;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[63];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_6118(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_6118,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6121,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:1168: r */
t3=((C_word*)t0)[3];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[62];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_6121(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_6121,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6124,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* chicken-syntax.scm:1169: r */
t3=((C_word*)t0)[3];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[53];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6122 in k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_6124(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_6124,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6127,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
t3=C_i_cdr(((C_word*)t0)[2]);
if(C_truep(C_i_nullp(t3))){
/* chicken-syntax.scm:1171: chicken.syntax#syntax-error */
t4=*((C_word*)lf[59]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[64];
av2[3]=lf[66];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_6127(2,av2);}}}

/* k6125 in k6122 in k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_6127(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,6)))){
C_save_and_reclaim((void *)f_6127,c,av);}
a=C_alloc(12);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6134,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t4,a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word)li7),tmp=(C_word)a,a+=10,tmp));
t6=((C_word*)t4)[1];
f_6134(t6,((C_word*)t0)[8],t2,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,C_SCHEME_FALSE);}

/* loop in k6125 in k6122 in k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in ... */
static void C_fcall f_6134(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,3)))){
C_save_and_reclaim_args((void *)trf_6134,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(11);
if(C_truep(C_i_nullp(t2))){
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6144,a[2]=t5,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:1174: scheme#reverse */
t7=*((C_word*)lf[58]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6209,a[2]=t2,a[3]=t3,a[4]=t4,a[5]=((C_word*)t0)[4],a[6]=t1,a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],a[10]=((C_word*)t0)[7],tmp=(C_word)a,a+=11,tmp);
/* chicken-syntax.scm:1183: c */
t7=((C_word*)t0)[6];{
C_word av2[4];
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[8];
av2[3]=C_i_car(t2);
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}

/* k6142 in loop in k6125 in k6122 in k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in ... */
static void C_ccall f_6144(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_6144,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6147,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:1175: scheme#reverse */
t3=*((C_word*)lf[58]+1);{
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

/* k6145 in k6142 in loop in k6125 in k6122 in k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_ccall f_6147(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6147,c,av);}
a=C_alloc(18);
if(C_truep(((C_word*)t0)[2])){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6153,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6186,a[2]=((C_word*)t0)[6],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1177: chicken.base#gensym */
t4=*((C_word*)lf[57]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=C_i_car(t1);
t3=C_a_i_list(&a,2,lf[29],t2);
t4=C_u_i_cdr(t1);
t5=C_a_i_cons(&a,2,t3,t4);
t6=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,3,lf[23],((C_word*)t0)[5],t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k6151 in k6145 in k6142 in loop in k6125 in k6122 in k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_ccall f_6153(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_6153,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6160,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:1178: ##sys#append */
t3=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6158 in k6151 in k6145 in k6142 in loop in k6125 in k6122 in k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static void C_ccall f_6160(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6160,c,av);}
a=C_alloc(9);
t2=C_i_car(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6176,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=C_a_i_list(&a,1,((C_word*)t0)[5]);
/* chicken-syntax.scm:1178: ##sys#append */
t6=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=t4;
av2[3]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k6174 in k6158 in k6151 in k6145 in k6142 in loop in k6125 in k6122 in k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in ... */
static void C_ccall f_6176(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,1)))){
C_save_and_reclaim((void *)f_6176,c,av);}
a=C_alloc(15);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[23],((C_word*)t0)[5],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k6184 in k6145 in k6142 in loop in k6125 in k6122 in k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_ccall f_6186(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6186,c,av);}
/* chicken-syntax.scm:1177: r */
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

/* k6207 in loop in k6125 in k6122 in k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in ... */
static void C_ccall f_6209(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_6209,c,av);}
a=C_alloc(11);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6212,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6229,a[2]=((C_word*)t0)[7],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1184: chicken.base#gensym */
t4=*((C_word*)lf[57]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6235,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
/* chicken-syntax.scm:1186: c */
t3=((C_word*)t0)[9];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[10];
av2[3]=C_u_i_car(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k6210 in k6207 in loop in k6125 in k6122 in k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_ccall f_6212(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_6212,c,av);}
a=C_alloc(6);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t1,((C_word*)t0)[3]);
t4=C_a_i_cons(&a,2,t1,((C_word*)t0)[4]);
/* chicken-syntax.scm:1185: loop */
t5=((C_word*)((C_word*)t0)[5])[1];
f_6134(t5,((C_word*)t0)[6],t2,t3,t4,C_SCHEME_FALSE);}

/* k6227 in k6207 in loop in k6125 in k6122 in k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_ccall f_6229(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6229,c,av);}
/* chicken-syntax.scm:1184: r */
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

/* k6233 in k6207 in loop in k6125 in k6122 in k6119 in k6116 in a6113 in k5659 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_ccall f_6235(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_6235,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
if(C_truep(C_i_nullp(C_u_i_cdr(((C_word*)t0)[2])))){
/* chicken-syntax.scm:1188: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_6134(t2,((C_word*)t0)[4],C_SCHEME_END_OF_LIST,((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_TRUE);}
else{
/* chicken-syntax.scm:1189: chicken.syntax#syntax-error */
t2=*((C_word*)lf[59]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
av2[2]=lf[64];
av2[3]=lf[65];
av2[4]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}
else{
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_u_i_car(((C_word*)t0)[2]);
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[6]);
/* chicken-syntax.scm:1193: loop */
t5=((C_word*)((C_word*)t0)[3])[1];
f_6134(t5,((C_word*)t0)[4],t2,((C_word*)t0)[5],t4,C_SCHEME_FALSE);}}

/* k6282 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_ccall f_6284(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6284,c,av);}
/* chicken-syntax.scm:1073: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[67];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_ccall f_6286(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6286,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6290,a[2]=t2,a[3]=t1,a[4]=t4,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:1078: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[67];
av2[3]=t2;
av2[4]=lf[87];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_6290(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_6290,c,av);}
a=C_alloc(7);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6296,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:1083: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[40]+1);{
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

/* k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_6296(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_6296,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6299,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6708,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1084: ##sys#current-module */
t4=*((C_word*)lf[86]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_6299(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6299,c,av);}
a=C_alloc(10);
t2=C_i_caddr(((C_word*)t0)[2]);
t3=C_i_cadddr(((C_word*)t0)[2]);
t4=C_i_cddddr(((C_word*)t0)[2]);
t5=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6311,a[2]=t2,a[3]=t4,a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=t3,a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:1092: r */
t6=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[82];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_6311(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_6311,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6314,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* chicken-syntax.scm:1093: r */
t3=((C_word*)t0)[9];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[81];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_6314(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_6314,c,av);}
a=C_alloc(13);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6320,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[2],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=t1,a[12]=((C_word*)t0)[10],tmp=(C_word)a,a+=13,tmp);
/* chicken-syntax.scm:1095: r */
t4=((C_word*)t0)[10];{
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

/* k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in ... */
static void C_ccall f_6320(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_6320,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6323,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* chicken-syntax.scm:1096: r */
t3=((C_word*)t0)[12];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[79];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in ... */
static void C_ccall f_6323(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(27,c,3)))){
C_save_and_reclaim((void *)f_6323,c,av);}
a=C_alloc(27);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[68]);
t7=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6332,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=t1,a[13]=((C_word*)t0)[2],tmp=(C_word)a,a+=14,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6673,a[2]=t4,a[3]=t9,a[4]=t5,a[5]=((C_word)li14),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_6673(t11,t7,((C_word*)t0)[2]);}

/* k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_ccall f_6332(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(26,c,3)))){
C_save_and_reclaim((void *)f_6332,c,av);}
a=C_alloc(26);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6333,a[2]=t1,a[3]=((C_word)li9),tmp=(C_word)a,a+=4,tmp);
t3=C_i_check_list_2(((C_word*)t0)[2],lf[70]);
t4=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_6349,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],tmp=(C_word)a,a+=15,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6650,a[2]=t6,a[3]=t2,a[4]=((C_word)li13),tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_6650(t8,t4,((C_word*)t0)[2]);}

/* g3048 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_fcall f_6333(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_6333,3,t0,t1,t2);}
if(C_truep(C_i_memq(t2,((C_word*)t0)[2]))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* chicken-syntax.scm:1101: chicken.syntax#syntax-error */
t3=*((C_word*)lf[59]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t1;
av2[2]=lf[67];
av2[3]=lf[69];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_ccall f_6349(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(53,c,3)))){
C_save_and_reclaim((void *)f_6349,c,av);}
a=C_alloc(53);
t2=C_a_i_list(&a,2,lf[39],((C_word*)t0)[2]);
t3=C_a_i_list(&a,3,((C_word*)t0)[3],((C_word*)t0)[4],t2);
t4=C_a_i_list(&a,2,lf[39],((C_word*)t0)[2]);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6597,a[2]=((C_word*)t0)[5],a[3]=((C_word)li10),tmp=(C_word)a,a+=4,tmp);
t10=C_i_check_list_2(((C_word*)t0)[6],lf[68]);
t11=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6610,a[2]=t4,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[2],a[8]=t3,a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],tmp=(C_word)a,a+=14,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6612,a[2]=t9,a[3]=t7,a[4]=t13,a[5]=t8,a[6]=((C_word)li12),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_6612(t15,t11,((C_word*)t0)[6]);}

/* k6378 in k6608 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in ... */
static void C_ccall f_6380(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_6380,c,av);}
a=C_alloc(12);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=C_a_i_cons(&a,2,((C_word*)t0)[4],t3);
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_cons(&a,2,lf[29],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* loop in k6608 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in ... */
static void C_fcall f_6382(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,0,3)))){
C_save_and_reclaim_args((void *)trf_6382,4,t0,t1,t2,t3);}
a=C_alloc(19);
if(C_truep(C_i_nullp(t2))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_car(t2);
t5=C_i_cddr(t4);
t6=C_i_pairp(t5);
t7=(C_truep(t6)?C_i_caddr(t4):C_SCHEME_FALSE);
t8=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_6401,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t4,a[5]=t3,a[6]=t1,a[7]=t2,a[8]=((C_word*)t0)[4],a[9]=t6,a[10]=((C_word*)t0)[5],a[11]=((C_word*)t0)[6],a[12]=t7,a[13]=((C_word*)t0)[7],a[14]=((C_word*)t0)[8],tmp=(C_word)a,a+=15,tmp);
if(C_truep(C_i_pairp(t7))){
if(C_truep(C_i_pairp(C_u_i_cdr(t7)))){
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6554,a[2]=t8,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1126: c */
t10=((C_word*)t0)[5];{
C_word av2[4];
av2[0]=t10;
av2[1]=t9;
av2[2]=lf[78];
av2[3]=C_u_i_car(t7);
((C_proc)(void*)(*((C_word*)t10+1)))(4,av2);}}
else{
t9=t8;
f_6401(t9,C_SCHEME_FALSE);}}
else{
t9=t8;
f_6401(t9,C_SCHEME_FALSE);}}}

/* k6399 in loop in k6608 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in ... */
static void C_fcall f_6401(C_word t0,C_word t1){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(128,0,2)))){
C_save_and_reclaim_args((void *)trf_6401,2,t0,t1);}
a=C_alloc(128);
t2=C_a_i_list(&a,1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,2,lf[39],((C_word*)t0)[3]);
t4=C_i_cadr(((C_word*)t0)[4]);
t5=C_a_i_list(&a,2,lf[39],t4);
t6=C_a_i_list(&a,4,lf[74],((C_word*)t0)[2],t3,t5);
t7=C_a_i_list(&a,2,lf[35],t6);
t8=C_a_i_list(&a,3,lf[75],((C_word*)t0)[2],((C_word*)t0)[5]);
t9=C_a_i_list(&a,4,lf[23],t2,t7,t8);
t10=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6407,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[9],a[7]=t1,a[8]=((C_word*)t0)[10],a[9]=((C_word*)t0)[4],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=t9,tmp=(C_word)a,a+=14,tmp);
if(C_truep(((C_word*)t0)[9])){
t11=C_a_i_list(&a,2,((C_word*)t0)[2],((C_word*)t0)[14]);
t12=C_a_i_list(&a,2,lf[39],((C_word*)t0)[3]);
t13=C_a_i_list(&a,2,lf[39],t1);
t14=C_a_i_list(&a,4,lf[74],((C_word*)t0)[2],t12,t13);
t15=C_a_i_list(&a,2,lf[35],t14);
t16=C_a_i_list(&a,4,lf[77],((C_word*)t0)[2],((C_word*)t0)[5],((C_word*)t0)[14]);
t17=t10;
f_6407(t17,C_a_i_list(&a,4,lf[23],t11,t15,t16));}
else{
t11=t10;
f_6407(t11,C_SCHEME_FALSE);}}

/* k6405 in k6399 in loop in k6608 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in ... */
static void C_fcall f_6407(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,0,3)))){
C_save_and_reclaim_args((void *)trf_6407,2,t0,t1);}
a=C_alloc(21);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6414,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
t3=C_u_i_cdr(((C_word*)t0)[9]);
t4=C_u_i_car(t3);
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6475,a[2]=((C_word*)t0)[12],a[3]=((C_word*)t0)[13],a[4]=t1,a[5]=t2,a[6]=((C_word*)t0)[10],a[7]=t4,tmp=(C_word)a,a+=8,tmp);
if(C_truep(((C_word*)t0)[7])){
t6=C_u_i_cdr(((C_word*)t0)[9]);
/* chicken-syntax.scm:1147: c */
t7=((C_word*)t0)[8];{
C_word av2[4];
av2[0]=t7;
av2[1]=t5;
av2[2]=((C_word*)t0)[7];
av2[3]=C_u_i_car(t6);
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t6=t5;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
f_6475(2,av2);}}}

/* k6412 in k6405 in k6399 in loop in k6608 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in ... */
static void C_fcall f_6414(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(22,0,3)))){
C_save_and_reclaim_args((void *)trf_6414,2,t0,t1);}
a=C_alloc(22);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6418,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6422,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[6])){
if(C_truep(((C_word*)t0)[7])){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6454,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[8],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:1152: c */
t5=((C_word*)t0)[9];{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[7];
av2[3]=C_i_cadr(((C_word*)t0)[10]);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
t4=C_a_i_list(&a,3,((C_word*)t0)[11],((C_word*)t0)[12],((C_word*)t0)[8]);
t5=t3;
f_6422(t5,C_a_i_list(&a,1,t4));}}
else{
t4=t3;
f_6422(t4,C_SCHEME_END_OF_LIST);}}

/* k6416 in k6412 in k6405 in k6399 in loop in k6608 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in ... */
static void C_ccall f_6418(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_6418,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k6420 in k6412 in k6405 in k6399 in loop in k6608 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in ... */
static void C_fcall f_6422(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,0,3)))){
C_save_and_reclaim_args((void *)trf_6422,2,t0,t1);}
a=C_alloc(33);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6426,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_u_i_cdr(((C_word*)t0)[3]);
t4=C_s_a_i_plus(&a,2,((C_word*)t0)[4],C_fix(1));
/* chicken-syntax.scm:1157: loop */
t5=((C_word*)((C_word*)t0)[5])[1];
f_6382(t5,t2,t3,t4);}

/* k6424 in k6420 in k6412 in k6405 in k6399 in loop in k6608 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in ... */
static void C_ccall f_6426(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6426,c,av);}
/* chicken-syntax.scm:1145: ##sys#append */
t2=*((C_word*)lf[56]+1);{
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

/* k6452 in k6412 in k6405 in k6399 in loop in k6608 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in ... */
static void C_ccall f_6454(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,1)))){
C_save_and_reclaim((void *)f_6454,c,av);}
a=C_alloc(18);
if(C_truep(C_i_not(t1))){
t2=C_a_i_list(&a,2,lf[76],lf[76]);
t3=C_a_i_list(&a,3,t2,((C_word*)t0)[2],((C_word*)t0)[3]);
t4=((C_word*)t0)[4];
f_6422(t4,C_a_i_list(&a,1,t3));}
else{
t2=((C_word*)t0)[4];
f_6422(t2,C_SCHEME_END_OF_LIST);}}

/* k6473 in k6405 in k6399 in loop in k6608 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in ... */
static void C_ccall f_6475(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,1)))){
C_save_and_reclaim((void *)f_6475,c,av);}
a=C_alloc(18);
if(C_truep(t1)){
t2=C_a_i_list(&a,3,((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4]);
t3=((C_word*)t0)[5];
f_6414(t3,C_a_i_list(&a,3,((C_word*)t0)[6],((C_word*)t0)[7],t2));}
else{
t2=((C_word*)t0)[5];
f_6414(t2,C_a_i_list(&a,3,((C_word*)t0)[6],((C_word*)t0)[7],((C_word*)t0)[3]));}}

/* k6552 in loop in k6608 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in ... */
static void C_ccall f_6554(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6554,c,av);}
t2=((C_word*)t0)[2];
f_6401(t2,(C_truep(t1)?C_i_cadr(((C_word*)t0)[3]):C_SCHEME_FALSE));}

/* g3074 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static C_word C_fcall f_6597(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_stack_overflow_check;{}
t2=C_i_memq(t1,((C_word*)t0)[2]);
return((C_truep(t2)?t1:lf[71]));}

/* k6608 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static void C_ccall f_6610(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(63,c,4)))){
C_save_and_reclaim((void *)f_6610,c,av);}
a=C_alloc(63);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,lf[72],t2);
t4=C_a_i_list(&a,3,((C_word*)t0)[3],((C_word*)t0)[4],t3);
t5=C_a_i_list(&a,2,((C_word*)t0)[5],((C_word*)t0)[6]);
t6=C_a_i_list(&a,2,lf[39],((C_word*)t0)[7]);
t7=C_a_i_list(&a,3,lf[73],((C_word*)t0)[6],t6);
t8=C_a_i_list(&a,3,((C_word*)t0)[3],t5,t7);
t9=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6380,a[2]=t8,a[3]=t4,a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[9],tmp=(C_word)a,a+=6,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6382,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=t11,a[5]=((C_word*)t0)[10],a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[11],a[8]=((C_word*)t0)[12],a[9]=((C_word)li11),tmp=(C_word)a,a+=10,tmp));
t13=((C_word*)t11)[1];
f_6382(t13,t9,((C_word*)t0)[13],C_fix(1));}

/* map-loop3068 in k6347 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static void C_fcall f_6612(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_6612,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=(
/* chicken-syntax.scm:1112: g3074 */
  f_6597(((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* for-each-loop3047 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_fcall f_6650(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_6650,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6660,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:1099: g3048 */
t4=((C_word*)t0)[3];
f_6333(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6658 in for-each-loop3047 in k6330 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static void C_ccall f_6660(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6660,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6650(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* map-loop3021 in k6321 in k6318 in k6312 in k6309 in k6297 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_fcall f_6673(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_6673,3,t0,t1,t2);}
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

/* k6706 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_6708(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_6708,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6715,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6719,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1086: ##sys#current-module */
t4=*((C_word*)lf[86]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
f_6299(2,av2);}}}

/* k6713 in k6706 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_6715(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6715,c,av);}
/* chicken-syntax.scm:1085: chicken.base#symbol-append */
t2=*((C_word*)lf[83]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[84];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k6717 in k6706 in k6294 in k6288 in a6285 in k5656 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_6719(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6719,c,av);}
/* chicken-syntax.scm:1086: ##sys#module-name */
t2=*((C_word*)lf[85]+1);{
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

/* k6721 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in ... */
static void C_ccall f_6723(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6723,c,av);}
/* chicken-syntax.scm:1039: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[88];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in ... */
static void C_ccall f_6725(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6725,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6729,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:1043: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[88];
av2[3]=t2;
av2[4]=lf[92];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_ccall f_6729(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6729,c,av);}
a=C_alloc(5);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_u_i_cdr(t3);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6737,a[2]=t2,a[3]=t4,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:1046: r */
t6=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[91];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k6735 in k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_6737(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_6737,c,av);}
a=C_alloc(9);
if(C_truep(C_i_pairp(((C_word*)t0)[2]))){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6746,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t3=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
/* chicken-syntax.scm:1048: ##sys#check-syntax */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[88];
av2[3]=t3;
av2[4]=lf[89];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6796,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
t3=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
/* chicken-syntax.scm:1061: ##sys#check-syntax */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[88];
av2[3]=t3;
av2[4]=lf[90];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* k6744 in k6735 in k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_6746(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6746,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6749,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:1051: chicken.syntax#strip-syntax */
t3=*((C_word*)lf[40]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_slot(((C_word*)t0)[2],C_fix(0));
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6747 in k6744 in k6735 in k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_6749(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_6749,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6752,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6774,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1052: ##sys#current-module */
t4=*((C_word*)lf[86]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k6750 in k6747 in k6744 in k6735 in k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_6752(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6752,c,av);}
a=C_alloc(21);
t2=C_a_i_list(&a,2,lf[39],t1);
t3=C_slot(((C_word*)t0)[2],C_fix(1));
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[3]);
t5=C_a_i_cons(&a,2,lf[23],t4);
t6=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,3,((C_word*)t0)[5],t2,t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k6772 in k6747 in k6744 in k6735 in k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_6774(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_6774,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6781,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6785,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1054: ##sys#current-module */
t4=*((C_word*)lf[86]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
f_6752(2,av2);}}}

/* k6779 in k6772 in k6747 in k6744 in k6735 in k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_6781(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6781,c,av);}
/* chicken-syntax.scm:1053: chicken.base#symbol-append */
t2=*((C_word*)lf[83]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[84];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k6783 in k6772 in k6747 in k6744 in k6735 in k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_6785(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6785,c,av);}
/* chicken-syntax.scm:1054: ##sys#module-name */
t2=*((C_word*)lf[85]+1);{
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

/* k6794 in k6735 in k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_6796(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6796,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6799,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:1062: chicken.syntax#strip-syntax */
t3=*((C_word*)lf[40]+1);{
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

/* k6797 in k6794 in k6735 in k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_6799(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_6799,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6802,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6816,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:1063: ##sys#current-module */
t4=*((C_word*)lf[86]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k6800 in k6797 in k6794 in k6735 in k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_6802(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_6802,c,av);}
a=C_alloc(12);
t2=C_a_i_list(&a,2,lf[39],t1);
t3=C_a_i_cons(&a,2,t2,((C_word*)t0)[2]);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[4],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k6814 in k6797 in k6794 in k6735 in k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_6816(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_6816,c,av);}
a=C_alloc(12);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6823,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6827,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:1065: ##sys#current-module */
t4=*((C_word*)lf[86]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=C_a_i_list(&a,2,lf[39],((C_word*)t0)[3]);
t3=C_a_i_cons(&a,2,t2,((C_word*)t0)[4]);
t4=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[6],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6821 in k6814 in k6797 in k6794 in k6735 in k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_6823(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6823,c,av);}
/* chicken-syntax.scm:1064: chicken.base#symbol-append */
t2=*((C_word*)lf[83]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[84];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k6825 in k6814 in k6797 in k6794 in k6735 in k6727 in a6724 in k5653 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_6827(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6827,c,av);}
/* chicken-syntax.scm:1065: ##sys#module-name */
t2=*((C_word*)lf[85]+1);{
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

/* k6837 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in ... */
static void C_ccall f_6839(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6839,c,av);}
/* chicken-syntax.scm:971: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[103];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in ... */
static void C_ccall f_6841(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6841,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6845,a[2]=t3,a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:980: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[103];
av2[3]=t2;
av2[4]=lf[112];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in ... */
static void C_ccall f_6845(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(26,c,3)))){
C_save_and_reclaim((void *)f_6845,c,av);}
a=C_alloc(26);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6847,a[2]=((C_word*)t0)[2],a[3]=((C_word)li18),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6882,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_i_cdr(((C_word*)t0)[3]);
t9=C_i_check_list_2(t8,lf[68]);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7221,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7223,a[2]=t6,a[3]=t12,a[4]=t7,a[5]=((C_word)li28),tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_7223(t14,t10,t8);}

/* genvars in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_fcall f_6847(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_6847,3,t0,t1,t2);}
a=C_alloc(8);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6853,a[2]=t2,a[3]=t4,a[4]=((C_word*)t0)[2],a[5]=((C_word)li17),tmp=(C_word)a,a+=6,tmp));
t6=((C_word*)t4)[1];
f_6853(t6,t1,C_fix(0));}

/* loop in genvars in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_fcall f_6853(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_6853,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6867,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6879,a[2]=((C_word*)t0)[4],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:985: chicken.base#gensym */
t5=*((C_word*)lf[57]+1);{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k6865 in loop in genvars in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_6867(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6867,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6871,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:985: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_6853(t3,t2,C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}

/* k6869 in k6865 in loop in genvars in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_6871(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_6871,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k6877 in loop in genvars in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_6879(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6879,c,av);}
/* chicken-syntax.scm:985: r */
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

/* k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_ccall f_6882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6882,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6885,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:991: genvars */
t3=((C_word*)t0)[5];
f_6847(t3,t2,t1);}

/* k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_6885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_6885,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6888,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:992: r */
t3=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[110];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_6888(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_6888,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6891,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* chicken-syntax.scm:993: r */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[109];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_6891(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_6891,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6894,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* chicken-syntax.scm:994: r */
t3=((C_word*)t0)[7];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[93];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_6894(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_6894,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6897,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:995: r */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[99];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_6897(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_6897,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6900,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t1,tmp=(C_word)a,a+=11,tmp);
/* chicken-syntax.scm:996: r */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[95];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in ... */
static void C_ccall f_6900(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_6900,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6903,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* chicken-syntax.scm:997: r */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[97];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in ... */
static void C_ccall f_6903(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_6903,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6906,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* chicken-syntax.scm:998: r */
t3=((C_word*)t0)[9];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[101];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_ccall f_6906(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_6906,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6913,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
/* chicken-syntax.scm:1000: scheme#append */
t3=*((C_word*)lf[108]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_ccall f_6913(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(35,c,3)))){
C_save_and_reclaim((void *)f_6913,c,av);}
a=C_alloc(35);
t2=C_a_i_list(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_list(&a,2,((C_word*)t0)[4],t2);
t4=C_a_i_list(&a,1,t3);
t5=C_u_i_cdr(((C_word*)t0)[5]);
t6=C_i_check_list_2(t5,lf[104]);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6929,a[2]=t4,a[3]=((C_word*)t0)[6],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6931,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[9],a[5]=((C_word*)t0)[10],a[6]=((C_word*)t0)[11],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[12],a[9]=((C_word*)t0)[4],a[10]=((C_word*)t0)[13],a[11]=t9,a[12]=((C_word)li26),tmp=(C_word)a,a+=13,tmp));
t11=((C_word*)t9)[1];
f_6931(t11,t7,t5);}

/* k6927 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static void C_ccall f_6929(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,1)))){
C_save_and_reclaim((void *)f_6929,c,av);}
a=C_alloc(18);
t2=C_a_i_list(&a,3,lf[38],((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,3,lf[23],((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static void C_fcall f_6931(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(17,0,4)))){
C_save_and_reclaim_args((void *)trf_6931,3,t0,t1,t2);}
a=C_alloc(17);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6939,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word)li25),tmp=(C_word)a,a+=12,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7184,a[2]=t3,a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t7=t5;
t8=C_slot(t2,C_fix(1));
t1=t7;
t2=t8;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=lf[107];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in ... */
static void C_fcall f_6939(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,0,5)))){
C_save_and_reclaim_args((void *)trf_6939,4,t0,t1,t2,t3);}
a=C_alloc(14);
t4=C_i_car(t2);
t5=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6949,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=t2,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],a[10]=((C_word*)t0)[8],a[11]=((C_word*)t0)[9],a[12]=((C_word*)t0)[10],a[13]=((C_word)li24),tmp=(C_word)a,a+=14,tmp);
/* chicken-syntax.scm:1005: ##sys#decompose-lambda-list */
t6=*((C_word*)lf[106]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t1;
av2[2]=t4;
av2[3]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in ... */
static void C_ccall f_6949(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,4)))){
C_save_and_reclaim((void *)f_6949,c,av);}
a=C_alloc(17);
t5=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_6953,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=t2,a[7]=((C_word*)t0)[4],a[8]=t4,a[9]=((C_word*)t0)[5],a[10]=((C_word*)t0)[6],a[11]=((C_word*)t0)[7],a[12]=((C_word*)t0)[8],a[13]=((C_word*)t0)[9],a[14]=((C_word*)t0)[10],a[15]=((C_word*)t0)[11],a[16]=((C_word*)t0)[12],tmp=(C_word)a,a+=17,tmp);
/* chicken-syntax.scm:1008: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[103];
av2[3]=C_i_car(((C_word*)t0)[5]);
av2[4]=lf[105];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in ... */
static void C_ccall f_6953(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(23,c,2)))){
C_save_and_reclaim((void *)f_6953,c,av);}
a=C_alloc(23);
t2=C_fixnum_difference(((C_word*)t0)[2],((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6963,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],tmp=(C_word)a,a+=14,tmp);
if(C_truep(((C_word*)t0)[8])){
t4=C_eqp(t2,C_fix(0));
t5=t3;
f_6963(t5,(C_truep(t4)?C_SCHEME_TRUE:C_a_i_list(&a,3,((C_word*)t0)[14],((C_word*)t0)[15],t2)));}
else{
t4=t3;
f_6963(t4,C_a_i_list(&a,3,((C_word*)t0)[16],((C_word*)t0)[15],t2));}}

/* k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in ... */
static void C_fcall f_6963(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,0,4)))){
C_save_and_reclaim_args((void *)trf_6963,2,t0,t1);}
a=C_alloc(21);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6967,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6969,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word)li20),tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6979,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[9],a[5]=((C_word*)t0)[10],a[6]=((C_word*)t0)[11],a[7]=((C_word*)t0)[12],a[8]=((C_word*)t0)[13],a[9]=((C_word)li23),tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:1015: ##sys#call-with-values */{
C_word av2[4];
av2[0]=0;
av2[1]=t2;
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}

/* k6965 in k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in ... */
static void C_ccall f_6967(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_6967,c,av);}
a=C_alloc(12);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,4,lf[37],((C_word*)t0)[3],t1,((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a6968 in k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in ... */
static void C_ccall f_6969(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_6969,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6977,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1016: take */
f_4347(t2,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* k6975 in a6968 in k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in ... */
static void C_ccall f_6977(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_6977,c,av);}
a=C_alloc(6);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4405,a[2]=t3,a[3]=((C_word)li19),tmp=(C_word)a,a+=4,tmp));
t5=((C_word*)t3)[1];
f_4405(t5,((C_word*)t0)[2],((C_word*)t0)[3],C_SCHEME_END_OF_LIST,t1);}

/* a6978 in k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in ... */
static void C_ccall f_6979(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,4)))){
C_save_and_reclaim((void *)f_6979,c,av);}
a=C_alloc(16);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6983,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7055,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=t6,a[7]=((C_word*)t0)[7],a[8]=((C_word)li22),tmp=(C_word)a,a+=9,tmp));
t8=((C_word*)t6)[1];
f_7055(t8,t4,t3,((C_word*)t0)[8]);}

/* k6981 in a6978 in k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in ... */
static void C_ccall f_6983(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,4)))){
C_save_and_reclaim((void *)f_6983,c,av);}
a=C_alloc(17);
if(C_truep(C_i_nullp(((C_word*)t0)[2]))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[68]);
t7=C_i_check_list_2(((C_word*)t0)[4],lf[68]);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7005,a[2]=((C_word*)t0)[3],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7007,a[2]=t4,a[3]=t10,a[4]=t5,a[5]=((C_word)li21),tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_7007(t12,t8,((C_word*)t0)[2],((C_word*)t0)[4]);}}

/* k7003 in k6981 in a6978 in k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in ... */
static void C_ccall f_7005(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_7005,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[38],t1,((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop2944 in k6981 in a6978 in k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in ... */
static void C_fcall f_7007(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_7007,4,t0,t1,t2,t3);}
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

/* build in a6978 in k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in ... */
static void C_fcall f_7055(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,2)))){
C_save_and_reclaim_args((void *)trf_7055,4,t0,t1,t2,t3);}
a=C_alloc(15);
if(C_truep(C_i_nullp(t2))){
if(C_truep(((C_word*)t0)[2])){
t4=C_a_i_list(&a,2,((C_word*)t0)[2],t3);
t5=C_a_i_list(&a,1,t4);
t6=C_i_cdr(((C_word*)t0)[3]);
t7=C_a_i_cons(&a,2,t5,t6);
t8=t1;{
C_word av2[2];
av2[0]=t8;
av2[1]=C_a_i_cons(&a,2,lf[38],t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t4=C_i_cddr(((C_word*)t0)[3]);
if(C_truep(C_i_nullp(t4))){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_u_i_car(C_u_i_cdr(((C_word*)t0)[3]));
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_u_i_cdr(((C_word*)t0)[3]);
t6=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,t5);
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=C_a_i_cons(&a,2,lf[38],t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}}
else{
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7108,a[2]=t2,a[3]=((C_word*)t0)[4],a[4]=t3,a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7156,a[2]=((C_word*)t0)[7],a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:1023: chicken.base#gensym */
t6=*((C_word*)lf[57]+1);{
C_word av2[2];
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k7106 in build in a6978 in k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in ... */
static void C_ccall f_7108(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7108,c,av);}
a=C_alloc(34);
t2=C_i_car(((C_word*)t0)[2]);
t3=C_a_i_list(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
t4=C_a_i_list(&a,2,t2,t3);
t5=C_a_i_list(&a,2,((C_word*)t0)[5],((C_word*)t0)[4]);
t6=C_a_i_list(&a,2,t1,t5);
t7=C_a_i_list(&a,2,t4,t6);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7119,a[2]=((C_word*)t0)[6],a[3]=t7,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_pairp(C_u_i_cdr(((C_word*)t0)[2])))){
/* chicken-syntax.scm:1027: build */
t9=((C_word*)((C_word*)t0)[7])[1];
f_7055(t9,t8,C_u_i_cdr(((C_word*)t0)[2]),t1);}
else{
/* chicken-syntax.scm:1028: build */
t9=((C_word*)((C_word*)t0)[7])[1];
f_7055(t9,t8,C_SCHEME_END_OF_LIST,t1);}}

/* k7117 in k7106 in build in a6978 in k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in ... */
static void C_ccall f_7119(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_7119,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7154 in build in a6978 in k6961 in k6951 in a6948 in g2901 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in ... */
static void C_ccall f_7156(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7156,c,av);}
/* chicken-syntax.scm:1023: r */
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

/* k7182 in foldr2896 in k6911 in k6904 in k6901 in k6898 in k6895 in k6892 in k6889 in k6886 in k6883 in k6880 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in ... */
static void C_ccall f_7184(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7184,c,av);}
/* chicken-syntax.scm:1003: g2901 */
t2=((C_word*)t0)[2];
f_6939(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* a7210 in map-loop2853 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_7211(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7211,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k7219 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_ccall f_7221(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7221,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[111]+1);
av2[3]=t1;
C_apply(4,av2);}}

/* map-loop2853 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_fcall f_7223(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,5)))){
C_save_and_reclaim_args((void *)trf_7223,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7248,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
t5=C_i_car(t4);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7211,a[2]=((C_word)li27),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:987: ##sys#decompose-lambda-list */
t7=*((C_word*)lf[106]+1);{
C_word av2[4];
av2[0]=t7;
av2[1]=t3;
av2[2]=t5;
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7246 in map-loop2853 in k6843 in a6840 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_7248(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7248,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7223(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7281 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_7283(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7283,c,av);}
/* chicken-syntax.scm:936: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[115];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a7284 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_7285(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7285,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7289,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:943: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[115];
av2[3]=t2;
av2[4]=lf[117];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k7287 in a7284 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in ... */
static void C_ccall f_7289(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_7289,c,av);}
a=C_alloc(7);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_i_caddr(((C_word*)t0)[2]);
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=C_u_i_cdr(t4);
t6=C_u_i_cdr(t5);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7301,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=t6,a[5]=((C_word*)t0)[4],a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:947: r */
t8=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=lf[113];
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}

/* k7299 in k7287 in a7284 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in ... */
static void C_ccall f_7301(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7301,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7304,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* chicken-syntax.scm:948: r */
t3=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[95];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7302 in k7299 in k7287 in a7284 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_ccall f_7304(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_7304,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7307,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* chicken-syntax.scm:949: r */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[97];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7305 in k7302 in k7299 in k7287 in a7284 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_7307(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_7307,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7310,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:950: r */
t3=((C_word*)t0)[7];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[45];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7308 in k7305 in k7302 in k7299 in k7287 in a7284 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_7310(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,4)))){
C_save_and_reclaim((void *)f_7310,c,av);}
a=C_alloc(24);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7321,a[2]=((C_word*)t0)[3],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7323,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=t6,a[7]=((C_word*)t0)[8],a[8]=((C_word)li30),tmp=(C_word)a,a+=9,tmp));
t8=((C_word*)t6)[1];
f_7323(t8,t4,t1,((C_word*)t0)[9]);}

/* k7319 in k7308 in k7305 in k7302 in k7299 in k7287 in a7284 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_7321(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_7321,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in k7308 in k7305 in k7302 in k7299 in k7287 in a7284 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_fcall f_7323(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,2)))){
C_save_and_reclaim_args((void *)trf_7323,4,t0,t1,t2,t3);}
a=C_alloc(15);
if(C_truep(C_i_nullp(t3))){
t4=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,((C_word*)t0)[2]);
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_a_i_cons(&a,2,lf[38],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_i_car(t3);
if(C_truep(C_i_pairp(t4))){
t5=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7349,a[2]=t4,a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=t1,a[8]=((C_word*)t0)[6],a[9]=t3,tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:958: r */
t6=((C_word*)t0)[7];{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[116];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=C_a_i_list(&a,2,t4,t2);
t6=C_a_i_list(&a,1,t5);
t7=C_a_i_cons(&a,2,t6,((C_word*)t0)[2]);
t8=t1;{
C_word av2[2];
av2[0]=t8;
av2[1]=C_a_i_cons(&a,2,lf[38],t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}}

/* k7347 in loop in k7308 in k7305 in k7302 in k7299 in k7287 in a7284 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_7349(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(76,c,3)))){
C_save_and_reclaim((void *)f_7349,c,av);}
a=C_alloc(76);
t2=C_u_i_car(((C_word*)t0)[2]);
t3=C_a_i_list(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
t4=C_i_cadr(((C_word*)t0)[2]);
t5=C_a_i_list(&a,2,((C_word*)t0)[5],((C_word*)t0)[4]);
t6=C_a_i_list(&a,4,lf[37],t3,t4,t5);
t7=C_a_i_list(&a,2,t2,t6);
t8=C_a_i_list(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
t9=C_a_i_list(&a,2,lf[39],C_SCHEME_END_OF_LIST);
t10=C_a_i_list(&a,2,((C_word*)t0)[6],((C_word*)t0)[4]);
t11=C_a_i_list(&a,4,lf[37],t8,t9,t10);
t12=C_a_i_list(&a,2,t1,t11);
t13=C_a_i_list(&a,2,t7,t12);
t14=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7360,a[2]=((C_word*)t0)[7],a[3]=t13,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:965: loop */
t15=((C_word*)((C_word*)t0)[8])[1];
f_7323(t15,t14,t1,C_u_i_cdr(((C_word*)t0)[9]));}

/* k7358 in k7347 in loop in k7308 in k7305 in k7302 in k7299 in k7287 in a7284 in k5647 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_7360(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_7360,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7441 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_7443(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7443,c,av);}
/* chicken-syntax.scm:908: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[118];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a7444 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_7445(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7445,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7449,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:915: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[118];
av2[3]=t2;
av2[4]=lf[119];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k7447 in a7444 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_7449(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_7449,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7452,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:916: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[45];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7450 in k7447 in a7444 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in ... */
static void C_ccall f_7452(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7452,c,av);}
a=C_alloc(16);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_a_i_list(&a,2,t1,t2);
t4=C_a_i_list(&a,1,t3);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7492,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t4,a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:918: r */
t6=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[113];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k7480 in k7490 in k7450 in k7447 in a7444 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_ccall f_7482(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,1)))){
C_save_and_reclaim((void *)f_7482,c,av);}
a=C_alloc(27);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,4,lf[37],((C_word*)t0)[3],((C_word*)t0)[4],t2);
t4=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[6],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k7490 in k7450 in k7447 in a7444 in k5644 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in ... */
static void C_ccall f_7492(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7492,c,av);}
a=C_alloc(13);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_i_cddr(((C_word*)t0)[3]);
t4=C_i_nullp(t3);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_i_car(t3));
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7482,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t5,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:920: r */
t7=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[95];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k7518 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_7520(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7520,c,av);}
/* chicken-syntax.scm:819: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[120];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_7522(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7522,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7526,a[2]=t2,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:826: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[120];
av2[3]=t2;
av2[4]=lf[130];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_7526(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,6)))){
C_save_and_reclaim((void *)f_7526,c,av);}
a=C_alloc(12);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_i_caddr(((C_word*)t0)[2]);
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=C_u_i_cdr(t4);
t6=C_u_i_cdr(t5);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7616,a[2]=((C_word*)t0)[3],a[3]=((C_word)li34),tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7709,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=t6,a[6]=((C_word*)t0)[4],a[7]=t7,tmp=(C_word)a,a+=8,tmp);
/* chicken-syntax.scm:865: ##sys#check-syntax */
t9=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t9;
av2[1]=t8;
av2[2]=lf[120];
av2[3]=t3;
av2[4]=lf[129];
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}

/* k7543 in k7777 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_7545(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_7545,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7549,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:836: scheme#reverse */
t3=*((C_word*)lf[58]+1);{
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

/* k7547 in k7543 in k7777 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in ... */
static void C_ccall f_7549(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_7549,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7553,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:837: scheme#reverse */
t3=*((C_word*)lf[58]+1);{
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

/* k7551 in k7547 in k7543 in k7777 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in ... */
static void C_ccall f_7553(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,6)))){
C_save_and_reclaim((void *)f_7553,c,av);}
a=C_alloc(6);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7555,a[2]=t3,a[3]=((C_word)li38),tmp=(C_word)a,a+=4,tmp));
t5=((C_word*)t3)[1];
f_7555(t5,((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4],t1,((C_word*)t0)[5]);}

/* recur in k7551 in k7547 in k7543 in k7777 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in ... */
static void C_fcall f_7555(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_7555,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t2))){
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_i_cdr(t2);
t7=C_i_car(t3);
t8=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7594,a[2]=t5,a[3]=t7,a[4]=t1,a[5]=((C_word*)t0)[2],a[6]=t6,a[7]=t3,a[8]=t4,tmp=(C_word)a,a+=9,tmp);
/* chicken-syntax.scm:842: scheme#reverse */
t9=*((C_word*)lf[58]+1);{
C_word av2[3];
av2[0]=t9;
av2[1]=t8;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}}

/* k7574 in k7600 in k7592 in recur in k7551 in k7547 in k7543 in k7777 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in ... */
static void C_ccall f_7576(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7576,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7592 in recur in k7551 in k7547 in k7543 in k7777 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in ... */
static void C_ccall f_7594(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_7594,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7602,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7606,a[2]=((C_word*)t0)[8],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:843: scheme#reverse */
t4=*((C_word*)lf[58]+1);{
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

/* k7600 in k7592 in recur in k7551 in k7547 in k7543 in k7777 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static void C_ccall f_7602(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(22,c,5)))){
C_save_and_reclaim((void *)f_7602,c,av);}
a=C_alloc(22);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_list(&a,3,lf[23],((C_word*)t0)[3],t2);
t4=C_a_i_list(&a,2,((C_word*)t0)[4],t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7576,a[2]=((C_word*)t0)[5],a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:844: recur */
t6=((C_word*)((C_word*)t0)[6])[1];
f_7555(t6,t5,((C_word*)t0)[7],C_u_i_cdr(((C_word*)t0)[8]),C_u_i_cdr(((C_word*)t0)[9]),C_u_i_car(((C_word*)t0)[8]));}

/* k7604 in k7592 in recur in k7551 in k7547 in k7543 in k7777 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in ... */
static void C_ccall f_7606(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_7606,c,av);}
a=C_alloc(3);
t2=C_i_car(((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
/* chicken-syntax.scm:841: ##sys#append */
t4=*((C_word*)lf[56]+1);{
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

/* make-if-tree in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_fcall f_7616(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,5)))){
C_save_and_reclaim_args((void *)trf_7616,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(9);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7622,a[2]=t4,a[3]=t5,a[4]=t7,a[5]=((C_word*)t0)[2],a[6]=((C_word)li33),tmp=(C_word)a,a+=7,tmp));
t9=((C_word*)t7)[1];
f_7622(t9,t1,t2,t3,C_SCHEME_END_OF_LIST);}

/* recur in make-if-tree in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in ... */
static void C_fcall f_7622(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_7622,5,t0,t1,t2,t3,t4);}
a=C_alloc(10);
if(C_truep(C_i_nullp(t2))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7636,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:855: scheme#reverse */
t6=*((C_word*)lf[58]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=C_i_car(t2);
t6=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7706,a[2]=((C_word*)t0)[3],a[3]=t3,a[4]=t5,a[5]=t1,a[6]=t2,a[7]=t4,a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[5],tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:857: r */
t7=((C_word*)t0)[5];{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[113];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}}

/* k7634 in recur in make-if-tree in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in ... */
static void C_ccall f_7636(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7636,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7660 in k7684 in k7692 in k7700 in k7704 in recur in make-if-tree in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_7662(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,c,1)))){
C_save_and_reclaim((void *)f_7662,c,av);}
a=C_alloc(21);
t2=C_a_i_list(&a,3,lf[38],((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,4,lf[37],((C_word*)t0)[4],((C_word*)t0)[5],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k7684 in k7692 in k7700 in k7704 in recur in make-if-tree in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_7686(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(27,c,4)))){
C_save_and_reclaim((void *)f_7686,c,av);}
a=C_alloc(27);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,2,((C_word*)t0)[2],t2);
t4=C_a_i_list(&a,2,((C_word*)t0)[3],t3);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7662,a[2]=t4,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
t6=C_u_i_cdr(((C_word*)t0)[7]);
t7=C_u_i_cdr(((C_word*)t0)[8]);
t8=C_a_i_cons(&a,2,((C_word*)t0)[9],((C_word*)t0)[10]);
/* chicken-syntax.scm:861: recur */
t9=((C_word*)((C_word*)t0)[11])[1];
f_7622(t9,t5,t6,t7,t8);}

/* k7692 in k7700 in k7704 in recur in make-if-tree in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_7694(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,2)))){
C_save_and_reclaim((void *)f_7694,c,av);}
a=C_alloc(24);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,2,((C_word*)t0)[3],t2);
t4=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7686,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[3],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* chicken-syntax.scm:860: r */
t5=((C_word*)t0)[11];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[97];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7700 in k7704 in recur in make-if-tree in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_ccall f_7702(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_7702,c,av);}
a=C_alloc(15);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7694,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=t2,a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
/* chicken-syntax.scm:859: r */
t4=((C_word*)t0)[11];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[95];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k7704 in recur in make-if-tree in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in ... */
static void C_ccall f_7706(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_7706,c,av);}
a=C_alloc(18);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_i_car(((C_word*)t0)[3]);
t4=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7702,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t2,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[3],a[9]=((C_word*)t0)[7],a[10]=((C_word*)t0)[8],a[11]=((C_word*)t0)[9],tmp=(C_word)a,a+=12,tmp);
/* chicken-syntax.scm:858: scheme#reverse */
t5=*((C_word*)lf[58]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_7709(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_7709,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7712,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* chicken-syntax.scm:866: ##sys#check-syntax */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[120];
av2[3]=((C_word*)t0)[5];
av2[4]=lf[128];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in ... */
static void C_ccall f_7712(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7712,c,av);}
a=C_alloc(21);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[68]);
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7721,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7920,a[2]=t4,a[3]=t9,a[4]=t5,a[5]=((C_word)li42),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_7920(t11,t7,((C_word*)t0)[2]);}

/* k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in ... */
static void C_ccall f_7721(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(32,c,4)))){
C_save_and_reclaim((void *)f_7721,c,av);}
a=C_alloc(32);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7722,a[2]=((C_word)li35),tmp=(C_word)a,a+=3,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7738,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word)li36),tmp=(C_word)a,a+=5,tmp);
t8=C_i_check_list_2(t1,lf[68]);
t9=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7752,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],tmp=(C_word)a,a+=10,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7886,a[2]=t5,a[3]=t11,a[4]=t7,a[5]=t6,a[6]=((C_word)li41),tmp=(C_word)a,a+=7,tmp));
t13=((C_word*)t11)[1];
f_7886(t13,t9,t1);}

/* prefix-sym in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_fcall f_7722(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_7722,3,t1,t2,t3);}
a=C_alloc(7);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7730,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7734,a[2]=t4,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:869: scheme#symbol->string */
t6=*((C_word*)lf[122]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k7728 in prefix-sym in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_7730(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7730,c,av);}
/* chicken-syntax.scm:869: scheme#string->symbol */
t2=*((C_word*)lf[121]+1);{
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

/* k7732 in prefix-sym in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_7734(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7734,c,av);}
/* chicken-syntax.scm:869: scheme#string-append */
t2=*((C_word*)lf[41]+1);{
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

/* g2706 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_fcall f_7738(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_7738,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7746,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:874: prefix-sym */
f_7722(t3,lf[123],t2);}

/* k7744 in g2706 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_7746(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7746,c,av);}
/* chicken-syntax.scm:874: r */
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

/* k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_ccall f_7752(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7752,c,av);}
a=C_alloc(23);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7758,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,tmp=(C_word)a,a+=10,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7852,a[2]=t4,a[3]=t8,a[4]=t5,a[5]=((C_word)li40),tmp=(C_word)a,a+=6,tmp));
t10=((C_word*)t8)[1];
f_7852(t10,t6,((C_word*)t0)[9]);}

/* k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_7758(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_7758,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7761,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t1,tmp=(C_word)a,a+=11,tmp);
/* chicken-syntax.scm:878: r */
t3=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[127];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_7761(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_7761,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7764,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* chicken-syntax.scm:881: r */
t3=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[126];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_7764(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(31,c,3)))){
C_save_and_reclaim((void *)f_7764,c,av);}
a=C_alloc(31);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7768,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li37),tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7779,a[2]=t1,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[2],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7818,a[2]=t4,a[3]=t9,a[4]=t6,a[5]=t5,a[6]=((C_word)li39),tmp=(C_word)a,a+=7,tmp));
t11=((C_word*)t9)[1];
f_7818(t11,t7,((C_word*)t0)[5]);}

/* g2763 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_fcall f_7768(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_7768,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7776,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:883: prefix-sym */
f_7722(t3,lf[124],t2);}

/* k7774 in g2763 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_7776(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7776,c,av);}
/* chicken-syntax.scm:883: r */
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

/* k7777 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_ccall f_7779(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_7779,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7782,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=t1,tmp=(C_word)a,a+=12,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7545,a[2]=t2,a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[11],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:835: scheme#reverse */
t4=*((C_word*)lf[58]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[10];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k7780 in k7777 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_7782(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_7782,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7785,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:888: make-if-tree */
t3=((C_word*)t0)[9];
f_7616(t3,t2,((C_word*)t0)[10],((C_word*)t0)[11],((C_word*)t0)[6],((C_word*)t0)[2]);}

/* k7783 in k7780 in k7777 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in ... */
static void C_ccall f_7785(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_7785,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7792,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,tmp=(C_word)a,a+=10,tmp);
/* chicken-syntax.scm:891: r */
t3=((C_word*)t0)[9];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[125];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7790 in k7783 in k7780 in k7777 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in ... */
static void C_ccall f_7792(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(33,c,1)))){
C_save_and_reclaim((void *)f_7792,c,av);}
a=C_alloc(33);
t2=C_a_i_list(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_cons(&a,2,((C_word*)t0)[4],((C_word*)t0)[5]);
t4=C_a_i_cons(&a,2,lf[23],t3);
t5=C_a_i_list(&a,2,((C_word*)t0)[6],t4);
t6=C_a_i_cons(&a,2,t5,((C_word*)t0)[7]);
t7=C_a_i_cons(&a,2,t2,t6);
t8=((C_word*)t0)[8];{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_a_i_list(&a,3,t1,t7,((C_word*)t0)[9]);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* map-loop2757 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in ... */
static void C_fcall f_7818(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7818,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7843,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:883: g2763 */
t4=((C_word*)t0)[4];
f_7768(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7841 in map-loop2757 in k7762 in k7759 in k7756 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in ... */
static void C_ccall f_7843(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7843,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7818(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop2728 in k7750 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_fcall f_7852(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_7852,3,t0,t1,t2);}
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

/* map-loop2700 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_fcall f_7886(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7886,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7911,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:874: g2706 */
t4=((C_word*)t0)[4];
f_7738(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7909 in map-loop2700 in k7719 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_ccall f_7911(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7911,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7886(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop2670 in k7710 in k7707 in k7524 in a7521 in k5641 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in ... */
static void C_fcall f_7920(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_7920,3,t0,t1,t2);}
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

/* k7966 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_7968(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7968,c,av);}
/* chicken-syntax.scm:715: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[131];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a7969 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_7970(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7970,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7974,a[2]=t2,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:719: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[131];
av2[3]=t2;
av2[4]=lf[134];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k7972 in a7969 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_7974(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_7974,c,av);}
a=C_alloc(8);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_u_i_cdr(t3);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7984,a[2]=t4,a[3]=t6,a[4]=((C_word*)t0)[3],a[5]=((C_word)li44),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_7984(t8,((C_word*)t0)[4],t2,C_SCHEME_TRUE);}

/* fold in k7972 in a7969 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_fcall f_7984(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_7984,4,t0,t1,t2,t3);}
a=C_alloc(10);
if(C_truep(C_i_nullp(t2))){
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[2]);
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_a_i_cons(&a,2,lf[29],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_i_car(t2);
t5=C_u_i_cdr(t2);
t6=C_i_pairp(t4);
if(C_truep(C_i_not(t6))){
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8011,a[2]=t4,a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=t5,a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:728: ##sys#check-syntax */
t8=*((C_word*)lf[46]+1);{
C_word av2[5];
av2[0]=t8;
av2[1]=t7;
av2[2]=lf[131];
av2[3]=t4;
av2[4]=lf[132];
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}
else{
t7=C_i_cdr(t4);
if(C_truep(C_i_nullp(t7))){
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8046,a[2]=t4,a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=t5,tmp=(C_word)a,a+=6,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8071,a[2]=((C_word*)t0)[4],a[3]=t8,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:733: chicken.base#gensym */
t10=*((C_word*)lf[57]+1);{
C_word av2[2];
av2[0]=t10;
av2[1]=t9;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8074,a[2]=t4,a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:737: ##sys#check-syntax */
t9=*((C_word*)lf[46]+1);{
C_word av2[5];
av2[0]=t9;
av2[1]=t8;
av2[2]=lf[131];
av2[3]=t4;
av2[4]=lf[133];
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}}}}

/* k8009 in fold in k7972 in a7969 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_8011(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_8011,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8014,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8037,a[2]=((C_word*)t0)[6],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:729: chicken.base#gensym */
t4=*((C_word*)lf[57]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k8012 in k8009 in fold in k7972 in a7969 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in ... */
static void C_ccall f_8014(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_8014,c,av);}
a=C_alloc(14);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8029,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:731: fold */
t5=((C_word*)((C_word*)t0)[4])[1];
f_7984(t5,t4,((C_word*)t0)[5],t1);}

/* k8027 in k8012 in k8009 in fold in k7972 in a7969 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in ... */
static void C_ccall f_8029(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,c,1)))){
C_save_and_reclaim((void *)f_8029,c,av);}
a=C_alloc(21);
t2=C_a_i_list(&a,4,lf[37],((C_word*)t0)[2],t1,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k8035 in k8009 in fold in k7972 in a7969 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in ... */
static void C_ccall f_8037(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8037,c,av);}
/* chicken-syntax.scm:729: r */
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

/* k8044 in fold in k7972 in a7969 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_8046(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8046,c,av);}
a=C_alloc(14);
t2=C_u_i_car(((C_word*)t0)[2]);
t3=C_a_i_list(&a,2,t1,t2);
t4=C_a_i_list(&a,1,t3);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8061,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:735: fold */
t6=((C_word*)((C_word*)t0)[4])[1];
f_7984(t6,t5,((C_word*)t0)[5],t1);}

/* k8059 in k8044 in fold in k7972 in a7969 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in ... */
static void C_ccall f_8061(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,c,1)))){
C_save_and_reclaim((void *)f_8061,c,av);}
a=C_alloc(21);
t2=C_a_i_list(&a,4,lf[37],((C_word*)t0)[2],t1,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k8069 in fold in k7972 in a7969 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_8071(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8071,c,av);}
/* chicken-syntax.scm:733: r */
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

/* k8072 in fold in k7972 in a7969 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_8074(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8074,c,av);}
a=C_alloc(14);
t2=C_u_i_car(((C_word*)t0)[2]);
t3=C_i_cadr(((C_word*)t0)[2]);
t4=C_a_i_list(&a,2,t2,t3);
t5=C_a_i_list(&a,1,t4);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8090,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:740: fold */
t7=((C_word*)((C_word*)t0)[4])[1];
f_7984(t7,t6,((C_word*)t0)[5],t2);}

/* k8088 in k8072 in fold in k7972 in a7969 in k5638 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in ... */
static void C_ccall f_8090(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,c,1)))){
C_save_and_reclaim((void *)f_8090,c,av);}
a=C_alloc(21);
t2=C_a_i_list(&a,4,lf[37],((C_word*)t0)[2],t1,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k8108 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_ccall f_8110(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8110,c,av);}
/* chicken-syntax.scm:694: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[135];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a8111 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_ccall f_8112(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_8112,c,av);}
a=C_alloc(8);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8114,a[2]=t4,a[3]=t3,a[4]=((C_word)li46),tmp=(C_word)a,a+=5,tmp);
t7=t5=t6;
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8202,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:713: quotify-proc */
t9=t5;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=C_i_cdr(t2);
av2[3]=lf[135];
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}

/* quotify-proc2570 in a8111 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_8114(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_8114,c,av);}
a=C_alloc(6);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8118,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:700: ##sys#check-syntax */
t5=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
av2[3]=t2;
av2[4]=lf[138];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k8116 in quotify-proc2570 in a8111 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_8118(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_8118,c,av);}
a=C_alloc(12);
t2=C_i_car(((C_word*)t0)[2]);
t3=C_i_pairp(t2);
t4=(C_truep(t3)?C_u_i_car(t2):t2);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8127,a[2]=((C_word*)t0)[3],a[3]=t4,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_pairp(t2))){
t6=C_u_i_cdr(t2);
t7=C_u_i_cdr(((C_word*)t0)[2]);
t8=C_a_i_cons(&a,2,t6,t7);
t9=t5;
f_8127(t9,C_a_i_cons(&a,2,lf[23],t8));}
else{
t6=t5;
f_8127(t6,C_i_cadr(((C_word*)t0)[2]));}}

/* k8125 in k8116 in quotify-proc2570 in a8111 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_fcall f_8127(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(19,0,2)))){
C_save_and_reclaim_args((void *)trf_8127,2,t0,t1);}
a=C_alloc(19);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8130,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=C_i_pairp(t1);
t4=C_i_not(t3);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8139,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t4)){
t6=t5;
f_8139(t6,t4);}
else{
t6=C_i_car(t1);
t7=C_eqp(lf[23],t6);
if(C_truep(C_i_not(t7))){
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8155,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8159,a[2]=((C_word*)t0)[4],a[3]=t8,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:708: r */
t10=((C_word*)t0)[5];{
C_word av2[3];
av2[0]=t10;
av2[1]=t9;
av2[2]=lf[137];
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
t8=t5;
f_8139(t8,C_SCHEME_FALSE);}}}

/* k8128 in k8125 in k8116 in quotify-proc2570 in a8111 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_8130(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_8130,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list2(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8137 in k8125 in k8116 in quotify-proc2570 in a8111 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_fcall f_8139(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,5)))){
C_save_and_reclaim_args((void *)trf_8139,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
/* chicken-syntax.scm:709: chicken.syntax#syntax-error */
t2=*((C_word*)lf[59]+1);{
C_word av2[6];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[135];
av2[3]=lf[136];
av2[4]=((C_word*)t0)[3];
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}
else{
t2=((C_word*)t0)[5];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_a_i_list2(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k8153 in k8125 in k8116 in quotify-proc2570 in a8111 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_8155(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8155,c,av);}
t2=((C_word*)t0)[2];
f_8139(t2,C_i_not(t1));}

/* k8157 in k8125 in k8116 in quotify-proc2570 in a8111 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_8159(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8159,c,av);}
/* chicken-syntax.scm:708: c */
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
av2[3]=C_u_i_car(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k8200 in a8111 in k5635 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_8202(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_8202,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,lf[139],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8212 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_ccall f_8214(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8214,c,av);}
/* chicken-syntax.scm:683: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[142];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a8215 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_ccall f_8216(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8216,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8220,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:688: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[142];
av2[3]=t2;
av2[4]=lf[143];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k8218 in a8215 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_ccall f_8220(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_8220,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8223,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:689: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[45];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k8221 in k8218 in a8215 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_8223(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_8223,c,av);}
a=C_alloc(15);
t2=C_i_caddr(((C_word*)t0)[2]);
t3=C_a_i_list(&a,3,lf[23],C_SCHEME_END_OF_LIST,t2);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8242,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:692: r */
t5=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[140];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k8240 in k8221 in k8218 in a8215 in k5632 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_8242(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,1)))){
C_save_and_reclaim((void *)f_8242,c,av);}
a=C_alloc(27);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_a_i_list(&a,3,t1,((C_word*)t0)[3],t2);
t4=C_a_i_list(&a,3,lf[23],((C_word*)t0)[3],t3);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,3,lf[28],((C_word*)t0)[5],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k8256 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_ccall f_8258(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8258,c,av);}
/* chicken-syntax.scm:674: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[144];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a8259 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_ccall f_8260(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8260,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8264,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:679: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[144];
av2[3]=t2;
av2[4]=lf[147];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k8262 in a8259 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_ccall f_8264(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_8264,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8267,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:680: chicken.internal#check-for-multiple-bindings */
t3=*((C_word*)lf[145]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cadr(((C_word*)t0)[2]);
av2[3]=((C_word*)t0)[2];
av2[4]=lf[146];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k8265 in k8262 in a8259 in k5629 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_ccall f_8267(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_8267,c,av);}
a=C_alloc(3);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[51],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k8278 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_ccall f_8280(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8280,c,av);}
/* chicken-syntax.scm:655: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[148];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_ccall f_8282(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8282,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8286,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:659: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[148];
av2[3]=t2;
av2[4]=lf[152];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_ccall f_8286(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_8286,c,av);}
a=C_alloc(18);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_u_i_cdr(t3);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=C_i_check_list_2(t2,lf[68]);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8300,a[2]=((C_word*)t0)[3],a[3]=t4,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8502,a[2]=t7,a[3]=t12,a[4]=t8,a[5]=((C_word)li55),tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_8502(t14,t10,t2);}

/* k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_ccall f_8300(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8300,c,av);}
a=C_alloc(18);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8306,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8468,a[2]=t4,a[3]=t8,a[4]=t5,a[5]=((C_word)li54),tmp=(C_word)a,a+=6,tmp));
t10=((C_word*)t8)[1];
f_8468(t10,t6,((C_word*)t0)[4]);}

/* k8304 in k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_ccall f_8306(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(19,c,4)))){
C_save_and_reclaim((void *)f_8306,c,av);}
a=C_alloc(19);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[149]);
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8328,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[2],a[6]=t4,a[7]=t5,tmp=(C_word)a,a+=8,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8432,a[2]=t9,a[3]=((C_word)li53),tmp=(C_word)a,a+=4,tmp));
t11=((C_word*)t9)[1];
f_8432(t11,t7,((C_word*)t0)[2],C_SCHEME_END_OF_LIST);}

/* k8326 in k8304 in k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_8328(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8328,c,av);}
a=C_alloc(14);
t2=C_i_check_list_2(t1,lf[68]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8334,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8398,a[2]=((C_word*)t0)[6],a[3]=t5,a[4]=((C_word*)t0)[7],a[5]=((C_word)li51),tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_8398(t7,t3,t1);}

/* k8332 in k8326 in k8304 in k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_8334(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,4)))){
C_save_and_reclaim((void *)f_8334,c,av);}
a=C_alloc(22);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8338,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=*((C_word*)lf[150]+1);
t8=C_i_check_list_2(((C_word*)t0)[3],lf[68]);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8348,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8350,a[2]=t5,a[3]=t11,a[4]=t7,a[5]=t6,a[6]=((C_word)li50),tmp=(C_word)a,a+=7,tmp));
t13=((C_word*)t11)[1];
f_8350(t13,t9,((C_word*)t0)[5],((C_word*)t0)[3]);}

/* k8336 in k8332 in k8326 in k8304 in k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_8338(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_8338,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[38],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k8346 in k8332 in k8326 in k8304 in k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_8348(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8348,c,av);}
/* chicken-syntax.scm:664: ##sys#append */
t2=*((C_word*)lf[56]+1);{
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

/* map-loop2518 in k8332 in k8326 in k8304 in k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_fcall f_8350(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_8350,4,t0,t1,t2,t3);}
a=C_alloc(7);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8379,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* chicken-syntax.scm:671: g2524 */
t7=((C_word*)t0)[4];{
C_word av2[4];
av2[0]=t7;
av2[1]=t6;
av2[2]=C_slot(t2,C_fix(0));
av2[3]=C_slot(t3,C_fix(0));
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k8377 in map-loop2518 in k8332 in k8326 in k8304 in k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_8379(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_8379,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_8350(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)),C_slot(((C_word*)t0)[6],C_fix(1)));}

/* map-loop2470 in k8326 in k8304 in k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_fcall f_8398(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_8398,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_a_i_list(&a,2,t3,lf[151]);
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

/* foldl2493 in k8304 in k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_fcall f_8432(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,5)))){
C_save_and_reclaim_args((void *)trf_8432,4,t0,t1,t2,t3);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t4=C_slot(t2,C_fix(1));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8462,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=C_slot(t2,C_fix(0));
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8456,a[2]=t5,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8458,a[2]=((C_word)li52),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:667: ##sys#decompose-lambda-list */
t9=*((C_word*)lf[106]+1);{
C_word av2[4];
av2[0]=t9;
av2[1]=t7;
av2[2]=t6;
av2[3]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k8454 in foldl2493 in k8304 in k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_8456(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8456,c,av);}
/* chicken-syntax.scm:667: ##sys#append */
t2=*((C_word*)lf[56]+1);{
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

/* a8457 in foldl2493 in k8304 in k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_8458(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8458,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k8460 in foldl2493 in k8304 in k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_8462(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8462,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_8432(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* map-loop2441 in k8298 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_fcall f_8468(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_8468,3,t0,t1,t2);}
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

/* map-loop2415 in k8284 in a8281 in k5626 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_fcall f_8502(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_8502,3,t0,t1,t2);}
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

/* k8536 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_8538(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8538,c,av);}
/* chicken-syntax.scm:640: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[153];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a8539 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_8540(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8540,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8544,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:644: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[153];
av2[3]=t2;
av2[4]=lf[155];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k8542 in a8539 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_ccall f_8544(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8544,c,av);}
a=C_alloc(5);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_u_i_cdr(t3);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8552,a[2]=t4,a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:647: r */
t6=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[154];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k8550 in k8542 in a8539 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_ccall f_8552(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_8552,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8557,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t3,a[5]=((C_word)li57),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_8557(t5,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* fold in k8550 in k8542 in a8539 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_fcall f_8557(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_8557,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_nullp(t2))){
t3=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,((C_word*)t0)[2]);
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_a_i_cons(&a,2,lf[38],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=C_a_i_list(&a,1,t3);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8582,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:652: fold */
t7=t5;
t8=C_u_i_cdr(t2);
t1=t7;
t2=t8;
goto loop;}}

/* k8580 in fold in k8550 in k8542 in a8539 in k5623 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_ccall f_8582(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_8582,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8590 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_8592(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8592,c,av);}
/* chicken-syntax.scm:586: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[154];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_8594(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8594,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8598,a[2]=t2,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:590: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[154];
av2[3]=t2;
av2[4]=lf[156];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_8598(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,c,4)))){
C_save_and_reclaim((void *)f_8598,c,av);}
a=C_alloc(33);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_u_i_cdr(t3);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8604,a[2]=t6,a[3]=((C_word)li59),tmp=(C_word)a,a+=4,tmp);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8632,a[2]=t8,a[3]=((C_word)li60),tmp=(C_word)a,a+=4,tmp);
t11=C_set_block_item(t6,0,t9);
t12=C_set_block_item(t8,0,t10);
t13=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t14=t13;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=((C_word*)t15)[1];
t17=C_i_check_list_2(t2,lf[68]);
t18=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8680,a[2]=((C_word*)t0)[3],a[3]=t4,a[4]=((C_word*)t0)[4],a[5]=t2,a[6]=t8,a[7]=t6,tmp=(C_word)a,a+=8,tmp);
t19=C_SCHEME_UNDEFINED;
t20=(*a=C_VECTOR_TYPE|1,a[1]=t19,tmp=(C_word)a,a+=2,tmp);
t21=C_set_block_item(t20,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9033,a[2]=t15,a[3]=t20,a[4]=t16,a[5]=((C_word)li70),tmp=(C_word)a,a+=6,tmp));
t22=((C_word*)t20)[1];
f_9033(t22,t18,t2);}

/* append*2221 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_ccall f_8604(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_8604,c,av);}
a=C_alloc(4);
t4=C_i_pairp(t2);
if(C_truep(C_i_not(t4))){
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_cons(&a,2,t2,t3);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_i_car(t2);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8625,a[2]=t1,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:597: append* */
t7=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=C_u_i_cdr(t2);
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}

/* k8623 in append*2221 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_ccall f_8625(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_8625,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map*2222 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_ccall f_8632(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_8632,c,av);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t3))){
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_pairp(t3);
if(C_truep(C_i_not(t4))){
/* chicken-syntax.scm:600: proc */
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8655,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:601: proc */
t6=t2;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=C_i_car(t3);
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}}}

/* k8653 in map*2222 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_ccall f_8655(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_8655,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8659,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:601: map* */
t3=((C_word*)((C_word*)t0)[3])[1];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_u_i_cdr(((C_word*)t0)[5]);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k8657 in k8653 in map*2222 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_ccall f_8659(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_8659,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_ccall f_8680(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8680,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8683,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8995,a[2]=t4,a[3]=((C_word*)t0)[7],a[4]=((C_word)li69),tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_8995(t6,t2,t1,C_SCHEME_END_OF_LIST);}

/* k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_ccall f_8683(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(26,c,3)))){
C_save_and_reclaim((void *)f_8683,c,av);}
a=C_alloc(26);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8687,a[2]=((C_word*)t0)[2],a[3]=((C_word)li61),tmp=(C_word)a,a+=4,tmp);
t7=C_i_check_list_2(t1,lf[68]);
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8705,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8961,a[2]=t4,a[3]=t10,a[4]=t6,a[5]=t5,a[6]=((C_word)li68),tmp=(C_word)a,a+=7,tmp));
t12=((C_word*)t10)[1];
f_8961(t12,t8,t1);}

/* g2282 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_fcall f_8687(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_8687,3,t0,t1,t2);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8695,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8699,a[2]=((C_word*)t0)[2],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:612: chicken.base#gensym */
t5=*((C_word*)lf[57]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k8693 in g2282 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_ccall f_8695(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_8695,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8697 in g2282 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_ccall f_8699(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8699,c,av);}
/* chicken-syntax.scm:612: r */
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

/* k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_ccall f_8705(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8705,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8706,a[2]=t1,a[3]=((C_word)li62),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8717,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8917,a[2]=t5,a[3]=t2,a[4]=((C_word*)t0)[7],a[5]=((C_word)li67),tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_8917(t7,t3,((C_word*)t0)[5],C_SCHEME_END_OF_LIST);}

/* lookup in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_ccall f_8706(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8706,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_cdr(C_i_assq(t2,((C_word*)t0)[2]));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k8715 in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_ccall f_8717(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,3)))){
C_save_and_reclaim((void *)f_8717,c,av);}
a=C_alloc(21);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8732,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,tmp=(C_word)a,a+=8,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8883,a[2]=t4,a[3]=t8,a[4]=t5,a[5]=((C_word)li66),tmp=(C_word)a,a+=6,tmp));
t10=((C_word*)t8)[1];
f_8883(t10,t6,((C_word*)t0)[7]);}

/* k8730 in k8715 in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_8732(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_8732,c,av);}
a=C_alloc(9);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8734,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t3,a[6]=((C_word)li65),tmp=(C_word)a,a+=7,tmp));
t5=((C_word*)t3)[1];
f_8734(t5,((C_word*)t0)[5],((C_word*)t0)[6],t1,((C_word*)t0)[7]);}

/* fold in k8730 in k8715 in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_fcall f_8734(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,0,4)))){
C_save_and_reclaim_args((void *)trf_8734,5,t0,t1,t2,t3,t4);}
a=C_alloc(22);
if(C_truep(C_i_nullp(t2))){
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8753,a[2]=((C_word*)t0)[2],a[3]=((C_word)li63),tmp=(C_word)a,a+=4,tmp);
t10=C_i_check_list_2(((C_word*)t0)[3],lf[68]);
t11=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8767,a[2]=((C_word*)t0)[4],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8769,a[2]=t7,a[3]=t13,a[4]=t9,a[5]=t8,a[6]=((C_word)li64),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_8769(t15,t11,((C_word*)t0)[3]);}
else{
t5=C_i_car(t4);
t6=C_i_pairp(t5);
t7=(C_truep(t6)?C_i_nullp(C_i_cdar(t4)):C_SCHEME_FALSE);
if(C_truep(t7)){
t8=C_i_caar(t4);
t9=C_i_car(t3);
t10=C_a_i_list(&a,2,t8,t9);
t11=C_a_i_list(&a,1,t10);
t12=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8818,a[2]=t1,a[3]=t11,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:632: fold */
t16=t12;
t17=C_i_cdr(t2);
t18=C_u_i_cdr(t3);
t19=C_u_i_cdr(t4);
t1=t16;
t2=t17;
t3=t18;
t4=t19;
goto loop;}
else{
t8=C_i_car(t3);
t9=C_a_i_list(&a,3,lf[23],C_SCHEME_END_OF_LIST,t8);
t10=C_u_i_car(t4);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8855,a[2]=t10,a[3]=t1,a[4]=t9,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:638: fold */
t16=t11;
t17=C_i_cdr(t2);
t18=C_u_i_cdr(t3);
t19=C_u_i_cdr(t4);
t1=t16;
t2=t17;
t3=t18;
t4=t19;
goto loop;}}}

/* g2333 in fold in k8730 in k8715 in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_fcall f_8753(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_8753,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8761,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:627: lookup */
t4=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
f_8706(3,av2);}}

/* k8759 in g2333 in fold in k8730 in k8715 in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_8761(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_8761,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8765 in fold in k8730 in k8715 in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_8767(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_8767,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[38],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* map-loop2327 in fold in k8730 in k8715 in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_fcall f_8769(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_8769,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8794,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:627: g2333 */
t4=((C_word*)t0)[4];
f_8753(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8792 in map-loop2327 in fold in k8730 in k8715 in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_8794(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8794,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_8769(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k8816 in fold in k8730 in k8715 in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_8818(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_8818,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8853 in fold in k8730 in k8715 in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_8855(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,1)))){
C_save_and_reclaim((void *)f_8855,c,av);}
a=C_alloc(18);
t2=C_a_i_list(&a,3,lf[23],((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,3,lf[28],((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* map-loop2362 in k8715 in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_fcall f_8883(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_8883,3,t0,t1,t2);}
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

/* loop in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_fcall f_8917(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_8917,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
/* chicken-syntax.scm:616: scheme#reverse */
t4=*((C_word*)lf[58]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t4=C_i_car(t2);
t5=C_i_pairp(t4);
if(C_truep(C_i_not(t5))){
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8948,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:619: lookup */
t7=((C_word*)t0)[3];{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=t4;
f_8706(3,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8955,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:620: map* */
t7=((C_word*)((C_word*)t0)[4])[1];{
C_word av2[4];
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[3];
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}}

/* k8946 in loop in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_8948(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_8948,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
/* chicken-syntax.scm:621: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_8917(t3,((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[5]),t2);}

/* k8953 in loop in k8703 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_8955(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_8955,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
/* chicken-syntax.scm:621: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_8917(t3,((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[5]),t2);}

/* map-loop2276 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_fcall f_8961(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_8961,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8986,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:612: g2282 */
t4=((C_word*)t0)[4];
f_8687(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8984 in map-loop2276 in k8681 in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_ccall f_8986(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8986,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_8961(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* loop in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_fcall f_8995(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_8995,4,t0,t1,t2,t3);}
a=C_alloc(8);
if(C_truep(C_i_nullp(t2))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_car(t2);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9008,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_listp(t4))){
/* chicken-syntax.scm:608: scheme#append */
t6=*((C_word*)lf[108]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
if(C_truep(C_i_pairp(t4))){
/* chicken-syntax.scm:609: append* */
t6=((C_word*)((C_word*)t0)[3])[1];{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t6=C_a_i_cons(&a,2,t4,t3);
/* chicken-syntax.scm:611: loop */
t8=t1;
t9=C_u_i_cdr(t2);
t10=t6;
t1=t8;
t2=t9;
t3=t10;
goto loop;}}}}

/* k9006 in loop in k8678 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_ccall f_9008(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9008,c,av);}
/* chicken-syntax.scm:611: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_8995(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]),t1);}

/* map-loop2238 in k8596 in a8593 in k5620 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_fcall f_9033(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_9033,3,t0,t1,t2);}
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

/* k9067 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in ... */
static void C_ccall f_9069(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9069,c,av);}
/* chicken-syntax.scm:569: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[157];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a9070 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in ... */
static void C_ccall f_9071(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9071,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9075,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:573: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[157];
av2[3]=t2;
av2[4]=lf[162];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k9073 in a9070 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_9075(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9075,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9082,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9086,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=C_i_cadr(((C_word*)t0)[3]);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9108,a[2]=((C_word)li74),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:575: ##sys#decompose-lambda-list */
t6=*((C_word*)lf[106]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=t4;
av2[3]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k9080 in k9073 in a9070 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_9082(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_9082,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,lf[29],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k9084 in k9073 in a9070 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_9086(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_9086,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9094,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:584: ##sys#expand-multiple-values-assignment */
t3=*((C_word*)lf[150]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cadr(((C_word*)t0)[3]);
av2[3]=C_i_caddr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k9092 in k9084 in k9073 in a9070 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_ccall f_9094(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_9094,c,av);}
a=C_alloc(3);
t2=C_a_i_list(&a,1,t1);
/* chicken-syntax.scm:574: ##sys#append */
t3=*((C_word*)lf[56]+1);{
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

/* a9107 in k9073 in a9070 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_9108(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_9108,c,av);}
a=C_alloc(10);
t5=C_i_check_list_2(t2,lf[70]);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9127,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9174,a[2]=t8,a[3]=((C_word)li73),tmp=(C_word)a,a+=4,tmp));
t10=((C_word*)t8)[1];
f_9174(t10,t6,t2);}

/* k9112 in for-each-loop2167 in a9107 in k9073 in a9070 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_ccall f_9114(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_9114,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9121,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:580: ##sys#current-module */
t3=*((C_word*)lf[86]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k9119 in k9112 in for-each-loop2167 in a9107 in k9073 in a9070 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_ccall f_9121(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9121,c,av);}
/* chicken-syntax.scm:580: ##sys#register-export */
t2=*((C_word*)lf[159]+1);{
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

/* k9125 in a9107 in k9073 in a9070 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_ccall f_9127(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9127,c,av);}
a=C_alloc(13);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9140,a[2]=t4,a[3]=t7,a[4]=t5,a[5]=((C_word)li72),tmp=(C_word)a,a+=6,tmp));
t9=((C_word*)t7)[1];
f_9140(t9,((C_word*)t0)[2],((C_word*)t0)[3]);}

/* map-loop2177 in k9125 in a9107 in k9073 in a9070 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_fcall f_9140(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_9140,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_a_i_list(&a,2,lf[158],t3);
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

/* for-each-loop2167 in a9107 in k9073 in a9070 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_fcall f_9174(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_9174,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9184,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9114,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:579: ##sys#get */
t6=*((C_word*)lf[160]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
av2[3]=lf[161];
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k9182 in for-each-loop2167 in a9107 in k9073 in a9070 in k5616 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_ccall f_9184(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9184,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_9174(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k9197 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in ... */
static void C_ccall f_9199(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9199,c,av);}
/* chicken-syntax.scm:561: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[163];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a9200 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in ... */
static void C_ccall f_9201(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9201,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9205,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:565: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[163];
av2[3]=t2;
av2[4]=lf[164];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k9203 in a9200 in k5613 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in ... */
static void C_ccall f_9205(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9205,c,av);}
/* chicken-syntax.scm:566: ##sys#expand-multiple-values-assignment */
t2=*((C_word*)lf[150]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_i_cadr(((C_word*)t0)[3]);
av2[3]=C_i_caddr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k9218 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_ccall f_9220(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9220,c,av);}
/* chicken-syntax.scm:552: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[165];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a9221 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_ccall f_9222(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9222,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9226,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:556: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[165];
av2[3]=t2;
av2[4]=lf[167];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k9224 in a9221 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in ... */
static void C_ccall f_9226(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,1)))){
C_save_and_reclaim((void *)f_9226,c,av);}
a=C_alloc(18);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,lf[166]);
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=C_u_i_cdr(t4);
t6=C_a_i_cons(&a,2,lf[29],t5);
t7=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_a_i_list(&a,4,lf[37],t2,t3,t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* k9246 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_ccall f_9248(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9248,c,av);}
/* chicken-syntax.scm:544: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[168];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a9249 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_ccall f_9250(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9250,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9254,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:548: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[168];
av2[3]=t2;
av2[4]=lf[169];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k9252 in a9249 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_ccall f_9254(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_9254,c,av);}
a=C_alloc(12);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_u_i_cdr(t3);
t5=C_a_i_cons(&a,2,lf[29],t4);
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,3,lf[37],t2,t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k9270 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in ... */
static void C_ccall f_9272(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9272,c,av);}
/* chicken-syntax.scm:531: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[170];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a9273 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in ... */
static void C_ccall f_9274(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9274,c,av);}
a=C_alloc(22);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9283,a[2]=t3,a[3]=t4,a[4]=((C_word)li81),tmp=(C_word)a,a+=5,tmp);
t10=C_i_cdr(t2);
t11=C_i_check_list_2(t10,lf[68]);
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9314,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_set_block_item(t14,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9316,a[2]=t7,a[3]=t14,a[4]=t9,a[5]=t8,a[6]=((C_word)li82),tmp=(C_word)a,a+=7,tmp));
t16=((C_word*)t14)[1];
f_9316(t16,t12,t10);}

/* g2092 in a9273 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_fcall f_9283(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,8)))){
C_save_and_reclaim_args((void *)trf_9283,3,t0,t1,t2);}
a=C_alloc(9);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9289,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word)li79),tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9295,a[2]=((C_word)li80),tmp=(C_word)a,a+=3,tmp);
/* chicken-syntax.scm:538: ##sys#call-with-values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}

/* a9288 in g2092 in a9273 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_ccall f_9289(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_9289,c,av);}
/* chicken-syntax.scm:538: ##sys#decompose-import */
t2=*((C_word*)lf[171]+1);{
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
av2[5]=lf[49];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* a9294 in g2092 in a9273 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_ccall f_9295(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_9295,c,av);}
a=C_alloc(9);
t8=C_i_not(t3);
t9=t1;{
C_word *av2=av;
av2[0]=t9;
av2[1]=(C_truep(t8)?lf[172]:C_a_i_list(&a,3,lf[173],t3,t2));
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}

/* k9312 in a9273 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_ccall f_9314(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_9314,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,lf[29],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop2086 in a9273 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_fcall f_9316(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_9316,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9341,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:537: g2092 */
t4=((C_word*)t0)[4];
f_9283(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k9339 in map-loop2086 in a9273 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_ccall f_9341(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9341,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_9316(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k9350 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in ... */
static void C_ccall f_9352(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9352,c,av);}
/* chicken-syntax.scm:477: ##sys#extend-macro-environment */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[174];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in k5539 in ... */
static void C_ccall f_9354(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9354,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9373,a[2]=t2,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-syntax.scm:485: ##sys#check-syntax */
t6=*((C_word*)lf[46]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[174];
av2[3]=t2;
av2[4]=lf[182];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in k5542 in ... */
static void C_ccall f_9373(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9373,c,av);}
a=C_alloc(6);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_u_i_cdr(t3);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9381,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=t4,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* chicken-syntax.scm:488: r */
t6=((C_word*)t0)[3];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[181];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in k5545 in ... */
static void C_ccall f_9381(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9381,c,av);}
a=C_alloc(20);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[68]);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9390,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10246,a[2]=t4,a[3]=t9,a[4]=t5,a[5]=((C_word)li101),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_10246(t11,t7,((C_word*)t0)[2]);}

/* k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in k5548 in ... */
static void C_ccall f_9390(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9390,c,av);}
a=C_alloc(20);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9396,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10212,a[2]=t4,a[3]=t8,a[4]=t5,a[5]=((C_word)li100),tmp=(C_word)a,a+=6,tmp));
t10=((C_word*)t8)[1];
f_10212(t10,t6,((C_word*)t0)[6]);}

/* k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in k5551 in ... */
static void C_ccall f_9396(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(26,c,3)))){
C_save_and_reclaim((void *)f_9396,c,av);}
a=C_alloc(26);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9400,a[2]=((C_word*)t0)[2],a[3]=((C_word)li84),tmp=(C_word)a,a+=4,tmp);
t7=C_i_check_list_2(((C_word*)t0)[3],lf[68]);
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9414,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[3],tmp=(C_word)a,a+=8,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10178,a[2]=t4,a[3]=t10,a[4]=t6,a[5]=t5,a[6]=((C_word)li99),tmp=(C_word)a,a+=7,tmp));
t12=((C_word*)t10)[1];
f_10178(t12,t8,((C_word*)t0)[3]);}

/* g1677 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in ... */
static void C_fcall f_9400(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_9400,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9408,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_symbolp(t2))){
/* chicken-syntax.scm:483: chicken.base#gensym */
t4=*((C_word*)lf[57]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
/* chicken-syntax.scm:484: chicken.base#gensym */
t4=*((C_word*)lf[57]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[175];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k9406 in g1677 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_9408(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9408,c,av);}
/* chicken-syntax.scm:491: r */
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

/* k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in k5555 in ... */
static void C_ccall f_9414(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(27,c,3)))){
C_save_and_reclaim((void *)f_9414,c,av);}
a=C_alloc(27);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9418,a[2]=((C_word*)t0)[2],a[3]=((C_word)li85),tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9429,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10144,a[2]=t4,a[3]=t9,a[4]=t6,a[5]=t5,a[6]=((C_word)li98),tmp=(C_word)a,a+=7,tmp));
t11=((C_word*)t9)[1];
f_10144(t11,t7,((C_word*)t0)[7]);}

/* g1705 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_fcall f_9418(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_9418,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9426,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:492: chicken.base#gensym */
t3=*((C_word*)lf[57]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[176];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k9424 in g1705 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_9426(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9426,c,av);}
/* chicken-syntax.scm:492: r */
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

/* k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in k5558 in ... */
static void C_ccall f_9429(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(27,c,3)))){
C_save_and_reclaim((void *)f_9429,c,av);}
a=C_alloc(27);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9433,a[2]=((C_word*)t0)[2],a[3]=((C_word)li86),tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9444,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10110,a[2]=t4,a[3]=t9,a[4]=t6,a[5]=t5,a[6]=((C_word)li97),tmp=(C_word)a,a+=7,tmp));
t11=((C_word*)t9)[1];
f_10110(t11,t7,((C_word*)t0)[8]);}

/* g1733 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_fcall f_9433(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_9433,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9441,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-syntax.scm:493: chicken.base#gensym */
t3=*((C_word*)lf[57]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[45];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k9439 in g1733 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_ccall f_9441(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9441,c,av);}
/* chicken-syntax.scm:493: r */
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

/* k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in k5561 in ... */
static void C_ccall f_9444(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,4)))){
C_save_and_reclaim((void *)f_9444,c,av);}
a=C_alloc(22);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[68]);
t7=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9457,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=t1,a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[2],tmp=(C_word)a,a+=9,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10062,a[2]=t4,a[3]=t9,a[4]=t5,a[5]=((C_word)li96),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_10062(t11,t7,((C_word*)t0)[2],((C_word*)t0)[8]);}

/* k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in k5564 in ... */
static void C_ccall f_9457(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,4)))){
C_save_and_reclaim((void *)f_9457,c,av);}
a=C_alloc(22);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[68]);
t7=C_i_check_list_2(((C_word*)t0)[3],lf[68]);
t8=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9474,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=t1,a[7]=((C_word*)t0)[2],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10014,a[2]=t4,a[3]=t10,a[4]=t5,a[5]=((C_word)li95),tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_10014(t12,t8,((C_word*)t0)[2],((C_word*)t0)[3]);}

/* k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in k5567 in ... */
static void C_ccall f_9474(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,c,4)))){
C_save_and_reclaim((void *)f_9474,c,av);}
a=C_alloc(23);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_9485,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9966,a[2]=t4,a[3]=t8,a[4]=t5,a[5]=((C_word)li94),tmp=(C_word)a,a+=6,tmp));
t10=((C_word*)t8)[1];
f_9966(t10,t6,((C_word*)t0)[7],((C_word*)t0)[7]);}

/* k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_ccall f_9485(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(51,c,5)))){
C_save_and_reclaim((void *)f_9485,c,av);}
a=C_alloc(51);
t2=C_a_i_list(&a,4,lf[177],lf[178],C_SCHEME_TRUE,C_SCHEME_TRUE);
t3=C_a_i_list(&a,2,((C_word*)t0)[2],t2);
t4=C_a_i_list(&a,1,t3);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9736,a[2]=((C_word*)t0)[2],a[3]=((C_word)li87),tmp=(C_word)a,a+=4,tmp);
t10=C_i_check_list_2(((C_word*)t0)[3],lf[68]);
t11=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_9754,a[2]=((C_word*)t0)[4],a[3]=t4,a[4]=t1,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[3],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[2],tmp=(C_word)a,a+=12,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9896,a[2]=t9,a[3]=t7,a[4]=t13,a[5]=t8,a[6]=((C_word)li93),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_9896(t15,t11,((C_word*)t0)[9],((C_word*)t0)[8],((C_word*)t0)[3]);}

/* k9531 in k9756 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_9533(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(28,c,4)))){
C_save_and_reclaim((void *)f_9533,c,av);}
a=C_alloc(28);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_9537,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9549,a[2]=t2,a[3]=((C_word*)t0)[9],a[4]=((C_word*)t0)[10],tmp=(C_word)a,a+=5,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9611,a[2]=t5,a[3]=t9,a[4]=t6,a[5]=((C_word)li89),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_9611(t11,t7,((C_word*)t0)[11],((C_word*)t0)[9]);}

/* k9535 in k9531 in k9756 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_9537(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(63,c,1)))){
C_save_and_reclaim((void *)f_9537,c,av);}
a=C_alloc(63);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,lf[38],t2);
t4=C_a_i_list(&a,3,lf[23],C_SCHEME_END_OF_LIST,t3);
t5=C_a_i_list(&a,4,lf[179],((C_word*)t0)[3],((C_word*)t0)[4],t4);
t6=C_a_i_list(&a,3,lf[38],((C_word*)t0)[5],t5);
t7=C_a_i_list(&a,3,lf[38],((C_word*)t0)[6],t6);
t8=C_a_i_list(&a,3,lf[38],((C_word*)t0)[7],t7);
t9=((C_word*)t0)[8];{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_a_i_list(&a,3,lf[38],((C_word*)t0)[9],t8);
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}

/* k9547 in k9531 in k9756 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_9549(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9549,c,av);}
a=C_alloc(17);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9561,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9563,a[2]=t4,a[3]=t8,a[4]=t5,a[5]=((C_word)li88),tmp=(C_word)a,a+=6,tmp));
t10=((C_word*)t8)[1];
f_9563(t10,t6,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* k9559 in k9547 in k9531 in k9756 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_9561(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9561,c,av);}
/* chicken-syntax.scm:494: ##sys#append */
t2=*((C_word*)lf[56]+1);{
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

/* map-loop2042 in k9547 in k9531 in k9756 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_fcall f_9563(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_9563,4,t0,t1,t2,t3);}
a=C_alloc(12);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,3,lf[180],t6,t7);
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

/* map-loop2006 in k9531 in k9756 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_fcall f_9611(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,0,3)))){
C_save_and_reclaim_args((void *)trf_9611,4,t0,t1,t2,t3);}
a=C_alloc(15);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,4,t6,t7,C_SCHEME_FALSE,C_SCHEME_TRUE);
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

/* map-loop1964 in k9756 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_fcall f_9659(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_9659,5,t0,t1,t2,t3,t4);}
a=C_alloc(9);
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9666,a[2]=t2,a[3]=t4,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=t1,a[7]=t3,a[8]=((C_word*)t0)[4],tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_i_pairp(t2))){
t6=C_i_pairp(t3);
t7=t5;
f_9666(t7,(C_truep(t6)?C_i_pairp(t4):C_SCHEME_FALSE));}
else{
t6=t5;
f_9666(t6,C_SCHEME_FALSE);}}

/* k9664 in map-loop1964 in k9756 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_fcall f_9666(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,0,4)))){
C_save_and_reclaim_args((void *)trf_9666,2,t0,t1);}
a=C_alloc(12);
if(C_truep(t1)){
t2=C_slot(((C_word*)t0)[2],C_fix(0));
t3=C_slot(((C_word*)t0)[3],C_fix(0));
t4=C_a_i_list(&a,1,t2);
t5=C_a_i_list(&a,2,t3,t4);
t6=C_a_i_cons(&a,2,t5,C_SCHEME_END_OF_LIST);
t7=C_i_setslot(((C_word*)((C_word*)t0)[4])[1],C_fix(1),t6);
t8=C_mutate(((C_word *)((C_word*)t0)[4])+1,t6);
t9=((C_word*)((C_word*)t0)[5])[1];
f_9659(t9,((C_word*)t0)[6],C_slot(((C_word*)t0)[2],C_fix(1)),C_slot(((C_word*)t0)[7],C_fix(1)),C_slot(((C_word*)t0)[3],C_fix(1)));}
else{
t2=((C_word*)t0)[6];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_slot(((C_word*)t0)[8],C_fix(1));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* g1856 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static C_word C_fcall f_9736(C_word *a,C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_stack_overflow_check;{}
t4=C_a_i_list(&a,4,t1,t2,C_SCHEME_TRUE,C_SCHEME_FALSE);
t5=C_a_i_list(&a,4,lf[37],((C_word*)t0)[2],t4,t2);
return(C_a_i_list(&a,2,t3,t5));}

/* k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_ccall f_9754(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(31,c,4)))){
C_save_and_reclaim((void *)f_9754,c,av);}
a=C_alloc(31);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_9758,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9774,a[2]=t2,a[3]=((C_word*)t0)[11],a[4]=((C_word*)t0)[10],a[5]=((C_word*)t0)[9],tmp=(C_word)a,a+=6,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9848,a[2]=t5,a[3]=t9,a[4]=t6,a[5]=((C_word)li92),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_9848(t11,t7,((C_word*)t0)[10],((C_word*)t0)[8]);}

/* k9756 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_9758(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(46,c,5)))){
C_save_and_reclaim((void *)f_9758,c,av);}
a=C_alloc(46);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,lf[38],t2);
t4=C_a_i_list(&a,3,lf[23],C_SCHEME_END_OF_LIST,t3);
t5=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,((C_word*)t0)[3]);
t6=C_a_i_cons(&a,2,lf[23],t5);
t7=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t8=t7;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=((C_word*)t9)[1];
t11=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_9533,a[2]=t4,a[3]=t6,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9659,a[2]=t9,a[3]=t13,a[4]=t10,a[5]=((C_word)li90),tmp=(C_word)a,a+=6,tmp));
t15=((C_word*)t13)[1];
f_9659(t15,t11,((C_word*)t0)[11],((C_word*)t0)[9],((C_word*)t0)[10]);}

/* k9772 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_9774(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,4)))){
C_save_and_reclaim((void *)f_9774,c,av);}
a=C_alloc(21);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9778,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9790,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9800,a[2]=t5,a[3]=t9,a[4]=t6,a[5]=((C_word)li91),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_9800(t11,t7,((C_word*)t0)[4],((C_word*)t0)[5]);}

/* k9776 in k9772 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_9778(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9778,c,av);}
/* chicken-syntax.scm:494: ##sys#append */
t2=*((C_word*)lf[56]+1);{
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

/* k9788 in k9772 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_9790(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_9790,c,av);}
a=C_alloc(12);
t2=C_a_i_list(&a,3,lf[180],((C_word*)t0)[2],C_SCHEME_FALSE);
t3=C_a_i_list(&a,1,t2);
/* chicken-syntax.scm:494: ##sys#append */
t4=*((C_word*)lf[56]+1);{
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

/* map-loop1928 in k9772 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_fcall f_9800(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,0,3)))){
C_save_and_reclaim_args((void *)trf_9800,4,t0,t1,t2,t3);}
a=C_alloc(15);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,4,t6,t7,C_SCHEME_FALSE,C_SCHEME_TRUE);
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

/* map-loop1892 in k9752 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_fcall f_9848(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,0,3)))){
C_save_and_reclaim_args((void *)trf_9848,4,t0,t1,t2,t3);}
a=C_alloc(15);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,1,t6);
t9=C_a_i_list(&a,3,lf[180],t7,t8);
t10=C_a_i_cons(&a,2,t9,C_SCHEME_END_OF_LIST);
t11=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t10);
t12=C_mutate(((C_word *)((C_word*)t0)[2])+1,t10);
t14=t1;
t15=C_slot(t2,C_fix(1));
t16=C_slot(t3,C_fix(1));
t1=t14;
t2=t15;
t3=t16;
goto loop;}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* map-loop1850 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in ... */
static void C_fcall f_9896(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_9896,5,t0,t1,t2,t3,t4);}
a=C_alloc(10);
t5=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_9903,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t3,a[5]=t4,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],a[8]=t1,a[9]=((C_word*)t0)[5],tmp=(C_word)a,a+=10,tmp);
if(C_truep(C_i_pairp(t2))){
t6=C_i_pairp(t3);
t7=t5;
f_9903(t7,(C_truep(t6)?C_i_pairp(t4):C_SCHEME_FALSE));}
else{
t6=t5;
f_9903(t6,C_SCHEME_FALSE);}}

/* k9901 in map-loop1850 in k9483 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_fcall f_9903(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,0,4)))){
C_save_and_reclaim_args((void *)trf_9903,2,t0,t1);}
a=C_alloc(33);
if(C_truep(t1)){
t2=(
/* chicken-syntax.scm:509: g1856 */
  f_9736(C_a_i(&a,30),((C_word*)t0)[2],C_slot(((C_word*)t0)[3],C_fix(0)),C_slot(((C_word*)t0)[4],C_fix(0)),C_slot(((C_word*)t0)[5],C_fix(0)))
);
t3=C_a_i_cons(&a,2,t2,C_SCHEME_END_OF_LIST);
t4=C_i_setslot(((C_word*)((C_word*)t0)[6])[1],C_fix(1),t3);
t5=C_mutate(((C_word *)((C_word*)t0)[6])+1,t3);
t6=((C_word*)((C_word*)t0)[7])[1];
f_9896(t6,((C_word*)t0)[8],C_slot(((C_word*)t0)[3],C_fix(1)),C_slot(((C_word*)t0)[4],C_fix(1)),C_slot(((C_word*)t0)[5],C_fix(1)));}
else{
t2=((C_word*)t0)[8];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_slot(((C_word*)t0)[9],C_fix(1));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* map-loop1819 in k9472 in k9455 in k9442 in k9427 in k9412 in k9394 in k9388 in k9379 in k9371 in a9353 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5573 in k5570 in ... */
static void C_fcall f_9966(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_9966,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,2,t6,t7);
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

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_chicken_2dsyntax_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("chicken-syntax"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_chicken_2dsyntax_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(2800))){
C_save(t1);
C_rereclaim2(2800*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,285);
lf[0]=C_h_intern(&lf[0],14, C_text("chicken-syntax"));
lf[2]=C_h_intern(&lf[2],41, C_text("##sys#chicken.condition-macro-environment"));
lf[3]=C_h_intern(&lf[3],36, C_text("##sys#chicken.type-macro-environment"));
lf[4]=C_h_intern(&lf[4],38, C_text("##sys#chicken.syntax-macro-environment"));
lf[5]=C_h_intern(&lf[5],39, C_text("chicken.syntax#define-values-definition"));
lf[6]=C_h_intern(&lf[6],36, C_text("##sys#chicken.base-macro-environment"));
lf[7]=C_h_intern(&lf[7],36, C_text("##sys#chicken.time-macro-environment"));
lf[8]=C_h_intern(&lf[8],34, C_text("chicken.platform#register-feature!"));
lf[9]=C_h_intern(&lf[9],6, C_text("srfi-2"));
lf[10]=C_h_intern(&lf[10],6, C_text("srfi-8"));
lf[11]=C_h_intern(&lf[11],6, C_text("srfi-9"));
lf[12]=C_h_intern(&lf[12],7, C_text("srfi-11"));
lf[13]=C_h_intern(&lf[13],7, C_text("srfi-15"));
lf[14]=C_h_intern(&lf[14],7, C_text("srfi-16"));
lf[15]=C_h_intern(&lf[15],7, C_text("srfi-26"));
lf[16]=C_h_intern(&lf[16],7, C_text("srfi-31"));
lf[17]=C_h_intern(&lf[17],7, C_text("srfi-55"));
lf[18]=C_h_intern(&lf[18],29, C_text("chicken.internal#macro-subset"));
lf[19]=C_h_intern(&lf[19],31, C_text("##sys#default-macro-environment"));
lf[20]=C_h_intern(&lf[20],30, C_text("##sys#extend-macro-environment"));
lf[21]=C_h_intern(&lf[21],4, C_text("time"));
lf[22]=C_h_intern(&lf[22],17, C_text("##sys#start-timer"));
lf[23]=C_h_intern(&lf[23],13, C_text("##core#lambda"));
lf[24]=C_h_intern(&lf[24],16, C_text("##sys#stop-timer"));
lf[25]=C_h_intern(&lf[25],19, C_text("##sys#display-times"));
lf[26]=C_h_intern(&lf[26],11, C_text("##sys#apply"));
lf[27]=C_h_intern(&lf[27],12, C_text("##sys#values"));
lf[28]=C_h_intern(&lf[28],22, C_text("##sys#call-with-values"));
lf[29]=C_h_intern(&lf[29],12, C_text("##core#begin"));
lf[30]=C_h_intern(&lf[30],1, C_text("t"));
lf[31]=C_h_intern(&lf[31],20, C_text("##sys#er-transformer"));
lf[32]=C_h_intern(&lf[32],23, C_text("##sys#macro-environment"));
lf[33]=C_h_intern(&lf[33],6, C_text("assert"));
lf[34]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020assertion failed"));
lf[35]=C_h_intern(&lf[35],12, C_text("##core#check"));
lf[36]=C_h_intern(&lf[36],11, C_text("##sys#error"));
lf[37]=C_h_intern(&lf[37],9, C_text("##core#if"));
lf[38]=C_h_intern(&lf[38],10, C_text("##core#let"));
lf[39]=C_h_intern(&lf[39],12, C_text("##core#quote"));
lf[40]=C_h_intern(&lf[40],27, C_text("chicken.syntax#strip-syntax"));
lf[41]=C_h_intern(&lf[41],20, C_text("scheme#string-append"));
lf[42]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001("));
lf[43]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002) "));
lf[44]=C_h_intern(&lf[44],30, C_text("chicken.syntax#get-line-number"));
lf[45]=C_h_intern(&lf[45],3, C_text("tmp"));
lf[46]=C_h_intern(&lf[46],18, C_text("##sys#check-syntax"));
lf[47]=C_decode_literal(C_heaptop,C_text("\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[48]=C_h_intern(&lf[48],17, C_text("require-extension"));
lf[49]=C_h_intern(&lf[49],6, C_text("import"));
lf[50]=C_h_intern(&lf[50],3, C_text("rec"));
lf[51]=C_h_intern(&lf[51],14, C_text("##core#letrec\052"));
lf[52]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\001\001_"));
lf[53]=C_h_intern(&lf[53],5, C_text("apply"));
lf[54]=C_h_intern(&lf[54],12, C_text("scheme#apply"));
lf[55]=C_h_intern(&lf[55],4, C_text("cute"));
lf[56]=C_h_intern(&lf[56],12, C_text("##sys#append"));
lf[57]=C_h_intern(&lf[57],19, C_text("chicken.base#gensym"));
lf[58]=C_h_intern(&lf[58],14, C_text("scheme#reverse"));
lf[59]=C_h_intern(&lf[59],27, C_text("chicken.syntax#syntax-error"));
lf[60]=C_decode_literal(C_heaptop,C_text("\376B\000\000+tail patterns after <...> are not supported"));
lf[61]=C_decode_literal(C_heaptop,C_text("\376B\000\000\047you need to supply at least a procedure"));
lf[62]=C_h_intern(&lf[62],5, C_text("<...>"));
lf[63]=C_h_intern(&lf[63],2, C_text("<>"));
lf[64]=C_h_intern(&lf[64],3, C_text("cut"));
lf[65]=C_decode_literal(C_heaptop,C_text("\376B\000\000+tail patterns after <...> are not supported"));
lf[66]=C_decode_literal(C_heaptop,C_text("\376B\000\000\047you need to supply at least a procedure"));
lf[67]=C_h_intern(&lf[67],18, C_text("define-record-type"));
lf[68]=C_h_intern(&lf[68],3, C_text("map"));
lf[69]=C_decode_literal(C_heaptop,C_text("\376B\000\000+unknown slot name in constructor definition"));
lf[70]=C_h_intern(&lf[70],8, C_text("for-each"));
lf[71]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[72]=C_h_intern(&lf[72],20, C_text("##sys#make-structure"));
lf[73]=C_h_intern(&lf[73],16, C_text("##sys#structure\077"));
lf[74]=C_h_intern(&lf[74],21, C_text("##sys#check-structure"));
lf[75]=C_h_intern(&lf[75],15, C_text("##sys#block-ref"));
lf[76]=C_h_intern(&lf[76],12, C_text("##sys#setter"));
lf[77]=C_h_intern(&lf[77],16, C_text("##sys#block-set!"));
lf[78]=C_h_intern(&lf[78],6, C_text("setter"));
lf[79]=C_h_intern(&lf[79],1, C_text("y"));
lf[80]=C_h_intern(&lf[80],1, C_text("x"));
lf[81]=C_h_intern(&lf[81],31, C_text("chicken.base#getter-with-setter"));
lf[82]=C_h_intern(&lf[82],6, C_text("define"));
lf[83]=C_h_intern(&lf[83],26, C_text("chicken.base#symbol-append"));
lf[84]=C_h_intern(&lf[84],1, C_text("#"));
lf[85]=C_h_intern(&lf[85],17, C_text("##sys#module-name"));
lf[86]=C_h_intern(&lf[86],20, C_text("##sys#current-module"));
lf[87]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\000\000\000\002\376\001\000\000\010\001variable\376\377\001\000\000\000\001\376\003\000\000\002\376\001\000\000\010\001variabl"
"e\376\001\000\000\001\001_"));
lf[88]=C_h_intern(&lf[88],21, C_text("define-record-printer"));
lf[89]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\010\001variable\376\377\016\376\000\000\000\002\376\001\000\000\001\001_\376\377\001"
"\000\000\000\001"));
lf[90]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[91]=C_h_intern(&lf[91],32, C_text("chicken.base#set-record-printer!"));
lf[92]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\001\001_"));
lf[93]=C_h_intern(&lf[93],2, C_text(">="));
lf[94]=C_h_intern(&lf[94],9, C_text("scheme#>="));
lf[95]=C_h_intern(&lf[95],3, C_text("car"));
lf[96]=C_h_intern(&lf[96],10, C_text("scheme#car"));
lf[97]=C_h_intern(&lf[97],3, C_text("cdr"));
lf[98]=C_h_intern(&lf[98],10, C_text("scheme#cdr"));
lf[99]=C_h_intern(&lf[99],3, C_text("eq\077"));
lf[100]=C_h_intern(&lf[100],10, C_text("scheme#eq\077"));
lf[101]=C_h_intern(&lf[101],6, C_text("length"));
lf[102]=C_h_intern(&lf[102],13, C_text("scheme#length"));
lf[103]=C_h_intern(&lf[103],11, C_text("case-lambda"));
lf[104]=C_h_intern(&lf[104],5, C_text("foldr"));
lf[105]=C_h_intern(&lf[105],11, C_text("lambda-list"));
lf[106]=C_h_intern(&lf[106],27, C_text("##sys#decompose-lambda-list"));
lf[107]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\014\001##core#check\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001##sys#error\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001##core#immutab"
"le\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001##core#quote\376\003\000\000\002\376B\000\0000no matching clause in call to \047case-lamb"
"da\047 form\376\377\016\376\377\016\376\377\016\376\377\016"));
lf[108]=C_h_intern(&lf[108],13, C_text("scheme#append"));
lf[109]=C_h_intern(&lf[109],4, C_text("lvar"));
lf[110]=C_h_intern(&lf[110],4, C_text("rvar"));
lf[111]=C_h_intern(&lf[111],10, C_text("scheme#min"));
lf[112]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\001\001_"));
lf[113]=C_h_intern(&lf[113],5, C_text("null\077"));
lf[114]=C_h_intern(&lf[114],12, C_text("scheme#null\077"));
lf[115]=C_h_intern(&lf[115],14, C_text("let-optionals\052"));
lf[116]=C_h_intern(&lf[116],4, C_text("tmp2"));
lf[117]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\004\001list\376\001\000\000\001\001_"));
lf[118]=C_h_intern(&lf[118],8, C_text("optional"));
lf[119]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\003\376\001\000\000\001\001_\376\377\001\000\000\000\000\376\377\001\000\000\000\001"));
lf[120]=C_h_intern(&lf[120],13, C_text("let-optionals"));
lf[121]=C_h_intern(&lf[121],21, C_text("scheme#string->symbol"));
lf[122]=C_h_intern(&lf[122],21, C_text("scheme#symbol->string"));
lf[123]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001%"));
lf[124]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004def-"));
lf[125]=C_h_intern(&lf[125],4, C_text("let\052"));
lf[126]=C_h_intern(&lf[126],6, C_text("_%rest"));
lf[127]=C_h_intern(&lf[127],4, C_text("body"));
lf[128]=C_decode_literal(C_heaptop,C_text("\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[129]=C_decode_literal(C_heaptop,C_text("\376\000\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016\376\377\001\000\000\000\000"));
lf[130]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\001\001_"));
lf[131]=C_h_intern(&lf[131],8, C_text("and-let\052"));
lf[132]=C_h_intern(&lf[132],8, C_text("variable"));
lf[133]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[134]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\000\376\001\000\000\001\001_"));
lf[135]=C_h_intern(&lf[135],13, C_text("define-inline"));
lf[136]=C_decode_literal(C_heaptop,C_text("\376B\000\000\052invalid substitution form - must be lambda"));
lf[137]=C_h_intern(&lf[137],6, C_text("lambda"));
lf[138]=C_decode_literal(C_heaptop,C_text("\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[139]=C_h_intern(&lf[139],20, C_text("##core#define-inline"));
lf[140]=C_h_intern(&lf[140],8, C_text("list-ref"));
lf[141]=C_h_intern(&lf[141],15, C_text("scheme#list-ref"));
lf[142]=C_h_intern(&lf[142],9, C_text("nth-value"));
lf[143]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[144]=C_h_intern(&lf[144],7, C_text("letrec\052"));
lf[145]=C_h_intern(&lf[145],44, C_text("chicken.internal#check-for-multiple-bindings"));
lf[146]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007letrec\052"));
lf[147]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\000\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016\376\377\001\000\000\000\000\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000"
"\000\001"));
lf[148]=C_h_intern(&lf[148],13, C_text("letrec-values"));
lf[149]=C_h_intern(&lf[149],5, C_text("foldl"));
lf[150]=C_h_intern(&lf[150],39, C_text("##sys#expand-multiple-values-assignment"));
lf[151]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[152]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\000\000\000\002\376\003\000\000\002\376\001\000\000\013\001lambda-list\376\001\000\000\001\001_\376\377\001\000\000\000\000\376\001\000\000\001\001_"));
lf[153]=C_h_intern(&lf[153],11, C_text("let\052-values"));
lf[154]=C_h_intern(&lf[154],10, C_text("let-values"));
lf[155]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\004\001list\376\001\000\000\001\001_"));
lf[156]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\004\001list\376\001\000\000\001\001_"));
lf[157]=C_h_intern(&lf[157],13, C_text("define-values"));
lf[158]=C_h_intern(&lf[158],33, C_text("##core#ensure-toplevel-definition"));
lf[159]=C_h_intern(&lf[159],21, C_text("##sys#register-export"));
lf[160]=C_h_intern(&lf[160],9, C_text("##sys#get"));
lf[161]=C_h_intern(&lf[161],18, C_text("##core#macro-alias"));
lf[162]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\013\001lambda-list\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[163]=C_h_intern(&lf[163],11, C_text("set!-values"));
lf[164]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\013\001lambda-list\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[165]=C_h_intern(&lf[165],6, C_text("unless"));
lf[166]=C_h_intern(&lf[166],16, C_text("##core#undefined"));
lf[167]=C_decode_literal(C_heaptop,C_text("\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\002"));
lf[168]=C_h_intern(&lf[168],4, C_text("when"));
lf[169]=C_decode_literal(C_heaptop,C_text("\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\002"));
lf[170]=C_h_intern(&lf[170],15, C_text("require-library"));
lf[171]=C_h_intern(&lf[171],22, C_text("##sys#decompose-import"));
lf[172]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[173]=C_h_intern(&lf[173],14, C_text("##core#require"));
lf[174]=C_h_intern(&lf[174],12, C_text("parameterize"));
lf[175]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011parameter"));
lf[176]=C_h_intern(&lf[176],5, C_text("saved"));
lf[177]=C_h_intern(&lf[177],10, C_text("##core#the"));
lf[178]=C_h_intern(&lf[178],7, C_text("boolean"));
lf[179]=C_h_intern(&lf[179],18, C_text("##sys#dynamic-wind"));
lf[180]=C_h_intern(&lf[180],11, C_text("##core#set!"));
lf[181]=C_h_intern(&lf[181],8, C_text("convert\077"));
lf[182]=C_decode_literal(C_heaptop,C_text("\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\002"));
lf[183]=C_h_intern(&lf[183],9, C_text("fluid-let"));
lf[184]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\000\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016\376\377\001\000\000\000\000\376\001\000\000\001\001_"));
lf[185]=C_h_intern(&lf[185],16, C_text("include-relative"));
lf[186]=C_h_intern(&lf[186],14, C_text("##core#include"));
lf[187]=C_h_intern(&lf[187],29, C_text("##sys#current-source-filename"));
lf[188]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\006\001string\376\377\016"));
lf[189]=C_h_intern(&lf[189],7, C_text("include"));
lf[190]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\006\001string\376\377\016"));
lf[191]=C_h_intern(&lf[191],11, C_text("delay-force"));
lf[192]=C_h_intern(&lf[192],18, C_text("##sys#make-promise"));
lf[193]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[194]=C_h_intern(&lf[194],7, C_text("declare"));
lf[195]=C_h_intern(&lf[195],14, C_text("##core#declare"));
lf[196]=C_h_intern(&lf[196],7, C_text("receive"));
lf[197]=C_h_intern(&lf[197],10, C_text("##sys#list"));
lf[198]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\013\001lambda-list\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[199]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\000"));
lf[200]=C_h_intern(&lf[200],13, C_text("define-record"));
lf[201]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032invalid slot specification"));
lf[202]=C_h_intern(&lf[202],3, C_text("val"));
lf[203]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001-"));
lf[204]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001-"));
lf[205]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005-set!"));
lf[206]=C_h_intern(&lf[206],19, C_text("##sys#string-append"));
lf[207]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\077"));
lf[208]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005make-"));
lf[209]=C_h_intern(&lf[209],19, C_text("chicken.base#setter"));
lf[210]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\010\001variable\376\001\000\000\001\001_"));
lf[211]=C_h_intern(&lf[211],15, C_text("define-constant"));
lf[212]=C_h_intern(&lf[212],22, C_text("##core#define-constant"));
lf[213]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[214]=C_h_intern(&lf[214],19, C_text("let-compiler-syntax"));
lf[215]=C_h_intern(&lf[215],26, C_text("##core#let-compiler-syntax"));
lf[216]=C_h_intern(&lf[216],51, C_text("chicken.internal.syntax-rules#syntax-rules-mismatch"));
lf[217]=C_h_intern(&lf[217],7, C_text("##sys#+"));
lf[218]=C_h_intern(&lf[218],7, C_text("##sys#="));
lf[219]=C_h_intern(&lf[219],8, C_text("##sys#>="));
lf[220]=C_h_intern(&lf[220],12, C_text("##sys#length"));
lf[221]=C_h_intern(&lf[221],11, C_text("##sys#list\077"));
lf[222]=C_h_intern(&lf[222],22, C_text("define-compiler-syntax"));
lf[223]=C_h_intern(&lf[223],29, C_text("##core#define-compiler-syntax"));
lf[224]=C_h_intern(&lf[224],17, C_text("define-for-syntax"));
lf[225]=C_h_intern(&lf[225],16, C_text("begin-for-syntax"));
lf[226]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\001\001_"));
lf[227]=C_h_intern(&lf[227],26, C_text("##core#elaborationtimeonly"));
lf[228]=C_h_intern(&lf[228],30, C_text("##sys#register-meta-expression"));
lf[229]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\000"));
lf[230]=C_h_intern(&lf[230],6, C_text("syntax"));
lf[231]=C_h_intern(&lf[231],13, C_text("##core#syntax"));
lf[232]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[233]=C_h_intern(&lf[233],11, C_text("define-type"));
lf[234]=C_h_intern_kw(&lf[234],9, C_text("compiling"));
lf[235]=C_h_intern(&lf[235],14, C_text("##sys#features"));
lf[236]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[237]=C_h_intern(&lf[237],28, C_text("##compiler#type-abbreviation"));
lf[238]=C_h_intern(&lf[238],18, C_text("##sys#put/restore!"));
lf[239]=C_h_intern(&lf[239],52, C_text("chicken.compiler.scrutinizer#check-and-validate-type"));
lf[240]=C_h_intern(&lf[240],5, C_text("quote"));
lf[241]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[242]=C_h_intern(&lf[242],17, C_text("compiler-typecase"));
lf[243]=C_h_intern(&lf[243],4, C_text("else"));
lf[244]=C_h_intern(&lf[244],15, C_text("##core#typecase"));
lf[245]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001\376\377\001\000\000\000\001"));
lf[246]=C_h_intern(&lf[246],21, C_text("define-specialization"));
lf[247]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[248]=C_h_intern(&lf[248],27, C_text("##core#local-specialization"));
lf[249]=C_h_intern(&lf[249],6, C_text("inline"));
lf[250]=C_h_intern(&lf[250],4, C_text("hide"));
lf[251]=C_h_intern(&lf[251],1, C_text("\052"));
lf[252]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027invalid argument syntax"));
lf[253]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\000\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\003\376\001\000\000\001\001_\376"
"\377\001\000\000\000\000\376\377\001\000\000\000\001"));
lf[254]=C_h_intern(&lf[254],6, C_text("assume"));
lf[255]=C_h_intern(&lf[255],3, C_text("the"));
lf[256]=C_h_intern(&lf[256],11, C_text("##sys#map-n"));
lf[257]=C_h_intern(&lf[257],3, C_text("let"));
lf[258]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[259]=C_h_intern(&lf[259],1, C_text(":"));
lf[260]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[261]=C_h_intern(&lf[261],42, C_text("chicken.compiler.scrutinizer#validate-type"));
lf[262]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023invalid type syntax"));
lf[263]=C_h_intern(&lf[263],4, C_text("type"));
lf[264]=C_h_intern(&lf[264],9, C_text("predicate"));
lf[265]=C_h_intern(&lf[265],4, C_text("pure"));
lf[266]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\006\001symbol\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\001\001_"));
lf[267]=C_h_intern(&lf[267],4, C_text("memv"));
lf[268]=C_h_intern(&lf[268],11, C_text("scheme#memv"));
lf[269]=C_h_intern(&lf[269],14, C_text("condition-case"));
lf[270]=C_h_intern(&lf[270],9, C_text("condition"));
lf[271]=C_h_intern(&lf[271],10, C_text("##sys#slot"));
lf[272]=C_h_intern(&lf[272],24, C_text("chicken.condition#signal"));
lf[273]=C_h_intern(&lf[273],4, C_text("cond"));
lf[274]=C_h_intern(&lf[274],17, C_text("handle-exceptions"));
lf[275]=C_h_intern(&lf[275],3, C_text("and"));
lf[276]=C_h_intern(&lf[276],4, C_text("kvar"));
lf[277]=C_h_intern(&lf[277],5, C_text("exvar"));
lf[278]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\001\001_"));
lf[279]=C_h_intern(&lf[279],30, C_text("call-with-current-continuation"));
lf[280]=C_h_intern(&lf[280],37, C_text("scheme#call-with-current-continuation"));
lf[281]=C_h_intern(&lf[281],40, C_text("chicken.condition#with-exception-handler"));
lf[282]=C_h_intern(&lf[282],4, C_text("args"));
lf[283]=C_h_intern(&lf[283],1, C_text("k"));
lf[284]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\001\001_"));
C_register_lf2(lf,285,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4231,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_expand_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[657] = {
{C_text("f_10014:chicken_2dsyntax_2escm"),(void*)f_10014},
{C_text("f_10062:chicken_2dsyntax_2escm"),(void*)f_10062},
{C_text("f_10110:chicken_2dsyntax_2escm"),(void*)f_10110},
{C_text("f_10135:chicken_2dsyntax_2escm"),(void*)f_10135},
{C_text("f_10144:chicken_2dsyntax_2escm"),(void*)f_10144},
{C_text("f_10169:chicken_2dsyntax_2escm"),(void*)f_10169},
{C_text("f_10178:chicken_2dsyntax_2escm"),(void*)f_10178},
{C_text("f_10203:chicken_2dsyntax_2escm"),(void*)f_10203},
{C_text("f_10212:chicken_2dsyntax_2escm"),(void*)f_10212},
{C_text("f_10246:chicken_2dsyntax_2escm"),(void*)f_10246},
{C_text("f_10282:chicken_2dsyntax_2escm"),(void*)f_10282},
{C_text("f_10284:chicken_2dsyntax_2escm"),(void*)f_10284},
{C_text("f_10288:chicken_2dsyntax_2escm"),(void*)f_10288},
{C_text("f_10302:chicken_2dsyntax_2escm"),(void*)f_10302},
{C_text("f_10306:chicken_2dsyntax_2escm"),(void*)f_10306},
{C_text("f_10314:chicken_2dsyntax_2escm"),(void*)f_10314},
{C_text("f_10317:chicken_2dsyntax_2escm"),(void*)f_10317},
{C_text("f_10321:chicken_2dsyntax_2escm"),(void*)f_10321},
{C_text("f_10329:chicken_2dsyntax_2escm"),(void*)f_10329},
{C_text("f_10332:chicken_2dsyntax_2escm"),(void*)f_10332},
{C_text("f_10339:chicken_2dsyntax_2escm"),(void*)f_10339},
{C_text("f_10363:chicken_2dsyntax_2escm"),(void*)f_10363},
{C_text("f_10375:chicken_2dsyntax_2escm"),(void*)f_10375},
{C_text("f_10379:chicken_2dsyntax_2escm"),(void*)f_10379},
{C_text("f_10391:chicken_2dsyntax_2escm"),(void*)f_10391},
{C_text("f_10401:chicken_2dsyntax_2escm"),(void*)f_10401},
{C_text("f_10449:chicken_2dsyntax_2escm"),(void*)f_10449},
{C_text("f_10507:chicken_2dsyntax_2escm"),(void*)f_10507},
{C_text("f_10522:chicken_2dsyntax_2escm"),(void*)f_10522},
{C_text("f_10526:chicken_2dsyntax_2escm"),(void*)f_10526},
{C_text("f_10538:chicken_2dsyntax_2escm"),(void*)f_10538},
{C_text("f_10548:chicken_2dsyntax_2escm"),(void*)f_10548},
{C_text("f_10596:chicken_2dsyntax_2escm"),(void*)f_10596},
{C_text("f_10652:chicken_2dsyntax_2escm"),(void*)f_10652},
{C_text("f_10661:chicken_2dsyntax_2escm"),(void*)f_10661},
{C_text("f_10668:chicken_2dsyntax_2escm"),(void*)f_10668},
{C_text("f_10677:chicken_2dsyntax_2escm"),(void*)f_10677},
{C_text("f_10679:chicken_2dsyntax_2escm"),(void*)f_10679},
{C_text("f_10729:chicken_2dsyntax_2escm"),(void*)f_10729},
{C_text("f_10743:chicken_2dsyntax_2escm"),(void*)f_10743},
{C_text("f_10749:chicken_2dsyntax_2escm"),(void*)f_10749},
{C_text("f_10797:chicken_2dsyntax_2escm"),(void*)f_10797},
{C_text("f_10831:chicken_2dsyntax_2escm"),(void*)f_10831},
{C_text("f_10856:chicken_2dsyntax_2escm"),(void*)f_10856},
{C_text("f_10865:chicken_2dsyntax_2escm"),(void*)f_10865},
{C_text("f_10890:chicken_2dsyntax_2escm"),(void*)f_10890},
{C_text("f_10899:chicken_2dsyntax_2escm"),(void*)f_10899},
{C_text("f_10935:chicken_2dsyntax_2escm"),(void*)f_10935},
{C_text("f_10937:chicken_2dsyntax_2escm"),(void*)f_10937},
{C_text("f_10941:chicken_2dsyntax_2escm"),(void*)f_10941},
{C_text("f_10952:chicken_2dsyntax_2escm"),(void*)f_10952},
{C_text("f_10954:chicken_2dsyntax_2escm"),(void*)f_10954},
{C_text("f_10958:chicken_2dsyntax_2escm"),(void*)f_10958},
{C_text("f_10969:chicken_2dsyntax_2escm"),(void*)f_10969},
{C_text("f_10971:chicken_2dsyntax_2escm"),(void*)f_10971},
{C_text("f_10975:chicken_2dsyntax_2escm"),(void*)f_10975},
{C_text("f_10990:chicken_2dsyntax_2escm"),(void*)f_10990},
{C_text("f_10992:chicken_2dsyntax_2escm"),(void*)f_10992},
{C_text("f_11004:chicken_2dsyntax_2escm"),(void*)f_11004},
{C_text("f_11006:chicken_2dsyntax_2escm"),(void*)f_11006},
{C_text("f_11010:chicken_2dsyntax_2escm"),(void*)f_11010},
{C_text("f_11032:chicken_2dsyntax_2escm"),(void*)f_11032},
{C_text("f_11097:chicken_2dsyntax_2escm"),(void*)f_11097},
{C_text("f_11099:chicken_2dsyntax_2escm"),(void*)f_11099},
{C_text("f_11103:chicken_2dsyntax_2escm"),(void*)f_11103},
{C_text("f_11109:chicken_2dsyntax_2escm"),(void*)f_11109},
{C_text("f_11112:chicken_2dsyntax_2escm"),(void*)f_11112},
{C_text("f_11115:chicken_2dsyntax_2escm"),(void*)f_11115},
{C_text("f_11121:chicken_2dsyntax_2escm"),(void*)f_11121},
{C_text("f_11124:chicken_2dsyntax_2escm"),(void*)f_11124},
{C_text("f_11127:chicken_2dsyntax_2escm"),(void*)f_11127},
{C_text("f_11131:chicken_2dsyntax_2escm"),(void*)f_11131},
{C_text("f_11144:chicken_2dsyntax_2escm"),(void*)f_11144},
{C_text("f_11159:chicken_2dsyntax_2escm"),(void*)f_11159},
{C_text("f_11191:chicken_2dsyntax_2escm"),(void*)f_11191},
{C_text("f_11222:chicken_2dsyntax_2escm"),(void*)f_11222},
{C_text("f_11224:chicken_2dsyntax_2escm"),(void*)f_11224},
{C_text("f_11240:chicken_2dsyntax_2escm"),(void*)f_11240},
{C_text("f_11243:chicken_2dsyntax_2escm"),(void*)f_11243},
{C_text("f_11246:chicken_2dsyntax_2escm"),(void*)f_11246},
{C_text("f_11260:chicken_2dsyntax_2escm"),(void*)f_11260},
{C_text("f_11272:chicken_2dsyntax_2escm"),(void*)f_11272},
{C_text("f_11276:chicken_2dsyntax_2escm"),(void*)f_11276},
{C_text("f_11369:chicken_2dsyntax_2escm"),(void*)f_11369},
{C_text("f_11373:chicken_2dsyntax_2escm"),(void*)f_11373},
{C_text("f_11388:chicken_2dsyntax_2escm"),(void*)f_11388},
{C_text("f_11408:chicken_2dsyntax_2escm"),(void*)f_11408},
{C_text("f_11414:chicken_2dsyntax_2escm"),(void*)f_11414},
{C_text("f_11434:chicken_2dsyntax_2escm"),(void*)f_11434},
{C_text("f_11442:chicken_2dsyntax_2escm"),(void*)f_11442},
{C_text("f_11467:chicken_2dsyntax_2escm"),(void*)f_11467},
{C_text("f_11477:chicken_2dsyntax_2escm"),(void*)f_11477},
{C_text("f_11484:chicken_2dsyntax_2escm"),(void*)f_11484},
{C_text("f_11488:chicken_2dsyntax_2escm"),(void*)f_11488},
{C_text("f_11492:chicken_2dsyntax_2escm"),(void*)f_11492},
{C_text("f_11494:chicken_2dsyntax_2escm"),(void*)f_11494},
{C_text("f_11498:chicken_2dsyntax_2escm"),(void*)f_11498},
{C_text("f_11509:chicken_2dsyntax_2escm"),(void*)f_11509},
{C_text("f_11511:chicken_2dsyntax_2escm"),(void*)f_11511},
{C_text("f_11521:chicken_2dsyntax_2escm"),(void*)f_11521},
{C_text("f_11534:chicken_2dsyntax_2escm"),(void*)f_11534},
{C_text("f_11550:chicken_2dsyntax_2escm"),(void*)f_11550},
{C_text("f_11556:chicken_2dsyntax_2escm"),(void*)f_11556},
{C_text("f_11559:chicken_2dsyntax_2escm"),(void*)f_11559},
{C_text("f_11565:chicken_2dsyntax_2escm"),(void*)f_11565},
{C_text("f_11574:chicken_2dsyntax_2escm"),(void*)f_11574},
{C_text("f_11581:chicken_2dsyntax_2escm"),(void*)f_11581},
{C_text("f_11595:chicken_2dsyntax_2escm"),(void*)f_11595},
{C_text("f_11606:chicken_2dsyntax_2escm"),(void*)f_11606},
{C_text("f_11609:chicken_2dsyntax_2escm"),(void*)f_11609},
{C_text("f_11615:chicken_2dsyntax_2escm"),(void*)f_11615},
{C_text("f_11624:chicken_2dsyntax_2escm"),(void*)f_11624},
{C_text("f_11631:chicken_2dsyntax_2escm"),(void*)f_11631},
{C_text("f_11645:chicken_2dsyntax_2escm"),(void*)f_11645},
{C_text("f_11657:chicken_2dsyntax_2escm"),(void*)f_11657},
{C_text("f_11659:chicken_2dsyntax_2escm"),(void*)f_11659},
{C_text("f_11679:chicken_2dsyntax_2escm"),(void*)f_11679},
{C_text("f_11693:chicken_2dsyntax_2escm"),(void*)f_11693},
{C_text("f_11706:chicken_2dsyntax_2escm"),(void*)f_11706},
{C_text("f_11754:chicken_2dsyntax_2escm"),(void*)f_11754},
{C_text("f_11756:chicken_2dsyntax_2escm"),(void*)f_11756},
{C_text("f_11760:chicken_2dsyntax_2escm"),(void*)f_11760},
{C_text("f_11767:chicken_2dsyntax_2escm"),(void*)f_11767},
{C_text("f_11775:chicken_2dsyntax_2escm"),(void*)f_11775},
{C_text("f_11783:chicken_2dsyntax_2escm"),(void*)f_11783},
{C_text("f_11785:chicken_2dsyntax_2escm"),(void*)f_11785},
{C_text("f_11789:chicken_2dsyntax_2escm"),(void*)f_11789},
{C_text("f_11792:chicken_2dsyntax_2escm"),(void*)f_11792},
{C_text("f_11813:chicken_2dsyntax_2escm"),(void*)f_11813},
{C_text("f_11815:chicken_2dsyntax_2escm"),(void*)f_11815},
{C_text("f_11819:chicken_2dsyntax_2escm"),(void*)f_11819},
{C_text("f_11830:chicken_2dsyntax_2escm"),(void*)f_11830},
{C_text("f_11832:chicken_2dsyntax_2escm"),(void*)f_11832},
{C_text("f_11836:chicken_2dsyntax_2escm"),(void*)f_11836},
{C_text("f_11845:chicken_2dsyntax_2escm"),(void*)f_11845},
{C_text("f_11848:chicken_2dsyntax_2escm"),(void*)f_11848},
{C_text("f_11851:chicken_2dsyntax_2escm"),(void*)f_11851},
{C_text("f_11874:chicken_2dsyntax_2escm"),(void*)f_11874},
{C_text("f_11890:chicken_2dsyntax_2escm"),(void*)f_11890},
{C_text("f_11892:chicken_2dsyntax_2escm"),(void*)f_11892},
{C_text("f_11896:chicken_2dsyntax_2escm"),(void*)f_11896},
{C_text("f_11902:chicken_2dsyntax_2escm"),(void*)f_11902},
{C_text("f_11905:chicken_2dsyntax_2escm"),(void*)f_11905},
{C_text("f_11929:chicken_2dsyntax_2escm"),(void*)f_11929},
{C_text("f_11933:chicken_2dsyntax_2escm"),(void*)f_11933},
{C_text("f_11940:chicken_2dsyntax_2escm"),(void*)f_11940},
{C_text("f_11967:chicken_2dsyntax_2escm"),(void*)f_11967},
{C_text("f_11969:chicken_2dsyntax_2escm"),(void*)f_11969},
{C_text("f_11994:chicken_2dsyntax_2escm"),(void*)f_11994},
{C_text("f_12013:chicken_2dsyntax_2escm"),(void*)f_12013},
{C_text("f_12015:chicken_2dsyntax_2escm"),(void*)f_12015},
{C_text("f_12025:chicken_2dsyntax_2escm"),(void*)f_12025},
{C_text("f_12035:chicken_2dsyntax_2escm"),(void*)f_12035},
{C_text("f_12038:chicken_2dsyntax_2escm"),(void*)f_12038},
{C_text("f_12041:chicken_2dsyntax_2escm"),(void*)f_12041},
{C_text("f_12049:chicken_2dsyntax_2escm"),(void*)f_12049},
{C_text("f_12059:chicken_2dsyntax_2escm"),(void*)f_12059},
{C_text("f_12062:chicken_2dsyntax_2escm"),(void*)f_12062},
{C_text("f_12104:chicken_2dsyntax_2escm"),(void*)f_12104},
{C_text("f_12106:chicken_2dsyntax_2escm"),(void*)f_12106},
{C_text("f_12168:chicken_2dsyntax_2escm"),(void*)f_12168},
{C_text("f_12189:chicken_2dsyntax_2escm"),(void*)f_12189},
{C_text("f_12191:chicken_2dsyntax_2escm"),(void*)f_12191},
{C_text("f_12216:chicken_2dsyntax_2escm"),(void*)f_12216},
{C_text("f_12233:chicken_2dsyntax_2escm"),(void*)f_12233},
{C_text("f_12235:chicken_2dsyntax_2escm"),(void*)f_12235},
{C_text("f_12253:chicken_2dsyntax_2escm"),(void*)f_12253},
{C_text("f_12289:chicken_2dsyntax_2escm"),(void*)f_12289},
{C_text("f_12306:chicken_2dsyntax_2escm"),(void*)f_12306},
{C_text("f_12363:chicken_2dsyntax_2escm"),(void*)f_12363},
{C_text("f_12365:chicken_2dsyntax_2escm"),(void*)f_12365},
{C_text("f_12375:chicken_2dsyntax_2escm"),(void*)f_12375},
{C_text("f_12392:chicken_2dsyntax_2escm"),(void*)f_12392},
{C_text("f_12413:chicken_2dsyntax_2escm"),(void*)f_12413},
{C_text("f_12423:chicken_2dsyntax_2escm"),(void*)f_12423},
{C_text("f_12431:chicken_2dsyntax_2escm"),(void*)f_12431},
{C_text("f_12433:chicken_2dsyntax_2escm"),(void*)f_12433},
{C_text("f_12449:chicken_2dsyntax_2escm"),(void*)f_12449},
{C_text("f_12459:chicken_2dsyntax_2escm"),(void*)f_12459},
{C_text("f_12493:chicken_2dsyntax_2escm"),(void*)f_12493},
{C_text("f_12537:chicken_2dsyntax_2escm"),(void*)f_12537},
{C_text("f_12543:chicken_2dsyntax_2escm"),(void*)f_12543},
{C_text("f_12546:chicken_2dsyntax_2escm"),(void*)f_12546},
{C_text("f_12552:chicken_2dsyntax_2escm"),(void*)f_12552},
{C_text("f_12561:chicken_2dsyntax_2escm"),(void*)f_12561},
{C_text("f_12568:chicken_2dsyntax_2escm"),(void*)f_12568},
{C_text("f_12582:chicken_2dsyntax_2escm"),(void*)f_12582},
{C_text("f_12593:chicken_2dsyntax_2escm"),(void*)f_12593},
{C_text("f_12596:chicken_2dsyntax_2escm"),(void*)f_12596},
{C_text("f_12602:chicken_2dsyntax_2escm"),(void*)f_12602},
{C_text("f_12611:chicken_2dsyntax_2escm"),(void*)f_12611},
{C_text("f_12618:chicken_2dsyntax_2escm"),(void*)f_12618},
{C_text("f_12630:chicken_2dsyntax_2escm"),(void*)f_12630},
{C_text("f_12641:chicken_2dsyntax_2escm"),(void*)f_12641},
{C_text("f_12672:chicken_2dsyntax_2escm"),(void*)f_12672},
{C_text("f_12674:chicken_2dsyntax_2escm"),(void*)f_12674},
{C_text("f_12678:chicken_2dsyntax_2escm"),(void*)f_12678},
{C_text("f_12694:chicken_2dsyntax_2escm"),(void*)f_12694},
{C_text("f_12710:chicken_2dsyntax_2escm"),(void*)f_12710},
{C_text("f_12712:chicken_2dsyntax_2escm"),(void*)f_12712},
{C_text("f_12716:chicken_2dsyntax_2escm"),(void*)f_12716},
{C_text("f_12725:chicken_2dsyntax_2escm"),(void*)f_12725},
{C_text("f_12732:chicken_2dsyntax_2escm"),(void*)f_12732},
{C_text("f_12740:chicken_2dsyntax_2escm"),(void*)f_12740},
{C_text("f_12742:chicken_2dsyntax_2escm"),(void*)f_12742},
{C_text("f_12767:chicken_2dsyntax_2escm"),(void*)f_12767},
{C_text("f_12771:chicken_2dsyntax_2escm"),(void*)f_12771},
{C_text("f_12821:chicken_2dsyntax_2escm"),(void*)f_12821},
{C_text("f_12823:chicken_2dsyntax_2escm"),(void*)f_12823},
{C_text("f_12827:chicken_2dsyntax_2escm"),(void*)f_12827},
{C_text("f_12830:chicken_2dsyntax_2escm"),(void*)f_12830},
{C_text("f_12833:chicken_2dsyntax_2escm"),(void*)f_12833},
{C_text("f_12836:chicken_2dsyntax_2escm"),(void*)f_12836},
{C_text("f_12839:chicken_2dsyntax_2escm"),(void*)f_12839},
{C_text("f_12842:chicken_2dsyntax_2escm"),(void*)f_12842},
{C_text("f_12844:chicken_2dsyntax_2escm"),(void*)f_12844},
{C_text("f_12854:chicken_2dsyntax_2escm"),(void*)f_12854},
{C_text("f_12879:chicken_2dsyntax_2escm"),(void*)f_12879},
{C_text("f_12893:chicken_2dsyntax_2escm"),(void*)f_12893},
{C_text("f_12895:chicken_2dsyntax_2escm"),(void*)f_12895},
{C_text("f_12974:chicken_2dsyntax_2escm"),(void*)f_12974},
{C_text("f_12999:chicken_2dsyntax_2escm"),(void*)f_12999},
{C_text("f_13006:chicken_2dsyntax_2escm"),(void*)f_13006},
{C_text("f_13010:chicken_2dsyntax_2escm"),(void*)f_13010},
{C_text("f_13030:chicken_2dsyntax_2escm"),(void*)f_13030},
{C_text("f_13055:chicken_2dsyntax_2escm"),(void*)f_13055},
{C_text("f_13094:chicken_2dsyntax_2escm"),(void*)f_13094},
{C_text("f_13096:chicken_2dsyntax_2escm"),(void*)f_13096},
{C_text("f_13100:chicken_2dsyntax_2escm"),(void*)f_13100},
{C_text("f_13103:chicken_2dsyntax_2escm"),(void*)f_13103},
{C_text("f_13106:chicken_2dsyntax_2escm"),(void*)f_13106},
{C_text("f_13117:chicken_2dsyntax_2escm"),(void*)f_13117},
{C_text("f_4231:chicken_2dsyntax_2escm"),(void*)f_4231},
{C_text("f_4234:chicken_2dsyntax_2escm"),(void*)f_4234},
{C_text("f_4237:chicken_2dsyntax_2escm"),(void*)f_4237},
{C_text("f_4347:chicken_2dsyntax_2escm"),(void*)f_4347},
{C_text("f_4365:chicken_2dsyntax_2escm"),(void*)f_4365},
{C_text("f_4405:chicken_2dsyntax_2escm"),(void*)f_4405},
{C_text("f_4419:chicken_2dsyntax_2escm"),(void*)f_4419},
{C_text("f_5519:chicken_2dsyntax_2escm"),(void*)f_5519},
{C_text("f_5522:chicken_2dsyntax_2escm"),(void*)f_5522},
{C_text("f_5525:chicken_2dsyntax_2escm"),(void*)f_5525},
{C_text("f_5528:chicken_2dsyntax_2escm"),(void*)f_5528},
{C_text("f_5532:chicken_2dsyntax_2escm"),(void*)f_5532},
{C_text("f_5535:chicken_2dsyntax_2escm"),(void*)f_5535},
{C_text("f_5538:chicken_2dsyntax_2escm"),(void*)f_5538},
{C_text("f_5541:chicken_2dsyntax_2escm"),(void*)f_5541},
{C_text("f_5544:chicken_2dsyntax_2escm"),(void*)f_5544},
{C_text("f_5547:chicken_2dsyntax_2escm"),(void*)f_5547},
{C_text("f_5550:chicken_2dsyntax_2escm"),(void*)f_5550},
{C_text("f_5553:chicken_2dsyntax_2escm"),(void*)f_5553},
{C_text("f_5557:chicken_2dsyntax_2escm"),(void*)f_5557},
{C_text("f_5560:chicken_2dsyntax_2escm"),(void*)f_5560},
{C_text("f_5563:chicken_2dsyntax_2escm"),(void*)f_5563},
{C_text("f_5566:chicken_2dsyntax_2escm"),(void*)f_5566},
{C_text("f_5569:chicken_2dsyntax_2escm"),(void*)f_5569},
{C_text("f_5572:chicken_2dsyntax_2escm"),(void*)f_5572},
{C_text("f_5575:chicken_2dsyntax_2escm"),(void*)f_5575},
{C_text("f_5579:chicken_2dsyntax_2escm"),(void*)f_5579},
{C_text("f_5582:chicken_2dsyntax_2escm"),(void*)f_5582},
{C_text("f_5585:chicken_2dsyntax_2escm"),(void*)f_5585},
{C_text("f_5588:chicken_2dsyntax_2escm"),(void*)f_5588},
{C_text("f_5591:chicken_2dsyntax_2escm"),(void*)f_5591},
{C_text("f_5594:chicken_2dsyntax_2escm"),(void*)f_5594},
{C_text("f_5597:chicken_2dsyntax_2escm"),(void*)f_5597},
{C_text("f_5600:chicken_2dsyntax_2escm"),(void*)f_5600},
{C_text("f_5603:chicken_2dsyntax_2escm"),(void*)f_5603},
{C_text("f_5606:chicken_2dsyntax_2escm"),(void*)f_5606},
{C_text("f_5609:chicken_2dsyntax_2escm"),(void*)f_5609},
{C_text("f_5612:chicken_2dsyntax_2escm"),(void*)f_5612},
{C_text("f_5615:chicken_2dsyntax_2escm"),(void*)f_5615},
{C_text("f_5618:chicken_2dsyntax_2escm"),(void*)f_5618},
{C_text("f_5622:chicken_2dsyntax_2escm"),(void*)f_5622},
{C_text("f_5625:chicken_2dsyntax_2escm"),(void*)f_5625},
{C_text("f_5628:chicken_2dsyntax_2escm"),(void*)f_5628},
{C_text("f_5631:chicken_2dsyntax_2escm"),(void*)f_5631},
{C_text("f_5634:chicken_2dsyntax_2escm"),(void*)f_5634},
{C_text("f_5637:chicken_2dsyntax_2escm"),(void*)f_5637},
{C_text("f_5640:chicken_2dsyntax_2escm"),(void*)f_5640},
{C_text("f_5643:chicken_2dsyntax_2escm"),(void*)f_5643},
{C_text("f_5646:chicken_2dsyntax_2escm"),(void*)f_5646},
{C_text("f_5649:chicken_2dsyntax_2escm"),(void*)f_5649},
{C_text("f_5652:chicken_2dsyntax_2escm"),(void*)f_5652},
{C_text("f_5655:chicken_2dsyntax_2escm"),(void*)f_5655},
{C_text("f_5658:chicken_2dsyntax_2escm"),(void*)f_5658},
{C_text("f_5661:chicken_2dsyntax_2escm"),(void*)f_5661},
{C_text("f_5664:chicken_2dsyntax_2escm"),(void*)f_5664},
{C_text("f_5667:chicken_2dsyntax_2escm"),(void*)f_5667},
{C_text("f_5670:chicken_2dsyntax_2escm"),(void*)f_5670},
{C_text("f_5673:chicken_2dsyntax_2escm"),(void*)f_5673},
{C_text("f_5676:chicken_2dsyntax_2escm"),(void*)f_5676},
{C_text("f_5679:chicken_2dsyntax_2escm"),(void*)f_5679},
{C_text("f_5683:chicken_2dsyntax_2escm"),(void*)f_5683},
{C_text("f_5686:chicken_2dsyntax_2escm"),(void*)f_5686},
{C_text("f_5689:chicken_2dsyntax_2escm"),(void*)f_5689},
{C_text("f_5692:chicken_2dsyntax_2escm"),(void*)f_5692},
{C_text("f_5696:chicken_2dsyntax_2escm"),(void*)f_5696},
{C_text("f_5698:chicken_2dsyntax_2escm"),(void*)f_5698},
{C_text("f_5702:chicken_2dsyntax_2escm"),(void*)f_5702},
{C_text("f_5745:chicken_2dsyntax_2escm"),(void*)f_5745},
{C_text("f_5747:chicken_2dsyntax_2escm"),(void*)f_5747},
{C_text("f_5751:chicken_2dsyntax_2escm"),(void*)f_5751},
{C_text("f_5762:chicken_2dsyntax_2escm"),(void*)f_5762},
{C_text("f_5765:chicken_2dsyntax_2escm"),(void*)f_5765},
{C_text("f_5788:chicken_2dsyntax_2escm"),(void*)f_5788},
{C_text("f_5807:chicken_2dsyntax_2escm"),(void*)f_5807},
{C_text("f_5817:chicken_2dsyntax_2escm"),(void*)f_5817},
{C_text("f_5824:chicken_2dsyntax_2escm"),(void*)f_5824},
{C_text("f_5834:chicken_2dsyntax_2escm"),(void*)f_5834},
{C_text("f_5836:chicken_2dsyntax_2escm"),(void*)f_5836},
{C_text("f_5844:chicken_2dsyntax_2escm"),(void*)f_5844},
{C_text("f_5852:chicken_2dsyntax_2escm"),(void*)f_5852},
{C_text("f_5854:chicken_2dsyntax_2escm"),(void*)f_5854},
{C_text("f_5858:chicken_2dsyntax_2escm"),(void*)f_5858},
{C_text("f_5917:chicken_2dsyntax_2escm"),(void*)f_5917},
{C_text("f_5919:chicken_2dsyntax_2escm"),(void*)f_5919},
{C_text("f_5923:chicken_2dsyntax_2escm"),(void*)f_5923},
{C_text("f_5926:chicken_2dsyntax_2escm"),(void*)f_5926},
{C_text("f_5929:chicken_2dsyntax_2escm"),(void*)f_5929},
{C_text("f_5932:chicken_2dsyntax_2escm"),(void*)f_5932},
{C_text("f_5939:chicken_2dsyntax_2escm"),(void*)f_5939},
{C_text("f_5949:chicken_2dsyntax_2escm"),(void*)f_5949},
{C_text("f_5952:chicken_2dsyntax_2escm"),(void*)f_5952},
{C_text("f_5958:chicken_2dsyntax_2escm"),(void*)f_5958},
{C_text("f_5969:chicken_2dsyntax_2escm"),(void*)f_5969},
{C_text("f_5985:chicken_2dsyntax_2escm"),(void*)f_5985},
{C_text("f_5995:chicken_2dsyntax_2escm"),(void*)f_5995},
{C_text("f_6018:chicken_2dsyntax_2escm"),(void*)f_6018},
{C_text("f_6021:chicken_2dsyntax_2escm"),(void*)f_6021},
{C_text("f_6038:chicken_2dsyntax_2escm"),(void*)f_6038},
{C_text("f_6044:chicken_2dsyntax_2escm"),(void*)f_6044},
{C_text("f_6061:chicken_2dsyntax_2escm"),(void*)f_6061},
{C_text("f_6084:chicken_2dsyntax_2escm"),(void*)f_6084},
{C_text("f_6112:chicken_2dsyntax_2escm"),(void*)f_6112},
{C_text("f_6114:chicken_2dsyntax_2escm"),(void*)f_6114},
{C_text("f_6118:chicken_2dsyntax_2escm"),(void*)f_6118},
{C_text("f_6121:chicken_2dsyntax_2escm"),(void*)f_6121},
{C_text("f_6124:chicken_2dsyntax_2escm"),(void*)f_6124},
{C_text("f_6127:chicken_2dsyntax_2escm"),(void*)f_6127},
{C_text("f_6134:chicken_2dsyntax_2escm"),(void*)f_6134},
{C_text("f_6144:chicken_2dsyntax_2escm"),(void*)f_6144},
{C_text("f_6147:chicken_2dsyntax_2escm"),(void*)f_6147},
{C_text("f_6153:chicken_2dsyntax_2escm"),(void*)f_6153},
{C_text("f_6160:chicken_2dsyntax_2escm"),(void*)f_6160},
{C_text("f_6176:chicken_2dsyntax_2escm"),(void*)f_6176},
{C_text("f_6186:chicken_2dsyntax_2escm"),(void*)f_6186},
{C_text("f_6209:chicken_2dsyntax_2escm"),(void*)f_6209},
{C_text("f_6212:chicken_2dsyntax_2escm"),(void*)f_6212},
{C_text("f_6229:chicken_2dsyntax_2escm"),(void*)f_6229},
{C_text("f_6235:chicken_2dsyntax_2escm"),(void*)f_6235},
{C_text("f_6284:chicken_2dsyntax_2escm"),(void*)f_6284},
{C_text("f_6286:chicken_2dsyntax_2escm"),(void*)f_6286},
{C_text("f_6290:chicken_2dsyntax_2escm"),(void*)f_6290},
{C_text("f_6296:chicken_2dsyntax_2escm"),(void*)f_6296},
{C_text("f_6299:chicken_2dsyntax_2escm"),(void*)f_6299},
{C_text("f_6311:chicken_2dsyntax_2escm"),(void*)f_6311},
{C_text("f_6314:chicken_2dsyntax_2escm"),(void*)f_6314},
{C_text("f_6320:chicken_2dsyntax_2escm"),(void*)f_6320},
{C_text("f_6323:chicken_2dsyntax_2escm"),(void*)f_6323},
{C_text("f_6332:chicken_2dsyntax_2escm"),(void*)f_6332},
{C_text("f_6333:chicken_2dsyntax_2escm"),(void*)f_6333},
{C_text("f_6349:chicken_2dsyntax_2escm"),(void*)f_6349},
{C_text("f_6380:chicken_2dsyntax_2escm"),(void*)f_6380},
{C_text("f_6382:chicken_2dsyntax_2escm"),(void*)f_6382},
{C_text("f_6401:chicken_2dsyntax_2escm"),(void*)f_6401},
{C_text("f_6407:chicken_2dsyntax_2escm"),(void*)f_6407},
{C_text("f_6414:chicken_2dsyntax_2escm"),(void*)f_6414},
{C_text("f_6418:chicken_2dsyntax_2escm"),(void*)f_6418},
{C_text("f_6422:chicken_2dsyntax_2escm"),(void*)f_6422},
{C_text("f_6426:chicken_2dsyntax_2escm"),(void*)f_6426},
{C_text("f_6454:chicken_2dsyntax_2escm"),(void*)f_6454},
{C_text("f_6475:chicken_2dsyntax_2escm"),(void*)f_6475},
{C_text("f_6554:chicken_2dsyntax_2escm"),(void*)f_6554},
{C_text("f_6597:chicken_2dsyntax_2escm"),(void*)f_6597},
{C_text("f_6610:chicken_2dsyntax_2escm"),(void*)f_6610},
{C_text("f_6612:chicken_2dsyntax_2escm"),(void*)f_6612},
{C_text("f_6650:chicken_2dsyntax_2escm"),(void*)f_6650},
{C_text("f_6660:chicken_2dsyntax_2escm"),(void*)f_6660},
{C_text("f_6673:chicken_2dsyntax_2escm"),(void*)f_6673},
{C_text("f_6708:chicken_2dsyntax_2escm"),(void*)f_6708},
{C_text("f_6715:chicken_2dsyntax_2escm"),(void*)f_6715},
{C_text("f_6719:chicken_2dsyntax_2escm"),(void*)f_6719},
{C_text("f_6723:chicken_2dsyntax_2escm"),(void*)f_6723},
{C_text("f_6725:chicken_2dsyntax_2escm"),(void*)f_6725},
{C_text("f_6729:chicken_2dsyntax_2escm"),(void*)f_6729},
{C_text("f_6737:chicken_2dsyntax_2escm"),(void*)f_6737},
{C_text("f_6746:chicken_2dsyntax_2escm"),(void*)f_6746},
{C_text("f_6749:chicken_2dsyntax_2escm"),(void*)f_6749},
{C_text("f_6752:chicken_2dsyntax_2escm"),(void*)f_6752},
{C_text("f_6774:chicken_2dsyntax_2escm"),(void*)f_6774},
{C_text("f_6781:chicken_2dsyntax_2escm"),(void*)f_6781},
{C_text("f_6785:chicken_2dsyntax_2escm"),(void*)f_6785},
{C_text("f_6796:chicken_2dsyntax_2escm"),(void*)f_6796},
{C_text("f_6799:chicken_2dsyntax_2escm"),(void*)f_6799},
{C_text("f_6802:chicken_2dsyntax_2escm"),(void*)f_6802},
{C_text("f_6816:chicken_2dsyntax_2escm"),(void*)f_6816},
{C_text("f_6823:chicken_2dsyntax_2escm"),(void*)f_6823},
{C_text("f_6827:chicken_2dsyntax_2escm"),(void*)f_6827},
{C_text("f_6839:chicken_2dsyntax_2escm"),(void*)f_6839},
{C_text("f_6841:chicken_2dsyntax_2escm"),(void*)f_6841},
{C_text("f_6845:chicken_2dsyntax_2escm"),(void*)f_6845},
{C_text("f_6847:chicken_2dsyntax_2escm"),(void*)f_6847},
{C_text("f_6853:chicken_2dsyntax_2escm"),(void*)f_6853},
{C_text("f_6867:chicken_2dsyntax_2escm"),(void*)f_6867},
{C_text("f_6871:chicken_2dsyntax_2escm"),(void*)f_6871},
{C_text("f_6879:chicken_2dsyntax_2escm"),(void*)f_6879},
{C_text("f_6882:chicken_2dsyntax_2escm"),(void*)f_6882},
{C_text("f_6885:chicken_2dsyntax_2escm"),(void*)f_6885},
{C_text("f_6888:chicken_2dsyntax_2escm"),(void*)f_6888},
{C_text("f_6891:chicken_2dsyntax_2escm"),(void*)f_6891},
{C_text("f_6894:chicken_2dsyntax_2escm"),(void*)f_6894},
{C_text("f_6897:chicken_2dsyntax_2escm"),(void*)f_6897},
{C_text("f_6900:chicken_2dsyntax_2escm"),(void*)f_6900},
{C_text("f_6903:chicken_2dsyntax_2escm"),(void*)f_6903},
{C_text("f_6906:chicken_2dsyntax_2escm"),(void*)f_6906},
{C_text("f_6913:chicken_2dsyntax_2escm"),(void*)f_6913},
{C_text("f_6929:chicken_2dsyntax_2escm"),(void*)f_6929},
{C_text("f_6931:chicken_2dsyntax_2escm"),(void*)f_6931},
{C_text("f_6939:chicken_2dsyntax_2escm"),(void*)f_6939},
{C_text("f_6949:chicken_2dsyntax_2escm"),(void*)f_6949},
{C_text("f_6953:chicken_2dsyntax_2escm"),(void*)f_6953},
{C_text("f_6963:chicken_2dsyntax_2escm"),(void*)f_6963},
{C_text("f_6967:chicken_2dsyntax_2escm"),(void*)f_6967},
{C_text("f_6969:chicken_2dsyntax_2escm"),(void*)f_6969},
{C_text("f_6977:chicken_2dsyntax_2escm"),(void*)f_6977},
{C_text("f_6979:chicken_2dsyntax_2escm"),(void*)f_6979},
{C_text("f_6983:chicken_2dsyntax_2escm"),(void*)f_6983},
{C_text("f_7005:chicken_2dsyntax_2escm"),(void*)f_7005},
{C_text("f_7007:chicken_2dsyntax_2escm"),(void*)f_7007},
{C_text("f_7055:chicken_2dsyntax_2escm"),(void*)f_7055},
{C_text("f_7108:chicken_2dsyntax_2escm"),(void*)f_7108},
{C_text("f_7119:chicken_2dsyntax_2escm"),(void*)f_7119},
{C_text("f_7156:chicken_2dsyntax_2escm"),(void*)f_7156},
{C_text("f_7184:chicken_2dsyntax_2escm"),(void*)f_7184},
{C_text("f_7211:chicken_2dsyntax_2escm"),(void*)f_7211},
{C_text("f_7221:chicken_2dsyntax_2escm"),(void*)f_7221},
{C_text("f_7223:chicken_2dsyntax_2escm"),(void*)f_7223},
{C_text("f_7248:chicken_2dsyntax_2escm"),(void*)f_7248},
{C_text("f_7283:chicken_2dsyntax_2escm"),(void*)f_7283},
{C_text("f_7285:chicken_2dsyntax_2escm"),(void*)f_7285},
{C_text("f_7289:chicken_2dsyntax_2escm"),(void*)f_7289},
{C_text("f_7301:chicken_2dsyntax_2escm"),(void*)f_7301},
{C_text("f_7304:chicken_2dsyntax_2escm"),(void*)f_7304},
{C_text("f_7307:chicken_2dsyntax_2escm"),(void*)f_7307},
{C_text("f_7310:chicken_2dsyntax_2escm"),(void*)f_7310},
{C_text("f_7321:chicken_2dsyntax_2escm"),(void*)f_7321},
{C_text("f_7323:chicken_2dsyntax_2escm"),(void*)f_7323},
{C_text("f_7349:chicken_2dsyntax_2escm"),(void*)f_7349},
{C_text("f_7360:chicken_2dsyntax_2escm"),(void*)f_7360},
{C_text("f_7443:chicken_2dsyntax_2escm"),(void*)f_7443},
{C_text("f_7445:chicken_2dsyntax_2escm"),(void*)f_7445},
{C_text("f_7449:chicken_2dsyntax_2escm"),(void*)f_7449},
{C_text("f_7452:chicken_2dsyntax_2escm"),(void*)f_7452},
{C_text("f_7482:chicken_2dsyntax_2escm"),(void*)f_7482},
{C_text("f_7492:chicken_2dsyntax_2escm"),(void*)f_7492},
{C_text("f_7520:chicken_2dsyntax_2escm"),(void*)f_7520},
{C_text("f_7522:chicken_2dsyntax_2escm"),(void*)f_7522},
{C_text("f_7526:chicken_2dsyntax_2escm"),(void*)f_7526},
{C_text("f_7545:chicken_2dsyntax_2escm"),(void*)f_7545},
{C_text("f_7549:chicken_2dsyntax_2escm"),(void*)f_7549},
{C_text("f_7553:chicken_2dsyntax_2escm"),(void*)f_7553},
{C_text("f_7555:chicken_2dsyntax_2escm"),(void*)f_7555},
{C_text("f_7576:chicken_2dsyntax_2escm"),(void*)f_7576},
{C_text("f_7594:chicken_2dsyntax_2escm"),(void*)f_7594},
{C_text("f_7602:chicken_2dsyntax_2escm"),(void*)f_7602},
{C_text("f_7606:chicken_2dsyntax_2escm"),(void*)f_7606},
{C_text("f_7616:chicken_2dsyntax_2escm"),(void*)f_7616},
{C_text("f_7622:chicken_2dsyntax_2escm"),(void*)f_7622},
{C_text("f_7636:chicken_2dsyntax_2escm"),(void*)f_7636},
{C_text("f_7662:chicken_2dsyntax_2escm"),(void*)f_7662},
{C_text("f_7686:chicken_2dsyntax_2escm"),(void*)f_7686},
{C_text("f_7694:chicken_2dsyntax_2escm"),(void*)f_7694},
{C_text("f_7702:chicken_2dsyntax_2escm"),(void*)f_7702},
{C_text("f_7706:chicken_2dsyntax_2escm"),(void*)f_7706},
{C_text("f_7709:chicken_2dsyntax_2escm"),(void*)f_7709},
{C_text("f_7712:chicken_2dsyntax_2escm"),(void*)f_7712},
{C_text("f_7721:chicken_2dsyntax_2escm"),(void*)f_7721},
{C_text("f_7722:chicken_2dsyntax_2escm"),(void*)f_7722},
{C_text("f_7730:chicken_2dsyntax_2escm"),(void*)f_7730},
{C_text("f_7734:chicken_2dsyntax_2escm"),(void*)f_7734},
{C_text("f_7738:chicken_2dsyntax_2escm"),(void*)f_7738},
{C_text("f_7746:chicken_2dsyntax_2escm"),(void*)f_7746},
{C_text("f_7752:chicken_2dsyntax_2escm"),(void*)f_7752},
{C_text("f_7758:chicken_2dsyntax_2escm"),(void*)f_7758},
{C_text("f_7761:chicken_2dsyntax_2escm"),(void*)f_7761},
{C_text("f_7764:chicken_2dsyntax_2escm"),(void*)f_7764},
{C_text("f_7768:chicken_2dsyntax_2escm"),(void*)f_7768},
{C_text("f_7776:chicken_2dsyntax_2escm"),(void*)f_7776},
{C_text("f_7779:chicken_2dsyntax_2escm"),(void*)f_7779},
{C_text("f_7782:chicken_2dsyntax_2escm"),(void*)f_7782},
{C_text("f_7785:chicken_2dsyntax_2escm"),(void*)f_7785},
{C_text("f_7792:chicken_2dsyntax_2escm"),(void*)f_7792},
{C_text("f_7818:chicken_2dsyntax_2escm"),(void*)f_7818},
{C_text("f_7843:chicken_2dsyntax_2escm"),(void*)f_7843},
{C_text("f_7852:chicken_2dsyntax_2escm"),(void*)f_7852},
{C_text("f_7886:chicken_2dsyntax_2escm"),(void*)f_7886},
{C_text("f_7911:chicken_2dsyntax_2escm"),(void*)f_7911},
{C_text("f_7920:chicken_2dsyntax_2escm"),(void*)f_7920},
{C_text("f_7968:chicken_2dsyntax_2escm"),(void*)f_7968},
{C_text("f_7970:chicken_2dsyntax_2escm"),(void*)f_7970},
{C_text("f_7974:chicken_2dsyntax_2escm"),(void*)f_7974},
{C_text("f_7984:chicken_2dsyntax_2escm"),(void*)f_7984},
{C_text("f_8011:chicken_2dsyntax_2escm"),(void*)f_8011},
{C_text("f_8014:chicken_2dsyntax_2escm"),(void*)f_8014},
{C_text("f_8029:chicken_2dsyntax_2escm"),(void*)f_8029},
{C_text("f_8037:chicken_2dsyntax_2escm"),(void*)f_8037},
{C_text("f_8046:chicken_2dsyntax_2escm"),(void*)f_8046},
{C_text("f_8061:chicken_2dsyntax_2escm"),(void*)f_8061},
{C_text("f_8071:chicken_2dsyntax_2escm"),(void*)f_8071},
{C_text("f_8074:chicken_2dsyntax_2escm"),(void*)f_8074},
{C_text("f_8090:chicken_2dsyntax_2escm"),(void*)f_8090},
{C_text("f_8110:chicken_2dsyntax_2escm"),(void*)f_8110},
{C_text("f_8112:chicken_2dsyntax_2escm"),(void*)f_8112},
{C_text("f_8114:chicken_2dsyntax_2escm"),(void*)f_8114},
{C_text("f_8118:chicken_2dsyntax_2escm"),(void*)f_8118},
{C_text("f_8127:chicken_2dsyntax_2escm"),(void*)f_8127},
{C_text("f_8130:chicken_2dsyntax_2escm"),(void*)f_8130},
{C_text("f_8139:chicken_2dsyntax_2escm"),(void*)f_8139},
{C_text("f_8155:chicken_2dsyntax_2escm"),(void*)f_8155},
{C_text("f_8159:chicken_2dsyntax_2escm"),(void*)f_8159},
{C_text("f_8202:chicken_2dsyntax_2escm"),(void*)f_8202},
{C_text("f_8214:chicken_2dsyntax_2escm"),(void*)f_8214},
{C_text("f_8216:chicken_2dsyntax_2escm"),(void*)f_8216},
{C_text("f_8220:chicken_2dsyntax_2escm"),(void*)f_8220},
{C_text("f_8223:chicken_2dsyntax_2escm"),(void*)f_8223},
{C_text("f_8242:chicken_2dsyntax_2escm"),(void*)f_8242},
{C_text("f_8258:chicken_2dsyntax_2escm"),(void*)f_8258},
{C_text("f_8260:chicken_2dsyntax_2escm"),(void*)f_8260},
{C_text("f_8264:chicken_2dsyntax_2escm"),(void*)f_8264},
{C_text("f_8267:chicken_2dsyntax_2escm"),(void*)f_8267},
{C_text("f_8280:chicken_2dsyntax_2escm"),(void*)f_8280},
{C_text("f_8282:chicken_2dsyntax_2escm"),(void*)f_8282},
{C_text("f_8286:chicken_2dsyntax_2escm"),(void*)f_8286},
{C_text("f_8300:chicken_2dsyntax_2escm"),(void*)f_8300},
{C_text("f_8306:chicken_2dsyntax_2escm"),(void*)f_8306},
{C_text("f_8328:chicken_2dsyntax_2escm"),(void*)f_8328},
{C_text("f_8334:chicken_2dsyntax_2escm"),(void*)f_8334},
{C_text("f_8338:chicken_2dsyntax_2escm"),(void*)f_8338},
{C_text("f_8348:chicken_2dsyntax_2escm"),(void*)f_8348},
{C_text("f_8350:chicken_2dsyntax_2escm"),(void*)f_8350},
{C_text("f_8379:chicken_2dsyntax_2escm"),(void*)f_8379},
{C_text("f_8398:chicken_2dsyntax_2escm"),(void*)f_8398},
{C_text("f_8432:chicken_2dsyntax_2escm"),(void*)f_8432},
{C_text("f_8456:chicken_2dsyntax_2escm"),(void*)f_8456},
{C_text("f_8458:chicken_2dsyntax_2escm"),(void*)f_8458},
{C_text("f_8462:chicken_2dsyntax_2escm"),(void*)f_8462},
{C_text("f_8468:chicken_2dsyntax_2escm"),(void*)f_8468},
{C_text("f_8502:chicken_2dsyntax_2escm"),(void*)f_8502},
{C_text("f_8538:chicken_2dsyntax_2escm"),(void*)f_8538},
{C_text("f_8540:chicken_2dsyntax_2escm"),(void*)f_8540},
{C_text("f_8544:chicken_2dsyntax_2escm"),(void*)f_8544},
{C_text("f_8552:chicken_2dsyntax_2escm"),(void*)f_8552},
{C_text("f_8557:chicken_2dsyntax_2escm"),(void*)f_8557},
{C_text("f_8582:chicken_2dsyntax_2escm"),(void*)f_8582},
{C_text("f_8592:chicken_2dsyntax_2escm"),(void*)f_8592},
{C_text("f_8594:chicken_2dsyntax_2escm"),(void*)f_8594},
{C_text("f_8598:chicken_2dsyntax_2escm"),(void*)f_8598},
{C_text("f_8604:chicken_2dsyntax_2escm"),(void*)f_8604},
{C_text("f_8625:chicken_2dsyntax_2escm"),(void*)f_8625},
{C_text("f_8632:chicken_2dsyntax_2escm"),(void*)f_8632},
{C_text("f_8655:chicken_2dsyntax_2escm"),(void*)f_8655},
{C_text("f_8659:chicken_2dsyntax_2escm"),(void*)f_8659},
{C_text("f_8680:chicken_2dsyntax_2escm"),(void*)f_8680},
{C_text("f_8683:chicken_2dsyntax_2escm"),(void*)f_8683},
{C_text("f_8687:chicken_2dsyntax_2escm"),(void*)f_8687},
{C_text("f_8695:chicken_2dsyntax_2escm"),(void*)f_8695},
{C_text("f_8699:chicken_2dsyntax_2escm"),(void*)f_8699},
{C_text("f_8705:chicken_2dsyntax_2escm"),(void*)f_8705},
{C_text("f_8706:chicken_2dsyntax_2escm"),(void*)f_8706},
{C_text("f_8717:chicken_2dsyntax_2escm"),(void*)f_8717},
{C_text("f_8732:chicken_2dsyntax_2escm"),(void*)f_8732},
{C_text("f_8734:chicken_2dsyntax_2escm"),(void*)f_8734},
{C_text("f_8753:chicken_2dsyntax_2escm"),(void*)f_8753},
{C_text("f_8761:chicken_2dsyntax_2escm"),(void*)f_8761},
{C_text("f_8767:chicken_2dsyntax_2escm"),(void*)f_8767},
{C_text("f_8769:chicken_2dsyntax_2escm"),(void*)f_8769},
{C_text("f_8794:chicken_2dsyntax_2escm"),(void*)f_8794},
{C_text("f_8818:chicken_2dsyntax_2escm"),(void*)f_8818},
{C_text("f_8855:chicken_2dsyntax_2escm"),(void*)f_8855},
{C_text("f_8883:chicken_2dsyntax_2escm"),(void*)f_8883},
{C_text("f_8917:chicken_2dsyntax_2escm"),(void*)f_8917},
{C_text("f_8948:chicken_2dsyntax_2escm"),(void*)f_8948},
{C_text("f_8955:chicken_2dsyntax_2escm"),(void*)f_8955},
{C_text("f_8961:chicken_2dsyntax_2escm"),(void*)f_8961},
{C_text("f_8986:chicken_2dsyntax_2escm"),(void*)f_8986},
{C_text("f_8995:chicken_2dsyntax_2escm"),(void*)f_8995},
{C_text("f_9008:chicken_2dsyntax_2escm"),(void*)f_9008},
{C_text("f_9033:chicken_2dsyntax_2escm"),(void*)f_9033},
{C_text("f_9069:chicken_2dsyntax_2escm"),(void*)f_9069},
{C_text("f_9071:chicken_2dsyntax_2escm"),(void*)f_9071},
{C_text("f_9075:chicken_2dsyntax_2escm"),(void*)f_9075},
{C_text("f_9082:chicken_2dsyntax_2escm"),(void*)f_9082},
{C_text("f_9086:chicken_2dsyntax_2escm"),(void*)f_9086},
{C_text("f_9094:chicken_2dsyntax_2escm"),(void*)f_9094},
{C_text("f_9108:chicken_2dsyntax_2escm"),(void*)f_9108},
{C_text("f_9114:chicken_2dsyntax_2escm"),(void*)f_9114},
{C_text("f_9121:chicken_2dsyntax_2escm"),(void*)f_9121},
{C_text("f_9127:chicken_2dsyntax_2escm"),(void*)f_9127},
{C_text("f_9140:chicken_2dsyntax_2escm"),(void*)f_9140},
{C_text("f_9174:chicken_2dsyntax_2escm"),(void*)f_9174},
{C_text("f_9184:chicken_2dsyntax_2escm"),(void*)f_9184},
{C_text("f_9199:chicken_2dsyntax_2escm"),(void*)f_9199},
{C_text("f_9201:chicken_2dsyntax_2escm"),(void*)f_9201},
{C_text("f_9205:chicken_2dsyntax_2escm"),(void*)f_9205},
{C_text("f_9220:chicken_2dsyntax_2escm"),(void*)f_9220},
{C_text("f_9222:chicken_2dsyntax_2escm"),(void*)f_9222},
{C_text("f_9226:chicken_2dsyntax_2escm"),(void*)f_9226},
{C_text("f_9248:chicken_2dsyntax_2escm"),(void*)f_9248},
{C_text("f_9250:chicken_2dsyntax_2escm"),(void*)f_9250},
{C_text("f_9254:chicken_2dsyntax_2escm"),(void*)f_9254},
{C_text("f_9272:chicken_2dsyntax_2escm"),(void*)f_9272},
{C_text("f_9274:chicken_2dsyntax_2escm"),(void*)f_9274},
{C_text("f_9283:chicken_2dsyntax_2escm"),(void*)f_9283},
{C_text("f_9289:chicken_2dsyntax_2escm"),(void*)f_9289},
{C_text("f_9295:chicken_2dsyntax_2escm"),(void*)f_9295},
{C_text("f_9314:chicken_2dsyntax_2escm"),(void*)f_9314},
{C_text("f_9316:chicken_2dsyntax_2escm"),(void*)f_9316},
{C_text("f_9341:chicken_2dsyntax_2escm"),(void*)f_9341},
{C_text("f_9352:chicken_2dsyntax_2escm"),(void*)f_9352},
{C_text("f_9354:chicken_2dsyntax_2escm"),(void*)f_9354},
{C_text("f_9373:chicken_2dsyntax_2escm"),(void*)f_9373},
{C_text("f_9381:chicken_2dsyntax_2escm"),(void*)f_9381},
{C_text("f_9390:chicken_2dsyntax_2escm"),(void*)f_9390},
{C_text("f_9396:chicken_2dsyntax_2escm"),(void*)f_9396},
{C_text("f_9400:chicken_2dsyntax_2escm"),(void*)f_9400},
{C_text("f_9408:chicken_2dsyntax_2escm"),(void*)f_9408},
{C_text("f_9414:chicken_2dsyntax_2escm"),(void*)f_9414},
{C_text("f_9418:chicken_2dsyntax_2escm"),(void*)f_9418},
{C_text("f_9426:chicken_2dsyntax_2escm"),(void*)f_9426},
{C_text("f_9429:chicken_2dsyntax_2escm"),(void*)f_9429},
{C_text("f_9433:chicken_2dsyntax_2escm"),(void*)f_9433},
{C_text("f_9441:chicken_2dsyntax_2escm"),(void*)f_9441},
{C_text("f_9444:chicken_2dsyntax_2escm"),(void*)f_9444},
{C_text("f_9457:chicken_2dsyntax_2escm"),(void*)f_9457},
{C_text("f_9474:chicken_2dsyntax_2escm"),(void*)f_9474},
{C_text("f_9485:chicken_2dsyntax_2escm"),(void*)f_9485},
{C_text("f_9533:chicken_2dsyntax_2escm"),(void*)f_9533},
{C_text("f_9537:chicken_2dsyntax_2escm"),(void*)f_9537},
{C_text("f_9549:chicken_2dsyntax_2escm"),(void*)f_9549},
{C_text("f_9561:chicken_2dsyntax_2escm"),(void*)f_9561},
{C_text("f_9563:chicken_2dsyntax_2escm"),(void*)f_9563},
{C_text("f_9611:chicken_2dsyntax_2escm"),(void*)f_9611},
{C_text("f_9659:chicken_2dsyntax_2escm"),(void*)f_9659},
{C_text("f_9666:chicken_2dsyntax_2escm"),(void*)f_9666},
{C_text("f_9736:chicken_2dsyntax_2escm"),(void*)f_9736},
{C_text("f_9754:chicken_2dsyntax_2escm"),(void*)f_9754},
{C_text("f_9758:chicken_2dsyntax_2escm"),(void*)f_9758},
{C_text("f_9774:chicken_2dsyntax_2escm"),(void*)f_9774},
{C_text("f_9778:chicken_2dsyntax_2escm"),(void*)f_9778},
{C_text("f_9790:chicken_2dsyntax_2escm"),(void*)f_9790},
{C_text("f_9800:chicken_2dsyntax_2escm"),(void*)f_9800},
{C_text("f_9848:chicken_2dsyntax_2escm"),(void*)f_9848},
{C_text("f_9896:chicken_2dsyntax_2escm"),(void*)f_9896},
{C_text("f_9903:chicken_2dsyntax_2escm"),(void*)f_9903},
{C_text("f_9966:chicken_2dsyntax_2escm"),(void*)f_9966},
{C_text("toplevel:chicken_2dsyntax_2escm"),(void*)C_chicken_2dsyntax_toplevel},
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
S|  scheme#for-each		2
S|  ##sys#map		11
S|  chicken.base#foldl		4
S|  scheme#map		42
S|  chicken.base#foldr		4
o|eliminated procedure checks: 738 
o|specializations:
o|  1 (chicken.base#add1 *)
o|  1 (scheme#zero? integer)
o|  2 (scheme#string-append string string)
o|  14 (scheme#cddr (pair * pair))
o|  2 (scheme#length list)
o|  1 (scheme#caddr (pair * (pair * pair)))
o|  4 (scheme#cadr (pair * pair))
o|  4 (scheme#cdddr (pair * (pair * pair)))
o|  1 (scheme#eqv? * *)
o|  40 (##sys#check-list (or pair list) *)
o|  69 (scheme#cdr pair)
o|  24 (scheme#car pair)
(o e)|safe calls: 1479 
o|safe globals: (posv posq make-list iota find-tail find length+ lset=/eq? lset<=/eq? list-tabulate lset-intersection/eq? lset-union/eq? lset-difference/eq? lset-adjoin/eq? list-index last unzip1 remove filter-map filter alist-cons delete-duplicates fifth fourth third second first delete concatenate cons* any every append-map split-at drop take span partition) 
o|removed side-effect free assignment to unused variable: partition 
o|removed side-effect free assignment to unused variable: span 
o|inlining procedure: k4349 
o|inlining procedure: k4349 
o|removed side-effect free assignment to unused variable: drop 
o|removed side-effect free assignment to unused variable: append-map 
o|inlining procedure: k4619 
o|inlining procedure: k4619 
o|inlining procedure: k4650 
o|inlining procedure: k4650 
o|removed side-effect free assignment to unused variable: cons* 
o|removed side-effect free assignment to unused variable: concatenate 
o|removed side-effect free assignment to unused variable: first 
o|removed side-effect free assignment to unused variable: second 
o|removed side-effect free assignment to unused variable: third 
o|removed side-effect free assignment to unused variable: fourth 
o|removed side-effect free assignment to unused variable: fifth 
o|removed side-effect free assignment to unused variable: delete-duplicates 
o|removed side-effect free assignment to unused variable: alist-cons 
o|inlining procedure: k4867 
o|inlining procedure: k4867 
o|inlining procedure: k4859 
o|inlining procedure: k4859 
o|removed side-effect free assignment to unused variable: filter-map 
o|removed side-effect free assignment to unused variable: remove 
o|removed side-effect free assignment to unused variable: unzip1 
o|removed side-effect free assignment to unused variable: last 
o|removed side-effect free assignment to unused variable: list-index 
o|removed side-effect free assignment to unused variable: lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: lset-difference/eq? 
o|removed side-effect free assignment to unused variable: lset-union/eq? 
o|removed side-effect free assignment to unused variable: lset-intersection/eq? 
o|inlining procedure: k5258 
o|inlining procedure: k5258 
o|removed side-effect free assignment to unused variable: lset<=/eq? 
o|removed side-effect free assignment to unused variable: lset=/eq? 
o|removed side-effect free assignment to unused variable: length+ 
o|removed side-effect free assignment to unused variable: find 
o|removed side-effect free assignment to unused variable: find-tail 
o|removed side-effect free assignment to unused variable: iota 
o|removed side-effect free assignment to unused variable: make-list 
o|removed side-effect free assignment to unused variable: posq 
o|removed side-effect free assignment to unused variable: posv 
o|inlining procedure: k5790 
o|inlining procedure: k5790 
o|inlining procedure: k5818 
o|inlining procedure: k5818 
o|inlining procedure: k5862 
o|inlining procedure: k5862 
o|inlining procedure: k5941 
o|inlining procedure: k5941 
o|inlining procedure: k6039 
o|inlining procedure: k6039 
o|inlining procedure: k6136 
o|inlining procedure: k6136 
o|inlining procedure: k6230 
o|inlining procedure: k6230 
o|inlining procedure: k6335 
o|inlining procedure: k6335 
o|inlining procedure: k6384 
o|inlining procedure: k6384 
o|inlining procedure: k6431 
o|inlining procedure: k6431 
o|inlining procedure: k6470 
o|inlining procedure: k6470 
o|inlining procedure: k6543 
o|inlining procedure: k6543 
o|inlining procedure: k6599 
o|inlining procedure: k6599 
o|inlining procedure: k6614 
o|inlining procedure: k6614 
o|inlining procedure: k6652 
o|inlining procedure: k6652 
o|inlining procedure: k6675 
o|inlining procedure: k6675 
o|inlining procedure: k6738 
o|inlining procedure: k6738 
o|inlining procedure: k6855 
o|inlining procedure: k6855 
o|contracted procedure: "(chicken-syntax.scm:1016) split-at" 
o|inlining procedure: k4407 
o|inlining procedure: k4407 
o|inlining procedure: k6984 
o|inlining procedure: k6984 
o|inlining procedure: k7009 
o|inlining procedure: k7009 
o|inlining procedure: k7057 
o|inlining procedure: k7085 
o|inlining procedure: k7085 
o|inlining procedure: k7057 
o|inlining procedure: k7117 
o|inlining procedure: k7117 
o|inlining procedure: k7157 
o|inlining procedure: k7157 
o|inlining procedure: k6933 
o|inlining procedure: k6933 
o|inlining procedure: k7225 
o|contracted procedure: "(chicken-syntax.scm:986) g28592868" 
o|inlining procedure: k7225 
o|inlining procedure: k7325 
o|inlining procedure: k7325 
o|removed unused formal parameters: (rename2654) 
o|inlining procedure: k7624 
o|inlining procedure: k7624 
o|removed unused parameter to known procedure: rename2654 "(chicken-syntax.scm:888) make-if-tree2634" 
o|contracted procedure: "(chicken-syntax.scm:886) make-default-procs2633" 
o|inlining procedure: k7557 
o|inlining procedure: k7557 
o|inlining procedure: k7820 
o|inlining procedure: k7820 
o|inlining procedure: k7854 
o|inlining procedure: k7854 
o|inlining procedure: k7888 
o|inlining procedure: k7888 
o|inlining procedure: k7922 
o|inlining procedure: k7922 
o|inlining procedure: k7986 
o|inlining procedure: k7986 
o|inlining procedure: k8038 
o|inlining procedure: k8038 
o|inlining procedure: k8128 
o|inlining procedure: k8128 
o|inlining procedure: k8143 
o|inlining procedure: k8143 
o|inlining procedure: k8352 
o|inlining procedure: k8352 
o|inlining procedure: k8400 
o|contracted procedure: "(chicken-syntax.scm:665) g24762485" 
o|inlining procedure: k8400 
o|inlining procedure: k8434 
o|contracted procedure: "(chicken-syntax.scm:666) g25002501" 
o|inlining procedure: k8434 
o|substituted constant variable: g24922495 
o|inlining procedure: k8470 
o|inlining procedure: k8470 
o|inlining procedure: k8504 
o|inlining procedure: k8504 
o|inlining procedure: k8559 
o|inlining procedure: k8559 
o|inlining procedure: k8606 
o|inlining procedure: k8606 
o|inlining procedure: k8634 
o|inlining procedure: k8634 
o|inlining procedure: k8736 
o|inlining procedure: k8771 
o|inlining procedure: k8771 
o|inlining procedure: k8736 
o|inlining procedure: k8885 
o|contracted procedure: "(chicken-syntax.scm:623) g23682377" 
o|inlining procedure: k8885 
o|inlining procedure: k8919 
o|inlining procedure: k8919 
o|inlining procedure: k8963 
o|inlining procedure: k8963 
o|inlining procedure: k8997 
o|inlining procedure: k8997 
o|inlining procedure: k9020 
o|inlining procedure: k9020 
o|inlining procedure: k9035 
o|inlining procedure: k9035 
o|inlining procedure: k9142 
o|contracted procedure: "(chicken-syntax.scm:582) g21832201" 
o|inlining procedure: k9142 
o|inlining procedure: k9176 
o|contracted procedure: "(chicken-syntax.scm:578) g21682190" 
o|inlining procedure: k9176 
o|inlining procedure: k9297 
o|inlining procedure: k9297 
o|inlining procedure: k9318 
o|inlining procedure: k9318 
o|contracted procedure: "(chicken-syntax.scm:491) pname1609" 
o|inlining procedure: k9359 
o|inlining procedure: k9359 
o|removed unused formal parameters: (z1716) 
o|removed unused formal parameters: (z1744) 
o|inlining procedure: k9565 
o|contracted procedure: "(chicken-syntax.scm:528) g20482058" 
o|inlining procedure: k9565 
o|inlining procedure: k9613 
o|contracted procedure: "(chicken-syntax.scm:526) g20122022" 
o|inlining procedure: k9613 
o|inlining procedure: k9661 
o|contracted procedure: "(chicken-syntax.scm:523) g19701981" 
o|inlining procedure: k9661 
o|inlining procedure: k9711 
o|inlining procedure: k9711 
o|inlining procedure: k9802 
o|contracted procedure: "(chicken-syntax.scm:516) g19341944" 
o|inlining procedure: k9802 
o|inlining procedure: k9850 
o|contracted procedure: "(chicken-syntax.scm:513) g18981908" 
o|inlining procedure: k9850 
o|inlining procedure: k9898 
o|inlining procedure: k9898 
o|inlining procedure: k9948 
o|inlining procedure: k9948 
o|inlining procedure: k9968 
o|inlining procedure: k9968 
o|inlining procedure: k10016 
o|inlining procedure: k10016 
o|inlining procedure: k10064 
o|inlining procedure: k10064 
o|inlining procedure: k10112 
o|removed unused parameter to known procedure: z1744 "(chicken-syntax.scm:493) g17331742" 
o|inlining procedure: k10112 
o|inlining procedure: k10146 
o|removed unused parameter to known procedure: z1716 "(chicken-syntax.scm:492) g17051714" 
o|inlining procedure: k10146 
o|inlining procedure: k10180 
o|inlining procedure: k10180 
o|inlining procedure: k10214 
o|inlining procedure: k10214 
o|inlining procedure: k10248 
o|inlining procedure: k10248 
o|removed unused formal parameters: (x1331) 
o|removed unused formal parameters: (x1359) 
o|inlining procedure: k10403 
o|contracted procedure: "(chicken-syntax.scm:473) g15771587" 
o|inlining procedure: k10403 
o|inlining procedure: k10451 
o|contracted procedure: "(chicken-syntax.scm:471) g15411551" 
o|inlining procedure: k10451 
o|inlining procedure: k10550 
o|contracted procedure: "(chicken-syntax.scm:466) g15051515" 
o|inlining procedure: k10550 
o|inlining procedure: k10598 
o|contracted procedure: "(chicken-syntax.scm:464) g14691479" 
o|inlining procedure: k10598 
o|inlining procedure: k10681 
o|inlining procedure: k10681 
o|inlining procedure: k10731 
o|inlining procedure: k10731 
o|inlining procedure: k10751 
o|inlining procedure: k10751 
o|inlining procedure: k10799 
o|inlining procedure: k10799 
o|inlining procedure: k10833 
o|removed unused parameter to known procedure: x1359 "(chicken-syntax.scm:454) g13481357" 
o|inlining procedure: k10833 
o|inlining procedure: k10867 
o|removed unused parameter to known procedure: x1331 "(chicken-syntax.scm:453) g13201329" 
o|inlining procedure: k10867 
o|inlining procedure: k10901 
o|inlining procedure: k10901 
o|inlining procedure: k11011 
o|inlining procedure: k11011 
o|inlining procedure: k11133 
o|inlining procedure: k11133 
o|inlining procedure: k11154 
o|inlining procedure: k11166 
o|inlining procedure: k11166 
o|inlining procedure: k11154 
o|inlining procedure: k11226 
o|inlining procedure: k11226 
o|inlining procedure: k11286 
o|inlining procedure: k11286 
o|inlining procedure: k11375 
o|inlining procedure: k11375 
o|substituted constant variable: a11410 
o|substituted constant variable: a11435 
o|inlining procedure: k11444 
o|inlining procedure: k11444 
o|inlining procedure: k11516 
o|inlining procedure: k11516 
o|inlining procedure: k11545 
o|inlining procedure: k11560 
o|inlining procedure: k11576 
o|inlining procedure: k11576 
o|inlining procedure: k11560 
o|inlining procedure: k11545 
o|inlining procedure: k11610 
o|inlining procedure: k11626 
o|inlining procedure: k11626 
o|inlining procedure: k11610 
o|inlining procedure: k11664 
o|inlining procedure: k11664 
o|inlining procedure: k11728 
o|inlining procedure: k11728 
o|inlining procedure: k11837 
o|inlining procedure: k11837 
o|inlining procedure: k11950 
o|inlining procedure: k11950 
o|inlining procedure: k11971 
o|inlining procedure: k11971 
o|inlining procedure: k12017 
o|inlining procedure: k12017 
o|inlining procedure: k12051 
o|inlining procedure: k12108 
o|contracted procedure: "(chicken-syntax.scm:198) g931941" 
o|inlining procedure: k12108 
o|inlining procedure: k12166 
o|inlining procedure: k12193 
o|contracted procedure: "(chicken-syntax.scm:190) g897906" 
o|propagated global variable: g914915 chicken.compiler.scrutinizer#check-and-validate-type 
o|inlining procedure: k12193 
o|inlining procedure: k12166 
o|inlining procedure: k12237 
o|inlining procedure: k12237 
o|inlining procedure: k12051 
o|inlining procedure: k12284 
o|inlining procedure: k12284 
o|inlining procedure: k12321 
o|inlining procedure: k12321 
o|inlining procedure: k12370 
o|inlining procedure: k12461 
o|contracted procedure: "(chicken-syntax.scm:155) g830839" 
o|inlining procedure: k12461 
o|inlining procedure: k12495 
o|contracted procedure: "(chicken-syntax.scm:155) g802811" 
o|inlining procedure: k12495 
o|inlining procedure: k12370 
o|inlining procedure: k12532 
o|inlining procedure: k12547 
o|inlining procedure: k12563 
o|inlining procedure: k12563 
o|inlining procedure: k12547 
o|inlining procedure: k12532 
o|inlining procedure: k12597 
o|inlining procedure: k12613 
o|inlining procedure: k12613 
o|inlining procedure: k12648 
o|inlining procedure: k12648 
o|inlining procedure: k12597 
o|inlining procedure: k12679 
o|inlining procedure: k12679 
o|inlining procedure: k12717 
o|inlining procedure: k12717 
o|inlining procedure: k12744 
o|inlining procedure: k12744 
o|inlining procedure: k12773 
o|inlining procedure: k12773 
o|inlining procedure: k12855 
o|inlining procedure: k12855 
o|inlining procedure: k12897 
o|inlining procedure: k12897 
o|inlining procedure: k13012 
o|inlining procedure: k13012 
o|inlining procedure: k13032 
o|inlining procedure: k13032 
o|replaced variables: 2095 
o|removed binding forms: 479 
o|substituted constant variable: r435013194 
o|removed side-effect free assignment to unused variable: every 
o|removed side-effect free assignment to unused variable: any 
o|removed side-effect free assignment to unused variable: filter 
o|removed side-effect free assignment to unused variable: list-tabulate 
o|substituted constant variable: r581913211 
o|substituted constant variable: r638513224 
o|substituted constant variable: r654413233 
o|substituted constant variable: r660013235 
o|substituted constant variable: r685613244 
o|substituted constant variable: r715813260 
o|substituted constant variable: r693413263 
o|converted assignments to bindings: (genvars2845) 
o|substituted constant variable: r755813270 
o|converted assignments to bindings: (make-if-tree2634) 
o|substituted constant variable: r814413295 
o|substituted constant variable: r863513310 
o|substituted constant variable: r929813332 
o|substituted constant variable: r971213345 
o|substituted constant variable: r994913353 
o|substituted constant variable: r1073213380 
o|substituted constant variable: r1116713398 
o|substituted constant variable: r1115513399 
o|substituted constant variable: r1156113418 
o|substituted constant variable: r1154613419 
o|substituted constant variable: r1161113423 
o|substituted constant variable: r1172913427 
o|substituted constant variable: r1183813428 
o|substituted constant variable: r1201813434 
o|substituted constant variable: r1223813445 
o|substituted constant variable: r1232213451 
o|substituted constant variable: r1254813462 
o|substituted constant variable: r1253313463 
o|substituted constant variable: r1264913468 
o|substituted constant variable: r1259813469 
o|substituted constant variable: r1271813472 
o|substituted constant variable: r1277413478 
o|substituted constant variable: r1277413478 
o|substituted constant variable: r1301313484 
o|substituted constant variable: r1301313484 
o|converted assignments to bindings: (parse-clause611) 
o|simplifications: ((let . 3)) 
o|replaced variables: 77 
o|removed binding forms: 1831 
o|removed call to pure procedure with unused result: "(chicken-syntax.scm:523) ##sys#slot" 
o|removed call to pure procedure with unused result: "(chicken-syntax.scm:493) ##sys#slot" 
o|removed call to pure procedure with unused result: "(chicken-syntax.scm:492) ##sys#slot" 
o|removed call to pure procedure with unused result: "(chicken-syntax.scm:454) ##sys#slot" 
o|removed call to pure procedure with unused result: "(chicken-syntax.scm:453) ##sys#slot" 
o|removed binding forms: 112 
o|contracted procedure: k9698 
o|contracted procedure: k10137 
o|contracted procedure: k10171 
o|contracted procedure: k10858 
o|contracted procedure: k10892 
o|removed binding forms: 5 
o|removed binding forms: 5 
o|simplifications: ((let . 32) (if . 31) (##core#call . 1224)) 
o|  call simplifications:
o|    scheme#cdddr	2
o|    chicken.fixnum#fx=
o|    scheme#vector
o|    ##sys#pair?	7
o|    ##sys#eq?	7
o|    ##sys#car	15
o|    ##sys#cdr	22
o|    scheme#symbol?	7
o|    scheme#list?	2
o|    scheme#cdar
o|    scheme#caar
o|    scheme#assq	2
o|    scheme#apply
o|    scheme#eq?	5
o|    ##sys#call-with-values	3
o|    scheme#values
o|    chicken.fixnum#fx>=
o|    chicken.fixnum#fx+	3
o|    scheme#cadddr	2
o|    scheme#cddddr
o|    ##sys#check-list	37
o|    ##sys#setslot	50
o|    ##sys#slot	196
o|    scheme#cddr	7
o|    scheme#caddr	14
o|    scheme#not	15
o|    scheme#memq	7
o|    scheme#list	8
o|    scheme#cadr	48
o|    scheme#null?	29
o|    scheme#string?
o|    scheme#pair?	96
o|    scheme#cdr	19
o|    ##sys#cons	141
o|    ##sys#list	292
o|    chicken.fixnum#fx<=	2
o|    scheme#car	45
o|    chicken.fixnum#fx-	4
o|    scheme#cons	128
o|contracted procedure: k4352 
o|contracted procedure: k4359 
o|contracted procedure: k4369 
o|contracted procedure: k5707 
o|contracted procedure: k5739 
o|contracted procedure: k5735 
o|contracted procedure: k5715 
o|contracted procedure: k5731 
o|contracted procedure: k5723 
o|contracted procedure: k5727 
o|contracted procedure: k5719 
o|contracted procedure: k5711 
o|contracted procedure: k5752 
o|contracted procedure: k5825 
o|contracted procedure: k5757 
o|contracted procedure: k5809 
o|contracted procedure: k5770 
o|contracted procedure: k5778 
o|contracted procedure: k5782 
o|contracted procedure: k5774 
o|contracted procedure: k5793 
o|contracted procedure: k5801 
o|contracted procedure: k5790 
o|contracted procedure: k5812 
o|contracted procedure: k5846 
o|contracted procedure: k5859 
o|contracted procedure: k5865 
o|contracted procedure: k5888 
o|contracted procedure: k5884 
o|contracted procedure: k5878 
o|contracted procedure: k5872 
o|contracted procedure: k5904 
o|contracted procedure: k5900 
o|contracted procedure: k6102 
o|contracted procedure: k5911 
o|contracted procedure: k5944 
o|contracted procedure: k5979 
o|contracted procedure: k5975 
o|contracted procedure: k5971 
o|contracted procedure: k5963 
o|contracted procedure: k5989 
o|contracted procedure: k6008 
o|contracted procedure: k6004 
o|contracted procedure: k6000 
o|contracted procedure: k6028 
o|contracted procedure: k6032 
o|contracted procedure: k6048 
o|contracted procedure: k6076 
o|contracted procedure: k6068 
o|contracted procedure: k6072 
o|contracted procedure: k6088 
o|contracted procedure: k6098 
o|contracted procedure: k6091 
o|contracted procedure: k6278 
o|contracted procedure: k6106 
o|contracted procedure: k6139 
o|contracted procedure: k6170 
o|contracted procedure: k6166 
o|contracted procedure: k6162 
o|contracted procedure: k6180 
o|contracted procedure: k6201 
o|contracted procedure: k6195 
o|contracted procedure: k6191 
o|contracted procedure: k6219 
o|contracted procedure: k6223 
o|contracted procedure: k6239 
o|contracted procedure: k6256 
o|contracted procedure: k6264 
o|contracted procedure: k6274 
o|contracted procedure: k6267 
o|contracted procedure: k6291 
o|contracted procedure: k6300 
o|contracted procedure: k6303 
o|contracted procedure: k6306 
o|contracted procedure: k6315 
o|contracted procedure: k6324 
o|contracted procedure: k6327 
o|contracted procedure: k6338 
o|contracted procedure: k6344 
o|contracted procedure: k6646 
o|contracted procedure: k6358 
o|contracted procedure: k6590 
o|contracted procedure: k6594 
o|contracted procedure: k6602 
o|contracted procedure: k6605 
o|contracted procedure: k6586 
o|contracted procedure: k6582 
o|contracted procedure: k6366 
o|contracted procedure: k6570 
o|contracted procedure: k6578 
o|contracted procedure: k6574 
o|contracted procedure: k6374 
o|contracted procedure: k6370 
o|contracted procedure: k6362 
o|contracted procedure: k6354 
o|contracted procedure: k6387 
o|contracted procedure: k6390 
o|contracted procedure: k6566 
o|contracted procedure: k6393 
o|contracted procedure: k6396 
o|contracted procedure: k6513 
o|contracted procedure: k6529 
o|contracted procedure: k6537 
o|contracted procedure: k6533 
o|contracted procedure: k6525 
o|contracted procedure: k6517 
o|contracted procedure: k6521 
o|contracted procedure: k6402 
o|contracted procedure: k6437 
o|contracted procedure: k6448 
o|contracted procedure: k6444 
o|contracted procedure: k6456 
o|contracted procedure: k6463 
o|contracted procedure: k6470 
o|contracted procedure: k6489 
o|contracted procedure: k6505 
o|contracted procedure: k6509 
o|contracted procedure: k6501 
o|contracted procedure: k6493 
o|contracted procedure: k6497 
o|contracted procedure: k6540 
o|contracted procedure: k6546 
o|contracted procedure: k6617 
o|contracted procedure: k6620 
o|contracted procedure: k6623 
o|contracted procedure: k6631 
o|contracted procedure: k6639 
o|contracted procedure: k6655 
o|contracted procedure: k6665 
o|contracted procedure: k6669 
o|contracted procedure: k6678 
o|contracted procedure: k6700 
o|contracted procedure: k6696 
o|contracted procedure: k6681 
o|contracted procedure: k6684 
o|contracted procedure: k6692 
o|contracted procedure: k6730 
o|contracted procedure: k6741 
o|contracted procedure: k6757 
o|contracted procedure: k6769 
o|contracted procedure: k6765 
o|contracted procedure: k6761 
o|contracted procedure: k6787 
o|contracted procedure: k6791 
o|contracted procedure: k6811 
o|contracted procedure: k6807 
o|contracted procedure: k6829 
o|contracted procedure: k7257 
o|contracted procedure: k7261 
o|contracted procedure: k7265 
o|contracted procedure: k7269 
o|contracted procedure: k7273 
o|contracted procedure: k6833 
o|contracted procedure: k6858 
o|contracted procedure: k6873 
o|contracted procedure: k7194 
o|contracted procedure: k7190 
o|contracted procedure: k6919 
o|contracted procedure: k6924 
o|contracted procedure: k6915 
o|contracted procedure: k6936 
o|contracted procedure: k6945 
o|contracted procedure: k6958 
o|contracted procedure: k4410 
o|contracted procedure: k4424 
o|contracted procedure: k4434 
o|contracted procedure: k4428 
o|contracted procedure: k6987 
o|contracted procedure: k6994 
o|contracted procedure: k6997 
o|contracted procedure: k7000 
o|contracted procedure: k7048 
o|contracted procedure: k7012 
o|contracted procedure: k7038 
o|contracted procedure: k7042 
o|contracted procedure: k7034 
o|contracted procedure: k7015 
o|contracted procedure: k7018 
o|contracted procedure: k7026 
o|contracted procedure: k7030 
o|contracted procedure: k7060 
o|contracted procedure: k7082 
o|contracted procedure: k7074 
o|contracted procedure: k7078 
o|contracted procedure: k7070 
o|contracted procedure: k7103 
o|contracted procedure: k7088 
o|contracted procedure: k7097 
o|contracted procedure: k7146 
o|contracted procedure: k7150 
o|contracted procedure: k7134 
o|contracted procedure: k7142 
o|contracted procedure: k7138 
o|contracted procedure: k7113 
o|contracted procedure: k7120 
o|contracted procedure: k7160 
o|contracted procedure: k7171 
o|contracted procedure: k7178 
o|contracted procedure: k7186 
o|contracted procedure: k7198 
o|contracted procedure: k7213 
o|contracted procedure: k7216 
o|contracted procedure: k7228 
o|contracted procedure: k7231 
o|contracted procedure: k7234 
o|contracted procedure: k7242 
o|contracted procedure: k7250 
o|contracted procedure: k7207 
o|contracted procedure: k7425 
o|contracted procedure: k7429 
o|contracted procedure: k7433 
o|contracted procedure: k7277 
o|contracted procedure: k7290 
o|contracted procedure: k7293 
o|contracted procedure: k7421 
o|contracted procedure: k7315 
o|contracted procedure: k7328 
o|contracted procedure: k7335 
o|contracted procedure: k7338 
o|contracted procedure: k7344 
o|contracted procedure: k7394 
o|contracted procedure: k7398 
o|contracted procedure: k7402 
o|contracted procedure: k7390 
o|contracted procedure: k7364 
o|contracted procedure: k7376 
o|contracted procedure: k7380 
o|contracted procedure: k7384 
o|contracted procedure: k7372 
o|contracted procedure: k7368 
o|contracted procedure: k7354 
o|contracted procedure: k7417 
o|contracted procedure: k7413 
o|contracted procedure: k7409 
o|contracted procedure: k7502 
o|contracted procedure: k7506 
o|contracted procedure: k7510 
o|contracted procedure: k7437 
o|contracted procedure: k7498 
o|contracted procedure: k7494 
o|contracted procedure: k7457 
o|contracted procedure: k7465 
o|contracted procedure: k7469 
o|contracted procedure: k7483 
o|contracted procedure: k7472 
o|contracted procedure: k7476 
o|contracted procedure: k7461 
o|contracted procedure: k7954 
o|contracted procedure: k7958 
o|contracted procedure: k7962 
o|contracted procedure: k7514 
o|contracted procedure: k7527 
o|contracted procedure: k7530 
o|contracted procedure: k7627 
o|contracted procedure: k7637 
o|contracted procedure: k7644 
o|contracted procedure: k7696 
o|contracted procedure: k7648 
o|contracted procedure: k7688 
o|contracted procedure: k7672 
o|contracted procedure: k7680 
o|contracted procedure: k7676 
o|contracted procedure: k7656 
o|contracted procedure: k7652 
o|contracted procedure: k7668 
o|contracted procedure: k7713 
o|contracted procedure: k7716 
o|contracted procedure: k7735 
o|contracted procedure: k7747 
o|contracted procedure: k7753 
o|contracted procedure: k7765 
o|contracted procedure: k7798 
o|contracted procedure: k7814 
o|contracted procedure: k7810 
o|contracted procedure: k7806 
o|contracted procedure: k7802 
o|contracted procedure: k7794 
o|contracted procedure: k7560 
o|contracted procedure: k7563 
o|contracted procedure: k7584 
o|contracted procedure: k7596 
o|contracted procedure: k7588 
o|contracted procedure: k7570 
o|contracted procedure: k7612 
o|contracted procedure: k7608 
o|contracted procedure: k7823 
o|contracted procedure: k7826 
o|contracted procedure: k7829 
o|contracted procedure: k7837 
o|contracted procedure: k7845 
o|contracted procedure: k7857 
o|contracted procedure: k7879 
o|contracted procedure: k7875 
o|contracted procedure: k7860 
o|contracted procedure: k7863 
o|contracted procedure: k7871 
o|contracted procedure: k7891 
o|contracted procedure: k7894 
o|contracted procedure: k7897 
o|contracted procedure: k7905 
o|contracted procedure: k7913 
o|contracted procedure: k7925 
o|contracted procedure: k7947 
o|contracted procedure: k7943 
o|contracted procedure: k7928 
o|contracted procedure: k7931 
o|contracted procedure: k7939 
o|contracted procedure: k7975 
o|contracted procedure: k7989 
o|contracted procedure: k7996 
o|contracted procedure: k7999 
o|contracted procedure: k8104 
o|contracted procedure: k8006 
o|contracted procedure: k8031 
o|contracted procedure: k8019 
o|contracted procedure: k8023 
o|contracted procedure: k8100 
o|contracted procedure: k8041 
o|contracted procedure: k8063 
o|contracted procedure: k8051 
o|contracted procedure: k8055 
o|contracted procedure: k8096 
o|contracted procedure: k8092 
o|contracted procedure: k8080 
o|contracted procedure: k8084 
o|contracted procedure: k8119 
o|contracted procedure: k8191 
o|contracted procedure: k8122 
o|contracted procedure: k8171 
o|contracted procedure: k8134 
o|contracted procedure: k8167 
o|contracted procedure: k8163 
o|contracted procedure: k8146 
o|contracted procedure: k8174 
o|contracted procedure: k8181 
o|contracted procedure: k8204 
o|contracted procedure: k8252 
o|contracted procedure: k8208 
o|contracted procedure: k8248 
o|contracted procedure: k8228 
o|contracted procedure: k8244 
o|contracted procedure: k8236 
o|contracted procedure: k8232 
o|contracted procedure: k8274 
o|contracted procedure: k8287 
o|contracted procedure: k8292 
o|contracted procedure: k8295 
o|contracted procedure: k8301 
o|contracted procedure: k8315 
o|contracted procedure: k8323 
o|contracted procedure: k8329 
o|contracted procedure: k8311 
o|contracted procedure: k8340 
o|contracted procedure: k8343 
o|contracted procedure: k8391 
o|contracted procedure: k8355 
o|contracted procedure: k8358 
o|contracted procedure: k8361 
o|contracted procedure: k8369 
o|contracted procedure: k8373 
o|contracted procedure: k8381 
o|contracted procedure: k8385 
o|contracted procedure: k8403 
o|contracted procedure: k8425 
o|contracted procedure: k8421 
o|contracted procedure: k8406 
o|contracted procedure: k8409 
o|contracted procedure: k8417 
o|contracted procedure: k8437 
o|contracted procedure: k8444 
o|contracted procedure: k8464 
o|contracted procedure: k8473 
o|contracted procedure: k8495 
o|contracted procedure: k8491 
o|contracted procedure: k8476 
o|contracted procedure: k8479 
o|contracted procedure: k8487 
o|contracted procedure: k8507 
o|contracted procedure: k8529 
o|contracted procedure: k8525 
o|contracted procedure: k8510 
o|contracted procedure: k8513 
o|contracted procedure: k8521 
o|contracted procedure: k8545 
o|contracted procedure: k8562 
o|contracted procedure: k8569 
o|contracted procedure: k8586 
o|contracted procedure: k8576 
o|contracted procedure: k8599 
o|contracted procedure: k8629 
o|contracted procedure: k8609 
o|contracted procedure: k8619 
o|contracted procedure: k8637 
o|contracted procedure: k8667 
o|contracted procedure: k8643 
o|contracted procedure: k8663 
o|contracted procedure: k8672 
o|contracted procedure: k8675 
o|contracted procedure: k8684 
o|contracted procedure: k8700 
o|contracted procedure: k8712 
o|contracted procedure: k8722 
o|contracted procedure: k8739 
o|contracted procedure: k8750 
o|contracted procedure: k8762 
o|contracted procedure: k8746 
o|contracted procedure: k8774 
o|contracted procedure: k8777 
o|contracted procedure: k8780 
o|contracted procedure: k8788 
o|contracted procedure: k8796 
o|contracted procedure: k8832 
o|contracted procedure: k8836 
o|contracted procedure: k8828 
o|contracted procedure: k8812 
o|contracted procedure: k8820 
o|contracted procedure: k8865 
o|contracted procedure: k8843 
o|contracted procedure: k8847 
o|contracted procedure: k8857 
o|contracted procedure: k8879 
o|contracted procedure: k8868 
o|contracted procedure: k8875 
o|contracted procedure: k8888 
o|contracted procedure: k8910 
o|contracted procedure: k8906 
o|contracted procedure: k8891 
o|contracted procedure: k8894 
o|contracted procedure: k8902 
o|contracted procedure: k8922 
o|contracted procedure: k8928 
o|contracted procedure: k8957 
o|contracted procedure: k8939 
o|inlining procedure: k8931 
o|inlining procedure: k8931 
o|contracted procedure: k8966 
o|contracted procedure: k8969 
o|contracted procedure: k8972 
o|contracted procedure: k8980 
o|contracted procedure: k8988 
o|contracted procedure: k9000 
o|contracted procedure: k9003 
o|contracted procedure: k9014 
o|contracted procedure: k9023 
o|inlining procedure: k9006 
o|contracted procedure: k9038 
o|contracted procedure: k9060 
o|contracted procedure: k9056 
o|contracted procedure: k9041 
o|contracted procedure: k9044 
o|contracted procedure: k9052 
o|contracted procedure: k9088 
o|contracted procedure: k9096 
o|contracted procedure: k9100 
o|contracted procedure: k9104 
o|contracted procedure: k9122 
o|contracted procedure: k9128 
o|contracted procedure: k9145 
o|contracted procedure: k9167 
o|contracted procedure: k9163 
o|contracted procedure: k9148 
o|contracted procedure: k9151 
o|contracted procedure: k9159 
o|contracted procedure: k9179 
o|contracted procedure: k9189 
o|contracted procedure: k9193 
o|contracted procedure: k9210 
o|contracted procedure: k9214 
o|contracted procedure: k9231 
o|contracted procedure: k9235 
o|contracted procedure: k9239 
o|contracted procedure: k9259 
o|contracted procedure: k9263 
o|contracted procedure: k9280 
o|contracted procedure: k9300 
o|contracted procedure: k9306 
o|contracted procedure: k9309 
o|contracted procedure: k9321 
o|contracted procedure: k9324 
o|contracted procedure: k9327 
o|contracted procedure: k9335 
o|contracted procedure: k9343 
o|contracted procedure: k9374 
o|contracted procedure: k9382 
o|contracted procedure: k9385 
o|contracted procedure: k9391 
o|contracted procedure: k9397 
o|contracted procedure: k9362 
o|contracted procedure: k9409 
o|contracted procedure: k9415 
o|contracted procedure: k9430 
o|contracted procedure: k9449 
o|contracted procedure: k9452 
o|contracted procedure: k9463 
o|contracted procedure: k9466 
o|contracted procedure: k9469 
o|contracted procedure: k9480 
o|contracted procedure: k9962 
o|contracted procedure: k9958 
o|contracted procedure: k9491 
o|contracted procedure: k9733 
o|contracted procedure: k9746 
o|contracted procedure: k9742 
o|contracted procedure: k9749 
o|contracted procedure: k9729 
o|contracted procedure: k9725 
o|contracted procedure: k9499 
o|contracted procedure: k9721 
o|contracted procedure: k9503 
o|contracted procedure: k9519 
o|contracted procedure: k9515 
o|contracted procedure: k9511 
o|contracted procedure: k9507 
o|contracted procedure: k9495 
o|contracted procedure: k9487 
o|contracted procedure: k9476 
o|contracted procedure: k9459 
o|contracted procedure: k9539 
o|contracted procedure: k9551 
o|contracted procedure: k9604 
o|contracted procedure: k9568 
o|contracted procedure: k9594 
o|contracted procedure: k9598 
o|contracted procedure: k9590 
o|contracted procedure: k9571 
o|contracted procedure: k9574 
o|contracted procedure: k9582 
o|contracted procedure: k9586 
o|contracted procedure: k9652 
o|contracted procedure: k9616 
o|contracted procedure: k9642 
o|contracted procedure: k9646 
o|contracted procedure: k9638 
o|contracted procedure: k9619 
o|contracted procedure: k9622 
o|contracted procedure: k9630 
o|contracted procedure: k9634 
o|contracted procedure: k9694 
o|contracted procedure: k9702 
o|contracted procedure: k9528 
o|contracted procedure: k9690 
o|contracted procedure: k9667 
o|contracted procedure: k9670 
o|contracted procedure: k9678 
o|contracted procedure: k9682 
o|contracted procedure: k9686 
o|contracted procedure: k9708 
o|contracted procedure: k9714 
o|contracted procedure: k9760 
o|contracted procedure: k9780 
o|contracted procedure: k9796 
o|contracted procedure: k9792 
o|contracted procedure: k9841 
o|contracted procedure: k9805 
o|contracted procedure: k9831 
o|contracted procedure: k9835 
o|contracted procedure: k9827 
o|contracted procedure: k9808 
o|contracted procedure: k9811 
o|contracted procedure: k9819 
o|contracted procedure: k9823 
o|contracted procedure: k9889 
o|contracted procedure: k9853 
o|contracted procedure: k9879 
o|contracted procedure: k9883 
o|contracted procedure: k9769 
o|contracted procedure: k9875 
o|contracted procedure: k9856 
o|contracted procedure: k9859 
o|contracted procedure: k9867 
o|contracted procedure: k9871 
o|contracted procedure: k9904 
o|contracted procedure: k9907 
o|contracted procedure: k9915 
o|contracted procedure: k9919 
o|contracted procedure: k9923 
o|contracted procedure: k9931 
o|contracted procedure: k9935 
o|contracted procedure: k9939 
o|contracted procedure: k9945 
o|contracted procedure: k9951 
o|contracted procedure: k10007 
o|contracted procedure: k9971 
o|contracted procedure: k9997 
o|contracted procedure: k10001 
o|contracted procedure: k9993 
o|contracted procedure: k9974 
o|contracted procedure: k9977 
o|contracted procedure: k9985 
o|contracted procedure: k9989 
o|contracted procedure: k10055 
o|contracted procedure: k10019 
o|contracted procedure: k10045 
o|contracted procedure: k10049 
o|contracted procedure: k10041 
o|contracted procedure: k10022 
o|contracted procedure: k10025 
o|contracted procedure: k10033 
o|contracted procedure: k10037 
o|contracted procedure: k10103 
o|contracted procedure: k10067 
o|contracted procedure: k10093 
o|contracted procedure: k10097 
o|contracted procedure: k10089 
o|contracted procedure: k10070 
o|contracted procedure: k10073 
o|contracted procedure: k10081 
o|contracted procedure: k10085 
o|contracted procedure: k10115 
o|contracted procedure: k10118 
o|contracted procedure: k10121 
o|contracted procedure: k10129 
o|contracted procedure: k10149 
o|contracted procedure: k10152 
o|contracted procedure: k10155 
o|contracted procedure: k10163 
o|contracted procedure: k10183 
o|contracted procedure: k10186 
o|contracted procedure: k10189 
o|contracted procedure: k10197 
o|contracted procedure: k10205 
o|contracted procedure: k10217 
o|contracted procedure: k10239 
o|contracted procedure: k10235 
o|contracted procedure: k10220 
o|contracted procedure: k10223 
o|contracted procedure: k10231 
o|contracted procedure: k10251 
o|contracted procedure: k10273 
o|contracted procedure: k10269 
o|contracted procedure: k10254 
o|contracted procedure: k10257 
o|contracted procedure: k10265 
o|contracted procedure: k10289 
o|contracted procedure: k10294 
o|contracted procedure: k10297 
o|contracted procedure: k10303 
o|contracted procedure: k10318 
o|contracted procedure: k10501 
o|contracted procedure: k10345 
o|contracted procedure: k10497 
o|contracted procedure: k10349 
o|contracted procedure: k10357 
o|contracted procedure: k10353 
o|contracted procedure: k10341 
o|contracted procedure: k10365 
o|contracted procedure: k10381 
o|contracted procedure: k10397 
o|contracted procedure: k10393 
o|contracted procedure: k10442 
o|contracted procedure: k10406 
o|contracted procedure: k10432 
o|contracted procedure: k10436 
o|contracted procedure: k10428 
o|contracted procedure: k10409 
o|contracted procedure: k10412 
o|contracted procedure: k10420 
o|contracted procedure: k10424 
o|contracted procedure: k10490 
o|contracted procedure: k10454 
o|contracted procedure: k10480 
o|contracted procedure: k10484 
o|contracted procedure: k10476 
o|contracted procedure: k10457 
o|contracted procedure: k10460 
o|contracted procedure: k10468 
o|contracted procedure: k10472 
o|contracted procedure: k10509 
o|contracted procedure: k10517 
o|contracted procedure: k10528 
o|contracted procedure: k10544 
o|contracted procedure: k10540 
o|contracted procedure: k10589 
o|contracted procedure: k10553 
o|contracted procedure: k10579 
o|contracted procedure: k10583 
o|contracted procedure: k10575 
o|contracted procedure: k10556 
o|contracted procedure: k10559 
o|contracted procedure: k10567 
o|contracted procedure: k10571 
o|contracted procedure: k10637 
o|contracted procedure: k10601 
o|contracted procedure: k10627 
o|contracted procedure: k10631 
o|contracted procedure: k10623 
o|contracted procedure: k10604 
o|contracted procedure: k10607 
o|contracted procedure: k10615 
o|contracted procedure: k10619 
o|contracted procedure: k10644 
o|contracted procedure: k10647 
o|contracted procedure: k10653 
o|contracted procedure: k10656 
o|contracted procedure: k10663 
o|contracted procedure: k10669 
o|contracted procedure: k10672 
o|contracted procedure: k10720 
o|contracted procedure: k10684 
o|contracted procedure: k10710 
o|contracted procedure: k10714 
o|contracted procedure: k10706 
o|contracted procedure: k10687 
o|contracted procedure: k10690 
o|contracted procedure: k10698 
o|contracted procedure: k10702 
o|contracted procedure: k10734 
o|contracted procedure: k10745 
o|contracted procedure: k10790 
o|contracted procedure: k10754 
o|contracted procedure: k10780 
o|contracted procedure: k10784 
o|contracted procedure: k10776 
o|contracted procedure: k10757 
o|contracted procedure: k10760 
o|contracted procedure: k10768 
o|contracted procedure: k10772 
o|contracted procedure: k10802 
o|contracted procedure: k10824 
o|contracted procedure: k10820 
o|contracted procedure: k10805 
o|contracted procedure: k10808 
o|contracted procedure: k10816 
o|contracted procedure: k10836 
o|contracted procedure: k10839 
o|contracted procedure: k10842 
o|contracted procedure: k10850 
o|contracted procedure: k10870 
o|contracted procedure: k10873 
o|contracted procedure: k10876 
o|contracted procedure: k10884 
o|contracted procedure: k10904 
o|contracted procedure: k10926 
o|contracted procedure: k10922 
o|contracted procedure: k10907 
o|contracted procedure: k10910 
o|contracted procedure: k10918 
o|contracted procedure: k10946 
o|contracted procedure: k10963 
o|contracted procedure: k10984 
o|contracted procedure: k10980 
o|contracted procedure: k10998 
o|contracted procedure: k11091 
o|contracted procedure: k11014 
o|contracted procedure: k11025 
o|contracted procedure: k11021 
o|contracted procedure: k11033 
o|contracted procedure: k11036 
o|contracted procedure: k11082 
o|contracted procedure: k11045 
o|contracted procedure: k11064 
o|contracted procedure: k11060 
o|contracted procedure: k11056 
o|contracted procedure: k11052 
o|contracted procedure: k11071 
o|contracted procedure: k11079 
o|contracted procedure: k11075 
o|contracted procedure: k11104 
o|contracted procedure: k11116 
o|contracted procedure: k11128 
o|contracted procedure: k11136 
o|contracted procedure: k11151 
o|contracted procedure: k11163 
o|contracted procedure: k11179 
o|contracted procedure: k11169 
o|inlining procedure: k11142 
o|inlining procedure: k11142 
o|inlining procedure: k11142 
o|contracted procedure: k11186 
o|contracted procedure: k11438 
o|contracted procedure: k11200 
o|contracted procedure: k11428 
o|contracted procedure: k11424 
o|contracted procedure: k11420 
o|contracted procedure: k11416 
o|contracted procedure: k11208 
o|contracted procedure: k11394 
o|contracted procedure: k11402 
o|contracted procedure: k11398 
o|contracted procedure: k11390 
o|contracted procedure: k11216 
o|contracted procedure: k11212 
o|contracted procedure: k11204 
o|contracted procedure: k11196 
o|contracted procedure: k11229 
o|contracted procedure: k11232 
o|contracted procedure: k11382 
o|contracted procedure: k11235 
o|contracted procedure: k11347 
o|contracted procedure: k11363 
o|contracted procedure: k11359 
o|contracted procedure: k11351 
o|contracted procedure: k11355 
o|contracted procedure: k11247 
o|contracted procedure: k11254 
o|contracted procedure: k11262 
o|contracted procedure: k11266 
o|contracted procedure: k11282 
o|contracted procedure: k11278 
o|contracted procedure: k11297 
o|contracted procedure: k11313 
o|contracted procedure: k11309 
o|contracted procedure: k11301 
o|contracted procedure: k11305 
o|contracted procedure: k11293 
o|contracted procedure: k11320 
o|contracted procedure: k11336 
o|contracted procedure: k11332 
o|contracted procedure: k11324 
o|contracted procedure: k11328 
o|contracted procedure: k11343 
o|contracted procedure: k11375 
o|contracted procedure: k11447 
o|contracted procedure: k11450 
o|contracted procedure: k11453 
o|contracted procedure: k11461 
o|contracted procedure: k11469 
o|contracted procedure: k11503 
o|contracted procedure: k11513 
o|contracted procedure: k11522 
o|contracted procedure: k11525 
o|contracted procedure: k11536 
o|contracted procedure: k11542 
o|contracted procedure: k11570 
o|contracted procedure: k11589 
o|contracted procedure: k11597 
o|contracted procedure: k11601 
o|contracted procedure: k11620 
o|contracted procedure: k11639 
o|contracted procedure: k11647 
o|contracted procedure: k11651 
o|contracted procedure: k11661 
o|contracted procedure: k11670 
o|contracted procedure: k11685 
o|contracted procedure: k11681 
o|contracted procedure: k11694 
o|contracted procedure: k11716 
o|contracted procedure: k11697 
o|contracted procedure: k11712 
o|contracted procedure: k11708 
o|contracted procedure: k11722 
o|contracted procedure: k11725 
o|contracted procedure: k11731 
o|contracted procedure: k11738 
o|contracted procedure: k11741 
o|contracted procedure: k11748 
o|contracted procedure: k11777 
o|contracted procedure: k11769 
o|contracted procedure: k11797 
o|contracted procedure: k11807 
o|contracted procedure: k11803 
o|contracted procedure: k11824 
o|contracted procedure: k11884 
o|contracted procedure: k11840 
o|contracted procedure: k11860 
o|contracted procedure: k11864 
o|contracted procedure: k11868 
o|contracted procedure: k11856 
o|contracted procedure: k11876 
o|contracted procedure: k11880 
o|contracted procedure: k11897 
o|contracted procedure: k12007 
o|contracted procedure: k12003 
o|contracted procedure: k11910 
o|contracted procedure: k11926 
o|contracted procedure: k11942 
o|contracted procedure: k11947 
o|contracted procedure: k11957 
o|contracted procedure: k11962 
o|contracted procedure: k11922 
o|contracted procedure: k11918 
o|contracted procedure: k11914 
o|contracted procedure: k11974 
o|contracted procedure: k11977 
o|contracted procedure: k11980 
o|contracted procedure: k11988 
o|contracted procedure: k11996 
o|contracted procedure: k12357 
o|contracted procedure: k12020 
o|contracted procedure: k12026 
o|contracted procedure: k12029 
o|contracted procedure: k12042 
o|contracted procedure: k12054 
o|contracted procedure: k12063 
o|contracted procedure: k12162 
o|contracted procedure: k12070 
o|contracted procedure: k12154 
o|contracted procedure: k12158 
o|contracted procedure: k12074 
o|contracted procedure: k12082 
o|contracted procedure: k12090 
o|contracted procedure: k12086 
o|contracted procedure: k12078 
o|contracted procedure: k12147 
o|contracted procedure: k12111 
o|contracted procedure: k12137 
o|contracted procedure: k12141 
o|contracted procedure: k12099 
o|contracted procedure: k12133 
o|contracted procedure: k12114 
o|contracted procedure: k12117 
o|contracted procedure: k12125 
o|contracted procedure: k12129 
o|contracted procedure: k12169 
o|contracted procedure: k12176 
o|contracted procedure: k12184 
o|contracted procedure: k12196 
o|contracted procedure: k12199 
o|contracted procedure: k12202 
o|contracted procedure: k12210 
o|contracted procedure: k12218 
o|contracted procedure: k12240 
o|contracted procedure: k12247 
o|contracted procedure: k12255 
o|contracted procedure: k12259 
o|contracted procedure: k12262 
o|contracted procedure: k12268 
o|contracted procedure: k12277 
o|contracted procedure: k12281 
o|contracted procedure: k12312 
o|contracted procedure: k12296 
o|contracted procedure: k12300 
o|contracted procedure: k12308 
o|contracted procedure: k12318 
o|contracted procedure: k12324 
o|contracted procedure: k12331 
o|contracted procedure: k12353 
o|contracted procedure: k12342 
o|contracted procedure: k12367 
o|contracted procedure: k12376 
o|contracted procedure: k12384 
o|contracted procedure: k12387 
o|contracted procedure: k12393 
o|contracted procedure: k12405 
o|contracted procedure: k12408 
o|contracted procedure: k12414 
o|contracted procedure: k12425 
o|contracted procedure: k12455 
o|contracted procedure: k12451 
o|contracted procedure: k12443 
o|contracted procedure: k12439 
o|contracted procedure: k12464 
o|contracted procedure: k12486 
o|contracted procedure: k12402 
o|contracted procedure: k12482 
o|contracted procedure: k12467 
o|contracted procedure: k12470 
o|contracted procedure: k12478 
o|contracted procedure: k12498 
o|contracted procedure: k12520 
o|contracted procedure: k12516 
o|contracted procedure: k12501 
o|contracted procedure: k12504 
o|contracted procedure: k12512 
o|contracted procedure: k12529 
o|contracted procedure: k12557 
o|contracted procedure: k12576 
o|contracted procedure: k12584 
o|contracted procedure: k12588 
o|contracted procedure: k12607 
o|contracted procedure: k12625 
o|contracted procedure: k12635 
o|contracted procedure: k12642 
o|contracted procedure: k12645 
o|contracted procedure: k12651 
o|contracted procedure: k12658 
o|contracted procedure: k12662 
o|contracted procedure: k12666 
o|contracted procedure: k12704 
o|contracted procedure: k12682 
o|contracted procedure: k12696 
o|contracted procedure: k12700 
o|contracted procedure: k12811 
o|contracted procedure: k12720 
o|contracted procedure: k12747 
o|contracted procedure: k12803 
o|contracted procedure: k12799 
o|contracted procedure: k12795 
o|contracted procedure: k12761 
o|contracted procedure: k12757 
o|contracted procedure: k12784 
o|contracted procedure: k12780 
o|contracted procedure: k12773 
o|contracted procedure: k12791 
o|contracted procedure: k12807 
o|contracted procedure: k13084 
o|contracted procedure: k12815 
o|contracted procedure: k12965 
o|contracted procedure: k12960 
o|contracted procedure: k12846 
o|contracted procedure: k12849 
o|contracted procedure: k12858 
o|contracted procedure: k12876 
o|contracted procedure: k12885 
o|contracted procedure: k12888 
o|contracted procedure: k12872 
o|contracted procedure: k12868 
o|contracted procedure: k12900 
o|contracted procedure: k12903 
o|contracted procedure: k12906 
o|contracted procedure: k12914 
o|contracted procedure: k12922 
o|contracted procedure: k12944 
o|contracted procedure: k12936 
o|contracted procedure: k12940 
o|contracted procedure: k12932 
o|contracted procedure: k12951 
o|contracted procedure: k13080 
o|contracted procedure: k13072 
o|contracted procedure: k13076 
o|contracted procedure: k13068 
o|contracted procedure: k13064 
o|contracted procedure: k12984 
o|contracted procedure: k12988 
o|contracted procedure: k12991 
o|contracted procedure: k12994 
o|contracted procedure: k13000 
o|contracted procedure: k12976 
o|contracted procedure: k12980 
o|contracted procedure: k13015 
o|contracted procedure: k13026 
o|contracted procedure: k13022 
o|contracted procedure: k13012 
o|contracted procedure: k13035 
o|contracted procedure: k13038 
o|contracted procedure: k13041 
o|contracted procedure: k13049 
o|contracted procedure: k13057 
o|contracted procedure: k13191 
o|contracted procedure: k13088 
o|contracted procedure: k13123 
o|contracted procedure: k13187 
o|contracted procedure: k13171 
o|contracted procedure: k13183 
o|contracted procedure: k13179 
o|contracted procedure: k13175 
o|contracted procedure: k13131 
o|contracted procedure: k13163 
o|contracted procedure: k13143 
o|contracted procedure: k13159 
o|contracted procedure: k13155 
o|contracted procedure: k13151 
o|contracted procedure: k13147 
o|contracted procedure: k13139 
o|contracted procedure: k13135 
o|contracted procedure: k13127 
o|contracted procedure: k13119 
o|contracted procedure: k13111 
o|simplifications: ((if . 5) (let . 234)) 
o|removed binding forms: 1042 
o|inlining procedure: k6800 
o|contracted procedure: k8805 
o|substituted constant variable: r1114314569 
o|substituted constant variable: r1114314570 
o|inlining procedure: k11286 
o|inlining procedure: k11286 
o|contracted procedure: k11667 
o|inlining procedure: k11938 
o|inlining procedure: k11938 
o|simplifications: ((let . 1)) 
o|removed binding forms: 3 
o|removed conditional forms: 2 
o|substituted constant variable: r1193914740 
o|replaced variables: 2 
o|removed binding forms: 3 
o|removed binding forms: 3 
o|direct leaf routine/allocation: g30743083 0 
o|direct leaf routine/allocation: g18561867 30 
o|direct leaf routine/allocation: g637646 15 
o|contracted procedure: "(chicken-syntax.scm:1112) k6635" 
o|contracted procedure: "(chicken-syntax.scm:509) k9927" 
o|contracted procedure: "(chicken-syntax.scm:96) k12918" 
o|removed binding forms: 3 
o|customizable procedures: (parse-clause611 map-loop662679 k12852 map-loop631652 k12769 k12628 loop748769 loop748785 map-loop796814 map-loop824842 k12287 loop867 loop2881 map-loop891916 k12166 map-loop925949 g985994 map-loop9791001 k11691 loop10991120 loop10991131 g11741183 map-loop11681194 k11274 mapslots1204 k11142 map-loop12871304 g13201329 map-loop13141332 g13481357 map-loop13421360 map-loop13931410 map-loop13721417 loop1448 map-loop14291451 map-loop14631487 map-loop14991523 map-loop15351559 map-loop15711595 map-loop16171634 map-loop16441661 g16771686 map-loop16711689 g17051714 map-loop16991717 g17331742 map-loop17271745 map-loop17571776 map-loop17881807 map-loop18191838 k9901 map-loop18501877 map-loop18921916 map-loop19281952 k9664 map-loop19641991 map-loop20062030 map-loop20422066 g20922101 map-loop20862131 for-each-loop21672194 map-loop21772207 map-loop22382255 loop2263 g22822291 map-loop22762294 loop2304 map-loop23622380 fold2314 g23332342 map-loop23272345 fold2396 map-loop24152432 map-loop24412458 foldl24932497 map-loop24702509 map-loop25182537 k8125 k8137 fold2596 map-loop26702687 g27062715 map-loop27002718 map-loop27282745 g27632772 map-loop27572775 recur2640 make-if-tree2634 prefix-sym2694 recur2655 loop2823 map-loop28532874 genvars2845 foldr28962899 g29012902 k6961 build2921 map-loop29442963 loop136 loop2847 map-loop30213038 g30483058 for-each-loop30473061 map-loop30683086 k6399 k6405 k6412 k6420 loop3093 loop3138 loop3168 k5763 k5786 take) 
o|calls to known targets: 248 
o|identified direct recursive calls: f_4347 1 
o|identified direct recursive calls: f_6612 1 
o|identified direct recursive calls: f_6673 1 
o|identified direct recursive calls: f_4405 1 
o|identified direct recursive calls: f_7007 1 
o|identified direct recursive calls: f_6931 1 
o|identified direct recursive calls: f_7852 1 
o|identified direct recursive calls: f_7920 1 
o|identified direct recursive calls: f_8398 1 
o|identified direct recursive calls: f_8468 1 
o|identified direct recursive calls: f_8502 1 
o|identified direct recursive calls: f_8557 1 
o|identified direct recursive calls: f_8734 2 
o|identified direct recursive calls: f_8883 1 
o|identified direct recursive calls: f_8995 1 
o|identified direct recursive calls: f_9033 1 
o|identified direct recursive calls: f_9140 1 
o|identified direct recursive calls: f_9563 1 
o|identified direct recursive calls: f_9611 1 
o|identified direct recursive calls: f_9800 1 
o|identified direct recursive calls: f_9848 1 
o|identified direct recursive calls: f_9966 1 
o|identified direct recursive calls: f_10014 1 
o|identified direct recursive calls: f_10062 1 
o|identified direct recursive calls: f_10212 1 
o|identified direct recursive calls: f_10246 1 
o|identified direct recursive calls: f_10401 1 
o|identified direct recursive calls: f_10449 1 
o|identified direct recursive calls: f_10548 1 
o|identified direct recursive calls: f_10596 1 
o|identified direct recursive calls: f_10679 1 
o|identified direct recursive calls: f_10729 1 
o|identified direct recursive calls: f_10749 1 
o|identified direct recursive calls: f_10797 1 
o|identified direct recursive calls: f_10899 1 
o|identified direct recursive calls: f_12106 1 
o|identified direct recursive calls: f_12235 1 
o|identified direct recursive calls: f_12049 1 
o|identified direct recursive calls: f_12459 1 
o|identified direct recursive calls: f_12493 1 
o|identified direct recursive calls: f_12895 1 
o|fast box initializations: 78 
o|fast global references: 2 
o|fast global assignments: 1 
o|dropping unused closure argument: f_4347 
o|dropping unused closure argument: f_7722 
*/
/* end of file */
