/* Generated from port.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: port.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file port.c -emit-import-library chicken.port
   unit: port
   uses: extras library
*/
#include "chicken.h"



#if !defined(_WIN32)
# include <sys/ioctl.h>
# include <termios.h>
#endif

#if !defined(__ANDROID__) && defined(TIOCGWINSZ)
static int get_tty_size(int fd, int *rows, int *cols)
{
  struct winsize tty_size;
  int r;

  memset(&tty_size, 0, sizeof tty_size);

  r = ioctl(fd, TIOCGWINSZ, &tty_size);
  if (r == 0) {
     *rows = tty_size.ws_row;
     *cols = tty_size.ws_col;
  }
  return r;
}
#else
static int get_tty_size(int fd, int *rows, int *cols)
{
  *rows = *cols = 0;
  errno = ENOSYS;
  return -1;
}
#endif

#if defined(_WIN32) && !defined(__CYGWIN__)
char *ttyname(int fd) {
  errno = ENOSYS;
  return NULL;
}
#endif



static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[90];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,31),40,99,104,105,99,107,101,110,46,112,111,114,116,35,112,111,114,116,45,110,97,109,101,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,39),40,99,104,105,99,107,101,110,46,112,111,114,116,35,115,101,116,45,112,111,114,116,45,110,97,109,101,33,32,112,111,114,116,32,110,97,109,101,41,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,35),40,99,104,105,99,107,101,110,46,112,111,114,116,35,112,111,114,116,45,112,111,115,105,116,105,111,110,32,46,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,51),40,99,104,105,99,107,101,110,46,112,111,114,116,35,115,101,116,45,98,117,102,102,101,114,105,110,103,45,109,111,100,101,33,32,112,111,114,116,32,109,111,100,101,32,46,32,115,105,122,101,41,0,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,112,111,114,116,35,112,111,114,116,45,102,111,114,45,101,97,99,104,32,102,110,32,116,104,117,110,107,41,0,0,0};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,9),40,108,111,111,112,32,120,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,32),40,99,104,105,99,107,101,110,46,112,111,114,116,35,112,111,114,116,45,109,97,112,32,102,110,32,116,104,117,110,107,41};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,97,99,99,41,0,0,0,0,0,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,112,111,114,116,35,112,111,114,116,45,102,111,108,100,32,102,110,32,97,99,99,32,116,104,117,110,107,41,0,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,14),40,102,95,49,49,50,57,32,98,117,102,32,110,41,0,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,13),40,100,111,108,111,111,112,49,57,49,32,105,41,0,0,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,14),40,102,95,49,49,51,52,32,98,117,102,32,110,41,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,110,41};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,7),40,97,49,49,53,49,41,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,9),40,97,49,49,53,55,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,112,111,114,116,35,99,111,112,121,45,112,111,114,116,32,115,114,99,32,100,101,115,116,32,46,32,114,101,115,116,41};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,11),40,103,50,53,51,32,103,50,54,53,41,0,0,0,0,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,53,50,32,103,50,53,57,41,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,9),40,97,49,49,57,51,32,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,55,55,32,103,50,56,52,41,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,7),40,97,49,50,50,55,41,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,112,111,114,116,35,109,97,107,101,45,98,114,111,97,100,99,97,115,116,45,112,111,114,116,32,46,32,112,111,114,116,115,41,0,0,0,0,0,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,7),40,97,49,50,54,53,41,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,7),40,97,49,51,48,48,41,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,7),40,97,49,51,50,48,41,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,110,32,99,41,0,0,0,0,0,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,22),40,97,49,51,53,53,32,112,32,110,32,100,101,115,116,32,115,116,97,114,116,41,0,0};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,48),40,99,104,105,99,107,101,110,46,112,111,114,116,35,109,97,107,101,45,99,111,110,99,97,116,101,110,97,116,101,100,45,112,111,114,116,32,112,49,32,46,32,112,111,114,116,115,41};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,7),40,97,49,52,49,55,41,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,7),40,97,49,52,50,50,41,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,7),40,97,49,52,50,56,41,0};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,46),40,99,104,105,99,107,101,110,46,112,111,114,116,35,119,105,116,104,45,105,110,112,117,116,45,102,114,111,109,45,112,111,114,116,32,112,111,114,116,32,116,104,117,110,107,41,0,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,7),40,97,49,52,52,50,41,0};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,7),40,97,49,52,52,55,41,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,7),40,97,49,52,53,51,41,0};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,112,111,114,116,35,119,105,116,104,45,111,117,116,112,117,116,45,116,111,45,112,111,114,116,32,112,111,114,116,32,116,104,117,110,107,41,0,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,7),40,97,49,52,54,55,41,0};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,7),40,97,49,52,55,50,41,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,7),40,97,49,52,55,56,41,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,51),40,99,104,105,99,107,101,110,46,112,111,114,116,35,119,105,116,104,45,101,114,114,111,114,45,111,117,116,112,117,116,45,116,111,45,112,111,114,116,32,112,111,114,116,32,116,104,117,110,107,41,0,0,0,0,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,46),40,99,104,105,99,107,101,110,46,112,111,114,116,35,99,97,108,108,45,119,105,116,104,45,105,110,112,117,116,45,115,116,114,105,110,103,32,115,116,114,32,112,114,111,99,41,0,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,112,111,114,116,35,99,97,108,108,45,119,105,116,104,45,111,117,116,112,117,116,45,115,116,114,105,110,103,32,112,114,111,99,41,0,0,0,0,0};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,7),40,97,49,53,49,51,41,0};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,7),40,97,49,53,49,56,41,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,7),40,97,49,53,50,52,41,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,47),40,99,104,105,99,107,101,110,46,112,111,114,116,35,119,105,116,104,45,105,110,112,117,116,45,102,114,111,109,45,115,116,114,105,110,103,32,115,116,114,32,116,104,117,110,107,41,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,7),40,97,49,53,51,56,41,0};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,7),40,97,49,53,52,51,41,0};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,7),40,97,49,53,53,50,41,0};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,112,111,114,116,35,119,105,116,104,45,111,117,116,112,117,116,45,116,111,45,115,116,114,105,110,103,32,116,104,117,110,107,41,0,0,0,0,0,0};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,7),40,97,49,53,54,54,41,0};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,7),40,97,49,53,55,49,41,0};
static C_char C_TLS li57[] C_aligned={C_lihdr(0,0,7),40,97,49,53,56,48,41,0};
static C_char C_TLS li58[] C_aligned={C_lihdr(0,0,48),40,99,104,105,99,107,101,110,46,112,111,114,116,35,119,105,116,104,45,101,114,114,111,114,45,111,117,116,112,117,116,45,116,111,45,115,116,114,105,110,103,32,116,104,117,110,107,41};
static C_char C_TLS li59[] C_aligned={C_lihdr(0,0,9),40,97,49,54,50,52,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li60[] C_aligned={C_lihdr(0,0,9),40,97,49,54,52,53,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li61[] C_aligned={C_lihdr(0,0,11),40,97,49,54,54,54,32,112,32,100,41,0,0,0,0,0};
static C_char C_TLS li62[] C_aligned={C_lihdr(0,0,9),40,97,49,54,55,50,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li63[] C_aligned={C_lihdr(0,0,55),40,99,104,105,99,107,101,110,46,112,111,114,116,35,109,97,107,101,45,105,110,112,117,116,45,112,111,114,116,32,114,101,97,100,32,114,101,97,100,121,63,32,99,108,111,115,101,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li64[] C_aligned={C_lihdr(0,0,11),40,97,49,55,52,52,32,112,32,99,41,0,0,0,0,0};
static C_char C_TLS li65[] C_aligned={C_lihdr(0,0,11),40,97,49,55,53,52,32,112,32,115,41,0,0,0,0,0};
static C_char C_TLS li66[] C_aligned={C_lihdr(0,0,11),40,97,49,55,54,48,32,112,32,100,41,0,0,0,0,0};
static C_char C_TLS li67[] C_aligned={C_lihdr(0,0,9),40,97,49,55,54,54,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li68[] C_aligned={C_lihdr(0,0,50),40,99,104,105,99,107,101,110,46,112,111,114,116,35,109,97,107,101,45,111,117,116,112,117,116,45,112,111,114,116,32,119,114,105,116,101,32,99,108,111,115,101,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li69[] C_aligned={C_lihdr(0,0,9),40,97,49,55,57,55,32,95,41,0,0,0,0,0,0,0};
static C_char C_TLS li70[] C_aligned={C_lihdr(0,0,9),40,97,49,56,48,51,32,95,41,0,0,0,0,0,0,0};
static C_char C_TLS li71[] C_aligned={C_lihdr(0,0,11),40,97,49,56,48,57,32,95,32,99,41,0,0,0,0,0};
static C_char C_TLS li72[] C_aligned={C_lihdr(0,0,11),40,97,49,56,49,53,32,95,32,115,41,0,0,0,0,0};
static C_char C_TLS li73[] C_aligned={C_lihdr(0,0,11),40,97,49,56,50,49,32,95,32,100,41,0,0,0,0,0};
static C_char C_TLS li74[] C_aligned={C_lihdr(0,0,9),40,97,49,56,52,54,32,95,41,0,0,0,0,0,0,0};
static C_char C_TLS li75[] C_aligned={C_lihdr(0,0,9),40,97,49,56,53,50,32,95,41,0,0,0,0,0,0,0};
static C_char C_TLS li76[] C_aligned={C_lihdr(0,0,15),40,97,49,56,53,56,32,95,32,110,32,100,32,115,41,0};
static C_char C_TLS li77[] C_aligned={C_lihdr(0,0,11),40,97,49,56,54,52,32,95,32,108,41,0,0,0,0,0};
static C_char C_TLS li78[] C_aligned={C_lihdr(0,0,7),40,97,49,56,55,48,41,0};
static C_char C_TLS li79[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,112,111,114,116,35,109,97,107,101,45,98,105,100,105,114,101,99,116,105,111,110,97,108,45,112,111,114,116,32,105,32,111,41,0,0,0,0,0,0};
static C_char C_TLS li80[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,112,111,114,116,35,112,111,115,105,120,45,101,114,114,111,114,32,116,121,112,101,32,108,111,99,32,109,115,103,32,97,114,103,115,41,0,0,0,0};
static C_char C_TLS li81[] C_aligned={C_lihdr(0,0,34),40,99,104,105,99,107,101,110,46,112,111,114,116,35,116,101,114,109,105,110,97,108,45,112,111,114,116,63,32,112,111,114,116,41,0,0,0,0,0,0};
static C_char C_TLS li82[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,112,111,114,116,35,99,104,101,99,107,45,116,101,114,109,105,110,97,108,33,32,99,97,108,108,101,114,32,112,111,114,116,41,0,0,0,0,0,0};
static C_char C_TLS li83[] C_aligned={C_lihdr(0,0,33),40,99,104,105,99,107,101,110,46,112,111,114,116,35,116,101,114,109,105,110,97,108,45,110,97,109,101,32,112,111,114,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li84[] C_aligned={C_lihdr(0,0,33),40,99,104,105,99,107,101,110,46,112,111,114,116,35,116,101,114,109,105,110,97,108,45,115,105,122,101,32,112,111,114,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li85[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


/* from k1980 */
C_regparm static C_word C_fcall stub551(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
int *t1=(int *)C_c_pointer_nn(C_a1);
int *t2=(int *)C_c_pointer_nn(C_a2);
C_r=C_fix((C_word)get_tty_size(t0,t1,t2));
return C_r;}

/* from k1950 */
C_regparm static C_word C_fcall stub537(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_mpointer(&C_a,(void*)ttyname(t0));
return C_r;}

/* from k1884 */
C_regparm static C_word C_fcall stub515(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_mpointer(&C_a,(void*)strerror(t0));
return C_r;}

#define return(x) C_cblock C_r = (C_fix((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub144(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word p=(C_word )(C_a0);
int m=(int )C_unfix(C_a1);
int s=(int )C_unfix(C_a2);
C_return(setvbuf(C_port_file(p), NULL, m, s));
C_ret:
#undef return

return C_r;}

C_noret_decl(f2127)
static void C_ccall f2127(C_word c,C_word *av) C_noret;
C_noret_decl(f_1004)
static void C_ccall f_1004(C_word c,C_word *av) C_noret;
C_noret_decl(f_1027)
static void C_fcall f_1027(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1031)
static void C_ccall f_1031(C_word c,C_word *av) C_noret;
C_noret_decl(f_1040)
static void C_ccall f_1040(C_word c,C_word *av) C_noret;
C_noret_decl(f_1049)
static void C_ccall f_1049(C_word c,C_word *av) C_noret;
C_noret_decl(f_1054)
static void C_fcall f_1054(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1058)
static void C_fcall f_1058(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1061)
static void C_ccall f_1061(C_word c,C_word *av) C_noret;
C_noret_decl(f_1096)
static void C_ccall f_1096(C_word c,C_word *av) C_noret;
C_noret_decl(f_1099)
static void C_ccall f_1099(C_word c,C_word *av) C_noret;
C_noret_decl(f_1129)
static void C_ccall f_1129(C_word c,C_word *av) C_noret;
C_noret_decl(f_1134)
static void C_ccall f_1134(C_word c,C_word *av) C_noret;
C_noret_decl(f_1152)
static void C_fcall f_1152(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1158)
static void C_fcall f_1158(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1188)
static void C_ccall f_1188(C_word c,C_word *av) C_noret;
C_noret_decl(f_1194)
static void C_ccall f_1194(C_word c,C_word *av) C_noret;
C_noret_decl(f_1196)
static void C_fcall f_1196(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1205)
static void C_fcall f_1205(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1215)
static void C_ccall f_1215(C_word c,C_word *av) C_noret;
C_noret_decl(f_1228)
static void C_ccall f_1228(C_word c,C_word *av) C_noret;
C_noret_decl(f_1234)
static void C_fcall f_1234(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1244)
static void C_ccall f_1244(C_word c,C_word *av) C_noret;
C_noret_decl(f_1257)
static void C_ccall f_1257(C_word c,C_word *av) C_noret;
C_noret_decl(f_1266)
static void C_ccall f_1266(C_word c,C_word *av) C_noret;
C_noret_decl(f_1272)
static void C_fcall f_1272(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1282)
static void C_ccall f_1282(C_word c,C_word *av) C_noret;
C_noret_decl(f_1301)
static void C_ccall f_1301(C_word c,C_word *av) C_noret;
C_noret_decl(f_1321)
static void C_ccall f_1321(C_word c,C_word *av) C_noret;
C_noret_decl(f_1327)
static void C_fcall f_1327(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1337)
static void C_ccall f_1337(C_word c,C_word *av) C_noret;
C_noret_decl(f_1356)
static void C_ccall f_1356(C_word c,C_word *av) C_noret;
C_noret_decl(f_1362)
static void C_fcall f_1362(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1378)
static void C_ccall f_1378(C_word c,C_word *av) C_noret;
C_noret_decl(f_1409)
static void C_ccall f_1409(C_word c,C_word *av) C_noret;
C_noret_decl(f_1418)
static void C_ccall f_1418(C_word c,C_word *av) C_noret;
C_noret_decl(f_1423)
static void C_ccall f_1423(C_word c,C_word *av) C_noret;
C_noret_decl(f_1429)
static void C_ccall f_1429(C_word c,C_word *av) C_noret;
C_noret_decl(f_1434)
static void C_ccall f_1434(C_word c,C_word *av) C_noret;
C_noret_decl(f_1443)
static void C_ccall f_1443(C_word c,C_word *av) C_noret;
C_noret_decl(f_1448)
static void C_ccall f_1448(C_word c,C_word *av) C_noret;
C_noret_decl(f_1454)
static void C_ccall f_1454(C_word c,C_word *av) C_noret;
C_noret_decl(f_1459)
static void C_ccall f_1459(C_word c,C_word *av) C_noret;
C_noret_decl(f_1468)
static void C_ccall f_1468(C_word c,C_word *av) C_noret;
C_noret_decl(f_1473)
static void C_ccall f_1473(C_word c,C_word *av) C_noret;
C_noret_decl(f_1479)
static void C_ccall f_1479(C_word c,C_word *av) C_noret;
C_noret_decl(f_1484)
static void C_ccall f_1484(C_word c,C_word *av) C_noret;
C_noret_decl(f_1488)
static void C_ccall f_1488(C_word c,C_word *av) C_noret;
C_noret_decl(f_1493)
static void C_ccall f_1493(C_word c,C_word *av) C_noret;
C_noret_decl(f_1497)
static void C_ccall f_1497(C_word c,C_word *av) C_noret;
C_noret_decl(f_1500)
static void C_ccall f_1500(C_word c,C_word *av) C_noret;
C_noret_decl(f_1505)
static void C_ccall f_1505(C_word c,C_word *av) C_noret;
C_noret_decl(f_1509)
static void C_ccall f_1509(C_word c,C_word *av) C_noret;
C_noret_decl(f_1514)
static void C_ccall f_1514(C_word c,C_word *av) C_noret;
C_noret_decl(f_1519)
static void C_ccall f_1519(C_word c,C_word *av) C_noret;
C_noret_decl(f_1525)
static void C_ccall f_1525(C_word c,C_word *av) C_noret;
C_noret_decl(f_1530)
static void C_ccall f_1530(C_word c,C_word *av) C_noret;
C_noret_decl(f_1534)
static void C_ccall f_1534(C_word c,C_word *av) C_noret;
C_noret_decl(f_1539)
static void C_ccall f_1539(C_word c,C_word *av) C_noret;
C_noret_decl(f_1544)
static void C_ccall f_1544(C_word c,C_word *av) C_noret;
C_noret_decl(f_1548)
static void C_ccall f_1548(C_word c,C_word *av) C_noret;
C_noret_decl(f_1553)
static void C_ccall f_1553(C_word c,C_word *av) C_noret;
C_noret_decl(f_1558)
static void C_ccall f_1558(C_word c,C_word *av) C_noret;
C_noret_decl(f_1562)
static void C_ccall f_1562(C_word c,C_word *av) C_noret;
C_noret_decl(f_1567)
static void C_ccall f_1567(C_word c,C_word *av) C_noret;
C_noret_decl(f_1572)
static void C_ccall f_1572(C_word c,C_word *av) C_noret;
C_noret_decl(f_1576)
static void C_ccall f_1576(C_word c,C_word *av) C_noret;
C_noret_decl(f_1581)
static void C_ccall f_1581(C_word c,C_word *av) C_noret;
C_noret_decl(f_1586)
static void C_ccall f_1586(C_word c,C_word *av) C_noret;
C_noret_decl(f_1620)
static void C_ccall f_1620(C_word c,C_word *av) C_noret;
C_noret_decl(f_1623)
static void C_ccall f_1623(C_word c,C_word *av) C_noret;
C_noret_decl(f_1625)
static void C_ccall f_1625(C_word c,C_word *av) C_noret;
C_noret_decl(f_1646)
static void C_ccall f_1646(C_word c,C_word *av) C_noret;
C_noret_decl(f_1662)
static void C_ccall f_1662(C_word c,C_word *av) C_noret;
C_noret_decl(f_1667)
static void C_ccall f_1667(C_word c,C_word *av) C_noret;
C_noret_decl(f_1673)
static void C_ccall f_1673(C_word c,C_word *av) C_noret;
C_noret_decl(f_1727)
static void C_ccall f_1727(C_word c,C_word *av) C_noret;
C_noret_decl(f_1740)
static void C_ccall f_1740(C_word c,C_word *av) C_noret;
C_noret_decl(f_1743)
static void C_ccall f_1743(C_word c,C_word *av) C_noret;
C_noret_decl(f_1745)
static void C_ccall f_1745(C_word c,C_word *av) C_noret;
C_noret_decl(f_1755)
static void C_ccall f_1755(C_word c,C_word *av) C_noret;
C_noret_decl(f_1761)
static void C_ccall f_1761(C_word c,C_word *av) C_noret;
C_noret_decl(f_1767)
static void C_ccall f_1767(C_word c,C_word *av) C_noret;
C_noret_decl(f_1782)
static void C_ccall f_1782(C_word c,C_word *av) C_noret;
C_noret_decl(f_1789)
static void C_ccall f_1789(C_word c,C_word *av) C_noret;
C_noret_decl(f_1792)
static void C_ccall f_1792(C_word c,C_word *av) C_noret;
C_noret_decl(f_1798)
static void C_ccall f_1798(C_word c,C_word *av) C_noret;
C_noret_decl(f_1804)
static void C_ccall f_1804(C_word c,C_word *av) C_noret;
C_noret_decl(f_1810)
static void C_ccall f_1810(C_word c,C_word *av) C_noret;
C_noret_decl(f_1816)
static void C_ccall f_1816(C_word c,C_word *av) C_noret;
C_noret_decl(f_1822)
static void C_ccall f_1822(C_word c,C_word *av) C_noret;
C_noret_decl(f_1847)
static void C_ccall f_1847(C_word c,C_word *av) C_noret;
C_noret_decl(f_1853)
static void C_ccall f_1853(C_word c,C_word *av) C_noret;
C_noret_decl(f_1859)
static void C_ccall f_1859(C_word c,C_word *av) C_noret;
C_noret_decl(f_1865)
static void C_ccall f_1865(C_word c,C_word *av) C_noret;
C_noret_decl(f_1871)
static void C_ccall f_1871(C_word c,C_word *av) C_noret;
C_noret_decl(f_1887)
static void C_fcall f_1887(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_1891)
static void C_ccall f_1891(C_word c,C_word *av) C_noret;
C_noret_decl(f_1898)
static void C_ccall f_1898(C_word c,C_word *av) C_noret;
C_noret_decl(f_1902)
static void C_ccall f_1902(C_word c,C_word *av) C_noret;
C_noret_decl(f_1904)
static void C_ccall f_1904(C_word c,C_word *av) C_noret;
C_noret_decl(f_1910)
static void C_ccall f_1910(C_word c,C_word *av) C_noret;
C_noret_decl(f_1922)
static void C_fcall f_1922(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1953)
static void C_ccall f_1953(C_word c,C_word *av) C_noret;
C_noret_decl(f_1957)
static void C_ccall f_1957(C_word c,C_word *av) C_noret;
C_noret_decl(f_1960)
static void C_ccall f_1960(C_word c,C_word *av) C_noret;
C_noret_decl(f_1983)
static void C_ccall f_1983(C_word c,C_word *av) C_noret;
C_noret_decl(f_1987)
static void C_ccall f_1987(C_word c,C_word *av) C_noret;
C_noret_decl(f_2008)
static void C_ccall f_2008(C_word c,C_word *av) C_noret;
C_noret_decl(f_2012)
static void C_ccall f_2012(C_word c,C_word *av) C_noret;
C_noret_decl(f_735)
static void C_ccall f_735(C_word c,C_word *av) C_noret;
C_noret_decl(f_738)
static void C_ccall f_738(C_word c,C_word *av) C_noret;
C_noret_decl(f_740)
static void C_ccall f_740(C_word c,C_word *av) C_noret;
C_noret_decl(f_747)
static void C_ccall f_747(C_word c,C_word *av) C_noret;
C_noret_decl(f_758)
static void C_ccall f_758(C_word c,C_word *av) C_noret;
C_noret_decl(f_762)
static void C_ccall f_762(C_word c,C_word *av) C_noret;
C_noret_decl(f_770)
static void C_ccall f_770(C_word c,C_word *av) C_noret;
C_noret_decl(f_777)
static void C_ccall f_777(C_word c,C_word *av) C_noret;
C_noret_decl(f_802)
static void C_ccall f_802(C_word c,C_word *av) C_noret;
C_noret_decl(f_806)
static void C_ccall f_806(C_word c,C_word *av) C_noret;
C_noret_decl(f_812)
static void C_ccall f_812(C_word c,C_word *av) C_noret;
C_noret_decl(f_815)
static void C_ccall f_815(C_word c,C_word *av) C_noret;
C_noret_decl(f_821)
static void C_fcall f_821(C_word t0,C_word t1) C_noret;
C_noret_decl(f_878)
static void C_ccall f_878(C_word c,C_word *av) C_noret;
C_noret_decl(f_884)
static void C_fcall f_884(C_word t0,C_word t1) C_noret;
C_noret_decl(f_888)
static void C_ccall f_888(C_word c,C_word *av) C_noret;
C_noret_decl(f_897)
static void C_ccall f_897(C_word c,C_word *av) C_noret;
C_noret_decl(f_902)
static void C_ccall f_902(C_word c,C_word *av) C_noret;
C_noret_decl(f_908)
static void C_fcall f_908(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_912)
static void C_ccall f_912(C_word c,C_word *av) C_noret;
C_noret_decl(f_932)
static void C_ccall f_932(C_word c,C_word *av) C_noret;
C_noret_decl(f_934)
static void C_ccall f_934(C_word c,C_word *av) C_noret;
C_noret_decl(f_940)
static void C_fcall f_940(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_944)
static void C_ccall f_944(C_word c,C_word *av) C_noret;
C_noret_decl(f_957)
static void C_ccall f_957(C_word c,C_word *av) C_noret;
C_noret_decl(f_964)
static void C_ccall f_964(C_word c,C_word *av) C_noret;
C_noret_decl(f_969)
static void C_fcall f_969(C_word t0,C_word t1) C_noret;
C_noret_decl(f_973)
static void C_ccall f_973(C_word c,C_word *av) C_noret;
C_noret_decl(f_982)
static void C_ccall f_982(C_word c,C_word *av) C_noret;
C_noret_decl(f_994)
static void C_fcall f_994(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(C_port_toplevel)
C_externexport void C_ccall C_port_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_1027)
static void C_ccall trf_1027(C_word c,C_word *av) C_noret;
static void C_ccall trf_1027(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1027(t0,t1);}

C_noret_decl(trf_1054)
static void C_ccall trf_1054(C_word c,C_word *av) C_noret;
static void C_ccall trf_1054(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1054(t0,t1,t2);}

C_noret_decl(trf_1058)
static void C_ccall trf_1058(C_word c,C_word *av) C_noret;
static void C_ccall trf_1058(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1058(t0,t1);}

C_noret_decl(trf_1152)
static void C_ccall trf_1152(C_word c,C_word *av) C_noret;
static void C_ccall trf_1152(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1152(t0,t1);}

C_noret_decl(trf_1158)
static void C_ccall trf_1158(C_word c,C_word *av) C_noret;
static void C_ccall trf_1158(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1158(t0,t1,t2);}

C_noret_decl(trf_1196)
static void C_ccall trf_1196(C_word c,C_word *av) C_noret;
static void C_ccall trf_1196(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1196(t0,t1,t2);}

C_noret_decl(trf_1205)
static void C_ccall trf_1205(C_word c,C_word *av) C_noret;
static void C_ccall trf_1205(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1205(t0,t1,t2);}

C_noret_decl(trf_1234)
static void C_ccall trf_1234(C_word c,C_word *av) C_noret;
static void C_ccall trf_1234(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1234(t0,t1,t2);}

C_noret_decl(trf_1272)
static void C_ccall trf_1272(C_word c,C_word *av) C_noret;
static void C_ccall trf_1272(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1272(t0,t1);}

C_noret_decl(trf_1327)
static void C_ccall trf_1327(C_word c,C_word *av) C_noret;
static void C_ccall trf_1327(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1327(t0,t1);}

C_noret_decl(trf_1362)
static void C_ccall trf_1362(C_word c,C_word *av) C_noret;
static void C_ccall trf_1362(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1362(t0,t1,t2,t3);}

C_noret_decl(trf_1887)
static void C_ccall trf_1887(C_word c,C_word *av) C_noret;
static void C_ccall trf_1887(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_1887(t0,t1,t2,t3,t4);}

C_noret_decl(trf_1922)
static void C_ccall trf_1922(C_word c,C_word *av) C_noret;
static void C_ccall trf_1922(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1922(t0,t1,t2);}

C_noret_decl(trf_821)
static void C_ccall trf_821(C_word c,C_word *av) C_noret;
static void C_ccall trf_821(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_821(t0,t1);}

C_noret_decl(trf_884)
static void C_ccall trf_884(C_word c,C_word *av) C_noret;
static void C_ccall trf_884(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_884(t0,t1);}

C_noret_decl(trf_908)
static void C_ccall trf_908(C_word c,C_word *av) C_noret;
static void C_ccall trf_908(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_908(t0,t1,t2);}

C_noret_decl(trf_940)
static void C_ccall trf_940(C_word c,C_word *av) C_noret;
static void C_ccall trf_940(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_940(t0,t1,t2);}

C_noret_decl(trf_969)
static void C_ccall trf_969(C_word c,C_word *av) C_noret;
static void C_ccall trf_969(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_969(t0,t1);}

C_noret_decl(trf_994)
static void C_ccall trf_994(C_word c,C_word *av) C_noret;
static void C_ccall trf_994(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_994(t0,t1,t2);}

/* f2127 in chicken.port#port-name in k736 in k733 */
static void C_ccall f2127(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f2127,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_slot(((C_word*)t0)[3],C_fix(3));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k1002 in doloop191 */
static void C_ccall f_1004(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1004,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_994(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}

/* loop in chicken.port#copy-port in k736 in k733 */
static void C_fcall f_1027(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1027,2,t0,t1);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1031,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* port.scm:193: reader */
t3=((C_word*)t0)[4];
f_1152(t3,t2);}

/* k1029 in loop in chicken.port#copy-port in k736 in k733 */
static void C_ccall f_1031(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1031,c,av);}
a=C_alloc(4);
if(C_truep(C_eofp(t1))){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1040,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* port.scm:195: writer */
t3=((C_word*)t0)[4];
f_1158(t3,t2,t1);}}

/* k1038 in k1029 in loop in chicken.port#copy-port in k736 in k733 */
static void C_ccall f_1040(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1040,c,av);}
/* port.scm:196: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1027(t2,((C_word*)t0)[3]);}

/* k1047 in chicken.port#copy-port in k736 in k733 */
static void C_ccall f_1049(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1049,c,av);}
a=C_alloc(10);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1054,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t3,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word)li14),tmp=(C_word)a,a+=8,tmp));
t5=((C_word*)t3)[1];
f_1054(t5,((C_word*)t0)[5],C_fix(0));}

