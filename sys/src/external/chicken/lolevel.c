/* Generated from lolevel.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: lolevel.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file lolevel.c -emit-import-library chicken.locative -emit-import-library chicken.memory -emit-import-library chicken.memory.representation
   unit: lolevel
   uses: library
*/
#include "chicken.h"

#ifndef C_NONUNIX
# include <sys/mman.h>
#endif

#define C_memmove_o(to, from, n, toff, foff) C_memmove((char *)(to) + (toff), (char *)(from) + (foff), (n))

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[157];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,27),40,35,35,115,121,115,35,99,104,101,99,107,45,98,108,111,99,107,32,120,32,46,32,108,111,99,41,0,0,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,108,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,32),40,35,35,115,121,115,35,99,104,101,99,107,45,98,101,99,111,109,101,45,97,108,105,115,116,32,120,32,108,111,99,41};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,39),40,35,35,115,121,115,35,99,104,101,99,107,45,103,101,110,101,114,105,99,45,115,116,114,117,99,116,117,114,101,32,120,32,46,32,108,111,99,41,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,36),40,35,35,115,121,115,35,99,104,101,99,107,45,103,101,110,101,114,105,99,45,118,101,99,116,111,114,32,120,32,46,32,108,111,99,41,0,0,0,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,29),40,35,35,115,121,115,35,99,104,101,99,107,45,112,111,105,110,116,101,114,32,120,32,46,32,108,111,99,41,0,0,0};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,10),40,110,111,115,105,122,101,114,114,41,0,0,0,0,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,13),40,115,105,122,101,114,114,32,97,114,103,115,41,0,0,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,20),40,99,104,101,99,107,110,49,32,110,32,110,109,97,120,32,111,102,102,41,0,0,0,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,32),40,99,104,101,99,107,110,50,32,110,32,110,109,97,120,32,110,109,97,120,50,32,111,102,102,49,32,111,102,102,50,41};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,14),40,109,111,118,101,32,102,114,111,109,32,116,111,41,0,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,109,111,118,101,45,109,101,109,111,114,121,33,32,102,114,111,109,32,116,111,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,32),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,97,108,108,111,99,97,116,101,32,105,110,116,51,49,57,41};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,34),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,102,114,101,101,32,99,45,112,111,105,110,116,101,114,51,50,53,41,0,0,0,0,0,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,27),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,63,32,120,41,0,0,0,0,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,32),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,108,105,107,101,63,32,120,41};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,38),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,97,100,100,114,101,115,115,45,62,112,111,105,110,116,101,114,32,97,100,100,114,41,0,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,62,97,100,100,114,101,115,115,32,112,116,114,41,0,0,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,34),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,111,98,106,101,99,116,45,62,112,111,105,110,116,101,114,32,120,41,0,0,0,0,0,0};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,62,111,98,106,101,99,116,32,112,116,114,41,0,0,0,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,32),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,61,63,32,112,49,32,112,50,41};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,39),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,43,32,112,116,114,51,54,55,32,111,102,102,51,54,56,41,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,32),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,97,108,105,103,110,45,116,111,45,119,111,114,100,32,120,41};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,116,97,103,45,112,111,105,110,116,101,114,32,112,116,114,32,116,97,103,41,0,0,0,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,116,97,103,103,101,100,45,112,111,105,110,116,101,114,63,32,120,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,30),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,116,97,103,32,120,41,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,117,56,45,115,101,116,33,32,112,32,110,41,0,0,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,115,56,45,115,101,116,33,32,112,32,110,41,0,0,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,117,49,54,45,115,101,116,33,32,112,32,110,41,0,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,115,49,54,45,115,101,116,33,32,112,32,110,41,0,0,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,117,51,50,45,115,101,116,33,32,112,32,110,41,0,0,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,115,51,50,45,115,101,116,33,32,112,32,110,41,0,0,0};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,117,54,52,45,115,101,116,33,32,112,32,110,41,0,0,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,115,54,52,45,115,101,116,33,32,112,32,110,41,0,0,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,102,51,50,45,115,101,116,33,32,112,32,110,41,0,0,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,102,54,52,45,115,101,116,33,32,112,32,110,41,0,0,0};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,11),40,100,111,108,111,111,112,52,57,57,41,0,0,0,0,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,109,97,107,101,45,112,111,105,110,116,101,114,45,118,101,99,116,111,114,32,110,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,34),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,118,101,99,116,111,114,63,32,120,41,0,0,0,0,0,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,18),40,100,111,108,111,111,112,53,49,52,32,112,116,114,115,32,105,41,0,0,0,0,0,0};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,38),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,118,101,99,116,111,114,32,46,32,112,116,114,115,41,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,11),40,100,111,108,111,111,112,53,50,55,41,0,0,0,0,0};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,118,101,99,116,111,114,45,102,105,108,108,33,32,112,118,32,112,116,114,41,0,0,0,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,118,101,99,116,111,114,45,115,101,116,33,32,112,118,32,105,32,112,116,114,41,0,0,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,35,112,111,105,110,116,101,114,45,118,101,99,116,111,114,45,108,101,110,103,116,104,32,112,118,41,0,0,0,0,0,0,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,13),40,100,111,108,111,111,112,54,51,54,32,105,41,0,0,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,8),40,99,111,112,121,32,120,41};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,111,98,106,101,99,116,45,99,111,112,121,32,120,41,0,0,0};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,9),40,97,50,49,52,57,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,11),40,97,50,49,54,53,32,120,32,105,41,0,0,0,0,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,58),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,101,120,116,101,110,100,45,112,114,111,99,101,100,117,114,101,32,112,114,111,99,32,100,97,116,97,41,0,0,0,0,0,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,9),40,97,50,49,57,50,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,53),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,101,120,116,101,110,100,101,100,45,112,114,111,99,101,100,117,114,101,63,32,120,41,0,0,0};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,9),40,97,50,50,50,53,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,48),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,112,114,111,99,101,100,117,114,101,45,100,97,116,97,32,120,41};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,58),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,115,101,116,45,112,114,111,99,101,100,117,114,101,45,100,97,116,97,33,32,112,114,111,99,32,120,41,0,0,0,0,0,0};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,46),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,118,101,99,116,111,114,45,108,105,107,101,63,32,120,41,0,0};
static C_char C_TLS li57[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,110,117,109,98,101,114,45,111,102,45,115,108,111,116,115,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li58[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,110,117,109,98,101,114,45,111,102,45,98,121,116,101,115,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li59[] C_aligned={C_lihdr(0,0,64),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,109,97,107,101,45,114,101,99,111,114,100,45,105,110,115,116,97,110,99,101,32,116,121,112,101,32,46,32,97,114,103,115,41};
static C_char C_TLS li60[] C_aligned={C_lihdr(0,0,57),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,114,101,99,111,114,100,45,105,110,115,116,97,110,99,101,63,32,120,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li61[] C_aligned={C_lihdr(0,0,54),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,114,101,99,111,114,100,45,105,110,115,116,97,110,99,101,45,116,121,112,101,32,120,41,0,0};
static C_char C_TLS li62[] C_aligned={C_lihdr(0,0,56),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,114,101,99,111,114,100,45,105,110,115,116,97,110,99,101,45,108,101,110,103,116,104,32,120,41};
static C_char C_TLS li63[] C_aligned={C_lihdr(0,0,63),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,114,101,99,111,114,100,45,105,110,115,116,97,110,99,101,45,115,108,111,116,45,115,101,116,33,32,120,32,105,32,121,41,0};
static C_char C_TLS li64[] C_aligned={C_lihdr(0,0,11),40,100,111,108,111,111,112,55,52,50,41,0,0,0,0,0};
static C_char C_TLS li65[] C_aligned={C_lihdr(0,0,48),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,114,101,99,111,114,100,45,62,118,101,99,116,111,114,32,120,41};
static C_char C_TLS li66[] C_aligned={C_lihdr(0,0,51),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,111,98,106,101,99,116,45,98,101,99,111,109,101,33,32,97,108,115,116,41,0,0,0,0,0};
static C_char C_TLS li67[] C_aligned={C_lihdr(0,0,58),40,99,104,105,99,107,101,110,46,109,101,109,111,114,121,46,114,101,112,114,101,115,101,110,116,97,116,105,111,110,35,109,117,116,97,116,101,45,112,114,111,99,101,100,117,114,101,33,32,111,108,100,32,112,114,111,99,41,0,0,0,0,0,0};
static C_char C_TLS li68[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,108,111,99,97,116,105,118,101,35,109,97,107,101,45,108,111,99,97,116,105,118,101,32,111,98,106,32,46,32,105,110,100,101,120,41,0,0,0,0};
static C_char C_TLS li69[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,108,111,99,97,116,105,118,101,35,109,97,107,101,45,119,101,97,107,45,108,111,99,97,116,105,118,101,32,111,98,106,32,46,32,105,110,100,101,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li70[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,108,111,99,97,116,105,118,101,35,108,111,99,97,116,105,118,101,45,115,101,116,33,32,120,32,121,41,0,0,0,0};
static C_char C_TLS li71[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,108,111,99,97,116,105,118,101,35,108,111,99,97,116,105,118,101,45,62,111,98,106,101,99,116,32,120,41,0,0,0};
static C_char C_TLS li72[] C_aligned={C_lihdr(0,0,35),40,99,104,105,99,107,101,110,46,108,111,99,97,116,105,118,101,35,108,111,99,97,116,105,118,101,45,105,110,100,101,120,32,120,41,0,0,0,0,0};
static C_char C_TLS li73[] C_aligned={C_lihdr(0,0,30),40,99,104,105,99,107,101,110,46,108,111,99,97,116,105,118,101,35,108,111,99,97,116,105,118,101,63,32,120,41,0,0};
static C_char C_TLS li74[] C_aligned={C_lihdr(0,0,11),40,97,50,53,52,53,32,108,111,99,41,0,0,0,0,0};
static C_char C_TLS li75[] C_aligned={C_lihdr(0,0,11),40,97,50,53,52,56,32,120,32,105,41,0,0,0,0,0};
static C_char C_TLS li76[] C_aligned={C_lihdr(0,0,12),40,97,50,53,55,50,32,112,118,32,105,41,0,0,0,0};
static C_char C_TLS li77[] C_aligned={C_lihdr(0,0,9),40,97,50,53,57,50,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li78[] C_aligned={C_lihdr(0,0,9),40,97,50,53,57,53,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li79[] C_aligned={C_lihdr(0,0,9),40,97,50,53,57,56,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li80[] C_aligned={C_lihdr(0,0,9),40,97,50,54,48,49,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li81[] C_aligned={C_lihdr(0,0,9),40,97,50,54,48,52,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li82[] C_aligned={C_lihdr(0,0,9),40,97,50,54,48,55,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li83[] C_aligned={C_lihdr(0,0,9),40,97,50,54,49,48,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li84[] C_aligned={C_lihdr(0,0,9),40,97,50,54,49,51,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li85[] C_aligned={C_lihdr(0,0,9),40,97,50,54,49,54,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li86[] C_aligned={C_lihdr(0,0,9),40,97,50,54,49,57,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li87[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


#define return(x) C_cblock C_r = (((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub546(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word buf=(C_word )(C_a0);
unsigned int i=(unsigned int )C_unfix(C_a1);
void * ptr=(void * )C_c_pointer_or_null(C_a2);
*((void **)C_data_pointer(buf) + i) = ptr;
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_mpointer_or_false(&C_a,(void*)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub537(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word buf=(C_word )(C_a0);
unsigned int i=(unsigned int )C_unfix(C_a1);
C_return(*((void **)C_data_pointer(buf) + i));
C_ret:
#undef return

return C_r;}

/* from k1862 */
C_regparm static C_word C_fcall stub494(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_fix((C_word)C_wordstobytes(t0));
return C_r;}

/* from k1663 */
C_regparm static C_word C_fcall stub380(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_num_to_int(C_a0);
C_r=C_int_to_num(&C_a,C_align(t0));
return C_r;}

#define return(x) C_cblock C_r = (C_mpointer(&C_a,(void*)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub369(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
void * ptr=(void * )C_c_pointer_or_null(C_a0);
int off=(int )C_num_to_int(C_a1);
C_return((unsigned char *)ptr + off);
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_mpointer(&C_a,(void*)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub354(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word x=(C_word )(C_a0);
C_return((void *)x);
C_ret:
#undef return

return C_r;}

/* from k1575 */
C_regparm static C_word C_fcall stub326(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
void * t0=(void * )C_c_pointer_or_null(C_a0);
C_free(t0);
return C_r;}

/* from k1568 */
C_regparm static C_word C_fcall stub320(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_mpointer_or_false(&C_a,(void*)C_malloc(t0));
return C_r;}

/* from k1207 */
C_regparm static C_word C_fcall stub199(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2,C_word C_a3,C_word C_a4){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
void * t0=(void * )C_data_pointer_or_null(C_a0);
void * t1=(void * )C_data_pointer_or_null(C_a1);
int t2=(int )C_unfix(C_a2);
int t3=(int )C_unfix(C_a3);
int t4=(int )C_unfix(C_a4);
C_memmove_o(t0,t1,t2,t3,t4);
return C_r;}

/* from k1179 */
C_regparm static C_word C_fcall stub183(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2,C_word C_a3,C_word C_a4){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
void * t0=(void * )C_data_pointer_or_null(C_a0);
void * t1=(void * )C_c_pointer_or_null(C_a1);
int t2=(int )C_unfix(C_a2);
int t3=(int )C_unfix(C_a3);
int t4=(int )C_unfix(C_a4);
C_memmove_o(t0,t1,t2,t3,t4);
return C_r;}

/* from k1151 */
C_regparm static C_word C_fcall stub167(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2,C_word C_a3,C_word C_a4){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
void * t0=(void * )C_c_pointer_or_null(C_a0);
void * t1=(void * )C_data_pointer_or_null(C_a1);
int t2=(int )C_unfix(C_a2);
int t3=(int )C_unfix(C_a3);
int t4=(int )C_unfix(C_a4);
C_memmove_o(t0,t1,t2,t3,t4);
return C_r;}

/* from k1123 */
C_regparm static C_word C_fcall stub151(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2,C_word C_a3,C_word C_a4){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
void * t0=(void * )C_c_pointer_or_null(C_a0);
void * t1=(void * )C_c_pointer_or_null(C_a1);
int t2=(int )C_unfix(C_a2);
int t3=(int )C_unfix(C_a3);
int t4=(int )C_unfix(C_a4);
C_memmove_o(t0,t1,t2,t3,t4);
return C_r;}

C_noret_decl(f_1007)
static void C_ccall f_1007(C_word c,C_word *av) C_noret;
C_noret_decl(f_1010)
static void C_ccall f_1010(C_word c,C_word *av) C_noret;
C_noret_decl(f_1024)
static void C_ccall f_1024(C_word c,C_word *av) C_noret;
C_noret_decl(f_1049)
static void C_ccall f_1049(C_word c,C_word *av) C_noret;
C_noret_decl(f_1068)
static void C_fcall f_1068(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1081)
static void C_ccall f_1081(C_word c,C_word *av) C_noret;
C_noret_decl(f_1222)
static void C_ccall f_1222(C_word c,C_word *av) C_noret;
C_noret_decl(f_1243)
static void C_fcall f_1243(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1249)
static void C_fcall f_1249(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1255)
static void C_fcall f_1255(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_1271)
static void C_fcall f_1271(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_1298)
static void C_ccall f_1298(C_word c,C_word *av) C_noret;
C_noret_decl(f_1301)
static void C_ccall f_1301(C_word c,C_word *av) C_noret;
C_noret_decl(f_1304)
static void C_ccall f_1304(C_word c,C_word *av) C_noret;
C_noret_decl(f_1307)
static void C_ccall f_1307(C_word c,C_word *av) C_noret;
C_noret_decl(f_1312)
static void C_fcall f_1312(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1404)
static void C_ccall f_1404(C_word c,C_word *av) C_noret;
C_noret_decl(f_1413)
static void C_ccall f_1413(C_word c,C_word *av) C_noret;
C_noret_decl(f_1423)
static void C_ccall f_1423(C_word c,C_word *av) C_noret;
C_noret_decl(f_1427)
static void C_ccall f_1427(C_word c,C_word *av) C_noret;
C_noret_decl(f_1446)
static void C_ccall f_1446(C_word c,C_word *av) C_noret;
C_noret_decl(f_1475)
static void C_ccall f_1475(C_word c,C_word *av) C_noret;
C_noret_decl(f_1485)
static void C_ccall f_1485(C_word c,C_word *av) C_noret;
C_noret_decl(f_1495)
static void C_ccall f_1495(C_word c,C_word *av) C_noret;
C_noret_decl(f_1565)
static void C_ccall f_1565(C_word c,C_word *av) C_noret;
C_noret_decl(f_1572)
static void C_ccall f_1572(C_word c,C_word *av) C_noret;
C_noret_decl(f_1582)
static void C_ccall f_1582(C_word c,C_word *av) C_noret;
C_noret_decl(f_1590)
static void C_ccall f_1590(C_word c,C_word *av) C_noret;
C_noret_decl(f_1601)
static void C_ccall f_1601(C_word c,C_word *av) C_noret;
C_noret_decl(f_1605)
static void C_ccall f_1605(C_word c,C_word *av) C_noret;
C_noret_decl(f_1610)
static void C_ccall f_1610(C_word c,C_word *av) C_noret;
C_noret_decl(f_1614)
static void C_ccall f_1614(C_word c,C_word *av) C_noret;
C_noret_decl(f_1619)
static void C_ccall f_1619(C_word c,C_word *av) C_noret;
C_noret_decl(f_1630)
static void C_ccall f_1630(C_word c,C_word *av) C_noret;
C_noret_decl(f_1634)
static void C_ccall f_1634(C_word c,C_word *av) C_noret;
C_noret_decl(f_1636)
static void C_ccall f_1636(C_word c,C_word *av) C_noret;
C_noret_decl(f_1640)
static void C_ccall f_1640(C_word c,C_word *av) C_noret;
C_noret_decl(f_1643)
static void C_ccall f_1643(C_word c,C_word *av) C_noret;
C_noret_decl(f_1645)
static void C_ccall f_1645(C_word c,C_word *av) C_noret;
C_noret_decl(f_1667)
static void C_ccall f_1667(C_word c,C_word *av) C_noret;
C_noret_decl(f_1697)
static void C_ccall f_1697(C_word c,C_word *av) C_noret;
C_noret_decl(f_1702)
static void C_ccall f_1702(C_word c,C_word *av) C_noret;
C_noret_decl(f_1706)
static void C_ccall f_1706(C_word c,C_word *av) C_noret;
C_noret_decl(f_1709)
static void C_ccall f_1709(C_word c,C_word *av) C_noret;
C_noret_decl(f_1723)
static void C_ccall f_1723(C_word c,C_word *av) C_noret;
C_noret_decl(f_1754)
static void C_ccall f_1754(C_word c,C_word *av) C_noret;
C_noret_decl(f_1778)
static void C_ccall f_1778(C_word c,C_word *av) C_noret;
C_noret_decl(f_1781)
static void C_ccall f_1781(C_word c,C_word *av) C_noret;
C_noret_decl(f_1784)
static void C_ccall f_1784(C_word c,C_word *av) C_noret;
C_noret_decl(f_1787)
static void C_ccall f_1787(C_word c,C_word *av) C_noret;
C_noret_decl(f_1790)
static void C_ccall f_1790(C_word c,C_word *av) C_noret;
C_noret_decl(f_1793)
static void C_ccall f_1793(C_word c,C_word *av) C_noret;
C_noret_decl(f_1796)
static void C_ccall f_1796(C_word c,C_word *av) C_noret;
C_noret_decl(f_1799)
static void C_ccall f_1799(C_word c,C_word *av) C_noret;
C_noret_decl(f_1802)
static void C_ccall f_1802(C_word c,C_word *av) C_noret;
C_noret_decl(f_1805)
static void C_ccall f_1805(C_word c,C_word *av) C_noret;
C_noret_decl(f_1810)
static void C_ccall f_1810(C_word c,C_word *av) C_noret;
C_noret_decl(f_1814)
static void C_ccall f_1814(C_word c,C_word *av) C_noret;
C_noret_decl(f_1818)
static void C_ccall f_1818(C_word c,C_word *av) C_noret;
C_noret_decl(f_1822)
static void C_ccall f_1822(C_word c,C_word *av) C_noret;
C_noret_decl(f_1826)
static void C_ccall f_1826(C_word c,C_word *av) C_noret;
C_noret_decl(f_1830)
static void C_ccall f_1830(C_word c,C_word *av) C_noret;
C_noret_decl(f_1834)
static void C_ccall f_1834(C_word c,C_word *av) C_noret;
C_noret_decl(f_1838)
static void C_ccall f_1838(C_word c,C_word *av) C_noret;
C_noret_decl(f_1842)
static void C_ccall f_1842(C_word c,C_word *av) C_noret;
C_noret_decl(f_1846)
static void C_ccall f_1846(C_word c,C_word *av) C_noret;
C_noret_decl(f_1851)
static void C_ccall f_1851(C_word c,C_word *av) C_noret;
C_noret_decl(f_1858)
static void C_ccall f_1858(C_word c,C_word *av) C_noret;
C_noret_decl(f_1870)
static void C_ccall f_1870(C_word c,C_word *av) C_noret;
C_noret_decl(f_1882)
static void C_ccall f_1882(C_word c,C_word *av) C_noret;
C_noret_decl(f_1887)
static C_word C_fcall f_1887(C_word t0,C_word t1);
C_noret_decl(f_1915)
static void C_ccall f_1915(C_word c,C_word *av) C_noret;
C_noret_decl(f_1921)
static void C_ccall f_1921(C_word c,C_word *av) C_noret;
C_noret_decl(f_1926)
static void C_ccall f_1926(C_word c,C_word *av) C_noret;
C_noret_decl(f_1934)
static void C_fcall f_1934(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1947)
static void C_ccall f_1947(C_word c,C_word *av) C_noret;
C_noret_decl(f_1961)
static void C_ccall f_1961(C_word c,C_word *av) C_noret;
C_noret_decl(f_1968)
static void C_ccall f_1968(C_word c,C_word *av) C_noret;
C_noret_decl(f_1979)
static C_word C_fcall f_1979(C_word t0,C_word t1);
C_noret_decl(f_2022)
static void C_ccall f_2022(C_word c,C_word *av) C_noret;
C_noret_decl(f_2029)
static void C_ccall f_2029(C_word c,C_word *av) C_noret;
C_noret_decl(f_2032)
static void C_ccall f_2032(C_word c,C_word *av) C_noret;
C_noret_decl(f_2050)
static void C_ccall f_2050(C_word c,C_word *av) C_noret;
C_noret_decl(f_2052)
static void C_ccall f_2052(C_word c,C_word *av) C_noret;
C_noret_decl(f_2061)
static void C_ccall f_2061(C_word c,C_word *av) C_noret;
C_noret_decl(f_2067)
static void C_fcall f_2067(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2097)
static void C_ccall f_2097(C_word c,C_word *av) C_noret;
C_noret_decl(f_2100)
static void C_ccall f_2100(C_word c,C_word *av) C_noret;
C_noret_decl(f_2109)
static void C_fcall f_2109(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2130)
static void C_ccall f_2130(C_word c,C_word *av) C_noret;
C_noret_decl(f_2141)
static void C_ccall f_2141(C_word c,C_word *av) C_noret;
C_noret_decl(f_2145)
static void C_ccall f_2145(C_word c,C_word *av) C_noret;
C_noret_decl(f_2150)
static void C_ccall f_2150(C_word c,C_word *av) C_noret;
C_noret_decl(f_2166)
static void C_ccall f_2166(C_word c,C_word *av) C_noret;
C_noret_decl(f_2176)
static void C_ccall f_2176(C_word c,C_word *av) C_noret;
C_noret_decl(f_2193)
static void C_ccall f_2193(C_word c,C_word *av) C_noret;
C_noret_decl(f_2210)
static void C_ccall f_2210(C_word c,C_word *av) C_noret;
C_noret_decl(f_2212)
static void C_ccall f_2212(C_word c,C_word *av) C_noret;
C_noret_decl(f_2226)
static void C_ccall f_2226(C_word c,C_word *av) C_noret;
C_noret_decl(f_2243)
static void C_ccall f_2243(C_word c,C_word *av) C_noret;
C_noret_decl(f_2251)
static void C_ccall f_2251(C_word c,C_word *av) C_noret;
C_noret_decl(f_2265)
static void C_ccall f_2265(C_word c,C_word *av) C_noret;
C_noret_decl(f_2267)
static void C_ccall f_2267(C_word c,C_word *av) C_noret;
C_noret_decl(f_2288)
static void C_ccall f_2288(C_word c,C_word *av) C_noret;
C_noret_decl(f_2290)
static void C_ccall f_2290(C_word c,C_word *av) C_noret;
C_noret_decl(f_2294)
static void C_ccall f_2294(C_word c,C_word *av) C_noret;
C_noret_decl(f_2299)
static void C_ccall f_2299(C_word c,C_word *av) C_noret;
C_noret_decl(f_2322)
static void C_ccall f_2322(C_word c,C_word *av) C_noret;
C_noret_decl(f_2331)
static void C_ccall f_2331(C_word c,C_word *av) C_noret;
C_noret_decl(f_2367)
static void C_ccall f_2367(C_word c,C_word *av) C_noret;
C_noret_decl(f_2371)
static void C_ccall f_2371(C_word c,C_word *av) C_noret;
C_noret_decl(f_2376)
static void C_ccall f_2376(C_word c,C_word *av) C_noret;
C_noret_decl(f_2380)
static void C_ccall f_2380(C_word c,C_word *av) C_noret;
C_noret_decl(f_2389)
static void C_ccall f_2389(C_word c,C_word *av) C_noret;
C_noret_decl(f_2393)
static void C_ccall f_2393(C_word c,C_word *av) C_noret;
C_noret_decl(f_2396)
static void C_ccall f_2396(C_word c,C_word *av) C_noret;
C_noret_decl(f_2415)
static void C_ccall f_2415(C_word c,C_word *av) C_noret;
C_noret_decl(f_2417)
static void C_ccall f_2417(C_word c,C_word *av) C_noret;
C_noret_decl(f_2421)
static void C_ccall f_2421(C_word c,C_word *av) C_noret;
C_noret_decl(f_2427)
static void C_ccall f_2427(C_word c,C_word *av) C_noret;
C_noret_decl(f_2432)
static C_word C_fcall f_2432(C_word t0,C_word t1);
C_noret_decl(f_2455)
static void C_ccall f_2455(C_word c,C_word *av) C_noret;
C_noret_decl(f_2459)
static void C_ccall f_2459(C_word c,C_word *av) C_noret;
C_noret_decl(f_2464)
static void C_ccall f_2464(C_word c,C_word *av) C_noret;
C_noret_decl(f_2468)
static void C_ccall f_2468(C_word c,C_word *av) C_noret;
C_noret_decl(f_2471)
static void C_ccall f_2471(C_word c,C_word *av) C_noret;
C_noret_decl(f_2478)
static void C_ccall f_2478(C_word c,C_word *av) C_noret;
C_noret_decl(f_2481)
static void C_ccall f_2481(C_word c,C_word *av) C_noret;
C_noret_decl(f_2493)
static void C_ccall f_2493(C_word c,C_word *av) C_noret;
C_noret_decl(f_2495)
static void C_ccall f_2495(C_word c,C_word *av) C_noret;
C_noret_decl(f_2511)
static void C_ccall f_2511(C_word c,C_word *av) C_noret;
C_noret_decl(f_2527)
static void C_ccall f_2527(C_word c,C_word *av) C_noret;
C_noret_decl(f_2532)
static void C_ccall f_2532(C_word c,C_word *av) C_noret;
C_noret_decl(f_2534)
static void C_ccall f_2534(C_word c,C_word *av) C_noret;
C_noret_decl(f_2537)
static void C_ccall f_2537(C_word c,C_word *av) C_noret;
C_noret_decl(f_2540)
static void C_ccall f_2540(C_word c,C_word *av) C_noret;
C_noret_decl(f_2546)
static void C_ccall f_2546(C_word c,C_word *av) C_noret;
C_noret_decl(f_2549)
static void C_ccall f_2549(C_word c,C_word *av) C_noret;
C_noret_decl(f_2553)
static void C_ccall f_2553(C_word c,C_word *av) C_noret;
C_noret_decl(f_2556)
static void C_ccall f_2556(C_word c,C_word *av) C_noret;
C_noret_decl(f_2573)
static void C_ccall f_2573(C_word c,C_word *av) C_noret;
C_noret_decl(f_2580)
static void C_ccall f_2580(C_word c,C_word *av) C_noret;
C_noret_decl(f_2593)
static void C_ccall f_2593(C_word c,C_word *av) C_noret;
C_noret_decl(f_2596)
static void C_ccall f_2596(C_word c,C_word *av) C_noret;
C_noret_decl(f_2599)
static void C_ccall f_2599(C_word c,C_word *av) C_noret;
C_noret_decl(f_2602)
static void C_ccall f_2602(C_word c,C_word *av) C_noret;
C_noret_decl(f_2605)
static void C_ccall f_2605(C_word c,C_word *av) C_noret;
C_noret_decl(f_2608)
static void C_ccall f_2608(C_word c,C_word *av) C_noret;
C_noret_decl(f_2611)
static void C_ccall f_2611(C_word c,C_word *av) C_noret;
C_noret_decl(f_2614)
static void C_ccall f_2614(C_word c,C_word *av) C_noret;
C_noret_decl(f_2617)
static void C_ccall f_2617(C_word c,C_word *av) C_noret;
C_noret_decl(f_2620)
static void C_ccall f_2620(C_word c,C_word *av) C_noret;
C_noret_decl(f_958)
static void C_ccall f_958(C_word c,C_word *av) C_noret;
C_noret_decl(f_960)
static void C_ccall f_960(C_word c,C_word *av) C_noret;
C_noret_decl(f_978)
static void C_ccall f_978(C_word c,C_word *av) C_noret;
C_noret_decl(f_987)
static void C_fcall f_987(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(C_lolevel_toplevel)
C_externexport void C_ccall C_lolevel_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_1068)
static void C_ccall trf_1068(C_word c,C_word *av) C_noret;
static void C_ccall trf_1068(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1068(t0,t1);}

C_noret_decl(trf_1243)
static void C_ccall trf_1243(C_word c,C_word *av) C_noret;
static void C_ccall trf_1243(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1243(t0,t1);}

C_noret_decl(trf_1249)
static void C_ccall trf_1249(C_word c,C_word *av) C_noret;
static void C_ccall trf_1249(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1249(t0,t1,t2);}

C_noret_decl(trf_1255)
static void C_ccall trf_1255(C_word c,C_word *av) C_noret;
static void C_ccall trf_1255(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_1255(t0,t1,t2,t3,t4);}

C_noret_decl(trf_1271)
static void C_ccall trf_1271(C_word c,C_word *av) C_noret;
static void C_ccall trf_1271(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_1271(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_1312)
static void C_ccall trf_1312(C_word c,C_word *av) C_noret;
static void C_ccall trf_1312(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1312(t0,t1,t2,t3);}

C_noret_decl(trf_1934)
static void C_ccall trf_1934(C_word c,C_word *av) C_noret;
static void C_ccall trf_1934(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1934(t0,t1,t2,t3);}

C_noret_decl(trf_2067)
static void C_ccall trf_2067(C_word c,C_word *av) C_noret;
static void C_ccall trf_2067(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2067(t0,t1,t2);}

C_noret_decl(trf_2109)
static void C_ccall trf_2109(C_word c,C_word *av) C_noret;
static void C_ccall trf_2109(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2109(t0,t1,t2);}

C_noret_decl(trf_987)
static void C_ccall trf_987(C_word c,C_word *av) C_noret;
static void C_ccall trf_987(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_987(t0,t1,t2);}

/* k1005 in loop in ##sys#check-become-alist in k956 */
static void C_ccall f_1007(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_1007,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1010,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* lolevel.scm:96: ##sys#check-block */
t3=*((C_word*)lf[2]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_u_i_cdr(((C_word*)t0)[5]);
av2[3]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k1008 in k1005 in loop in ##sys#check-become-alist in k956 */
static void C_ccall f_1010(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1010,c,av);}
/* lolevel.scm:97: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_987(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}

/* ##sys#check-generic-structure in k956 */
static void C_ccall f_1024(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +0,c,5)))){
C_save_and_reclaim((void*)f_1024,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+0);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
t4=(C_truep(C_blockp(t2))?C_structurep(t2):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=C_SCHEME_UNDEFINED;
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
if(C_truep(C_i_pairp(t3))){
/* lolevel.scm:105: ##sys#signal-hook */
t5=*((C_word*)lf[5]+1);{
C_word av2[6];
av2[0]=t5;
av2[1]=t1;
av2[2]=lf[6];
av2[3]=C_get_rest_arg(c,3,av,3,t0);
av2[4]=lf[9];
av2[5]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}
else{
/* lolevel.scm:105: ##sys#signal-hook */
t5=*((C_word*)lf[5]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=lf[6];
av2[3]=C_SCHEME_FALSE;
av2[4]=lf[9];
av2[5]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}}}

/* ##sys#check-generic-vector in k956 */
static void C_ccall f_1049(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,2)))){
C_save_and_reclaim((void*)f_1049,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1068,a[2]=t1,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_blockp(t2))){
t5=C_specialp(t2);
t6=t4;
f_1068(t6,(C_truep(t5)?C_i_not(t5):C_i_not(C_byteblockp(t2))));}
else{
t5=t4;
f_1068(t5,C_SCHEME_FALSE);}}

/* k1066 in ##sys#check-generic-vector in k956 */
static void C_fcall f_1068(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,5)))){
C_save_and_reclaim_args((void *)trf_1068,2,t0,t1);}
if(C_truep(t1)){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[3]))){
/* lolevel.scm:113: ##sys#signal-hook */
t2=*((C_word*)lf[5]+1);{
C_word av2[6];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[6];
av2[3]=C_u_i_car(((C_word*)t0)[3]);
av2[4]=lf[11];
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}
else{
/* lolevel.scm:113: ##sys#signal-hook */
t2=*((C_word*)lf[5]+1);{
C_word av2[6];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[6];
av2[3]=C_SCHEME_FALSE;
av2[4]=lf[11];
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}}

/* ##sys#check-pointer in k956 */
static void C_ccall f_1081(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +0,c,5)))){
C_save_and_reclaim((void*)f_1081,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+0);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
if(C_truep(C_i_safe_pointerp(t2))){
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_fix((C_word)C_BAD_ARGUMENT_TYPE_NO_POINTER_ERROR);
if(C_truep(C_i_pairp(t3))){
/* lolevel.scm:119: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[3]+1);
av2[1]=t1;
av2[2]=t4;
av2[3]=C_get_rest_arg(c,3,av,3,t0);
av2[4]=lf[13];
av2[5]=t2;
tp(6,av2);}}
else{
/* lolevel.scm:119: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=t1;
av2[2]=t4;
av2[3]=C_SCHEME_FALSE;
av2[4]=lf[13];
av2[5]=t2;
tp(6,av2);}}}}

/* chicken.memory#move-memory! in k956 */
static void C_ccall f_1222(C_word c,C_word *av){
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
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(38,c,7)))){
C_save_and_reclaim((void *)f_1222,c,av);}
a=C_alloc(38);
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,4,t0));
t6=C_rest_nullp(c,4);
t7=C_rest_nullp(c,5);
t8=(C_truep(t7)?C_fix(0):C_get_rest_arg(c,5,av,4,t0));
t9=C_rest_nullp(c,5);
t10=C_rest_nullp(c,6);
t11=(C_truep(t10)?C_fix(0):C_get_rest_arg(c,6,av,4,t0));
t12=C_rest_nullp(c,6);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_SCHEME_UNDEFINED;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_SCHEME_UNDEFINED;
t18=(*a=C_VECTOR_TYPE|1,a[1]=t17,tmp=(C_word)a,a+=2,tmp);
t19=C_SCHEME_UNDEFINED;
t20=(*a=C_VECTOR_TYPE|1,a[1]=t19,tmp=(C_word)a,a+=2,tmp);
t21=C_set_block_item(t14,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1243,a[2]=t2,a[3]=t3,a[4]=((C_word)li6),tmp=(C_word)a,a+=5,tmp));
t22=C_set_block_item(t16,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1249,a[2]=t2,a[3]=t3,a[4]=((C_word)li7),tmp=(C_word)a,a+=5,tmp));
t23=C_set_block_item(t18,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1255,a[2]=t16,a[3]=((C_word)li8),tmp=(C_word)a,a+=4,tmp));
t24=C_set_block_item(t20,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1271,a[2]=t16,a[3]=((C_word)li9),tmp=(C_word)a,a+=4,tmp));
t25=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_1298,a[2]=((C_word*)t0)[2],a[3]=t11,a[4]=t8,a[5]=t5,a[6]=t14,a[7]=t18,a[8]=t20,a[9]=t1,a[10]=t2,a[11]=t3,tmp=(C_word)a,a+=12,tmp);
/* lolevel.scm:158: ##sys#check-block */
t26=*((C_word*)lf[2]+1);{
C_word *av2=av;
av2[0]=t26;
av2[1]=t25;
av2[2]=t2;
av2[3]=lf[17];
((C_proc)(void*)(*((C_word*)t26+1)))(4,av2);}}

