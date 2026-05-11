/* Generated from file.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: file.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file file.c -emit-import-library chicken.file
   unit: file
   uses: pathname irregex extras library
*/
#include "chicken.h"

#include <errno.h>

#define C_test_access(fn, m) C_fix(access(C_c_string(fn), C_unfix(m)))

/* For Windows */
#ifndef R_OK
# define R_OK 2
#endif
#ifndef W_OK
# define W_OK 4
#endif
#ifndef X_OK
# define X_OK 2
#endif

#define C_rename(old, new)  C_fix(rename(C_c_string(old), C_c_string(new)))
#define C_remove(str)       C_fix(remove(C_c_string(str)))
#define C_rmdir(str)        C_fix(rmdir(C_c_string(str)))

#ifndef _WIN32
# include <sys/stat.h>
# define C_mkdir(str)       C_fix(mkdir(C_c_string(str), S_IRWXU | S_IRWXG | S_IRWXO))
#else
# define C_mkdir(str)       C_fix(mkdir(C_c_string(str)))
#endif

#include <sys/types.h>
#include <dirent.h>

#define C_opendir(s,h)      C_set_block_item(h, 0, (C_word) opendir(C_c_string(s)))
#define C_readdir(h,e)      C_set_block_item(e, 0, (C_word) readdir((DIR *)C_block_item(h, 0)))
#define C_closedir(h)       (closedir((DIR *)C_block_item(h, 0)), C_SCHEME_UNDEFINED)
#define C_foundfile(e,b,l)  (C_strlcpy(C_c_string(b), ((struct dirent *) C_block_item(e, 0))->d_name, l), C_fix(strlen(((struct dirent *) C_block_item(e, 0))->d_name)))

static C_word C_fcall C_u_i_symbolic_linkp(C_word path)
{
#if !defined(_WIN32) || defined(__CYGWIN__)
  struct stat buf;
  if (lstat(C_c_string(path), &buf) == 0)
    return C_mk_bool(S_ISLNK(buf.st_mode));
#endif
  return C_SCHEME_FALSE;
}