/* loop in k1047 in chicken.port#copy-port in k736 in k733 */
static void C_fcall f_1054(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,4)))){
C_save_and_reclaim_args((void *)trf_1054,3,t0,t1,t2);}
a=C_alloc(15);
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1058,a[2]=t3,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)t3)[1],C_fix(1024)))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1096,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* port.scm:201: chicken.io#write-string */
t6=*((C_word*)lf[28]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(1024);
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t5=t4;
f_1058(t5,C_SCHEME_UNDEFINED);}}

/* k1056 in loop in k1047 in chicken.port#copy-port in k736 in k733 */
static void C_fcall f_1058(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_1058,2,t0,t1);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1061,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* port.scm:203: reader */
t3=((C_word*)t0)[7];{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[8];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k1059 in k1056 in loop in k1047 in chicken.port#copy-port in k736 in k733 */
static void C_ccall f_1061(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1061,c,av);}
if(C_truep(C_eofp(t1))){
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[2])[1],C_fix(0)))){
/* port.scm:206: chicken.io#write-string */
t2=*((C_word*)lf[28]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)((C_word*)t0)[2])[1];
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}
else{
t2=C_fix(C_character_code(t1));
t3=C_setbyte(((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1],t2);
/* port.scm:209: loop */
t4=((C_word*)((C_word*)t0)[6])[1];
f_1054(t4,((C_word*)t0)[3],C_fixnum_plus(((C_word*)((C_word*)t0)[2])[1],C_fix(1)));}}