/* nosizerr in chicken.memory#move-memory! in k956 */
static void C_fcall f_1243(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,5)))){
C_save_and_reclaim_args((void *)trf_1243,2,t0,t1);}
/* lolevel.scm:143: ##sys#error */
t2=*((C_word*)lf[16]+1);{
C_word av2[6];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[17];
av2[3]=lf[18];
av2[4]=((C_word*)t0)[2];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* sizerr in chicken.memory#move-memory! in k956 */
static void C_fcall f_1249(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,7)))){
C_save_and_reclaim_args((void *)trf_1249,3,t0,t1,t2);}{
C_word av2[8];
av2[0]=0;
av2[1]=t1;
av2[2]=*((C_word*)lf[16]+1);
av2[3]=lf[17];
av2[4]=lf[19];
av2[5]=((C_word*)t0)[2];
av2[6]=((C_word*)t0)[3];
av2[7]=t2;
C_apply(8,av2);}}

/* checkn1 in chicken.memory#move-memory! in k956 */
static void C_fcall f_1255(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_1255,5,t0,t1,t2,t3,t4);}
a=C_alloc(6);
t5=C_fixnum_difference(t3,t4);
if(C_truep(C_fixnum_less_or_equal_p(t2,t5))){
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
/* lolevel.scm:151: sizerr */
t6=((C_word*)((C_word*)t0)[2])[1];
f_1249(t6,t1,C_a_i_list(&a,2,t2,t3));}}