static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_pathname_toplevel)
C_externimport void C_ccall C_pathname_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_irregex_toplevel)
C_externimport void C_ccall C_irregex_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[113];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,102,105,108,101,35,112,111,115,105,120,45,101,114,114,111,114,32,116,121,112,101,32,108,111,99,32,109,115,103,32,97,114,103,115,41,0,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,32),40,99,104,105,99,107,101,110,46,102,105,108,101,35,102,105,108,101,45,101,120,105,115,116,115,63,32,110,97,109,101,41};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,102,105,108,101,35,100,105,114,101,99,116,111,114,121,45,101,120,105,115,116,115,63,32,110,97,109,101,41,0,0,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,102,105,108,101,35,116,101,115,116,45,97,99,99,101,115,115,32,102,105,108,101,110,97,109,101,32,97,99,99,32,108,111,99,41,0,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,38),40,99,104,105,99,107,101,110,46,102,105,108,101,35,102,105,108,101,45,114,101,97,100,97,98,108,101,63,32,102,105,108,101,110,97,109,101,41,0,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,38),40,99,104,105,99,107,101,110,46,102,105,108,101,35,102,105,108,101,45,119,114,105,116,97,98,108,101,63,32,102,105,108,101,110,97,109,101,41,0,0};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,102,105,108,101,35,102,105,108,101,45,101,120,101,99,117,116,97,98,108,101,63,32,102,105,108,101,110,97,109,101,41};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,31),40,99,104,105,99,107,101,110,46,102,105,108,101,35,100,105,114,101,99,116,111,114,121,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,100,105,114,41,0,0,0,0,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,7),40,97,49,48,53,51,41,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,29),40,97,49,48,53,57,32,100,105,114,50,51,55,32,102,105,108,101,50,51,57,32,101,120,116,50,52,49,41,0,0,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,102,105,108,101,35,99,114,101,97,116,101,45,100,105,114,101,99,116,111,114,121,32,110,97,109,101,32,46,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,11),40,114,109,100,105,114,32,100,105,114,41,0,0,0,0,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,8),40,103,50,55,52,32,102,41};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,55,51,32,103,50,56,48,41,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,102,105,108,101,35,100,101,108,101,116,101,45,100,105,114,101,99,116,111,114,121,32,110,97,109,101,32,46,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,35),40,99,104,105,99,107,101,110,46,102,105,108,101,35,100,101,108,101,116,101,45,102,105,108,101,32,102,105,108,101,110,97,109,101,41,0,0,0,0,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,32),40,99,104,105,99,107,101,110,46,102,105,108,101,35,100,101,108,101,116,101,45,102,105,108,101,42,32,102,105,108,101,41};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,102,105,108,101,35,114,101,110,97,109,101,45,102,105,108,101,32,111,108,100,102,105,108,101,32,110,101,119,102,105,108,101,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,100,32,108,41,0,0,0,0,0,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,47),40,99,104,105,99,107,101,110,46,102,105,108,101,35,99,111,112,121,45,102,105,108,101,32,111,108,100,102,105,108,101,32,110,101,119,102,105,108,101,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,100,32,108,41,0,0,0,0,0,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,47),40,99,104,105,99,107,101,110,46,102,105,108,101,35,109,111,118,101,45,102,105,108,101,32,111,108,100,102,105,108,101,32,110,101,119,102,105,108,101,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,9),40,116,101,109,112,100,105,114,41,0,0,0,0,0,0,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,9),40,97,49,54,50,55,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,102,105,108,101,35,99,114,101,97,116,101,45,116,101,109,112,111,114,97,114,121,45,102,105,108,101,32,46,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,102,105,108,101,35,99,114,101,97,116,101,45,116,101,109,112,111,114,97,114,121,45,100,105,114,101,99,116,111,114,121,41,0,0,0,0,0,0,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,7),40,97,49,55,52,53,41,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,8),40,103,52,55,55,32,109,41};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,102,110,115,41,0,0,0,0,0,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,7),40,97,49,56,52,49,41,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,13),40,97,49,56,51,53,32,101,120,118,97,114,41,0,0,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,9),40,116,109,112,49,55,50,53,41,0,0,0,0,0,0,0};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,7),40,97,49,56,57,48,41,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,14),40,116,109,112,50,55,50,54,32,97,114,103,115,41,0,0};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,7),40,97,49,56,55,55,41,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,9),40,97,49,56,50,57,32,107,41,0,0,0,0,0,0,0};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,28),40,97,49,55,53,49,32,100,105,114,52,52,57,32,102,105,108,52,53,49,32,101,120,116,52,53,51,41,0,0,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,17),40,99,111,110,99,45,108,111,111,112,32,112,97,116,104,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,27),40,99,104,105,99,107,101,110,46,102,105,108,101,35,103,108,111,98,32,46,32,112,97,116,104,115,41,0,0,0,0,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,7),40,97,50,48,50,48,41,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,7),40,97,50,48,50,53,41,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,7),40,97,50,48,52,53,41,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,15),40,108,111,111,112,32,100,105,114,32,102,115,32,114,41,0};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,10),40,102,95,50,48,57,55,32,120,41,0,0,0,0,0,0};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,12),40,102,95,50,49,48,53,32,46,32,95,41,0,0,0,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,12),40,102,95,50,49,49,51,32,46,32,95,41,0,0,0,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,7),40,97,50,49,49,56,41,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,7),40,97,50,49,50,49,41,0};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,7),40,97,50,49,50,52,41,0};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,7),40,97,50,49,50,55,41,0};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,12),40,102,95,50,49,51,51,32,120,32,121,41,0,0,0,0};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,7),40,97,50,49,51,48,41,0};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,12),40,102,95,50,49,52,49,32,46,32,95,41,0,0,0,0};
static C_char C_TLS li57[] C_aligned={C_lihdr(0,0,7),40,97,50,49,51,56,41,0};
static C_char C_TLS li58[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,102,105,108,101,35,102,105,110,100,45,102,105,108,101,115,32,100,105,114,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li59[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


/* from getpid */
C_regparm static C_word C_fcall stub437(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_fix((C_word)C_getpid());
return C_r;}

/* from getpid */
C_regparm static C_word C_fcall stub428(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_fix((C_word)C_getpid());
return C_r;}

/* from k753 */
C_regparm static C_word C_fcall stub142(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_mpointer(&C_a,(void*)strerror(t0));
return C_r;}

C_noret_decl(f_1000)
static void C_ccall f_1000(C_word c,C_word *av) C_noret;
C_noret_decl(f_1010)
static void C_ccall f_1010(C_word c,C_word *av) C_noret;
C_noret_decl(f_1012)
static void C_fcall f_1012(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1019)
static void C_fcall f_1019(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1022)
static void C_ccall f_1022(C_word c,C_word *av) C_noret;
C_noret_decl(f_1038)
static void C_ccall f_1038(C_word c,C_word *av) C_noret;
C_noret_decl(f_1045)
static void C_ccall f_1045(C_word c,C_word *av) C_noret;
C_noret_decl(f_1052)
static void C_ccall f_1052(C_word c,C_word *av) C_noret;
C_noret_decl(f_1054)
static void C_ccall f_1054(C_word c,C_word *av) C_noret;
C_noret_decl(f_1060)
static void C_ccall f_1060(C_word c,C_word *av) C_noret;
C_noret_decl(f_1083)
static void C_ccall f_1083(C_word c,C_word *av) C_noret;
C_noret_decl(f_1101)
static void C_ccall f_1101(C_word c,C_word *av) C_noret;
C_noret_decl(f_1107)
static void C_fcall f_1107(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1111)
static void C_ccall f_1111(C_word c,C_word *av) C_noret;
C_noret_decl(f_1130)
static void C_ccall f_1130(C_word c,C_word *av) C_noret;
C_noret_decl(f_1131)
static void C_fcall f_1131(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1144)
static void C_ccall f_1144(C_word c,C_word *av) C_noret;
C_noret_decl(f_1153)
static void C_ccall f_1153(C_word c,C_word *av) C_noret;
C_noret_decl(f_1156)
static void C_ccall f_1156(C_word c,C_word *av) C_noret;
C_noret_decl(f_1161)
static void C_fcall f_1161(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1171)
static void C_ccall f_1171(C_word c,C_word *av) C_noret;
C_noret_decl(f_1193)
static void C_ccall f_1193(C_word c,C_word *av) C_noret;
C_noret_decl(f_1206)
static void C_ccall f_1206(C_word c,C_word *av) C_noret;
C_noret_decl(f_1210)
static void C_ccall f_1210(C_word c,C_word *av) C_noret;
C_noret_decl(f_1214)
static void C_ccall f_1214(C_word c,C_word *av) C_noret;
C_noret_decl(f_1218)
static void C_ccall f_1218(C_word c,C_word *av) C_noret;
C_noret_decl(f_1223)
static void C_ccall f_1223(C_word c,C_word *av) C_noret;
C_noret_decl(f_1225)
static void C_ccall f_1225(C_word c,C_word *av) C_noret;
C_noret_decl(f_1232)
static void C_ccall f_1232(C_word c,C_word *av) C_noret;
C_noret_decl(f_1237)
static void C_ccall f_1237(C_word c,C_word *av) C_noret;
C_noret_decl(f_1250)
static void C_ccall f_1250(C_word c,C_word *av) C_noret;
C_noret_decl(f_1253)
static void C_ccall f_1253(C_word c,C_word *av) C_noret;
C_noret_decl(f_1263)
static void C_ccall f_1263(C_word c,C_word *av) C_noret;
C_noret_decl(f_1267)
static void C_ccall f_1267(C_word c,C_word *av) C_noret;
C_noret_decl(f_1271)
static void C_ccall f_1271(C_word c,C_word *av) C_noret;
C_noret_decl(f_1276)
static void C_ccall f_1276(C_word c,C_word *av) C_noret;
C_noret_decl(f_1280)
static void C_ccall f_1280(C_word c,C_word *av) C_noret;
C_noret_decl(f_1283)
static void C_ccall f_1283(C_word c,C_word *av) C_noret;
C_noret_decl(f_1300)
static void C_ccall f_1300(C_word c,C_word *av) C_noret;
C_noret_decl(f_1325)
static void C_ccall f_1325(C_word c,C_word *av) C_noret;
C_noret_decl(f_1328)
static void C_ccall f_1328(C_word c,C_word *av) C_noret;
C_noret_decl(f_1331)
static void C_ccall f_1331(C_word c,C_word *av) C_noret;
C_noret_decl(f_1334)
static void C_ccall f_1334(C_word c,C_word *av) C_noret;
C_noret_decl(f_1337)
static void C_ccall f_1337(C_word c,C_word *av) C_noret;
C_noret_decl(f_1340)
static void C_ccall f_1340(C_word c,C_word *av) C_noret;
C_noret_decl(f_1347)
static void C_ccall f_1347(C_word c,C_word *av) C_noret;
C_noret_decl(f_1349)
static void C_fcall f_1349(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1359)
static void C_ccall f_1359(C_word c,C_word *av) C_noret;
C_noret_decl(f_1362)
static void C_ccall f_1362(C_word c,C_word *av) C_noret;
C_noret_decl(f_1365)
static void C_ccall f_1365(C_word c,C_word *av) C_noret;
C_noret_decl(f_1372)
static void C_ccall f_1372(C_word c,C_word *av) C_noret;
C_noret_decl(f_1379)
static void C_ccall f_1379(C_word c,C_word *av) C_noret;
C_noret_decl(f_1391)
static void C_ccall f_1391(C_word c,C_word *av) C_noret;
C_noret_decl(f_1430)
static void C_ccall f_1430(C_word c,C_word *av) C_noret;
C_noret_decl(f_1455)
static void C_ccall f_1455(C_word c,C_word *av) C_noret;
C_noret_decl(f_1458)
static void C_ccall f_1458(C_word c,C_word *av) C_noret;
C_noret_decl(f_1461)
static void C_ccall f_1461(C_word c,C_word *av) C_noret;
C_noret_decl(f_1464)
static void C_ccall f_1464(C_word c,C_word *av) C_noret;
C_noret_decl(f_1467)
static void C_ccall f_1467(C_word c,C_word *av) C_noret;
C_noret_decl(f_1470)
static void C_ccall f_1470(C_word c,C_word *av) C_noret;
C_noret_decl(f_1477)
static void C_ccall f_1477(C_word c,C_word *av) C_noret;
C_noret_decl(f_1479)
static void C_fcall f_1479(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1489)
static void C_ccall f_1489(C_word c,C_word *av) C_noret;
C_noret_decl(f_1492)
static void C_ccall f_1492(C_word c,C_word *av) C_noret;
C_noret_decl(f_1495)
static void C_ccall f_1495(C_word c,C_word *av) C_noret;
C_noret_decl(f_1498)
static void C_ccall f_1498(C_word c,C_word *av) C_noret;
C_noret_decl(f_1505)
static void C_ccall f_1505(C_word c,C_word *av) C_noret;
C_noret_decl(f_1512)
static void C_ccall f_1512(C_word c,C_word *av) C_noret;
C_noret_decl(f_1524)
static void C_ccall f_1524(C_word c,C_word *av) C_noret;
C_noret_decl(f_1563)
static void C_fcall f_1563(C_word t0) C_noret;
C_noret_decl(f_1567)
static void C_ccall f_1567(C_word c,C_word *av) C_noret;
C_noret_decl(f_1573)
static void C_ccall f_1573(C_word c,C_word *av) C_noret;
C_noret_decl(f_1579)
static void C_ccall f_1579(C_word c,C_word *av) C_noret;
C_noret_decl(f_1588)
static void C_ccall f_1588(C_word c,C_word *av) C_noret;
C_noret_decl(f_1596)
static void C_ccall f_1596(C_word c,C_word *av) C_noret;
C_noret_decl(f_1608)
static void C_fcall f_1608(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1614)
static void C_ccall f_1614(C_word c,C_word *av) C_noret;
C_noret_decl(f_1620)
static void C_ccall f_1620(C_word c,C_word *av) C_noret;
C_noret_decl(f_1628)
static void C_ccall f_1628(C_word c,C_word *av) C_noret;
C_noret_decl(f_1633)
static void C_ccall f_1633(C_word c,C_word *av) C_noret;
C_noret_decl(f_1637)
static void C_ccall f_1637(C_word c,C_word *av) C_noret;
C_noret_decl(f_1641)
static void C_ccall f_1641(C_word c,C_word *av) C_noret;
C_noret_decl(f_1645)
static void C_ccall f_1645(C_word c,C_word *av) C_noret;
C_noret_decl(f_1659)
static void C_ccall f_1659(C_word c,C_word *av) C_noret;
C_noret_decl(f_1665)
static void C_fcall f_1665(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1671)
static void C_ccall f_1671(C_word c,C_word *av) C_noret;
C_noret_decl(f_1677)
static void C_ccall f_1677(C_word c,C_word *av) C_noret;
C_noret_decl(f_1684)
static void C_ccall f_1684(C_word c,C_word *av) C_noret;
C_noret_decl(f_1697)
static void C_ccall f_1697(C_word c,C_word *av) C_noret;
C_noret_decl(f_1701)
static void C_ccall f_1701(C_word c,C_word *av) C_noret;
C_noret_decl(f_1705)
static void C_ccall f_1705(C_word c,C_word *av) C_noret;
C_noret_decl(f_1709)
static void C_ccall f_1709(C_word c,C_word *av) C_noret;
C_noret_decl(f_1713)
static void C_ccall f_1713(C_word c,C_word *av) C_noret;
C_noret_decl(f_1717)
static void C_ccall f_1717(C_word c,C_word *av) C_noret;
C_noret_decl(f_1725)
static void C_ccall f_1725(C_word c,C_word *av) C_noret;
C_noret_decl(f_1731)
static void C_fcall f_1731(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1746)
static void C_ccall f_1746(C_word c,C_word *av) C_noret;
C_noret_decl(f_1752)
static void C_ccall f_1752(C_word c,C_word *av) C_noret;
C_noret_decl(f_1759)
static void C_ccall f_1759(C_word c,C_word *av) C_noret;
C_noret_decl(f_1766)
static void C_ccall f_1766(C_word c,C_word *av) C_noret;
C_noret_decl(f_1769)
static void C_ccall f_1769(C_word c,C_word *av) C_noret;
C_noret_decl(f_1771)
static void C_fcall f_1771(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1788)
static void C_ccall f_1788(C_word c,C_word *av) C_noret;
C_noret_decl(f_1792)
static void C_fcall f_1792(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1800)
static void C_ccall f_1800(C_word c,C_word *av) C_noret;
C_noret_decl(f_1804)
static void C_ccall f_1804(C_word c,C_word *av) C_noret;
C_noret_decl(f_1812)
static void C_ccall f_1812(C_word c,C_word *av) C_noret;
C_noret_decl(f_1830)
static void C_ccall f_1830(C_word c,C_word *av) C_noret;
C_noret_decl(f_1836)
static void C_ccall f_1836(C_word c,C_word *av) C_noret;
C_noret_decl(f_1842)
static void C_ccall f_1842(C_word c,C_word *av) C_noret;
C_noret_decl(f_1878)
static void C_ccall f_1878(C_word c,C_word *av) C_noret;
C_noret_decl(f_1880)
static void C_fcall f_1880(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1885)
static void C_fcall f_1885(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1891)
static void C_ccall f_1891(C_word c,C_word *av) C_noret;
C_noret_decl(f_1902)
static void C_ccall f_1902(C_word c,C_word *av) C_noret;
C_noret_decl(f_1906)
static void C_ccall f_1906(C_word c,C_word *av) C_noret;
C_noret_decl(f_1910)
static void C_ccall f_1910(C_word c,C_word *av) C_noret;
C_noret_decl(f_1916)
static void C_ccall f_1916(C_word c,C_word *av) C_noret;
C_noret_decl(f_1920)
static void C_ccall f_1920(C_word c,C_word *av) C_noret;
C_noret_decl(f_1923)
static void C_ccall f_1923(C_word c,C_word *av) C_noret;
C_noret_decl(f_1926)
static void C_ccall f_1926(C_word c,C_word *av) C_noret;
C_noret_decl(f_1929)
static void C_ccall f_1929(C_word c,C_word *av) C_noret;
C_noret_decl(f_1932)
static void C_ccall f_1932(C_word c,C_word *av) C_noret;
C_noret_decl(f_1935)
static void C_ccall f_1935(C_word c,C_word *av) C_noret;
C_noret_decl(f_1941)
static void C_fcall f_1941(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1944)
static void C_fcall f_1944(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1951)
static void C_ccall f_1951(C_word c,C_word *av) C_noret;
C_noret_decl(f_1953)
static void C_fcall f_1953(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_1966)
static void C_ccall f_1966(C_word c,C_word *av) C_noret;
C_noret_decl(f_1975)
static void C_ccall f_1975(C_word c,C_word *av) C_noret;
C_noret_decl(f_1997)
static void C_ccall f_1997(C_word c,C_word *av) C_noret;
C_noret_decl(f_2000)
static void C_ccall f_2000(C_word c,C_word *av) C_noret;
C_noret_decl(f_2009)
static void C_ccall f_2009(C_word c,C_word *av) C_noret;
C_noret_decl(f_2019)
static void C_ccall f_2019(C_word c,C_word *av) C_noret;
C_noret_decl(f_2021)
static void C_ccall f_2021(C_word c,C_word *av) C_noret;
C_noret_decl(f_2026)
static void C_ccall f_2026(C_word c,C_word *av) C_noret;
C_noret_decl(f_2034)
static void C_ccall f_2034(C_word c,C_word *av) C_noret;
C_noret_decl(f_2038)
static void C_ccall f_2038(C_word c,C_word *av) C_noret;
C_noret_decl(f_2041)
static void C_ccall f_2041(C_word c,C_word *av) C_noret;
C_noret_decl(f_2046)
static void C_ccall f_2046(C_word c,C_word *av) C_noret;
C_noret_decl(f_2056)
static void C_ccall f_2056(C_word c,C_word *av) C_noret;
C_noret_decl(f_2059)
static void C_ccall f_2059(C_word c,C_word *av) C_noret;
C_noret_decl(f_2068)
static void C_ccall f_2068(C_word c,C_word *av) C_noret;
C_noret_decl(f_2080)
static void C_ccall f_2080(C_word c,C_word *av) C_noret;
C_noret_decl(f_2087)
static void C_ccall f_2087(C_word c,C_word *av) C_noret;
C_noret_decl(f_2096)
static void C_ccall f_2096(C_word c,C_word *av) C_noret;
C_noret_decl(f_2097)
static void C_ccall f_2097(C_word c,C_word *av) C_noret;
C_noret_decl(f_2105)
static void C_ccall f_2105(C_word c,C_word *av) C_noret;
C_noret_decl(f_2113)
static void C_ccall f_2113(C_word c,C_word *av) C_noret;
C_noret_decl(f_2119)
static void C_ccall f_2119(C_word c,C_word *av) C_noret;
C_noret_decl(f_2122)
static void C_ccall f_2122(C_word c,C_word *av) C_noret;
C_noret_decl(f_2125)
static void C_ccall f_2125(C_word c,C_word *av) C_noret;
C_noret_decl(f_2128)
static void C_ccall f_2128(C_word c,C_word *av) C_noret;
C_noret_decl(f_2131)
static void C_ccall f_2131(C_word c,C_word *av) C_noret;
C_noret_decl(f_2133)
static void C_ccall f_2133(C_word c,C_word *av) C_noret;
C_noret_decl(f_2139)
static void C_ccall f_2139(C_word c,C_word *av) C_noret;
C_noret_decl(f_2141)
static void C_ccall f_2141(C_word c,C_word *av) C_noret;
C_noret_decl(f_735)
static void C_ccall f_735(C_word c,C_word *av) C_noret;
C_noret_decl(f_738)
static void C_ccall f_738(C_word c,C_word *av) C_noret;
C_noret_decl(f_741)
static void C_ccall f_741(C_word c,C_word *av) C_noret;
C_noret_decl(f_744)
static void C_ccall f_744(C_word c,C_word *av) C_noret;
C_noret_decl(f_756)
static void C_fcall f_756(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_760)
static void C_ccall f_760(C_word c,C_word *av) C_noret;
C_noret_decl(f_767)
static void C_ccall f_767(C_word c,C_word *av) C_noret;
C_noret_decl(f_771)
static void C_ccall f_771(C_word c,C_word *av) C_noret;
C_noret_decl(f_773)
static void C_ccall f_773(C_word c,C_word *av) C_noret;
C_noret_decl(f_783)
static void C_ccall f_783(C_word c,C_word *av) C_noret;
C_noret_decl(f_785)
static void C_ccall f_785(C_word c,C_word *av) C_noret;
C_noret_decl(f_795)
static void C_ccall f_795(C_word c,C_word *av) C_noret;
C_noret_decl(f_797)
static void C_fcall f_797(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_805)
static void C_ccall f_805(C_word c,C_word *av) C_noret;
C_noret_decl(f_824)
static void C_ccall f_824(C_word c,C_word *av) C_noret;
C_noret_decl(f_827)
static void C_ccall f_827(C_word c,C_word *av) C_noret;
C_noret_decl(f_833)
static void C_ccall f_833(C_word c,C_word *av) C_noret;
C_noret_decl(f_839)
static void C_ccall f_839(C_word c,C_word *av) C_noret;
C_noret_decl(f_845)
static void C_ccall f_845(C_word c,C_word *av) C_noret;
C_noret_decl(f_849)
static void C_ccall f_849(C_word c,C_word *av) C_noret;
C_noret_decl(f_864)
static void C_ccall f_864(C_word c,C_word *av) C_noret;
C_noret_decl(f_867)
static void C_ccall f_867(C_word c,C_word *av) C_noret;
C_noret_decl(f_870)
static void C_ccall f_870(C_word c,C_word *av) C_noret;
C_noret_decl(f_874)
static void C_ccall f_874(C_word c,C_word *av) C_noret;
C_noret_decl(f_888)
static void C_fcall f_888(C_word t0,C_word t1) C_noret;
C_noret_decl(f_902)
static void C_ccall f_902(C_word c,C_word *av) C_noret;
C_noret_decl(f_914)
static void C_fcall f_914(C_word t0,C_word t1) C_noret;
C_noret_decl(f_924)
static void C_ccall f_924(C_word c,C_word *av) C_noret;
C_noret_decl(f_984)
static void C_ccall f_984(C_word c,C_word *av) C_noret;
C_noret_decl(f_994)
static void C_ccall f_994(C_word c,C_word *av) C_noret;
C_noret_decl(C_file_toplevel)
C_externexport void C_ccall C_file_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_1012)
static void C_ccall trf_1012(C_word c,C_word *av) C_noret;
static void C_ccall trf_1012(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1012(t0,t1,t2);}

C_noret_decl(trf_1019)
static void C_ccall trf_1019(C_word c,C_word *av) C_noret;
static void C_ccall trf_1019(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1019(t0,t1);}

C_noret_decl(trf_1107)
static void C_ccall trf_1107(C_word c,C_word *av) C_noret;
static void C_ccall trf_1107(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1107(t0,t1);}

C_noret_decl(trf_1131)
static void C_ccall trf_1131(C_word c,C_word *av) C_noret;
static void C_ccall trf_1131(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1131(t0,t1,t2);}

C_noret_decl(trf_1161)
static void C_ccall trf_1161(C_word c,C_word *av) C_noret;
static void C_ccall trf_1161(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1161(t0,t1,t2);}

C_noret_decl(trf_1349)
static void C_ccall trf_1349(C_word c,C_word *av) C_noret;
static void C_ccall trf_1349(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1349(t0,t1,t2,t3);}

C_noret_decl(trf_1479)
static void C_ccall trf_1479(C_word c,C_word *av) C_noret;
static void C_ccall trf_1479(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1479(t0,t1,t2,t3);}

C_noret_decl(trf_1563)
static void C_ccall trf_1563(C_word c,C_word *av) C_noret;
static void C_ccall trf_1563(C_word c,C_word *av){
C_word t0=av[0];
f_1563(t0);}

C_noret_decl(trf_1608)
static void C_ccall trf_1608(C_word c,C_word *av) C_noret;
static void C_ccall trf_1608(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1608(t0,t1);}

C_noret_decl(trf_1665)
static void C_ccall trf_1665(C_word c,C_word *av) C_noret;
static void C_ccall trf_1665(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1665(t0,t1);}

C_noret_decl(trf_1731)
static void C_ccall trf_1731(C_word c,C_word *av) C_noret;
static void C_ccall trf_1731(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1731(t0,t1,t2);}

C_noret_decl(trf_1771)
static void C_ccall trf_1771(C_word c,C_word *av) C_noret;
static void C_ccall trf_1771(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1771(t0,t1,t2);}

C_noret_decl(trf_1792)
static void C_ccall trf_1792(C_word c,C_word *av) C_noret;
static void C_ccall trf_1792(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1792(t0,t1,t2);}

C_noret_decl(trf_1880)
static void C_ccall trf_1880(C_word c,C_word *av) C_noret;
static void C_ccall trf_1880(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1880(t0,t1);}

C_noret_decl(trf_1885)
static void C_ccall trf_1885(C_word c,C_word *av) C_noret;
static void C_ccall trf_1885(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1885(t0,t1,t2);}

C_noret_decl(trf_1941)
static void C_ccall trf_1941(C_word c,C_word *av) C_noret;
static void C_ccall trf_1941(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1941(t0,t1);}

C_noret_decl(trf_1944)
static void C_ccall trf_1944(C_word c,C_word *av) C_noret;
static void C_ccall trf_1944(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1944(t0,t1);}

C_noret_decl(trf_1953)
static void C_ccall trf_1953(C_word c,C_word *av) C_noret;
static void C_ccall trf_1953(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_1953(t0,t1,t2,t3,t4);}

C_noret_decl(trf_756)
static void C_ccall trf_756(C_word c,C_word *av) C_noret;
static void C_ccall trf_756(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_756(t0,t1,t2,t3,t4);}

C_noret_decl(trf_797)
static void C_ccall trf_797(C_word c,C_word *av) C_noret;
static void C_ccall trf_797(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_797(t0,t1,t2,t3);}

C_noret_decl(trf_888)
static void C_ccall trf_888(C_word c,C_word *av) C_noret;
static void C_ccall trf_888(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_888(t0,t1);}

C_noret_decl(trf_914)
static void C_ccall trf_914(C_word c,C_word *av) C_noret;
static void C_ccall trf_914(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_914(t0,t1);}

/* k998 in chicken.file#create-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1000(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_1000,c,av);}
a=C_alloc(10);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(((C_word*)t0)[4])){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1010,a[2]=((C_word*)t0)[5],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1054,a[2]=((C_word*)t0)[3],a[3]=((C_word)li10),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1060,a[2]=((C_word)li11),tmp=(C_word)a,a+=3,tmp);
/* file.scm:193: ##sys#call-with-values */{
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
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1083,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* file.scm:184: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[16]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[16]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[31];
tp(4,av2);}}}}