/* k1094 in loop in k1047 in chicken.port#copy-port in k736 in k733 */
static void C_ccall f_1096(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1096,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_fix(0));
t3=((C_word*)t0)[3];
f_1058(t3,t2);}

/* chicken.port#copy-port in k736 in k733 */
static void C_ccall f_1099(C_word c,C_word *av){
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
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,4)))){
C_save_and_reclaim((void *)f_1099,c,av);}
a=C_alloc(18);
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?((C_word*)t0)[2]:C_get_rest_arg(c,4,av,4,t0));
t6=C_rest_nullp(c,4);
t7=C_rest_nullp(c,5);
t8=(C_truep(t7)?((C_word*)t0)[3]:C_get_rest_arg(c,5,av,4,t0));
t9=C_rest_nullp(c,5);
t10=C_eqp(t5,((C_word*)t0)[2]);
if(C_truep(t10)){
t11=C_eqp(t8,((C_word*)t0)[3]);
t12=(C_truep(t11)?(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1129,a[2]=t3,a[3]=((C_word)li10),tmp=(C_word)a,a+=4,tmp):(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1134,a[2]=t8,a[3]=t3,a[4]=((C_word)li12),tmp=(C_word)a,a+=5,tmp));
t13=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_964,a[2]=t12,a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[30]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[30]+1);
av2[1]=t13;
av2[2]=C_fix(1024);
av2[3]=C_make_character(32);
tp(4,av2);}}
else{
t11=C_eqp(t8,((C_word*)t0)[3]);
if(C_truep(t11)){
t12=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1049,a[2]=t3,a[3]=t5,a[4]=t2,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[30]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[30]+1);
av2[1]=t12;
av2[2]=C_fix(1024);
av2[3]=C_make_character(32);
tp(4,av2);}}
else{
t12=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1152,a[2]=t5,a[3]=t2,a[4]=((C_word)li15),tmp=(C_word)a,a+=5,tmp);
t13=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1158,a[2]=t8,a[3]=t3,a[4]=((C_word)li16),tmp=(C_word)a,a+=5,tmp);
t14=C_SCHEME_UNDEFINED;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1027,a[2]=t15,a[3]=t13,a[4]=t12,a[5]=((C_word)li17),tmp=(C_word)a,a+=6,tmp));
t17=((C_word*)t15)[1];
f_1027(t17,t1);}}}

/* f_1129 in chicken.port#copy-port in k736 in k733 */
static void C_ccall f_1129(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1129,c,av);}
/* port.scm:216: chicken.io#write-string */
t4=*((C_word*)lf[28]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* f_1134 in chicken.port#copy-port in k736 in k733 */
static void C_ccall f_1134(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_1134,c,av);}
a=C_alloc(10);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_994,a[2]=t3,a[3]=t5,a[4]=t2,a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[3],a[7]=((C_word)li11),tmp=(C_word)a,a+=8,tmp));
t7=((C_word*)t5)[1];
f_994(t7,t1,C_fix(0));}

/* a1151 in chicken.port#copy-port in k736 in k733 */
static void C_fcall f_1152(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_1152,2,t0,t1);}
/* port.scm:222: read */
t2=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* a1157 in chicken.port#copy-port in k736 in k733 */
static void C_fcall f_1158(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_1158,3,t0,t1,t2);}
/* port.scm:223: write */
t3=((C_word*)t0)[2];{
C_word av2[4];
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
av2[3]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}

/* chicken.port#make-broadcast-port in k736 in k733 */
static void C_ccall f_1188(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +8,c,4)))){
C_save_and_reclaim((void*)f_1188,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+8);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1194,a[2]=t2,a[3]=((C_word)li21),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1228,a[2]=t2,a[3]=((C_word)li23),tmp=(C_word)a,a+=4,tmp);
/* port.scm:229: make-output-port */
t5=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=t3;
av2[3]=*((C_word*)lf[34]+1);
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* a1193 in chicken.port#make-broadcast-port in k736 in k733 */
static void C_ccall f_1194(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_1194,c,av);}
a=C_alloc(11);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1196,a[2]=t2,a[3]=((C_word)li19),tmp=(C_word)a,a+=4,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1205,a[2]=t5,a[3]=t3,a[4]=((C_word)li20),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_1205(t7,t1,((C_word*)t0)[2]);}

/* g253 in a1193 in chicken.port#make-broadcast-port in k736 in k733 */
static void C_fcall f_1196(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_1196,3,t0,t1,t2);}
t3=*((C_word*)lf[28]+1);
/* port.scm:230: g268 */
t4=*((C_word*)lf[28]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=C_SCHEME_FALSE;
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* for-each-loop252 in a1193 in chicken.port#make-broadcast-port in k736 in k733 */
static void C_fcall f_1205(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1205,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1215,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* port.scm:230: g253 */
t4=((C_word*)t0)[3];
f_1196(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k1213 in for-each-loop252 in a1193 in chicken.port#make-broadcast-port in k736 in k733 */
static void C_ccall f_1215(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1215,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_1205(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* a1227 in chicken.port#make-broadcast-port in k736 in k733 */
static void C_ccall f_1228(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_1228,c,av);}
a=C_alloc(6);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1234,a[2]=t3,a[3]=((C_word)li22),tmp=(C_word)a,a+=4,tmp));
t5=((C_word*)t3)[1];
f_1234(t5,t1,((C_word*)t0)[2]);}

/* for-each-loop277 in a1227 in chicken.port#make-broadcast-port in k736 in k733 */
static void C_fcall f_1234(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1234,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1244,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* port.scm:232: g278 */
t4=*((C_word*)lf[32]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k1242 in for-each-loop277 in a1227 in chicken.port#make-broadcast-port in k736 in k733 */
static void C_ccall f_1244(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1244,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_1234(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* chicken.port#make-concatenated-port in k736 in k733 */
static void C_ccall f_1257(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +21,c,6)))){
C_save_and_reclaim((void*)f_1257,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+21);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
t4=C_a_i_cons(&a,2,t2,t3);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1266,a[2]=t6,a[3]=((C_word)li26),tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1301,a[2]=t6,a[3]=((C_word)li27),tmp=(C_word)a,a+=4,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1321,a[2]=t6,a[3]=((C_word)li29),tmp=(C_word)a,a+=4,tmp);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1356,a[2]=t6,a[3]=((C_word)li31),tmp=(C_word)a,a+=4,tmp);
/* port.scm:237: make-input-port */
t11=*((C_word*)lf[39]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t11;
av2[1]=t1;
av2[2]=t7;
av2[3]=t8;
av2[4]=*((C_word*)lf[34]+1);
av2[5]=t9;
av2[6]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(7,av2);}}

/* a1265 in chicken.port#make-concatenated-port in k736 in k733 */
static void C_ccall f_1266(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_1266,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1272,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word)li25),tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_1272(t5,t1);}

/* loop in a1265 in chicken.port#make-concatenated-port in k736 in k733 */
static void C_fcall f_1272(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1272,2,t0,t1);}
a=C_alloc(5);
if(C_truep(C_i_nullp(((C_word*)((C_word*)t0)[2])[1]))){
t2=t1;{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_END_OF_FILE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1282,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* ##sys#read-char/port */
t3=*((C_word*)lf[36]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k1280 in loop in a1265 in chicken.port#make-concatenated-port in k736 in k733 */
static void C_ccall f_1282(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1282,c,av);}
if(C_truep(C_eofp(t1))){
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
/* port.scm:245: loop */
t4=((C_word*)((C_word*)t0)[3])[1];
f_1272(t4,((C_word*)t0)[4]);}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* a1300 in chicken.port#make-concatenated-port in k736 in k733 */
static void C_ccall f_1301(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1301,c,av);}
t2=C_i_nullp(((C_word*)((C_word*)t0)[2])[1]);
if(C_truep(C_i_not(t2))){
/* port.scm:249: scheme#char-ready? */
t3=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* a1320 in chicken.port#make-concatenated-port in k736 in k733 */
static void C_ccall f_1321(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_1321,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1327,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word)li28),tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_1327(t5,t1);}

/* loop in a1320 in chicken.port#make-concatenated-port in k736 in k733 */
static void C_fcall f_1327(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1327,2,t0,t1);}
a=C_alloc(5);
if(C_truep(C_i_nullp(((C_word*)((C_word*)t0)[2])[1]))){
t2=t1;{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_END_OF_FILE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1337,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* port.scm:255: scheme#peek-char */
t3=*((C_word*)lf[38]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k1335 in loop in a1320 in chicken.port#make-concatenated-port in k736 in k733 */
static void C_ccall f_1337(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1337,c,av);}
if(C_truep(C_eofp(t1))){
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
/* port.scm:258: loop */
t4=((C_word*)((C_word*)t0)[3])[1];
f_1327(t4,((C_word*)t0)[4]);}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* a1355 in chicken.port#make-concatenated-port in k736 in k733 */
static void C_ccall f_1356(C_word c,C_word *av){
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
C_word *a;
if(c!=6) C_bad_argc_2(c,6,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_1356,c,av);}
a=C_alloc(9);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1362,a[2]=((C_word*)t0)[2],a[3]=t7,a[4]=t4,a[5]=t5,a[6]=((C_word)li30),tmp=(C_word)a,a+=7,tmp));
t9=((C_word*)t7)[1];
f_1362(t9,t1,t3,C_fix(0));}

/* loop in a1355 in chicken.port#make-concatenated-port in k736 in k733 */
static void C_fcall f_1362(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,5)))){
C_save_and_reclaim_args((void *)trf_1362,4,t0,t1,t2,t3);}
a=C_alloc(7);
if(C_truep(C_i_nullp(((C_word*)((C_word*)t0)[2])[1]))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_fixnum_less_or_equal_p(t2,C_fix(0)))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1378,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* port.scm:265: chicken.io#read-string! */
t5=*((C_word*)lf[29]+1);{
C_word av2[6];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=((C_word*)t0)[4];
av2[4]=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
av2[5]=C_fixnum_plus(((C_word*)t0)[5],t3);
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}}}