/* checkn2 in chicken.memory#move-memory! in k956 */
static void C_fcall f_1271(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6){
C_word tmp;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_1271,7,t0,t1,t2,t3,t4,t5,t6);}
a=C_alloc(9);
t7=C_fixnum_difference(t3,t5);
t8=C_fixnum_less_or_equal_p(t2,t7);
t9=(C_truep(t8)?C_fixnum_less_or_equal_p(t2,C_fixnum_difference(t4,t6)):C_SCHEME_FALSE);
if(C_truep(t9)){
t10=t1;{
C_word av2[2];
av2[0]=t10;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
/* lolevel.scm:156: sizerr */
t10=((C_word*)((C_word*)t0)[2])[1];
f_1249(t10,t1,C_a_i_list(&a,3,t2,t3,t4));}}

/* k1296 in chicken.memory#move-memory! in k956 */
static void C_ccall f_1298(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_1298,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_1301,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
/* lolevel.scm:159: ##sys#check-block */
t3=*((C_word*)lf[2]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[11];
av2[3]=lf[17];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k1299 in k1296 in chicken.memory#move-memory! in k956 */
static void C_ccall f_1301(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_1301,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_1304,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
if(C_truep(C_fixnum_lessp(((C_word*)t0)[4],C_fix(0)))){
/* lolevel.scm:161: ##sys#error */
t3=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[17];
av2[3]=lf[22];
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_1304(2,av2);}}}

/* k1302 in k1299 in k1296 in chicken.memory#move-memory! in k956 */
static void C_ccall f_1304(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_1304,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_1307,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
if(C_truep(C_fixnum_lessp(((C_word*)t0)[3],C_fix(0)))){
/* lolevel.scm:163: ##sys#error */
t3=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[17];
av2[3]=lf[21];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_1307(2,av2);}}}

/* k1305 in k1302 in k1299 in k1296 in chicken.memory#move-memory! in k956 */
static void C_ccall f_1307(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_1307,c,av);}
a=C_alloc(13);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_1312,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word)li10),tmp=(C_word)a,a+=11,tmp));
t5=((C_word*)t3)[1];
f_1312(t5,((C_word*)t0)[9],((C_word*)t0)[10],((C_word*)t0)[11]);}

/* move in k1305 in k1302 in k1299 in k1296 in chicken.memory#move-memory! in k956 */
static void C_fcall f_1312(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_1312,4,t0,t1,t2,t3);}
a=C_alloc(10);
if(C_truep(C_structurep(t2))){
t4=C_slot(t2,C_fix(0));
if(C_truep(C_i_memq(t4,((C_word*)t0)[2]))){
/* lolevel.scm:167: move */
t10=t1;
t11=C_slot(t2,C_fix(1));
t12=t3;
t1=t10;
t2=t11;
t3=t12;
goto loop;}
else{
t5=C_fix((C_word)C_BAD_ARGUMENT_TYPE_ERROR);
/* lolevel.scm:133: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[3]+1);
av2[1]=t1;
av2[2]=t5;
av2[3]=lf[17];
av2[4]=t2;
tp(5,av2);}}}
else{
if(C_truep(C_structurep(t3))){
t4=C_slot(t3,C_fix(0));
if(C_truep(C_i_memq(t4,((C_word*)t0)[2]))){
/* lolevel.scm:171: move */
t10=t1;
t11=t2;
t12=C_slot(t3,C_fix(1));
t1=t10;
t2=t11;
t3=t12;
goto loop;}
else{
t5=C_fix((C_word)C_BAD_ARGUMENT_TYPE_ERROR);
/* lolevel.scm:133: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[3]+1);
av2[1]=t1;
av2[2]=t5;
av2[3]=lf[17];
av2[4]=t3;
tp(5,av2);}}}
else{
t4=C_i_safe_pointerp(t2);
t5=(C_truep(t4)?t4:C_locativep(t2));
if(C_truep(t5)){
t6=C_i_safe_pointerp(t3);
t7=(C_truep(t6)?t6:C_locativep(t3));
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1404,a[2]=t3,a[3]=t2,a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)t0)[6])){
t9=t8;{
C_word av2[2];
av2[0]=t9;
av2[1]=((C_word*)t0)[6];
f_1404(2,av2);}}
else{
/* lolevel.scm:175: nosizerr */
t9=((C_word*)((C_word*)t0)[7])[1];
f_1243(t9,t8);}}
else{
t8=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_1413,a[2]=t3,a[3]=t2,a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],tmp=(C_word)a,a+=10,tmp);
/* lolevel.scm:176: ##sys#bytevector? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[20]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[20]+1);
av2[1]=t8;
av2[2]=t3;
tp(3,av2);}}}
else{
t6=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_1446,a[2]=t2,a[3]=t3,a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* lolevel.scm:180: ##sys#bytevector? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[20]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[20]+1);
av2[1]=t6;
av2[2]=t2;
tp(3,av2);}}}}}

/* k1402 in move in k1305 in k1302 in k1299 in k1296 in chicken.memory#move-memory! in k956 */
static void C_ccall f_1404(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1404,c,av);}
t2=(C_truep(((C_word*)t0)[2])?C_i_foreign_pointer_argumentp(((C_word*)t0)[2]):C_SCHEME_FALSE);
t3=(C_truep(((C_word*)t0)[3])?C_i_foreign_pointer_argumentp(((C_word*)t0)[3]):C_SCHEME_FALSE);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=stub151(C_SCHEME_UNDEFINED,t2,t3,C_i_foreign_fixnum_argumentp(t1),C_i_foreign_fixnum_argumentp(((C_word*)t0)[5]),C_i_foreign_fixnum_argumentp(((C_word*)t0)[6]));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k1411 in move in k1305 in k1302 in k1299 in k1296 in chicken.memory#move-memory! in k956 */
static void C_ccall f_1413(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_1413,c,av);}
a=C_alloc(13);
t2=(C_truep(t1)?t1:C_i_stringp(((C_word*)t0)[2]));
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1423,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1427,a[2]=((C_word*)t0)[7],a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[8])){
/* lolevel.scm:177: checkn1 */
t5=((C_word*)((C_word*)t0)[7])[1];
f_1255(t5,t3,((C_word*)t0)[8],C_block_size(((C_word*)t0)[2]),((C_word*)t0)[5]);}
else{
/* lolevel.scm:177: nosizerr */
t5=((C_word*)((C_word*)t0)[9])[1];
f_1243(t5,t4);}}
else{
t3=C_fix((C_word)C_BAD_ARGUMENT_TYPE_ERROR);
/* lolevel.scm:133: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=((C_word*)t0)[4];
av2[2]=t3;
av2[3]=lf[17];
av2[4]=((C_word*)t0)[2];
tp(5,av2);}}}

/* k1421 in k1411 in move in k1305 in k1302 in k1299 in k1296 in chicken.memory#move-memory! in k956 */
static void C_ccall f_1423(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1423,c,av);}
t2=(C_truep(((C_word*)t0)[2])?C_i_foreign_block_argumentp(((C_word*)t0)[2]):C_SCHEME_FALSE);
t3=(C_truep(((C_word*)t0)[3])?C_i_foreign_pointer_argumentp(((C_word*)t0)[3]):C_SCHEME_FALSE);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=stub183(C_SCHEME_UNDEFINED,t2,t3,C_i_foreign_fixnum_argumentp(t1),C_i_foreign_fixnum_argumentp(((C_word*)t0)[5]),C_i_foreign_fixnum_argumentp(((C_word*)t0)[6]));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k1425 in k1411 in move in k1305 in k1302 in k1299 in k1296 in chicken.memory#move-memory! in k956 */
static void C_ccall f_1427(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1427,c,av);}
/* lolevel.scm:177: checkn1 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1255(t2,((C_word*)t0)[3],t1,C_block_size(((C_word*)t0)[4]),((C_word*)t0)[5]);}

/* k1444 in move in k1305 in k1302 in k1299 in k1296 in chicken.memory#move-memory! in k956 */
static void C_ccall f_1446(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1446,c,av);}
a=C_alloc(10);
t2=(C_truep(t1)?t1:C_i_stringp(((C_word*)t0)[2]));
if(C_truep(t2)){
t3=C_block_size(((C_word*)t0)[2]);
t4=C_i_safe_pointerp(((C_word*)t0)[3]);
t5=(C_truep(t4)?t4:C_locativep(((C_word*)t0)[3]));
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1475,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)t0)[7])){
/* lolevel.scm:183: checkn1 */
t7=((C_word*)((C_word*)t0)[8])[1];
f_1255(t7,t6,((C_word*)t0)[7],t3,((C_word*)t0)[6]);}
else{
/* lolevel.scm:183: checkn1 */
t7=((C_word*)((C_word*)t0)[8])[1];
f_1255(t7,t6,t3,t3,((C_word*)t0)[6]);}}
else{
t6=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_1485,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t3,a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* lolevel.scm:184: ##sys#bytevector? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[20]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[20]+1);
av2[1]=t6;
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}}
else{
t3=C_fix((C_word)C_BAD_ARGUMENT_TYPE_ERROR);
/* lolevel.scm:133: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=((C_word*)t0)[4];
av2[2]=t3;
av2[3]=lf[17];
av2[4]=((C_word*)t0)[2];
tp(5,av2);}}}

/* k1473 in k1444 in move in k1305 in k1302 in k1299 in k1296 in chicken.memory#move-memory! in k956 */
static void C_ccall f_1475(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1475,c,av);}
t2=(C_truep(((C_word*)t0)[2])?C_i_foreign_pointer_argumentp(((C_word*)t0)[2]):C_SCHEME_FALSE);
t3=(C_truep(((C_word*)t0)[3])?C_i_foreign_block_argumentp(((C_word*)t0)[3]):C_SCHEME_FALSE);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=stub167(C_SCHEME_UNDEFINED,t2,t3,C_i_foreign_fixnum_argumentp(t1),C_i_foreign_fixnum_argumentp(((C_word*)t0)[5]),C_i_foreign_fixnum_argumentp(((C_word*)t0)[6]));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k1483 in k1444 in move in k1305 in k1302 in k1299 in k1296 in chicken.memory#move-memory! in k956 */
static void C_ccall f_1485(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,6)))){
C_save_and_reclaim((void *)f_1485,c,av);}
a=C_alloc(7);
t2=(C_truep(t1)?t1:C_i_stringp(((C_word*)t0)[2]));
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1495,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t4=(C_truep(((C_word*)t0)[7])?((C_word*)t0)[7]:((C_word*)t0)[8]);
/* lolevel.scm:185: checkn2 */
t5=((C_word*)((C_word*)t0)[9])[1];
f_1271(t5,t3,t4,((C_word*)t0)[8],C_block_size(((C_word*)t0)[2]),((C_word*)t0)[6],((C_word*)t0)[5]);}
else{
t3=C_fix((C_word)C_BAD_ARGUMENT_TYPE_ERROR);
/* lolevel.scm:133: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=((C_word*)t0)[4];
av2[2]=t3;
av2[3]=lf[17];
av2[4]=((C_word*)t0)[2];
tp(5,av2);}}}

/* k1493 in k1483 in k1444 in move in k1305 in k1302 in k1299 in k1296 in chicken.memory#move-memory! in k956 */
static void C_ccall f_1495(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1495,c,av);}
t2=(C_truep(((C_word*)t0)[2])?C_i_foreign_block_argumentp(((C_word*)t0)[2]):C_SCHEME_FALSE);
t3=(C_truep(((C_word*)t0)[3])?C_i_foreign_block_argumentp(((C_word*)t0)[3]):C_SCHEME_FALSE);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=stub199(C_SCHEME_UNDEFINED,t2,t3,C_i_foreign_fixnum_argumentp(t1),C_i_foreign_fixnum_argumentp(((C_word*)t0)[5]),C_i_foreign_fixnum_argumentp(((C_word*)t0)[6]));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.memory#allocate in k956 */
static void C_ccall f_1565(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_1565,c,av);}
a=C_alloc(5);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=stub320(t3,C_i_foreign_fixnum_argumentp(t2));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.memory#free in k956 */
static void C_ccall f_1572(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1572,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?stub326(C_SCHEME_UNDEFINED,C_i_foreign_pointer_argumentp(t2)):stub326(C_SCHEME_UNDEFINED,C_SCHEME_FALSE));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.memory#pointer? in k956 */
static void C_ccall f_1582(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1582,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_safe_pointerp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.memory#pointer-like? in k956 */
static void C_ccall f_1590(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1590,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(C_blockp(t2))?C_specialp(t2):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.memory#address->pointer in k956 */
static void C_ccall f_1601(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_1601,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1605,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* lolevel.scm:203: ##sys#check-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[29]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[29]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[30];
tp(4,av2);}}

/* k1603 in chicken.memory#address->pointer in k956 */
static void C_ccall f_1605(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1605,c,av);}
/* lolevel.scm:204: ##sys#address->pointer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[28]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[28]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}

/* chicken.memory#pointer->address in k956 */
static void C_ccall f_1610(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_1610,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1614,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* lolevel.scm:207: ##sys#check-special */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[33]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[33]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[34];
tp(4,av2);}}

/* k1612 in chicken.memory#pointer->address in k956 */
static void C_ccall f_1614(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1614,c,av);}
/* lolevel.scm:208: ##sys#pointer->address */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[32]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}