/* k1008 in k998 in chicken.file#create-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1010(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_1010,c,av);}
a=C_alloc(6);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1012,a[2]=t3,a[3]=((C_word)li9),tmp=(C_word)a,a+=4,tmp));
t5=((C_word*)t3)[1];
f_1012(t5,((C_word*)t0)[2],t1);}

/* loop in k1008 in k998 in chicken.file#create-directory in k742 in k739 in k736 in k733 */
static void C_fcall f_1012(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_1012,3,t0,t1,t2);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1019,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t2)){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1052,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* file.scm:195: directory-exists? */
t5=*((C_word*)lf[11]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t4=t3;
f_1019(t4,C_SCHEME_FALSE);}}

/* k1017 in loop in k1008 in k998 in chicken.file#create-directory in k742 in k739 in k736 in k733 */
static void C_fcall f_1019(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_1019,2,t0,t1);}
a=C_alloc(8);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1022,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1045,a[2]=((C_word*)t0)[4],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* file.scm:196: chicken.pathname#pathname-directory */
t4=*((C_word*)lf[33]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k1020 in k1017 in loop in k1008 in k998 in chicken.file#create-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1022(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_1022,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1038,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* file.scm:184: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[16]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[16]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[31];
tp(4,av2);}}

/* k1036 in k1020 in k1017 in loop in k1008 in k998 in chicken.file#create-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1038(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_1038,c,av);}
a=C_alloc(3);
t2=C_eqp(C_fix(0),C_mkdir(t1));
if(C_truep(t2)){
t3=C_SCHEME_UNDEFINED;
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* file.scm:185: posix-error */
f_756(((C_word*)t0)[2],lf[14],lf[31],lf[32],C_a_i_list(&a,1,((C_word*)t0)[3]));}}

/* k1043 in k1017 in loop in k1008 in k998 in chicken.file#create-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1045(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1045,c,av);}
/* file.scm:196: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1012(t2,((C_word*)t0)[3],t1);}

/* k1050 in loop in k1008 in k998 in chicken.file#create-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1052(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1052,c,av);}
t2=((C_word*)t0)[2];
f_1019(t2,C_i_not(t1));}

/* a1053 in k998 in chicken.file#create-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1054(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1054,c,av);}
/* file.scm:193: chicken.pathname#decompose-pathname */
t2=*((C_word*)lf[34]+1);{
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

/* a1059 in k998 in chicken.file#create-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1060(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1060,c,av);}
if(C_truep(t3)){
/* file.scm:194: chicken.pathname#make-pathname */
t5=*((C_word*)lf[35]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k1081 in k998 in chicken.file#create-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1083(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_1083,c,av);}
a=C_alloc(3);
t2=C_eqp(C_fix(0),C_mkdir(t1));
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* file.scm:185: posix-error */
f_756(((C_word*)t0)[4],lf[14],lf[31],lf[32],C_a_i_list(&a,1,((C_word*)t0)[3]));}}

/* chicken.file#delete-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1101(C_word c,C_word *av){
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
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,6)))){
C_save_and_reclaim((void *)f_1101,c,av);}
a=C_alloc(8);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1107,a[2]=((C_word)li13),tmp=(C_word)a,a+=3,tmp);
t6=C_i_check_string_2(t2,lf[37]);
if(C_truep(t4)){
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1130,a[2]=t5,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* file.scm:209: find-files */
t8=*((C_word*)lf[40]+1);{
C_word av2[7];
av2[0]=t8;
av2[1]=t7;
av2[2]=t2;
av2[3]=lf[41];
av2[4]=C_SCHEME_TRUE;
av2[5]=lf[42];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(7,av2);}}
else{
/* file.scm:221: rmdir */
f_1107(t1,t2);}}

/* rmdir in chicken.file#delete-directory in k742 in k739 in k736 in k733 */
static void C_fcall f_1107(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_1107,2,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1111,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* file.scm:204: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[16]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[16]+1);
av2[1]=t3;
av2[2]=t2;
tp(3,av2);}}

/* k1109 in rmdir in chicken.file#delete-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1111(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_1111,c,av);}
a=C_alloc(3);
t2=C_eqp(C_fix(0),C_rmdir(t1));
if(C_truep(t2)){
t3=C_SCHEME_UNDEFINED;
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* file.scm:206: posix-error */
f_756(((C_word*)t0)[2],lf[14],lf[37],lf[38],C_a_i_list(&a,1,((C_word*)t0)[3]));}}

/* k1128 in chicken.file#delete-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1130(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_1130,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1131,a[2]=((C_word*)t0)[2],a[3]=((C_word)li14),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1156,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1161,a[2]=t5,a[3]=t2,a[4]=((C_word)li15),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_1161(t7,t3,t1);}

/* g274 in k1128 in chicken.file#delete-directory in k742 in k739 in k736 in k733 */
static void C_fcall f_1131(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_1131,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1144,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* file.scm:181: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[16]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[16]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[37];
tp(4,av2);}}

/* k1142 in g274 in k1128 in chicken.file#delete-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1144(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1144,c,av);}
a=C_alloc(5);
if(C_truep(C_u_i_symbolic_linkp(t1))){
t2=*((C_word*)lf[39]+1);
t3=*((C_word*)lf[39]+1);
/* file.scm:214: g284 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[39]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[39]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1153,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* file.scm:216: directory-exists? */
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
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k1151 in k1142 in g274 in k1128 in chicken.file#delete-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1153(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1153,c,av);}
if(C_truep(t1)){
/* file.scm:214: g284 */
f_1107(((C_word*)t0)[3],((C_word*)t0)[4]);}
else{
t2=*((C_word*)lf[39]+1);
t3=*((C_word*)lf[39]+1);
/* file.scm:214: g284 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[39]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[39]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
tp(3,av2);}}}

/* k1154 in k1128 in chicken.file#delete-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1156(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1156,c,av);}
/* file.scm:220: rmdir */
f_1107(((C_word*)t0)[3],((C_word*)t0)[4]);}

/* for-each-loop273 in k1128 in chicken.file#delete-directory in k742 in k739 in k736 in k733 */
static void C_fcall f_1161(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1161,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1171,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* file.scm:213: g274 */
t4=((C_word*)t0)[3];
f_1131(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k1169 in for-each-loop273 in k1128 in chicken.file#delete-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1171(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1171,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_1161(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* chicken.file#delete-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1193(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1193,c,av);}
a=C_alloc(4);
t3=C_i_check_string_2(t2,lf[43]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1223,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* file.scm:228: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[16]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[16]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[43];
tp(4,av2);}}

/* k1204 in k1221 in chicken.file#delete-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1206(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1206,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k1208 in k1221 in chicken.file#delete-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1210(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_1210,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1214,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1218,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)strerror(errno));
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k1212 in k1208 in k1221 in chicken.file#delete-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1214(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_1214,c,av);}
/* file.scm:229: ##sys#signal-hook/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[14];
av2[3]=((C_word*)t0)[3];
av2[4]=lf[43];
av2[5]=t1;
av2[6]=((C_word*)t0)[4];
tp(7,av2);}}

/* k1216 in k1208 in k1221 in chicken.file#delete-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1218(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1218,c,av);}
/* file.scm:231: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[45];
av2[3]=t1;
tp(4,av2);}}

/* k1221 in chicken.file#delete-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1223(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_1223,c,av);}
a=C_alloc(8);
t2=C_eqp(C_fix(0),C_remove(t1));
if(C_truep(t2)){
t3=C_SCHEME_UNDEFINED;
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1206,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1210,a[2]=t3,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* file.scm:230: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[7]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[7]+1);
av2[1]=t4;
tp(2,av2);}}}

/* chicken.file#delete-file* in k742 in k739 in k736 in k733 */
static void C_ccall f_1225(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1225,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1232,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* file.scm:235: file-exists? */
t4=*((C_word*)lf[8]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k1230 in chicken.file#delete-file* in k742 in k739 in k736 in k733 */
static void C_ccall f_1232(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1232,c,av);}
if(C_truep(t1)){
/* file.scm:235: delete-file */
t2=*((C_word*)lf[39]+1);{
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
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.file#rename-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1237(C_word c,C_word *av){
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
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_1237,c,av);}
a=C_alloc(9);
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,4,t0));
t6=C_i_check_string_2(t2,lf[48]);
t7=C_i_check_string_2(t3,lf[48]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1250,a[2]=t1,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1283,a[2]=t8,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_not(t5))){
/* file.scm:240: file-exists? */
t10=*((C_word*)lf[8]+1);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
t10=t8;{
C_word *av2=av;
av2[0]=t10;
av2[1]=C_SCHEME_UNDEFINED;
f_1250(2,av2);}}}

/* k1248 in chicken.file#rename-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1250(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_1250,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1253,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1276,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* file.scm:244: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[16]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[16]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[48];
tp(4,av2);}}

/* k1251 in k1248 in chicken.file#rename-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1253(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1253,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k1261 in k1278 in k1274 in k1248 in chicken.file#rename-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1263(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_1263,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1267,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1271,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)strerror(errno));
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k1265 in k1261 in k1278 in k1274 in k1248 in chicken.file#rename-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1267(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_1267,c,av);}
/* file.scm:246: ##sys#signal-hook/errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[14];
av2[3]=((C_word*)t0)[3];
av2[4]=lf[48];
av2[5]=t1;
av2[6]=((C_word*)t0)[4];
av2[7]=((C_word*)t0)[5];
tp(8,av2);}}

/* k1269 in k1261 in k1278 in k1274 in k1248 in chicken.file#rename-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1271(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1271,c,av);}
/* file.scm:248: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[49];
av2[3]=t1;
tp(4,av2);}}

/* k1274 in k1248 in chicken.file#rename-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1276(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_1276,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1280,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* file.scm:245: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[16]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[16]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[48];
tp(4,av2);}}

/* k1278 in k1274 in k1248 in chicken.file#rename-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1280(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1280,c,av);}
a=C_alloc(5);
t2=C_eqp(C_fix(0),C_rename(((C_word*)t0)[2],t1));
if(C_truep(t2)){
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1263,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* file.scm:247: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[7]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[7]+1);
av2[1]=t3;
tp(2,av2);}}}

/* k1281 in chicken.file#rename-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1283(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1283,c,av);}
if(C_truep(t1)){
/* file.scm:241: ##sys#error */
t2=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[48];
av2[3]=lf[51];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_1250(2,av2);}}}

/* chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1300(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_1300,c,av);}
a=C_alloc(7);
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,4,t0));
t6=C_rest_nullp(c,4);
t7=C_rest_nullp(c,5);
t8=(C_truep(t7)?C_fix(1024):C_get_rest_arg(c,5,av,4,t0));
t9=C_rest_nullp(c,5);
t10=C_i_check_string_2(t2,lf[53]);
t11=C_i_check_string_2(t3,lf[53]);
t12=C_i_check_number_2(t8,lf[53]);
t13=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1325,a[2]=t8,a[3]=t1,a[4]=t3,a[5]=t2,a[6]=t5,tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_i_integerp(t8))){
if(C_truep(C_fixnum_greaterp(t8,C_fix(0)))){
t14=t13;{
C_word *av2=av;
av2[0]=t14;
av2[1]=C_SCHEME_UNDEFINED;
f_1325(2,av2);}}
else{
/* file.scm:256: ##sys#error */
t14=*((C_word*)lf[50]+1);{
C_word av2[5];
av2[0]=t14;
av2[1]=t13;
av2[2]=lf[53];
av2[3]=lf[64];
av2[4]=t8;
((C_proc)(void*)(*((C_word*)t14+1)))(5,av2);}}}
else{
/* file.scm:256: ##sys#error */
t14=*((C_word*)lf[50]+1);{
C_word av2[5];
av2[0]=t14;
av2[1]=t13;
av2[2]=lf[53];
av2[3]=lf[64];
av2[4]=t8;
((C_proc)(void*)(*((C_word*)t14+1)))(5,av2);}}}

/* k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1325(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_1325,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1328,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1391,a[2]=t2,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* file.scm:257: directory-exists? */
t4=*((C_word*)lf[11]+1);{
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

/* k1326 in k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1328(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_1328,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1331,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1379,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_not(((C_word*)t0)[6]))){
/* file.scm:259: file-exists? */
t4=*((C_word*)lf[8]+1);{
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
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_1331(2,av2);}}}

/* k1329 in k1326 in k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1331(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_1331,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1334,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* file.scm:261: scheme#open-input-file */
t3=*((C_word*)lf[61]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=lf[60];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k1332 in k1329 in k1326 in k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1334(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_1334,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1337,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* file.scm:262: scheme#open-output-file */
t3=*((C_word*)lf[59]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[60];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k1335 in k1332 in k1329 in k1326 in k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1337(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_1337,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1340,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* file.scm:263: scheme#make-string */
t3=*((C_word*)lf[58]+1);{
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

/* k1338 in k1335 in k1332 in k1329 in k1326 in k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1340(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_1340,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1347,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* file.scm:264: chicken.io#read-string! */
t3=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=t1;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k1345 in k1338 in k1335 in k1332 in k1329 in k1326 in k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_1347,c,av);}
a=C_alloc(10);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1349,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word)li20),tmp=(C_word)a,a+=8,tmp));
t5=((C_word*)t3)[1];
f_1349(t5,((C_word*)t0)[6],t1,C_fix(0));}

/* loop in k1345 in k1338 in k1335 in k1332 in k1329 in k1326 in k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_fcall f_1349(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,4)))){
C_save_and_reclaim_args((void *)trf_1349,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_eqp(C_fix(0),t2);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1359,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* file.scm:268: scheme#close-input-port */
t6=*((C_word*)lf[55]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1365,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[3],tmp=(C_word)a,a+=9,tmp);
/* file.scm:272: chicken.io#write-string */
t6=*((C_word*)lf[57]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[6];
av2[3]=t2;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}}

/* k1357 in loop in k1345 in k1338 in k1335 in k1332 in k1329 in k1326 in k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1359(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1359,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1362,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* file.scm:269: scheme#close-output-port */
t3=*((C_word*)lf[54]+1);{
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

/* k1360 in k1357 in loop in k1345 in k1338 in k1335 in k1332 in k1329 in k1326 in k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1362(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1362,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k1363 in loop in k1345 in k1338 in k1335 in k1332 in k1329 in k1326 in k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1365(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1365,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1372,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* file.scm:273: chicken.io#read-string! */
t3=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)t0)[7];
av2[4]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k1370 in k1363 in loop in k1345 in k1338 in k1335 in k1332 in k1329 in k1326 in k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1372(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1372,c,av);}
/* file.scm:273: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1349(t2,((C_word*)t0)[3],t1,C_fixnum_plus(((C_word*)t0)[4],((C_word*)t0)[5]));}

/* k1377 in k1326 in k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1379(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1379,c,av);}
if(C_truep(t1)){
/* file.scm:260: ##sys#error */
t2=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[53];
av2[3]=lf[62];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_1331(2,av2);}}}

/* k1389 in k1323 in chicken.file#copy-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1391(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1391,c,av);}
if(C_truep(t1)){
/* file.scm:258: ##sys#error */
t2=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[53];
av2[3]=lf[63];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_1328(2,av2);}}}

/* chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1430(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_1430,c,av);}
a=C_alloc(7);
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,4,t0));
t6=C_rest_nullp(c,4);
t7=C_rest_nullp(c,5);
t8=(C_truep(t7)?C_fix(1024):C_get_rest_arg(c,5,av,4,t0));
t9=C_rest_nullp(c,5);
t10=C_i_check_string_2(t2,lf[66]);
t11=C_i_check_string_2(t3,lf[66]);
t12=C_i_check_number_2(t8,lf[66]);
t13=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1455,a[2]=t2,a[3]=t8,a[4]=t1,a[5]=t3,a[6]=t5,tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_i_integerp(t8))){
if(C_truep(C_fixnum_greaterp(t8,C_fix(0)))){
t14=t13;{
C_word *av2=av;
av2[0]=t14;
av2[1]=C_SCHEME_UNDEFINED;
f_1455(2,av2);}}
else{
/* file.scm:280: ##sys#error */
t14=*((C_word*)lf[50]+1);{
C_word av2[5];
av2[0]=t14;
av2[1]=t13;
av2[2]=lf[66];
av2[3]=lf[69];
av2[4]=t8;
((C_proc)(void*)(*((C_word*)t14+1)))(5,av2);}}}
else{
/* file.scm:280: ##sys#error */
t14=*((C_word*)lf[50]+1);{
C_word av2[5];
av2[0]=t14;
av2[1]=t13;
av2[2]=lf[66];
av2[3]=lf[69];
av2[4]=t8;
((C_proc)(void*)(*((C_word*)t14+1)))(5,av2);}}}

/* k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1455(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_1455,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1458,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1524,a[2]=t2,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* file.scm:281: directory-exists? */
t4=*((C_word*)lf[11]+1);{
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

/* k1456 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1458(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_1458,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1461,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1512,a[2]=t2,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_not(((C_word*)t0)[6]))){
/* file.scm:283: file-exists? */
t4=*((C_word*)lf[8]+1);{
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
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_1461(2,av2);}}}

/* k1459 in k1456 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1461(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_1461,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1464,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* file.scm:285: scheme#open-input-file */
t3=*((C_word*)lf[61]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[60];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k1462 in k1459 in k1456 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1464(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_1464,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1467,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* file.scm:286: scheme#open-output-file */
t3=*((C_word*)lf[59]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=lf[60];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k1465 in k1462 in k1459 in k1456 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1467(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_1467,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1470,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* file.scm:287: scheme#make-string */
t3=*((C_word*)lf[58]+1);{
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

/* k1468 in k1465 in k1462 in k1459 in k1456 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1470(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_1470,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1477,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* file.scm:288: chicken.io#read-string! */
t3=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=t1;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k1475 in k1468 in k1465 in k1462 in k1459 in k1456 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1477(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_1477,c,av);}
a=C_alloc(11);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1479,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t3,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word)li22),tmp=(C_word)a,a+=9,tmp));
t5=((C_word*)t3)[1];
f_1479(t5,((C_word*)t0)[7],t1,C_fix(0));}

/* loop in k1475 in k1468 in k1465 in k1462 in k1459 in k1456 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_fcall f_1479(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,4)))){
C_save_and_reclaim_args((void *)trf_1479,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_eqp(C_fix(0),t2);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1489,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* file.scm:292: scheme#close-input-port */
t6=*((C_word*)lf[55]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1498,a[2]=((C_word*)t0)[5],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[4],tmp=(C_word)a,a+=9,tmp);
/* file.scm:297: chicken.io#write-string */
t6=*((C_word*)lf[57]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[7];
av2[3]=t2;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}}

/* k1487 in loop in k1475 in k1468 in k1465 in k1462 in k1459 in k1456 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1489(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1489,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1492,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* file.scm:293: scheme#close-output-port */
t3=*((C_word*)lf[54]+1);{
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

/* k1490 in k1487 in loop in k1475 in k1468 in k1465 in k1462 in k1459 in k1456 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1492(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1492,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1495,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* file.scm:294: delete-file */
t3=*((C_word*)lf[39]+1);{
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

/* k1493 in k1490 in k1487 in loop in k1475 in k1468 in k1465 in k1462 in k1459 in k1456 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1495(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1495,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k1496 in loop in k1475 in k1468 in k1465 in k1462 in k1459 in k1456 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1498(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1498,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1505,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* file.scm:298: chicken.io#read-string! */
t3=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)t0)[7];
av2[4]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k1503 in k1496 in loop in k1475 in k1468 in k1465 in k1462 in k1459 in k1456 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1505(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1505,c,av);}
/* file.scm:298: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1479(t2,((C_word*)t0)[3],t1,C_fixnum_plus(((C_word*)t0)[4],((C_word*)t0)[5]));}

/* k1510 in k1456 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1512(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1512,c,av);}
if(C_truep(t1)){
/* file.scm:284: ##sys#error */
t2=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[66];
av2[3]=lf[67];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_1461(2,av2);}}}

/* k1522 in k1453 in chicken.file#move-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1524(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1524,c,av);}
if(C_truep(t1)){
/* file.scm:282: ##sys#error */
t2=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[66];
av2[3]=lf[68];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_1458(2,av2);}}}

/* tempdir in k742 in k739 in k736 in k733 */
static void C_fcall f_1563(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_1563,1,t1);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1567,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* file.scm:309: chicken.process-context#get-environment-variable */
t3=*((C_word*)lf[74]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[79];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k1565 in tempdir in k742 in k739 in k736 in k733 */
static void C_ccall f_1567(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1567,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1573,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* file.scm:310: chicken.process-context#get-environment-variable */
t3=*((C_word*)lf[74]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[78];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k1571 in k1565 in tempdir in k742 in k739 in k736 in k733 */
static void C_ccall f_1573(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1573,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1579,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* file.scm:311: chicken.process-context#get-environment-variable */
t3=*((C_word*)lf[74]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[77];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k1577 in k1571 in k1565 in tempdir in k742 in k739 in k736 in k733 */
static void C_ccall f_1579(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1579,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(*((C_word*)lf[71]+1))){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1588,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* file.scm:313: chicken.process-context#get-environment-variable */
t3=*((C_word*)lf[74]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[75];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[76];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}}

/* k1586 in k1577 in k1571 in k1565 in tempdir in k742 in k739 in k736 in k733 */
static void C_ccall f_1588(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1588,c,av);}
if(C_truep(t1)){
/* file.scm:315: string-append */
t2=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[72];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[73];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.file#create-temporary-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1596(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_1596,c,av);}
a=C_alloc(9);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?lf[81]:C_get_rest_arg(c,2,av,2,t0));
t4=C_i_check_string_2(t3,lf[82]);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1608,a[2]=t6,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word)li26),tmp=(C_word)a,a+=7,tmp));
t8=((C_word*)t6)[1];
f_1608(t8,t1);}

/* loop in chicken.file#create-temporary-file in k742 in k739 in k736 in k733 */
static void C_fcall f_1608(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_1608,2,t0,t1);}
a=C_alloc(10);
t2=C_random_fixnum(C_fix(65536));
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1614,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1633,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* file.scm:325: tempdir */
f_1563(t4);}

/* k1612 in loop in chicken.file#create-temporary-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1614(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1614,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1620,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* file.scm:332: file-exists? */
t3=*((C_word*)lf[8]+1);{
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

/* k1618 in k1612 in loop in chicken.file#create-temporary-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_1620,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
/* file.scm:333: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1608(t2,((C_word*)t0)[3]);}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1628,a[2]=((C_word*)t0)[4],a[3]=((C_word)li25),tmp=(C_word)a,a+=4,tmp);
/* file.scm:334: scheme#call-with-output-file */
t3=*((C_word*)lf[83]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* a1627 in k1618 in k1612 in loop in chicken.file#create-temporary-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1628(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1628,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k1631 in loop in chicken.file#create-temporary-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1633(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_1633,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1637,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1641,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[85]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[85]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=C_fix(16);
tp(4,av2);}}

/* k1635 in k1631 in loop in chicken.file#create-temporary-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1637(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1637,c,av);}
/* file.scm:324: chicken.pathname#make-pathname */
t2=*((C_word*)lf[35]+1);{
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

/* k1639 in k1631 in loop in chicken.file#create-temporary-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1641(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1641,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1645,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* file.scm:330: ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[85]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[85]+1);
av2[1]=t2;
av2[2]=stub428(C_SCHEME_UNDEFINED);
tp(3,av2);}}

/* k1643 in k1639 in k1631 in loop in chicken.file#create-temporary-file in k742 in k739 in k736 in k733 */
static void C_ccall f_1645(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_1645,c,av);}
/* file.scm:326: string-append */
t2=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=lf[84];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* chicken.file#create-temporary-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1659(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_1659,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1665,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word)li28),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_1665(t5,t1);}

/* loop in chicken.file#create-temporary-directory in k742 in k739 in k736 in k733 */
static void C_fcall f_1665(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_1665,2,t0,t1);}
a=C_alloc(9);
t2=C_random_fixnum(C_fix(65536));
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1671,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1705,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* file.scm:341: tempdir */
f_1563(t4);}

/* k1669 in loop in chicken.file#create-temporary-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1671(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1671,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1677,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* file.scm:347: file-exists? */
t3=*((C_word*)lf[8]+1);{
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

/* k1675 in k1669 in loop in chicken.file#create-temporary-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1677(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_1677,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
/* file.scm:348: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1665(t2,((C_word*)t0)[3]);}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1684,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* file.scm:349: ##sys#make-c-string */
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
av2[3]=lf[88];
tp(4,av2);}}}

/* k1682 in k1675 in k1669 in loop in chicken.file#create-temporary-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1684(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1684,c,av);}
a=C_alloc(10);
t2=C_mkdir(t1);
t3=C_eqp(t2,C_fix(0));
if(C_truep(t3)){
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1697,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1701,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t6=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_mpointer(&a,(void*)strerror(errno));
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}}

/* k1695 in k1682 in k1675 in k1669 in loop in chicken.file#create-temporary-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1697(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_1697,c,av);}
/* file.scm:352: ##sys#signal-hook */
t2=*((C_word*)lf[87]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[14];
av2[3]=lf[88];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k1699 in k1682 in k1675 in k1669 in loop in chicken.file#create-temporary-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1701(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1701,c,av);}
/* file.scm:354: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[44]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[44]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[89];
av2[3]=t1;
tp(4,av2);}}

/* k1703 in loop in chicken.file#create-temporary-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1705(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_1705,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1709,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1713,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[85]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[85]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(16);
tp(4,av2);}}

/* k1707 in k1703 in loop in chicken.file#create-temporary-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1709(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1709,c,av);}
/* file.scm:340: chicken.pathname#make-pathname */
t2=*((C_word*)lf[35]+1);{
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

/* k1711 in k1703 in loop in chicken.file#create-temporary-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1713(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1713,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1717,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* file.scm:346: ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[85]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[85]+1);
av2[1]=t2;
av2[2]=stub437(C_SCHEME_UNDEFINED);
tp(3,av2);}}

/* k1715 in k1711 in k1703 in loop in chicken.file#create-temporary-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_1717(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_1717,c,av);}
/* file.scm:342: string-append */
t2=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=lf[90];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1725(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +6,c,3)))){
C_save_and_reclaim((void*)f_1725,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+6);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
C_word t6;
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1731,a[2]=t4,a[3]=((C_word)li41),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_1731(t6,t1,t2);}

/* conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_fcall f_1731(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,5)))){
C_save_and_reclaim_args((void *)trf_1731,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1746,a[2]=t3,a[3]=((C_word)li30),tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1752,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word)li40),tmp=(C_word)a,a+=5,tmp);
/* file.scm:365: ##sys#call-with-values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=t4;
av2[3]=t5;
C_call_with_values(4,av2);}}}

/* a1745 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1746(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1746,c,av);}
/* file.scm:365: chicken.pathname#decompose-pathname */
t2=*((C_word*)lf[34]+1);{
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

/* a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1752(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_1752,c,av);}
a=C_alloc(13);
t5=(C_truep(t2)?t2:lf[92]);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1759,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=t1,a[6]=t5,tmp=(C_word)a,a+=7,tmp);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1906,a[2]=t6,tmp=(C_word)a,a+=3,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1910,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
if(C_truep(t3)){
/* file.scm:367: chicken.pathname#make-pathname */
t9=*((C_word*)lf[35]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=C_SCHEME_FALSE;
av2[3]=t3;
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}
else{
/* file.scm:367: chicken.pathname#make-pathname */
t9=*((C_word*)lf[35]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=C_SCHEME_FALSE;
av2[3]=lf[103];
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}}

/* k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1759(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_1759,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1766,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1830,a[2]=((C_word*)t0)[6],a[3]=((C_word)li39),tmp=(C_word)a,a+=4,tmp);
/* file.scm:368: scheme#call-with-current-continuation */
t4=*((C_word*)lf[100]+1);{
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

/* k1764 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1766(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_1766,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1769,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* file.scm:368: g491 */
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k1767 in k1764 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1769(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_1769,c,av);}
a=C_alloc(10);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1771,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word)li32),tmp=(C_word)a,a+=8,tmp));
t5=((C_word*)t3)[1];
f_1771(t5,((C_word*)t0)[6],t1);}