/* k1376 in loop in a1355 in chicken.port#make-concatenated-port in k736 in k733 */
static void C_ccall f_1378(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1378,c,av);}
if(C_truep(C_fixnum_lessp(t1,((C_word*)t0)[2]))){
t2=C_i_cdr(((C_word*)((C_word*)t0)[3])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,t2);
/* port.scm:268: loop */
t4=((C_word*)((C_word*)t0)[4])[1];
f_1362(t4,((C_word*)t0)[5],C_fixnum_difference(((C_word*)t0)[2],t1),C_fixnum_plus(((C_word*)t0)[6],t1));}
else{
/* port.scm:268: loop */
t2=((C_word*)((C_word*)t0)[4])[1];
f_1362(t2,((C_word*)t0)[5],C_fixnum_difference(((C_word*)t0)[2],t1),C_fixnum_plus(((C_word*)t0)[6],t1));}}

/* chicken.port#with-input-from-port in k736 in k733 */
static void C_ccall f_1409(C_word c,C_word *av){
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
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,4)))){
C_save_and_reclaim((void *)f_1409,c,av);}
a=C_alloc(18);
t4=C_i_check_port_2(t2,C_fix(1),C_SCHEME_TRUE,lf[41]);
t5=t2;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_FALSE;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1418,a[2]=t8,a[3]=t6,a[4]=((C_word)li33),tmp=(C_word)a,a+=5,tmp);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1423,a[2]=t3,a[3]=((C_word)li34),tmp=(C_word)a,a+=4,tmp);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1429,a[2]=t6,a[3]=t8,a[4]=((C_word)li35),tmp=(C_word)a,a+=5,tmp);
/* port.scm:275: ##sys#dynamic-wind */
t12=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t12;
av2[1]=t1;
av2[2]=t9;
av2[3]=t10;
av2[4]=t11;
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}

/* a1417 in chicken.port#with-input-from-port in k736 in k733 */
static void C_ccall f_1418(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1418,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[3]+1));
t3=C_mutate((C_word*)lf[3]+1 /* (set! ##sys#standard-input ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a1422 in chicken.port#with-input-from-port in k736 in k733 */
static void C_ccall f_1423(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1423,c,av);}
/* port.scm:276: thunk */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a1428 in chicken.port#with-input-from-port in k736 in k733 */
static void C_ccall f_1429(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1429,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[3]+1));
t3=C_mutate((C_word*)lf[3]+1 /* (set! ##sys#standard-input ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.port#with-output-to-port in k736 in k733 */
static void C_ccall f_1434(C_word c,C_word *av){
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
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,4)))){
C_save_and_reclaim((void *)f_1434,c,av);}
a=C_alloc(18);
t4=C_i_check_port_2(t2,C_fix(2),C_SCHEME_TRUE,lf[44]);
t5=t2;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_FALSE;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1443,a[2]=t8,a[3]=t6,a[4]=((C_word)li37),tmp=(C_word)a,a+=5,tmp);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1448,a[2]=t3,a[3]=((C_word)li38),tmp=(C_word)a,a+=4,tmp);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1454,a[2]=t6,a[3]=t8,a[4]=((C_word)li39),tmp=(C_word)a,a+=5,tmp);
/* port.scm:280: ##sys#dynamic-wind */
t12=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t12;
av2[1]=t1;
av2[2]=t9;
av2[3]=t10;
av2[4]=t11;
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}

/* a1442 in chicken.port#with-output-to-port in k736 in k733 */
static void C_ccall f_1443(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1443,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[45]+1));
t3=C_mutate((C_word*)lf[45]+1 /* (set! ##sys#standard-output ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a1447 in chicken.port#with-output-to-port in k736 in k733 */
static void C_ccall f_1448(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1448,c,av);}
/* port.scm:281: thunk */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a1453 in chicken.port#with-output-to-port in k736 in k733 */
static void C_ccall f_1454(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1454,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[45]+1));
t3=C_mutate((C_word*)lf[45]+1 /* (set! ##sys#standard-output ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.port#with-error-output-to-port in k736 in k733 */
static void C_ccall f_1459(C_word c,C_word *av){
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
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,4)))){
C_save_and_reclaim((void *)f_1459,c,av);}
a=C_alloc(18);
t4=C_i_check_port_2(t2,C_fix(2),C_SCHEME_TRUE,lf[47]);
t5=t2;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_FALSE;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1468,a[2]=t8,a[3]=t6,a[4]=((C_word)li41),tmp=(C_word)a,a+=5,tmp);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1473,a[2]=t3,a[3]=((C_word)li42),tmp=(C_word)a,a+=4,tmp);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1479,a[2]=t6,a[3]=t8,a[4]=((C_word)li43),tmp=(C_word)a,a+=5,tmp);
/* port.scm:285: ##sys#dynamic-wind */
t12=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t12;
av2[1]=t1;
av2[2]=t9;
av2[3]=t10;
av2[4]=t11;
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}

/* a1467 in chicken.port#with-error-output-to-port in k736 in k733 */
static void C_ccall f_1468(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1468,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[48]+1));
t3=C_mutate((C_word*)lf[48]+1 /* (set! ##sys#standard-error ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a1472 in chicken.port#with-error-output-to-port in k736 in k733 */
static void C_ccall f_1473(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1473,c,av);}
/* port.scm:286: thunk */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a1478 in chicken.port#with-error-output-to-port in k736 in k733 */
static void C_ccall f_1479(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1479,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[48]+1));
t3=C_mutate((C_word*)lf[48]+1 /* (set! ##sys#standard-error ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.port#call-with-input-string in k736 in k733 */
static void C_ccall f_1484(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1484,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1488,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* port.scm:292: chicken.base#open-input-string */
t5=*((C_word*)lf[50]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k1486 in chicken.port#call-with-input-string in k736 in k733 */
static void C_ccall f_1488(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1488,c,av);}
/* port.scm:293: proc */
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

/* chicken.port#call-with-output-string in k736 in k733 */
static void C_ccall f_1493(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1493,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1497,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* port.scm:297: chicken.base#open-output-string */
t4=*((C_word*)lf[53]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k1495 in chicken.port#call-with-output-string in k736 in k733 */
static void C_ccall f_1497(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1497,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1500,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* port.scm:298: proc */
t3=((C_word*)t0)[3];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k1498 in k1495 in chicken.port#call-with-output-string in k736 in k733 */
static void C_ccall f_1500(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1500,c,av);}
/* port.scm:299: chicken.base#get-output-string */
t2=*((C_word*)lf[52]+1);{
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

/* chicken.port#with-input-from-string in k736 in k733 */
static void C_ccall f_1505(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1505,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1509,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* port.scm:303: chicken.base#open-input-string */
t5=*((C_word*)lf[50]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k1507 in chicken.port#with-input-from-string in k736 in k733 */
static void C_ccall f_1509(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,4)))){
C_save_and_reclaim((void *)f_1509,c,av);}
a=C_alloc(18);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1514,a[2]=t5,a[3]=t3,a[4]=((C_word)li47),tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1519,a[2]=((C_word*)t0)[2],a[3]=((C_word)li48),tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1525,a[2]=t3,a[3]=t5,a[4]=((C_word)li49),tmp=(C_word)a,a+=5,tmp);
/* port.scm:303: ##sys#dynamic-wind */
t9=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t9;
av2[1]=((C_word*)t0)[3];
av2[2]=t6;
av2[3]=t7;
av2[4]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}

/* a1513 in k1507 in chicken.port#with-input-from-string in k736 in k733 */
static void C_ccall f_1514(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1514,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[3]+1));
t3=C_mutate((C_word*)lf[3]+1 /* (set! ##sys#standard-input ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a1518 in k1507 in chicken.port#with-input-from-string in k736 in k733 */
static void C_ccall f_1519(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1519,c,av);}
/* port.scm:304: thunk */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a1524 in k1507 in chicken.port#with-input-from-string in k736 in k733 */
static void C_ccall f_1525(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1525,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[3]+1));
t3=C_mutate((C_word*)lf[3]+1 /* (set! ##sys#standard-input ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.port#with-output-to-string in k736 in k733 */
static void C_ccall f_1530(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1530,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1534,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* port.scm:308: chicken.base#open-output-string */
t4=*((C_word*)lf[53]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k1532 in chicken.port#with-output-to-string in k736 in k733 */
static void C_ccall f_1534(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,4)))){
C_save_and_reclaim((void *)f_1534,c,av);}
a=C_alloc(18);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1539,a[2]=t5,a[3]=t3,a[4]=((C_word)li51),tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1544,a[2]=((C_word*)t0)[2],a[3]=((C_word)li52),tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1553,a[2]=t3,a[3]=t5,a[4]=((C_word)li53),tmp=(C_word)a,a+=5,tmp);
/* port.scm:308: ##sys#dynamic-wind */
t9=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t9;
av2[1]=((C_word*)t0)[3];
av2[2]=t6;
av2[3]=t7;
av2[4]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}

/* a1538 in k1532 in chicken.port#with-output-to-string in k736 in k733 */
static void C_ccall f_1539(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1539,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[45]+1));
t3=C_mutate((C_word*)lf[45]+1 /* (set! ##sys#standard-output ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a1543 in k1532 in chicken.port#with-output-to-string in k736 in k733 */
static void C_ccall f_1544(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1544,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1548,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* port.scm:309: thunk */
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k1546 in a1543 in k1532 in chicken.port#with-output-to-string in k736 in k733 */
static void C_ccall f_1548(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1548,c,av);}
/* port.scm:310: chicken.base#get-output-string */
t2=*((C_word*)lf[52]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[45]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* a1552 in k1532 in chicken.port#with-output-to-string in k736 in k733 */
static void C_ccall f_1553(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1553,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[45]+1));
t3=C_mutate((C_word*)lf[45]+1 /* (set! ##sys#standard-output ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.port#with-error-output-to-string in k736 in k733 */
static void C_ccall f_1558(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1558,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1562,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* port.scm:314: chicken.base#open-output-string */
t4=*((C_word*)lf[53]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k1560 in chicken.port#with-error-output-to-string in k736 in k733 */
static void C_ccall f_1562(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,4)))){
C_save_and_reclaim((void *)f_1562,c,av);}
a=C_alloc(18);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1567,a[2]=t5,a[3]=t3,a[4]=((C_word)li55),tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1572,a[2]=((C_word*)t0)[2],a[3]=((C_word)li56),tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1581,a[2]=t3,a[3]=t5,a[4]=((C_word)li57),tmp=(C_word)a,a+=5,tmp);
/* port.scm:314: ##sys#dynamic-wind */
t9=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t9;
av2[1]=((C_word*)t0)[3];
av2[2]=t6;
av2[3]=t7;
av2[4]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}

/* a1566 in k1560 in chicken.port#with-error-output-to-string in k736 in k733 */
static void C_ccall f_1567(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1567,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[48]+1));
t3=C_mutate((C_word*)lf[48]+1 /* (set! ##sys#standard-error ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a1571 in k1560 in chicken.port#with-error-output-to-string in k736 in k733 */
static void C_ccall f_1572(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1572,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1576,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* port.scm:315: thunk */
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k1574 in a1571 in k1560 in chicken.port#with-error-output-to-string in k736 in k733 */
static void C_ccall f_1576(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1576,c,av);}
/* port.scm:316: chicken.base#get-output-string */
t2=*((C_word*)lf[52]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[48]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* a1580 in k1560 in chicken.port#with-error-output-to-string in k736 in k733 */
static void C_ccall f_1581(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1581,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[48]+1));
t3=C_mutate((C_word*)lf[48]+1 /* (set! ##sys#standard-error ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.port#make-input-port in k736 in k733 */
static void C_ccall f_1586(C_word c,C_word *av){
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
C_word t20;
C_word t21;
C_word t22;
C_word t23;
C_word t24;
C_word *a;
if(c<5) C_bad_min_argc_2(c,5,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(35,c,5)))){
C_save_and_reclaim((void *)f_1586,c,av);}
a=C_alloc(35);
t5=C_rest_nullp(c,5);
t6=(C_truep(t5)?C_SCHEME_FALSE:C_get_rest_arg(c,5,av,5,t0));
t7=C_rest_nullp(c,5);
t8=C_rest_nullp(c,6);
t9=(C_truep(t8)?C_SCHEME_FALSE:C_get_rest_arg(c,6,av,5,t0));
t10=C_rest_nullp(c,6);
t11=C_rest_nullp(c,7);
t12=(C_truep(t11)?C_SCHEME_FALSE:C_get_rest_arg(c,7,av,5,t0));
t13=C_rest_nullp(c,7);
t14=C_rest_nullp(c,8);
t15=(C_truep(t14)?C_SCHEME_FALSE:C_get_rest_arg(c,8,av,5,t0));
t16=C_rest_nullp(c,8);
t17=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1625,a[2]=t6,a[3]=t2,a[4]=((C_word)li59),tmp=(C_word)a,a+=5,tmp);
t18=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1646,a[2]=t6,a[3]=t2,a[4]=((C_word)li60),tmp=(C_word)a,a+=5,tmp);
t19=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1667,a[2]=t4,a[3]=((C_word)li61),tmp=(C_word)a,a+=4,tmp);
t20=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1673,a[2]=t3,a[3]=((C_word)li62),tmp=(C_word)a,a+=4,tmp);
t21=C_a_i_vector(&a,10,t17,t18,C_SCHEME_FALSE,C_SCHEME_FALSE,t19,C_SCHEME_FALSE,t20,t9,t12,t15);
t22=C_a_i_vector1(&a,1,C_SCHEME_FALSE);
t23=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1620,a[2]=t1,a[3]=t22,tmp=(C_word)a,a+=4,tmp);
/* port.scm:354: ##sys#make-port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[58]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[58]+1);
av2[1]=t23;
av2[2]=C_fix(1);
av2[3]=t21;
av2[4]=lf[59];
av2[5]=lf[60];
tp(6,av2);}}

/* k1618 in chicken.port#make-input-port in k736 in k733 */
static void C_ccall f_1620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_1620,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1623,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* port.scm:355: ##sys#set-port-data! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[57]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[57]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k1621 in k1618 in chicken.port#make-input-port in k736 in k733 */
static void C_ccall f_1623(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1623,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a1624 in chicken.port#make-input-port in k736 in k733 */
static void C_ccall f_1625(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1625,c,av);}
t3=C_slot(t2,C_fix(10));
if(C_truep(((C_word*)t0)[2])){
/* port.scm:330: read */
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}
else{
if(C_truep(t3)){
t4=C_i_set_i_slot(t2,C_fix(10),C_SCHEME_FALSE);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
/* port.scm:334: read */
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}}}

