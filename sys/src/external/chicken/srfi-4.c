/* Generated from srfi-4.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: srfi-4.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file srfi-4.c -emit-import-library srfi-4
   unit: srfi-4
   uses: extras expand library
*/
#include "chicken.h"

#define C_copy_subvector(to, from, start_to, start_from, bytes)   \
  (C_memcpy((C_char *)C_data_pointer(to) + C_unfix(start_to), (C_char *)C_data_pointer(from) + C_unfix(start_from), C_unfix(bytes)), \
    C_SCHEME_UNDEFINED)

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_expand_toplevel)
C_externimport void C_ccall C_expand_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[289];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,26),40,115,114,102,105,45,52,35,117,56,118,101,99,116,111,114,45,108,101,110,103,116,104,32,120,41,0,0,0,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,26),40,115,114,102,105,45,52,35,115,56,118,101,99,116,111,114,45,108,101,110,103,116,104,32,120,41,0,0,0,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,27),40,115,114,102,105,45,52,35,117,49,54,118,101,99,116,111,114,45,108,101,110,103,116,104,32,120,41,0,0,0,0,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,27),40,115,114,102,105,45,52,35,115,49,54,118,101,99,116,111,114,45,108,101,110,103,116,104,32,120,41,0,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,27),40,115,114,102,105,45,52,35,117,51,50,118,101,99,116,111,114,45,108,101,110,103,116,104,32,120,41,0,0,0,0,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,27),40,115,114,102,105,45,52,35,115,51,50,118,101,99,116,111,114,45,108,101,110,103,116,104,32,120,41,0,0,0,0,0};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,27),40,115,114,102,105,45,52,35,117,54,52,118,101,99,116,111,114,45,108,101,110,103,116,104,32,120,41,0,0,0,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,27),40,115,114,102,105,45,52,35,115,54,52,118,101,99,116,111,114,45,108,101,110,103,116,104,32,120,41,0,0,0,0,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,27),40,115,114,102,105,45,52,35,102,51,50,118,101,99,116,111,114,45,108,101,110,103,116,104,32,120,41,0,0,0,0,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,27),40,115,114,102,105,45,52,35,102,54,52,118,101,99,116,111,114,45,108,101,110,103,116,104,32,120,41,0,0,0,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,28),40,115,114,102,105,45,52,35,117,56,118,101,99,116,111,114,45,115,101,116,33,32,120,32,105,32,121,41,0,0,0,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,28),40,115,114,102,105,45,52,35,115,56,118,101,99,116,111,114,45,115,101,116,33,32,120,32,105,32,121,41,0,0,0,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,29),40,115,114,102,105,45,52,35,117,49,54,118,101,99,116,111,114,45,115,101,116,33,32,120,32,105,32,121,41,0,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,29),40,115,114,102,105,45,52,35,115,49,54,118,101,99,116,111,114,45,115,101,116,33,32,120,32,105,32,121,41,0,0,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,29),40,115,114,102,105,45,52,35,117,51,50,118,101,99,116,111,114,45,115,101,116,33,32,120,32,105,32,121,41,0,0,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,29),40,115,114,102,105,45,52,35,115,51,50,118,101,99,116,111,114,45,115,101,116,33,32,120,32,105,32,121,41,0,0,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,29),40,115,114,102,105,45,52,35,117,54,52,118,101,99,116,111,114,45,115,101,116,33,32,120,32,105,32,121,41,0,0,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,29),40,115,114,102,105,45,52,35,115,54,52,118,101,99,116,111,114,45,115,101,116,33,32,120,32,105,32,121,41,0,0,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,29),40,115,114,102,105,45,52,35,102,51,50,118,101,99,116,111,114,45,115,101,116,33,32,120,32,105,32,121,41,0,0,0};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,29),40,115,114,102,105,45,52,35,102,54,52,118,101,99,116,111,114,45,115,101,116,33,32,120,32,105,32,121,41,0,0,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,16),40,101,120,116,45,102,114,101,101,32,98,118,50,50,55,41};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,32),40,97,108,108,111,99,32,108,111,99,32,101,108,101,109,45,115,105,122,101,32,101,108,101,109,115,32,101,120,116,63,41};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,32),40,115,114,102,105,45,52,35,114,101,108,101,97,115,101,45,110,117,109,98,101,114,45,118,101,99,116,111,114,32,118,41};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,11),40,100,111,108,111,111,112,50,55,52,41,0,0,0,0,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,33),40,115,114,102,105,45,52,35,109,97,107,101,45,117,56,118,101,99,116,111,114,32,108,101,110,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,11),40,100,111,108,111,111,112,51,48,56,41,0,0,0,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,33),40,115,114,102,105,45,52,35,109,97,107,101,45,115,56,118,101,99,116,111,114,32,108,101,110,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,11),40,100,111,108,111,111,112,51,52,50,41,0,0,0,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,34),40,115,114,102,105,45,52,35,109,97,107,101,45,117,49,54,118,101,99,116,111,114,32,108,101,110,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,11),40,100,111,108,111,111,112,51,55,54,41,0,0,0,0,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,34),40,115,114,102,105,45,52,35,109,97,107,101,45,115,49,54,118,101,99,116,111,114,32,108,101,110,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,11),40,100,111,108,111,111,112,52,49,48,41,0,0,0,0,0};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,34),40,115,114,102,105,45,52,35,109,97,107,101,45,117,51,50,118,101,99,116,111,114,32,108,101,110,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,11),40,100,111,108,111,111,112,52,52,52,41,0,0,0,0,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,34),40,115,114,102,105,45,52,35,109,97,107,101,45,117,54,52,118,101,99,116,111,114,32,108,101,110,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,11),40,100,111,108,111,111,112,52,55,56,41,0,0,0,0,0};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,34),40,115,114,102,105,45,52,35,109,97,107,101,45,115,51,50,118,101,99,116,111,114,32,108,101,110,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,11),40,100,111,108,111,111,112,53,49,50,41,0,0,0,0,0};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,34),40,115,114,102,105,45,52,35,109,97,107,101,45,115,54,52,118,101,99,116,111,114,32,108,101,110,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,11),40,100,111,108,111,111,112,53,52,55,41,0,0,0,0,0};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,34),40,115,114,102,105,45,52,35,109,97,107,101,45,102,51,50,118,101,99,116,111,114,32,108,101,110,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,11),40,100,111,108,111,111,112,53,56,51,41,0,0,0,0,0};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,34),40,115,114,102,105,45,52,35,109,97,107,101,45,102,54,52,118,101,99,116,111,114,32,108,101,110,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,15),40,100,111,108,111,111,112,54,49,56,32,112,32,105,41,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,27),40,115,114,102,105,45,52,35,108,105,115,116,45,62,117,56,118,101,99,116,111,114,32,108,115,116,41,0,0,0,0,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,15),40,100,111,108,111,111,112,54,51,49,32,112,32,105,41,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,27),40,115,114,102,105,45,52,35,108,105,115,116,45,62,115,56,118,101,99,116,111,114,32,108,115,116,41,0,0,0,0,0};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,15),40,100,111,108,111,111,112,54,52,52,32,112,32,105,41,0};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,28),40,115,114,102,105,45,52,35,108,105,115,116,45,62,117,49,54,118,101,99,116,111,114,32,108,115,116,41,0,0,0,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,15),40,100,111,108,111,111,112,54,53,55,32,112,32,105,41,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,28),40,115,114,102,105,45,52,35,108,105,115,116,45,62,115,49,54,118,101,99,116,111,114,32,108,115,116,41,0,0,0,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,15),40,100,111,108,111,111,112,54,55,48,32,112,32,105,41,0};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,28),40,115,114,102,105,45,52,35,108,105,115,116,45,62,117,51,50,118,101,99,116,111,114,32,108,115,116,41,0,0,0,0};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,15),40,100,111,108,111,111,112,54,56,51,32,112,32,105,41,0};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,28),40,115,114,102,105,45,52,35,108,105,115,116,45,62,115,51,50,118,101,99,116,111,114,32,108,115,116,41,0,0,0,0};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,15),40,100,111,108,111,111,112,54,57,54,32,112,32,105,41,0};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,28),40,115,114,102,105,45,52,35,108,105,115,116,45,62,117,54,52,118,101,99,116,111,114,32,108,115,116,41,0,0,0,0};
static C_char C_TLS li57[] C_aligned={C_lihdr(0,0,15),40,100,111,108,111,111,112,55,48,57,32,112,32,105,41,0};
static C_char C_TLS li58[] C_aligned={C_lihdr(0,0,28),40,115,114,102,105,45,52,35,108,105,115,116,45,62,115,54,52,118,101,99,116,111,114,32,108,115,116,41,0,0,0,0};
static C_char C_TLS li59[] C_aligned={C_lihdr(0,0,15),40,100,111,108,111,111,112,55,50,50,32,112,32,105,41,0};
static C_char C_TLS li60[] C_aligned={C_lihdr(0,0,28),40,115,114,102,105,45,52,35,108,105,115,116,45,62,102,51,50,118,101,99,116,111,114,32,108,115,116,41,0,0,0,0};
static C_char C_TLS li61[] C_aligned={C_lihdr(0,0,15),40,100,111,108,111,111,112,55,51,53,32,112,32,105,41,0};
static C_char C_TLS li62[] C_aligned={C_lihdr(0,0,28),40,115,114,102,105,45,52,35,108,105,115,116,45,62,102,54,52,118,101,99,116,111,114,32,108,115,116,41,0,0,0,0};
static C_char C_TLS li63[] C_aligned={C_lihdr(0,0,22),40,115,114,102,105,45,52,35,117,56,118,101,99,116,111,114,32,46,32,120,115,41,0,0};
static C_char C_TLS li64[] C_aligned={C_lihdr(0,0,22),40,115,114,102,105,45,52,35,115,56,118,101,99,116,111,114,32,46,32,120,115,41,0,0};
static C_char C_TLS li65[] C_aligned={C_lihdr(0,0,23),40,115,114,102,105,45,52,35,117,49,54,118,101,99,116,111,114,32,46,32,120,115,41,0};
static C_char C_TLS li66[] C_aligned={C_lihdr(0,0,23),40,115,114,102,105,45,52,35,115,49,54,118,101,99,116,111,114,32,46,32,120,115,41,0};
static C_char C_TLS li67[] C_aligned={C_lihdr(0,0,23),40,115,114,102,105,45,52,35,117,51,50,118,101,99,116,111,114,32,46,32,120,115,41,0};
static C_char C_TLS li68[] C_aligned={C_lihdr(0,0,23),40,115,114,102,105,45,52,35,115,51,50,118,101,99,116,111,114,32,46,32,120,115,41,0};
static C_char C_TLS li69[] C_aligned={C_lihdr(0,0,23),40,115,114,102,105,45,52,35,117,54,52,118,101,99,116,111,114,32,46,32,120,115,41,0};
static C_char C_TLS li70[] C_aligned={C_lihdr(0,0,23),40,115,114,102,105,45,52,35,115,54,52,118,101,99,116,111,114,32,46,32,120,115,41,0};
static C_char C_TLS li71[] C_aligned={C_lihdr(0,0,23),40,115,114,102,105,45,52,35,102,51,50,118,101,99,116,111,114,32,46,32,120,115,41,0};
static C_char C_TLS li72[] C_aligned={C_lihdr(0,0,23),40,115,114,102,105,45,52,35,102,54,52,118,101,99,116,111,114,32,46,32,120,115,41,0};
static C_char C_TLS li73[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li74[] C_aligned={C_lihdr(0,0,25),40,115,114,102,105,45,52,35,117,56,118,101,99,116,111,114,45,62,108,105,115,116,32,118,41,0,0,0,0,0,0,0};
static C_char C_TLS li75[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li76[] C_aligned={C_lihdr(0,0,25),40,115,114,102,105,45,52,35,115,56,118,101,99,116,111,114,45,62,108,105,115,116,32,118,41,0,0,0,0,0,0,0};
static C_char C_TLS li77[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li78[] C_aligned={C_lihdr(0,0,26),40,115,114,102,105,45,52,35,117,49,54,118,101,99,116,111,114,45,62,108,105,115,116,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li79[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li80[] C_aligned={C_lihdr(0,0,26),40,115,114,102,105,45,52,35,115,49,54,118,101,99,116,111,114,45,62,108,105,115,116,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li81[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li82[] C_aligned={C_lihdr(0,0,26),40,115,114,102,105,45,52,35,117,51,50,118,101,99,116,111,114,45,62,108,105,115,116,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li83[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li84[] C_aligned={C_lihdr(0,0,26),40,115,114,102,105,45,52,35,115,51,50,118,101,99,116,111,114,45,62,108,105,115,116,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li85[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li86[] C_aligned={C_lihdr(0,0,26),40,115,114,102,105,45,52,35,117,54,52,118,101,99,116,111,114,45,62,108,105,115,116,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li87[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li88[] C_aligned={C_lihdr(0,0,26),40,115,114,102,105,45,52,35,115,54,52,118,101,99,116,111,114,45,62,108,105,115,116,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li89[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li90[] C_aligned={C_lihdr(0,0,26),40,115,114,102,105,45,52,35,102,51,50,118,101,99,116,111,114,45,62,108,105,115,116,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li91[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li92[] C_aligned={C_lihdr(0,0,26),40,115,114,102,105,45,52,35,102,54,52,118,101,99,116,111,114,45,62,108,105,115,116,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li93[] C_aligned={C_lihdr(0,0,20),40,115,114,102,105,45,52,35,117,56,118,101,99,116,111,114,63,32,120,41,0,0,0,0};
static C_char C_TLS li94[] C_aligned={C_lihdr(0,0,20),40,115,114,102,105,45,52,35,115,56,118,101,99,116,111,114,63,32,120,41,0,0,0,0};
static C_char C_TLS li95[] C_aligned={C_lihdr(0,0,21),40,115,114,102,105,45,52,35,117,49,54,118,101,99,116,111,114,63,32,120,41,0,0,0};
static C_char C_TLS li96[] C_aligned={C_lihdr(0,0,21),40,115,114,102,105,45,52,35,115,49,54,118,101,99,116,111,114,63,32,120,41,0,0,0};
static C_char C_TLS li97[] C_aligned={C_lihdr(0,0,21),40,115,114,102,105,45,52,35,117,51,50,118,101,99,116,111,114,63,32,120,41,0,0,0};
static C_char C_TLS li98[] C_aligned={C_lihdr(0,0,21),40,115,114,102,105,45,52,35,115,51,50,118,101,99,116,111,114,63,32,120,41,0,0,0};
static C_char C_TLS li99[] C_aligned={C_lihdr(0,0,21),40,115,114,102,105,45,52,35,117,54,52,118,101,99,116,111,114,63,32,120,41,0,0,0};
static C_char C_TLS li100[] C_aligned={C_lihdr(0,0,21),40,115,114,102,105,45,52,35,115,54,52,118,101,99,116,111,114,63,32,120,41,0,0,0};
static C_char C_TLS li101[] C_aligned={C_lihdr(0,0,21),40,115,114,102,105,45,52,35,102,51,50,118,101,99,116,111,114,63,32,120,41,0,0,0};
static C_char C_TLS li102[] C_aligned={C_lihdr(0,0,21),40,115,114,102,105,45,52,35,102,54,52,118,101,99,116,111,114,63,32,120,41,0,0,0};
static C_char C_TLS li103[] C_aligned={C_lihdr(0,0,10),40,102,95,51,54,56,52,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li104[] C_aligned={C_lihdr(0,0,26),40,115,114,102,105,45,52,35,112,97,99,107,45,99,111,112,121,32,116,97,103,32,108,111,99,41,0,0,0,0,0,0};
static C_char C_TLS li105[] C_aligned={C_lihdr(0,0,12),40,102,95,51,55,48,50,32,115,116,114,41,0,0,0,0};
static C_char C_TLS li106[] C_aligned={C_lihdr(0,0,26),40,115,114,102,105,45,52,35,117,110,112,97,99,107,32,116,97,103,32,115,122,32,108,111,99,41,0,0,0,0,0,0};
static C_char C_TLS li107[] C_aligned={C_lihdr(0,0,12),40,102,95,51,55,51,50,32,115,116,114,41,0,0,0,0};
static C_char C_TLS li108[] C_aligned={C_lihdr(0,0,31),40,115,114,102,105,45,52,35,117,110,112,97,99,107,45,99,111,112,121,32,116,97,103,32,115,122,32,108,111,99,41,0};
static C_char C_TLS li109[] C_aligned={C_lihdr(0,0,16),40,102,53,54,49,56,32,118,56,55,52,53,54,49,55,41};
static C_char C_TLS li110[] C_aligned={C_lihdr(0,0,16),40,102,53,54,49,49,32,118,56,55,52,53,54,49,48,41};
static C_char C_TLS li111[] C_aligned={C_lihdr(0,0,16),40,102,53,54,48,52,32,118,56,55,52,53,54,48,51,41};
static C_char C_TLS li112[] C_aligned={C_lihdr(0,0,16),40,102,53,53,57,55,32,118,56,55,52,53,53,57,54,41};
static C_char C_TLS li113[] C_aligned={C_lihdr(0,0,16),40,102,53,53,57,48,32,118,56,55,52,53,53,56,57,41};
static C_char C_TLS li114[] C_aligned={C_lihdr(0,0,16),40,102,53,53,56,51,32,118,56,55,52,53,53,56,50,41};
static C_char C_TLS li115[] C_aligned={C_lihdr(0,0,16),40,102,53,53,55,54,32,118,56,55,52,53,53,55,53,41};
static C_char C_TLS li116[] C_aligned={C_lihdr(0,0,16),40,102,53,53,54,57,32,118,56,55,52,53,53,54,56,41};
static C_char C_TLS li117[] C_aligned={C_lihdr(0,0,16),40,102,53,53,54,50,32,118,56,55,52,53,53,54,49,41};
static C_char C_TLS li118[] C_aligned={C_lihdr(0,0,16),40,102,53,53,53,53,32,118,56,55,52,53,53,53,52,41};
static C_char C_TLS li119[] C_aligned={C_lihdr(0,0,19),40,109,97,112,45,108,111,111,112,57,57,50,32,103,49,48,48,52,41,0,0,0,0,0};
static C_char C_TLS li120[] C_aligned={C_lihdr(0,0,15),40,108,111,111,112,50,32,110,115,32,112,114,101,118,41,0};
static C_char C_TLS li121[] C_aligned={C_lihdr(0,0,9),40,114,101,116,114,121,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li122[] C_aligned={C_lihdr(0,0,15),40,108,111,111,112,32,108,115,116,32,112,114,101,118,41,0};
static C_char C_TLS li123[] C_aligned={C_lihdr(0,0,8),40,103,57,56,54,32,99,41};
static C_char C_TLS li124[] C_aligned={C_lihdr(0,0,32),40,35,35,115,121,115,35,117,115,101,114,45,114,101,97,100,45,104,111,111,107,32,99,104,97,114,32,112,111,114,116,41};
static C_char C_TLS li125[] C_aligned={C_lihdr(0,0,39),40,35,35,115,121,115,35,117,115,101,114,45,112,114,105,110,116,45,104,111,111,107,32,120,32,114,101,97,100,97,98,108,101,32,112,111,114,116,41,0};
static C_char C_TLS li126[] C_aligned={C_lihdr(0,0,38),40,115,114,102,105,45,52,35,115,117,98,110,118,101,99,116,111,114,32,118,32,116,32,101,115,32,102,114,111,109,32,116,111,32,108,111,99,41,0,0};
static C_char C_TLS li127[] C_aligned={C_lihdr(0,0,30),40,115,114,102,105,45,52,35,115,117,98,117,56,118,101,99,116,111,114,32,118,32,102,114,111,109,32,116,111,41,0,0};
static C_char C_TLS li128[] C_aligned={C_lihdr(0,0,31),40,115,114,102,105,45,52,35,115,117,98,117,49,54,118,101,99,116,111,114,32,118,32,102,114,111,109,32,116,111,41,0};
static C_char C_TLS li129[] C_aligned={C_lihdr(0,0,31),40,115,114,102,105,45,52,35,115,117,98,117,51,50,118,101,99,116,111,114,32,118,32,102,114,111,109,32,116,111,41,0};
static C_char C_TLS li130[] C_aligned={C_lihdr(0,0,31),40,115,114,102,105,45,52,35,115,117,98,117,54,52,118,101,99,116,111,114,32,118,32,102,114,111,109,32,116,111,41,0};
static C_char C_TLS li131[] C_aligned={C_lihdr(0,0,30),40,115,114,102,105,45,52,35,115,117,98,115,56,118,101,99,116,111,114,32,118,32,102,114,111,109,32,116,111,41,0,0};
static C_char C_TLS li132[] C_aligned={C_lihdr(0,0,31),40,115,114,102,105,45,52,35,115,117,98,115,49,54,118,101,99,116,111,114,32,118,32,102,114,111,109,32,116,111,41,0};
static C_char C_TLS li133[] C_aligned={C_lihdr(0,0,31),40,115,114,102,105,45,52,35,115,117,98,115,51,50,118,101,99,116,111,114,32,118,32,102,114,111,109,32,116,111,41,0};
static C_char C_TLS li134[] C_aligned={C_lihdr(0,0,31),40,115,114,102,105,45,52,35,115,117,98,115,54,52,118,101,99,116,111,114,32,118,32,102,114,111,109,32,116,111,41,0};
static C_char C_TLS li135[] C_aligned={C_lihdr(0,0,31),40,115,114,102,105,45,52,35,115,117,98,102,51,50,118,101,99,116,111,114,32,118,32,102,114,111,109,32,116,111,41,0};
static C_char C_TLS li136[] C_aligned={C_lihdr(0,0,31),40,115,114,102,105,45,52,35,115,117,98,102,54,52,118,101,99,116,111,114,32,118,32,102,114,111,109,32,116,111,41,0};
static C_char C_TLS li137[] C_aligned={C_lihdr(0,0,32),40,115,114,102,105,45,52,35,119,114,105,116,101,45,117,56,118,101,99,116,111,114,32,118,32,46,32,114,101,115,116,41};
static C_char C_TLS li138[] C_aligned={C_lihdr(0,0,37),40,115,114,102,105,45,52,35,114,101,97,100,45,117,56,118,101,99,116,111,114,33,32,110,32,100,101,115,116,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li139[] C_aligned={C_lihdr(0,0,29),40,115,114,102,105,45,52,35,114,101,97,100,45,117,56,118,101,99,116,111,114,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li140[] C_aligned={C_lihdr(0,0,11),40,97,52,55,48,48,32,120,32,105,41,0,0,0,0,0};
static C_char C_TLS li141[] C_aligned={C_lihdr(0,0,11),40,97,52,55,48,51,32,120,32,105,41,0,0,0,0,0};
static C_char C_TLS li142[] C_aligned={C_lihdr(0,0,11),40,97,52,55,48,54,32,120,32,105,41,0,0,0,0,0};
static C_char C_TLS li143[] C_aligned={C_lihdr(0,0,11),40,97,52,55,48,57,32,120,32,105,41,0,0,0,0,0};
static C_char C_TLS li144[] C_aligned={C_lihdr(0,0,11),40,97,52,55,49,50,32,120,32,105,41,0,0,0,0,0};
static C_char C_TLS li145[] C_aligned={C_lihdr(0,0,11),40,97,52,55,49,53,32,120,32,105,41,0,0,0,0,0};
static C_char C_TLS li146[] C_aligned={C_lihdr(0,0,11),40,97,52,55,49,56,32,120,32,105,41,0,0,0,0,0};
static C_char C_TLS li147[] C_aligned={C_lihdr(0,0,11),40,97,52,55,50,49,32,120,32,105,41,0,0,0,0,0};
static C_char C_TLS li148[] C_aligned={C_lihdr(0,0,11),40,97,52,55,50,52,32,120,32,105,41,0,0,0,0,0};
static C_char C_TLS li149[] C_aligned={C_lihdr(0,0,11),40,97,52,55,50,55,32,120,32,105,41,0,0,0,0,0};
static C_char C_TLS li150[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


#define return(x) C_cblock C_r = (((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub228(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word bv=(C_word )(C_a0);
C_free((void *)C_block_item(bv, 1));
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub222(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
size_t bytes=(size_t )(size_t)C_num_to_uint64(C_a0);
if (bytes > C_HEADER_SIZE_MASK) C_return(C_SCHEME_FALSE);
C_word *buf = (C_word *)C_malloc(bytes + sizeof(C_header));
if(buf == NULL) C_return(C_SCHEME_FALSE);
C_block_header_init(buf, C_make_header(C_BYTEVECTOR_TYPE, bytes));
C_return(buf);
C_ret:
#undef return

return C_r;}

C_noret_decl(f5555)
static void C_ccall f5555(C_word c,C_word *av) C_noret;
C_noret_decl(f5562)
static void C_ccall f5562(C_word c,C_word *av) C_noret;
C_noret_decl(f5569)
static void C_ccall f5569(C_word c,C_word *av) C_noret;
C_noret_decl(f5576)
static void C_ccall f5576(C_word c,C_word *av) C_noret;
C_noret_decl(f5583)
static void C_ccall f5583(C_word c,C_word *av) C_noret;
C_noret_decl(f5590)
static void C_ccall f5590(C_word c,C_word *av) C_noret;
C_noret_decl(f5597)
static void C_ccall f5597(C_word c,C_word *av) C_noret;
C_noret_decl(f5604)
static void C_ccall f5604(C_word c,C_word *av) C_noret;
C_noret_decl(f5611)
static void C_ccall f5611(C_word c,C_word *av) C_noret;
C_noret_decl(f5618)
static void C_ccall f5618(C_word c,C_word *av) C_noret;
C_noret_decl(f_1576)
static void C_ccall f_1576(C_word c,C_word *av) C_noret;
C_noret_decl(f_1579)
static void C_ccall f_1579(C_word c,C_word *av) C_noret;
C_noret_decl(f_1582)
static void C_ccall f_1582(C_word c,C_word *av) C_noret;
C_noret_decl(f_1584)
static void C_ccall f_1584(C_word c,C_word *av) C_noret;
C_noret_decl(f_1587)
static void C_ccall f_1587(C_word c,C_word *av) C_noret;
C_noret_decl(f_1590)
static void C_ccall f_1590(C_word c,C_word *av) C_noret;
C_noret_decl(f_1593)
static void C_ccall f_1593(C_word c,C_word *av) C_noret;
C_noret_decl(f_1596)
static void C_ccall f_1596(C_word c,C_word *av) C_noret;
C_noret_decl(f_1599)
static void C_ccall f_1599(C_word c,C_word *av) C_noret;
C_noret_decl(f_1602)
static void C_ccall f_1602(C_word c,C_word *av) C_noret;
C_noret_decl(f_1605)
static void C_ccall f_1605(C_word c,C_word *av) C_noret;
C_noret_decl(f_1608)
static void C_ccall f_1608(C_word c,C_word *av) C_noret;
C_noret_decl(f_1611)
static void C_ccall f_1611(C_word c,C_word *av) C_noret;
C_noret_decl(f_1614)
static void C_ccall f_1614(C_word c,C_word *av) C_noret;
C_noret_decl(f_1617)
static void C_ccall f_1617(C_word c,C_word *av) C_noret;
C_noret_decl(f_1620)
static void C_ccall f_1620(C_word c,C_word *av) C_noret;
C_noret_decl(f_1623)
static void C_ccall f_1623(C_word c,C_word *av) C_noret;
C_noret_decl(f_1626)
static void C_ccall f_1626(C_word c,C_word *av) C_noret;
C_noret_decl(f_1629)
static void C_ccall f_1629(C_word c,C_word *av) C_noret;
C_noret_decl(f_1632)
static void C_ccall f_1632(C_word c,C_word *av) C_noret;
C_noret_decl(f_1635)
static void C_ccall f_1635(C_word c,C_word *av) C_noret;
C_noret_decl(f_1638)
static void C_ccall f_1638(C_word c,C_word *av) C_noret;
C_noret_decl(f_1641)
static void C_ccall f_1641(C_word c,C_word *av) C_noret;
C_noret_decl(f_1646)
static void C_ccall f_1646(C_word c,C_word *av) C_noret;
C_noret_decl(f_1650)
static void C_ccall f_1650(C_word c,C_word *av) C_noret;
C_noret_decl(f_1654)
static void C_ccall f_1654(C_word c,C_word *av) C_noret;
C_noret_decl(f_1658)
static void C_ccall f_1658(C_word c,C_word *av) C_noret;
C_noret_decl(f_1662)
static void C_ccall f_1662(C_word c,C_word *av) C_noret;
C_noret_decl(f_1666)
static void C_ccall f_1666(C_word c,C_word *av) C_noret;
C_noret_decl(f_1670)
static void C_ccall f_1670(C_word c,C_word *av) C_noret;
C_noret_decl(f_1674)
static void C_ccall f_1674(C_word c,C_word *av) C_noret;
C_noret_decl(f_1678)
static void C_ccall f_1678(C_word c,C_word *av) C_noret;
C_noret_decl(f_1682)
static void C_ccall f_1682(C_word c,C_word *av) C_noret;
C_noret_decl(f_1690)
static void C_ccall f_1690(C_word c,C_word *av) C_noret;
C_noret_decl(f_1692)
static void C_fcall f_1692(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_1696)
static void C_ccall f_1696(C_word c,C_word *av) C_noret;
C_noret_decl(f_1699)
static void C_ccall f_1699(C_word c,C_word *av) C_noret;
C_noret_decl(f_1705)
static void C_ccall f_1705(C_word c,C_word *av) C_noret;
C_noret_decl(f_1720)
static void C_ccall f_1720(C_word c,C_word *av) C_noret;
C_noret_decl(f_1731)
static void C_ccall f_1731(C_word c,C_word *av) C_noret;
C_noret_decl(f_1738)
static void C_ccall f_1738(C_word c,C_word *av) C_noret;
C_noret_decl(f_1746)
static void C_ccall f_1746(C_word c,C_word *av) C_noret;
C_noret_decl(f_1771)
static void C_ccall f_1771(C_word c,C_word *av) C_noret;
C_noret_decl(f_1782)
static void C_ccall f_1782(C_word c,C_word *av) C_noret;
C_noret_decl(f_1801)
static void C_ccall f_1801(C_word c,C_word *av) C_noret;
C_noret_decl(f_1806)
static C_word C_fcall f_1806(C_word t0,C_word t1);
C_noret_decl(f_1824)
static void C_ccall f_1824(C_word c,C_word *av) C_noret;
C_noret_decl(f_1862)
static void C_ccall f_1862(C_word c,C_word *av) C_noret;
C_noret_decl(f_1887)
static void C_ccall f_1887(C_word c,C_word *av) C_noret;
C_noret_decl(f_1898)
static void C_ccall f_1898(C_word c,C_word *av) C_noret;
C_noret_decl(f_1917)
static void C_ccall f_1917(C_word c,C_word *av) C_noret;
C_noret_decl(f_1922)
static C_word C_fcall f_1922(C_word t0,C_word t1);
C_noret_decl(f_1940)
static void C_ccall f_1940(C_word c,C_word *av) C_noret;
C_noret_decl(f_1978)
static void C_ccall f_1978(C_word c,C_word *av) C_noret;
C_noret_decl(f_2003)
static void C_ccall f_2003(C_word c,C_word *av) C_noret;
C_noret_decl(f_2014)
static void C_ccall f_2014(C_word c,C_word *av) C_noret;
C_noret_decl(f_2033)
static void C_ccall f_2033(C_word c,C_word *av) C_noret;
C_noret_decl(f_2038)
static C_word C_fcall f_2038(C_word t0,C_word t1);
C_noret_decl(f_2056)
static void C_ccall f_2056(C_word c,C_word *av) C_noret;
C_noret_decl(f_2094)
static void C_ccall f_2094(C_word c,C_word *av) C_noret;
C_noret_decl(f_2119)
static void C_ccall f_2119(C_word c,C_word *av) C_noret;
C_noret_decl(f_2130)
static void C_ccall f_2130(C_word c,C_word *av) C_noret;
C_noret_decl(f_2159)
static void C_ccall f_2159(C_word c,C_word *av) C_noret;
C_noret_decl(f_2164)
static C_word C_fcall f_2164(C_word t0,C_word t1);
C_noret_decl(f_2182)
static void C_ccall f_2182(C_word c,C_word *av) C_noret;
C_noret_decl(f_2220)
static void C_ccall f_2220(C_word c,C_word *av) C_noret;
C_noret_decl(f_2245)
static void C_ccall f_2245(C_word c,C_word *av) C_noret;
C_noret_decl(f_2256)
static void C_ccall f_2256(C_word c,C_word *av) C_noret;
C_noret_decl(f_2275)
static void C_ccall f_2275(C_word c,C_word *av) C_noret;
C_noret_decl(f_2280)
static C_word C_fcall f_2280(C_word t0,C_word t1);
C_noret_decl(f_2298)
static void C_ccall f_2298(C_word c,C_word *av) C_noret;
C_noret_decl(f_2336)
static void C_ccall f_2336(C_word c,C_word *av) C_noret;
C_noret_decl(f_2361)
static void C_ccall f_2361(C_word c,C_word *av) C_noret;
C_noret_decl(f_2372)
static void C_ccall f_2372(C_word c,C_word *av) C_noret;
C_noret_decl(f_2391)
static void C_ccall f_2391(C_word c,C_word *av) C_noret;
C_noret_decl(f_2396)
static C_word C_fcall f_2396(C_word t0,C_word t1);
C_noret_decl(f_2414)
static void C_ccall f_2414(C_word c,C_word *av) C_noret;
C_noret_decl(f_2452)
static void C_ccall f_2452(C_word c,C_word *av) C_noret;
C_noret_decl(f_2477)
static void C_ccall f_2477(C_word c,C_word *av) C_noret;
C_noret_decl(f_2488)
static void C_ccall f_2488(C_word c,C_word *av) C_noret;
C_noret_decl(f_2517)
static void C_ccall f_2517(C_word c,C_word *av) C_noret;
C_noret_decl(f_2522)
static C_word C_fcall f_2522(C_word t0,C_word t1);
C_noret_decl(f_2540)
static void C_ccall f_2540(C_word c,C_word *av) C_noret;
C_noret_decl(f_2578)
static void C_ccall f_2578(C_word c,C_word *av) C_noret;
C_noret_decl(f_2603)
static void C_ccall f_2603(C_word c,C_word *av) C_noret;
C_noret_decl(f_2614)
static void C_ccall f_2614(C_word c,C_word *av) C_noret;
C_noret_decl(f_2643)
static void C_ccall f_2643(C_word c,C_word *av) C_noret;
C_noret_decl(f_2648)
static C_word C_fcall f_2648(C_word t0,C_word t1);
C_noret_decl(f_2666)
static void C_ccall f_2666(C_word c,C_word *av) C_noret;
C_noret_decl(f_2704)
static void C_ccall f_2704(C_word c,C_word *av) C_noret;
C_noret_decl(f_2729)
static void C_ccall f_2729(C_word c,C_word *av) C_noret;
C_noret_decl(f_2750)
static void C_ccall f_2750(C_word c,C_word *av) C_noret;
C_noret_decl(f_2753)
static void C_fcall f_2753(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2758)
static C_word C_fcall f_2758(C_word t0,C_word t1);
C_noret_decl(f_2777)
static void C_ccall f_2777(C_word c,C_word *av) C_noret;
C_noret_decl(f_2815)
static void C_ccall f_2815(C_word c,C_word *av) C_noret;
C_noret_decl(f_2840)
static void C_ccall f_2840(C_word c,C_word *av) C_noret;
C_noret_decl(f_2861)
static void C_ccall f_2861(C_word c,C_word *av) C_noret;
C_noret_decl(f_2864)
static void C_fcall f_2864(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2869)
static C_word C_fcall f_2869(C_word t0,C_word t1);
C_noret_decl(f_2888)
static void C_ccall f_2888(C_word c,C_word *av) C_noret;
C_noret_decl(f_2926)
static void C_ccall f_2926(C_word c,C_word *av) C_noret;
C_noret_decl(f_2933)
static void C_ccall f_2933(C_word c,C_word *av) C_noret;
C_noret_decl(f_2938)
static void C_fcall f_2938(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2945)
static void C_ccall f_2945(C_word c,C_word *av) C_noret;
C_noret_decl(f_2962)
static void C_ccall f_2962(C_word c,C_word *av) C_noret;
C_noret_decl(f_2969)
static void C_ccall f_2969(C_word c,C_word *av) C_noret;
C_noret_decl(f_2974)
static void C_fcall f_2974(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2981)
static void C_ccall f_2981(C_word c,C_word *av) C_noret;
C_noret_decl(f_2998)
static void C_ccall f_2998(C_word c,C_word *av) C_noret;
C_noret_decl(f_3005)
static void C_ccall f_3005(C_word c,C_word *av) C_noret;
C_noret_decl(f_3010)
static void C_fcall f_3010(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3017)
static void C_ccall f_3017(C_word c,C_word *av) C_noret;
C_noret_decl(f_3034)
static void C_ccall f_3034(C_word c,C_word *av) C_noret;
C_noret_decl(f_3041)
static void C_ccall f_3041(C_word c,C_word *av) C_noret;
C_noret_decl(f_3046)
static void C_fcall f_3046(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3053)
static void C_ccall f_3053(C_word c,C_word *av) C_noret;
C_noret_decl(f_3070)
static void C_ccall f_3070(C_word c,C_word *av) C_noret;
C_noret_decl(f_3077)
static void C_ccall f_3077(C_word c,C_word *av) C_noret;
C_noret_decl(f_3082)
static void C_fcall f_3082(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3089)
static void C_ccall f_3089(C_word c,C_word *av) C_noret;
C_noret_decl(f_3106)
static void C_ccall f_3106(C_word c,C_word *av) C_noret;
C_noret_decl(f_3113)
static void C_ccall f_3113(C_word c,C_word *av) C_noret;
C_noret_decl(f_3118)
static void C_fcall f_3118(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3125)
static void C_ccall f_3125(C_word c,C_word *av) C_noret;
C_noret_decl(f_3142)
static void C_ccall f_3142(C_word c,C_word *av) C_noret;
C_noret_decl(f_3149)
static void C_ccall f_3149(C_word c,C_word *av) C_noret;
C_noret_decl(f_3154)
static void C_fcall f_3154(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3161)
static void C_ccall f_3161(C_word c,C_word *av) C_noret;
C_noret_decl(f_3178)
static void C_ccall f_3178(C_word c,C_word *av) C_noret;
C_noret_decl(f_3185)
static void C_ccall f_3185(C_word c,C_word *av) C_noret;
C_noret_decl(f_3190)
static void C_fcall f_3190(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3197)
static void C_ccall f_3197(C_word c,C_word *av) C_noret;
C_noret_decl(f_3214)
static void C_ccall f_3214(C_word c,C_word *av) C_noret;
C_noret_decl(f_3221)
static void C_ccall f_3221(C_word c,C_word *av) C_noret;
C_noret_decl(f_3226)
static void C_fcall f_3226(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3233)
static void C_ccall f_3233(C_word c,C_word *av) C_noret;
C_noret_decl(f_3250)
static void C_ccall f_3250(C_word c,C_word *av) C_noret;
C_noret_decl(f_3257)
static void C_ccall f_3257(C_word c,C_word *av) C_noret;
C_noret_decl(f_3262)
static void C_fcall f_3262(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3269)
static void C_ccall f_3269(C_word c,C_word *av) C_noret;
C_noret_decl(f_3286)
static void C_ccall f_3286(C_word c,C_word *av) C_noret;
C_noret_decl(f_3292)
static void C_ccall f_3292(C_word c,C_word *av) C_noret;
C_noret_decl(f_3298)
static void C_ccall f_3298(C_word c,C_word *av) C_noret;
C_noret_decl(f_3304)
static void C_ccall f_3304(C_word c,C_word *av) C_noret;
C_noret_decl(f_3310)
static void C_ccall f_3310(C_word c,C_word *av) C_noret;
C_noret_decl(f_3316)
static void C_ccall f_3316(C_word c,C_word *av) C_noret;
C_noret_decl(f_3322)
static void C_ccall f_3322(C_word c,C_word *av) C_noret;
C_noret_decl(f_3328)
static void C_ccall f_3328(C_word c,C_word *av) C_noret;
C_noret_decl(f_3334)
static void C_ccall f_3334(C_word c,C_word *av) C_noret;
C_noret_decl(f_3340)
static void C_ccall f_3340(C_word c,C_word *av) C_noret;
C_noret_decl(f_3346)
static void C_ccall f_3346(C_word c,C_word *av) C_noret;
C_noret_decl(f_3355)
static void C_fcall f_3355(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3370)
static void C_ccall f_3370(C_word c,C_word *av) C_noret;
C_noret_decl(f_3376)
static void C_ccall f_3376(C_word c,C_word *av) C_noret;
C_noret_decl(f_3385)
static void C_fcall f_3385(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3400)
static void C_ccall f_3400(C_word c,C_word *av) C_noret;
C_noret_decl(f_3406)
static void C_ccall f_3406(C_word c,C_word *av) C_noret;
C_noret_decl(f_3415)
static void C_fcall f_3415(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3430)
static void C_ccall f_3430(C_word c,C_word *av) C_noret;
C_noret_decl(f_3436)
static void C_ccall f_3436(C_word c,C_word *av) C_noret;
C_noret_decl(f_3445)
static void C_fcall f_3445(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3460)
static void C_ccall f_3460(C_word c,C_word *av) C_noret;
C_noret_decl(f_3466)
static void C_ccall f_3466(C_word c,C_word *av) C_noret;
C_noret_decl(f_3475)
static void C_fcall f_3475(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3489)
static void C_ccall f_3489(C_word c,C_word *av) C_noret;
C_noret_decl(f_3495)
static void C_ccall f_3495(C_word c,C_word *av) C_noret;
C_noret_decl(f_3504)
static void C_fcall f_3504(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3518)
static void C_ccall f_3518(C_word c,C_word *av) C_noret;
C_noret_decl(f_3524)
static void C_ccall f_3524(C_word c,C_word *av) C_noret;
C_noret_decl(f_3533)
static void C_fcall f_3533(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3547)
static void C_ccall f_3547(C_word c,C_word *av) C_noret;
C_noret_decl(f_3553)
static void C_ccall f_3553(C_word c,C_word *av) C_noret;
C_noret_decl(f_3562)
static void C_fcall f_3562(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3576)
static void C_ccall f_3576(C_word c,C_word *av) C_noret;
C_noret_decl(f_3582)
static void C_ccall f_3582(C_word c,C_word *av) C_noret;
C_noret_decl(f_3591)
static void C_fcall f_3591(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3605)
static void C_ccall f_3605(C_word c,C_word *av) C_noret;
C_noret_decl(f_3611)
static void C_ccall f_3611(C_word c,C_word *av) C_noret;
C_noret_decl(f_3620)
static void C_fcall f_3620(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3634)
static void C_ccall f_3634(C_word c,C_word *av) C_noret;
C_noret_decl(f_3640)
static void C_ccall f_3640(C_word c,C_word *av) C_noret;
C_noret_decl(f_3643)
static void C_ccall f_3643(C_word c,C_word *av) C_noret;
C_noret_decl(f_3646)
static void C_ccall f_3646(C_word c,C_word *av) C_noret;
C_noret_decl(f_3649)
static void C_ccall f_3649(C_word c,C_word *av) C_noret;
C_noret_decl(f_3652)
static void C_ccall f_3652(C_word c,C_word *av) C_noret;
C_noret_decl(f_3655)
static void C_ccall f_3655(C_word c,C_word *av) C_noret;
C_noret_decl(f_3658)
static void C_ccall f_3658(C_word c,C_word *av) C_noret;
C_noret_decl(f_3661)
static void C_ccall f_3661(C_word c,C_word *av) C_noret;
C_noret_decl(f_3664)
static void C_ccall f_3664(C_word c,C_word *av) C_noret;
C_noret_decl(f_3667)
static void C_ccall f_3667(C_word c,C_word *av) C_noret;
C_noret_decl(f_3682)
static void C_fcall f_3682(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3684)
static void C_ccall f_3684(C_word c,C_word *av) C_noret;
C_noret_decl(f_3694)
static void C_ccall f_3694(C_word c,C_word *av) C_noret;
C_noret_decl(f_3700)
static void C_fcall f_3700(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3702)
static void C_ccall f_3702(C_word c,C_word *av) C_noret;
C_noret_decl(f_3730)
static void C_fcall f_3730(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3732)
static void C_ccall f_3732(C_word c,C_word *av) C_noret;
C_noret_decl(f_3742)
static void C_ccall f_3742(C_word c,C_word *av) C_noret;
C_noret_decl(f_3806)
static void C_ccall f_3806(C_word c,C_word *av) C_noret;
C_noret_decl(f_3810)
static void C_ccall f_3810(C_word c,C_word *av) C_noret;
C_noret_decl(f_3814)
static void C_ccall f_3814(C_word c,C_word *av) C_noret;
C_noret_decl(f_3818)
static void C_ccall f_3818(C_word c,C_word *av) C_noret;
C_noret_decl(f_3822)
static void C_ccall f_3822(C_word c,C_word *av) C_noret;
C_noret_decl(f_3826)
static void C_ccall f_3826(C_word c,C_word *av) C_noret;
C_noret_decl(f_3830)
static void C_ccall f_3830(C_word c,C_word *av) C_noret;
C_noret_decl(f_3834)
static void C_ccall f_3834(C_word c,C_word *av) C_noret;
C_noret_decl(f_3838)
static void C_ccall f_3838(C_word c,C_word *av) C_noret;
C_noret_decl(f_3842)
static void C_ccall f_3842(C_word c,C_word *av) C_noret;
C_noret_decl(f_3846)
static void C_ccall f_3846(C_word c,C_word *av) C_noret;
C_noret_decl(f_3850)
static void C_ccall f_3850(C_word c,C_word *av) C_noret;
C_noret_decl(f_3854)
static void C_ccall f_3854(C_word c,C_word *av) C_noret;
C_noret_decl(f_3858)
static void C_ccall f_3858(C_word c,C_word *av) C_noret;
C_noret_decl(f_3862)
static void C_ccall f_3862(C_word c,C_word *av) C_noret;
C_noret_decl(f_3866)
static void C_ccall f_3866(C_word c,C_word *av) C_noret;
C_noret_decl(f_3870)
static void C_ccall f_3870(C_word c,C_word *av) C_noret;
C_noret_decl(f_3874)
static void C_ccall f_3874(C_word c,C_word *av) C_noret;
C_noret_decl(f_3878)
static void C_ccall f_3878(C_word c,C_word *av) C_noret;
C_noret_decl(f_3882)
static void C_ccall f_3882(C_word c,C_word *av) C_noret;
C_noret_decl(f_3886)
static void C_ccall f_3886(C_word c,C_word *av) C_noret;
C_noret_decl(f_3890)
static void C_ccall f_3890(C_word c,C_word *av) C_noret;
C_noret_decl(f_3894)
static void C_ccall f_3894(C_word c,C_word *av) C_noret;
C_noret_decl(f_3898)
static void C_ccall f_3898(C_word c,C_word *av) C_noret;
C_noret_decl(f_3902)
static void C_ccall f_3902(C_word c,C_word *av) C_noret;
C_noret_decl(f_3906)
static void C_ccall f_3906(C_word c,C_word *av) C_noret;
C_noret_decl(f_3910)
static void C_ccall f_3910(C_word c,C_word *av) C_noret;
C_noret_decl(f_3914)
static void C_ccall f_3914(C_word c,C_word *av) C_noret;
C_noret_decl(f_3918)
static void C_ccall f_3918(C_word c,C_word *av) C_noret;
C_noret_decl(f_3922)
static void C_ccall f_3922(C_word c,C_word *av) C_noret;
C_noret_decl(f_3930)
static void C_fcall f_3930(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3946)
static void C_fcall f_3946(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3960)
static void C_ccall f_3960(C_word c,C_word *av) C_noret;
C_noret_decl(f_3986)
static void C_ccall f_3986(C_word c,C_word *av) C_noret;
C_noret_decl(f_3988)
static void C_fcall f_3988(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3995)
static void C_fcall f_3995(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4057)
static void C_ccall f_4057(C_word c,C_word *av) C_noret;
C_noret_decl(f_4066)
static void C_ccall f_4066(C_word c,C_word *av) C_noret;
C_noret_decl(f_4085)
static void C_fcall f_4085(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4089)
static void C_ccall f_4089(C_word c,C_word *av) C_noret;
C_noret_decl(f_4112)
static void C_ccall f_4112(C_word c,C_word *av) C_noret;
C_noret_decl(f_4115)
static void C_ccall f_4115(C_word c,C_word *av) C_noret;
C_noret_decl(f_4117)
static void C_fcall f_4117(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4153)
static void C_ccall f_4153(C_word c,C_word *av) C_noret;
C_noret_decl(f_4170)
static void C_ccall f_4170(C_word c,C_word *av) C_noret;
C_noret_decl(f_4182)
static void C_ccall f_4182(C_word c,C_word *av) C_noret;
C_noret_decl(f_4185)
static void C_ccall f_4185(C_word c,C_word *av) C_noret;
C_noret_decl(f_4195)
static void C_ccall f_4195(C_word c,C_word *av) C_noret;
C_noret_decl(f_4244)
static void C_fcall f_4244(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_4259)
static void C_ccall f_4259(C_word c,C_word *av) C_noret;
C_noret_decl(f_4278)
static void C_ccall f_4278(C_word c,C_word *av) C_noret;
C_noret_decl(f_4283)
static void C_ccall f_4283(C_word c,C_word *av) C_noret;
C_noret_decl(f_4302)
static void C_ccall f_4302(C_word c,C_word *av) C_noret;
C_noret_decl(f_4308)
static void C_ccall f_4308(C_word c,C_word *av) C_noret;
C_noret_decl(f_4329)
static void C_ccall f_4329(C_word c,C_word *av) C_noret;
C_noret_decl(f_4335)
static void C_ccall f_4335(C_word c,C_word *av) C_noret;
C_noret_decl(f_4341)
static void C_ccall f_4341(C_word c,C_word *av) C_noret;
C_noret_decl(f_4347)
static void C_ccall f_4347(C_word c,C_word *av) C_noret;
C_noret_decl(f_4353)
static void C_ccall f_4353(C_word c,C_word *av) C_noret;
C_noret_decl(f_4359)
static void C_ccall f_4359(C_word c,C_word *av) C_noret;
C_noret_decl(f_4365)
static void C_ccall f_4365(C_word c,C_word *av) C_noret;
C_noret_decl(f_4371)
static void C_ccall f_4371(C_word c,C_word *av) C_noret;
C_noret_decl(f_4377)
static void C_ccall f_4377(C_word c,C_word *av) C_noret;
C_noret_decl(f_4383)
static void C_ccall f_4383(C_word c,C_word *av) C_noret;
C_noret_decl(f_4389)
static void C_ccall f_4389(C_word c,C_word *av) C_noret;
C_noret_decl(f_4419)
static void C_ccall f_4419(C_word c,C_word *av) C_noret;
C_noret_decl(f_4438)
static void C_ccall f_4438(C_word c,C_word *av) C_noret;
C_noret_decl(f_4441)
static void C_ccall f_4441(C_word c,C_word *av) C_noret;
C_noret_decl(f_4454)
static void C_fcall f_4454(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4464)
static void C_ccall f_4464(C_word c,C_word *av) C_noret;
C_noret_decl(f_4489)
static void C_ccall f_4489(C_word c,C_word *av) C_noret;
C_noret_decl(f_4558)
static void C_ccall f_4558(C_word c,C_word *av) C_noret;
C_noret_decl(f_4577)
static void C_ccall f_4577(C_word c,C_word *av) C_noret;
C_noret_decl(f_4583)
static void C_ccall f_4583(C_word c,C_word *av) C_noret;
C_noret_decl(f_4638)
static void C_ccall f_4638(C_word c,C_word *av) C_noret;
C_noret_decl(f_4657)
static void C_ccall f_4657(C_word c,C_word *av) C_noret;
C_noret_decl(f_4660)
static void C_ccall f_4660(C_word c,C_word *av) C_noret;
C_noret_decl(f_4699)
static void C_ccall f_4699(C_word c,C_word *av) C_noret;
C_noret_decl(f_4701)
static void C_ccall f_4701(C_word c,C_word *av) C_noret;
C_noret_decl(f_4704)
static void C_ccall f_4704(C_word c,C_word *av) C_noret;
C_noret_decl(f_4707)
static void C_ccall f_4707(C_word c,C_word *av) C_noret;
C_noret_decl(f_4710)
static void C_ccall f_4710(C_word c,C_word *av) C_noret;
C_noret_decl(f_4713)
static void C_ccall f_4713(C_word c,C_word *av) C_noret;
C_noret_decl(f_4716)
static void C_ccall f_4716(C_word c,C_word *av) C_noret;
C_noret_decl(f_4719)
static void C_ccall f_4719(C_word c,C_word *av) C_noret;
C_noret_decl(f_4722)
static void C_ccall f_4722(C_word c,C_word *av) C_noret;
C_noret_decl(f_4725)
static void C_ccall f_4725(C_word c,C_word *av) C_noret;
C_noret_decl(f_4728)
static void C_ccall f_4728(C_word c,C_word *av) C_noret;
C_noret_decl(C_srfi_2d4_toplevel)
C_externexport void C_ccall C_srfi_2d4_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_1692)
static void C_ccall trf_1692(C_word c,C_word *av) C_noret;
static void C_ccall trf_1692(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_1692(t0,t1,t2,t3,t4);}

C_noret_decl(trf_2753)
static void C_ccall trf_2753(C_word c,C_word *av) C_noret;
static void C_ccall trf_2753(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2753(t0,t1);}

C_noret_decl(trf_2864)
static void C_ccall trf_2864(C_word c,C_word *av) C_noret;
static void C_ccall trf_2864(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2864(t0,t1);}

C_noret_decl(trf_2938)
static void C_ccall trf_2938(C_word c,C_word *av) C_noret;
static void C_ccall trf_2938(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2938(t0,t1,t2,t3);}

C_noret_decl(trf_2974)
static void C_ccall trf_2974(C_word c,C_word *av) C_noret;
static void C_ccall trf_2974(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2974(t0,t1,t2,t3);}

C_noret_decl(trf_3010)
static void C_ccall trf_3010(C_word c,C_word *av) C_noret;
static void C_ccall trf_3010(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3010(t0,t1,t2,t3);}

C_noret_decl(trf_3046)
static void C_ccall trf_3046(C_word c,C_word *av) C_noret;
static void C_ccall trf_3046(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3046(t0,t1,t2,t3);}

C_noret_decl(trf_3082)
static void C_ccall trf_3082(C_word c,C_word *av) C_noret;
static void C_ccall trf_3082(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3082(t0,t1,t2,t3);}

C_noret_decl(trf_3118)
static void C_ccall trf_3118(C_word c,C_word *av) C_noret;
static void C_ccall trf_3118(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3118(t0,t1,t2,t3);}

C_noret_decl(trf_3154)
static void C_ccall trf_3154(C_word c,C_word *av) C_noret;
static void C_ccall trf_3154(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3154(t0,t1,t2,t3);}

C_noret_decl(trf_3190)
static void C_ccall trf_3190(C_word c,C_word *av) C_noret;
static void C_ccall trf_3190(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3190(t0,t1,t2,t3);}

C_noret_decl(trf_3226)
static void C_ccall trf_3226(C_word c,C_word *av) C_noret;
static void C_ccall trf_3226(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3226(t0,t1,t2,t3);}

C_noret_decl(trf_3262)
static void C_ccall trf_3262(C_word c,C_word *av) C_noret;
static void C_ccall trf_3262(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3262(t0,t1,t2,t3);}

C_noret_decl(trf_3355)
static void C_ccall trf_3355(C_word c,C_word *av) C_noret;
static void C_ccall trf_3355(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3355(t0,t1,t2);}

C_noret_decl(trf_3385)
static void C_ccall trf_3385(C_word c,C_word *av) C_noret;
static void C_ccall trf_3385(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3385(t0,t1,t2);}

C_noret_decl(trf_3415)
static void C_ccall trf_3415(C_word c,C_word *av) C_noret;
static void C_ccall trf_3415(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3415(t0,t1,t2);}

C_noret_decl(trf_3445)
static void C_ccall trf_3445(C_word c,C_word *av) C_noret;
static void C_ccall trf_3445(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3445(t0,t1,t2);}

C_noret_decl(trf_3475)
static void C_ccall trf_3475(C_word c,C_word *av) C_noret;
static void C_ccall trf_3475(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3475(t0,t1,t2);}

C_noret_decl(trf_3504)
static void C_ccall trf_3504(C_word c,C_word *av) C_noret;
static void C_ccall trf_3504(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3504(t0,t1,t2);}

C_noret_decl(trf_3533)
static void C_ccall trf_3533(C_word c,C_word *av) C_noret;
static void C_ccall trf_3533(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3533(t0,t1,t2);}

C_noret_decl(trf_3562)
static void C_ccall trf_3562(C_word c,C_word *av) C_noret;
static void C_ccall trf_3562(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3562(t0,t1,t2);}

C_noret_decl(trf_3591)
static void C_ccall trf_3591(C_word c,C_word *av) C_noret;
static void C_ccall trf_3591(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3591(t0,t1,t2);}

C_noret_decl(trf_3620)
static void C_ccall trf_3620(C_word c,C_word *av) C_noret;
static void C_ccall trf_3620(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3620(t0,t1,t2);}

C_noret_decl(trf_3682)
static void C_ccall trf_3682(C_word c,C_word *av) C_noret;
static void C_ccall trf_3682(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3682(t0,t1,t2);}

C_noret_decl(trf_3700)
static void C_ccall trf_3700(C_word c,C_word *av) C_noret;
static void C_ccall trf_3700(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3700(t0,t1,t2,t3);}

C_noret_decl(trf_3730)
static void C_ccall trf_3730(C_word c,C_word *av) C_noret;
static void C_ccall trf_3730(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3730(t0,t1,t2,t3);}

C_noret_decl(trf_3930)
static void C_ccall trf_3930(C_word c,C_word *av) C_noret;
static void C_ccall trf_3930(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3930(t0,t1,t2,t3);}

C_noret_decl(trf_3946)
static void C_ccall trf_3946(C_word c,C_word *av) C_noret;
static void C_ccall trf_3946(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3946(t0,t1,t2);}

C_noret_decl(trf_3988)
static void C_ccall trf_3988(C_word c,C_word *av) C_noret;
static void C_ccall trf_3988(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3988(t0,t1,t2,t3);}

C_noret_decl(trf_3995)
static void C_ccall trf_3995(C_word c,C_word *av) C_noret;
static void C_ccall trf_3995(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3995(t0,t1);}

C_noret_decl(trf_4085)
static void C_ccall trf_4085(C_word c,C_word *av) C_noret;
static void C_ccall trf_4085(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4085(t0,t1,t2);}

C_noret_decl(trf_4117)
static void C_ccall trf_4117(C_word c,C_word *av) C_noret;
static void C_ccall trf_4117(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4117(t0,t1,t2);}

C_noret_decl(trf_4244)
static void C_ccall trf_4244(C_word c,C_word *av) C_noret;
static void C_ccall trf_4244(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_4244(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_4454)
static void C_ccall trf_4454(C_word c,C_word *av) C_noret;
static void C_ccall trf_4454(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4454(t0,t1);}

/* f5555 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f5555(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f5555,c,av);}
t3=C_i_check_structure_2(t2,lf[76],lf[164]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* f5562 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f5562(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f5562,c,av);}
t3=C_i_check_structure_2(t2,lf[73],lf[162]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* f5569 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f5569(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f5569,c,av);}
t3=C_i_check_structure_2(t2,lf[70],lf[160]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* f5576 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f5576(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f5576,c,av);}
t3=C_i_check_structure_2(t2,lf[63],lf[158]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* f5583 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f5583(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f5583,c,av);}
t3=C_i_check_structure_2(t2,lf[67],lf[156]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* f5590 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f5590(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f5590,c,av);}
t3=C_i_check_structure_2(t2,lf[59],lf[154]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* f5597 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f5597(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f5597,c,av);}
t3=C_i_check_structure_2(t2,lf[55],lf[152]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* f5604 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f5604(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f5604,c,av);}
t3=C_i_check_structure_2(t2,lf[52],lf[150]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* f5611 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f5611(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f5611,c,av);}
t3=C_i_check_structure_2(t2,lf[49],lf[148]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* f5618 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f5618(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f5618,c,av);}
t3=C_i_check_structure_2(t2,lf[43],lf[146]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k1574 */
static void C_ccall f_1576(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1576,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1579,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k1577 in k1574 */
static void C_ccall f_1579(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_1579,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1582,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

/* k1580 in k1577 in k1574 */
static void C_ccall f_1582(C_word c,C_word *av){
C_word tmp;
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(66,c,5)))){
C_save_and_reclaim((void *)f_1582,c,av);}
a=C_alloc(66);
t2=C_mutate((C_word*)lf[2]+1 /* (set! srfi-4#u8vector-length ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1584,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t3=C_mutate((C_word*)lf[3]+1 /* (set! srfi-4#s8vector-length ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1587,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[4]+1 /* (set! srfi-4#u16vector-length ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1590,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[5]+1 /* (set! srfi-4#s16vector-length ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1593,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[6]+1 /* (set! srfi-4#u32vector-length ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1596,a[2]=((C_word)li4),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[7]+1 /* (set! srfi-4#s32vector-length ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1599,a[2]=((C_word)li5),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[8]+1 /* (set! srfi-4#u64vector-length ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1602,a[2]=((C_word)li6),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[9]+1 /* (set! srfi-4#s64vector-length ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1605,a[2]=((C_word)li7),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[10]+1 /* (set! srfi-4#f32vector-length ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1608,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[11]+1 /* (set! srfi-4#f64vector-length ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1611,a[2]=((C_word)li9),tmp=(C_word)a,a+=3,tmp));
t12=C_mutate((C_word*)lf[12]+1 /* (set! srfi-4#u8vector-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1614,a[2]=((C_word)li10),tmp=(C_word)a,a+=3,tmp));
t13=C_mutate((C_word*)lf[13]+1 /* (set! srfi-4#s8vector-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1617,a[2]=((C_word)li11),tmp=(C_word)a,a+=3,tmp));
t14=C_mutate((C_word*)lf[14]+1 /* (set! srfi-4#u16vector-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1620,a[2]=((C_word)li12),tmp=(C_word)a,a+=3,tmp));
t15=C_mutate((C_word*)lf[15]+1 /* (set! srfi-4#s16vector-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1623,a[2]=((C_word)li13),tmp=(C_word)a,a+=3,tmp));
t16=C_mutate((C_word*)lf[16]+1 /* (set! srfi-4#u32vector-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1626,a[2]=((C_word)li14),tmp=(C_word)a,a+=3,tmp));
t17=C_mutate((C_word*)lf[17]+1 /* (set! srfi-4#s32vector-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1629,a[2]=((C_word)li15),tmp=(C_word)a,a+=3,tmp));
t18=C_mutate((C_word*)lf[18]+1 /* (set! srfi-4#u64vector-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1632,a[2]=((C_word)li16),tmp=(C_word)a,a+=3,tmp));
t19=C_mutate((C_word*)lf[19]+1 /* (set! srfi-4#s64vector-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1635,a[2]=((C_word)li17),tmp=(C_word)a,a+=3,tmp));
t20=C_mutate((C_word*)lf[20]+1 /* (set! srfi-4#f32vector-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1638,a[2]=((C_word)li18),tmp=(C_word)a,a+=3,tmp));
t21=C_mutate((C_word*)lf[21]+1 /* (set! srfi-4#f64vector-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1641,a[2]=((C_word)li19),tmp=(C_word)a,a+=3,tmp));
t22=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1646,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t23=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4728,a[2]=((C_word)li149),tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:187: chicken.base#getter-with-setter */
t24=*((C_word*)lf[278]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t24;
av2[1]=t22;
av2[2]=t23;
av2[3]=*((C_word*)lf[12]+1);
av2[4]=lf[288];
((C_proc)(void*)(*((C_word*)t24+1)))(5,av2);}}

/* srfi-4#u8vector-length in k1580 in k1577 in k1574 */
static void C_ccall f_1584(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1584,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_u8vector_length(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#s8vector-length in k1580 in k1577 in k1574 */
static void C_ccall f_1587(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1587,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_s8vector_length(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#u16vector-length in k1580 in k1577 in k1574 */
static void C_ccall f_1590(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1590,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_u16vector_length(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#s16vector-length in k1580 in k1577 in k1574 */
static void C_ccall f_1593(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1593,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_s16vector_length(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#u32vector-length in k1580 in k1577 in k1574 */
static void C_ccall f_1596(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1596,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_u32vector_length(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#s32vector-length in k1580 in k1577 in k1574 */
static void C_ccall f_1599(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1599,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_s32vector_length(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#u64vector-length in k1580 in k1577 in k1574 */
static void C_ccall f_1602(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1602,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_u64vector_length(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#s64vector-length in k1580 in k1577 in k1574 */
static void C_ccall f_1605(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1605,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_s64vector_length(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#f32vector-length in k1580 in k1577 in k1574 */
static void C_ccall f_1608(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1608,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_f32vector_length(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#f64vector-length in k1580 in k1577 in k1574 */
static void C_ccall f_1611(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1611,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_f64vector_length(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#u8vector-set! in k1580 in k1577 in k1574 */
static void C_ccall f_1614(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1614,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_u8vector_set(t2,t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* srfi-4#s8vector-set! in k1580 in k1577 in k1574 */
static void C_ccall f_1617(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1617,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_s8vector_set(t2,t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* srfi-4#u16vector-set! in k1580 in k1577 in k1574 */
static void C_ccall f_1620(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1620,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_u16vector_set(t2,t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* srfi-4#s16vector-set! in k1580 in k1577 in k1574 */
static void C_ccall f_1623(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1623,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_s16vector_set(t2,t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* srfi-4#u32vector-set! in k1580 in k1577 in k1574 */
static void C_ccall f_1626(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1626,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_u32vector_set(t2,t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* srfi-4#s32vector-set! in k1580 in k1577 in k1574 */
static void C_ccall f_1629(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1629,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_s32vector_set(t2,t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* srfi-4#u64vector-set! in k1580 in k1577 in k1574 */
static void C_ccall f_1632(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1632,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_u64vector_set(t2,t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* srfi-4#s64vector-set! in k1580 in k1577 in k1574 */
static void C_ccall f_1635(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1635,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_s64vector_set(t2,t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* srfi-4#f32vector-set! in k1580 in k1577 in k1574 */
static void C_ccall f_1638(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1638,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_f32vector_set(t2,t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* srfi-4#f64vector-set! in k1580 in k1577 in k1574 */
static void C_ccall f_1641(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1641,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_f64vector_set(t2,t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1646(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1646,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[22]+1 /* (set! srfi-4#u8vector-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1650,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4725,a[2]=((C_word)li148),tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:193: chicken.base#getter-with-setter */
t5=*((C_word*)lf[278]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[13]+1);
av2[4]=lf[287];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1650(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1650,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[23]+1 /* (set! srfi-4#s8vector-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1654,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4722,a[2]=((C_word)li147),tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:199: chicken.base#getter-with-setter */
t5=*((C_word*)lf[278]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[14]+1);
av2[4]=lf[286];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1654(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1654,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[24]+1 /* (set! srfi-4#u16vector-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1658,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4719,a[2]=((C_word)li146),tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:205: chicken.base#getter-with-setter */
t5=*((C_word*)lf[278]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[15]+1);
av2[4]=lf[285];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1658(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1658,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[25]+1 /* (set! srfi-4#s16vector-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1662,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4716,a[2]=((C_word)li145),tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:211: chicken.base#getter-with-setter */
t5=*((C_word*)lf[278]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[16]+1);
av2[4]=lf[284];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1662(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1662,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[26]+1 /* (set! srfi-4#u32vector-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1666,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4713,a[2]=((C_word)li144),tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:217: chicken.base#getter-with-setter */
t5=*((C_word*)lf[278]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[17]+1);
av2[4]=lf[283];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1666(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1666,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[27]+1 /* (set! srfi-4#s32vector-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1670,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4710,a[2]=((C_word)li143),tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:223: chicken.base#getter-with-setter */
t5=*((C_word*)lf[278]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[18]+1);
av2[4]=lf[282];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1670(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1670,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[28]+1 /* (set! srfi-4#u64vector-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1674,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4707,a[2]=((C_word)li142),tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:229: chicken.base#getter-with-setter */
t5=*((C_word*)lf[278]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[19]+1);
av2[4]=lf[281];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1674(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1674,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[29]+1 /* (set! srfi-4#s64vector-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1678,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4704,a[2]=((C_word)li141),tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:235: chicken.base#getter-with-setter */
t5=*((C_word*)lf[278]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[20]+1);
av2[4]=lf[280];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1678(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1678,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[30]+1 /* (set! srfi-4#f32vector-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1682,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4701,a[2]=((C_word)li140),tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:241: chicken.base#getter-with-setter */
t5=*((C_word*)lf[278]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[21]+1);
av2[4]=lf[279];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1682(C_word c,C_word *av){
C_word tmp;
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
C_word t86;
C_word t87;
C_word t88;
C_word t89;
C_word t90;
C_word t91;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(231,c,6)))){
C_save_and_reclaim((void *)f_1682,c,av);}
a=C_alloc(231);
t2=C_mutate((C_word*)lf[31]+1 /* (set! srfi-4#f64vector-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1690,a[2]=((C_word)li20),tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1692,a[2]=((C_word)li21),tmp=(C_word)a,a+=3,tmp);
t5=C_mutate((C_word*)lf[38]+1 /* (set! srfi-4#release-number-vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1731,a[2]=((C_word)li22),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[42]+1 /* (set! srfi-4#make-u8vector ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1746,a[2]=t3,a[3]=t4,a[4]=((C_word)li24),tmp=(C_word)a,a+=5,tmp));
t7=C_mutate((C_word*)lf[48]+1 /* (set! srfi-4#make-s8vector ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1862,a[2]=t3,a[3]=t4,a[4]=((C_word)li26),tmp=(C_word)a,a+=5,tmp));
t8=C_mutate((C_word*)lf[51]+1 /* (set! srfi-4#make-u16vector ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1978,a[2]=t3,a[3]=t4,a[4]=((C_word)li28),tmp=(C_word)a,a+=5,tmp));
t9=C_mutate((C_word*)lf[54]+1 /* (set! srfi-4#make-s16vector ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2094,a[2]=t3,a[3]=t4,a[4]=((C_word)li30),tmp=(C_word)a,a+=5,tmp));
t10=C_mutate((C_word*)lf[58]+1 /* (set! srfi-4#make-u32vector ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2220,a[2]=t3,a[3]=t4,a[4]=((C_word)li32),tmp=(C_word)a,a+=5,tmp));
t11=C_mutate((C_word*)lf[62]+1 /* (set! srfi-4#make-u64vector ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2336,a[2]=t3,a[3]=t4,a[4]=((C_word)li34),tmp=(C_word)a,a+=5,tmp));
t12=C_mutate((C_word*)lf[66]+1 /* (set! srfi-4#make-s32vector ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2452,a[2]=t3,a[3]=t4,a[4]=((C_word)li36),tmp=(C_word)a,a+=5,tmp));
t13=C_mutate((C_word*)lf[69]+1 /* (set! srfi-4#make-s64vector ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2578,a[2]=t3,a[3]=t4,a[4]=((C_word)li38),tmp=(C_word)a,a+=5,tmp));
t14=C_mutate((C_word*)lf[72]+1 /* (set! srfi-4#make-f32vector ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2704,a[2]=t3,a[3]=t4,a[4]=((C_word)li40),tmp=(C_word)a,a+=5,tmp));
t15=C_mutate((C_word*)lf[75]+1 /* (set! srfi-4#make-f64vector ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2815,a[2]=t3,a[3]=t4,a[4]=((C_word)li42),tmp=(C_word)a,a+=5,tmp));
t16=*((C_word*)lf[42]+1);
t17=C_mutate((C_word*)lf[78]+1 /* (set! srfi-4#list->u8vector ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2926,a[2]=t16,a[3]=((C_word)li44),tmp=(C_word)a,a+=4,tmp));
t18=*((C_word*)lf[48]+1);
t19=C_mutate((C_word*)lf[81]+1 /* (set! srfi-4#list->s8vector ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2962,a[2]=t18,a[3]=((C_word)li46),tmp=(C_word)a,a+=4,tmp));
t20=*((C_word*)lf[51]+1);
t21=C_mutate((C_word*)lf[83]+1 /* (set! srfi-4#list->u16vector ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2998,a[2]=t20,a[3]=((C_word)li48),tmp=(C_word)a,a+=4,tmp));
t22=*((C_word*)lf[54]+1);
t23=C_mutate((C_word*)lf[85]+1 /* (set! srfi-4#list->s16vector ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3034,a[2]=t22,a[3]=((C_word)li50),tmp=(C_word)a,a+=4,tmp));
t24=*((C_word*)lf[58]+1);
t25=C_mutate((C_word*)lf[87]+1 /* (set! srfi-4#list->u32vector ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3070,a[2]=t24,a[3]=((C_word)li52),tmp=(C_word)a,a+=4,tmp));
t26=*((C_word*)lf[66]+1);
t27=C_mutate((C_word*)lf[89]+1 /* (set! srfi-4#list->s32vector ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3106,a[2]=t26,a[3]=((C_word)li54),tmp=(C_word)a,a+=4,tmp));
t28=*((C_word*)lf[62]+1);
t29=C_mutate((C_word*)lf[91]+1 /* (set! srfi-4#list->u64vector ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3142,a[2]=t28,a[3]=((C_word)li56),tmp=(C_word)a,a+=4,tmp));
t30=*((C_word*)lf[69]+1);
t31=C_mutate((C_word*)lf[93]+1 /* (set! srfi-4#list->s64vector ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3178,a[2]=t30,a[3]=((C_word)li58),tmp=(C_word)a,a+=4,tmp));
t32=*((C_word*)lf[72]+1);
t33=C_mutate((C_word*)lf[95]+1 /* (set! srfi-4#list->f32vector ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3214,a[2]=t32,a[3]=((C_word)li60),tmp=(C_word)a,a+=4,tmp));
t34=*((C_word*)lf[75]+1);
t35=C_mutate((C_word*)lf[97]+1 /* (set! srfi-4#list->f64vector ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3250,a[2]=t34,a[3]=((C_word)li62),tmp=(C_word)a,a+=4,tmp));
t36=C_mutate((C_word*)lf[99]+1 /* (set! srfi-4#u8vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3286,a[2]=((C_word)li63),tmp=(C_word)a,a+=3,tmp));
t37=C_mutate((C_word*)lf[100]+1 /* (set! srfi-4#s8vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3292,a[2]=((C_word)li64),tmp=(C_word)a,a+=3,tmp));
t38=C_mutate((C_word*)lf[101]+1 /* (set! srfi-4#u16vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3298,a[2]=((C_word)li65),tmp=(C_word)a,a+=3,tmp));
t39=C_mutate((C_word*)lf[102]+1 /* (set! srfi-4#s16vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3304,a[2]=((C_word)li66),tmp=(C_word)a,a+=3,tmp));
t40=C_mutate((C_word*)lf[103]+1 /* (set! srfi-4#u32vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3310,a[2]=((C_word)li67),tmp=(C_word)a,a+=3,tmp));
t41=C_mutate((C_word*)lf[104]+1 /* (set! srfi-4#s32vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3316,a[2]=((C_word)li68),tmp=(C_word)a,a+=3,tmp));
t42=C_mutate((C_word*)lf[105]+1 /* (set! srfi-4#u64vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3322,a[2]=((C_word)li69),tmp=(C_word)a,a+=3,tmp));
t43=C_mutate((C_word*)lf[106]+1 /* (set! srfi-4#s64vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3328,a[2]=((C_word)li70),tmp=(C_word)a,a+=3,tmp));
t44=C_mutate((C_word*)lf[107]+1 /* (set! srfi-4#f32vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3334,a[2]=((C_word)li71),tmp=(C_word)a,a+=3,tmp));
t45=C_mutate((C_word*)lf[108]+1 /* (set! srfi-4#f64vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3340,a[2]=((C_word)li72),tmp=(C_word)a,a+=3,tmp));
t46=C_mutate((C_word*)lf[109]+1 /* (set! srfi-4#u8vector->list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3346,a[2]=((C_word)li74),tmp=(C_word)a,a+=3,tmp));
t47=C_mutate((C_word*)lf[111]+1 /* (set! srfi-4#s8vector->list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3376,a[2]=((C_word)li76),tmp=(C_word)a,a+=3,tmp));
t48=C_mutate((C_word*)lf[113]+1 /* (set! srfi-4#u16vector->list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3406,a[2]=((C_word)li78),tmp=(C_word)a,a+=3,tmp));
t49=C_mutate((C_word*)lf[115]+1 /* (set! srfi-4#s16vector->list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3436,a[2]=((C_word)li80),tmp=(C_word)a,a+=3,tmp));
t50=C_mutate((C_word*)lf[117]+1 /* (set! srfi-4#u32vector->list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3466,a[2]=((C_word)li82),tmp=(C_word)a,a+=3,tmp));
t51=C_mutate((C_word*)lf[119]+1 /* (set! srfi-4#s32vector->list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3495,a[2]=((C_word)li84),tmp=(C_word)a,a+=3,tmp));
t52=C_mutate((C_word*)lf[121]+1 /* (set! srfi-4#u64vector->list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3524,a[2]=((C_word)li86),tmp=(C_word)a,a+=3,tmp));
t53=C_mutate((C_word*)lf[123]+1 /* (set! srfi-4#s64vector->list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3553,a[2]=((C_word)li88),tmp=(C_word)a,a+=3,tmp));
t54=C_mutate((C_word*)lf[125]+1 /* (set! srfi-4#f32vector->list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3582,a[2]=((C_word)li90),tmp=(C_word)a,a+=3,tmp));
t55=C_mutate((C_word*)lf[127]+1 /* (set! srfi-4#f64vector->list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3611,a[2]=((C_word)li92),tmp=(C_word)a,a+=3,tmp));
t56=C_mutate((C_word*)lf[129]+1 /* (set! srfi-4#u8vector? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3640,a[2]=((C_word)li93),tmp=(C_word)a,a+=3,tmp));
t57=C_mutate((C_word*)lf[130]+1 /* (set! srfi-4#s8vector? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3643,a[2]=((C_word)li94),tmp=(C_word)a,a+=3,tmp));
t58=C_mutate((C_word*)lf[131]+1 /* (set! srfi-4#u16vector? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3646,a[2]=((C_word)li95),tmp=(C_word)a,a+=3,tmp));
t59=C_mutate((C_word*)lf[132]+1 /* (set! srfi-4#s16vector? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3649,a[2]=((C_word)li96),tmp=(C_word)a,a+=3,tmp));
t60=C_mutate((C_word*)lf[133]+1 /* (set! srfi-4#u32vector? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3652,a[2]=((C_word)li97),tmp=(C_word)a,a+=3,tmp));
t61=C_mutate((C_word*)lf[134]+1 /* (set! srfi-4#s32vector? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3655,a[2]=((C_word)li98),tmp=(C_word)a,a+=3,tmp));
t62=C_mutate((C_word*)lf[135]+1 /* (set! srfi-4#u64vector? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3658,a[2]=((C_word)li99),tmp=(C_word)a,a+=3,tmp));
t63=C_mutate((C_word*)lf[136]+1 /* (set! srfi-4#s64vector? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3661,a[2]=((C_word)li100),tmp=(C_word)a,a+=3,tmp));
t64=C_mutate((C_word*)lf[137]+1 /* (set! srfi-4#f32vector? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3664,a[2]=((C_word)li101),tmp=(C_word)a,a+=3,tmp));
t65=C_mutate((C_word*)lf[138]+1 /* (set! srfi-4#f64vector? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3667,a[2]=((C_word)li102),tmp=(C_word)a,a+=3,tmp));
t66=C_mutate((C_word*)lf[41]+1 /* (set! srfi-4#number-vector? ...) */,*((C_word*)lf[139]+1));
t67=C_mutate(&lf[140] /* (set! srfi-4#pack-copy ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3682,a[2]=((C_word)li104),tmp=(C_word)a,a+=3,tmp));
t68=C_mutate(&lf[142] /* (set! srfi-4#unpack ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3700,a[2]=((C_word)li106),tmp=(C_word)a,a+=3,tmp));
t69=C_mutate(&lf[144] /* (set! srfi-4#unpack-copy ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3730,a[2]=((C_word)li108),tmp=(C_word)a,a+=3,tmp));
t70=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5618,a[2]=((C_word)li109),tmp=(C_word)a,a+=3,tmp);
t71=C_mutate((C_word*)lf[147]+1 /* (set! srfi-4#u8vector->blob/shared ...) */,t70);
t72=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5611,a[2]=((C_word)li110),tmp=(C_word)a,a+=3,tmp);
t73=C_mutate((C_word*)lf[149]+1 /* (set! srfi-4#s8vector->blob/shared ...) */,t72);
t74=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5604,a[2]=((C_word)li111),tmp=(C_word)a,a+=3,tmp);
t75=C_mutate((C_word*)lf[151]+1 /* (set! srfi-4#u16vector->blob/shared ...) */,t74);
t76=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5597,a[2]=((C_word)li112),tmp=(C_word)a,a+=3,tmp);
t77=C_mutate((C_word*)lf[153]+1 /* (set! srfi-4#s16vector->blob/shared ...) */,t76);
t78=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5590,a[2]=((C_word)li113),tmp=(C_word)a,a+=3,tmp);
t79=C_mutate((C_word*)lf[155]+1 /* (set! srfi-4#u32vector->blob/shared ...) */,t78);
t80=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5583,a[2]=((C_word)li114),tmp=(C_word)a,a+=3,tmp);
t81=C_mutate((C_word*)lf[157]+1 /* (set! srfi-4#s32vector->blob/shared ...) */,t80);
t82=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5576,a[2]=((C_word)li115),tmp=(C_word)a,a+=3,tmp);
t83=C_mutate((C_word*)lf[159]+1 /* (set! srfi-4#u64vector->blob/shared ...) */,t82);
t84=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5569,a[2]=((C_word)li116),tmp=(C_word)a,a+=3,tmp);
t85=C_mutate((C_word*)lf[161]+1 /* (set! srfi-4#s64vector->blob/shared ...) */,t84);
t86=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5562,a[2]=((C_word)li117),tmp=(C_word)a,a+=3,tmp);
t87=C_mutate((C_word*)lf[163]+1 /* (set! srfi-4#f32vector->blob/shared ...) */,t86);
t88=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5555,a[2]=((C_word)li118),tmp=(C_word)a,a+=3,tmp);
t89=C_mutate((C_word*)lf[165]+1 /* (set! srfi-4#f64vector->blob/shared ...) */,t88);
t90=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3806,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:579: pack-copy */
f_3682(t90,lf[43],lf[277]);}

/* ext-free in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1690(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1690,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=stub228(C_SCHEME_UNDEFINED,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* alloc in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_1692(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_1692,5,t1,t2,t3,t4,t5);}
a=C_alloc(7);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1696,a[2]=t4,a[3]=t3,a[4]=t5,a[5]=t1,a[6]=t2,tmp=(C_word)a,a+=7,tmp);
/* srfi-4.scm:273: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[37]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[37]+1);
av2[1]=t6;
av2[2]=t4;
av2[3]=t2;
tp(4,av2);}}

/* k1694 in alloc in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1696(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_1696,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1699,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_fixnum_lessp(((C_word*)t0)[2],C_fix(0)))){
/* srfi-4.scm:274: ##sys#error */
t3=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=lf[36];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_1699(2,av2);}}}

/* k1697 in k1694 in alloc in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1699(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_1699,c,av);}
a=C_alloc(6);
t2=C_i_o_fixnum_times(((C_word*)t0)[2],((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1705,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t2)){
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_1705(2,av2);}}
else{
/* srfi-4.scm:276: ##sys#error */
t4=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[35];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k1703 in k1697 in k1694 in alloc in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1705(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_1705,c,av);}
a=C_alloc(3);
if(C_truep(((C_word*)t0)[2])){
t2=C_fix((C_word)sizeof(size_t) * CHAR_BIT);
t3=C_i_foreign_unsigned_ranged_integer_argumentp(((C_word*)t0)[3],t2);
t4=stub222(C_SCHEME_UNDEFINED,t3);
if(C_truep(t4)){
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
/* srfi-4.scm:280: ##sys#error */
t5=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[5];
av2[3]=lf[33];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1720,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:281: ##sys#allocate-vector */
t3=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
av2[5]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}}

/* k1718 in k1703 in k1697 in k1694 in alloc in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1720(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1720,c,av);}
t2=C_string_to_bytevector(t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#release-number-vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1731(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1731,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1738,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:287: number-vector? */
t4=*((C_word*)lf[41]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k1736 in srfi-4#release-number-vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1738(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1738,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=stub228(C_SCHEME_UNDEFINED,((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* srfi-4.scm:289: ##sys#error */
t2=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[39];
av2[3]=lf[40];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* srfi-4#make-u8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1746(C_word c,C_word *av){
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
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_1746,c,av);}
a=C_alloc(8);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_TRUE:C_get_rest_arg(c,5,av,3,t0));
t11=C_rest_nullp(c,5);
t12=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1824,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t7,a[6]=t10,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* srfi-4.scm:293: alloc */
f_1692(t12,lf[45],C_fix(1),t2,t7);}

/* k1769 in k1822 in srfi-4#make-u8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1771(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_1771,c,av);}
a=C_alloc(10);
if(C_truep(C_i_not(((C_word*)t0)[2]))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1801,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1782,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:109: ##sys#check-exact-uinteger */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[46]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[46]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[45];
tp(4,av2);}}}

/* k1780 in k1769 in k1822 in srfi-4#make-u8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1782(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_1782,c,av);}
if(C_truep(C_fixnum_greaterp(C_i_integer_length(((C_word*)t0)[2]),C_fix(8)))){
t2=C_fix((C_word)C_OUT_OF_RANGE_ERROR);
/* srfi-4.scm:111: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=lf[45];
av2[4]=((C_word*)t0)[2];
av2[5]=C_fix(0);
av2[6]=C_fix(256);
tp(7,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_1801(2,av2);}}}

/* k1799 in k1769 in k1822 in srfi-4#make-u8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1801(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_1801,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1806,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li23),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
  f_1806(t2,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* doloop274 in k1799 in k1769 in k1822 in srfi-4#make-u8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static C_word C_fcall f_1806(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
return(((C_word*)t0)[3]);}
else{
t2=C_u_i_u8vector_set(((C_word*)t0)[3],t1,((C_word*)t0)[4]);
t4=C_fixnum_plus(t1,C_fix(1));
t1=t4;
goto loop;}}

/* k1822 in srfi-4#make-u8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1824(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_1824,c,av);}
a=C_alloc(9);
t2=C_a_i_record2(&a,2,lf[43],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1771,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
if(C_truep(((C_word*)t0)[6])){
/* srfi-4.scm:294: chicken.gc#set-finalizer! */
t4=*((C_word*)lf[47]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_1771(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_1771(2,av2);}}}

/* srfi-4#make-s8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1862(C_word c,C_word *av){
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
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_1862,c,av);}
a=C_alloc(8);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_TRUE:C_get_rest_arg(c,5,av,3,t0));
t11=C_rest_nullp(c,5);
t12=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1940,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t7,a[6]=t10,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* srfi-4.scm:305: alloc */
f_1692(t12,lf[50],C_fix(1),t2,t7);}

/* k1885 in k1938 in srfi-4#make-s8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1887(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_1887,c,av);}
a=C_alloc(10);
if(C_truep(C_i_not(((C_word*)t0)[2]))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1917,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1898,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:109: ##sys#check-exact-uinteger */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[46]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[46]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[50];
tp(4,av2);}}}

/* k1896 in k1885 in k1938 in srfi-4#make-s8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1898(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_1898,c,av);}
if(C_truep(C_fixnum_greaterp(C_i_integer_length(((C_word*)t0)[2]),C_fix(8)))){
t2=C_fix((C_word)C_OUT_OF_RANGE_ERROR);
/* srfi-4.scm:111: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=lf[50];
av2[4]=((C_word*)t0)[2];
av2[5]=C_fix(0);
av2[6]=C_fix(256);
tp(7,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_1917(2,av2);}}}

/* k1915 in k1885 in k1938 in srfi-4#make-s8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1917(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_1917,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1922,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li25),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
  f_1922(t2,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* doloop308 in k1915 in k1885 in k1938 in srfi-4#make-s8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static C_word C_fcall f_1922(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
return(((C_word*)t0)[3]);}
else{
t2=C_u_i_s8vector_set(((C_word*)t0)[3],t1,((C_word*)t0)[4]);
t4=C_fixnum_plus(t1,C_fix(1));
t1=t4;
goto loop;}}

/* k1938 in srfi-4#make-s8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1940(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_1940,c,av);}
a=C_alloc(9);
t2=C_a_i_record2(&a,2,lf[49],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1887,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
if(C_truep(((C_word*)t0)[6])){
/* srfi-4.scm:306: chicken.gc#set-finalizer! */
t4=*((C_word*)lf[47]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_1887(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_1887(2,av2);}}}

/* srfi-4#make-u16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_1978(C_word c,C_word *av){
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
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_1978,c,av);}
a=C_alloc(8);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_TRUE:C_get_rest_arg(c,5,av,3,t0));
t11=C_rest_nullp(c,5);
t12=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2056,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t7,a[6]=t10,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* srfi-4.scm:317: alloc */
f_1692(t12,lf[53],C_fix(2),t2,t7);}

/* k2001 in k2054 in srfi-4#make-u16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2003(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_2003,c,av);}
a=C_alloc(10);
if(C_truep(C_i_not(((C_word*)t0)[2]))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2033,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2014,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:109: ##sys#check-exact-uinteger */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[46]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[46]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[53];
tp(4,av2);}}}

/* k2012 in k2001 in k2054 in srfi-4#make-u16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2014(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_2014,c,av);}
if(C_truep(C_fixnum_greaterp(C_i_integer_length(((C_word*)t0)[2]),C_fix(16)))){
t2=C_fix((C_word)C_OUT_OF_RANGE_ERROR);
/* srfi-4.scm:111: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=lf[53];
av2[4]=((C_word*)t0)[2];
av2[5]=C_fix(0);
av2[6]=C_fix(65536);
tp(7,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_2033(2,av2);}}}

/* k2031 in k2001 in k2054 in srfi-4#make-u16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2033(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2033,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2038,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li27),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
  f_2038(t2,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* doloop342 in k2031 in k2001 in k2054 in srfi-4#make-u16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static C_word C_fcall f_2038(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
return(((C_word*)t0)[3]);}
else{
t2=C_u_i_u16vector_set(((C_word*)t0)[3],t1,((C_word*)t0)[4]);
t4=C_fixnum_plus(t1,C_fix(1));
t1=t4;
goto loop;}}

/* k2054 in srfi-4#make-u16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2056(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2056,c,av);}
a=C_alloc(9);
t2=C_a_i_record2(&a,2,lf[52],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2003,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
if(C_truep(((C_word*)t0)[6])){
/* srfi-4.scm:318: chicken.gc#set-finalizer! */
t4=*((C_word*)lf[47]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2003(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2003(2,av2);}}}

/* srfi-4#make-s16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2094(C_word c,C_word *av){
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
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_2094,c,av);}
a=C_alloc(8);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_TRUE:C_get_rest_arg(c,5,av,3,t0));
t11=C_rest_nullp(c,5);
t12=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2182,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t7,a[6]=t10,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* srfi-4.scm:329: alloc */
f_1692(t12,lf[56],C_fix(2),t2,t7);}

/* k2117 in k2180 in srfi-4#make-s16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2119(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_2119,c,av);}
a=C_alloc(10);
if(C_truep(C_i_not(((C_word*)t0)[2]))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2159,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2130,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:115: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[57]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[57]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[56];
tp(4,av2);}}}

/* k2128 in k2117 in k2180 in srfi-4#make-s16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2130(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(58,c,6)))){
C_save_and_reclaim((void *)f_2130,c,av);}
a=C_alloc(58);
t2=C_i_integer_length(((C_word*)t0)[2]);
t3=C_fixnum_difference(C_fix(16),C_fix(1));
if(C_truep(C_fixnum_greaterp(t2,t3))){
t4=C_fix((C_word)C_OUT_OF_RANGE_ERROR);
t5=C_s_a_i_negate(&a,1,C_fix(65536));
t6=C_s_a_i_minus(&a,2,C_fix(65536),C_fix(1));
/* srfi-4.scm:117: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t4;
av2[3]=lf[56];
av2[4]=((C_word*)t0)[2];
av2[5]=t5;
av2[6]=t6;
tp(7,av2);}}
else{
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
f_2159(2,av2);}}}

/* k2157 in k2117 in k2180 in srfi-4#make-s16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2159(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2159,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2164,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li29),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
  f_2164(t2,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* doloop376 in k2157 in k2117 in k2180 in srfi-4#make-s16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static C_word C_fcall f_2164(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
return(((C_word*)t0)[3]);}
else{
t2=C_u_i_s16vector_set(((C_word*)t0)[3],t1,((C_word*)t0)[4]);
t4=C_fixnum_plus(t1,C_fix(1));
t1=t4;
goto loop;}}

/* k2180 in srfi-4#make-s16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2182(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2182,c,av);}
a=C_alloc(9);
t2=C_a_i_record2(&a,2,lf[55],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2119,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
if(C_truep(((C_word*)t0)[6])){
/* srfi-4.scm:330: chicken.gc#set-finalizer! */
t4=*((C_word*)lf[47]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2119(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2119(2,av2);}}}

/* srfi-4#make-u32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2220(C_word c,C_word *av){
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
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_2220,c,av);}
a=C_alloc(8);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_TRUE:C_get_rest_arg(c,5,av,3,t0));
t11=C_rest_nullp(c,5);
t12=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2298,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t7,a[6]=t10,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* srfi-4.scm:341: alloc */
f_1692(t12,lf[60],C_fix(4),t2,t7);}

/* k2243 in k2296 in srfi-4#make-u32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2245(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_2245,c,av);}
a=C_alloc(10);
if(C_truep(C_i_not(((C_word*)t0)[2]))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2275,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2256,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:109: ##sys#check-exact-uinteger */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[46]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[46]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[60];
tp(4,av2);}}}

/* k2254 in k2243 in k2296 in srfi-4#make-u32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2256(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_2256,c,av);}
if(C_truep(C_fixnum_greaterp(C_i_integer_length(((C_word*)t0)[2]),C_fix(32)))){
t2=C_fix((C_word)C_OUT_OF_RANGE_ERROR);
/* srfi-4.scm:111: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=lf[60];
av2[4]=((C_word*)t0)[2];
av2[5]=C_fix(0);
av2[6]=lf[61];
tp(7,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_2275(2,av2);}}}

/* k2273 in k2243 in k2296 in srfi-4#make-u32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2275(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2275,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2280,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li31),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
  f_2280(t2,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* doloop410 in k2273 in k2243 in k2296 in srfi-4#make-u32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static C_word C_fcall f_2280(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
return(((C_word*)t0)[3]);}
else{
t2=C_u_i_u32vector_set(((C_word*)t0)[3],t1,((C_word*)t0)[4]);
t4=C_fixnum_plus(t1,C_fix(1));
t1=t4;
goto loop;}}

/* k2296 in srfi-4#make-u32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2298(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2298,c,av);}
a=C_alloc(9);
t2=C_a_i_record2(&a,2,lf[59],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2245,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
if(C_truep(((C_word*)t0)[6])){
/* srfi-4.scm:342: chicken.gc#set-finalizer! */
t4=*((C_word*)lf[47]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2245(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2245(2,av2);}}}

/* srfi-4#make-u64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2336(C_word c,C_word *av){
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
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_2336,c,av);}
a=C_alloc(8);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_TRUE:C_get_rest_arg(c,5,av,3,t0));
t11=C_rest_nullp(c,5);
t12=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2414,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t7,a[6]=t10,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* srfi-4.scm:353: alloc */
f_1692(t12,lf[64],C_fix(8),t2,t7);}

/* k2359 in k2412 in srfi-4#make-u64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2361(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_2361,c,av);}
a=C_alloc(10);
if(C_truep(C_i_not(((C_word*)t0)[2]))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2391,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2372,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:109: ##sys#check-exact-uinteger */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[46]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[46]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[64];
tp(4,av2);}}}

/* k2370 in k2359 in k2412 in srfi-4#make-u64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2372(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_2372,c,av);}
if(C_truep(C_fixnum_greaterp(C_i_integer_length(((C_word*)t0)[2]),C_fix(64)))){
t2=C_fix((C_word)C_OUT_OF_RANGE_ERROR);
/* srfi-4.scm:111: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=lf[64];
av2[4]=((C_word*)t0)[2];
av2[5]=C_fix(0);
av2[6]=lf[65];
tp(7,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_2391(2,av2);}}}

/* k2389 in k2359 in k2412 in srfi-4#make-u64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2391(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2391,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2396,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li33),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
  f_2396(t2,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* doloop444 in k2389 in k2359 in k2412 in srfi-4#make-u64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static C_word C_fcall f_2396(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
return(((C_word*)t0)[3]);}
else{
t2=C_u_i_u64vector_set(((C_word*)t0)[3],t1,((C_word*)t0)[4]);
t4=C_fixnum_plus(t1,C_fix(1));
t1=t4;
goto loop;}}

/* k2412 in srfi-4#make-u64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2414(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2414,c,av);}
a=C_alloc(9);
t2=C_a_i_record2(&a,2,lf[63],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2361,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
if(C_truep(((C_word*)t0)[6])){
/* srfi-4.scm:354: chicken.gc#set-finalizer! */
t4=*((C_word*)lf[47]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2361(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2361(2,av2);}}}

/* srfi-4#make-s32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2452(C_word c,C_word *av){
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
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_2452,c,av);}
a=C_alloc(8);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_TRUE:C_get_rest_arg(c,5,av,3,t0));
t11=C_rest_nullp(c,5);
t12=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2540,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t7,a[6]=t10,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* srfi-4.scm:365: alloc */
f_1692(t12,lf[68],C_fix(4),t2,t7);}

/* k2475 in k2538 in srfi-4#make-s32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2477(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_2477,c,av);}
a=C_alloc(10);
if(C_truep(C_i_not(((C_word*)t0)[2]))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2517,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2488,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:115: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[57]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[57]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[68];
tp(4,av2);}}}

/* k2486 in k2475 in k2538 in srfi-4#make-s32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2488(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(58,c,6)))){
C_save_and_reclaim((void *)f_2488,c,av);}
a=C_alloc(58);
t2=C_i_integer_length(((C_word*)t0)[2]);
t3=C_fixnum_difference(C_fix(32),C_fix(1));
if(C_truep(C_fixnum_greaterp(t2,t3))){
t4=C_fix((C_word)C_OUT_OF_RANGE_ERROR);
t5=C_s_a_i_negate(&a,1,lf[61]);
t6=C_s_a_i_minus(&a,2,lf[61],C_fix(1));
/* srfi-4.scm:117: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t4;
av2[3]=lf[68];
av2[4]=((C_word*)t0)[2];
av2[5]=t5;
av2[6]=t6;
tp(7,av2);}}
else{
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
f_2517(2,av2);}}}

/* k2515 in k2475 in k2538 in srfi-4#make-s32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2517(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2517,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2522,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li35),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
  f_2522(t2,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* doloop478 in k2515 in k2475 in k2538 in srfi-4#make-s32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static C_word C_fcall f_2522(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
return(((C_word*)t0)[3]);}
else{
t2=C_u_i_s32vector_set(((C_word*)t0)[3],t1,((C_word*)t0)[4]);
t4=C_fixnum_plus(t1,C_fix(1));
t1=t4;
goto loop;}}

/* k2538 in srfi-4#make-s32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2540(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2540,c,av);}
a=C_alloc(9);
t2=C_a_i_record2(&a,2,lf[67],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2477,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
if(C_truep(((C_word*)t0)[6])){
/* srfi-4.scm:366: chicken.gc#set-finalizer! */
t4=*((C_word*)lf[47]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2477(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2477(2,av2);}}}

/* srfi-4#make-s64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2578(C_word c,C_word *av){
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
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_2578,c,av);}
a=C_alloc(8);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_TRUE:C_get_rest_arg(c,5,av,3,t0));
t11=C_rest_nullp(c,5);
t12=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2666,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t7,a[6]=t10,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* srfi-4.scm:377: alloc */
f_1692(t12,lf[71],C_fix(8),t2,t7);}

/* k2601 in k2664 in srfi-4#make-s64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2603(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_2603,c,av);}
a=C_alloc(10);
if(C_truep(C_i_not(((C_word*)t0)[2]))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2643,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2614,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:115: ##sys#check-exact-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[57]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[57]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[71];
tp(4,av2);}}}

/* k2612 in k2601 in k2664 in srfi-4#make-s64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2614(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(58,c,6)))){
C_save_and_reclaim((void *)f_2614,c,av);}
a=C_alloc(58);
t2=C_i_integer_length(((C_word*)t0)[2]);
t3=C_fixnum_difference(C_fix(64),C_fix(1));
if(C_truep(C_fixnum_greaterp(t2,t3))){
t4=C_fix((C_word)C_OUT_OF_RANGE_ERROR);
t5=C_s_a_i_negate(&a,1,lf[65]);
t6=C_s_a_i_minus(&a,2,lf[65],C_fix(1));
/* srfi-4.scm:117: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t4;
av2[3]=lf[71];
av2[4]=((C_word*)t0)[2];
av2[5]=t5;
av2[6]=t6;
tp(7,av2);}}
else{
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
f_2643(2,av2);}}}

/* k2641 in k2601 in k2664 in srfi-4#make-s64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2643(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2643,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2648,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li37),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
  f_2648(t2,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* doloop512 in k2641 in k2601 in k2664 in srfi-4#make-s64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static C_word C_fcall f_2648(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
return(((C_word*)t0)[3]);}
else{
t2=C_u_i_s64vector_set(((C_word*)t0)[3],t1,((C_word*)t0)[4]);
t4=C_fixnum_plus(t1,C_fix(1));
t1=t4;
goto loop;}}

/* k2664 in srfi-4#make-s64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2666(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2666,c,av);}
a=C_alloc(9);
t2=C_a_i_record2(&a,2,lf[70],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2603,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
if(C_truep(((C_word*)t0)[6])){
/* srfi-4.scm:378: chicken.gc#set-finalizer! */
t4=*((C_word*)lf[47]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2603(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2603(2,av2);}}}

/* srfi-4#make-f32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2704(C_word c,C_word *av){
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
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_2704,c,av);}
a=C_alloc(10);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_rest_nullp(c,3);
t8=C_rest_nullp(c,4);
t9=(C_truep(t8)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t10=C_rest_nullp(c,4);
t11=C_rest_nullp(c,5);
t12=(C_truep(t11)?C_SCHEME_TRUE:C_get_rest_arg(c,5,av,3,t0));
t13=C_rest_nullp(c,5);
t14=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2777,a[2]=t6,a[3]=t1,a[4]=t2,a[5]=t9,a[6]=t12,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* srfi-4.scm:389: alloc */
f_1692(t14,lf[74],C_fix(4),t2,t9);}

/* k2727 in k2775 in srfi-4#make-f32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2729(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2729,c,av);}
a=C_alloc(6);
if(C_truep(C_i_not(((C_word*)((C_word*)t0)[2])[1]))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2750,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)((C_word*)t0)[2])[1];
t4=C_i_exact_integerp(t3);
t5=(C_truep(t4)?t4:C_i_flonump(t3));
if(C_truep(t5)){
t6=C_SCHEME_UNDEFINED;
t7=t2;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
f_2750(2,av2);}}
else{
t6=C_fix((C_word)C_BAD_ARGUMENT_TYPE_NO_FLONUM_ERROR);
/* srfi-4.scm:99: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=t2;
av2[2]=t6;
av2[3]=lf[74];
av2[4]=t3;
tp(5,av2);}}}}

/* k2748 in k2727 in k2775 in srfi-4#make-f32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2750(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_2750,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2753,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_flonump(((C_word*)((C_word*)t0)[4])[1]))){
t3=t2;
f_2753(t3,C_SCHEME_UNDEFINED);}
else{
t3=C_mutate(((C_word *)((C_word*)t0)[4])+1,C_a_u_i_int_to_flo(&a,1,((C_word*)((C_word*)t0)[4])[1]));
t4=t2;
f_2753(t4,t3);}}

/* k2751 in k2748 in k2727 in k2775 in srfi-4#make-f32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_2753(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_2753,2,t0,t1);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2758,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li39),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[5];{
C_word av2[2];
av2[0]=t3;
av2[1]=(
  f_2758(t2,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* doloop547 in k2751 in k2748 in k2727 in k2775 in srfi-4#make-f32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static C_word C_fcall f_2758(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
return(((C_word*)t0)[3]);}
else{
t2=C_u_i_f32vector_set(((C_word*)t0)[3],t1,((C_word*)((C_word*)t0)[4])[1]);
t4=C_fixnum_plus(t1,C_fix(1));
t1=t4;
goto loop;}}

/* k2775 in srfi-4#make-f32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2777(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2777,c,av);}
a=C_alloc(9);
t2=C_a_i_record2(&a,2,lf[73],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2729,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
if(C_truep(((C_word*)t0)[6])){
/* srfi-4.scm:390: chicken.gc#set-finalizer! */
t4=*((C_word*)lf[47]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2729(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2729(2,av2);}}}

/* srfi-4#make-f64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2815(C_word c,C_word *av){
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
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_2815,c,av);}
a=C_alloc(10);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_rest_nullp(c,3);
t8=C_rest_nullp(c,4);
t9=(C_truep(t8)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t10=C_rest_nullp(c,4);
t11=C_rest_nullp(c,5);
t12=(C_truep(t11)?C_SCHEME_TRUE:C_get_rest_arg(c,5,av,3,t0));
t13=C_rest_nullp(c,5);
t14=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2888,a[2]=t6,a[3]=t1,a[4]=t2,a[5]=t9,a[6]=t12,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* srfi-4.scm:403: alloc */
f_1692(t14,lf[77],C_fix(8),t2,t9);}

/* k2838 in k2886 in srfi-4#make-f64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2840(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2840,c,av);}
a=C_alloc(6);
if(C_truep(C_i_not(((C_word*)((C_word*)t0)[2])[1]))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2861,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)((C_word*)t0)[2])[1];
t4=C_i_exact_integerp(t3);
t5=(C_truep(t4)?t4:C_i_flonump(t3));
if(C_truep(t5)){
t6=C_SCHEME_UNDEFINED;
t7=t2;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
f_2861(2,av2);}}
else{
t6=C_fix((C_word)C_BAD_ARGUMENT_TYPE_NO_FLONUM_ERROR);
/* srfi-4.scm:99: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=t2;
av2[2]=t6;
av2[3]=lf[77];
av2[4]=t3;
tp(5,av2);}}}}

/* k2859 in k2838 in k2886 in srfi-4#make-f64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2861(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_2861,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2864,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_flonump(((C_word*)((C_word*)t0)[4])[1]))){
t3=t2;
f_2864(t3,C_SCHEME_UNDEFINED);}
else{
t3=C_mutate(((C_word *)((C_word*)t0)[4])+1,C_a_u_i_int_to_flo(&a,1,((C_word*)((C_word*)t0)[4])[1]));
t4=t2;
f_2864(t4,t3);}}

/* k2862 in k2859 in k2838 in k2886 in srfi-4#make-f64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_2864(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_2864,2,t0,t1);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2869,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li41),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[5];{
C_word av2[2];
av2[0]=t3;
av2[1]=(
  f_2869(t2,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* doloop583 in k2862 in k2859 in k2838 in k2886 in srfi-4#make-f64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static C_word C_fcall f_2869(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
return(((C_word*)t0)[3]);}
else{
t2=C_u_i_f64vector_set(((C_word*)t0)[3],t1,((C_word*)((C_word*)t0)[4])[1]);
t4=C_fixnum_plus(t1,C_fix(1));
t1=t4;
goto loop;}}

/* k2886 in srfi-4#make-f64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2888(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2888,c,av);}
a=C_alloc(9);
t2=C_a_i_record2(&a,2,lf[76],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2840,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
if(C_truep(((C_word*)t0)[6])){
/* srfi-4.scm:404: chicken.gc#set-finalizer! */
t4=*((C_word*)lf[47]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2840(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2840(2,av2);}}}

/* srfi-4#list->u8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2926(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2926,c,av);}
a=C_alloc(4);
t3=C_i_check_list_2(t2,lf[43]);
t4=C_i_length(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2933,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:439: make-u8vector */
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k2931 in srfi-4#list->u8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2933(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_2933,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2938,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word)li43),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_2938(t5,((C_word*)t0)[3],((C_word*)t0)[2],C_fix(0));}

/* doloop618 in k2931 in srfi-4#list->u8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_2938(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_2938,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_eqp(t2,C_SCHEME_END_OF_LIST))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2945,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t5=(C_truep(C_blockp(t2))?C_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_i_u8vector_set(((C_word*)t0)[2],t3,C_slot(t2,C_fix(0)));
t8=t1;
t9=C_slot(t2,C_fix(1));
t10=C_fixnum_plus(t3,C_fix(1));
t1=t8;
t2=t9;
t3=t10;
goto loop;}
else{
/* srfi-4.scm:439: ##sys#error-not-a-proper-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[79]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[79]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[80];
tp(4,av2);}}}}

/* k2943 in doloop618 in k2931 in srfi-4#list->u8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2945(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2945,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_2938(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* srfi-4#list->s8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2962(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2962,c,av);}
a=C_alloc(4);
t3=C_i_check_list_2(t2,lf[49]);
t4=C_i_length(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2969,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:440: make-s8vector */
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k2967 in srfi-4#list->s8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2969(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_2969,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2974,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word)li45),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_2974(t5,((C_word*)t0)[3],((C_word*)t0)[2],C_fix(0));}

/* doloop631 in k2967 in srfi-4#list->s8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_2974(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_2974,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_eqp(t2,C_SCHEME_END_OF_LIST))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2981,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t5=(C_truep(C_blockp(t2))?C_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_i_s8vector_set(((C_word*)t0)[2],t3,C_slot(t2,C_fix(0)));
t8=t1;
t9=C_slot(t2,C_fix(1));
t10=C_fixnum_plus(t3,C_fix(1));
t1=t8;
t2=t9;
t3=t10;
goto loop;}
else{
/* srfi-4.scm:440: ##sys#error-not-a-proper-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[79]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[79]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[82];
tp(4,av2);}}}}

/* k2979 in doloop631 in k2967 in srfi-4#list->s8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2981(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2981,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_2974(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* srfi-4#list->u16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_2998(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2998,c,av);}
a=C_alloc(4);
t3=C_i_check_list_2(t2,lf[52]);
t4=C_i_length(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3005,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:441: make-u16vector */
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k3003 in srfi-4#list->u16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3005(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_3005,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3010,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word)li47),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_3010(t5,((C_word*)t0)[3],((C_word*)t0)[2],C_fix(0));}

/* doloop644 in k3003 in srfi-4#list->u16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3010(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_3010,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_eqp(t2,C_SCHEME_END_OF_LIST))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3017,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t5=(C_truep(C_blockp(t2))?C_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_i_u16vector_set(((C_word*)t0)[2],t3,C_slot(t2,C_fix(0)));
t8=t1;
t9=C_slot(t2,C_fix(1));
t10=C_fixnum_plus(t3,C_fix(1));
t1=t8;
t2=t9;
t3=t10;
goto loop;}
else{
/* srfi-4.scm:441: ##sys#error-not-a-proper-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[79]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[79]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[84];
tp(4,av2);}}}}

/* k3015 in doloop644 in k3003 in srfi-4#list->u16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3017(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3017,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3010(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* srfi-4#list->s16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3034(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3034,c,av);}
a=C_alloc(4);
t3=C_i_check_list_2(t2,lf[55]);
t4=C_i_length(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3041,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:442: make-s16vector */
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k3039 in srfi-4#list->s16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3041(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_3041,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3046,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word)li49),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_3046(t5,((C_word*)t0)[3],((C_word*)t0)[2],C_fix(0));}

/* doloop657 in k3039 in srfi-4#list->s16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3046(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_3046,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_eqp(t2,C_SCHEME_END_OF_LIST))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3053,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t5=(C_truep(C_blockp(t2))?C_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_i_s16vector_set(((C_word*)t0)[2],t3,C_slot(t2,C_fix(0)));
t8=t1;
t9=C_slot(t2,C_fix(1));
t10=C_fixnum_plus(t3,C_fix(1));
t1=t8;
t2=t9;
t3=t10;
goto loop;}
else{
/* srfi-4.scm:442: ##sys#error-not-a-proper-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[79]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[79]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[86];
tp(4,av2);}}}}

/* k3051 in doloop657 in k3039 in srfi-4#list->s16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3053(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3053,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3046(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* srfi-4#list->u32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3070(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3070,c,av);}
a=C_alloc(4);
t3=C_i_check_list_2(t2,lf[59]);
t4=C_i_length(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3077,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:443: make-u32vector */
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k3075 in srfi-4#list->u32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3077(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_3077,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3082,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word)li51),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_3082(t5,((C_word*)t0)[3],((C_word*)t0)[2],C_fix(0));}

/* doloop670 in k3075 in srfi-4#list->u32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3082(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_3082,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_eqp(t2,C_SCHEME_END_OF_LIST))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3089,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t5=(C_truep(C_blockp(t2))?C_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_i_u32vector_set(((C_word*)t0)[2],t3,C_slot(t2,C_fix(0)));
t8=t1;
t9=C_slot(t2,C_fix(1));
t10=C_fixnum_plus(t3,C_fix(1));
t1=t8;
t2=t9;
t3=t10;
goto loop;}
else{
/* srfi-4.scm:443: ##sys#error-not-a-proper-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[79]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[79]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[88];
tp(4,av2);}}}}

/* k3087 in doloop670 in k3075 in srfi-4#list->u32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3089(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3089,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3082(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* srfi-4#list->s32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3106(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3106,c,av);}
a=C_alloc(4);
t3=C_i_check_list_2(t2,lf[67]);
t4=C_i_length(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3113,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:444: make-s32vector */
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k3111 in srfi-4#list->s32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3113(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_3113,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3118,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word)li53),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_3118(t5,((C_word*)t0)[3],((C_word*)t0)[2],C_fix(0));}

/* doloop683 in k3111 in srfi-4#list->s32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3118(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_3118,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_eqp(t2,C_SCHEME_END_OF_LIST))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3125,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t5=(C_truep(C_blockp(t2))?C_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_i_s32vector_set(((C_word*)t0)[2],t3,C_slot(t2,C_fix(0)));
t8=t1;
t9=C_slot(t2,C_fix(1));
t10=C_fixnum_plus(t3,C_fix(1));
t1=t8;
t2=t9;
t3=t10;
goto loop;}
else{
/* srfi-4.scm:444: ##sys#error-not-a-proper-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[79]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[79]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[90];
tp(4,av2);}}}}

/* k3123 in doloop683 in k3111 in srfi-4#list->s32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3125(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3125,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3118(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* srfi-4#list->u64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3142(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3142,c,av);}
a=C_alloc(4);
t3=C_i_check_list_2(t2,lf[63]);
t4=C_i_length(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3149,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:445: make-u64vector */
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k3147 in srfi-4#list->u64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3149(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_3149,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3154,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word)li55),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_3154(t5,((C_word*)t0)[3],((C_word*)t0)[2],C_fix(0));}

/* doloop696 in k3147 in srfi-4#list->u64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3154(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_3154,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_eqp(t2,C_SCHEME_END_OF_LIST))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3161,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t5=(C_truep(C_blockp(t2))?C_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_i_u64vector_set(((C_word*)t0)[2],t3,C_slot(t2,C_fix(0)));
t8=t1;
t9=C_slot(t2,C_fix(1));
t10=C_fixnum_plus(t3,C_fix(1));
t1=t8;
t2=t9;
t3=t10;
goto loop;}
else{
/* srfi-4.scm:445: ##sys#error-not-a-proper-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[79]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[79]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[92];
tp(4,av2);}}}}

/* k3159 in doloop696 in k3147 in srfi-4#list->u64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3161(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3161,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3154(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* srfi-4#list->s64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3178(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3178,c,av);}
a=C_alloc(4);
t3=C_i_check_list_2(t2,lf[70]);
t4=C_i_length(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3185,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:446: make-s64vector */
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)C_fast_retrieve_proc(t6))(3,av2);}}

/* k3183 in srfi-4#list->s64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3185(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_3185,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3190,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word)li57),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_3190(t5,((C_word*)t0)[3],((C_word*)t0)[2],C_fix(0));}

/* doloop709 in k3183 in srfi-4#list->s64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3190(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_3190,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_eqp(t2,C_SCHEME_END_OF_LIST))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3197,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t5=(C_truep(C_blockp(t2))?C_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_i_s64vector_set(((C_word*)t0)[2],t3,C_slot(t2,C_fix(0)));
t8=t1;
t9=C_slot(t2,C_fix(1));
t10=C_fixnum_plus(t3,C_fix(1));
t1=t8;
t2=t9;
t3=t10;
goto loop;}
else{
/* srfi-4.scm:446: ##sys#error-not-a-proper-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[79]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[79]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[94];
tp(4,av2);}}}}

/* k3195 in doloop709 in k3183 in srfi-4#list->s64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3197(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3197,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3190(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* srfi-4#list->f32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3214(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3214,c,av);}
a=C_alloc(4);
t3=C_i_check_list_2(t2,lf[73]);
t4=C_i_length(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3221,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:447: make-f32vector */
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k3219 in srfi-4#list->f32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3221(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_3221,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3226,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word)li59),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_3226(t5,((C_word*)t0)[3],((C_word*)t0)[2],C_fix(0));}

/* doloop722 in k3219 in srfi-4#list->f32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3226(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_3226,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_eqp(t2,C_SCHEME_END_OF_LIST))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3233,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t5=(C_truep(C_blockp(t2))?C_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_i_f32vector_set(((C_word*)t0)[2],t3,C_slot(t2,C_fix(0)));
t8=t1;
t9=C_slot(t2,C_fix(1));
t10=C_fixnum_plus(t3,C_fix(1));
t1=t8;
t2=t9;
t3=t10;
goto loop;}
else{
/* srfi-4.scm:447: ##sys#error-not-a-proper-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[79]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[79]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[96];
tp(4,av2);}}}}

/* k3231 in doloop722 in k3219 in srfi-4#list->f32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3233(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3233,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3226(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* srfi-4#list->f64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3250(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3250,c,av);}
a=C_alloc(4);
t3=C_i_check_list_2(t2,lf[76]);
t4=C_i_length(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3257,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:448: make-f64vector */
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k3255 in srfi-4#list->f64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3257(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_3257,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3262,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word)li61),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_3262(t5,((C_word*)t0)[3],((C_word*)t0)[2],C_fix(0));}

/* doloop735 in k3255 in srfi-4#list->f64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3262(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_3262,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_eqp(t2,C_SCHEME_END_OF_LIST))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3269,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t5=(C_truep(C_blockp(t2))?C_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_i_f64vector_set(((C_word*)t0)[2],t3,C_slot(t2,C_fix(0)));
t8=t1;
t9=C_slot(t2,C_fix(1));
t10=C_fixnum_plus(t3,C_fix(1));
t1=t8;
t2=t9;
t3=t10;
goto loop;}
else{
/* srfi-4.scm:448: ##sys#error-not-a-proper-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[79]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[79]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[98];
tp(4,av2);}}}}

/* k3267 in doloop735 in k3255 in srfi-4#list->f64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3269(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3269,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3262(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* srfi-4#u8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3286(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,2)))){
C_save_and_reclaim((void*)f_3286,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;
/* srfi-4.scm:454: list->u8vector */
t3=*((C_word*)lf[78]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* srfi-4#s8vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3292(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,2)))){
C_save_and_reclaim((void*)f_3292,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;
/* srfi-4.scm:457: list->s8vector */
t3=*((C_word*)lf[81]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* srfi-4#u16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3298(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,2)))){
C_save_and_reclaim((void*)f_3298,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;
/* srfi-4.scm:460: list->u16vector */
t3=*((C_word*)lf[83]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* srfi-4#s16vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3304(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,2)))){
C_save_and_reclaim((void*)f_3304,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;
/* srfi-4.scm:463: list->s16vector */
t3=*((C_word*)lf[85]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* srfi-4#u32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3310(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,2)))){
C_save_and_reclaim((void*)f_3310,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;
/* srfi-4.scm:466: list->u32vector */
t3=*((C_word*)lf[87]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* srfi-4#s32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3316(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,2)))){
C_save_and_reclaim((void*)f_3316,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;
/* srfi-4.scm:469: list->s32vector */
t3=*((C_word*)lf[89]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* srfi-4#u64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3322(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,2)))){
C_save_and_reclaim((void*)f_3322,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;
/* srfi-4.scm:472: list->u64vector */
t3=*((C_word*)lf[91]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* srfi-4#s64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3328(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,2)))){
C_save_and_reclaim((void*)f_3328,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;
/* srfi-4.scm:475: list->s64vector */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[93]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[93]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* srfi-4#f32vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3334(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,2)))){
C_save_and_reclaim((void*)f_3334,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;
/* srfi-4.scm:478: list->f32vector */
t3=*((C_word*)lf[95]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* srfi-4#f64vector in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3340(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,2)))){
C_save_and_reclaim((void*)f_3340,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;
/* srfi-4.scm:481: list->f64vector */
t3=*((C_word*)lf[97]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* srfi-4#u8vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3346(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3346,c,av);}
a=C_alloc(8);
t3=C_i_check_structure_2(t2,lf[43],lf[110]);
t4=C_u_i_u8vector_length(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3355,a[2]=t4,a[3]=t2,a[4]=t6,a[5]=((C_word)li73),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_3355(t8,t1,C_fix(0));}

/* loop in srfi-4#u8vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3355(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3355,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_u_i_u8vector_ref(((C_word*)t0)[3],t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3370,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:504: loop */
t6=t4;
t7=C_fixnum_plus(t2,C_fix(1));
t1=t6;
t2=t7;
goto loop;}}

/* k3368 in loop in srfi-4#u8vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3370(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3370,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* srfi-4#s8vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3376(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3376,c,av);}
a=C_alloc(8);
t3=C_i_check_structure_2(t2,lf[49],lf[112]);
t4=C_u_i_s8vector_length(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3385,a[2]=t4,a[3]=t2,a[4]=t6,a[5]=((C_word)li75),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_3385(t8,t1,C_fix(0));}

/* loop in srfi-4#s8vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3385(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3385,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_u_i_s8vector_ref(((C_word*)t0)[3],t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3400,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:505: loop */
t6=t4;
t7=C_fixnum_plus(t2,C_fix(1));
t1=t6;
t2=t7;
goto loop;}}

/* k3398 in loop in srfi-4#s8vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3400(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3400,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* srfi-4#u16vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3406(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3406,c,av);}
a=C_alloc(8);
t3=C_i_check_structure_2(t2,lf[52],lf[114]);
t4=C_u_i_u16vector_length(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3415,a[2]=t4,a[3]=t2,a[4]=t6,a[5]=((C_word)li77),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_3415(t8,t1,C_fix(0));}

/* loop in srfi-4#u16vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3415(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3415,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_u_i_u16vector_ref(((C_word*)t0)[3],t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3430,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:506: loop */
t6=t4;
t7=C_fixnum_plus(t2,C_fix(1));
t1=t6;
t2=t7;
goto loop;}}

/* k3428 in loop in srfi-4#u16vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3430(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3430,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* srfi-4#s16vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3436(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3436,c,av);}
a=C_alloc(8);
t3=C_i_check_structure_2(t2,lf[55],lf[116]);
t4=C_u_i_s16vector_length(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3445,a[2]=t4,a[3]=t2,a[4]=t6,a[5]=((C_word)li79),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_3445(t8,t1,C_fix(0));}

/* loop in srfi-4#s16vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3445(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3445,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_u_i_s16vector_ref(((C_word*)t0)[3],t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3460,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:507: loop */
t6=t4;
t7=C_fixnum_plus(t2,C_fix(1));
t1=t6;
t2=t7;
goto loop;}}

/* k3458 in loop in srfi-4#s16vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3460(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3460,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* srfi-4#u32vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3466(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3466,c,av);}
a=C_alloc(8);
t3=C_i_check_structure_2(t2,lf[59],lf[118]);
t4=C_u_i_u32vector_length(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3475,a[2]=t4,a[3]=t2,a[4]=t6,a[5]=((C_word)li81),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_3475(t8,t1,C_fix(0));}

/* loop in srfi-4#u32vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3475(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3475,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3489,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* srfi-4.scm:509: loop */
t5=t3;
t6=C_fixnum_plus(t2,C_fix(1));
t1=t5;
t2=t6;
goto loop;}}

/* k3487 in loop in srfi-4#u32vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3489(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_3489,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,C_a_u_i_u32vector_ref(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]),t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* srfi-4#s32vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3495(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3495,c,av);}
a=C_alloc(8);
t3=C_i_check_structure_2(t2,lf[67],lf[120]);
t4=C_u_i_s32vector_length(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3504,a[2]=t4,a[3]=t2,a[4]=t6,a[5]=((C_word)li83),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_3504(t8,t1,C_fix(0));}

/* loop in srfi-4#s32vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3504(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3504,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3518,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* srfi-4.scm:510: loop */
t5=t3;
t6=C_fixnum_plus(t2,C_fix(1));
t1=t5;
t2=t6;
goto loop;}}

/* k3516 in loop in srfi-4#s32vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3518(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_3518,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,C_a_u_i_s32vector_ref(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]),t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* srfi-4#u64vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3524(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3524,c,av);}
a=C_alloc(8);
t3=C_i_check_structure_2(t2,lf[63],lf[122]);
t4=C_u_i_u64vector_length(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3533,a[2]=t4,a[3]=t2,a[4]=t6,a[5]=((C_word)li85),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_3533(t8,t1,C_fix(0));}

/* loop in srfi-4#u64vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3533(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3533,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3547,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* srfi-4.scm:511: loop */
t5=t3;
t6=C_fixnum_plus(t2,C_fix(1));
t1=t5;
t2=t6;
goto loop;}}

/* k3545 in loop in srfi-4#u64vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3547(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,1)))){
C_save_and_reclaim((void *)f_3547,c,av);}
a=C_alloc(10);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,C_a_u_i_u64vector_ref(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]),t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* srfi-4#s64vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3553(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3553,c,av);}
a=C_alloc(8);
t3=C_i_check_structure_2(t2,lf[70],lf[124]);
t4=C_u_i_s64vector_length(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3562,a[2]=t4,a[3]=t2,a[4]=t6,a[5]=((C_word)li87),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_3562(t8,t1,C_fix(0));}

/* loop in srfi-4#s64vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3562(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3562,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3576,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* srfi-4.scm:512: loop */
t5=t3;
t6=C_fixnum_plus(t2,C_fix(1));
t1=t5;
t2=t6;
goto loop;}}

/* k3574 in loop in srfi-4#s64vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3576(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,1)))){
C_save_and_reclaim((void *)f_3576,c,av);}
a=C_alloc(10);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,C_a_u_i_s64vector_ref(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]),t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* srfi-4#f32vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3582(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3582,c,av);}
a=C_alloc(8);
t3=C_i_check_structure_2(t2,lf[73],lf[126]);
t4=C_u_i_f32vector_length(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3591,a[2]=t4,a[3]=t2,a[4]=t6,a[5]=((C_word)li89),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_3591(t8,t1,C_fix(0));}

/* loop in srfi-4#f32vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3591(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3591,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3605,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* srfi-4.scm:513: loop */
t5=t3;
t6=C_fixnum_plus(t2,C_fix(1));
t1=t5;
t2=t6;
goto loop;}}

/* k3603 in loop in srfi-4#f32vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3605(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_3605,c,av);}
a=C_alloc(7);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,C_a_u_i_f32vector_ref(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]),t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* srfi-4#f64vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3611(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3611,c,av);}
a=C_alloc(8);
t3=C_i_check_structure_2(t2,lf[76],lf[128]);
t4=C_u_i_f64vector_length(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3620,a[2]=t4,a[3]=t2,a[4]=t6,a[5]=((C_word)li91),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_3620(t8,t1,C_fix(0));}

/* loop in srfi-4#f64vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3620(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3620,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3634,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* srfi-4.scm:514: loop */
t5=t3;
t6=C_fixnum_plus(t2,C_fix(1));
t1=t5;
t2=t6;
goto loop;}}

/* k3632 in loop in srfi-4#f64vector->list in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3634(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_3634,c,av);}
a=C_alloc(7);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,C_a_u_i_f64vector_ref(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]),t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* srfi-4#u8vector? in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3640(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3640,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_u8vectorp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#s8vector? in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3643(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3643,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_s8vectorp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#u16vector? in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3646(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3646,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_u16vectorp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#s16vector? in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3649(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3649,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_s16vectorp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#u32vector? in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3652(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3652,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_u32vectorp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#s32vector? in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3655(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3655,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_s32vectorp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#u64vector? in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3658(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3658,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_u64vectorp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#s64vector? in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3661(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3661,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_s64vectorp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#f32vector? in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3664(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3664,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_f32vectorp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#f64vector? in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3667(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3667,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_f64vectorp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* srfi-4#pack-copy in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3682(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_3682,3,t1,t2,t3);}
a=C_alloc(5);
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3684,a[2]=t2,a[3]=t3,a[4]=((C_word)li103),tmp=(C_word)a,a+=5,tmp);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* f_3684 in srfi-4#pack-copy in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3684(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3684,c,av);}
a=C_alloc(4);
t3=C_i_check_structure_2(t2,((C_word*)t0)[2],((C_word*)t0)[3]);
t4=C_slot(t2,C_fix(1));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3694,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:544: ##sys#make-blob */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[141]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[141]+1);
av2[1]=t5;
av2[2]=C_block_size(t4);
tp(3,av2);}}

/* k3692 */
static void C_ccall f_3694(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3694,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_copy_block(((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* srfi-4#unpack in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3700(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_3700,4,t1,t2,t3,t4);}
a=C_alloc(6);
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3702,a[2]=t4,a[3]=t3,a[4]=t2,a[5]=((C_word)li105),tmp=(C_word)a,a+=6,tmp);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* f_3702 in srfi-4#unpack in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3702(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3702,c,av);}
a=C_alloc(3);
t3=C_i_check_bytevector_2(t2,((C_word*)t0)[2]);
t4=C_block_size(t2);
t5=C_eqp(C_SCHEME_TRUE,((C_word*)t0)[3]);
t6=(C_truep(t5)?t5:C_eqp(C_fix(0),C_fixnum_modulo(t4,((C_word*)t0)[3])));
if(C_truep(t6)){
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_a_i_record2(&a,2,((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
/* srfi-4.scm:554: ##sys#error */
t7=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t7;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[143];
av2[4]=((C_word*)t0)[4];
av2[5]=t4;
av2[6]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t7+1)))(7,av2);}}}

/* srfi-4#unpack-copy in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_fcall f_3730(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_3730,4,t1,t2,t3,t4);}
a=C_alloc(6);
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3732,a[2]=t4,a[3]=t3,a[4]=t2,a[5]=((C_word)li107),tmp=(C_word)a,a+=6,tmp);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* f_3732 in srfi-4#unpack-copy in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3732(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_3732,c,av);}
a=C_alloc(8);
t3=C_i_check_bytevector_2(t2,((C_word*)t0)[2]);
t4=C_block_size(t2);
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3742,a[2]=((C_word*)t0)[3],a[3]=t4,a[4]=t2,a[5]=t1,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* srfi-4.scm:560: ##sys#make-blob */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[141]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[141]+1);
av2[1]=t5;
av2[2]=t4;
tp(3,av2);}}

/* k3740 */
static void C_ccall f_3742(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3742,c,av);}
a=C_alloc(3);
t2=C_eqp(C_SCHEME_TRUE,((C_word*)t0)[2]);
t3=(C_truep(t2)?t2:C_eqp(C_fix(0),C_fixnum_modulo(((C_word*)t0)[3],((C_word*)t0)[2])));
if(C_truep(t3)){
t4=C_copy_block(((C_word*)t0)[4],t1);
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_record2(&a,2,((C_word*)t0)[6],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
/* srfi-4.scm:566: ##sys#error */
t4=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[5];
av2[2]=((C_word*)t0)[7];
av2[3]=lf[145];
av2[4]=((C_word*)t0)[6];
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}}}

/* k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3806(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3806,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[166]+1 /* (set! srfi-4#u8vector->blob ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3810,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:580: pack-copy */
f_3682(t3,lf[49],lf[276]);}

/* k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3810(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3810,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[167]+1 /* (set! srfi-4#s8vector->blob ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3814,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:581: pack-copy */
f_3682(t3,lf[52],lf[275]);}

/* k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3814(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3814,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[168]+1 /* (set! srfi-4#u16vector->blob ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3818,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:582: pack-copy */
f_3682(t3,lf[55],lf[274]);}

/* k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3818(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3818,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[169]+1 /* (set! srfi-4#s16vector->blob ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3822,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:583: pack-copy */
f_3682(t3,lf[59],lf[273]);}

/* k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3822(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3822,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[170]+1 /* (set! srfi-4#u32vector->blob ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3826,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:584: pack-copy */
f_3682(t3,lf[67],lf[272]);}

/* k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3826(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3826,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[171]+1 /* (set! srfi-4#s32vector->blob ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3830,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:585: pack-copy */
f_3682(t3,lf[63],lf[271]);}