/* loop in k1767 in k1764 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_fcall f_1771(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_1771,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_i_pairp(t2);
if(C_truep(C_i_not(t3))){
/* file.scm:370: conc-loop */
t4=((C_word*)((C_word*)t0)[2])[1];
f_1731(t4,t1,C_i_cdr(((C_word*)t0)[3]));}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1788,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* file.scm:371: chicken.irregex#irregex-match */
t5=*((C_word*)lf[94]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[6];
av2[3]=C_i_car(t2);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k1786 in loop in k1767 in k1764 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1788(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_1788,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1792,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word)li31),tmp=(C_word)a,a+=6,tmp);
/* file.scm:370: g477 */
t3=t2;
f_1792(t3,((C_word*)t0)[5],t1);}
else{
/* file.scm:375: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1771(t2,((C_word*)t0)[5],C_u_i_cdr(((C_word*)t0)[3]));}}

/* g477 in k1786 in loop in k1767 in k1764 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_fcall f_1792(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_1792,3,t0,t1,t2);}
a=C_alloc(9);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1800,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1812,a[2]=t3,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* file.scm:373: chicken.irregex#irregex-match-substring */
t5=*((C_word*)lf[93]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k1798 in g477 in k1786 in loop in k1767 in k1764 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1800(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1800,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1804,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* file.scm:374: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_1771(t3,t2,C_i_cdr(((C_word*)t0)[4]));}

/* k1802 in k1798 in g477 in k1786 in loop in k1767 in k1764 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1804(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_1804,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k1810 in g477 in k1786 in loop in k1767 in k1764 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1812(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1812,c,av);}
/* file.scm:373: chicken.pathname#make-pathname */
t2=*((C_word*)lf[35]+1);{
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

/* a1829 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1830(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_1830,c,av);}
a=C_alloc(9);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1836,a[2]=t2,a[3]=((C_word)li34),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1878,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word)li38),tmp=(C_word)a,a+=5,tmp);
/* file.scm:368: chicken.condition#with-exception-handler */
t5=*((C_word*)lf[99]+1);{
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

/* a1835 in a1829 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1836(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1836,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1842,a[2]=t2,a[3]=((C_word)li33),tmp=(C_word)a,a+=4,tmp);
/* file.scm:368: k488 */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a1841 in a1835 in a1829 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1842(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1842,c,av);}
t2=C_i_structurep(((C_word*)t0)[2],lf[95]);
t3=(C_truep(t2)?C_slot(((C_word*)t0)[2],C_fix(1)):C_SCHEME_FALSE);
if(C_truep(t3)){
if(C_truep(C_i_memq(lf[96],t3))){
if(C_truep(C_i_memq(lf[97],t3))){
if(C_truep(C_i_memq(lf[0],t3))){
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* file.scm:368: chicken.condition#signal */
t4=*((C_word*)lf[98]+1);{
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
else{
/* file.scm:368: chicken.condition#signal */
t4=*((C_word*)lf[98]+1);{
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
else{
/* file.scm:368: chicken.condition#signal */
t4=*((C_word*)lf[98]+1);{
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
else{
/* file.scm:368: chicken.condition#signal */
t4=*((C_word*)lf[98]+1);{
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

/* a1877 in a1829 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1878(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_1878,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1880,a[2]=((C_word*)t0)[2],a[3]=((C_word)li35),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1885,a[2]=((C_word*)t0)[3],a[3]=((C_word)li37),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1902,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* tmp1725 */
t5=t2;
f_1880(t5,t4);}

/* tmp1725 in a1877 in a1829 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_fcall f_1880(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_1880,2,t0,t1);}
/* file.scm:368: directory */
t2=*((C_word*)lf[23]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* tmp2726 in a1877 in a1829 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_fcall f_1885(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_1885,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1891,a[2]=t2,a[3]=((C_word)li36),tmp=(C_word)a,a+=4,tmp);
/* file.scm:368: k488 */
t4=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a1890 in tmp2726 in a1877 in a1829 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1891(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1891,c,av);}{
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

/* k1900 in a1877 in a1829 in k1757 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1902(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1902,c,av);}
a=C_alloc(3);
/* tmp2726 */
t2=((C_word*)t0)[2];
f_1885(t2,((C_word*)t0)[3],C_a_i_list(&a,1,t1));}

/* k1904 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1906(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1906,c,av);}
/* file.scm:367: chicken.irregex#irregex */
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

/* k1908 in a1751 in conc-loop in chicken.file#glob in k742 in k739 in k736 in k733 */
static void C_ccall f_1910(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1910,c,av);}
/* file.scm:367: chicken.irregex#glob->sre */
t2=*((C_word*)lf[102]+1);{
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

/* chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_1916(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +8,c,4)))){
C_save_and_reclaim((void*)f_1916,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+8);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1920,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2139,a[2]=((C_word)li57),tmp=(C_word)a,a+=3,tmp);
/* file.scm:380: ##sys#get-keyword */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[108]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[108]+1);
av2[1]=t4;
av2[2]=lf[112];
av2[3]=t3;
av2[4]=t5;
tp(5,av2);}}

/* k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_1920(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_1920,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1923,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2131,a[2]=((C_word)li55),tmp=(C_word)a,a+=3,tmp);
/* file.scm:380: ##sys#get-keyword */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[108]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[108]+1);
av2[1]=t2;
av2[2]=lf[111];
av2[3]=((C_word*)t0)[4];
av2[4]=t3;
tp(5,av2);}}

/* k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_1923(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_1923,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1926,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2128,a[2]=((C_word)li53),tmp=(C_word)a,a+=3,tmp);
/* file.scm:380: ##sys#get-keyword */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[108]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[108]+1);
av2[1]=t2;
av2[2]=lf[110];
av2[3]=((C_word*)t0)[5];
av2[4]=t3;
tp(5,av2);}}

/* k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_1926(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_1926,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1929,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2125,a[2]=((C_word)li52),tmp=(C_word)a,a+=3,tmp);
/* file.scm:380: ##sys#get-keyword */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[108]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[108]+1);
av2[1]=t2;
av2[2]=lf[109];
av2[3]=((C_word*)t0)[6];
av2[4]=t3;
tp(5,av2);}}

/* k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_1929(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_1929,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1932,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2122,a[2]=((C_word)li51),tmp=(C_word)a,a+=3,tmp);
/* file.scm:380: ##sys#get-keyword */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[108]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[108]+1);
av2[1]=t2;
av2[2]=lf[41];
av2[3]=((C_word*)t0)[7];
av2[4]=t3;
tp(5,av2);}}

/* k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_1932(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_1932,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1935,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2119,a[2]=((C_word)li50),tmp=(C_word)a,a+=3,tmp);
/* file.scm:380: ##sys#get-keyword */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[108]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[108]+1);
av2[1]=t2;
av2[2]=lf[42];
av2[3]=((C_word*)t0)[8];
av2[4]=t3;
tp(5,av2);}}

/* k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_1935(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,2)))){
C_save_and_reclaim((void *)f_1935,c,av);}
a=C_alloc(17);
t2=C_i_check_string_2(((C_word*)t0)[2],lf[104]);
t3=C_fix(0);
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_1941,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t4,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[2],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],tmp=(C_word)a,a+=10,tmp);
if(C_truep(C_i_not(((C_word*)t0)[8]))){
t6=t5;
f_1941(t6,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2105,a[2]=((C_word)li48),tmp=(C_word)a,a+=3,tmp));}
else{
if(C_truep(C_fixnump(((C_word*)t0)[8]))){
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2113,a[2]=t4,a[3]=((C_word*)t0)[8],a[4]=((C_word)li49),tmp=(C_word)a,a+=5,tmp);
t7=t5;
f_1941(t7,t6);}
else{
t6=t5;
f_1941(t6,((C_word*)t0)[8]);}}}

/* k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_fcall f_1941(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,0,2)))){
C_save_and_reclaim_args((void *)trf_1941,2,t0,t1);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_1944,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
if(C_truep(C_i_closurep(((C_word*)t0)[9]))){
t3=t2;
f_1944(t3,((C_word*)t0)[9]);}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2096,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* file.scm:395: chicken.irregex#irregex */
t4=*((C_word*)lf[101]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[9];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_fcall f_1944(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,3)))){
C_save_and_reclaim_args((void *)trf_1944,2,t0,t1);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_1951,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* file.scm:398: directory */
t3=*((C_word*)lf[23]+1);{
C_word av2[4];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[8];
av2[3]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_1951(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,5)))){
C_save_and_reclaim((void *)f_1951,c,av);}
a=C_alloc(12);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_1953,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word)li46),tmp=(C_word)a,a+=10,tmp));
t5=((C_word*)t3)[1];
f_1953(t5,((C_word*)t0)[8],((C_word*)t0)[9],t1,((C_word*)t0)[10]);}

/* loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_fcall f_1953(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,0,3)))){
C_save_and_reclaim_args((void *)trf_1953,5,t0,t1,t2,t3,t4);}
a=C_alloc(14);
if(C_truep(C_i_nullp(t3))){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_slot(t3,C_fix(0));
t6=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_1966,a[2]=t3,a[3]=t5,a[4]=((C_word*)t0)[2],a[5]=t1,a[6]=t2,a[7]=t4,a[8]=((C_word*)t0)[3],a[9]=((C_word*)t0)[4],a[10]=((C_word*)t0)[5],a[11]=((C_word*)t0)[6],a[12]=((C_word*)t0)[7],a[13]=((C_word*)t0)[8],tmp=(C_word)a,a+=14,tmp);
/* file.scm:403: chicken.pathname#make-pathname */
t7=*((C_word*)lf[35]+1);{
C_word av2[4];
av2[0]=t7;
av2[1]=t6;
av2[2]=t2;
av2[3]=t5;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}

/* k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_1966(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_1966,c,av);}
a=C_alloc(15);
t2=C_slot(((C_word*)t0)[2],C_fix(1));
t3=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_1975,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=t2,a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t1,a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],tmp=(C_word)a,a+=15,tmp);
/* file.scm:405: directory-exists? */
t4=*((C_word*)lf[11]+1);{
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

/* k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_1975(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,4)))){
C_save_and_reclaim((void *)f_1975,c,av);}
a=C_alloc(14);
if(C_truep(t1)){
if(C_truep((C_truep(C_i_equalp(((C_word*)t0)[2],lf[105]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(((C_word*)t0)[2],lf[106]))?C_SCHEME_TRUE:C_SCHEME_FALSE)))){
/* file.scm:406: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_1953(t2,((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]);}
else{
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_2068,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[9],a[8]=((C_word*)t0)[10],a[9]=((C_word*)t0)[7],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],tmp=(C_word)a,a+=14,tmp);
/* file.scm:181: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[16]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[16]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[10];
av2[3]=lf[104];
tp(4,av2);}}}
else{
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2080,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[10],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* file.scm:417: pproc */
t3=((C_word*)t0)[11];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[10];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k1995 in k2066 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_1997(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1997,c,av);}
/* file.scm:408: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1953(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* k1998 in k2066 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2000(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2000,c,av);}
if(C_truep(t1)){
/* file.scm:408: action */
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
av2[3]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t2))(4,av2);}}
else{
/* file.scm:408: loop */
t2=((C_word*)((C_word*)t0)[6])[1];
f_1953(t2,((C_word*)t0)[7],((C_word*)t0)[8],((C_word*)t0)[9],((C_word*)t0)[5]);}}

/* k2007 in k2066 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2009(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2009,c,av);}
a=C_alloc(31);
if(C_truep(t1)){
t2=C_fixnum_plus(((C_word*)((C_word*)t0)[2])[1],C_fix(1));
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_SCHEME_FALSE;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2019,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2021,a[2]=t6,a[3]=((C_word*)t0)[2],a[4]=t4,a[5]=((C_word)li43),tmp=(C_word)a,a+=6,tmp);
t9=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2026,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[9],a[6]=((C_word*)t0)[10],a[7]=((C_word*)t0)[11],a[8]=((C_word)li44),tmp=(C_word)a,a+=9,tmp);
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2046,a[2]=t4,a[3]=((C_word*)t0)[2],a[4]=t6,a[5]=((C_word)li45),tmp=(C_word)a,a+=6,tmp);
/* file.scm:412: ##sys#dynamic-wind */
t11=*((C_word*)lf[107]+1);{
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
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2056,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_2059,a[2]=((C_word*)t0)[8],a[3]=t2,a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[9],a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],tmp=(C_word)a,a+=10,tmp);
/* file.scm:416: pproc */
t4=((C_word*)t0)[10];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k2017 in k2007 in k2066 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2019(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2019,c,av);}
/* file.scm:410: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1953(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* a2020 in k2007 in k2066 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2021(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2021,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)((C_word*)t0)[3])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,((C_word*)((C_word*)t0)[4])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a2025 in k2007 in k2066 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2026(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_2026,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2034,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* file.scm:414: directory */
t3=*((C_word*)lf[23]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2032 in a2025 in k2007 in k2066 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2034(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_2034,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2038,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2041,a[2]=((C_word*)t0)[5],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[3],a[8]=t1,tmp=(C_word)a,a+=9,tmp);
/* file.scm:415: pproc */
t4=((C_word*)t0)[7];{
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

/* k2036 in k2032 in a2025 in k2007 in k2066 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 in ... */
static void C_ccall f_2038(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2038,c,av);}
/* file.scm:413: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1953(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* k2039 in k2032 in a2025 in k2007 in k2066 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 in ... */
static void C_ccall f_2041(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2041,c,av);}
if(C_truep(t1)){
/* file.scm:415: action */
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
av2[3]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t2))(4,av2);}}
else{
/* file.scm:413: loop */
t2=((C_word*)((C_word*)t0)[6])[1];
f_1953(t2,((C_word*)t0)[7],((C_word*)t0)[4],((C_word*)t0)[8],((C_word*)t0)[5]);}}

/* a2045 in k2007 in k2066 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2046(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2046,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)((C_word*)t0)[3])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,((C_word*)((C_word*)t0)[4])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k2054 in k2007 in k2066 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2056(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2056,c,av);}
/* file.scm:416: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1953(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* k2057 in k2007 in k2066 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2059(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2059,c,av);}
if(C_truep(t1)){
/* file.scm:416: action */
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
av2[3]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t2))(4,av2);}}
else{
/* file.scm:416: loop */
t2=((C_word*)((C_word*)t0)[6])[1];
f_1953(t2,((C_word*)t0)[7],((C_word*)t0)[8],((C_word*)t0)[9],((C_word*)t0)[5]);}}

/* k2066 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2068(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_2068,c,av);}
a=C_alloc(16);
t2=(C_truep(C_u_i_symbolic_linkp(t1))?C_i_not(((C_word*)t0)[2]):C_SCHEME_FALSE);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1997,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_2000,a[2]=((C_word*)t0)[7],a[3]=t3,a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[9],a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],tmp=(C_word)a,a+=10,tmp);
/* file.scm:408: pproc */
t5=((C_word*)t0)[10];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_2009,a[2]=((C_word*)t0)[11],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[12],tmp=(C_word)a,a+=12,tmp);
/* file.scm:409: lproc */
t4=((C_word*)t0)[13];{
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

/* k2078 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2080(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_2080,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2087,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* file.scm:417: action */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=((C_word*)t0)[8];
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}
else{
/* file.scm:418: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1953(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[8]);}}

/* k2085 in k2078 in k1973 in k1964 in loop in k1949 in k1942 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2087(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2087,c,av);}
/* file.scm:417: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1953(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* k2094 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2096(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2096,c,av);}
a=C_alloc(4);
t2=((C_word*)t0)[2];
f_1944(t2,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2097,a[2]=t1,a[3]=((C_word)li47),tmp=(C_word)a,a+=4,tmp));}

/* f_2097 in k2094 in k1939 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2097(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2097,c,av);}
/* file.scm:396: chicken.irregex#irregex-match */
t3=*((C_word*)lf[94]+1);{
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

/* f_2105 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2105(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2105,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_2113 in k1933 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2113(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2113,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fixnum_lessp(((C_word*)((C_word*)t0)[2])[1],((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a2118 in k1930 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2119(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2119,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a2121 in k1927 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2122(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2122,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a2124 in k1924 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2125(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2125,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a2127 in k1921 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2128(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2128,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a2130 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2131(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_2131,c,av);}
a=C_alloc(3);
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2133,a[2]=((C_word)li54),tmp=(C_word)a,a+=3,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_2133 in a2130 in k1918 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2133(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2133,c,av);}
a=C_alloc(3);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_cons(&a,2,t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a2138 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2139(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2139,c,av);}
a=C_alloc(3);
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2141,a[2]=((C_word)li56),tmp=(C_word)a,a+=3,tmp);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_2141 in a2138 in chicken.file#find-files in k742 in k739 in k736 in k733 */
static void C_ccall f_2141(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2141,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k733 */
static void C_ccall f_735(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_735,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_738,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_irregex_toplevel(2,av2);}}

/* k736 in k733 */
static void C_ccall f_738(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_738,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_741,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_pathname_toplevel(2,av2);}}

/* k739 in k736 in k733 */
static void C_ccall f_741(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_741,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_744,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

/* k742 in k739 in k736 in k733 */
static void C_ccall f_744(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(64,c,6)))){
C_save_and_reclaim((void *)f_744,c,av);}
a=C_alloc(64);
t2=C_mutate(&lf[2] /* (set! chicken.file#posix-error ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_756,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t3=C_mutate((C_word*)lf[8]+1 /* (set! chicken.file#file-exists? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_773,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[11]+1 /* (set! chicken.file#directory-exists? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_785,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate(&lf[13] /* (set! chicken.file#test-access ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_797,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[17]+1 /* (set! chicken.file#file-readable? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_827,a[2]=((C_word)li4),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[19]+1 /* (set! chicken.file#file-writable? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_833,a[2]=((C_word)li5),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[21]+1 /* (set! chicken.file#file-executable? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_839,a[2]=((C_word)li6),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[23]+1 /* (set! chicken.file#directory ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_845,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[30]+1 /* (set! chicken.file#create-directory ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_984,a[2]=((C_word)li12),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[36]+1 /* (set! chicken.file#delete-directory ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1101,a[2]=((C_word)li16),tmp=(C_word)a,a+=3,tmp));
t12=C_mutate((C_word*)lf[39]+1 /* (set! chicken.file#delete-file ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1193,a[2]=((C_word)li17),tmp=(C_word)a,a+=3,tmp));
t13=C_mutate((C_word*)lf[46]+1 /* (set! chicken.file#delete-file* ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1225,a[2]=((C_word)li18),tmp=(C_word)a,a+=3,tmp));
t14=C_mutate((C_word*)lf[47]+1 /* (set! chicken.file#rename-file ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1237,a[2]=((C_word)li19),tmp=(C_word)a,a+=3,tmp));
t15=C_mutate((C_word*)lf[52]+1 /* (set! chicken.file#copy-file ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1300,a[2]=((C_word)li21),tmp=(C_word)a,a+=3,tmp));
t16=C_mutate((C_word*)lf[65]+1 /* (set! chicken.file#move-file ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1430,a[2]=((C_word)li23),tmp=(C_word)a,a+=3,tmp));
t17=lf[70];
t18=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1563,a[2]=((C_word)li24),tmp=(C_word)a,a+=3,tmp);
t19=C_mutate((C_word*)lf[80]+1 /* (set! chicken.file#create-temporary-file ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1596,a[2]=t17,a[3]=t18,a[4]=((C_word)li27),tmp=(C_word)a,a+=5,tmp));
t20=C_mutate((C_word*)lf[86]+1 /* (set! chicken.file#create-temporary-directory ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1659,a[2]=t17,a[3]=t18,a[4]=((C_word)li29),tmp=(C_word)a,a+=5,tmp));
t21=C_mutate((C_word*)lf[91]+1 /* (set! chicken.file#glob ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1725,a[2]=((C_word)li42),tmp=(C_word)a,a+=3,tmp));
t22=C_mutate((C_word*)lf[40]+1 /* (set! chicken.file#find-files ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1916,a[2]=((C_word)li58),tmp=(C_word)a,a+=3,tmp));
t23=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t23;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t23+1)))(2,av2);}}

/* chicken.file#posix-error in k742 in k739 in k736 in k733 */
static void C_fcall f_756(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_756,5,t1,t2,t3,t4,t5);}
a=C_alloc(7);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_760,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=t5,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* file.scm:118: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[7]+1));
C_word av2[2];
av2[0]=*((C_word*)lf[7]+1);
av2[1]=t6;
tp(2,av2);}}