/* a1645 in chicken.port#make-input-port in k736 in k733 */
static void C_ccall f_1646(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1646,c,av);}
a=C_alloc(4);
t3=C_slot(t2,C_fix(10));
if(C_truep(((C_word*)t0)[2])){
/* port.scm:337: peek */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}
else{
if(C_truep(t3)){
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1662,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* port.scm:340: read */
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)C_fast_retrieve_proc(t5))(2,av2);}}}}

/* k1660 in a1645 in chicken.port#make-input-port in k736 in k733 */
static void C_ccall f_1662(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1662,c,av);}
t2=C_i_setslot(((C_word*)t0)[2],C_fix(10),t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a1666 in chicken.port#make-input-port in k736 in k733 */
static void C_ccall f_1667(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1667,c,av);}
/* port.scm:346: close */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* a1672 in chicken.port#make-input-port in k736 in k733 */
static void C_ccall f_1673(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1673,c,av);}
/* port.scm:349: ready? */
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* chicken.port#make-output-port in k736 in k733 */
static void C_ccall f_1727(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(32,c,5)))){
C_save_and_reclaim((void *)f_1727,c,av);}
a=C_alloc(32);
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,4,t0));
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1745,a[2]=t2,a[3]=((C_word)li64),tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1755,a[2]=t2,a[3]=((C_word)li65),tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1761,a[2]=t3,a[3]=((C_word)li66),tmp=(C_word)a,a+=4,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1767,a[2]=t5,a[3]=((C_word)li67),tmp=(C_word)a,a+=4,tmp);
t10=C_a_i_vector(&a,9,C_SCHEME_FALSE,C_SCHEME_FALSE,t6,t7,t8,t9,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE);
t11=C_a_i_vector1(&a,1,C_SCHEME_FALSE);
t12=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1740,a[2]=t1,a[3]=t11,tmp=(C_word)a,a+=4,tmp);
/* port.scm:376: ##sys#make-port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[58]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[58]+1);
av2[1]=t12;
av2[2]=C_fix(2);
av2[3]=t10;
av2[4]=lf[61];
av2[5]=lf[60];
tp(6,av2);}}

/* k1738 in chicken.port#make-output-port in k736 in k733 */
static void C_ccall f_1740(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_1740,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1743,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* port.scm:377: ##sys#set-port-data! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[57]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[57]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k1741 in k1738 in chicken.port#make-output-port in k736 in k733 */
static void C_ccall f_1743(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1743,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a1744 in chicken.port#make-output-port in k736 in k733 */
static void C_ccall f_1745(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(2,c,2)))){
C_save_and_reclaim((void *)f_1745,c,av);}
a=C_alloc(2);
t4=C_a_i_string(&a,1,t3);
/* port.scm:365: write */
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=t4;
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}

/* a1754 in chicken.port#make-output-port in k736 in k733 */
static void C_ccall f_1755(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1755,c,av);}
/* port.scm:367: write */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a1760 in chicken.port#make-output-port in k736 in k733 */
static void C_ccall f_1761(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1761,c,av);}
/* port.scm:369: close */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* a1766 in chicken.port#make-output-port in k736 in k733 */
static void C_ccall f_1767(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1767,c,av);}
if(C_truep(((C_word*)t0)[2])){
/* port.scm:371: flush */
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* chicken.port#make-bidirectional-port in k736 in k733 */
static void C_ccall f_1782(C_word c,C_word *av){
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
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(55,c,6)))){
C_save_and_reclaim((void *)f_1782,c,av);}
a=C_alloc(55);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1798,a[2]=t2,a[3]=((C_word)li69),tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1804,a[2]=t2,a[3]=((C_word)li70),tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1810,a[2]=t3,a[3]=((C_word)li71),tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1816,a[2]=t3,a[3]=((C_word)li72),tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1822,a[2]=t2,a[3]=t3,a[4]=((C_word)li73),tmp=(C_word)a,a+=5,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1847,a[2]=t3,a[3]=((C_word)li74),tmp=(C_word)a,a+=4,tmp);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1853,a[2]=t2,a[3]=((C_word)li75),tmp=(C_word)a,a+=4,tmp);
t11=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1859,a[2]=t2,a[3]=((C_word)li76),tmp=(C_word)a,a+=4,tmp);
t12=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1865,a[2]=t2,a[3]=((C_word)li77),tmp=(C_word)a,a+=4,tmp);
t13=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1871,a[2]=t2,a[3]=((C_word)li78),tmp=(C_word)a,a+=4,tmp);
t14=C_a_i_vector(&a,10,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13);
t15=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1789,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* port.scm:404: ##sys#make-port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[58]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[58]+1);
av2[1]=t15;
av2[2]=C_fix(3);
av2[3]=t14;
av2[4]=lf[68];
av2[5]=lf[69];
tp(6,av2);}}

/* k1787 in chicken.port#make-bidirectional-port in k736 in k733 */
static void C_ccall f_1789(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_1789,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1792,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_vector1(&a,1,C_SCHEME_FALSE);
/* port.scm:405: ##sys#set-port-data! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[57]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[57]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=t3;
tp(4,av2);}}

/* k1790 in k1787 in chicken.port#make-bidirectional-port in k736 in k733 */
static void C_ccall f_1792(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1792,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a1797 in chicken.port#make-bidirectional-port in k736 in k733 */
static void C_ccall f_1798(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1798,c,av);}
/* ##sys#read-char/port */
t3=*((C_word*)lf[36]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* a1803 in chicken.port#make-bidirectional-port in k736 in k733 */
static void C_ccall f_1804(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1804,c,av);}
/* port.scm:385: scheme#peek-char */
t3=*((C_word*)lf[38]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* a1809 in chicken.port#make-bidirectional-port in k736 in k733 */
static void C_ccall f_1810(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1810,c,av);}
/* ##sys#write-char/port */
t4=*((C_word*)lf[63]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* a1815 in chicken.port#make-bidirectional-port in k736 in k733 */
static void C_ccall f_1816(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1816,c,av);}
/* port.scm:389: chicken.io#write-string */
t4=*((C_word*)lf[28]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* a1821 in chicken.port#make-bidirectional-port in k736 in k733 */
static void C_ccall f_1822(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1822,c,av);}
switch(t3){
case C_fix(1):
/* port.scm:392: scheme#close-input-port */
t4=*((C_word*)lf[64]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}
case C_fix(2):
/* port.scm:393: scheme#close-output-port */
t4=*((C_word*)lf[65]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}
default:
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* a1846 in chicken.port#make-bidirectional-port in k736 in k733 */
static void C_ccall f_1847(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1847,c,av);}
/* port.scm:395: chicken.base#flush-output */
t3=*((C_word*)lf[32]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* a1852 in chicken.port#make-bidirectional-port in k736 in k733 */
static void C_ccall f_1853(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1853,c,av);}
/* port.scm:397: scheme#char-ready? */
t3=*((C_word*)lf[37]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* a1858 in chicken.port#make-bidirectional-port in k736 in k733 */
static void C_ccall f_1859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6;
C_word *a;
if(c!=6) C_bad_argc_2(c,6,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_1859,c,av);}
/* port.scm:399: chicken.io#read-string! */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
av2[4]=((C_word*)t0)[2];
av2[5]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(6,av2);}}

/* a1864 in chicken.port#make-bidirectional-port in k736 in k733 */
static void C_ccall f_1865(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1865,c,av);}
/* port.scm:401: chicken.io#read-line */
t4=*((C_word*)lf[66]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* a1870 in chicken.port#make-bidirectional-port in k736 in k733 */
static void C_ccall f_1871(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1871,c,av);}
/* port.scm:403: chicken.io#read-buffered */
t2=*((C_word*)lf[67]+1);{
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

/* chicken.port#posix-error in k736 in k733 */
static void C_fcall f_1887(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_1887,5,t1,t2,t3,t4,t5);}
a=C_alloc(7);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1891,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=t5,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* port.scm:413: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[75]+1));
C_word av2[2];
av2[0]=*((C_word*)lf[75]+1);
av2[1]=t6;
tp(2,av2);}}

/* k1889 in chicken.port#posix-error in k736 in k733 */
static void C_ccall f_1891(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_1891,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1898,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1902,a[2]=t2,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t1);
/* port.scm:410: ##sys#peek-c-string */
t6=*((C_word*)lf[74]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=stub515(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k1896 in k1889 in chicken.port#posix-error in k736 in k733 */
static void C_ccall f_1898(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_1898,c,av);}{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[71]+1);
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
av2[5]=((C_word*)t0)[5];
av2[6]=t1;
av2[7]=((C_word*)t0)[6];
C_apply(8,av2);}}

/* k1900 in k1889 in chicken.port#posix-error in k736 in k733 */
static void C_ccall f_1902(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1902,c,av);}
/* port.scm:415: string-append */
t2=*((C_word*)lf[72]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[73];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* chicken.port#terminal-port? in k736 in k733 */
static void C_ccall f_1904(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_1904,c,av);}
a=C_alloc(4);
t3=C_i_check_port_2(t2,C_fix(0),C_SCHEME_TRUE,lf[77]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1910,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* port.scm:420: ##sys#peek-unsigned-integer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[78]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[78]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=C_fix(0);
tp(4,av2);}}

/* k1908 in chicken.port#terminal-port? in k736 in k733 */
static void C_ccall f_1910(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1910,c,av);}
t2=C_eqp(C_fix(0),t1);
t3=C_i_not(t2);
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?C_tty_portp(((C_word*)t0)[3]):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.port#check-terminal! in k736 in k733 */
static void C_fcall f_1922(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_1922,3,t1,t2,t3);}
t4=C_i_check_port_2(t3,C_fix(0),C_SCHEME_TRUE,t2);
t5=C_slot(t3,C_fix(7));
t6=C_eqp(lf[15],t5);
t7=(C_truep(t6)?C_tty_portp(t3):C_SCHEME_FALSE);
if(C_truep(t7)){
t8=C_SCHEME_UNDEFINED;
t9=t1;{
C_word av2[2];
av2[0]=t9;
av2[1]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
/* port.scm:427: ##sys#error */
t8=*((C_word*)lf[9]+1);{
C_word av2[5];
av2[0]=t8;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[80];
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}}

/* chicken.port#terminal-name in k736 in k733 */
static void C_ccall f_1953(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1953,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1957,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* port.scm:432: check-terminal! */
f_1922(t3,lf[83],t2);}

/* k1955 in chicken.port#terminal-name in k736 in k733 */
static void C_ccall f_1957(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1957,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1960,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_port_fileno(((C_word*)t0)[3]);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* port.scm:430: ##sys#peek-c-string */
t6=*((C_word*)lf[74]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub537(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k1958 in k1955 in chicken.port#terminal-name in k736 in k733 */
static void C_ccall f_1960(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_1960,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* port.scm:434: posix-error */
f_1887(((C_word*)t0)[2],lf[82],lf[83],lf[84],C_a_i_list(&a,1,((C_word*)t0)[3]));}}

/* chicken.port#terminal-size in k736 in k733 */
static void C_ccall f_1983(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1983,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1987,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* port.scm:442: check-terminal! */
f_1922(t3,lf[86],t2);}

/* k1985 in chicken.port#terminal-size in k736 in k733 */
static void C_ccall f_1987(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,5)))){
C_save_and_reclaim((void *)f_1987,c,av);}
a=C_alloc(13);
t2=C_a_i_bytevector(&a,1,C_fix(1));
t3=C_a_i_bytevector(&a,1,C_fix(1));
t4=C_port_fileno(((C_word*)t0)[2]);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2008,a[2]=t4,a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=t3,a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
/* port.scm:446: ##sys#make-locative */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[88]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[88]+1);
av2[1]=t5;
av2[2]=t2;
av2[3]=C_fix(0);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[89];
tp(6,av2);}}

/* k2006 in k1985 in chicken.port#terminal-size in k736 in k733 */
static void C_ccall f_2008(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_2008,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2012,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* port.scm:447: ##sys#make-locative */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[88]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[88]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=C_fix(0);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[89];
tp(6,av2);}}

/* k2010 in k2006 in k1985 in chicken.port#terminal-size in k736 in k733 */
static void C_ccall f_2012(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_2012,c,av);}
a=C_alloc(3);
t2=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t3=C_i_foreign_pointer_argumentp(((C_word*)t0)[3]);
t4=C_i_foreign_pointer_argumentp(t1);
t5=C_eqp(C_fix(0),stub551(C_SCHEME_UNDEFINED,t2,t3,t4));
if(C_truep(t5)){
/* port.scm:448: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=C_fix((C_word)*((int *)C_data_pointer(((C_word*)t0)[5])));
av2[3]=C_fix((C_word)*((int *)C_data_pointer(((C_word*)t0)[6])));
C_values(4,av2);}}
else{
/* port.scm:449: posix-error */
f_1887(((C_word*)t0)[4],lf[82],lf[86],lf[87],C_a_i_list(&a,1,((C_word*)t0)[7]));}}