/* k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3830(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3830,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[172]+1 /* (set! srfi-4#u64vector->blob ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3834,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:586: pack-copy */
f_3682(t3,lf[70],lf[270]);}

/* k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_3834(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3834,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[173]+1 /* (set! srfi-4#s64vector->blob ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3838,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:587: pack-copy */
f_3682(t3,lf[73],lf[269]);}

/* k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 in ... */
static void C_ccall f_3838(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3838,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[174]+1 /* (set! srfi-4#f32vector->blob ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3842,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:588: pack-copy */
f_3682(t3,lf[76],lf[268]);}

/* k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in ... */
static void C_ccall f_3842(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3842,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[175]+1 /* (set! srfi-4#f64vector->blob ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3846,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:590: unpack */
f_3700(t3,lf[43],C_SCHEME_TRUE,lf[267]);}

/* k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in ... */
static void C_ccall f_3846(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3846,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[176]+1 /* (set! srfi-4#blob->u8vector/shared ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3850,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:591: unpack */
f_3700(t3,lf[49],C_SCHEME_TRUE,lf[266]);}

/* k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in ... */
static void C_ccall f_3850(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3850,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[177]+1 /* (set! srfi-4#blob->s8vector/shared ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3854,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:592: unpack */
f_3700(t3,lf[52],C_fix(2),lf[265]);}