/* k758 in chicken.file#posix-error in k742 in k739 in k736 in k733 */
static void C_ccall f_760(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_760,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_767,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_771,a[2]=t2,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t1);
/* file.scm:115: ##sys#peek-c-string */
t6=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=stub142(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k765 in k758 in chicken.file#posix-error in k742 in k739 in k736 in k733 */
static void C_ccall f_767(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_767,c,av);}{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[3]+1);
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
av2[5]=((C_word*)t0)[5];
av2[6]=t1;
av2[7]=((C_word*)t0)[6];
C_apply(8,av2);}}

/* k769 in k758 in chicken.file#posix-error in k742 in k739 in k736 in k733 */
static void C_ccall f_771(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_771,c,av);}
/* file.scm:120: string-append */
t2=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[5];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* chicken.file#file-exists? in k742 in k739 in k736 in k733 */
static void C_ccall f_773(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_773,c,av);}
a=C_alloc(4);
t3=C_i_check_string_2(t2,lf[9]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_783,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* file.scm:127: ##sys#file-exists? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[10]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[9];
tp(6,av2);}}

/* k781 in chicken.file#file-exists? in k742 in k739 in k736 in k733 */
static void C_ccall f_783(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_783,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?((C_word*)t0)[3]:C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file#directory-exists? in k742 in k739 in k736 in k733 */
static void C_ccall f_785(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_785,c,av);}
a=C_alloc(4);
t3=C_i_check_string_2(t2,lf[12]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_795,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* file.scm:131: ##sys#file-exists? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[10]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
av2[5]=lf[12];
tp(6,av2);}}

/* k793 in chicken.file#directory-exists? in k742 in k739 in k736 in k733 */
static void C_ccall f_795(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_795,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?((C_word*)t0)[3]:C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file#test-access in k742 in k739 in k736 in k733 */
static void C_fcall f_797(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_797,4,t1,t2,t3,t4);}
a=C_alloc(6);
t5=C_i_check_string_2(t2,t4);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_805,a[2]=t3,a[3]=t1,a[4]=t4,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* file.scm:142: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[16]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[16]+1);
av2[1]=t6;
av2[2]=t2;
av2[3]=t4;
tp(4,av2);}}

/* k803 in chicken.file#test-access in k742 in k739 in k736 in k733 */
static void C_ccall f_805(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_805,c,av);}
a=C_alloc(5);
t2=C_test_access(t1,((C_word*)t0)[2]);
t3=C_eqp(t2,C_fix(0));
if(C_truep(t3)){
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_824,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* file.scm:144: ##sys#update-errno */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[7]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[7]+1);
av2[1]=t4;
tp(2,av2);}}}

/* k822 in k803 in chicken.file#test-access in k742 in k739 in k736 in k733 */
static void C_ccall f_824(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_824,c,av);}
a=C_alloc(3);
t2=C_fix((C_word)EACCES);
t3=C_eqp(t1,t2);
if(C_truep(t3)){
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* file.scm:146: posix-error */
f_756(((C_word*)t0)[2],lf[14],((C_word*)t0)[3],lf[15],C_a_i_list(&a,1,((C_word*)t0)[4]));}}

/* chicken.file#file-readable? in k742 in k739 in k736 in k733 */
static void C_ccall f_827(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_827,c,av);}
/* file.scm:148: test-access */
f_797(t1,t2,C_fix((C_word)R_OK),lf[18]);}

/* chicken.file#file-writable? in k742 in k739 in k736 in k733 */
static void C_ccall f_833(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_833,c,av);}
/* file.scm:149: test-access */
f_797(t1,t2,C_fix((C_word)W_OK),lf[20]);}

/* chicken.file#file-executable? in k742 in k739 in k736 in k733 */
static void C_ccall f_839(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_839,c,av);}
/* file.scm:150: test-access */
f_797(t1,t2,C_fix((C_word)X_OK),lf[22]);}

/* chicken.file#directory in k742 in k739 in k736 in k733 */
static void C_ccall f_845(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_845,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_849,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_nullp(t2))){
/* file.scm:155: chicken.process-context#current-directory */
t4=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_car(t2);
f_849(2,av2);}}}

/* k847 in chicken.file#directory in k742 in k739 in k736 in k733 */
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_849,c,av);}
a=C_alloc(5);
t2=C_i_nullp(((C_word*)t0)[2]);
t3=(C_truep(t2)?C_SCHEME_END_OF_LIST:C_i_cdr(((C_word*)t0)[2]));
t4=C_i_nullp(t3);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_i_car(t3));
t6=C_i_nullp(t3);
t7=(C_truep(t6)?C_SCHEME_END_OF_LIST:C_i_cdr(t3));
t8=C_i_check_string_2(t1,lf[24]);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_864,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[28]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[28]+1);
av2[1]=t9;
av2[2]=C_fix(256);
av2[3]=C_make_character(32);
tp(4,av2);}}

/* k862 in k847 in chicken.file#directory in k742 in k739 in k736 in k733 */
static void C_ccall f_864(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_864,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_867,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* file.scm:158: ##sys#make-pointer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[27]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[27]+1);
av2[1]=t2;
tp(2,av2);}}

/* k865 in k862 in k847 in chicken.file#directory in k742 in k739 in k736 in k733 */
static void C_ccall f_867(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_867,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_870,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* file.scm:159: ##sys#make-pointer */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[27]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[27]+1);
av2[1]=t2;
tp(2,av2);}}

/* k868 in k865 in k862 in k847 in chicken.file#directory in k742 in k739 in k736 in k733 */
static void C_ccall f_870(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_870,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_874,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* file.scm:162: ##sys#make-c-string */
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
av2[3]=lf[24];
tp(4,av2);}}

/* k872 in k868 in k865 in k862 in k847 in chicken.file#directory in k742 in k739 in k736 in k733 */
static void C_ccall f_874(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_874,c,av);}
a=C_alloc(10);
t2=C_opendir(t1,((C_word*)t0)[2]);
if(C_truep(C_null_pointerp(((C_word*)t0)[2]))){
/* file.scm:164: posix-error */
f_756(((C_word*)t0)[3],lf[14],lf[24],lf[25],C_a_i_list(&a,1,((C_word*)t0)[4]));}
else{
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_888,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=t4,a[6]=((C_word*)t0)[7],a[7]=((C_word)li7),tmp=(C_word)a,a+=8,tmp));
t6=((C_word*)t4)[1];
f_888(t6,((C_word*)t0)[3]);}}

/* loop in k872 in k868 in k865 in k862 in k847 in chicken.file#directory in k742 in k739 in k736 in k733 */
static void C_fcall f_888(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_888,2,t0,t1);}
a=C_alloc(6);
t2=C_readdir(((C_word*)t0)[2],((C_word*)t0)[3]);
if(C_truep(C_null_pointerp(((C_word*)t0)[3]))){
t3=C_closedir(((C_word*)t0)[2]);
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=C_block_size(((C_word*)t0)[4]);
t4=C_foundfile(((C_word*)t0)[3],((C_word*)t0)[4],t3);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_902,a[2]=t4,a[3]=((C_word*)t0)[5],a[4]=t1,a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
/* file.scm:170: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[26]+1);
av2[1]=t5;
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(0);
av2[4]=t4;
tp(5,av2);}}}

/* k900 in loop in k872 in k868 in k865 in k862 in k847 in chicken.file#directory in k742 in k739 in k736 in k733 */
static void C_ccall f_902(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_902,c,av);}
a=C_alloc(5);
t2=C_i_string_ref(t1,C_fix(0));
t3=C_fixnum_greaterp(((C_word*)t0)[2],C_fix(1));
t4=(C_truep(t3)?C_i_string_ref(t1,C_fix(1)):C_SCHEME_FALSE);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_914,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t6=C_eqp(C_make_character(46),t2);
if(C_truep(t6)){
t7=C_i_not(t4);
if(C_truep(t7)){
t8=t5;
f_914(t8,t7);}
else{
t8=C_eqp(C_make_character(46),t4);
if(C_truep(t8)){
t9=C_eqp(C_fix(2),((C_word*)t0)[2]);
t10=t5;
f_914(t10,(C_truep(t9)?t9:C_i_not(((C_word*)t0)[5])));}
else{
t9=t5;
f_914(t9,C_i_not(((C_word*)t0)[5]));}}}
else{
t7=t5;
f_914(t7,C_SCHEME_FALSE);}}

/* k912 in k900 in loop in k872 in k868 in k865 in k862 in k847 in chicken.file#directory in k742 in k739 in k736 in k733 */
static void C_fcall f_914(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_914,2,t0,t1);}
a=C_alloc(4);
if(C_truep(t1)){
/* file.scm:177: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_888(t2,((C_word*)t0)[3]);}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_924,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* file.scm:178: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_888(t3,t2);}}

/* k922 in k912 in k900 in loop in k872 in k868 in k865 in k862 in k847 in chicken.file#directory in k742 in k739 in k736 in k733 */
static void C_ccall f_924(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_924,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.file#create-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_984(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_984,c,av);}
a=C_alloc(10);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=C_i_check_string_2(t2,lf[31]);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_994,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t7=C_block_size(t2);
t8=C_eqp(C_fix(0),t7);
t9=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1000,a[2]=t1,a[3]=t2,a[4]=t4,a[5]=t6,tmp=(C_word)a,a+=6,tmp);
if(C_truep(t8)){
t10=t9;{
C_word *av2=av;
av2[0]=t10;
av2[1]=t8;
f_1000(2,av2);}}
else{
/* file.scm:191: file-exists? */
t10=*((C_word*)lf[8]+1);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}}