/* k733 */
static void C_ccall f_735(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_735,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_738,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

/* k736 in k733 */
static void C_ccall f_738(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(80,c,6)))){
C_save_and_reclaim((void *)f_738,c,av);}
a=C_alloc(80);
t2=C_mutate((C_word*)lf[2]+1 /* (set! chicken.port#port-name ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_740,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t3=C_mutate((C_word*)lf[6]+1 /* (set! chicken.port#set-port-name! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_758,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[8]+1 /* (set! chicken.port#port-position ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_770,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[12]+1 /* (set! chicken.port#set-buffering-mode! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_802,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[21]+1 /* (set! chicken.port#port-for-each ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_878,a[2]=((C_word)li5),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[22]+1 /* (set! chicken.port#port-map ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_902,a[2]=((C_word)li7),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[24]+1 /* (set! chicken.port#port-fold ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_934,a[2]=((C_word)li9),tmp=(C_word)a,a+=3,tmp));
t9=*((C_word*)lf[25]+1);
t10=*((C_word*)lf[26]+1);
t11=C_mutate((C_word*)lf[27]+1 /* (set! chicken.port#copy-port ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1099,a[2]=t9,a[3]=t10,a[4]=((C_word)li18),tmp=(C_word)a,a+=5,tmp));
t12=C_mutate((C_word*)lf[31]+1 /* (set! chicken.port#make-broadcast-port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1188,a[2]=((C_word)li24),tmp=(C_word)a,a+=3,tmp));
t13=C_mutate((C_word*)lf[35]+1 /* (set! chicken.port#make-concatenated-port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1257,a[2]=((C_word)li32),tmp=(C_word)a,a+=3,tmp));
t14=C_mutate((C_word*)lf[40]+1 /* (set! chicken.port#with-input-from-port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1409,a[2]=((C_word)li36),tmp=(C_word)a,a+=3,tmp));
t15=C_mutate((C_word*)lf[43]+1 /* (set! chicken.port#with-output-to-port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1434,a[2]=((C_word)li40),tmp=(C_word)a,a+=3,tmp));
t16=C_mutate((C_word*)lf[46]+1 /* (set! chicken.port#with-error-output-to-port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1459,a[2]=((C_word)li44),tmp=(C_word)a,a+=3,tmp));
t17=C_mutate((C_word*)lf[49]+1 /* (set! chicken.port#call-with-input-string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1484,a[2]=((C_word)li45),tmp=(C_word)a,a+=3,tmp));
t18=C_mutate((C_word*)lf[51]+1 /* (set! chicken.port#call-with-output-string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1493,a[2]=((C_word)li46),tmp=(C_word)a,a+=3,tmp));
t19=C_mutate((C_word*)lf[54]+1 /* (set! chicken.port#with-input-from-string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1505,a[2]=((C_word)li50),tmp=(C_word)a,a+=3,tmp));
t20=C_mutate((C_word*)lf[55]+1 /* (set! chicken.port#with-output-to-string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1530,a[2]=((C_word)li54),tmp=(C_word)a,a+=3,tmp));
t21=C_mutate((C_word*)lf[56]+1 /* (set! chicken.port#with-error-output-to-string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1558,a[2]=((C_word)li58),tmp=(C_word)a,a+=3,tmp));
t22=C_mutate((C_word*)lf[39]+1 /* (set! chicken.port#make-input-port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1586,a[2]=((C_word)li63),tmp=(C_word)a,a+=3,tmp));
t23=C_mutate((C_word*)lf[33]+1 /* (set! chicken.port#make-output-port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1727,a[2]=((C_word)li68),tmp=(C_word)a,a+=3,tmp));
t24=C_mutate((C_word*)lf[62]+1 /* (set! chicken.port#make-bidirectional-port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1782,a[2]=((C_word)li79),tmp=(C_word)a,a+=3,tmp));
t25=C_mutate(&lf[70] /* (set! chicken.port#posix-error ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1887,a[2]=((C_word)li80),tmp=(C_word)a,a+=3,tmp));
t26=C_mutate((C_word*)lf[76]+1 /* (set! chicken.port#terminal-port? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1904,a[2]=((C_word)li81),tmp=(C_word)a,a+=3,tmp));
t27=C_mutate(&lf[79] /* (set! chicken.port#check-terminal! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1922,a[2]=((C_word)li82),tmp=(C_word)a,a+=3,tmp));
t28=C_mutate((C_word*)lf[81]+1 /* (set! chicken.port#terminal-name ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1953,a[2]=((C_word)li83),tmp=(C_word)a,a+=3,tmp));
t29=C_mutate((C_word*)lf[85]+1 /* (set! chicken.port#terminal-size ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1983,a[2]=((C_word)li84),tmp=(C_word)a,a+=3,tmp));
t30=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t30;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t30+1)))(2,av2);}}

/* chicken.port#port-name in k736 in k733 */
static void C_ccall f_740(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_740,c,av);}
a=C_alloc(4);
if(C_truep(C_rest_nullp(c,2))){
t2=*((C_word*)lf[3]+1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f2127,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* port.scm:120: ##sys#check-port */
t4=*((C_word*)lf[4]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=*((C_word*)lf[3]+1);
av2[3]=lf[5];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t2=C_get_rest_arg(c,2,av,2,t0);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_747,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* port.scm:120: ##sys#check-port */
t4=*((C_word*)lf[4]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[5];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k745 in chicken.port#port-name in k736 in k733 */
static void C_ccall f_747(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_747,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_slot(((C_word*)t0)[3],C_fix(3));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.port#set-port-name! in k736 in k733 */
static void C_ccall f_758(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_758,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_762,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* port.scm:124: ##sys#check-port */
t5=*((C_word*)lf[4]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[7];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k760 in chicken.port#set-port-name! in k736 in k733 */
static void C_ccall f_762(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_762,c,av);}
t2=C_i_check_string_2(((C_word*)t0)[2],lf[7]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_setslot(((C_word*)t0)[4],C_fix(3),((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.port#port-position in k736 in k733 */
static void C_ccall f_770(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_770,c,av);}
a=C_alloc(4);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?*((C_word*)lf[3]+1):C_get_rest_arg(c,2,av,2,t0));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_777,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* port.scm:129: ##sys#check-port */
t5=*((C_word*)lf[4]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
av2[3]=lf[10];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k775 in chicken.port#port-position in k736 in k733 */
static void C_ccall f_777(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_777,c,av);}
if(C_truep(C_input_portp(((C_word*)t0)[2]))){
/* port.scm:131: ##sys#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=C_slot(((C_word*)t0)[2],C_fix(4));
av2[3]=C_slot(((C_word*)t0)[2],C_fix(5));
C_values(4,av2);}}
else{
/* port.scm:132: ##sys#error */
t2=*((C_word*)lf[9]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[10];
av2[3]=lf[11];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* chicken.port#set-buffering-mode! in k736 in k733 */
static void C_ccall f_802(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +6,c,3)))){
C_save_and_reclaim((void*)f_802,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+6);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_806,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* port.scm:135: ##sys#check-port */
t6=*((C_word*)lf[4]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
av2[3]=lf[13];
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k804 in chicken.port#set-buffering-mode! in k736 in k733 */
static void C_ccall f_806(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_806,c,av);}
a=C_alloc(5);
t2=C_i_pairp(((C_word*)t0)[2]);
t3=(C_truep(t2)?C_u_i_car(((C_word*)t0)[2]):C_fix((C_word)BUFSIZ));
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_812,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t5=C_eqp(((C_word*)t0)[5],lf[17]);
if(C_truep(t5)){
t6=t4;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_fix((C_word)_IOFBF);
f_812(2,av2);}}
else{
t6=C_eqp(((C_word*)t0)[5],lf[18]);
if(C_truep(t6)){
t7=C_fix((C_word)_IOLBF);
t8=t4;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
f_812(2,av2);}}
else{
t7=C_eqp(((C_word*)t0)[5],lf[19]);
if(C_truep(t7)){
t8=t4;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_fix((C_word)_IONBF);
f_812(2,av2);}}
else{
/* port.scm:141: ##sys#error */
t8=*((C_word*)lf[9]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t8;
av2[1]=t4;
av2[2]=lf[13];
av2[3]=lf[20];
av2[4]=((C_word*)t0)[5];
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t8+1)))(6,av2);}}}}}

/* k810 in k804 in chicken.port#set-buffering-mode! in k736 in k733 */
static void C_ccall f_812(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_812,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_815,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* port.scm:142: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[16]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[16]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[13];
tp(4,av2);}}

/* k813 in k810 in k804 in chicken.port#set-buffering-mode! in k736 in k733 */
static void C_ccall f_815(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_815,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_821,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_slot(((C_word*)t0)[3],C_fix(7));
t4=C_eqp(lf[15],t3);
if(C_truep(t4)){
t5=C_i_foreign_fixnum_argumentp(((C_word*)t0)[4]);
t6=C_i_foreign_fixnum_argumentp(((C_word*)t0)[5]);
t7=t2;
f_821(t7,C_fixnum_lessp(stub144(C_SCHEME_UNDEFINED,((C_word*)t0)[3],t5,t6),C_fix(0)));}
else{
t5=t2;
f_821(t5,C_fixnum_lessp(C_fix(-1),C_fix(0)));}}

/* k819 in k813 in k810 in k804 in chicken.port#set-buffering-mode! in k736 in k733 */
static void C_fcall f_821(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,6)))){
C_save_and_reclaim_args((void *)trf_821,2,t0,t1);}
if(C_truep(t1)){
/* port.scm:149: ##sys#error */
t2=*((C_word*)lf[9]+1);{
C_word av2[7];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[13];
av2[3]=lf[14];
av2[4]=((C_word*)t0)[3];
av2[5]=((C_word*)t0)[4];
av2[6]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(7,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.port#port-for-each in k736 in k733 */
static void C_ccall f_878(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_878,c,av);}
a=C_alloc(8);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_884,a[2]=t5,a[3]=t2,a[4]=t3,a[5]=((C_word)li4),tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_884(t7,t1);}

/* loop in chicken.port#port-for-each in k736 in k733 */
static void C_fcall f_884(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_884,2,t0,t1);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_888,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* port.scm:155: thunk */
t3=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k886 in loop in chicken.port#port-for-each in k736 in k733 */
static void C_ccall f_888(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_888,c,av);}
a=C_alloc(4);
if(C_truep(C_eofp(t1))){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_897,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* port.scm:157: fn */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}}

/* k895 in k886 in loop in chicken.port#port-for-each in k736 in k733 */
static void C_ccall f_897(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_897,c,av);}
/* port.scm:158: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_884(t2,((C_word*)t0)[3]);}

/* chicken.port#port-map in k736 in k733 */
static void C_ccall f_902(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_902,c,av);}
a=C_alloc(8);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_908,a[2]=t5,a[3]=t2,a[4]=t3,a[5]=((C_word)li6),tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_908(t7,t1,C_SCHEME_END_OF_LIST);}

/* loop in chicken.port#port-map in k736 in k733 */
static void C_fcall f_908(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_908,3,t0,t1,t2);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_912,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* port.scm:163: thunk */
t4=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* k910 in loop in chicken.port#port-map in k736 in k733 */
static void C_ccall f_912(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_912,c,av);}
a=C_alloc(5);
if(C_truep(C_eofp(t1))){
/* port.scm:165: ##sys#fast-reverse */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[23]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[23]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_932,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* port.scm:166: fn */
t3=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}}

/* k930 in k910 in loop in chicken.port#port-map in k736 in k733 */
static void C_ccall f_932(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_932,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
/* port.scm:166: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_908(t3,((C_word*)t0)[4],t2);}

/* chicken.port#port-fold in k736 in k733 */
static void C_ccall f_934(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_934,c,av);}
a=C_alloc(8);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_940,a[2]=t6,a[3]=t2,a[4]=t4,a[5]=((C_word)li8),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_940(t8,t1,t3);}

/* loop in chicken.port#port-fold in k736 in k733 */
static void C_fcall f_940(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_940,3,t0,t1,t2);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_944,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* port.scm:170: thunk */
t4=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}

/* k942 in loop in chicken.port#port-fold in k736 in k733 */
static void C_ccall f_944(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_944,c,av);}
a=C_alloc(4);
if(C_truep(C_eofp(t1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_957,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* port.scm:173: fn */
t3=((C_word*)t0)[5];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}}

/* k955 in k942 in loop in chicken.port#port-fold in k736 in k733 */
static void C_ccall f_957(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_957,c,av);}
/* port.scm:173: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_940(t2,((C_word*)t0)[3],t1);}

/* k962 in chicken.port#copy-port in k736 in k733 */
static void C_ccall f_964(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_964,c,av);}
a=C_alloc(9);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_969,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=((C_word)li13),tmp=(C_word)a,a+=7,tmp));
t5=((C_word*)t3)[1];
f_969(t5,((C_word*)t0)[4]);}

/* loop in k962 in chicken.port#copy-port in k736 in k733 */
static void C_fcall f_969(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_969,2,t0,t1);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_973,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* port.scm:183: chicken.io#read-string! */
t3=*((C_word*)lf[29]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_fix(1024);
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k971 in loop in k962 in chicken.port#copy-port in k736 in k733 */
static void C_ccall f_973(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_973,c,av);}
a=C_alloc(4);
t2=C_eqp(t1,C_fix(0));
if(C_truep(t2)){
t3=C_SCHEME_UNDEFINED;
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_982,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* port.scm:185: writer */
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
av2[3]=t1;
((C_proc)C_fast_retrieve_proc(t4))(4,av2);}}}