/* k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in ... */
static void C_ccall f_3854(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3854,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[178]+1 /* (set! srfi-4#blob->u16vector/shared ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3858,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:593: unpack */
f_3700(t3,lf[55],C_fix(2),lf[264]);}

/* k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in ... */
static void C_ccall f_3858(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3858,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[179]+1 /* (set! srfi-4#blob->s16vector/shared ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3862,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:594: unpack */
f_3700(t3,lf[59],C_fix(4),lf[263]);}

/* k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in ... */
static void C_ccall f_3862(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3862,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[180]+1 /* (set! srfi-4#blob->u32vector/shared ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3866,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:595: unpack */
f_3700(t3,lf[67],C_fix(4),lf[262]);}

/* k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in k1660 in ... */
static void C_ccall f_3866(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3866,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[181]+1 /* (set! srfi-4#blob->s32vector/shared ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3870,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:596: unpack */
f_3700(t3,lf[63],C_fix(4),lf[261]);}

/* k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in k1664 in ... */
static void C_ccall f_3870(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3870,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[182]+1 /* (set! srfi-4#blob->u64vector/shared ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3874,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:597: unpack */
f_3700(t3,lf[70],C_fix(4),lf[260]);}

/* k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in k1668 in ... */
static void C_ccall f_3874(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3874,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[183]+1 /* (set! srfi-4#blob->s64vector/shared ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3878,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:598: unpack */
f_3700(t3,lf[73],C_fix(4),lf[259]);}