/* chicken.memory#object->pointer in k956 */
static void C_ccall f_1619(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_1619,c,av);}
a=C_alloc(5);
if(C_truep(C_blockp(t2))){
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=stub354(t3,t2);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.memory#pointer->object in k956 */
static void C_ccall f_1630(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_1630,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1634,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* lolevel.scm:215: ##sys#check-pointer */
t4=*((C_word*)lf[12]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[37];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k1632 in chicken.memory#pointer->object in k956 */
static void C_ccall f_1634(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1634,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_pointer_to_object(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.memory#pointer=? in k956 */
static void C_ccall f_1636(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_1636,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1640,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* lolevel.scm:219: ##sys#check-special */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[33]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[33]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[39];
tp(4,av2);}}

/* k1638 in chicken.memory#pointer=? in k956 */
static void C_ccall f_1640(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_1640,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1643,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* lolevel.scm:220: ##sys#check-special */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[33]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[33]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[39];
tp(4,av2);}}

/* k1641 in k1638 in chicken.memory#pointer=? in k956 */
static void C_ccall f_1643(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1643,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_pointer_eqp(((C_word*)t0)[3],((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.memory#pointer+ in k956 */
static void C_ccall f_1645(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_1645,c,av);}
a=C_alloc(5);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=(C_truep(t2)?C_i_foreign_pointer_argumentp(t2):C_SCHEME_FALSE);
t6=C_fix((C_word)sizeof(int) * CHAR_BIT);
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=stub369(t4,t5,C_i_foreign_ranged_integer_argumentp(t3,t6));
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* chicken.memory#align-to-word in k956 */
static void C_ccall f_1667(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_1667,c,av);}
a=C_alloc(8);
if(C_truep(C_i_integerp(t2))){
t3=C_a_i_bytevector(&a,1,C_fix(6));
t4=C_fix((C_word)sizeof(int) * CHAR_BIT);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=stub380(t3,C_i_foreign_ranged_integer_argumentp(t2,t4));
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t3=(C_truep(C_blockp(t2))?C_specialp(t2):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1697,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:233: ##sys#pointer->address */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[32]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[32]+1);
av2[1]=t4;
av2[2]=t2;
tp(3,av2);}}
else{
/* lolevel.scm:235: ##sys#signal-hook */
t4=*((C_word*)lf[5]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=lf[6];
av2[3]=lf[42];
av2[4]=lf[43];
av2[5]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(6,av2);}}}}

/* k1695 in chicken.memory#align-to-word in k956 */
static void C_ccall f_1697(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_1697,c,av);}
a=C_alloc(8);
t2=C_a_i_bytevector(&a,1,C_fix(6));
t3=C_fix((C_word)sizeof(int) * CHAR_BIT);
/* lolevel.scm:233: ##sys#address->pointer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[28]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[28]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=stub380(t2,C_i_foreign_ranged_integer_argumentp(t1,t3));
tp(3,av2);}}

/* chicken.memory#tag-pointer in k956 */
static void C_ccall f_1702(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1702,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1706,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* lolevel.scm:243: ##sys#make-tagged-pointer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[46]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[46]+1);
av2[1]=t4;
av2[2]=t3;
tp(3,av2);}}

/* k1704 in chicken.memory#tag-pointer in k956 */
static void C_ccall f_1706(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_1706,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1709,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(C_truep(C_blockp(((C_word*)t0)[3]))?C_specialp(((C_word*)t0)[3]):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=C_copy_pointer(((C_word*)t0)[3],t1);
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_fix((C_word)C_BAD_ARGUMENT_TYPE_NO_POINTER_ERROR);
/* lolevel.scm:246: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=t2;
av2[2]=t4;
av2[3]=lf[45];
av2[4]=((C_word*)t0)[3];
tp(5,av2);}}}

/* k1707 in k1704 in chicken.memory#tag-pointer in k956 */
static void C_ccall f_1709(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1709,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.memory#tagged-pointer? in k956 */
static void C_ccall f_1723(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1723,c,av);}
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
if(C_truep(C_blockp(t2))){
if(C_truep(C_taggedpointerp(t2))){
t5=C_i_not(t4);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=(C_truep(t5)?t5:C_i_equalp(t4,C_slot(t2,C_fix(1))));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}
else{
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* chicken.memory#pointer-tag in k956 */
static void C_ccall f_1754(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1754,c,av);}
t3=(C_truep(C_blockp(t2))?C_specialp(t2):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(C_taggedpointerp(t2))?C_slot(t2,C_fix(1)):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_fix((C_word)C_BAD_ARGUMENT_TYPE_NO_POINTER_ERROR);
/* lolevel.scm:258: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=t1;
av2[2]=t4;
av2[3]=lf[49];
av2[4]=t2;
tp(5,av2);}}}

/* chicken.memory#pointer-u8-set! in k956 */
static void C_ccall f_1778(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1778,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_u_i_pointer_u8_set(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.memory#pointer-s8-set! in k956 */
static void C_ccall f_1781(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1781,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_u_i_pointer_s8_set(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.memory#pointer-u16-set! in k956 */
static void C_ccall f_1784(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1784,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_u_i_pointer_u16_set(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.memory#pointer-s16-set! in k956 */
static void C_ccall f_1787(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1787,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_u_i_pointer_s16_set(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.memory#pointer-u32-set! in k956 */
static void C_ccall f_1790(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1790,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_u_i_pointer_u32_set(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.memory#pointer-s32-set! in k956 */
static void C_ccall f_1793(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1793,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_u_i_pointer_s32_set(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.memory#pointer-u64-set! in k956 */
static void C_ccall f_1796(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1796,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_u_i_pointer_u64_set(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.memory#pointer-s64-set! in k956 */
static void C_ccall f_1799(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1799,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_u_i_pointer_s64_set(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.memory#pointer-f32-set! in k956 */
static void C_ccall f_1802(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1802,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_u_i_pointer_f32_set(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.memory#pointer-f64-set! in k956 */
static void C_ccall f_1805(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1805,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_u_i_pointer_f64_set(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k1808 in k956 */
static void C_ccall f_1810(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1810,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[60]+1 /* (set! chicken.memory#pointer-u8-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1814,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2617,a[2]=((C_word)li85),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:283: chicken.base#getter-with-setter */
t5=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[51]+1);
av2[4]=lf[155];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1812 in k1808 in k956 */
static void C_ccall f_1814(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1814,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[61]+1 /* (set! chicken.memory#pointer-s8-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1818,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2614,a[2]=((C_word)li84),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:289: chicken.base#getter-with-setter */
t5=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[52]+1);
av2[4]=lf[154];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1818(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1818,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[62]+1 /* (set! chicken.memory#pointer-u16-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1822,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2611,a[2]=((C_word)li83),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:295: chicken.base#getter-with-setter */
t5=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[53]+1);
av2[4]=lf[153];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1822(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1822,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[63]+1 /* (set! chicken.memory#pointer-s16-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1826,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2608,a[2]=((C_word)li82),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:301: chicken.base#getter-with-setter */
t5=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[54]+1);
av2[4]=lf[152];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1826(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1826,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[64]+1 /* (set! chicken.memory#pointer-u32-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1830,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2605,a[2]=((C_word)li81),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:307: chicken.base#getter-with-setter */
t5=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[55]+1);
av2[4]=lf[151];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1830(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1830,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[65]+1 /* (set! chicken.memory#pointer-s32-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1834,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2602,a[2]=((C_word)li80),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:313: chicken.base#getter-with-setter */
t5=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[56]+1);
av2[4]=lf[150];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1834(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1834,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[66]+1 /* (set! chicken.memory#pointer-u64-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1838,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2599,a[2]=((C_word)li79),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:319: chicken.base#getter-with-setter */
t5=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[57]+1);
av2[4]=lf[149];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1838(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1838,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[67]+1 /* (set! chicken.memory#pointer-s64-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1842,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2596,a[2]=((C_word)li78),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:325: chicken.base#getter-with-setter */
t5=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[58]+1);
av2[4]=lf[148];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1842(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1842,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[68]+1 /* (set! chicken.memory#pointer-f32-ref ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1846,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2593,a[2]=((C_word)li77),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:331: chicken.base#getter-with-setter */
t5=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=*((C_word*)lf[59]+1);
av2[4]=lf[147];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1846(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(25,c,5)))){
C_save_and_reclaim((void *)f_1846,c,av);}
a=C_alloc(25);
t2=C_mutate((C_word*)lf[69]+1 /* (set! chicken.memory#pointer-f64-ref ...) */,t1);
t3=C_a_i_list1(&a,1,lf[70]);
t4=C_mutate((C_word*)lf[71]+1 /* (set! chicken.memory#make-pointer-vector ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1851,a[2]=t3,a[3]=((C_word)li37),tmp=(C_word)a,a+=4,tmp));
t5=C_mutate((C_word*)lf[76]+1 /* (set! chicken.memory#pointer-vector? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1915,a[2]=((C_word)li38),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[77]+1 /* (set! chicken.memory#pointer-vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1921,a[2]=((C_word)li40),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[78]+1 /* (set! chicken.memory#pointer-vector-fill! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1961,a[2]=((C_word)li42),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[80]+1 /* (set! chicken.memory#pointer-vector-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2022,a[2]=((C_word)li43),tmp=(C_word)a,a+=3,tmp));
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2050,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2573,a[2]=((C_word)li76),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:392: chicken.base#getter-with-setter */
t11=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t11;
av2[1]=t9;
av2[2]=t10;
av2[3]=*((C_word*)lf[80]+1);
av2[4]=lf[146];
((C_proc)(void*)(*((C_word*)t11+1)))(5,av2);}}

/* chicken.memory#make-pointer-vector in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1851(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_1851,c,av);}
a=C_alloc(6);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?((C_word*)t0)[2]:C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1858,a[2]=t2,a[3]=t4,a[4]=((C_word*)t0)[2],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* lolevel.scm:342: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[75]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[75]+1);
av2[1]=t5;
av2[2]=t2;
av2[3]=lf[73];
tp(4,av2);}}

/* k1856 in chicken.memory#make-pointer-vector in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1858(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_1858,c,av);}
a=C_alloc(6);
t2=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t3=stub494(C_SCHEME_UNDEFINED,t2);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1870,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* lolevel.scm:345: ##sys#make-blob */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[74]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[74]+1);
av2[1]=t4;
av2[2]=t3;
tp(3,av2);}}

/* k1868 in k1856 in chicken.memory#make-pointer-vector in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1870(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_1870,c,av);}
a=C_alloc(6);
t2=C_eqp(((C_word*)t0)[2],((C_word*)t0)[3]);
if(C_truep(t2)){
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record3(&a,3,lf[72],((C_word*)t0)[5],t1);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1882,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[2])){
/* lolevel.scm:348: ##sys#check-pointer */
t4=*((C_word*)lf[12]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[73];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_1882(2,av2);}}}}

/* k1880 in k1868 in k1856 in chicken.memory#make-pointer-vector in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_1882,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1887,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li36),tmp=(C_word)a,a+=6,tmp);
t3=(
  f_1887(t2,C_fix(0))
);
t4=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_record3(&a,3,lf[72],((C_word*)t0)[2],((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* doloop499 in k1880 in k1868 in k1856 in chicken.memory#make-pointer-vector in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static C_word C_fcall f_1887(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
t2=C_SCHEME_UNDEFINED;
return(t2);}
else{
t2=C_i_foreign_fixnum_argumentp(t1);
t3=(C_truep(((C_word*)t0)[3])?stub546(C_SCHEME_UNDEFINED,((C_word*)t0)[4],t2,C_i_foreign_pointer_argumentp(((C_word*)t0)[3])):stub546(C_SCHEME_UNDEFINED,((C_word*)t0)[4],t2,C_SCHEME_FALSE));
t5=C_fixnum_plus(t1,C_fix(1));
t1=t5;
goto loop;}}

/* chicken.memory#pointer-vector? in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1915(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1915,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_structurep(t2,lf[72]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.memory#pointer-vector in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1921(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_1921,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
t3=C_u_i_length(t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1926,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* lolevel.scm:359: make-pointer-vector */
t5=*((C_word*)lf[71]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k1924 in chicken.memory#pointer-vector in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1926(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1926,c,av);}
a=C_alloc(8);
t2=C_slot(t1,C_fix(2));
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1934,a[2]=t1,a[3]=t2,a[4]=t4,a[5]=((C_word)li39),tmp=(C_word)a,a+=6,tmp));
t6=((C_word*)t4)[1];
f_1934(t6,((C_word*)t0)[2],((C_word*)t0)[3],C_fix(0));}

/* doloop514 in k1924 in chicken.memory#pointer-vector in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_fcall f_1934(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_1934,4,t0,t1,t2,t3);}
a=C_alloc(8);
if(C_truep(C_i_nullp(t2))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_car(t2);
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1947,a[2]=t3,a[3]=t4,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=t1,a[7]=t2,tmp=(C_word)a,a+=8,tmp);
/* lolevel.scm:365: ##sys#check-pointer */
t6=*((C_word*)lf[12]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
av2[3]=lf[72];
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}}

/* k1945 in doloop514 in k1924 in chicken.memory#pointer-vector in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1947(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1947,c,av);}
t2=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t3=(C_truep(((C_word*)t0)[3])?stub546(C_SCHEME_UNDEFINED,((C_word*)t0)[4],t2,C_i_foreign_pointer_argumentp(((C_word*)t0)[3])):stub546(C_SCHEME_UNDEFINED,((C_word*)t0)[4],t2,C_SCHEME_FALSE));
t4=((C_word*)((C_word*)t0)[5])[1];
f_1934(t4,((C_word*)t0)[6],C_u_i_cdr(((C_word*)t0)[7]),C_fixnum_plus(((C_word*)t0)[2],C_fix(1)));}

/* chicken.memory#pointer-vector-fill! in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1961(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1961,c,av);}
a=C_alloc(5);
t4=C_i_check_structure_2(t2,lf[72],lf[79]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1968,a[2]=t2,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t3)){
/* lolevel.scm:370: ##sys#check-pointer */
t6=*((C_word*)lf[12]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t3;
av2[3]=lf[79];
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t6=t5;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
f_1968(2,av2);}}}

/* k1966 in chicken.memory#pointer-vector-fill! in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_1968(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_1968,c,av);}
a=C_alloc(6);
t2=C_slot(((C_word*)t0)[2],C_fix(2));
t3=C_slot(((C_word*)t0)[2],C_fix(1));
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1979,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word)li41),tmp=(C_word)a,a+=6,tmp);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=(
  f_1979(t4,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* doloop527 in k1966 in chicken.memory#pointer-vector-fill! in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static C_word C_fcall f_1979(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
t2=C_SCHEME_UNDEFINED;
return(t2);}
else{
t2=C_i_foreign_fixnum_argumentp(t1);
t3=(C_truep(((C_word*)t0)[3])?stub546(C_SCHEME_UNDEFINED,((C_word*)t0)[4],t2,C_i_foreign_pointer_argumentp(((C_word*)t0)[3])):stub546(C_SCHEME_UNDEFINED,((C_word*)t0)[4],t2,C_SCHEME_FALSE));
t5=C_fixnum_plus(t1,C_fix(1));
t1=t5;
goto loop;}}

/* chicken.memory#pointer-vector-set! in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2022(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_2022,c,av);}
a=C_alloc(6);
t5=C_i_check_structure_2(t2,lf[72],lf[81]);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2029,a[2]=t2,a[3]=t3,a[4]=t1,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* lolevel.scm:387: ##sys#check-range */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[83]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[83]+1);
av2[1]=t6;
av2[2]=t3;
av2[3]=C_fix(0);
av2[4]=C_slot(t2,C_fix(1));
tp(5,av2);}}

/* k2027 in chicken.memory#pointer-vector-set! in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2029(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2029,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2032,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
/* lolevel.scm:388: ##sys#check-pointer */
t3=*((C_word*)lf[12]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=lf[82];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_2032(2,av2);}}}

/* k2030 in k2027 in chicken.memory#pointer-vector-set! in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2032(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2032,c,av);}
t2=C_slot(((C_word*)t0)[2],C_fix(2));
t3=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(((C_word*)t0)[5])?stub546(C_SCHEME_UNDEFINED,t2,t3,C_i_foreign_pointer_argumentp(((C_word*)t0)[5])):stub546(C_SCHEME_UNDEFINED,t2,t3,C_SCHEME_FALSE));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2050(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(34,c,4)))){
C_save_and_reclaim((void *)f_2050,c,av);}
a=C_alloc(34);
t2=C_mutate((C_word*)lf[84]+1 /* (set! chicken.memory#pointer-vector-ref ...) */,t1);
t3=C_mutate((C_word*)lf[85]+1 /* (set! chicken.memory#pointer-vector-length ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2052,a[2]=((C_word)li44),tmp=(C_word)a,a+=3,tmp));
t4=C_a_i_provide(&a,1,lf[87]);
t5=C_mutate((C_word*)lf[88]+1 /* (set! chicken.memory.representation#object-copy ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2061,a[2]=((C_word)li47),tmp=(C_word)a,a+=3,tmp));
t6=C_a_i_vector1(&a,1,lf[90]);
t7=C_mutate(&lf[91] /* (set! chicken.memory.representation#xproc-tag ...) */,t6);
t8=C_mutate((C_word*)lf[92]+1 /* (set! chicken.memory.representation#extend-procedure ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2141,a[2]=((C_word)li50),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[96]+1 /* (set! chicken.memory.representation#extended-procedure? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2176,a[2]=((C_word)li52),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[98]+1 /* (set! chicken.memory.representation#procedure-data ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2212,a[2]=((C_word)li54),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[99]+1 /* (set! chicken.memory.representation#set-procedure-data! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2251,a[2]=((C_word)li55),tmp=(C_word)a,a+=3,tmp));
t12=C_mutate((C_word*)lf[102]+1 /* (set! chicken.memory.representation#vector-like? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2267,a[2]=((C_word)li56),tmp=(C_word)a,a+=3,tmp));
t13=C_mutate((C_word*)lf[103]+1 /* (set! chicken.memory.representation#block-set! ...) */,*((C_word*)lf[104]+1));
t14=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2288,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:472: chicken.base#getter-with-setter */
t15=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t15;
av2[1]=t14;
av2[2]=*((C_word*)lf[144]+1);
av2[3]=*((C_word*)lf[104]+1);
av2[4]=lf[145];
((C_proc)(void*)(*((C_word*)t15+1)))(5,av2);}}

/* chicken.memory#pointer-vector-length in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2052(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2052,c,av);}
t3=C_i_check_structure_2(t2,lf[72],lf[86]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.memory.representation#object-copy in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2061(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2061,c,av);}
a=C_alloc(6);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2067,a[2]=t4,a[3]=((C_word)li46),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_2067(t6,t1,t2);}

/* copy in chicken.memory.representation#object-copy in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_fcall f_2067(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_2067,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_not(C_blockp(t2)))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(C_i_symbolp(t2))){
/* lolevel.scm:423: ##sys#intern-symbol */{
C_word av2[3];
av2[0]=0;
av2[1]=t1;
av2[2]=C_slot(t2,C_fix(1));
C_string_to_symbol(3,av2);}}
else{
t3=C_block_size(t2);
t4=(C_truep(C_byteblockp(t2))?C_words(t3):t3);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2097,a[2]=t2,a[3]=t1,a[4]=t3,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* lolevel.scm:427: ##sys#make-vector */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[89]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[89]+1);
av2[1]=t5;
av2[2]=t4;
tp(3,av2);}}}}