/* k980 in k971 in loop in k962 in chicken.port#copy-port in k736 in k733 */
static void C_ccall f_982(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_982,c,av);}
/* port.scm:186: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_969(t2,((C_word*)t0)[3]);}

/* doloop191 */
static void C_fcall f_994(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_994,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1004,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_subbyte(((C_word*)t0)[4],t2);
/* port.scm:190: writer */
t5=((C_word*)t0)[5];{
C_word av2[4];
av2[0]=t5;
av2[1]=t3;
av2[2]=C_make_character(C_unfix(t4));
av2[3]=((C_word*)t0)[6];
((C_proc)C_fast_retrieve_proc(t5))(4,av2);}}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_port_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("port"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_port_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(546))){
C_save(t1);
C_rereclaim2(546*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,90);
lf[0]=C_h_intern(&lf[0],4, C_text("port"));
lf[1]=C_h_intern(&lf[1],13, C_text("chicken.port#"));
lf[2]=C_h_intern(&lf[2],22, C_text("chicken.port#port-name"));
lf[3]=C_h_intern(&lf[3],20, C_text("##sys#standard-input"));
lf[4]=C_h_intern(&lf[4],16, C_text("##sys#check-port"));
lf[5]=C_h_intern(&lf[5],9, C_text("port-name"));
lf[6]=C_h_intern(&lf[6],27, C_text("chicken.port#set-port-name!"));
lf[7]=C_h_intern(&lf[7],14, C_text("set-port-name!"));
lf[8]=C_h_intern(&lf[8],26, C_text("chicken.port#port-position"));
lf[9]=C_h_intern(&lf[9],11, C_text("##sys#error"));
lf[10]=C_h_intern(&lf[10],13, C_text("port-position"));
lf[11]=C_decode_literal(C_heaptop,C_text("\376B\000\000\037cannot compute position of port"));
lf[12]=C_h_intern(&lf[12],32, C_text("chicken.port#set-buffering-mode!"));
lf[13]=C_h_intern(&lf[13],19, C_text("set-buffering-mode!"));
lf[14]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031cannot set buffering mode"));
lf[15]=C_h_intern(&lf[15],6, C_text("stream"));
lf[16]=C_h_intern(&lf[16],18, C_text("##sys#check-fixnum"));
lf[17]=C_h_intern_kw(&lf[17],4, C_text("full"));
lf[18]=C_h_intern_kw(&lf[18],4, C_text("line"));
lf[19]=C_h_intern_kw(&lf[19],4, C_text("none"));
lf[20]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026invalid buffering-mode"));
lf[21]=C_h_intern(&lf[21],26, C_text("chicken.port#port-for-each"));
lf[22]=C_h_intern(&lf[22],21, C_text("chicken.port#port-map"));
lf[23]=C_h_intern(&lf[23],18, C_text("##sys#fast-reverse"));
lf[24]=C_h_intern(&lf[24],22, C_text("chicken.port#port-fold"));
lf[25]=C_h_intern(&lf[25],16, C_text("scheme#read-char"));
lf[26]=C_h_intern(&lf[26],17, C_text("scheme#write-char"));
lf[27]=C_h_intern(&lf[27],22, C_text("chicken.port#copy-port"));
lf[28]=C_h_intern(&lf[28],23, C_text("chicken.io#write-string"));
lf[29]=C_h_intern(&lf[29],23, C_text("chicken.io#read-string!"));
lf[30]=C_h_intern(&lf[30],17, C_text("##sys#make-string"));
lf[31]=C_h_intern(&lf[31],32, C_text("chicken.port#make-broadcast-port"));
lf[32]=C_h_intern(&lf[32],25, C_text("chicken.base#flush-output"));
lf[33]=C_h_intern(&lf[33],29, C_text("chicken.port#make-output-port"));
lf[34]=C_h_intern(&lf[34],17, C_text("chicken.base#void"));
lf[35]=C_h_intern(&lf[35],35, C_text("chicken.port#make-concatenated-port"));
lf[36]=C_h_intern(&lf[36],20, C_text("##sys#read-char/port"));
lf[37]=C_h_intern(&lf[37],18, C_text("scheme#char-ready\077"));
lf[38]=C_h_intern(&lf[38],16, C_text("scheme#peek-char"));
lf[39]=C_h_intern(&lf[39],28, C_text("chicken.port#make-input-port"));
lf[40]=C_h_intern(&lf[40],33, C_text("chicken.port#with-input-from-port"));
lf[41]=C_h_intern(&lf[41],20, C_text("with-input-from-port"));
lf[42]=C_h_intern(&lf[42],18, C_text("##sys#dynamic-wind"));
lf[43]=C_h_intern(&lf[43],32, C_text("chicken.port#with-output-to-port"));
lf[44]=C_h_intern(&lf[44],19, C_text("with-output-to-port"));
lf[45]=C_h_intern(&lf[45],21, C_text("##sys#standard-output"));
lf[46]=C_h_intern(&lf[46],38, C_text("chicken.port#with-error-output-to-port"));
lf[47]=C_h_intern(&lf[47],25, C_text("with-error-output-to-port"));
lf[48]=C_h_intern(&lf[48],20, C_text("##sys#standard-error"));
lf[49]=C_h_intern(&lf[49],35, C_text("chicken.port#call-with-input-string"));
lf[50]=C_h_intern(&lf[50],30, C_text("chicken.base#open-input-string"));
lf[51]=C_h_intern(&lf[51],36, C_text("chicken.port#call-with-output-string"));
lf[52]=C_h_intern(&lf[52],30, C_text("chicken.base#get-output-string"));
lf[53]=C_h_intern(&lf[53],31, C_text("chicken.base#open-output-string"));
lf[54]=C_h_intern(&lf[54],35, C_text("chicken.port#with-input-from-string"));
lf[55]=C_h_intern(&lf[55],34, C_text("chicken.port#with-output-to-string"));
lf[56]=C_h_intern(&lf[56],40, C_text("chicken.port#with-error-output-to-string"));
lf[57]=C_h_intern(&lf[57],20, C_text("##sys#set-port-data!"));
lf[58]=C_h_intern(&lf[58],15, C_text("##sys#make-port"));
lf[59]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010(custom)"));
lf[60]=C_h_intern(&lf[60],6, C_text("custom"));
lf[61]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010(custom)"));
lf[62]=C_h_intern(&lf[62],36, C_text("chicken.port#make-bidirectional-port"));
lf[63]=C_h_intern(&lf[63],21, C_text("##sys#write-char/port"));
lf[64]=C_h_intern(&lf[64],23, C_text("scheme#close-input-port"));
lf[65]=C_h_intern(&lf[65],24, C_text("scheme#close-output-port"));
lf[66]=C_h_intern(&lf[66],20, C_text("chicken.io#read-line"));
lf[67]=C_h_intern(&lf[67],24, C_text("chicken.io#read-buffered"));
lf[68]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017(bidirectional)"));
lf[69]=C_h_intern(&lf[69],13, C_text("bidirectional"));
lf[71]=C_h_intern(&lf[71],23, C_text("##sys#signal-hook/errno"));
lf[72]=C_h_intern(&lf[72],20, C_text("scheme#string-append"));
lf[73]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003 - "));
lf[74]=C_h_intern(&lf[74],19, C_text("##sys#peek-c-string"));
lf[75]=C_h_intern(&lf[75],18, C_text("##sys#update-errno"));
lf[76]=C_h_intern(&lf[76],27, C_text("chicken.port#terminal-port\077"));
lf[77]=C_h_intern(&lf[77],14, C_text("terminal-port\077"));
lf[78]=C_h_intern(&lf[78],27, C_text("##sys#peek-unsigned-integer"));
lf[80]=C_decode_literal(C_heaptop,C_text("\376B\000\000#port is not connected to a terminal"));
lf[81]=C_h_intern(&lf[81],26, C_text("chicken.port#terminal-name"));
lf[82]=C_h_intern_kw(&lf[82],5, C_text("error"));
lf[83]=C_h_intern(&lf[83],13, C_text("terminal-name"));
lf[84]=C_decode_literal(C_heaptop,C_text("\376B\000\000\036cannot determine terminal name"));
lf[85]=C_h_intern(&lf[85],26, C_text("chicken.port#terminal-size"));
lf[86]=C_h_intern(&lf[86],13, C_text("terminal-size"));
lf[87]=C_decode_literal(C_heaptop,C_text("\376B\000\000\036cannot determine terminal size"));
lf[88]=C_h_intern(&lf[88],19, C_text("##sys#make-locative"));
lf[89]=C_h_intern(&lf[89],8, C_text("location"));
C_register_lf2(lf,90,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_735,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[142] = {
{C_text("f2127:port_2escm"),(void*)f2127},
{C_text("f_1004:port_2escm"),(void*)f_1004},
{C_text("f_1027:port_2escm"),(void*)f_1027},
{C_text("f_1031:port_2escm"),(void*)f_1031},
{C_text("f_1040:port_2escm"),(void*)f_1040},
{C_text("f_1049:port_2escm"),(void*)f_1049},
{C_text("f_1054:port_2escm"),(void*)f_1054},
{C_text("f_1058:port_2escm"),(void*)f_1058},
{C_text("f_1061:port_2escm"),(void*)f_1061},
{C_text("f_1096:port_2escm"),(void*)f_1096},
{C_text("f_1099:port_2escm"),(void*)f_1099},
{C_text("f_1129:port_2escm"),(void*)f_1129},
{C_text("f_1134:port_2escm"),(void*)f_1134},
{C_text("f_1152:port_2escm"),(void*)f_1152},
{C_text("f_1158:port_2escm"),(void*)f_1158},
{C_text("f_1188:port_2escm"),(void*)f_1188},
{C_text("f_1194:port_2escm"),(void*)f_1194},
{C_text("f_1196:port_2escm"),(void*)f_1196},
{C_text("f_1205:port_2escm"),(void*)f_1205},
{C_text("f_1215:port_2escm"),(void*)f_1215},
{C_text("f_1228:port_2escm"),(void*)f_1228},
{C_text("f_1234:port_2escm"),(void*)f_1234},
{C_text("f_1244:port_2escm"),(void*)f_1244},
{C_text("f_1257:port_2escm"),(void*)f_1257},
{C_text("f_1266:port_2escm"),(void*)f_1266},
{C_text("f_1272:port_2escm"),(void*)f_1272},
{C_text("f_1282:port_2escm"),(void*)f_1282},
{C_text("f_1301:port_2escm"),(void*)f_1301},
{C_text("f_1321:port_2escm"),(void*)f_1321},
{C_text("f_1327:port_2escm"),(void*)f_1327},
{C_text("f_1337:port_2escm"),(void*)f_1337},
{C_text("f_1356:port_2escm"),(void*)f_1356},
{C_text("f_1362:port_2escm"),(void*)f_1362},
{C_text("f_1378:port_2escm"),(void*)f_1378},
{C_text("f_1409:port_2escm"),(void*)f_1409},
{C_text("f_1418:port_2escm"),(void*)f_1418},
{C_text("f_1423:port_2escm"),(void*)f_1423},
{C_text("f_1429:port_2escm"),(void*)f_1429},
{C_text("f_1434:port_2escm"),(void*)f_1434},
{C_text("f_1443:port_2escm"),(void*)f_1443},
{C_text("f_1448:port_2escm"),(void*)f_1448},
{C_text("f_1454:port_2escm"),(void*)f_1454},
{C_text("f_1459:port_2escm"),(void*)f_1459},
{C_text("f_1468:port_2escm"),(void*)f_1468},
{C_text("f_1473:port_2escm"),(void*)f_1473},
{C_text("f_1479:port_2escm"),(void*)f_1479},
{C_text("f_1484:port_2escm"),(void*)f_1484},
{C_text("f_1488:port_2escm"),(void*)f_1488},
{C_text("f_1493:port_2escm"),(void*)f_1493},
{C_text("f_1497:port_2escm"),(void*)f_1497},
{C_text("f_1500:port_2escm"),(void*)f_1500},
{C_text("f_1505:port_2escm"),(void*)f_1505},
{C_text("f_1509:port_2escm"),(void*)f_1509},
{C_text("f_1514:port_2escm"),(void*)f_1514},
{C_text("f_1519:port_2escm"),(void*)f_1519},
{C_text("f_1525:port_2escm"),(void*)f_1525},
{C_text("f_1530:port_2escm"),(void*)f_1530},
{C_text("f_1534:port_2escm"),(void*)f_1534},
{C_text("f_1539:port_2escm"),(void*)f_1539},
{C_text("f_1544:port_2escm"),(void*)f_1544},
{C_text("f_1548:port_2escm"),(void*)f_1548},
{C_text("f_1553:port_2escm"),(void*)f_1553},
{C_text("f_1558:port_2escm"),(void*)f_1558},
{C_text("f_1562:port_2escm"),(void*)f_1562},
{C_text("f_1567:port_2escm"),(void*)f_1567},
{C_text("f_1572:port_2escm"),(void*)f_1572},
{C_text("f_1576:port_2escm"),(void*)f_1576},
{C_text("f_1581:port_2escm"),(void*)f_1581},
{C_text("f_1586:port_2escm"),(void*)f_1586},
{C_text("f_1620:port_2escm"),(void*)f_1620},
{C_text("f_1623:port_2escm"),(void*)f_1623},
{C_text("f_1625:port_2escm"),(void*)f_1625},
{C_text("f_1646:port_2escm"),(void*)f_1646},
{C_text("f_1662:port_2escm"),(void*)f_1662},
{C_text("f_1667:port_2escm"),(void*)f_1667},
{C_text("f_1673:port_2escm"),(void*)f_1673},
{C_text("f_1727:port_2escm"),(void*)f_1727},
{C_text("f_1740:port_2escm"),(void*)f_1740},
{C_text("f_1743:port_2escm"),(void*)f_1743},
{C_text("f_1745:port_2escm"),(void*)f_1745},
{C_text("f_1755:port_2escm"),(void*)f_1755},
{C_text("f_1761:port_2escm"),(void*)f_1761},
{C_text("f_1767:port_2escm"),(void*)f_1767},
{C_text("f_1782:port_2escm"),(void*)f_1782},
{C_text("f_1789:port_2escm"),(void*)f_1789},
{C_text("f_1792:port_2escm"),(void*)f_1792},
{C_text("f_1798:port_2escm"),(void*)f_1798},
{C_text("f_1804:port_2escm"),(void*)f_1804},
{C_text("f_1810:port_2escm"),(void*)f_1810},
{C_text("f_1816:port_2escm"),(void*)f_1816},
{C_text("f_1822:port_2escm"),(void*)f_1822},
{C_text("f_1847:port_2escm"),(void*)f_1847},
{C_text("f_1853:port_2escm"),(void*)f_1853},
{C_text("f_1859:port_2escm"),(void*)f_1859},
{C_text("f_1865:port_2escm"),(void*)f_1865},
{C_text("f_1871:port_2escm"),(void*)f_1871},
{C_text("f_1887:port_2escm"),(void*)f_1887},
{C_text("f_1891:port_2escm"),(void*)f_1891},
{C_text("f_1898:port_2escm"),(void*)f_1898},
{C_text("f_1902:port_2escm"),(void*)f_1902},
{C_text("f_1904:port_2escm"),(void*)f_1904},
{C_text("f_1910:port_2escm"),(void*)f_1910},
{C_text("f_1922:port_2escm"),(void*)f_1922},
{C_text("f_1953:port_2escm"),(void*)f_1953},
{C_text("f_1957:port_2escm"),(void*)f_1957},
{C_text("f_1960:port_2escm"),(void*)f_1960},
{C_text("f_1983:port_2escm"),(void*)f_1983},
{C_text("f_1987:port_2escm"),(void*)f_1987},
{C_text("f_2008:port_2escm"),(void*)f_2008},
{C_text("f_2012:port_2escm"),(void*)f_2012},
{C_text("f_735:port_2escm"),(void*)f_735},
{C_text("f_738:port_2escm"),(void*)f_738},
{C_text("f_740:port_2escm"),(void*)f_740},
{C_text("f_747:port_2escm"),(void*)f_747},
{C_text("f_758:port_2escm"),(void*)f_758},
{C_text("f_762:port_2escm"),(void*)f_762},
{C_text("f_770:port_2escm"),(void*)f_770},
{C_text("f_777:port_2escm"),(void*)f_777},
{C_text("f_802:port_2escm"),(void*)f_802},
{C_text("f_806:port_2escm"),(void*)f_806},
{C_text("f_812:port_2escm"),(void*)f_812},
{C_text("f_815:port_2escm"),(void*)f_815},
{C_text("f_821:port_2escm"),(void*)f_821},
{C_text("f_878:port_2escm"),(void*)f_878},
{C_text("f_884:port_2escm"),(void*)f_884},
{C_text("f_888:port_2escm"),(void*)f_888},
{C_text("f_897:port_2escm"),(void*)f_897},
{C_text("f_902:port_2escm"),(void*)f_902},
{C_text("f_908:port_2escm"),(void*)f_908},
{C_text("f_912:port_2escm"),(void*)f_912},
{C_text("f_932:port_2escm"),(void*)f_932},
{C_text("f_934:port_2escm"),(void*)f_934},
{C_text("f_940:port_2escm"),(void*)f_940},
{C_text("f_944:port_2escm"),(void*)f_944},
{C_text("f_957:port_2escm"),(void*)f_957},
{C_text("f_964:port_2escm"),(void*)f_964},
{C_text("f_969:port_2escm"),(void*)f_969},
{C_text("f_973:port_2escm"),(void*)f_973},
{C_text("f_982:port_2escm"),(void*)f_982},
{C_text("f_994:port_2escm"),(void*)f_994},
{C_text("toplevel:port_2escm"),(void*)C_port_toplevel},
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
o|hiding unexported module binding: chicken.port#d 
o|hiding unexported module binding: chicken.port#define-alias 
o|hiding unexported module binding: chicken.port#posix-error 
o|hiding unexported module binding: chicken.port#check-terminal! 
S|applied compiler syntax:
S|  scheme#for-each		2
o|eliminated procedure checks: 32 
o|specializations:
o|  2 (##sys#check-open-port * *)
o|  2 (##sys#check-output-port * * *)
o|  1 (##sys#check-input-port * * *)
o|  2 (##sys#check-list (or pair list) *)
o|  2 (scheme#make-string fixnum)
o|  5 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  1 (scheme#car pair)
(o e)|safe calls: 161 
(o e)|assignments to immediate values: 1 
o|safe globals: (chicken.port#terminal-size chicken.port#terminal-name chicken.port#check-terminal! chicken.port#terminal-port? chicken.port#posix-error chicken.port#make-bidirectional-port chicken.port#make-output-port chicken.port#make-input-port chicken.port#with-error-output-to-string chicken.port#with-output-to-string chicken.port#with-input-from-string chicken.port#call-with-output-string chicken.port#call-with-input-string chicken.port#with-error-output-to-port chicken.port#with-output-to-port chicken.port#with-input-from-port chicken.port#make-concatenated-port chicken.port#make-broadcast-port chicken.port#copy-port chicken.port#port-fold chicken.port#port-map chicken.port#port-for-each chicken.port#set-buffering-mode! chicken.port#port-position chicken.port#set-port-name! chicken.port#port-name) 
o|inlining procedure: k778 
o|inlining procedure: k778 
o|inlining procedure: k816 
o|inlining procedure: k816 
o|inlining procedure: k826 
o|contracted procedure: "(port.scm:143) g139140" 
o|inlining procedure: k826 
o|inlining procedure: k852 
o|inlining procedure: k852 
o|substituted constant variable: a868 
o|substituted constant variable: a870 
o|substituted constant variable: a872 
o|inlining procedure: k889 
o|inlining procedure: k889 
o|inlining procedure: k913 
o|inlining procedure: k913 
o|inlining procedure: k945 
o|inlining procedure: k945 
o|inlining procedure: k1113 
o|contracted procedure: "(port.scm:213) read-buf176" 
o|inlining procedure: k974 
o|inlining procedure: k974 
o|substituted constant variable: a986 
o|contracted procedure: "(port.scm:217) write-buf177" 
o|inlining procedure: k996 
o|inlining procedure: k996 
o|inlining procedure: k1113 
o|contracted procedure: "(port.scm:219) read-and-write-buf179" 
o|inlining procedure: k1062 
o|inlining procedure: k1062 
o|substituted constant variable: a1098 
o|contracted procedure: "(port.scm:221) read-and-write178" 
o|inlining procedure: k1032 
o|inlining procedure: k1032 
o|propagated global variable: g268269 chicken.io#write-string 
o|inlining procedure: k1207 
o|inlining procedure: k1207 
o|inlining procedure: k1236 
o|inlining procedure: k1236 
o|inlining procedure: k1274 
o|inlining procedure: k1274 
o|inlining procedure: k1303 
o|inlining procedure: k1303 
o|inlining procedure: k1329 
o|inlining procedure: k1329 
o|inlining procedure: k1364 
o|inlining procedure: k1364 
o|substituted constant variable: a1412 
o|substituted constant variable: a1413 
o|substituted constant variable: a1437 
o|substituted constant variable: a1438 
o|substituted constant variable: a1462 
o|substituted constant variable: a1463 
o|inlining procedure: k1630 
o|inlining procedure: k1630 
o|inlining procedure: k1651 
o|inlining procedure: k1651 
o|inlining procedure: k1769 
o|inlining procedure: k1769 
o|inlining procedure: k1824 
o|inlining procedure: k1824 
o|substituted constant variable: a1843 
o|substituted constant variable: a1845 
o|merged explicitly consed rest parameter: args522 
o|contracted procedure: "(port.scm:415) strerror512" 
o|substituted constant variable: a1907 
o|inlining procedure: k1911 
o|inlining procedure: k1911 
o|inlining procedure: k1926 
o|inlining procedure: k1926 
o|inlining procedure: k1961 
o|inlining procedure: k1961 
o|consed rest parameter at call site: "(port.scm:434) chicken.port#posix-error" 4 
o|contracted procedure: "(port.scm:433) ttyname535" 
o|inlining procedure: k1988 
o|inlining procedure: k1988 
o|consed rest parameter at call site: "(port.scm:449) chicken.port#posix-error" 4 
o|contracted procedure: "(port.scm:445) ttysize547" 
o|replaced variables: 284 
o|removed binding forms: 113 
o|substituted constant variable: r8272019 
o|substituted constant variable: r8272019 
o|substituted constant variable: r12752043 
o|substituted constant variable: r13042046 
o|substituted constant variable: r13302047 
o|substituted constant variable: r19122060 
o|replaced variables: 31 
o|removed binding forms: 258 
o|inlining procedure: k742 
o|propagated global variable: r7432125 ##sys#standard-input 
o|inlining procedure: k826 
o|inlining procedure: k2001 
o|removed binding forms: 36 
o|removed binding forms: 2 
o|simplifications: ((let . 5) (if . 18) (##core#call . 120)) 
o|  call simplifications:
o|    ##sys#foreign-pointer-argument	2
o|    chicken.fixnum#fx=
o|    scheme#values
o|    scheme#apply
o|    scheme#write-char
o|    scheme#string
o|    ##sys#setislot
o|    scheme#vector	6
o|    chicken.fixnum#fx<=
o|    chicken.fixnum#fx-
o|    scheme#not	2
o|    scheme#read-char	2
o|    scheme#cdr	9
o|    scheme#char->integer
o|    ##sys#setbyte
o|    chicken.fixnum#fx>=	3
o|    ##sys#byte
o|    scheme#integer->char
o|    chicken.fixnum#fx+	4
o|    scheme#cons	2
o|    scheme#eof-object?	7
o|    scheme#pair?	3
o|    scheme#eq?	12
o|    ##sys#foreign-fixnum-argument	5
o|    chicken.fixnum#fx<	3
o|    ##sys#values
o|    ##sys#check-string
o|    ##sys#setslot	2
o|    scheme#null?	19
o|    scheme#car	13
o|    ##sys#slot	12
o|contracted procedure: k751 
o|contracted procedure: k742 
o|contracted procedure: k763 
o|contracted procedure: k795 
o|contracted procedure: k772 
o|contracted procedure: k785 
o|contracted procedure: k789 
o|contracted procedure: k873 
o|contracted procedure: k807 
o|contracted procedure: k846 
o|contracted procedure: k829 
o|contracted procedure: k835 
o|contracted procedure: k839 
o|contracted procedure: k849 
o|contracted procedure: k855 
o|contracted procedure: k861 
o|contracted procedure: k892 
o|contracted procedure: k916 
o|contracted procedure: k926 
o|contracted procedure: k948 
o|contracted procedure: k1181 
o|contracted procedure: k1101 
o|contracted procedure: k1175 
o|contracted procedure: k1104 
o|contracted procedure: k1169 
o|contracted procedure: k1107 
o|contracted procedure: k1163 
o|contracted procedure: k1110 
o|contracted procedure: k1116 
o|contracted procedure: k1126 
o|contracted procedure: k1123 
o|contracted procedure: k999 
o|contracted procedure: k1009 
o|contracted procedure: k1017 
o|contracted procedure: k1013 
o|contracted procedure: k977 
o|contracted procedure: k1142 
o|contracted procedure: k1065 
o|contracted procedure: k1071 
o|contracted procedure: k1088 
o|contracted procedure: k1077 
o|contracted procedure: k1084 
o|contracted procedure: k1091 
o|contracted procedure: k1035 
o|contracted procedure: k1210 
o|contracted procedure: k1220 
o|contracted procedure: k1224 
o|contracted procedure: k1239 
o|contracted procedure: k1249 
o|contracted procedure: k1253 
o|contracted procedure: k1259 
o|contracted procedure: k1277 
o|contracted procedure: k1286 
o|contracted procedure: k1290 
o|contracted procedure: k1297 
o|contracted procedure: k1317 
o|contracted procedure: k1306 
o|contracted procedure: k1313 
o|contracted procedure: k1332 
o|contracted procedure: k1341 
o|contracted procedure: k1345 
o|contracted procedure: k1352 
o|contracted procedure: k1367 
o|contracted procedure: k1373 
o|contracted procedure: k1386 
o|contracted procedure: k1390 
o|contracted procedure: k1393 
o|contracted procedure: k1397 
o|contracted procedure: k1401 
o|contracted procedure: k1405 
o|contracted procedure: k1720 
o|contracted procedure: k1588 
o|contracted procedure: k1714 
o|contracted procedure: k1591 
o|contracted procedure: k1708 
o|contracted procedure: k1594 
o|contracted procedure: k1702 
o|contracted procedure: k1597 
o|contracted procedure: k1696 
o|contracted procedure: k1600 
o|contracted procedure: k1690 
o|contracted procedure: k1603 
o|contracted procedure: k1684 
o|contracted procedure: k1606 
o|contracted procedure: k1678 
o|contracted procedure: k1609 
o|contracted procedure: k1627 
o|contracted procedure: k1639 
o|contracted procedure: k1648 
o|contracted procedure: k1663 
o|contracted procedure: k1612 
o|contracted procedure: k1615 
o|contracted procedure: k1775 
o|contracted procedure: k1729 
o|contracted procedure: k1751 
o|contracted procedure: k1732 
o|contracted procedure: k1735 
o|contracted procedure: k1827 
o|contracted procedure: k1836 
o|contracted procedure: k1784 
o|contracted procedure: k1794 
o|contracted procedure: k1884 
o|contracted procedure: k1918 
o|contracted procedure: k1914 
o|contracted procedure: k1939 
o|contracted procedure: k1935 
o|contracted procedure: k1929 
o|contracted procedure: k1950 
o|contracted procedure: k1972 
o|contracted procedure: k1976 
o|contracted procedure: k1980 
o|contracted procedure: k1991 
o|simplifications: ((let . 36)) 
o|removed binding forms: 112 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest102103 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest102103 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest119120 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest119120 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest220223 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest220223 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest220223 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest220223 0 
o|inlining procedure: k1379 
o|inlining procedure: k1379 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest420424 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest420424 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest420424 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest420424 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest463466 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest463466 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1105 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1105 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1105 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1105 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1592 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1592 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1592 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1592 1 
o|removed binding forms: 3 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1598 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r1598 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1598 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1598 2 
o|removed binding forms: 3 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1604 3 
(o x)|known list op on rest arg sublist: ##core#rest-car r1604 3 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1604 3 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1604 3 
o|removed binding forms: 1 
o|removed binding forms: 2 
o|customizable procedures: (chicken.port#check-terminal! chicken.port#posix-error loop317 loop305 loop296 for-each-loop277287 g253260 for-each-loop252270 a1151 a1157 loop198 k1056 loop206 loop183 doloop191192 loop169 loop161 loop154 k819) 
o|calls to known targets: 39 
o|unused rest argument: rest102103 f_740 
o|unused rest argument: rest119120 f_770 
o|unused rest argument: rest220223 f_1099 
o|unused rest argument: rest420424 f_1586 
o|unused rest argument: rest463466 f_1727 
o|fast box initializations: 12 
o|fast global references: 4 
o|fast global assignments: 2 
o|dropping unused closure argument: f_1887 
o|dropping unused closure argument: f_1922 
*/
/* end of file */