/* k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in k1672 in ... */
static void C_ccall f_3878(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3878,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[184]+1 /* (set! srfi-4#blob->f32vector/shared ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3882,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:599: unpack */
f_3700(t3,lf[76],C_fix(8),lf[258]);}

/* k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in k1676 in ... */
static void C_ccall f_3882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3882,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[185]+1 /* (set! srfi-4#blob->f64vector/shared ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3886,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:601: unpack-copy */
f_3730(t3,lf[43],C_SCHEME_TRUE,lf[257]);}

/* k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in k1680 in ... */
static void C_ccall f_3886(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3886,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[186]+1 /* (set! srfi-4#blob->u8vector ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3890,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:602: unpack-copy */
f_3730(t3,lf[49],C_SCHEME_TRUE,lf[256]);}

/* k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in k3804 in ... */
static void C_ccall f_3890(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3890,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[187]+1 /* (set! srfi-4#blob->s8vector ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3894,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:603: unpack-copy */
f_3730(t3,lf[52],C_fix(2),lf[255]);}

/* k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in k3808 in ... */
static void C_ccall f_3894(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3894,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[188]+1 /* (set! srfi-4#blob->u16vector ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3898,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:604: unpack-copy */
f_3730(t3,lf[55],C_fix(2),lf[254]);}

