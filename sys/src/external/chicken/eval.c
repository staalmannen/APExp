/* Generated from eval.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: eval.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file eval.c -emit-import-library chicken.eval -emit-import-library chicken.load
   unit: eval
   uses: modules eval expand internal library
*/
#include "chicken.h"


#ifndef C_INSTALL_EGG_HOME
# define C_INSTALL_EGG_HOME    "."
#endif

#ifndef C_INSTALL_SHARE_HOME
# define C_INSTALL_SHARE_HOME NULL
#endif

#ifndef C_BINARY_VERSION
# define C_BINARY_VERSION      0
#endif


#define C_store_result(x, ptr)   (*((C_word *)C_block_item(ptr, 0)) = (x), C_SCHEME_TRUE)


#define C_copy_result_string(str, buf, n)  (C_memcpy((char *)C_block_item(buf, 0), C_c_string(str), C_unfix(n)), ((char *)C_block_item(buf, 0))[ C_unfix(n) ] = '\0', C_SCHEME_TRUE)


C_externexport  void  CHICKEN_get_error_message(char *t0,int t1);

C_externexport  int  CHICKEN_load(char * t0);

C_externexport  int  CHICKEN_read(char * t0,C_word *t1);

C_externexport  int  CHICKEN_apply_to_string(C_word t0,C_word t1,char *t2,int t3);

C_externexport  int  CHICKEN_apply(C_word t0,C_word t1,C_word *t2);

C_externexport  int  CHICKEN_eval_string_to_string(char * t0,char *t1,int t2);

C_externexport  int  CHICKEN_eval_to_string(C_word t0,char *t1,int t2);

C_externexport  int  CHICKEN_eval_string(char * t0,C_word *t1);

C_externexport  int  CHICKEN_eval(C_word t0,C_word *t1);

C_externexport  int  CHICKEN_yield();

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_modules_toplevel)
C_externimport void C_ccall C_modules_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_expand_toplevel)
C_externimport void C_ccall C_expand_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_internal_toplevel)
C_externimport void C_ccall C_internal_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[357];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,15),40,102,105,110,100,45,105,100,32,105,100,32,115,101,41,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,7),40,97,51,54,52,57,41,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,13),40,97,51,54,53,53,32,46,32,116,109,112,41,0,0,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,12),40,114,101,110,97,109,101,32,118,97,114,41,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,8),40,103,50,52,53,32,112,41};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,14),40,108,111,111,112,32,101,110,118,115,32,101,105,41,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,15),40,108,111,111,107,117,112,32,118,97,114,48,32,101,41,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,34),40,101,109,105,116,45,116,114,97,99,101,45,105,110,102,111,32,108,110,32,105,110,102,111,32,99,110,116,114,32,101,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,37),40,101,109,105,116,45,115,121,110,116,97,120,45,116,114,97,99,101,45,105,110,102,111,32,116,102,32,105,110,102,111,32,99,110,116,114,41,0,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,9),40,97,51,53,51,55,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,11),40,97,51,53,53,48,32,112,32,105,41,0,0,0,0,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,15),40,100,101,99,111,114,97,116,101,32,112,32,108,108,41,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,12),40,102,95,51,56,51,51,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,7),40,97,51,56,52,52,41,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,10),40,102,95,51,56,55,49,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,12),40,102,95,51,56,56,50,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,12),40,102,95,51,56,56,55,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,10),40,102,95,51,57,53,53,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,10),40,102,95,51,57,55,48,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,10),40,102,95,51,57,56,57,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,10),40,102,95,52,48,49,50,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,10),40,102,95,52,48,51,51,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,11),40,97,51,56,53,48,32,105,32,106,41,0,0,0,0,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,12),40,102,95,52,48,53,57,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,12),40,102,95,52,48,54,55,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,12),40,102,95,52,48,55,53,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,12),40,102,95,52,48,56,51,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,12),40,102,95,52,48,56,53,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,12),40,102,95,52,49,48,52,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,12),40,102,95,52,49,48,54,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,12),40,102,95,52,49,49,55,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,21),40,102,95,51,56,48,48,32,105,110,112,117,116,32,111,117,116,112,117,116,41,0,0,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,12),40,102,95,52,49,55,54,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,12),40,102,95,52,49,56,52,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,12),40,102,95,52,49,57,50,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,12),40,102,95,52,50,48,48,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,12),40,102,95,52,50,48,56,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,12),40,102,95,52,50,49,54,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,12),40,102,95,52,50,50,52,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,12),40,102,95,52,50,50,54,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,12),40,102,95,52,50,53,53,32,46,32,118,41,0,0,0,0};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,10),40,102,95,52,50,56,57,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,10),40,102,95,52,51,48,54,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,10),40,102,95,52,51,57,49,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,10),40,102,95,52,52,49,54,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,7),40,97,52,52,57,49,41,0};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,10),40,102,95,52,53,49,53,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,10),40,102,95,52,53,50,51,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,10),40,102,95,52,53,53,56,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,10),40,102,95,52,53,55,49,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,11),40,97,52,52,57,55,32,105,32,106,41,0,0,0,0,0};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,10),40,102,95,52,54,51,53,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,10),40,102,95,52,54,55,50,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,10),40,102,95,52,55,50,55,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,10),40,102,95,52,55,57,55,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,8),40,103,53,53,55,32,120,41};
static C_char C_TLS li57[] C_aligned={C_lihdr(0,0,19),40,100,111,108,111,111,112,53,55,56,32,105,32,118,108,105,115,116,41,0,0,0,0,0};
static C_char C_TLS li58[] C_aligned={C_lihdr(0,0,10),40,102,95,52,56,55,53,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li59[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,53,53,49,32,103,53,54,51,41,0,0,0,0,0,0};
static C_char C_TLS li60[] C_aligned={C_lihdr(0,0,7),40,97,52,57,54,50,41,0};
static C_char C_TLS li61[] C_aligned={C_lihdr(0,0,7),40,97,52,57,55,57,41,0};
static C_char C_TLS li62[] C_aligned={C_lihdr(0,0,7),40,97,52,57,57,55,41,0};
static C_char C_TLS li63[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,52,56,52,32,103,52,57,54,41,0,0,0,0,0,0};
static C_char C_TLS li64[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,52,53,54,32,103,52,54,56,41,0,0,0,0,0,0};
static C_char C_TLS li65[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,54,49,57,32,103,54,51,49,41,0,0,0,0,0,0};
static C_char C_TLS li66[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,53,57,50,32,103,54,48,52,41,0,0,0,0,0,0};
static C_char C_TLS li67[] C_aligned={C_lihdr(0,0,23),40,109,97,112,45,108,111,111,112,55,54,56,32,103,55,56,48,32,103,55,56,49,41,0};
static C_char C_TLS li68[] C_aligned={C_lihdr(0,0,23),40,109,97,112,45,108,111,111,112,55,51,53,32,103,55,52,55,32,103,55,52,56,41,0};
static C_char C_TLS li69[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,55,48,56,32,103,55,50,48,41,0,0,0,0,0,0};
static C_char C_TLS li70[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,54,55,56,32,103,54,57,48,41,0,0,0,0,0,0};
static C_char C_TLS li71[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,54,53,49,32,103,54,54,51,41,0,0,0,0,0,0};
static C_char C_TLS li72[] C_aligned={C_lihdr(0,0,11),40,97,53,53,56,56,32,46,32,114,41,0,0,0,0,0};
static C_char C_TLS li73[] C_aligned={C_lihdr(0,0,10),40,102,95,53,53,56,51,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li74[] C_aligned={C_lihdr(0,0,7),40,97,53,54,48,55,41,0};
static C_char C_TLS li75[] C_aligned={C_lihdr(0,0,10),40,102,95,53,54,48,50,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li76[] C_aligned={C_lihdr(0,0,14),40,97,53,54,51,49,32,97,49,32,46,32,114,41,0,0};
static C_char C_TLS li77[] C_aligned={C_lihdr(0,0,10),40,102,95,53,54,50,54,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li78[] C_aligned={C_lihdr(0,0,10),40,97,53,54,53,48,32,97,49,41,0,0,0,0,0,0};
static C_char C_TLS li79[] C_aligned={C_lihdr(0,0,10),40,102,95,53,54,52,53,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li80[] C_aligned={C_lihdr(0,0,17),40,97,53,54,55,56,32,97,49,32,97,50,32,46,32,114,41,0,0,0,0,0,0,0};
static C_char C_TLS li81[] C_aligned={C_lihdr(0,0,10),40,102,95,53,54,55,51,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li82[] C_aligned={C_lihdr(0,0,13),40,97,53,54,57,55,32,97,49,32,97,50,41,0,0,0};
static C_char C_TLS li83[] C_aligned={C_lihdr(0,0,10),40,102,95,53,54,57,50,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li84[] C_aligned={C_lihdr(0,0,20),40,97,53,55,50,53,32,97,49,32,97,50,32,97,51,32,46,32,114,41,0,0,0,0};
static C_char C_TLS li85[] C_aligned={C_lihdr(0,0,10),40,102,95,53,55,50,48,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li86[] C_aligned={C_lihdr(0,0,16),40,97,53,55,52,52,32,97,49,32,97,50,32,97,51,41};
static C_char C_TLS li87[] C_aligned={C_lihdr(0,0,10),40,102,95,53,55,51,57,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li88[] C_aligned={C_lihdr(0,0,23),40,97,53,55,55,50,32,97,49,32,97,50,32,97,51,32,97,52,32,46,32,114,41,0};
static C_char C_TLS li89[] C_aligned={C_lihdr(0,0,10),40,102,95,53,55,54,55,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li90[] C_aligned={C_lihdr(0,0,19),40,97,53,55,57,49,32,97,49,32,97,50,32,97,51,32,97,52,41,0,0,0,0,0};
static C_char C_TLS li91[] C_aligned={C_lihdr(0,0,10),40,102,95,53,55,56,54,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li92[] C_aligned={C_lihdr(0,0,26),40,100,111,108,111,111,112,49,50,55,55,32,110,32,99,32,97,114,103,115,32,108,97,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li93[] C_aligned={C_lihdr(0,0,12),40,97,53,56,49,51,32,46,32,97,115,41,0,0,0,0};
static C_char C_TLS li94[] C_aligned={C_lihdr(0,0,10),40,102,95,53,56,48,56,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li95[] C_aligned={C_lihdr(0,0,12),40,97,53,56,51,54,32,46,32,97,115,41,0,0,0,0};
static C_char C_TLS li96[] C_aligned={C_lihdr(0,0,10),40,102,95,53,56,51,49,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li97[] C_aligned={C_lihdr(0,0,7),40,97,53,56,55,52,41,0};
static C_char C_TLS li98[] C_aligned={C_lihdr(0,0,7),40,97,53,56,57,49,41,0};
static C_char C_TLS li99[] C_aligned={C_lihdr(0,0,7),40,97,53,57,48,53,41,0};
static C_char C_TLS li100[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,56,49,57,32,103,56,51,49,41,0,0,0,0,0,0};
static C_char C_TLS li101[] C_aligned={C_lihdr(0,0,22),40,97,53,53,53,51,32,118,97,114,115,32,97,114,103,99,32,114,101,115,116,41,0,0};
static C_char C_TLS li102[] C_aligned={C_lihdr(0,0,7),40,97,53,57,53,57,41,0};
static C_char C_TLS li103[] C_aligned={C_lihdr(0,0,24),40,97,53,57,54,57,32,108,108,105,115,116,56,48,56,32,98,111,100,121,56,48,57,41};
static C_char C_TLS li104[] C_aligned={C_lihdr(0,0,7),40,97,53,57,57,52,41,0};
static C_char C_TLS li105[] C_aligned={C_lihdr(0,0,7),40,97,54,48,49,49,41,0};
static C_char C_TLS li106[] C_aligned={C_lihdr(0,0,7),40,97,54,48,50,57,41,0};
static C_char C_TLS li107[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,57,50,50,32,103,57,51,52,41,0,0,0,0,0,0};
static C_char C_TLS li108[] C_aligned={C_lihdr(0,0,6),40,103,57,56,54,41,0,0};
static C_char C_TLS li109[] C_aligned={C_lihdr(0,0,18),40,102,111,114,45,101,97,99,104,45,108,111,111,112,57,56,53,41,0,0,0,0,0,0};
static C_char C_TLS li110[] C_aligned={C_lihdr(0,0,7),40,97,54,49,56,55,41,0};
static C_char C_TLS li111[] C_aligned={C_lihdr(0,0,7),40,97,54,50,48,52,41,0};
static C_char C_TLS li112[] C_aligned={C_lihdr(0,0,7),40,97,54,50,50,50,41,0};
static C_char C_TLS li113[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,57,53,55,32,103,57,54,57,41,0,0,0,0,0,0};
static C_char C_TLS li114[] C_aligned={C_lihdr(0,0,7),40,97,54,52,48,56,41,0};
static C_char C_TLS li115[] C_aligned={C_lihdr(0,0,7),40,97,54,52,49,51,41,0};
static C_char C_TLS li116[] C_aligned={C_lihdr(0,0,7),40,97,54,52,49,57,41,0};
static C_char C_TLS li117[] C_aligned={C_lihdr(0,0,18),40,97,54,51,57,57,32,102,111,114,109,115,32,112,97,116,104,41,0,0,0,0,0,0};
static C_char C_TLS li118[] C_aligned={C_lihdr(0,0,7),40,97,54,52,55,57,41,0};
static C_char C_TLS li119[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,48,52,51,32,103,49,48,53,53,41,0,0,0,0};
static C_char C_TLS li120[] C_aligned={C_lihdr(0,0,7),40,97,54,53,53,55,41,0};
static C_char C_TLS li121[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,50,32,120,115,41,0,0,0,0,0,0};
static C_char C_TLS li122[] C_aligned={C_lihdr(0,0,10),40,102,95,54,54,52,55,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li123[] C_aligned={C_lihdr(0,0,14),40,108,111,111,112,32,98,111,100,121,32,120,115,41,0,0};
static C_char C_TLS li124[] C_aligned={C_lihdr(0,0,7),40,97,54,54,49,57,41,0};
static C_char C_TLS li125[] C_aligned={C_lihdr(0,0,7),40,97,54,54,49,51,41,0};
static C_char C_TLS li126[] C_aligned={C_lihdr(0,0,7),40,97,54,55,48,57,41,0};
static C_char C_TLS li127[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li128[] C_aligned={C_lihdr(0,0,11),40,103,49,48,56,54,32,101,120,112,41,0,0,0,0,0};
static C_char C_TLS li129[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,48,56,48,32,103,49,48,57,50,41,0,0,0,0};
static C_char C_TLS li130[] C_aligned={C_lihdr(0,0,10),40,103,49,50,53,57,32,99,108,41,0,0,0,0,0,0};
static C_char C_TLS li131[] C_aligned={C_lihdr(0,0,7),40,97,55,48,57,50,41,0};
static C_char C_TLS li132[] C_aligned={C_lihdr(0,0,7),40,97,55,48,57,55,41,0};
static C_char C_TLS li133[] C_aligned={C_lihdr(0,0,7),40,97,55,49,48,55,41,0};
static C_char C_TLS li134[] C_aligned={C_lihdr(0,0,7),40,97,55,50,56,56,41,0};
static C_char C_TLS li135[] C_aligned={C_lihdr(0,0,7),40,97,55,50,57,51,41,0};
static C_char C_TLS li136[] C_aligned={C_lihdr(0,0,7),40,97,55,51,48,51,41,0};
static C_char C_TLS li137[] C_aligned={C_lihdr(0,0,27),40,99,111,109,112,105,108,101,32,120,32,101,32,104,32,116,102,32,99,110,116,114,32,116,108,63,41,0,0,0,0,0};
static C_char C_TLS li138[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,110,41};
static C_char C_TLS li139[] C_aligned={C_lihdr(0,0,10),40,102,95,55,52,55,57,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li140[] C_aligned={C_lihdr(0,0,10),40,102,95,55,52,57,57,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li141[] C_aligned={C_lihdr(0,0,10),40,102,95,55,53,51,48,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li142[] C_aligned={C_lihdr(0,0,10),40,102,95,55,53,54,57,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li143[] C_aligned={C_lihdr(0,0,10),40,102,95,55,54,49,54,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li144[] C_aligned={C_lihdr(0,0,9),40,103,49,51,53,52,32,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li145[] C_aligned={C_lihdr(0,0,9),40,103,49,51,56,50,32,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li146[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,51,55,54,32,103,49,51,56,56,41,0,0,0,0};
static C_char C_TLS li147[] C_aligned={C_lihdr(0,0,10),40,102,95,55,54,54,52,32,118,41,0,0,0,0,0,0};
static C_char C_TLS li148[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,51,52,56,32,103,49,51,54,48,41,0,0,0,0};
static C_char C_TLS li149[] C_aligned={C_lihdr(0,0,12),40,102,95,55,55,55,52,32,46,32,95,41,0,0,0,0};
static C_char C_TLS li150[] C_aligned={C_lihdr(0,0,26),40,99,111,109,112,105,108,101,45,99,97,108,108,32,120,32,101,32,116,102,32,99,110,116,114,41,0,0,0,0,0,0};
static C_char C_TLS li151[] C_aligned={C_lihdr(0,0,46),40,99,104,105,99,107,101,110,46,101,118,97,108,35,99,111,109,112,105,108,101,45,116,111,45,99,108,111,115,117,114,101,32,101,120,112,32,101,110,118,32,114,101,115,116,41,0,0};
static C_char C_TLS li152[] C_aligned={C_lihdr(0,0,7),40,97,55,56,53,52,41,0};
static C_char C_TLS li153[] C_aligned={C_lihdr(0,0,7),40,97,55,57,48,51,41,0};
static C_char C_TLS li154[] C_aligned={C_lihdr(0,0,7),40,97,55,57,49,50,41,0};
static C_char C_TLS li155[] C_aligned={C_lihdr(0,0,7),40,97,55,56,57,55,41,0};
static C_char C_TLS li156[] C_aligned={C_lihdr(0,0,7),40,97,55,57,50,57,41,0};
static C_char C_TLS li157[] C_aligned={C_lihdr(0,0,22),40,35,35,115,121,115,35,101,118,97,108,47,109,101,116,97,32,102,111,114,109,41,0,0};
static C_char C_TLS li158[] C_aligned={C_lihdr(0,0,21),40,115,99,104,101,109,101,35,101,118,97,108,32,120,32,46,32,101,110,118,41,0,0,0};
static C_char C_TLS li159[] C_aligned={C_lihdr(0,0,38),40,99,104,105,99,107,101,110,46,101,118,97,108,35,109,111,100,117,108,101,45,101,110,118,105,114,111,110,109,101,110,116,32,110,97,109,101,41,0,0};
static C_char C_TLS li160[] C_aligned={C_lihdr(0,0,5),40,101,114,114,41,0,0,0};
static C_char C_TLS li161[] C_aligned={C_lihdr(0,0,22),40,108,111,111,112,32,108,108,105,115,116,32,118,97,114,115,32,97,114,103,99,41,0,0};
static C_char C_TLS li162[] C_aligned={C_lihdr(0,0,38),40,35,35,115,121,115,35,100,101,99,111,109,112,111,115,101,45,108,97,109,98,100,97,45,108,105,115,116,32,108,108,105,115,116,48,32,107,41,0,0};
static C_char C_TLS li163[] C_aligned={C_lihdr(0,0,32),40,115,99,104,101,109,101,35,105,110,116,101,114,97,99,116,105,111,110,45,101,110,118,105,114,111,110,109,101,110,116,41};
static C_char C_TLS li164[] C_aligned={C_lihdr(0,0,17),40,102,111,108,100,114,49,53,55,54,32,103,49,53,55,55,41,0,0,0,0,0,0,0};
static C_char C_TLS li165[] C_aligned={C_lihdr(0,0,10),40,115,116,114,105,112,32,115,101,41,0,0,0,0,0,0};
static C_char C_TLS li166[] C_aligned={C_lihdr(0,0,36),40,115,99,104,101,109,101,35,115,99,104,101,109,101,45,114,101,112,111,114,116,45,101,110,118,105,114,111,110,109,101,110,116,32,110,41,0,0,0,0};
static C_char C_TLS li167[] C_aligned={C_lihdr(0,0,27),40,115,99,104,101,109,101,35,110,117,108,108,45,101,110,118,105,114,111,110,109,101,110,116,32,110,41,0,0,0,0,0};
static C_char C_TLS li168[] C_aligned={C_lihdr(0,0,31),40,99,104,105,99,107,101,110,46,108,111,97,100,35,99,111,114,101,45,108,105,98,114,97,114,121,63,32,105,100,41,0};
static C_char C_TLS li169[] C_aligned={C_lihdr(0,0,18),40,35,35,115,121,115,35,112,114,111,118,105,100,101,32,105,100,41,0,0,0,0,0,0};
static C_char C_TLS li170[] C_aligned={C_lihdr(0,0,20),40,35,35,115,121,115,35,112,114,111,118,105,100,101,100,63,32,105,100,41,0,0,0,0};
static C_char C_TLS li171[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li172[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,108,111,97,100,35,112,97,116,104,45,115,101,112,97,114,97,116,111,114,45,105,110,100,101,120,47,114,105,103,104,116,32,115,41,0,0,0,0,0};
static C_char C_TLS li173[] C_aligned={C_lihdr(0,0,47),40,99,104,105,99,107,101,110,46,108,111,97,100,35,109,97,107,101,45,114,101,108,97,116,105,118,101,45,112,97,116,104,110,97,109,101,32,102,114,111,109,32,102,105,108,101,41,0};
static C_char C_TLS li174[] C_aligned={C_lihdr(0,0,11),40,108,111,111,112,32,109,111,100,101,41,0,0,0,0,0};
static C_char C_TLS li175[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,108,111,97,100,35,115,101,116,45,100,121,110,97,109,105,99,45,108,111,97,100,45,109,111,100,101,33,32,109,111,100,101,41,0,0,0,0,0,0};
static C_char C_TLS li176[] C_aligned={C_lihdr(0,0,34),40,99,104,105,99,107,101,110,46,108,111,97,100,35,99,45,116,111,112,108,101,118,101,108,32,110,97,109,101,32,108,111,99,41,0,0,0,0,0,0};
static C_char C_TLS li177[] C_aligned={C_lihdr(0,0,13),40,102,95,57,55,53,48,32,112,97,116,104,41,0,0,0};
static C_char C_TLS li178[] C_aligned={C_lihdr(0,0,7),40,97,57,56,48,56,41,0};
static C_char C_TLS li179[] C_aligned={C_lihdr(0,0,7),40,97,57,56,50,54,41,0};
static C_char C_TLS li180[] C_aligned={C_lihdr(0,0,7),40,97,57,56,55,56,41,0};
static C_char C_TLS li181[] C_aligned={C_lihdr(0,0,11),40,97,57,56,56,52,32,46,32,116,41,0,0,0,0,0};
static C_char C_TLS li182[] C_aligned={C_lihdr(0,0,7),40,97,57,56,54,54,41,0};
static C_char C_TLS li183[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,51,54,51,32,103,50,51,55,48,41,0,0,0,0,0,0,0};
static C_char C_TLS li184[] C_aligned={C_lihdr(0,0,17),40,97,57,57,48,48,32,46,32,114,101,115,117,108,116,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li185[] C_aligned={C_lihdr(0,0,14),40,100,111,108,111,111,112,50,51,53,51,32,120,41,0,0};
static C_char C_TLS li186[] C_aligned={C_lihdr(0,0,7),40,97,57,56,50,57,41,0};
static C_char C_TLS li187[] C_aligned={C_lihdr(0,0,7),40,97,57,57,54,48,41,0};
static C_char C_TLS li188[] C_aligned={C_lihdr(0,0,7),40,97,57,56,49,55,41,0};
static C_char C_TLS li189[] C_aligned={C_lihdr(0,0,7),40,97,57,57,54,57,41,0};
static C_char C_TLS li190[] C_aligned={C_lihdr(0,0,7),40,97,57,56,48,50,41,0};
static C_char C_TLS li191[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,108,111,97,100,35,108,111,97,100,47,105,110,116,101,114,110,97,108,32,105,110,112,117,116,32,101,118,97,108,117,97,116,111,114,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li192[] C_aligned={C_lihdr(0,0,29),40,115,99,104,101,109,101,35,108,111,97,100,32,102,105,108,101,110,97,109,101,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li193[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,108,111,97,100,35,108,111,97,100,45,114,101,108,97,116,105,118,101,32,102,105,108,101,110,97,109,101,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li194[] C_aligned={C_lihdr(0,0,8),40,97,49,48,49,53,54,41};
static C_char C_TLS li195[] C_aligned={C_lihdr(0,0,8),40,97,49,48,49,53,57,41};
static C_char C_TLS li196[] C_aligned={C_lihdr(0,0,8),40,97,49,48,49,54,50,41};
static C_char C_TLS li197[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,108,111,97,100,35,108,111,97,100,45,110,111,105,115,105,108,121,32,102,105,108,101,110,97,109,101,32,46,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li198[] C_aligned={C_lihdr(0,0,16),40,99,111,109,112,108,101,116,101,32,103,50,52,51,55,41};
static C_char C_TLS li199[] C_aligned={C_lihdr(0,0,11),40,108,111,111,112,32,108,105,98,115,41,0,0,0,0,0};
static C_char C_TLS li200[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,108,111,97,100,35,108,111,97,100,45,117,110,105,116,32,117,110,105,116,45,110,97,109,101,32,108,105,98,32,108,111,99,41,0,0,0,0,0,0};
static C_char C_TLS li201[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,108,111,97,100,35,108,111,97,100,45,108,105,98,114,97,114,121,32,117,110,105,116,45,110,97,109,101,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li202[] C_aligned={C_lihdr(0,0,8),40,97,49,48,51,50,49,41};
static C_char C_TLS li203[] C_aligned={C_lihdr(0,0,17),40,100,111,108,111,111,112,50,53,50,49,32,120,32,120,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li204[] C_aligned={C_lihdr(0,0,8),40,97,49,48,51,50,54,41};
static C_char C_TLS li205[] C_aligned={C_lihdr(0,0,8),40,97,49,48,51,53,57,41};
static C_char C_TLS li206[] C_aligned={C_lihdr(0,0,11),40,97,49,48,51,49,49,32,105,110,41,0,0,0,0,0};
static C_char C_TLS li207[] C_aligned={C_lihdr(0,0,49),40,35,35,115,121,115,35,105,110,99,108,117,100,101,45,102,111,114,109,115,45,102,114,111,109,45,102,105,108,101,32,102,105,108,101,110,97,109,101,32,115,111,117,114,99,101,32,107,41,0,0,0,0,0,0,0};
static C_char C_TLS li208[] C_aligned={C_lihdr(0,0,32),40,99,104,105,99,107,101,110,46,108,111,97,100,35,102,105,108,101,45,101,120,105,115,116,115,63,32,110,97,109,101,41};
static C_char C_TLS li209[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,108,111,97,100,35,102,105,110,100,45,102,105,108,101,32,110,97,109,101,32,115,101,97,114,99,104,45,112,97,116,104,41,0,0,0,0,0,0,0};
static C_char C_TLS li210[] C_aligned={C_lihdr(0,0,12),40,99,104,101,99,107,32,112,97,116,104,41,0,0,0,0};
static C_char C_TLS li211[] C_aligned={C_lihdr(0,0,12),40,108,111,111,112,32,112,97,116,104,115,41,0,0,0,0};
static C_char C_TLS li212[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,108,111,97,100,35,102,105,110,100,45,100,121,110,97,109,105,99,45,101,120,116,101,110,115,105,111,110,32,105,100,32,105,110,99,63,41,0,0,0};
static C_char C_TLS li213[] C_aligned={C_lihdr(0,0,11),40,103,50,53,57,50,32,101,120,116,41,0,0,0,0,0};
static C_char C_TLS li214[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,108,111,97,100,35,108,111,97,100,45,101,120,116,101,110,115,105,111,110,32,108,105,98,32,109,111,100,32,108,111,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li215[] C_aligned={C_lihdr(0,0,19),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,54,48,49,41,0,0,0,0,0};
static C_char C_TLS li216[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,54,49,49,32,103,50,54,49,56,41,0,0,0,0,0,0,0};
static C_char C_TLS li217[] C_aligned={C_lihdr(0,0,28),40,99,104,105,99,107,101,110,46,108,111,97,100,35,114,101,113,117,105,114,101,32,46,32,105,100,115,41,0,0,0,0};
static C_char C_TLS li218[] C_aligned={C_lihdr(0,0,19),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,54,53,52,41,0,0,0,0,0};
static C_char C_TLS li219[] C_aligned={C_lihdr(0,0,25),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,54,54,52,32,103,50,54,55,49,41,0,0,0,0,0,0,0};
static C_char C_TLS li220[] C_aligned={C_lihdr(0,0,28),40,99,104,105,99,107,101,110,46,108,111,97,100,35,112,114,111,118,105,100,101,32,46,32,105,100,115,41,0,0,0,0};
static C_char C_TLS li221[] C_aligned={C_lihdr(0,0,19),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,55,48,55,41,0,0,0,0,0};
static C_char C_TLS li222[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,108,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li223[] C_aligned={C_lihdr(0,0,30),40,99,104,105,99,107,101,110,46,108,111,97,100,35,112,114,111,118,105,100,101,100,63,32,46,32,105,100,115,41,0,0};
static C_char C_TLS li224[] C_aligned={C_lihdr(0,0,44),40,35,35,115,121,115,35,112,114,111,99,101,115,115,45,114,101,113,117,105,114,101,32,108,105,98,32,109,111,100,32,99,111,109,112,105,108,101,45,109,111,100,101,41,0,0,0,0};
static C_char C_TLS li225[] C_aligned={C_lihdr(0,0,27),40,116,101,115,116,45,101,120,116,101,110,115,105,111,110,115,32,102,110,97,109,101,32,108,115,116,41,0,0,0,0,0};
static C_char C_TLS li226[] C_aligned={C_lihdr(0,0,12),40,116,101,115,116,32,102,110,97,109,101,41,0,0,0,0};
static C_char C_TLS li227[] C_aligned={C_lihdr(0,0,12),40,108,111,111,112,32,112,97,116,104,115,41,0,0,0,0};
static C_char C_TLS li228[] C_aligned={C_lihdr(0,0,55),40,35,35,115,121,115,35,114,101,115,111,108,118,101,45,105,110,99,108,117,100,101,45,102,105,108,101,110,97,109,101,32,102,110,97,109,101,32,101,120,116,115,32,114,101,112,111,32,115,111,117,114,99,101,41,0};
static C_char C_TLS li229[] C_aligned={C_lihdr(0,0,8),40,97,49,49,48,48,48,41};
static C_char C_TLS li230[] C_aligned={C_lihdr(0,0,11),40,97,49,48,57,57,52,32,101,120,41,0,0,0,0,0};
static C_char C_TLS li231[] C_aligned={C_lihdr(0,0,8),40,97,49,49,48,49,57,41};
static C_char C_TLS li232[] C_aligned={C_lihdr(0,0,8),40,97,49,49,48,51,49,41};
static C_char C_TLS li233[] C_aligned={C_lihdr(0,0,15),40,97,49,49,48,50,53,32,46,32,97,114,103,115,41,0};
static C_char C_TLS li234[] C_aligned={C_lihdr(0,0,8),40,97,49,49,48,49,51,41};
static C_char C_TLS li235[] C_aligned={C_lihdr(0,0,10),40,97,49,48,57,56,56,32,107,41,0,0,0,0,0,0};
static C_char C_TLS li236[] C_aligned={C_lihdr(0,0,16),40,114,117,110,45,115,97,102,101,32,116,104,117,110,107,41};
static C_char C_TLS li237[] C_aligned={C_lihdr(0,0,23),40,115,116,111,114,101,45,114,101,115,117,108,116,32,120,32,114,101,115,117,108,116,41,0};
static C_char C_TLS li238[] C_aligned={C_lihdr(0,0,8),40,97,49,49,48,53,50,41};
static C_char C_TLS li239[] C_aligned={C_lihdr(0,0,15),40,67,72,73,67,75,69,78,95,121,105,101,108,100,41,0};
static C_char C_TLS li240[] C_aligned={C_lihdr(0,0,8),40,97,49,49,48,54,52,41};
static C_char C_TLS li241[] C_aligned={C_lihdr(0,0,25),40,67,72,73,67,75,69,78,95,101,118,97,108,32,101,120,112,32,114,101,115,117,108,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li242[] C_aligned={C_lihdr(0,0,8),40,97,49,49,48,56,51,41};
static C_char C_TLS li243[] C_aligned={C_lihdr(0,0,32),40,67,72,73,67,75,69,78,95,101,118,97,108,95,115,116,114,105,110,103,32,115,116,114,32,114,101,115,117,108,116,41};
static C_char C_TLS li244[] C_aligned={C_lihdr(0,0,26),40,115,116,111,114,101,45,115,116,114,105,110,103,32,98,117,102,115,105,122,101,32,98,117,102,41,0,0,0,0,0,0};
static C_char C_TLS li245[] C_aligned={C_lihdr(0,0,8),40,97,49,49,49,49,57,41};
static C_char C_TLS li246[] C_aligned={C_lihdr(0,0,40),40,67,72,73,67,75,69,78,95,101,118,97,108,95,116,111,95,115,116,114,105,110,103,32,101,120,112,32,98,117,102,32,98,117,102,115,105,122,101,41};
static C_char C_TLS li247[] C_aligned={C_lihdr(0,0,8),40,97,49,49,49,52,56,41};
static C_char C_TLS li248[] C_aligned={C_lihdr(0,0,47),40,67,72,73,67,75,69,78,95,101,118,97,108,95,115,116,114,105,110,103,95,116,111,95,115,116,114,105,110,103,32,115,116,114,32,98,117,102,32,98,117,102,115,105,122,101,41,0};
static C_char C_TLS li249[] C_aligned={C_lihdr(0,0,8),40,97,49,49,49,56,50,41};
static C_char C_TLS li250[] C_aligned={C_lihdr(0,0,32),40,67,72,73,67,75,69,78,95,97,112,112,108,121,32,102,117,110,99,32,97,114,103,115,32,114,101,115,117,108,116,41};
static C_char C_TLS li251[] C_aligned={C_lihdr(0,0,8),40,97,49,49,49,57,56,41};
static C_char C_TLS li252[] C_aligned={C_lihdr(0,0,47),40,67,72,73,67,75,69,78,95,97,112,112,108,121,95,116,111,95,115,116,114,105,110,103,32,102,117,110,99,32,97,114,103,115,32,98,117,102,32,98,117,102,115,105,122,101,41,0};
static C_char C_TLS li253[] C_aligned={C_lihdr(0,0,8),40,97,49,49,50,50,55,41};
static C_char C_TLS li254[] C_aligned={C_lihdr(0,0,25),40,67,72,73,67,75,69,78,95,114,101,97,100,32,115,116,114,32,114,101,115,117,108,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li255[] C_aligned={C_lihdr(0,0,8),40,97,49,49,50,52,57,41};
static C_char C_TLS li256[] C_aligned={C_lihdr(0,0,18),40,67,72,73,67,75,69,78,95,108,111,97,100,32,115,116,114,41,0,0,0,0,0,0};
static C_char C_TLS li257[] C_aligned={C_lihdr(0,0,39),40,67,72,73,67,75,69,78,95,103,101,116,95,101,114,114,111,114,95,109,101,115,115,97,103,101,32,98,117,102,32,98,117,102,115,105,122,101,41,0};
static C_char C_TLS li258[] C_aligned={C_lihdr(0,0,10),40,97,49,49,50,55,50,32,120,41,0,0,0,0,0,0};
static C_char C_TLS li259[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,52,52,52,32,103,50,52,53,54,41,0,0,0,0};
static C_char C_TLS li260[] C_aligned={C_lihdr(0,0,12),40,97,49,49,52,48,54,32,101,32,112,41,0,0,0,0};
static C_char C_TLS li261[] C_aligned={C_lihdr(0,0,21),40,97,49,49,52,50,56,32,115,121,109,32,112,114,111,112,32,118,97,108,41,0,0,0};
static C_char C_TLS li262[] C_aligned={C_lihdr(0,0,8),40,97,49,49,52,53,53,41};
static C_char C_TLS li263[] C_aligned={C_lihdr(0,0,12),40,100,111,108,111,111,112,49,53,51,54,41,0,0,0,0};
static C_char C_TLS li264[] C_aligned={C_lihdr(0,0,8),40,97,49,49,52,54,48,41};
static C_char C_TLS li265[] C_aligned={C_lihdr(0,0,14),40,97,49,49,52,52,57,32,116,104,117,110,107,41,0,0};
static C_char C_TLS li266[] C_aligned={C_lihdr(0,0,8),40,97,49,49,52,50,50,41};
static C_char C_TLS li267[] C_aligned={C_lihdr(0,0,63),40,97,49,49,52,57,48,32,35,35,115,121,115,35,112,117,116,47,114,101,115,116,111,114,101,33,49,53,50,51,32,35,35,115,121,115,35,119,105,116,104,45,112,114,111,112,101,114,116,121,45,114,101,115,116,111,114,101,49,53,50,52,41,0};
static C_char C_TLS li268[] C_aligned={C_lihdr(0,0,8),40,97,49,49,53,50,53,41};
static C_char C_TLS li269[] C_aligned={C_lihdr(0,0,8),40,97,49,49,53,53,53,41};
static C_char C_TLS li270[] C_aligned={C_lihdr(0,0,8),40,97,49,49,53,54,53,41};
static C_char C_TLS li271[] C_aligned={C_lihdr(0,0,17),40,97,49,49,52,57,53,32,120,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li272[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_10001)
static void C_ccall f_10001(C_word c,C_word *av) C_noret;
C_noret_decl(f_10004)
static void C_ccall f_10004(C_word c,C_word *av) C_noret;
C_noret_decl(f_10019)
static void C_ccall f_10019(C_word c,C_word *av) C_noret;
C_noret_decl(f_10022)
static void C_ccall f_10022(C_word c,C_word *av) C_noret;
C_noret_decl(f_10025)
static void C_fcall f_10025(C_word t0,C_word t1) C_noret;
C_noret_decl(f_10031)
static void C_ccall f_10031(C_word c,C_word *av) C_noret;
C_noret_decl(f_10043)
static void C_ccall f_10043(C_word c,C_word *av) C_noret;
C_noret_decl(f_10049)
static void C_ccall f_10049(C_word c,C_word *av) C_noret;
C_noret_decl(f_10109)
static void C_ccall f_10109(C_word c,C_word *av) C_noret;
C_noret_decl(f_10124)
static void C_ccall f_10124(C_word c,C_word *av) C_noret;
C_noret_decl(f_10131)
static void C_ccall f_10131(C_word c,C_word *av) C_noret;
C_noret_decl(f_10142)
static void C_ccall f_10142(C_word c,C_word *av) C_noret;
C_noret_decl(f_10146)
static void C_ccall f_10146(C_word c,C_word *av) C_noret;
C_noret_decl(f_10149)
static void C_ccall f_10149(C_word c,C_word *av) C_noret;
C_noret_decl(f_10152)
static void C_ccall f_10152(C_word c,C_word *av) C_noret;
C_noret_decl(f_10157)
static void C_ccall f_10157(C_word c,C_word *av) C_noret;
C_noret_decl(f_10160)
static void C_ccall f_10160(C_word c,C_word *av) C_noret;
C_noret_decl(f_10163)
static void C_ccall f_10163(C_word c,C_word *av) C_noret;
C_noret_decl(f_10168)
static void C_ccall f_10168(C_word c,C_word *av) C_noret;
C_noret_decl(f_10170)
static void C_fcall f_10170(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10177)
static void C_ccall f_10177(C_word c,C_word *av) C_noret;
C_noret_decl(f_10179)
static void C_ccall f_10179(C_word c,C_word *av) C_noret;
C_noret_decl(f_10186)
static void C_ccall f_10186(C_word c,C_word *av) C_noret;
C_noret_decl(f_10189)
static void C_fcall f_10189(C_word t0,C_word t1) C_noret;
C_noret_decl(f_10192)
static void C_ccall f_10192(C_word c,C_word *av) C_noret;
C_noret_decl(f_10195)
static void C_ccall f_10195(C_word c,C_word *av) C_noret;
C_noret_decl(f_10200)
static void C_fcall f_10200(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10214)
static void C_ccall f_10214(C_word c,C_word *av) C_noret;
C_noret_decl(f_10223)
static void C_ccall f_10223(C_word c,C_word *av) C_noret;
C_noret_decl(f_10234)
static void C_ccall f_10234(C_word c,C_word *av) C_noret;
C_noret_decl(f_10241)
static void C_ccall f_10241(C_word c,C_word *av) C_noret;
C_noret_decl(f_10244)
static void C_ccall f_10244(C_word c,C_word *av) C_noret;
C_noret_decl(f_10247)
static void C_ccall f_10247(C_word c,C_word *av) C_noret;
C_noret_decl(f_10260)
static void C_ccall f_10260(C_word c,C_word *av) C_noret;
C_noret_decl(f_10264)
static void C_ccall f_10264(C_word c,C_word *av) C_noret;
C_noret_decl(f_10270)
static void C_ccall f_10270(C_word c,C_word *av) C_noret;
C_noret_decl(f_10297)
static void C_ccall f_10297(C_word c,C_word *av) C_noret;
C_noret_decl(f_10301)
static void C_ccall f_10301(C_word c,C_word *av) C_noret;
C_noret_decl(f_10304)
static void C_ccall f_10304(C_word c,C_word *av) C_noret;
C_noret_decl(f_10307)
static void C_ccall f_10307(C_word c,C_word *av) C_noret;
C_noret_decl(f_10312)
static void C_ccall f_10312(C_word c,C_word *av) C_noret;
C_noret_decl(f_10320)
static void C_ccall f_10320(C_word c,C_word *av) C_noret;
C_noret_decl(f_10322)
static void C_ccall f_10322(C_word c,C_word *av) C_noret;
C_noret_decl(f_10327)
static void C_ccall f_10327(C_word c,C_word *av) C_noret;
C_noret_decl(f_10335)
static void C_ccall f_10335(C_word c,C_word *av) C_noret;
C_noret_decl(f_10337)
static void C_fcall f_10337(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10354)
static void C_ccall f_10354(C_word c,C_word *av) C_noret;
C_noret_decl(f_10360)
static void C_ccall f_10360(C_word c,C_word *av) C_noret;
C_noret_decl(f_10366)
static void C_ccall f_10366(C_word c,C_word *av) C_noret;
C_noret_decl(f_10378)
static void C_fcall f_10378(C_word t0,C_word t1) C_noret;
C_noret_decl(f_10385)
static void C_ccall f_10385(C_word c,C_word *av) C_noret;
C_noret_decl(f_10387)
static void C_ccall f_10387(C_word c,C_word *av) C_noret;
C_noret_decl(f_10416)
static void C_ccall f_10416(C_word c,C_word *av) C_noret;
C_noret_decl(f_10428)
static void C_ccall f_10428(C_word c,C_word *av) C_noret;
C_noret_decl(f_10434)
static void C_ccall f_10434(C_word c,C_word *av) C_noret;
C_noret_decl(f_10438)
static void C_ccall f_10438(C_word c,C_word *av) C_noret;
C_noret_decl(f_10441)
static void C_ccall f_10441(C_word c,C_word *av) C_noret;
C_noret_decl(f_10443)
static void C_fcall f_10443(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10447)
static void C_ccall f_10447(C_word c,C_word *av) C_noret;
C_noret_decl(f_10450)
static void C_ccall f_10450(C_word c,C_word *av) C_noret;
C_noret_decl(f_10460)
static void C_ccall f_10460(C_word c,C_word *av) C_noret;
C_noret_decl(f_10472)
static void C_ccall f_10472(C_word c,C_word *av) C_noret;
C_noret_decl(f_10479)
static void C_ccall f_10479(C_word c,C_word *av) C_noret;
C_noret_decl(f_10486)
static void C_ccall f_10486(C_word c,C_word *av) C_noret;
C_noret_decl(f_10488)
static void C_fcall f_10488(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10501)
static void C_ccall f_10501(C_word c,C_word *av) C_noret;
C_noret_decl(f_10535)
static void C_ccall f_10535(C_word c,C_word *av) C_noret;
C_noret_decl(f_10544)
static void C_ccall f_10544(C_word c,C_word *av) C_noret;
C_noret_decl(f_10560)
static void C_ccall f_10560(C_word c,C_word *av) C_noret;
C_noret_decl(f_10573)
static void C_ccall f_10573(C_word c,C_word *av) C_noret;
C_noret_decl(f_10576)
static void C_ccall f_10576(C_word c,C_word *av) C_noret;
C_noret_decl(f_10588)
static void C_ccall f_10588(C_word c,C_word *av) C_noret;
C_noret_decl(f_10592)
static void C_fcall f_10592(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10596)
static void C_ccall f_10596(C_word c,C_word *av) C_noret;
C_noret_decl(f_10599)
static void C_ccall f_10599(C_word c,C_word *av) C_noret;
C_noret_decl(f_10607)
static void C_ccall f_10607(C_word c,C_word *av) C_noret;
C_noret_decl(f_10626)
static void C_fcall f_10626(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10636)
static void C_ccall f_10636(C_word c,C_word *av) C_noret;
C_noret_decl(f_10649)
static C_word C_fcall f_10649(C_word t0);
C_noret_decl(f_10672)
static void C_ccall f_10672(C_word c,C_word *av) C_noret;
C_noret_decl(f_10691)
static void C_fcall f_10691(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10701)
static void C_ccall f_10701(C_word c,C_word *av) C_noret;
C_noret_decl(f_10714)
static C_word C_fcall f_10714(C_word t0);
C_noret_decl(f_10737)
static void C_ccall f_10737(C_word c,C_word *av) C_noret;
C_noret_decl(f_10751)
static C_word C_fcall f_10751(C_word t0);
C_noret_decl(f_10778)
static void C_ccall f_10778(C_word c,C_word *av) C_noret;
C_noret_decl(f_10847)
static void C_ccall f_10847(C_word c,C_word *av) C_noret;
C_noret_decl(f_10850)
static void C_fcall f_10850(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10863)
static void C_ccall f_10863(C_word c,C_word *av) C_noret;
C_noret_decl(f_10866)
static void C_ccall f_10866(C_word c,C_word *av) C_noret;
C_noret_decl(f_10869)
static void C_ccall f_10869(C_word c,C_word *av) C_noret;
C_noret_decl(f_10883)
static void C_fcall f_10883(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10919)
static void C_ccall f_10919(C_word c,C_word *av) C_noret;
C_noret_decl(f_10922)
static void C_ccall f_10922(C_word c,C_word *av) C_noret;
C_noret_decl(f_10932)
static void C_ccall f_10932(C_word c,C_word *av) C_noret;
C_noret_decl(f_10934)
static void C_fcall f_10934(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10944)
static void C_ccall f_10944(C_word c,C_word *av) C_noret;
C_noret_decl(f_10958)
static void C_ccall f_10958(C_word c,C_word *av) C_noret;
C_noret_decl(f_10969)
static void C_ccall f_10969(C_word c,C_word *av) C_noret;
C_noret_decl(f_10976)
static void C_ccall f_10976(C_word c,C_word *av) C_noret;
C_noret_decl(f_10979)
static void C_fcall f_10979(C_word t0,C_word t1) C_noret;
C_noret_decl(f_10984)
static void C_ccall f_10984(C_word c,C_word *av) C_noret;
C_noret_decl(f_10989)
static void C_ccall f_10989(C_word c,C_word *av) C_noret;
C_noret_decl(f_10995)
static void C_ccall f_10995(C_word c,C_word *av) C_noret;
C_noret_decl(f_11001)
static void C_ccall f_11001(C_word c,C_word *av) C_noret;
C_noret_decl(f_11005)
static void C_ccall f_11005(C_word c,C_word *av) C_noret;
C_noret_decl(f_11008)
static void C_ccall f_11008(C_word c,C_word *av) C_noret;
C_noret_decl(f_11012)
static void C_ccall f_11012(C_word c,C_word *av) C_noret;
C_noret_decl(f_11014)
static void C_ccall f_11014(C_word c,C_word *av) C_noret;
C_noret_decl(f_11020)
static void C_ccall f_11020(C_word c,C_word *av) C_noret;
C_noret_decl(f_11026)
static void C_ccall f_11026(C_word c,C_word *av) C_noret;
C_noret_decl(f_11032)
static void C_ccall f_11032(C_word c,C_word *av) C_noret;
C_noret_decl(f_11038)
static void C_fcall f_11038(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11042)
static void C_ccall f_11042(C_word c,C_word *av) C_noret;
C_noret_decl(f_11047)
static void C_ccall f_11047(C_word c,C_word *av) C_noret;
C_noret_decl(f_11053)
static void C_ccall f_11053(C_word c,C_word *av) C_noret;
C_noret_decl(f_11057)
static void C_ccall f_11057(C_word c,C_word *av) C_noret;
C_noret_decl(f_11059)
static void C_ccall f_11059(C_word c,C_word *av) C_noret;
C_noret_decl(f_11065)
static void C_ccall f_11065(C_word c,C_word *av) C_noret;
C_noret_decl(f_11073)
static void C_ccall f_11073(C_word c,C_word *av) C_noret;
C_noret_decl(f_11075)
static void C_ccall f_11075(C_word c,C_word *av) C_noret;
C_noret_decl(f_11079)
static void C_ccall f_11079(C_word c,C_word *av) C_noret;
C_noret_decl(f_11084)
static void C_ccall f_11084(C_word c,C_word *av) C_noret;
C_noret_decl(f_11088)
static void C_ccall f_11088(C_word c,C_word *av) C_noret;
C_noret_decl(f_11095)
static void C_ccall f_11095(C_word c,C_word *av) C_noret;
C_noret_decl(f_11099)
static void C_ccall f_11099(C_word c,C_word *av) C_noret;
C_noret_decl(f_11101)
static C_word C_fcall f_11101(C_word t0,C_word t1,C_word t2);
C_noret_decl(f_11114)
static void C_ccall f_11114(C_word c,C_word *av) C_noret;
C_noret_decl(f_11120)
static void C_ccall f_11120(C_word c,C_word *av) C_noret;
C_noret_decl(f_11124)
static void C_ccall f_11124(C_word c,C_word *av) C_noret;
C_noret_decl(f_11127)
static void C_ccall f_11127(C_word c,C_word *av) C_noret;
C_noret_decl(f_11134)
static void C_ccall f_11134(C_word c,C_word *av) C_noret;
C_noret_decl(f_11138)
static void C_ccall f_11138(C_word c,C_word *av) C_noret;
C_noret_decl(f_11140)
static void C_ccall f_11140(C_word c,C_word *av) C_noret;
C_noret_decl(f_11144)
static void C_ccall f_11144(C_word c,C_word *av) C_noret;
C_noret_decl(f_11149)
static void C_ccall f_11149(C_word c,C_word *av) C_noret;
C_noret_decl(f_11153)
static void C_ccall f_11153(C_word c,C_word *av) C_noret;
C_noret_decl(f_11156)
static void C_ccall f_11156(C_word c,C_word *av) C_noret;
C_noret_decl(f_11163)
static void C_ccall f_11163(C_word c,C_word *av) C_noret;
C_noret_decl(f_11167)
static void C_ccall f_11167(C_word c,C_word *av) C_noret;
C_noret_decl(f_11171)
static void C_ccall f_11171(C_word c,C_word *av) C_noret;
C_noret_decl(f_11175)
static void C_ccall f_11175(C_word c,C_word *av) C_noret;
C_noret_decl(f_11177)
static void C_ccall f_11177(C_word c,C_word *av) C_noret;
C_noret_decl(f_11183)
static void C_ccall f_11183(C_word c,C_word *av) C_noret;
C_noret_decl(f_11191)
static void C_ccall f_11191(C_word c,C_word *av) C_noret;
C_noret_decl(f_11193)
static void C_ccall f_11193(C_word c,C_word *av) C_noret;
C_noret_decl(f_11199)
static void C_ccall f_11199(C_word c,C_word *av) C_noret;
C_noret_decl(f_11203)
static void C_ccall f_11203(C_word c,C_word *av) C_noret;
C_noret_decl(f_11206)
static void C_ccall f_11206(C_word c,C_word *av) C_noret;
C_noret_decl(f_11213)
static void C_ccall f_11213(C_word c,C_word *av) C_noret;
C_noret_decl(f_11217)
static void C_ccall f_11217(C_word c,C_word *av) C_noret;
C_noret_decl(f_11219)
static void C_ccall f_11219(C_word c,C_word *av) C_noret;
C_noret_decl(f_11223)
static void C_ccall f_11223(C_word c,C_word *av) C_noret;
C_noret_decl(f_11228)
static void C_ccall f_11228(C_word c,C_word *av) C_noret;
C_noret_decl(f_11232)
static void C_ccall f_11232(C_word c,C_word *av) C_noret;
C_noret_decl(f_11239)
static void C_ccall f_11239(C_word c,C_word *av) C_noret;
C_noret_decl(f_11241)
static void C_ccall f_11241(C_word c,C_word *av) C_noret;
C_noret_decl(f_11245)
static void C_ccall f_11245(C_word c,C_word *av) C_noret;
C_noret_decl(f_11250)
static void C_ccall f_11250(C_word c,C_word *av) C_noret;
C_noret_decl(f_11254)
static void C_ccall f_11254(C_word c,C_word *av) C_noret;
C_noret_decl(f_11256)
static void C_ccall f_11256(C_word c,C_word *av) C_noret;
C_noret_decl(f_11271)
static void C_ccall f_11271(C_word c,C_word *av) C_noret;
C_noret_decl(f_11273)
static void C_ccall f_11273(C_word c,C_word *av) C_noret;
C_noret_decl(f_11279)
static void C_fcall f_11279(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11304)
static void C_ccall f_11304(C_word c,C_word *av) C_noret;
C_noret_decl(f_11318)
static void C_ccall f_11318(C_word c,C_word *av) C_noret;
C_noret_decl(f_11330)
static void C_ccall f_11330(C_word c,C_word *av) C_noret;
C_noret_decl(f_11334)
static void C_ccall f_11334(C_word c,C_word *av) C_noret;
C_noret_decl(f_11361)
static void C_ccall f_11361(C_word c,C_word *av) C_noret;
C_noret_decl(f_11365)
static void C_ccall f_11365(C_word c,C_word *av) C_noret;
C_noret_decl(f_11369)
static void C_ccall f_11369(C_word c,C_word *av) C_noret;
C_noret_decl(f_11373)
static void C_ccall f_11373(C_word c,C_word *av) C_noret;
C_noret_decl(f_11377)
static void C_ccall f_11377(C_word c,C_word *av) C_noret;
C_noret_decl(f_11385)
static void C_ccall f_11385(C_word c,C_word *av) C_noret;
C_noret_decl(f_11393)
static void C_ccall f_11393(C_word c,C_word *av) C_noret;
C_noret_decl(f_11401)
static void C_ccall f_11401(C_word c,C_word *av) C_noret;
C_noret_decl(f_11407)
static void C_ccall f_11407(C_word c,C_word *av) C_noret;
C_noret_decl(f_11411)
static void C_ccall f_11411(C_word c,C_word *av) C_noret;
C_noret_decl(f_11414)
static void C_ccall f_11414(C_word c,C_word *av) C_noret;
C_noret_decl(f_11423)
static void C_ccall f_11423(C_word c,C_word *av) C_noret;
C_noret_decl(f_11429)
static void C_ccall f_11429(C_word c,C_word *av) C_noret;
C_noret_decl(f_11433)
static void C_fcall f_11433(C_word t0,C_word t1) C_noret;
C_noret_decl(f_11436)
static void C_ccall f_11436(C_word c,C_word *av) C_noret;
C_noret_decl(f_11448)
static void C_ccall f_11448(C_word c,C_word *av) C_noret;
C_noret_decl(f_11450)
static void C_ccall f_11450(C_word c,C_word *av) C_noret;
C_noret_decl(f_11456)
static void C_ccall f_11456(C_word c,C_word *av) C_noret;
C_noret_decl(f_11461)
static void C_ccall f_11461(C_word c,C_word *av) C_noret;
C_noret_decl(f_11465)
static void C_ccall f_11465(C_word c,C_word *av) C_noret;
C_noret_decl(f_11468)
static void C_fcall f_11468(C_word t0,C_word t1) C_noret;
C_noret_decl(f_11478)
static void C_ccall f_11478(C_word c,C_word *av) C_noret;
C_noret_decl(f_11491)
static void C_ccall f_11491(C_word c,C_word *av) C_noret;
C_noret_decl(f_11496)
static void C_ccall f_11496(C_word c,C_word *av) C_noret;
C_noret_decl(f_11503)
static void C_ccall f_11503(C_word c,C_word *av) C_noret;
C_noret_decl(f_11506)
static void C_ccall f_11506(C_word c,C_word *av) C_noret;
C_noret_decl(f_11518)
static void C_ccall f_11518(C_word c,C_word *av) C_noret;
C_noret_decl(f_11526)
static void C_ccall f_11526(C_word c,C_word *av) C_noret;
C_noret_decl(f_11530)
static void C_ccall f_11530(C_word c,C_word *av) C_noret;
C_noret_decl(f_11533)
static void C_ccall f_11533(C_word c,C_word *av) C_noret;
C_noret_decl(f_11537)
static void C_ccall f_11537(C_word c,C_word *av) C_noret;
C_noret_decl(f_11541)
static void C_ccall f_11541(C_word c,C_word *av) C_noret;
C_noret_decl(f_11544)
static void C_ccall f_11544(C_word c,C_word *av) C_noret;
C_noret_decl(f_11547)
static void C_ccall f_11547(C_word c,C_word *av) C_noret;
C_noret_decl(f_11556)
static void C_ccall f_11556(C_word c,C_word *av) C_noret;
C_noret_decl(f_11566)
static void C_ccall f_11566(C_word c,C_word *av) C_noret;
C_noret_decl(f_11570)
static void C_ccall f_11570(C_word c,C_word *av) C_noret;
C_noret_decl(f_11573)
static void C_ccall f_11573(C_word c,C_word *av) C_noret;
C_noret_decl(f_11576)
static void C_ccall f_11576(C_word c,C_word *av) C_noret;
C_noret_decl(f_11579)
static void C_ccall f_11579(C_word c,C_word *av) C_noret;
C_noret_decl(f_11587)
static void C_ccall f_11587(C_word c,C_word *av) C_noret;
C_noret_decl(f_11596)
static void C_ccall f_11596(C_word c,C_word *av) C_noret;
C_noret_decl(f_3521)
static void C_ccall f_3521(C_word c,C_word *av) C_noret;
C_noret_decl(f_3524)
static void C_ccall f_3524(C_word c,C_word *av) C_noret;
C_noret_decl(f_3527)
static void C_ccall f_3527(C_word c,C_word *av) C_noret;
C_noret_decl(f_3530)
static void C_ccall f_3530(C_word c,C_word *av) C_noret;
C_noret_decl(f_3538)
static void C_ccall f_3538(C_word c,C_word *av) C_noret;
C_noret_decl(f_3551)
static void C_ccall f_3551(C_word c,C_word *av) C_noret;
C_noret_decl(f_3559)
static void C_ccall f_3559(C_word c,C_word *av) C_noret;
C_noret_decl(f_3563)
static void C_ccall f_3563(C_word c,C_word *av) C_noret;
C_noret_decl(f_3566)
static void C_ccall f_3566(C_word c,C_word *av) C_noret;
C_noret_decl(f_3569)
static void C_ccall f_3569(C_word c,C_word *av) C_noret;
C_noret_decl(f_3574)
static void C_ccall f_3574(C_word c,C_word *av) C_noret;
C_noret_decl(f_3576)
static void C_fcall f_3576(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3603)
static void C_fcall f_3603(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3616)
static void C_fcall f_3616(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3638)
static void C_fcall f_3638(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3642)
static void C_ccall f_3642(C_word c,C_word *av) C_noret;
C_noret_decl(f_3650)
static void C_ccall f_3650(C_word c,C_word *av) C_noret;
C_noret_decl(f_3656)
static void C_ccall f_3656(C_word c,C_word *av) C_noret;
C_noret_decl(f_3663)
static void C_ccall f_3663(C_word c,C_word *av) C_noret;
C_noret_decl(f_3670)
static void C_ccall f_3670(C_word c,C_word *av) C_noret;
C_noret_decl(f_3672)
static void C_fcall f_3672(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3676)
static void C_ccall f_3676(C_word c,C_word *av) C_noret;
C_noret_decl(f_3684)
static void C_fcall f_3684(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3701)
static void C_fcall f_3701(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3731)
static C_word C_fcall f_3731(C_word t0,C_word t1,C_word t2);
C_noret_decl(f_3761)
static C_word C_fcall f_3761(C_word *a,C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5);
C_noret_decl(f_3775)
static void C_fcall f_3775(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3783)
static void C_ccall f_3783(C_word c,C_word *av) C_noret;
C_noret_decl(f_3792)
static void C_fcall f_3792(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3800)
static void C_ccall f_3800(C_word c,C_word *av) C_noret;
C_noret_decl(f_3807)
static void C_ccall f_3807(C_word c,C_word *av) C_noret;
C_noret_decl(f_3810)
static void C_ccall f_3810(C_word c,C_word *av) C_noret;
C_noret_decl(f_3825)
static void C_fcall f_3825(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7) C_noret;
C_noret_decl(f_3832)
static void C_ccall f_3832(C_word c,C_word *av) C_noret;
C_noret_decl(f_3833)
static void C_ccall f_3833(C_word c,C_word *av) C_noret;
C_noret_decl(f_3845)
static void C_ccall f_3845(C_word c,C_word *av) C_noret;
C_noret_decl(f_3851)
static void C_ccall f_3851(C_word c,C_word *av) C_noret;
C_noret_decl(f_3861)
static void C_ccall f_3861(C_word c,C_word *av) C_noret;
C_noret_decl(f_3864)
static void C_fcall f_3864(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3871)
static void C_ccall f_3871(C_word c,C_word *av) C_noret;
C_noret_decl(f_3881)
static void C_ccall f_3881(C_word c,C_word *av) C_noret;
C_noret_decl(f_3882)
static void C_ccall f_3882(C_word c,C_word *av) C_noret;
C_noret_decl(f_3887)
static void C_ccall f_3887(C_word c,C_word *av) C_noret;
C_noret_decl(f_3891)
static void C_fcall f_3891(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3912)
static void C_ccall f_3912(C_word c,C_word *av) C_noret;
C_noret_decl(f_3944)
static void C_ccall f_3944(C_word c,C_word *av) C_noret;
C_noret_decl(f_3955)
static void C_ccall f_3955(C_word c,C_word *av) C_noret;
C_noret_decl(f_3970)
static void C_ccall f_3970(C_word c,C_word *av) C_noret;
C_noret_decl(f_3989)
static void C_ccall f_3989(C_word c,C_word *av) C_noret;
C_noret_decl(f_4012)
static void C_ccall f_4012(C_word c,C_word *av) C_noret;
C_noret_decl(f_4033)
static void C_ccall f_4033(C_word c,C_word *av) C_noret;
C_noret_decl(f_4052)
static void C_ccall f_4052(C_word c,C_word *av) C_noret;
C_noret_decl(f_4059)
static void C_ccall f_4059(C_word c,C_word *av) C_noret;
C_noret_decl(f_4067)
static void C_ccall f_4067(C_word c,C_word *av) C_noret;
C_noret_decl(f_4075)
static void C_ccall f_4075(C_word c,C_word *av) C_noret;
C_noret_decl(f_4083)
static void C_ccall f_4083(C_word c,C_word *av) C_noret;
C_noret_decl(f_4085)
static void C_ccall f_4085(C_word c,C_word *av) C_noret;
C_noret_decl(f_4104)
static void C_ccall f_4104(C_word c,C_word *av) C_noret;
C_noret_decl(f_4106)
static void C_ccall f_4106(C_word c,C_word *av) C_noret;
C_noret_decl(f_4116)
static void C_ccall f_4116(C_word c,C_word *av) C_noret;
C_noret_decl(f_4117)
static void C_ccall f_4117(C_word c,C_word *av) C_noret;
C_noret_decl(f_4136)
static void C_ccall f_4136(C_word c,C_word *av) C_noret;
C_noret_decl(f_4139)
static void C_ccall f_4139(C_word c,C_word *av) C_noret;
C_noret_decl(f_4145)
static void C_ccall f_4145(C_word c,C_word *av) C_noret;
C_noret_decl(f_4160)
static void C_ccall f_4160(C_word c,C_word *av) C_noret;
C_noret_decl(f_4169)
static void C_ccall f_4169(C_word c,C_word *av) C_noret;
C_noret_decl(f_4176)
static void C_ccall f_4176(C_word c,C_word *av) C_noret;
C_noret_decl(f_4184)
static void C_ccall f_4184(C_word c,C_word *av) C_noret;
C_noret_decl(f_4192)
static void C_ccall f_4192(C_word c,C_word *av) C_noret;
C_noret_decl(f_4200)
static void C_ccall f_4200(C_word c,C_word *av) C_noret;
C_noret_decl(f_4208)
static void C_ccall f_4208(C_word c,C_word *av) C_noret;
C_noret_decl(f_4216)
static void C_ccall f_4216(C_word c,C_word *av) C_noret;
C_noret_decl(f_4224)
static void C_ccall f_4224(C_word c,C_word *av) C_noret;
C_noret_decl(f_4226)
static void C_ccall f_4226(C_word c,C_word *av) C_noret;
C_noret_decl(f_4255)
static void C_ccall f_4255(C_word c,C_word *av) C_noret;
C_noret_decl(f_4289)
static void C_ccall f_4289(C_word c,C_word *av) C_noret;
C_noret_decl(f_4299)
static void C_ccall f_4299(C_word c,C_word *av) C_noret;
C_noret_decl(f_4302)
static void C_ccall f_4302(C_word c,C_word *av) C_noret;
C_noret_decl(f_4305)
static void C_ccall f_4305(C_word c,C_word *av) C_noret;
C_noret_decl(f_4306)
static void C_ccall f_4306(C_word c,C_word *av) C_noret;
C_noret_decl(f_4313)
static void C_ccall f_4313(C_word c,C_word *av) C_noret;
C_noret_decl(f_4387)
static void C_ccall f_4387(C_word c,C_word *av) C_noret;
C_noret_decl(f_4390)
static void C_ccall f_4390(C_word c,C_word *av) C_noret;
C_noret_decl(f_4391)
static void C_ccall f_4391(C_word c,C_word *av) C_noret;
C_noret_decl(f_4395)
static void C_ccall f_4395(C_word c,C_word *av) C_noret;
C_noret_decl(f_4409)
static void C_ccall f_4409(C_word c,C_word *av) C_noret;
C_noret_decl(f_4412)
static void C_ccall f_4412(C_word c,C_word *av) C_noret;
C_noret_decl(f_4415)
static void C_ccall f_4415(C_word c,C_word *av) C_noret;
C_noret_decl(f_4416)
static void C_ccall f_4416(C_word c,C_word *av) C_noret;
C_noret_decl(f_4420)
static void C_ccall f_4420(C_word c,C_word *av) C_noret;
C_noret_decl(f_4423)
static void C_ccall f_4423(C_word c,C_word *av) C_noret;
C_noret_decl(f_4461)
static void C_ccall f_4461(C_word c,C_word *av) C_noret;
C_noret_decl(f_4464)
static void C_ccall f_4464(C_word c,C_word *av) C_noret;
C_noret_decl(f_4492)
static void C_ccall f_4492(C_word c,C_word *av) C_noret;
C_noret_decl(f_4498)
static void C_ccall f_4498(C_word c,C_word *av) C_noret;
C_noret_decl(f_4502)
static void C_ccall f_4502(C_word c,C_word *av) C_noret;
C_noret_decl(f_4511)
static void C_ccall f_4511(C_word c,C_word *av) C_noret;
C_noret_decl(f_4515)
static void C_ccall f_4515(C_word c,C_word *av) C_noret;
C_noret_decl(f_4522)
static void C_ccall f_4522(C_word c,C_word *av) C_noret;
C_noret_decl(f_4523)
static void C_ccall f_4523(C_word c,C_word *av) C_noret;
C_noret_decl(f_4527)
static void C_ccall f_4527(C_word c,C_word *av) C_noret;
C_noret_decl(f_4553)
static void C_ccall f_4553(C_word c,C_word *av) C_noret;
C_noret_decl(f_4558)
static void C_ccall f_4558(C_word c,C_word *av) C_noret;
C_noret_decl(f_4570)
static void C_ccall f_4570(C_word c,C_word *av) C_noret;
C_noret_decl(f_4571)
static void C_ccall f_4571(C_word c,C_word *av) C_noret;
C_noret_decl(f_4580)
static void C_ccall f_4580(C_word c,C_word *av) C_noret;
C_noret_decl(f_4607)
static void C_ccall f_4607(C_word c,C_word *av) C_noret;
C_noret_decl(f_4616)
static void C_ccall f_4616(C_word c,C_word *av) C_noret;
C_noret_decl(f_4622)
static void C_ccall f_4622(C_word c,C_word *av) C_noret;
C_noret_decl(f_4625)
static void C_ccall f_4625(C_word c,C_word *av) C_noret;
C_noret_decl(f_4634)
static void C_ccall f_4634(C_word c,C_word *av) C_noret;
C_noret_decl(f_4635)
static void C_ccall f_4635(C_word c,C_word *av) C_noret;
C_noret_decl(f_4651)
static void C_ccall f_4651(C_word c,C_word *av) C_noret;
C_noret_decl(f_4655)
static void C_ccall f_4655(C_word c,C_word *av) C_noret;
C_noret_decl(f_4668)
static void C_ccall f_4668(C_word c,C_word *av) C_noret;
C_noret_decl(f_4671)
static void C_ccall f_4671(C_word c,C_word *av) C_noret;
C_noret_decl(f_4672)
static void C_ccall f_4672(C_word c,C_word *av) C_noret;
C_noret_decl(f_4688)
static void C_ccall f_4688(C_word c,C_word *av) C_noret;
C_noret_decl(f_4692)
static void C_ccall f_4692(C_word c,C_word *av) C_noret;
C_noret_decl(f_4696)
static void C_ccall f_4696(C_word c,C_word *av) C_noret;
C_noret_decl(f_4704)
static void C_ccall f_4704(C_word c,C_word *av) C_noret;
C_noret_decl(f_4717)
static void C_ccall f_4717(C_word c,C_word *av) C_noret;
C_noret_decl(f_4720)
static void C_ccall f_4720(C_word c,C_word *av) C_noret;
C_noret_decl(f_4726)
static void C_ccall f_4726(C_word c,C_word *av) C_noret;
C_noret_decl(f_4727)
static void C_ccall f_4727(C_word c,C_word *av) C_noret;
C_noret_decl(f_4743)
static void C_ccall f_4743(C_word c,C_word *av) C_noret;
C_noret_decl(f_4747)
static void C_ccall f_4747(C_word c,C_word *av) C_noret;
C_noret_decl(f_4751)
static void C_ccall f_4751(C_word c,C_word *av) C_noret;
C_noret_decl(f_4755)
static void C_ccall f_4755(C_word c,C_word *av) C_noret;
C_noret_decl(f_4763)
static void C_ccall f_4763(C_word c,C_word *av) C_noret;
C_noret_decl(f_4771)
static void C_ccall f_4771(C_word c,C_word *av) C_noret;
C_noret_decl(f_4784)
static void C_ccall f_4784(C_word c,C_word *av) C_noret;
C_noret_decl(f_4787)
static void C_ccall f_4787(C_word c,C_word *av) C_noret;
C_noret_decl(f_4793)
static void C_ccall f_4793(C_word c,C_word *av) C_noret;
C_noret_decl(f_4796)
static void C_ccall f_4796(C_word c,C_word *av) C_noret;
C_noret_decl(f_4797)
static void C_ccall f_4797(C_word c,C_word *av) C_noret;
C_noret_decl(f_4813)
static void C_ccall f_4813(C_word c,C_word *av) C_noret;
C_noret_decl(f_4817)
static void C_ccall f_4817(C_word c,C_word *av) C_noret;
C_noret_decl(f_4821)
static void C_ccall f_4821(C_word c,C_word *av) C_noret;
C_noret_decl(f_4825)
static void C_ccall f_4825(C_word c,C_word *av) C_noret;
C_noret_decl(f_4829)
static void C_ccall f_4829(C_word c,C_word *av) C_noret;
C_noret_decl(f_4837)
static void C_ccall f_4837(C_word c,C_word *av) C_noret;
C_noret_decl(f_4845)
static void C_ccall f_4845(C_word c,C_word *av) C_noret;
C_noret_decl(f_4853)
static void C_ccall f_4853(C_word c,C_word *av) C_noret;
C_noret_decl(f_4861)
static void C_fcall f_4861(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4874)
static void C_ccall f_4874(C_word c,C_word *av) C_noret;
C_noret_decl(f_4875)
static void C_ccall f_4875(C_word c,C_word *av) C_noret;
C_noret_decl(f_4879)
static void C_ccall f_4879(C_word c,C_word *av) C_noret;
C_noret_decl(f_4882)
static void C_ccall f_4882(C_word c,C_word *av) C_noret;
C_noret_decl(f_4891)
static void C_fcall f_4891(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_4916)
static void C_ccall f_4916(C_word c,C_word *av) C_noret;
C_noret_decl(f_4921)
static void C_fcall f_4921(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4946)
static void C_ccall f_4946(C_word c,C_word *av) C_noret;
C_noret_decl(f_4963)
static void C_ccall f_4963(C_word c,C_word *av) C_noret;
C_noret_decl(f_4967)
static void C_ccall f_4967(C_word c,C_word *av) C_noret;
C_noret_decl(f_4971)
static void C_ccall f_4971(C_word c,C_word *av) C_noret;
C_noret_decl(f_4974)
static void C_ccall f_4974(C_word c,C_word *av) C_noret;
C_noret_decl(f_4980)
static void C_ccall f_4980(C_word c,C_word *av) C_noret;
C_noret_decl(f_4988)
static void C_ccall f_4988(C_word c,C_word *av) C_noret;
C_noret_decl(f_4996)
static void C_ccall f_4996(C_word c,C_word *av) C_noret;
C_noret_decl(f_4998)
static void C_ccall f_4998(C_word c,C_word *av) C_noret;
C_noret_decl(f_5002)
static void C_ccall f_5002(C_word c,C_word *av) C_noret;
C_noret_decl(f_5005)
static void C_ccall f_5005(C_word c,C_word *av) C_noret;
C_noret_decl(f_5010)
static void C_ccall f_5010(C_word c,C_word *av) C_noret;
C_noret_decl(f_5012)
static void C_fcall f_5012(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5037)
static void C_ccall f_5037(C_word c,C_word *av) C_noret;
C_noret_decl(f_5046)
static void C_fcall f_5046(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5119)
static void C_ccall f_5119(C_word c,C_word *av) C_noret;
C_noret_decl(f_5123)
static void C_ccall f_5123(C_word c,C_word *av) C_noret;
C_noret_decl(f_5143)
static void C_ccall f_5143(C_word c,C_word *av) C_noret;
C_noret_decl(f_5157)
static void C_fcall f_5157(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5191)
static void C_fcall f_5191(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5241)
static void C_ccall f_5241(C_word c,C_word *av) C_noret;
C_noret_decl(f_5250)
static void C_ccall f_5250(C_word c,C_word *av) C_noret;
C_noret_decl(f_5276)
static void C_ccall f_5276(C_word c,C_word *av) C_noret;
C_noret_decl(f_5303)
static void C_ccall f_5303(C_word c,C_word *av) C_noret;
C_noret_decl(f_5307)
static void C_ccall f_5307(C_word c,C_word *av) C_noret;
C_noret_decl(f_5319)
static void C_ccall f_5319(C_word c,C_word *av) C_noret;
C_noret_decl(f_5333)
static void C_fcall f_5333(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_5381)
static void C_fcall f_5381(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_5429)
static void C_fcall f_5429(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5463)
static void C_fcall f_5463(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5488)
static void C_ccall f_5488(C_word c,C_word *av) C_noret;
C_noret_decl(f_5497)
static void C_fcall f_5497(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5538)
static void C_ccall f_5538(C_word c,C_word *av) C_noret;
C_noret_decl(f_5549)
static void C_ccall f_5549(C_word c,C_word *av) C_noret;
C_noret_decl(f_5554)
static void C_ccall f_5554(C_word c,C_word *av) C_noret;
C_noret_decl(f_5564)
static void C_ccall f_5564(C_word c,C_word *av) C_noret;
C_noret_decl(f_5567)
static void C_ccall f_5567(C_word c,C_word *av) C_noret;
C_noret_decl(f_5573)
static void C_ccall f_5573(C_word c,C_word *av) C_noret;
C_noret_decl(f_5583)
static void C_ccall f_5583(C_word c,C_word *av) C_noret;
C_noret_decl(f_5589)
static void C_ccall f_5589(C_word c,C_word *av) C_noret;
C_noret_decl(f_5602)
static void C_ccall f_5602(C_word c,C_word *av) C_noret;
C_noret_decl(f_5608)
static void C_ccall f_5608(C_word c,C_word *av) C_noret;
C_noret_decl(f_5626)
static void C_ccall f_5626(C_word c,C_word *av) C_noret;
C_noret_decl(f_5632)
static void C_ccall f_5632(C_word c,C_word *av) C_noret;
C_noret_decl(f_5645)
static void C_ccall f_5645(C_word c,C_word *av) C_noret;
C_noret_decl(f_5651)
static void C_ccall f_5651(C_word c,C_word *av) C_noret;
C_noret_decl(f_5673)
static void C_ccall f_5673(C_word c,C_word *av) C_noret;
C_noret_decl(f_5679)
static void C_ccall f_5679(C_word c,C_word *av) C_noret;
C_noret_decl(f_5692)
static void C_ccall f_5692(C_word c,C_word *av) C_noret;
C_noret_decl(f_5698)
static void C_ccall f_5698(C_word c,C_word *av) C_noret;
C_noret_decl(f_5720)
static void C_ccall f_5720(C_word c,C_word *av) C_noret;
C_noret_decl(f_5726)
static void C_ccall f_5726(C_word c,C_word *av) C_noret;
C_noret_decl(f_5739)
static void C_ccall f_5739(C_word c,C_word *av) C_noret;
C_noret_decl(f_5745)
static void C_ccall f_5745(C_word c,C_word *av) C_noret;
C_noret_decl(f_5767)
static void C_ccall f_5767(C_word c,C_word *av) C_noret;
C_noret_decl(f_5773)
static void C_ccall f_5773(C_word c,C_word *av) C_noret;
C_noret_decl(f_5786)
static void C_ccall f_5786(C_word c,C_word *av) C_noret;
C_noret_decl(f_5792)
static void C_ccall f_5792(C_word c,C_word *av) C_noret;
C_noret_decl(f_5804)
static void C_ccall f_5804(C_word c,C_word *av) C_noret;
C_noret_decl(f_5808)
static void C_ccall f_5808(C_word c,C_word *av) C_noret;
C_noret_decl(f_5814)
static void C_ccall f_5814(C_word c,C_word *av) C_noret;
C_noret_decl(f_5826)
static void C_ccall f_5826(C_word c,C_word *av) C_noret;
C_noret_decl(f_5830)
static void C_ccall f_5830(C_word c,C_word *av) C_noret;
C_noret_decl(f_5831)
static void C_ccall f_5831(C_word c,C_word *av) C_noret;
C_noret_decl(f_5837)
static void C_ccall f_5837(C_word c,C_word *av) C_noret;
C_noret_decl(f_5859)
static void C_ccall f_5859(C_word c,C_word *av) C_noret;
C_noret_decl(f_5875)
static void C_ccall f_5875(C_word c,C_word *av) C_noret;
C_noret_decl(f_5879)
static void C_ccall f_5879(C_word c,C_word *av) C_noret;
C_noret_decl(f_5883)
static void C_ccall f_5883(C_word c,C_word *av) C_noret;
C_noret_decl(f_5886)
static void C_ccall f_5886(C_word c,C_word *av) C_noret;
C_noret_decl(f_5892)
static void C_ccall f_5892(C_word c,C_word *av) C_noret;
C_noret_decl(f_5900)
static void C_ccall f_5900(C_word c,C_word *av) C_noret;
C_noret_decl(f_5906)
static void C_ccall f_5906(C_word c,C_word *av) C_noret;
C_noret_decl(f_5910)
static void C_ccall f_5910(C_word c,C_word *av) C_noret;
C_noret_decl(f_5913)
static void C_ccall f_5913(C_word c,C_word *av) C_noret;
C_noret_decl(f_5918)
static void C_ccall f_5918(C_word c,C_word *av) C_noret;
C_noret_decl(f_5920)
static void C_fcall f_5920(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5945)
static void C_ccall f_5945(C_word c,C_word *av) C_noret;
C_noret_decl(f_5955)
static void C_ccall f_5955(C_word c,C_word *av) C_noret;
C_noret_decl(f_5960)
static void C_ccall f_5960(C_word c,C_word *av) C_noret;
C_noret_decl(f_5968)
static void C_ccall f_5968(C_word c,C_word *av) C_noret;
C_noret_decl(f_5970)
static void C_ccall f_5970(C_word c,C_word *av) C_noret;
C_noret_decl(f_5981)
static void C_ccall f_5981(C_word c,C_word *av) C_noret;
C_noret_decl(f_5990)
static void C_ccall f_5990(C_word c,C_word *av) C_noret;
C_noret_decl(f_5995)
static void C_ccall f_5995(C_word c,C_word *av) C_noret;
C_noret_decl(f_5999)
static void C_ccall f_5999(C_word c,C_word *av) C_noret;
C_noret_decl(f_6003)
static void C_ccall f_6003(C_word c,C_word *av) C_noret;
C_noret_decl(f_6006)
static void C_ccall f_6006(C_word c,C_word *av) C_noret;
C_noret_decl(f_6012)
static void C_ccall f_6012(C_word c,C_word *av) C_noret;
C_noret_decl(f_6020)
static void C_ccall f_6020(C_word c,C_word *av) C_noret;
C_noret_decl(f_6028)
static void C_ccall f_6028(C_word c,C_word *av) C_noret;
C_noret_decl(f_6030)
static void C_ccall f_6030(C_word c,C_word *av) C_noret;
C_noret_decl(f_6034)
static void C_ccall f_6034(C_word c,C_word *av) C_noret;
C_noret_decl(f_6037)
static void C_ccall f_6037(C_word c,C_word *av) C_noret;
C_noret_decl(f_6055)
static void C_ccall f_6055(C_word c,C_word *av) C_noret;
C_noret_decl(f_6059)
static void C_ccall f_6059(C_word c,C_word *av) C_noret;
C_noret_decl(f_6063)
static void C_ccall f_6063(C_word c,C_word *av) C_noret;
C_noret_decl(f_6067)
static void C_ccall f_6067(C_word c,C_word *av) C_noret;
C_noret_decl(f_6082)
static void C_ccall f_6082(C_word c,C_word *av) C_noret;
C_noret_decl(f_6086)
static void C_ccall f_6086(C_word c,C_word *av) C_noret;
C_noret_decl(f_6088)
static void C_fcall f_6088(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6142)
static void C_ccall f_6142(C_word c,C_word *av) C_noret;
C_noret_decl(f_6146)
static void C_ccall f_6146(C_word c,C_word *av) C_noret;
C_noret_decl(f_6150)
static void C_ccall f_6150(C_word c,C_word *av) C_noret;
C_noret_decl(f_6165)
static void C_ccall f_6165(C_word c,C_word *av) C_noret;
C_noret_decl(f_6168)
static void C_ccall f_6168(C_word c,C_word *av) C_noret;
C_noret_decl(f_6169)
static C_word C_fcall f_6169(C_word t0,C_word t1);
C_noret_decl(f_6188)
static void C_ccall f_6188(C_word c,C_word *av) C_noret;
C_noret_decl(f_6192)
static void C_ccall f_6192(C_word c,C_word *av) C_noret;
C_noret_decl(f_6196)
static void C_ccall f_6196(C_word c,C_word *av) C_noret;
C_noret_decl(f_6199)
static void C_ccall f_6199(C_word c,C_word *av) C_noret;
C_noret_decl(f_6205)
static void C_ccall f_6205(C_word c,C_word *av) C_noret;
C_noret_decl(f_6213)
static void C_ccall f_6213(C_word c,C_word *av) C_noret;
C_noret_decl(f_6221)
static void C_ccall f_6221(C_word c,C_word *av) C_noret;
C_noret_decl(f_6223)
static void C_ccall f_6223(C_word c,C_word *av) C_noret;
C_noret_decl(f_6227)
static void C_ccall f_6227(C_word c,C_word *av) C_noret;
C_noret_decl(f_6230)
static void C_ccall f_6230(C_word c,C_word *av) C_noret;
C_noret_decl(f_6233)
static C_word C_fcall f_6233(C_word t0,C_word t1);
C_noret_decl(f_6258)
static void C_ccall f_6258(C_word c,C_word *av) C_noret;
C_noret_decl(f_6260)
static void C_fcall f_6260(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6307)
static void C_ccall f_6307(C_word c,C_word *av) C_noret;
C_noret_decl(f_6310)
static void C_ccall f_6310(C_word c,C_word *av) C_noret;
C_noret_decl(f_6313)
static void C_ccall f_6313(C_word c,C_word *av) C_noret;
C_noret_decl(f_6316)
static void C_ccall f_6316(C_word c,C_word *av) C_noret;
C_noret_decl(f_6319)
static void C_ccall f_6319(C_word c,C_word *av) C_noret;
C_noret_decl(f_6326)
static void C_ccall f_6326(C_word c,C_word *av) C_noret;
C_noret_decl(f_6330)
static void C_ccall f_6330(C_word c,C_word *av) C_noret;
C_noret_decl(f_6334)
static void C_ccall f_6334(C_word c,C_word *av) C_noret;
C_noret_decl(f_6351)
static void C_ccall f_6351(C_word c,C_word *av) C_noret;
C_noret_decl(f_6373)
static void C_ccall f_6373(C_word c,C_word *av) C_noret;
C_noret_decl(f_6381)
static void C_ccall f_6381(C_word c,C_word *av) C_noret;
C_noret_decl(f_6400)
static void C_ccall f_6400(C_word c,C_word *av) C_noret;
C_noret_decl(f_6404)
static void C_ccall f_6404(C_word c,C_word *av) C_noret;
C_noret_decl(f_6409)
static void C_ccall f_6409(C_word c,C_word *av) C_noret;
C_noret_decl(f_6414)
static void C_ccall f_6414(C_word c,C_word *av) C_noret;
C_noret_decl(f_6420)
static void C_ccall f_6420(C_word c,C_word *av) C_noret;
C_noret_decl(f_6433)
static void C_ccall f_6433(C_word c,C_word *av) C_noret;
C_noret_decl(f_6437)
static void C_ccall f_6437(C_word c,C_word *av) C_noret;
C_noret_decl(f_6466)
static void C_ccall f_6466(C_word c,C_word *av) C_noret;
C_noret_decl(f_6478)
static void C_ccall f_6478(C_word c,C_word *av) C_noret;
C_noret_decl(f_6480)
static void C_ccall f_6480(C_word c,C_word *av) C_noret;
C_noret_decl(f_6494)
static void C_fcall f_6494(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6519)
static void C_ccall f_6519(C_word c,C_word *av) C_noret;
C_noret_decl(f_6535)
static void C_ccall f_6535(C_word c,C_word *av) C_noret;
C_noret_decl(f_6544)
static void C_ccall f_6544(C_word c,C_word *av) C_noret;
C_noret_decl(f_6547)
static void C_ccall f_6547(C_word c,C_word *av) C_noret;
C_noret_decl(f_6550)
static void C_ccall f_6550(C_word c,C_word *av) C_noret;
C_noret_decl(f_6553)
static void C_ccall f_6553(C_word c,C_word *av) C_noret;
C_noret_decl(f_6558)
static void C_ccall f_6558(C_word c,C_word *av) C_noret;
C_noret_decl(f_6562)
static void C_ccall f_6562(C_word c,C_word *av) C_noret;
C_noret_decl(f_6565)
static void C_ccall f_6565(C_word c,C_word *av) C_noret;
C_noret_decl(f_6568)
static void C_ccall f_6568(C_word c,C_word *av) C_noret;
C_noret_decl(f_6571)
static void C_ccall f_6571(C_word c,C_word *av) C_noret;
C_noret_decl(f_6575)
static void C_ccall f_6575(C_word c,C_word *av) C_noret;
C_noret_decl(f_6579)
static void C_ccall f_6579(C_word c,C_word *av) C_noret;
C_noret_decl(f_6583)
static void C_ccall f_6583(C_word c,C_word *av) C_noret;
C_noret_decl(f_6587)
static void C_ccall f_6587(C_word c,C_word *av) C_noret;
C_noret_decl(f_6590)
static void C_ccall f_6590(C_word c,C_word *av) C_noret;
C_noret_decl(f_6593)
static void C_ccall f_6593(C_word c,C_word *av) C_noret;
C_noret_decl(f_6596)
static void C_ccall f_6596(C_word c,C_word *av) C_noret;
C_noret_decl(f_6599)
static void C_ccall f_6599(C_word c,C_word *av) C_noret;
C_noret_decl(f_6614)
static void C_ccall f_6614(C_word c,C_word *av) C_noret;
C_noret_decl(f_6620)
static void C_ccall f_6620(C_word c,C_word *av) C_noret;
C_noret_decl(f_6630)
static void C_fcall f_6630(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6640)
static void C_ccall f_6640(C_word c,C_word *av) C_noret;
C_noret_decl(f_6643)
static void C_ccall f_6643(C_word c,C_word *av) C_noret;
C_noret_decl(f_6646)
static void C_ccall f_6646(C_word c,C_word *av) C_noret;
C_noret_decl(f_6647)
static void C_ccall f_6647(C_word c,C_word *av) C_noret;
C_noret_decl(f_6653)
static void C_fcall f_6653(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6676)
static void C_ccall f_6676(C_word c,C_word *av) C_noret;
C_noret_decl(f_6687)
static void C_ccall f_6687(C_word c,C_word *av) C_noret;
C_noret_decl(f_6691)
static void C_ccall f_6691(C_word c,C_word *av) C_noret;
C_noret_decl(f_6706)
static void C_ccall f_6706(C_word c,C_word *av) C_noret;
C_noret_decl(f_6710)
static void C_ccall f_6710(C_word c,C_word *av) C_noret;
C_noret_decl(f_6714)
static void C_ccall f_6714(C_word c,C_word *av) C_noret;
C_noret_decl(f_6717)
static void C_ccall f_6717(C_word c,C_word *av) C_noret;
C_noret_decl(f_6720)
static void C_ccall f_6720(C_word c,C_word *av) C_noret;
C_noret_decl(f_6723)
static void C_ccall f_6723(C_word c,C_word *av) C_noret;
C_noret_decl(f_6726)
static void C_ccall f_6726(C_word c,C_word *av) C_noret;
C_noret_decl(f_6729)
static void C_ccall f_6729(C_word c,C_word *av) C_noret;
C_noret_decl(f_6732)
static void C_ccall f_6732(C_word c,C_word *av) C_noret;
C_noret_decl(f_6735)
static void C_ccall f_6735(C_word c,C_word *av) C_noret;
C_noret_decl(f_6742)
static void C_ccall f_6742(C_word c,C_word *av) C_noret;
C_noret_decl(f_6749)
static void C_fcall f_6749(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6762)
static void C_fcall f_6762(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6773)
static C_word C_fcall f_6773(C_word t0);
C_noret_decl(f_6806)
static void C_fcall f_6806(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6831)
static void C_ccall f_6831(C_word c,C_word *av) C_noret;
C_noret_decl(f_6859)
static void C_ccall f_6859(C_word c,C_word *av) C_noret;
C_noret_decl(f_6893)
static void C_ccall f_6893(C_word c,C_word *av) C_noret;
C_noret_decl(f_6919)
static void C_ccall f_6919(C_word c,C_word *av) C_noret;
C_noret_decl(f_6940)
static void C_ccall f_6940(C_word c,C_word *av) C_noret;
C_noret_decl(f_6969)
static void C_fcall f_6969(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6981)
static void C_ccall f_6981(C_word c,C_word *av) C_noret;
C_noret_decl(f_7004)
static void C_ccall f_7004(C_word c,C_word *av) C_noret;
C_noret_decl(f_7017)
static void C_fcall f_7017(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7037)
static void C_ccall f_7037(C_word c,C_word *av) C_noret;
C_noret_decl(f_7063)
static void C_fcall f_7063(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7081)
static void C_ccall f_7081(C_word c,C_word *av) C_noret;
C_noret_decl(f_7093)
static void C_ccall f_7093(C_word c,C_word *av) C_noret;
C_noret_decl(f_7098)
static void C_ccall f_7098(C_word c,C_word *av) C_noret;
C_noret_decl(f_7106)
static void C_ccall f_7106(C_word c,C_word *av) C_noret;
C_noret_decl(f_7108)
static void C_ccall f_7108(C_word c,C_word *av) C_noret;
C_noret_decl(f_7289)
static void C_ccall f_7289(C_word c,C_word *av) C_noret;
C_noret_decl(f_7294)
static void C_ccall f_7294(C_word c,C_word *av) C_noret;
C_noret_decl(f_7302)
static void C_ccall f_7302(C_word c,C_word *av) C_noret;
C_noret_decl(f_7304)
static void C_ccall f_7304(C_word c,C_word *av) C_noret;
C_noret_decl(f_7310)
static void C_ccall f_7310(C_word c,C_word *av) C_noret;
C_noret_decl(f_7317)
static void C_ccall f_7317(C_word c,C_word *av) C_noret;
C_noret_decl(f_7343)
static void C_ccall f_7343(C_word c,C_word *av) C_noret;
C_noret_decl(f_7372)
static void C_fcall f_7372(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_7401)
static void C_ccall f_7401(C_word c,C_word *av) C_noret;
C_noret_decl(f_7418)
static C_word C_fcall f_7418(C_word t0,C_word t1);
C_noret_decl(f_7444)
static void C_fcall f_7444(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_7451)
static void C_ccall f_7451(C_word c,C_word *av) C_noret;
C_noret_decl(f_7460)
static void C_ccall f_7460(C_word c,C_word *av) C_noret;
C_noret_decl(f_7479)
static void C_ccall f_7479(C_word c,C_word *av) C_noret;
C_noret_decl(f_7486)
static void C_ccall f_7486(C_word c,C_word *av) C_noret;
C_noret_decl(f_7498)
static void C_ccall f_7498(C_word c,C_word *av) C_noret;
C_noret_decl(f_7499)
static void C_ccall f_7499(C_word c,C_word *av) C_noret;
C_noret_decl(f_7506)
static void C_ccall f_7506(C_word c,C_word *av) C_noret;
C_noret_decl(f_7513)
static void C_ccall f_7513(C_word c,C_word *av) C_noret;
C_noret_decl(f_7526)
static void C_ccall f_7526(C_word c,C_word *av) C_noret;
C_noret_decl(f_7529)
static void C_ccall f_7529(C_word c,C_word *av) C_noret;
C_noret_decl(f_7530)
static void C_ccall f_7530(C_word c,C_word *av) C_noret;
C_noret_decl(f_7537)
static void C_ccall f_7537(C_word c,C_word *av) C_noret;
C_noret_decl(f_7544)
static void C_ccall f_7544(C_word c,C_word *av) C_noret;
C_noret_decl(f_7548)
static void C_ccall f_7548(C_word c,C_word *av) C_noret;
C_noret_decl(f_7562)
static void C_ccall f_7562(C_word c,C_word *av) C_noret;
C_noret_decl(f_7565)
static void C_ccall f_7565(C_word c,C_word *av) C_noret;
C_noret_decl(f_7568)
static void C_ccall f_7568(C_word c,C_word *av) C_noret;
C_noret_decl(f_7569)
static void C_ccall f_7569(C_word c,C_word *av) C_noret;
C_noret_decl(f_7576)
static void C_ccall f_7576(C_word c,C_word *av) C_noret;
C_noret_decl(f_7583)
static void C_ccall f_7583(C_word c,C_word *av) C_noret;
C_noret_decl(f_7587)
static void C_ccall f_7587(C_word c,C_word *av) C_noret;
C_noret_decl(f_7591)
static void C_ccall f_7591(C_word c,C_word *av) C_noret;
C_noret_decl(f_7606)
static void C_ccall f_7606(C_word c,C_word *av) C_noret;
C_noret_decl(f_7609)
static void C_ccall f_7609(C_word c,C_word *av) C_noret;
C_noret_decl(f_7612)
static void C_ccall f_7612(C_word c,C_word *av) C_noret;
C_noret_decl(f_7615)
static void C_ccall f_7615(C_word c,C_word *av) C_noret;
C_noret_decl(f_7616)
static void C_ccall f_7616(C_word c,C_word *av) C_noret;
C_noret_decl(f_7623)
static void C_ccall f_7623(C_word c,C_word *av) C_noret;
C_noret_decl(f_7630)
static void C_ccall f_7630(C_word c,C_word *av) C_noret;
C_noret_decl(f_7634)
static void C_ccall f_7634(C_word c,C_word *av) C_noret;
C_noret_decl(f_7638)
static void C_ccall f_7638(C_word c,C_word *av) C_noret;
C_noret_decl(f_7642)
static void C_ccall f_7642(C_word c,C_word *av) C_noret;
C_noret_decl(f_7653)
static void C_fcall f_7653(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7663)
static void C_ccall f_7663(C_word c,C_word *av) C_noret;
C_noret_decl(f_7664)
static void C_ccall f_7664(C_word c,C_word *av) C_noret;
C_noret_decl(f_7675)
static void C_ccall f_7675(C_word c,C_word *av) C_noret;
C_noret_decl(f_7680)
static void C_fcall f_7680(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7690)
static void C_ccall f_7690(C_word c,C_word *av) C_noret;
C_noret_decl(f_7692)
static void C_fcall f_7692(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7717)
static void C_ccall f_7717(C_word c,C_word *av) C_noret;
C_noret_decl(f_7726)
static void C_fcall f_7726(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7751)
static void C_ccall f_7751(C_word c,C_word *av) C_noret;
C_noret_decl(f_7774)
static void C_ccall f_7774(C_word c,C_word *av) C_noret;
C_noret_decl(f_7793)
static void C_ccall f_7793(C_word c,C_word *av) C_noret;
C_noret_decl(f_7843)
static void C_ccall f_7843(C_word c,C_word *av) C_noret;
C_noret_decl(f_7847)
static void C_ccall f_7847(C_word c,C_word *av) C_noret;
C_noret_decl(f_7850)
static void C_ccall f_7850(C_word c,C_word *av) C_noret;
C_noret_decl(f_7855)
static void C_ccall f_7855(C_word c,C_word *av) C_noret;
C_noret_decl(f_7859)
static void C_ccall f_7859(C_word c,C_word *av) C_noret;
C_noret_decl(f_7862)
static void C_ccall f_7862(C_word c,C_word *av) C_noret;
C_noret_decl(f_7865)
static void C_ccall f_7865(C_word c,C_word *av) C_noret;
C_noret_decl(f_7869)
static void C_ccall f_7869(C_word c,C_word *av) C_noret;
C_noret_decl(f_7873)
static void C_ccall f_7873(C_word c,C_word *av) C_noret;
C_noret_decl(f_7877)
static void C_ccall f_7877(C_word c,C_word *av) C_noret;
C_noret_decl(f_7880)
static void C_ccall f_7880(C_word c,C_word *av) C_noret;
C_noret_decl(f_7883)
static void C_ccall f_7883(C_word c,C_word *av) C_noret;
C_noret_decl(f_7886)
static void C_ccall f_7886(C_word c,C_word *av) C_noret;
C_noret_decl(f_7898)
static void C_ccall f_7898(C_word c,C_word *av) C_noret;
C_noret_decl(f_7904)
static void C_ccall f_7904(C_word c,C_word *av) C_noret;
C_noret_decl(f_7908)
static void C_ccall f_7908(C_word c,C_word *av) C_noret;
C_noret_decl(f_7913)
static void C_ccall f_7913(C_word c,C_word *av) C_noret;
C_noret_decl(f_7917)
static void C_ccall f_7917(C_word c,C_word *av) C_noret;
C_noret_decl(f_7924)
static void C_ccall f_7924(C_word c,C_word *av) C_noret;
C_noret_decl(f_7928)
static void C_ccall f_7928(C_word c,C_word *av) C_noret;
C_noret_decl(f_7930)
static void C_ccall f_7930(C_word c,C_word *av) C_noret;
C_noret_decl(f_7934)
static void C_ccall f_7934(C_word c,C_word *av) C_noret;
C_noret_decl(f_7937)
static void C_ccall f_7937(C_word c,C_word *av) C_noret;
C_noret_decl(f_7940)
static void C_ccall f_7940(C_word c,C_word *av) C_noret;
C_noret_decl(f_7943)
static void C_ccall f_7943(C_word c,C_word *av) C_noret;
C_noret_decl(f_7946)
static void C_ccall f_7946(C_word c,C_word *av) C_noret;
C_noret_decl(f_7949)
static void C_ccall f_7949(C_word c,C_word *av) C_noret;
C_noret_decl(f_7956)
static void C_ccall f_7956(C_word c,C_word *av) C_noret;
C_noret_decl(f_7958)
static void C_ccall f_7958(C_word c,C_word *av) C_noret;
C_noret_decl(f_7966)
static void C_ccall f_7966(C_word c,C_word *av) C_noret;
C_noret_decl(f_7968)
static void C_ccall f_7968(C_word c,C_word *av) C_noret;
C_noret_decl(f_7975)
static void C_ccall f_7975(C_word c,C_word *av) C_noret;
C_noret_decl(f_7977)
static void C_ccall f_7977(C_word c,C_word *av) C_noret;
C_noret_decl(f_7980)
static void C_fcall f_7980(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7990)
static void C_fcall f_7990(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_8004)
static void C_ccall f_8004(C_word c,C_word *av) C_noret;
C_noret_decl(f_8023)
static void C_ccall f_8023(C_word c,C_word *av) C_noret;
C_noret_decl(f_8062)
static void C_ccall f_8062(C_word c,C_word *av) C_noret;
C_noret_decl(f_8066)
static void C_ccall f_8066(C_word c,C_word *av) C_noret;
C_noret_decl(f_8069)
static void C_ccall f_8069(C_word c,C_word *av) C_noret;
C_noret_decl(f_8072)
static void C_ccall f_8072(C_word c,C_word *av) C_noret;
C_noret_decl(f_8075)
static void C_ccall f_8075(C_word c,C_word *av) C_noret;
C_noret_decl(f_8078)
static void C_ccall f_8078(C_word c,C_word *av) C_noret;
C_noret_decl(f_8080)
static void C_fcall f_8080(C_word t0,C_word t1) C_noret;
C_noret_decl(f_8089)
static void C_fcall f_8089(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8120)
static void C_ccall f_8120(C_word c,C_word *av) C_noret;
C_noret_decl(f_8138)
static void C_ccall f_8138(C_word c,C_word *av) C_noret;
C_noret_decl(f_8142)
static void C_ccall f_8142(C_word c,C_word *av) C_noret;
C_noret_decl(f_8163)
static void C_ccall f_8163(C_word c,C_word *av) C_noret;
C_noret_decl(f_8167)
static void C_ccall f_8167(C_word c,C_word *av) C_noret;
C_noret_decl(f_8189)
static void C_ccall f_8189(C_word c,C_word *av) C_noret;
C_noret_decl(f_8566)
static void C_fcall f_8566(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8588)
static void C_ccall f_8588(C_word c,C_word *av) C_noret;
C_noret_decl(f_9479)
static void C_fcall f_9479(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9482)
static void C_ccall f_9482(C_word c,C_word *av) C_noret;
C_noret_decl(f_9496)
static void C_ccall f_9496(C_word c,C_word *av) C_noret;
C_noret_decl(f_9499)
static void C_fcall f_9499(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9501)
static void C_ccall f_9501(C_word c,C_word *av) C_noret;
C_noret_decl(f_9504)
static void C_ccall f_9504(C_word c,C_word *av) C_noret;
C_noret_decl(f_9511)
static void C_fcall f_9511(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9521)
static C_word C_fcall f_9521(C_word t0,C_word t1);
C_noret_decl(f_9546)
static void C_fcall f_9546(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9550)
static void C_ccall f_9550(C_word c,C_word *av) C_noret;
C_noret_decl(f_9563)
static void C_ccall f_9563(C_word c,C_word *av) C_noret;
C_noret_decl(f_9589)
static void C_ccall f_9589(C_word c,C_word *av) C_noret;
C_noret_decl(f_9593)
static void C_ccall f_9593(C_word c,C_word *av) C_noret;
C_noret_decl(f_9600)
static void C_ccall f_9600(C_word c,C_word *av) C_noret;
C_noret_decl(f_9605)
static void C_fcall f_9605(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9618)
static void C_ccall f_9618(C_word c,C_word *av) C_noret;
C_noret_decl(f_9687)
static void C_ccall f_9687(C_word c,C_word *av) C_noret;
C_noret_decl(f_9693)
static void C_fcall f_9693(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9701)
static void C_ccall f_9701(C_word c,C_word *av) C_noret;
C_noret_decl(f_9705)
static void C_ccall f_9705(C_word c,C_word *av) C_noret;
C_noret_decl(f_9707)
static void C_fcall f_9707(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_9745)
static void C_ccall f_9745(C_word c,C_word *av) C_noret;
C_noret_decl(f_9750)
static void C_fcall f_9750(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9754)
static void C_ccall f_9754(C_word c,C_word *av) C_noret;
C_noret_decl(f_9757)
static void C_ccall f_9757(C_word c,C_word *av) C_noret;
C_noret_decl(f_9773)
static void C_ccall f_9773(C_word c,C_word *av) C_noret;
C_noret_decl(f_9777)
static void C_ccall f_9777(C_word c,C_word *av) C_noret;
C_noret_decl(f_9781)
static void C_ccall f_9781(C_word c,C_word *av) C_noret;
C_noret_decl(f_9785)
static void C_ccall f_9785(C_word c,C_word *av) C_noret;
C_noret_decl(f_9789)
static void C_ccall f_9789(C_word c,C_word *av) C_noret;
C_noret_decl(f_9792)
static void C_ccall f_9792(C_word c,C_word *av) C_noret;
C_noret_decl(f_9795)
static void C_ccall f_9795(C_word c,C_word *av) C_noret;
C_noret_decl(f_9798)
static void C_ccall f_9798(C_word c,C_word *av) C_noret;
C_noret_decl(f_9803)
static void C_fcall f_9803(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9809)
static void C_ccall f_9809(C_word c,C_word *av) C_noret;
C_noret_decl(f_9818)
static void C_ccall f_9818(C_word c,C_word *av) C_noret;
C_noret_decl(f_9822)
static void C_ccall f_9822(C_word c,C_word *av) C_noret;
C_noret_decl(f_9827)
static void C_ccall f_9827(C_word c,C_word *av) C_noret;
C_noret_decl(f_9830)
static void C_ccall f_9830(C_word c,C_word *av) C_noret;
C_noret_decl(f_9834)
static void C_ccall f_9834(C_word c,C_word *av) C_noret;
C_noret_decl(f_9837)
static void C_ccall f_9837(C_word c,C_word *av) C_noret;
C_noret_decl(f_9840)
static void C_ccall f_9840(C_word c,C_word *av) C_noret;
C_noret_decl(f_9845)
static void C_fcall f_9845(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9855)
static void C_ccall f_9855(C_word c,C_word *av) C_noret;
C_noret_decl(f_9858)
static void C_ccall f_9858(C_word c,C_word *av) C_noret;
C_noret_decl(f_9865)
static void C_ccall f_9865(C_word c,C_word *av) C_noret;
C_noret_decl(f_9867)
static void C_ccall f_9867(C_word c,C_word *av) C_noret;
C_noret_decl(f_9874)
static void C_ccall f_9874(C_word c,C_word *av) C_noret;
C_noret_decl(f_9879)
static void C_ccall f_9879(C_word c,C_word *av) C_noret;
C_noret_decl(f_9885)
static void C_ccall f_9885(C_word c,C_word *av) C_noret;
C_noret_decl(f_9889)
static void C_ccall f_9889(C_word c,C_word *av) C_noret;
C_noret_decl(f_9896)
static void C_ccall f_9896(C_word c,C_word *av) C_noret;
C_noret_decl(f_9901)
static void C_ccall f_9901(C_word c,C_word *av) C_noret;
C_noret_decl(f_9910)
static void C_ccall f_9910(C_word c,C_word *av) C_noret;
C_noret_decl(f_9918)
static void C_fcall f_9918(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9928)
static void C_ccall f_9928(C_word c,C_word *av) C_noret;
C_noret_decl(f_9952)
static void C_ccall f_9952(C_word c,C_word *av) C_noret;
C_noret_decl(f_9956)
static void C_ccall f_9956(C_word c,C_word *av) C_noret;
C_noret_decl(f_9961)
static void C_ccall f_9961(C_word c,C_word *av) C_noret;
C_noret_decl(f_9970)
static void C_ccall f_9970(C_word c,C_word *av) C_noret;
C_noret_decl(f_9989)
static void C_ccall f_9989(C_word c,C_word *av) C_noret;
C_noret_decl(f_9992)
static void C_ccall f_9992(C_word c,C_word *av) C_noret;
C_noret_decl(f_9995)
static void C_ccall f_9995(C_word c,C_word *av) C_noret;
C_noret_decl(C_eval_toplevel)
C_externexport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;

/* from CHICKEN_get_error_message */
 void  CHICKEN_get_error_message(char *t0,int t1){
C_word x,s=0+3,*a=C_alloc(s);
C_callback_adjust_stack(a,s);
x=C_fix((C_word)t1);
C_save(x);
x=C_mpointer_or_false(&a,(void*)t0);
C_save(x);C_callback_wrapper((void *)f_11256,2);}

/* from CHICKEN_load */
 int  CHICKEN_load(char * t0){
C_word x,s=0+2+(t0==NULL?1:C_bytestowords(C_strlen(t0))),*a=C_alloc(s);
C_callback_adjust_stack(a,s);
x=C_mpointer(&a,(void*)t0);
C_save(x);
return C_truep(C_callback_wrapper((void *)f_11241,1));}

/* from CHICKEN_read */
 int  CHICKEN_read(char * t0,C_word *t1){
C_word x,s=0+2+(t0==NULL?1:C_bytestowords(C_strlen(t0)))+3,*a=C_alloc(s);
C_callback_adjust_stack(a,s);
x=C_mpointer_or_false(&a,(void*)t1);
C_save(x);
x=C_mpointer(&a,(void*)t0);
C_save(x);
return C_truep(C_callback_wrapper((void *)f_11219,2));}

/* from CHICKEN_apply_to_string */
 int  CHICKEN_apply_to_string(C_word t0,C_word t1,char *t2,int t3){
C_word x,s=0+3,*a=C_alloc(s);
C_callback_adjust_stack(a,s);
x=C_fix((C_word)t3);
C_save(x);
x=C_mpointer_or_false(&a,(void*)t2);
C_save(x);
x=((C_word)t1);
C_save(x);
x=((C_word)t0);
C_save(x);
return C_truep(C_callback_wrapper((void *)f_11193,4));}

/* from CHICKEN_apply */
 int  CHICKEN_apply(C_word t0,C_word t1,C_word *t2){
C_word x,s=0+3,*a=C_alloc(s);
C_callback_adjust_stack(a,s);
x=C_mpointer_or_false(&a,(void*)t2);
C_save(x);
x=((C_word)t1);
C_save(x);
x=((C_word)t0);
C_save(x);
return C_truep(C_callback_wrapper((void *)f_11177,3));}

/* from CHICKEN_eval_string_to_string */
 int  CHICKEN_eval_string_to_string(char * t0,char *t1,int t2){
C_word x,s=0+2+(t0==NULL?1:C_bytestowords(C_strlen(t0)))+3,*a=C_alloc(s);
C_callback_adjust_stack(a,s);
x=C_fix((C_word)t2);
C_save(x);
x=C_mpointer_or_false(&a,(void*)t1);
C_save(x);
x=C_mpointer(&a,(void*)t0);
C_save(x);
return C_truep(C_callback_wrapper((void *)f_11140,3));}

/* from CHICKEN_eval_to_string */
 int  CHICKEN_eval_to_string(C_word t0,char *t1,int t2){
C_word x,s=0+3,*a=C_alloc(s);
C_callback_adjust_stack(a,s);
x=C_fix((C_word)t2);
C_save(x);
x=C_mpointer_or_false(&a,(void*)t1);
C_save(x);
x=((C_word)t0);
C_save(x);
return C_truep(C_callback_wrapper((void *)f_11114,3));}

/* from CHICKEN_eval_string */
 int  CHICKEN_eval_string(char * t0,C_word *t1){
C_word x,s=0+2+(t0==NULL?1:C_bytestowords(C_strlen(t0)))+3,*a=C_alloc(s);
C_callback_adjust_stack(a,s);
x=C_mpointer_or_false(&a,(void*)t1);
C_save(x);
x=C_mpointer(&a,(void*)t0);
C_save(x);
return C_truep(C_callback_wrapper((void *)f_11075,2));}

/* from CHICKEN_eval */
 int  CHICKEN_eval(C_word t0,C_word *t1){
C_word x,s=0+3,*a=C_alloc(s);
C_callback_adjust_stack(a,s);
x=C_mpointer_or_false(&a,(void*)t1);
C_save(x);
x=((C_word)t0);
C_save(x);
return C_truep(C_callback_wrapper((void *)f_11059,2));}

/* from CHICKEN_yield */
 int  CHICKEN_yield(){
C_word x,s=0,*a=C_stack_pointer;
C_callback_adjust_stack(a,s);
return C_truep(C_callback_wrapper((void *)f_11047,0));}

C_noret_decl(trf_10025)
static void C_ccall trf_10025(C_word c,C_word *av) C_noret;
static void C_ccall trf_10025(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_10025(t0,t1);}

C_noret_decl(trf_10170)
static void C_ccall trf_10170(C_word c,C_word *av) C_noret;
static void C_ccall trf_10170(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10170(t0,t1,t2);}

C_noret_decl(trf_10189)
static void C_ccall trf_10189(C_word c,C_word *av) C_noret;
static void C_ccall trf_10189(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_10189(t0,t1);}

C_noret_decl(trf_10200)
static void C_ccall trf_10200(C_word c,C_word *av) C_noret;
static void C_ccall trf_10200(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10200(t0,t1,t2);}

C_noret_decl(trf_10337)
static void C_ccall trf_10337(C_word c,C_word *av) C_noret;
static void C_ccall trf_10337(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10337(t0,t1,t2,t3);}

C_noret_decl(trf_10378)
static void C_ccall trf_10378(C_word c,C_word *av) C_noret;
static void C_ccall trf_10378(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_10378(t0,t1);}

C_noret_decl(trf_10443)
static void C_ccall trf_10443(C_word c,C_word *av) C_noret;
static void C_ccall trf_10443(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10443(t0,t1,t2);}

C_noret_decl(trf_10488)
static void C_ccall trf_10488(C_word c,C_word *av) C_noret;
static void C_ccall trf_10488(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10488(t0,t1,t2);}

C_noret_decl(trf_10592)
static void C_ccall trf_10592(C_word c,C_word *av) C_noret;
static void C_ccall trf_10592(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10592(t0,t1,t2);}

C_noret_decl(trf_10626)
static void C_ccall trf_10626(C_word c,C_word *av) C_noret;
static void C_ccall trf_10626(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10626(t0,t1,t2);}

C_noret_decl(trf_10691)
static void C_ccall trf_10691(C_word c,C_word *av) C_noret;
static void C_ccall trf_10691(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10691(t0,t1,t2);}

C_noret_decl(trf_10850)
static void C_ccall trf_10850(C_word c,C_word *av) C_noret;
static void C_ccall trf_10850(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10850(t0,t1,t2,t3);}

C_noret_decl(trf_10883)
static void C_ccall trf_10883(C_word c,C_word *av) C_noret;
static void C_ccall trf_10883(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10883(t0,t1,t2);}

C_noret_decl(trf_10934)
static void C_ccall trf_10934(C_word c,C_word *av) C_noret;
static void C_ccall trf_10934(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10934(t0,t1,t2);}

C_noret_decl(trf_10979)
static void C_ccall trf_10979(C_word c,C_word *av) C_noret;
static void C_ccall trf_10979(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_10979(t0,t1);}

C_noret_decl(trf_11038)
static void C_ccall trf_11038(C_word c,C_word *av) C_noret;
static void C_ccall trf_11038(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11038(t0,t1,t2);}

C_noret_decl(trf_11279)
static void C_ccall trf_11279(C_word c,C_word *av) C_noret;
static void C_ccall trf_11279(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11279(t0,t1,t2);}

C_noret_decl(trf_11433)
static void C_ccall trf_11433(C_word c,C_word *av) C_noret;
static void C_ccall trf_11433(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_11433(t0,t1);}

C_noret_decl(trf_11468)
static void C_ccall trf_11468(C_word c,C_word *av) C_noret;
static void C_ccall trf_11468(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_11468(t0,t1);}

C_noret_decl(trf_3576)
static void C_ccall trf_3576(C_word c,C_word *av) C_noret;
static void C_ccall trf_3576(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3576(t0,t1,t2,t3);}

C_noret_decl(trf_3603)
static void C_ccall trf_3603(C_word c,C_word *av) C_noret;
static void C_ccall trf_3603(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3603(t0,t1,t2,t3);}

C_noret_decl(trf_3616)
static void C_ccall trf_3616(C_word c,C_word *av) C_noret;
static void C_ccall trf_3616(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3616(t0,t1);}

C_noret_decl(trf_3638)
static void C_ccall trf_3638(C_word c,C_word *av) C_noret;
static void C_ccall trf_3638(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3638(t0,t1,t2);}

C_noret_decl(trf_3672)
static void C_ccall trf_3672(C_word c,C_word *av) C_noret;
static void C_ccall trf_3672(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3672(t0,t1,t2,t3);}

C_noret_decl(trf_3684)
static void C_ccall trf_3684(C_word c,C_word *av) C_noret;
static void C_ccall trf_3684(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3684(t0,t1,t2,t3);}

C_noret_decl(trf_3701)
static void C_ccall trf_3701(C_word c,C_word *av) C_noret;
static void C_ccall trf_3701(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3701(t0,t1,t2);}

C_noret_decl(trf_3775)
static void C_ccall trf_3775(C_word c,C_word *av) C_noret;
static void C_ccall trf_3775(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3775(t0,t1,t2,t3);}

C_noret_decl(trf_3792)
static void C_ccall trf_3792(C_word c,C_word *av) C_noret;
static void C_ccall trf_3792(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3792(t0,t1,t2);}

C_noret_decl(trf_3825)
static void C_ccall trf_3825(C_word c,C_word *av) C_noret;
static void C_ccall trf_3825(C_word c,C_word *av){
C_word t0=av[7];
C_word t1=av[6];
C_word t2=av[5];
C_word t3=av[4];
C_word t4=av[3];
C_word t5=av[2];
C_word t6=av[1];
C_word t7=av[0];
f_3825(t0,t1,t2,t3,t4,t5,t6,t7);}

C_noret_decl(trf_3864)
static void C_ccall trf_3864(C_word c,C_word *av) C_noret;
static void C_ccall trf_3864(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3864(t0,t1);}

C_noret_decl(trf_3891)
static void C_ccall trf_3891(C_word c,C_word *av) C_noret;
static void C_ccall trf_3891(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3891(t0,t1);}

C_noret_decl(trf_4861)
static void C_ccall trf_4861(C_word c,C_word *av) C_noret;
static void C_ccall trf_4861(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4861(t0,t1,t2);}

C_noret_decl(trf_4891)
static void C_ccall trf_4891(C_word c,C_word *av) C_noret;
static void C_ccall trf_4891(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_4891(t0,t1,t2,t3);}

C_noret_decl(trf_4921)
static void C_ccall trf_4921(C_word c,C_word *av) C_noret;
static void C_ccall trf_4921(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4921(t0,t1,t2);}

C_noret_decl(trf_5012)
static void C_ccall trf_5012(C_word c,C_word *av) C_noret;
static void C_ccall trf_5012(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5012(t0,t1,t2);}

C_noret_decl(trf_5046)
static void C_ccall trf_5046(C_word c,C_word *av) C_noret;
static void C_ccall trf_5046(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5046(t0,t1,t2);}

C_noret_decl(trf_5157)
static void C_ccall trf_5157(C_word c,C_word *av) C_noret;
static void C_ccall trf_5157(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5157(t0,t1,t2);}

C_noret_decl(trf_5191)
static void C_ccall trf_5191(C_word c,C_word *av) C_noret;
static void C_ccall trf_5191(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5191(t0,t1,t2);}

C_noret_decl(trf_5333)
static void C_ccall trf_5333(C_word c,C_word *av) C_noret;
static void C_ccall trf_5333(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_5333(t0,t1,t2,t3);}

C_noret_decl(trf_5381)
static void C_ccall trf_5381(C_word c,C_word *av) C_noret;
static void C_ccall trf_5381(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_5381(t0,t1,t2,t3);}

C_noret_decl(trf_5429)
static void C_ccall trf_5429(C_word c,C_word *av) C_noret;
static void C_ccall trf_5429(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5429(t0,t1,t2);}

C_noret_decl(trf_5463)
static void C_ccall trf_5463(C_word c,C_word *av) C_noret;
static void C_ccall trf_5463(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5463(t0,t1,t2);}

C_noret_decl(trf_5497)
static void C_ccall trf_5497(C_word c,C_word *av) C_noret;
static void C_ccall trf_5497(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5497(t0,t1,t2);}

C_noret_decl(trf_5920)
static void C_ccall trf_5920(C_word c,C_word *av) C_noret;
static void C_ccall trf_5920(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5920(t0,t1,t2);}

C_noret_decl(trf_6088)
static void C_ccall trf_6088(C_word c,C_word *av) C_noret;
static void C_ccall trf_6088(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6088(t0,t1,t2);}

C_noret_decl(trf_6260)
static void C_ccall trf_6260(C_word c,C_word *av) C_noret;
static void C_ccall trf_6260(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6260(t0,t1,t2);}

C_noret_decl(trf_6494)
static void C_ccall trf_6494(C_word c,C_word *av) C_noret;
static void C_ccall trf_6494(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6494(t0,t1,t2);}

C_noret_decl(trf_6630)
static void C_ccall trf_6630(C_word c,C_word *av) C_noret;
static void C_ccall trf_6630(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6630(t0,t1,t2,t3);}

C_noret_decl(trf_6653)
static void C_ccall trf_6653(C_word c,C_word *av) C_noret;
static void C_ccall trf_6653(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6653(t0,t1,t2);}

C_noret_decl(trf_6749)
static void C_ccall trf_6749(C_word c,C_word *av) C_noret;
static void C_ccall trf_6749(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6749(t0,t1,t2);}

C_noret_decl(trf_6762)
static void C_ccall trf_6762(C_word c,C_word *av) C_noret;
static void C_ccall trf_6762(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6762(t0,t1);}

C_noret_decl(trf_6806)
static void C_ccall trf_6806(C_word c,C_word *av) C_noret;
static void C_ccall trf_6806(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6806(t0,t1,t2);}

C_noret_decl(trf_6969)
static void C_ccall trf_6969(C_word c,C_word *av) C_noret;
static void C_ccall trf_6969(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6969(t0,t1);}

C_noret_decl(trf_7017)
static void C_ccall trf_7017(C_word c,C_word *av) C_noret;
static void C_ccall trf_7017(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7017(t0,t1);}

C_noret_decl(trf_7063)
static void C_ccall trf_7063(C_word c,C_word *av) C_noret;
static void C_ccall trf_7063(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7063(t0,t1,t2);}

C_noret_decl(trf_7372)
static void C_ccall trf_7372(C_word c,C_word *av) C_noret;
static void C_ccall trf_7372(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_7372(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_7444)
static void C_ccall trf_7444(C_word c,C_word *av) C_noret;
static void C_ccall trf_7444(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_7444(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_7653)
static void C_ccall trf_7653(C_word c,C_word *av) C_noret;
static void C_ccall trf_7653(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7653(t0,t1,t2);}

C_noret_decl(trf_7680)
static void C_ccall trf_7680(C_word c,C_word *av) C_noret;
static void C_ccall trf_7680(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7680(t0,t1,t2);}

C_noret_decl(trf_7692)
static void C_ccall trf_7692(C_word c,C_word *av) C_noret;
static void C_ccall trf_7692(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7692(t0,t1,t2);}

C_noret_decl(trf_7726)
static void C_ccall trf_7726(C_word c,C_word *av) C_noret;
static void C_ccall trf_7726(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7726(t0,t1,t2);}

C_noret_decl(trf_7980)
static void C_ccall trf_7980(C_word c,C_word *av) C_noret;
static void C_ccall trf_7980(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7980(t0,t1);}

C_noret_decl(trf_7990)
static void C_ccall trf_7990(C_word c,C_word *av) C_noret;
static void C_ccall trf_7990(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_7990(t0,t1,t2,t3,t4);}

C_noret_decl(trf_8080)
static void C_ccall trf_8080(C_word c,C_word *av) C_noret;
static void C_ccall trf_8080(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_8080(t0,t1);}

C_noret_decl(trf_8089)
static void C_ccall trf_8089(C_word c,C_word *av) C_noret;
static void C_ccall trf_8089(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8089(t0,t1,t2);}

C_noret_decl(trf_8566)
static void C_ccall trf_8566(C_word c,C_word *av) C_noret;
static void C_ccall trf_8566(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8566(t0,t1,t2);}

C_noret_decl(trf_9479)
static void C_ccall trf_9479(C_word c,C_word *av) C_noret;
static void C_ccall trf_9479(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9479(t0,t1);}

C_noret_decl(trf_9499)
static void C_ccall trf_9499(C_word c,C_word *av) C_noret;
static void C_ccall trf_9499(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9499(t0,t1);}

C_noret_decl(trf_9511)
static void C_ccall trf_9511(C_word c,C_word *av) C_noret;
static void C_ccall trf_9511(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9511(t0,t1);}

C_noret_decl(trf_9546)
static void C_ccall trf_9546(C_word c,C_word *av) C_noret;
static void C_ccall trf_9546(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9546(t0,t1,t2);}

C_noret_decl(trf_9605)
static void C_ccall trf_9605(C_word c,C_word *av) C_noret;
static void C_ccall trf_9605(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9605(t0,t1,t2);}

C_noret_decl(trf_9693)
static void C_ccall trf_9693(C_word c,C_word *av) C_noret;
static void C_ccall trf_9693(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9693(t0,t1,t2);}

C_noret_decl(trf_9707)
static void C_ccall trf_9707(C_word c,C_word *av) C_noret;
static void C_ccall trf_9707(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_9707(t0,t1,t2,t3,t4);}

C_noret_decl(trf_9750)
static void C_ccall trf_9750(C_word c,C_word *av) C_noret;
static void C_ccall trf_9750(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9750(t0,t1,t2);}

C_noret_decl(trf_9803)
static void C_ccall trf_9803(C_word c,C_word *av) C_noret;
static void C_ccall trf_9803(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9803(t0,t1);}

C_noret_decl(trf_9845)
static void C_ccall trf_9845(C_word c,C_word *av) C_noret;
static void C_ccall trf_9845(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9845(t0,t1,t2);}

C_noret_decl(trf_9918)
static void C_ccall trf_9918(C_word c,C_word *av) C_noret;
static void C_ccall trf_9918(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9918(t0,t1,t2);}

/* k9999 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10001(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_10001,c,av);}
a=C_alloc(4);
t2=(C_truep(t1)?((C_word*)((C_word*)t0)[2])[1]:C_SCHEME_FALSE);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9989,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1074: display */
t4=*((C_word*)lf[250]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[252];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_9792(2,av2);}}}

/* k10002 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10004(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_10004,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_9789(2,av2);}}
else{
t2=C_i_stringp(((C_word*)t0)[3]);
if(C_truep(C_i_not(t2))){
/* eval.scm:1064: ##sys#signal-hook */
t3=*((C_word*)lf[223]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[253];
av2[3]=lf[235];
av2[4]=lf[254];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10019,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1065: ##sys#file-exists? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[257]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[257]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[235];
tp(6,av2);}}}}

/* k10017 in k10002 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10019(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_10019,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
f_9789(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10022,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1066: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[228]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[228]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=*((C_word*)lf[201]+1);
tp(4,av2);}}}

/* k10020 in k10017 in k10002 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10022(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_10022,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10025,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)((C_word*)t0)[4])[1])){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10049,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1067: ##sys#file-exists? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[257]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[257]+1);
av2[1]=t3;
av2[2]=t1;
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[235];
tp(6,av2);}}
else{
t3=t2;
f_10025(t3,C_SCHEME_FALSE);}}

/* k10023 in k10020 in k10017 in k10002 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_fcall f_10025(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_10025,2,t0,t1);}
a=C_alloc(4);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=t1;
f_9789(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10031,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1068: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[228]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[228]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[198];
tp(4,av2);}}}

/* k10029 in k10023 in k10020 in k10017 in k10002 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_10031(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_10031,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10043,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1069: ##sys#file-exists? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[257]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[257]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[235];
tp(6,av2);}}

/* k10041 in k10029 in k10023 in k10020 in k10017 in k10002 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_ccall f_10043(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_10043,c,av);}
if(C_truep(t1)){
if(C_truep(((C_word*)t0)[2])){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
f_9789(2,av2);}}
else{
/* eval.scm:1071: ##sys#signal-hook */
t2=*((C_word*)lf[223]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[255];
av2[3]=lf[235];
av2[4]=lf[256];
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}
else{
/* eval.scm:1071: ##sys#signal-hook */
t2=*((C_word*)lf[223]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[255];
av2[3]=lf[235];
av2[4]=lf[256];
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}

/* k10047 in k10020 in k10017 in k10002 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_10049(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10049,c,av);}
t2=((C_word*)t0)[2];
f_10025(t2,(C_truep(t1)?((C_word*)t0)[3]:C_SCHEME_FALSE));}

/* scheme#load in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_10109(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10109,c,av);}
if(C_truep(C_rest_nullp(c,3))){
/* eval.scm:1120: load/internal */
t3=lf[233];
f_9707(t3,t1,t2,C_SCHEME_FALSE,C_SCHEME_END_OF_LIST);}
else{
/* eval.scm:1120: load/internal */
t3=lf[233];
f_9707(t3,t1,t2,C_get_rest_arg(c,3,av,3,t0),C_SCHEME_END_OF_LIST);}}

/* chicken.load#load-relative in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_10124(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_10124,c,av);}
a=C_alloc(4);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10131,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1123: make-relative-pathname */
f_9546(t5,*((C_word*)lf[215]+1),t2);}

/* k10129 in chicken.load#load-relative in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_10131(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10131,c,av);}
/* eval.scm:1124: load/internal */
t2=lf[233];
f_9707(t2,((C_word*)t0)[2],t1,((C_word*)t0)[3],C_SCHEME_END_OF_LIST);}

/* chicken.load#load-noisily in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_10142(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +8,c,4)))){
C_save_and_reclaim((void*)f_10142,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+8);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10146,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10163,a[2]=((C_word)li196),tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1126: ##sys#get-keyword */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[264]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[264]+1);
av2[1]=t4;
av2[2]=lf[267];
av2[3]=t3;
av2[4]=t5;
tp(5,av2);}}

/* k10144 in chicken.load#load-noisily in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_10146(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_10146,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10149,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10160,a[2]=((C_word)li195),tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1126: ##sys#get-keyword */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[264]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[264]+1);
av2[1]=t2;
av2[2]=lf[266];
av2[3]=((C_word*)t0)[4];
av2[4]=t3;
tp(5,av2);}}

/* k10147 in k10144 in chicken.load#load-noisily in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10149(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_10149,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10152,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10157,a[2]=((C_word)li194),tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1126: ##sys#get-keyword */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[264]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[264]+1);
av2[1]=t2;
av2[2]=lf[265];
av2[3]=((C_word*)t0)[5];
av2[4]=t3;
tp(5,av2);}}

/* k10150 in k10147 in k10144 in chicken.load#load-noisily in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10152(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_10152,c,av);}
a=C_alloc(9);
/* eval.scm:1127: load/internal */
t2=lf[233];
f_9707(t2,((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4],C_a_i_list(&a,3,C_SCHEME_TRUE,((C_word*)t0)[5],t1));}

/* a10156 in k10147 in k10144 in chicken.load#load-noisily in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10157(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10157,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a10159 in k10144 in chicken.load#load-noisily in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10160(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10160,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a10162 in chicken.load#load-noisily in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_10163(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10163,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_10168(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_10168,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10170,a[2]=t1,a[3]=((C_word)li198),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10177,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=lf[203];
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11271,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11279,a[2]=t6,a[3]=t11,a[4]=t2,a[5]=t7,a[6]=((C_word)li259),tmp=(C_word)a,a+=7,tmp));
t13=((C_word*)t11)[1];
f_11279(t13,t9,lf[203]);}

/* complete in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_fcall f_10170(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_10170,3,t0,t1,t2);}
t3=*((C_word*)lf[228]+1);
/* eval.scm:1138: g2440 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[228]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[228]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=((C_word*)t0)[2];
tp(4,av2);}}

/* k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_10177(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(75,c,6)))){
C_save_and_reclaim((void *)f_10177,c,av);}
a=C_alloc(75);
t2=C_mutate((C_word*)lf[268]+1 /* (set! chicken.load#dynamic-load-libraries ...) */,t1);
t3=C_mutate((C_word*)lf[269]+1 /* (set! chicken.load#load-unit ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10179,a[2]=((C_word)li200),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[275]+1 /* (set! chicken.load#load-library ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10270,a[2]=((C_word)li201),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[91]+1 /* (set! ##sys#include-forms-from-file ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10297,a[2]=((C_word)li207),tmp=(C_word)a,a+=3,tmp));
t6=C_set_block_item(lf[283] /* ##sys#setup-mode */,0,C_SCHEME_FALSE);
t7=C_mutate(&lf[284] /* (set! chicken.load#file-exists? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10378,a[2]=((C_word)li208),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[285]+1 /* (set! chicken.load#find-file ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10387,a[2]=((C_word)li209),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[287]+1 /* (set! chicken.load#find-dynamic-extension ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10434,a[2]=((C_word)li212),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[114]+1 /* (set! chicken.load#load-extension ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10535,a[2]=((C_word)li214),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[295]+1 /* (set! chicken.load#require ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10607,a[2]=((C_word)li217),tmp=(C_word)a,a+=3,tmp));
t12=C_mutate((C_word*)lf[297]+1 /* (set! chicken.load#provide ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10672,a[2]=((C_word)li220),tmp=(C_word)a,a+=3,tmp));
t13=C_mutate((C_word*)lf[299]+1 /* (set! chicken.load#provided? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10737,a[2]=((C_word)li223),tmp=(C_word)a,a+=3,tmp));
t14=C_mutate((C_word*)lf[269]+1 /* (set! chicken.load#load-unit ...) */,*((C_word*)lf[269]+1));
t15=C_mutate((C_word*)lf[114]+1 /* (set! chicken.load#load-extension ...) */,*((C_word*)lf[114]+1));
t16=C_mutate((C_word*)lf[285]+1 /* (set! chicken.load#find-file ...) */,*((C_word*)lf[285]+1));
t17=C_mutate((C_word*)lf[287]+1 /* (set! chicken.load#find-dynamic-extension ...) */,*((C_word*)lf[287]+1));
t18=C_mutate((C_word*)lf[116]+1 /* (set! ##sys#process-require ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10778,a[2]=((C_word)li224),tmp=(C_word)a,a+=3,tmp));
t19=C_mutate((C_word*)lf[282]+1 /* (set! ##sys#resolve-include-filename ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10847,a[2]=((C_word)li228),tmp=(C_word)a,a+=3,tmp));
t20=lf[303] /* last-error */ =C_SCHEME_FALSE;;
t21=C_mutate(&lf[304] /* (set! run-safe ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10979,a[2]=((C_word)li236),tmp=(C_word)a,a+=3,tmp));
t22=C_mutate(&lf[308] /* (set! store-result ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11038,a[2]=((C_word)li237),tmp=(C_word)a,a+=3,tmp));
t23=C_mutate(&lf[310] /* (set! CHICKEN_yield ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11047,a[2]=((C_word)li239),tmp=(C_word)a,a+=3,tmp));
t24=C_mutate(&lf[312] /* (set! CHICKEN_eval ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11059,a[2]=((C_word)li241),tmp=(C_word)a,a+=3,tmp));
t25=C_mutate(&lf[313] /* (set! CHICKEN_eval_string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11075,a[2]=((C_word)li243),tmp=(C_word)a,a+=3,tmp));
t26=C_mutate(&lf[316] /* (set! store-string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11101,a[2]=((C_word)li244),tmp=(C_word)a,a+=3,tmp));
t27=C_mutate(&lf[318] /* (set! CHICKEN_eval_to_string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11114,a[2]=((C_word)li246),tmp=(C_word)a,a+=3,tmp));
t28=C_mutate(&lf[319] /* (set! CHICKEN_eval_string_to_string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11140,a[2]=((C_word)li248),tmp=(C_word)a,a+=3,tmp));
t29=C_mutate(&lf[320] /* (set! CHICKEN_apply ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11177,a[2]=((C_word)li250),tmp=(C_word)a,a+=3,tmp));
t30=C_mutate(&lf[321] /* (set! CHICKEN_apply_to_string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11193,a[2]=((C_word)li252),tmp=(C_word)a,a+=3,tmp));
t31=C_mutate(&lf[322] /* (set! CHICKEN_read ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11219,a[2]=((C_word)li254),tmp=(C_word)a,a+=3,tmp));
t32=C_mutate(&lf[323] /* (set! CHICKEN_load ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11241,a[2]=((C_word)li256),tmp=(C_word)a,a+=3,tmp));
t33=C_mutate(&lf[324] /* (set! CHICKEN_get_error_message ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11256,a[2]=((C_word)li257),tmp=(C_word)a,a+=3,tmp));
t34=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t34;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t34+1)))(2,av2);}}

/* chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10179(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_10179,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10186,a[2]=t1,a[3]=t4,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:1146: ##sys#provided? */
t6=*((C_word*)lf[204]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k10184 in chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10186(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_10186,c,av);}
a=C_alloc(8);
if(C_truep(t1)){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10189,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[5])){
t3=t2;
f_10189(t3,C_a_i_list(&a,1,((C_word*)t0)[5]));}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10260,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1150: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[228]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[228]+1);
av2[1]=t3;
av2[2]=C_slot(((C_word*)t0)[4],C_fix(1));
av2[3]=lf[200];
tp(4,av2);}}}}

/* k10187 in k10184 in chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_fcall f_10189(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_10189,2,t0,t1);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10192,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:1153: c-toplevel */
f_9693(t2,((C_word*)t0)[3],((C_word*)t0)[2]);}

/* k10190 in k10187 in k10184 in chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_10192(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_10192,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10195,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10241,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1154: load-verbose */
t4=*((C_word*)lf[214]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k10193 in k10190 in k10187 in k10184 in chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_10195(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_10195,c,av);}
a=C_alloc(9);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10200,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=((C_word*)t0)[4],a[6]=((C_word)li199),tmp=(C_word)a,a+=7,tmp));
t5=((C_word*)t3)[1];
f_10200(t5,((C_word*)t0)[5],((C_word*)t0)[6]);}

/* loop in k10193 in k10190 in k10187 in k10184 in chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_fcall f_10200(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_10200,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10214,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[245]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_dlerror);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10223,a[2]=t1,a[3]=((C_word*)t0)[4],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10234,a[2]=t3,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1161: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[227]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[227]+1);
av2[1]=t4;
av2[2]=C_slot(t2,C_fix(0));
av2[3]=lf[272];
tp(4,av2);}}}

/* k10212 in loop in k10193 in k10190 in k10187 in k10184 in chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in ... */
static void C_ccall f_10214(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_10214,c,av);}
if(C_truep(t1)){
/* eval.scm:1160: ##sys#error */
t2=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[270];
av2[4]=((C_word*)t0)[4];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}
else{
/* eval.scm:1160: ##sys#error */
t2=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[270];
av2[4]=((C_word*)t0)[4];
av2[5]=lf[271];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}

/* k10221 in loop in k10193 in k10190 in k10187 in k10184 in chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in ... */
static void C_ccall f_10223(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10223,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* eval.scm:1164: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_10200(t2,((C_word*)t0)[2],C_slot(((C_word*)t0)[4],C_fix(1)));}}

/* k10232 in loop in k10193 in k10190 in k10187 in k10184 in chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in ... */
static void C_ccall f_10234(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10234,c,av);}
/* eval.scm:1161: ##sys#dload */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[234]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[234]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k10239 in k10190 in k10187 in k10184 in chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_10241(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_10241,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10244,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1155: scheme#display */
t3=*((C_word*)lf[250]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[274];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_10195(2,av2);}}}

/* k10242 in k10239 in k10190 in k10187 in k10184 in chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_ccall f_10244(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10244,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10247,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1156: scheme#display */
t3=*((C_word*)lf[250]+1);{
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

/* k10245 in k10242 in k10239 in k10190 in k10187 in k10184 in chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in ... */
static void C_ccall f_10247(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10247,c,av);}
/* eval.scm:1157: scheme#display */
t2=*((C_word*)lf[250]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[273];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k10258 in k10184 in chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10260(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_10260,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10264,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1151: dynamic-load-libraries */
t3=*((C_word*)lf[268]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k10262 in k10258 in k10184 in chicken.load#load-unit in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_10264(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_10264,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];
f_10189(t2,C_a_i_cons(&a,2,((C_word*)t0)[3],t1));}

/* chicken.load#load-library in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10270(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10270,c,av);}
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_i_check_symbol_2(t2,lf[272]);
if(C_truep(C_i_not(t4))){
/* eval.scm:1169: load-unit */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[269]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[269]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=t4;
av2[4]=lf[272];
tp(5,av2);}}
else{
t6=C_i_check_string_2(t4,lf[272]);
/* eval.scm:1169: load-unit */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[269]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[269]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=t4;
av2[4]=lf[272];
tp(5,av2);}}}

/* ##sys#include-forms-from-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10297(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_10297,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10301,a[2]=t4,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1175: ##sys#resolve-include-filename */
t6=*((C_word*)lf[282]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
av2[5]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(6,av2);}}

/* k10299 in ##sys#include-forms-from-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10301(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_10301,c,av);}
a=C_alloc(6);
t2=*((C_word*)lf[238]+1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10304,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_not(t1))){
/* eval.scm:1178: ##sys#signal-hook */
t4=*((C_word*)lf[223]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[255];
av2[3]=lf[280];
av2[4]=lf[281];
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(6,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_10304(2,av2);}}}

/* k10302 in k10299 in ##sys#include-forms-from-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10304(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_10304,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10307,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10366,a[2]=t2,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1179: load-verbose */
t4=*((C_word*)lf[214]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k10305 in k10302 in k10299 in ##sys#include-forms-from-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_10307(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_10307,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10312,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li206),tmp=(C_word)a,a+=6,tmp);
/* eval.scm:1181: call-with-input-file */
t3=*((C_word*)lf[276]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[5];
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* a10311 in k10305 in k10302 in k10299 in ##sys#include-forms-from-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_10312(C_word c,C_word *av){
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
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,4)))){
C_save_and_reclaim((void *)f_10312,c,av);}
a=C_alloc(24);
t3=((C_word*)t0)[2];
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_SCHEME_FALSE;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10320,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10322,a[2]=t6,a[3]=t4,a[4]=((C_word)li202),tmp=(C_word)a,a+=5,tmp);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10327,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word)li204),tmp=(C_word)a,a+=5,tmp);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10360,a[2]=t4,a[3]=t6,a[4]=((C_word)li205),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1183: ##sys#dynamic-wind */
t11=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t11;
av2[1]=t7;
av2[2]=t8;
av2[3]=t9;
av2[4]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(5,av2);}}

/* k10318 in a10311 in k10305 in k10302 in k10299 in ##sys#include-forms-from-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_ccall f_10320(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10320,c,av);}
/* eval.scm:1183: k */
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

/* a10321 in a10311 in k10305 in k10302 in k10299 in ##sys#include-forms-from-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_ccall f_10322(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10322,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[90]+1));
t3=C_mutate((C_word*)lf[90]+1 /* (set! ##sys#current-source-filename ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a10326 in a10311 in k10305 in k10302 in k10299 in ##sys#include-forms-from-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_ccall f_10327(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_10327,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10335,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1184: read-with-source-info */
t3=((C_word*)t0)[2];{
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

/* k10333 in a10326 in a10311 in k10305 in k10302 in k10299 in ##sys#include-forms-from-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in ... */
static void C_ccall f_10335(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10335,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10337,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word)li203),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_10337(t5,((C_word*)t0)[4],t1,C_SCHEME_END_OF_LIST);}

/* doloop2521 in k10333 in a10326 in a10311 in k10305 in k10302 in k10299 in ##sys#include-forms-from-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in ... */
static void C_fcall f_10337(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10337,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_eofp(t2))){
/* eval.scm:1187: reverse */
t4=*((C_word*)lf[104]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10354,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:1184: read-with-source-info */
t5=((C_word*)t0)[3];{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k10352 in doloop2521 in k10333 in a10326 in a10311 in k10305 in k10302 in k10299 in ##sys#include-forms-from-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in ... */
static void C_ccall f_10354(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_10354,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=((C_word*)((C_word*)t0)[4])[1];
f_10337(t3,((C_word*)t0)[5],t1,t2);}

/* a10359 in a10311 in k10305 in k10302 in k10299 in ##sys#include-forms-from-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_ccall f_10360(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10360,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[90]+1));
t3=C_mutate((C_word*)lf[90]+1 /* (set! ##sys#current-source-filename ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k10364 in k10302 in k10299 in ##sys#include-forms-from-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_10366(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10366,c,av);}
if(C_truep(t1)){
/* eval.scm:1180: chicken.base#print */
t2=*((C_word*)lf[277]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[278];
av2[3]=((C_word*)t0)[3];
av2[4]=lf[279];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_10307(2,av2);}}}

/* chicken.load#file-exists? in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_fcall f_10378(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,5)))){
C_save_and_reclaim_args((void *)trf_10378,2,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10385,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1196: ##sys#file-exists? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[257]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[257]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
av2[5]=C_SCHEME_FALSE;
tp(6,av2);}}

/* k10383 in chicken.load#file-exists? in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10385(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10385,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?((C_word*)t0)[3]:C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.load#find-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10387(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_10387,c,av);}
a=C_alloc(8);
if(C_truep(C_i_not(t3))){
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_i_nullp(t3))){
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_i_stringp(t3))){
t4=C_a_i_list1(&a,1,t3);
/* eval.scm:1201: find-file */
t5=*((C_word*)lf[285]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10416,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10428,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1202: scheme#string-append */
t6=*((C_word*)lf[211]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_i_car(t3);
av2[3]=lf[286];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}}}}

/* k10414 in chicken.load#find-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10416(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10416,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* eval.scm:1203: find-file */
t2=*((C_word*)lf[285]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_u_i_cdr(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k10426 in chicken.load#find-file in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10428(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10428,c,av);}
/* eval.scm:1202: file-exists? */
f_10378(((C_word*)t0)[2],t1);}

/* chicken.load#find-dynamic-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10434(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_10434,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10438,a[2]=t1,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1208: chicken.platform#repository-path */
t5=*((C_word*)lf[293]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k10436 in chicken.load#find-dynamic-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10438(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_10438,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10441,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_symbolp(((C_word*)t0)[4]))){
/* eval.scm:1209: scheme#symbol->string */
t3=*((C_word*)lf[292]+1);{
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
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
f_10441(2,av2);}}}

/* k10439 in k10436 in chicken.load#find-dynamic-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10441(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_10441,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10443,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word)li210),tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10486,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=(C_truep(*((C_word*)lf[283]+1))?lf[289]:C_SCHEME_END_OF_LIST);
t5=(C_truep(((C_word*)t0)[2])?((C_word*)t0)[2]:C_SCHEME_END_OF_LIST);
t6=(C_truep(((C_word*)t0)[4])?*((C_word*)lf[290]+1):C_SCHEME_END_OF_LIST);
if(C_truep(*((C_word*)lf[283]+1))){
/* eval.scm:1217: ##sys#append */
t7=*((C_word*)lf[57]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t7;
av2[1]=t3;
av2[2]=t4;
av2[3]=t5;
av2[4]=t6;
av2[5]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t7+1)))(6,av2);}}
else{
/* eval.scm:1217: ##sys#append */
t7=*((C_word*)lf[57]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t7;
av2[1]=t3;
av2[2]=t4;
av2[3]=t5;
av2[4]=t6;
av2[5]=lf[291];
((C_proc)(void*)(*((C_word*)t7+1)))(6,av2);}}}

/* check in k10439 in k10436 in chicken.load#find-dynamic-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_fcall f_10443(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,4)))){
C_save_and_reclaim_args((void *)trf_10443,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10447,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1211: string-append */
t4=*((C_word*)lf[211]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[288];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k10445 in check in k10439 in k10436 in chicken.load#find-dynamic-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_10447(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_10447,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10450,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)t0)[3])){
if(C_truep(C_i_not(*((C_word*)lf[216]+1)))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10472,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1214: chicken.platform#feature? */
t4=*((C_word*)lf[259]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[260];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_10450(2,av2);}}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_10450(2,av2);}}}

/* k10448 in k10445 in check in k10439 in k10436 in chicken.load#find-dynamic-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_ccall f_10450(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_10450,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10460,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1216: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[228]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[228]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[198];
tp(4,av2);}}}

/* k10458 in k10448 in k10445 in check in k10439 in k10436 in chicken.load#find-dynamic-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in ... */
static void C_ccall f_10460(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10460,c,av);}
/* eval.scm:1216: file-exists? */
f_10378(((C_word*)t0)[2],t1);}

/* k10470 in k10445 in check in k10439 in k10436 in chicken.load#find-dynamic-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_ccall f_10472(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_10472,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10479,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1215: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[228]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[228]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=*((C_word*)lf[201]+1);
tp(4,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_10450(2,av2);}}}

/* k10477 in k10470 in k10445 in check in k10439 in k10436 in chicken.load#find-dynamic-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in ... */
static void C_ccall f_10479(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10479,c,av);}
/* eval.scm:1215: file-exists? */
f_10378(((C_word*)t0)[2],t1);}

/* k10484 in k10439 in k10436 in chicken.load#find-dynamic-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_10486(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10486,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10488,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word)li211),tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_10488(t5,((C_word*)t0)[3],t1);}

/* loop in k10484 in k10439 in k10436 in chicken.load#find-dynamic-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_fcall f_10488(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_10488,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10501,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1224: check */
t5=((C_word*)t0)[3];
f_10443(t5,t4,t3);}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10499 in loop in k10484 in k10439 in k10436 in chicken.load#find-dynamic-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_ccall f_10501(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10501,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* eval.scm:1225: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_10488(t2,((C_word*)t0)[2],C_slot(((C_word*)t0)[4],C_fix(1)));}}

/* chicken.load#load-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10535(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_10535,c,av);}
a=C_alloc(10);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10576,a[2]=t1,a[3]=t2,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10544,a[2]=t5,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1228: ##sys#provided? */
t7=*((C_word*)lf[204]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k10542 in chicken.load#load-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10544(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10544,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
f_10576(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],C_SCHEME_TRUE);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10560,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1230: chicken.internal#module-requirement */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[102]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[102]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
tp(3,av2);}}
else{
if(C_truep(C_i_symbolp(((C_word*)t0)[3]))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10573,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1232: chicken.internal#module-requirement */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[102]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[102]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_10576(2,av2);}}}}}

/* k10558 in k10542 in chicken.load#load-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10560(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10560,c,av);}
/* eval.scm:1230: ##sys#provided? */
t2=*((C_word*)lf[204]+1);{
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

/* k10571 in k10542 in chicken.load#load-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10573(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10573,c,av);}
/* eval.scm:1232: ##sys#provided? */
t2=*((C_word*)lf[204]+1);{
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

/* k10574 in chicken.load#load-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10576(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_10576,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(C_i_memq(((C_word*)t0)[3],lf[194]))){
/* eval.scm:1238: load-unit */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[269]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[269]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[4];
tp(5,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10588,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1239: find-dynamic-extension */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[287]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[287]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_FALSE;
tp(4,av2);}}}}

/* k10586 in k10574 in chicken.load#load-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10588(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_10588,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10592,a[2]=((C_word*)t0)[2],a[3]=((C_word)li213),tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1237: g2592 */
t3=t2;
f_10592(t3,((C_word*)t0)[3],t1);}
else{
/* eval.scm:1245: ##sys#error */
t2=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[294];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* g2592 in k10586 in k10574 in chicken.load#load-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_fcall f_10592(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(16,0,4)))){
C_save_and_reclaim_args((void *)trf_10592,3,t0,t1,t2);}
a=C_alloc(16);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10596,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1241: load/internal */
t4=lf[233];
f_9707(t4,t3,t2,C_SCHEME_FALSE,C_a_i_list(&a,4,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE,((C_word*)t0)[2]));}

/* k10594 in g2592 in k10586 in k10574 in chicken.load#load-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_10596(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10596,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10599,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1242: ##sys#provide */
t3=*((C_word*)lf[101]+1);{
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

/* k10597 in k10594 in g2592 in k10586 in k10574 in chicken.load#load-extension in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_ccall f_10599(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10599,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.load#require in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10607(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +9,c,3)))){
C_save_and_reclaim((void*)f_10607,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+9);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10649,a[2]=((C_word)li215),tmp=(C_word)a,a+=3,tmp);
t4=(
  f_10649(t2)
);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10626,a[2]=t6,a[3]=((C_word)li216),tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_10626(t8,t1,t2);}

/* for-each-loop2611 in chicken.load#require in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_fcall f_10626(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_10626,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10636,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=*((C_word*)lf[114]+1);
/* eval.scm:1249: g2642 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[114]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[114]+1);
av2[1]=t3;
av2[2]=t4;
av2[3]=C_SCHEME_FALSE;
av2[4]=lf[296];
tp(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k10634 in for-each-loop2611 in chicken.load#require in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10636(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10636,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_10626(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop2601 in chicken.load#require in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static C_word C_fcall f_10649(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_pairp(t1))){
t2=C_slot(t1,C_fix(0));
t3=C_i_check_symbol_2(t2,lf[296]);
t5=C_slot(t1,C_fix(1));
t1=t5;
goto loop;}
else{
t2=C_SCHEME_UNDEFINED;
return(t2);}}

/* chicken.load#provide in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10672(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +9,c,3)))){
C_save_and_reclaim((void*)f_10672,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+9);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10714,a[2]=((C_word)li218),tmp=(C_word)a,a+=3,tmp);
t4=(
  f_10714(t2)
);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10691,a[2]=t6,a[3]=((C_word)li219),tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_10691(t8,t1,t2);}

/* for-each-loop2664 in chicken.load#provide in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_fcall f_10691(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_10691,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10701,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=*((C_word*)lf[101]+1);
/* eval.scm:1253: g2695 */
t6=*((C_word*)lf[101]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k10699 in for-each-loop2664 in chicken.load#provide in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10701(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10701,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_10691(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop2654 in chicken.load#provide in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static C_word C_fcall f_10714(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_pairp(t1))){
t2=C_slot(t1,C_fix(0));
t3=C_i_check_symbol_2(t2,lf[298]);
t5=C_slot(t1,C_fix(1));
t1=t5;
goto loop;}
else{
t2=C_SCHEME_UNDEFINED;
return(t2);}}

/* chicken.load#provided? in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10737(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +10,c,3)))){
C_save_and_reclaim((void*)f_10737,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+10);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10751,a[2]=((C_word)li221),tmp=(C_word)a,a+=3,tmp);
t4=(
  f_10751(t2)
);
t5=*((C_word*)lf[204]+1);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8566,a[2]=t7,a[3]=t5,a[4]=((C_word)li222),tmp=(C_word)a,a+=5,tmp));
t9=((C_word*)t7)[1];
f_8566(t9,t1,t2);}

/* for-each-loop2707 in chicken.load#provided? in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static C_word C_fcall f_10751(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_pairp(t1))){
t2=C_slot(t1,C_fix(0));
t3=C_i_check_symbol_2(t2,lf[300]);
t5=C_slot(t1,C_fix(1));
t1=t5;
goto loop;}
else{
t2=C_SCHEME_UNDEFINED;
return(t2);}}

/* ##sys#process-require in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10778(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(30,c,1)))){
C_save_and_reclaim((void *)f_10778,c,av);}
a=C_alloc(30);
t5=C_eqp(t2,t3);
t6=(C_truep(t5)?t5:t3);
t7=C_i_assq(t2,lf[192]);
if(C_truep(t7)){
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_i_cdr(t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
if(C_truep(C_i_memq(t2,lf[194]))){
if(C_truep(t4)){
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_a_i_list(&a,2,lf[148],t2);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=C_a_i_list(&a,2,lf[26],t2);
t9=C_a_i_list(&a,2,lf[26],C_SCHEME_FALSE);
t10=C_a_i_list(&a,2,lf[26],C_SCHEME_FALSE);
t11=t1;{
C_word *av2=av;
av2[0]=t11;
av2[1]=C_a_i_list(&a,4,lf[269],t8,t9,t10);
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}}
else{
t8=C_eqp(t4,lf[301]);
if(C_truep(t8)){
t9=t1;{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_a_i_list(&a,2,lf[148],t2);
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
t9=C_a_i_list(&a,2,lf[26],t2);
t10=C_a_i_list(&a,2,lf[26],t6);
t11=C_a_i_list(&a,2,lf[26],C_SCHEME_FALSE);
t12=t1;{
C_word *av2=av;
av2[0]=t12;
av2[1]=C_a_i_list(&a,4,lf[114],t9,t10,t11);
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}}}}

/* ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_10847(C_word c,C_word *av){
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
C_word t14;
C_word *a;
if(c!=6) C_bad_argc_2(c,6,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(23,c,4)))){
C_save_and_reclaim((void *)f_10847,c,av);}
a=C_alloc(23);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10850,a[2]=t7,a[3]=((C_word)li225),tmp=(C_word)a,a+=4,tmp));
t11=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10883,a[2]=t3,a[3]=t7,a[4]=((C_word)li226),tmp=(C_word)a,a+=5,tmp));
t12=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10922,a[2]=t1,a[3]=t9,a[4]=t2,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
t13=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10976,a[2]=t9,a[3]=t12,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1306: make-relative-pathname */
f_9546(t13,t5,t2);}

/* test-extensions in ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_fcall f_10850(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_10850,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t3))){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10863,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1292: file-exists? */
f_10378(t4,t2);}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10866,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:1293: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[228]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[228]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=C_i_car(t3);
tp(4,av2);}}}

/* k10861 in test-extensions in ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10863(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10863,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?((C_word*)t0)[3]:C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k10864 in test-extensions in ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10866(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_10866,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10869,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* eval.scm:1294: file-exists? */
f_10378(t2,t1);}

/* k10867 in k10864 in test-extensions in ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_10869(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10869,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* eval.scm:1295: test-extensions */
t2=((C_word*)((C_word*)t0)[3])[1];
f_10850(t2,((C_word*)t0)[2],((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[5]));}}

/* test in ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_fcall f_10883(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_10883,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(((C_word*)t0)[2]))){
/* eval.scm:1297: test-extensions */
t3=((C_word*)((C_word*)t0)[3])[1];
f_10850(t3,t1,t2,((C_word*)t0)[2]);}
else{
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10919,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* eval.scm:1300: chicken.platform#feature? */
t4=*((C_word*)lf[259]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[260];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k10917 in test in ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10919(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_10919,c,av);}
a=C_alloc(6);
if(C_truep(C_i_not(t1))){
t2=C_a_i_list1(&a,1,lf[198]);
/* eval.scm:1297: test-extensions */
t3=((C_word*)((C_word*)t0)[2])[1];
f_10850(t3,((C_word*)t0)[3],((C_word*)t0)[4],t2);}
else{
t2=C_i_not(((C_word*)t0)[5]);
t3=(C_truep(t2)?C_a_i_list2(&a,2,*((C_word*)lf[201]+1),lf[198]):C_a_i_list2(&a,2,lf[198],*((C_word*)lf[201]+1)));
/* eval.scm:1297: test-extensions */
t4=((C_word*)((C_word*)t0)[2])[1];
f_10850(t4,((C_word*)t0)[3],((C_word*)t0)[4],t3);}}

/* k10920 in ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10922(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_10922,c,av);}
a=C_alloc(8);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10932,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[5])){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10969,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1310: chicken.platform#repository-path */
t4=*((C_word*)lf[293]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=*((C_word*)lf[290]+1);
f_10932(2,av2);}}}}

/* k10930 in k10920 in ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10932(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_10932,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10934,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word)li227),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_10934(t5,((C_word*)t0)[4],t1);}

/* loop in k10930 in k10920 in ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_fcall f_10934(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,4)))){
C_save_and_reclaim_args((void *)trf_10934,3,t0,t1,t2);}
a=C_alloc(9);
t3=C_eqp(t2,C_SCHEME_END_OF_LIST);
if(C_truep(t3)){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10944,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10958,a[2]=((C_word*)t0)[3],a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1313: string-append */
t6=*((C_word*)lf[211]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t5;
av2[2]=C_slot(t2,C_fix(0));
av2[3]=lf[302];
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}}

/* k10942 in loop in k10930 in k10920 in ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_10944(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10944,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* eval.scm:1316: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_10934(t2,((C_word*)t0)[2],C_slot(((C_word*)t0)[4],C_fix(1)));}}

/* k10956 in loop in k10930 in k10920 in ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_10958(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10958,c,av);}
/* eval.scm:1313: test */
t2=((C_word*)((C_word*)t0)[2])[1];
f_10883(t2,((C_word*)t0)[3],t1);}

/* k10967 in k10920 in ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10969(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10969,c,av);}
if(C_truep(t1)){
/* eval.scm:1308: ##sys#append */
t2=*((C_word*)lf[57]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[290]+1);
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
/* eval.scm:1308: ##sys#append */
t2=*((C_word*)lf[57]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[290]+1);
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k10974 in ##sys#resolve-include-filename in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10976(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10976,c,av);}
/* eval.scm:1306: test */
t2=((C_word*)((C_word*)t0)[2])[1];
f_10883(t2,((C_word*)t0)[3],t1);}

/* run-safe in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_fcall f_10979(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_10979,2,t1,t2);}
a=C_alloc(7);
t3=lf[303] /* last-error */ =C_SCHEME_FALSE;;
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10984,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10989,a[2]=t2,a[3]=((C_word)li235),tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1336: scheme#call-with-current-continuation */
t6=*((C_word*)lf[307]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t4;
av2[2]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k10982 in run-safe in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10984(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10984,c,av);}
/* eval.scm:1334: g2870 */
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a10988 in run-safe in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_10989(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_10989,c,av);}
a=C_alloc(9);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10995,a[2]=t2,a[3]=((C_word)li230),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11014,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word)li234),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1336: chicken.condition#with-exception-handler */
t5=*((C_word*)lf[306]+1);{
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

/* a10994 in a10988 in run-safe in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_10995(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10995,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11001,a[2]=t2,a[3]=((C_word)li229),tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1336: k2867 */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a11000 in a10994 in a10988 in run-safe in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_11001(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_11001,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11005,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1337: chicken.base#open-output-string */
t3=*((C_word*)lf[17]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k11003 in a11000 in a10994 in a10988 in run-safe in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_11005(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_11005,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11008,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1338: chicken.condition#print-error-message */
t3=*((C_word*)lf[305]+1);{
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

/* k11006 in k11003 in a11000 in a10994 in a10988 in run-safe in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_ccall f_11008(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11008,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11012,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1339: chicken.base#get-output-string */
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

/* k11010 in k11006 in k11003 in a11000 in a10994 in a10988 in run-safe in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in ... */
static void C_ccall f_11012(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11012,c,av);}
t2=C_mutate(&lf[303] /* (set! last-error ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a11013 in a10988 in run-safe in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_11014(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_11014,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11020,a[2]=((C_word*)t0)[2],a[3]=((C_word)li231),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11026,a[2]=((C_word*)t0)[3],a[3]=((C_word)li233),tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1336: ##sys#call-with-values */{
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

/* a11019 in a11013 in a10988 in run-safe in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_11020(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11020,c,av);}
/* eval.scm:1341: thunk */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a11025 in a11013 in a10988 in run-safe in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_11026(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_11026,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11032,a[2]=t2,a[3]=((C_word)li232),tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1336: k2867 */
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

/* a11031 in a11025 in a11013 in a10988 in run-safe in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_11032(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11032,c,av);}{
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

/* store-result in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_fcall f_11038(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_11038,3,t1,t2,t3);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11042,a[2]=t3,a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1348: ##sys#gc */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[309]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[309]+1);
av2[1]=t4;
av2[2]=C_SCHEME_FALSE;
tp(3,av2);}}

/* k11040 in store-result in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_11042(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11042,c,av);}
if(C_truep(((C_word*)t0)[2])){
t2=C_store_result(((C_word*)t0)[3],((C_word*)t0)[2]);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* CHICKEN_yield in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_11047(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11047,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11053,a[2]=((C_word)li238),tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1354: run-safe */
f_10979(t1,t2);}

/* a11052 in CHICKEN_yield in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_11053(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11053,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11057,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1354: ##sys#thread-yield! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[311]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[311]+1);
av2[1]=t2;
tp(2,av2);}}

/* k11055 in a11052 in CHICKEN_yield in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_11057(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11057,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* CHICKEN_eval in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_11059(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11059,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11065,a[2]=t3,a[3]=t2,a[4]=((C_word)li240),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1357: run-safe */
f_10979(t1,t4);}

/* a11064 in CHICKEN_eval in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_11065(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_11065,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11073,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1359: scheme#eval */
t3=*((C_word*)lf[163]+1);{
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

/* k11071 in a11064 in CHICKEN_eval in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_11073(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11073,c,av);}
/* eval.scm:1359: store-result */
f_11038(((C_word*)t0)[2],t1,((C_word*)t0)[3]);}

/* CHICKEN_eval_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_11075(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11075,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11079,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1361: ##sys#peek-c-string */
t5=*((C_word*)lf[245]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k11077 in CHICKEN_eval_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_11079(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11079,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11084,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word)li242),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1362: run-safe */
f_10979(((C_word*)t0)[3],t2);}

/* a11083 in k11077 in CHICKEN_eval_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_11084(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_11084,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11088,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1364: chicken.base#open-input-string */
t3=*((C_word*)lf[315]+1);{
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

/* k11086 in a11083 in k11077 in CHICKEN_eval_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_11088(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_11088,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11095,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11099,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1365: scheme#read */
t4=*((C_word*)lf[314]+1);{
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

/* k11093 in k11086 in a11083 in k11077 in CHICKEN_eval_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_11095(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11095,c,av);}
/* eval.scm:1365: store-result */
f_11038(((C_word*)t0)[2],t1,((C_word*)t0)[3]);}

/* k11097 in k11086 in a11083 in k11077 in CHICKEN_eval_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_11099(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11099,c,av);}
/* eval.scm:1365: scheme#eval */
t2=*((C_word*)lf[163]+1);{
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

/* store-string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static C_word C_fcall f_11101(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_stack_overflow_check;{}
t4=C_block_size(t1);
if(C_truep(C_fixnum_greater_or_equal_p(t4,t2))){
t5=C_mutate(&lf[303] /* (set! last-error ...) */,lf[317]);
return(C_SCHEME_FALSE);}
else{
return(C_copy_result_string(t1,t3,t4));}}

/* CHICKEN_eval_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_11114(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_11114,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11120,a[2]=t4,a[3]=t3,a[4]=t2,a[5]=((C_word)li245),tmp=(C_word)a,a+=6,tmp);
/* eval.scm:1381: run-safe */
f_10979(t1,t5);}

/* a11119 in CHICKEN_eval_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_11120(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_11120,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11124,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* eval.scm:1383: chicken.base#open-output-string */
t3=*((C_word*)lf[17]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k11122 in a11119 in CHICKEN_eval_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_11124(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_11124,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11127,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11138,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1384: scheme#eval */
t4=*((C_word*)lf[163]+1);{
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

/* k11125 in k11122 in a11119 in CHICKEN_eval_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_11127(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11127,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11134,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1385: chicken.base#get-output-string */
t3=*((C_word*)lf[15]+1);{
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

/* k11132 in k11125 in k11122 in a11119 in CHICKEN_eval_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_11134(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11134,c,av);}
/* eval.scm:1385: store-string */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(
/* eval.scm:1385: store-string */
  f_11101(t1,((C_word*)t0)[3],((C_word*)t0)[4])
);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k11136 in k11122 in a11119 in CHICKEN_eval_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_11138(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11138,c,av);}
/* eval.scm:1384: scheme#write */
t2=*((C_word*)lf[16]+1);{
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

/* CHICKEN_eval_string_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_11140(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_11140,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11144,a[2]=t4,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1387: ##sys#peek-c-string */
t6=*((C_word*)lf[245]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k11142 in CHICKEN_eval_string_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_11144(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_11144,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11149,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word)li247),tmp=(C_word)a,a+=6,tmp);
/* eval.scm:1390: run-safe */
f_10979(((C_word*)t0)[4],t2);}

/* a11148 in k11142 in CHICKEN_eval_string_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_11149(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_11149,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11153,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* eval.scm:1392: chicken.base#open-output-string */
t3=*((C_word*)lf[17]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k11151 in a11148 in k11142 in CHICKEN_eval_string_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_11153(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11153,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11156,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11167,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11171,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11175,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1393: chicken.base#open-input-string */
t6=*((C_word*)lf[315]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k11154 in k11151 in a11148 in k11142 in CHICKEN_eval_string_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_11156(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11156,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11163,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1394: chicken.base#get-output-string */
t3=*((C_word*)lf[15]+1);{
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

/* k11161 in k11154 in k11151 in a11148 in k11142 in CHICKEN_eval_string_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_ccall f_11163(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11163,c,av);}
/* eval.scm:1394: store-string */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(
/* eval.scm:1394: store-string */
  f_11101(t1,((C_word*)t0)[3],((C_word*)t0)[4])
);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k11165 in k11151 in a11148 in k11142 in CHICKEN_eval_string_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_11167(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11167,c,av);}
/* eval.scm:1393: scheme#write */
t2=*((C_word*)lf[16]+1);{
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

/* k11169 in k11151 in a11148 in k11142 in CHICKEN_eval_string_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_11171(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11171,c,av);}
/* eval.scm:1393: scheme#eval */
t2=*((C_word*)lf[163]+1);{
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

/* k11173 in k11151 in a11148 in k11142 in CHICKEN_eval_string_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_11175(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11175,c,av);}
/* eval.scm:1393: scheme#read */
t2=*((C_word*)lf[314]+1);{
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

/* CHICKEN_apply in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_11177(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_11177,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11183,a[2]=t4,a[3]=t2,a[4]=t3,a[5]=((C_word)li249),tmp=(C_word)a,a+=6,tmp);
/* eval.scm:1399: run-safe */
f_10979(t1,t5);}

/* a11182 in CHICKEN_apply in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_11183(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_11183,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11191,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
C_apply(4,av2);}}

/* k11189 in a11182 in CHICKEN_apply in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_11191(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11191,c,av);}
/* eval.scm:1399: store-result */
f_11038(((C_word*)t0)[2],t1,((C_word*)t0)[3]);}

/* CHICKEN_apply_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_11193(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_11193,c,av);}
a=C_alloc(7);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11199,a[2]=t5,a[3]=t4,a[4]=t2,a[5]=t3,a[6]=((C_word)li251),tmp=(C_word)a,a+=7,tmp);
/* eval.scm:1404: run-safe */
f_10979(t1,t6);}

/* a11198 in CHICKEN_apply_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_11199(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_11199,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11203,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* eval.scm:1406: chicken.base#open-output-string */
t3=*((C_word*)lf[17]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k11201 in a11198 in CHICKEN_apply_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_11203(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_11203,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11206,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11217,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[6];
C_apply(4,av2);}}

/* k11204 in k11201 in a11198 in CHICKEN_apply_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_11206(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11206,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11213,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1408: chicken.base#get-output-string */
t3=*((C_word*)lf[15]+1);{
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

/* k11211 in k11204 in k11201 in a11198 in CHICKEN_apply_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_11213(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11213,c,av);}
/* eval.scm:1408: store-string */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(
/* eval.scm:1408: store-string */
  f_11101(t1,((C_word*)t0)[3],((C_word*)t0)[4])
);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k11215 in k11201 in a11198 in CHICKEN_apply_to_string in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_11217(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11217,c,av);}
/* eval.scm:1407: scheme#write */
t2=*((C_word*)lf[16]+1);{
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

/* CHICKEN_read in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_11219(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11219,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11223,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1410: ##sys#peek-c-string */
t5=*((C_word*)lf[245]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k11221 in CHICKEN_read in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_11223(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11223,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11228,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word)li253),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1411: run-safe */
f_10979(((C_word*)t0)[3],t2);}

/* a11227 in k11221 in CHICKEN_read in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_11228(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_11228,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11232,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1413: chicken.base#open-input-string */
t3=*((C_word*)lf[315]+1);{
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

/* k11230 in a11227 in k11221 in CHICKEN_read in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_11232(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_11232,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11239,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1414: scheme#read */
t3=*((C_word*)lf[314]+1);{
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

/* k11237 in k11230 in a11227 in k11221 in CHICKEN_read in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_11239(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11239,c,av);}
/* eval.scm:1414: store-result */
f_11038(((C_word*)t0)[2],t1,((C_word*)t0)[3]);}

/* CHICKEN_load in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_11241(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11241,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11245,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1416: ##sys#peek-c-string */
t4=*((C_word*)lf[245]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k11243 in CHICKEN_load in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_11245(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_11245,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11250,a[2]=t1,a[3]=((C_word)li255),tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1417: run-safe */
f_10979(((C_word*)t0)[2],t2);}

/* a11249 in k11243 in CHICKEN_load in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_11250(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11250,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11254,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1417: scheme#load */
t3=*((C_word*)lf[261]+1);{
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

/* k11252 in a11249 in k11243 in CHICKEN_load in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_11254(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11254,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* CHICKEN_get_error_message in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_11256(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11256,c,av);}
t4=lf[303];
if(C_truep(lf[303])){
t5=lf[303];
t6=lf[303];
/* eval.scm:1420: store-string */
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=(
/* eval.scm:1420: store-string */
  f_11101(lf[303],t3,t2)
);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
/* eval.scm:1420: store-string */
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=(
/* eval.scm:1420: store-string */
  f_11101(lf[325],t3,t2)
);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k11269 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_11271(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_11271,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11273,a[2]=((C_word)li258),tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1139: chicken.base#make-parameter */
t3=*((C_word*)lf[326]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* a11272 in k11269 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_11273(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11273,c,av);}
t3=C_i_check_list(t2);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* map-loop2444 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_fcall f_11279(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_11279,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11304,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:1140: g2450 */
t4=((C_word*)t0)[4];
f_10170(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k11302 in map-loop2444 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_11304(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11304,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_11279(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k11316 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_11318(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11318,c,av);}
/* eval.scm:1132: scheme#string-append */
t2=*((C_word*)lf[211]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[200];
av2[3]=lf[327];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k11328 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11330(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_11330,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];
f_9499(t2,C_a_i_list(&a,1,t1));}

/* k11332 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11334(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11334,c,av);}
/* eval.scm:967: scheme#string-append */
t2=*((C_word*)lf[211]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[331];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k11359 in k11363 in k11367 in k11371 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11361(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11361,c,av);}
t2=C_eqp(t1,lf[338]);
t3=((C_word*)t0)[2];
f_9479(t3,(C_truep(t2)?lf[339]:lf[196]));}

/* k11363 in k11367 in k11371 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11365(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11365,c,av);}
a=C_alloc(3);
t2=C_eqp(t1,lf[337]);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11361,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:955: chicken.platform#machine-type */
t4=*((C_word*)lf[340]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=((C_word*)t0)[2];
f_9479(t3,lf[196]);}}

/* k11367 in k11371 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11369(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11369,c,av);}
a=C_alloc(3);
t2=C_eqp(t1,lf[335]);
if(C_truep(t2)){
t3=((C_word*)t0)[2];
f_9479(t3,lf[336]);}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11365,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:954: chicken.platform#software-version */
t4=*((C_word*)lf[332]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k11371 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11373(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11373,c,av);}
a=C_alloc(3);
t2=C_eqp(t1,lf[333]);
if(C_truep(t2)){
t3=((C_word*)t0)[2];
f_9479(t3,lf[334]);}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11369,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:953: chicken.platform#software-version */
t4=*((C_word*)lf[332]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11377(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,3)))){
C_save_and_reclaim((void *)f_11377,c,av);}
a=C_alloc(21);
t2=C_i_setslot(((C_word*)t0)[2],C_fix(2),t1);
t3=C_mutate((C_word*)lf[184]+1 /* (set! scheme#scheme-report-environment ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8138,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word)li166),tmp=(C_word)a,a+=5,tmp));
t4=C_mutate((C_word*)lf[188]+1 /* (set! scheme#null-environment ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8163,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[2],a[4]=((C_word)li167),tmp=(C_word)a,a+=5,tmp));
t5=C_a_i_provide(&a,1,lf[191]);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8189,a[2]=((C_word*)t0)[6],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t6;
C_eval_toplevel(2,av2);}}

/* k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11385(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_11385,c,av);}
a=C_alloc(7);
t2=C_i_setslot(((C_word*)t0)[2],C_fix(2),t1);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11377,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* eval.scm:876: strip */
f_8080(t3,C_slot(((C_word*)t0)[3],C_fix(2)));}

/* k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11393(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_11393,c,av);}
a=C_alloc(8);
t2=C_i_setslot(((C_word*)t0)[2],C_fix(2),t1);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11385,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:875: strip */
f_8080(t3,C_slot(((C_word*)t0)[3],C_fix(2)));}

/* k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11401(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_11401,c,av);}
a=C_alloc(8);
t2=C_i_setslot(((C_word*)t0)[2],C_fix(2),t1);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11393,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:874: strip */
f_8080(t3,C_slot(((C_word*)t0)[3],C_fix(2)));}

/* a11406 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11407(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_11407,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11411,a[2]=t1,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:841: ##sys#print */
t5=*((C_word*)lf[351]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[352];
av2[3]=C_SCHEME_FALSE;
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k11409 in a11406 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11411(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_11411,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11414,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:842: ##sys#print */
t3=*((C_word*)lf[351]+1);{
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

/* k11412 in k11409 in a11406 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11414(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11414,c,av);}
/* eval.scm:843: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[350]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[350]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(62);
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* a11422 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11423(C_word c,C_word *av){
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
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,5)))){
C_save_and_reclaim((void *)f_11423,c,av);}
a=C_alloc(14);
t2=C_SCHEME_END_OF_LIST;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11429,a[2]=t5,a[3]=t3,a[4]=((C_word)li261),tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11450,a[2]=t5,a[3]=t3,a[4]=((C_word)li265),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:795: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=t6;
av2[3]=t7;
C_values(4,av2);}}

/* a11428 in a11422 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11429(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_11429,c,av);}
a=C_alloc(12);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11433,a[2]=t1,a[3]=t4,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)((C_word*)t0)[2])[1])){
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11448,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:798: ##sys#get */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t6;
av2[2]=t2;
av2[3]=t3;
tp(4,av2);}}
else{
t6=t5;
f_11433(t6,C_SCHEME_UNDEFINED);}}

/* k11431 in a11428 in a11422 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_11433(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,4)))){
C_save_and_reclaim_args((void *)trf_11433,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11436,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:799: ##sys#put! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[354]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[354]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[3];
tp(5,av2);}}

/* k11434 in k11431 in a11428 in a11422 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11436(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11436,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k11446 in a11428 in a11422 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11448(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_11448,c,av);}
a=C_alloc(12);
t2=C_a_i_list3(&a,3,((C_word*)t0)[2],((C_word*)t0)[3],t1);
t3=C_a_i_cons(&a,2,t2,((C_word*)((C_word*)t0)[4])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[4])+1,t3);
t5=((C_word*)t0)[5];
f_11433(t5,t4);}

/* a11449 in a11422 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11450(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,4)))){
C_save_and_reclaim((void *)f_11450,c,av);}
a=C_alloc(15);
t3=C_SCHEME_FALSE;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)((C_word*)t0)[2])[1];
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11456,a[2]=t4,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word)li262),tmp=(C_word)a,a+=6,tmp);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11461,a[2]=((C_word*)t0)[2],a[3]=t5,a[4]=t4,a[5]=((C_word*)t0)[3],a[6]=((C_word)li264),tmp=(C_word)a,a+=7,tmp);
/* eval.scm:804: scheme#dynamic-wind */
t8=*((C_word*)lf[160]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t8;
av2[1]=t1;
av2[2]=t6;
av2[3]=t2;
av2[4]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}

/* a11455 in a11449 in a11422 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11456(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11456,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)((C_word*)t0)[3])[1]);
t3=C_set_block_item(((C_word*)t0)[4],0,C_SCHEME_TRUE);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a11460 in a11449 in a11422 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11461(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_11461,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11465,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11468,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=t4,a[5]=((C_word)li263),tmp=(C_word)a,a+=6,tmp));
t6=((C_word*)t4)[1];
f_11468(t6,t2);}

/* k11463 in a11460 in a11449 in a11422 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11465(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11465,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)t0)[3]);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* doloop1536 in a11460 in a11449 in a11422 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_11468(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_11468,2,t0,t1);}
a=C_alloc(5);
t2=C_eqp(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]);
if(C_truep(t2)){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11478,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,tmp=(C_word)a,a+=5,tmp);{
C_word av2[4];
av2[0]=0;
av2[1]=t3;
av2[2]=*((C_word*)lf[354]+1);
av2[3]=C_i_car(((C_word*)((C_word*)t0)[3])[1]);
C_apply(4,av2);}}}

/* k11476 in doloop1536 in a11460 in a11449 in a11422 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11478(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11478,c,av);}
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t4=((C_word*)((C_word*)t0)[3])[1];
f_11468(t4,((C_word*)t0)[4]);}

/* a11490 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11491(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11491,c,av);}
t4=C_mutate((C_word*)lf[38]+1 /* (set! ##sys#put/restore! ...) */,t2);
t5=C_mutate((C_word*)lf[105]+1 /* (set! ##sys#with-property-restore ...) */,t3);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11496(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11496,c,av);}
a=C_alloc(5);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11503,a[2]=t4,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:758: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t5;
tp(2,av2);}}

/* k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11503(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(35,c,4)))){
C_save_and_reclaim((void *)f_11503,c,av);}
a=C_alloc(35);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11506,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_nullp(t1))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11596,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=C_a_i_cons(&a,2,lf[178],*((C_word*)lf[355]+1));
t5=C_a_i_cons(&a,2,lf[177],*((C_word*)lf[356]+1));
t6=C_a_i_list(&a,3,lf[34],t4,t5);
/* eval.scm:764: compile-to-closure */
f_3576(t3,t6,C_SCHEME_END_OF_LIST,C_a_i_list(&a,4,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_TRUE));}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_11506(2,av2);}}}

/* k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11506(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,4)))){
C_save_and_reclaim((void *)f_11506,c,av);}
a=C_alloc(29);
if(C_truep(((C_word*)t0)[2])){
t2=C_i_check_structure_2(((C_word*)t0)[2],lf[168],lf[0]);
t3=C_slot(((C_word*)t0)[2],C_fix(2));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11518,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t3)){
t5=*((C_word*)lf[97]+1);
t6=*((C_word*)lf[9]+1);
t7=C_SCHEME_END_OF_LIST;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=t3;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_SCHEME_TRUE;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11526,a[2]=t8,a[3]=t10,a[4]=t12,a[5]=t6,a[6]=t5,a[7]=((C_word)li268),tmp=(C_word)a,a+=8,tmp);
t14=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11556,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word)li269),tmp=(C_word)a,a+=5,tmp);
t15=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11566,a[2]=t8,a[3]=t10,a[4]=t6,a[5]=t5,a[6]=((C_word)li270),tmp=(C_word)a,a+=7,tmp);
/* eval.scm:772: ##sys#dynamic-wind */
t16=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t16;
av2[1]=t4;
av2[2]=t13;
av2[3]=t14;
av2[4]=t15;
((C_proc)(void*)(*((C_word*)t16+1)))(5,av2);}}
else{
/* eval.scm:775: compile-to-closure */
f_3576(t4,((C_word*)t0)[4],C_SCHEME_END_OF_LIST,C_a_i_list(&a,4,C_SCHEME_FALSE,((C_word*)t0)[2],C_SCHEME_FALSE,C_SCHEME_TRUE));}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11587,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:778: compile-to-closure */
f_3576(t2,((C_word*)t0)[4],C_SCHEME_END_OF_LIST,C_a_i_list(&a,4,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_TRUE));}}

/* k11516 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11518(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11518,c,av);}
/* eval.scm:770: g1484 */
t2=t1;{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_END_OF_LIST;
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* a11525 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11526(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_11526,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11530,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
if(C_truep(((C_word*)((C_word*)t0)[4])[1])){
/* eval.scm:772: ##sys#macro-environment1487 */
t3=((C_word*)t0)[6];{
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
f_11530(2,av2);}}}

/* k11528 in a11525 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11530(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_11530,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_11533,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,tmp=(C_word)a,a+=9,tmp);
if(C_truep(((C_word*)((C_word*)t0)[4])[1])){
/* eval.scm:772: ##sys#current-environment1488 */
t3=((C_word*)t0)[6];{
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
f_11533(2,av2);}}}

/* k11531 in k11528 in a11525 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11533(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_11533,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_11537,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* eval.scm:772: ##sys#macro-environment1487 */
t3=((C_word*)t0)[7];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k11535 in k11531 in k11528 in a11525 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11537(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_11537,c,av);}
a=C_alloc(9);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_11541,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],tmp=(C_word)a,a+=9,tmp);
/* eval.scm:772: ##sys#current-environment1488 */
t4=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* k11539 in k11535 in k11531 in k11528 in a11525 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11541(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_11541,c,av);}
a=C_alloc(6);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11544,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
/* eval.scm:772: ##sys#macro-environment1487 */
t4=((C_word*)t0)[7];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[8];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t4))(5,av2);}}

/* k11542 in k11539 in k11535 in k11531 in k11528 in a11525 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11544(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_11544,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11547,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:772: ##sys#current-environment1488 */
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

/* k11545 in k11542 in k11539 in k11535 in k11531 in k11528 in a11525 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11547(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11547,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a11555 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11556(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_11556,c,av);}
a=C_alloc(12);
t2=C_slot(((C_word*)t0)[2],C_fix(3));
/* eval.scm:774: compile-to-closure */
f_3576(t1,((C_word*)t0)[3],C_SCHEME_END_OF_LIST,C_a_i_list(&a,4,C_SCHEME_FALSE,((C_word*)t0)[2],t2,C_SCHEME_TRUE));}

/* a11565 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11566(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_11566,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11570,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* eval.scm:772: ##sys#macro-environment1487 */
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k11568 in a11565 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11570(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_11570,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11573,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:772: ##sys#current-environment1488 */
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k11571 in k11568 in a11565 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11573(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_11573,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11576,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:772: ##sys#macro-environment1487 */
t3=((C_word*)t0)[7];{
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

/* k11574 in k11571 in k11568 in a11565 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11576(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_11576,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11579,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* eval.scm:772: ##sys#current-environment1488 */
t3=((C_word*)t0)[7];{
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

/* k11577 in k11574 in k11571 in k11568 in a11565 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11579(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11579,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)t0)[3]);
t3=C_mutate(((C_word *)((C_word*)t0)[4])+1,((C_word*)t0)[5]);
t4=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k11585 in k11504 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11587(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11587,c,av);}
/* eval.scm:768: g1516 */
t2=t1;{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_END_OF_LIST;
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* k11594 in k11501 in a11495 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_11596(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11596,c,av);}
/* eval.scm:763: g1478 */
t2=t1;{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_END_OF_LIST;
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* k3519 */
static void C_ccall f_3521(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3521,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3524,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

/* k3522 in k3519 */
static void C_ccall f_3524(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3524,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3527,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_internal_toplevel(2,av2);}}

/* k3525 in k3522 in k3519 */
static void C_ccall f_3527(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3527,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3530,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_expand_toplevel(2,av2);}}

/* k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3530(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3530,c,av);}
a=C_alloc(3);
t2=C_set_block_item(lf[2] /* ##sys#unbound-in-eval */,0,C_SCHEME_FALSE);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3574,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:79: chicken.base#make-parameter */
t4=*((C_word*)lf[326]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_fix(1);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* a3537 in decorate in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3538(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3538,c,av);}
t3=C_immp(t2);
t4=C_i_not(t3);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=(C_truep(t4)?C_lambdainfop(t2):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* a3550 in decorate in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3551(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_3551,c,av);}
a=C_alloc(9);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3559,a[2]=t2,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3563,a[2]=t4,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:73: chicken.base#open-output-string */
t6=*((C_word*)lf[17]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k3557 in a3550 in decorate in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3559(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3559,c,av);}
t2=C_i_setslot(((C_word*)t0)[2],((C_word*)t0)[3],t1);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3561 in a3550 in decorate in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3563(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3563,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3566,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:74: scheme#write */
t3=*((C_word*)lf[16]+1);{
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

/* k3564 in k3561 in a3550 in decorate in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3566(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3566,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3569,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:75: chicken.base#get-output-string */
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

/* k3567 in k3564 in k3561 in a3550 in decorate in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3569(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3569,c,av);}
/* eval.scm:72: ##sys#make-lambda-info */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[14]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[14]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
tp(3,av2);}}

/* k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3574(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,5)))){
C_save_and_reclaim((void *)f_3574,c,av);}
a=C_alloc(12);
t2=C_mutate((C_word*)lf[3]+1 /* (set! ##sys#eval-debug-level ...) */,t1);
t3=C_mutate(&lf[4] /* (set! chicken.eval#compile-to-closure ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3576,a[2]=((C_word)li151),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[76]+1 /* (set! ##sys#eval/meta ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7843,a[2]=((C_word)li157),tmp=(C_word)a,a+=3,tmp));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7956,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11496,a[2]=((C_word)li271),tmp=(C_word)a,a+=3,tmp);
/* eval.scm:756: chicken.base#make-parameter */
t7=*((C_word*)lf[326]+1);{
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

/* chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_3576(C_word t1,C_word t2,C_word t3,C_word t4){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(61,0,8)))){
C_save_and_reclaim_args((void *)trf_3576,4,t1,t2,t3,t4);}
a=C_alloc(61);
t5=C_i_nullp(t4);
t6=(C_truep(t5)?C_SCHEME_FALSE:C_i_car(t4));
t7=C_i_nullp(t4);
t8=(C_truep(t7)?C_SCHEME_END_OF_LIST:C_i_cdr(t4));
t9=C_i_nullp(t8);
t10=(C_truep(t9)?C_SCHEME_FALSE:C_i_car(t8));
t11=C_i_nullp(t8);
t12=(C_truep(t11)?C_SCHEME_END_OF_LIST:C_i_cdr(t8));
t13=C_i_nullp(t12);
t14=(C_truep(t13)?C_SCHEME_FALSE:C_i_car(t12));
t15=C_i_nullp(t12);
t16=(C_truep(t15)?C_SCHEME_END_OF_LIST:C_i_cdr(t12));
t17=C_i_nullp(t16);
t18=(C_truep(t17)?C_SCHEME_FALSE:C_i_car(t16));
t19=C_i_nullp(t16);
t20=(C_truep(t19)?C_SCHEME_END_OF_LIST:C_i_cdr(t16));
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
t37=C_set_block_item(t22,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3603,a[2]=t22,a[3]=((C_word)li0),tmp=(C_word)a,a+=4,tmp));
t38=C_set_block_item(t24,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3638,a[2]=t22,a[3]=((C_word)li3),tmp=(C_word)a,a+=4,tmp));
t39=C_set_block_item(t26,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3672,a[2]=t24,a[3]=((C_word)li7),tmp=(C_word)a,a+=4,tmp));
t40=C_set_block_item(t28,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3761,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp));
t41=C_set_block_item(t30,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3775,a[2]=((C_word)li9),tmp=(C_word)a,a+=3,tmp));
t42=C_set_block_item(t32,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3792,a[2]=((C_word)li12),tmp=(C_word)a,a+=3,tmp));
t43=C_set_block_item(t34,0,(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_3825,a[2]=t26,a[3]=t14,a[4]=t34,a[5]=t10,a[6]=t32,a[7]=t24,a[8]=t36,a[9]=t30,a[10]=((C_word)li137),tmp=(C_word)a,a+=11,tmp));
t44=C_set_block_item(t36,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7444,a[2]=t28,a[3]=t34,a[4]=((C_word)li150),tmp=(C_word)a,a+=5,tmp));
t45=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7793,a[2]=t34,a[3]=t1,a[4]=t2,a[5]=t3,a[6]=t6,a[7]=t18,tmp=(C_word)a,a+=8,tmp);
/* eval.scm:729: ##sys#eval-debug-level */
t46=*((C_word*)lf[3]+1);{
C_word av2[2];
av2[0]=t46;
av2[1]=t45;
((C_proc)(void*)(*((C_word*)t46+1)))(2,av2);}}

/* find-id in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_3603(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_3603,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t3))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3616,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t5=C_i_caar(t3);
t6=C_eqp(t2,t5);
if(C_truep(t6)){
t7=C_u_i_car(t3);
t8=t4;
f_3616(t8,C_i_symbolp(C_u_i_cdr(t7)));}
else{
t7=t4;
f_3616(t7,C_SCHEME_FALSE);}}}

/* k3614 in find-id in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_3616(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_3616,2,t0,t1);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_u_i_cdr(C_u_i_car(((C_word*)t0)[3]));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* eval.scm:91: find-id */
t2=((C_word*)((C_word*)t0)[4])[1];
f_3603(t2,((C_word*)t0)[2],((C_word*)t0)[5],C_u_i_cdr(((C_word*)t0)[3]));}}

/* rename in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_3638(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_3638,3,t0,t1,t2);}
a=C_alloc(9);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3642,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3670,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:94: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word av2[2];
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t4;
tp(2,av2);}}

/* k3640 in rename in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3642(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3642,c,av);}
a=C_alloc(8);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3650,a[2]=((C_word*)t0)[3],a[3]=((C_word)li1),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3656,a[2]=((C_word*)t0)[3],a[3]=((C_word)li2),tmp=(C_word)a,a+=4,tmp);
/* eval.scm:94: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}}

/* a3649 in k3640 in rename in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3650(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3650,c,av);}
/* eval.scm:95: ##sys#get */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[6];
tp(4,av2);}}

/* a3655 in k3640 in rename in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3656(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +5,c,3)))){
C_save_and_reclaim((void*)f_3656,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+5);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3663,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t3;
av2[2]=*((C_word*)lf[8]+1);
av2[3]=t2;
C_apply(4,av2);}}

/* k3661 in a3655 in k3640 in rename in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3663(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3663,c,av);}
if(C_truep(t1)){{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[7]+1);
av2[3]=((C_word*)t0)[3];
C_apply(4,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3668 in rename in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3670(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3670,c,av);}
/* eval.scm:94: find-id */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3603(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* lookup in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_3672(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3672,4,t0,t1,t2,t3);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3676,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:99: rename */
t5=((C_word*)((C_word*)t0)[2])[1];
f_3638(t5,t4,t2);}

/* k3674 in lookup in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3676(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3676,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3684,a[2]=t1,a[3]=t3,a[4]=((C_word)li6),tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_3684(t5,((C_word*)t0)[2],((C_word*)t0)[3],C_fix(0));}

/* loop in k3674 in lookup in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_3684(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_3684,4,t0,t1,t2,t3);}
a=C_alloc(8);
if(C_truep(C_i_nullp(t2))){
/* eval.scm:102: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=C_SCHEME_FALSE;
av2[3]=((C_word*)t0)[2];
C_values(4,av2);}}
else{
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3731,a[2]=((C_word*)t0)[2],a[3]=((C_word)li4),tmp=(C_word)a,a+=4,tmp);
t6=(
  f_3731(t5,t4,C_fix(0))
);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3701,a[2]=t3,a[3]=((C_word)li5),tmp=(C_word)a,a+=4,tmp);
/* eval.scm:102: g245 */
t8=t7;
f_3701(t8,t1,t6);}
else{
/* eval.scm:104: loop */
t9=t1;
t10=C_slot(t2,C_fix(1));
t11=C_fixnum_plus(t3,C_fix(1));
t1=t9;
t2=t10;
t3=t11;
goto loop;}}}

/* g245 in loop in k3674 in lookup in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_3701(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_3701,3,t0,t1,t2);}
/* eval.scm:103: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
C_values(4,av2);}}

/* loop in loop in k3674 in lookup in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static C_word C_fcall f_3731(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_nullp(t1))){
return(C_SCHEME_FALSE);}
else{
t3=C_slot(t1,C_fix(0));
t4=C_eqp(((C_word*)t0)[2],t3);
if(C_truep(t4)){
return(t2);}
else{
t6=C_slot(t1,C_fix(1));
t7=C_fixnum_plus(t2,C_fix(1));
t1=t6;
t2=t7;
goto loop;}}}

/* emit-trace-info in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static C_word C_fcall f_3761(C_word *a,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6){
C_word tmp;
C_word t7;
C_word t8;
C_stack_overflow_check;{}
if(C_truep(t1)){
t7=C_a_i_record4(&a,4,lf[10],t4,t5,t6);
return(C_emit_trace_info(t2,t3,t7,C_slot(*((C_word*)lf[11]+1),C_fix(14))));}
else{
t7=C_SCHEME_UNDEFINED;
return(t7);}}

/* emit-syntax-trace-info in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_3775(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3775,4,t1,t2,t3,t4);}
a=C_alloc(5);
if(C_truep(t2)){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3783,a[2]=t1,a[3]=t3,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:125: chicken.syntax#get-line-number */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[13]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[13]+1);
av2[1]=t5;
av2[2]=t3;
tp(3,av2);}}
else{
t5=C_SCHEME_UNDEFINED;
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k3781 in emit-syntax-trace-info in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3783(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3783,c,av);}
t2=(C_truep(t1)?t1:lf[12]);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_emit_trace_info(t2,((C_word*)t0)[3],((C_word*)t0)[4],C_slot(*((C_word*)lf[11]+1),C_fix(14)));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* decorate in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_3792(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,4)))){
C_save_and_reclaim_args((void *)trf_3792,3,t1,t2,t3);}
a=C_alloc(7);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3538,a[2]=((C_word)li10),tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3551,a[2]=t3,a[3]=((C_word)li11),tmp=(C_word)a,a+=4,tmp);
/* eval.scm:66: ##sys#decorate-lambda */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[18]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[18]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=t4;
av2[4]=t5;
tp(5,av2);}}

/* f_3800 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3800(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_3800,c,av);}
a=C_alloc(10);
t4=C_eqp(t2,t3);
t5=C_i_not(t4);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3807,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t5)){
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3810,a[2]=t6,a[3]=t3,a[4]=t1,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* eval.scm:136: chicken.syntax#get-line-number */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[13]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[13]+1);
av2[1]=t7;
av2[2]=t2;
tp(3,av2);}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k3805 */
static void C_ccall f_3807(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3807,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3808 */
static void C_ccall f_3810(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3810,c,av);}
if(C_truep(t1)){
if(C_truep(t1)){
/* eval.scm:137: ##sys#update-line-number-database! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[25]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[25]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
tp(4,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}
else{
if(C_truep(((C_word*)t0)[5])){
/* eval.scm:137: ##sys#update-line-number-database! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[25]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[25]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[5];
tp(4,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}}

/* compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_3825(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7){
C_word tmp;
C_word t8;
C_word t9;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(17,0,2)))){
C_save_and_reclaim_args((void *)trf_3825,8,t0,t1,t2,t3,t4,t5,t6,t7);}
a=C_alloc(17);
t8=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_3832,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=t3,a[6]=t6,a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[4],a[9]=t4,a[10]=t5,a[11]=t7,a[12]=((C_word*)t0)[5],a[13]=((C_word*)t0)[6],a[14]=((C_word*)t0)[7],a[15]=((C_word*)t0)[8],a[16]=((C_word*)t0)[9],tmp=(C_word)a,a+=17,tmp);
/* eval.scm:141: chicken.keyword#keyword? */
t9=*((C_word*)lf[155]+1);{
C_word av2[3];
av2[0]=t9;
av2[1]=t8;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3832(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,4)))){
C_save_and_reclaim((void *)f_3832,c,av);}
a=C_alloc(17);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3833,a[2]=((C_word*)t0)[2],a[3]=((C_word)li13),tmp=(C_word)a,a+=4,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(C_i_symbolp(((C_word*)t0)[2]))){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3845,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word)li14),tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3851,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],a[5]=((C_word)li23),tmp=(C_word)a,a+=6,tmp);
/* eval.scm:143: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_4052,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[10],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[11],a[10]=((C_word*)t0)[4],a[11]=((C_word*)t0)[7],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],tmp=(C_word)a,a+=17,tmp);
/* eval.scm:182: ##sys#number? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[154]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[154]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}}}

/* f_3833 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3833(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3833,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a3844 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3845(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3845,c,av);}
/* eval.scm:143: lookup */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3672(t2,t1,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3851(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_3851,c,av);}
a=C_alloc(12);
if(C_truep(C_i_not(t2))){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3861,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t5=C_i_symbolp(t3);
if(C_truep(C_i_not(t5))){
t6=t4;{
C_word *av2=av;
av2[0]=t6;
av2[1]=((C_word*)t0)[2];
f_3861(2,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3944,a[2]=((C_word*)t0)[2],a[3]=t4,a[4]=t3,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[3],tmp=(C_word)a,a+=7,tmp);
/* eval.scm:146: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t6;
tp(2,av2);}}}
else{
switch(t2){
case C_fix(0):
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3955,a[2]=t3,a[3]=((C_word)li18),tmp=(C_word)a,a+=4,tmp);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}
case C_fix(1):
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3970,a[2]=t3,a[3]=((C_word)li19),tmp=(C_word)a,a+=4,tmp);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}
case C_fix(2):
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3989,a[2]=t3,a[3]=((C_word)li20),tmp=(C_word)a,a+=4,tmp);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}
case C_fix(3):
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4012,a[2]=t3,a[3]=((C_word)li21),tmp=(C_word)a,a+=4,tmp);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}
default:
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4033,a[2]=t2,a[3]=t3,a[4]=((C_word)li22),tmp=(C_word)a,a+=5,tmp);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}}

/* k3859 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3861(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_3861,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3864,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3891,a[2]=t1,a[3]=((C_word*)t0)[4],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(*((C_word*)lf[2]+1))){
t4=C_i_not(t1);
if(C_truep(t4)){
t5=t3;
f_3891(t5,t4);}
else{
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3912,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:153: ##sys#symbol-has-toplevel-binding? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[21]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[21]+1);
av2[1]=t5;
av2[2]=t1;
tp(3,av2);}}}
else{
t4=t3;
f_3891(t4,C_SCHEME_FALSE);}}

/* k3862 in k3859 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_3864(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_3864,2,t0,t1);}
a=C_alloc(4);
if(C_truep(C_i_not(((C_word*)t0)[2]))){
t2=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3871,a[2]=((C_word*)t0)[4],a[3]=((C_word)li15),tmp=(C_word)a,a+=4,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3881,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:159: ##sys#symbol-has-toplevel-binding? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[21]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[21]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}}

/* f_3871 in k3862 in k3859 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3871(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3871,c,av);}
/* eval.scm:158: ##sys#error */
t3=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=lf[20];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k3879 in k3862 in k3859 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3881(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3881,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3882,a[2]=((C_word*)t0)[2],a[3]=((C_word)li16),tmp=(C_word)a,a+=4,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3887,a[2]=((C_word*)t0)[2],a[3]=((C_word)li17),tmp=(C_word)a,a+=4,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* f_3882 in k3879 in k3862 in k3859 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3882,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_slot(((C_word*)t0)[2],C_fix(0));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_3887 in k3879 in k3862 in k3859 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3887(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3887,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fast_retrieve(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3889 in k3859 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_3891(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,1)))){
C_save_and_reclaim_args((void *)trf_3891,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_cons(&a,2,t2,*((C_word*)lf[2]+1));
t4=C_mutate((C_word*)lf[2]+1 /* (set! ##sys#unbound-in-eval ...) */,t3);
t5=((C_word*)t0)[4];
f_3864(t5,t4);}
else{
t2=((C_word*)t0)[4];
f_3864(t2,C_SCHEME_UNDEFINED);}}

/* k3910 in k3859 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3912(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3912,c,av);}
t2=((C_word*)t0)[2];
f_3891(t2,C_i_not(t1));}

/* k3942 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3944(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3944,c,av);}
if(C_truep(C_i_assq(((C_word*)t0)[2],t1))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
f_3861(2,av2);}}
else{
if(C_truep(C_i_not(((C_word*)t0)[5]))){
/* eval.scm:148: ##sys#alias-global-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[22]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[22]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[6];
tp(5,av2);}}
else{
t2=C_eqp(((C_word*)t0)[2],((C_word*)t0)[4]);
t3=C_i_not(t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?((C_word*)t0)[4]:C_SCHEME_FALSE);
f_3861(2,av2);}}}}

/* f_3955 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3955(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3955,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_slot(C_slot(t2,C_fix(0)),((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* f_3970 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3970(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3970,c,av);}
t3=C_slot(t2,C_fix(1));
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_slot(C_slot(t3,C_fix(0)),((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* f_3989 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_3989(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3989,c,av);}
t3=C_slot(t2,C_fix(1));
t4=C_slot(t3,C_fix(1));
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_slot(C_slot(t4,C_fix(0)),((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* f_4012 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4012(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4012,c,av);}
t3=C_slot(t2,C_fix(1));
t4=C_slot(t3,C_fix(1));
t5=C_slot(t4,C_fix(1));
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_slot(C_slot(t5,C_fix(0)),((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* f_4033 in a3850 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4033(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4033,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_slot(C_u_i_list_ref(t2,((C_word*)t0)[2]),((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4052(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,2)))){
C_save_and_reclaim((void *)f_4052,c,av);}
a=C_alloc(21);
if(C_truep(t1)){
switch(((C_word*)t0)[2]){
case C_fix(-1):
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4059,a[2]=((C_word)li24),tmp=(C_word)a,a+=3,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}
case C_fix(0):
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4067,a[2]=((C_word)li25),tmp=(C_word)a,a+=3,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}
case C_fix(1):
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4075,a[2]=((C_word)li26),tmp=(C_word)a,a+=3,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}
case C_fix(2):
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4083,a[2]=((C_word)li27),tmp=(C_word)a,a+=3,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}
default:
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4085,a[2]=((C_word*)t0)[2],a[3]=((C_word)li28),tmp=(C_word)a,a+=4,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}
else{
if(C_truep(C_booleanp(((C_word*)t0)[2]))){
if(C_truep(((C_word*)t0)[2])){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4104,a[2]=((C_word)li29),tmp=(C_word)a,a+=3,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4106,a[2]=((C_word)li30),tmp=(C_word)a,a+=3,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}
else{
t2=C_charp(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_4116,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],tmp=(C_word)a,a+=17,tmp);
if(C_truep(t2)){
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
f_4116(2,av2);}}
else{
t4=C_eofp(((C_word*)t0)[2]);
if(C_truep(t4)){
t5=t3;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
f_4116(2,av2);}}
else{
t5=C_bwpp(((C_word*)t0)[2]);
if(C_truep(t5)){
t6=t3;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
f_4116(2,av2);}}
else{
t6=C_i_stringp(((C_word*)t0)[2]);
if(C_truep(t6)){
t7=t3;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
f_4116(2,av2);}}
else{
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7343,a[2]=t3,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:198: chicken.blob#blob? */
t8=*((C_word*)lf[153]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}}}}}}}

/* f_4059 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4059(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4059,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(-1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4067 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4067(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4067,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(0);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4075 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4075(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4075,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4083 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4083(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4083,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(2);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4085 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4085(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4085,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4104 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4104(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4104,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4106 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4106(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4106,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4116(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,4)))){
C_save_and_reclaim((void *)f_4116,c,av);}
a=C_alloc(16);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4117,a[2]=((C_word*)t0)[2],a[3]=((C_word)li31),tmp=(C_word)a,a+=4,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_i_pairp(((C_word*)t0)[2]);
if(C_truep(C_i_not(t2))){
/* eval.scm:203: ##sys#syntax-error/context */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[23]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[23]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=lf[24];
av2[3]=((C_word*)t0)[2];
tp(4,av2);}}
else{
t3=C_slot(((C_word*)t0)[2],C_fix(0));
if(C_truep(C_i_symbolp(t3))){
t4=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_4136,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],tmp=(C_word)a,a+=16,tmp);
/* eval.scm:205: emit-syntax-trace-info */
f_3775(t4,((C_word*)t0)[7],((C_word*)t0)[2],((C_word*)t0)[8]);}
else{
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7310,a[2]=((C_word*)t0)[15],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:665: emit-syntax-trace-info */
f_3775(t4,((C_word*)t0)[7],((C_word*)t0)[2],((C_word*)t0)[8]);}}}}

/* f_4117 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4117(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4117,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4136(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_4136,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_4139,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],tmp=(C_word)a,a+=16,tmp);
/* eval.scm:206: chicken.syntax#get-line-number */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[13]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[13]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}

/* k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4139(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(38,c,4)))){
C_save_and_reclaim((void *)f_4139,c,av);}
a=C_alloc(38);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3800,a[2]=t1,a[3]=((C_word)li32),tmp=(C_word)a,a+=4,tmp);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_SCHEME_FALSE;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_4145,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],tmp=(C_word)a,a+=16,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7289,a[2]=t6,a[3]=t4,a[4]=((C_word)li134),tmp=(C_word)a,a+=5,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7294,a[2]=((C_word*)t0)[2],a[3]=((C_word)li135),tmp=(C_word)a,a+=4,tmp);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7304,a[2]=t4,a[3]=t6,a[4]=((C_word)li136),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:207: ##sys#dynamic-wind */
t11=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t11;
av2[1]=t7;
av2[2]=t8;
av2[3]=t9;
av2[4]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(5,av2);}}

/* k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4145(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,7)))){
C_save_and_reclaim((void *)f_4145,c,av);}
a=C_alloc(16);
t2=C_eqp(t1,((C_word*)t0)[2]);
if(C_truep(C_i_not(t2))){
/* eval.scm:212: compile */
t3=((C_word*)((C_word*)t0)[3])[1];
f_3825(t3,((C_word*)t0)[4],t1,((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],((C_word*)t0)[8],((C_word*)t0)[9]);}
else{
t3=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_4160,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],tmp=(C_word)a,a+=16,tmp);
/* eval.scm:213: rename */
t4=((C_word*)((C_word*)t0)[14])[1];
f_3638(t4,t3,C_slot(((C_word*)t0)[2],C_fix(0)));}}

/* k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4160(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(25,c,7)))){
C_save_and_reclaim((void *)f_4160,c,av);}
a=C_alloc(25);
t2=C_eqp(t1,lf[26]);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4169,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:219: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_cadr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=C_eqp(t1,lf[28]);
if(C_truep(t3)){
t4=C_i_cadr(((C_word*)t0)[3]);
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4255,a[2]=t4,a[3]=((C_word)li41),tmp=(C_word)a,a+=4,tmp);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_eqp(t1,lf[29]);
if(C_truep(t4)){
/* eval.scm:235: compile */
t5=((C_word*)((C_word*)t0)[4])[1];
f_3825(t5,((C_word*)t0)[2],C_i_cadr(((C_word*)t0)[3]),((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],((C_word*)t0)[8],C_SCHEME_FALSE);}
else{
t5=C_eqp(t1,lf[30]);
if(C_truep(t5)){
/* eval.scm:238: compile */
t6=((C_word*)((C_word*)t0)[4])[1];
f_3825(t6,((C_word*)t0)[2],C_i_cadr(((C_word*)t0)[3]),((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[7],((C_word*)t0)[8],C_SCHEME_FALSE);}
else{
t6=C_eqp(t1,lf[31]);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4289,a[2]=((C_word)li42),tmp=(C_word)a,a+=3,tmp);
t8=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t7=C_eqp(t1,lf[32]);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4299,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:243: compile */
t9=((C_word*)((C_word*)t0)[4])[1];
f_3825(t9,t8,C_i_cadr(((C_word*)t0)[3]),((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[7],((C_word*)t0)[8],C_SCHEME_FALSE);}
else{
t8=C_eqp(t1,lf[34]);
if(C_truep(t8)){
t9=C_slot(((C_word*)t0)[3],C_fix(1));
t10=C_i_length(t9);
switch(t10){
case C_fix(0):
/* eval.scm:254: compile */
t11=((C_word*)((C_word*)t0)[4])[1];
f_3825(t11,((C_word*)t0)[2],lf[35],((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[7],((C_word*)t0)[8],((C_word*)t0)[9]);
case C_fix(1):
/* eval.scm:255: compile */
t11=((C_word*)((C_word*)t0)[4])[1];
f_3825(t11,((C_word*)t0)[2],C_slot(t9,C_fix(0)),((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[7],((C_word*)t0)[8],((C_word*)t0)[9]);
case C_fix(2):
t11=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4387,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=t9,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],tmp=(C_word)a,a+=9,tmp);
/* eval.scm:256: compile */
t12=((C_word*)((C_word*)t0)[4])[1];
f_3825(t12,t11,C_slot(t9,C_fix(0)),((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[7],((C_word*)t0)[8],((C_word*)t0)[9]);
default:
t11=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4409,a[2]=((C_word*)t0)[2],a[3]=t9,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],tmp=(C_word)a,a+=9,tmp);
/* eval.scm:260: compile */
t12=((C_word*)((C_word*)t0)[4])[1];
f_3825(t12,t11,C_slot(t9,C_fix(0)),((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[7],((C_word*)t0)[8],((C_word*)t0)[9]);}}
else{
t9=C_eqp(t1,lf[36]);
if(C_truep(t9)){
t10=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4461,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[3],tmp=(C_word)a,a+=8,tmp);
if(C_truep(((C_word*)t0)[9])){
t11=t10;{
C_word *av2=av;
av2[0]=t11;
av2[1]=C_SCHEME_UNDEFINED;
f_4461(2,av2);}}
else{
/* eval.scm:267: ##sys#error */
t11=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t11;
av2[1]=t10;
av2[2]=lf[41];
av2[3]=C_i_cadr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t11+1)))(4,av2);}}}
else{
t10=C_eqp(t1,lf[42]);
if(C_truep(t10)){
t11=C_i_cadr(((C_word*)t0)[3]);
t12=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4492,a[2]=((C_word*)t0)[10],a[3]=t11,a[4]=((C_word*)t0)[5],a[5]=((C_word)li46),tmp=(C_word)a,a+=6,tmp);
t13=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_4498,a[2]=((C_word*)t0)[11],a[3]=((C_word*)t0)[12],a[4]=t11,a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[7],a[10]=((C_word)li51),tmp=(C_word)a,a+=11,tmp);
/* eval.scm:274: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=t12;
av2[3]=t13;
C_call_with_values(4,av2);}}
else{
t11=C_eqp(t1,lf[47]);
if(C_truep(t11)){
t12=C_i_cadr(((C_word*)t0)[3]);
t13=C_i_length(t12);
t14=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t15=t14;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=((C_word*)t16)[1];
t18=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_4607,a[2]=((C_word*)t0)[5],a[3]=t13,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=t12,a[9]=((C_word*)t0)[12],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[3],tmp=(C_word)a,a+=12,tmp);
t19=C_SCHEME_UNDEFINED;
t20=(*a=C_VECTOR_TYPE|1,a[1]=t19,tmp=(C_word)a,a+=2,tmp);
t21=C_set_block_item(t20,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5046,a[2]=t16,a[3]=t20,a[4]=t17,a[5]=((C_word)li64),tmp=(C_word)a,a+=6,tmp));
t22=((C_word*)t20)[1];
f_5046(t22,t18,t12);}
else{
t12=C_eqp(t1,lf[56]);
if(C_truep(t12)){
t13=C_i_cadr(((C_word*)t0)[3]);
t14=C_u_i_cdr(((C_word*)t0)[3]);
t15=C_u_i_cdr(t14);
t16=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t17=t16;
t18=(*a=C_VECTOR_TYPE|1,a[1]=t17,tmp=(C_word)a,a+=2,tmp);
t19=((C_word*)t18)[1];
t20=C_i_check_list_2(t13,lf[48]);
t21=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_5119,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=t15,a[9]=t13,tmp=(C_word)a,a+=10,tmp);
t22=C_SCHEME_UNDEFINED;
t23=(*a=C_VECTOR_TYPE|1,a[1]=t22,tmp=(C_word)a,a+=2,tmp);
t24=C_set_block_item(t23,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5191,a[2]=t18,a[3]=t23,a[4]=t19,a[5]=((C_word)li66),tmp=(C_word)a,a+=6,tmp));
t25=((C_word*)t23)[1];
f_5191(t25,t21,t13);}
else{
t13=C_eqp(t1,lf[59]);
if(C_truep(t13)){
t14=C_i_cadr(((C_word*)t0)[3]);
t15=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t16=t15;
t17=(*a=C_VECTOR_TYPE|1,a[1]=t16,tmp=(C_word)a,a+=2,tmp);
t18=((C_word*)t17)[1];
t19=C_i_check_list_2(t14,lf[48]);
t20=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_5241,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t14,tmp=(C_word)a,a+=10,tmp);
t21=C_SCHEME_UNDEFINED;
t22=(*a=C_VECTOR_TYPE|1,a[1]=t21,tmp=(C_word)a,a+=2,tmp);
t23=C_set_block_item(t22,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5497,a[2]=t17,a[3]=t22,a[4]=t18,a[5]=((C_word)li71),tmp=(C_word)a,a+=6,tmp));
t24=((C_word*)t22)[1];
f_5497(t24,t20,t14);}
else{
t14=C_eqp(t1,lf[61]);
if(C_truep(t14)){
t15=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_5538,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[13],a[6]=((C_word*)t0)[12],a[7]=((C_word*)t0)[11],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[2],tmp=(C_word)a,a+=10,tmp);
t16=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5981,a[2]=t15,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:377: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t16;
tp(2,av2);}}
else{
t15=C_eqp(t1,lf[73]);
if(C_truep(t15)){
t16=*((C_word*)lf[9]+1);
t17=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_5990,a[2]=t16,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[2],tmp=(C_word)a,a+=9,tmp);
t18=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t19=t18;
t20=(*a=C_VECTOR_TYPE|1,a[1]=t19,tmp=(C_word)a,a+=2,tmp);
t21=((C_word*)t20)[1];
t22=C_i_cadr(((C_word*)t0)[3]);
t23=C_i_check_list_2(t22,lf[48]);
t24=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6082,a[2]=t17,tmp=(C_word)a,a+=3,tmp);
t25=C_SCHEME_UNDEFINED;
t26=(*a=C_VECTOR_TYPE|1,a[1]=t25,tmp=(C_word)a,a+=2,tmp);
t27=C_set_block_item(t26,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6088,a[2]=t20,a[3]=t26,a[4]=t21,a[5]=((C_word)li107),tmp=(C_word)a,a+=6,tmp));
t28=((C_word*)t26)[1];
f_6088(t28,t24,t22);}
else{
t16=C_eqp(t1,lf[77]);
if(C_truep(t16)){
t17=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t18=t17;
t19=(*a=C_VECTOR_TYPE|1,a[1]=t18,tmp=(C_word)a,a+=2,tmp);
t20=((C_word*)t19)[1];
t21=C_i_cadr(((C_word*)t0)[3]);
t22=C_i_check_list_2(t21,lf[48]);
t23=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6165,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
t24=C_SCHEME_UNDEFINED;
t25=(*a=C_VECTOR_TYPE|1,a[1]=t24,tmp=(C_word)a,a+=2,tmp);
t26=C_set_block_item(t25,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6260,a[2]=t19,a[3]=t25,a[4]=t20,a[5]=((C_word)li113),tmp=(C_word)a,a+=6,tmp));
t27=((C_word*)t25)[1];
f_6260(t27,t23,t21);}
else{
t17=C_eqp(t1,lf[79]);
if(C_truep(t17)){
t18=C_i_cadr(((C_word*)t0)[3]);
t19=C_i_caddr(((C_word*)t0)[3]);
t20=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6307,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=t19,a[8]=((C_word*)t0)[11],a[9]=t18,a[10]=((C_word*)t0)[12],tmp=(C_word)a,a+=11,tmp);
/* eval.scm:509: rename */
t21=((C_word*)((C_word*)t0)[14])[1];
f_3638(t21,t20,t18);}
else{
t18=C_eqp(t1,lf[86]);
if(C_truep(t18)){
/* eval.scm:523: compile */
t19=((C_word*)((C_word*)t0)[4])[1];
f_3825(t19,((C_word*)t0)[2],lf[87],((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[7],((C_word*)t0)[8],C_SCHEME_FALSE);}
else{
t19=C_eqp(t1,lf[88]);
if(C_truep(t19)){
t20=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6373,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],tmp=(C_word)a,a+=7,tmp);
t21=C_i_cddr(((C_word*)t0)[3]);
t22=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6381,a[2]=t20,a[3]=t21,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:527: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t22;
tp(2,av2);}}
else{
t20=C_eqp(t1,lf[89]);
if(C_truep(t20)){
t21=C_i_cadr(((C_word*)t0)[3]);
t22=C_i_caddr(((C_word*)t0)[3]);
t23=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6400,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[3],a[8]=((C_word)li117),tmp=(C_word)a,a+=9,tmp);
/* eval.scm:531: ##sys#include-forms-from-file */
t24=*((C_word*)lf[91]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t24;
av2[1]=((C_word*)t0)[2];
av2[2]=t21;
av2[3]=t22;
av2[4]=t23;
((C_proc)(void*)(*((C_word*)t24+1)))(5,av2);}}
else{
t21=C_eqp(t1,lf[92]);
if(C_truep(t21)){
t22=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t23=t22;
t24=(*a=C_VECTOR_TYPE|1,a[1]=t23,tmp=(C_word)a,a+=2,tmp);
t25=((C_word*)t24)[1];
t26=C_i_cadr(((C_word*)t0)[3]);
t27=C_i_check_list_2(t26,lf[48]);
t28=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6478,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[9],a[8]=((C_word*)t0)[2],tmp=(C_word)a,a+=9,tmp);
t29=C_SCHEME_UNDEFINED;
t30=(*a=C_VECTOR_TYPE|1,a[1]=t29,tmp=(C_word)a,a+=2,tmp);
t31=C_set_block_item(t30,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6494,a[2]=t24,a[3]=t30,a[4]=t25,a[5]=((C_word)li119),tmp=(C_word)a,a+=6,tmp));
t32=((C_word*)t30)[1];
f_6494(t32,t28,t26);}
else{
t22=C_eqp(t1,lf[96]);
if(C_truep(t22)){
t23=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6535,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* eval.scm:553: chicken.syntax#strip-syntax */
t24=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t24;
av2[1]=t23;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t24+1)))(3,av2);}}
else{
t23=C_eqp(t1,lf[110]);
if(C_truep(t23)){
t24=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6859,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:605: rename */
t25=((C_word*)((C_word*)t0)[14])[1];
f_3638(t25,t24,lf[71]);}
else{
t24=C_eqp(t1,lf[111]);
if(C_truep(t24)){
t25=C_i_cadr(((C_word*)t0)[3]);
t26=C_a_i_list(&a,2,lf[26],t25);
t27=C_a_i_list(&a,2,lf[101],t26);
/* eval.scm:608: compile */
t28=((C_word*)((C_word*)t0)[4])[1];
f_3825(t28,((C_word*)t0)[2],t27,((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[7],((C_word*)t0)[8],C_SCHEME_FALSE);}
else{
t25=C_eqp(t1,lf[112]);
if(C_truep(t25)){
t26=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6893,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],tmp=(C_word)a,a+=7,tmp);
/* eval.scm:611: chicken.load#load-extension */
t27=*((C_word*)lf[114]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t27;
av2[1]=t26;
av2[2]=C_i_cadr(((C_word*)t0)[3]);
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t27+1)))(5,av2);}}
else{
t26=C_eqp(t1,lf[115]);
if(C_truep(t26)){
t27=C_i_cadr(((C_word*)t0)[3]);
t28=C_u_i_cdr(((C_word*)t0)[3]);
t29=C_i_pairp(C_u_i_cdr(t28));
t30=(C_truep(t29)?C_i_caddr(((C_word*)t0)[3]):C_SCHEME_FALSE);
t31=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6919,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],tmp=(C_word)a,a+=7,tmp);
/* eval.scm:617: ##sys#process-require */
t32=*((C_word*)lf[116]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t32;
av2[1]=t31;
av2[2]=t27;
av2[3]=t30;
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t32+1)))(5,av2);}}
else{
t27=C_eqp(t1,lf[117]);
t28=(C_truep(t27)?t27:C_eqp(t1,lf[118]));
if(C_truep(t28)){
t29=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6940,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[9],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:620: ##sys#eval/meta */
t30=*((C_word*)lf[76]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t30;
av2[1]=t29;
av2[2]=C_i_cadr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t30+1)))(3,av2);}}
else{
t29=C_eqp(t1,lf[120]);
if(C_truep(t29)){
/* eval.scm:624: compile */
t30=((C_word*)((C_word*)t0)[4])[1];
f_3825(t30,((C_word*)t0)[2],C_i_cadr(((C_word*)t0)[3]),((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[7],((C_word*)t0)[8],((C_word*)t0)[9]);}
else{
t30=C_eqp(t1,lf[121]);
t31=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6969,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[9],a[8]=t1,a[9]=((C_word*)t0)[3],a[10]=((C_word*)t0)[14],a[11]=((C_word*)t0)[15],a[12]=((C_word*)t0)[6],tmp=(C_word)a,a+=13,tmp);
if(C_truep(t30)){
t32=t31;
f_6969(t32,t30);}
else{
t32=C_eqp(t1,lf[148]);
t33=t31;
f_6969(t33,(C_truep(t32)?t32:C_eqp(t1,lf[149])));}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

/* k4167 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4169(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4169,c,av);}
a=C_alloc(4);
switch(t1){
case C_fix(-1):
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4176,a[2]=((C_word)li33),tmp=(C_word)a,a+=3,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}
case C_fix(0):
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4184,a[2]=((C_word)li34),tmp=(C_word)a,a+=3,tmp);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}
case C_fix(1):
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4192,a[2]=((C_word)li35),tmp=(C_word)a,a+=3,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}
case C_fix(2):
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4200,a[2]=((C_word)li36),tmp=(C_word)a,a+=3,tmp);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}
case C_SCHEME_TRUE:
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4208,a[2]=((C_word)li37),tmp=(C_word)a,a+=3,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}
case C_SCHEME_FALSE:
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4216,a[2]=((C_word)li38),tmp=(C_word)a,a+=3,tmp);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}
default:
t2=C_eqp(t1,C_SCHEME_END_OF_LIST);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4224,a[2]=((C_word)li39),tmp=(C_word)a,a+=3,tmp):(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4226,a[2]=t1,a[3]=((C_word)li40),tmp=(C_word)a,a+=4,tmp));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* f_4176 in k4167 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4176(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4176,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(-1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4184 in k4167 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4184(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4184,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(0);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4192 in k4167 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4192(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4192,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4200 in k4167 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4200(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4200,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(2);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4208 in k4167 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4208(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4208,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4216 in k4167 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4216(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4216,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4224 in k4167 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4224(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4224,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4226 in k4167 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4226(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4226,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4255 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4255(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4255,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4289 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4289(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4289,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4297 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4299(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,7)))){
C_save_and_reclaim((void *)f_4299,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4302,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* eval.scm:244: compile */
t3=((C_word*)((C_word*)t0)[4])[1];
f_3825(t3,t2,C_i_caddr(((C_word*)t0)[3]),((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k4300 in k4297 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4302(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,7)))){
C_save_and_reclaim((void *)f_4302,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4305,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=C_i_cdddr(((C_word*)t0)[4]);
if(C_truep(C_i_pairp(t3))){
/* eval.scm:246: compile */
t4=((C_word*)((C_word*)t0)[5])[1];
f_3825(t4,t2,C_i_cadddr(((C_word*)t0)[4]),((C_word*)t0)[6],C_SCHEME_FALSE,((C_word*)t0)[7],((C_word*)t0)[8],C_SCHEME_FALSE);}
else{
/* eval.scm:247: compile */
t4=((C_word*)((C_word*)t0)[5])[1];
f_3825(t4,t2,lf[33],((C_word*)t0)[6],C_SCHEME_FALSE,((C_word*)t0)[7],((C_word*)t0)[8],C_SCHEME_FALSE);}}

/* k4303 in k4300 in k4297 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4305(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4305,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4306,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word)li43),tmp=(C_word)a,a+=6,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4306 in k4303 in k4300 in k4297 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4306(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4306,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4313,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4311 */
static void C_ccall f_4313(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4313,c,av);}
if(C_truep(t1)){
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
t2=((C_word*)t0)[5];{
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

/* k4385 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4387(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,7)))){
C_save_and_reclaim((void *)f_4387,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4390,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:257: compile */
t3=((C_word*)((C_word*)t0)[3])[1];
f_3825(t3,t2,C_i_cadr(((C_word*)t0)[4]),((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[6],((C_word*)t0)[7],((C_word*)t0)[8]);}

/* k4388 in k4385 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4390(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_4390,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4391,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word)li44),tmp=(C_word)a,a+=5,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4391 in k4388 in k4385 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4391(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4391,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4395,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4393 */
static void C_ccall f_4395(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4395,c,av);}
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

/* k4407 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4409(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,7)))){
C_save_and_reclaim((void *)f_4409,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4412,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* eval.scm:261: compile */
t3=((C_word*)((C_word*)t0)[4])[1];
f_3825(t3,t2,C_i_cadr(((C_word*)t0)[3]),((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[6],((C_word*)t0)[7],((C_word*)t0)[8]);}

/* k4410 in k4407 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4412(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,7)))){
C_save_and_reclaim((void *)f_4412,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4415,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=C_slot(((C_word*)t0)[4],C_fix(1));
t4=C_slot(t3,C_fix(1));
t5=C_a_i_cons(&a,2,lf[34],t4);
/* eval.scm:262: compile */
t6=((C_word*)((C_word*)t0)[5])[1];
f_3825(t6,t2,t5,((C_word*)t0)[6],C_SCHEME_FALSE,((C_word*)t0)[7],((C_word*)t0)[8],((C_word*)t0)[9]);}

/* k4413 in k4410 in k4407 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4415(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4415,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4416,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li45),tmp=(C_word)a,a+=6,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4416 in k4413 in k4410 in k4407 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4416(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4416,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4420,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4418 */
static void C_ccall f_4420(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4420,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4423,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=((C_word*)t0)[5];{
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

/* k4421 in k4418 */
static void C_ccall f_4423(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4423,c,av);}
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

/* k4459 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4461(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_4461,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4464,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* eval.scm:268: ##sys#put/restore! */
t3=*((C_word*)lf[38]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cadr(((C_word*)t0)[7]);
av2[3]=lf[39];
av2[4]=lf[40];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4462 in k4459 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4464(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4464,c,av);}
/* eval.scm:269: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],lf[37],((C_word*)t0)[4],C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_FALSE);}

/* a4491 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4492(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4492,c,av);}
/* eval.scm:274: lookup */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3672(t2,t1,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* a4497 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4498(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,7)))){
C_save_and_reclaim((void *)f_4498,c,av);}
a=C_alloc(9);
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4502,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=t3,a[8]=((C_word*)t0)[5],tmp=(C_word)a,a+=9,tmp);
/* eval.scm:275: compile */
t5=((C_word*)((C_word*)t0)[6])[1];
f_3825(t5,t4,C_i_caddr(((C_word*)t0)[7]),((C_word*)t0)[8],((C_word*)t0)[4],((C_word*)t0)[9],((C_word*)t0)[5],C_SCHEME_FALSE);}

/* k4500 in a4497 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4502(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_4502,c,av);}
a=C_alloc(13);
if(C_truep(C_i_not(((C_word*)t0)[2]))){
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4511,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=t1,a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
if(C_truep(*((C_word*)lf[44]+1))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4553,a[2]=((C_word*)t0)[6],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:278: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t3;
tp(2,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_4511(2,av2);}}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(C_i_zerop(((C_word*)t0)[2]))?(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4558,a[2]=((C_word*)t0)[7],a[3]=t1,a[4]=((C_word)li49),tmp=(C_word)a,a+=5,tmp):(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4571,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[7],a[4]=t1,a[5]=((C_word)li50),tmp=(C_word)a,a+=6,tmp));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k4509 in k4500 in a4497 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4511(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_4511,c,av);}
a=C_alloc(5);
if(C_truep(((C_word*)t0)[2])){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4515,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word)li47),tmp=(C_word)a,a+=5,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4522,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:284: ##sys#alias-global-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[22]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[22]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[8];
tp(5,av2);}}}

/* f_4515 in k4509 in k4500 in a4497 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4515(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_4515,c,av);}
/* eval.scm:283: ##sys#error */
t3=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=lf[0];
av2[3]=lf[43];
av2[4]=((C_word*)t0)[2];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4520 in k4509 in k4500 in a4497 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4522(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_4522,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4523,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word)li48),tmp=(C_word)a,a+=5,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4523 in k4520 in k4509 in k4500 in a4497 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4523(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4523,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4527,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4525 */
static void C_ccall f_4527(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4527,c,av);}
t2=C_i_persist_symbol(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_setslot(((C_word*)t0)[2],C_fix(0),t1);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4551 in k4500 in a4497 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4553(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4553,c,av);}
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=C_i_cdr(t2);
if(C_truep(C_i_symbolp(t3))){
/* eval.scm:280: ##sys#notice */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[45]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[45]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=lf[46];
av2[3]=((C_word*)t0)[2];
tp(4,av2);}}
else{
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_4511(2,av2);}}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_4511(2,av2);}}}

/* f_4558 in k4500 in a4497 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4558(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4558,c,av);}
a=C_alloc(5);
t3=C_slot(t2,C_fix(0));
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4570,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k4568 */
static void C_ccall f_4570(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4570,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_setslot(((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4571 in k4500 in a4497 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4571(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4571,c,av);}
a=C_alloc(5);
t3=C_u_i_list_ref(t2,((C_word*)t0)[2]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4580,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k4578 */
static void C_ccall f_4580(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4580,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_setslot(((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4607(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(26,c,3)))){
C_save_and_reclaim((void *)f_4607,c,av);}
a=C_alloc(26);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(t1,lf[48]);
t7=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_4616,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5012,a[2]=t4,a[3]=t9,a[4]=t5,a[5]=((C_word)li63),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_5012(t11,t7,t1);}

/* k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4616(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(22,c,2)))){
C_save_and_reclaim((void *)f_4616,c,av);}
a=C_alloc(22);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_4622,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t2,a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5010,a[2]=t3,a[3]=((C_word*)t0)[6],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:301: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t4;
tp(2,av2);}}

/* k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4622(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(33,c,4)))){
C_save_and_reclaim((void *)f_4622,c,av);}
a=C_alloc(33);
t2=*((C_word*)lf[9]+1);
t3=t1;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_SCHEME_TRUE;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4625,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4963,a[2]=t4,a[3]=t6,a[4]=t2,a[5]=((C_word)li60),tmp=(C_word)a,a+=6,tmp);
t9=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4980,a[2]=((C_word*)t0)[10],a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[11],a[5]=((C_word*)t0)[12],a[6]=((C_word*)t0)[13],a[7]=((C_word)li61),tmp=(C_word)a,a+=8,tmp);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4998,a[2]=t4,a[3]=t2,a[4]=((C_word)li62),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:302: ##sys#dynamic-wind */
t11=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t11;
av2[1]=t7;
av2[2]=t8;
av2[3]=t9;
av2[4]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(5,av2);}}

/* k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4625(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(26,c,3)))){
C_save_and_reclaim((void *)f_4625,c,av);}
a=C_alloc(26);
switch(((C_word*)t0)[2]){
case C_fix(1):
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4634,a[2]=t1,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4655,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:307: scheme#cadar */
t4=*((C_word*)lf[49]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[9];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}
case C_fix(2):
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4668,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4704,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:310: scheme#cadar */
t4=*((C_word*)lf[49]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[9];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}
case C_fix(3):
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4717,a[2]=((C_word*)t0)[9],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4771,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:314: scheme#cadar */
t4=*((C_word*)lf[49]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[9];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}
case C_fix(4):
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4784,a[2]=((C_word*)t0)[9],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4853,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:322: scheme#cadar */
t4=*((C_word*)lf[49]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[9];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}
default:
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4861,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word)li56),tmp=(C_word)a,a+=7,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4874,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4921,a[2]=t4,a[3]=t9,a[4]=t6,a[5]=t5,a[6]=((C_word)li59),tmp=(C_word)a,a+=7,tmp));
t11=((C_word*)t9)[1];
f_4921(t11,t7,((C_word*)t0)[9]);}}

/* k4632 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4634(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_4634,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4635,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word)li52),tmp=(C_word)a,a+=5,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* f_4635 in k4632 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4635(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4635,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4651,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4649 */
static void C_ccall f_4651(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4651,c,av);}
a=C_alloc(5);
t2=C_a_i_vector1(&a,1,t1);
t3=C_a_i_cons(&a,2,t2,((C_word*)t0)[2]);
t4=((C_word*)t0)[3];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4653 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4655(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4655,c,av);}
/* eval.scm:307: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_i_car(((C_word*)t0)[5]),((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k4666 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4668(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_4668,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4671,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4696,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:311: scheme#cadadr */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[9];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4669 in k4666 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4671(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4671,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4672,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word)li53),tmp=(C_word)a,a+=6,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4672 in k4669 in k4666 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4672(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4672,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4688,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4686 */
static void C_ccall f_4688(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_4688,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4692,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[5];{
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

/* k4690 in k4686 */
static void C_ccall f_4692(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_4692,c,av);}
a=C_alloc(6);
t2=C_a_i_vector2(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,t2,((C_word*)t0)[3]);
t4=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[5];
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4694 in k4666 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4696(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4696,c,av);}
/* eval.scm:311: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_i_cadr(((C_word*)t0)[5]),((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k4702 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4704(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4704,c,av);}
/* eval.scm:310: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_i_car(((C_word*)t0)[5]),((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k4715 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4717(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_4717,c,av);}
a=C_alloc(19);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_4720,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4763,a[2]=((C_word*)t0)[5],a[3]=t2,a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[9],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:315: scheme#cadadr */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4718 in k4715 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4720(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_4720,c,av);}
a=C_alloc(14);
t2=C_i_cddr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4726,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4755,a[2]=((C_word*)t0)[6],a[3]=t3,a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[10],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:317: scheme#cadar */
t5=*((C_word*)lf[49]+1);{
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

/* k4724 in k4718 in k4715 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4726(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_4726,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4727,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word)li54),tmp=(C_word)a,a+=7,tmp);
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* f_4727 in k4724 in k4718 in k4715 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_4727(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4727,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4743,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
t4=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4741 */
static void C_ccall f_4743(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4743,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4747,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=((C_word*)t0)[6];{
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

/* k4745 in k4741 */
static void C_ccall f_4747(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4747,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4751,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=((C_word*)t0)[6];{
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

/* k4749 in k4745 in k4741 */
static void C_ccall f_4751(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4751,c,av);}
a=C_alloc(7);
t2=C_a_i_vector3(&a,3,((C_word*)t0)[2],((C_word*)t0)[3],t1);
t3=C_a_i_cons(&a,2,t2,((C_word*)t0)[4]);
t4=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[6];
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4753 in k4718 in k4715 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4755(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4755,c,av);}
/* eval.scm:317: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_i_caddr(((C_word*)t0)[5]),((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k4761 in k4715 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4763(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4763,c,av);}
/* eval.scm:315: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_i_cadr(((C_word*)t0)[5]),((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k4769 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4771(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4771,c,av);}
/* eval.scm:314: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_i_car(((C_word*)t0)[5]),((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k4782 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4784(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_4784,c,av);}
a=C_alloc(19);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_4787,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4845,a[2]=((C_word*)t0)[5],a[3]=t2,a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[9],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:323: scheme#cadadr */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4785 in k4782 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4787(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(20,c,2)))){
C_save_and_reclaim((void *)f_4787,c,av);}
a=C_alloc(20);
t2=C_i_cddr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_4793,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=t2,tmp=(C_word)a,a+=12,tmp);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4837,a[2]=((C_word*)t0)[6],a[3]=t3,a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[10],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:325: scheme#cadar */
t5=*((C_word*)lf[49]+1);{
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

/* k4791 in k4785 in k4782 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4793(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_4793,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4796,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4829,a[2]=((C_word*)t0)[6],a[3]=t2,a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[10],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:326: scheme#cadadr */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[11];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4794 in k4791 in k4785 in k4782 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_4796(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_4796,c,av);}
a=C_alloc(8);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4797,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word)li55),tmp=(C_word)a,a+=8,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4797 in k4794 in k4791 in k4785 in k4782 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_4797(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_4797,c,av);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4813,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
t4=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4811 */
static void C_ccall f_4813(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_4813,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4817,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t3=((C_word*)t0)[7];{
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

/* k4815 in k4811 */
static void C_ccall f_4817(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_4817,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4821,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t3=((C_word*)t0)[7];{
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

/* k4819 in k4815 in k4811 */
static void C_ccall f_4821(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_4821,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4825,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t3=((C_word*)t0)[7];{
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

/* k4823 in k4819 in k4815 in k4811 */
static void C_ccall f_4825(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_4825,c,av);}
a=C_alloc(8);
t2=C_a_i_vector4(&a,4,((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4],t1);
t3=C_a_i_cons(&a,2,t2,((C_word*)t0)[5]);
t4=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[7];
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4827 in k4791 in k4785 in k4782 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_4829(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4829,c,av);}
/* eval.scm:326: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_i_cadddr(((C_word*)t0)[5]),((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k4835 in k4785 in k4782 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4837(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4837,c,av);}
/* eval.scm:325: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_i_caddr(((C_word*)t0)[5]),((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k4843 in k4782 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4845(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4845,c,av);}
/* eval.scm:323: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_i_cadr(((C_word*)t0)[5]),((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k4851 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4853(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_4853,c,av);}
/* eval.scm:322: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_i_car(((C_word*)t0)[5]),((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* g557 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_4861(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,7)))){
C_save_and_reclaim_args((void *)trf_4861,3,t0,t1,t2);}
/* eval.scm:336: compile */
t3=((C_word*)((C_word*)t0)[2])[1];
f_3825(t3,t1,C_i_cadr(t2),((C_word*)t0)[3],C_u_i_car(t2),((C_word*)t0)[4],((C_word*)t0)[5],C_SCHEME_FALSE);}

/* k4872 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4874(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4874,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4875,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,a[5]=((C_word)li58),tmp=(C_word)a,a+=6,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_4875 in k4872 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4875(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4875,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4879,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
/* eval.scm:338: ##sys#make-vector */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[51]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[51]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}

/* k4877 */
static void C_ccall f_4879(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,4)))){
C_save_and_reclaim((void *)f_4879,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4882,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4891,a[2]=((C_word*)t0)[5],a[3]=t1,a[4]=t4,a[5]=((C_word*)t0)[2],a[6]=((C_word)li57),tmp=(C_word)a,a+=7,tmp));
t6=((C_word*)t4)[1];
f_4891(t6,t2,C_fix(0),((C_word*)t0)[6]);}

/* k4880 in k4877 */
static void C_ccall f_4882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4882,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[5];
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* doloop578 in k4877 */
static void C_fcall f_4891(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_4891,4,t0,t1,t2,t3);}
a=C_alloc(7);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4916,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
t5=C_slot(t3,C_fix(0));{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k4914 in doloop578 in k4877 */
static void C_ccall f_4916(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4916,c,av);}
t2=C_i_setslot(((C_word*)t0)[2],((C_word*)t0)[3],t1);
t3=((C_word*)((C_word*)t0)[4])[1];
f_4891(t3,((C_word*)t0)[5],C_fixnum_plus(((C_word*)t0)[3],C_fix(1)),C_slot(((C_word*)t0)[6],C_fix(1)));}

/* map-loop551 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_4921(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_4921,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4946,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:336: g557 */
t4=((C_word*)t0)[4];
f_4861(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4944 in map-loop551 in k4623 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4946(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4946,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_4921(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* a4962 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4963(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4963,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4967,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)((C_word*)t0)[3])[1])){
/* eval.scm:302: ##sys#current-environment512 */
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
f_4967(2,av2);}}}

/* k4965 in a4962 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4967(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4967,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4971,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* eval.scm:302: ##sys#current-environment512 */
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k4969 in k4965 in a4962 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4971(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4971,c,av);}
a=C_alloc(4);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4974,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:302: ##sys#current-environment512 */
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

/* k4972 in k4969 in k4965 in a4962 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4974(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4974,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a4979 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4980(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_4980,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4988,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=C_i_cddr(((C_word*)t0)[6]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4996,a[2]=t2,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:304: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t4;
tp(2,av2);}}

/* k4986 in a4979 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4988(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_4988,c,av);}
a=C_alloc(12);
/* eval.scm:303: compile-to-closure */
f_3576(((C_word*)t0)[2],t1,((C_word*)t0)[3],C_a_i_list(&a,4,((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_FALSE));}

/* k4994 in a4979 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4996(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4996,c,av);}
/* eval.scm:304: ##sys#canonicalize-body */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[52]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[52]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* a4997 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_4998(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4998,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5002,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:302: ##sys#current-environment512 */
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k5000 in a4997 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5002(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_5002,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5005,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:302: ##sys#current-environment512 */
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

/* k5003 in k5000 in a4997 in k4620 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5005(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5005,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)t0)[3]);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5008 in k4614 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5010(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5010,c,av);}
/* eval.scm:301: ##sys#extend-se */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[54]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[54]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
tp(5,av2);}}

/* map-loop484 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_5012(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_5012,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5037,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:299: g490 */
t4=*((C_word*)lf[55]+1);{
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

/* k5035 in map-loop484 in k4605 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5037(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5037,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_5012(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop456 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_5046(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_5046,3,t0,t1,t2);}
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

/* k5117 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5119(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(26,c,3)))){
C_save_and_reclaim((void *)f_5119,c,av);}
a=C_alloc(26);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_5123,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5143,a[2]=((C_word*)t0)[8],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5157,a[2]=t5,a[3]=t9,a[4]=t6,a[5]=((C_word)li65),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_5157(t11,t7,((C_word*)t0)[9]);}

/* k5121 in k5117 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5123(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,7)))){
C_save_and_reclaim((void *)f_5123,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,lf[47],t2);
/* eval.scm:348: compile */
t4=((C_word*)((C_word*)t0)[3])[1];
f_3825(t4,((C_word*)t0)[4],t3,((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],((C_word*)t0)[8],C_SCHEME_FALSE);}

/* k5141 in k5117 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5143(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_5143,c,av);}
a=C_alloc(9);
t2=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[47],t2);
t4=C_a_i_list(&a,1,t3);
/* eval.scm:349: ##sys#append */
t5=*((C_word*)lf[57]+1);{
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
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* map-loop619 in k5117 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_5157(C_word t0,C_word t1,C_word t2){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_5157,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_car(t3);
t5=C_i_cadr(t3);
t6=C_a_i_list(&a,3,lf[42],t4,t5);
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

/* map-loop592 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_5191(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_5191,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_car(t3);
t5=C_a_i_list2(&a,2,t4,lf[58]);
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

/* k5239 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5241(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_5241,c,av);}
a=C_alloc(24);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(t1,lf[48]);
t7=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_5250,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5463,a[2]=t4,a[3]=t9,a[4]=t5,a[5]=((C_word)li70),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_5463(t11,t7,t1);}

/* k5248 in k5239 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5250(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,c,3)))){
C_save_and_reclaim((void *)f_5250,c,av);}
a=C_alloc(25);
t2=C_i_cddr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_5276,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t2,a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5429,a[2]=t5,a[3]=t9,a[4]=t6,a[5]=((C_word)li69),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_5429(t11,t7,((C_word*)t0)[10]);}

/* k5274 in k5248 in k5239 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5276(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,c,4)))){
C_save_and_reclaim((void *)f_5276,c,av);}
a=C_alloc(25);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[48]);
t7=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_5303,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[2],tmp=(C_word)a,a+=12,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5381,a[2]=t4,a[3]=t9,a[4]=t5,a[5]=((C_word)li68),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_5381(t11,t7,((C_word*)t0)[2],((C_word*)t0)[11]);}

/* k5301 in k5274 in k5248 in k5239 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5303(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(27,c,4)))){
C_save_and_reclaim((void *)f_5303,c,av);}
a=C_alloc(27);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_5307,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5319,a[2]=((C_word*)t0)[9],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5333,a[2]=t5,a[3]=t9,a[4]=t6,a[5]=((C_word)li67),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_5333(t11,t7,((C_word*)t0)[10],((C_word*)t0)[11]);}

/* k5305 in k5301 in k5274 in k5248 in k5239 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5307(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,7)))){
C_save_and_reclaim((void *)f_5307,c,av);}
a=C_alloc(15);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,lf[47],t2);
t4=C_a_i_list(&a,3,lf[47],((C_word*)t0)[3],t3);
/* eval.scm:364: compile */
t5=((C_word*)((C_word*)t0)[4])[1];
f_3825(t5,((C_word*)t0)[5],t4,((C_word*)t0)[6],((C_word*)t0)[7],((C_word*)t0)[8],((C_word*)t0)[9],C_SCHEME_FALSE);}

/* k5317 in k5301 in k5274 in k5248 in k5239 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5319(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_5319,c,av);}
a=C_alloc(9);
t2=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[47],t2);
t4=C_a_i_list(&a,1,t3);
/* eval.scm:365: ##sys#append */
t5=*((C_word*)lf[57]+1);{
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
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* map-loop768 in k5301 in k5274 in k5248 in k5239 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_5333(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_5333,4,t0,t1,t2,t3);}
a=C_alloc(12);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,3,lf[42],t6,t7);
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

/* map-loop735 in k5274 in k5248 in k5239 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_5381(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_5381,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_i_cadr(t7);
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

/* map-loop708 in k5248 in k5239 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_5429(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_5429,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_car(t3);
t5=C_a_i_list2(&a,2,t4,lf[60]);
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

/* map-loop678 in k5239 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_5463(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_5463,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5488,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:362: g684 */
t4=*((C_word*)lf[55]+1);{
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

/* k5486 in map-loop678 in k5239 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5488(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5488,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_5463(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop651 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_5497(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_5497,3,t0,t1,t2);}
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

/* k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5538(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,2)))){
C_save_and_reclaim((void *)f_5538,c,av);}
a=C_alloc(24);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_u_i_cdr(((C_word*)t0)[2]);
t6=C_u_i_cdr(t5);
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=(C_truep(((C_word*)t0)[3])?C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t4)[1]):C_a_i_cons(&a,2,lf[62],((C_word*)t4)[1]));
t9=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_5549,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=t8,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t7,a[10]=((C_word*)t0)[9],a[11]=t4,tmp=(C_word)a,a+=12,tmp);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5955,a[2]=t4,a[3]=t7,a[4]=t9,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:381: ##sys#extended-lambda-list? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[69]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[69]+1);
av2[1]=t10;
av2[2]=((C_word*)t4)[1];
tp(3,av2);}}

/* k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5549(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,5)))){
C_save_and_reclaim((void *)f_5549,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_5554,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word)li101),tmp=(C_word)a,a+=11,tmp);
/* eval.scm:386: ##sys#decompose-lambda-list */
t3=*((C_word*)lf[66]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[10];
av2[2]=((C_word*)((C_word*)t0)[11])[1];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5554(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,3)))){
C_save_and_reclaim((void *)f_5554,c,av);}
a=C_alloc(27);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=C_i_check_list_2(t2,lf[48]);
t10=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_5564,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=t1,a[5]=t4,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],a[10]=((C_word*)t0)[7],a[11]=((C_word*)t0)[8],a[12]=((C_word*)t0)[9],a[13]=t2,tmp=(C_word)a,a+=14,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5920,a[2]=t7,a[3]=t12,a[4]=t8,a[5]=((C_word)li100),tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_5920(t14,t10,t2);}

/* k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5564(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_5564,c,av);}
a=C_alloc(19);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_5567,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5918,a[2]=t2,a[3]=((C_word*)t0)[13],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:390: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t3;
tp(2,av2);}}

/* k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5567(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(35,c,4)))){
C_save_and_reclaim((void *)f_5567,c,av);}
a=C_alloc(35);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=*((C_word*)lf[9]+1);
t4=t1;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_TRUE;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5573,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],tmp=(C_word)a,a+=7,tmp);
t9=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5875,a[2]=t5,a[3]=t7,a[4]=t3,a[5]=((C_word)li97),tmp=(C_word)a,a+=6,tmp);
t10=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_5892,a[2]=((C_word*)t0)[9],a[3]=t2,a[4]=((C_word*)t0)[10],a[5]=((C_word*)t0)[11],a[6]=((C_word*)t0)[12],a[7]=((C_word*)t0)[13],a[8]=t1,a[9]=((C_word)li98),tmp=(C_word)a,a+=10,tmp);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5906,a[2]=t5,a[3]=t3,a[4]=((C_word)li99),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:393: ##sys#dynamic-wind */
t12=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t12;
av2[1]=t8;
av2[2]=t9;
av2[3]=t10;
av2[4]=t11;
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}

/* k5571 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5573(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5573,c,av);}
a=C_alloc(7);
switch(((C_word*)t0)[2]){
case C_fix(0):
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(((C_word*)t0)[4])?(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5583,a[2]=t1,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word)li73),tmp=(C_word)a,a+=6,tmp):(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5602,a[2]=t1,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word)li75),tmp=(C_word)a,a+=6,tmp));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}
case C_fix(1):
if(C_truep(((C_word*)t0)[4])){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5626,a[2]=t1,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word)li77),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5645,a[2]=t1,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word)li79),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
case C_fix(2):
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(((C_word*)t0)[4])?(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5673,a[2]=t1,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word)li81),tmp=(C_word)a,a+=6,tmp):(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5692,a[2]=t1,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word)li83),tmp=(C_word)a,a+=6,tmp));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}
case C_fix(3):
if(C_truep(((C_word*)t0)[4])){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5720,a[2]=t1,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word)li85),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5739,a[2]=t1,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word)li87),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
default:
t2=C_eqp(((C_word*)t0)[2],C_fix(4));
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?(C_truep(((C_word*)t0)[4])?(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5767,a[2]=t1,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word)li89),tmp=(C_word)a,a+=6,tmp):(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5786,a[2]=t1,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word)li91),tmp=(C_word)a,a+=6,tmp)):(C_truep(((C_word*)t0)[4])?(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5808,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word)li94),tmp=(C_word)a,a+=7,tmp):(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5831,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word)li96),tmp=(C_word)a,a+=7,tmp)));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* f_5583 in k5571 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5583(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_5583,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5589,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word)li72),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:400: decorate */
f_3792(t1,t3,((C_word*)t0)[4]);}

/* a5588 */
static void C_ccall f_5589(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +5,c,2)))){
C_save_and_reclaim((void*)f_5589,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+5);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
t3=C_a_i_vector1(&a,1,t2);
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[2]);
t5=((C_word*)t0)[3];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* f_5602 in k5571 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5602(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_5602,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5608,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word)li74),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:405: decorate */
f_3792(t1,t3,((C_word*)t0)[4]);}

/* a5607 */
static void C_ccall f_5608(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5608,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,C_SCHEME_FALSE,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
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

/* f_5626 in k5571 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5626(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_5626,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5632,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word)li76),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:410: decorate */
f_3792(t1,t3,((C_word*)t0)[4]);}

/* a5631 */
static void C_ccall f_5632(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +6,c,2)))){
C_save_and_reclaim((void*)f_5632,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+6);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
t4=C_a_i_vector2(&a,2,t2,t3);
t5=C_a_i_cons(&a,2,t4,((C_word*)t0)[2]);
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t1;
av2[2]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* f_5645 in k5571 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5645(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_5645,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5651,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word)li78),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:415: decorate */
f_3792(t1,t3,((C_word*)t0)[4]);}

/* a5650 */
static void C_ccall f_5651(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_5651,c,av);}
a=C_alloc(5);
t3=C_a_i_vector1(&a,1,t2);
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[2]);
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* f_5673 in k5571 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5673(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_5673,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5679,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word)li80),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:421: decorate */
f_3792(t1,t3,((C_word*)t0)[4]);}

/* a5678 */
static void C_ccall f_5679(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +7,c,2)))){
C_save_and_reclaim((void*)f_5679,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+7);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
C_word t7;
t5=C_a_i_vector3(&a,3,t2,t3,t4);
t6=C_a_i_cons(&a,2,t5,((C_word*)t0)[2]);
t7=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t7;
av2[1]=t1;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* f_5692 in k5571 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5692(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_5692,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5698,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word)li82),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:426: decorate */
f_3792(t1,t3,((C_word*)t0)[4]);}

/* a5697 */
static void C_ccall f_5698(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_5698,c,av);}
a=C_alloc(6);
t4=C_a_i_vector2(&a,2,t2,t3);
t5=C_a_i_cons(&a,2,t4,((C_word*)t0)[2]);
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t1;
av2[2]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* f_5720 in k5571 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5720(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_5720,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5726,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word)li84),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:432: decorate */
f_3792(t1,t3,((C_word*)t0)[4]);}

/* a5725 */
static void C_ccall f_5726(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c<5) C_bad_min_argc_2(c,5,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-5)*C_SIZEOF_PAIR +8,c,2)))){
C_save_and_reclaim((void*)f_5726,c,av);}
a=C_alloc((c-5)*C_SIZEOF_PAIR+8);
t5=C_build_rest(&a,c,5,av);
C_word t6;
C_word t7;
C_word t8;
t6=C_a_i_vector4(&a,4,t2,t3,t4,t5);
t7=C_a_i_cons(&a,2,t6,((C_word*)t0)[2]);
t8=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t8;
av2[1]=t1;
av2[2]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}

/* f_5739 in k5571 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5739(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_5739,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5745,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word)li86),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:437: decorate */
f_3792(t1,t3,((C_word*)t0)[4]);}

/* a5744 */
static void C_ccall f_5745(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_5745,c,av);}
a=C_alloc(7);
t5=C_a_i_vector3(&a,3,t2,t3,t4);
t6=C_a_i_cons(&a,2,t5,((C_word*)t0)[2]);
t7=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t7;
av2[1]=t1;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* f_5767 in k5571 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5767(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_5767,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5773,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word)li88),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:443: decorate */
f_3792(t1,t3,((C_word*)t0)[4]);}

/* a5772 */
static void C_ccall f_5773(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6;
C_word *a;
if(c<6) C_bad_min_argc_2(c,6,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-6)*C_SIZEOF_PAIR +9,c,2)))){
C_save_and_reclaim((void*)f_5773,c,av);}
a=C_alloc((c-6)*C_SIZEOF_PAIR+9);
t6=C_build_rest(&a,c,6,av);
C_word t7;
C_word t8;
C_word t9;
t7=C_a_i_vector5(&a,5,t2,t3,t4,t5,t6);
t8=C_a_i_cons(&a,2,t7,((C_word*)t0)[2]);
t9=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t9;
av2[1]=t1;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* f_5786 in k5571 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5786(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_5786,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5792,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word)li90),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:448: decorate */
f_3792(t1,t3,((C_word*)t0)[4]);}

/* a5791 */
static void C_ccall f_5792(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_5792,c,av);}
a=C_alloc(5);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5804,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:450: ##sys#vector */
t7=*((C_word*)lf[63]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=t2;
av2[3]=t3;
av2[4]=t4;
av2[5]=t5;
((C_proc)(void*)(*((C_word*)t7+1)))(6,av2);}}

/* k5802 in a5791 */
static void C_ccall f_5804(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5804,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* f_5808 in k5571 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5808(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_5808,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5814,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word)li93),tmp=(C_word)a,a+=6,tmp);
/* eval.scm:455: decorate */
f_3792(t1,t3,((C_word*)t0)[5]);}

/* a5813 */
static void C_ccall f_5814(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +15,c,6)))){
C_save_and_reclaim((void*)f_5814,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+15);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5826,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5830,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_nullp(t2))){
t5=C_a_i_list1(&a,1,t2);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t3;
av2[2]=*((C_word*)lf[63]+1);
av2[3]=t5;
C_apply(4,av2);}}
else{
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7372,a[2]=t2,a[3]=t6,a[4]=((C_word)li92),tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_7372(t8,t4,((C_word*)t0)[4],C_fix(0),t2,C_SCHEME_FALSE);}}

/* k5824 in a5813 */
static void C_ccall f_5826(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5826,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k5828 in a5813 */
static void C_ccall f_5830(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5830,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[63]+1);
av2[3]=t1;
C_apply(4,av2);}}

/* f_5831 in k5571 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5831(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_5831,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5837,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=((C_word)li95),tmp=(C_word)a,a+=6,tmp);
/* eval.scm:462: decorate */
f_3792(t1,t3,((C_word*)t0)[5]);}

/* a5836 */
static void C_ccall f_5837(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +5,c,4)))){
C_save_and_reclaim((void*)f_5837,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+5);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
C_word t6;
t3=C_fix(c - 2);
t4=C_eqp(t3,((C_word*)t0)[2]);
if(C_truep(C_i_not(t4))){
/* eval.scm:466: ##sys#error */
t5=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=lf[65];
av2[3]=((C_word*)t0)[2];
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5859,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,tmp=(C_word)a,a+=5,tmp);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t5;
av2[2]=*((C_word*)lf[63]+1);
av2[3]=t2;
C_apply(4,av2);}}}

/* k5857 in a5836 */
static void C_ccall f_5859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5859,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* a5874 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5875(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5875,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5879,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)((C_word*)t0)[3])[1])){
/* eval.scm:393: ##sys#current-environment847 */
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
f_5879(2,av2);}}}

/* k5877 in a5874 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5879(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_5879,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5883,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* eval.scm:393: ##sys#current-environment847 */
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k5881 in k5877 in a5874 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_5883(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_5883,c,av);}
a=C_alloc(4);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5886,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:393: ##sys#current-environment847 */
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

/* k5884 in k5881 in k5877 in a5874 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_5886(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5886,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a5891 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5892(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_5892,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5900,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:395: ##sys#canonicalize-body */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[52]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[52]+1);
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[7])[1];
av2[3]=((C_word*)t0)[8];
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k5898 in a5891 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5900(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_5900,c,av);}
a=C_alloc(12);
if(C_truep(((C_word*)t0)[2])){
/* eval.scm:394: compile-to-closure */
f_3576(((C_word*)t0)[3],t1,((C_word*)t0)[4],C_a_i_list(&a,4,((C_word*)t0)[2],((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_FALSE));}
else{
/* eval.scm:394: compile-to-closure */
f_3576(((C_word*)t0)[3],t1,((C_word*)t0)[4],C_a_i_list(&a,4,((C_word*)t0)[7],((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_FALSE));}}

/* a5905 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5906(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_5906,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5910,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:393: ##sys#current-environment847 */
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k5908 in a5905 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5910(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_5910,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5913,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:393: ##sys#current-environment847 */
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

/* k5911 in k5908 in a5905 in k5565 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_5913(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5913,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)t0)[3]);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5916 in k5562 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5918(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5918,c,av);}
/* eval.scm:390: ##sys#extend-se */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[54]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[54]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
tp(5,av2);}}

/* map-loop819 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_5920(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_5920,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5945,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:389: g825 */
t4=*((C_word*)lf[55]+1);{
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

/* k5943 in map-loop819 in a5553 in k5547 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5945(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5945,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_5920(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k5953 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5955(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_5955,c,av);}
a=C_alloc(10);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5960,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li102),tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5970,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li103),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:382: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_5549(2,av2);}}}

/* a5959 in k5953 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5960(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_5960,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5968,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:385: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t2;
tp(2,av2);}}

/* k5966 in a5959 in k5953 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5968(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_5968,c,av);}
/* eval.scm:384: ##sys#expand-extended-lambda-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[67]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[67]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=((C_word*)((C_word*)t0)[4])[1];
av2[4]=*((C_word*)lf[68]+1);
av2[5]=t1;
tp(6,av2);}}

/* a5969 in k5953 in k5536 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5970(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5970,c,av);}
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=C_mutate(((C_word *)((C_word*)t0)[3])+1,t3);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k5979 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5981(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_5981,c,av);}
/* eval.scm:377: ##sys#check-syntax */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[70]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[70]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[71];
av2[3]=((C_word*)t0)[3];
av2[4]=lf[72];
av2[5]=C_SCHEME_FALSE;
av2[6]=t1;
tp(7,av2);}}

/* k5988 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5990(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(23,c,4)))){
C_save_and_reclaim((void *)f_5990,c,av);}
a=C_alloc(23);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_TRUE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5995,a[2]=t3,a[3]=t5,a[4]=((C_word*)t0)[2],a[5]=((C_word)li104),tmp=(C_word)a,a+=6,tmp);
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6012,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word)li105),tmp=(C_word)a,a+=8,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6030,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word)li106),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:471: ##sys#dynamic-wind */
t9=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t9;
av2[1]=((C_word*)t0)[8];
av2[2]=t6;
av2[3]=t7;
av2[4]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}

/* a5994 in k5988 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5995,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5999,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)((C_word*)t0)[3])[1])){
/* eval.scm:471: ##sys#current-environment913 */
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
f_5999(2,av2);}}}

/* k5997 in a5994 in k5988 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_5999(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_5999,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6003,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* eval.scm:471: ##sys#current-environment913 */
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k6001 in k5997 in a5994 in k5988 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6003(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_6003,c,av);}
a=C_alloc(4);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6006,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:471: ##sys#current-environment913 */
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

/* k6004 in k6001 in k5997 in a5994 in k5988 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6006(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6006,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a6011 in k5988 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6012(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_6012,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6020,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=C_i_cddr(((C_word*)t0)[6]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6028,a[2]=t2,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:484: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t4;
tp(2,av2);}}

/* k6018 in a6011 in k5988 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6020(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_6020,c,av);}
/* eval.scm:483: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_FALSE);}

/* k6026 in a6011 in k5988 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6028(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6028,c,av);}
/* eval.scm:484: ##sys#canonicalize-body */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[52]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[52]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* a6029 in k5988 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6030(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6030,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6034,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:471: ##sys#current-environment913 */
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k6032 in a6029 in k5988 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6034(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_6034,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6037,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:471: ##sys#current-environment913 */
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

/* k6035 in k6032 in a6029 in k5988 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6037(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6037,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)t0)[3]);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k6053 in map-loop922 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6055(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_6055,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6059,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6063,a[2]=t2,a[3]=((C_word*)t0)[7],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:479: ##sys#eval/meta */
t4=*((C_word*)lf[76]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_cadr(((C_word*)t0)[7]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k6057 in k6053 in map-loop922 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6059(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_6059,c,av);}
a=C_alloc(12);
t2=C_a_i_list3(&a,3,((C_word*)t0)[2],((C_word*)t0)[3],t1);
t3=C_a_i_cons(&a,2,t2,C_SCHEME_END_OF_LIST);
t4=C_i_setslot(((C_word*)((C_word*)t0)[4])[1],C_fix(1),t3);
t5=C_mutate(((C_word *)((C_word*)t0)[4])+1,t3);
t6=((C_word*)((C_word*)t0)[5])[1];
f_6088(t6,((C_word*)t0)[6],C_slot(((C_word*)t0)[7],C_fix(1)));}

/* k6061 in k6053 in map-loop922 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6063(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6063,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6067,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:480: chicken.syntax#strip-syntax */
t3=*((C_word*)lf[27]+1);{
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

/* k6065 in k6061 in k6053 in map-loop922 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6067(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6067,c,av);}
/* eval.scm:478: ##sys#ensure-transformer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[75]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[75]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
tp(4,av2);}}

/* k6080 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6082(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6082,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6086,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:482: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t2;
tp(2,av2);}}

/* k6084 in k6080 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6086(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6086,c,av);}
/* eval.scm:473: scheme#append */
t2=*((C_word*)lf[74]+1);{
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

/* map-loop922 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_6088(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_6088,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_car(t3);
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6055,a[2]=t4,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=t2,a[7]=t3,tmp=(C_word)a,a+=8,tmp);
/* eval.scm:477: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word av2[2];
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t5;
tp(2,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6140 in map-loop957 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6142(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_6142,c,av);}
a=C_alloc(12);
t2=C_a_i_list3(&a,3,((C_word*)t0)[2],C_SCHEME_FALSE,t1);
t3=C_a_i_cons(&a,2,t2,C_SCHEME_END_OF_LIST);
t4=C_i_setslot(((C_word*)((C_word*)t0)[3])[1],C_fix(1),t3);
t5=C_mutate(((C_word *)((C_word*)t0)[3])+1,t3);
t6=((C_word*)((C_word*)t0)[4])[1];
f_6260(t6,((C_word*)t0)[5],C_slot(((C_word*)t0)[6],C_fix(1)));}

/* k6144 in map-loop957 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6146(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6146,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6150,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:494: chicken.syntax#strip-syntax */
t3=*((C_word*)lf[27]+1);{
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

/* k6148 in k6144 in map-loop957 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6150(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6150,c,av);}
/* eval.scm:492: ##sys#ensure-transformer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[75]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[75]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
tp(4,av2);}}

/* k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6165(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_6165,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6168,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6258,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:496: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t3;
tp(2,av2);}}

/* k6166 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6168(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(31,c,4)))){
C_save_and_reclaim((void *)f_6168,c,av);}
a=C_alloc(31);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6169,a[2]=t1,a[3]=((C_word)li108),tmp=(C_word)a,a+=4,tmp);
t3=C_i_check_list_2(((C_word*)t0)[2],lf[78]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6233,a[2]=t2,a[3]=((C_word)li109),tmp=(C_word)a,a+=4,tmp);
t5=(
  f_6233(t4,((C_word*)t0)[2])
);
t6=*((C_word*)lf[9]+1);
t7=t1;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_SCHEME_TRUE;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6188,a[2]=t8,a[3]=t10,a[4]=t6,a[5]=((C_word)li110),tmp=(C_word)a,a+=6,tmp);
t12=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6205,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word)li111),tmp=(C_word)a,a+=8,tmp);
t13=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6223,a[2]=t8,a[3]=t6,a[4]=((C_word)li112),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:501: ##sys#dynamic-wind */
t14=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t14;
av2[1]=((C_word*)t0)[8];
av2[2]=t11;
av2[3]=t12;
av2[4]=t13;
((C_proc)(void*)(*((C_word*)t14+1)))(5,av2);}}

/* g986 in k6166 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static C_word C_fcall f_6169(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_set_car(C_i_cdr(t1),((C_word*)t0)[2]));}

/* a6187 in k6166 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6188(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6188,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6192,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)((C_word*)t0)[3])[1])){
/* eval.scm:501: ##sys#current-environment994 */
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
f_6192(2,av2);}}}

/* k6190 in a6187 in k6166 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6192(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_6192,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6196,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* eval.scm:501: ##sys#current-environment994 */
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k6194 in k6190 in a6187 in k6166 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6196(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_6196,c,av);}
a=C_alloc(4);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6199,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:501: ##sys#current-environment994 */
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

/* k6197 in k6194 in k6190 in a6187 in k6166 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6199(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6199,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a6204 in k6166 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6205(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_6205,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6213,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=C_i_cddr(((C_word*)t0)[6]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6221,a[2]=t2,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:503: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t4;
tp(2,av2);}}

/* k6211 in a6204 in k6166 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6213(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_6213,c,av);}
/* eval.scm:502: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_FALSE);}

/* k6219 in a6204 in k6166 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6221(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6221,c,av);}
/* eval.scm:503: ##sys#canonicalize-body */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[52]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[52]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* a6222 in k6166 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6223(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6223,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6227,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:501: ##sys#current-environment994 */
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k6225 in a6222 in k6166 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6227(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_6227,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6230,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:501: ##sys#current-environment994 */
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

/* k6228 in k6225 in a6222 in k6166 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6230(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6230,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)t0)[3]);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* for-each-loop985 in k6166 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static C_word C_fcall f_6233(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_pairp(t1))){
t2=(
/* eval.scm:497: g986 */
  f_6169(((C_word*)t0)[2],C_slot(t1,C_fix(0)))
);
t4=C_slot(t1,C_fix(1));
t1=t4;
goto loop;}
else{
t2=C_SCHEME_UNDEFINED;
return(t2);}}

/* k6256 in k6163 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6258(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6258,c,av);}
/* eval.scm:496: scheme#append */
t2=*((C_word*)lf[74]+1);{
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

/* map-loop957 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_6260(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,2)))){
C_save_and_reclaim_args((void *)trf_6260,3,t0,t1,t2);}
a=C_alloc(11);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_car(t3);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6142,a[2]=t4,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=t2,tmp=(C_word)a,a+=7,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6146,a[2]=t5,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:493: ##sys#eval/meta */
t7=*((C_word*)lf[76]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=C_i_cadr(t3);
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6305 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6307(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_6307,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6310,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
if(C_truep(((C_word*)t0)[8])){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6351,a[2]=((C_word*)t0)[9],a[3]=t2,a[4]=((C_word*)t0)[10],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:510: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t3;
tp(2,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6310(2,av2);}}}

/* k6308 in k6305 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6310(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_6310,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6313,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* eval.scm:512: ##sys#put/restore! */
t3=*((C_word*)lf[38]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=lf[39];
av2[4]=lf[84];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6311 in k6308 in k6305 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6313(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_6313,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6316,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6334,a[2]=t2,a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:514: ##sys#current-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[83]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[83]+1);
av2[1]=t3;
tp(2,av2);}}

/* k6314 in k6311 in k6308 in k6305 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6316(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_6316,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6319,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6326,a[2]=t2,a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:518: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t3;
tp(2,av2);}}

/* k6317 in k6314 in k6311 in k6308 in k6305 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6319(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_6319,c,av);}
/* eval.scm:520: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],lf[80],((C_word*)t0)[4],C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_FALSE);}

/* k6324 in k6314 in k6311 in k6308 in k6305 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6326(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6326,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6330,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:519: ##sys#eval/meta */
t3=*((C_word*)lf[76]+1);{
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

/* k6328 in k6324 in k6314 in k6311 in k6308 in k6305 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6330(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6330,c,av);}
/* eval.scm:516: ##sys#extend-macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[81]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[81]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=t1;
tp(5,av2);}}

/* k6332 in k6311 in k6308 in k6305 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6334(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6334,c,av);}
/* eval.scm:513: ##sys#register-syntax-export */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[82]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[82]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
av2[4]=((C_word*)t0)[4];
tp(5,av2);}}

/* k6349 in k6305 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6351(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_6351,c,av);}
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(C_i_not(t2))){
/* eval.scm:511: ##sys#error */
t3=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[0];
av2[3]=lf[85];
av2[4]=((C_word*)t0)[4];
av2[5]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6310(2,av2);}}}

/* k6371 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6373(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_6373,c,av);}
/* eval.scm:526: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_FALSE);}

/* k6379 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6381(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6381,c,av);}
/* eval.scm:527: ##sys#canonicalize-body */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[52]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[52]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* a6399 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6400(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_6400,c,av);}
a=C_alloc(12);
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6404,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=t1,tmp=(C_word)a,a+=9,tmp);
t5=C_i_cdddr(((C_word*)t0)[7]);
if(C_truep(C_i_pairp(t5))){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6433,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:537: scheme#append */
t7=*((C_word*)lf[74]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=t2;
av2[3]=C_i_cadddr(((C_word*)t0)[7]);
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t6=t4;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_cons(&a,2,lf[34],t2);
f_6404(2,av2);}}}

/* k6402 in a6399 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6404(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(23,c,4)))){
C_save_and_reclaim((void *)f_6404,c,av);}
a=C_alloc(23);
t2=((C_word*)t0)[2];
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6409,a[2]=t5,a[3]=t3,a[4]=((C_word)li114),tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6414,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word)li115),tmp=(C_word)a,a+=9,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6420,a[2]=t3,a[3]=t5,a[4]=((C_word)li116),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:540: ##sys#dynamic-wind */
t9=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t9;
av2[1]=((C_word*)t0)[8];
av2[2]=t6;
av2[3]=t7;
av2[4]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}

/* a6408 in k6402 in a6399 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6409(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6409,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[90]+1));
t3=C_mutate((C_word*)lf[90]+1 /* (set! ##sys#current-source-filename ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a6413 in k6402 in a6399 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6414(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_6414,c,av);}
/* eval.scm:541: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,t1,((C_word*)t0)[3],((C_word*)t0)[4],C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]);}

/* a6419 in k6402 in a6399 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6420(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6420,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[90]+1));
t3=C_mutate((C_word*)lf[90]+1 /* (set! ##sys#current-source-filename ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k6431 in a6399 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6433(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6433,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6437,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:538: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t2;
tp(2,av2);}}

/* k6435 in k6431 in a6399 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6437(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6437,c,av);}
/* eval.scm:536: ##sys#canonicalize-body */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[52]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[52]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
tp(4,av2);}}

/* k6464 in map-loop1043 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6466(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6466,c,av);}
/* eval.scm:547: chicken.syntax#strip-syntax */
t2=*((C_word*)lf[27]+1);{
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

/* k6476 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6478(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_6478,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6480,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word)li118),tmp=(C_word)a,a+=9,tmp);
/* eval.scm:544: ##sys#with-module-aliases */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[93]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[93]+1);
av2[1]=((C_word*)t0)[8];
av2[2]=t1;
av2[3]=t2;
tp(4,av2);}}

/* a6479 in k6476 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6480(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_6480,c,av);}
a=C_alloc(3);
t2=C_i_cddr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[34],t2);
/* eval.scm:550: compile */
t4=((C_word*)((C_word*)t0)[3])[1];
f_3825(t4,t1,t3,((C_word*)t0)[4],C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]);}

/* map-loop1043 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_6494(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_6494,3,t0,t1,t2);}
a=C_alloc(10);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6519,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6466,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:546: ##sys#check-syntax */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[70]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[70]+1);
av2[1]=t5;
av2[2]=lf[94];
av2[3]=t4;
av2[4]=lf[95];
tp(5,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6517 in map-loop1043 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6519(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6519,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_6494(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6535(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(26,c,3)))){
C_save_and_reclaim((void *)f_6535,c,av);}
a=C_alloc(26);
t2=C_i_cadr(t1);
t3=C_i_caddr(t1);
t4=C_eqp(C_SCHEME_TRUE,t3);
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6544,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
if(C_truep(t4)){
t6=t5;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t4;
f_6544(2,av2);}}
else{
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6749,a[2]=t2,a[3]=((C_word)li128),tmp=(C_word)a,a+=4,tmp);
t11=C_u_i_cdr(t1);
t12=C_u_i_cdr(t11);
t13=C_u_i_car(t12);
t14=C_i_check_list_2(t13,lf[48]);
t15=C_SCHEME_UNDEFINED;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_set_block_item(t16,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6806,a[2]=t8,a[3]=t16,a[4]=t10,a[5]=t9,a[6]=((C_word)li129),tmp=(C_word)a,a+=7,tmp));
t18=((C_word*)t16)[1];
f_6806(t18,t5,t13);}}

/* k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6544(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_6544,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6547,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,tmp=(C_word)a,a+=9,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6742,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:570: ##sys#current-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[83]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[83]+1);
av2[1]=t3;
tp(2,av2);}}

/* k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6547(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_6547,c,av);}
a=C_alloc(12);
t2=*((C_word*)lf[83]+1);
t3=*((C_word*)lf[9]+1);
t4=*((C_word*)lf[97]+1);
t5=*((C_word*)lf[98]+1);
t6=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6550,a[2]=t5,a[3]=t4,a[4]=t3,a[5]=t2,a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[5],a[10]=((C_word*)t0)[6],a[11]=((C_word*)t0)[7],tmp=(C_word)a,a+=12,tmp);
/* eval.scm:573: ##sys#register-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[106]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[106]+1);
av2[1]=t6;
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[8];
tp(5,av2);}}

/* k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6550(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_6550,c,av);}
a=C_alloc(14);
t2=*((C_word*)lf[99]+1);
t3=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6553,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],a[10]=((C_word*)t0)[8],a[11]=((C_word*)t0)[9],a[12]=((C_word*)t0)[10],a[13]=((C_word*)t0)[11],tmp=(C_word)a,a+=14,tmp);
/* eval.scm:578: ##sys#module-alias-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[98]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[98]+1);
av2[1]=t3;
tp(2,av2);}}

/* k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6553(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(41,c,4)))){
C_save_and_reclaim((void *)f_6553,c,av);}
a=C_alloc(41);
t2=((C_word*)t0)[2];
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_END_OF_LIST;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t0)[3];
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=t1;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_SCHEME_TRUE;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6558,a[2]=t3,a[3]=t5,a[4]=t7,a[5]=t9,a[6]=t11,a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],a[10]=((C_word*)t0)[7],a[11]=((C_word)li120),tmp=(C_word)a,a+=12,tmp);
t13=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6614,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[9],a[4]=((C_word*)t0)[10],a[5]=((C_word*)t0)[11],a[6]=((C_word*)t0)[12],a[7]=((C_word)li125),tmp=(C_word)a,a+=8,tmp);
t14=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6710,a[2]=t3,a[3]=t5,a[4]=t7,a[5]=t9,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],a[10]=((C_word)li126),tmp=(C_word)a,a+=11,tmp);
/* eval.scm:572: ##sys#dynamic-wind */
t15=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t15;
av2[1]=((C_word*)t0)[13];
av2[2]=t12;
av2[3]=t13;
av2[4]=t14;
((C_proc)(void*)(*((C_word*)t15+1)))(5,av2);}}

/* a6557 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6558(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_6558,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6562,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
if(C_truep(((C_word*)((C_word*)t0)[6])[1])){
/* eval.scm:572: ##sys#current-module1118 */
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
f_6562(2,av2);}}}

/* k6560 in a6557 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6562(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_6562,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6565,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=t1,tmp=(C_word)a,a+=13,tmp);
if(C_truep(((C_word*)((C_word*)t0)[6])[1])){
/* eval.scm:572: ##sys#current-environment1119 */
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
f_6565(2,av2);}}}

/* k6563 in k6560 in a6557 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_6565(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,4)))){
C_save_and_reclaim((void *)f_6565,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6568,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=t1,a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
if(C_truep(((C_word*)((C_word*)t0)[6])[1])){
/* eval.scm:572: ##sys#macro-environment1120 */
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
f_6568(2,av2);}}}

/* k6566 in k6563 in k6560 in a6557 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_6568(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,4)))){
C_save_and_reclaim((void *)f_6568,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_6571,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t1,a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],tmp=(C_word)a,a+=15,tmp);
if(C_truep(((C_word*)((C_word*)t0)[6])[1])){
/* eval.scm:572: ##sys#module-alias-environment1121 */
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
f_6571(2,av2);}}}

/* k6569 in k6566 in k6563 in k6560 in a6557 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in ... */
static void C_ccall f_6571(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_6571,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_6575,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],a[15]=((C_word*)t0)[14],tmp=(C_word)a,a+=16,tmp);
/* eval.scm:572: ##sys#current-module1118 */
t3=((C_word*)t0)[13];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k6573 in k6569 in k6566 in k6563 in k6560 in a6557 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in ... */
static void C_ccall f_6575(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_6575,c,av);}
a=C_alloc(15);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_6579,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],tmp=(C_word)a,a+=15,tmp);
/* eval.scm:572: ##sys#current-environment1119 */
t4=((C_word*)t0)[12];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* k6577 in k6573 in k6569 in k6566 in k6563 in k6560 in a6557 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in ... */
static void C_ccall f_6579(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_6579,c,av);}
a=C_alloc(14);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6583,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],tmp=(C_word)a,a+=14,tmp);
/* eval.scm:572: ##sys#macro-environment1120 */
t4=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* k6581 in k6577 in k6573 in k6569 in k6566 in k6563 in k6560 in a6557 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in ... */
static void C_ccall f_6583(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_6583,c,av);}
a=C_alloc(13);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6587,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],tmp=(C_word)a,a+=13,tmp);
/* eval.scm:572: ##sys#module-alias-environment1121 */
t4=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* k6585 in k6581 in k6577 in k6573 in k6569 in k6566 in k6563 in k6560 in a6557 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in ... */
static void C_ccall f_6587(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_6587,c,av);}
a=C_alloc(10);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6590,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],tmp=(C_word)a,a+=10,tmp);
/* eval.scm:572: ##sys#current-module1118 */
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

/* k6588 in k6585 in k6581 in k6577 in k6573 in k6569 in k6566 in k6563 in k6560 in a6557 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in ... */
static void C_ccall f_6590(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_6590,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6593,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:572: ##sys#current-environment1119 */
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

/* k6591 in k6588 in k6585 in k6581 in k6577 in k6573 in k6569 in k6566 in k6563 in k6560 in a6557 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in ... */
static void C_ccall f_6593(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6593,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6596,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* eval.scm:572: ##sys#macro-environment1120 */
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

/* k6594 in k6591 in k6588 in k6585 in k6581 in k6577 in k6573 in k6569 in k6566 in k6563 in k6560 in a6557 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in ... */
static void C_ccall f_6596(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_6596,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6599,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:572: ##sys#module-alias-environment1121 */
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

/* k6597 in k6594 in k6591 in k6588 in k6585 in k6581 in k6577 in k6573 in k6569 in k6566 in k6563 in k6560 in a6557 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in ... */
static void C_ccall f_6599(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6599,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a6613 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6614(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_6614,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6620,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word)li124),tmp=(C_word)a,a+=8,tmp);
/* eval.scm:579: ##sys#with-property-restore */
t3=*((C_word*)lf[105]+1);{
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

/* a6619 in a6613 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_6620,c,av);}
a=C_alloc(10);
t2=C_i_cdddr(((C_word*)t0)[2]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6630,a[2]=((C_word*)t0)[3],a[3]=t4,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word)li123),tmp=(C_word)a,a+=8,tmp));
t6=((C_word*)t4)[1];
f_6630(t6,t1,t2,C_SCHEME_END_OF_LIST);}

/* loop in a6619 in a6613 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_fcall f_6630(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,7)))){
C_save_and_reclaim_args((void *)trf_6630,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6640,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:583: reverse */
t5=*((C_word*)lf[104]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t4=C_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6706,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:598: compile */
t6=((C_word*)((C_word*)t0)[4])[1];
f_3825(t6,t5,C_u_i_car(t2),C_SCHEME_END_OF_LIST,C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_TRUE);}}

/* k6638 in loop in a6619 in a6613 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_6640(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_6640,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6643,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6691,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:584: ##sys#current-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[83]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[83]+1);
av2[1]=t3;
tp(2,av2);}}

/* k6641 in k6638 in loop in a6619 in a6613 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in ... */
static void C_ccall f_6643(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_6643,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6646,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6687,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:585: chicken.internal#module-requirement */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[102]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[102]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
tp(3,av2);}}

/* k6644 in k6641 in k6638 in loop in a6619 in a6613 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in ... */
static void C_ccall f_6646(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_6646,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6647,a[2]=((C_word*)t0)[2],a[3]=((C_word)li122),tmp=(C_word)a,a+=4,tmp);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* f_6647 in k6644 in k6641 in k6638 in loop in a6619 in a6613 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in ... */
static void C_ccall f_6647(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_6647,c,av);}
a=C_alloc(7);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6653,a[2]=t4,a[3]=t2,a[4]=((C_word)li121),tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_6653(t6,t1,((C_word*)t0)[2]);}

/* loop2 */
static void C_fcall f_6653(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_6653,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=*((C_word*)lf[100]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_cdr(t2);
if(C_truep(C_i_pairp(t3))){
t4=C_u_i_car(t2);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6676,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:591: g1175 */
t6=t4;{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t6))(3,av2);}}
else{
/* eval.scm:591: g1178 */
t4=C_u_i_car(t2);{
C_word av2[3];
av2[0]=t4;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}}}

/* k6674 in loop2 */
static void C_ccall f_6676(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6676,c,av);}
/* eval.scm:593: loop2 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_6653(t2,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* k6685 in k6641 in k6638 in loop in a6619 in a6613 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in ... */
static void C_ccall f_6687(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6687,c,av);}
/* eval.scm:585: ##sys#provide */
t2=*((C_word*)lf[101]+1);{
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

/* k6689 in k6638 in loop in a6619 in a6613 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in ... */
static void C_ccall f_6691(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6691,c,av);}
/* eval.scm:584: ##sys#finalize-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[103]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[103]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
tp(3,av2);}}

/* k6704 in loop in a6619 in a6613 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_6706(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_6706,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
/* eval.scm:596: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_6630(t3,((C_word*)t0)[4],((C_word*)t0)[5],t2);}

/* a6709 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6710(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_6710,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6714,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* eval.scm:572: ##sys#current-module1118 */
t3=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k6712 in a6709 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6714(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_6714,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6717,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* eval.scm:572: ##sys#current-environment1119 */
t3=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k6715 in k6712 in a6709 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_6717(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_6717,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6720,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* eval.scm:572: ##sys#macro-environment1120 */
t3=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k6718 in k6715 in k6712 in a6709 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_6720(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_6720,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6723,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
/* eval.scm:572: ##sys#module-alias-environment1121 */
t3=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k6721 in k6718 in k6715 in k6712 in a6709 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in ... */
static void C_ccall f_6723(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,4)))){
C_save_and_reclaim((void *)f_6723,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6726,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
/* eval.scm:572: ##sys#current-module1118 */
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

/* k6724 in k6721 in k6718 in k6715 in k6712 in a6709 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in ... */
static void C_ccall f_6726(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_6726,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6729,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],tmp=(C_word)a,a+=13,tmp);
/* eval.scm:572: ##sys#current-environment1119 */
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

/* k6727 in k6724 in k6721 in k6718 in k6715 in k6712 in a6709 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in ... */
static void C_ccall f_6729(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_6729,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6732,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
/* eval.scm:572: ##sys#macro-environment1120 */
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

/* k6730 in k6727 in k6724 in k6721 in k6718 in k6715 in k6712 in a6709 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in ... */
static void C_ccall f_6732(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_6732,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6735,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
/* eval.scm:572: ##sys#module-alias-environment1121 */
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

/* k6733 in k6730 in k6727 in k6724 in k6721 in k6718 in k6715 in k6712 in a6709 in k6551 in k6548 in k6545 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in ... */
static void C_ccall f_6735(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6735,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)t0)[3]);
t3=C_mutate(((C_word *)((C_word*)t0)[4])+1,((C_word*)t0)[5]);
t4=C_mutate(((C_word *)((C_word*)t0)[6])+1,((C_word*)t0)[7]);
t5=C_mutate(((C_word *)((C_word*)t0)[8])+1,((C_word*)t0)[9]);
t6=((C_word*)t0)[10];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k6740 in k6542 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6742(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6742,c,av);}
if(C_truep(t1)){
/* eval.scm:571: ##sys#syntax-error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[68]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[68]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[107];
av2[3]=lf[108];
av2[4]=((C_word*)t0)[3];
tp(5,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_6547(2,av2);}}}

/* g1086 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_6749(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_6749,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_symbolp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6762,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_pairp(t2))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6773,a[2]=((C_word)li127),tmp=(C_word)a,a+=3,tmp);
t5=t3;
f_6762(t5,(
  f_6773(t2)
));}
else{
t4=t3;
f_6762(t4,C_SCHEME_FALSE);}}}

/* k6760 in g1086 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_6762(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,5)))){
C_save_and_reclaim_args((void *)trf_6762,2,t0,t1);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* eval.scm:566: ##sys#syntax-error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[68]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[68]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[107];
av2[3]=lf[109];
av2[4]=((C_word*)t0)[3];
av2[5]=((C_word*)t0)[4];
tp(6,av2);}}}

/* loop in g1086 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static C_word C_fcall f_6773(C_word t1){
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
if(C_truep(C_i_symbolp(t3))){
t5=C_u_i_cdr(t1);
t1=t5;
goto loop;}
else{
return(C_SCHEME_FALSE);}}}

/* map-loop1080 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_6806(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_6806,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6831,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:557: g1086 */
t4=((C_word*)t0)[4];
f_6749(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6829 in map-loop1080 in k6533 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6831(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6831,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_6806(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k6857 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_6859,c,av);}
a=C_alloc(3);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t1,t2);
/* eval.scm:605: compile */
t4=((C_word*)((C_word*)t0)[3])[1];
f_3825(t4,((C_word*)t0)[4],t3,((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k6891 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6893(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_6893,c,av);}
/* eval.scm:612: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],lf[113],((C_word*)t0)[4],C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_FALSE);}

/* k6917 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6919(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_6919,c,av);}
/* eval.scm:617: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_FALSE);}

/* k6938 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6940(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_6940,c,av);}
/* eval.scm:621: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],lf[119],((C_word*)t0)[4],C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]);}

/* k6967 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_6969(C_word t0,C_word t1){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,7)))){
C_save_and_reclaim_args((void *)trf_6969,2,t0,t1);}
a=C_alloc(12);
if(C_truep(t1)){
/* eval.scm:627: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],lf[122],((C_word*)t0)[4],C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]);}
else{
t2=C_eqp(((C_word*)t0)[8],lf[123]);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6981,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* eval.scm:630: ##sys#notice */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[45]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[45]+1);
av2[1]=t3;
av2[2]=lf[125];
av2[3]=((C_word*)t0)[9];
tp(4,av2);}}
else{
t3=C_eqp(((C_word*)t0)[8],lf[126]);
t4=(C_truep(t3)?t3:C_eqp(((C_word*)t0)[8],lf[127]));
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7004,a[2]=((C_word*)t0)[9],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* eval.scm:634: rename */
t6=((C_word*)((C_word*)t0)[10])[1];
f_3638(t6,t5,lf[128]);}
else{
t5=C_eqp(((C_word*)t0)[8],lf[129]);
t6=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7017,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[9],a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[11],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[2],a[10]=((C_word*)t0)[12],a[11]=((C_word*)t0)[7],tmp=(C_word)a,a+=12,tmp);
if(C_truep(t5)){
t7=t6;
f_7017(t7,t5);}
else{
t7=C_eqp(((C_word*)t0)[8],lf[138]);
if(C_truep(t7)){
t8=t6;
f_7017(t8,t7);}
else{
t8=C_eqp(((C_word*)t0)[8],lf[139]);
if(C_truep(t8)){
t9=t6;
f_7017(t9,t8);}
else{
t9=C_eqp(((C_word*)t0)[8],lf[140]);
if(C_truep(t9)){
t10=t6;
f_7017(t10,t9);}
else{
t10=C_eqp(((C_word*)t0)[8],lf[141]);
if(C_truep(t10)){
t11=t6;
f_7017(t11,t10);}
else{
t11=C_eqp(((C_word*)t0)[8],lf[142]);
if(C_truep(t11)){
t12=t6;
f_7017(t12,t11);}
else{
t12=C_eqp(((C_word*)t0)[8],lf[143]);
if(C_truep(t12)){
t13=t6;
f_7017(t13,t12);}
else{
t13=C_eqp(((C_word*)t0)[8],lf[144]);
if(C_truep(t13)){
t14=t6;
f_7017(t14,t13);}
else{
t14=C_eqp(((C_word*)t0)[8],lf[145]);
if(C_truep(t14)){
t15=t6;
f_7017(t15,t14);}
else{
t15=C_eqp(((C_word*)t0)[8],lf[146]);
t16=t6;
f_7017(t16,(C_truep(t15)?t15:C_eqp(((C_word*)t0)[8],lf[147])));}}}}}}}}}}}}}

/* k6979 in k6967 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_6981(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_6981,c,av);}
/* eval.scm:631: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],lf[124],((C_word*)t0)[4],C_SCHEME_FALSE,((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_FALSE);}

/* k7002 in k6967 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7004(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_7004,c,av);}
a=C_alloc(3);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t1,t2);
/* eval.scm:634: compile */
t4=((C_word*)((C_word*)t0)[3])[1];
f_3825(t4,((C_word*)t0)[4],t3,((C_word*)t0)[5],C_SCHEME_FALSE,((C_word*)t0)[6],((C_word*)t0)[7],((C_word*)t0)[8]);}

/* k7015 in k6967 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_7017(C_word t0,C_word t1){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(25,0,7)))){
C_save_and_reclaim_args((void *)trf_7017,2,t0,t1);}
a=C_alloc(25);
if(C_truep(t1)){
/* eval.scm:641: ##sys#syntax-error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[68]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[68]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[130];
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}
else{
t2=C_eqp(((C_word*)t0)[4],lf[131]);
if(C_truep(t2)){
t3=C_i_cdr(((C_word*)t0)[3]);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7037,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[2],a[4]=t3,a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:644: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word av2[2];
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t4;
tp(2,av2);}}
else{
t3=C_eqp(((C_word*)t0)[4],lf[132]);
if(C_truep(t3)){
/* eval.scm:647: compile */
t4=((C_word*)((C_word*)t0)[9])[1];
f_3825(t4,((C_word*)t0)[2],C_i_cadddr(((C_word*)t0)[3]),((C_word*)t0)[6],((C_word*)t0)[10],((C_word*)t0)[7],((C_word*)t0)[8],((C_word*)t0)[11]);}
else{
t4=C_eqp(((C_word*)t0)[4],lf[133]);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7081,a[2]=((C_word*)t0)[9],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[10],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[11],a[8]=((C_word*)t0)[2],a[9]=((C_word*)t0)[3],tmp=(C_word)a,a+=10,tmp);
/* eval.scm:651: chicken.syntax#strip-syntax */
t6=*((C_word*)lf[27]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=C_i_cdddr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=C_a_i_cons(&a,2,((C_word*)t0)[4],*((C_word*)lf[137]+1));
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_FALSE;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7093,a[2]=t9,a[3]=t7,a[4]=((C_word)li131),tmp=(C_word)a,a+=5,tmp);
t11=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7098,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word)li132),tmp=(C_word)a,a+=8,tmp);
t12=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7108,a[2]=t7,a[3]=t9,a[4]=((C_word)li133),tmp=(C_word)a,a+=5,tmp);
/* eval.scm:661: ##sys#dynamic-wind */
t13=*((C_word*)lf[53]+1);{
C_word av2[5];
av2[0]=t13;
av2[1]=((C_word*)t0)[2];
av2[2]=t10;
av2[3]=t11;
av2[4]=t12;
((C_proc)(void*)(*((C_word*)t13+1)))(5,av2);}}}}}}

/* k7035 in k7015 in k6967 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7037(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7037,c,av);}
/* eval.scm:644: compile-call */
t2=((C_word*)((C_word*)t0)[2])[1];
f_7444(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]);}

/* g1259 in k7079 in k7015 in k6967 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_7063(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,7)))){
C_save_and_reclaim_args((void *)trf_7063,3,t0,t1,t2);}
/* eval.scm:653: compile */
t3=((C_word*)((C_word*)t0)[2])[1];
f_3825(t3,t1,C_i_cadr(t2),((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]);}

/* k7079 in k7015 in k6967 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7081(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_7081,c,av);}
a=C_alloc(9);
t2=C_i_assq(lf[134],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7063,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word)li130),tmp=(C_word)a,a+=9,tmp);
/* eval.scm:651: g1259 */
t4=t3;
f_7063(t4,((C_word*)t0)[8],t2);}
else{
/* eval.scm:655: ##sys#syntax-error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[68]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[68]+1);
av2[1]=((C_word*)t0)[8];
av2[2]=lf[135];
av2[3]=lf[136];
av2[4]=((C_word*)t0)[9];
tp(5,av2);}}}

/* a7092 in k7015 in k6967 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7093(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7093,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[137]+1));
t3=C_mutate((C_word*)lf[137]+1 /* (set! ##sys#syntax-context ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a7097 in k7015 in k6967 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7098(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7098,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7106,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:662: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t2;
tp(2,av2);}}

/* k7104 in a7097 in k7015 in k6967 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7106(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7106,c,av);}
/* eval.scm:662: compile-call */
t2=((C_word*)((C_word*)t0)[2])[1];
f_7444(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]);}

/* a7107 in k7015 in k6967 in k4158 in k4143 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7108(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7108,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[137]+1));
t3=C_mutate((C_word*)lf[137]+1 /* (set! ##sys#syntax-context ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a7288 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7289(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7289,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[150]+1));
t3=C_mutate((C_word*)lf[150]+1 /* (set! chicken.syntax#expansion-result-hook ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a7293 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7294(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7294,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7302,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:209: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t2;
tp(2,av2);}}

/* k7300 in a7293 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7302(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7302,c,av);}
/* eval.scm:209: chicken.syntax#expand */
t2=*((C_word*)lf[151]+1);{
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

/* a7303 in k4137 in k4134 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7304(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7304,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[150]+1));
t3=C_mutate((C_word*)lf[150]+1 /* (set! chicken.syntax#expansion-result-hook ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k7308 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7310(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7310,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7317,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:666: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t2;
tp(2,av2);}}

/* k7315 in k7308 in k4114 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7317(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7317,c,av);}
/* eval.scm:666: compile-call */
t2=((C_word*)((C_word*)t0)[2])[1];
f_7444(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]);}

/* k7341 in k4050 in k3830 in compile in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7343(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7343,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
f_4116(2,av2);}}
else{
t2=C_i_vectorp(((C_word*)t0)[3]);
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_4116(2,av2);}}
else{
/* eval.scm:200: ##sys#srfi-4-vector? */
t3=*((C_word*)lf[152]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}}

/* doloop1277 in a5813 */
static void C_fcall f_7372(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
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
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,5)))){
C_save_and_reclaim_args((void *)trf_7372,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(7);
t6=C_eqp(t2,C_fix(0));
if(C_truep(t6)){
t7=C_a_i_list1(&a,1,t4);
t8=C_i_setslot(t5,C_fix(1),t7);
t9=t1;{
C_word av2[2];
av2[0]=t9;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
t7=C_fixnum_difference(t2,C_fix(1));
t8=C_fixnum_plus(t3,C_fix(1));
t9=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7401,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t7,a[5]=t8,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
t10=C_eqp(C_SCHEME_END_OF_LIST,t4);
if(C_truep(t10)){
/* eval.scm:675: ##sys#error */
t11=*((C_word*)lf[19]+1);{
C_word av2[5];
av2[0]=t11;
av2[1]=t9;
av2[2]=lf[64];
av2[3]=t2;
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t11+1)))(5,av2);}}
else{
t12=t1;
t13=t7;
t14=t8;
t15=C_slot(t4,C_fix(1));
t16=t4;
t1=t12;
t2=t13;
t3=t14;
t4=t15;
t5=t16;
goto loop;}}}

/* k7399 in doloop1277 in a5813 */
static void C_ccall f_7401(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7401,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7372(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1,((C_word*)t0)[6]);}

/* loop in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static C_word C_fcall f_7418(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_nullp(t1))){
return(t2);}
else{
if(C_truep(C_i_pairp(t1))){
t4=C_slot(t1,C_fix(1));
t5=C_fixnum_plus(t2,C_fix(1));
t1=t4;
t2=t5;
goto loop;}
else{
return(C_SCHEME_FALSE);}}}

/* compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_7444(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,0,7)))){
C_save_and_reclaim_args((void *)trf_7444,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(13);
t6=C_slot(t2,C_fix(0));
t7=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7451,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=t4,a[6]=t5,a[7]=t3,a[8]=((C_word*)t0)[3],tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_i_closurep(t6))){
t8=t7;{
C_word av2[2];
av2[0]=t8;
av2[1]=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7774,a[2]=t6,a[3]=((C_word)li149),tmp=(C_word)a,a+=4,tmp);
f_7451(2,av2);}}
else{
/* eval.scm:692: compile */
t8=((C_word*)((C_word*)t0)[3])[1];
f_3825(t8,t7,C_slot(t2,C_fix(0)),t3,C_SCHEME_FALSE,t4,t5,C_SCHEME_FALSE);}}

/* k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7451(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_7451,c,av);}
a=C_alloc(15);
t2=C_slot(((C_word*)t0)[2],C_fix(1));
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7418,a[2]=((C_word)li138),tmp=(C_word)a,a+=3,tmp);
t4=(
  f_7418(t2,C_fix(0))
);
t5=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7460,a[2]=t4,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=t1,a[10]=((C_word*)t0)[8],a[11]=t2,tmp=(C_word)a,a+=12,tmp);
/* eval.scm:696: chicken.syntax#get-line-number */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[13]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[13]+1);
av2[1]=t5;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}

/* k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7460(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(31,c,7)))){
C_save_and_reclaim((void *)f_7460,c,av);}
a=C_alloc(31);
t2=(C_truep(t1)?t1:lf[156]);
switch(((C_word*)t0)[2]){
case C_SCHEME_FALSE:
/* eval.scm:698: ##sys#syntax-error/context */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[23]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[23]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=lf[157];
av2[3]=((C_word*)t0)[4];
tp(4,av2);}
case C_fix(0):
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7479,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=t2,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word)li139),tmp=(C_word)a,a+=10,tmp);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}
case C_fix(1):
t3=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7498,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=t2,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[3],tmp=(C_word)a,a+=10,tmp);
/* eval.scm:702: compile */
t4=((C_word*)((C_word*)t0)[10])[1];
f_3825(t4,t3,C_slot(((C_word*)t0)[11],C_fix(0)),((C_word*)t0)[8],C_SCHEME_FALSE,((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);
case C_fix(2):
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7526,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=t2,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
/* eval.scm:706: compile */
t4=((C_word*)((C_word*)t0)[10])[1];
f_3825(t4,t3,C_slot(((C_word*)t0)[11],C_fix(0)),((C_word*)t0)[8],C_SCHEME_FALSE,((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);
case C_fix(3):
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7562,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=t2,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[3],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
/* eval.scm:711: compile */
t4=((C_word*)((C_word*)t0)[10])[1];
f_3825(t4,t3,C_slot(((C_word*)t0)[11],C_fix(0)),((C_word*)t0)[8],C_SCHEME_FALSE,((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);
case C_fix(4):
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7606,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=t2,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
/* eval.scm:717: compile */
t4=((C_word*)((C_word*)t0)[10])[1];
f_3825(t4,t3,C_slot(((C_word*)t0)[11],C_fix(0)),((C_word*)t0)[8],C_SCHEME_FALSE,((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);
default:
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7653,a[2]=((C_word*)t0)[10],a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word)li144),tmp=(C_word)a,a+=7,tmp);
t8=C_i_check_list_2(((C_word*)t0)[11],lf[48]);
t9=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7663,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=t2,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7726,a[2]=t5,a[3]=t11,a[4]=t7,a[5]=t6,a[6]=((C_word)li148),tmp=(C_word)a,a+=7,tmp));
t13=((C_word*)t11)[1];
f_7726(t13,t9,((C_word*)t0)[11]);}}

/* f_7479 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7479(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7479,c,av);}
a=C_alloc(8);
t3=(
/* eval.scm:700: emit-trace-info */
  f_3761(C_a_i(&a,5),((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],t2)
);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7486,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t5=((C_word*)t0)[8];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7484 */
static void C_ccall f_7486(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7486,c,av);}
/* eval.scm:699: g1316 */
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* k7496 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7498(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_7498,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7499,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],a[10]=((C_word)li140),tmp=(C_word)a,a+=11,tmp);
t3=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* f_7499 in k7496 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7499(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_7499,c,av);}
a=C_alloc(10);
t3=(
/* eval.scm:704: emit-trace-info */
  f_3761(C_a_i(&a,5),((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],t2)
);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7506,a[2]=t1,a[3]=((C_word*)t0)[8],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t5=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7504 */
static void C_ccall f_7506(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7506,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7513,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=((C_word*)t0)[3];{
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

/* k7511 in k7504 */
static void C_ccall f_7513(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7513,c,av);}
/* eval.scm:703: g1321 */
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

/* k7524 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7526(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,7)))){
C_save_and_reclaim((void *)f_7526,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7529,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* eval.scm:707: compile */
t3=((C_word*)((C_word*)t0)[10])[1];
f_3825(t3,t2,C_u_i_list_ref(((C_word*)t0)[11],C_fix(1)),((C_word*)t0)[8],C_SCHEME_FALSE,((C_word*)t0)[4],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k7527 in k7524 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7529(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_7529,c,av);}
a=C_alloc(12);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7530,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=t1,a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word)li141),tmp=(C_word)a,a+=12,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_7530 in k7527 in k7524 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7530(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_7530,c,av);}
a=C_alloc(11);
t3=(
/* eval.scm:709: emit-trace-info */
  f_3761(C_a_i(&a,5),((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],t2)
);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7537,a[2]=t1,a[3]=((C_word*)t0)[8],a[4]=t2,a[5]=((C_word*)t0)[9],tmp=(C_word)a,a+=6,tmp);
t5=((C_word*)t0)[10];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7535 */
static void C_ccall f_7537(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_7537,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7544,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[5];{
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

/* k7542 in k7535 */
static void C_ccall f_7544(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_7544,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7548,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=((C_word*)t0)[4];{
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

/* k7546 in k7542 in k7535 */
static void C_ccall f_7548(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7548,c,av);}
/* eval.scm:708: g1327 */
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

/* k7560 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7562(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,7)))){
C_save_and_reclaim((void *)f_7562,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_7565,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* eval.scm:712: compile */
t3=((C_word*)((C_word*)t0)[10])[1];
f_3825(t3,t2,C_u_i_list_ref(((C_word*)t0)[11],C_fix(1)),((C_word*)t0)[7],C_SCHEME_FALSE,((C_word*)t0)[3],((C_word*)t0)[6],C_SCHEME_FALSE);}

/* k7563 in k7560 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7565(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,7)))){
C_save_and_reclaim((void *)f_7565,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7568,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* eval.scm:713: compile */
t3=((C_word*)((C_word*)t0)[11])[1];
f_3825(t3,t2,C_u_i_list_ref(((C_word*)t0)[12],C_fix(2)),((C_word*)t0)[7],C_SCHEME_FALSE,((C_word*)t0)[3],((C_word*)t0)[6],C_SCHEME_FALSE);}

/* k7566 in k7563 in k7560 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7568(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_7568,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_7569,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word)li142),tmp=(C_word)a,a+=13,tmp);
t3=((C_word*)t0)[11];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* f_7569 in k7566 in k7563 in k7560 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7569(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_7569,c,av);}
a=C_alloc(12);
t3=(
/* eval.scm:715: emit-trace-info */
  f_3761(C_a_i(&a,5),((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],t2)
);
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7576,a[2]=t1,a[3]=((C_word*)t0)[8],a[4]=t2,a[5]=((C_word*)t0)[9],a[6]=((C_word*)t0)[10],tmp=(C_word)a,a+=7,tmp);
t5=((C_word*)t0)[11];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7574 */
static void C_ccall f_7576(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_7576,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7583,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=((C_word*)t0)[6];{
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

/* k7581 in k7574 */
static void C_ccall f_7583(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_7583,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7587,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=((C_word*)t0)[6];{
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

/* k7585 in k7581 in k7574 */
static void C_ccall f_7587(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_7587,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7591,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[5];{
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

/* k7589 in k7585 in k7581 in k7574 */
static void C_ccall f_7591(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7591,c,av);}
/* eval.scm:714: g1334 */
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
av2[4]=t1;
((C_proc)C_fast_retrieve_proc(t2))(5,av2);}}

/* k7604 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7606(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,7)))){
C_save_and_reclaim((void *)f_7606,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_7609,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* eval.scm:718: compile */
t3=((C_word*)((C_word*)t0)[10])[1];
f_3825(t3,t2,C_u_i_list_ref(((C_word*)t0)[11],C_fix(1)),((C_word*)t0)[8],C_SCHEME_FALSE,((C_word*)t0)[4],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k7607 in k7604 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7609(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,7)))){
C_save_and_reclaim((void *)f_7609,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_7612,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
/* eval.scm:719: compile */
t3=((C_word*)((C_word*)t0)[11])[1];
f_3825(t3,t2,C_u_i_list_ref(((C_word*)t0)[12],C_fix(2)),((C_word*)t0)[8],C_SCHEME_FALSE,((C_word*)t0)[4],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k7610 in k7607 in k7604 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7612(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,7)))){
C_save_and_reclaim((void *)f_7612,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_7615,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* eval.scm:720: compile */
t3=((C_word*)((C_word*)t0)[12])[1];
f_3825(t3,t2,C_u_i_list_ref(((C_word*)t0)[13],C_fix(3)),((C_word*)t0)[8],C_SCHEME_FALSE,((C_word*)t0)[4],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* k7613 in k7610 in k7607 in k7604 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7615(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_7615,c,av);}
a=C_alloc(14);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_7616,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=t1,a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word)li143),tmp=(C_word)a,a+=14,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_7616 in k7613 in k7610 in k7607 in k7604 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7616(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_7616,c,av);}
a=C_alloc(13);
t3=(
/* eval.scm:722: emit-trace-info */
  f_3761(C_a_i(&a,5),((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],t2)
);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7623,a[2]=t1,a[3]=((C_word*)t0)[8],a[4]=t2,a[5]=((C_word*)t0)[9],a[6]=((C_word*)t0)[10],a[7]=((C_word*)t0)[11],tmp=(C_word)a,a+=8,tmp);
t5=((C_word*)t0)[12];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7621 */
static void C_ccall f_7623(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7623,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7630,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t3=((C_word*)t0)[7];{
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

/* k7628 in k7621 */
static void C_ccall f_7630(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7630,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7634,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t3=((C_word*)t0)[7];{
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

/* k7632 in k7628 in k7621 */
static void C_ccall f_7634(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7634,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7638,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t3=((C_word*)t0)[7];{
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

/* k7636 in k7632 in k7628 in k7621 */
static void C_ccall f_7638(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_7638,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7642,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
t3=((C_word*)t0)[6];{
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

/* k7640 in k7636 in k7632 in k7628 in k7621 */
static void C_ccall f_7642(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7642,c,av);}
/* eval.scm:721: g1342 */
t2=((C_word*)t0)[2];{
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

/* g1354 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_7653(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,7)))){
C_save_and_reclaim_args((void *)trf_7653,3,t0,t1,t2);}
/* eval.scm:724: compile */
t3=((C_word*)((C_word*)t0)[2])[1];
f_3825(t3,t1,t2,((C_word*)t0)[3],C_SCHEME_FALSE,((C_word*)t0)[4],((C_word*)t0)[5],C_SCHEME_FALSE);}

/* k7661 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7663(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_7663,c,av);}
a=C_alloc(11);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7664,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=t1,a[9]=((C_word*)t0)[9],a[10]=((C_word)li147),tmp=(C_word)a,a+=11,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_7664 in k7661 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7664(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_7664,c,av);}
a=C_alloc(10);
t3=(
/* eval.scm:726: emit-trace-info */
  f_3761(C_a_i(&a,5),((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],t2)
);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7675,a[2]=t2,a[3]=((C_word*)t0)[8],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t5=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7673 */
static void C_ccall f_7675(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_7675,c,av);}
a=C_alloc(22);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7680,a[2]=((C_word*)t0)[2],a[3]=((C_word)li145),tmp=(C_word)a,a+=4,tmp);
t7=C_i_check_list_2(((C_word*)t0)[3],lf[48]);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7690,a[2]=((C_word*)t0)[4],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7692,a[2]=t4,a[3]=t10,a[4]=t6,a[5]=t5,a[6]=((C_word)li146),tmp=(C_word)a,a+=7,tmp));
t12=((C_word*)t10)[1];
f_7692(t12,t8,((C_word*)t0)[3]);}

/* g1382 in k7673 */
static void C_fcall f_7680(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_7680,3,t0,t1,t2);}
t3=t2;{
C_word av2[3];
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7688 in k7673 */
static void C_ccall f_7690(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7690,c,av);}{
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

/* map-loop1376 in k7673 */
static void C_fcall f_7692(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7692,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7717,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:727: g1382 */
t4=((C_word*)t0)[4];
f_7680(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7715 in map-loop1376 in k7673 */
static void C_ccall f_7717(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7717,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7692(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop1348 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_7726(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7726,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7751,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* eval.scm:724: g1354 */
t4=((C_word*)t0)[4];
f_7653(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7749 in map-loop1348 in k7458 in k7449 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7751(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7751,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7726(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* f_7774 in compile-call in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7774(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7774,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7791 in chicken.eval#compile-to-closure in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7793(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_7793,c,av);}
/* eval.scm:729: compile */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3825(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],C_SCHEME_FALSE,C_fixnum_greaterp(t1,C_fix(0)),((C_word*)t0)[6],((C_word*)t0)[7]);}

/* ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7843(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_7843,c,av);}
a=C_alloc(7);
t3=*((C_word*)lf[83]+1);
t4=*((C_word*)lf[97]+1);
t5=*((C_word*)lf[9]+1);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7847,a[2]=t5,a[3]=t4,a[4]=t3,a[5]=t2,a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* eval.scm:735: ##sys#meta-macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[158]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[158]+1);
av2[1]=t6;
tp(2,av2);}}

/* k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7847(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7847,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7850,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:736: ##sys#current-meta-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[159]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[159]+1);
av2[1]=t2;
tp(2,av2);}}

/* k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7850(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(31,c,4)))){
C_save_and_reclaim((void *)f_7850,c,av);}
a=C_alloc(31);
t2=C_SCHEME_FALSE;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=((C_word*)t0)[2];
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=t1;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_TRUE;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7855,a[2]=t3,a[3]=t5,a[4]=t7,a[5]=t9,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word)li152),tmp=(C_word)a,a+=10,tmp);
t11=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7898,a[2]=((C_word*)t0)[6],a[3]=((C_word)li155),tmp=(C_word)a,a+=4,tmp);
t12=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7930,a[2]=t3,a[3]=t5,a[4]=t7,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word)li156),tmp=(C_word)a,a+=9,tmp);
/* eval.scm:734: ##sys#dynamic-wind */
t13=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t13;
av2[1]=((C_word*)t0)[7];
av2[2]=t10;
av2[3]=t11;
av2[4]=t12;
((C_proc)(void*)(*((C_word*)t13+1)))(5,av2);}}

/* a7854 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7855(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_7855,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7859,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
if(C_truep(((C_word*)((C_word*)t0)[5])[1])){
/* eval.scm:734: ##sys#current-module1417 */
t3=((C_word*)t0)[8];{
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
f_7859(2,av2);}}}

/* k7857 in a7854 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_7859,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7862,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t1,tmp=(C_word)a,a+=11,tmp);
if(C_truep(((C_word*)((C_word*)t0)[5])[1])){
/* eval.scm:734: ##sys#macro-environment1418 */
t3=((C_word*)t0)[8];{
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
f_7862(2,av2);}}}

/* k7860 in k7857 in a7854 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7862(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_7862,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7865,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
if(C_truep(((C_word*)((C_word*)t0)[5])[1])){
/* eval.scm:734: ##sys#current-environment1419 */
t3=((C_word*)t0)[7];{
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
f_7865(2,av2);}}}

/* k7863 in k7860 in k7857 in a7854 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7865(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_7865,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_7869,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* eval.scm:734: ##sys#current-module1417 */
t3=((C_word*)t0)[10];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k7867 in k7863 in k7860 in k7857 in a7854 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7869(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_7869,c,av);}
a=C_alloc(12);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7873,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],tmp=(C_word)a,a+=12,tmp);
/* eval.scm:734: ##sys#macro-environment1418 */
t4=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* k7871 in k7867 in k7863 in k7860 in k7857 in a7854 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7873(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_7873,c,av);}
a=C_alloc(11);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7877,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],tmp=(C_word)a,a+=11,tmp);
/* eval.scm:734: ##sys#current-environment1419 */
t4=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* k7875 in k7871 in k7867 in k7863 in k7860 in k7857 in a7854 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7877(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_7877,c,av);}
a=C_alloc(8);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7880,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
/* eval.scm:734: ##sys#current-module1417 */
t4=((C_word*)t0)[9];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[10];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t4))(5,av2);}}

/* k7878 in k7875 in k7871 in k7867 in k7863 in k7860 in k7857 in a7854 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7880(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_7880,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7883,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* eval.scm:734: ##sys#macro-environment1418 */
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

/* k7881 in k7878 in k7875 in k7871 in k7867 in k7863 in k7860 in k7857 in a7854 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7883(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_7883,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7886,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:734: ##sys#current-environment1419 */
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

/* k7884 in k7881 in k7878 in k7875 in k7871 in k7867 in k7863 in k7860 in k7857 in a7854 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7886(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7886,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a7897 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7898(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_7898,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7904,a[2]=((C_word*)t0)[2],a[3]=((C_word)li153),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7913,a[2]=((C_word)li154),tmp=(C_word)a,a+=3,tmp);
/* eval.scm:737: scheme#dynamic-wind */
t4=*((C_word*)lf[160]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=*((C_word*)lf[161]+1);
av2[3]=t2;
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* a7903 in a7897 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7904(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,4)))){
C_save_and_reclaim((void *)f_7904,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7908,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:740: compile-to-closure */
f_3576(t2,((C_word*)t0)[2],C_SCHEME_END_OF_LIST,C_a_i_list(&a,4,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_TRUE));}

/* k7906 in a7903 in a7897 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7908(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7908,c,av);}
/* eval.scm:739: g1451 */
t2=t1;{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_END_OF_LIST;
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* a7912 in a7897 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7913(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_7913,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7917,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7928,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:752: ##sys#current-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t3;
tp(2,av2);}}

/* k7915 in a7912 in a7897 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7917(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7917,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7924,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:753: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[97]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[97]+1);
av2[1]=t2;
tp(2,av2);}}

/* k7922 in k7915 in a7912 in a7897 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7924(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7924,c,av);}
/* eval.scm:753: ##sys#meta-macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[158]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[158]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
tp(3,av2);}}

/* k7926 in a7912 in a7897 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7928(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7928,c,av);}
/* eval.scm:752: ##sys#current-meta-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[159]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[159]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
tp(3,av2);}}

/* a7929 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7930(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_7930,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7934,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* eval.scm:734: ##sys#current-module1417 */
t3=((C_word*)t0)[7];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k7932 in a7929 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7934(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_7934,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7937,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* eval.scm:734: ##sys#macro-environment1418 */
t3=((C_word*)t0)[7];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k7935 in k7932 in a7929 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7937(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_7937,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7940,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* eval.scm:734: ##sys#current-environment1419 */
t3=((C_word*)t0)[7];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k7938 in k7935 in k7932 in a7929 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7940(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_7940,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7943,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* eval.scm:734: ##sys#current-module1417 */
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
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}

/* k7941 in k7938 in k7935 in k7932 in a7929 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7943(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_7943,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7946,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* eval.scm:734: ##sys#macro-environment1418 */
t3=((C_word*)t0)[10];{
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

/* k7944 in k7941 in k7938 in k7935 in k7932 in a7929 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7946(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_7946,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7949,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* eval.scm:734: ##sys#current-environment1419 */
t3=((C_word*)t0)[9];{
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

/* k7947 in k7944 in k7941 in k7938 in k7935 in k7932 in a7929 in k7848 in k7845 in ##sys#eval/meta in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7949(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7949,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)t0)[3]);
t3=C_mutate(((C_word *)((C_word*)t0)[4])+1,((C_word*)t0)[5]);
t4=C_mutate(((C_word *)((C_word*)t0)[6])+1,((C_word*)t0)[7]);
t5=((C_word*)t0)[8];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7956(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,4)))){
C_save_and_reclaim((void *)f_7956,c,av);}
a=C_alloc(15);
t2=C_mutate((C_word*)lf[162]+1 /* (set! chicken.eval#eval-handler ...) */,t1);
t3=C_mutate((C_word*)lf[163]+1 /* (set! scheme#eval ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7958,a[2]=((C_word)li158),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[164]+1 /* (set! chicken.eval#module-environment ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7968,a[2]=((C_word)li159),tmp=(C_word)a,a+=3,tmp));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7975,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11423,a[2]=((C_word)li266),tmp=(C_word)a,a+=3,tmp);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11491,a[2]=((C_word)li267),tmp=(C_word)a,a+=3,tmp);
/* eval.scm:792: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t5;
av2[2]=t6;
av2[3]=t7;
C_call_with_values(4,av2);}}

/* scheme#eval in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7958(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,2)))){
C_save_and_reclaim((void*)f_7958,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7966,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:782: eval-handler */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[162]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[162]+1);
av2[1]=t4;
tp(2,av2);}}

/* k7964 in scheme#eval in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7966(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7966,c,av);}{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
C_apply(5,av2);}}

/* chicken.eval#module-environment in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7968(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7968,c,av);}
/* eval.scm:787: chicken.module#module-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[165]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[165]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7975(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,4)))){
C_save_and_reclaim((void *)f_7975,c,av);}
a=C_alloc(18);
t2=C_mutate((C_word*)lf[66]+1 /* (set! ##sys#decompose-lambda-list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7977,a[2]=((C_word)li162),tmp=(C_word)a,a+=3,tmp));
t3=C_a_i_record4(&a,4,lf[168],lf[169],C_SCHEME_FALSE,C_SCHEME_FALSE);
t4=C_mutate((C_word*)lf[170]+1 /* (set! scheme#interaction-environment ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8062,a[2]=t3,a[3]=((C_word)li163),tmp=(C_word)a,a+=4,tmp));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8066,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11407,a[2]=((C_word)li260),tmp=(C_word)a,a+=3,tmp);
/* eval.scm:839: chicken.base#set-record-printer! */
t7=*((C_word*)lf[353]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=lf[168];
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}

/* ##sys#decompose-lambda-list in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_7977(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,5)))){
C_save_and_reclaim((void *)f_7977,c,av);}
a=C_alloc(12);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7980,a[2]=t2,a[3]=((C_word)li160),tmp=(C_word)a,a+=4,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7990,a[2]=t3,a[3]=t4,a[4]=t6,a[5]=((C_word)li161),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_7990(t8,t1,t2,C_SCHEME_END_OF_LIST,C_fix(0));}

/* err in ##sys#decompose-lambda-list in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_7980(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_7980,2,t0,t1);}
t2=C_set_block_item(lf[166] /* ##sys#syntax-error-culprit */,0,C_SCHEME_FALSE);
/* eval.scm:824: ##sys#syntax-error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[68]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[68]+1);
av2[1]=t1;
av2[2]=lf[167];
av2[3]=((C_word*)t0)[2];
tp(4,av2);}}

/* loop in ##sys#decompose-lambda-list in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_7990(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,4)))){
C_save_and_reclaim_args((void *)trf_7990,5,t0,t1,t2,t3,t4);}
a=C_alloc(9);
t5=C_eqp(t2,C_SCHEME_END_OF_LIST);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8004,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:827: reverse */
t7=*((C_word*)lf[104]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
if(C_truep(C_i_not(C_blockp(t2)))){
/* eval.scm:828: err */
t6=((C_word*)t0)[3];
f_7980(t6,t1);}
else{
if(C_truep(C_symbolp(t2))){
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8023,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t7=C_a_i_cons(&a,2,t2,t3);
/* eval.scm:829: reverse */
t8=*((C_word*)lf[104]+1);{
C_word av2[3];
av2[0]=t8;
av2[1]=t6;
av2[2]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
if(C_truep(C_i_not(C_pairp(t2)))){
/* eval.scm:830: err */
t6=((C_word*)t0)[3];
f_7980(t6,t1);}
else{
t6=C_slot(t2,C_fix(1));
t7=C_slot(t2,C_fix(0));
t8=C_a_i_cons(&a,2,t7,t3);
/* eval.scm:831: loop */
t10=t1;
t11=t6;
t12=t8;
t13=C_fixnum_plus(t4,C_fix(1));
t1=t10;
t2=t11;
t3=t12;
t4=t13;
goto loop;}}}}}

/* k8002 in loop in ##sys#decompose-lambda-list in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8004(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8004,c,av);}
/* eval.scm:827: k */
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
av2[3]=((C_word*)t0)[4];
av2[4]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t2))(5,av2);}}

/* k8021 in loop in ##sys#decompose-lambda-list in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8023(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8023,c,av);}
/* eval.scm:829: k */
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
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t2))(5,av2);}}

/* scheme#interaction-environment in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8062(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8062,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8066(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_8066,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8069,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:845: chicken.module#module-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[165]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[165]+1);
av2[1]=t2;
av2[2]=lf[348];
av2[3]=lf[349];
tp(4,av2);}}

/* k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8069(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_8069,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8072,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:846: chicken.module#module-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[165]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[165]+1);
av2[1]=t2;
av2[2]=lf[346];
av2[3]=lf[347];
tp(4,av2);}}

/* k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8072(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_8072,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8075,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:847: chicken.module#module-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[165]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[165]+1);
av2[1]=t2;
av2[2]=lf[344];
av2[3]=lf[345];
tp(4,av2);}}

/* k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8075(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_8075,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8078,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* eval.scm:848: chicken.module#module-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[165]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[165]+1);
av2[1]=t2;
av2[2]=lf[342];
av2[3]=lf[343];
tp(4,av2);}}

/* k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8078(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_8078,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8080,a[2]=((C_word)li165),tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11401,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=t2,tmp=(C_word)a,a+=8,tmp);
/* eval.scm:873: strip */
f_8080(t3,C_slot(((C_word*)t0)[2],C_fix(2)));}

/* strip in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_8080(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_8080,2,t1,t2);}
a=C_alloc(6);
t3=C_i_check_list_2(t2,lf[171]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8089,a[2]=t5,a[3]=((C_word)li164),tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_8089(t7,t1,t2);}

/* foldr1576 in strip in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_8089(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_8089,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8120,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t6=t4;
t7=C_slot(t2,C_fix(1));
t1=t6;
t2=t7;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8118 in foldr1576 in strip in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8120(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_8120,c,av);}
a=C_alloc(3);
t2=C_i_car(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep((C_truep(C_eqp(t2,lf[172]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[173]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[174]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[175]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[176]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[94]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[177]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[178]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[179]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[180]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[181]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[107]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[182]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[183]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[84]))?C_SCHEME_TRUE:C_SCHEME_FALSE))))))))))))))))?t1:C_a_i_cons(&a,2,((C_word*)t0)[2],t1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* scheme#scheme-report-environment in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8138(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_8138,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8142,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* eval.scm:879: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[187]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[187]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[185];
tp(4,av2);}}

/* k8140 in scheme#scheme-report-environment in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8142(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8142,c,av);}
switch(((C_word*)t0)[2]){
case C_fix(4):
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}
case C_fix(5):
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}
default:
/* eval.scm:884: ##sys#error */
t2=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[185];
av2[3]=lf[186];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* scheme#null-environment in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8163(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_8163,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8167,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* eval.scm:889: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[187]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[187]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[189];
tp(4,av2);}}

/* k8165 in scheme#null-environment in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8167(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8167,c,av);}
switch(((C_word*)t0)[2]){
case C_fix(4):
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}
case C_fix(5):
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}
default:
/* eval.scm:894: ##sys#error */
t2=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[189];
av2[3]=lf[190];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_8189(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_8189,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[192] /* (set! chicken.load#constant2145 ...) */,lf[193]);
t3=C_mutate(&lf[194] /* (set! chicken.load#constant2148 ...) */,lf[195]);
t4=C_mutate(&lf[196] /* (set! chicken.load#constant2178 ...) */,lf[197]);
t5=C_mutate(&lf[198] /* (set! chicken.load#constant2187 ...) */,lf[199]);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9479,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11373,a[2]=t6,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:952: chicken.platform#software-type */
t8=*((C_word*)lf[341]+1);{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* loop in chicken.load#provided? in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_fcall f_8566(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_8566,3,t0,t1,t2);}
a=C_alloc(5);
t3=C_i_nullp(t2);
if(C_truep(t3)){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8588,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* mini-srfi-1.scm:82: pred */
t5=((C_word*)t0)[3];{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=C_i_car(t2);
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}}

/* k8586 in loop in chicken.load#provided? in k10175 in k10166 in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_8588(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8588,c,av);}
if(C_truep(C_i_not(t1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* mini-srfi-1.scm:83: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_8566(t2,((C_word*)t0)[2],C_u_i_cdr(((C_word*)t0)[4]));}}

/* k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_9479(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_9479,2,t0,t1);}
a=C_alloc(6);
t2=C_mutate(&lf[200] /* (set! chicken.load#load-library-extension ...) */,t1);
t3=C_mutate((C_word*)lf[201]+1 /* (set! ##sys#load-dynamic-extension ...) */,lf[196]);
t4=C_mutate((C_word*)lf[202]+1 /* (set! chicken.load#core-library? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9482,a[2]=((C_word)li168),tmp=(C_word)a,a+=3,tmp));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9496,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:965: chicken.platform#software-version */
t6=*((C_word*)lf[332]+1);{
C_word av2[2];
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* chicken.load#core-library? in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_9482(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9482,c,av);}
t3=C_i_memq(t2,lf[194]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?t3:C_i_assq(t2,lf[192]));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_9496(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_9496,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9499,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_eqp(t1,lf[329]);
if(C_truep(t3)){
t4=t2;
f_9499(t4,lf[330]);}
else{
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11330,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11334,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t6=*((C_word*)lf[245]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_LIB_NAME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}}

/* k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_9499(C_word t0,C_word t1){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,4)))){
C_save_and_reclaim_args((void *)trf_9499,2,t0,t1);}
a=C_alloc(15);
t2=C_mutate(&lf[203] /* (set! chicken.load#default-dynamic-load-libraries ...) */,t1);
t3=C_mutate((C_word*)lf[101]+1 /* (set! ##sys#provide ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9501,a[2]=((C_word)li169),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[204]+1 /* (set! ##sys#provided? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9504,a[2]=((C_word)li170),tmp=(C_word)a,a+=3,tmp));
t5=(C_truep(*((C_word*)lf[205]+1))?lf[206]:lf[207]);
t6=C_mutate(&lf[208] /* (set! chicken.load#path-separators ...) */,t5);
t7=C_mutate(&lf[209] /* (set! chicken.load#path-separator-index/right ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9511,a[2]=((C_word)li172),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate(&lf[210] /* (set! chicken.load#make-relative-pathname ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9546,a[2]=((C_word)li173),tmp=(C_word)a,a+=3,tmp));
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9589,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1000: chicken.base#make-parameter */
t10=*((C_word*)lf[326]+1);{
C_word av2[3];
av2[0]=t10;
av2[1]=t9;
av2[2]=C_i_debug_modep();
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}

/* ##sys#provide in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_9501(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,1)))){
C_save_and_reclaim((void *)f_9501,c,av);}
a=C_alloc(8);
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_provide(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* ##sys#provided? in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_9504(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9504,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_providedp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.load#path-separator-index/right in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_9511(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_9511,2,t1,t2);}
a=C_alloc(4);
t3=C_block_size(t2);
t4=C_fixnum_difference(t3,C_fix(1));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9521,a[2]=t2,a[3]=((C_word)li171),tmp=(C_word)a,a+=4,tmp);
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=(
  f_9521(t5,t4)
);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* loop in chicken.load#path-separator-index/right in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static C_word C_fcall f_9521(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
t2=C_subchar(((C_word*)t0)[2],t1);
t3=lf[208];
if(C_truep(C_u_i_memq(t2,lf[208]))){
return(t1);}
else{
if(C_truep(C_fixnum_lessp(C_fix(0),t1))){
t5=C_fixnum_difference(t1,C_fix(1));
t1=t5;
goto loop;}
else{
return(C_SCHEME_FALSE);}}}

/* chicken.load#make-relative-pathname in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_fcall f_9546(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_9546,3,t1,t2,t3);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9550,a[2]=t1,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_stringp(t2))){
t5=C_block_size(t3);
if(C_truep(C_i_fixnum_positivep(t5))){
t6=C_subchar(t3,C_fix(0));
t7=lf[208];
if(C_truep(C_i_not(C_u_i_memq(t6,lf[208])))){
/* eval.scm:994: path-separator-index/right */
f_9511(t4,t2);}
else{
t8=t4;{
C_word av2[2];
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
f_9550(2,av2);}}}
else{
t6=t4;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
f_9550(2,av2);}}}
else{
t5=t4;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
f_9550(2,av2);}}}

/* k9548 in chicken.load#make-relative-pathname in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_9550(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_9550,c,av);}
a=C_alloc(4);
if(C_truep(C_i_not(t1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9563,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:995: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[213]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[213]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(0);
av2[4]=t1;
tp(5,av2);}}}

/* k9561 in k9548 in chicken.load#make-relative-pathname in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_9563(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9563,c,av);}
/* eval.scm:995: scheme#string-append */
t2=*((C_word*)lf[211]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[212];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 */
static void C_ccall f_9589(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,c,5)))){
C_save_and_reclaim((void *)f_9589,c,av);}
a=C_alloc(25);
t2=C_mutate((C_word*)lf[214]+1 /* (set! chicken.load#load-verbose ...) */,t1);
t3=C_set_block_item(lf[215] /* ##sys#current-load-filename */,0,C_SCHEME_FALSE);
t4=C_set_block_item(lf[216] /* ##sys#dload-disabled */,0,C_SCHEME_FALSE);
t5=C_mutate((C_word*)lf[217]+1 /* (set! chicken.load#set-dynamic-load-mode! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9593,a[2]=((C_word)li175),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate(&lf[226] /* (set! chicken.load#c-toplevel ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9693,a[2]=((C_word)li176),tmp=(C_word)a,a+=3,tmp));
t7=*((C_word*)lf[163]+1);
t8=C_mutate(&lf[233] /* (set! chicken.load#load/internal ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9707,a[2]=t7,a[3]=((C_word)li191),tmp=(C_word)a,a+=4,tmp));
t9=C_mutate((C_word*)lf[261]+1 /* (set! scheme#load ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10109,a[2]=((C_word)li192),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[262]+1 /* (set! chicken.load#load-relative ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10124,a[2]=((C_word)li193),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[263]+1 /* (set! chicken.load#load-noisily ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10142,a[2]=((C_word)li197),tmp=(C_word)a,a+=3,tmp));
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10168,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_mk_bool(C_USES_SONAME))){
t13=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11318,a[2]=t12,tmp=(C_word)a,a+=3,tmp);
t14=C_fix((C_word)C_BINARY_VERSION);
/* ##sys#fixnum->string */
t15=*((C_word*)lf[328]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t15;
av2[1]=t13;
av2[2]=t14;
av2[3]=C_fix(10);
((C_proc)(void*)(*((C_word*)t15+1)))(4,av2);}}
else{
t13=t12;{
C_word *av2=av;
av2[0]=t13;
av2[1]=lf[200];
f_10168(2,av2);}}}

/* chicken.load#set-dynamic-load-mode! in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_ccall f_9593(C_word c,C_word *av){
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
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(20,c,3)))){
C_save_and_reclaim((void *)f_9593,c,av);}
a=C_alloc(20);
t3=C_i_pairp(t2);
t4=(C_truep(t3)?t2:C_a_i_list1(&a,1,t2));
t5=C_SCHEME_FALSE;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_TRUE;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9600,a[2]=t1,a[3]=t6,a[4]=t8,tmp=(C_word)a,a+=5,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9605,a[2]=t11,a[3]=t8,a[4]=t6,a[5]=((C_word)li174),tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_9605(t13,t9,t4);}

/* k9598 in chicken.load#set-dynamic-load-mode! in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_9600(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9600,c,av);}
/* eval.scm:1020: ##sys#set-dlopen-flags! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[218]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[218]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=((C_word*)((C_word*)t0)[4])[1];
tp(4,av2);}}

/* loop in chicken.load#set-dynamic-load-mode! in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_fcall f_9605(C_word t0,C_word t1,C_word t2){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_9605,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9618,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t5=C_eqp(t3,lf[219]);
if(C_truep(t5)){
t6=C_set_block_item(((C_word*)t0)[3],0,C_SCHEME_TRUE);
/* eval.scm:1019: loop */
t11=t1;
t12=C_slot(t2,C_fix(1));
t1=t11;
t2=t12;
goto loop;}
else{
t6=C_eqp(t3,lf[220]);
if(C_truep(t6)){
t7=C_set_block_item(((C_word*)t0)[3],0,C_SCHEME_FALSE);
/* eval.scm:1019: loop */
t11=t1;
t12=C_slot(t2,C_fix(1));
t1=t11;
t2=t12;
goto loop;}
else{
t7=C_eqp(t3,lf[221]);
if(C_truep(t7)){
t8=C_set_block_item(((C_word*)t0)[4],0,C_SCHEME_FALSE);
/* eval.scm:1019: loop */
t11=t1;
t12=C_slot(t2,C_fix(1));
t1=t11;
t2=t12;
goto loop;}
else{
t8=C_eqp(t3,lf[222]);
if(C_truep(t8)){
t9=C_set_block_item(((C_word*)t0)[4],0,C_SCHEME_TRUE);
/* eval.scm:1019: loop */
t11=t1;
t12=C_slot(t2,C_fix(1));
t1=t11;
t2=t12;
goto loop;}
else{
/* eval.scm:1018: ##sys#signal-hook */
t9=*((C_word*)lf[223]+1);{
C_word av2[5];
av2[0]=t9;
av2[1]=t4;
av2[2]=lf[224];
av2[3]=lf[225];
av2[4]=C_slot(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}}}}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k9616 in loop in chicken.load#set-dynamic-load-mode! in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_9618(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9618,c,av);}
/* eval.scm:1019: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_9605(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k9685 in chicken.load#c-toplevel in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_9687(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9687,c,av);}
/* eval.scm:1025: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[228]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[228]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[231];
tp(4,av2);}}

/* chicken.load#c-toplevel in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_fcall f_9693(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,3)))){
C_save_and_reclaim_args((void *)trf_9693,3,t1,t2,t3);}
a=C_alloc(10);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9701,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9705,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_not(t2))){
/* eval.scm:1030: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[228]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[228]+1);
av2[1]=t4;
av2[2]=lf[229];
av2[3]=lf[230];
tp(4,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9687,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1026: chicken.internal#string->c-identifier */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[232]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[232]+1);
av2[1]=t6;
av2[2]=C_slot(t2,C_fix(1));
tp(3,av2);}}}

/* k9699 in chicken.load#c-toplevel in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_9701(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9701,c,av);}
/* eval.scm:1030: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[227]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[227]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k9703 in chicken.load#c-toplevel in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_9705(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9705,c,av);}
/* eval.scm:1030: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[228]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[228]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[229];
av2[3]=t1;
tp(4,av2);}}

/* chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in k3519 in ... */
static void C_fcall f_9707(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(23,0,3)))){
C_save_and_reclaim_args((void *)trf_9707,5,t0,t1,t2,t3,t4);}
a=C_alloc(23);
t5=C_i_nullp(t4);
t6=(C_truep(t5)?C_SCHEME_FALSE:C_i_car(t4));
t7=C_i_nullp(t4);
t8=(C_truep(t7)?C_SCHEME_END_OF_LIST:C_i_cdr(t4));
t9=C_i_nullp(t8);
t10=(C_truep(t9)?C_SCHEME_FALSE:C_i_car(t8));
t11=C_i_nullp(t8);
t12=(C_truep(t11)?C_SCHEME_END_OF_LIST:C_i_cdr(t8));
t13=C_i_nullp(t12);
t14=(C_truep(t13)?C_SCHEME_FALSE:C_i_car(t12));
t15=C_i_nullp(t12);
t16=(C_truep(t15)?C_SCHEME_END_OF_LIST:C_i_cdr(t12));
t17=C_i_nullp(t16);
t18=(C_truep(t17)?C_SCHEME_FALSE:C_i_car(t16));
t19=C_i_nullp(t16);
t20=(C_truep(t19)?C_SCHEME_END_OF_LIST:C_i_cdr(t16));
t21=C_SCHEME_UNDEFINED;
t22=(*a=C_VECTOR_TYPE|1,a[1]=t21,tmp=(C_word)a,a+=2,tmp);
t23=C_SCHEME_UNDEFINED;
t24=(*a=C_VECTOR_TYPE|1,a[1]=t23,tmp=(C_word)a,a+=2,tmp);
t25=C_SCHEME_UNDEFINED;
t26=(*a=C_VECTOR_TYPE|1,a[1]=t25,tmp=(C_word)a,a+=2,tmp);
t27=C_SCHEME_UNDEFINED;
t28=(*a=C_VECTOR_TYPE|1,a[1]=t27,tmp=(C_word)a,a+=2,tmp);
t29=(C_truep(t3)?t3:((C_word*)t0)[2]);
t30=C_set_block_item(t22,0,t29);
t31=C_set_block_item(t24,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9750,a[2]=t18,a[3]=((C_word)li177),tmp=(C_word)a,a+=4,tmp));
t32=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_9785,a[2]=t26,a[3]=t28,a[4]=t1,a[5]=t10,a[6]=t22,a[7]=t6,a[8]=t14,a[9]=t2,a[10]=t24,tmp=(C_word)a,a+=11,tmp);
if(C_truep(C_i_not(*((C_word*)lf[216]+1)))){
/* eval.scm:1059: chicken.platform#feature? */
t33=*((C_word*)lf[259]+1);{
C_word av2[3];
av2[0]=t33;
av2[1]=t32;
av2[2]=lf[260];
((C_proc)(void*)(*((C_word*)t33+1)))(3,av2);}}
else{
t33=t32;{
C_word av2[2];
av2[0]=t33;
av2[1]=C_SCHEME_FALSE;
f_9785(2,av2);}}}

/* k9743 */
static void C_ccall f_9745(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9745,c,av);}
if(C_truep(t1)){
/* eval.scm:1052: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[227]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[227]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[235];
tp(4,av2);}}
else{
/* eval.scm:1049: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[228]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[228]+1);
av2[1]=((C_word*)t0)[4];
av2[2]=lf[236];
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}}

/* f_9750 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_fcall f_9750(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_9750,3,t0,t1,t2);}
a=C_alloc(12);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9754,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9781,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9745,a[2]=t3,a[3]=t2,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1047: path-separator-index/right */
f_9511(t5,t2);}

/* k9752 */
static void C_ccall f_9754(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_9754,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9757,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9777,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1053: c-toplevel */
f_9693(t3,((C_word*)t0)[3],lf[235]);}

/* k9755 in k9752 */
static void C_ccall f_9757(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_9757,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_symbolp(((C_word*)t0)[3]))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9773,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1055: c-toplevel */
f_9693(t2,C_SCHEME_FALSE,lf[235]);}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}}

/* k9771 in k9755 in k9752 */
static void C_ccall f_9773(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9773,c,av);}
/* eval.scm:1055: ##sys#dload */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[234]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[234]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
tp(4,av2);}}

/* k9775 in k9752 */
static void C_ccall f_9777(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9777,c,av);}
/* eval.scm:1053: ##sys#dload */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[234]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[234]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
tp(4,av2);}}

/* k9779 */
static void C_ccall f_9781(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9781,c,av);}
/* eval.scm:1052: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[227]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[227]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[235];
tp(4,av2);}}

/* k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in k3522 in ... */
static void C_ccall f_9785(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_9785,c,av);}
a=C_alloc(16);
t2=C_set_block_item(((C_word*)t0)[2],0,t1);
t3=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_9789,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[2],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10004,a[2]=t3,a[3]=((C_word*)t0)[9],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1062: chicken.base#port? */
t5=*((C_word*)lf[258]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[9];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in k3525 in ... */
static void C_ccall f_9789(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_9789,c,av);}
a=C_alloc(15);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_9792,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10001,a[2]=((C_word*)t0)[2],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1073: load-verbose */
t5=*((C_word*)lf[214]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in k3528 in ... */
static void C_ccall f_9792(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_9792,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9795,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
if(C_truep(((C_word*)((C_word*)t0)[3])[1])){
if(C_truep(((C_word*)((C_word*)t0)[9])[1])){
/* eval.scm:1079: dload */
t3=((C_word*)((C_word*)t0)[10])[1];
f_9750(t3,t2,((C_word*)((C_word*)t0)[3])[1]);}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_9795(2,av2);}}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_9795(2,av2);}}}

/* k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_9795(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_9795,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9798,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9803,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word)li190),tmp=(C_word)a,a+=9,tmp);
t4=t3;
f_9803(t4,t2);}}

/* k9796 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_9798(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9798,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_fcall f_9803(C_word t0,C_word t1){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(39,0,4)))){
C_save_and_reclaim_args((void *)trf_9803,2,t0,t1);}
a=C_alloc(39);
t2=C_SCHEME_TRUE;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=((C_word*)((C_word*)t0)[2])[1];
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)((C_word*)t0)[2])[1];
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_FALSE;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_SCHEME_FALSE;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_SCHEME_FALSE;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9809,a[2]=t9,a[3]=t11,a[4]=t13,a[5]=t3,a[6]=t5,a[7]=t7,a[8]=((C_word)li178),tmp=(C_word)a,a+=9,tmp);
t15=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9818,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[7],a[8]=((C_word)li188),tmp=(C_word)a,a+=9,tmp);
t16=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9970,a[2]=t3,a[3]=t5,a[4]=t7,a[5]=t9,a[6]=t11,a[7]=t13,a[8]=((C_word)li189),tmp=(C_word)a,a+=9,tmp);
/* eval.scm:1082: ##sys#dynamic-wind */
t17=*((C_word*)lf[53]+1);{
C_word av2[5];
av2[0]=t17;
av2[1]=t1;
av2[2]=t14;
av2[3]=t15;
av2[4]=t16;
((C_proc)(void*)(*((C_word*)t17+1)))(5,av2);}}

/* a9808 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_9809(C_word c,C_word *av){
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
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9809,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[237]+1));
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,*((C_word*)lf[215]+1));
t4=C_mutate(((C_word *)((C_word*)t0)[4])+1,*((C_word*)lf[90]+1));
t5=C_mutate((C_word*)lf[237]+1 /* (set! ##sys#read-error-with-line-number ...) */,((C_word*)((C_word*)t0)[5])[1]);
t6=C_mutate((C_word*)lf[215]+1 /* (set! ##sys#current-load-filename ...) */,((C_word*)((C_word*)t0)[6])[1]);
t7=C_mutate((C_word*)lf[90]+1 /* (set! ##sys#current-source-filename ...) */,((C_word*)((C_word*)t0)[7])[1]);
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_9818(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_9818,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9822,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,tmp=(C_word)a,a+=8,tmp);
if(C_truep(((C_word*)((C_word*)t0)[6])[1])){
/* eval.scm:1085: open-input-file */
t3=*((C_word*)lf[248]+1);{
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
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[7];
f_9822(2,av2);}}}

/* k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in ... */
static void C_ccall f_9822(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,4)))){
C_save_and_reclaim((void *)f_9822,c,av);}
a=C_alloc(17);
t2=*((C_word*)lf[238]+1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9827,a[2]=((C_word)li179),tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_9830,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word)li186),tmp=(C_word)a,a+=10,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9961,a[2]=t1,a[3]=((C_word)li187),tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1087: ##sys#dynamic-wind */
t6=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=((C_word*)t0)[7];
av2[2]=t3;
av2[3]=t4;
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* a9826 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in ... */
static void C_ccall f_9827(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9827,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in ... */
static void C_ccall f_9830(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_9830,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_9834,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* eval.scm:1090: scheme#peek-char */
t3=*((C_word*)lf[246]+1);{
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

/* k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in ... */
static void C_ccall f_9834(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(19,c,3)))){
C_save_and_reclaim((void *)f_9834,c,av);}
a=C_alloc(19);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9837,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t3=C_eqp(t1,C_make_character(127));
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9952,a[2]=t2,a[3]=((C_word*)t0)[9],tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9956,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t6=*((C_word*)lf[245]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_mpointer(&a,(void*)C_dlerror);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_9837(2,av2);}}}

/* k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in ... */
static void C_ccall f_9837(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_9837,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9840,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* eval.scm:1098: read-with-source-info */
t3=((C_word*)t0)[2];{
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

/* k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in ... */
static void C_ccall f_9840(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9840,c,av);}
a=C_alloc(12);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_9845,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word)li185),tmp=(C_word)a,a+=10,tmp));
t5=((C_word*)t3)[1];
f_9845(t5,((C_word*)t0)[8],t1);}

/* doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in ... */
static void C_fcall f_9845(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_9845,3,t0,t1,t2);}
a=C_alloc(10);
if(C_truep(C_eofp(t2))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_9855,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=t2,a[9]=((C_word*)t0)[7],tmp=(C_word)a,a+=10,tmp);
if(C_truep(((C_word*)t0)[8])){
/* eval.scm:1101: printer */
t4=((C_word*)t0)[8];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}
else{
t4=t3;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_9855(2,av2);}}}}

/* k9853 in doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in ... */
static void C_ccall f_9855(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_9855,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9858,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9867,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],a[5]=((C_word)li182),tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9901,a[2]=((C_word*)t0)[9],a[3]=((C_word)li184),tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1102: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t2;
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}

/* k9856 in k9853 in doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in ... */
static void C_ccall f_9858(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_9858,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9865,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* eval.scm:1099: read-with-source-info */
t3=((C_word*)t0)[4];{
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

/* k9863 in k9856 in k9853 in doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in ... */
static void C_ccall f_9865(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9865,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_9845(t2,((C_word*)t0)[3],t1);}

/* a9866 in k9853 in doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in ... */
static void C_ccall f_9867(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_9867,c,av);}
a=C_alloc(5);
if(C_truep(((C_word*)t0)[2])){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9874,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* eval.scm:1105: ##sys#start-timer */
t3=*((C_word*)lf[241]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* eval.scm:1106: evalproc */
t2=((C_word*)((C_word*)t0)[3])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[4];
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}}

/* k9872 in a9866 in k9853 in doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in ... */
static void C_ccall f_9874(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_9874,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9879,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li180),tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9885,a[2]=((C_word)li181),tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1105: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a9878 in k9872 in a9866 in k9853 in doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in ... */
static void C_ccall f_9879(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9879,c,av);}
/* eval.scm:1105: evalproc */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* a9884 in k9872 in a9866 in k9853 in doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in ... */
static void C_ccall f_9885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +7,c,2)))){
C_save_and_reclaim((void*)f_9885,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+7);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9889,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9896,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1105: ##sys#stop-timer */
t5=*((C_word*)lf[240]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k9887 in a9884 in k9872 in a9866 in k9853 in doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in ... */
static void C_ccall f_9889(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9889,c,av);}{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
C_apply_values(3,av2);}}

/* k9894 in a9884 in k9872 in a9866 in k9853 in doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in ... */
static void C_ccall f_9896(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9896,c,av);}
/* eval.scm:1105: ##sys#display-times */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[239]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[239]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
tp(3,av2);}}

/* a9900 in k9853 in doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in ... */
static void C_ccall f_9901(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +6,c,3)))){
C_save_and_reclaim((void*)f_9901,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+6);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
C_word t6;
if(C_truep(((C_word*)t0)[2])){
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9918,a[2]=t4,a[3]=((C_word)li183),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_9918(t6,t1,t2);}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k9908 in for-each-loop2363 in a9900 in k9853 in doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in ... */
static void C_ccall f_9910(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9910,c,av);}
/* eval.scm:1112: newline */
t2=*((C_word*)lf[242]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* for-each-loop2363 in a9900 in k9853 in doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in ... */
static void C_fcall f_9918(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_9918,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9928,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9910,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1111: write */
t6=*((C_word*)lf[16]+1);{
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

/* k9926 in for-each-loop2363 in a9900 in k9853 in doloop2353 in k9838 in k9835 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in ... */
static void C_ccall f_9928(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9928,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_9918(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k9950 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in ... */
static void C_ccall f_9952(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9952,c,av);}
/* eval.scm:1092: ##sys#error */
t2=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[235];
av2[3]=t1;
av2[4]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k9954 in k9832 in a9829 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in ... */
static void C_ccall f_9956(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9956,c,av);}
if(C_truep(t1)){
/* eval.scm:1094: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[228]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[228]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[243];
av2[3]=t1;
tp(4,av2);}}
else{
/* eval.scm:1094: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[228]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[228]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[243];
av2[3]=lf[244];
tp(4,av2);}}}

/* a9960 in k9820 in a9817 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in ... */
static void C_ccall f_9961(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9961,c,av);}
/* eval.scm:1115: close-input-port */
t2=*((C_word*)lf[247]+1);{
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

/* a9969 in a9802 in k9793 in k9790 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_9970(C_word c,C_word *av){
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
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9970,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[237]+1));
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,*((C_word*)lf[215]+1));
t4=C_mutate(((C_word *)((C_word*)t0)[4])+1,*((C_word*)lf[90]+1));
t5=C_mutate((C_word*)lf[237]+1 /* (set! ##sys#read-error-with-line-number ...) */,((C_word*)((C_word*)t0)[5])[1]);
t6=C_mutate((C_word*)lf[215]+1 /* (set! ##sys#current-load-filename ...) */,((C_word*)((C_word*)t0)[6])[1]);
t7=C_mutate((C_word*)lf[90]+1 /* (set! ##sys#current-source-filename ...) */,((C_word*)((C_word*)t0)[7])[1]);
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* k9987 in k9999 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in k3572 in ... */
static void C_ccall f_9989(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9989,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9992,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1075: display */
t3=*((C_word*)lf[250]+1);{
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

/* k9990 in k9987 in k9999 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in k7954 in ... */
static void C_ccall f_9992(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9992,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9995,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* eval.scm:1076: display */
t3=*((C_word*)lf[250]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[251];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k9993 in k9990 in k9987 in k9999 in k9787 in k9783 in chicken.load#load/internal in k9587 in k9497 in k9494 in k9477 in k8187 in k11375 in k11383 in k11391 in k11399 in k8076 in k8073 in k8070 in k8067 in k8064 in k7973 in ... */
static void C_ccall f_9995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9995,c,av);}
/* eval.scm:1077: chicken.base#flush-output */
t2=*((C_word*)lf[249]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_eval_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("eval"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_eval_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(2316))){
C_save(t1);
C_rereclaim2(2316*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,357);
lf[0]=C_h_intern(&lf[0],4, C_text("eval"));
lf[1]=C_h_intern(&lf[1],13, C_text("chicken.eval#"));
lf[2]=C_h_intern(&lf[2],21, C_text("##sys#unbound-in-eval"));
lf[3]=C_h_intern(&lf[3],22, C_text("##sys#eval-debug-level"));
lf[5]=C_h_intern(&lf[5],9, C_text("##sys#get"));
lf[6]=C_h_intern(&lf[6],18, C_text("##core#macro-alias"));
lf[7]=C_h_intern(&lf[7],13, C_text("scheme#values"));
lf[8]=C_h_intern(&lf[8],14, C_text("scheme#symbol\077"));
lf[9]=C_h_intern(&lf[9],25, C_text("##sys#current-environment"));
lf[10]=C_h_intern(&lf[10],9, C_text("frameinfo"));
lf[11]=C_h_intern(&lf[11],20, C_text("##sys#current-thread"));
lf[12]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010<syntax>"));
lf[13]=C_h_intern(&lf[13],30, C_text("chicken.syntax#get-line-number"));
lf[14]=C_h_intern(&lf[14],22, C_text("##sys#make-lambda-info"));
lf[15]=C_h_intern(&lf[15],30, C_text("chicken.base#get-output-string"));
lf[16]=C_h_intern(&lf[16],12, C_text("scheme#write"));
lf[17]=C_h_intern(&lf[17],31, C_text("chicken.base#open-output-string"));
lf[18]=C_h_intern(&lf[18],21, C_text("##sys#decorate-lambda"));
lf[19]=C_h_intern(&lf[19],11, C_text("##sys#error"));
lf[20]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020unbound variable"));
lf[21]=C_h_intern(&lf[21],34, C_text("##sys#symbol-has-toplevel-binding\077"));
lf[22]=C_h_intern(&lf[22],23, C_text("##sys#alias-global-hook"));
lf[23]=C_h_intern(&lf[23],26, C_text("##sys#syntax-error/context"));
lf[24]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031illegal non-atomic object"));
lf[25]=C_h_intern(&lf[25],34, C_text("##sys#update-line-number-database!"));
lf[26]=C_h_intern(&lf[26],12, C_text("##core#quote"));
lf[27]=C_h_intern(&lf[27],27, C_text("chicken.syntax#strip-syntax"));
lf[28]=C_h_intern(&lf[28],13, C_text("##core#syntax"));
lf[29]=C_h_intern(&lf[29],12, C_text("##core#check"));
lf[30]=C_h_intern(&lf[30],16, C_text("##core#immutable"));
lf[31]=C_h_intern(&lf[31],16, C_text("##core#undefined"));
lf[32]=C_h_intern(&lf[32],9, C_text("##core#if"));
lf[33]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[34]=C_h_intern(&lf[34],12, C_text("##core#begin"));
lf[35]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[36]=C_h_intern(&lf[36],33, C_text("##core#ensure-toplevel-definition"));
lf[37]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[38]=C_h_intern(&lf[38],18, C_text("##sys#put/restore!"));
lf[39]=C_h_intern(&lf[39],14, C_text("##sys#override"));
lf[40]=C_h_intern(&lf[40],5, C_text("value"));
lf[41]=C_decode_literal(C_heaptop,C_text("\376B\000\0008toplevel definition in non-toplevel context for variable"));
lf[42]=C_h_intern(&lf[42],11, C_text("##core#set!"));
lf[43]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032environment is not mutable"));
lf[44]=C_h_intern(&lf[44],21, C_text("##sys#notices-enabled"));
lf[45]=C_h_intern(&lf[45],12, C_text("##sys#notice"));
lf[46]=C_decode_literal(C_heaptop,C_text("\376B\000\000$assignment to imported value binding"));
lf[47]=C_h_intern(&lf[47],10, C_text("##core#let"));
lf[48]=C_h_intern(&lf[48],3, C_text("map"));
lf[49]=C_h_intern(&lf[49],12, C_text("scheme#cadar"));
lf[50]=C_h_intern(&lf[50],13, C_text("scheme#cadadr"));
lf[51]=C_h_intern(&lf[51],17, C_text("##sys#make-vector"));
lf[52]=C_h_intern(&lf[52],23, C_text("##sys#canonicalize-body"));
lf[53]=C_h_intern(&lf[53],18, C_text("##sys#dynamic-wind"));
lf[54]=C_h_intern(&lf[54],15, C_text("##sys#extend-se"));
lf[55]=C_h_intern(&lf[55],19, C_text("chicken.base#gensym"));
lf[56]=C_h_intern(&lf[56],14, C_text("##core#letrec\052"));
lf[57]=C_h_intern(&lf[57],12, C_text("##sys#append"));
lf[58]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[59]=C_h_intern(&lf[59],13, C_text("##core#letrec"));
lf[60]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[61]=C_h_intern(&lf[61],13, C_text("##core#lambda"));
lf[62]=C_h_intern(&lf[62],1, C_text("\077"));
lf[63]=C_h_intern(&lf[63],12, C_text("##sys#vector"));
lf[64]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022bad argument count"));
lf[65]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022bad argument count"));
lf[66]=C_h_intern(&lf[66],27, C_text("##sys#decompose-lambda-list"));
lf[67]=C_h_intern(&lf[67],33, C_text("##sys#expand-extended-lambda-list"));
lf[68]=C_h_intern(&lf[68],23, C_text("##sys#syntax-error-hook"));
lf[69]=C_h_intern(&lf[69],27, C_text("##sys#extended-lambda-list\077"));
lf[70]=C_h_intern(&lf[70],18, C_text("##sys#check-syntax"));
lf[71]=C_h_intern(&lf[71],6, C_text("lambda"));
lf[72]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\013\001lambda-list\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[73]=C_h_intern(&lf[73],17, C_text("##core#let-syntax"));
lf[74]=C_h_intern(&lf[74],13, C_text("scheme#append"));
lf[75]=C_h_intern(&lf[75],24, C_text("##sys#ensure-transformer"));
lf[76]=C_h_intern(&lf[76],15, C_text("##sys#eval/meta"));
lf[77]=C_h_intern(&lf[77],20, C_text("##core#letrec-syntax"));
lf[78]=C_h_intern(&lf[78],8, C_text("for-each"));
lf[79]=C_h_intern(&lf[79],20, C_text("##core#define-syntax"));
lf[80]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[81]=C_h_intern(&lf[81],30, C_text("##sys#extend-macro-environment"));
lf[82]=C_h_intern(&lf[82],28, C_text("##sys#register-syntax-export"));
lf[83]=C_h_intern(&lf[83],20, C_text("##sys#current-module"));
lf[84]=C_h_intern(&lf[84],6, C_text("syntax"));
lf[85]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032environment is not mutable"));
lf[86]=C_h_intern(&lf[86],29, C_text("##core#define-compiler-syntax"));
lf[87]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[88]=C_h_intern(&lf[88],26, C_text("##core#let-compiler-syntax"));
lf[89]=C_h_intern(&lf[89],14, C_text("##core#include"));
lf[90]=C_h_intern(&lf[90],29, C_text("##sys#current-source-filename"));
lf[91]=C_h_intern(&lf[91],29, C_text("##sys#include-forms-from-file"));
lf[92]=C_h_intern(&lf[92],23, C_text("##core#let-module-alias"));
lf[93]=C_h_intern(&lf[93],25, C_text("##sys#with-module-aliases"));
lf[94]=C_h_intern(&lf[94],7, C_text("functor"));
lf[95]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001symbol\376\003\000\000\002\376\001\000\000\006\001symbol\376\377\016"));
lf[96]=C_h_intern(&lf[96],13, C_text("##core#module"));
lf[97]=C_h_intern(&lf[97],23, C_text("##sys#macro-environment"));
lf[98]=C_h_intern(&lf[98],30, C_text("##sys#module-alias-environment"));
lf[99]=C_h_intern(&lf[99],31, C_text("##sys#initial-macro-environment"));
lf[100]=C_h_intern(&lf[100],21, C_text("##sys#undefined-value"));
lf[101]=C_h_intern(&lf[101],13, C_text("##sys#provide"));
lf[102]=C_h_intern(&lf[102],35, C_text("chicken.internal#module-requirement"));
lf[103]=C_h_intern(&lf[103],21, C_text("##sys#finalize-module"));
lf[104]=C_h_intern(&lf[104],14, C_text("scheme#reverse"));
lf[105]=C_h_intern(&lf[105],27, C_text("##sys#with-property-restore"));
lf[106]=C_h_intern(&lf[106],21, C_text("##sys#register-module"));
lf[107]=C_h_intern(&lf[107],6, C_text("module"));
lf[108]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031modules may not be nested"));
lf[109]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025invalid export syntax"));
lf[110]=C_h_intern(&lf[110],18, C_text("##core#loop-lambda"));
lf[111]=C_h_intern(&lf[111],14, C_text("##core#provide"));
lf[112]=C_h_intern(&lf[112],25, C_text("##core#require-for-syntax"));
lf[113]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[114]=C_h_intern(&lf[114],27, C_text("chicken.load#load-extension"));
lf[115]=C_h_intern(&lf[115],14, C_text("##core#require"));
lf[116]=C_h_intern(&lf[116],21, C_text("##sys#process-require"));
lf[117]=C_h_intern(&lf[117],26, C_text("##core#elaborationtimeonly"));
lf[118]=C_h_intern(&lf[118],25, C_text("##core#elaborationtimetoo"));
lf[119]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[120]=C_h_intern(&lf[120],21, C_text("##core#compiletimetoo"));
lf[121]=C_h_intern(&lf[121],22, C_text("##core#compiletimeonly"));
lf[122]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[123]=C_h_intern(&lf[123],14, C_text("##core#declare"));
lf[124]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[125]=C_decode_literal(C_heaptop,C_text("\376B\000\000,declarations are ignored in interpreted code"));
lf[126]=C_h_intern(&lf[126],20, C_text("##core#define-inline"));
lf[127]=C_h_intern(&lf[127],22, C_text("##core#define-constant"));
lf[128]=C_h_intern(&lf[128],6, C_text("define"));
lf[129]=C_h_intern(&lf[129],16, C_text("##core#primitive"));
lf[130]=C_decode_literal(C_heaptop,C_text("\376B\000\000%cannot evaluate compiler-special-form"));
lf[131]=C_h_intern(&lf[131],10, C_text("##core#app"));
lf[132]=C_h_intern(&lf[132],10, C_text("##core#the"));
lf[133]=C_h_intern(&lf[133],15, C_text("##core#typecase"));
lf[134]=C_h_intern(&lf[134],4, C_text("else"));
lf[135]=C_h_intern(&lf[135],17, C_text("compiler-typecase"));
lf[136]=C_decode_literal(C_heaptop,C_text("\376B\000\0007no `else-clause\047 in unresolved `compiler-typecase\047 form"));
lf[137]=C_h_intern(&lf[137],20, C_text("##sys#syntax-context"));
lf[138]=C_h_intern(&lf[138],13, C_text("##core#inline"));
lf[139]=C_h_intern(&lf[139],22, C_text("##core#inline_allocate"));
lf[140]=C_h_intern(&lf[140],21, C_text("##core#foreign-lambda"));
lf[141]=C_h_intern(&lf[141],30, C_text("##core#define-foreign-variable"));
lf[142]=C_h_intern(&lf[142],31, C_text("##core#define-external-variable"));
lf[143]=C_h_intern(&lf[143],19, C_text("##core#let-location"));
lf[144]=C_h_intern(&lf[144],24, C_text("##core#foreign-primitive"));
lf[145]=C_h_intern(&lf[145],15, C_text("##core#location"));
lf[146]=C_h_intern(&lf[146],22, C_text("##core#foreign-lambda\052"));
lf[147]=C_h_intern(&lf[147],26, C_text("##core#define-foreign-type"));
lf[148]=C_h_intern(&lf[148],15, C_text("##core#callunit"));
lf[149]=C_h_intern(&lf[149],27, C_text("##core#local-specialization"));
lf[150]=C_h_intern(&lf[150],36, C_text("chicken.syntax#expansion-result-hook"));
lf[151]=C_h_intern(&lf[151],21, C_text("chicken.syntax#expand"));
lf[152]=C_h_intern(&lf[152],20, C_text("##sys#srfi-4-vector\077"));
lf[153]=C_h_intern(&lf[153],18, C_text("chicken.blob#blob\077"));
lf[154]=C_h_intern(&lf[154],13, C_text("##sys#number\077"));
lf[155]=C_h_intern(&lf[155],24, C_text("chicken.keyword#keyword\077"));
lf[156]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006<eval>"));
lf[157]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024malformed expression"));
lf[158]=C_h_intern(&lf[158],28, C_text("##sys#meta-macro-environment"));
lf[159]=C_h_intern(&lf[159],30, C_text("##sys#current-meta-environment"));
lf[160]=C_h_intern(&lf[160],19, C_text("scheme#dynamic-wind"));
lf[161]=C_h_intern(&lf[161],17, C_text("chicken.base#void"));
lf[162]=C_h_intern(&lf[162],25, C_text("chicken.eval#eval-handler"));
lf[163]=C_h_intern(&lf[163],11, C_text("scheme#eval"));
lf[164]=C_h_intern(&lf[164],31, C_text("chicken.eval#module-environment"));
lf[165]=C_h_intern(&lf[165],33, C_text("chicken.module#module-environment"));
lf[166]=C_h_intern(&lf[166],26, C_text("##sys#syntax-error-culprit"));
lf[167]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032illegal lambda-list syntax"));
lf[168]=C_h_intern(&lf[168],11, C_text("environment"));
lf[169]=C_h_intern(&lf[169],23, C_text("interaction-environment"));
lf[170]=C_h_intern(&lf[170],30, C_text("scheme#interaction-environment"));
lf[171]=C_h_intern(&lf[171],5, C_text("foldr"));
lf[172]=C_h_intern(&lf[172],11, C_text("cond-expand"));
lf[173]=C_h_intern(&lf[173],16, C_text("define-interface"));
lf[174]=C_h_intern(&lf[174],11, C_text("delay-force"));
lf[175]=C_h_intern(&lf[175],6, C_text("export"));
lf[176]=C_h_intern(&lf[176],13, C_text("export/rename"));
lf[177]=C_h_intern(&lf[177],6, C_text("import"));
lf[178]=C_h_intern(&lf[178],17, C_text("import-for-syntax"));
lf[179]=C_h_intern(&lf[179],13, C_text("import-syntax"));
lf[180]=C_h_intern(&lf[180],24, C_text("import-syntax-for-syntax"));
lf[181]=C_h_intern(&lf[181],7, C_text("letrec\052"));
lf[182]=C_h_intern(&lf[182],8, C_text("reexport"));
lf[183]=C_h_intern(&lf[183],15, C_text("require-library"));
lf[184]=C_h_intern(&lf[184],32, C_text("scheme#scheme-report-environment"));
lf[185]=C_h_intern(&lf[185],25, C_text("scheme-report-environment"));
lf[186]=C_decode_literal(C_heaptop,C_text("\376B\000\000-unsupported scheme report environment version"));
lf[187]=C_h_intern(&lf[187],18, C_text("##sys#check-fixnum"));
lf[188]=C_h_intern(&lf[188],23, C_text("scheme#null-environment"));
lf[189]=C_h_intern(&lf[189],16, C_text("null-environment"));
lf[190]=C_decode_literal(C_heaptop,C_text("\376B\000\000$unsupported null environment version"));
lf[191]=C_h_intern(&lf[191],13, C_text("chicken.load#"));
lf[193]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001chicken.foreign\376\003\000\000\002\376\001\000\000\031\001##core#require-for-syntax\376\003\000\000\002\376\001\000\000\022\001ch"
"icken-ffi-syntax\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001chicken.condition\376\003\000\000\002\376\001\000\000\014\001##core#begin\376\003\000\000\002"
"\376\003\000\000\002\376\001\000\000\031\001##core#require-for-syntax\376\003\000\000\002\376\001\000\000\016\001chicken-syntax\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001"
"##core#require\376\003\000\000\002\376\001\000\000\007\001library\376\377\016\376\377\016\376\377\016"));
lf[195]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\016\001chicken-syntax\376\003\000\000\002\376\001\000\000\022\001chicken-ffi-syntax\376\003\000\000\002\376\001\000\000\014\001continuation\376\003\000"
"\000\002\376\001\000\000\017\001data-structures\376\003\000\000\002\376\001\000\000\017\001debugger-client\376\003\000\000\002\376\001\000\000\004\001eval\376\003\000\000\002\376\001\000\000\014\001eval-"
"modules\376\003\000\000\002\376\001\000\000\006\001expand\376\003\000\000\002\376\001\000\000\006\001extras\376\003\000\000\002\376\001\000\000\004\001file\376\003\000\000\002\376\001\000\000\010\001internal\376\003\000\000\002"
"\376\001\000\000\007\001irregex\376\003\000\000\002\376\001\000\000\007\001library\376\003\000\000\002\376\001\000\000\007\001lolevel\376\003\000\000\002\376\001\000\000\010\001pathname\376\003\000\000\002\376\001\000\000\004\001p"
"ort\376\003\000\000\002\376\001\000\000\005\001posix\376\003\000\000\002\376\001\000\000\010\001profiler\376\003\000\000\002\376\001\000\000\013\001read-syntax\376\003\000\000\002\376\001\000\000\004\001repl\376\003\000\000\002"
"\376\001\000\000\011\001scheduler\376\003\000\000\002\376\001\000\000\006\001srfi-4\376\003\000\000\002\376\001\000\000\003\001tcp\376\377\016"));
lf[197]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003.so"));
lf[199]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004.scm"));
lf[201]=C_h_intern(&lf[201],28, C_text("##sys#load-dynamic-extension"));
lf[202]=C_h_intern(&lf[202],26, C_text("chicken.load#core-library\077"));
lf[204]=C_h_intern(&lf[204],15, C_text("##sys#provided\077"));
lf[205]=C_h_intern(&lf[205],22, C_text("##sys#windows-platform"));
lf[206]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\012\000\000\134\376\003\000\000\002\376\377\012\000\000/\376\377\016"));
lf[207]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\012\000\000/\376\377\016"));
lf[211]=C_h_intern(&lf[211],20, C_text("scheme#string-append"));
lf[212]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[213]=C_h_intern(&lf[213],15, C_text("##sys#substring"));
lf[214]=C_h_intern(&lf[214],25, C_text("chicken.load#load-verbose"));
lf[215]=C_h_intern(&lf[215],27, C_text("##sys#current-load-filename"));
lf[216]=C_h_intern(&lf[216],20, C_text("##sys#dload-disabled"));
lf[217]=C_h_intern(&lf[217],35, C_text("chicken.load#set-dynamic-load-mode!"));
lf[218]=C_h_intern(&lf[218],23, C_text("##sys#set-dlopen-flags!"));
lf[219]=C_h_intern(&lf[219],6, C_text("global"));
lf[220]=C_h_intern(&lf[220],5, C_text("local"));
lf[221]=C_h_intern(&lf[221],4, C_text("lazy"));
lf[222]=C_h_intern(&lf[222],3, C_text("now"));
lf[223]=C_h_intern(&lf[223],17, C_text("##sys#signal-hook"));
lf[224]=C_h_intern(&lf[224],22, C_text("set-dynamic-load-mode!"));
lf[225]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031invalid dynamic-load mode"));
lf[227]=C_h_intern(&lf[227],19, C_text("##sys#make-c-string"));
lf[228]=C_h_intern(&lf[228],19, C_text("##sys#string-append"));
lf[229]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002C_"));
lf[230]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010toplevel"));
lf[231]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011_toplevel"));
lf[232]=C_h_intern(&lf[232],37, C_text("chicken.internal#string->c-identifier"));
lf[234]=C_h_intern(&lf[234],11, C_text("##sys#dload"));
lf[235]=C_h_intern(&lf[235],4, C_text("load"));
lf[236]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002./"));
lf[237]=C_h_intern(&lf[237],33, C_text("##sys#read-error-with-line-number"));
lf[238]=C_h_intern(&lf[238],36, C_text("chicken.syntax#read-with-source-info"));
lf[239]=C_h_intern(&lf[239],19, C_text("##sys#display-times"));
lf[240]=C_h_intern(&lf[240],16, C_text("##sys#stop-timer"));
lf[241]=C_h_intern(&lf[241],17, C_text("##sys#start-timer"));
lf[242]=C_h_intern(&lf[242],14, C_text("scheme#newline"));
lf[243]=C_decode_literal(C_heaptop,C_text("\376B\000\000!unable to load compiled module - "));
lf[244]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016unknown reason"));
lf[245]=C_h_intern(&lf[245],19, C_text("##sys#peek-c-string"));
lf[246]=C_h_intern(&lf[246],16, C_text("scheme#peek-char"));
lf[247]=C_h_intern(&lf[247],23, C_text("scheme#close-input-port"));
lf[248]=C_h_intern(&lf[248],22, C_text("scheme#open-input-file"));
lf[249]=C_h_intern(&lf[249],25, C_text("chicken.base#flush-output"));
lf[250]=C_h_intern(&lf[250],14, C_text("scheme#display"));
lf[251]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005 ...\012"));
lf[252]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012; loading "));
lf[253]=C_h_intern_kw(&lf[253],10, C_text("type-error"));
lf[254]=C_decode_literal(C_heaptop,C_text("\376B\000\000(bad argument type - not a port or string"));
lf[255]=C_h_intern_kw(&lf[255],10, C_text("file-error"));
lf[256]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020cannot open file"));
lf[257]=C_h_intern(&lf[257],18, C_text("##sys#file-exists\077"));
lf[258]=C_h_intern(&lf[258],18, C_text("chicken.base#port\077"));
lf[259]=C_h_intern(&lf[259],25, C_text("chicken.platform#feature\077"));
lf[260]=C_h_intern_kw(&lf[260],5, C_text("dload"));
lf[261]=C_h_intern(&lf[261],11, C_text("scheme#load"));
lf[262]=C_h_intern(&lf[262],26, C_text("chicken.load#load-relative"));
lf[263]=C_h_intern(&lf[263],25, C_text("chicken.load#load-noisily"));
lf[264]=C_h_intern(&lf[264],17, C_text("##sys#get-keyword"));
lf[265]=C_h_intern_kw(&lf[265],7, C_text("printer"));
lf[266]=C_h_intern_kw(&lf[266],4, C_text("time"));
lf[267]=C_h_intern_kw(&lf[267],9, C_text("evaluator"));
lf[268]=C_h_intern(&lf[268],35, C_text("chicken.load#dynamic-load-libraries"));
lf[269]=C_h_intern(&lf[269],22, C_text("chicken.load#load-unit"));
lf[270]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026unable to load library"));
lf[271]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021library not found"));
lf[272]=C_h_intern(&lf[272],12, C_text("load-library"));
lf[273]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005 ...\012"));
lf[274]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022; loading library "));
lf[275]=C_h_intern(&lf[275],25, C_text("chicken.load#load-library"));
lf[276]=C_h_intern(&lf[276],27, C_text("scheme#call-with-input-file"));
lf[277]=C_h_intern(&lf[277],18, C_text("chicken.base#print"));
lf[278]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014; including "));
lf[279]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004 ..."));
lf[280]=C_h_intern(&lf[280],7, C_text("include"));
lf[281]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020cannot open file"));
lf[282]=C_h_intern(&lf[282],30, C_text("##sys#resolve-include-filename"));
lf[283]=C_h_intern(&lf[283],16, C_text("##sys#setup-mode"));
lf[285]=C_h_intern(&lf[285],22, C_text("chicken.load#find-file"));
lf[286]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[287]=C_h_intern(&lf[287],35, C_text("chicken.load#find-dynamic-extension"));
lf[288]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[289]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\001.\376\377\016"));
lf[290]=C_h_intern(&lf[290],23, C_text("##sys#include-pathnames"));
lf[291]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\001.\376\377\016"));
lf[292]=C_h_intern(&lf[292],21, C_text("scheme#symbol->string"));
lf[293]=C_h_intern(&lf[293],32, C_text("chicken.platform#repository-path"));
lf[294]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025cannot load extension"));
lf[295]=C_h_intern(&lf[295],20, C_text("chicken.load#require"));
lf[296]=C_h_intern(&lf[296],7, C_text("require"));
lf[297]=C_h_intern(&lf[297],20, C_text("chicken.load#provide"));
lf[298]=C_h_intern(&lf[298],7, C_text("provide"));
lf[299]=C_h_intern(&lf[299],22, C_text("chicken.load#provided\077"));
lf[300]=C_h_intern(&lf[300],9, C_text("provided\077"));
lf[301]=C_h_intern(&lf[301],6, C_text("static"));
lf[302]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[305]=C_h_intern(&lf[305],37, C_text("chicken.condition#print-error-message"));
lf[306]=C_h_intern(&lf[306],40, C_text("chicken.condition#with-exception-handler"));
lf[307]=C_h_intern(&lf[307],37, C_text("scheme#call-with-current-continuation"));
lf[309]=C_h_intern(&lf[309],8, C_text("##sys#gc"));
lf[311]=C_h_intern(&lf[311],19, C_text("##sys#thread-yield!"));
lf[314]=C_h_intern(&lf[314],11, C_text("scheme#read"));
lf[315]=C_h_intern(&lf[315],30, C_text("chicken.base#open-input-string"));
lf[317]=C_decode_literal(C_heaptop,C_text("\376B\000\000(Error: not enough room for result string"));
lf[325]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010No error"));
lf[326]=C_h_intern(&lf[326],27, C_text("chicken.base#make-parameter"));
lf[327]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[328]=C_h_intern(&lf[328],20, C_text("##sys#fixnum->string"));
lf[329]=C_h_intern(&lf[329],6, C_text("cygwin"));
lf[330]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\014cygchicken-0\376\377\016"));
lf[331]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003lib"));
lf[332]=C_h_intern(&lf[332],33, C_text("chicken.platform#software-version"));
lf[333]=C_h_intern(&lf[333],7, C_text("windows"));
lf[334]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004.dll"));
lf[335]=C_h_intern(&lf[335],6, C_text("macosx"));
lf[336]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006.dylib"));
lf[337]=C_h_intern(&lf[337],4, C_text("hpux"));
lf[338]=C_h_intern(&lf[338],4, C_text("hppa"));
lf[339]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003.sl"));
lf[340]=C_h_intern(&lf[340],29, C_text("chicken.platform#machine-type"));
lf[341]=C_h_intern(&lf[341],30, C_text("chicken.platform#software-type"));
lf[342]=C_h_intern(&lf[342],9, C_text("r5rs-null"));
lf[343]=C_h_intern(&lf[343],18, C_text("null-environment/5"));
lf[344]=C_h_intern(&lf[344],9, C_text("r4rs-null"));
lf[345]=C_h_intern(&lf[345],18, C_text("null-environment/4"));
lf[346]=C_h_intern(&lf[346],6, C_text("scheme"));
lf[347]=C_h_intern(&lf[347],27, C_text("scheme-report-environment/5"));
lf[348]=C_h_intern(&lf[348],4, C_text("r4rs"));
lf[349]=C_h_intern(&lf[349],27, C_text("scheme-report-environment/4"));
lf[350]=C_h_intern(&lf[350],18, C_text("##sys#write-char-0"));
lf[351]=C_h_intern(&lf[351],11, C_text("##sys#print"));
lf[352]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016#<environment "));
lf[353]=C_h_intern(&lf[353],32, C_text("chicken.base#set-record-printer!"));
lf[354]=C_h_intern(&lf[354],10, C_text("##sys#put!"));
lf[355]=C_h_intern(&lf[355],39, C_text("chicken.internal#default-syntax-imports"));
lf[356]=C_h_intern(&lf[356],32, C_text("chicken.internal#default-imports"));
C_register_lf2(lf,357,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3521,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_modules_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[738] = {
{C_text("f_10001:eval_2escm"),(void*)f_10001},
{C_text("f_10004:eval_2escm"),(void*)f_10004},
{C_text("f_10019:eval_2escm"),(void*)f_10019},
{C_text("f_10022:eval_2escm"),(void*)f_10022},
{C_text("f_10025:eval_2escm"),(void*)f_10025},
{C_text("f_10031:eval_2escm"),(void*)f_10031},
{C_text("f_10043:eval_2escm"),(void*)f_10043},
{C_text("f_10049:eval_2escm"),(void*)f_10049},
{C_text("f_10109:eval_2escm"),(void*)f_10109},
{C_text("f_10124:eval_2escm"),(void*)f_10124},
{C_text("f_10131:eval_2escm"),(void*)f_10131},
{C_text("f_10142:eval_2escm"),(void*)f_10142},
{C_text("f_10146:eval_2escm"),(void*)f_10146},
{C_text("f_10149:eval_2escm"),(void*)f_10149},
{C_text("f_10152:eval_2escm"),(void*)f_10152},
{C_text("f_10157:eval_2escm"),(void*)f_10157},
{C_text("f_10160:eval_2escm"),(void*)f_10160},
{C_text("f_10163:eval_2escm"),(void*)f_10163},
{C_text("f_10168:eval_2escm"),(void*)f_10168},
{C_text("f_10170:eval_2escm"),(void*)f_10170},
{C_text("f_10177:eval_2escm"),(void*)f_10177},
{C_text("f_10179:eval_2escm"),(void*)f_10179},
{C_text("f_10186:eval_2escm"),(void*)f_10186},
{C_text("f_10189:eval_2escm"),(void*)f_10189},
{C_text("f_10192:eval_2escm"),(void*)f_10192},
{C_text("f_10195:eval_2escm"),(void*)f_10195},
{C_text("f_10200:eval_2escm"),(void*)f_10200},
{C_text("f_10214:eval_2escm"),(void*)f_10214},
{C_text("f_10223:eval_2escm"),(void*)f_10223},
{C_text("f_10234:eval_2escm"),(void*)f_10234},
{C_text("f_10241:eval_2escm"),(void*)f_10241},
{C_text("f_10244:eval_2escm"),(void*)f_10244},
{C_text("f_10247:eval_2escm"),(void*)f_10247},
{C_text("f_10260:eval_2escm"),(void*)f_10260},
{C_text("f_10264:eval_2escm"),(void*)f_10264},
{C_text("f_10270:eval_2escm"),(void*)f_10270},
{C_text("f_10297:eval_2escm"),(void*)f_10297},
{C_text("f_10301:eval_2escm"),(void*)f_10301},
{C_text("f_10304:eval_2escm"),(void*)f_10304},
{C_text("f_10307:eval_2escm"),(void*)f_10307},
{C_text("f_10312:eval_2escm"),(void*)f_10312},
{C_text("f_10320:eval_2escm"),(void*)f_10320},
{C_text("f_10322:eval_2escm"),(void*)f_10322},
{C_text("f_10327:eval_2escm"),(void*)f_10327},
{C_text("f_10335:eval_2escm"),(void*)f_10335},
{C_text("f_10337:eval_2escm"),(void*)f_10337},
{C_text("f_10354:eval_2escm"),(void*)f_10354},
{C_text("f_10360:eval_2escm"),(void*)f_10360},
{C_text("f_10366:eval_2escm"),(void*)f_10366},
{C_text("f_10378:eval_2escm"),(void*)f_10378},
{C_text("f_10385:eval_2escm"),(void*)f_10385},
{C_text("f_10387:eval_2escm"),(void*)f_10387},
{C_text("f_10416:eval_2escm"),(void*)f_10416},
{C_text("f_10428:eval_2escm"),(void*)f_10428},
{C_text("f_10434:eval_2escm"),(void*)f_10434},
{C_text("f_10438:eval_2escm"),(void*)f_10438},
{C_text("f_10441:eval_2escm"),(void*)f_10441},
{C_text("f_10443:eval_2escm"),(void*)f_10443},
{C_text("f_10447:eval_2escm"),(void*)f_10447},
{C_text("f_10450:eval_2escm"),(void*)f_10450},
{C_text("f_10460:eval_2escm"),(void*)f_10460},
{C_text("f_10472:eval_2escm"),(void*)f_10472},
{C_text("f_10479:eval_2escm"),(void*)f_10479},
{C_text("f_10486:eval_2escm"),(void*)f_10486},
{C_text("f_10488:eval_2escm"),(void*)f_10488},
{C_text("f_10501:eval_2escm"),(void*)f_10501},
{C_text("f_10535:eval_2escm"),(void*)f_10535},
{C_text("f_10544:eval_2escm"),(void*)f_10544},
{C_text("f_10560:eval_2escm"),(void*)f_10560},
{C_text("f_10573:eval_2escm"),(void*)f_10573},
{C_text("f_10576:eval_2escm"),(void*)f_10576},
{C_text("f_10588:eval_2escm"),(void*)f_10588},
{C_text("f_10592:eval_2escm"),(void*)f_10592},
{C_text("f_10596:eval_2escm"),(void*)f_10596},
{C_text("f_10599:eval_2escm"),(void*)f_10599},
{C_text("f_10607:eval_2escm"),(void*)f_10607},
{C_text("f_10626:eval_2escm"),(void*)f_10626},
{C_text("f_10636:eval_2escm"),(void*)f_10636},
{C_text("f_10649:eval_2escm"),(void*)f_10649},
{C_text("f_10672:eval_2escm"),(void*)f_10672},
{C_text("f_10691:eval_2escm"),(void*)f_10691},
{C_text("f_10701:eval_2escm"),(void*)f_10701},
{C_text("f_10714:eval_2escm"),(void*)f_10714},
{C_text("f_10737:eval_2escm"),(void*)f_10737},
{C_text("f_10751:eval_2escm"),(void*)f_10751},
{C_text("f_10778:eval_2escm"),(void*)f_10778},
{C_text("f_10847:eval_2escm"),(void*)f_10847},
{C_text("f_10850:eval_2escm"),(void*)f_10850},
{C_text("f_10863:eval_2escm"),(void*)f_10863},
{C_text("f_10866:eval_2escm"),(void*)f_10866},
{C_text("f_10869:eval_2escm"),(void*)f_10869},
{C_text("f_10883:eval_2escm"),(void*)f_10883},
{C_text("f_10919:eval_2escm"),(void*)f_10919},
{C_text("f_10922:eval_2escm"),(void*)f_10922},
{C_text("f_10932:eval_2escm"),(void*)f_10932},
{C_text("f_10934:eval_2escm"),(void*)f_10934},
{C_text("f_10944:eval_2escm"),(void*)f_10944},
{C_text("f_10958:eval_2escm"),(void*)f_10958},
{C_text("f_10969:eval_2escm"),(void*)f_10969},
{C_text("f_10976:eval_2escm"),(void*)f_10976},
{C_text("f_10979:eval_2escm"),(void*)f_10979},
{C_text("f_10984:eval_2escm"),(void*)f_10984},
{C_text("f_10989:eval_2escm"),(void*)f_10989},
{C_text("f_10995:eval_2escm"),(void*)f_10995},
{C_text("f_11001:eval_2escm"),(void*)f_11001},
{C_text("f_11005:eval_2escm"),(void*)f_11005},
{C_text("f_11008:eval_2escm"),(void*)f_11008},
{C_text("f_11012:eval_2escm"),(void*)f_11012},
{C_text("f_11014:eval_2escm"),(void*)f_11014},
{C_text("f_11020:eval_2escm"),(void*)f_11020},
{C_text("f_11026:eval_2escm"),(void*)f_11026},
{C_text("f_11032:eval_2escm"),(void*)f_11032},
{C_text("f_11038:eval_2escm"),(void*)f_11038},
{C_text("f_11042:eval_2escm"),(void*)f_11042},
{C_text("f_11047:eval_2escm"),(void*)f_11047},
{C_text("f_11053:eval_2escm"),(void*)f_11053},
{C_text("f_11057:eval_2escm"),(void*)f_11057},
{C_text("f_11059:eval_2escm"),(void*)f_11059},
{C_text("f_11065:eval_2escm"),(void*)f_11065},
{C_text("f_11073:eval_2escm"),(void*)f_11073},
{C_text("f_11075:eval_2escm"),(void*)f_11075},
{C_text("f_11079:eval_2escm"),(void*)f_11079},
{C_text("f_11084:eval_2escm"),(void*)f_11084},
{C_text("f_11088:eval_2escm"),(void*)f_11088},
{C_text("f_11095:eval_2escm"),(void*)f_11095},
{C_text("f_11099:eval_2escm"),(void*)f_11099},
{C_text("f_11101:eval_2escm"),(void*)f_11101},
{C_text("f_11114:eval_2escm"),(void*)f_11114},
{C_text("f_11120:eval_2escm"),(void*)f_11120},
{C_text("f_11124:eval_2escm"),(void*)f_11124},
{C_text("f_11127:eval_2escm"),(void*)f_11127},
{C_text("f_11134:eval_2escm"),(void*)f_11134},
{C_text("f_11138:eval_2escm"),(void*)f_11138},
{C_text("f_11140:eval_2escm"),(void*)f_11140},
{C_text("f_11144:eval_2escm"),(void*)f_11144},
{C_text("f_11149:eval_2escm"),(void*)f_11149},
{C_text("f_11153:eval_2escm"),(void*)f_11153},
{C_text("f_11156:eval_2escm"),(void*)f_11156},
{C_text("f_11163:eval_2escm"),(void*)f_11163},
{C_text("f_11167:eval_2escm"),(void*)f_11167},
{C_text("f_11171:eval_2escm"),(void*)f_11171},
{C_text("f_11175:eval_2escm"),(void*)f_11175},
{C_text("f_11177:eval_2escm"),(void*)f_11177},
{C_text("f_11183:eval_2escm"),(void*)f_11183},
{C_text("f_11191:eval_2escm"),(void*)f_11191},
{C_text("f_11193:eval_2escm"),(void*)f_11193},
{C_text("f_11199:eval_2escm"),(void*)f_11199},
{C_text("f_11203:eval_2escm"),(void*)f_11203},
{C_text("f_11206:eval_2escm"),(void*)f_11206},
{C_text("f_11213:eval_2escm"),(void*)f_11213},
{C_text("f_11217:eval_2escm"),(void*)f_11217},
{C_text("f_11219:eval_2escm"),(void*)f_11219},
{C_text("f_11223:eval_2escm"),(void*)f_11223},
{C_text("f_11228:eval_2escm"),(void*)f_11228},
{C_text("f_11232:eval_2escm"),(void*)f_11232},
{C_text("f_11239:eval_2escm"),(void*)f_11239},
{C_text("f_11241:eval_2escm"),(void*)f_11241},
{C_text("f_11245:eval_2escm"),(void*)f_11245},
{C_text("f_11250:eval_2escm"),(void*)f_11250},
{C_text("f_11254:eval_2escm"),(void*)f_11254},
{C_text("f_11256:eval_2escm"),(void*)f_11256},
{C_text("f_11271:eval_2escm"),(void*)f_11271},
{C_text("f_11273:eval_2escm"),(void*)f_11273},
{C_text("f_11279:eval_2escm"),(void*)f_11279},
{C_text("f_11304:eval_2escm"),(void*)f_11304},
{C_text("f_11318:eval_2escm"),(void*)f_11318},
{C_text("f_11330:eval_2escm"),(void*)f_11330},
{C_text("f_11334:eval_2escm"),(void*)f_11334},
{C_text("f_11361:eval_2escm"),(void*)f_11361},
{C_text("f_11365:eval_2escm"),(void*)f_11365},
{C_text("f_11369:eval_2escm"),(void*)f_11369},
{C_text("f_11373:eval_2escm"),(void*)f_11373},
{C_text("f_11377:eval_2escm"),(void*)f_11377},
{C_text("f_11385:eval_2escm"),(void*)f_11385},
{C_text("f_11393:eval_2escm"),(void*)f_11393},
{C_text("f_11401:eval_2escm"),(void*)f_11401},
{C_text("f_11407:eval_2escm"),(void*)f_11407},
{C_text("f_11411:eval_2escm"),(void*)f_11411},
{C_text("f_11414:eval_2escm"),(void*)f_11414},
{C_text("f_11423:eval_2escm"),(void*)f_11423},
{C_text("f_11429:eval_2escm"),(void*)f_11429},
{C_text("f_11433:eval_2escm"),(void*)f_11433},
{C_text("f_11436:eval_2escm"),(void*)f_11436},
{C_text("f_11448:eval_2escm"),(void*)f_11448},
{C_text("f_11450:eval_2escm"),(void*)f_11450},
{C_text("f_11456:eval_2escm"),(void*)f_11456},
{C_text("f_11461:eval_2escm"),(void*)f_11461},
{C_text("f_11465:eval_2escm"),(void*)f_11465},
{C_text("f_11468:eval_2escm"),(void*)f_11468},
{C_text("f_11478:eval_2escm"),(void*)f_11478},
{C_text("f_11491:eval_2escm"),(void*)f_11491},
{C_text("f_11496:eval_2escm"),(void*)f_11496},
{C_text("f_11503:eval_2escm"),(void*)f_11503},
{C_text("f_11506:eval_2escm"),(void*)f_11506},
{C_text("f_11518:eval_2escm"),(void*)f_11518},
{C_text("f_11526:eval_2escm"),(void*)f_11526},
{C_text("f_11530:eval_2escm"),(void*)f_11530},
{C_text("f_11533:eval_2escm"),(void*)f_11533},
{C_text("f_11537:eval_2escm"),(void*)f_11537},
{C_text("f_11541:eval_2escm"),(void*)f_11541},
{C_text("f_11544:eval_2escm"),(void*)f_11544},
{C_text("f_11547:eval_2escm"),(void*)f_11547},
{C_text("f_11556:eval_2escm"),(void*)f_11556},
{C_text("f_11566:eval_2escm"),(void*)f_11566},
{C_text("f_11570:eval_2escm"),(void*)f_11570},
{C_text("f_11573:eval_2escm"),(void*)f_11573},
{C_text("f_11576:eval_2escm"),(void*)f_11576},
{C_text("f_11579:eval_2escm"),(void*)f_11579},
{C_text("f_11587:eval_2escm"),(void*)f_11587},
{C_text("f_11596:eval_2escm"),(void*)f_11596},
{C_text("f_3521:eval_2escm"),(void*)f_3521},
{C_text("f_3524:eval_2escm"),(void*)f_3524},
{C_text("f_3527:eval_2escm"),(void*)f_3527},
{C_text("f_3530:eval_2escm"),(void*)f_3530},
{C_text("f_3538:eval_2escm"),(void*)f_3538},
{C_text("f_3551:eval_2escm"),(void*)f_3551},
{C_text("f_3559:eval_2escm"),(void*)f_3559},
{C_text("f_3563:eval_2escm"),(void*)f_3563},
{C_text("f_3566:eval_2escm"),(void*)f_3566},
{C_text("f_3569:eval_2escm"),(void*)f_3569},
{C_text("f_3574:eval_2escm"),(void*)f_3574},
{C_text("f_3576:eval_2escm"),(void*)f_3576},
{C_text("f_3603:eval_2escm"),(void*)f_3603},
{C_text("f_3616:eval_2escm"),(void*)f_3616},
{C_text("f_3638:eval_2escm"),(void*)f_3638},
{C_text("f_3642:eval_2escm"),(void*)f_3642},
{C_text("f_3650:eval_2escm"),(void*)f_3650},
{C_text("f_3656:eval_2escm"),(void*)f_3656},
{C_text("f_3663:eval_2escm"),(void*)f_3663},
{C_text("f_3670:eval_2escm"),(void*)f_3670},
{C_text("f_3672:eval_2escm"),(void*)f_3672},
{C_text("f_3676:eval_2escm"),(void*)f_3676},
{C_text("f_3684:eval_2escm"),(void*)f_3684},
{C_text("f_3701:eval_2escm"),(void*)f_3701},
{C_text("f_3731:eval_2escm"),(void*)f_3731},
{C_text("f_3761:eval_2escm"),(void*)f_3761},
{C_text("f_3775:eval_2escm"),(void*)f_3775},
{C_text("f_3783:eval_2escm"),(void*)f_3783},
{C_text("f_3792:eval_2escm"),(void*)f_3792},
{C_text("f_3800:eval_2escm"),(void*)f_3800},
{C_text("f_3807:eval_2escm"),(void*)f_3807},
{C_text("f_3810:eval_2escm"),(void*)f_3810},
{C_text("f_3825:eval_2escm"),(void*)f_3825},
{C_text("f_3832:eval_2escm"),(void*)f_3832},
{C_text("f_3833:eval_2escm"),(void*)f_3833},
{C_text("f_3845:eval_2escm"),(void*)f_3845},
{C_text("f_3851:eval_2escm"),(void*)f_3851},
{C_text("f_3861:eval_2escm"),(void*)f_3861},
{C_text("f_3864:eval_2escm"),(void*)f_3864},
{C_text("f_3871:eval_2escm"),(void*)f_3871},
{C_text("f_3881:eval_2escm"),(void*)f_3881},
{C_text("f_3882:eval_2escm"),(void*)f_3882},
{C_text("f_3887:eval_2escm"),(void*)f_3887},
{C_text("f_3891:eval_2escm"),(void*)f_3891},
{C_text("f_3912:eval_2escm"),(void*)f_3912},
{C_text("f_3944:eval_2escm"),(void*)f_3944},
{C_text("f_3955:eval_2escm"),(void*)f_3955},
{C_text("f_3970:eval_2escm"),(void*)f_3970},
{C_text("f_3989:eval_2escm"),(void*)f_3989},
{C_text("f_4012:eval_2escm"),(void*)f_4012},
{C_text("f_4033:eval_2escm"),(void*)f_4033},
{C_text("f_4052:eval_2escm"),(void*)f_4052},
{C_text("f_4059:eval_2escm"),(void*)f_4059},
{C_text("f_4067:eval_2escm"),(void*)f_4067},
{C_text("f_4075:eval_2escm"),(void*)f_4075},
{C_text("f_4083:eval_2escm"),(void*)f_4083},
{C_text("f_4085:eval_2escm"),(void*)f_4085},
{C_text("f_4104:eval_2escm"),(void*)f_4104},
{C_text("f_4106:eval_2escm"),(void*)f_4106},
{C_text("f_4116:eval_2escm"),(void*)f_4116},
{C_text("f_4117:eval_2escm"),(void*)f_4117},
{C_text("f_4136:eval_2escm"),(void*)f_4136},
{C_text("f_4139:eval_2escm"),(void*)f_4139},
{C_text("f_4145:eval_2escm"),(void*)f_4145},
{C_text("f_4160:eval_2escm"),(void*)f_4160},
{C_text("f_4169:eval_2escm"),(void*)f_4169},
{C_text("f_4176:eval_2escm"),(void*)f_4176},
{C_text("f_4184:eval_2escm"),(void*)f_4184},
{C_text("f_4192:eval_2escm"),(void*)f_4192},
{C_text("f_4200:eval_2escm"),(void*)f_4200},
{C_text("f_4208:eval_2escm"),(void*)f_4208},
{C_text("f_4216:eval_2escm"),(void*)f_4216},
{C_text("f_4224:eval_2escm"),(void*)f_4224},
{C_text("f_4226:eval_2escm"),(void*)f_4226},
{C_text("f_4255:eval_2escm"),(void*)f_4255},
{C_text("f_4289:eval_2escm"),(void*)f_4289},
{C_text("f_4299:eval_2escm"),(void*)f_4299},
{C_text("f_4302:eval_2escm"),(void*)f_4302},
{C_text("f_4305:eval_2escm"),(void*)f_4305},
{C_text("f_4306:eval_2escm"),(void*)f_4306},
{C_text("f_4313:eval_2escm"),(void*)f_4313},
{C_text("f_4387:eval_2escm"),(void*)f_4387},
{C_text("f_4390:eval_2escm"),(void*)f_4390},
{C_text("f_4391:eval_2escm"),(void*)f_4391},
{C_text("f_4395:eval_2escm"),(void*)f_4395},
{C_text("f_4409:eval_2escm"),(void*)f_4409},
{C_text("f_4412:eval_2escm"),(void*)f_4412},
{C_text("f_4415:eval_2escm"),(void*)f_4415},
{C_text("f_4416:eval_2escm"),(void*)f_4416},
{C_text("f_4420:eval_2escm"),(void*)f_4420},
{C_text("f_4423:eval_2escm"),(void*)f_4423},
{C_text("f_4461:eval_2escm"),(void*)f_4461},
{C_text("f_4464:eval_2escm"),(void*)f_4464},
{C_text("f_4492:eval_2escm"),(void*)f_4492},
{C_text("f_4498:eval_2escm"),(void*)f_4498},
{C_text("f_4502:eval_2escm"),(void*)f_4502},
{C_text("f_4511:eval_2escm"),(void*)f_4511},
{C_text("f_4515:eval_2escm"),(void*)f_4515},
{C_text("f_4522:eval_2escm"),(void*)f_4522},
{C_text("f_4523:eval_2escm"),(void*)f_4523},
{C_text("f_4527:eval_2escm"),(void*)f_4527},
{C_text("f_4553:eval_2escm"),(void*)f_4553},
{C_text("f_4558:eval_2escm"),(void*)f_4558},
{C_text("f_4570:eval_2escm"),(void*)f_4570},
{C_text("f_4571:eval_2escm"),(void*)f_4571},
{C_text("f_4580:eval_2escm"),(void*)f_4580},
{C_text("f_4607:eval_2escm"),(void*)f_4607},
{C_text("f_4616:eval_2escm"),(void*)f_4616},
{C_text("f_4622:eval_2escm"),(void*)f_4622},
{C_text("f_4625:eval_2escm"),(void*)f_4625},
{C_text("f_4634:eval_2escm"),(void*)f_4634},
{C_text("f_4635:eval_2escm"),(void*)f_4635},
{C_text("f_4651:eval_2escm"),(void*)f_4651},
{C_text("f_4655:eval_2escm"),(void*)f_4655},
{C_text("f_4668:eval_2escm"),(void*)f_4668},
{C_text("f_4671:eval_2escm"),(void*)f_4671},
{C_text("f_4672:eval_2escm"),(void*)f_4672},
{C_text("f_4688:eval_2escm"),(void*)f_4688},
{C_text("f_4692:eval_2escm"),(void*)f_4692},
{C_text("f_4696:eval_2escm"),(void*)f_4696},
{C_text("f_4704:eval_2escm"),(void*)f_4704},
{C_text("f_4717:eval_2escm"),(void*)f_4717},
{C_text("f_4720:eval_2escm"),(void*)f_4720},
{C_text("f_4726:eval_2escm"),(void*)f_4726},
{C_text("f_4727:eval_2escm"),(void*)f_4727},
{C_text("f_4743:eval_2escm"),(void*)f_4743},
{C_text("f_4747:eval_2escm"),(void*)f_4747},
{C_text("f_4751:eval_2escm"),(void*)f_4751},
{C_text("f_4755:eval_2escm"),(void*)f_4755},
{C_text("f_4763:eval_2escm"),(void*)f_4763},
{C_text("f_4771:eval_2escm"),(void*)f_4771},
{C_text("f_4784:eval_2escm"),(void*)f_4784},
{C_text("f_4787:eval_2escm"),(void*)f_4787},
{C_text("f_4793:eval_2escm"),(void*)f_4793},
{C_text("f_4796:eval_2escm"),(void*)f_4796},
{C_text("f_4797:eval_2escm"),(void*)f_4797},
{C_text("f_4813:eval_2escm"),(void*)f_4813},
{C_text("f_4817:eval_2escm"),(void*)f_4817},
{C_text("f_4821:eval_2escm"),(void*)f_4821},
{C_text("f_4825:eval_2escm"),(void*)f_4825},
{C_text("f_4829:eval_2escm"),(void*)f_4829},
{C_text("f_4837:eval_2escm"),(void*)f_4837},
{C_text("f_4845:eval_2escm"),(void*)f_4845},
{C_text("f_4853:eval_2escm"),(void*)f_4853},
{C_text("f_4861:eval_2escm"),(void*)f_4861},
{C_text("f_4874:eval_2escm"),(void*)f_4874},
{C_text("f_4875:eval_2escm"),(void*)f_4875},
{C_text("f_4879:eval_2escm"),(void*)f_4879},
{C_text("f_4882:eval_2escm"),(void*)f_4882},
{C_text("f_4891:eval_2escm"),(void*)f_4891},
{C_text("f_4916:eval_2escm"),(void*)f_4916},
{C_text("f_4921:eval_2escm"),(void*)f_4921},
{C_text("f_4946:eval_2escm"),(void*)f_4946},
{C_text("f_4963:eval_2escm"),(void*)f_4963},
{C_text("f_4967:eval_2escm"),(void*)f_4967},
{C_text("f_4971:eval_2escm"),(void*)f_4971},
{C_text("f_4974:eval_2escm"),(void*)f_4974},
{C_text("f_4980:eval_2escm"),(void*)f_4980},
{C_text("f_4988:eval_2escm"),(void*)f_4988},
{C_text("f_4996:eval_2escm"),(void*)f_4996},
{C_text("f_4998:eval_2escm"),(void*)f_4998},
{C_text("f_5002:eval_2escm"),(void*)f_5002},
{C_text("f_5005:eval_2escm"),(void*)f_5005},
{C_text("f_5010:eval_2escm"),(void*)f_5010},
{C_text("f_5012:eval_2escm"),(void*)f_5012},
{C_text("f_5037:eval_2escm"),(void*)f_5037},
{C_text("f_5046:eval_2escm"),(void*)f_5046},
{C_text("f_5119:eval_2escm"),(void*)f_5119},
{C_text("f_5123:eval_2escm"),(void*)f_5123},
{C_text("f_5143:eval_2escm"),(void*)f_5143},
{C_text("f_5157:eval_2escm"),(void*)f_5157},
{C_text("f_5191:eval_2escm"),(void*)f_5191},
{C_text("f_5241:eval_2escm"),(void*)f_5241},
{C_text("f_5250:eval_2escm"),(void*)f_5250},
{C_text("f_5276:eval_2escm"),(void*)f_5276},
{C_text("f_5303:eval_2escm"),(void*)f_5303},
{C_text("f_5307:eval_2escm"),(void*)f_5307},
{C_text("f_5319:eval_2escm"),(void*)f_5319},
{C_text("f_5333:eval_2escm"),(void*)f_5333},
{C_text("f_5381:eval_2escm"),(void*)f_5381},
{C_text("f_5429:eval_2escm"),(void*)f_5429},
{C_text("f_5463:eval_2escm"),(void*)f_5463},
{C_text("f_5488:eval_2escm"),(void*)f_5488},
{C_text("f_5497:eval_2escm"),(void*)f_5497},
{C_text("f_5538:eval_2escm"),(void*)f_5538},
{C_text("f_5549:eval_2escm"),(void*)f_5549},
{C_text("f_5554:eval_2escm"),(void*)f_5554},
{C_text("f_5564:eval_2escm"),(void*)f_5564},
{C_text("f_5567:eval_2escm"),(void*)f_5567},
{C_text("f_5573:eval_2escm"),(void*)f_5573},
{C_text("f_5583:eval_2escm"),(void*)f_5583},
{C_text("f_5589:eval_2escm"),(void*)f_5589},
{C_text("f_5602:eval_2escm"),(void*)f_5602},
{C_text("f_5608:eval_2escm"),(void*)f_5608},
{C_text("f_5626:eval_2escm"),(void*)f_5626},
{C_text("f_5632:eval_2escm"),(void*)f_5632},
{C_text("f_5645:eval_2escm"),(void*)f_5645},
{C_text("f_5651:eval_2escm"),(void*)f_5651},
{C_text("f_5673:eval_2escm"),(void*)f_5673},
{C_text("f_5679:eval_2escm"),(void*)f_5679},
{C_text("f_5692:eval_2escm"),(void*)f_5692},
{C_text("f_5698:eval_2escm"),(void*)f_5698},
{C_text("f_5720:eval_2escm"),(void*)f_5720},
{C_text("f_5726:eval_2escm"),(void*)f_5726},
{C_text("f_5739:eval_2escm"),(void*)f_5739},
{C_text("f_5745:eval_2escm"),(void*)f_5745},
{C_text("f_5767:eval_2escm"),(void*)f_5767},
{C_text("f_5773:eval_2escm"),(void*)f_5773},
{C_text("f_5786:eval_2escm"),(void*)f_5786},
{C_text("f_5792:eval_2escm"),(void*)f_5792},
{C_text("f_5804:eval_2escm"),(void*)f_5804},
{C_text("f_5808:eval_2escm"),(void*)f_5808},
{C_text("f_5814:eval_2escm"),(void*)f_5814},
{C_text("f_5826:eval_2escm"),(void*)f_5826},
{C_text("f_5830:eval_2escm"),(void*)f_5830},
{C_text("f_5831:eval_2escm"),(void*)f_5831},
{C_text("f_5837:eval_2escm"),(void*)f_5837},
{C_text("f_5859:eval_2escm"),(void*)f_5859},
{C_text("f_5875:eval_2escm"),(void*)f_5875},
{C_text("f_5879:eval_2escm"),(void*)f_5879},
{C_text("f_5883:eval_2escm"),(void*)f_5883},
{C_text("f_5886:eval_2escm"),(void*)f_5886},
{C_text("f_5892:eval_2escm"),(void*)f_5892},
{C_text("f_5900:eval_2escm"),(void*)f_5900},
{C_text("f_5906:eval_2escm"),(void*)f_5906},
{C_text("f_5910:eval_2escm"),(void*)f_5910},
{C_text("f_5913:eval_2escm"),(void*)f_5913},
{C_text("f_5918:eval_2escm"),(void*)f_5918},
{C_text("f_5920:eval_2escm"),(void*)f_5920},
{C_text("f_5945:eval_2escm"),(void*)f_5945},
{C_text("f_5955:eval_2escm"),(void*)f_5955},
{C_text("f_5960:eval_2escm"),(void*)f_5960},
{C_text("f_5968:eval_2escm"),(void*)f_5968},
{C_text("f_5970:eval_2escm"),(void*)f_5970},
{C_text("f_5981:eval_2escm"),(void*)f_5981},
{C_text("f_5990:eval_2escm"),(void*)f_5990},
{C_text("f_5995:eval_2escm"),(void*)f_5995},
{C_text("f_5999:eval_2escm"),(void*)f_5999},
{C_text("f_6003:eval_2escm"),(void*)f_6003},
{C_text("f_6006:eval_2escm"),(void*)f_6006},
{C_text("f_6012:eval_2escm"),(void*)f_6012},
{C_text("f_6020:eval_2escm"),(void*)f_6020},
{C_text("f_6028:eval_2escm"),(void*)f_6028},
{C_text("f_6030:eval_2escm"),(void*)f_6030},
{C_text("f_6034:eval_2escm"),(void*)f_6034},
{C_text("f_6037:eval_2escm"),(void*)f_6037},
{C_text("f_6055:eval_2escm"),(void*)f_6055},
{C_text("f_6059:eval_2escm"),(void*)f_6059},
{C_text("f_6063:eval_2escm"),(void*)f_6063},
{C_text("f_6067:eval_2escm"),(void*)f_6067},
{C_text("f_6082:eval_2escm"),(void*)f_6082},
{C_text("f_6086:eval_2escm"),(void*)f_6086},
{C_text("f_6088:eval_2escm"),(void*)f_6088},
{C_text("f_6142:eval_2escm"),(void*)f_6142},
{C_text("f_6146:eval_2escm"),(void*)f_6146},
{C_text("f_6150:eval_2escm"),(void*)f_6150},
{C_text("f_6165:eval_2escm"),(void*)f_6165},
{C_text("f_6168:eval_2escm"),(void*)f_6168},
{C_text("f_6169:eval_2escm"),(void*)f_6169},
{C_text("f_6188:eval_2escm"),(void*)f_6188},
{C_text("f_6192:eval_2escm"),(void*)f_6192},
{C_text("f_6196:eval_2escm"),(void*)f_6196},
{C_text("f_6199:eval_2escm"),(void*)f_6199},
{C_text("f_6205:eval_2escm"),(void*)f_6205},
{C_text("f_6213:eval_2escm"),(void*)f_6213},
{C_text("f_6221:eval_2escm"),(void*)f_6221},
{C_text("f_6223:eval_2escm"),(void*)f_6223},
{C_text("f_6227:eval_2escm"),(void*)f_6227},
{C_text("f_6230:eval_2escm"),(void*)f_6230},
{C_text("f_6233:eval_2escm"),(void*)f_6233},
{C_text("f_6258:eval_2escm"),(void*)f_6258},
{C_text("f_6260:eval_2escm"),(void*)f_6260},
{C_text("f_6307:eval_2escm"),(void*)f_6307},
{C_text("f_6310:eval_2escm"),(void*)f_6310},
{C_text("f_6313:eval_2escm"),(void*)f_6313},
{C_text("f_6316:eval_2escm"),(void*)f_6316},
{C_text("f_6319:eval_2escm"),(void*)f_6319},
{C_text("f_6326:eval_2escm"),(void*)f_6326},
{C_text("f_6330:eval_2escm"),(void*)f_6330},
{C_text("f_6334:eval_2escm"),(void*)f_6334},
{C_text("f_6351:eval_2escm"),(void*)f_6351},
{C_text("f_6373:eval_2escm"),(void*)f_6373},
{C_text("f_6381:eval_2escm"),(void*)f_6381},
{C_text("f_6400:eval_2escm"),(void*)f_6400},
{C_text("f_6404:eval_2escm"),(void*)f_6404},
{C_text("f_6409:eval_2escm"),(void*)f_6409},
{C_text("f_6414:eval_2escm"),(void*)f_6414},
{C_text("f_6420:eval_2escm"),(void*)f_6420},
{C_text("f_6433:eval_2escm"),(void*)f_6433},
{C_text("f_6437:eval_2escm"),(void*)f_6437},
{C_text("f_6466:eval_2escm"),(void*)f_6466},
{C_text("f_6478:eval_2escm"),(void*)f_6478},
{C_text("f_6480:eval_2escm"),(void*)f_6480},
{C_text("f_6494:eval_2escm"),(void*)f_6494},
{C_text("f_6519:eval_2escm"),(void*)f_6519},
{C_text("f_6535:eval_2escm"),(void*)f_6535},
{C_text("f_6544:eval_2escm"),(void*)f_6544},
{C_text("f_6547:eval_2escm"),(void*)f_6547},
{C_text("f_6550:eval_2escm"),(void*)f_6550},
{C_text("f_6553:eval_2escm"),(void*)f_6553},
{C_text("f_6558:eval_2escm"),(void*)f_6558},
{C_text("f_6562:eval_2escm"),(void*)f_6562},
{C_text("f_6565:eval_2escm"),(void*)f_6565},
{C_text("f_6568:eval_2escm"),(void*)f_6568},
{C_text("f_6571:eval_2escm"),(void*)f_6571},
{C_text("f_6575:eval_2escm"),(void*)f_6575},
{C_text("f_6579:eval_2escm"),(void*)f_6579},
{C_text("f_6583:eval_2escm"),(void*)f_6583},
{C_text("f_6587:eval_2escm"),(void*)f_6587},
{C_text("f_6590:eval_2escm"),(void*)f_6590},
{C_text("f_6593:eval_2escm"),(void*)f_6593},
{C_text("f_6596:eval_2escm"),(void*)f_6596},
{C_text("f_6599:eval_2escm"),(void*)f_6599},
{C_text("f_6614:eval_2escm"),(void*)f_6614},
{C_text("f_6620:eval_2escm"),(void*)f_6620},
{C_text("f_6630:eval_2escm"),(void*)f_6630},
{C_text("f_6640:eval_2escm"),(void*)f_6640},
{C_text("f_6643:eval_2escm"),(void*)f_6643},
{C_text("f_6646:eval_2escm"),(void*)f_6646},
{C_text("f_6647:eval_2escm"),(void*)f_6647},
{C_text("f_6653:eval_2escm"),(void*)f_6653},
{C_text("f_6676:eval_2escm"),(void*)f_6676},
{C_text("f_6687:eval_2escm"),(void*)f_6687},
{C_text("f_6691:eval_2escm"),(void*)f_6691},
{C_text("f_6706:eval_2escm"),(void*)f_6706},
{C_text("f_6710:eval_2escm"),(void*)f_6710},
{C_text("f_6714:eval_2escm"),(void*)f_6714},
{C_text("f_6717:eval_2escm"),(void*)f_6717},
{C_text("f_6720:eval_2escm"),(void*)f_6720},
{C_text("f_6723:eval_2escm"),(void*)f_6723},
{C_text("f_6726:eval_2escm"),(void*)f_6726},
{C_text("f_6729:eval_2escm"),(void*)f_6729},
{C_text("f_6732:eval_2escm"),(void*)f_6732},
{C_text("f_6735:eval_2escm"),(void*)f_6735},
{C_text("f_6742:eval_2escm"),(void*)f_6742},
{C_text("f_6749:eval_2escm"),(void*)f_6749},
{C_text("f_6762:eval_2escm"),(void*)f_6762},
{C_text("f_6773:eval_2escm"),(void*)f_6773},
{C_text("f_6806:eval_2escm"),(void*)f_6806},
{C_text("f_6831:eval_2escm"),(void*)f_6831},
{C_text("f_6859:eval_2escm"),(void*)f_6859},
{C_text("f_6893:eval_2escm"),(void*)f_6893},
{C_text("f_6919:eval_2escm"),(void*)f_6919},
{C_text("f_6940:eval_2escm"),(void*)f_6940},
{C_text("f_6969:eval_2escm"),(void*)f_6969},
{C_text("f_6981:eval_2escm"),(void*)f_6981},
{C_text("f_7004:eval_2escm"),(void*)f_7004},
{C_text("f_7017:eval_2escm"),(void*)f_7017},
{C_text("f_7037:eval_2escm"),(void*)f_7037},
{C_text("f_7063:eval_2escm"),(void*)f_7063},
{C_text("f_7081:eval_2escm"),(void*)f_7081},
{C_text("f_7093:eval_2escm"),(void*)f_7093},
{C_text("f_7098:eval_2escm"),(void*)f_7098},
{C_text("f_7106:eval_2escm"),(void*)f_7106},
{C_text("f_7108:eval_2escm"),(void*)f_7108},
{C_text("f_7289:eval_2escm"),(void*)f_7289},
{C_text("f_7294:eval_2escm"),(void*)f_7294},
{C_text("f_7302:eval_2escm"),(void*)f_7302},
{C_text("f_7304:eval_2escm"),(void*)f_7304},
{C_text("f_7310:eval_2escm"),(void*)f_7310},
{C_text("f_7317:eval_2escm"),(void*)f_7317},
{C_text("f_7343:eval_2escm"),(void*)f_7343},
{C_text("f_7372:eval_2escm"),(void*)f_7372},
{C_text("f_7401:eval_2escm"),(void*)f_7401},
{C_text("f_7418:eval_2escm"),(void*)f_7418},
{C_text("f_7444:eval_2escm"),(void*)f_7444},
{C_text("f_7451:eval_2escm"),(void*)f_7451},
{C_text("f_7460:eval_2escm"),(void*)f_7460},
{C_text("f_7479:eval_2escm"),(void*)f_7479},
{C_text("f_7486:eval_2escm"),(void*)f_7486},
{C_text("f_7498:eval_2escm"),(void*)f_7498},
{C_text("f_7499:eval_2escm"),(void*)f_7499},
{C_text("f_7506:eval_2escm"),(void*)f_7506},
{C_text("f_7513:eval_2escm"),(void*)f_7513},
{C_text("f_7526:eval_2escm"),(void*)f_7526},
{C_text("f_7529:eval_2escm"),(void*)f_7529},
{C_text("f_7530:eval_2escm"),(void*)f_7530},
{C_text("f_7537:eval_2escm"),(void*)f_7537},
{C_text("f_7544:eval_2escm"),(void*)f_7544},
{C_text("f_7548:eval_2escm"),(void*)f_7548},
{C_text("f_7562:eval_2escm"),(void*)f_7562},
{C_text("f_7565:eval_2escm"),(void*)f_7565},
{C_text("f_7568:eval_2escm"),(void*)f_7568},
{C_text("f_7569:eval_2escm"),(void*)f_7569},
{C_text("f_7576:eval_2escm"),(void*)f_7576},
{C_text("f_7583:eval_2escm"),(void*)f_7583},
{C_text("f_7587:eval_2escm"),(void*)f_7587},
{C_text("f_7591:eval_2escm"),(void*)f_7591},
{C_text("f_7606:eval_2escm"),(void*)f_7606},
{C_text("f_7609:eval_2escm"),(void*)f_7609},
{C_text("f_7612:eval_2escm"),(void*)f_7612},
{C_text("f_7615:eval_2escm"),(void*)f_7615},
{C_text("f_7616:eval_2escm"),(void*)f_7616},
{C_text("f_7623:eval_2escm"),(void*)f_7623},
{C_text("f_7630:eval_2escm"),(void*)f_7630},
{C_text("f_7634:eval_2escm"),(void*)f_7634},
{C_text("f_7638:eval_2escm"),(void*)f_7638},
{C_text("f_7642:eval_2escm"),(void*)f_7642},
{C_text("f_7653:eval_2escm"),(void*)f_7653},
{C_text("f_7663:eval_2escm"),(void*)f_7663},
{C_text("f_7664:eval_2escm"),(void*)f_7664},
{C_text("f_7675:eval_2escm"),(void*)f_7675},
{C_text("f_7680:eval_2escm"),(void*)f_7680},
{C_text("f_7690:eval_2escm"),(void*)f_7690},
{C_text("f_7692:eval_2escm"),(void*)f_7692},
{C_text("f_7717:eval_2escm"),(void*)f_7717},
{C_text("f_7726:eval_2escm"),(void*)f_7726},
{C_text("f_7751:eval_2escm"),(void*)f_7751},
{C_text("f_7774:eval_2escm"),(void*)f_7774},
{C_text("f_7793:eval_2escm"),(void*)f_7793},
{C_text("f_7843:eval_2escm"),(void*)f_7843},
{C_text("f_7847:eval_2escm"),(void*)f_7847},
{C_text("f_7850:eval_2escm"),(void*)f_7850},
{C_text("f_7855:eval_2escm"),(void*)f_7855},
{C_text("f_7859:eval_2escm"),(void*)f_7859},
{C_text("f_7862:eval_2escm"),(void*)f_7862},
{C_text("f_7865:eval_2escm"),(void*)f_7865},
{C_text("f_7869:eval_2escm"),(void*)f_7869},
{C_text("f_7873:eval_2escm"),(void*)f_7873},
{C_text("f_7877:eval_2escm"),(void*)f_7877},
{C_text("f_7880:eval_2escm"),(void*)f_7880},
{C_text("f_7883:eval_2escm"),(void*)f_7883},
{C_text("f_7886:eval_2escm"),(void*)f_7886},
{C_text("f_7898:eval_2escm"),(void*)f_7898},
{C_text("f_7904:eval_2escm"),(void*)f_7904},
{C_text("f_7908:eval_2escm"),(void*)f_7908},
{C_text("f_7913:eval_2escm"),(void*)f_7913},
{C_text("f_7917:eval_2escm"),(void*)f_7917},
{C_text("f_7924:eval_2escm"),(void*)f_7924},
{C_text("f_7928:eval_2escm"),(void*)f_7928},
{C_text("f_7930:eval_2escm"),(void*)f_7930},
{C_text("f_7934:eval_2escm"),(void*)f_7934},
{C_text("f_7937:eval_2escm"),(void*)f_7937},
{C_text("f_7940:eval_2escm"),(void*)f_7940},
{C_text("f_7943:eval_2escm"),(void*)f_7943},
{C_text("f_7946:eval_2escm"),(void*)f_7946},
{C_text("f_7949:eval_2escm"),(void*)f_7949},
{C_text("f_7956:eval_2escm"),(void*)f_7956},
{C_text("f_7958:eval_2escm"),(void*)f_7958},
{C_text("f_7966:eval_2escm"),(void*)f_7966},
{C_text("f_7968:eval_2escm"),(void*)f_7968},
{C_text("f_7975:eval_2escm"),(void*)f_7975},
{C_text("f_7977:eval_2escm"),(void*)f_7977},
{C_text("f_7980:eval_2escm"),(void*)f_7980},
{C_text("f_7990:eval_2escm"),(void*)f_7990},
{C_text("f_8004:eval_2escm"),(void*)f_8004},
{C_text("f_8023:eval_2escm"),(void*)f_8023},
{C_text("f_8062:eval_2escm"),(void*)f_8062},
{C_text("f_8066:eval_2escm"),(void*)f_8066},
{C_text("f_8069:eval_2escm"),(void*)f_8069},
{C_text("f_8072:eval_2escm"),(void*)f_8072},
{C_text("f_8075:eval_2escm"),(void*)f_8075},
{C_text("f_8078:eval_2escm"),(void*)f_8078},
{C_text("f_8080:eval_2escm"),(void*)f_8080},
{C_text("f_8089:eval_2escm"),(void*)f_8089},
{C_text("f_8120:eval_2escm"),(void*)f_8120},
{C_text("f_8138:eval_2escm"),(void*)f_8138},
{C_text("f_8142:eval_2escm"),(void*)f_8142},
{C_text("f_8163:eval_2escm"),(void*)f_8163},
{C_text("f_8167:eval_2escm"),(void*)f_8167},
{C_text("f_8189:eval_2escm"),(void*)f_8189},
{C_text("f_8566:eval_2escm"),(void*)f_8566},
{C_text("f_8588:eval_2escm"),(void*)f_8588},
{C_text("f_9479:eval_2escm"),(void*)f_9479},
{C_text("f_9482:eval_2escm"),(void*)f_9482},
{C_text("f_9496:eval_2escm"),(void*)f_9496},
{C_text("f_9499:eval_2escm"),(void*)f_9499},
{C_text("f_9501:eval_2escm"),(void*)f_9501},
{C_text("f_9504:eval_2escm"),(void*)f_9504},
{C_text("f_9511:eval_2escm"),(void*)f_9511},
{C_text("f_9521:eval_2escm"),(void*)f_9521},
{C_text("f_9546:eval_2escm"),(void*)f_9546},
{C_text("f_9550:eval_2escm"),(void*)f_9550},
{C_text("f_9563:eval_2escm"),(void*)f_9563},
{C_text("f_9589:eval_2escm"),(void*)f_9589},
{C_text("f_9593:eval_2escm"),(void*)f_9593},
{C_text("f_9600:eval_2escm"),(void*)f_9600},
{C_text("f_9605:eval_2escm"),(void*)f_9605},
{C_text("f_9618:eval_2escm"),(void*)f_9618},
{C_text("f_9687:eval_2escm"),(void*)f_9687},
{C_text("f_9693:eval_2escm"),(void*)f_9693},
{C_text("f_9701:eval_2escm"),(void*)f_9701},
{C_text("f_9705:eval_2escm"),(void*)f_9705},
{C_text("f_9707:eval_2escm"),(void*)f_9707},
{C_text("f_9745:eval_2escm"),(void*)f_9745},
{C_text("f_9750:eval_2escm"),(void*)f_9750},
{C_text("f_9754:eval_2escm"),(void*)f_9754},
{C_text("f_9757:eval_2escm"),(void*)f_9757},
{C_text("f_9773:eval_2escm"),(void*)f_9773},
{C_text("f_9777:eval_2escm"),(void*)f_9777},
{C_text("f_9781:eval_2escm"),(void*)f_9781},
{C_text("f_9785:eval_2escm"),(void*)f_9785},
{C_text("f_9789:eval_2escm"),(void*)f_9789},
{C_text("f_9792:eval_2escm"),(void*)f_9792},
{C_text("f_9795:eval_2escm"),(void*)f_9795},
{C_text("f_9798:eval_2escm"),(void*)f_9798},
{C_text("f_9803:eval_2escm"),(void*)f_9803},
{C_text("f_9809:eval_2escm"),(void*)f_9809},
{C_text("f_9818:eval_2escm"),(void*)f_9818},
{C_text("f_9822:eval_2escm"),(void*)f_9822},
{C_text("f_9827:eval_2escm"),(void*)f_9827},
{C_text("f_9830:eval_2escm"),(void*)f_9830},
{C_text("f_9834:eval_2escm"),(void*)f_9834},
{C_text("f_9837:eval_2escm"),(void*)f_9837},
{C_text("f_9840:eval_2escm"),(void*)f_9840},
{C_text("f_9845:eval_2escm"),(void*)f_9845},
{C_text("f_9855:eval_2escm"),(void*)f_9855},
{C_text("f_9858:eval_2escm"),(void*)f_9858},
{C_text("f_9865:eval_2escm"),(void*)f_9865},
{C_text("f_9867:eval_2escm"),(void*)f_9867},
{C_text("f_9874:eval_2escm"),(void*)f_9874},
{C_text("f_9879:eval_2escm"),(void*)f_9879},
{C_text("f_9885:eval_2escm"),(void*)f_9885},
{C_text("f_9889:eval_2escm"),(void*)f_9889},
{C_text("f_9896:eval_2escm"),(void*)f_9896},
{C_text("f_9901:eval_2escm"),(void*)f_9901},
{C_text("f_9910:eval_2escm"),(void*)f_9910},
{C_text("f_9918:eval_2escm"),(void*)f_9918},
{C_text("f_9928:eval_2escm"),(void*)f_9928},
{C_text("f_9952:eval_2escm"),(void*)f_9952},
{C_text("f_9956:eval_2escm"),(void*)f_9956},
{C_text("f_9961:eval_2escm"),(void*)f_9961},
{C_text("f_9970:eval_2escm"),(void*)f_9970},
{C_text("f_9989:eval_2escm"),(void*)f_9989},
{C_text("f_9992:eval_2escm"),(void*)f_9992},
{C_text("f_9995:eval_2escm"),(void*)f_9995},
{C_text("toplevel:eval_2escm"),(void*)C_eval_toplevel},
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
o|hiding unexported module binding: chicken.eval#d 
o|hiding unexported module binding: chicken.eval#define-alias 
o|hiding unexported module binding: chicken.eval#d 
o|hiding unexported module binding: chicken.eval#eval-decorator 
o|hiding unexported module binding: chicken.eval#compile-to-closure 
o|hiding unexported module binding: chicken.load#partition 
o|hiding unexported module binding: chicken.load#span 
o|hiding unexported module binding: chicken.load#take 
o|hiding unexported module binding: chicken.load#drop 
o|hiding unexported module binding: chicken.load#split-at 
o|hiding unexported module binding: chicken.load#append-map 
o|hiding unexported module binding: chicken.load#every 
o|hiding unexported module binding: chicken.load#any 
o|hiding unexported module binding: chicken.load#cons* 
o|hiding unexported module binding: chicken.load#concatenate 
o|hiding unexported module binding: chicken.load#delete 
o|hiding unexported module binding: chicken.load#first 
o|hiding unexported module binding: chicken.load#second 
o|hiding unexported module binding: chicken.load#third 
o|hiding unexported module binding: chicken.load#fourth 
o|hiding unexported module binding: chicken.load#fifth 
o|hiding unexported module binding: chicken.load#delete-duplicates 
o|hiding unexported module binding: chicken.load#alist-cons 
o|hiding unexported module binding: chicken.load#filter 
o|hiding unexported module binding: chicken.load#filter-map 
o|hiding unexported module binding: chicken.load#remove 
o|hiding unexported module binding: chicken.load#unzip1 
o|hiding unexported module binding: chicken.load#last 
o|hiding unexported module binding: chicken.load#list-index 
o|hiding unexported module binding: chicken.load#lset-adjoin/eq? 
o|hiding unexported module binding: chicken.load#lset-difference/eq? 
o|hiding unexported module binding: chicken.load#lset-union/eq? 
o|hiding unexported module binding: chicken.load#lset-intersection/eq? 
o|hiding unexported module binding: chicken.load#list-tabulate 
o|hiding unexported module binding: chicken.load#lset<=/eq? 
o|hiding unexported module binding: chicken.load#lset=/eq? 
o|hiding unexported module binding: chicken.load#length+ 
o|hiding unexported module binding: chicken.load#find 
o|hiding unexported module binding: chicken.load#find-tail 
o|hiding unexported module binding: chicken.load#iota 
o|hiding unexported module binding: chicken.load#make-list 
o|hiding unexported module binding: chicken.load#posq 
o|hiding unexported module binding: chicken.load#posv 
o|hiding unexported module binding: chicken.load#constant2145 
o|hiding unexported module binding: chicken.load#constant2148 
o|hiding unexported module binding: chicken.load#constant2152 
o|hiding unexported module binding: chicken.load#constant2157 
o|hiding unexported module binding: chicken.load#constant2163 
o|hiding unexported module binding: chicken.load#constant2170 
o|hiding unexported module binding: chicken.load#constant2178 
o|hiding unexported module binding: chicken.load#constant2187 
o|hiding unexported module binding: chicken.load#load-library-extension 
o|hiding unexported module binding: chicken.load#default-dynamic-load-libraries 
o|hiding unexported module binding: chicken.load#path-separators 
o|hiding unexported module binding: chicken.load#path-separator-index/right 
o|hiding unexported module binding: chicken.load#make-relative-pathname 
o|hiding unexported module binding: chicken.load#toplevel 
o|hiding unexported module binding: chicken.load#c-toplevel 
o|hiding unexported module binding: chicken.load#load/internal 
o|hiding unexported module binding: chicken.load#load-unit 
o|hiding unexported module binding: chicken.load#file-exists? 
o|hiding unexported module binding: chicken.load#find-file 
o|hiding unexported module binding: chicken.load#find-dynamic-extension 
o|hiding unexported module binding: chicken.load#load-extension 
S|applied compiler syntax:
S|  chicken.base#foldl		3
S|  chicken.base#foldr		4
S|  scheme#for-each		7
S|  ##sys#map		4
S|  scheme#map		17
o|eliminated procedure checks: 315 
o|folded constant expression: (scheme#integer->char (quote 127)) 
o|specializations:
o|  1 (scheme#number->string fixnum)
o|  1 (##sys#debug-mode?)
o|  1 (scheme#positive? fixnum)
o|  1 (scheme#eqv? * *)
o|  3 (scheme#memq * list)
o|  1 (scheme#caddr (pair * (pair * pair)))
o|  1 (scheme#length list)
o|  3 (scheme#cddr (pair * pair))
o|  13 (scheme#car pair)
o|  17 (##sys#check-list (or pair list) *)
o|  1 (scheme#zero? *)
o|  8 (scheme#eqv? (or eof null fixnum char boolean symbol keyword) *)
o|  82 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  26 (scheme#cdr pair)
o|  2 (scheme#cdar (pair pair *))
(o e)|safe calls: 1075 
(o e)|assignments to immediate values: 1 
o|safe globals: (##sys#unbound-in-eval chicken.eval#eval-decorator) 
o|merged explicitly consed rest parameter: rest157160 
o|inlining procedure: k3605 
o|inlining procedure: k3605 
o|inlining procedure: k3643 
o|inlining procedure: k3643 
o|inlining procedure: k3658 
o|inlining procedure: k3658 
o|inlining procedure: k3686 
o|inlining procedure: k3686 
o|contracted procedure: "(eval.scm:103) posq206" 
o|inlining procedure: k3733 
o|inlining procedure: k3733 
o|inlining procedure: k3763 
o|inlining procedure: k3763 
o|inlining procedure: k3777 
o|inlining procedure: k3777 
o|contracted procedure: "(eval.scm:131) chicken.eval#eval-decorator" 
o|inlining procedure: k3540 
o|inlining procedure: k3540 
o|inlining procedure: k3827 
o|inlining procedure: k3827 
o|inlining procedure: k3853 
o|inlining procedure: k3876 
o|inlining procedure: k3876 
o|inlining procedure: k3903 
o|inlining procedure: k3903 
o|inlining procedure: k3916 
o|inlining procedure: k3916 
o|inlining procedure: k3931 
o|inlining procedure: k3931 
o|inlining procedure: k3853 
o|inlining procedure: k3964 
o|inlining procedure: k3964 
o|inlining procedure: k4006 
o|inlining procedure: k4006 
o|substituted constant variable: a4040 
o|substituted constant variable: a4042 
o|substituted constant variable: a4044 
o|substituted constant variable: a4046 
o|inlining procedure: k4047 
o|inlining procedure: k4061 
o|inlining procedure: k4061 
o|inlining procedure: k4077 
o|inlining procedure: k4077 
o|substituted constant variable: a4088 
o|substituted constant variable: a4090 
o|substituted constant variable: a4092 
o|substituted constant variable: a4094 
o|inlining procedure: k4047 
o|inlining procedure: k4101 
o|inlining procedure: k4101 
o|inlining procedure: k4108 
o|inlining procedure: k4108 
o|inlining procedure: k4128 
o|inlining procedure: k4161 
o|inlining procedure: k4178 
o|inlining procedure: k4178 
o|inlining procedure: k4194 
o|inlining procedure: k4194 
o|inlining procedure: k4210 
o|inlining procedure: k4210 
o|substituted constant variable: a4229 
o|substituted constant variable: a4231 
o|substituted constant variable: a4233 
o|substituted constant variable: a4235 
o|substituted constant variable: a4237 
o|substituted constant variable: a4239 
o|substituted constant variable: a4241 
o|inlining procedure: k4161 
o|inlining procedure: k4257 
o|inlining procedure: k4257 
o|inlining procedure: k4283 
o|inlining procedure: k4283 
o|inlining procedure: k4308 
o|inlining procedure: k4308 
o|inlining procedure: k4345 
o|inlining procedure: k4366 
o|inlining procedure: k4366 
o|substituted constant variable: a4448 
o|substituted constant variable: a4450 
o|substituted constant variable: a4452 
o|inlining procedure: k4345 
o|inlining procedure: k4479 
o|inlining procedure: k4503 
o|inlining procedure: k4534 
o|inlining procedure: k4534 
o|inlining procedure: k4503 
o|inlining procedure: k4479 
o|inlining procedure: k4626 
o|inlining procedure: k4626 
o|inlining procedure: k4709 
o|inlining procedure: k4709 
o|inlining procedure: k4893 
o|inlining procedure: k4893 
o|inlining procedure: k4923 
o|inlining procedure: k4923 
o|substituted constant variable: a4955 
o|substituted constant variable: a4957 
o|substituted constant variable: a4959 
o|substituted constant variable: a4961 
o|consed rest parameter at call site: "(eval.scm:303) chicken.eval#compile-to-closure" 3 
o|inlining procedure: k5014 
o|inlining procedure: k5014 
o|inlining procedure: k5048 
o|contracted procedure: "(eval.scm:298) g462471" 
o|inlining procedure: k5048 
o|inlining procedure: k5079 
o|inlining procedure: k5159 
o|contracted procedure: "(eval.scm:353) g625634" 
o|inlining procedure: k5159 
o|inlining procedure: k5193 
o|contracted procedure: "(eval.scm:350) g598607" 
o|inlining procedure: k5193 
o|inlining procedure: k5079 
o|inlining procedure: k5335 
o|contracted procedure: "(eval.scm:370) g774784" 
o|inlining procedure: k5335 
o|inlining procedure: k5383 
o|contracted procedure: "(eval.scm:369) g741751" 
o|inlining procedure: k5383 
o|inlining procedure: k5431 
o|contracted procedure: "(eval.scm:366) g714723" 
o|inlining procedure: k5431 
o|inlining procedure: k5465 
o|inlining procedure: k5465 
o|inlining procedure: k5499 
o|inlining procedure: k5499 
o|inlining procedure: k5530 
o|inlining procedure: k5574 
o|inlining procedure: k5574 
o|inlining procedure: k5623 
o|inlining procedure: k5623 
o|inlining procedure: k5664 
o|inlining procedure: k5664 
o|inlining procedure: k5717 
o|inlining procedure: k5717 
o|inlining procedure: k5758 
o|inlining procedure: k5758 
o|contracted procedure: "(eval.scm:459) fudge-argument-list212" 
o|inlining procedure: k7359 
o|inlining procedure: k7359 
o|inlining procedure: k7374 
o|inlining procedure: k7374 
o|inlining procedure: k7399 
o|inlining procedure: k7399 
o|inlining procedure: k5840 
o|inlining procedure: k5840 
o|substituted constant variable: a5865 
o|substituted constant variable: a5867 
o|substituted constant variable: a5869 
o|substituted constant variable: a5871 
o|substituted constant variable: a5873 
o|consed rest parameter at call site: "(eval.scm:394) chicken.eval#compile-to-closure" 3 
o|inlining procedure: k5902 
o|consed rest parameter at call site: "(eval.scm:394) chicken.eval#compile-to-closure" 3 
o|inlining procedure: k5902 
o|consed rest parameter at call site: "(eval.scm:394) chicken.eval#compile-to-closure" 3 
o|inlining procedure: k5922 
o|inlining procedure: k5922 
o|inlining procedure: k5975 
o|inlining procedure: k5975 
o|inlining procedure: k5530 
o|inlining procedure: k6090 
o|contracted procedure: "(eval.scm:474) g928937" 
o|inlining procedure: k6090 
o|inlining procedure: k6121 
o|inlining procedure: k6235 
o|inlining procedure: k6235 
o|inlining procedure: k6262 
o|contracted procedure: "(eval.scm:488) g963972" 
o|inlining procedure: k6262 
o|inlining procedure: k6121 
o|inlining procedure: k6352 
o|inlining procedure: k6352 
o|inlining procedure: k6382 
o|inlining procedure: k6382 
o|inlining procedure: k6496 
o|contracted procedure: "(eval.scm:545) g10491058" 
o|inlining procedure: k6496 
o|substituted constant variable: saved112411251143 
o|inlining procedure: k6527 
o|inlining procedure: k6632 
o|inlining procedure: k6655 
o|inlining procedure: k6655 
o|inlining procedure: k6632 
o|inlining procedure: k6751 
o|inlining procedure: k6751 
o|inlining procedure: k6778 
o|inlining procedure: k6778 
o|inlining procedure: k6808 
o|inlining procedure: k6808 
o|inlining procedure: k6527 
o|inlining procedure: k6864 
o|inlining procedure: k6864 
o|inlining procedure: k6901 
o|inlining procedure: k6901 
o|inlining procedure: k6948 
o|inlining procedure: k6948 
o|inlining procedure: k6973 
o|inlining procedure: k6973 
o|inlining procedure: k7009 
o|inlining procedure: k7009 
o|removed unused parameter to known procedure: se1298 "(eval.scm:644) compile-call214" 
o|inlining procedure: k7038 
o|inlining procedure: k7038 
o|inlining procedure: k7060 
o|inlining procedure: k7060 
o|removed unused parameter to known procedure: se1298 "(eval.scm:662) compile-call214" 
o|substituted constant variable: a7113 
o|substituted constant variable: a7115 
o|substituted constant variable: a7117 
o|inlining procedure: k7121 
o|inlining procedure: k7121 
o|inlining procedure: k7133 
o|inlining procedure: k7133 
o|inlining procedure: k7145 
o|inlining procedure: k7145 
o|inlining procedure: k7157 
o|inlining procedure: k7157 
o|inlining procedure: k7169 
o|inlining procedure: k7169 
o|substituted constant variable: a7176 
o|substituted constant variable: a7178 
o|substituted constant variable: a7180 
o|substituted constant variable: a7182 
o|substituted constant variable: a7184 
o|substituted constant variable: a7186 
o|substituted constant variable: a7188 
o|substituted constant variable: a7190 
o|substituted constant variable: a7192 
o|substituted constant variable: a7194 
o|substituted constant variable: a7196 
o|substituted constant variable: a7201 
o|substituted constant variable: a7203 
o|substituted constant variable: a7205 
o|inlining procedure: k7209 
o|inlining procedure: k7209 
o|substituted constant variable: a7216 
o|substituted constant variable: a7218 
o|substituted constant variable: a7220 
o|substituted constant variable: a7222 
o|substituted constant variable: a7227 
o|substituted constant variable: a7229 
o|substituted constant variable: a7231 
o|substituted constant variable: a7233 
o|substituted constant variable: a7235 
o|substituted constant variable: a7237 
o|substituted constant variable: a7239 
o|substituted constant variable: a7241 
o|substituted constant variable: a7243 
o|substituted constant variable: a7245 
o|substituted constant variable: a7247 
o|substituted constant variable: a7249 
o|substituted constant variable: a7251 
o|substituted constant variable: a7253 
o|substituted constant variable: a7255 
o|substituted constant variable: a7257 
o|substituted constant variable: a7259 
o|substituted constant variable: a7261 
o|substituted constant variable: a7263 
o|substituted constant variable: a7265 
o|substituted constant variable: a7267 
o|substituted constant variable: a7269 
o|substituted constant variable: a7271 
o|substituted constant variable: a7273 
o|substituted constant variable: a7275 
o|substituted constant variable: a7277 
o|substituted constant variable: a7279 
o|contracted procedure: "(eval.scm:208) handle-expansion-result210" 
o|inlining procedure: k3805 
o|inlining procedure: k3805 
o|inlining procedure: k4128 
o|removed unused parameter to known procedure: se1298 "(eval.scm:666) compile-call214" 
o|inlining procedure: k7329 
o|inlining procedure: k7329 
o|inlining procedure: k7338 
o|inlining procedure: k7338 
o|inlining procedure: k7350 
o|inlining procedure: k7350 
o|removed unused formal parameters: (se1298) 
o|inlining procedure: k7464 
o|inlining procedure: k7464 
o|inlining procedure: k7490 
o|inlining procedure: k7490 
o|inlining procedure: k7554 
o|inlining procedure: k7554 
o|inlining procedure: k7694 
o|inlining procedure: k7694 
o|inlining procedure: k7728 
o|inlining procedure: k7728 
o|substituted constant variable: a7760 
o|substituted constant variable: a7762 
o|substituted constant variable: a7764 
o|substituted constant variable: a7766 
o|substituted constant variable: a7768 
o|substituted constant variable: a7770 
o|contracted procedure: "(eval.scm:694) checked-length213" 
o|inlining procedure: k7420 
o|inlining procedure: k7420 
o|substituted constant variable: saved142014211435 
o|consed rest parameter at call site: "(eval.scm:740) chicken.eval#compile-to-closure" 3 
o|inlining procedure: k7992 
o|inlining procedure: k7992 
o|inlining procedure: k8014 
o|inlining procedure: k8014 
o|inlining procedure: k8091 
o|contracted procedure: "(eval.scm:850) g15811582" 
o|substituted constant variable: a8106 
o|inlining procedure: k8099 
o|inlining procedure: k8099 
o|inlining procedure: k8091 
o|inlining procedure: k8143 
o|inlining procedure: k8143 
o|substituted constant variable: a8159 
o|substituted constant variable: a8161 
o|inlining procedure: k8168 
o|inlining procedure: k8168 
o|substituted constant variable: a8184 
o|substituted constant variable: a8186 
o|removed side-effect free assignment to unused variable: chicken.load#partition 
o|removed side-effect free assignment to unused variable: chicken.load#span 
o|removed side-effect free assignment to unused variable: chicken.load#drop 
o|removed side-effect free assignment to unused variable: chicken.load#split-at 
o|removed side-effect free assignment to unused variable: chicken.load#append-map 
o|inlining procedure: k8571 
o|inlining procedure: k8571 
o|inlining procedure: k8602 
o|inlining procedure: k8602 
o|removed side-effect free assignment to unused variable: chicken.load#cons* 
o|removed side-effect free assignment to unused variable: chicken.load#concatenate 
o|removed side-effect free assignment to unused variable: chicken.load#first 
o|removed side-effect free assignment to unused variable: chicken.load#second 
o|removed side-effect free assignment to unused variable: chicken.load#third 
o|removed side-effect free assignment to unused variable: chicken.load#fourth 
o|removed side-effect free assignment to unused variable: chicken.load#fifth 
o|removed side-effect free assignment to unused variable: chicken.load#delete-duplicates 
o|removed side-effect free assignment to unused variable: chicken.load#alist-cons 
o|inlining procedure: k8819 
o|inlining procedure: k8819 
o|inlining procedure: k8811 
o|inlining procedure: k8811 
o|removed side-effect free assignment to unused variable: chicken.load#filter-map 
o|removed side-effect free assignment to unused variable: chicken.load#remove 
o|removed side-effect free assignment to unused variable: chicken.load#unzip1 
o|removed side-effect free assignment to unused variable: chicken.load#last 
o|removed side-effect free assignment to unused variable: chicken.load#list-index 
o|removed side-effect free assignment to unused variable: chicken.load#lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: chicken.load#lset-difference/eq? 
o|removed side-effect free assignment to unused variable: chicken.load#lset-union/eq? 
o|removed side-effect free assignment to unused variable: chicken.load#lset-intersection/eq? 
o|inlining procedure: k9210 
o|inlining procedure: k9210 
o|removed side-effect free assignment to unused variable: chicken.load#lset<=/eq? 
o|removed side-effect free assignment to unused variable: chicken.load#lset=/eq? 
o|removed side-effect free assignment to unused variable: chicken.load#length+ 
o|removed side-effect free assignment to unused variable: chicken.load#find 
o|removed side-effect free assignment to unused variable: chicken.load#find-tail 
o|removed side-effect free assignment to unused variable: chicken.load#iota 
o|removed side-effect free assignment to unused variable: chicken.load#make-list 
o|removed side-effect free assignment to unused variable: chicken.load#posq 
o|removed side-effect free assignment to unused variable: chicken.load#posv 
o|inlining procedure: k9487 
o|inlining procedure: k9487 
o|inlining procedure: k9523 
o|inlining procedure: k9523 
o|inlining procedure: k9551 
o|inlining procedure: k9551 
o|inlining procedure: k9567 
o|inlining procedure: k9567 
o|inlining procedure: k9607 
o|inlining procedure: k9630 
o|inlining procedure: k9630 
o|inlining procedure: k9644 
o|inlining procedure: k9644 
o|substituted constant variable: a9659 
o|substituted constant variable: a9661 
o|substituted constant variable: a9663 
o|substituted constant variable: a9665 
o|inlining procedure: k9607 
o|contracted procedure: "(eval.scm:1030) chicken.load#toplevel" 
o|inlining procedure: k9675 
o|inlining procedure: k9675 
o|merged explicitly consed rest parameter: rest22632266 
o|inlining procedure: k9740 
o|inlining procedure: k9740 
o|inlining procedure: k9758 
o|inlining procedure: k9758 
o|inlining procedure: k9796 
o|inlining procedure: k9796 
o|inlining procedure: k9847 
o|inlining procedure: k9847 
o|inlining procedure: k9869 
o|inlining procedure: k9869 
o|inlining procedure: k9903 
o|inlining procedure: k9920 
o|inlining procedure: k9920 
o|inlining procedure: k9903 
o|inlining procedure: k9957 
o|inlining procedure: k9957 
o|inlining procedure: k9978 
o|inlining procedure: k9978 
o|inlining procedure: k10005 
o|inlining procedure: k10005 
o|inlining procedure: k10026 
o|inlining procedure: k10026 
o|inlining procedure: k10044 
o|inlining procedure: k10044 
o|consed rest parameter at call site: "(eval.scm:1120) chicken.load#load/internal" 3 
o|inlining procedure: k10111 
o|consed rest parameter at call site: "(eval.scm:1120) chicken.load#load/internal" 3 
o|inlining procedure: k10111 
o|consed rest parameter at call site: "(eval.scm:1120) chicken.load#load/internal" 3 
o|consed rest parameter at call site: "(eval.scm:1124) chicken.load#load/internal" 3 
o|consed rest parameter at call site: "(eval.scm:1127) chicken.load#load/internal" 3 
o|propagated global variable: g24402441 ##sys#string-append 
o|inlining procedure: k10181 
o|inlining procedure: k10181 
o|inlining procedure: k10202 
o|inlining procedure: k10215 
o|inlining procedure: k10215 
o|inlining procedure: k10202 
o|inlining procedure: k10339 
o|inlining procedure: k10339 
o|inlining procedure: k10380 
o|inlining procedure: k10380 
o|inlining procedure: k10389 
o|inlining procedure: k10389 
o|inlining procedure: k10401 
o|inlining procedure: k10401 
o|inlining procedure: k10451 
o|inlining procedure: k10451 
o|inlining procedure: k10461 
o|inlining procedure: k10461 
o|inlining procedure: k10490 
o|inlining procedure: k10490 
o|inlining procedure: k10525 
o|inlining procedure: k10525 
o|inlining procedure: k10537 
o|inlining procedure: k10537 
o|consed rest parameter at call site: "(eval.scm:1241) chicken.load#load/internal" 3 
o|inlining procedure: k10589 
o|inlining procedure: k10589 
o|contracted procedure: "(eval.scm:1236) g25752576" 
o|inlining procedure: k10545 
o|inlining procedure: k10545 
o|inlining procedure: k10561 
o|inlining procedure: k10561 
o|inlining procedure: k10628 
o|contracted procedure: "(eval.scm:1249) g26122634" 
o|propagated global variable: g26422643 chicken.load#load-extension 
o|inlining procedure: k10628 
o|inlining procedure: k10651 
o|contracted procedure: "(eval.scm:1248) g26022619" 
o|inlining procedure: k10651 
o|inlining procedure: k10693 
o|contracted procedure: "(eval.scm:1253) g26652687" 
o|propagated global variable: g26952696 ##sys#provide 
o|inlining procedure: k10693 
o|inlining procedure: k10716 
o|contracted procedure: "(eval.scm:1252) g26552672" 
o|inlining procedure: k10716 
o|inlining procedure: k10753 
o|contracted procedure: "(eval.scm:1256) g27082715" 
o|inlining procedure: k10753 
o|inlining procedure: k10789 
o|inlining procedure: k10789 
o|inlining procedure: k10801 
o|inlining procedure: k10801 
o|inlining procedure: k10822 
o|inlining procedure: k10822 
o|inlining procedure: k10852 
o|inlining procedure: k10852 
o|inlining procedure: k10889 
o|inlining procedure: k10889 
o|inlining procedure: k10904 
o|inlining procedure: k10904 
o|inlining procedure: k10923 
o|inlining procedure: k10923 
o|inlining procedure: k10936 
o|inlining procedure: k10936 
o|inlining procedure: k10970 
o|inlining procedure: k10970 
o|inlining procedure: k11043 
o|inlining procedure: k11043 
o|inlining procedure: k11106 
o|inlining procedure: k11106 
o|propagated global variable: tmp29782980 last-error 
o|inlining procedure: k11262 
o|propagated global variable: tmp29782980 last-error 
o|inlining procedure: k11262 
o|inlining procedure: k11281 
o|inlining procedure: k11281 
o|substituted constant variable: chicken.load#constant2152 
o|substituted constant variable: a11336 
o|substituted constant variable: chicken.load#constant2163 
o|inlining procedure: k11340 
o|substituted constant variable: chicken.load#constant2157 
o|propagated global variable: r1134111975 chicken.load#constant2157 
o|inlining procedure: k11340 
o|substituted constant variable: chicken.load#constant2170 
o|inlining procedure: k11349 
o|substituted constant variable: chicken.load#constant2170 
o|inlining procedure: k11349 
o|substituted constant variable: chicken.load#constant2170 
o|inlining procedure: k11470 
o|inlining procedure: k11470 
o|inlining procedure: k11507 
o|substituted constant variable: saved148914901499 
o|consed rest parameter at call site: "(eval.scm:774) chicken.eval#compile-to-closure" 3 
o|consed rest parameter at call site: "(eval.scm:775) chicken.eval#compile-to-closure" 3 
o|inlining procedure: k11507 
o|consed rest parameter at call site: "(eval.scm:778) chicken.eval#compile-to-closure" 3 
o|consed rest parameter at call site: "(eval.scm:764) chicken.eval#compile-to-closure" 3 
o|simplifications: ((if . 1)) 
o|replaced variables: 1953 
o|removed binding forms: 482 
o|substituted constant variable: r360611618 
o|substituted constant variable: r373411626 
o|removed call to pure procedure with unused result: "(eval.scm:100) chicken.base#void" 
o|substituted constant variable: r354111633 
o|substituted constant variable: r393211644 
o|substituted constant variable: r453511682 
o|substituted constant variable: r597611742 
o|substituted constant variable: r597611742 
o|removed call to pure procedure with unused result: "(eval.scm:210) chicken.base#void" 
o|inlining procedure: k3805 
o|converted assignments to bindings: (err1549) 
o|substituted constant variable: r809211828 
o|removed side-effect free assignment to unused variable: chicken.load#any 
o|removed side-effect free assignment to unused variable: chicken.load#filter 
o|removed side-effect free assignment to unused variable: chicken.load#list-tabulate 
o|removed side-effect free assignment to unused variable: chicken.load#constant2152 
o|removed side-effect free assignment to unused variable: chicken.load#constant2163 
o|removed side-effect free assignment to unused variable: chicken.load#constant2170 
o|substituted constant variable: r956811850 
o|substituted constant variable: r967611857 
o|contracted procedure: "(eval.scm:1109) g23642371" 
o|substituted constant variable: r995811877 
o|substituted constant variable: r995811877 
o|substituted constant variable: r997911880 
o|substituted constant variable: r1004511886 
o|substituted constant variable: r1011211887 
o|substituted constant variable: r1011211887 
o|substituted constant variable: r1021611902 
o|substituted constant variable: r1021611902 
o|inlining procedure: k10278 
o|substituted constant variable: r1038111908 
o|substituted constant variable: r1039011909 
o|substituted constant variable: r1046211916 
o|substituted constant variable: r1049111918 
o|substituted constant variable: r1052611919 
o|substituted constant variable: r1052611919 
o|substituted constant variable: r1052611921 
o|substituted constant variable: r1052611921 
o|converted assignments to bindings: (check2550) 
o|substituted constant variable: r1056211930 
o|contracted procedure: "(eval.scm:1257) chicken.load#every" 
o|substituted constant variable: r1093711957 
o|substituted constant variable: r1097111961 
o|substituted constant variable: r1097111961 
o|substituted constant variable: r1110711967 
o|propagated global variable: r1126311969 last-error 
o|substituted constant variable: r1126311971 
o|substituted constant variable: r1126311971 
o|converted assignments to bindings: (complete2433) 
o|substituted constant variable: chicken.load#constant2157 
o|substituted constant variable: r1135011978 
o|converted assignments to bindings: (strip1570) 
o|simplifications: ((let . 4)) 
o|replaced variables: 138 
o|removed binding forms: 1649 
o|removed conditional forms: 1 
o|contracted procedure: k3677 
o|removed unused formal parameters: (h274 cntr275) 
o|contracted procedure: k4146 
o|removed unused parameter to known procedure: h274 "(eval.scm:400) decorate209" 
o|removed unused parameter to known procedure: cntr275 "(eval.scm:400) decorate209" 
o|removed unused parameter to known procedure: h274 "(eval.scm:405) decorate209" 
o|removed unused parameter to known procedure: cntr275 "(eval.scm:405) decorate209" 
o|removed unused parameter to known procedure: h274 "(eval.scm:410) decorate209" 
o|removed unused parameter to known procedure: cntr275 "(eval.scm:410) decorate209" 
o|removed unused parameter to known procedure: h274 "(eval.scm:415) decorate209" 
o|removed unused parameter to known procedure: cntr275 "(eval.scm:415) decorate209" 
o|removed unused parameter to known procedure: h274 "(eval.scm:421) decorate209" 
o|removed unused parameter to known procedure: cntr275 "(eval.scm:421) decorate209" 
o|removed unused parameter to known procedure: h274 "(eval.scm:426) decorate209" 
o|removed unused parameter to known procedure: cntr275 "(eval.scm:426) decorate209" 
o|removed unused parameter to known procedure: h274 "(eval.scm:432) decorate209" 
o|removed unused parameter to known procedure: cntr275 "(eval.scm:432) decorate209" 
o|removed unused parameter to known procedure: h274 "(eval.scm:437) decorate209" 
o|removed unused parameter to known procedure: cntr275 "(eval.scm:437) decorate209" 
o|removed unused parameter to known procedure: h274 "(eval.scm:443) decorate209" 
o|removed unused parameter to known procedure: cntr275 "(eval.scm:443) decorate209" 
o|removed unused parameter to known procedure: h274 "(eval.scm:448) decorate209" 
o|removed unused parameter to known procedure: cntr275 "(eval.scm:448) decorate209" 
o|removed unused parameter to known procedure: h274 "(eval.scm:455) decorate209" 
o|removed unused parameter to known procedure: cntr275 "(eval.scm:455) decorate209" 
o|removed unused parameter to known procedure: h274 "(eval.scm:462) decorate209" 
o|removed unused parameter to known procedure: cntr275 "(eval.scm:462) decorate209" 
o|inlining procedure: k6335 
o|inlining procedure: k3811 
o|inlining procedure: k3811 
o|removed side-effect free assignment to unused variable: chicken.load#constant2157 
o|inlining procedure: k9616 
o|inlining procedure: k9616 
o|inlining procedure: k9616 
o|inlining procedure: k9616 
o|inlining procedure: k9703 
o|inlining procedure: k10032 
o|inlining procedure: k10032 
o|propagated global variable: r1126311969 last-error 
o|replaced variables: 4 
o|removed binding forms: 151 
o|contracted procedure: k4140 
o|substituted constant variable: r633612172 
o|substituted constant variable: r970412221 
o|substituted constant variable: r1003312227 
o|substituted constant variable: r1003312227 
o|replaced variables: 6 
o|removed binding forms: 16 
o|removed conditional forms: 2 
o|removed binding forms: 6 
o|simplifications: ((if . 53) (##core#call . 707) (let . 28)) 
o|  call simplifications:
o|    ##sys#check-structure
o|    ##sys#check-symbol	4
o|    ##sys#check-string
o|    scheme#call-with-current-continuation
o|    ##sys#size	3
o|    chicken.fixnum#fx<
o|    scheme#memq	3
o|    chicken.fixnum#fx>
o|    scheme#procedure?
o|    scheme#boolean?
o|    scheme#char?
o|    scheme#eof-object?	3
o|    scheme#string?	4
o|    scheme#vector?
o|    ##sys#void
o|    scheme#set-car!
o|    chicken.fixnum#fx=	2
o|    chicken.fixnum#fx-	3
o|    scheme#apply	7
o|    scheme#list	13
o|    ##sys#list	20
o|    ##sys#check-list	15
o|    chicken.fixnum#fx>=	2
o|    scheme#cddr	8
o|    scheme#car	29
o|    scheme#vector	12
o|    scheme#cdr	17
o|    scheme#length	2
o|    ##sys#cons	18
o|    scheme#caddr	8
o|    scheme#cdddr	4
o|    scheme#pair?	39
o|    scheme#cadddr	4
o|    scheme#cadr	34
o|    scheme#assq	6
o|    scheme#cons	64
o|    ##sys#setslot	28
o|    ##sys#immediate?
o|    scheme#not	28
o|    ##sys#make-structure	2
o|    ##sys#slot	140
o|    chicken.fixnum#fx+	6
o|    scheme#values	3
o|    ##sys#call-with-values	8
o|    ##sys#apply	4
o|    scheme#null?	33
o|    scheme#caar
o|    scheme#eq?	108
o|    scheme#symbol?	10
o|contracted procedure: k7836 
o|contracted procedure: k3578 
o|contracted procedure: k7830 
o|contracted procedure: k3581 
o|contracted procedure: k7824 
o|contracted procedure: k3584 
o|contracted procedure: k7818 
o|contracted procedure: k3587 
o|contracted procedure: k7812 
o|contracted procedure: k3590 
o|contracted procedure: k7806 
o|contracted procedure: k3593 
o|contracted procedure: k7800 
o|contracted procedure: k3596 
o|contracted procedure: k7794 
o|contracted procedure: k3599 
o|contracted procedure: k3608 
o|contracted procedure: k3634 
o|contracted procedure: k3624 
o|contracted procedure: k3689 
o|contracted procedure: k3713 
o|contracted procedure: k3717 
o|contracted procedure: k3721 
o|contracted procedure: k3736 
o|contracted procedure: k3757 
o|contracted procedure: k3742 
o|contracted procedure: k3749 
o|contracted procedure: k3753 
o|contracted procedure: k3767 
o|contracted procedure: k3771 
o|contracted procedure: k3784 
o|contracted procedure: k3788 
o|contracted procedure: k3547 
o|contracted procedure: k3543 
o|contracted procedure: k3553 
o|contracted procedure: k3838 
o|contracted procedure: k3856 
o|contracted procedure: k3868 
o|contracted procedure: k3897 
o|contracted procedure: k3893 
o|contracted procedure: k3900 
o|contracted procedure: k3946 
o|contracted procedure: k3913 
o|contracted procedure: k3919 
o|contracted procedure: k3925 
o|contracted procedure: k3938 
o|contracted procedure: k3934 
o|contracted procedure: k3952 
o|contracted procedure: k3961 
o|contracted procedure: k3967 
o|contracted procedure: k3980 
o|contracted procedure: k3976 
o|contracted procedure: k3986 
o|contracted procedure: k4003 
o|contracted procedure: k3999 
o|contracted procedure: k3995 
o|contracted procedure: k4009 
o|contracted procedure: k4030 
o|contracted procedure: k4026 
o|contracted procedure: k4022 
o|contracted procedure: k4018 
o|contracted procedure: k4056 
o|contracted procedure: k4064 
o|contracted procedure: k4072 
o|contracted procedure: k4080 
o|contracted procedure: k4098 
o|contracted procedure: k4111 
o|contracted procedure: k7323 
o|contracted procedure: k4122 
o|contracted procedure: k7319 
o|contracted procedure: k4131 
o|contracted procedure: k3821 
o|contracted procedure: k3802 
o|contracted procedure: k7285 
o|contracted procedure: k4152 
o|contracted procedure: k4164 
o|contracted procedure: k4173 
o|contracted procedure: k4181 
o|contracted procedure: k4189 
o|contracted procedure: k4197 
o|contracted procedure: k4205 
o|contracted procedure: k4213 
o|contracted procedure: k4221 
o|contracted procedure: k4243 
o|contracted procedure: k4249 
o|contracted procedure: k4252 
o|contracted procedure: k4260 
o|contracted procedure: k4267 
o|contracted procedure: k4273 
o|contracted procedure: k4280 
o|contracted procedure: k4286 
o|contracted procedure: k4294 
o|contracted procedure: k4334 
o|contracted procedure: k4320 
o|contracted procedure: k4327 
o|contracted procedure: k4338 
o|contracted procedure: k4342 
o|contracted procedure: k4348 
o|contracted procedure: k4351 
o|contracted procedure: k4354 
o|contracted procedure: k4360 
o|contracted procedure: k4369 
o|contracted procedure: k4376 
o|contracted procedure: k4382 
o|contracted procedure: k4400 
o|contracted procedure: k4404 
o|contracted procedure: k4436 
o|contracted procedure: k4432 
o|contracted procedure: k4428 
o|contracted procedure: k4440 
o|contracted procedure: k4444 
o|contracted procedure: k4456 
o|contracted procedure: k4469 
o|contracted procedure: k4476 
o|contracted procedure: k4482 
o|contracted procedure: k4485 
o|contracted procedure: k4506 
o|contracted procedure: k4531 
o|contracted procedure: k4547 
o|contracted procedure: k4537 
o|contracted procedure: k4564 
o|contracted procedure: k4582 
o|contracted procedure: k4588 
o|contracted procedure: k4591 
o|contracted procedure: k4594 
o|contracted procedure: k4597 
o|contracted procedure: k4608 
o|contracted procedure: k4611 
o|contracted procedure: k4617 
o|contracted procedure: k4629 
o|contracted procedure: k4645 
o|contracted procedure: k4641 
o|contracted procedure: k4657 
o|contracted procedure: k4663 
o|contracted procedure: k4682 
o|contracted procedure: k4678 
o|contracted procedure: k4698 
o|contracted procedure: k4706 
o|contracted procedure: k4712 
o|contracted procedure: k4721 
o|contracted procedure: k4737 
o|contracted procedure: k4733 
o|contracted procedure: k4757 
o|contracted procedure: k4765 
o|contracted procedure: k4773 
o|contracted procedure: k4779 
o|contracted procedure: k4788 
o|contracted procedure: k4807 
o|contracted procedure: k4803 
o|contracted procedure: k4831 
o|contracted procedure: k4839 
o|contracted procedure: k4847 
o|contracted procedure: k4855 
o|contracted procedure: k4858 
o|contracted procedure: k4867 
o|contracted procedure: k4887 
o|contracted procedure: k4896 
o|contracted procedure: k4899 
o|contracted procedure: k4906 
o|contracted procedure: k4910 
o|contracted procedure: k4917 
o|contracted procedure: k4926 
o|contracted procedure: k4929 
o|contracted procedure: k4932 
o|contracted procedure: k4940 
o|contracted procedure: k4948 
o|contracted procedure: k4990 
o|contracted procedure: k5017 
o|contracted procedure: k5020 
o|contracted procedure: k5023 
o|contracted procedure: k5031 
o|contracted procedure: k5039 
o|contracted procedure: k5051 
o|contracted procedure: k5073 
o|contracted procedure: k5069 
o|contracted procedure: k5054 
o|contracted procedure: k5057 
o|contracted procedure: k5065 
o|contracted procedure: k5082 
o|contracted procedure: k5085 
o|contracted procedure: k5102 
o|contracted procedure: k5114 
o|contracted procedure: k5098 
o|contracted procedure: k5094 
o|contracted procedure: k5125 
o|contracted procedure: k5153 
o|contracted procedure: k5149 
o|contracted procedure: k5145 
o|contracted procedure: k5162 
o|contracted procedure: k5184 
o|contracted procedure: k5134 
o|contracted procedure: k5138 
o|contracted procedure: k5180 
o|contracted procedure: k5165 
o|contracted procedure: k5168 
o|contracted procedure: k5176 
o|contracted procedure: k5196 
o|contracted procedure: k5218 
o|contracted procedure: k5111 
o|contracted procedure: k5214 
o|contracted procedure: k5199 
o|contracted procedure: k5202 
o|contracted procedure: k5210 
o|contracted procedure: k5227 
o|contracted procedure: k5230 
o|contracted procedure: k5233 
o|contracted procedure: k5236 
o|contracted procedure: k5242 
o|contracted procedure: k5245 
o|contracted procedure: k5251 
o|contracted procedure: k5262 
o|contracted procedure: k5286 
o|contracted procedure: k5298 
o|contracted procedure: k5282 
o|contracted procedure: k5278 
o|contracted procedure: k5258 
o|contracted procedure: k5309 
o|contracted procedure: k5329 
o|contracted procedure: k5325 
o|contracted procedure: k5321 
o|contracted procedure: k5374 
o|contracted procedure: k5338 
o|contracted procedure: k5364 
o|contracted procedure: k5368 
o|contracted procedure: k5360 
o|contracted procedure: k5341 
o|contracted procedure: k5344 
o|contracted procedure: k5352 
o|contracted procedure: k5356 
o|contracted procedure: k5422 
o|contracted procedure: k5386 
o|contracted procedure: k5412 
o|contracted procedure: k5416 
o|contracted procedure: k5295 
o|contracted procedure: k5408 
o|contracted procedure: k5389 
o|contracted procedure: k5392 
o|contracted procedure: k5400 
o|contracted procedure: k5404 
o|contracted procedure: k5434 
o|contracted procedure: k5456 
o|contracted procedure: k5271 
o|contracted procedure: k5452 
o|contracted procedure: k5437 
o|contracted procedure: k5440 
o|contracted procedure: k5448 
o|contracted procedure: k5468 
o|contracted procedure: k5471 
o|contracted procedure: k5474 
o|contracted procedure: k5482 
o|contracted procedure: k5490 
o|contracted procedure: k5502 
o|contracted procedure: k5524 
o|contracted procedure: k5520 
o|contracted procedure: k5505 
o|contracted procedure: k5508 
o|contracted procedure: k5516 
o|contracted procedure: k5533 
o|contracted procedure: k5539 
o|contracted procedure: k5544 
o|contracted procedure: k5556 
o|contracted procedure: k5559 
o|contracted procedure: k5568 
o|contracted procedure: k5577 
o|contracted procedure: k5599 
o|contracted procedure: k5595 
o|contracted procedure: k5614 
o|contracted procedure: k5620 
o|contracted procedure: k5642 
o|contracted procedure: k5638 
o|contracted procedure: k5661 
o|contracted procedure: k5657 
o|contracted procedure: k5667 
o|contracted procedure: k5689 
o|contracted procedure: k5685 
o|contracted procedure: k5708 
o|contracted procedure: k5704 
o|contracted procedure: k5714 
o|contracted procedure: k5736 
o|contracted procedure: k5732 
o|contracted procedure: k5755 
o|contracted procedure: k5751 
o|contracted procedure: k5761 
o|contracted procedure: k5783 
o|contracted procedure: k5779 
o|contracted procedure: k5798 
o|contracted procedure: k5820 
o|contracted procedure: k7362 
o|inlining procedure: k5828 
o|contracted procedure: k7377 
o|contracted procedure: k7384 
o|contracted procedure: k7380 
o|contracted procedure: k7391 
o|contracted procedure: k7395 
o|contracted procedure: k7402 
o|inlining procedure: k7399 
o|contracted procedure: k5861 
o|contracted procedure: k5843 
o|contracted procedure: k5853 
o|contracted procedure: k5925 
o|contracted procedure: k5928 
o|contracted procedure: k5931 
o|contracted procedure: k5939 
o|contracted procedure: k5947 
o|contracted procedure: k5985 
o|contracted procedure: k6022 
o|contracted procedure: k6040 
o|contracted procedure: k6074 
o|contracted procedure: k6077 
o|contracted procedure: k6093 
o|contracted procedure: k6115 
o|contracted procedure: k6049 
o|contracted procedure: k6111 
o|contracted procedure: k6096 
o|contracted procedure: k6099 
o|contracted procedure: k6107 
o|contracted procedure: k6071 
o|contracted procedure: k6124 
o|contracted procedure: k6127 
o|contracted procedure: k6157 
o|contracted procedure: k6160 
o|contracted procedure: k6175 
o|contracted procedure: k6178 
o|contracted procedure: k6215 
o|contracted procedure: k6238 
o|contracted procedure: k6248 
o|contracted procedure: k6252 
o|contracted procedure: k6265 
o|contracted procedure: k6287 
o|contracted procedure: k6136 
o|contracted procedure: k6283 
o|contracted procedure: k6268 
o|contracted procedure: k6271 
o|contracted procedure: k6279 
o|contracted procedure: k6154 
o|contracted procedure: k6296 
o|contracted procedure: k6299 
o|contracted procedure: k6302 
o|contracted procedure: k6345 
o|contracted procedure: k6335 
o|contracted procedure: k6355 
o|contracted procedure: k6364 
o|contracted procedure: k6375 
o|contracted procedure: k6385 
o|contracted procedure: k6392 
o|contracted procedure: k6396 
o|contracted procedure: k6446 
o|contracted procedure: k6424 
o|contracted procedure: k6439 
o|contracted procedure: k6452 
o|contracted procedure: k6459 
o|contracted procedure: k6470 
o|contracted procedure: k6473 
o|contracted procedure: k6490 
o|contracted procedure: k6486 
o|contracted procedure: k6499 
o|contracted procedure: k6502 
o|contracted procedure: k6505 
o|contracted procedure: k6513 
o|contracted procedure: k6521 
o|contracted procedure: k6530 
o|contracted procedure: k6536 
o|contracted procedure: k6840 
o|contracted procedure: k6539 
o|contracted procedure: k6626 
o|contracted procedure: k6635 
o|contracted procedure: k6658 
o|contracted procedure: k6664 
o|contracted procedure: k6670 
o|contracted procedure: k6696 
o|contracted procedure: k6700 
o|contracted procedure: k6746 
o|contracted procedure: k6754 
o|contracted procedure: k6766 
o|contracted procedure: k6775 
o|contracted procedure: k6793 
o|contracted procedure: k6784 
o|contracted procedure: k6799 
o|contracted procedure: k6811 
o|contracted procedure: k6814 
o|contracted procedure: k6817 
o|contracted procedure: k6825 
o|contracted procedure: k6833 
o|contracted procedure: k6846 
o|contracted procedure: k6861 
o|contracted procedure: k6853 
o|contracted procedure: k6867 
o|contracted procedure: k6882 
o|contracted procedure: k6878 
o|contracted procedure: k6874 
o|contracted procedure: k6888 
o|contracted procedure: k6898 
o|contracted procedure: k6904 
o|contracted procedure: k6907 
o|contracted procedure: k6920 
o|contracted procedure: k6910 
o|contracted procedure: k6932 
o|contracted procedure: k6935 
o|contracted procedure: k6945 
o|contracted procedure: k6951 
o|contracted procedure: k6958 
o|contracted procedure: k6964 
o|contracted procedure: k6976 
o|contracted procedure: k6988 
o|contracted procedure: k6991 
o|contracted procedure: k7006 
o|contracted procedure: k6998 
o|contracted procedure: k7012 
o|contracted procedure: k7024 
o|contracted procedure: k7031 
o|contracted procedure: k7041 
o|contracted procedure: k7048 
o|contracted procedure: k7054 
o|contracted procedure: k7057 
o|contracted procedure: k7069 
o|contracted procedure: k7083 
o|contracted procedure: k7086 
o|contracted procedure: k7118 
o|contracted procedure: k7124 
o|contracted procedure: k7130 
o|contracted procedure: k7136 
o|contracted procedure: k7142 
o|contracted procedure: k7148 
o|contracted procedure: k7154 
o|contracted procedure: k7160 
o|contracted procedure: k7166 
o|contracted procedure: k7206 
o|contracted procedure: k7281 
o|contracted procedure: k7326 
o|contracted procedure: k7335 
o|contracted procedure: k7347 
o|contracted procedure: k7446 
o|contracted procedure: k7452 
o|contracted procedure: k7461 
o|contracted procedure: k7467 
o|contracted procedure: k7476 
o|contracted procedure: k7493 
o|contracted procedure: k7515 
o|contracted procedure: k7521 
o|contracted procedure: k7551 
o|contracted procedure: k7557 
o|contracted procedure: k7595 
o|contracted procedure: k7601 
o|contracted procedure: k7647 
o|contracted procedure: k7650 
o|contracted procedure: k7658 
o|contracted procedure: k7677 
o|contracted procedure: k7685 
o|contracted procedure: k7697 
o|contracted procedure: k7700 
o|contracted procedure: k7703 
o|contracted procedure: k7711 
o|contracted procedure: k7719 
o|contracted procedure: k7731 
o|contracted procedure: k7734 
o|contracted procedure: k7737 
o|contracted procedure: k7745 
o|contracted procedure: k7753 
o|contracted procedure: k7423 
o|contracted procedure: k7429 
o|contracted procedure: k7436 
o|contracted procedure: k7440 
o|contracted procedure: k7771 
o|contracted procedure: k7780 
o|contracted procedure: k7787 
o|contracted procedure: k7995 
o|contracted procedure: k8008 
o|contracted procedure: k8025 
o|contracted procedure: k8031 
o|contracted procedure: k8041 
o|contracted procedure: k8053 
o|contracted procedure: k8045 
o|contracted procedure: k8049 
o|contracted procedure: k8059 
o|contracted procedure: k8082 
o|contracted procedure: k8094 
o|contracted procedure: k8114 
o|contracted procedure: k8103 
o|contracted procedure: k8122 
o|contracted procedure: k8125 
o|contracted procedure: k8128 
o|contracted procedure: k8131 
o|contracted procedure: k8134 
o|contracted procedure: k8146 
o|contracted procedure: k8152 
o|contracted procedure: k8171 
o|contracted procedure: k8177 
o|contracted procedure: k9484 
o|contracted procedure: k9507 
o|contracted procedure: k9542 
o|contracted procedure: k9517 
o|contracted procedure: k9531 
o|contracted procedure: k9538 
o|contracted procedure: k9554 
o|contracted procedure: k9564 
o|contracted procedure: k9571 
o|contracted procedure: k9577 
o|contracted procedure: k9666 
o|contracted procedure: k9595 
o|contracted procedure: k9610 
o|contracted procedure: k9613 
o|contracted procedure: k9623 
o|contracted procedure: k9626 
o|contracted procedure: k962312206 
o|contracted procedure: k9633 
o|contracted procedure: k962312210 
o|contracted procedure: k9640 
o|contracted procedure: k962312214 
o|contracted procedure: k9647 
o|contracted procedure: k962312218 
o|contracted procedure: k9655 
o|contracted procedure: k9678 
o|contracted procedure: k9689 
o|contracted procedure: k10102 
o|contracted procedure: k9709 
o|contracted procedure: k10096 
o|contracted procedure: k9712 
o|contracted procedure: k10090 
o|contracted procedure: k9715 
o|contracted procedure: k10084 
o|contracted procedure: k9718 
o|contracted procedure: k10078 
o|contracted procedure: k9721 
o|contracted procedure: k10072 
o|contracted procedure: k9724 
o|contracted procedure: k10066 
o|contracted procedure: k9727 
o|contracted procedure: k10060 
o|contracted procedure: k9730 
o|contracted procedure: k9734 
o|contracted procedure: k9764 
o|removed unused formal parameters: (abrt2321) 
o|contracted procedure: k9850 
o|contracted procedure: k9923 
o|contracted procedure: k9933 
o|contracted procedure: k9937 
o|contracted procedure: k9943 
o|removed unused parameter to known procedure: abrt2321 a9802 
o|contracted procedure: k9984 
o|contracted procedure: k10051 
o|contracted procedure: k10008 
o|contracted procedure: k10054 
o|contracted procedure: k10117 
o|contracted procedure: k10111 
o|contracted procedure: k10135 
o|contracted procedure: k10126 
o|contracted procedure: k10205 
o|contracted procedure: k10228 
o|contracted procedure: k10236 
o|contracted procedure: k10266 
o|contracted procedure: k10290 
o|contracted procedure: k10272 
o|contracted procedure: k10275 
o|contracted procedure: k10284 
o|contracted procedure: k10278 
o|contracted procedure: k10342 
o|contracted procedure: k10356 
o|contracted procedure: k10370 
o|contracted procedure: k10392 
o|contracted procedure: k10398 
o|contracted procedure: k10404 
o|contracted procedure: k10411 
o|contracted procedure: k10430 
o|contracted procedure: k10464 
o|contracted procedure: k10493 
o|contracted procedure: k10496 
o|contracted procedure: k10509 
o|contracted procedure: k10513 
o|contracted procedure: k10517 
o|contracted procedure: k10521 
o|contracted procedure: k10528 
o|contracted procedure: k10580 
o|contracted procedure: k10551 
o|contracted procedure: k10564 
o|contracted procedure: k10631 
o|contracted procedure: k10641 
o|contracted procedure: k10645 
o|contracted procedure: k10654 
o|contracted procedure: k10668 
o|contracted procedure: k10657 
o|contracted procedure: k10664 
o|contracted procedure: k10696 
o|contracted procedure: k10706 
o|contracted procedure: k10710 
o|contracted procedure: k10719 
o|contracted procedure: k10733 
o|contracted procedure: k10722 
o|contracted procedure: k10729 
o|contracted procedure: k8568 
o|contracted procedure: k8577 
o|contracted procedure: k8590 
o|contracted procedure: k10756 
o|contracted procedure: k10770 
o|contracted procedure: k10759 
o|contracted procedure: k10766 
o|contracted procedure: k10780 
o|contracted procedure: k10783 
o|contracted procedure: k10786 
o|contracted procedure: k10798 
o|contracted procedure: k10811 
o|contracted procedure: k10815 
o|contracted procedure: k10819 
o|contracted procedure: k10825 
o|contracted procedure: k10835 
o|contracted procedure: k10839 
o|contracted procedure: k10843 
o|contracted procedure: k10855 
o|contracted procedure: k10879 
o|contracted procedure: k10892 
o|contracted procedure: k10898 
o|inlining procedure: k10889 
o|contracted procedure: k10907 
o|inlining procedure: k10889 
o|contracted procedure: k10939 
o|contracted procedure: k10952 
o|contracted procedure: k10960 
o|contracted procedure: k11103 
o|contracted procedure: k11109 
o|contracted procedure: k11266 
o|contracted procedure: k11275 
o|contracted procedure: k11284 
o|contracted procedure: k11287 
o|contracted procedure: k11290 
o|contracted procedure: k11298 
o|contracted procedure: k11306 
o|contracted procedure: k11321 
o|contracted procedure: k11337 
o|contracted procedure: k11343 
o|contracted procedure: k11352 
o|contracted procedure: k11349 
o|contracted procedure: k11379 
o|contracted procedure: k11387 
o|contracted procedure: k11395 
o|contracted procedure: k11403 
o|contracted procedure: k11419 
o|contracted procedure: k11442 
o|contracted procedure: k11438 
o|contracted procedure: k11473 
o|contracted procedure: k11480 
o|contracted procedure: k11487 
o|contracted procedure: k11612 
o|contracted procedure: k11498 
o|contracted procedure: k11510 
o|contracted procedure: k11513 
o|contracted procedure: k11562 
o|contracted procedure: k11591 
o|contracted procedure: k11605 
o|contracted procedure: k11609 
o|contracted procedure: k11601 
o|simplifications: ((let . 231)) 
o|removed binding forms: 643 
(o x)|known list op on rest arg sublist: ##core#rest-length as908 0 
o|contracted procedure: "(eval.scm:1052) dload-path2282" 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest24002402 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest24002402 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest24122414 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest24122414 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest24942496 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest24942496 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest14661468 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest14661468 0 
o|simplifications: ((let . 1)) 
o|removed binding forms: 2 
o|replaced variables: 5 
o|removed binding forms: 1 
o|inlining procedure: k9779 
o|removed binding forms: 2 
o|replaced variables: 1 
o|removed binding forms: 1 
o|direct leaf routine/allocation: loop252 0 
o|direct leaf routine/allocation: emit-trace-info207 5 
o|direct leaf routine/allocation: g986999 0 
o|direct leaf routine/allocation: loop1103 0 
o|direct leaf routine/allocation: loop1286 0 
o|direct leaf routine/allocation: loop2218 0 
o|direct leaf routine/allocation: for-each-loop26012629 0 
o|direct leaf routine/allocation: for-each-loop26542682 0 
o|direct leaf routine/allocation: for-each-loop27072725 0 
o|direct leaf routine/allocation: store-string 0 
o|contracted procedure: k3695 
o|converted assignments to bindings: (loop252) 
o|contracted procedure: "(eval.scm:497) k6241" 
o|converted assignments to bindings: (loop1103) 
o|contracted procedure: k7455 
o|contracted procedure: "(eval.scm:700) k7481" 
o|contracted procedure: "(eval.scm:704) k7501" 
o|contracted procedure: "(eval.scm:709) k7532" 
o|contracted procedure: "(eval.scm:715) k7571" 
o|contracted procedure: "(eval.scm:722) k7618" 
o|contracted procedure: "(eval.scm:726) k7666" 
o|converted assignments to bindings: (loop1286) 
o|converted assignments to bindings: (loop2218) 
o|contracted procedure: k10614 
o|converted assignments to bindings: (for-each-loop26012629) 
o|contracted procedure: k10679 
o|converted assignments to bindings: (for-each-loop26542682) 
o|contracted procedure: k10744 
o|converted assignments to bindings: (for-each-loop27072725) 
o|simplifications: ((let . 7)) 
o|removed binding forms: 12 
o|direct leaf routine/allocation: for-each-loop9851002 0 
o|contracted procedure: k6181 
o|converted assignments to bindings: (for-each-loop9851002) 
o|simplifications: ((let . 1)) 
o|removed binding forms: 1 
o|customizable procedures: (doloop15361537 k11431 strip1570 k9477 k9497 complete2433 map-loop24442461 store-result run-safe test2770 loop2784 test-extensions2769 loop1781 for-each-loop26642697 for-each-loop26112644 g25922593 check2550 loop2559 chicken.load#file-exists? doloop25212522 k10187 loop2479 chicken.load#make-relative-pathname chicken.load#load/internal k10023 dload2283 a9802 for-each-loop23632375 doloop23532354 chicken.load#c-toplevel loop2237 chicken.load#path-separator-index/right foldr15761579 loop1551 err1549 g13541363 map-loop13481366 g13821391 map-loop13761394 emit-syntax-trace-info208 k6967 k7015 g12591260 compile-call214 g10861095 map-loop10801110 k6760 loop1163 loop21168 map-loop10431062 map-loop957975 map-loop922940 map-loop819836 doloop12771278 decorate209 map-loop651668 map-loop678695 map-loop708726 map-loop735756 map-loop768792 map-loop592610 map-loop619640 map-loop456474 map-loop484501 chicken.eval#compile-to-closure g557566 map-loop551569 doloop578579 compile211 k3889 k3862 lookup205 rename204 loop236 g245246 k3614 find-id203) 
o|calls to known targets: 317 
o|identified direct recursive calls: f_3731 1 
o|identified direct recursive calls: f_3684 1 
o|unused rest argument: v298 f_3833 
o|unused rest argument: v319 f_3882 
o|unused rest argument: v320 f_3887 
o|unused rest argument: v339 f_4059 
o|unused rest argument: v340 f_4067 
o|unused rest argument: v341 f_4075 
o|unused rest argument: v342 f_4083 
o|unused rest argument: v343 f_4085 
o|unused rest argument: v344 f_4104 
o|unused rest argument: v345 f_4106 
o|unused rest argument: v364 f_4117 
o|unused rest argument: v392 f_4176 
o|unused rest argument: v393 f_4184 
o|unused rest argument: v394 f_4192 
o|unused rest argument: v395 f_4200 
o|unused rest argument: v396 f_4208 
o|unused rest argument: v397 f_4216 
o|unused rest argument: v398 f_4224 
o|unused rest argument: v399 f_4226 
o|unused rest argument: v401 f_4255 
o|identified direct recursive calls: f_5046 1 
o|identified direct recursive calls: f_5157 1 
o|identified direct recursive calls: f_5191 1 
o|identified direct recursive calls: f_5333 1 
o|identified direct recursive calls: f_5381 1 
o|identified direct recursive calls: f_5429 1 
o|identified direct recursive calls: f_5497 1 
o|identified direct recursive calls: f_7372 1 
o|identified direct recursive calls: f_6233 1 
o|identified direct recursive calls: f_6773 1 
o|identified direct recursive calls: f_7418 1 
o|unused rest argument: _1301 f_7774 
o|identified direct recursive calls: f_7990 1 
o|identified direct recursive calls: f_8089 1 
o|identified direct recursive calls: f_9521 1 
o|identified direct recursive calls: f_9605 4 
o|unused rest argument: rest24002402 f_10109 
o|unused rest argument: rest24122414 f_10124 
o|unused rest argument: rest24942496 f_10270 
o|identified direct recursive calls: f_10649 1 
o|identified direct recursive calls: f_10714 1 
o|identified direct recursive calls: f_10751 1 
o|unused rest argument: rest14661468 f_11496 
o|fast box initializations: 48 
o|fast global references: 70 
o|fast global assignments: 30 
o|dropping unused closure argument: f_10378 
o|dropping unused closure argument: f_10649 
o|dropping unused closure argument: f_10714 
o|dropping unused closure argument: f_10751 
o|dropping unused closure argument: f_10979 
o|dropping unused closure argument: f_11038 
o|dropping unused closure argument: f_11101 
o|dropping unused closure argument: f_3576 
o|dropping unused closure argument: f_3761 
o|dropping unused closure argument: f_3775 
o|dropping unused closure argument: f_3792 
o|dropping unused closure argument: f_6773 
o|dropping unused closure argument: f_7418 
o|dropping unused closure argument: f_8080 
o|dropping unused closure argument: f_9511 
o|dropping unused closure argument: f_9546 
o|dropping unused closure argument: f_9693 
*/
/* end of file */