/* k2095 in copy in chicken.memory.representation#object-copy in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2097(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_2097,c,av);}
a=C_alloc(13);
t2=C_copy_block(((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2100,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_byteblockp(((C_word*)t0)[2]))){
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(C_truep(C_specialp(((C_word*)t0)[2]))?C_fix(1):C_fix(0));
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2109,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=t6,a[5]=((C_word*)t0)[5],a[6]=((C_word)li45),tmp=(C_word)a,a+=7,tmp));
t8=((C_word*)t6)[1];
f_2109(t8,t3,t4);}}

/* k2098 in k2095 in copy in chicken.memory.representation#object-copy in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2100(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2100,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* doloop636 in k2095 in copy in chicken.memory.representation#object-copy in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_fcall f_2109(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_2109,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2130,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* lolevel.scm:431: copy */
t4=((C_word*)((C_word*)t0)[5])[1];
f_2067(t4,t3,C_slot(((C_word*)t0)[3],t2));}}

/* k2128 in doloop636 in k2095 in copy in chicken.memory.representation#object-copy in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2130(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2130,c,av);}
t2=C_i_setslot(((C_word*)t0)[2],((C_word*)t0)[3],t1);
t3=((C_word*)((C_word*)t0)[4])[1];
f_2109(t3,((C_word*)t0)[5],C_fixnum_plus(((C_word*)t0)[3],C_fix(1)));}

/* chicken.memory.representation#extend-procedure in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2141(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_2141,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2145,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* lolevel.scm:441: ##sys#check-closure */
t5=*((C_word*)lf[94]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[95];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2143 in chicken.memory.representation#extend-procedure in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2145(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_2145,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2150,a[2]=((C_word)li48),tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2166,a[2]=((C_word*)t0)[2],a[3]=((C_word)li49),tmp=(C_word)a,a+=4,tmp);
/* lolevel.scm:442: ##sys#decorate-lambda */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[93]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[93]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t2;
av2[4]=t3;
tp(5,av2);}}

/* a2149 in k2143 in chicken.memory.representation#extend-procedure in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2150(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2150,c,av);}
t3=C_i_pairp(t2);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?C_eqp(lf[91],C_slot(t2,C_fix(0))):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a2165 in k2143 in chicken.memory.representation#extend-procedure in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2166(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2166,c,av);}
a=C_alloc(3);
t4=C_a_i_cons(&a,2,lf[91],((C_word*)t0)[2]);
t5=C_i_setslot(t2,t3,t4);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* chicken.memory.representation#extended-procedure? in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2176(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2176,c,av);}
a=C_alloc(6);
if(C_truep(C_blockp(t2))){
if(C_truep(C_closurep(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2210,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2193,a[2]=((C_word)li51),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:448: ##sys#lambda-decoration */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[97]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[97]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=t4;
tp(4,av2);}}
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

/* a2192 in chicken.memory.representation#extended-procedure? in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2193(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2193,c,av);}
t3=C_i_pairp(t2);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?C_eqp(lf[91],C_slot(t2,C_fix(0))):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k2208 in chicken.memory.representation#extended-procedure? in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2210(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2210,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?C_SCHEME_TRUE:C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.memory.representation#procedure-data in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2212(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2212,c,av);}
a=C_alloc(6);
if(C_truep(C_blockp(t2))){
if(C_truep(C_closurep(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2243,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2226,a[2]=((C_word)li53),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:448: ##sys#lambda-decoration */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[97]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[97]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=t4;
tp(4,av2);}}
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

/* a2225 in chicken.memory.representation#procedure-data in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2226(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2226,c,av);}
t3=C_i_pairp(t2);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?C_eqp(lf[91],C_slot(t2,C_fix(0))):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k2241 in chicken.memory.representation#procedure-data in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2243(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2243,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?C_slot(t1,C_fix(1)):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.memory.representation#set-procedure-data! in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2251(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2251,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2265,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* lolevel.scm:461: extend-procedure */
t5=*((C_word*)lf[92]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2263 in chicken.memory.representation#set-procedure-data! in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2265(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2265,c,av);}
t2=C_eqp(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=C_SCHEME_UNDEFINED;
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* lolevel.scm:462: ##sys#signal-hook */
t3=*((C_word*)lf[5]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[6];
av2[3]=lf[100];
av2[4]=lf[101];
av2[5]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}}

/* chicken.memory.representation#vector-like? in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2267(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2267,c,av);}
if(C_truep(C_blockp(t2))){
t3=C_specialp(t2);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?C_i_not(t3):C_i_not(C_byteblockp(t2)));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2288(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(27,c,5)))){
C_save_and_reclaim((void *)f_2288,c,av);}
a=C_alloc(27);
t2=C_mutate((C_word*)lf[105]+1 /* (set! chicken.memory.representation#block-ref ...) */,t1);
t3=C_mutate((C_word*)lf[106]+1 /* (set! chicken.memory.representation#number-of-slots ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2290,a[2]=((C_word)li57),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[108]+1 /* (set! chicken.memory.representation#number-of-bytes ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2299,a[2]=((C_word)li58),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[111]+1 /* (set! chicken.memory.representation#make-record-instance ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2322,a[2]=((C_word)li59),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[114]+1 /* (set! chicken.memory.representation#record-instance? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2331,a[2]=((C_word)li60),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[115]+1 /* (set! chicken.memory.representation#record-instance-type ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2367,a[2]=((C_word)li61),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[117]+1 /* (set! chicken.memory.representation#record-instance-length ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2376,a[2]=((C_word)li62),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[119]+1 /* (set! chicken.memory.representation#record-instance-slot-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2389,a[2]=((C_word)li63),tmp=(C_word)a,a+=3,tmp));
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2415,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2549,a[2]=((C_word)li75),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:520: chicken.base#getter-with-setter */
t12=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t12;
av2[1]=t10;
av2[2]=t11;
av2[3]=*((C_word*)lf[119]+1);
av2[4]=lf[143];
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}

/* chicken.memory.representation#number-of-slots in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2290(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2290,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2294,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* lolevel.scm:476: ##sys#check-generic-vector */
t4=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[107];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2292 in chicken.memory.representation#number-of-slots in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2294(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2294,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_block_size(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.memory.representation#number-of-bytes in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2299(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2299,c,av);}
if(C_truep(C_i_not(C_blockp(t2)))){
/* lolevel.scm:481: ##sys#signal-hook */
t3=*((C_word*)lf[5]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=lf[6];
av2[3]=lf[109];
av2[4]=lf[110];
av2[5]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(C_byteblockp(t2))?C_block_size(t2):C_bytes(C_block_size(t2)));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.memory.representation#make-record-instance in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2322(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +0,c,4)))){
C_save_and_reclaim((void*)f_2322,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+0);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=C_i_check_symbol_2(t2,lf[112]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t1;
av2[2]=*((C_word*)lf[113]+1);
av2[3]=t2;
av2[4]=t3;
C_apply(5,av2);}}

/* chicken.memory.representation#record-instance? in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2331(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2331,c,av);}
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=(C_truep(C_blockp(t2))?C_structurep(t2):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_i_not(t4);
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=(C_truep(t6)?t6:C_eqp(t4,C_slot(t2,C_fix(0))));
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* chicken.memory.representation#record-instance-type in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2367(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2367,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2371,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* lolevel.scm:507: ##sys#check-generic-structure */
t4=*((C_word*)lf[8]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[116];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2369 in chicken.memory.representation#record-instance-type in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2371(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2371,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_slot(((C_word*)t0)[3],C_fix(0));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.memory.representation#record-instance-length in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2376(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2376,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2380,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* lolevel.scm:511: ##sys#check-generic-structure */
t4=*((C_word*)lf[8]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[118];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2378 in chicken.memory.representation#record-instance-length in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2380(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2380,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fixnum_difference(C_block_size(((C_word*)t0)[3]),C_fix(1));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.memory.representation#record-instance-slot-set! in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2389(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2389,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2393,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* lolevel.scm:515: ##sys#check-generic-structure */
t6=*((C_word*)lf[8]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
av2[3]=lf[120];
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2391 in chicken.memory.representation#record-instance-slot-set! in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2393(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_2393,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2396,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_block_size(((C_word*)t0)[3]);
/* lolevel.scm:516: ##sys#check-range */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[83]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[83]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(0);
av2[4]=C_fixnum_difference(t3,C_fix(1));
av2[5]=lf[120];
tp(6,av2);}}

/* k2394 in k2391 in chicken.memory.representation#record-instance-slot-set! in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2396(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2396,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_setslot(((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)),((C_word*)t0)[5]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2415(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(32,c,4)))){
C_save_and_reclaim((void *)f_2415,c,av);}
a=C_alloc(32);
t2=C_mutate((C_word*)lf[121]+1 /* (set! chicken.memory.representation#record-instance-slot ...) */,t1);
t3=C_mutate((C_word*)lf[122]+1 /* (set! chicken.memory.representation#record->vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2417,a[2]=((C_word)li65),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[124]+1 /* (set! chicken.memory.representation#object-become! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2455,a[2]=((C_word)li66),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[127]+1 /* (set! chicken.memory.representation#mutate-procedure! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2464,a[2]=((C_word)li67),tmp=(C_word)a,a+=3,tmp));
t6=C_a_i_provide(&a,1,lf[129]);
t7=C_mutate((C_word*)lf[130]+1 /* (set! chicken.locative#make-locative ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2495,a[2]=((C_word)li68),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[133]+1 /* (set! chicken.locative#make-weak-locative ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2511,a[2]=((C_word)li69),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[135]+1 /* (set! chicken.locative#locative-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2527,a[2]=((C_word)li70),tmp=(C_word)a,a+=3,tmp));
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2532,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2546,a[2]=((C_word)li74),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:591: chicken.base#getter-with-setter */
t12=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t12;
av2[1]=t10;
av2[2]=t11;
av2[3]=*((C_word*)lf[135]+1);
av2[4]=lf[141];
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}

/* chicken.memory.representation#record->vector in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2417(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2417,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2421,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* lolevel.scm:529: ##sys#check-generic-structure */
t4=*((C_word*)lf[8]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[123];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2419 in chicken.memory.representation#record->vector in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2421(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_2421,c,av);}
a=C_alloc(5);
t2=C_block_size(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2427,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* lolevel.scm:531: ##sys#make-vector */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[89]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[89]+1);
av2[1]=t3;
av2[2]=t2;
tp(3,av2);}}

/* k2425 in k2419 in chicken.memory.representation#record->vector in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2427(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2427,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2432,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word)li64),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
  f_2432(t2,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* doloop742 in k2425 in k2419 in chicken.memory.representation#record->vector in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static C_word C_fcall f_2432(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
return(((C_word*)t0)[3]);}
else{
t2=C_slot(((C_word*)t0)[4],t1);
t3=C_i_setslot(((C_word*)t0)[3],t1,t2);
t5=C_fixnum_plus(t1,C_fix(1));
t1=t5;
goto loop;}}

/* chicken.memory.representation#object-become! in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2455(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2455,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2459,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* lolevel.scm:540: ##sys#check-become-alist */
t4=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[126];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2457 in chicken.memory.representation#object-become! in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2459(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2459,c,av);}
/* lolevel.scm:541: ##sys#become! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[125]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[125]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}

/* chicken.memory.representation#mutate-procedure! in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2464(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_2464,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2468,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* lolevel.scm:544: ##sys#check-closure */
t5=*((C_word*)lf[94]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[128];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2466 in chicken.memory.representation#mutate-procedure! in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2468(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_2468,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2471,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* lolevel.scm:545: ##sys#check-closure */
t3=*((C_word*)lf[94]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[128];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2469 in k2466 in chicken.memory.representation#mutate-procedure! in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2471(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2471,c,av);}
a=C_alloc(5);
t2=C_block_size(((C_word*)t0)[2]);
t3=C_words(t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2478,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* lolevel.scm:548: ##sys#make-vector */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[89]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[89]+1);
av2[1]=t4;
av2[2]=t3;
tp(3,av2);}}

/* k2476 in k2469 in k2466 in chicken.memory.representation#mutate-procedure! in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2478(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_2478,c,av);}
a=C_alloc(8);
t2=C_copy_block(((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2481,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2493,a[2]=((C_word*)t0)[2],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* lolevel.scm:549: proc */
t5=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k2479 in k2476 in k2469 in k2466 in chicken.memory.representation#mutate-procedure! in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2481(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2481,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2491 in k2476 in k2469 in k2466 in chicken.memory.representation#mutate-procedure! in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2493(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2493,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_list1(&a,1,t2);
/* lolevel.scm:549: ##sys#become! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[125]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[125]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t3;
tp(3,av2);}}

/* chicken.locative#make-locative in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2495(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2495,c,av);}
if(C_truep(C_rest_nullp(c,3))){
/* lolevel.scm:583: ##sys#make-locative */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[131]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[131]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=C_fix(0);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[132];
tp(6,av2);}}
else{
/* lolevel.scm:583: ##sys#make-locative */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[131]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[131]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=C_get_rest_arg(c,3,av,3,t0);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[132];
tp(6,av2);}}}

/* chicken.locative#make-weak-locative in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2511(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2511,c,av);}
if(C_truep(C_rest_nullp(c,3))){
/* lolevel.scm:586: ##sys#make-locative */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[131]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[131]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=C_fix(0);
av2[4]=C_SCHEME_TRUE;
av2[5]=lf[134];
tp(6,av2);}}
else{
/* lolevel.scm:586: ##sys#make-locative */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[131]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[131]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=C_get_rest_arg(c,3,av,3,t0);
av2[4]=C_SCHEME_TRUE;
av2[5]=lf[134];
tp(6,av2);}}}

/* chicken.locative#locative-set! in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2527(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2527,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_locative_set(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k2530 in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2532(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2532,c,av);}
a=C_alloc(9);
t2=C_mutate((C_word*)lf[136]+1 /* (set! chicken.locative#locative-ref ...) */,t1);
t3=C_mutate((C_word*)lf[137]+1 /* (set! chicken.locative#locative->object ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2534,a[2]=((C_word)li71),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[138]+1 /* (set! chicken.locative#locative-index ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2537,a[2]=((C_word)li72),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[139]+1 /* (set! chicken.locative#locative? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2540,a[2]=((C_word)li73),tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* chicken.locative#locative->object in k2530 in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2534(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2534,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_locative_to_object(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.locative#locative-index in k2530 in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2537(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2537,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_locative_index(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.locative#locative? in k2530 in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2540(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2540,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(C_blockp(t2))?C_locativep(t2):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a2545 in k2413 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2546(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_2546,c,av);}
a=C_alloc(6);
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_locative_ref(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a2548 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2549(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_2549,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2553,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* lolevel.scm:522: ##sys#check-generic-structure */
t5=*((C_word*)lf[8]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[142];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2551 in a2548 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2553(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_2553,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2556,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_block_size(((C_word*)t0)[3]);
/* lolevel.scm:523: ##sys#check-range */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[83]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[83]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(0);
av2[4]=C_fixnum_difference(t3,C_fix(1));
av2[5]=lf[142];
tp(6,av2);}}

/* k2554 in k2551 in a2548 in k2286 in k2048 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2556(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2556,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_slot(((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a2572 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2573(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_2573,c,av);}
a=C_alloc(5);
t4=C_i_check_structure_2(t2,lf[72],lf[81]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2580,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* lolevel.scm:395: ##sys#check-range */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[83]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[83]+1);
av2[1]=t5;
av2[2]=t3;
av2[3]=C_fix(0);
av2[4]=C_slot(t2,C_fix(1));
tp(5,av2);}}