/* k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in k3812 in ... */
static void C_ccall f_3898(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3898,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[189]+1 /* (set! srfi-4#blob->s16vector ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3902,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:605: unpack-copy */
f_3730(t3,lf[59],C_fix(4),lf[253]);}

/* k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in k3816 in ... */
static void C_ccall f_3902(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3902,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[190]+1 /* (set! srfi-4#blob->u32vector ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3906,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:606: unpack-copy */
f_3730(t3,lf[67],C_fix(4),lf[252]);}

/* k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in k3820 in ... */
static void C_ccall f_3906(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3906,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[191]+1 /* (set! srfi-4#blob->s32vector ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3910,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:607: unpack-copy */
f_3730(t3,lf[63],C_fix(4),lf[251]);}

/* k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in k3824 in ... */
static void C_ccall f_3910(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3910,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[192]+1 /* (set! srfi-4#blob->u64vector ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3914,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:608: unpack-copy */
f_3730(t3,lf[70],C_fix(4),lf[250]);}

/* k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in k3828 in ... */
static void C_ccall f_3914(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3914,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[193]+1 /* (set! srfi-4#blob->s64vector ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3918,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:609: unpack-copy */
f_3730(t3,lf[73],C_fix(4),lf[249]);}

/* k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in k3832 in ... */
static void C_ccall f_3918(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3918,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[194]+1 /* (set! srfi-4#blob->f32vector ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3922,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:610: unpack-copy */
f_3730(t3,lf[76],C_fix(8),lf[248]);}

/* k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in k3836 in ... */
static void C_ccall f_3922(C_word c,C_word *av){
C_word tmp;
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
if(C_unlikely(!C_demand(C_calculate_demand(114,c,8)))){
C_save_and_reclaim((void *)f_3922,c,av);}
a=C_alloc(114);
t2=C_mutate((C_word*)lf[195]+1 /* (set! srfi-4#blob->f64vector ...) */,t1);
t3=*((C_word*)lf[196]+1);
t4=C_a_i_list(&a,20,lf[197],*((C_word*)lf[78]+1),lf[198],*((C_word*)lf[81]+1),lf[199],*((C_word*)lf[83]+1),lf[200],*((C_word*)lf[85]+1),lf[201],*((C_word*)lf[87]+1),lf[202],*((C_word*)lf[89]+1),lf[203],*((C_word*)lf[91]+1),lf[204],*((C_word*)lf[93]+1),lf[205],*((C_word*)lf[95]+1),lf[206],*((C_word*)lf[97]+1));
t5=C_mutate((C_word*)lf[196]+1 /* (set! ##sys#user-read-hook ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4057,a[2]=t4,a[3]=t3,a[4]=((C_word)li124),tmp=(C_word)a,a+=5,tmp));
t6=*((C_word*)lf[214]+1);
t7=C_mutate((C_word*)lf[214]+1 /* (set! ##sys#user-print-hook ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4170,a[2]=t6,a[3]=((C_word)li125),tmp=(C_word)a,a+=4,tmp));
t8=C_mutate(&lf[216] /* (set! srfi-4#subnvector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4244,a[2]=((C_word)li126),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[217]+1 /* (set! srfi-4#subu8vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4329,a[2]=((C_word)li127),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[219]+1 /* (set! srfi-4#subu16vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4335,a[2]=((C_word)li128),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[221]+1 /* (set! srfi-4#subu32vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4341,a[2]=((C_word)li129),tmp=(C_word)a,a+=3,tmp));
t12=C_mutate((C_word*)lf[223]+1 /* (set! srfi-4#subu64vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4347,a[2]=((C_word)li130),tmp=(C_word)a,a+=3,tmp));
t13=C_mutate((C_word*)lf[225]+1 /* (set! srfi-4#subs8vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4353,a[2]=((C_word)li131),tmp=(C_word)a,a+=3,tmp));
t14=C_mutate((C_word*)lf[227]+1 /* (set! srfi-4#subs16vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4359,a[2]=((C_word)li132),tmp=(C_word)a,a+=3,tmp));
t15=C_mutate((C_word*)lf[229]+1 /* (set! srfi-4#subs32vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4365,a[2]=((C_word)li133),tmp=(C_word)a,a+=3,tmp));
t16=C_mutate((C_word*)lf[231]+1 /* (set! srfi-4#subs64vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4371,a[2]=((C_word)li134),tmp=(C_word)a,a+=3,tmp));
t17=C_mutate((C_word*)lf[233]+1 /* (set! srfi-4#subf32vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4377,a[2]=((C_word)li135),tmp=(C_word)a,a+=3,tmp));
t18=C_mutate((C_word*)lf[235]+1 /* (set! srfi-4#subf64vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4383,a[2]=((C_word)li136),tmp=(C_word)a,a+=3,tmp));
t19=C_mutate((C_word*)lf[237]+1 /* (set! srfi-4#write-u8vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4389,a[2]=((C_word)li137),tmp=(C_word)a,a+=3,tmp));
t20=C_mutate((C_word*)lf[240]+1 /* (set! srfi-4#read-u8vector! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4558,a[2]=((C_word)li138),tmp=(C_word)a,a+=3,tmp));
t21=C_mutate((C_word*)lf[244]+1 /* (set! srfi-4#read-u8vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4638,a[2]=((C_word)li139),tmp=(C_word)a,a+=3,tmp));
t22=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4699,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:757: chicken.platform#register-feature! */
t23=*((C_word*)lf[247]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t23;
av2[1]=t22;
av2[2]=lf[0];
((C_proc)(void*)(*((C_word*)t23+1)))(3,av2);}}

/* loop in k4087 in g986 in k4064 in ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in ... */
static void C_fcall f_3930(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,3)))){
C_save_and_reclaim_args((void *)trf_3930,4,t0,t1,t2,t3);}
a=C_alloc(10);
t4=(C_truep(C_blockp(t2))?C_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=C_slot(t2,C_fix(0));
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3946,a[2]=t7,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=t3,a[6]=((C_word*)t0)[3],a[7]=((C_word)li121),tmp=(C_word)a,a+=8,tmp));
t9=((C_word*)t7)[1];
f_3946(t9,t1,t5);}
else{
if(C_truep(t3)){
t5=C_i_set_i_slot(t3,C_fix(1),C_SCHEME_END_OF_LIST);
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}}

/* retry in loop in k4087 in g986 in k4064 in ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in ... */
static void C_fcall f_3946(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_3946,3,t0,t1,t2);}
a=C_alloc(7);
if(C_truep(C_charp(t2))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3960,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:625: ##sys#char->utf8-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[210]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[210]+1);
av2[1]=t3;
av2[2]=t2;
tp(3,av2);}}
else{
if(C_truep(C_i_stringp(t2))){
t3=C_block_size(t2);
t4=C_eqp(t3,C_fix(0));
if(C_truep(t4)){
/* srfi-4.scm:628: loop */
t5=((C_word*)((C_word*)t0)[3])[1];
f_3930(t5,t1,C_slot(((C_word*)t0)[4],C_fix(1)),((C_word*)t0)[5]);}
else{
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3986,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[6],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* ##sys#string->list */
t6=*((C_word*)lf[209]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}}
else{
/* srfi-4.scm:639: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_3930(t3,t1,C_slot(((C_word*)t0)[4],C_fix(1)),((C_word*)t0)[4]);}}}

/* k3958 in retry in loop in k4087 in g986 in k4064 in ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in ... */
static void C_ccall f_3960(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3960,c,av);}
/* srfi-4.scm:625: retry */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3946(t2,((C_word*)t0)[3],t1);}

/* k3984 in retry in loop in k4087 in g986 in k4064 in ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in ... */
static void C_ccall f_3986(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_3986,c,av);}
a=C_alloc(9);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3988,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=((C_word*)t0)[4],a[6]=((C_word)li120),tmp=(C_word)a,a+=7,tmp));
t5=((C_word*)t3)[1];
f_3988(t5,((C_word*)t0)[5],t1,((C_word*)t0)[6]);}

/* loop2 in k3984 in retry in loop in k4087 in g986 in k4064 in ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in ... */
static void C_fcall f_3988(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,2)))){
C_save_and_reclaim_args((void *)trf_3988,4,t0,t1,t2,t3);}
a=C_alloc(11);
t4=C_slot(t2,C_fix(0));
t5=C_fix(C_character_code(t4));
t6=C_slot(((C_word*)t0)[2],C_fix(1));
t7=C_a_i_cons(&a,2,t5,t6);
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3995,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[2],a[6]=t7,a[7]=((C_word*)t0)[4],tmp=(C_word)a,a+=8,tmp);
if(C_truep(t3)){
t9=t8;
f_3995(t9,C_i_setslot(t3,C_fix(1),t7));}
else{
t9=C_mutate(((C_word *)((C_word*)t0)[5])+1,t7);
t10=t8;
f_3995(t10,t9);}}

/* k3993 in loop2 in k3984 in retry in loop in k4087 in g986 in k4064 in ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in ... */
static void C_fcall f_3995(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_3995,2,t0,t1);}
t2=C_slot(((C_word*)t0)[2],C_fix(1));
if(C_truep(C_i_nullp(t2))){
/* srfi-4.scm:637: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_3930(t3,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)),((C_word*)t0)[6]);}
else{
/* srfi-4.scm:638: loop2 */
t3=((C_word*)((C_word*)t0)[7])[1];
f_3988(t3,((C_word*)t0)[4],C_slot(((C_word*)t0)[2],C_fix(1)),((C_word*)t0)[6]);}}

/* ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4057(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4057,c,av);}
a=C_alloc(5);
if(C_truep((C_truep(C_eqp(t2,C_make_character(117)))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,C_make_character(115)))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,C_make_character(102)))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,C_make_character(85)))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,C_make_character(83)))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,C_make_character(70)))?C_SCHEME_TRUE:C_SCHEME_FALSE)))))))){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4066,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* srfi-4.scm:659: read */
t5=*((C_word*)lf[211]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
/* srfi-4.scm:670: old-hook */
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
((C_proc)C_fast_retrieve_proc(t4))(4,av2);}}}

/* k4064 in ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in ... */
static void C_ccall f_4066(C_word c,C_word *av){
C_word tmp;
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4066,c,av);}
a=C_alloc(4);
t2=C_i_symbolp(t1);
t3=(C_truep(t2)?t1:C_SCHEME_FALSE);
t4=C_eqp(t3,lf[207]);
t5=(C_truep(t4)?t4:C_eqp(t3,lf[208]));
if(C_truep(t5)){
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_i_memq(t3,((C_word*)t0)[3]);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4085,a[2]=((C_word*)t0)[4],a[3]=((C_word)li123),tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:661: g986 */
t8=t7;
f_4085(t8,((C_word*)t0)[2],t6);}
else{
/* srfi-4.scm:669: ##sys#read-error */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[212]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[212]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[213];
av2[4]=t3;
tp(5,av2);}}}}

/* g986 in k4064 in ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in ... */
static void C_fcall f_4085(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_4085,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4089,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:664: read */
t4=*((C_word*)lf[211]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4087 in g986 in k4064 in ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in ... */
static void C_ccall f_4089(C_word c,C_word *av){
C_word tmp;
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,4)))){
C_save_and_reclaim((void *)f_4089,c,av);}
a=C_alloc(16);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
if(C_truep(C_i_stringp(((C_word*)t3)[1]))){
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4112,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t6,a[6]=t7,tmp=(C_word)a,a+=7,tmp);
/* ##sys#string->list */
t9=*((C_word*)lf[209]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t8;
av2[2]=((C_word*)t3)[1];
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4153,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t5=((C_word*)t3)[1];
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3930,a[2]=t8,a[3]=t6,a[4]=((C_word)li122),tmp=(C_word)a,a+=5,tmp));
t10=((C_word*)t8)[1];
f_3930(t10,t4,((C_word*)t6)[1],C_SCHEME_FALSE);}}

/* k4110 in k4087 in g986 in k4064 in ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in ... */
static void C_ccall f_4112(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4112,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4115,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4117,a[2]=((C_word*)t0)[5],a[3]=t4,a[4]=((C_word*)t0)[6],a[5]=((C_word)li119),tmp=(C_word)a,a+=6,tmp));
t6=((C_word*)t4)[1];
f_4117(t6,t2,t1);}

/* k4113 in k4110 in k4087 in g986 in k4064 in ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in ... */
static void C_ccall f_4115(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4115,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_slot(((C_word*)t0)[3],C_fix(1));
/* srfi-4.scm:664: g1016 */
t4=C_slot(t3,C_fix(0));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)((C_word*)t0)[2])[1];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* map-loop992 in k4110 in k4087 in g986 in k4064 in ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in ... */
static void C_fcall f_4117(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_4117,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_fix(C_character_code(t3));
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

/* k4151 in k4087 in g986 in k4064 in ##sys#user-read-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in ... */
static void C_ccall f_4153(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4153,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_slot(((C_word*)t0)[3],C_fix(1));
/* srfi-4.scm:664: g1016 */
t4=C_slot(t3,C_fix(0));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)((C_word*)t0)[2])[1];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* ##sys#user-print-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4170(C_word c,C_word *av){
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
C_word t18;
C_word t19;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(126,c,4)))){
C_save_and_reclaim((void *)f_4170,c,av);}
a=C_alloc(126);
t5=C_slot(t2,C_fix(0));
t6=C_a_i_list(&a,3,lf[43],lf[197],*((C_word*)lf[109]+1));
t7=C_a_i_list(&a,3,lf[49],lf[198],*((C_word*)lf[111]+1));
t8=C_a_i_list(&a,3,lf[52],lf[199],*((C_word*)lf[113]+1));
t9=C_a_i_list(&a,3,lf[55],lf[200],*((C_word*)lf[115]+1));
t10=C_a_i_list(&a,3,lf[59],lf[201],*((C_word*)lf[117]+1));
t11=C_a_i_list(&a,3,lf[67],lf[202],*((C_word*)lf[119]+1));
t12=C_a_i_list(&a,3,lf[63],lf[203],*((C_word*)lf[121]+1));
t13=C_a_i_list(&a,3,lf[70],lf[204],*((C_word*)lf[123]+1));
t14=C_a_i_list(&a,3,lf[73],lf[205],*((C_word*)lf[125]+1));
t15=C_a_i_list(&a,3,lf[76],lf[206],*((C_word*)lf[127]+1));
t16=C_a_i_list(&a,10,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15);
t17=C_u_i_assq(t5,t16);
if(C_truep(t17)){
t18=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4182,a[2]=t17,a[3]=t1,a[4]=t4,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* srfi-4.scm:690: ##sys#print */
t19=*((C_word*)lf[215]+1);{
C_word *av2=av;
av2[0]=t19;
av2[1]=t18;
av2[2]=C_make_character(35);
av2[3]=C_SCHEME_FALSE;
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t19+1)))(5,av2);}}
else{
/* srfi-4.scm:693: old-hook */
t18=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t18;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t4;
((C_proc)C_fast_retrieve_proc(t18))(5,av2);}}}

/* k4180 in ##sys#user-print-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in ... */
static void C_ccall f_4182(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4182,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4185,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* srfi-4.scm:691: ##sys#print */
t3=*((C_word*)lf[215]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cadr(((C_word*)t0)[2]);
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4183 in k4180 in ##sys#user-print-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in ... */
static void C_ccall f_4185(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4185,c,av);}
a=C_alloc(4);
t2=C_i_caddr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4195,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* srfi-4.scm:692: g1030 */
t4=t2;{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k4193 in k4183 in k4180 in ##sys#user-print-hook in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in ... */
static void C_ccall f_4195(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4195,c,av);}
/* srfi-4.scm:692: ##sys#print */
t2=*((C_word*)lf[215]+1);{
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

/* srfi-4#subnvector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_fcall f_4244(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7){
C_word tmp;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,0,3)))){
C_save_and_reclaim_args((void *)trf_4244,7,t1,t2,t3,t4,t5,t6,t7);}
a=C_alloc(16);
t8=C_i_check_structure_2(t2,t3,t7);
t9=C_slot(t2,C_fix(1));
t10=C_block_size(t9);
t11=C_u_fixnum_divide(t10,t4);
t12=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4278,a[2]=t6,a[3]=t5,a[4]=t4,a[5]=t3,a[6]=t9,a[7]=t1,a[8]=t11,a[9]=t7,tmp=(C_word)a,a+=10,tmp);
t13=C_fixnum_plus(t11,C_fix(1));
t14=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4259,a[2]=t5,a[3]=t13,a[4]=t12,a[5]=t7,tmp=(C_word)a,a+=6,tmp);
/* srfi-4.scm:102: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[37]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[37]+1);
av2[1]=t14;
av2[2]=t5;
av2[3]=t7;
tp(4,av2);}}

/* k4257 in srfi-4#subnvector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in ... */
static void C_ccall f_4259(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_4259,c,av);}
t2=C_fixnum_less_or_equal_p(C_fix(0),((C_word*)t0)[2]);
t3=(C_truep(t2)?C_fixnum_lessp(((C_word*)t0)[2],((C_word*)t0)[3]):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
f_4278(2,av2);}}
else{
t4=C_fix((C_word)C_OUT_OF_RANGE_ERROR);
/* srfi-4.scm:104: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[4];
av2[2]=t4;
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[2];
av2[5]=C_fix(0);
av2[6]=((C_word*)t0)[3];
tp(7,av2);}}}

/* k4276 in srfi-4#subnvector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in ... */
static void C_ccall f_4278(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_4278,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4302,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t3=C_fixnum_plus(((C_word*)t0)[8],C_fix(1));
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4283,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=t2,a[5]=((C_word*)t0)[9],tmp=(C_word)a,a+=6,tmp);
/* srfi-4.scm:102: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[37]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[37]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[9];
tp(4,av2);}}

/* k4281 in k4276 in srfi-4#subnvector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in ... */
static void C_ccall f_4283(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_4283,c,av);}
t2=C_fixnum_less_or_equal_p(C_fix(0),((C_word*)t0)[2]);
t3=(C_truep(t2)?C_fixnum_lessp(((C_word*)t0)[2],((C_word*)t0)[3]):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
f_4302(2,av2);}}
else{
t4=C_fix((C_word)C_OUT_OF_RANGE_ERROR);
/* srfi-4.scm:104: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[4];
av2[2]=t4;
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[2];
av2[5]=C_fix(0);
av2[6]=((C_word*)t0)[3];
tp(7,av2);}}}

/* k4300 in k4276 in srfi-4#subnvector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in ... */
static void C_ccall f_4302(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_4302,c,av);}
a=C_alloc(8);
t2=C_fixnum_difference(((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_fixnum_times(((C_word*)t0)[4],t2);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4308,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[6],a[6]=t3,a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* srfi-4.scm:706: ##sys#allocate-vector */
t5=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
av2[5]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}

/* k4306 in k4300 in k4276 in srfi-4#subnvector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in ... */
static void C_ccall f_4308(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_4308,c,av);}
a=C_alloc(3);
t2=C_string_to_bytevector(t1);
t3=C_a_i_record2(&a,2,((C_word*)t0)[2],t1);
t4=C_fixnum_times(((C_word*)t0)[3],((C_word*)t0)[4]);
t5=C_copy_subvector(t1,((C_word*)t0)[5],C_fix(0),t4,((C_word*)t0)[6]);
t6=((C_word*)t0)[7];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* srfi-4#subu8vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4329(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4329,c,av);}
/* srfi-4.scm:712: subnvector */
f_4244(t1,t2,lf[43],C_fix(1),t3,t4,lf[218]);}

/* srfi-4#subu16vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4335(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4335,c,av);}
/* srfi-4.scm:713: subnvector */
f_4244(t1,t2,lf[52],C_fix(2),t3,t4,lf[220]);}

/* srfi-4#subu32vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4341(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4341,c,av);}
/* srfi-4.scm:714: subnvector */
f_4244(t1,t2,lf[59],C_fix(4),t3,t4,lf[222]);}

/* srfi-4#subu64vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4347,c,av);}
/* srfi-4.scm:715: subnvector */
f_4244(t1,t2,lf[63],C_fix(8),t3,t4,lf[224]);}

/* srfi-4#subs8vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4353(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4353,c,av);}
/* srfi-4.scm:716: subnvector */
f_4244(t1,t2,lf[49],C_fix(1),t3,t4,lf[226]);}

/* srfi-4#subs16vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4359(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4359,c,av);}
/* srfi-4.scm:717: subnvector */
f_4244(t1,t2,lf[55],C_fix(2),t3,t4,lf[228]);}

/* srfi-4#subs32vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4365(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4365,c,av);}
/* srfi-4.scm:718: subnvector */
f_4244(t1,t2,lf[67],C_fix(4),t3,t4,lf[230]);}

/* srfi-4#subs64vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4371(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4371,c,av);}
/* srfi-4.scm:719: subnvector */
f_4244(t1,t2,lf[70],C_fix(8),t3,t4,lf[232]);}

/* srfi-4#subf32vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4377(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4377,c,av);}
/* srfi-4.scm:720: subnvector */
f_4244(t1,t2,lf[73],C_fix(4),t3,t4,lf[234]);}

/* srfi-4#subf64vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4383(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4383,c,av);}
/* srfi-4.scm:721: subnvector */
f_4244(t1,t2,lf[76],C_fix(8),t3,t4,lf[236]);}