/* k992 in chicken.file#create-directory in k742 in k739 in k736 in k733 */
static void C_ccall f_994(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_994,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_file_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("file"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_file_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(567))){
C_save(t1);
C_rereclaim2(567*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,113);
lf[0]=C_h_intern(&lf[0],4, C_text("file"));
lf[1]=C_h_intern(&lf[1],13, C_text("chicken.file#"));
lf[3]=C_h_intern(&lf[3],23, C_text("##sys#signal-hook/errno"));
lf[4]=C_h_intern(&lf[4],20, C_text("scheme#string-append"));
lf[5]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003 - "));
lf[6]=C_h_intern(&lf[6],19, C_text("##sys#peek-c-string"));
lf[7]=C_h_intern(&lf[7],18, C_text("##sys#update-errno"));
lf[8]=C_h_intern(&lf[8],25, C_text("chicken.file#file-exists\077"));
lf[9]=C_h_intern(&lf[9],12, C_text("file-exists\077"));
lf[10]=C_h_intern(&lf[10],18, C_text("##sys#file-exists\077"));
lf[11]=C_h_intern(&lf[11],30, C_text("chicken.file#directory-exists\077"));
lf[12]=C_h_intern(&lf[12],17, C_text("directory-exists\077"));
lf[14]=C_h_intern_kw(&lf[14],10, C_text("file-error"));
lf[15]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022cannot access file"));
lf[16]=C_h_intern(&lf[16],19, C_text("##sys#make-c-string"));
lf[17]=C_h_intern(&lf[17],27, C_text("chicken.file#file-readable\077"));
lf[18]=C_h_intern(&lf[18],14, C_text("file-readable\077"));
lf[19]=C_h_intern(&lf[19],27, C_text("chicken.file#file-writable\077"));
lf[20]=C_h_intern(&lf[20],14, C_text("file-writable\077"));
lf[21]=C_h_intern(&lf[21],29, C_text("chicken.file#file-executable\077"));
lf[22]=C_h_intern(&lf[22],16, C_text("file-executable\077"));
lf[23]=C_h_intern(&lf[23],22, C_text("chicken.file#directory"));
lf[24]=C_h_intern(&lf[24],9, C_text("directory"));
lf[25]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025cannot open directory"));
lf[26]=C_h_intern(&lf[26],15, C_text("##sys#substring"));
lf[27]=C_h_intern(&lf[27],18, C_text("##sys#make-pointer"));
lf[28]=C_h_intern(&lf[28],17, C_text("##sys#make-string"));
lf[29]=C_h_intern(&lf[29],41, C_text("chicken.process-context#current-directory"));
lf[30]=C_h_intern(&lf[30],29, C_text("chicken.file#create-directory"));
lf[31]=C_h_intern(&lf[31],16, C_text("create-directory"));
lf[32]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027cannot create directory"));
lf[33]=C_h_intern(&lf[33],35, C_text("chicken.pathname#pathname-directory"));
lf[34]=C_h_intern(&lf[34],35, C_text("chicken.pathname#decompose-pathname"));
lf[35]=C_h_intern(&lf[35],30, C_text("chicken.pathname#make-pathname"));
lf[36]=C_h_intern(&lf[36],29, C_text("chicken.file#delete-directory"));
lf[37]=C_h_intern(&lf[37],16, C_text("delete-directory"));
lf[38]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027cannot delete directory"));
lf[39]=C_h_intern(&lf[39],24, C_text("chicken.file#delete-file"));
lf[40]=C_h_intern(&lf[40],23, C_text("chicken.file#find-files"));
lf[41]=C_h_intern_kw(&lf[41],8, C_text("dotfiles"));
lf[42]=C_h_intern_kw(&lf[42],15, C_text("follow-symlinks"));
lf[43]=C_h_intern(&lf[43],11, C_text("delete-file"));
lf[44]=C_h_intern(&lf[44],19, C_text("##sys#string-append"));
lf[45]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025cannot delete file - "));
lf[46]=C_h_intern(&lf[46],25, C_text("chicken.file#delete-file\052"));
lf[47]=C_h_intern(&lf[47],24, C_text("chicken.file#rename-file"));
lf[48]=C_h_intern(&lf[48],11, C_text("rename-file"));
lf[49]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025cannot rename file - "));
lf[50]=C_h_intern(&lf[50],11, C_text("##sys#error"));
lf[51]=C_decode_literal(C_heaptop,C_text("\376B\000\000#newfile exists but clobber is false"));
lf[52]=C_h_intern(&lf[52],22, C_text("chicken.file#copy-file"));
lf[53]=C_h_intern(&lf[53],9, C_text("copy-file"));
lf[54]=C_h_intern(&lf[54],24, C_text("scheme#close-output-port"));
lf[55]=C_h_intern(&lf[55],23, C_text("scheme#close-input-port"));
lf[56]=C_h_intern(&lf[56],23, C_text("chicken.io#read-string!"));
lf[57]=C_h_intern(&lf[57],23, C_text("chicken.io#write-string"));
lf[58]=C_h_intern(&lf[58],18, C_text("scheme#make-string"));
lf[59]=C_h_intern(&lf[59],23, C_text("scheme#open-output-file"));
lf[60]=C_h_intern_kw(&lf[60],6, C_text("binary"));
lf[61]=C_h_intern(&lf[61],22, C_text("scheme#open-input-file"));
lf[62]=C_decode_literal(C_heaptop,C_text("\376B\000\000#newfile exists but clobber is false"));
lf[63]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027cannot copy directories"));
lf[64]=C_decode_literal(C_heaptop,C_text("\376B\000\000\052invalid blocksize - not a positive integer"));
lf[65]=C_h_intern(&lf[65],22, C_text("chicken.file#move-file"));
lf[66]=C_h_intern(&lf[66],9, C_text("move-file"));
lf[67]=C_decode_literal(C_heaptop,C_text("\376B\000\000#newfile exists but clobber is false"));
lf[68]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027cannot move directories"));
lf[69]=C_decode_literal(C_heaptop,C_text("\376B\000\000\052invalid blocksize - not a positive integer"));
lf[70]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004temp"));
lf[71]=C_h_intern(&lf[71],22, C_text("##sys#windows-platform"));
lf[72]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023/AppData/Local/Temp"));
lf[73]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[74]=C_h_intern(&lf[74],48, C_text("chicken.process-context#get-environment-variable"));
lf[75]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013USERPROFILE"));
lf[76]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004/tmp"));
lf[77]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003TMP"));
lf[78]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004TEMP"));
lf[79]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006TMPDIR"));
lf[80]=C_h_intern(&lf[80],34, C_text("chicken.file#create-temporary-file"));
lf[81]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003tmp"));
lf[82]=C_h_intern(&lf[82],21, C_text("create-temporary-file"));
lf[83]=C_h_intern(&lf[83],28, C_text("scheme#call-with-output-file"));
lf[84]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[85]=C_h_intern(&lf[85],20, C_text("##sys#number->string"));
lf[86]=C_h_intern(&lf[86],39, C_text("chicken.file#create-temporary-directory"));
lf[87]=C_h_intern(&lf[87],17, C_text("##sys#signal-hook"));
lf[88]=C_h_intern(&lf[88],26, C_text("create-temporary-directory"));
lf[89]=C_decode_literal(C_heaptop,C_text("\376B\000\000$cannot create temporary directory - "));
lf[90]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[91]=C_h_intern(&lf[91],17, C_text("chicken.file#glob"));
lf[92]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[93]=C_h_intern(&lf[93],39, C_text("chicken.irregex#irregex-match-substring"));
lf[94]=C_h_intern(&lf[94],29, C_text("chicken.irregex#irregex-match"));
lf[95]=C_h_intern(&lf[95],9, C_text("condition"));
lf[96]=C_h_intern(&lf[96],3, C_text("exn"));
lf[97]=C_h_intern(&lf[97],3, C_text("i/o"));
lf[98]=C_h_intern(&lf[98],24, C_text("chicken.condition#signal"));
lf[99]=C_h_intern(&lf[99],40, C_text("chicken.condition#with-exception-handler"));
lf[100]=C_h_intern(&lf[100],37, C_text("scheme#call-with-current-continuation"));
lf[101]=C_h_intern(&lf[101],23, C_text("chicken.irregex#irregex"));
lf[102]=C_h_intern(&lf[102],25, C_text("chicken.irregex#glob->sre"));
lf[103]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\052"));
lf[104]=C_h_intern(&lf[104],10, C_text("find-files"));
lf[105]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[106]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002.."));
lf[107]=C_h_intern(&lf[107],18, C_text("##sys#dynamic-wind"));
lf[108]=C_h_intern(&lf[108],17, C_text("##sys#get-keyword"));
lf[109]=C_h_intern_kw(&lf[109],5, C_text("limit"));
lf[110]=C_h_intern_kw(&lf[110],4, C_text("seed"));
lf[111]=C_h_intern_kw(&lf[111],6, C_text("action"));
lf[112]=C_h_intern_kw(&lf[112],4, C_text("test"));
C_register_lf2(lf,113,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_735,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[189] = {
{C_text("f_1000:file_2escm"),(void*)f_1000},
{C_text("f_1010:file_2escm"),(void*)f_1010},
{C_text("f_1012:file_2escm"),(void*)f_1012},
{C_text("f_1019:file_2escm"),(void*)f_1019},
{C_text("f_1022:file_2escm"),(void*)f_1022},
{C_text("f_1038:file_2escm"),(void*)f_1038},
{C_text("f_1045:file_2escm"),(void*)f_1045},
{C_text("f_1052:file_2escm"),(void*)f_1052},
{C_text("f_1054:file_2escm"),(void*)f_1054},
{C_text("f_1060:file_2escm"),(void*)f_1060},
{C_text("f_1083:file_2escm"),(void*)f_1083},
{C_text("f_1101:file_2escm"),(void*)f_1101},
{C_text("f_1107:file_2escm"),(void*)f_1107},
{C_text("f_1111:file_2escm"),(void*)f_1111},
{C_text("f_1130:file_2escm"),(void*)f_1130},
{C_text("f_1131:file_2escm"),(void*)f_1131},
{C_text("f_1144:file_2escm"),(void*)f_1144},
{C_text("f_1153:file_2escm"),(void*)f_1153},
{C_text("f_1156:file_2escm"),(void*)f_1156},
{C_text("f_1161:file_2escm"),(void*)f_1161},
{C_text("f_1171:file_2escm"),(void*)f_1171},
{C_text("f_1193:file_2escm"),(void*)f_1193},
{C_text("f_1206:file_2escm"),(void*)f_1206},
{C_text("f_1210:file_2escm"),(void*)f_1210},
{C_text("f_1214:file_2escm"),(void*)f_1214},
{C_text("f_1218:file_2escm"),(void*)f_1218},
{C_text("f_1223:file_2escm"),(void*)f_1223},
{C_text("f_1225:file_2escm"),(void*)f_1225},
{C_text("f_1232:file_2escm"),(void*)f_1232},
{C_text("f_1237:file_2escm"),(void*)f_1237},
{C_text("f_1250:file_2escm"),(void*)f_1250},
{C_text("f_1253:file_2escm"),(void*)f_1253},
{C_text("f_1263:file_2escm"),(void*)f_1263},
{C_text("f_1267:file_2escm"),(void*)f_1267},
{C_text("f_1271:file_2escm"),(void*)f_1271},
{C_text("f_1276:file_2escm"),(void*)f_1276},
{C_text("f_1280:file_2escm"),(void*)f_1280},
{C_text("f_1283:file_2escm"),(void*)f_1283},
{C_text("f_1300:file_2escm"),(void*)f_1300},
{C_text("f_1325:file_2escm"),(void*)f_1325},
{C_text("f_1328:file_2escm"),(void*)f_1328},
{C_text("f_1331:file_2escm"),(void*)f_1331},
{C_text("f_1334:file_2escm"),(void*)f_1334},
{C_text("f_1337:file_2escm"),(void*)f_1337},
{C_text("f_1340:file_2escm"),(void*)f_1340},
{C_text("f_1347:file_2escm"),(void*)f_1347},
{C_text("f_1349:file_2escm"),(void*)f_1349},
{C_text("f_1359:file_2escm"),(void*)f_1359},
{C_text("f_1362:file_2escm"),(void*)f_1362},
{C_text("f_1365:file_2escm"),(void*)f_1365},
{C_text("f_1372:file_2escm"),(void*)f_1372},
{C_text("f_1379:file_2escm"),(void*)f_1379},
{C_text("f_1391:file_2escm"),(void*)f_1391},
{C_text("f_1430:file_2escm"),(void*)f_1430},
{C_text("f_1455:file_2escm"),(void*)f_1455},
{C_text("f_1458:file_2escm"),(void*)f_1458},
{C_text("f_1461:file_2escm"),(void*)f_1461},
{C_text("f_1464:file_2escm"),(void*)f_1464},
{C_text("f_1467:file_2escm"),(void*)f_1467},
{C_text("f_1470:file_2escm"),(void*)f_1470},
{C_text("f_1477:file_2escm"),(void*)f_1477},
{C_text("f_1479:file_2escm"),(void*)f_1479},
{C_text("f_1489:file_2escm"),(void*)f_1489},
{C_text("f_1492:file_2escm"),(void*)f_1492},
{C_text("f_1495:file_2escm"),(void*)f_1495},
{C_text("f_1498:file_2escm"),(void*)f_1498},
{C_text("f_1505:file_2escm"),(void*)f_1505},
{C_text("f_1512:file_2escm"),(void*)f_1512},
{C_text("f_1524:file_2escm"),(void*)f_1524},
{C_text("f_1563:file_2escm"),(void*)f_1563},
{C_text("f_1567:file_2escm"),(void*)f_1567},
{C_text("f_1573:file_2escm"),(void*)f_1573},
{C_text("f_1579:file_2escm"),(void*)f_1579},
{C_text("f_1588:file_2escm"),(void*)f_1588},
{C_text("f_1596:file_2escm"),(void*)f_1596},
{C_text("f_1608:file_2escm"),(void*)f_1608},
{C_text("f_1614:file_2escm"),(void*)f_1614},
{C_text("f_1620:file_2escm"),(void*)f_1620},
{C_text("f_1628:file_2escm"),(void*)f_1628},
{C_text("f_1633:file_2escm"),(void*)f_1633},
{C_text("f_1637:file_2escm"),(void*)f_1637},
{C_text("f_1641:file_2escm"),(void*)f_1641},
{C_text("f_1645:file_2escm"),(void*)f_1645},
{C_text("f_1659:file_2escm"),(void*)f_1659},
{C_text("f_1665:file_2escm"),(void*)f_1665},
{C_text("f_1671:file_2escm"),(void*)f_1671},
{C_text("f_1677:file_2escm"),(void*)f_1677},
{C_text("f_1684:file_2escm"),(void*)f_1684},
{C_text("f_1697:file_2escm"),(void*)f_1697},
{C_text("f_1701:file_2escm"),(void*)f_1701},
{C_text("f_1705:file_2escm"),(void*)f_1705},
{C_text("f_1709:file_2escm"),(void*)f_1709},
{C_text("f_1713:file_2escm"),(void*)f_1713},
{C_text("f_1717:file_2escm"),(void*)f_1717},
{C_text("f_1725:file_2escm"),(void*)f_1725},
{C_text("f_1731:file_2escm"),(void*)f_1731},
{C_text("f_1746:file_2escm"),(void*)f_1746},
{C_text("f_1752:file_2escm"),(void*)f_1752},
{C_text("f_1759:file_2escm"),(void*)f_1759},
{C_text("f_1766:file_2escm"),(void*)f_1766},
{C_text("f_1769:file_2escm"),(void*)f_1769},
{C_text("f_1771:file_2escm"),(void*)f_1771},
{C_text("f_1788:file_2escm"),(void*)f_1788},
{C_text("f_1792:file_2escm"),(void*)f_1792},
{C_text("f_1800:file_2escm"),(void*)f_1800},
{C_text("f_1804:file_2escm"),(void*)f_1804},
{C_text("f_1812:file_2escm"),(void*)f_1812},
{C_text("f_1830:file_2escm"),(void*)f_1830},
{C_text("f_1836:file_2escm"),(void*)f_1836},
{C_text("f_1842:file_2escm"),(void*)f_1842},
{C_text("f_1878:file_2escm"),(void*)f_1878},
{C_text("f_1880:file_2escm"),(void*)f_1880},
{C_text("f_1885:file_2escm"),(void*)f_1885},
{C_text("f_1891:file_2escm"),(void*)f_1891},
{C_text("f_1902:file_2escm"),(void*)f_1902},
{C_text("f_1906:file_2escm"),(void*)f_1906},
{C_text("f_1910:file_2escm"),(void*)f_1910},
{C_text("f_1916:file_2escm"),(void*)f_1916},
{C_text("f_1920:file_2escm"),(void*)f_1920},
{C_text("f_1923:file_2escm"),(void*)f_1923},
{C_text("f_1926:file_2escm"),(void*)f_1926},
{C_text("f_1929:file_2escm"),(void*)f_1929},
{C_text("f_1932:file_2escm"),(void*)f_1932},
{C_text("f_1935:file_2escm"),(void*)f_1935},
{C_text("f_1941:file_2escm"),(void*)f_1941},
{C_text("f_1944:file_2escm"),(void*)f_1944},
{C_text("f_1951:file_2escm"),(void*)f_1951},
{C_text("f_1953:file_2escm"),(void*)f_1953},
{C_text("f_1966:file_2escm"),(void*)f_1966},
{C_text("f_1975:file_2escm"),(void*)f_1975},
{C_text("f_1997:file_2escm"),(void*)f_1997},
{C_text("f_2000:file_2escm"),(void*)f_2000},
{C_text("f_2009:file_2escm"),(void*)f_2009},
{C_text("f_2019:file_2escm"),(void*)f_2019},
{C_text("f_2021:file_2escm"),(void*)f_2021},
{C_text("f_2026:file_2escm"),(void*)f_2026},
{C_text("f_2034:file_2escm"),(void*)f_2034},
{C_text("f_2038:file_2escm"),(void*)f_2038},
{C_text("f_2041:file_2escm"),(void*)f_2041},
{C_text("f_2046:file_2escm"),(void*)f_2046},
{C_text("f_2056:file_2escm"),(void*)f_2056},
{C_text("f_2059:file_2escm"),(void*)f_2059},
{C_text("f_2068:file_2escm"),(void*)f_2068},
{C_text("f_2080:file_2escm"),(void*)f_2080},
{C_text("f_2087:file_2escm"),(void*)f_2087},
{C_text("f_2096:file_2escm"),(void*)f_2096},
{C_text("f_2097:file_2escm"),(void*)f_2097},
{C_text("f_2105:file_2escm"),(void*)f_2105},
{C_text("f_2113:file_2escm"),(void*)f_2113},
{C_text("f_2119:file_2escm"),(void*)f_2119},
{C_text("f_2122:file_2escm"),(void*)f_2122},
{C_text("f_2125:file_2escm"),(void*)f_2125},
{C_text("f_2128:file_2escm"),(void*)f_2128},
{C_text("f_2131:file_2escm"),(void*)f_2131},
{C_text("f_2133:file_2escm"),(void*)f_2133},
{C_text("f_2139:file_2escm"),(void*)f_2139},
{C_text("f_2141:file_2escm"),(void*)f_2141},
{C_text("f_735:file_2escm"),(void*)f_735},
{C_text("f_738:file_2escm"),(void*)f_738},
{C_text("f_741:file_2escm"),(void*)f_741},
{C_text("f_744:file_2escm"),(void*)f_744},
{C_text("f_756:file_2escm"),(void*)f_756},
{C_text("f_760:file_2escm"),(void*)f_760},
{C_text("f_767:file_2escm"),(void*)f_767},
{C_text("f_771:file_2escm"),(void*)f_771},
{C_text("f_773:file_2escm"),(void*)f_773},
{C_text("f_783:file_2escm"),(void*)f_783},
{C_text("f_785:file_2escm"),(void*)f_785},
{C_text("f_795:file_2escm"),(void*)f_795},
{C_text("f_797:file_2escm"),(void*)f_797},
{C_text("f_805:file_2escm"),(void*)f_805},
{C_text("f_824:file_2escm"),(void*)f_824},
{C_text("f_827:file_2escm"),(void*)f_827},
{C_text("f_833:file_2escm"),(void*)f_833},
{C_text("f_839:file_2escm"),(void*)f_839},
{C_text("f_845:file_2escm"),(void*)f_845},
{C_text("f_849:file_2escm"),(void*)f_849},
{C_text("f_864:file_2escm"),(void*)f_864},
{C_text("f_867:file_2escm"),(void*)f_867},
{C_text("f_870:file_2escm"),(void*)f_870},
{C_text("f_874:file_2escm"),(void*)f_874},
{C_text("f_888:file_2escm"),(void*)f_888},
{C_text("f_902:file_2escm"),(void*)f_902},
{C_text("f_914:file_2escm"),(void*)f_914},
{C_text("f_924:file_2escm"),(void*)f_924},
{C_text("f_984:file_2escm"),(void*)f_984},
{C_text("f_994:file_2escm"),(void*)f_994},
{C_text("toplevel:file_2escm"),(void*)C_file_toplevel},
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
o|hiding unexported module binding: chicken.file#d 
o|hiding unexported module binding: chicken.file#define-alias 
o|hiding unexported module binding: chicken.file#posix-error 
o|hiding unexported module binding: chicken.file#test-access 
S|applied compiler syntax:
S|  scheme#for-each		1
o|eliminated procedure checks: 22 
o|specializations:
o|  1 (##sys#call-with-values (procedure () *) *)
o|  1 (scheme#cdr pair)
o|  2 (scheme#number->string * *)
o|  2 (scheme#integer? *)
o|  1 (##sys#check-list (or pair list) *)
o|  1 (scheme#string-ref string fixnum)
o|  1 (scheme#string-length string)
o|  1 (scheme#make-string fixnum)
(o e)|safe calls: 202 
o|dropping redundant toplevel assignment: chicken.file#create-temporary-file 
o|dropping redundant toplevel assignment: chicken.file#create-temporary-directory 
o|safe globals: (chicken.file#find-files chicken.file#glob chicken.file#create-temporary-directory chicken.file#create-temporary-file chicken.file#move-file chicken.file#copy-file chicken.file#rename-file chicken.file#delete-file* chicken.file#delete-file chicken.file#delete-directory chicken.file#create-directory chicken.file#directory chicken.file#file-executable? chicken.file#file-writable? chicken.file#file-readable? chicken.file#test-access chicken.file#directory-exists? chicken.file#file-exists? chicken.file#posix-error) 
o|merged explicitly consed rest parameter: args149 
o|contracted procedure: "(file.scm:120) strerror139" 
o|inlining procedure: k778 
o|inlining procedure: k778 
o|inlining procedure: k790 
o|inlining procedure: k790 
o|inlining procedure: k809 
o|inlining procedure: k809 
o|consed rest parameter at call site: "(file.scm:146) chicken.file#posix-error" 4 
o|inlining procedure: k875 
o|consed rest parameter at call site: "(file.scm:164) chicken.file#posix-error" 4 
o|inlining procedure: k875 
o|inlining procedure: k890 
o|inlining procedure: k890 
o|inlining procedure: k931 
o|inlining procedure: k931 
o|substituted constant variable: a953 
o|substituted constant variable: a955 
o|inlining procedure: k992 
o|inlining procedure: k992 
o|inlining procedure: k1014 
o|contracted procedure: "(file.scm:197) g231232" 
o|inlining procedure: k1025 
o|inlining procedure: k1025 
o|consed rest parameter at call site: "(file.scm:185) chicken.file#posix-error" 4 
o|inlining procedure: k1014 
o|inlining procedure: k1062 
o|inlining procedure: k1062 
o|contracted procedure: "(file.scm:198) g249250" 
o|inlining procedure: k1070 
o|inlining procedure: k1070 
o|consed rest parameter at call site: "(file.scm:185) chicken.file#posix-error" 4 
o|inlining procedure: k1112 
o|inlining procedure: k1112 
o|consed rest parameter at call site: "(file.scm:206) chicken.file#posix-error" 4 
o|inlining procedure: k1133 
o|propagated global variable: r11342169 chicken.file#delete-file 
o|inlining procedure: k1133 
o|contracted procedure: "(file.scm:215) g290291" 
o|inlining procedure: k1125 
o|inlining procedure: k1163 
o|inlining procedure: k1163 
o|inlining procedure: k1125 
o|inlining procedure: k1198 
o|inlining procedure: k1198 
o|inlining procedure: k1227 
o|inlining procedure: k1227 
o|inlining procedure: k1251 
o|inlining procedure: k1251 
o|inlining procedure: k1351 
o|inlining procedure: k1351 
o|inlining procedure: k1481 
o|inlining procedure: k1481 
o|inlining procedure: k1568 
o|inlining procedure: k1568 
o|inlining procedure: k1580 
o|inlining procedure: k1580 
o|inlining procedure: k1589 
o|inlining procedure: k1589 
o|inlining procedure: k1615 
o|inlining procedure: k1615 
o|contracted procedure: "(file.scm:330) getpid427" 
o|substituted constant variable: a1651 
o|inlining procedure: k1672 
o|inlining procedure: k1672 
o|contracted procedure: "(file.scm:346) getpid436" 
o|substituted constant variable: a1723 
o|inlining procedure: k1733 
o|inlining procedure: k1733 
o|inlining procedure: k1773 
o|inlining procedure: k1773 
o|inlining procedure: k1847 
o|inlining procedure: k1847 
o|inlining procedure: k1856 
o|inlining procedure: k1856 
o|merged explicitly consed rest parameter: args489504 
o|consed rest parameter at call site: tmp2726 1 
o|inlining procedure: k1912 
o|inlining procedure: k1912 
o|inlining procedure: k1955 
o|inlining procedure: k1955 
o|inlining procedure: k1976 
o|inlining procedure: k1976 
o|inlining procedure: k1995 
o|inlining procedure: k1995 
o|inlining procedure: k2004 
o|inlining procedure: k2036 
o|inlining procedure: k2036 
o|inlining procedure: k2004 
o|inlining procedure: k2054 
o|inlining procedure: k2054 
o|contracted procedure: "(file.scm:407) g549550" 
o|inlining procedure: k2075 
o|inlining procedure: k2075 
o|inlining procedure: k2107 
o|inlining procedure: k2107 
o|replaced variables: 405 
o|removed binding forms: 97 
o|substituted constant variable: r7792144 
o|substituted constant variable: r7912146 
o|substituted constant variable: r8912151 
o|substituted constant variable: loc233 
o|substituted constant variable: loc233 
o|substituted constant variable: loc251 
o|substituted constant variable: loc251 
o|propagated global variable: g2842852170 chicken.file#delete-file 
o|inlining procedure: k1133 
o|inlining procedure: k1133 
o|propagated global variable: r11342252 chicken.file#delete-file 
o|propagated global variable: r11342252 chicken.file#delete-file 
o|substituted constant variable: loc293 
o|converted assignments to bindings: (rmdir267) 
o|substituted constant variable: r12282186 
o|substituted constant variable: r15902200 
o|substituted constant variable: r17342205 
o|substituted constant variable: r18482209 
o|substituted constant variable: r18572212 
o|substituted constant variable: r19132215 
o|substituted constant variable: r19132215 
o|substituted constant variable: loc552 
o|converted assignments to bindings: (tempdir404) 
o|simplifications: ((let . 2)) 
o|replaced variables: 37 
o|removed binding forms: 296 
o|inlining procedure: k934 
o|inlining procedure: k992 
o|inlining procedure: k1281 
o|inlining procedure: k1377 
o|inlining procedure: k1395 
o|inlining procedure: k1510 
o|inlining procedure: k1528 
o|inlining procedure: k1647 
o|inlining procedure: k1719 
o|inlining procedure: k1850 
o|inlining procedure: k1850 
o|inlining procedure: k1850 
o|inlining procedure: k2069 
o|replaced variables: 1 
o|removed binding forms: 53 
o|substituted constant variable: r9352289 
o|substituted constant variable: r9352289 
o|contracted procedure: k1145 
o|substituted constant variable: r12822297 
o|substituted constant variable: r13782300 
o|substituted constant variable: r13962301 
o|substituted constant variable: r15112304 
o|substituted constant variable: r15292305 
o|substituted constant variable: r18512314 
o|substituted constant variable: r18512316 
o|substituted constant variable: r18512318 
o|simplifications: ((let . 2)) 
o|removed binding forms: 9 
o|removed conditional forms: 9 
o|removed binding forms: 10 
o|simplifications: ((if . 22) (let . 9) (##core#call . 113)) 
o|  call simplifications:
o|    chicken.base#fixnum?
o|    chicken.fixnum#fx<
o|    scheme#procedure?
o|    scheme#member
o|    ##sys#apply
o|    ##sys#structure?
o|    scheme#memv	3
o|    ##sys#check-number	2
o|    scheme#>	2
o|    chicken.fixnum#fx+	3
o|    scheme#pair?	2
o|    ##sys#slot	5
o|    ##sys#call-with-values	2
o|    scheme#car	12
o|    scheme#null?	18
o|    scheme#cdr	8
o|    ##sys#null-pointer?	2
o|    ##sys#size	2
o|    scheme#string-ref
o|    chicken.fixnum#fx>
o|    scheme#eq?	6
o|    scheme#not	10
o|    scheme#cons	3
o|    chicken.fixnum#fx=	8
o|    ##sys#check-string	15
o|    ##sys#foreign-fixnum-argument
o|    scheme#apply
o|contracted procedure: k753 
o|contracted procedure: k775 
o|contracted procedure: k787 
o|contracted procedure: k799 
o|contracted procedure: k806 
o|contracted procedure: k815 
o|contracted procedure: k968 
o|contracted procedure: k850 
o|contracted procedure: k962 
o|contracted procedure: k853 
o|contracted procedure: k956 
o|contracted procedure: k856 
o|contracted procedure: k859 
o|contracted procedure: k878 
o|contracted procedure: k893 
o|contracted procedure: k897 
o|contracted procedure: k903 
o|contracted procedure: k949 
o|contracted procedure: k906 
o|contracted procedure: k925 
o|contracted procedure: k928 
o|contracted procedure: k943 
o|contracted procedure: k934 
o|contracted procedure: k974 
o|contracted procedure: k1094 
o|contracted procedure: k986 
o|contracted procedure: k989 
o|contracted procedure: k1091 
o|contracted procedure: k995 
o|contracted procedure: k1028 
o|contracted procedure: k1073 
o|contracted procedure: k1186 
o|contracted procedure: k1103 
o|contracted procedure: k1115 
o|contracted procedure: k1122 
o|contracted procedure: k1166 
o|contracted procedure: k1176 
o|contracted procedure: k1180 
o|contracted procedure: k1195 
o|contracted procedure: k1201 
o|contracted procedure: k1293 
o|contracted procedure: k1239 
o|contracted procedure: k1242 
o|contracted procedure: k1245 
o|contracted procedure: k1254 
o|contracted procedure: k1287 
o|contracted procedure: k1423 
o|contracted procedure: k1302 
o|contracted procedure: k1417 
o|contracted procedure: k1305 
o|contracted procedure: k1411 
o|contracted procedure: k1308 
o|contracted procedure: k1405 
o|contracted procedure: k1311 
o|contracted procedure: k1314 
o|contracted procedure: k1317 
o|contracted procedure: k1320 
o|contracted procedure: k1354 
o|contracted procedure: k1374 
o|contracted procedure: k1383 
o|contracted procedure: k1395 
o|substituted constant variable: g2394 
o|contracted procedure: k1556 
o|contracted procedure: k1432 
o|contracted procedure: k1550 
o|contracted procedure: k1435 
o|contracted procedure: k1544 
o|contracted procedure: k1438 
o|contracted procedure: k1538 
o|contracted procedure: k1441 
o|contracted procedure: k1444 
o|contracted procedure: k1447 
o|contracted procedure: k1450 
o|contracted procedure: k1484 
o|contracted procedure: k1507 
o|contracted procedure: k1516 
o|contracted procedure: k1528 
o|substituted constant variable: g2398 
o|contracted procedure: k1652 
o|contracted procedure: k1598 
o|contracted procedure: k1601 
o|contracted procedure: k1688 
o|contracted procedure: k1736 
o|contracted procedure: k1739 
o|contracted procedure: k1754 
o|contracted procedure: k1826 
o|contracted procedure: k1776 
o|contracted procedure: k1783 
o|contracted procedure: k1806 
o|contracted procedure: k1822 
o|contracted procedure: k1871 
o|contracted procedure: k1844 
o|contracted procedure: k1859 
o|contracted procedure: k1865 
o|contracted procedure: k1850 
o|contracted procedure: k1936 
o|contracted procedure: k1958 
o|contracted procedure: k1961 
o|contracted procedure: k1967 
o|contracted procedure: k1979 
o|contracted procedure: k1988 
o|contracted procedure: k2014 
o|contracted procedure: k2091 
o|contracted procedure: k2102 
o|contracted procedure: k2110 
o|simplifications: ((if . 1) (let . 26)) 
o|replaced variables: 2 
o|removed binding forms: 103 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest217219 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest217219 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest259261 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest259261 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest313316 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest313316 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest331334 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest331334 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest331334 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest331334 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest367370 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest367370 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest367370 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest367370 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest418419 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest418419 0 
o|replaced variables: 2 
o|removed binding forms: 4 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1306 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1306 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1306 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1306 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1436 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1436 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1436 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1436 1 
o|removed binding forms: 1 
o|removed binding forms: 4 
o|customizable procedures: (k1939 k1942 loop533 tmp1725 tmp2726 g477478 loop469 conc-loop446 loop434 tempdir404 loop425 loop386 loop350 g274281 for-each-loop273294 rmdir267 k1017 loop228 k912 loop194 chicken.file#test-access chicken.file#posix-error) 
o|calls to known targets: 71 
o|unused rest argument: rest217219 f_984 
o|unused rest argument: rest259261 f_1101 
o|unused rest argument: rest313316 f_1237 
o|unused rest argument: rest331334 f_1300 
o|unused rest argument: rest367370 f_1430 
o|unused rest argument: rest418419 f_1596 
o|unused rest argument: _528 f_2105 
o|unused rest argument: _529 f_2113 
o|unused rest argument: _514 f_2141 
o|fast box initializations: 10 
o|fast global references: 8 
o|fast global assignments: 2 
o|dropping unused closure argument: f_1107 
o|dropping unused closure argument: f_1563 
o|dropping unused closure argument: f_756 
o|dropping unused closure argument: f_797 
*/
/* end of file */