/* k2578 in a2572 in k1844 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2580(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_2580,c,av);}
a=C_alloc(5);
t2=C_slot(((C_word*)t0)[2],C_fix(2));
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=stub537(t3,t2,C_i_foreign_fixnum_argumentp(((C_word*)t0)[4]));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a2592 in k1840 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2593(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,1)))){
C_save_and_reclaim((void *)f_2593,c,av);}
a=C_alloc(4);
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_u_i_pointer_f64_ref(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a2595 in k1836 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2596(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,1)))){
C_save_and_reclaim((void *)f_2596,c,av);}
a=C_alloc(4);
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_u_i_pointer_f32_ref(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a2598 in k1832 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2599(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_2599,c,av);}
a=C_alloc(7);
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_u_i_pointer_s64_ref(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a2601 in k1828 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2602(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_2602,c,av);}
a=C_alloc(7);
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_u_i_pointer_u64_ref(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a2604 in k1824 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2605(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_2605,c,av);}
a=C_alloc(6);
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_u_i_pointer_s32_ref(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a2607 in k1820 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2608(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_2608,c,av);}
a=C_alloc(6);
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_u_i_pointer_u32_ref(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a2610 in k1816 in k1812 in k1808 in k956 */
static void C_ccall f_2611(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2611,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_u_i_pointer_s16_ref(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a2613 in k1812 in k1808 in k956 */
static void C_ccall f_2614(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2614,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_u_i_pointer_u16_ref(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a2616 in k1808 in k956 */
static void C_ccall f_2617(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2617,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_u_i_pointer_s8_ref(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a2619 in k956 */
static void C_ccall f_2620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2620,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_u_i_pointer_u8_ref(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k956 */
static void C_ccall f_958(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(97,c,4)))){
C_save_and_reclaim((void *)f_958,c,av);}
a=C_alloc(97);
t2=C_mutate((C_word*)lf[2]+1 /* (set! ##sys#check-block ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_960,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t3=C_mutate((C_word*)lf[4]+1 /* (set! ##sys#check-become-alist ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_978,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[8]+1 /* (set! ##sys#check-generic-structure ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1024,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[10]+1 /* (set! ##sys#check-generic-vector ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1049,a[2]=((C_word)li4),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[12]+1 /* (set! ##sys#check-pointer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1081,a[2]=((C_word)li5),tmp=(C_word)a,a+=3,tmp));
t7=lf[14];
t8=C_mutate((C_word*)lf[15]+1 /* (set! chicken.memory#move-memory! ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1222,a[2]=t7,a[3]=((C_word)li11),tmp=(C_word)a,a+=4,tmp));
t9=C_mutate((C_word*)lf[23]+1 /* (set! chicken.memory#allocate ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1565,a[2]=((C_word)li12),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[24]+1 /* (set! chicken.memory#free ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1572,a[2]=((C_word)li13),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[25]+1 /* (set! chicken.memory#pointer? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1582,a[2]=((C_word)li14),tmp=(C_word)a,a+=3,tmp));
t12=C_mutate((C_word*)lf[26]+1 /* (set! chicken.memory#pointer-like? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1590,a[2]=((C_word)li15),tmp=(C_word)a,a+=3,tmp));
t13=C_mutate((C_word*)lf[27]+1 /* (set! chicken.memory#address->pointer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1601,a[2]=((C_word)li16),tmp=(C_word)a,a+=3,tmp));
t14=C_mutate((C_word*)lf[31]+1 /* (set! chicken.memory#pointer->address ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1610,a[2]=((C_word)li17),tmp=(C_word)a,a+=3,tmp));
t15=C_mutate((C_word*)lf[35]+1 /* (set! chicken.memory#object->pointer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1619,a[2]=((C_word)li18),tmp=(C_word)a,a+=3,tmp));
t16=C_mutate((C_word*)lf[36]+1 /* (set! chicken.memory#pointer->object ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1630,a[2]=((C_word)li19),tmp=(C_word)a,a+=3,tmp));
t17=C_mutate((C_word*)lf[38]+1 /* (set! chicken.memory#pointer=? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1636,a[2]=((C_word)li20),tmp=(C_word)a,a+=3,tmp));
t18=C_mutate((C_word*)lf[40]+1 /* (set! chicken.memory#pointer+ ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1645,a[2]=((C_word)li21),tmp=(C_word)a,a+=3,tmp));
t19=C_mutate((C_word*)lf[41]+1 /* (set! chicken.memory#align-to-word ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1667,a[2]=((C_word)li22),tmp=(C_word)a,a+=3,tmp));
t20=C_mutate((C_word*)lf[44]+1 /* (set! chicken.memory#tag-pointer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1702,a[2]=((C_word)li23),tmp=(C_word)a,a+=3,tmp));
t21=C_mutate((C_word*)lf[47]+1 /* (set! chicken.memory#tagged-pointer? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1723,a[2]=((C_word)li24),tmp=(C_word)a,a+=3,tmp));
t22=C_mutate((C_word*)lf[48]+1 /* (set! chicken.memory#pointer-tag ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1754,a[2]=((C_word)li25),tmp=(C_word)a,a+=3,tmp));
t23=C_mutate((C_word*)lf[50]+1 /* (set! chicken.memory#pointer-u8-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1778,a[2]=((C_word)li26),tmp=(C_word)a,a+=3,tmp));
t24=C_mutate((C_word*)lf[51]+1 /* (set! chicken.memory#pointer-s8-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1781,a[2]=((C_word)li27),tmp=(C_word)a,a+=3,tmp));
t25=C_mutate((C_word*)lf[52]+1 /* (set! chicken.memory#pointer-u16-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1784,a[2]=((C_word)li28),tmp=(C_word)a,a+=3,tmp));
t26=C_mutate((C_word*)lf[53]+1 /* (set! chicken.memory#pointer-s16-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1787,a[2]=((C_word)li29),tmp=(C_word)a,a+=3,tmp));
t27=C_mutate((C_word*)lf[54]+1 /* (set! chicken.memory#pointer-u32-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1790,a[2]=((C_word)li30),tmp=(C_word)a,a+=3,tmp));
t28=C_mutate((C_word*)lf[55]+1 /* (set! chicken.memory#pointer-s32-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1793,a[2]=((C_word)li31),tmp=(C_word)a,a+=3,tmp));
t29=C_mutate((C_word*)lf[56]+1 /* (set! chicken.memory#pointer-u64-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1796,a[2]=((C_word)li32),tmp=(C_word)a,a+=3,tmp));
t30=C_mutate((C_word*)lf[57]+1 /* (set! chicken.memory#pointer-s64-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1799,a[2]=((C_word)li33),tmp=(C_word)a,a+=3,tmp));
t31=C_mutate((C_word*)lf[58]+1 /* (set! chicken.memory#pointer-f32-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1802,a[2]=((C_word)li34),tmp=(C_word)a,a+=3,tmp));
t32=C_mutate((C_word*)lf[59]+1 /* (set! chicken.memory#pointer-f64-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1805,a[2]=((C_word)li35),tmp=(C_word)a,a+=3,tmp));
t33=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1810,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t34=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2620,a[2]=((C_word)li86),tmp=(C_word)a,a+=3,tmp);
/* lolevel.scm:277: chicken.base#getter-with-setter */
t35=*((C_word*)lf[140]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t35;
av2[1]=t33;
av2[2]=t34;
av2[3]=*((C_word*)lf[50]+1);
av2[4]=lf[156];
((C_proc)(void*)(*((C_word*)t35+1)))(5,av2);}}

/* ##sys#check-block in k956 */
static void C_ccall f_960(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +0,c,4)))){
C_save_and_reclaim((void*)f_960,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+0);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
if(C_truep(C_blockp(t2))){
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_fix((C_word)C_BAD_ARGUMENT_TYPE_NO_BLOCK_ERROR);
if(C_truep(C_i_pairp(t3))){
/* lolevel.scm:84: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[3]+1);
av2[1]=t1;
av2[2]=t4;
av2[3]=C_get_rest_arg(c,3,av,3,t0);
av2[4]=t2;
tp(5,av2);}}
else{
/* lolevel.scm:84: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=t1;
av2[2]=t4;
av2[3]=C_SCHEME_FALSE;
av2[4]=t2;
tp(5,av2);}}}}

/* ##sys#check-become-alist in k956 */
static void C_ccall f_978(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_978,c,av);}
a=C_alloc(8);
t4=C_i_check_list_2(t2,t3);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_987,a[2]=t3,a[3]=t6,a[4]=t2,a[5]=((C_word)li1),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_987(t8,t1,t2);}

/* loop in ##sys#check-become-alist in k956 */
static void C_fcall f_987(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,5)))){
C_save_and_reclaim_args((void *)trf_987,3,t0,t1,t2);}
a=C_alloc(7);
t3=C_i_nullp(t2);
if(C_truep(t3)){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_i_pairp(t2))){
t4=C_u_i_car(t2);
t5=C_i_check_pair_2(t4,((C_word*)t0)[2]);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1007,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t4,a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
/* lolevel.scm:95: ##sys#check-block */
t7=*((C_word*)lf[2]+1);{
C_word av2[4];
av2[0]=t7;
av2[1]=t6;
av2[2]=C_u_i_car(t4);
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
/* lolevel.scm:99: ##sys#signal-hook */
t4=*((C_word*)lf[5]+1);{
C_word av2[6];
av2[0]=t4;
av2[1]=t1;
av2[2]=lf[6];
av2[3]=((C_word*)t0)[2];
av2[4]=lf[7];
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(6,av2);}}}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_lolevel_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("lolevel"));
C_check_nursery_minimum(C_calculate_demand(19,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void*)C_lolevel_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(1020))){
C_save(t1);
C_rereclaim2(1020*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(19);
C_initialize_lf(lf,157);
lf[0]=C_h_intern(&lf[0],7, C_text("lolevel"));
lf[1]=C_h_intern(&lf[1],15, C_text("chicken.memory#"));
lf[2]=C_h_intern(&lf[2],17, C_text("##sys#check-block"));
lf[3]=C_h_intern(&lf[3],16, C_text("##sys#error-hook"));
lf[4]=C_h_intern(&lf[4],24, C_text("##sys#check-become-alist"));
lf[5]=C_h_intern(&lf[5],17, C_text("##sys#signal-hook"));
lf[6]=C_h_intern_kw(&lf[6],10, C_text("type-error"));
lf[7]=C_decode_literal(C_heaptop,C_text("\376B\000\0002bad argument type - not an a-list of block objects"));
lf[8]=C_h_intern(&lf[8],29, C_text("##sys#check-generic-structure"));
lf[9]=C_decode_literal(C_heaptop,C_text("\376B\000\000#bad argument type - not a structure"));
lf[10]=C_h_intern(&lf[10],26, C_text("##sys#check-generic-vector"));
lf[11]=C_decode_literal(C_heaptop,C_text("\376B\000\000,bad argument type - not a vector-like object"));
lf[12]=C_h_intern(&lf[12],19, C_text("##sys#check-pointer"));
lf[13]=C_decode_literal(C_heaptop,C_text("\376B\000\000!bad argument type - not a pointer"));
lf[14]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\004\001mmap\376\003\000\000\002\376\001\000\000\010\001u8vector\376\003\000\000\002\376\001\000\000\011\001u16vector\376\003\000\000\002\376\001\000\000\011\001u32vector\376\003\000\000\002\376"
"\001\000\000\011\001u64vector\376\003\000\000\002\376\001\000\000\010\001s8vector\376\003\000\000\002\376\001\000\000\011\001s16vector\376\003\000\000\002\376\001\000\000\011\001s32vector\376\003\000\000\002\376\001"
"\000\000\011\001s64vector\376\003\000\000\002\376\001\000\000\011\001f32vector\376\003\000\000\002\376\001\000\000\011\001f64vector\376\377\016"));
lf[15]=C_h_intern(&lf[15],27, C_text("chicken.memory#move-memory!"));
lf[16]=C_h_intern(&lf[16],11, C_text("##sys#error"));
lf[17]=C_h_intern(&lf[17],12, C_text("move-memory!"));
lf[18]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034need number of bytes to move"));
lf[19]=C_decode_literal(C_heaptop,C_text("\376B\000\000!number of bytes to move too large"));
lf[20]=C_h_intern(&lf[20],17, C_text("##sys#bytevector\077"));
lf[21]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033negative destination offset"));
lf[22]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026negative source offset"));
lf[23]=C_h_intern(&lf[23],23, C_text("chicken.memory#allocate"));
lf[24]=C_h_intern(&lf[24],19, C_text("chicken.memory#free"));
lf[25]=C_h_intern(&lf[25],23, C_text("chicken.memory#pointer\077"));
lf[26]=C_h_intern(&lf[26],28, C_text("chicken.memory#pointer-like\077"));
lf[27]=C_h_intern(&lf[27],31, C_text("chicken.memory#address->pointer"));
lf[28]=C_h_intern(&lf[28],22, C_text("##sys#address->pointer"));
lf[29]=C_h_intern(&lf[29],19, C_text("##sys#check-integer"));
lf[30]=C_h_intern(&lf[30],16, C_text("address->pointer"));
lf[31]=C_h_intern(&lf[31],31, C_text("chicken.memory#pointer->address"));
lf[32]=C_h_intern(&lf[32],22, C_text("##sys#pointer->address"));
lf[33]=C_h_intern(&lf[33],19, C_text("##sys#check-special"));
lf[34]=C_h_intern(&lf[34],16, C_text("pointer->address"));
lf[35]=C_h_intern(&lf[35],30, C_text("chicken.memory#object->pointer"));
lf[36]=C_h_intern(&lf[36],30, C_text("chicken.memory#pointer->object"));
lf[37]=C_h_intern(&lf[37],15, C_text("pointer->object"));
lf[38]=C_h_intern(&lf[38],24, C_text("chicken.memory#pointer=\077"));
lf[39]=C_h_intern(&lf[39],9, C_text("pointer=\077"));
lf[40]=C_h_intern(&lf[40],23, C_text("chicken.memory#pointer+"));
lf[41]=C_h_intern(&lf[41],28, C_text("chicken.memory#align-to-word"));
lf[42]=C_h_intern(&lf[42],13, C_text("align-to-word"));
lf[43]=C_decode_literal(C_heaptop,C_text("\376B\000\000,bad argument type - not a pointer or integer"));
lf[44]=C_h_intern(&lf[44],26, C_text("chicken.memory#tag-pointer"));
lf[45]=C_h_intern(&lf[45],11, C_text("tag-pointer"));
lf[46]=C_h_intern(&lf[46],25, C_text("##sys#make-tagged-pointer"));
lf[47]=C_h_intern(&lf[47],30, C_text("chicken.memory#tagged-pointer\077"));
lf[48]=C_h_intern(&lf[48],26, C_text("chicken.memory#pointer-tag"));
lf[49]=C_h_intern(&lf[49],11, C_text("pointer-tag"));
lf[50]=C_h_intern(&lf[50],30, C_text("chicken.memory#pointer-u8-set!"));
lf[51]=C_h_intern(&lf[51],30, C_text("chicken.memory#pointer-s8-set!"));
lf[52]=C_h_intern(&lf[52],31, C_text("chicken.memory#pointer-u16-set!"));
lf[53]=C_h_intern(&lf[53],31, C_text("chicken.memory#pointer-s16-set!"));
lf[54]=C_h_intern(&lf[54],31, C_text("chicken.memory#pointer-u32-set!"));
lf[55]=C_h_intern(&lf[55],31, C_text("chicken.memory#pointer-s32-set!"));
lf[56]=C_h_intern(&lf[56],31, C_text("chicken.memory#pointer-u64-set!"));
lf[57]=C_h_intern(&lf[57],31, C_text("chicken.memory#pointer-s64-set!"));
lf[58]=C_h_intern(&lf[58],31, C_text("chicken.memory#pointer-f32-set!"));
lf[59]=C_h_intern(&lf[59],31, C_text("chicken.memory#pointer-f64-set!"));
lf[60]=C_h_intern(&lf[60],29, C_text("chicken.memory#pointer-u8-ref"));
lf[61]=C_h_intern(&lf[61],29, C_text("chicken.memory#pointer-s8-ref"));
lf[62]=C_h_intern(&lf[62],30, C_text("chicken.memory#pointer-u16-ref"));
lf[63]=C_h_intern(&lf[63],30, C_text("chicken.memory#pointer-s16-ref"));
lf[64]=C_h_intern(&lf[64],30, C_text("chicken.memory#pointer-u32-ref"));
lf[65]=C_h_intern(&lf[65],30, C_text("chicken.memory#pointer-s32-ref"));
lf[66]=C_h_intern(&lf[66],30, C_text("chicken.memory#pointer-u64-ref"));
lf[67]=C_h_intern(&lf[67],30, C_text("chicken.memory#pointer-s64-ref"));
lf[68]=C_h_intern(&lf[68],30, C_text("chicken.memory#pointer-f32-ref"));
lf[69]=C_h_intern(&lf[69],30, C_text("chicken.memory#pointer-f64-ref"));
lf[70]=C_h_intern(&lf[70],5, C_text("unset"));
lf[71]=C_h_intern(&lf[71],34, C_text("chicken.memory#make-pointer-vector"));
lf[72]=C_h_intern(&lf[72],14, C_text("pointer-vector"));
lf[73]=C_h_intern(&lf[73],19, C_text("make-pointer-vector"));
lf[74]=C_h_intern(&lf[74],15, C_text("##sys#make-blob"));
lf[75]=C_h_intern(&lf[75],18, C_text("##sys#check-fixnum"));
lf[76]=C_h_intern(&lf[76],30, C_text("chicken.memory#pointer-vector\077"));
lf[77]=C_h_intern(&lf[77],29, C_text("chicken.memory#pointer-vector"));
lf[78]=C_h_intern(&lf[78],35, C_text("chicken.memory#pointer-vector-fill!"));
lf[79]=C_h_intern(&lf[79],20, C_text("pointer-vector-fill!"));
lf[80]=C_h_intern(&lf[80],34, C_text("chicken.memory#pointer-vector-set!"));
lf[81]=C_h_intern(&lf[81],18, C_text("pointer-vector-ref"));
lf[82]=C_h_intern(&lf[82],19, C_text("pointer-vector-set!"));
lf[83]=C_h_intern(&lf[83],17, C_text("##sys#check-range"));
lf[84]=C_h_intern(&lf[84],33, C_text("chicken.memory#pointer-vector-ref"));
lf[85]=C_h_intern(&lf[85],36, C_text("chicken.memory#pointer-vector-length"));
lf[86]=C_h_intern(&lf[86],21, C_text("pointer-vector-length"));
lf[87]=C_h_intern(&lf[87],30, C_text("chicken.memory.representation#"));
lf[88]=C_h_intern(&lf[88],41, C_text("chicken.memory.representation#object-copy"));
lf[89]=C_h_intern(&lf[89],17, C_text("##sys#make-vector"));
lf[90]=C_h_intern(&lf[90],8, C_text("extended"));
lf[92]=C_h_intern(&lf[92],46, C_text("chicken.memory.representation#extend-procedure"));
lf[93]=C_h_intern(&lf[93],21, C_text("##sys#decorate-lambda"));
lf[94]=C_h_intern(&lf[94],19, C_text("##sys#check-closure"));
lf[95]=C_h_intern(&lf[95],16, C_text("extend-procedure"));
lf[96]=C_h_intern(&lf[96],49, C_text("chicken.memory.representation#extended-procedure\077"));
lf[97]=C_h_intern(&lf[97],23, C_text("##sys#lambda-decoration"));
lf[98]=C_h_intern(&lf[98],44, C_text("chicken.memory.representation#procedure-data"));
lf[99]=C_h_intern(&lf[99],49, C_text("chicken.memory.representation#set-procedure-data!"));
lf[100]=C_h_intern(&lf[100],19, C_text("set-procedure-data!"));
lf[101]=C_decode_literal(C_heaptop,C_text("\376B\000\000-bad argument type - not an extended procedure"));
lf[102]=C_h_intern(&lf[102],42, C_text("chicken.memory.representation#vector-like\077"));
lf[103]=C_h_intern(&lf[103],40, C_text("chicken.memory.representation#block-set!"));
lf[104]=C_h_intern(&lf[104],16, C_text("##sys#block-set!"));
lf[105]=C_h_intern(&lf[105],39, C_text("chicken.memory.representation#block-ref"));
lf[106]=C_h_intern(&lf[106],45, C_text("chicken.memory.representation#number-of-slots"));
lf[107]=C_h_intern(&lf[107],15, C_text("number-of-slots"));
lf[108]=C_h_intern(&lf[108],45, C_text("chicken.memory.representation#number-of-bytes"));
lf[109]=C_h_intern(&lf[109],15, C_text("number-of-bytes"));
lf[110]=C_decode_literal(C_heaptop,C_text("\376B\000\0002cannot compute number of bytes of immediate object"));
lf[111]=C_h_intern(&lf[111],50, C_text("chicken.memory.representation#make-record-instance"));
lf[112]=C_h_intern(&lf[112],20, C_text("make-record-instance"));
lf[113]=C_h_intern(&lf[113],20, C_text("##sys#make-structure"));
lf[114]=C_h_intern(&lf[114],46, C_text("chicken.memory.representation#record-instance\077"));
lf[115]=C_h_intern(&lf[115],50, C_text("chicken.memory.representation#record-instance-type"));
lf[116]=C_h_intern(&lf[116],20, C_text("record-instance-type"));
lf[117]=C_h_intern(&lf[117],52, C_text("chicken.memory.representation#record-instance-length"));
lf[118]=C_h_intern(&lf[118],22, C_text("record-instance-length"));
lf[119]=C_h_intern(&lf[119],55, C_text("chicken.memory.representation#record-instance-slot-set!"));
lf[120]=C_h_intern(&lf[120],25, C_text("record-instance-slot-set!"));
lf[121]=C_h_intern(&lf[121],50, C_text("chicken.memory.representation#record-instance-slot"));
lf[122]=C_h_intern(&lf[122],44, C_text("chicken.memory.representation#record->vector"));
lf[123]=C_h_intern(&lf[123],14, C_text("record->vector"));
lf[124]=C_h_intern(&lf[124],44, C_text("chicken.memory.representation#object-become!"));
lf[125]=C_h_intern(&lf[125],13, C_text("##sys#become!"));
lf[126]=C_h_intern(&lf[126],14, C_text("object-become!"));
lf[127]=C_h_intern(&lf[127],47, C_text("chicken.memory.representation#mutate-procedure!"));
lf[128]=C_h_intern(&lf[128],17, C_text("mutate-procedure!"));
lf[129]=C_h_intern(&lf[129],17, C_text("chicken.locative#"));
lf[130]=C_h_intern(&lf[130],30, C_text("chicken.locative#make-locative"));
lf[131]=C_h_intern(&lf[131],19, C_text("##sys#make-locative"));
lf[132]=C_h_intern(&lf[132],13, C_text("make-locative"));
lf[133]=C_h_intern(&lf[133],35, C_text("chicken.locative#make-weak-locative"));
lf[134]=C_h_intern(&lf[134],18, C_text("make-weak-locative"));
lf[135]=C_h_intern(&lf[135],30, C_text("chicken.locative#locative-set!"));
lf[136]=C_h_intern(&lf[136],29, C_text("chicken.locative#locative-ref"));
lf[137]=C_h_intern(&lf[137],33, C_text("chicken.locative#locative->object"));
lf[138]=C_h_intern(&lf[138],31, C_text("chicken.locative#locative-index"));
lf[139]=C_h_intern(&lf[139],26, C_text("chicken.locative#locative\077"));
lf[140]=C_h_intern(&lf[140],31, C_text("chicken.base#getter-with-setter"));
lf[141]=C_decode_literal(C_heaptop,C_text("\376B\000\000#(chicken.locative#locative-ref loc)"));
lf[142]=C_h_intern(&lf[142],20, C_text("record-instance-slot"));
lf[143]=C_decode_literal(C_heaptop,C_text("\376B\000\0008(chicken.memory.representation#record-instance-slot x i)"));
lf[144]=C_h_intern(&lf[144],15, C_text("##sys#block-ref"));
lf[145]=C_decode_literal(C_heaptop,C_text("\376B\000\000-(chicken.memory.representation#block-ref x i)"));
lf[146]=C_decode_literal(C_heaptop,C_text("\376B\000\000((chicken.memory#pointer-vector-ref pv i)"));
lf[147]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.memory#pointer-f64-ref p)"));
lf[148]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.memory#pointer-f32-ref p)"));
lf[149]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.memory#pointer-s64-ref p)"));
lf[150]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.memory#pointer-u64-ref p)"));
lf[151]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.memory#pointer-s32-ref p)"));
lf[152]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.memory#pointer-u32-ref p)"));
lf[153]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.memory#pointer-s16-ref p)"));
lf[154]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042(chicken.memory#pointer-u16-ref p)"));
lf[155]=C_decode_literal(C_heaptop,C_text("\376B\000\000!(chicken.memory#pointer-s8-ref p)"));
lf[156]=C_decode_literal(C_heaptop,C_text("\376B\000\000!(chicken.memory#pointer-u8-ref p)"));
C_register_lf2(lf,157,create_ptable());{}
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_958,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[158] = {
{C_text("f_1007:lolevel_2escm"),(void*)f_1007},
{C_text("f_1010:lolevel_2escm"),(void*)f_1010},
{C_text("f_1024:lolevel_2escm"),(void*)f_1024},
{C_text("f_1049:lolevel_2escm"),(void*)f_1049},
{C_text("f_1068:lolevel_2escm"),(void*)f_1068},
{C_text("f_1081:lolevel_2escm"),(void*)f_1081},
{C_text("f_1222:lolevel_2escm"),(void*)f_1222},
{C_text("f_1243:lolevel_2escm"),(void*)f_1243},
{C_text("f_1249:lolevel_2escm"),(void*)f_1249},
{C_text("f_1255:lolevel_2escm"),(void*)f_1255},
{C_text("f_1271:lolevel_2escm"),(void*)f_1271},
{C_text("f_1298:lolevel_2escm"),(void*)f_1298},
{C_text("f_1301:lolevel_2escm"),(void*)f_1301},
{C_text("f_1304:lolevel_2escm"),(void*)f_1304},
{C_text("f_1307:lolevel_2escm"),(void*)f_1307},
{C_text("f_1312:lolevel_2escm"),(void*)f_1312},
{C_text("f_1404:lolevel_2escm"),(void*)f_1404},
{C_text("f_1413:lolevel_2escm"),(void*)f_1413},
{C_text("f_1423:lolevel_2escm"),(void*)f_1423},
{C_text("f_1427:lolevel_2escm"),(void*)f_1427},
{C_text("f_1446:lolevel_2escm"),(void*)f_1446},
{C_text("f_1475:lolevel_2escm"),(void*)f_1475},
{C_text("f_1485:lolevel_2escm"),(void*)f_1485},
{C_text("f_1495:lolevel_2escm"),(void*)f_1495},
{C_text("f_1565:lolevel_2escm"),(void*)f_1565},
{C_text("f_1572:lolevel_2escm"),(void*)f_1572},
{C_text("f_1582:lolevel_2escm"),(void*)f_1582},
{C_text("f_1590:lolevel_2escm"),(void*)f_1590},
{C_text("f_1601:lolevel_2escm"),(void*)f_1601},
{C_text("f_1605:lolevel_2escm"),(void*)f_1605},
{C_text("f_1610:lolevel_2escm"),(void*)f_1610},
{C_text("f_1614:lolevel_2escm"),(void*)f_1614},
{C_text("f_1619:lolevel_2escm"),(void*)f_1619},
{C_text("f_1630:lolevel_2escm"),(void*)f_1630},
{C_text("f_1634:lolevel_2escm"),(void*)f_1634},
{C_text("f_1636:lolevel_2escm"),(void*)f_1636},
{C_text("f_1640:lolevel_2escm"),(void*)f_1640},
{C_text("f_1643:lolevel_2escm"),(void*)f_1643},
{C_text("f_1645:lolevel_2escm"),(void*)f_1645},
{C_text("f_1667:lolevel_2escm"),(void*)f_1667},
{C_text("f_1697:lolevel_2escm"),(void*)f_1697},
{C_text("f_1702:lolevel_2escm"),(void*)f_1702},
{C_text("f_1706:lolevel_2escm"),(void*)f_1706},
{C_text("f_1709:lolevel_2escm"),(void*)f_1709},
{C_text("f_1723:lolevel_2escm"),(void*)f_1723},
{C_text("f_1754:lolevel_2escm"),(void*)f_1754},
{C_text("f_1778:lolevel_2escm"),(void*)f_1778},
{C_text("f_1781:lolevel_2escm"),(void*)f_1781},
{C_text("f_1784:lolevel_2escm"),(void*)f_1784},
{C_text("f_1787:lolevel_2escm"),(void*)f_1787},
{C_text("f_1790:lolevel_2escm"),(void*)f_1790},
{C_text("f_1793:lolevel_2escm"),(void*)f_1793},
{C_text("f_1796:lolevel_2escm"),(void*)f_1796},
{C_text("f_1799:lolevel_2escm"),(void*)f_1799},
{C_text("f_1802:lolevel_2escm"),(void*)f_1802},
{C_text("f_1805:lolevel_2escm"),(void*)f_1805},
{C_text("f_1810:lolevel_2escm"),(void*)f_1810},
{C_text("f_1814:lolevel_2escm"),(void*)f_1814},
{C_text("f_1818:lolevel_2escm"),(void*)f_1818},
{C_text("f_1822:lolevel_2escm"),(void*)f_1822},
{C_text("f_1826:lolevel_2escm"),(void*)f_1826},
{C_text("f_1830:lolevel_2escm"),(void*)f_1830},
{C_text("f_1834:lolevel_2escm"),(void*)f_1834},
{C_text("f_1838:lolevel_2escm"),(void*)f_1838},
{C_text("f_1842:lolevel_2escm"),(void*)f_1842},
{C_text("f_1846:lolevel_2escm"),(void*)f_1846},
{C_text("f_1851:lolevel_2escm"),(void*)f_1851},
{C_text("f_1858:lolevel_2escm"),(void*)f_1858},
{C_text("f_1870:lolevel_2escm"),(void*)f_1870},
{C_text("f_1882:lolevel_2escm"),(void*)f_1882},
{C_text("f_1887:lolevel_2escm"),(void*)f_1887},
{C_text("f_1915:lolevel_2escm"),(void*)f_1915},
{C_text("f_1921:lolevel_2escm"),(void*)f_1921},
{C_text("f_1926:lolevel_2escm"),(void*)f_1926},
{C_text("f_1934:lolevel_2escm"),(void*)f_1934},
{C_text("f_1947:lolevel_2escm"),(void*)f_1947},
{C_text("f_1961:lolevel_2escm"),(void*)f_1961},
{C_text("f_1968:lolevel_2escm"),(void*)f_1968},
{C_text("f_1979:lolevel_2escm"),(void*)f_1979},
{C_text("f_2022:lolevel_2escm"),(void*)f_2022},
{C_text("f_2029:lolevel_2escm"),(void*)f_2029},
{C_text("f_2032:lolevel_2escm"),(void*)f_2032},
{C_text("f_2050:lolevel_2escm"),(void*)f_2050},
{C_text("f_2052:lolevel_2escm"),(void*)f_2052},
{C_text("f_2061:lolevel_2escm"),(void*)f_2061},
{C_text("f_2067:lolevel_2escm"),(void*)f_2067},
{C_text("f_2097:lolevel_2escm"),(void*)f_2097},
{C_text("f_2100:lolevel_2escm"),(void*)f_2100},
{C_text("f_2109:lolevel_2escm"),(void*)f_2109},
{C_text("f_2130:lolevel_2escm"),(void*)f_2130},
{C_text("f_2141:lolevel_2escm"),(void*)f_2141},
{C_text("f_2145:lolevel_2escm"),(void*)f_2145},
{C_text("f_2150:lolevel_2escm"),(void*)f_2150},
{C_text("f_2166:lolevel_2escm"),(void*)f_2166},
{C_text("f_2176:lolevel_2escm"),(void*)f_2176},
{C_text("f_2193:lolevel_2escm"),(void*)f_2193},
{C_text("f_2210:lolevel_2escm"),(void*)f_2210},
{C_text("f_2212:lolevel_2escm"),(void*)f_2212},
{C_text("f_2226:lolevel_2escm"),(void*)f_2226},
{C_text("f_2243:lolevel_2escm"),(void*)f_2243},
{C_text("f_2251:lolevel_2escm"),(void*)f_2251},
{C_text("f_2265:lolevel_2escm"),(void*)f_2265},
{C_text("f_2267:lolevel_2escm"),(void*)f_2267},
{C_text("f_2288:lolevel_2escm"),(void*)f_2288},
{C_text("f_2290:lolevel_2escm"),(void*)f_2290},
{C_text("f_2294:lolevel_2escm"),(void*)f_2294},
{C_text("f_2299:lolevel_2escm"),(void*)f_2299},
{C_text("f_2322:lolevel_2escm"),(void*)f_2322},
{C_text("f_2331:lolevel_2escm"),(void*)f_2331},
{C_text("f_2367:lolevel_2escm"),(void*)f_2367},
{C_text("f_2371:lolevel_2escm"),(void*)f_2371},
{C_text("f_2376:lolevel_2escm"),(void*)f_2376},
{C_text("f_2380:lolevel_2escm"),(void*)f_2380},
{C_text("f_2389:lolevel_2escm"),(void*)f_2389},
{C_text("f_2393:lolevel_2escm"),(void*)f_2393},
{C_text("f_2396:lolevel_2escm"),(void*)f_2396},
{C_text("f_2415:lolevel_2escm"),(void*)f_2415},
{C_text("f_2417:lolevel_2escm"),(void*)f_2417},
{C_text("f_2421:lolevel_2escm"),(void*)f_2421},
{C_text("f_2427:lolevel_2escm"),(void*)f_2427},
{C_text("f_2432:lolevel_2escm"),(void*)f_2432},
{C_text("f_2455:lolevel_2escm"),(void*)f_2455},
{C_text("f_2459:lolevel_2escm"),(void*)f_2459},
{C_text("f_2464:lolevel_2escm"),(void*)f_2464},
{C_text("f_2468:lolevel_2escm"),(void*)f_2468},
{C_text("f_2471:lolevel_2escm"),(void*)f_2471},
{C_text("f_2478:lolevel_2escm"),(void*)f_2478},
{C_text("f_2481:lolevel_2escm"),(void*)f_2481},
{C_text("f_2493:lolevel_2escm"),(void*)f_2493},
{C_text("f_2495:lolevel_2escm"),(void*)f_2495},
{C_text("f_2511:lolevel_2escm"),(void*)f_2511},
{C_text("f_2527:lolevel_2escm"),(void*)f_2527},
{C_text("f_2532:lolevel_2escm"),(void*)f_2532},
{C_text("f_2534:lolevel_2escm"),(void*)f_2534},
{C_text("f_2537:lolevel_2escm"),(void*)f_2537},
{C_text("f_2540:lolevel_2escm"),(void*)f_2540},
{C_text("f_2546:lolevel_2escm"),(void*)f_2546},
{C_text("f_2549:lolevel_2escm"),(void*)f_2549},
{C_text("f_2553:lolevel_2escm"),(void*)f_2553},
{C_text("f_2556:lolevel_2escm"),(void*)f_2556},
{C_text("f_2573:lolevel_2escm"),(void*)f_2573},
{C_text("f_2580:lolevel_2escm"),(void*)f_2580},
{C_text("f_2593:lolevel_2escm"),(void*)f_2593},
{C_text("f_2596:lolevel_2escm"),(void*)f_2596},
{C_text("f_2599:lolevel_2escm"),(void*)f_2599},
{C_text("f_2602:lolevel_2escm"),(void*)f_2602},
{C_text("f_2605:lolevel_2escm"),(void*)f_2605},
{C_text("f_2608:lolevel_2escm"),(void*)f_2608},
{C_text("f_2611:lolevel_2escm"),(void*)f_2611},
{C_text("f_2614:lolevel_2escm"),(void*)f_2614},
{C_text("f_2617:lolevel_2escm"),(void*)f_2617},
{C_text("f_2620:lolevel_2escm"),(void*)f_2620},
{C_text("f_958:lolevel_2escm"),(void*)f_958},
{C_text("f_960:lolevel_2escm"),(void*)f_960},
{C_text("f_978:lolevel_2escm"),(void*)f_978},
{C_text("f_987:lolevel_2escm"),(void*)f_987},
{C_text("toplevel:lolevel_2escm"),(void*)C_lolevel_toplevel},
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
o|hiding unexported module binding: chicken.memory#pv-buf-ref 
o|hiding unexported module binding: chicken.memory#pv-buf-set! 
o|hiding unexported module binding: chicken.memory.representation#xproc-tag 
o|eliminated procedure checks: 75 
o|specializations:
o|  1 (scheme#length list)
o|  1 (scheme#integer? *)
o|  3 (scheme#cdr pair)
o|  6 (scheme#car pair)
(o e)|safe calls: 209 
o|safe globals: (chicken.memory#pointer-f64-set! chicken.memory#pointer-f32-set! chicken.memory#pointer-s64-set! chicken.memory#pointer-u64-set! chicken.memory#pointer-s32-set! chicken.memory#pointer-u32-set! chicken.memory#pointer-s16-set! chicken.memory#pointer-u16-set! chicken.memory#pointer-s8-set! chicken.memory#pointer-u8-set! chicken.memory#pointer-tag chicken.memory#tagged-pointer? chicken.memory#tag-pointer chicken.memory#align-to-word chicken.memory#pointer+ chicken.memory#pointer=? chicken.memory#pointer->object chicken.memory#object->pointer chicken.memory#pointer->address chicken.memory#address->pointer chicken.memory#pointer-like? chicken.memory#pointer? chicken.memory#free chicken.memory#allocate chicken.memory#move-memory! ##sys#check-pointer ##sys#check-generic-vector ##sys#check-generic-structure ##sys#check-become-alist ##sys#check-block) 
o|inlining procedure: k962 
o|inlining procedure: k962 
o|inlining procedure: k970 
o|inlining procedure: k970 
o|inlining procedure: k992 
o|inlining procedure: k992 
o|inlining procedure: k1026 
o|inlining procedure: k1026 
o|inlining procedure: k1041 
o|inlining procedure: k1041 
o|contracted procedure: "(lolevel.scm:104) g115116" 
o|inlining procedure: k1031 
o|inlining procedure: k1031 
o|inlining procedure: k1051 
o|inlining procedure: k1051 
o|inlining procedure: k1073 
o|inlining procedure: k1073 
o|contracted procedure: "(lolevel.scm:112) g123124" 
o|inlining procedure: k1056 
o|inlining procedure: k1063 
o|inlining procedure: k1063 
o|inlining procedure: k1056 
o|inlining procedure: k1083 
o|inlining procedure: k1083 
o|inlining procedure: k1096 
o|inlining procedure: k1096 
o|contracted procedure: "(lolevel.scm:118) g134135" 
o|merged explicitly consed rest parameter: args235 
o|inlining procedure: k1257 
o|inlining procedure: k1257 
o|consed rest parameter at call site: "(lolevel.scm:151) sizerr232" 1 
o|inlining procedure: k1273 
o|inlining procedure: k1273 
o|consed rest parameter at call site: "(lolevel.scm:156) sizerr232" 1 
o|inlining procedure: k1314 
o|inlining procedure: "(lolevel.scm:168) typerr144" 
o|inlining procedure: k1314 
o|inlining procedure: k1346 
o|inlining procedure: k1346 
o|inlining procedure: "(lolevel.scm:172) typerr144" 
o|inlining procedure: k1366 
o|contracted procedure: "(lolevel.scm:175) memmove1140" 
o|inlining procedure: k1408 
o|contracted procedure: "(lolevel.scm:177) memmove3142" 
o|inlining procedure: k1408 
o|inlining procedure: "(lolevel.scm:179) typerr144" 
o|contracted procedure: "(lolevel.scm:174) g265266" 
o|inlining procedure: k1392 
o|inlining procedure: k1392 
o|contracted procedure: "(lolevel.scm:63) g271272" 
o|inlining procedure: k1366 
o|inlining procedure: k1453 
o|contracted procedure: "(lolevel.scm:183) memmove2141" 
o|inlining procedure: k1477 
o|inlining procedure: k1477 
o|inlining procedure: k1453 
o|contracted procedure: "(lolevel.scm:185) memmove4143" 
o|inlining procedure: "(lolevel.scm:188) typerr144" 
o|contracted procedure: "(lolevel.scm:182) g291292" 
o|inlining procedure: k1463 
o|inlining procedure: k1463 
o|contracted procedure: "(lolevel.scm:63) g297298" 
o|inlining procedure: "(lolevel.scm:190) typerr144" 
o|contracted procedure: "(lolevel.scm:173) g252253" 
o|inlining procedure: k1376 
o|inlining procedure: k1376 
o|contracted procedure: "(lolevel.scm:63) g258259" 
o|inlining procedure: k1575 
o|inlining procedure: k1575 
o|contracted procedure: "(lolevel.scm:198) g333334" 
o|contracted procedure: "(lolevel.scm:200) g338339" 
o|inlining procedure: k1594 
o|inlining procedure: k1594 
o|inlining procedure: k1621 
o|contracted procedure: "(lolevel.scm:211) g351352" 
o|inlining procedure: k1621 
o|inlining procedure: k1669 
o|inlining procedure: k1669 
o|contracted procedure: "(lolevel.scm:232) g390391" 
o|inlining procedure: k1681 
o|inlining procedure: k1681 
o|inlining procedure: k1707 
o|inlining procedure: k1707 
o|contracted procedure: "(lolevel.scm:244) g398399" 
o|inlining procedure: k1712 
o|inlining procedure: k1712 
o|inlining procedure: k1728 
o|inlining procedure: k1737 
o|inlining procedure: k1737 
o|inlining procedure: k1728 
o|inlining procedure: k1756 
o|inlining procedure: k1756 
o|contracted procedure: "(lolevel.scm:255) g423424" 
o|inlining procedure: k1761 
o|inlining procedure: k1761 
o|inlining procedure: k1889 
o|inlining procedure: k1889 
o|contracted procedure: "(lolevel.scm:344) words->bytes492" 
o|inlining procedure: k1936 
o|inlining procedure: k1936 
o|inlining procedure: k1981 
o|inlining procedure: k1981 
o|inlining procedure: k2015 
o|inlining procedure: k2015 
o|inlining procedure: k2069 
o|inlining procedure: k2069 
o|inlining procedure: k2098 
o|inlining procedure: k2098 
o|inlining procedure: k2111 
o|inlining procedure: k2111 
o|inlining procedure: k2152 
o|inlining procedure: k2152 
o|inlining procedure: k2178 
o|inlining procedure: k2184 
o|inlining procedure: k2184 
o|contracted procedure: "(lolevel.scm:452) g658659" 
o|inlining procedure: k2195 
o|inlining procedure: k2195 
o|inlining procedure: k2178 
o|inlining procedure: k2214 
o|inlining procedure: k2244 
o|inlining procedure: k2244 
o|contracted procedure: "(lolevel.scm:457) g668669" 
o|inlining procedure: k2228 
o|inlining procedure: k2228 
o|inlining procedure: k2214 
o|inlining procedure: k2253 
o|inlining procedure: k2253 
o|contracted procedure: "(lolevel.scm:467) g679680" 
o|inlining procedure: k2271 
o|inlining procedure: k2278 
o|inlining procedure: k2278 
o|inlining procedure: k2271 
o|inlining procedure: k2301 
o|inlining procedure: k2301 
o|inlining procedure: k2336 
o|inlining procedure: k2336 
o|contracted procedure: "(lolevel.scm:502) g714715" 
o|inlining procedure: k2341 
o|inlining procedure: k2341 
o|inlining procedure: k2434 
o|inlining procedure: k2434 
o|inlining procedure: k2501 
o|inlining procedure: k2501 
o|inlining procedure: k2517 
o|inlining procedure: k2517 
o|inlining procedure: k2542 
o|inlining procedure: k2542 
o|contracted procedure: "(lolevel.scm:396) chicken.memory#pv-buf-ref" 
o|replaced variables: 404 
o|removed binding forms: 171 
o|substituted constant variable: r9712626 
o|substituted constant variable: r9712626 
o|substituted constant variable: r10422634 
o|substituted constant variable: r10422634 
o|substituted constant variable: r10322637 
o|substituted constant variable: r10742642 
o|substituted constant variable: r10742642 
o|substituted constant variable: r10572649 
o|substituted constant variable: r10972654 
o|substituted constant variable: r10972654 
o|substituted constant variable: r15762712 
o|substituted constant variable: r15762712 
o|substituted constant variable: r15952715 
o|substituted constant variable: r16222717 
o|substituted constant variable: r16822721 
o|substituted constant variable: r17132727 
o|substituted constant variable: r17292731 
o|substituted constant variable: r17622735 
o|inlining procedure: k1871 
o|substituted constant variable: r20162744 
o|substituted constant variable: r20162744 
o|substituted constant variable: r21532755 
o|substituted constant variable: r21852757 
o|substituted constant variable: r21852758 
o|substituted constant variable: r21962760 
o|substituted constant variable: r21792761 
o|substituted constant variable: r22452764 
o|substituted constant variable: r22292766 
o|substituted constant variable: r22152767 
o|substituted constant variable: r22722775 
o|substituted constant variable: r23372779 
o|substituted constant variable: r23422781 
o|substituted constant variable: r25022784 
o|substituted constant variable: r25022784 
o|substituted constant variable: r25182788 
o|substituted constant variable: r25182788 
o|substituted constant variable: r25432793 
o|replaced variables: 140 
o|removed binding forms: 325 
o|inlining procedure: k1389 
o|inlining procedure: k1460 
o|inlining procedure: k1373 
o|removed binding forms: 145 
o|contracted procedure: k1088 
o|contracted procedure: k1865 
o|simplifications: ((let . 1)) 
o|removed binding forms: 8 
o|simplifications: ((if . 39) (##core#call . 165) (let . 21)) 
o|  call simplifications:
o|    scheme#vector
o|    scheme#list	2
o|    ##sys#check-symbol
o|    scheme#cons	2
o|    scheme#symbol?
o|    ##sys#setslot	4
o|    ##sys#intern-symbol
o|    ##sys#check-structure	4
o|    ##sys#structure?
o|    scheme#eq?	6
o|    chicken.fixnum#fx>=	4
o|    chicken.fixnum#fx+	7
o|    ##sys#make-structure	2
o|    scheme#equal?
o|    ##sys#foreign-ranged-integer-argument	2
o|    scheme#car	9
o|    scheme#cdr	3
o|    chicken.fixnum#fx<	2
o|    ##sys#generic-structure?	2
o|    scheme#string?	3
o|    ##sys#size	12
o|    ##sys#foreign-block-argument	4
o|    ##sys#foreign-pointer-argument	7
o|    ##sys#foreign-fixnum-argument	16
o|    scheme#memq	2
o|    ##sys#slot	24
o|    chicken.fixnum#fx-	6
o|    chicken.fixnum#fx<=	3
o|    scheme#apply	2
o|    scheme#not	8
o|    ##sys#check-list
o|    scheme#null?	13
o|    ##sys#check-pair
o|    scheme#pair?	8
o|contracted procedure: k973 
o|contracted procedure: k980 
o|contracted procedure: k989 
o|contracted procedure: k998 
o|contracted procedure: k1002 
o|contracted procedure: k1034 
o|contracted procedure: k1044 
o|contracted procedure: k1076 
o|contracted procedure: k1099 
o|contracted procedure: k1558 
o|contracted procedure: k1224 
o|contracted procedure: k1552 
o|contracted procedure: k1227 
o|contracted procedure: k1546 
o|contracted procedure: k1230 
o|contracted procedure: k1540 
o|contracted procedure: k1233 
o|contracted procedure: k1534 
o|contracted procedure: k1236 
o|contracted procedure: k1528 
o|contracted procedure: k1239 
o|contracted procedure: k1267 
o|contracted procedure: k1260 
o|contracted procedure: k1293 
o|contracted procedure: k1282 
o|contracted procedure: k1289 
o|contracted procedure: k1317 
o|contracted procedure: k1337 
o|contracted procedure: k1323 
o|contracted procedure: k1330 
o|contracted procedure: k1343 
o|contracted procedure: k1363 
o|contracted procedure: k1349 
o|contracted procedure: k1356 
o|contracted procedure: k1379 
o|contracted procedure: k1395 
o|contracted procedure: k1107 
o|contracted procedure: k1111 
o|contracted procedure: k1115 
o|contracted procedure: k1119 
o|contracted procedure: k1123 
o|contracted procedure: k1414 
o|contracted procedure: k1163 
o|contracted procedure: k1167 
o|contracted procedure: k1171 
o|contracted procedure: k1175 
o|contracted procedure: k1179 
o|contracted procedure: k1429 
o|contracted procedure: k1447 
o|contracted procedure: k1450 
o|contracted procedure: k1466 
o|contracted procedure: k1135 
o|contracted procedure: k1139 
o|contracted procedure: k1143 
o|contracted procedure: k1147 
o|contracted procedure: k1151 
o|contracted procedure: k1486 
o|contracted procedure: k1191 
o|contracted procedure: k1195 
o|contracted procedure: k1199 
o|contracted procedure: k1203 
o|contracted procedure: k1207 
o|contracted procedure: k1497 
o|contracted procedure: k1501 
o|contracted procedure: k1516 
o|contracted procedure: k1522 
o|contracted procedure: k1568 
o|contracted procedure: k1575 
o|contracted procedure: k1648 
o|contracted procedure: k1652 
o|contracted procedure: k1663 
o|contracted procedure: k1684 
o|contracted procedure: k1715 
o|contracted procedure: k1747 
o|contracted procedure: k1725 
o|contracted procedure: k1734 
o|contracted procedure: k1744 
o|contracted procedure: k1764 
o|contracted procedure: k1848 
o|contracted procedure: k1908 
o|contracted procedure: k1853 
o|contracted procedure: k1862 
o|contracted procedure: k1877 
o|contracted procedure: k1892 
o|contracted procedure: k1902 
o|contracted procedure: k1927 
o|contracted procedure: k1939 
o|contracted procedure: k1942 
o|contracted procedure: k1957 
o|contracted procedure: k1963 
o|contracted procedure: k1969 
o|contracted procedure: k1972 
o|contracted procedure: k1984 
o|contracted procedure: k1994 
o|contracted procedure: k2011 
o|contracted procedure: k2015 
o|contracted procedure: k2024 
o|contracted procedure: k2037 
o|contracted procedure: k2044 
o|contracted procedure: k2054 
o|contracted procedure: k2072 
o|contracted procedure: k2078 
o|contracted procedure: k2085 
o|contracted procedure: k2088 
o|contracted procedure: k2091 
o|contracted procedure: k2105 
o|contracted procedure: k2114 
o|contracted procedure: k2117 
o|contracted procedure: k2124 
o|contracted procedure: k2132 
o|contracted procedure: k2137 
o|contracted procedure: k2155 
o|contracted procedure: k2162 
o|contracted procedure: k2172 
o|contracted procedure: k2168 
o|contracted procedure: k2198 
o|contracted procedure: k2205 
o|contracted procedure: k2231 
o|contracted procedure: k2238 
o|contracted procedure: k2256 
o|contracted procedure: k2304 
o|contracted procedure: k2317 
o|contracted procedure: k2324 
o|contracted procedure: k2360 
o|contracted procedure: k2333 
o|contracted procedure: k2344 
o|contracted procedure: k2347 
o|contracted procedure: k2357 
o|contracted procedure: k2385 
o|contracted procedure: k2401 
o|contracted procedure: k2409 
o|contracted procedure: k2405 
o|contracted procedure: k2422 
o|contracted procedure: k2437 
o|contracted procedure: k2451 
o|contracted procedure: k2440 
o|contracted procedure: k2447 
o|contracted procedure: k2472 
o|contracted procedure: k2487 
o|contracted procedure: k2483 
o|contracted procedure: k2504 
o|contracted procedure: k2501 
o|contracted procedure: k2520 
o|contracted procedure: k2517 
o|contracted procedure: k2561 
o|contracted procedure: k2569 
o|contracted procedure: k2565 
o|contracted procedure: k2575 
o|contracted procedure: k2585 
o|contracted procedure: k2004 
o|contracted procedure: k2589 
o|simplifications: ((if . 9) (let . 69)) 
o|removed binding forms: 151 
(o x)|known list op on rest arg sublist: ##core#rest-car loc91 0 
(o x)|known list op on rest arg sublist: ##core#rest-car loc114 0 
(o x)|known list op on rest arg sublist: ##core#rest-car loc133 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest215218 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest215218 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest215218 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest215218 0 
o|contracted procedure: k1276 
o|inlining procedure: k1425 
o|inlining procedure: "(lolevel.scm:231) align378" 
o|inlining procedure: "(lolevel.scm:233) align378" 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest408410 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest408410 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest484486 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest484486 0 
o|inlining procedure: "(lolevel.scm:351) chicken.memory#pv-buf-set!" 
o|inlining procedure: "(lolevel.scm:366) chicken.memory#pv-buf-set!" 
o|inlining procedure: "(lolevel.scm:375) chicken.memory#pv-buf-set!" 
o|inlining procedure: "(lolevel.scm:389) chicken.memory#pv-buf-set!" 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest705707 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest705707 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? index788 0 
(o x)|known list op on rest arg sublist: ##core#rest-car index788 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? index795 0 
(o x)|known list op on rest arg sublist: ##core#rest-car index795 0 
o|removed binding forms: 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1228 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1228 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1228 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1228 1 
o|removed side-effect free assignment to unused variable: chicken.memory#pv-buf-set! 
o|replaced variables: 27 
o|removed binding forms: 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1234 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r1234 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1234 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1234 2 
o|inlining procedure: k1691 
o|inlining procedure: k1895 
o|inlining procedure: k1948 
o|inlining procedure: k1987 
o|removed binding forms: 22 
o|simplifications: ((let . 1)) 
o|removed binding forms: 6 
o|direct leaf routine/allocation: doloop499500 0 
o|direct leaf routine/allocation: doloop527528 0 
o|direct leaf routine/allocation: doloop742743 0 
o|contracted procedure: k1871 
o|converted assignments to bindings: (doloop499500) 
o|converted assignments to bindings: (doloop527528) 
o|converted assignments to bindings: (doloop742743) 
o|simplifications: ((let . 3)) 
o|removed binding forms: 1 
o|customizable procedures: (copy627 doloop636637 doloop514515 checkn2234 checkn1233 nosizerr231 move245 sizerr232 k1066 loop97) 
o|calls to known targets: 28 
o|identified direct recursive calls: f_1312 2 
o|unused rest argument: rest215218 f_1222 
o|unused rest argument: rest408410 f_1723 
o|identified direct recursive calls: f_1887 1 
o|unused rest argument: rest484486 f_1851 
o|identified direct recursive calls: f_1979 1 
o|unused rest argument: rest705707 f_2331 
o|identified direct recursive calls: f_2432 1 
o|unused rest argument: index788 f_2495 
o|unused rest argument: index795 f_2511 
o|fast box initializations: 9 
o|fast global references: 4 
o|fast global assignments: 1 
*/
/* end of file */