/* srfi-4#write-u8vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4389(C_word c,C_word *av){
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
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_4389,c,av);}
a=C_alloc(13);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?*((C_word*)lf[238]+1):C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_fix(0):C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=C_rest_nullp(c,5);
t10=(C_truep(t9)?C_SCHEME_FALSE:C_get_rest_arg(c,5,av,3,t0));
t11=C_rest_nullp(c,5);
t12=C_i_check_structure_2(t2,lf[43],lf[239]);
t13=C_i_check_port_2(t4,C_fix(2),C_SCHEME_TRUE,lf[239]);
t14=C_u_i_8vector_length(t2);
t15=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4438,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t10,a[6]=t7,a[7]=t14,tmp=(C_word)a,a+=8,tmp);
t16=(C_truep(t10)?C_fixnum_plus(t10,C_fix(1)):C_fixnum_plus(t14,C_fix(1)));
t17=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4419,a[2]=t7,a[3]=t16,a[4]=t15,tmp=(C_word)a,a+=5,tmp);
/* srfi-4.scm:102: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[37]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[37]+1);
av2[1]=t17;
av2[2]=t7;
av2[3]=lf[239];
tp(4,av2);}}

/* k4417 in srfi-4#write-u8vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in ... */
static void C_ccall f_4419(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_4419,c,av);}
t2=C_fixnum_less_or_equal_p(C_fix(0),((C_word*)t0)[2]);
t3=(C_truep(t2)?C_fixnum_lessp(((C_word*)t0)[2],((C_word*)t0)[3]):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
f_4438(2,av2);}}
else{
t4=C_fix((C_word)C_OUT_OF_RANGE_ERROR);
/* srfi-4.scm:104: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[4];
av2[2]=t4;
av2[3]=lf[239];
av2[4]=((C_word*)t0)[2];
av2[5]=C_fix(0);
av2[6]=((C_word*)t0)[3];
tp(7,av2);}}}

/* k4436 in srfi-4#write-u8vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in ... */
static void C_ccall f_4438(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_4438,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4441,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
if(C_truep(((C_word*)t0)[5])){
t3=C_fixnum_plus(((C_word*)t0)[7],C_fix(1));
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4489,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[5],a[4]=t3,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* srfi-4.scm:102: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[37]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[37]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[5];
av2[3]=lf[239];
tp(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_4441(2,av2);}}}

/* k4439 in k4436 in srfi-4#write-u8vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in ... */
static void C_ccall f_4441(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_4441,c,av);}
a=C_alloc(9);
t2=C_slot(((C_word*)t0)[2],C_fix(2));
t3=C_slot(t2,C_fix(3));
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4454,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
t5=C_eqp(((C_word*)t0)[6],C_fix(0));
if(C_truep(t5)){
t6=C_i_not(((C_word*)t0)[5]);
t7=t4;
f_4454(t7,(C_truep(t6)?t6:C_eqp(((C_word*)t0)[5],((C_word*)t0)[7])));}
else{
t6=t4;
f_4454(t6,C_SCHEME_FALSE);}}

/* k4452 in k4439 in k4436 in srfi-4#write-u8vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in ... */
static void C_fcall f_4454(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_4454,2,t0,t1);}
a=C_alloc(5);
if(C_truep(t1)){
/* srfi-4.scm:726: g1151 */
t2=((C_word*)t0)[2];{
C_word av2[4];
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)C_fast_retrieve_proc(t2))(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4464,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[6])){
/* srfi-4.scm:735: subu8vector */
t3=*((C_word*)lf[217]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[7];
av2[4]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
/* srfi-4.scm:735: subu8vector */
t3=*((C_word*)lf[217]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[7];
av2[4]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}}

/* k4462 in k4452 in k4439 in k4436 in srfi-4#write-u8vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in ... */
static void C_ccall f_4464(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4464,c,av);}
/* srfi-4.scm:726: g1151 */
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
av2[3]=C_slot(t1,C_fix(1));
((C_proc)C_fast_retrieve_proc(t2))(4,av2);}}

/* k4487 in k4436 in srfi-4#write-u8vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in ... */
static void C_ccall f_4489(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_4489,c,av);}
t2=C_fixnum_less_or_equal_p(((C_word*)t0)[2],((C_word*)t0)[3]);
t3=(C_truep(t2)?C_fixnum_lessp(((C_word*)t0)[3],((C_word*)t0)[4]):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
f_4441(2,av2);}}
else{
t4=C_fix((C_word)C_OUT_OF_RANGE_ERROR);
/* srfi-4.scm:104: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[5];
av2[2]=t4;
av2[3]=lf[239];
av2[4]=((C_word*)t0)[3];
av2[5]=((C_word*)t0)[2];
av2[6]=((C_word*)t0)[4];
tp(7,av2);}}}

/* srfi-4#read-u8vector! in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4558(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_4558,c,av);}
a=C_alloc(9);
t4=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t5=C_rest_nullp(c,4);
t6=(C_truep(t5)?*((C_word*)lf[241]+1):C_get_rest_arg(c,4,av,4,t0));
t7=C_rest_nullp(c,4);
t8=C_rest_nullp(c,5);
t9=(C_truep(t8)?C_fix(0):C_get_rest_arg(c,5,av,4,t0));
t10=C_rest_nullp(c,5);
t11=C_i_check_port_2(t6,C_fix(1),C_SCHEME_TRUE,lf[242]);
t12=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4577,a[2]=t3,a[3]=t4,a[4]=t9,a[5]=t1,a[6]=t6,tmp=(C_word)a,a+=7,tmp);
/* srfi-4.scm:739: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[37]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[37]+1);
av2[1]=t12;
av2[2]=t9;
av2[3]=lf[242];
tp(4,av2);}}

/* k4575 in srfi-4#read-u8vector! in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in ... */
static void C_ccall f_4577(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_4577,c,av);}
a=C_alloc(7);
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[43],lf[242]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4583,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)((C_word*)t0)[3])[1])){
/* srfi-4.scm:741: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[37]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[37]+1);
av2[1]=t3;
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=lf[242];
tp(4,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_4583(2,av2);}}}

/* k4581 in k4575 in srfi-4#read-u8vector! in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in ... */
static void C_ccall f_4583(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_4583,c,av);}
t2=C_slot(((C_word*)t0)[2],C_fix(1));
t3=C_block_size(t2);
t4=(C_truep(((C_word*)((C_word*)t0)[3])[1])?C_fixnum_less_or_equal_p(C_fixnum_plus(((C_word*)t0)[4],((C_word*)((C_word*)t0)[3])[1]),t3):C_SCHEME_FALSE);
if(C_truep(t4)){
/* srfi-4.scm:746: chicken.io#read-string!/port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[243]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[243]+1);
av2[1]=((C_word*)t0)[5];
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=t2;
av2[4]=((C_word*)t0)[6];
av2[5]=((C_word*)t0)[4];
tp(6,av2);}}
else{
t5=C_fixnum_difference(t3,((C_word*)t0)[4]);
t6=C_set_block_item(((C_word*)t0)[3],0,t5);
/* srfi-4.scm:746: chicken.io#read-string!/port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[243]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[243]+1);
av2[1]=((C_word*)t0)[5];
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=t2;
av2[4]=((C_word*)t0)[6];
av2[5]=((C_word*)t0)[4];
tp(6,av2);}}}

/* srfi-4#read-u8vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4638(C_word c,C_word *av){
C_word tmp;
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_4638,c,av);}
a=C_alloc(5);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?C_SCHEME_FALSE:C_get_rest_arg(c,2,av,2,t0));
t4=C_rest_nullp(c,2);
t5=C_rest_nullp(c,3);
t6=(C_truep(t5)?*((C_word*)lf[241]+1):C_get_rest_arg(c,3,av,2,t0));
t7=C_rest_nullp(c,3);
t8=C_i_check_port_2(t6,C_fix(1),C_SCHEME_TRUE,lf[245]);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4657,a[2]=t1,a[3]=t3,a[4]=t6,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t3)){
/* srfi-4.scm:750: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[37]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[37]+1);
av2[1]=t9;
av2[2]=t3;
av2[3]=lf[245];
tp(4,av2);}}
else{
t10=t9;{
C_word *av2=av;
av2[0]=t10;
av2[1]=C_SCHEME_UNDEFINED;
f_4657(2,av2);}}}

/* k4655 in srfi-4#read-u8vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in ... */
static void C_ccall f_4657(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4657,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4660,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* srfi-4.scm:751: chicken.io#read-string/port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[246]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[246]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
tp(4,av2);}}

/* k4658 in k4655 in srfi-4#read-u8vector in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in ... */
static void C_ccall f_4660(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_4660,c,av);}
a=C_alloc(3);
if(C_truep(C_eofp(t1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_string_to_bytevector(t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record2(&a,2,lf[43],t1);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4697 in k3920 in k3916 in k3912 in k3908 in k3904 in k3900 in k3896 in k3892 in k3888 in k3884 in k3880 in k3876 in k3872 in k3868 in k3864 in k3860 in k3856 in k3852 in k3848 in k3844 in k3840 in ... */
static void C_ccall f_4699(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4699,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a4700 in k1676 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_4701(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,1)))){
C_save_and_reclaim((void *)f_4701,c,av);}
a=C_alloc(4);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_f64vector_ref(&a,2,t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a4703 in k1672 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_4704(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,1)))){
C_save_and_reclaim((void *)f_4704,c,av);}
a=C_alloc(4);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_f32vector_ref(&a,2,t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a4706 in k1668 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_4707(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_4707,c,av);}
a=C_alloc(7);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_s64vector_ref(&a,2,t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a4709 in k1664 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_4710(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_4710,c,av);}
a=C_alloc(7);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_u64vector_ref(&a,2,t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a4712 in k1660 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_4713(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_4713,c,av);}
a=C_alloc(5);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_s32vector_ref(&a,2,t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a4715 in k1656 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_4716(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_4716,c,av);}
a=C_alloc(5);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_u32vector_ref(&a,2,t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a4718 in k1652 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_4719(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4719,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_s16vector_ref(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a4721 in k1648 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_4722(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4722,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_u16vector_ref(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a4724 in k1644 in k1580 in k1577 in k1574 */
static void C_ccall f_4725(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4725,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_s8vector_ref(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a4727 in k1580 in k1577 in k1574 */
static void C_ccall f_4728(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4728,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_u8vector_ref(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_srfi_2d4_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("srfi-4"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_srfi_2d4_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(1866))){
C_save(t1);
C_rereclaim2(1866*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,289);
lf[0]=C_h_intern(&lf[0],6, C_text("srfi-4"));
lf[1]=C_h_intern(&lf[1],7, C_text("srfi-4#"));
lf[2]=C_h_intern(&lf[2],22, C_text("srfi-4#u8vector-length"));
lf[3]=C_h_intern(&lf[3],22, C_text("srfi-4#s8vector-length"));
lf[4]=C_h_intern(&lf[4],23, C_text("srfi-4#u16vector-length"));
lf[5]=C_h_intern(&lf[5],23, C_text("srfi-4#s16vector-length"));
lf[6]=C_h_intern(&lf[6],23, C_text("srfi-4#u32vector-length"));
lf[7]=C_h_intern(&lf[7],23, C_text("srfi-4#s32vector-length"));
lf[8]=C_h_intern(&lf[8],23, C_text("srfi-4#u64vector-length"));
lf[9]=C_h_intern(&lf[9],23, C_text("srfi-4#s64vector-length"));
lf[10]=C_h_intern(&lf[10],23, C_text("srfi-4#f32vector-length"));
lf[11]=C_h_intern(&lf[11],23, C_text("srfi-4#f64vector-length"));
lf[12]=C_h_intern(&lf[12],20, C_text("srfi-4#u8vector-set!"));
lf[13]=C_h_intern(&lf[13],20, C_text("srfi-4#s8vector-set!"));
lf[14]=C_h_intern(&lf[14],21, C_text("srfi-4#u16vector-set!"));
lf[15]=C_h_intern(&lf[15],21, C_text("srfi-4#s16vector-set!"));
lf[16]=C_h_intern(&lf[16],21, C_text("srfi-4#u32vector-set!"));
lf[17]=C_h_intern(&lf[17],21, C_text("srfi-4#s32vector-set!"));
lf[18]=C_h_intern(&lf[18],21, C_text("srfi-4#u64vector-set!"));
lf[19]=C_h_intern(&lf[19],21, C_text("srfi-4#s64vector-set!"));
lf[20]=C_h_intern(&lf[20],21, C_text("srfi-4#f32vector-set!"));
lf[21]=C_h_intern(&lf[21],21, C_text("srfi-4#f64vector-set!"));
lf[22]=C_h_intern(&lf[22],19, C_text("srfi-4#u8vector-ref"));
lf[23]=C_h_intern(&lf[23],19, C_text("srfi-4#s8vector-ref"));
lf[24]=C_h_intern(&lf[24],20, C_text("srfi-4#u16vector-ref"));
lf[25]=C_h_intern(&lf[25],20, C_text("srfi-4#s16vector-ref"));
lf[26]=C_h_intern(&lf[26],20, C_text("srfi-4#u32vector-ref"));
lf[27]=C_h_intern(&lf[27],20, C_text("srfi-4#s32vector-ref"));
lf[28]=C_h_intern(&lf[28],20, C_text("srfi-4#u64vector-ref"));
lf[29]=C_h_intern(&lf[29],20, C_text("srfi-4#s64vector-ref"));
lf[30]=C_h_intern(&lf[30],20, C_text("srfi-4#f32vector-ref"));
lf[31]=C_h_intern(&lf[31],20, C_text("srfi-4#f64vector-ref"));
lf[32]=C_h_intern(&lf[32],11, C_text("##sys#error"));
lf[33]=C_decode_literal(C_heaptop,C_text("\376B\000\000:not enough memory - cannot allocate external number vector"));
lf[34]=C_h_intern(&lf[34],21, C_text("##sys#allocate-vector"));
lf[35]=C_decode_literal(C_heaptop,C_text("\376B\000\000:overflow - cannot allocate the required number of elements"));
lf[36]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020size is negative"));
lf[37]=C_h_intern(&lf[37],18, C_text("##sys#check-fixnum"));
lf[38]=C_h_intern(&lf[38],28, C_text("srfi-4#release-number-vector"));
lf[39]=C_h_intern(&lf[39],21, C_text("release-number-vector"));
lf[40]=C_decode_literal(C_heaptop,C_text("\376B\000\000\047bad argument type - not a number vector"));
lf[41]=C_h_intern(&lf[41],21, C_text("srfi-4#number-vector\077"));
lf[42]=C_h_intern(&lf[42],20, C_text("srfi-4#make-u8vector"));
lf[43]=C_h_intern(&lf[43],8, C_text("u8vector"));
lf[44]=C_h_intern(&lf[44],16, C_text("##sys#error-hook"));
lf[45]=C_h_intern(&lf[45],13, C_text("make-u8vector"));
lf[46]=C_h_intern(&lf[46],26, C_text("##sys#check-exact-uinteger"));
lf[47]=C_h_intern(&lf[47],25, C_text("chicken.gc#set-finalizer!"));
lf[48]=C_h_intern(&lf[48],20, C_text("srfi-4#make-s8vector"));
lf[49]=C_h_intern(&lf[49],8, C_text("s8vector"));
lf[50]=C_h_intern(&lf[50],13, C_text("make-s8vector"));
lf[51]=C_h_intern(&lf[51],21, C_text("srfi-4#make-u16vector"));
lf[52]=C_h_intern(&lf[52],9, C_text("u16vector"));
lf[53]=C_h_intern(&lf[53],14, C_text("make-u16vector"));
lf[54]=C_h_intern(&lf[54],21, C_text("srfi-4#make-s16vector"));
lf[55]=C_h_intern(&lf[55],9, C_text("s16vector"));
lf[56]=C_h_intern(&lf[56],14, C_text("make-s16vector"));
lf[57]=C_h_intern(&lf[57],25, C_text("##sys#check-exact-integer"));
lf[58]=C_h_intern(&lf[58],21, C_text("srfi-4#make-u32vector"));
lf[59]=C_h_intern(&lf[59],9, C_text("u32vector"));
lf[60]=C_h_intern(&lf[60],14, C_text("make-u32vector"));
lf[61]=C_decode_literal(C_heaptop,C_text("\376\302\000\000\011100000000"));
lf[62]=C_h_intern(&lf[62],21, C_text("srfi-4#make-u64vector"));
lf[63]=C_h_intern(&lf[63],9, C_text("u64vector"));
lf[64]=C_h_intern(&lf[64],14, C_text("make-u64vector"));
lf[65]=C_decode_literal(C_heaptop,C_text("\376\302\000\000\02110000000000000000"));
lf[66]=C_h_intern(&lf[66],21, C_text("srfi-4#make-s32vector"));
lf[67]=C_h_intern(&lf[67],9, C_text("s32vector"));
lf[68]=C_h_intern(&lf[68],14, C_text("make-s32vector"));
lf[69]=C_h_intern(&lf[69],21, C_text("srfi-4#make-s64vector"));
lf[70]=C_h_intern(&lf[70],9, C_text("s64vector"));
lf[71]=C_h_intern(&lf[71],14, C_text("make-s64vector"));
lf[72]=C_h_intern(&lf[72],21, C_text("srfi-4#make-f32vector"));
lf[73]=C_h_intern(&lf[73],9, C_text("f32vector"));
lf[74]=C_h_intern(&lf[74],14, C_text("make-f32vector"));
lf[75]=C_h_intern(&lf[75],21, C_text("srfi-4#make-f64vector"));
lf[76]=C_h_intern(&lf[76],9, C_text("f64vector"));
lf[77]=C_h_intern(&lf[77],14, C_text("make-f64vector"));
lf[78]=C_h_intern(&lf[78],21, C_text("srfi-4#list->u8vector"));
lf[79]=C_h_intern(&lf[79],29, C_text("##sys#error-not-a-proper-list"));
lf[80]=C_h_intern(&lf[80],14, C_text("list->u8vector"));
lf[81]=C_h_intern(&lf[81],21, C_text("srfi-4#list->s8vector"));
lf[82]=C_h_intern(&lf[82],14, C_text("list->s8vector"));
lf[83]=C_h_intern(&lf[83],22, C_text("srfi-4#list->u16vector"));
lf[84]=C_h_intern(&lf[84],15, C_text("list->u16vector"));
lf[85]=C_h_intern(&lf[85],22, C_text("srfi-4#list->s16vector"));
lf[86]=C_h_intern(&lf[86],15, C_text("list->s16vector"));
lf[87]=C_h_intern(&lf[87],22, C_text("srfi-4#list->u32vector"));
lf[88]=C_h_intern(&lf[88],15, C_text("list->u32vector"));
lf[89]=C_h_intern(&lf[89],22, C_text("srfi-4#list->s32vector"));
lf[90]=C_h_intern(&lf[90],15, C_text("list->s32vector"));
lf[91]=C_h_intern(&lf[91],22, C_text("srfi-4#list->u64vector"));
lf[92]=C_h_intern(&lf[92],15, C_text("list->u64vector"));
lf[93]=C_h_intern(&lf[93],22, C_text("srfi-4#list->s64vector"));
lf[94]=C_h_intern(&lf[94],15, C_text("list->s64vector"));
lf[95]=C_h_intern(&lf[95],22, C_text("srfi-4#list->f32vector"));
lf[96]=C_h_intern(&lf[96],15, C_text("list->f32vector"));
lf[97]=C_h_intern(&lf[97],22, C_text("srfi-4#list->f64vector"));
lf[98]=C_h_intern(&lf[98],15, C_text("list->f64vector"));
lf[99]=C_h_intern(&lf[99],15, C_text("srfi-4#u8vector"));
lf[100]=C_h_intern(&lf[100],15, C_text("srfi-4#s8vector"));
lf[101]=C_h_intern(&lf[101],16, C_text("srfi-4#u16vector"));
lf[102]=C_h_intern(&lf[102],16, C_text("srfi-4#s16vector"));
lf[103]=C_h_intern(&lf[103],16, C_text("srfi-4#u32vector"));
lf[104]=C_h_intern(&lf[104],16, C_text("srfi-4#s32vector"));
lf[105]=C_h_intern(&lf[105],16, C_text("srfi-4#u64vector"));
lf[106]=C_h_intern(&lf[106],16, C_text("srfi-4#s64vector"));
lf[107]=C_h_intern(&lf[107],16, C_text("srfi-4#f32vector"));
lf[108]=C_h_intern(&lf[108],16, C_text("srfi-4#f64vector"));
lf[109]=C_h_intern(&lf[109],21, C_text("srfi-4#u8vector->list"));
lf[110]=C_h_intern(&lf[110],14, C_text("u8vector->list"));
lf[111]=C_h_intern(&lf[111],21, C_text("srfi-4#s8vector->list"));
lf[112]=C_h_intern(&lf[112],14, C_text("s8vector->list"));
lf[113]=C_h_intern(&lf[113],22, C_text("srfi-4#u16vector->list"));
lf[114]=C_h_intern(&lf[114],15, C_text("u16vector->list"));
lf[115]=C_h_intern(&lf[115],22, C_text("srfi-4#s16vector->list"));
lf[116]=C_h_intern(&lf[116],15, C_text("s16vector->list"));
lf[117]=C_h_intern(&lf[117],22, C_text("srfi-4#u32vector->list"));
lf[118]=C_h_intern(&lf[118],15, C_text("u32vector->list"));
lf[119]=C_h_intern(&lf[119],22, C_text("srfi-4#s32vector->list"));
lf[120]=C_h_intern(&lf[120],15, C_text("s32vector->list"));
lf[121]=C_h_intern(&lf[121],22, C_text("srfi-4#u64vector->list"));
lf[122]=C_h_intern(&lf[122],15, C_text("u64vector->list"));
lf[123]=C_h_intern(&lf[123],22, C_text("srfi-4#s64vector->list"));
lf[124]=C_h_intern(&lf[124],15, C_text("s64vector->list"));
lf[125]=C_h_intern(&lf[125],22, C_text("srfi-4#f32vector->list"));
lf[126]=C_h_intern(&lf[126],15, C_text("f32vector->list"));
lf[127]=C_h_intern(&lf[127],22, C_text("srfi-4#f64vector->list"));
lf[128]=C_h_intern(&lf[128],15, C_text("f64vector->list"));
lf[129]=C_h_intern(&lf[129],16, C_text("srfi-4#u8vector\077"));
lf[130]=C_h_intern(&lf[130],16, C_text("srfi-4#s8vector\077"));
lf[131]=C_h_intern(&lf[131],17, C_text("srfi-4#u16vector\077"));
lf[132]=C_h_intern(&lf[132],17, C_text("srfi-4#s16vector\077"));
lf[133]=C_h_intern(&lf[133],17, C_text("srfi-4#u32vector\077"));
lf[134]=C_h_intern(&lf[134],17, C_text("srfi-4#s32vector\077"));
lf[135]=C_h_intern(&lf[135],17, C_text("srfi-4#u64vector\077"));
lf[136]=C_h_intern(&lf[136],17, C_text("srfi-4#s64vector\077"));
lf[137]=C_h_intern(&lf[137],17, C_text("srfi-4#f32vector\077"));
lf[138]=C_h_intern(&lf[138],17, C_text("srfi-4#f64vector\077"));
lf[139]=C_h_intern(&lf[139],20, C_text("##sys#srfi-4-vector\077"));
lf[141]=C_h_intern(&lf[141],15, C_text("##sys#make-blob"));
lf[143]=C_decode_literal(C_heaptop,C_text("\376B\000\000+blob does not have correct size for packing"));
lf[145]=C_decode_literal(C_heaptop,C_text("\376B\000\000+blob does not have correct size for packing"));
lf[146]=C_h_intern(&lf[146],21, C_text("u8vector->blob/shared"));
lf[147]=C_h_intern(&lf[147],28, C_text("srfi-4#u8vector->blob/shared"));
lf[148]=C_h_intern(&lf[148],21, C_text("s8vector->blob/shared"));
lf[149]=C_h_intern(&lf[149],28, C_text("srfi-4#s8vector->blob/shared"));
lf[150]=C_h_intern(&lf[150],22, C_text("u16vector->blob/shared"));
lf[151]=C_h_intern(&lf[151],29, C_text("srfi-4#u16vector->blob/shared"));
lf[152]=C_h_intern(&lf[152],22, C_text("s16vector->blob/shared"));
lf[153]=C_h_intern(&lf[153],29, C_text("srfi-4#s16vector->blob/shared"));
lf[154]=C_h_intern(&lf[154],22, C_text("u32vector->blob/shared"));
lf[155]=C_h_intern(&lf[155],29, C_text("srfi-4#u32vector->blob/shared"));
lf[156]=C_h_intern(&lf[156],22, C_text("s32vector->blob/shared"));
lf[157]=C_h_intern(&lf[157],29, C_text("srfi-4#s32vector->blob/shared"));
lf[158]=C_h_intern(&lf[158],22, C_text("u64vector->blob/shared"));
lf[159]=C_h_intern(&lf[159],29, C_text("srfi-4#u64vector->blob/shared"));
lf[160]=C_h_intern(&lf[160],22, C_text("s64vector->blob/shared"));
lf[161]=C_h_intern(&lf[161],29, C_text("srfi-4#s64vector->blob/shared"));
lf[162]=C_h_intern(&lf[162],22, C_text("f32vector->blob/shared"));
lf[163]=C_h_intern(&lf[163],29, C_text("srfi-4#f32vector->blob/shared"));
lf[164]=C_h_intern(&lf[164],22, C_text("f64vector->blob/shared"));
lf[165]=C_h_intern(&lf[165],29, C_text("srfi-4#f64vector->blob/shared"));
lf[166]=C_h_intern(&lf[166],21, C_text("srfi-4#u8vector->blob"));
lf[167]=C_h_intern(&lf[167],21, C_text("srfi-4#s8vector->blob"));
lf[168]=C_h_intern(&lf[168],22, C_text("srfi-4#u16vector->blob"));
lf[169]=C_h_intern(&lf[169],22, C_text("srfi-4#s16vector->blob"));
lf[170]=C_h_intern(&lf[170],22, C_text("srfi-4#u32vector->blob"));
lf[171]=C_h_intern(&lf[171],22, C_text("srfi-4#s32vector->blob"));
lf[172]=C_h_intern(&lf[172],22, C_text("srfi-4#u64vector->blob"));
lf[173]=C_h_intern(&lf[173],22, C_text("srfi-4#s64vector->blob"));
lf[174]=C_h_intern(&lf[174],22, C_text("srfi-4#f32vector->blob"));
lf[175]=C_h_intern(&lf[175],22, C_text("srfi-4#f64vector->blob"));
lf[176]=C_h_intern(&lf[176],28, C_text("srfi-4#blob->u8vector/shared"));
lf[177]=C_h_intern(&lf[177],28, C_text("srfi-4#blob->s8vector/shared"));
lf[178]=C_h_intern(&lf[178],29, C_text("srfi-4#blob->u16vector/shared"));
lf[179]=C_h_intern(&lf[179],29, C_text("srfi-4#blob->s16vector/shared"));
lf[180]=C_h_intern(&lf[180],29, C_text("srfi-4#blob->u32vector/shared"));
lf[181]=C_h_intern(&lf[181],29, C_text("srfi-4#blob->s32vector/shared"));
lf[182]=C_h_intern(&lf[182],29, C_text("srfi-4#blob->u64vector/shared"));
lf[183]=C_h_intern(&lf[183],29, C_text("srfi-4#blob->s64vector/shared"));
lf[184]=C_h_intern(&lf[184],29, C_text("srfi-4#blob->f32vector/shared"));
lf[185]=C_h_intern(&lf[185],29, C_text("srfi-4#blob->f64vector/shared"));
lf[186]=C_h_intern(&lf[186],21, C_text("srfi-4#blob->u8vector"));
lf[187]=C_h_intern(&lf[187],21, C_text("srfi-4#blob->s8vector"));
lf[188]=C_h_intern(&lf[188],22, C_text("srfi-4#blob->u16vector"));
lf[189]=C_h_intern(&lf[189],22, C_text("srfi-4#blob->s16vector"));
lf[190]=C_h_intern(&lf[190],22, C_text("srfi-4#blob->u32vector"));
lf[191]=C_h_intern(&lf[191],22, C_text("srfi-4#blob->s32vector"));
lf[192]=C_h_intern(&lf[192],22, C_text("srfi-4#blob->u64vector"));
lf[193]=C_h_intern(&lf[193],22, C_text("srfi-4#blob->s64vector"));
lf[194]=C_h_intern(&lf[194],22, C_text("srfi-4#blob->f32vector"));
lf[195]=C_h_intern(&lf[195],22, C_text("srfi-4#blob->f64vector"));
lf[196]=C_h_intern(&lf[196],20, C_text("##sys#user-read-hook"));
lf[197]=C_h_intern(&lf[197],2, C_text("u8"));
lf[198]=C_h_intern(&lf[198],2, C_text("s8"));
lf[199]=C_h_intern(&lf[199],3, C_text("u16"));
lf[200]=C_h_intern(&lf[200],3, C_text("s16"));
lf[201]=C_h_intern(&lf[201],3, C_text("u32"));
lf[202]=C_h_intern(&lf[202],3, C_text("s32"));
lf[203]=C_h_intern(&lf[203],3, C_text("u64"));
lf[204]=C_h_intern(&lf[204],3, C_text("s64"));
lf[205]=C_h_intern(&lf[205],3, C_text("f32"));
lf[206]=C_h_intern(&lf[206],3, C_text("f64"));
lf[207]=C_h_intern(&lf[207],1, C_text("f"));
lf[208]=C_h_intern(&lf[208],1, C_text("F"));
lf[209]=C_h_intern(&lf[209],18, C_text("##sys#string->list"));
lf[210]=C_h_intern(&lf[210],23, C_text("##sys#char->utf8-string"));
lf[211]=C_h_intern(&lf[211],11, C_text("scheme#read"));
lf[212]=C_h_intern(&lf[212],16, C_text("##sys#read-error"));
lf[213]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031illegal bytevector syntax"));
lf[214]=C_h_intern(&lf[214],21, C_text("##sys#user-print-hook"));
lf[215]=C_h_intern(&lf[215],11, C_text("##sys#print"));
lf[217]=C_h_intern(&lf[217],18, C_text("srfi-4#subu8vector"));
lf[218]=C_h_intern(&lf[218],11, C_text("subu8vector"));
lf[219]=C_h_intern(&lf[219],19, C_text("srfi-4#subu16vector"));
lf[220]=C_h_intern(&lf[220],12, C_text("subu16vector"));
lf[221]=C_h_intern(&lf[221],19, C_text("srfi-4#subu32vector"));
lf[222]=C_h_intern(&lf[222],12, C_text("subu32vector"));
lf[223]=C_h_intern(&lf[223],19, C_text("srfi-4#subu64vector"));
lf[224]=C_h_intern(&lf[224],12, C_text("subu64vector"));
lf[225]=C_h_intern(&lf[225],18, C_text("srfi-4#subs8vector"));
lf[226]=C_h_intern(&lf[226],11, C_text("subs8vector"));
lf[227]=C_h_intern(&lf[227],19, C_text("srfi-4#subs16vector"));
lf[228]=C_h_intern(&lf[228],12, C_text("subs16vector"));
lf[229]=C_h_intern(&lf[229],19, C_text("srfi-4#subs32vector"));
lf[230]=C_h_intern(&lf[230],12, C_text("subs32vector"));
lf[231]=C_h_intern(&lf[231],19, C_text("srfi-4#subs64vector"));
lf[232]=C_h_intern(&lf[232],12, C_text("subs64vector"));
lf[233]=C_h_intern(&lf[233],19, C_text("srfi-4#subf32vector"));
lf[234]=C_h_intern(&lf[234],12, C_text("subf32vector"));
lf[235]=C_h_intern(&lf[235],19, C_text("srfi-4#subf64vector"));
lf[236]=C_h_intern(&lf[236],12, C_text("subf64vector"));
lf[237]=C_h_intern(&lf[237],21, C_text("srfi-4#write-u8vector"));
lf[238]=C_h_intern(&lf[238],21, C_text("##sys#standard-output"));
lf[239]=C_h_intern(&lf[239],14, C_text("write-u8vector"));
lf[240]=C_h_intern(&lf[240],21, C_text("srfi-4#read-u8vector!"));
lf[241]=C_h_intern(&lf[241],20, C_text("##sys#standard-input"));
lf[242]=C_h_intern(&lf[242],14, C_text("read-u8vector!"));
lf[243]=C_h_intern(&lf[243],28, C_text("chicken.io#read-string!/port"));
lf[244]=C_h_intern(&lf[244],20, C_text("srfi-4#read-u8vector"));
lf[245]=C_h_intern(&lf[245],13, C_text("read-u8vector"));
lf[246]=C_h_intern(&lf[246],27, C_text("chicken.io#read-string/port"));
lf[247]=C_h_intern(&lf[247],34, C_text("chicken.platform#register-feature!"));
lf[248]=C_h_intern(&lf[248],15, C_text("blob->f64vector"));
lf[249]=C_h_intern(&lf[249],15, C_text("blob->f32vector"));
lf[250]=C_h_intern(&lf[250],15, C_text("blob->s64vector"));
lf[251]=C_h_intern(&lf[251],15, C_text("blob->u64vector"));
lf[252]=C_h_intern(&lf[252],15, C_text("blob->s32vector"));
lf[253]=C_h_intern(&lf[253],15, C_text("blob->u32vector"));
lf[254]=C_h_intern(&lf[254],15, C_text("blob->s16vector"));
lf[255]=C_h_intern(&lf[255],15, C_text("blob->u16vector"));
lf[256]=C_h_intern(&lf[256],14, C_text("blob->s8vector"));
lf[257]=C_h_intern(&lf[257],14, C_text("blob->u8vector"));
lf[258]=C_h_intern(&lf[258],22, C_text("blob->f64vector/shared"));
lf[259]=C_h_intern(&lf[259],22, C_text("blob->f32vector/shared"));
lf[260]=C_h_intern(&lf[260],22, C_text("blob->s64vector/shared"));
lf[261]=C_h_intern(&lf[261],22, C_text("blob->u64vector/shared"));
lf[262]=C_h_intern(&lf[262],22, C_text("blob->s32vector/shared"));
lf[263]=C_h_intern(&lf[263],22, C_text("blob->u32vector/shared"));
lf[264]=C_h_intern(&lf[264],22, C_text("blob->s16vector/shared"));
lf[265]=C_h_intern(&lf[265],22, C_text("blob->u16vector/shared"));
lf[266]=C_h_intern(&lf[266],21, C_text("blob->s8vector/shared"));
lf[267]=C_h_intern(&lf[267],21, C_text("blob->u8vector/shared"));
lf[268]=C_h_intern(&lf[268],15, C_text("f64vector->blob"));
lf[269]=C_h_intern(&lf[269],15, C_text("f32vector->blob"));
lf[270]=C_h_intern(&lf[270],15, C_text("s64vector->blob"));
lf[271]=C_h_intern(&lf[271],15, C_text("u64vector->blob"));
lf[272]=C_h_intern(&lf[272],15, C_text("s32vector->blob"));
lf[273]=C_h_intern(&lf[273],15, C_text("u32vector->blob"));
lf[274]=C_h_intern(&lf[274],15, C_text("s16vector->blob"));
lf[275]=C_h_intern(&lf[275],15, C_text("u16vector->blob"));
lf[276]=C_h_intern(&lf[276],14, C_text("s8vector->blob"));
lf[277]=C_h_intern(&lf[277],14, C_text("u8vector->blob"));
lf[278]=C_h_intern(&lf[278],31, C_text("chicken.base#getter-with-setter"));
lf[279]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.srfi-4#f64vector-ref v i)"));
lf[280]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.srfi-4#f32vector-ref v i)"));
lf[281]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.srfi-4#s64vector-ref v i)"));
lf[282]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.srfi-4#u64vector-ref v i)"));
lf[283]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.srfi-4#s32vector-ref v i)"));
lf[284]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.srfi-4#u32vector-ref v i)"));
lf[285]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.srfi-4#s16vector-ref v i)"));
lf[286]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.srfi-4#u16vector-ref v i)"));
lf[287]=C_decode_literal(C_heaptop,C_text("\376B\000\000!(chicken.srfi-4#s8vector-ref v i)"));
lf[288]=C_decode_literal(C_heaptop,C_text("\376B\000\000!(chicken.srfi-4#u8vector-ref v i)"));
C_register_lf2(lf,289,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1576,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_expand_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[299] = {
{C_text("f5555:srfi_2d4_2escm"),(void*)f5555},
{C_text("f5562:srfi_2d4_2escm"),(void*)f5562},
{C_text("f5569:srfi_2d4_2escm"),(void*)f5569},
{C_text("f5576:srfi_2d4_2escm"),(void*)f5576},
{C_text("f5583:srfi_2d4_2escm"),(void*)f5583},
{C_text("f5590:srfi_2d4_2escm"),(void*)f5590},
{C_text("f5597:srfi_2d4_2escm"),(void*)f5597},
{C_text("f5604:srfi_2d4_2escm"),(void*)f5604},
{C_text("f5611:srfi_2d4_2escm"),(void*)f5611},
{C_text("f5618:srfi_2d4_2escm"),(void*)f5618},
{C_text("f_1576:srfi_2d4_2escm"),(void*)f_1576},
{C_text("f_1579:srfi_2d4_2escm"),(void*)f_1579},
{C_text("f_1582:srfi_2d4_2escm"),(void*)f_1582},
{C_text("f_1584:srfi_2d4_2escm"),(void*)f_1584},
{C_text("f_1587:srfi_2d4_2escm"),(void*)f_1587},
{C_text("f_1590:srfi_2d4_2escm"),(void*)f_1590},
{C_text("f_1593:srfi_2d4_2escm"),(void*)f_1593},
{C_text("f_1596:srfi_2d4_2escm"),(void*)f_1596},
{C_text("f_1599:srfi_2d4_2escm"),(void*)f_1599},
{C_text("f_1602:srfi_2d4_2escm"),(void*)f_1602},
{C_text("f_1605:srfi_2d4_2escm"),(void*)f_1605},
{C_text("f_1608:srfi_2d4_2escm"),(void*)f_1608},
{C_text("f_1611:srfi_2d4_2escm"),(void*)f_1611},
{C_text("f_1614:srfi_2d4_2escm"),(void*)f_1614},
{C_text("f_1617:srfi_2d4_2escm"),(void*)f_1617},
{C_text("f_1620:srfi_2d4_2escm"),(void*)f_1620},
{C_text("f_1623:srfi_2d4_2escm"),(void*)f_1623},
{C_text("f_1626:srfi_2d4_2escm"),(void*)f_1626},
{C_text("f_1629:srfi_2d4_2escm"),(void*)f_1629},
{C_text("f_1632:srfi_2d4_2escm"),(void*)f_1632},
{C_text("f_1635:srfi_2d4_2escm"),(void*)f_1635},
{C_text("f_1638:srfi_2d4_2escm"),(void*)f_1638},
{C_text("f_1641:srfi_2d4_2escm"),(void*)f_1641},
{C_text("f_1646:srfi_2d4_2escm"),(void*)f_1646},
{C_text("f_1650:srfi_2d4_2escm"),(void*)f_1650},
{C_text("f_1654:srfi_2d4_2escm"),(void*)f_1654},
{C_text("f_1658:srfi_2d4_2escm"),(void*)f_1658},
{C_text("f_1662:srfi_2d4_2escm"),(void*)f_1662},
{C_text("f_1666:srfi_2d4_2escm"),(void*)f_1666},
{C_text("f_1670:srfi_2d4_2escm"),(void*)f_1670},
{C_text("f_1674:srfi_2d4_2escm"),(void*)f_1674},
{C_text("f_1678:srfi_2d4_2escm"),(void*)f_1678},
{C_text("f_1682:srfi_2d4_2escm"),(void*)f_1682},
{C_text("f_1690:srfi_2d4_2escm"),(void*)f_1690},
{C_text("f_1692:srfi_2d4_2escm"),(void*)f_1692},
{C_text("f_1696:srfi_2d4_2escm"),(void*)f_1696},
{C_text("f_1699:srfi_2d4_2escm"),(void*)f_1699},
{C_text("f_1705:srfi_2d4_2escm"),(void*)f_1705},
{C_text("f_1720:srfi_2d4_2escm"),(void*)f_1720},
{C_text("f_1731:srfi_2d4_2escm"),(void*)f_1731},
{C_text("f_1738:srfi_2d4_2escm"),(void*)f_1738},
{C_text("f_1746:srfi_2d4_2escm"),(void*)f_1746},
{C_text("f_1771:srfi_2d4_2escm"),(void*)f_1771},
{C_text("f_1782:srfi_2d4_2escm"),(void*)f_1782},
{C_text("f_1801:srfi_2d4_2escm"),(void*)f_1801},
{C_text("f_1806:srfi_2d4_2escm"),(void*)f_1806},
{C_text("f_1824:srfi_2d4_2escm"),(void*)f_1824},
{C_text("f_1862:srfi_2d4_2escm"),(void*)f_1862},
{C_text("f_1887:srfi_2d4_2escm"),(void*)f_1887},
{C_text("f_1898:srfi_2d4_2escm"),(void*)f_1898},
{C_text("f_1917:srfi_2d4_2escm"),(void*)f_1917},
{C_text("f_1922:srfi_2d4_2escm"),(void*)f_1922},
{C_text("f_1940:srfi_2d4_2escm"),(void*)f_1940},
{C_text("f_1978:srfi_2d4_2escm"),(void*)f_1978},
{C_text("f_2003:srfi_2d4_2escm"),(void*)f_2003},
{C_text("f_2014:srfi_2d4_2escm"),(void*)f_2014},
{C_text("f_2033:srfi_2d4_2escm"),(void*)f_2033},
{C_text("f_2038:srfi_2d4_2escm"),(void*)f_2038},
{C_text("f_2056:srfi_2d4_2escm"),(void*)f_2056},
{C_text("f_2094:srfi_2d4_2escm"),(void*)f_2094},
{C_text("f_2119:srfi_2d4_2escm"),(void*)f_2119},
{C_text("f_2130:srfi_2d4_2escm"),(void*)f_2130},
{C_text("f_2159:srfi_2d4_2escm"),(void*)f_2159},
{C_text("f_2164:srfi_2d4_2escm"),(void*)f_2164},
{C_text("f_2182:srfi_2d4_2escm"),(void*)f_2182},
{C_text("f_2220:srfi_2d4_2escm"),(void*)f_2220},
{C_text("f_2245:srfi_2d4_2escm"),(void*)f_2245},
{C_text("f_2256:srfi_2d4_2escm"),(void*)f_2256},
{C_text("f_2275:srfi_2d4_2escm"),(void*)f_2275},
{C_text("f_2280:srfi_2d4_2escm"),(void*)f_2280},
{C_text("f_2298:srfi_2d4_2escm"),(void*)f_2298},
{C_text("f_2336:srfi_2d4_2escm"),(void*)f_2336},
{C_text("f_2361:srfi_2d4_2escm"),(void*)f_2361},
{C_text("f_2372:srfi_2d4_2escm"),(void*)f_2372},
{C_text("f_2391:srfi_2d4_2escm"),(void*)f_2391},
{C_text("f_2396:srfi_2d4_2escm"),(void*)f_2396},
{C_text("f_2414:srfi_2d4_2escm"),(void*)f_2414},
{C_text("f_2452:srfi_2d4_2escm"),(void*)f_2452},
{C_text("f_2477:srfi_2d4_2escm"),(void*)f_2477},
{C_text("f_2488:srfi_2d4_2escm"),(void*)f_2488},
{C_text("f_2517:srfi_2d4_2escm"),(void*)f_2517},
{C_text("f_2522:srfi_2d4_2escm"),(void*)f_2522},
{C_text("f_2540:srfi_2d4_2escm"),(void*)f_2540},
{C_text("f_2578:srfi_2d4_2escm"),(void*)f_2578},
{C_text("f_2603:srfi_2d4_2escm"),(void*)f_2603},
{C_text("f_2614:srfi_2d4_2escm"),(void*)f_2614},
{C_text("f_2643:srfi_2d4_2escm"),(void*)f_2643},
{C_text("f_2648:srfi_2d4_2escm"),(void*)f_2648},
{C_text("f_2666:srfi_2d4_2escm"),(void*)f_2666},
{C_text("f_2704:srfi_2d4_2escm"),(void*)f_2704},
{C_text("f_2729:srfi_2d4_2escm"),(void*)f_2729},
{C_text("f_2750:srfi_2d4_2escm"),(void*)f_2750},
{C_text("f_2753:srfi_2d4_2escm"),(void*)f_2753},
{C_text("f_2758:srfi_2d4_2escm"),(void*)f_2758},
{C_text("f_2777:srfi_2d4_2escm"),(void*)f_2777},
{C_text("f_2815:srfi_2d4_2escm"),(void*)f_2815},
{C_text("f_2840:srfi_2d4_2escm"),(void*)f_2840},
{C_text("f_2861:srfi_2d4_2escm"),(void*)f_2861},
{C_text("f_2864:srfi_2d4_2escm"),(void*)f_2864},
{C_text("f_2869:srfi_2d4_2escm"),(void*)f_2869},
{C_text("f_2888:srfi_2d4_2escm"),(void*)f_2888},
{C_text("f_2926:srfi_2d4_2escm"),(void*)f_2926},
{C_text("f_2933:srfi_2d4_2escm"),(void*)f_2933},
{C_text("f_2938:srfi_2d4_2escm"),(void*)f_2938},
{C_text("f_2945:srfi_2d4_2escm"),(void*)f_2945},
{C_text("f_2962:srfi_2d4_2escm"),(void*)f_2962},
{C_text("f_2969:srfi_2d4_2escm"),(void*)f_2969},
{C_text("f_2974:srfi_2d4_2escm"),(void*)f_2974},
{C_text("f_2981:srfi_2d4_2escm"),(void*)f_2981},
{C_text("f_2998:srfi_2d4_2escm"),(void*)f_2998},
{C_text("f_3005:srfi_2d4_2escm"),(void*)f_3005},
{C_text("f_3010:srfi_2d4_2escm"),(void*)f_3010},
{C_text("f_3017:srfi_2d4_2escm"),(void*)f_3017},
{C_text("f_3034:srfi_2d4_2escm"),(void*)f_3034},
{C_text("f_3041:srfi_2d4_2escm"),(void*)f_3041},
{C_text("f_3046:srfi_2d4_2escm"),(void*)f_3046},
{C_text("f_3053:srfi_2d4_2escm"),(void*)f_3053},
{C_text("f_3070:srfi_2d4_2escm"),(void*)f_3070},
{C_text("f_3077:srfi_2d4_2escm"),(void*)f_3077},
{C_text("f_3082:srfi_2d4_2escm"),(void*)f_3082},
{C_text("f_3089:srfi_2d4_2escm"),(void*)f_3089},
{C_text("f_3106:srfi_2d4_2escm"),(void*)f_3106},
{C_text("f_3113:srfi_2d4_2escm"),(void*)f_3113},
{C_text("f_3118:srfi_2d4_2escm"),(void*)f_3118},
{C_text("f_3125:srfi_2d4_2escm"),(void*)f_3125},
{C_text("f_3142:srfi_2d4_2escm"),(void*)f_3142},
{C_text("f_3149:srfi_2d4_2escm"),(void*)f_3149},
{C_text("f_3154:srfi_2d4_2escm"),(void*)f_3154},
{C_text("f_3161:srfi_2d4_2escm"),(void*)f_3161},
{C_text("f_3178:srfi_2d4_2escm"),(void*)f_3178},
{C_text("f_3185:srfi_2d4_2escm"),(void*)f_3185},
{C_text("f_3190:srfi_2d4_2escm"),(void*)f_3190},
{C_text("f_3197:srfi_2d4_2escm"),(void*)f_3197},
{C_text("f_3214:srfi_2d4_2escm"),(void*)f_3214},
{C_text("f_3221:srfi_2d4_2escm"),(void*)f_3221},
{C_text("f_3226:srfi_2d4_2escm"),(void*)f_3226},
{C_text("f_3233:srfi_2d4_2escm"),(void*)f_3233},
{C_text("f_3250:srfi_2d4_2escm"),(void*)f_3250},
{C_text("f_3257:srfi_2d4_2escm"),(void*)f_3257},
{C_text("f_3262:srfi_2d4_2escm"),(void*)f_3262},
{C_text("f_3269:srfi_2d4_2escm"),(void*)f_3269},
{C_text("f_3286:srfi_2d4_2escm"),(void*)f_3286},
{C_text("f_3292:srfi_2d4_2escm"),(void*)f_3292},
{C_text("f_3298:srfi_2d4_2escm"),(void*)f_3298},
{C_text("f_3304:srfi_2d4_2escm"),(void*)f_3304},
{C_text("f_3310:srfi_2d4_2escm"),(void*)f_3310},
{C_text("f_3316:srfi_2d4_2escm"),(void*)f_3316},
{C_text("f_3322:srfi_2d4_2escm"),(void*)f_3322},
{C_text("f_3328:srfi_2d4_2escm"),(void*)f_3328},
{C_text("f_3334:srfi_2d4_2escm"),(void*)f_3334},
{C_text("f_3340:srfi_2d4_2escm"),(void*)f_3340},
{C_text("f_3346:srfi_2d4_2escm"),(void*)f_3346},
{C_text("f_3355:srfi_2d4_2escm"),(void*)f_3355},
{C_text("f_3370:srfi_2d4_2escm"),(void*)f_3370},
{C_text("f_3376:srfi_2d4_2escm"),(void*)f_3376},
{C_text("f_3385:srfi_2d4_2escm"),(void*)f_3385},
{C_text("f_3400:srfi_2d4_2escm"),(void*)f_3400},
{C_text("f_3406:srfi_2d4_2escm"),(void*)f_3406},
{C_text("f_3415:srfi_2d4_2escm"),(void*)f_3415},
{C_text("f_3430:srfi_2d4_2escm"),(void*)f_3430},
{C_text("f_3436:srfi_2d4_2escm"),(void*)f_3436},
{C_text("f_3445:srfi_2d4_2escm"),(void*)f_3445},
{C_text("f_3460:srfi_2d4_2escm"),(void*)f_3460},
{C_text("f_3466:srfi_2d4_2escm"),(void*)f_3466},
{C_text("f_3475:srfi_2d4_2escm"),(void*)f_3475},
{C_text("f_3489:srfi_2d4_2escm"),(void*)f_3489},
{C_text("f_3495:srfi_2d4_2escm"),(void*)f_3495},
{C_text("f_3504:srfi_2d4_2escm"),(void*)f_3504},
{C_text("f_3518:srfi_2d4_2escm"),(void*)f_3518},
{C_text("f_3524:srfi_2d4_2escm"),(void*)f_3524},
{C_text("f_3533:srfi_2d4_2escm"),(void*)f_3533},
{C_text("f_3547:srfi_2d4_2escm"),(void*)f_3547},
{C_text("f_3553:srfi_2d4_2escm"),(void*)f_3553},
{C_text("f_3562:srfi_2d4_2escm"),(void*)f_3562},
{C_text("f_3576:srfi_2d4_2escm"),(void*)f_3576},
{C_text("f_3582:srfi_2d4_2escm"),(void*)f_3582},
{C_text("f_3591:srfi_2d4_2escm"),(void*)f_3591},
{C_text("f_3605:srfi_2d4_2escm"),(void*)f_3605},
{C_text("f_3611:srfi_2d4_2escm"),(void*)f_3611},
{C_text("f_3620:srfi_2d4_2escm"),(void*)f_3620},
{C_text("f_3634:srfi_2d4_2escm"),(void*)f_3634},
{C_text("f_3640:srfi_2d4_2escm"),(void*)f_3640},
{C_text("f_3643:srfi_2d4_2escm"),(void*)f_3643},
{C_text("f_3646:srfi_2d4_2escm"),(void*)f_3646},
{C_text("f_3649:srfi_2d4_2escm"),(void*)f_3649},
{C_text("f_3652:srfi_2d4_2escm"),(void*)f_3652},
{C_text("f_3655:srfi_2d4_2escm"),(void*)f_3655},
{C_text("f_3658:srfi_2d4_2escm"),(void*)f_3658},
{C_text("f_3661:srfi_2d4_2escm"),(void*)f_3661},
{C_text("f_3664:srfi_2d4_2escm"),(void*)f_3664},
{C_text("f_3667:srfi_2d4_2escm"),(void*)f_3667},
{C_text("f_3682:srfi_2d4_2escm"),(void*)f_3682},
{C_text("f_3684:srfi_2d4_2escm"),(void*)f_3684},
{C_text("f_3694:srfi_2d4_2escm"),(void*)f_3694},
{C_text("f_3700:srfi_2d4_2escm"),(void*)f_3700},
{C_text("f_3702:srfi_2d4_2escm"),(void*)f_3702},
{C_text("f_3730:srfi_2d4_2escm"),(void*)f_3730},
{C_text("f_3732:srfi_2d4_2escm"),(void*)f_3732},
{C_text("f_3742:srfi_2d4_2escm"),(void*)f_3742},
{C_text("f_3806:srfi_2d4_2escm"),(void*)f_3806},
{C_text("f_3810:srfi_2d4_2escm"),(void*)f_3810},
{C_text("f_3814:srfi_2d4_2escm"),(void*)f_3814},
{C_text("f_3818:srfi_2d4_2escm"),(void*)f_3818},
{C_text("f_3822:srfi_2d4_2escm"),(void*)f_3822},
{C_text("f_3826:srfi_2d4_2escm"),(void*)f_3826},
{C_text("f_3830:srfi_2d4_2escm"),(void*)f_3830},
{C_text("f_3834:srfi_2d4_2escm"),(void*)f_3834},
{C_text("f_3838:srfi_2d4_2escm"),(void*)f_3838},
{C_text("f_3842:srfi_2d4_2escm"),(void*)f_3842},
{C_text("f_3846:srfi_2d4_2escm"),(void*)f_3846},
{C_text("f_3850:srfi_2d4_2escm"),(void*)f_3850},
{C_text("f_3854:srfi_2d4_2escm"),(void*)f_3854},
{C_text("f_3858:srfi_2d4_2escm"),(void*)f_3858},
{C_text("f_3862:srfi_2d4_2escm"),(void*)f_3862},
{C_text("f_3866:srfi_2d4_2escm"),(void*)f_3866},
{C_text("f_3870:srfi_2d4_2escm"),(void*)f_3870},
{C_text("f_3874:srfi_2d4_2escm"),(void*)f_3874},
{C_text("f_3878:srfi_2d4_2escm"),(void*)f_3878},
{C_text("f_3882:srfi_2d4_2escm"),(void*)f_3882},
{C_text("f_3886:srfi_2d4_2escm"),(void*)f_3886},
{C_text("f_3890:srfi_2d4_2escm"),(void*)f_3890},
{C_text("f_3894:srfi_2d4_2escm"),(void*)f_3894},
{C_text("f_3898:srfi_2d4_2escm"),(void*)f_3898},
{C_text("f_3902:srfi_2d4_2escm"),(void*)f_3902},
{C_text("f_3906:srfi_2d4_2escm"),(void*)f_3906},
{C_text("f_3910:srfi_2d4_2escm"),(void*)f_3910},
{C_text("f_3914:srfi_2d4_2escm"),(void*)f_3914},
{C_text("f_3918:srfi_2d4_2escm"),(void*)f_3918},
{C_text("f_3922:srfi_2d4_2escm"),(void*)f_3922},
{C_text("f_3930:srfi_2d4_2escm"),(void*)f_3930},
{C_text("f_3946:srfi_2d4_2escm"),(void*)f_3946},
{C_text("f_3960:srfi_2d4_2escm"),(void*)f_3960},
{C_text("f_3986:srfi_2d4_2escm"),(void*)f_3986},
{C_text("f_3988:srfi_2d4_2escm"),(void*)f_3988},
{C_text("f_3995:srfi_2d4_2escm"),(void*)f_3995},
{C_text("f_4057:srfi_2d4_2escm"),(void*)f_4057},
{C_text("f_4066:srfi_2d4_2escm"),(void*)f_4066},
{C_text("f_4085:srfi_2d4_2escm"),(void*)f_4085},
{C_text("f_4089:srfi_2d4_2escm"),(void*)f_4089},
{C_text("f_4112:srfi_2d4_2escm"),(void*)f_4112},
{C_text("f_4115:srfi_2d4_2escm"),(void*)f_4115},
{C_text("f_4117:srfi_2d4_2escm"),(void*)f_4117},
{C_text("f_4153:srfi_2d4_2escm"),(void*)f_4153},
{C_text("f_4170:srfi_2d4_2escm"),(void*)f_4170},
{C_text("f_4182:srfi_2d4_2escm"),(void*)f_4182},
{C_text("f_4185:srfi_2d4_2escm"),(void*)f_4185},
{C_text("f_4195:srfi_2d4_2escm"),(void*)f_4195},
{C_text("f_4244:srfi_2d4_2escm"),(void*)f_4244},
{C_text("f_4259:srfi_2d4_2escm"),(void*)f_4259},
{C_text("f_4278:srfi_2d4_2escm"),(void*)f_4278},
{C_text("f_4283:srfi_2d4_2escm"),(void*)f_4283},
{C_text("f_4302:srfi_2d4_2escm"),(void*)f_4302},
{C_text("f_4308:srfi_2d4_2escm"),(void*)f_4308},
{C_text("f_4329:srfi_2d4_2escm"),(void*)f_4329},
{C_text("f_4335:srfi_2d4_2escm"),(void*)f_4335},
{C_text("f_4341:srfi_2d4_2escm"),(void*)f_4341},
{C_text("f_4347:srfi_2d4_2escm"),(void*)f_4347},
{C_text("f_4353:srfi_2d4_2escm"),(void*)f_4353},
{C_text("f_4359:srfi_2d4_2escm"),(void*)f_4359},
{C_text("f_4365:srfi_2d4_2escm"),(void*)f_4365},
{C_text("f_4371:srfi_2d4_2escm"),(void*)f_4371},
{C_text("f_4377:srfi_2d4_2escm"),(void*)f_4377},
{C_text("f_4383:srfi_2d4_2escm"),(void*)f_4383},
{C_text("f_4389:srfi_2d4_2escm"),(void*)f_4389},
{C_text("f_4419:srfi_2d4_2escm"),(void*)f_4419},
{C_text("f_4438:srfi_2d4_2escm"),(void*)f_4438},
{C_text("f_4441:srfi_2d4_2escm"),(void*)f_4441},
{C_text("f_4454:srfi_2d4_2escm"),(void*)f_4454},
{C_text("f_4464:srfi_2d4_2escm"),(void*)f_4464},
{C_text("f_4489:srfi_2d4_2escm"),(void*)f_4489},
{C_text("f_4558:srfi_2d4_2escm"),(void*)f_4558},
{C_text("f_4577:srfi_2d4_2escm"),(void*)f_4577},
{C_text("f_4583:srfi_2d4_2escm"),(void*)f_4583},
{C_text("f_4638:srfi_2d4_2escm"),(void*)f_4638},
{C_text("f_4657:srfi_2d4_2escm"),(void*)f_4657},
{C_text("f_4660:srfi_2d4_2escm"),(void*)f_4660},
{C_text("f_4699:srfi_2d4_2escm"),(void*)f_4699},
{C_text("f_4701:srfi_2d4_2escm"),(void*)f_4701},
{C_text("f_4704:srfi_2d4_2escm"),(void*)f_4704},
{C_text("f_4707:srfi_2d4_2escm"),(void*)f_4707},
{C_text("f_4710:srfi_2d4_2escm"),(void*)f_4710},
{C_text("f_4713:srfi_2d4_2escm"),(void*)f_4713},
{C_text("f_4716:srfi_2d4_2escm"),(void*)f_4716},
{C_text("f_4719:srfi_2d4_2escm"),(void*)f_4719},
{C_text("f_4722:srfi_2d4_2escm"),(void*)f_4722},
{C_text("f_4725:srfi_2d4_2escm"),(void*)f_4725},
{C_text("f_4728:srfi_2d4_2escm"),(void*)f_4728},
{C_text("toplevel:srfi_2d4_2escm"),(void*)C_srfi_2d4_toplevel},
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
o|hiding unexported module binding: srfi-4#d 
o|hiding unexported module binding: srfi-4#define-alias 
o|hiding unexported module binding: srfi-4#list->NNNvector 
o|hiding unexported module binding: srfi-4#NNNvector->list 
o|hiding unexported module binding: srfi-4#pack 
o|hiding unexported module binding: srfi-4#pack-copy 
o|hiding unexported module binding: srfi-4#unpack 
o|hiding unexported module binding: srfi-4#unpack-copy 
o|hiding unexported module binding: srfi-4#canonicalize-number-list! 
o|hiding unexported module binding: srfi-4#subnvector 
S|applied compiler syntax:
S|  scheme#map		1
o|eliminated procedure checks: 46 
o|specializations:
o|  2 (##sys#check-input-port * * *)
o|  1 (##sys#check-output-port * * *)
o|  1 (scheme#assq * (list-of pair))
o|  1 (##sys#check-list (or pair list) *)
o|  1 (scheme#memq * list)
o|  1 (scheme#zero? integer)
o|  1 (scheme#string-length string)
o|  3 (chicken.base#sub1 *)
o|  3 (scheme#- *)
o|  8 (chicken.bitwise#integer-length *)
(o e)|safe calls: 445 
(o e)|assignments to immediate values: 1 
o|dropping redundant toplevel assignment: srfi-4#release-number-vector 
o|dropping redundant toplevel assignment: srfi-4#make-u8vector 
o|dropping redundant toplevel assignment: srfi-4#make-s8vector 
o|dropping redundant toplevel assignment: srfi-4#make-u16vector 
o|dropping redundant toplevel assignment: srfi-4#make-s16vector 
o|dropping redundant toplevel assignment: srfi-4#make-u32vector 
o|dropping redundant toplevel assignment: srfi-4#make-u64vector 
o|dropping redundant toplevel assignment: srfi-4#make-s32vector 
o|dropping redundant toplevel assignment: srfi-4#make-s64vector 
o|dropping redundant toplevel assignment: srfi-4#make-f32vector 
o|dropping redundant toplevel assignment: srfi-4#make-f64vector 
o|safe globals: (srfi-4#f64vector-set! srfi-4#f32vector-set! srfi-4#s64vector-set! srfi-4#u64vector-set! srfi-4#s32vector-set! srfi-4#u32vector-set! srfi-4#s16vector-set! srfi-4#u16vector-set! srfi-4#s8vector-set! srfi-4#u8vector-set! srfi-4#f64vector-length srfi-4#f32vector-length srfi-4#s64vector-length srfi-4#u64vector-length srfi-4#s32vector-length srfi-4#u32vector-length srfi-4#s16vector-length srfi-4#u16vector-length srfi-4#s8vector-length srfi-4#u8vector-length) 
o|inlining procedure: k1706 
o|contracted procedure: "(srfi-4.scm:278) ext-alloc220" 
o|inlining procedure: k1706 
o|inlining procedure: k1733 
o|inlining procedure: "(srfi-4.scm:288) ext-free226" 
o|inlining procedure: k1733 
o|inlining procedure: k1772 
o|inlining procedure: k1772 
o|inlining procedure: k1808 
o|inlining procedure: k1808 
o|contracted procedure: "(srfi-4.scm:298) g267268" 
o|inlining procedure: k1783 
o|inlining procedure: k1783 
o|inlining procedure: k1888 
o|inlining procedure: k1888 
o|inlining procedure: k1924 
o|inlining procedure: k1924 
o|contracted procedure: "(srfi-4.scm:310) g301302" 
o|inlining procedure: k1899 
o|inlining procedure: k1899 
o|inlining procedure: k2004 
o|inlining procedure: k2004 
o|inlining procedure: k2040 
o|inlining procedure: k2040 
o|contracted procedure: "(srfi-4.scm:322) g335336" 
o|inlining procedure: k2015 
o|inlining procedure: k2015 
o|inlining procedure: k2120 
o|inlining procedure: k2120 
o|inlining procedure: k2166 
o|inlining procedure: k2166 
o|contracted procedure: "(srfi-4.scm:334) g369370" 
o|inlining procedure: k2131 
o|inlining procedure: k2131 
o|inlining procedure: k2246 
o|inlining procedure: k2246 
o|inlining procedure: k2282 
o|inlining procedure: k2282 
o|contracted procedure: "(srfi-4.scm:346) g403404" 
o|inlining procedure: k2257 
o|inlining procedure: k2257 
o|inlining procedure: k2362 
o|inlining procedure: k2362 
o|inlining procedure: k2398 
o|inlining procedure: k2398 
o|contracted procedure: "(srfi-4.scm:358) g437438" 
o|inlining procedure: k2373 
o|inlining procedure: k2373 
o|inlining procedure: k2478 
o|inlining procedure: k2478 
o|inlining procedure: k2524 
o|inlining procedure: k2524 
o|contracted procedure: "(srfi-4.scm:370) g471472" 
o|inlining procedure: k2489 
o|inlining procedure: k2489 
o|inlining procedure: k2604 
o|inlining procedure: k2604 
o|inlining procedure: k2650 
o|inlining procedure: k2650 
o|contracted procedure: "(srfi-4.scm:382) g505506" 
o|inlining procedure: k2615 
o|inlining procedure: k2615 
o|inlining procedure: k2730 
o|inlining procedure: k2730 
o|inlining procedure: k2760 
o|inlining procedure: k2760 
o|contracted procedure: "(srfi-4.scm:394) g539540" 
o|inlining procedure: k2738 
o|inlining procedure: k2738 
o|inlining procedure: k2841 
o|inlining procedure: k2841 
o|inlining procedure: k2871 
o|inlining procedure: k2871 
o|contracted procedure: "(srfi-4.scm:408) g575576" 
o|inlining procedure: k2849 
o|inlining procedure: k2849 
o|inlining procedure: k2940 
o|inlining procedure: k2940 
o|inlining procedure: k2976 
o|inlining procedure: k2976 
o|inlining procedure: k3012 
o|inlining procedure: k3012 
o|inlining procedure: k3048 
o|inlining procedure: k3048 
o|inlining procedure: k3084 
o|inlining procedure: k3084 
o|inlining procedure: k3120 
o|inlining procedure: k3120 
o|inlining procedure: k3156 
o|inlining procedure: k3156 
o|inlining procedure: k3192 
o|inlining procedure: k3192 
o|inlining procedure: k3228 
o|inlining procedure: k3228 
o|inlining procedure: k3264 
o|inlining procedure: k3264 
o|inlining procedure: k3357 
o|inlining procedure: k3357 
o|inlining procedure: k3387 
o|inlining procedure: k3387 
o|inlining procedure: k3417 
o|inlining procedure: k3417 
o|inlining procedure: k3447 
o|inlining procedure: k3447 
o|inlining procedure: k3477 
o|inlining procedure: k3477 
o|inlining procedure: k3506 
o|inlining procedure: k3506 
o|inlining procedure: k3535 
o|inlining procedure: k3535 
o|inlining procedure: k3564 
o|inlining procedure: k3564 
o|inlining procedure: k3593 
o|inlining procedure: k3593 
o|inlining procedure: k3622 
o|inlining procedure: k3622 
o|inlining procedure: k3710 
o|inlining procedure: k3710 
o|inlining procedure: k3743 
o|inlining procedure: k3743 
o|substituted constant variable: a4063 
o|inlining procedure: k4059 
o|inlining procedure: k4119 
o|inlining procedure: k4119 
o|contracted procedure: "(srfi-4.scm:667) srfi-4#canonicalize-number-list!" 
o|inlining procedure: k3932 
o|inlining procedure: k3948 
o|inlining procedure: k3948 
o|inlining procedure: k3967 
o|inlining procedure: k3967 
o|inlining procedure: k3999 
o|inlining procedure: k3999 
o|inlining procedure: k3932 
o|inlining procedure: k4082 
o|inlining procedure: k4082 
o|inlining procedure: k4059 
o|inlining procedure: k4177 
o|inlining procedure: k4177 
o|contracted procedure: "(srfi-4.scm:704) g10531054" 
o|inlining procedure: k4284 
o|inlining procedure: k4284 
o|contracted procedure: "(srfi-4.scm:703) g10441045" 
o|inlining procedure: k4260 
o|inlining procedure: k4260 
o|substituted constant variable: a4413 
o|substituted constant variable: a4414 
o|inlining procedure: k4449 
o|inlining procedure: k4449 
o|inlining procedure: k4466 
o|inlining procedure: k4466 
o|inlining procedure: k4475 
o|inlining procedure: k4475 
o|contracted procedure: "(srfi-4.scm:728) g11421143" 
o|inlining procedure: k4490 
o|inlining procedure: k4490 
o|contracted procedure: "(srfi-4.scm:727) g11301131" 
o|inlining procedure: k4420 
o|inlining procedure: k4420 
o|inlining procedure: k4518 
o|inlining procedure: k4518 
o|substituted constant variable: a4573 
o|substituted constant variable: a4574 
o|substituted constant variable: a4653 
o|substituted constant variable: a4654 
o|inlining procedure: k4661 
o|inlining procedure: k4661 
o|simplifications: ((if . 1)) 
o|replaced variables: 714 
o|removed binding forms: 317 
o|substituted constant variable: loc271 
o|substituted constant variable: len270 
o|folded constant expression: (scheme#expt (quote 2) (quote 8)) 
o|substituted constant variable: len270 
o|substituted constant variable: loc271 
o|substituted constant variable: loc305 
o|substituted constant variable: len304 
o|folded constant expression: (scheme#expt (quote 2) (quote 8)) 
o|substituted constant variable: len304 
o|substituted constant variable: loc305 
o|substituted constant variable: loc339 
o|substituted constant variable: len338 
o|folded constant expression: (scheme#expt (quote 2) (quote 16)) 
o|substituted constant variable: len338 
o|substituted constant variable: loc339 
o|substituted constant variable: loc373 
o|substituted constant variable: len372 
o|folded constant expression: (scheme#expt (quote 2) (quote 16)) 
o|substituted constant variable: len372 
o|folded constant expression: (scheme#expt (quote 2) (quote 16)) 
o|substituted constant variable: len372 
o|substituted constant variable: loc373 
o|substituted constant variable: loc407 
o|substituted constant variable: len406 
o|folded constant expression: (scheme#expt (quote 2) (quote 32)) 
o|substituted constant variable: len406 
o|substituted constant variable: loc407 
o|substituted constant variable: loc441 
o|substituted constant variable: len440 
o|folded constant expression: (scheme#expt (quote 2) (quote 64)) 
o|substituted constant variable: len440 
o|substituted constant variable: loc441 
o|substituted constant variable: loc475 
o|substituted constant variable: len474 
o|folded constant expression: (scheme#expt (quote 2) (quote 32)) 
o|substituted constant variable: len474 
o|folded constant expression: (scheme#expt (quote 2) (quote 32)) 
o|substituted constant variable: len474 
o|substituted constant variable: loc475 
o|substituted constant variable: loc509 
o|substituted constant variable: len508 
o|folded constant expression: (scheme#expt (quote 2) (quote 64)) 
o|substituted constant variable: len508 
o|folded constant expression: (scheme#expt (quote 2) (quote 64)) 
o|substituted constant variable: len508 
o|substituted constant variable: loc509 
o|substituted constant variable: loc542 
o|substituted constant variable: loc578 
o|substituted constant variable: r33584816 
o|substituted constant variable: r33884818 
o|substituted constant variable: r34184820 
o|substituted constant variable: r34484822 
o|substituted constant variable: r34784824 
o|substituted constant variable: r35074826 
o|substituted constant variable: r35364828 
o|substituted constant variable: r35654830 
o|substituted constant variable: r35944832 
o|substituted constant variable: r36234834 
o|substituted constant variable: from1056 
o|substituted constant variable: from1056 
o|substituted constant variable: from1047 
o|substituted constant variable: from1047 
o|substituted constant variable: loc1147 
o|substituted constant variable: loc1147 
o|substituted constant variable: loc1135 
o|substituted constant variable: from1133 
o|substituted constant variable: from1133 
o|substituted constant variable: loc1135 
o|replaced variables: 134 
o|removed binding forms: 549 
o|inlining procedure: k1709 
o|contracted procedure: k1794 
o|inlining procedure: k1815 
o|inlining procedure: k1815 
o|contracted procedure: k1910 
o|inlining procedure: k1931 
o|inlining procedure: k1931 
o|contracted procedure: k2026 
o|inlining procedure: k2047 
o|inlining procedure: k2047 
o|contracted procedure: k2143 
o|contracted procedure: k2148 
o|inlining procedure: k2173 
o|inlining procedure: k2173 
o|contracted procedure: k2268 
o|inlining procedure: k2289 
o|inlining procedure: k2289 
o|contracted procedure: k2384 
o|inlining procedure: k2405 
o|inlining procedure: k2405 
o|contracted procedure: k2501 
o|contracted procedure: k2506 
o|inlining procedure: k2531 
o|inlining procedure: k2531 
o|contracted procedure: k2627 
o|contracted procedure: k2632 
o|inlining procedure: k2657 
o|inlining procedure: k2657 
o|inlining procedure: k2768 
o|inlining procedure: k2768 
o|inlining procedure: k2879 
o|inlining procedure: k2879 
o|inlining procedure: k4590 
o|inlining procedure: k4590 
o|removed binding forms: 124 
o|substituted constant variable: r1795 
o|substituted constant variable: r18165039 
o|substituted constant variable: r1911 
o|substituted constant variable: r19325043 
o|substituted constant variable: r2027 
o|substituted constant variable: r20485047 
o|substituted constant variable: r2144 
o|substituted constant variable: r2149 
o|substituted constant variable: r21745051 
o|substituted constant variable: r2269 
o|substituted constant variable: r22905055 
o|substituted constant variable: r2385 
o|substituted constant variable: r24065059 
o|substituted constant variable: r2502 
o|substituted constant variable: r2507 
o|substituted constant variable: r25325063 
o|substituted constant variable: r2628 
o|substituted constant variable: r2633 
o|substituted constant variable: r26585067 
o|substituted constant variable: r27695071 
o|substituted constant variable: r28805075 
o|replaced variables: 10 
o|removed binding forms: 14 
o|removed conditional forms: 10 
o|removed binding forms: 31 
o|simplifications: ((if . 97) (let . 47) (##core#call . 341)) 
o|  call simplifications:
o|    scheme#list
o|    scheme#eof-object?
o|    chicken.fixnum#fx=	2
o|    chicken.fixnum#fx<=	5
o|    chicken.fixnum#fx*	2
o|    ##sys#list	11
o|    scheme#cadr
o|    scheme#caddr
o|    scheme#symbol?
o|    scheme#memq
o|    scheme#char?
o|    scheme#string?	2
o|    scheme#string->list	2
o|    scheme#pair?
o|    scheme#char->integer	2
o|    ##sys#setslot	3
o|    ##sys#check-byte-vector	2
o|    scheme#eq?	7
o|    ##sys#size	6
o|    ##sys#slot	21
o|    ##sys#check-structure	15
o|    chicken.fixnum#fx>=	10
o|    chicken.fixnum#fx+	16
o|    scheme#cons	13
o|    srfi-4#f64vector-set!
o|    srfi-4#f32vector-set!
o|    srfi-4#s64vector-set!
o|    srfi-4#u64vector-set!
o|    srfi-4#s32vector-set!
o|    srfi-4#u32vector-set!
o|    srfi-4#s16vector-set!
o|    srfi-4#u16vector-set!
o|    srfi-4#s8vector-set!
o|    ##sys#check-list	10
o|    srfi-4#u8vector-set!
o|    chicken.fixnum#fx-	5
o|    scheme#car	37
o|    scheme#null?	75
o|    scheme#cdr	37
o|    ##sys#make-structure	14
o|    scheme#not	11
o|    chicken.fixnum#fx>	8
o|    chicken.fixnum#fx<	5
o|    chicken.fixnum#fx*?
o|    ##sys#foreign-unsigned-ranged-integer-argument
o|contracted procedure: k1700 
o|contracted procedure: k1686 
o|contracted procedure: k1724 
o|contracted procedure: k1855 
o|contracted procedure: k1748 
o|contracted procedure: k1849 
o|contracted procedure: k1751 
o|contracted procedure: k1843 
o|contracted procedure: k1754 
o|contracted procedure: k1837 
o|contracted procedure: k1757 
o|contracted procedure: k1831 
o|contracted procedure: k1760 
o|contracted procedure: k1825 
o|contracted procedure: k1763 
o|contracted procedure: k1766 
o|contracted procedure: k1775 
o|contracted procedure: k1786 
o|contracted procedure: k1971 
o|contracted procedure: k1864 
o|contracted procedure: k1965 
o|contracted procedure: k1867 
o|contracted procedure: k1959 
o|contracted procedure: k1870 
o|contracted procedure: k1953 
o|contracted procedure: k1873 
o|contracted procedure: k1947 
o|contracted procedure: k1876 
o|contracted procedure: k1941 
o|contracted procedure: k1879 
o|contracted procedure: k1882 
o|contracted procedure: k1891 
o|contracted procedure: k1902 
o|contracted procedure: k2087 
o|contracted procedure: k1980 
o|contracted procedure: k2081 
o|contracted procedure: k1983 
o|contracted procedure: k2075 
o|contracted procedure: k1986 
o|contracted procedure: k2069 
o|contracted procedure: k1989 
o|contracted procedure: k2063 
o|contracted procedure: k1992 
o|contracted procedure: k2057 
o|contracted procedure: k1995 
o|contracted procedure: k1998 
o|contracted procedure: k2007 
o|contracted procedure: k2018 
o|contracted procedure: k2213 
o|contracted procedure: k2096 
o|contracted procedure: k2207 
o|contracted procedure: k2099 
o|contracted procedure: k2201 
o|contracted procedure: k2102 
o|contracted procedure: k2195 
o|contracted procedure: k2105 
o|contracted procedure: k2189 
o|contracted procedure: k2108 
o|contracted procedure: k2183 
o|contracted procedure: k2111 
o|contracted procedure: k2114 
o|contracted procedure: k2123 
o|contracted procedure: k2154 
o|contracted procedure: k2134 
o|contracted procedure: k2329 
o|contracted procedure: k2222 
o|contracted procedure: k2323 
o|contracted procedure: k2225 
o|contracted procedure: k2317 
o|contracted procedure: k2228 
o|contracted procedure: k2311 
o|contracted procedure: k2231 
o|contracted procedure: k2305 
o|contracted procedure: k2234 
o|contracted procedure: k2299 
o|contracted procedure: k2237 
o|contracted procedure: k2240 
o|contracted procedure: k2249 
o|contracted procedure: k2260 
o|contracted procedure: k2445 
o|contracted procedure: k2338 
o|contracted procedure: k2439 
o|contracted procedure: k2341 
o|contracted procedure: k2433 
o|contracted procedure: k2344 
o|contracted procedure: k2427 
o|contracted procedure: k2347 
o|contracted procedure: k2421 
o|contracted procedure: k2350 
o|contracted procedure: k2415 
o|contracted procedure: k2353 
o|contracted procedure: k2356 
o|contracted procedure: k2365 
o|contracted procedure: k2376 
o|contracted procedure: k2571 
o|contracted procedure: k2454 
o|contracted procedure: k2565 
o|contracted procedure: k2457 
o|contracted procedure: k2559 
o|contracted procedure: k2460 
o|contracted procedure: k2553 
o|contracted procedure: k2463 
o|contracted procedure: k2547 
o|contracted procedure: k2466 
o|contracted procedure: k2541 
o|contracted procedure: k2469 
o|contracted procedure: k2472 
o|contracted procedure: k2481 
o|contracted procedure: k2512 
o|contracted procedure: k2492 
o|contracted procedure: k2697 
o|contracted procedure: k2580 
o|contracted procedure: k2691 
o|contracted procedure: k2583 
o|contracted procedure: k2685 
o|contracted procedure: k2586 
o|contracted procedure: k2679 
o|contracted procedure: k2589 
o|contracted procedure: k2673 
o|contracted procedure: k2592 
o|contracted procedure: k2667 
o|contracted procedure: k2595 
o|contracted procedure: k2598 
o|contracted procedure: k2607 
o|contracted procedure: k2638 
o|contracted procedure: k2618 
o|contracted procedure: k2808 
o|contracted procedure: k2706 
o|contracted procedure: k2802 
o|contracted procedure: k2709 
o|contracted procedure: k2796 
o|contracted procedure: k2712 
o|contracted procedure: k2790 
o|contracted procedure: k2715 
o|contracted procedure: k2784 
o|contracted procedure: k2718 
o|contracted procedure: k2778 
o|contracted procedure: k2721 
o|contracted procedure: k2724 
o|contracted procedure: k2733 
o|contracted procedure: k2741 
o|contracted procedure: k2919 
o|contracted procedure: k2817 
o|contracted procedure: k2913 
o|contracted procedure: k2820 
o|contracted procedure: k2907 
o|contracted procedure: k2823 
o|contracted procedure: k2901 
o|contracted procedure: k2826 
o|contracted procedure: k2895 
o|contracted procedure: k2829 
o|contracted procedure: k2889 
o|contracted procedure: k2832 
o|contracted procedure: k2835 
o|contracted procedure: k2844 
o|contracted procedure: k2852 
o|contracted procedure: k2928 
o|contracted procedure: k2951 
o|inlining procedure: k2943 
o|contracted procedure: k2964 
o|contracted procedure: k2987 
o|inlining procedure: k2979 
o|contracted procedure: k3000 
o|contracted procedure: k3023 
o|inlining procedure: k3015 
o|contracted procedure: k3036 
o|contracted procedure: k3059 
o|inlining procedure: k3051 
o|contracted procedure: k3072 
o|contracted procedure: k3095 
o|inlining procedure: k3087 
o|contracted procedure: k3108 
o|contracted procedure: k3131 
o|inlining procedure: k3123 
o|contracted procedure: k3144 
o|contracted procedure: k3167 
o|inlining procedure: k3159 
o|contracted procedure: k3180 
o|contracted procedure: k3203 
o|inlining procedure: k3195 
o|contracted procedure: k3216 
o|contracted procedure: k3239 
o|inlining procedure: k3231 
o|contracted procedure: k3252 
o|contracted procedure: k3275 
o|inlining procedure: k3267 
o|contracted procedure: k3348 
o|contracted procedure: k3360 
o|contracted procedure: k3372 
o|contracted procedure: k3378 
o|contracted procedure: k3390 
o|contracted procedure: k3402 
o|contracted procedure: k3408 
o|contracted procedure: k3420 
o|contracted procedure: k3432 
o|contracted procedure: k3438 
o|contracted procedure: k3450 
o|contracted procedure: k3462 
o|contracted procedure: k3468 
o|contracted procedure: k3480 
o|contracted procedure: k3491 
o|contracted procedure: k3497 
o|contracted procedure: k3509 
o|contracted procedure: k3520 
o|contracted procedure: k3526 
o|contracted procedure: k3538 
o|contracted procedure: k3549 
o|contracted procedure: k3555 
o|contracted procedure: k3567 
o|contracted procedure: k3578 
o|contracted procedure: k3584 
o|contracted procedure: k3596 
o|contracted procedure: k3607 
o|contracted procedure: k3613 
o|contracted procedure: k3625 
o|contracted procedure: k3636 
o|contracted procedure: k3675 
o|contracted procedure: k3686 
o|contracted procedure: k3689 
o|contracted procedure: k3696 
o|contracted procedure: k3704 
o|contracted procedure: k3707 
o|contracted procedure: k3713 
o|contracted procedure: k3716 
o|contracted procedure: k3734 
o|contracted procedure: k3737 
o|contracted procedure: k3746 
o|contracted procedure: k3749 
o|contracted procedure: k4054 
o|contracted procedure: k4163 
o|contracted procedure: k4067 
o|contracted procedure: k4073 
o|contracted procedure: k4076 
o|contracted procedure: k4079 
o|contracted procedure: k4100 
o|contracted procedure: k4093 
o|contracted procedure: k4103 
o|contracted procedure: k4107 
o|contracted procedure: k4122 
o|contracted procedure: k4144 
o|contracted procedure: k4140 
o|contracted procedure: k4125 
o|contracted procedure: k4128 
o|contracted procedure: k4136 
o|contracted procedure: k3935 
o|contracted procedure: k3942 
o|contracted procedure: k3951 
o|contracted procedure: k3964 
o|contracted procedure: k4036 
o|contracted procedure: k3970 
o|contracted procedure: k3977 
o|contracted procedure: k4032 
o|contracted procedure: k4024 
o|contracted procedure: k4028 
o|contracted procedure: k3990 
o|contracted procedure: k3996 
o|contracted procedure: k4002 
o|contracted procedure: k4009 
o|contracted procedure: k4016 
o|contracted procedure: k4044 
o|contracted procedure: k4050 
o|contracted procedure: k4204 
o|contracted procedure: k4208 
o|contracted procedure: k4212 
o|contracted procedure: k4216 
o|contracted procedure: k4220 
o|contracted procedure: k4224 
o|contracted procedure: k4228 
o|contracted procedure: k4232 
o|contracted procedure: k4236 
o|contracted procedure: k4240 
o|contracted procedure: k4174 
o|contracted procedure: k4190 
o|contracted procedure: k4197 
o|contracted procedure: k4246 
o|contracted procedure: k4249 
o|contracted procedure: k4252 
o|contracted procedure: k4317 
o|contracted procedure: k4303 
o|contracted procedure: k4309 
o|contracted procedure: k4313 
o|contracted procedure: k4321 
o|contracted procedure: k4294 
o|contracted procedure: k4287 
o|contracted procedure: k4325 
o|contracted procedure: k4270 
o|contracted procedure: k4263 
o|contracted procedure: k4551 
o|contracted procedure: k4391 
o|contracted procedure: k4545 
o|contracted procedure: k4394 
o|contracted procedure: k4539 
o|contracted procedure: k4397 
o|contracted procedure: k4533 
o|contracted procedure: k4400 
o|contracted procedure: k4527 
o|contracted procedure: k4403 
o|contracted procedure: k4521 
o|contracted procedure: k4406 
o|contracted procedure: k4409 
o|contracted procedure: k4482 
o|contracted procedure: k4442 
o|inlining procedure: k4449 
o|inlining procedure: k4449 
o|contracted procedure: k4469 
o|contracted procedure: k4472 
o|contracted procedure: k4510 
o|contracted procedure: k4500 
o|contracted procedure: k4493 
o|contracted procedure: k4514 
o|contracted procedure: k4430 
o|contracted procedure: k4423 
o|contracted procedure: k4631 
o|contracted procedure: k4560 
o|contracted procedure: k4625 
o|contracted procedure: k4563 
o|contracted procedure: k4619 
o|contracted procedure: k4566 
o|contracted procedure: k4613 
o|contracted procedure: k4569 
o|contracted procedure: k4578 
o|contracted procedure: k4584 
o|contracted procedure: k4587 
o|contracted procedure: k4600 
o|contracted procedure: k4607 
o|contracted procedure: k4691 
o|contracted procedure: k4640 
o|contracted procedure: k4685 
o|contracted procedure: k4643 
o|contracted procedure: k4679 
o|contracted procedure: k4646 
o|contracted procedure: k4673 
o|contracted procedure: k4649 
o|contracted procedure: k4664 
o|simplifications: ((if . 1) (let . 54)) 
o|removed binding forms: 322 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest250252 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest250252 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest250252 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest250252 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest284286 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest284286 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest284286 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest284286 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest318320 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest318320 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest318320 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest318320 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest352354 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest352354 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest352354 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest352354 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest386388 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest386388 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest386388 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest386388 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest420422 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest420422 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest420422 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest420422 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest454456 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest454456 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest454456 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest454456 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest488490 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest488490 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest488490 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest488490 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest522524 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest522524 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest522524 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest522524 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest558560 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest558560 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest558560 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest558560 0 
o|inlining procedure: k4090 
o|inlining procedure: k4090 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest11141116 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest11141116 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest11141116 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest11141116 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest11681171 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest11681171 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest11681171 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest11681171 0 
o|contracted procedure: k4596 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest11941195 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest11941195 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest11941195 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest11941195 0 
o|inlining procedure: "(srfi-4.scm:577) srfi-4#pack" 
o|inlining procedure: "(srfi-4.scm:576) srfi-4#pack" 
o|inlining procedure: "(srfi-4.scm:575) srfi-4#pack" 
o|inlining procedure: "(srfi-4.scm:574) srfi-4#pack" 
o|inlining procedure: "(srfi-4.scm:573) srfi-4#pack" 
o|inlining procedure: "(srfi-4.scm:572) srfi-4#pack" 
o|inlining procedure: "(srfi-4.scm:571) srfi-4#pack" 
o|inlining procedure: "(srfi-4.scm:570) srfi-4#pack" 
o|inlining procedure: "(srfi-4.scm:569) srfi-4#pack" 
o|inlining procedure: "(srfi-4.scm:568) srfi-4#pack" 
o|simplifications: ((let . 2)) 
o|removed binding forms: 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1752 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1752 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1752 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1752 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1868 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1868 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1868 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1868 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1984 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1984 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1984 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1984 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2100 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r2100 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2100 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2100 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2226 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r2226 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2226 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2226 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2342 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r2342 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2342 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2342 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2458 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r2458 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2458 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2458 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2584 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r2584 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2584 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2584 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2710 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r2710 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2710 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2710 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2821 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r2821 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2821 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2821 1 
o|removed side-effect free assignment to unused variable: srfi-4#pack 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4395 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r4395 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4395 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r4395 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4564 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r4564 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4564 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r4564 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4644 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r4644 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4644 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r4644 1 
o|substituted constant variable: tag8725551 
o|substituted constant variable: loc8735552 
o|substituted constant variable: tag8725558 
o|substituted constant variable: loc8735559 
o|substituted constant variable: tag8725565 
o|substituted constant variable: loc8735566 
o|substituted constant variable: tag8725572 
o|substituted constant variable: loc8735573 
o|substituted constant variable: tag8725579 
o|substituted constant variable: loc8735580 
o|substituted constant variable: tag8725586 
o|substituted constant variable: loc8735587 
o|substituted constant variable: tag8725593 
o|substituted constant variable: loc8735594 
o|substituted constant variable: tag8725600 
o|substituted constant variable: loc8735601 
o|substituted constant variable: tag8725607 
o|substituted constant variable: loc8735608 
o|substituted constant variable: tag8725614 
o|substituted constant variable: loc8735615 
o|replaced variables: 10 
o|removed binding forms: 3 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1758 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r1758 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1758 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1758 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1874 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r1874 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1874 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1874 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1990 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r1990 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1990 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1990 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2106 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r2106 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2106 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2106 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2232 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r2232 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2232 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2232 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2348 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r2348 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2348 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2348 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2464 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r2464 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2464 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2464 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2590 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r2590 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2590 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2590 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2716 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r2716 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2716 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2716 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2827 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r2827 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2827 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2827 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4401 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r4401 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r4401 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r4401 2 
o|removed binding forms: 46 
o|contracted procedure: k3764 
o|contracted procedure: k3768 
o|contracted procedure: k3772 
o|contracted procedure: k3776 
o|contracted procedure: k3780 
o|contracted procedure: k3784 
o|contracted procedure: k3788 
o|contracted procedure: k3792 
o|contracted procedure: k3796 
o|contracted procedure: k3800 
o|removed binding forms: 32 
o|direct leaf routine/allocation: doloop274275 0 
o|direct leaf routine/allocation: doloop308309 0 
o|direct leaf routine/allocation: doloop342343 0 
o|direct leaf routine/allocation: doloop376377 0 
o|direct leaf routine/allocation: doloop410411 0 
o|direct leaf routine/allocation: doloop444445 0 
o|direct leaf routine/allocation: doloop478479 0 
o|direct leaf routine/allocation: doloop512513 0 
o|direct leaf routine/allocation: doloop547548 0 
o|direct leaf routine/allocation: doloop583584 0 
o|converted assignments to bindings: (doloop274275) 
o|converted assignments to bindings: (doloop308309) 
o|converted assignments to bindings: (doloop342343) 
o|converted assignments to bindings: (doloop376377) 
o|converted assignments to bindings: (doloop410411) 
o|converted assignments to bindings: (doloop444445) 
o|converted assignments to bindings: (doloop478479) 
o|converted assignments to bindings: (doloop512513) 
o|converted assignments to bindings: (doloop547548) 
o|converted assignments to bindings: (doloop583584) 
o|simplifications: ((let . 10)) 
o|customizable procedures: (srfi-4#pack-copy srfi-4#unpack srfi-4#unpack-copy k4452 srfi-4#subnvector g986987 k3993 loop2956 loop946 retry950 map-loop9921009 loop846 loop839 loop832 loop825 loop818 loop811 loop804 loop797 loop790 loop783 doloop735736 doloop722723 doloop709710 doloop696697 doloop683684 doloop670671 doloop657658 doloop644645 doloop631632 doloop618619 k2862 k2751 alloc231) 
o|calls to known targets: 158 
o|identified direct recursive calls: f_1806 1 
o|unused rest argument: rest250252 f_1746 
o|identified direct recursive calls: f_1922 1 
o|unused rest argument: rest284286 f_1862 
o|identified direct recursive calls: f_2038 1 
o|unused rest argument: rest318320 f_1978 
o|identified direct recursive calls: f_2164 1 
o|unused rest argument: rest352354 f_2094 
o|identified direct recursive calls: f_2280 1 
o|unused rest argument: rest386388 f_2220 
o|identified direct recursive calls: f_2396 1 
o|unused rest argument: rest420422 f_2336 
o|identified direct recursive calls: f_2522 1 
o|unused rest argument: rest454456 f_2452 
o|identified direct recursive calls: f_2648 1 
o|unused rest argument: rest488490 f_2578 
o|identified direct recursive calls: f_2758 1 
o|unused rest argument: rest522524 f_2704 
o|identified direct recursive calls: f_2869 1 
o|unused rest argument: rest558560 f_2815 
o|identified direct recursive calls: f_2938 1 
o|identified direct recursive calls: f_2974 1 
o|identified direct recursive calls: f_3010 1 
o|identified direct recursive calls: f_3046 1 
o|identified direct recursive calls: f_3082 1 
o|identified direct recursive calls: f_3118 1 
o|identified direct recursive calls: f_3154 1 
o|identified direct recursive calls: f_3190 1 
o|identified direct recursive calls: f_3226 1 
o|identified direct recursive calls: f_3262 1 
o|identified direct recursive calls: f_3355 1 
o|identified direct recursive calls: f_3385 1 
o|identified direct recursive calls: f_3415 1 
o|identified direct recursive calls: f_3445 1 
o|identified direct recursive calls: f_3475 1 
o|identified direct recursive calls: f_3504 1 
o|identified direct recursive calls: f_3533 1 
o|identified direct recursive calls: f_3562 1 
o|identified direct recursive calls: f_3591 1 
o|identified direct recursive calls: f_3620 1 
o|identified direct recursive calls: f_4117 1 
o|unused rest argument: rest11141116 f_4389 
o|unused rest argument: rest11681171 f_4558 
o|unused rest argument: rest11941195 f_4638 
o|fast box initializations: 24 
o|fast global references: 40 
o|fast global assignments: 4 
o|dropping unused closure argument: f_1692 
o|dropping unused closure argument: f_3682 
o|dropping unused closure argument: f_3700 
o|dropping unused closure argument: f_3730 
o|dropping unused closure argument: f_4244 
*/
/* end of file */
