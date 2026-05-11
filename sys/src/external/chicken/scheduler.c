/* Generated from scheduler.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: scheduler.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file scheduler.c
   unit: scheduler
   uses: extras library
*/
#include "chicken.h"

#ifdef HAVE_ERRNO_H
# include <errno.h>
# define C_signal_interrupted_p     C_mk_bool(errno == EINTR)
#else
# define C_signal_interrupted_p     C_SCHEME_FALSE
#endif

#ifdef _WIN32
/* TODO: Winsock select() only works for sockets */
# include <winsock2.h>
/* Beware: winsock2.h must come BEFORE windows.h */
# define C_msleep(n)   (Sleep((DWORD)C_num_to_uint64(n)), C_SCHEME_TRUE)
#else
# include <sys/time.h>
static C_word C_msleep(C_word ms);
C_word C_msleep(C_word ms) {
#ifdef __CYGWIN__
  if(usleep((useconds_t)C_num_to_uint64(ms) * 1000) == -1) return C_SCHEME_FALSE;
#else
  struct timespec ts;
  C_word ab[C_SIZEOF_FIX_BIGNUM], *a = ab,
         sec = C_s_a_u_i_integer_quotient(&a, 2, ms, C_fix(1000)),
         msec = C_s_a_u_i_integer_remainder(&a, 2, ms, C_fix(1000));
  ts.tv_sec = (time_t)C_num_to_uint64(sec);
  ts.tv_nsec = (long)C_unfix(msec) * 1000000;
  
  if(nanosleep(&ts, NULL) == -1) return C_SCHEME_FALSE;
#endif
  return C_SCHEME_TRUE;
}
#endif

#ifdef NO_POSIX_POLL

/* Shouldn't we include <sys/select.h> here? */
static fd_set C_fdset_input, C_fdset_output;

#define C_fd_input_ready(fd,pos)  C_mk_bool(FD_ISSET(C_unfix(fd), &C_fdset_input))
#define C_fd_output_ready(fd,pos)  C_mk_bool(FD_ISSET(C_unfix(fd), &C_fdset_output))

inline static int C_ready_fds_timeout(int to, unsigned int tm) {
  struct timeval timeout;
  timeout.tv_sec = tm / 1000;
  timeout.tv_usec = fmod(tm, 1000) * 1000;
  /* we use FD_SETSIZE, but really should use max fd */
  return select(FD_SETSIZE, &C_fdset_input, &C_fdset_output, NULL, to ? &timeout : NULL);
}

inline static void C_prepare_fdset(int length) {
  FD_ZERO(&C_fdset_input);
  FD_ZERO(&C_fdset_output);
}

inline static void C_fdset_add(int fd, int input, int output) {
  if (input) FD_SET(fd, &C_fdset_input);
  if (output) FD_SET(fd, &C_fdset_output);
}

#else
#  include <poll.h>
#  include <assert.h>

static int C_fdset_nfds;
static struct pollfd *C_fdset_set = NULL;

inline static int C_fd_ready(int fd, int pos, int what) {
  assert(fd == C_fdset_set[pos].fd); /* Must match position in fd-list! */
  return(C_fdset_set[pos].revents & what);
}

#define C_fd_input_ready(fd,pos)  C_mk_bool(C_fd_ready(C_unfix(fd), C_unfix(pos),POLLIN|POLLERR|POLLHUP|POLLNVAL))
#define C_fd_output_ready(fd,pos)  C_mk_bool(C_fd_ready(C_unfix(fd), C_unfix(pos),POLLOUT|POLLERR|POLLHUP|POLLNVAL))

inline static int C_ready_fds_timeout(int to, unsigned int tm) {
  return poll(C_fdset_set, C_fdset_nfds, to ? tm : -1);
}

inline static void C_prepare_fdset(int length) {
  /* TODO: Only realloc when needed? */
  C_fdset_set = realloc(C_fdset_set, sizeof(struct pollfd) * length);
  if (C_fdset_set == NULL)
    C_halt(C_SCHEME_FALSE); /* Ugly: no message */
  C_fdset_nfds = 0;
}

/* This *must* be called in order, so position will match fd-list */
inline static void C_fdset_add(int fd, int input, int output) {
  C_fdset_set[C_fdset_nfds].events = ((input ? POLLIN : 0) | (output ? POLLOUT : 0));
  C_fdset_set[C_fdset_nfds++].fd = fd;
}
#endif

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[74];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,108,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,12),40,100,101,108,113,32,120,32,108,115,116,41,0,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,7),40,108,111,111,112,50,41,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,20),40,108,111,111,112,50,32,116,104,114,101,97,100,115,32,107,101,101,112,41,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,32,110,32,112,111,115,32,108,115,116,41};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,8),40,103,52,48,48,32,116,41};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,51,57,57,32,103,52,48,54,41,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,108,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,108,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,7),40,108,111,111,112,49,41,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,16),40,35,35,115,121,115,35,115,99,104,101,100,117,108,101,41};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,24),40,35,35,115,121,115,35,102,111,114,99,101,45,112,114,105,109,111,114,100,105,97,108,41};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,19),40,35,35,115,121,115,35,114,101,97,100,121,45,113,117,101,117,101,41,0,0,0,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,33),40,35,35,115,121,115,35,97,100,100,45,116,111,45,114,101,97,100,121,45,113,117,101,117,101,32,116,104,114,101,97,100,41,0,0,0,0,0,0,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,34),40,35,35,115,121,115,35,117,112,100,97,116,101,45,116,104,114,101,97,100,45,115,116,97,116,101,45,98,117,102,102,101,114,41,0,0,0,0,0,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,7),40,97,49,51,49,53,41,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,35),40,35,35,115,121,115,35,105,110,116,101,114,114,117,112,116,45,104,111,111,107,32,114,101,97,115,111,110,32,115,116,97,116,101,41,0,0,0,0,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,21),40,35,35,115,121,115,35,116,105,109,101,111,117,116,45,113,117,101,117,101,41,0,0,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,11),40,108,111,111,112,32,112,114,101,118,41,0,0,0,0,0};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,34),40,35,35,115,121,115,35,114,101,109,111,118,101,45,102,114,111,109,45,116,105,109,101,111,117,116,45,108,105,115,116,32,116,41,0,0,0,0,0,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,14),40,108,111,111,112,32,116,108,32,112,114,101,118,41,0,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,38),40,35,35,115,121,115,35,116,104,114,101,97,100,45,98,108,111,99,107,45,102,111,114,45,116,105,109,101,111,117,116,33,32,116,32,116,109,41,0,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,42),40,35,35,115,121,115,35,116,104,114,101,97,100,45,98,108,111,99,107,45,102,111,114,45,116,101,114,109,105,110,97,116,105,111,110,33,32,116,32,116,50,41,0,0,0,0,0,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,9),40,103,51,52,49,32,116,50,41,0,0,0,0,0,0,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,51,52,48,32,103,51,52,55,41,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,51,48,54,32,103,51,49,51,41,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,50,57,50,32,103,50,57,57,41,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,24),40,35,35,115,121,115,35,116,104,114,101,97,100,45,107,105,108,108,33,32,116,32,115,41};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,31),40,35,35,115,121,115,35,116,104,114,101,97,100,45,98,97,115,105,99,45,117,110,98,108,111,99,107,33,32,116,41,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,7),40,97,49,55,49,53,41,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,37),40,35,35,115,121,115,35,100,101,102,97,117,108,116,45,101,120,99,101,112,116,105,111,110,45,104,97,110,100,108,101,114,32,97,114,103,41,0,0,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,16),40,35,35,115,121,115,35,102,100,45,113,117,101,117,101,41};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,108,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,38),40,35,35,115,121,115,35,116,104,114,101,97,100,45,98,108,111,99,107,45,102,111,114,45,105,47,111,33,32,116,32,102,100,32,105,47,111,41,0,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,108,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,37),40,35,35,115,121,115,35,99,108,101,97,114,45,105,47,111,45,115,116,97,116,101,45,102,111,114,45,116,104,114,101,97,100,33,32,116,41,0,0,0};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,27),40,102,95,50,52,57,51,32,113,117,101,117,101,32,97,114,103,32,118,97,108,32,105,110,105,116,41,0,0,0,0,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,108,41};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,108,32,105,41,0,0,0,0,0,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,108,32,105,41,0,0,0,0,0,0};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,108,32,105,41,0,0,0,0,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,26),40,35,35,115,121,115,35,97,108,108,45,116,104,114,101,97,100,115,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,31),40,35,35,115,121,115,35,102,101,116,99,104,45,97,110,100,45,99,108,101,97,114,45,116,104,114,101,97,100,115,41,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,27),40,35,35,115,121,115,35,114,101,115,116,111,114,101,45,116,104,114,101,97,100,115,32,118,101,99,41,0,0,0,0,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,25),40,35,35,115,121,115,35,116,104,114,101,97,100,45,117,110,98,108,111,99,107,33,32,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,7),40,97,50,53,56,48,41,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,14),40,97,50,53,54,56,32,114,101,116,117,114,110,41,0,0};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,24),40,35,35,115,121,115,35,116,104,114,101,97,100,45,115,108,101,101,112,33,32,116,109,41};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,27),40,99,104,105,99,107,101,110,46,98,97,115,101,35,115,108,101,101,112,45,104,111,111,107,32,110,41,0,0,0,0,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,9),40,115,117,115,112,101,110,100,41,0,0,0,0,0,0,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,6),40,103,54,53,51,41,0,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,18),40,102,111,114,45,101,97,99,104,45,108,111,111,112,54,53,50,41,0,0,0,0,0,0};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,18),40,102,111,114,45,101,97,99,104,45,108,111,111,112,54,56,53,41,0,0,0,0,0,0};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,6),40,103,54,54,51,41,0,0};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,18),40,102,111,114,45,101,97,99,104,45,108,111,111,112,54,54,50,41,0,0,0,0,0,0};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,32),40,35,35,115,121,115,35,107,105,108,108,45,111,116,104,101,114,45,116,104,114,101,97,100,115,32,116,104,117,110,107,41};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


/* from g512 */
C_regparm static C_word C_fcall stub516(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_truep(C_a0);
unsigned int t1=(unsigned int )C_num_to_unsigned_int(C_a1);
C_r=C_fix((C_word)C_ready_fds_timeout(t0,t1));
return C_r;}

/* from g443 */
C_regparm static C_word C_fcall stub448(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
int t1=(int )C_truep(C_a1);
int t2=(int )C_truep(C_a2);
C_fdset_add(t0,t1,t2);
return C_r;}

/* from g386 */
C_regparm static C_word C_fcall stub389(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_prepare_fdset(t0);
return C_r;}

C_noret_decl(f_1000)
static void C_fcall f_1000(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1004)
static void C_ccall f_1004(C_word c,C_word *av) C_noret;
C_noret_decl(f_1007)
static void C_ccall f_1007(C_word c,C_word *av) C_noret;
C_noret_decl(f_1012)
static void C_fcall f_1012(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1016)
static void C_fcall f_1016(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1076)
static void C_fcall f_1076(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1110)
static void C_ccall f_1110(C_word c,C_word *av) C_noret;
C_noret_decl(f_1113)
static void C_ccall f_1113(C_word c,C_word *av) C_noret;
C_noret_decl(f_1125)
static void C_fcall f_1125(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1131)
static void C_ccall f_1131(C_word c,C_word *av) C_noret;
C_noret_decl(f_1143)
static void C_ccall f_1143(C_word c,C_word *av) C_noret;
C_noret_decl(f_1151)
static void C_ccall f_1151(C_word c,C_word *av) C_noret;
C_noret_decl(f_1185)
static void C_ccall f_1185(C_word c,C_word *av) C_noret;
C_noret_decl(f_1196)
static void C_ccall f_1196(C_word c,C_word *av) C_noret;
C_noret_decl(f_1199)
static void C_ccall f_1199(C_word c,C_word *av) C_noret;
C_noret_decl(f_1244)
static C_word C_fcall f_1244(C_word t0);
C_noret_decl(f_1298)
static void C_ccall f_1298(C_word c,C_word *av) C_noret;
C_noret_decl(f_1302)
static void C_ccall f_1302(C_word c,C_word *av) C_noret;
C_noret_decl(f_1316)
static void C_ccall f_1316(C_word c,C_word *av) C_noret;
C_noret_decl(f_1323)
static void C_ccall f_1323(C_word c,C_word *av) C_noret;
C_noret_decl(f_1326)
static void C_ccall f_1326(C_word c,C_word *av) C_noret;
C_noret_decl(f_1332)
static C_word C_fcall f_1332(C_word t0,C_word t1,C_word t2);
C_noret_decl(f_1367)
static void C_ccall f_1367(C_word c,C_word *av) C_noret;
C_noret_decl(f_1377)
static void C_ccall f_1377(C_word c,C_word *av) C_noret;
C_noret_decl(f_1388)
static void C_fcall f_1388(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1436)
static void C_ccall f_1436(C_word c,C_word *av) C_noret;
C_noret_decl(f_1501)
static void C_ccall f_1501(C_word c,C_word *av) C_noret;
C_noret_decl(f_1517)
static void C_fcall f_1517(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1527)
static void C_ccall f_1527(C_word c,C_word *av) C_noret;
C_noret_decl(f_1543)
static void C_fcall f_1543(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1566)
static void C_ccall f_1566(C_word c,C_word *av) C_noret;
C_noret_decl(f_1570)
static void C_ccall f_1570(C_word c,C_word *av) C_noret;
C_noret_decl(f_1576)
static void C_fcall f_1576(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1579)
static void C_ccall f_1579(C_word c,C_word *av) C_noret;
C_noret_decl(f_1582)
static void C_ccall f_1582(C_word c,C_word *av) C_noret;
C_noret_decl(f_1600)
static void C_ccall f_1600(C_word c,C_word *av) C_noret;
C_noret_decl(f_1607)
static void C_fcall f_1607(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1626)
static void C_fcall f_1626(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1636)
static void C_ccall f_1636(C_word c,C_word *av) C_noret;
C_noret_decl(f_1657)
static void C_ccall f_1657(C_word c,C_word *av) C_noret;
C_noret_decl(f_1674)
static void C_ccall f_1674(C_word c,C_word *av) C_noret;
C_noret_decl(f_1680)
static void C_ccall f_1680(C_word c,C_word *av) C_noret;
C_noret_decl(f_1692)
static void C_ccall f_1692(C_word c,C_word *av) C_noret;
C_noret_decl(f_1696)
static void C_ccall f_1696(C_word c,C_word *av) C_noret;
C_noret_decl(f_1702)
static void C_ccall f_1702(C_word c,C_word *av) C_noret;
C_noret_decl(f_1716)
static void C_ccall f_1716(C_word c,C_word *av) C_noret;
C_noret_decl(f_1720)
static void C_ccall f_1720(C_word c,C_word *av) C_noret;
C_noret_decl(f_1729)
static void C_ccall f_1729(C_word c,C_word *av) C_noret;
C_noret_decl(f_1743)
static void C_fcall f_1743(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1754)
static void C_fcall f_1754(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1797)
static void C_ccall f_1797(C_word c,C_word *av) C_noret;
C_noret_decl(f_1803)
static void C_ccall f_1803(C_word c,C_word *av) C_noret;
C_noret_decl(f_1806)
static void C_ccall f_1806(C_word c,C_word *av) C_noret;
C_noret_decl(f_1809)
static void C_ccall f_1809(C_word c,C_word *av) C_noret;
C_noret_decl(f_1812)
static void C_ccall f_1812(C_word c,C_word *av) C_noret;
C_noret_decl(f_1815)
static void C_ccall f_1815(C_word c,C_word *av) C_noret;
C_noret_decl(f_1818)
static void C_ccall f_1818(C_word c,C_word *av) C_noret;
C_noret_decl(f_1839)
static void C_ccall f_1839(C_word c,C_word *av) C_noret;
C_noret_decl(f_1851)
static void C_fcall f_1851(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1861)
static void C_ccall f_1861(C_word c,C_word *av) C_noret;
C_noret_decl(f_1876)
static void C_ccall f_1876(C_word c,C_word *av) C_noret;
C_noret_decl(f_1910)
static void C_ccall f_1910(C_word c,C_word *av) C_noret;
C_noret_decl(f_1916)
static void C_ccall f_1916(C_word c,C_word *av) C_noret;
C_noret_decl(f_1919)
static void C_ccall f_1919(C_word c,C_word *av) C_noret;
C_noret_decl(f_1922)
static void C_ccall f_1922(C_word c,C_word *av) C_noret;
C_noret_decl(f_1925)
static void C_ccall f_1925(C_word c,C_word *av) C_noret;
C_noret_decl(f_1928)
static void C_ccall f_1928(C_word c,C_word *av) C_noret;
C_noret_decl(f_1931)
static void C_ccall f_1931(C_word c,C_word *av) C_noret;
C_noret_decl(f_1934)
static void C_ccall f_1934(C_word c,C_word *av) C_noret;
C_noret_decl(f_1937)
static void C_ccall f_1937(C_word c,C_word *av) C_noret;
C_noret_decl(f_1955)
static void C_ccall f_1955(C_word c,C_word *av) C_noret;
C_noret_decl(f_1959)
static void C_ccall f_1959(C_word c,C_word *av) C_noret;
C_noret_decl(f_1974)
static void C_fcall f_1974(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2022)
static void C_ccall f_2022(C_word c,C_word *av) C_noret;
C_noret_decl(f_2031)
static void C_ccall f_2031(C_word c,C_word *av) C_noret;
C_noret_decl(f_2055)
static void C_ccall f_2055(C_word c,C_word *av) C_noret;
C_noret_decl(f_2057)
static void C_fcall f_2057(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_2084)
static void C_fcall f_2084(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2119)
static void C_ccall f_2119(C_word c,C_word *av) C_noret;
C_noret_decl(f_2153)
static void C_ccall f_2153(C_word c,C_word *av) C_noret;
C_noret_decl(f_2156)
static void C_ccall f_2156(C_word c,C_word *av) C_noret;
C_noret_decl(f_2177)
static void C_ccall f_2177(C_word c,C_word *av) C_noret;
C_noret_decl(f_2183)
static void C_ccall f_2183(C_word c,C_word *av) C_noret;
C_noret_decl(f_2186)
static void C_ccall f_2186(C_word c,C_word *av) C_noret;
C_noret_decl(f_2189)
static void C_ccall f_2189(C_word c,C_word *av) C_noret;
C_noret_decl(f_2192)
static void C_ccall f_2192(C_word c,C_word *av) C_noret;
C_noret_decl(f_2195)
static void C_ccall f_2195(C_word c,C_word *av) C_noret;
C_noret_decl(f_2198)
static void C_ccall f_2198(C_word c,C_word *av) C_noret;
C_noret_decl(f_2206)
static void C_fcall f_2206(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2209)
static void C_ccall f_2209(C_word c,C_word *av) C_noret;
C_noret_decl(f_2212)
static void C_ccall f_2212(C_word c,C_word *av) C_noret;
C_noret_decl(f_2253)
static void C_ccall f_2253(C_word c,C_word *av) C_noret;
C_noret_decl(f_2273)
static void C_ccall f_2273(C_word c,C_word *av) C_noret;
C_noret_decl(f_2284)
static void C_ccall f_2284(C_word c,C_word *av) C_noret;
C_noret_decl(f_2289)
static void C_fcall f_2289(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2303)
static void C_ccall f_2303(C_word c,C_word *av) C_noret;
C_noret_decl(f_2305)
static void C_fcall f_2305(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2327)
static void C_ccall f_2327(C_word c,C_word *av) C_noret;
C_noret_decl(f_2346)
static void C_ccall f_2346(C_word c,C_word *av) C_noret;
C_noret_decl(f_2358)
static void C_ccall f_2358(C_word c,C_word *av) C_noret;
C_noret_decl(f_2376)
static void C_fcall f_2376(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2392)
static void C_ccall f_2392(C_word c,C_word *av) C_noret;
C_noret_decl(f_2399)
static void C_fcall f_2399(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2418)
static void C_ccall f_2418(C_word c,C_word *av) C_noret;
C_noret_decl(f_2423)
static void C_fcall f_2423(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2441)
static void C_ccall f_2441(C_word c,C_word *av) C_noret;
C_noret_decl(f_2448)
static void C_fcall f_2448(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2464)
static void C_ccall f_2464(C_word c,C_word *av) C_noret;
C_noret_decl(f_2493)
static void C_ccall f_2493(C_word c,C_word *av) C_noret;
C_noret_decl(f_2502)
static void C_ccall f_2502(C_word c,C_word *av) C_noret;
C_noret_decl(f_2512)
static void C_ccall f_2512(C_word c,C_word *av) C_noret;
C_noret_decl(f_2531)
static void C_ccall f_2531(C_word c,C_word *av) C_noret;
C_noret_decl(f_2544)
static void C_ccall f_2544(C_word c,C_word *av) C_noret;
C_noret_decl(f_2547)
static void C_ccall f_2547(C_word c,C_word *av) C_noret;
C_noret_decl(f_2563)
static void C_ccall f_2563(C_word c,C_word *av) C_noret;
C_noret_decl(f_2569)
static void C_ccall f_2569(C_word c,C_word *av) C_noret;
C_noret_decl(f_2576)
static void C_ccall f_2576(C_word c,C_word *av) C_noret;
C_noret_decl(f_2581)
static void C_ccall f_2581(C_word c,C_word *av) C_noret;
C_noret_decl(f_2587)
static void C_ccall f_2587(C_word c,C_word *av) C_noret;
C_noret_decl(f_2601)
static void C_ccall f_2601(C_word c,C_word *av) C_noret;
C_noret_decl(f_2604)
static C_word C_fcall f_2604(C_word t0,C_word t1);
C_noret_decl(f_2630)
static C_word C_fcall f_2630(C_word t0,C_word t1);
C_noret_decl(f_2642)
static C_word C_fcall f_2642(C_word t0,C_word t1);
C_noret_decl(f_2651)
static C_word C_fcall f_2651(C_word t0,C_word t1);
C_noret_decl(f_2680)
static void C_ccall f_2680(C_word c,C_word *av) C_noret;
C_noret_decl(f_2685)
static C_word C_fcall f_2685(C_word t0,C_word t1);
C_noret_decl(f_2708)
static C_word C_fcall f_2708(C_word t0,C_word t1);
C_noret_decl(f_916)
static void C_ccall f_916(C_word c,C_word *av) C_noret;
C_noret_decl(f_919)
static void C_ccall f_919(C_word c,C_word *av) C_noret;
C_noret_decl(f_921)
static void C_fcall f_921(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_927)
static void C_fcall f_927(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_954)
static void C_ccall f_954(C_word c,C_word *av) C_noret;
C_noret_decl(f_964)
static void C_ccall f_964(C_word c,C_word *av) C_noret;
C_noret_decl(f_995)
static void C_ccall f_995(C_word c,C_word *av) C_noret;
C_noret_decl(C_scheduler_toplevel)
C_externexport void C_ccall C_scheduler_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_1000)
static void C_ccall trf_1000(C_word c,C_word *av) C_noret;
static void C_ccall trf_1000(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1000(t0,t1);}

C_noret_decl(trf_1012)
static void C_ccall trf_1012(C_word c,C_word *av) C_noret;
static void C_ccall trf_1012(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1012(t0,t1);}

C_noret_decl(trf_1016)
static void C_ccall trf_1016(C_word c,C_word *av) C_noret;
static void C_ccall trf_1016(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1016(t0,t1);}

C_noret_decl(trf_1076)
static void C_ccall trf_1076(C_word c,C_word *av) C_noret;
static void C_ccall trf_1076(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1076(t0,t1,t2);}

C_noret_decl(trf_1125)
static void C_ccall trf_1125(C_word c,C_word *av) C_noret;
static void C_ccall trf_1125(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1125(t0,t1);}

C_noret_decl(trf_1388)
static void C_ccall trf_1388(C_word c,C_word *av) C_noret;
static void C_ccall trf_1388(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1388(t0,t1,t2,t3);}

C_noret_decl(trf_1517)
static void C_ccall trf_1517(C_word c,C_word *av) C_noret;
static void C_ccall trf_1517(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1517(t0,t1,t2);}

C_noret_decl(trf_1543)
static void C_ccall trf_1543(C_word c,C_word *av) C_noret;
static void C_ccall trf_1543(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1543(t0,t1,t2);}

C_noret_decl(trf_1576)
static void C_ccall trf_1576(C_word c,C_word *av) C_noret;
static void C_ccall trf_1576(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1576(t0,t1);}

C_noret_decl(trf_1607)
static void C_ccall trf_1607(C_word c,C_word *av) C_noret;
static void C_ccall trf_1607(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1607(t0,t1,t2);}

C_noret_decl(trf_1626)
static void C_ccall trf_1626(C_word c,C_word *av) C_noret;
static void C_ccall trf_1626(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1626(t0,t1,t2);}

C_noret_decl(trf_1743)
static void C_ccall trf_1743(C_word c,C_word *av) C_noret;
static void C_ccall trf_1743(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1743(t0,t1,t2);}

C_noret_decl(trf_1754)
static void C_ccall trf_1754(C_word c,C_word *av) C_noret;
static void C_ccall trf_1754(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1754(t0,t1,t2);}

C_noret_decl(trf_1851)
static void C_ccall trf_1851(C_word c,C_word *av) C_noret;
static void C_ccall trf_1851(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1851(t0,t1,t2);}

C_noret_decl(trf_1974)
static void C_ccall trf_1974(C_word c,C_word *av) C_noret;
static void C_ccall trf_1974(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1974(t0,t1,t2);}

C_noret_decl(trf_2057)
static void C_ccall trf_2057(C_word c,C_word *av) C_noret;
static void C_ccall trf_2057(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_2057(t0,t1,t2,t3,t4);}

C_noret_decl(trf_2084)
static void C_ccall trf_2084(C_word c,C_word *av) C_noret;
static void C_ccall trf_2084(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2084(t0,t1,t2,t3);}

C_noret_decl(trf_2206)
static void C_ccall trf_2206(C_word c,C_word *av) C_noret;
static void C_ccall trf_2206(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2206(t0,t1);}

C_noret_decl(trf_2289)
static void C_ccall trf_2289(C_word c,C_word *av) C_noret;
static void C_ccall trf_2289(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2289(t0,t1);}

C_noret_decl(trf_2305)
static void C_ccall trf_2305(C_word c,C_word *av) C_noret;
static void C_ccall trf_2305(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2305(t0,t1,t2);}

C_noret_decl(trf_2376)
static void C_ccall trf_2376(C_word c,C_word *av) C_noret;
static void C_ccall trf_2376(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2376(t0,t1,t2,t3);}

C_noret_decl(trf_2399)
static void C_ccall trf_2399(C_word c,C_word *av) C_noret;
static void C_ccall trf_2399(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2399(t0,t1,t2,t3);}

C_noret_decl(trf_2423)
static void C_ccall trf_2423(C_word c,C_word *av) C_noret;
static void C_ccall trf_2423(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2423(t0,t1,t2);}

C_noret_decl(trf_2448)
static void C_ccall trf_2448(C_word c,C_word *av) C_noret;
static void C_ccall trf_2448(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2448(t0,t1,t2,t3);}

C_noret_decl(trf_921)
static void C_ccall trf_921(C_word c,C_word *av) C_noret;
static void C_ccall trf_921(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_921(t0,t1,t2);}

C_noret_decl(trf_927)
static void C_ccall trf_927(C_word c,C_word *av) C_noret;
static void C_ccall trf_927(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_927(t0,t1,t2);}

/* loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_fcall f_1000(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,0,3)))){
C_save_and_reclaim_args((void *)trf_1000,2,t0,t1);}
a=C_alloc(21);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1004,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_nullp(lf[5]))){
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_1004(2,av2);}}
else{
t3=C_a_i_current_process_milliseconds(&a,1,C_SCHEME_FALSE);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1076,a[2]=t3,a[3]=t5,a[4]=((C_word*)t0)[3],a[5]=((C_word)li8),tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_1076(t7,t2,lf[5]);}}

/* k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1004(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_1004,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1007,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)((C_word*)t0)[4])[1])){
t3=(
/* scheduler.scm:223: ##sys#update-thread-state-buffer */
  f_1244(((C_word*)t0)[5])
);
/* scheduler.scm:224: ##sys#force-primordial */
t4=*((C_word*)lf[19]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_i_nullp(lf[6]))){
t3=C_SCHEME_UNDEFINED;
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
f_1007(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2022,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1876,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* scheduler.scm:405: ##sys#length */
t5=*((C_word*)lf[40]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[6];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}}

/* k1005 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1007(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_1007,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1012,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word)li2),tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_1012(t5,((C_word*)t0)[3]);}

/* loop2 in k1005 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_fcall f_1012(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1012,2,t0,t1);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1016,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=lf[17];
t4=C_i_nullp(lf[17]);
if(C_truep(C_i_not(t4))){
t5=C_u_i_cdr(lf[17]);
t6=C_mutate(&lf[17] /* (set! ready-queue-head ...) */,t5);
t7=C_eqp(C_SCHEME_END_OF_LIST,t5);
if(C_truep(t7)){
t8=lf[18] /* ready-queue-tail */ =C_SCHEME_END_OF_LIST;;
t9=t2;
f_1016(t9,C_u_i_car(t3));}
else{
t8=t2;
f_1016(t8,C_u_i_car(t3));}}
else{
t5=t2;
f_1016(t5,C_SCHEME_FALSE);}}

/* k1014 in loop2 in k1005 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_fcall f_1016(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_1016,2,t0,t1);}
if(C_truep(C_i_not(t1))){
if(C_truep(C_i_nullp(lf[5]))){
if(C_truep(C_i_nullp(lf[6]))){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_halt(lf[7]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* scheduler.scm:233: loop1 */
t2=((C_word*)((C_word*)t0)[3])[1];
f_1000(t2,((C_word*)t0)[2]);}}
else{
/* scheduler.scm:233: loop1 */
t2=((C_word*)((C_word*)t0)[3])[1];
f_1000(t2,((C_word*)t0)[2]);}}
else{
t2=C_slot(t1,C_fix(3));
t3=C_eqp(t2,lf[8]);
if(C_truep(t3)){
t4=C_mutate((C_word*)lf[3]+1 /* (set! ##sys#current-thread ...) */,t1);
t5=C_i_setslot(t1,C_fix(3),lf[9]);
t6=C_slot(t1,C_fix(5));
t7=C_slot(t6,C_fix(0));
t8=C_mutate((C_word*)lf[10]+1 /* (set! ##sys#dynamic-winds ...) */,t7);
t9=C_slot(t6,C_fix(1));
t10=C_mutate((C_word*)lf[11]+1 /* (set! ##sys#standard-input ...) */,t9);
t11=C_slot(t6,C_fix(2));
t12=C_mutate((C_word*)lf[12]+1 /* (set! ##sys#standard-output ...) */,t11);
t13=C_slot(t6,C_fix(3));
t14=C_mutate((C_word*)lf[13]+1 /* (set! ##sys#standard-error ...) */,t13);
t15=C_slot(t6,C_fix(4));
t16=C_mutate((C_word*)lf[14]+1 /* (set! ##sys#current-exception-handler ...) */,t15);
t17=C_slot(t6,C_fix(5));
t18=C_mutate((C_word*)lf[15]+1 /* (set! ##sys#current-parameter-vector ...) */,t17);
t19=C_slot(t1,C_fix(9));
t20=C_set_initial_timer_interrupt_period(t19);
/* scheduler.scm:175: ##sys#call-with-cthulhu */
t21=*((C_word*)lf[16]+1);{
C_word av2[3];
av2[0]=t21;
av2[1]=((C_word*)t0)[2];
av2[2]=C_slot(t1,C_fix(1));
((C_proc)(void*)(*((C_word*)t21+1)))(3,av2);}}
else{
/* scheduler.scm:235: loop2 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_1012(t4,((C_word*)t0)[2]);}}}

/* loop in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_fcall f_1076(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_1076,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t3=lf[5] /* timeout-list */ =C_SCHEME_END_OF_LIST;;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=C_u_i_caar(t2);
t4=C_u_i_car(t2);
t5=C_u_i_cdr(t4);
t6=C_slot(t5,C_fix(4));
if(C_truep(C_i_equalp(t3,t6))){
if(C_truep(C_i_greater_or_equalp(((C_word*)t0)[2],t3))){
t7=C_i_set_i_slot(t5,C_fix(13),C_SCHEME_TRUE);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1110,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* scheduler.scm:200: ##sys#clear-i/o-state-for-thread! */
f_2289(t8,t5);}
else{
t7=C_mutate(&lf[5] /* (set! timeout-list ...) */,t2);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1125,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_nullp(lf[17]))){
t9=C_i_nullp(lf[6]);
t10=t8;
f_1125(t10,(C_truep(t9)?C_i_pairp(lf[5]):C_SCHEME_FALSE));}
else{
t9=t8;
f_1125(t9,C_SCHEME_FALSE);}}}
else{
/* scheduler.scm:219: loop */
t11=t1;
t12=C_u_i_cdr(t2);
t1=t11;
t2=t12;
goto loop;}}}

/* k1108 in loop in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1110(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1110,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1113,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:201: ##sys#thread-basic-unblock! */
t3=*((C_word*)lf[20]+1);{
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

/* k1111 in k1108 in loop in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1113(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1113,c,av);}
/* scheduler.scm:202: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1076(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}

/* k1123 in loop in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_fcall f_1125(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_1125,2,t0,t1);}
a=C_alloc(8);
if(C_truep(t1)){
t2=C_u_i_caar(lf[5]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1131,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1151,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* scheduler.scm:212: scheme#round */
t5=*((C_word*)lf[37]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k1129 in k1123 in loop in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1131(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,c,3)))){
C_save_and_reclaim((void *)f_1131,c,av);}
a=C_alloc(33);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1143,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_s_a_i_minus(&a,2,t1,((C_word*)t0)[4]);
/* scheduler.scm:216: scheme#max */
t4=*((C_word*)lf[35]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=C_fix(0);
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k1141 in k1129 in k1123 in loop in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1143(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1143,c,av);}
if(C_truep(C_i_not(C_msleep(t1)))){
t2=C_mk_bool(C_signal_interrupted_p);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k1149 in k1123 in loop in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1151(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1151,c,av);}
/* scheduler.scm:212: scheme#inexact->exact */
t2=*((C_word*)lf[36]+1);{
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

/* ##sys#force-primordial in k917 in k914 */
static void C_ccall f_1185(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1185,c,av);}
t2=C_i_set_i_slot(*((C_word*)lf[43]+1),C_fix(13),C_SCHEME_FALSE);
/* scheduler.scm:240: ##sys#thread-unblock! */
t3=*((C_word*)lf[44]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=*((C_word*)lf[43]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* ##sys#ready-queue in k917 in k914 */
static void C_ccall f_1196(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1196,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[17];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#add-to-ready-queue in k917 in k914 */
static void C_ccall f_1199(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_1199,c,av);}
a=C_alloc(3);
t3=C_i_setslot(t2,C_fix(3),lf[8]);
t4=C_a_i_cons(&a,2,t2,C_SCHEME_END_OF_LIST);
t5=C_eqp(C_SCHEME_END_OF_LIST,lf[17]);
if(C_truep(t5)){
t6=C_mutate(&lf[17] /* (set! ready-queue-head ...) */,t4);
t7=C_mutate(&lf[18] /* (set! ready-queue-tail ...) */,t4);
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t6=C_i_setslot(lf[18],C_fix(1),t4);
t7=C_mutate(&lf[18] /* (set! ready-queue-tail ...) */,t4);
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* ##sys#update-thread-state-buffer in k917 in k914 */
static C_word C_fcall f_1244(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;{}
t2=C_slot(t1,C_fix(5));
t3=C_i_setslot(t2,C_fix(0),*((C_word*)lf[10]+1));
t4=C_i_setslot(t2,C_fix(1),*((C_word*)lf[11]+1));
t5=C_i_setslot(t2,C_fix(2),*((C_word*)lf[12]+1));
t6=C_i_setslot(t2,C_fix(3),*((C_word*)lf[13]+1));
t7=C_i_setslot(t2,C_fix(4),*((C_word*)lf[14]+1));
return(C_i_setslot(t2,C_fix(5),*((C_word*)lf[15]+1)));}

/* ##sys#interrupt-hook in k917 in k914 */
static void C_ccall f_1298(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_1298,c,av);}
a=C_alloc(12);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1302,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t5=C_eqp(t2,C_fix(255));
if(C_truep(t5)){
t6=*((C_word*)lf[3]+1);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1316,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t3,a[5]=((C_word)li15),tmp=(C_word)a,a+=6,tmp);
t8=C_i_setslot(*((C_word*)lf[3]+1),C_fix(1),t7);
/* scheduler.scm:287: ##sys#schedule */
t9=*((C_word*)lf[2]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
/* scheduler.scm:288: oldhook */
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}}

/* k1300 in ##sys#interrupt-hook in k917 in k914 */
static void C_ccall f_1302(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1302,c,av);}
/* scheduler.scm:288: oldhook */
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
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* a1315 in ##sys#interrupt-hook in k917 in k914 */
static void C_ccall f_1316(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1316,c,av);}
/* scheduler.scm:286: oldhook */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* ##sys#timeout-queue in k917 in k914 */
static void C_ccall f_1323(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1323,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[5];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#remove-from-timeout-list in k917 in k914 */
static void C_ccall f_1326(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_1326,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1332,a[2]=t2,a[3]=((C_word)li18),tmp=(C_word)a,a+=4,tmp);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(
  f_1332(t3,lf[5],C_SCHEME_FALSE)
);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* loop in ##sys#remove-from-timeout-list in k917 in k914 */
static C_word C_fcall f_1332(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
loop:{}
if(C_truep(C_i_nullp(t1))){
return(t1);}
else{
t3=C_slot(t1,C_fix(0));
t4=C_slot(t1,C_fix(1));
t5=C_slot(t3,C_fix(1));
t6=C_eqp(t5,((C_word*)t0)[2]);
if(C_truep(t6)){
if(C_truep(t2)){
return(C_i_setslot(t2,C_fix(1),t4));}
else{
t7=C_mutate(&lf[5] /* (set! timeout-list ...) */,t4);
return(t7);}}
else{
t9=t4;
t10=t1;
t1=t9;
t2=t10;
goto loop;}}}

/* ##sys#thread-block-for-timeout! in k917 in k914 */
static void C_ccall f_1367(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_1367,c,av);}
a=C_alloc(13);
if(C_truep(C_i_greaterp(t3,C_fix(0)))){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1377,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1388,a[2]=t3,a[3]=t2,a[4]=t6,a[5]=((C_word)li20),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_1388(t8,t4,lf[5],C_SCHEME_FALSE);}
else{
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k1375 in ##sys#thread-block-for-timeout! in k917 in k914 */
static void C_ccall f_1377(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1377,c,av);}
t2=C_i_setslot(((C_word*)t0)[2],C_fix(3),lf[49]);
t3=C_i_set_i_slot(((C_word*)t0)[2],C_fix(13),C_SCHEME_FALSE);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_setslot(((C_word*)t0)[2],C_fix(4),((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* loop in ##sys#thread-block-for-timeout! in k917 in k914 */
static void C_fcall f_1388(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_1388,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_nullp(t2);
t5=(C_truep(t4)?t4:C_i_lessp(((C_word*)t0)[2],C_u_i_caar(t2)));
if(C_truep(t5)){
if(C_truep(t3)){
t6=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t7=C_a_i_cons(&a,2,t6,t2);
t8=t1;{
C_word av2[2];
av2[0]=t8;
av2[1]=C_i_setslot(t3,C_fix(1),t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t6=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t7=C_a_i_cons(&a,2,t6,t2);
t8=C_mutate(&lf[5] /* (set! timeout-list ...) */,t7);
t9=t1;{
C_word av2[2];
av2[0]=t9;
av2[1]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}
else{
/* scheduler.scm:315: loop */
t10=t1;
t11=C_u_i_cdr(t2);
t12=t2;
t1=t10;
t2=t11;
t3=t12;
goto loop;}}

/* ##sys#thread-block-for-termination! in k917 in k914 */
static void C_ccall f_1436(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_1436,c,av);}
a=C_alloc(3);
t4=C_slot(t3,C_fix(3));
t5=C_eqp(t4,lf[51]);
t6=(C_truep(t5)?t5:C_eqp(t4,lf[52]));
if(C_truep(t6)){
t7=C_SCHEME_UNDEFINED;
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t7=C_slot(t3,C_fix(12));
t8=C_a_i_cons(&a,2,t2,t7);
t9=C_i_setslot(t3,C_fix(12),t8);
t10=C_i_setslot(t2,C_fix(3),lf[49]);
t11=C_i_set_i_slot(t2,C_fix(13),C_SCHEME_FALSE);
t12=t1;{
C_word *av2=av;
av2[0]=t12;
av2[1]=C_i_setslot(t2,C_fix(11),t3);
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}}

/* k1499 in for-each-loop292 in ##sys#thread-kill! in k917 in k914 */
static void C_ccall f_1501(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1501,c,av);}
t2=C_i_set_i_slot(((C_word*)t0)[2],C_fix(3),C_SCHEME_END_OF_LIST);
t3=((C_word*)((C_word*)t0)[3])[1];
f_1543(t3,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* for-each-loop306 in for-each-loop292 in ##sys#thread-kill! in k917 in k914 */
static void C_fcall f_1517(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1517,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1527,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:342: ##sys#thread-unblock! */
t4=*((C_word*)lf[44]+1);{
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

/* k1525 in for-each-loop306 in for-each-loop292 in ##sys#thread-kill! in k917 in k914 */
static void C_ccall f_1527(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1527,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_1517(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop292 in ##sys#thread-kill! in k917 in k914 */
static void C_fcall f_1543(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_1543,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_set_i_slot(t3,C_fix(2),C_SCHEME_FALSE);
t5=C_i_set_i_slot(t3,C_fix(4),C_SCHEME_TRUE);
t6=C_i_set_i_slot(t3,C_fix(5),C_SCHEME_FALSE);
t7=C_slot(t3,C_fix(3));
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1501,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_nullp(t7))){
t9=C_i_set_i_slot(t3,C_fix(3),C_SCHEME_END_OF_LIST);
t13=t1;
t14=C_slot(t2,C_fix(1));
t1=t13;
t2=t14;
goto loop;}
else{
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1517,a[2]=t10,a[3]=((C_word)li25),tmp=(C_word)a,a+=4,tmp));
t12=((C_word*)t10)[1];
f_1517(t12,t8,t7);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* ##sys#thread-kill! in k917 in k914 */
static void C_ccall f_1566(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_1566,c,av);}
a=C_alloc(11);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1570,a[2]=t2,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t5=C_slot(t2,C_fix(8));
if(C_truep(C_i_nullp(t5))){
t6=C_SCHEME_UNDEFINED;
t7=t4;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
f_1570(2,av2);}}
else{
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1543,a[2]=t7,a[3]=((C_word)li26),tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_1543(t9,t4,t5);}}

/* k1568 in ##sys#thread-kill! in k917 in k914 */
static void C_ccall f_1570(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_1570,c,av);}
a=C_alloc(9);
t2=C_slot(((C_word*)t0)[2],C_fix(11));
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1576,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_structurep(t2,lf[54]))){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1657,a[2]=t3,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:353: delq */
f_921(t4,((C_word*)t0)[2],C_slot(t2,C_fix(2)));}
else{
if(C_truep(C_i_structurep(t2,lf[55]))){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1674,a[2]=t3,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:355: delq */
f_921(t4,((C_word*)t0)[2],C_slot(t2,C_fix(12)));}
else{
t4=C_SCHEME_UNDEFINED;
t5=t3;
f_1576(t5,t4);}}}

/* k1574 in k1568 in ##sys#thread-kill! in k917 in k914 */
static void C_fcall f_1576(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1576,2,t0,t1);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1579,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:356: ##sys#remove-from-timeout-list */
t3=*((C_word*)lf[21]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k1577 in k1574 in k1568 in ##sys#thread-kill! in k917 in k914 */
static void C_ccall f_1579(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1579,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1582,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:357: ##sys#clear-i/o-state-for-thread! */
f_2289(t2,((C_word*)t0)[2]);}

/* k1580 in k1577 in k1574 in k1568 in ##sys#thread-kill! in k917 in k914 */
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_1582,c,av);}
a=C_alloc(15);
t2=C_i_setslot(((C_word*)t0)[2],C_fix(3),((C_word*)t0)[3]);
t3=C_i_set_i_slot(((C_word*)t0)[2],C_fix(4),C_SCHEME_FALSE);
t4=C_i_set_i_slot(((C_word*)t0)[2],C_fix(11),C_SCHEME_FALSE);
t5=C_i_set_i_slot(((C_word*)t0)[2],C_fix(8),C_SCHEME_END_OF_LIST);
t6=C_slot(((C_word*)t0)[2],C_fix(12));
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1600,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_nullp(t6))){
t8=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_i_set_i_slot(((C_word*)t0)[2],C_fix(12),C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1607,a[2]=((C_word*)t0)[2],a[3]=((C_word)li23),tmp=(C_word)a,a+=4,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1626,a[2]=t10,a[3]=t8,a[4]=((C_word)li24),tmp=(C_word)a,a+=5,tmp));
t12=((C_word*)t10)[1];
f_1626(t12,t7,t6);}}

/* k1598 in k1580 in k1577 in k1574 in k1568 in ##sys#thread-kill! in k917 in k914 */
static void C_ccall f_1600(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1600,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_set_i_slot(((C_word*)t0)[3],C_fix(12),C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* g341 in k1580 in k1577 in k1574 in k1568 in ##sys#thread-kill! in k917 in k914 */
static void C_fcall f_1607(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_1607,3,t0,t1,t2);}
t3=C_slot(t2,C_fix(11));
t4=C_eqp(t3,((C_word*)t0)[2]);
if(C_truep(t4)){
/* scheduler.scm:368: ##sys#thread-basic-unblock! */
t5=*((C_word*)lf[20]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t5=C_SCHEME_UNDEFINED;
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* for-each-loop340 in k1580 in k1577 in k1574 in k1568 in ##sys#thread-kill! in k917 in k914 */
static void C_fcall f_1626(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1626,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1636,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:364: g341 */
t4=((C_word*)t0)[3];
f_1607(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k1634 in for-each-loop340 in k1580 in k1577 in k1574 in k1568 in ##sys#thread-kill! in k917 in k914 */
static void C_ccall f_1636(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1636,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_1626(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k1655 in k1568 in ##sys#thread-kill! in k917 in k914 */
static void C_ccall f_1657(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1657,c,av);}
t2=((C_word*)t0)[2];
f_1576(t2,C_i_setslot(((C_word*)t0)[3],C_fix(2),t1));}

/* k1672 in k1568 in ##sys#thread-kill! in k917 in k914 */
static void C_ccall f_1674(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1674,c,av);}
t2=((C_word*)t0)[2];
f_1576(t2,C_i_setslot(((C_word*)t0)[3],C_fix(12),t1));}

/* ##sys#thread-basic-unblock! in k917 in k914 */
static void C_ccall f_1680(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1680,c,av);}
t3=C_i_set_i_slot(t2,C_fix(11),C_SCHEME_FALSE);
t4=C_i_set_i_slot(t2,C_fix(4),C_SCHEME_FALSE);
/* scheduler.scm:376: ##sys#add-to-ready-queue */
t5=*((C_word*)lf[42]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* ##sys#default-exception-handler in k917 in k914 */
static void C_ccall f_1692(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_1692,c,av);}
a=C_alloc(10);
t3=*((C_word*)lf[3]+1);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1696,a[2]=t3,a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_mk_bool(C_abort_on_thread_exceptions))){
t5=*((C_word*)lf[43]+1);
t6=C_slot(*((C_word*)lf[43]+1),C_fix(1));
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1716,a[2]=t6,a[3]=t2,a[4]=((C_word)li29),tmp=(C_word)a,a+=5,tmp);
t8=C_i_setslot(*((C_word*)lf[43]+1),C_fix(1),t7);
/* scheduler.scm:390: ##sys#thread-unblock! */
t9=*((C_word*)lf[44]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t4;
av2[2]=*((C_word*)lf[43]+1);
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
/* scheduler.scm:392: ##sys#show-exception-warning */
t5=*((C_word*)lf[58]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[59];
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}}

/* k1694 in ##sys#default-exception-handler in k917 in k914 */
static void C_ccall f_1696(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_1696,c,av);}
a=C_alloc(3);
t2=C_i_setslot(((C_word*)t0)[2],C_fix(7),((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1702,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp);
/* scheduler.scm:394: ##sys#thread-kill! */
t4=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[52];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k1700 in k1694 in ##sys#default-exception-handler in k917 in k914 */
static void C_ccall f_1702(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1702,c,av);}
/* scheduler.scm:395: ##sys#schedule */
t2=*((C_word*)lf[2]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a1715 in ##sys#default-exception-handler in k917 in k914 */
static void C_ccall f_1716(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1716,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1720,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:388: chicken.condition#signal */
t3=*((C_word*)lf[57]+1);{
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

/* k1718 in a1715 in ##sys#default-exception-handler in k917 in k914 */
static void C_ccall f_1720(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1720,c,av);}
/* scheduler.scm:389: ptx */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#fd-queue in k917 in k914 */
static void C_ccall f_1729(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1729,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[6];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in k1874 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_fcall f_1743(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,0,3)))){
C_save_and_reclaim_args((void *)trf_1743,3,t0,t1,t2);}
a=C_alloc(25);
if(C_truep(C_i_nullp(t2))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=C_u_i_caar(t2);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_FALSE;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1754,a[2]=t5,a[3]=t7,a[4]=t3,a[5]=((C_word)li5),tmp=(C_word)a,a+=6,tmp);
t9=C_u_i_car(t2);
t10=C_u_i_cdr(t9);
t11=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1839,a[2]=t5,a[3]=t7,a[4]=t3,a[5]=((C_word*)t0)[2],a[6]=t1,a[7]=t2,tmp=(C_word)a,a+=8,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1851,a[2]=t13,a[3]=t8,a[4]=((C_word)li6),tmp=(C_word)a,a+=5,tmp));
t15=((C_word*)t13)[1];
f_1851(t15,t11,t10);}}

/* g400 in loop in k1874 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_fcall f_1754(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1754,3,t0,t1,t2);}
a=C_alloc(5);
t3=C_slot(t2,C_fix(11));
if(C_truep(C_i_pairp(t3))){
t4=C_u_i_cdr(t3);
t5=C_eqp(t4,C_SCHEME_TRUE);
t6=(C_truep(t5)?t5:C_eqp(t4,lf[29]));
if(C_truep(t6)){
t7=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_TRUE);
t8=t1;{
C_word av2[2];
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t7=C_eqp(t4,C_SCHEME_FALSE);
t8=(C_truep(t7)?t7:C_eqp(t4,lf[30]));
if(C_truep(t8)){
t9=C_set_block_item(((C_word*)t0)[3],0,C_SCHEME_TRUE);
t10=t1;{
C_word av2[2];
av2[0]=t10;
av2[1]=t9;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t9=C_eqp(t4,lf[31]);
if(C_truep(t9)){
t10=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_TRUE);
t11=C_set_block_item(((C_word*)t0)[3],0,C_SCHEME_TRUE);
t12=t1;{
C_word av2[2];
av2[0]=t12;
av2[1]=t11;
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}
else{
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1797,a[2]=t1,a[3]=((C_word*)t0)[4],a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:428: chicken.base#open-output-string */
t11=*((C_word*)lf[28]+1);{
C_word av2[2];
av2[0]=t11;
av2[1]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}}}}
else{
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k1795 in g400 in loop in k1874 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1797(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1797,c,av);}
a=C_alloc(6);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[22]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1803,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* scheduler.scm:428: ##sys#print */
t4=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[39];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k1801 in k1795 in g400 in loop in k1874 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1803(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_1803,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1806,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:428: ##sys#print */
t3=*((C_word*)lf[25]+1);{
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
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k1804 in k1801 in k1795 in g400 in loop in k1874 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1806(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_1806,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1809,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:428: ##sys#print */
t3=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[38];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k1807 in k1804 in k1801 in k1795 in g400 in loop in k1874 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1809(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_1809,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1812,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:428: ##sys#print */
t3=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k1810 in k1807 in k1804 in k1801 in k1795 in g400 in loop in k1874 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1812(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_1812,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1815,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:428: ##sys#write-char-0 */
t3=*((C_word*)lf[24]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(41);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k1813 in k1810 in k1807 in k1804 in k1801 in k1795 in g400 in loop in k1874 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1815(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1815,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1818,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* scheduler.scm:428: chicken.base#get-output-string */
t3=*((C_word*)lf[23]+1);{
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

/* k1816 in k1813 in k1810 in k1807 in k1804 in k1801 in k1795 in g400 in loop in k1874 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1818(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1818,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_halt(t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k1837 in loop in k1874 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1839(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1839,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
t3=((C_word*)((C_word*)t0)[3])[1];
t4=stub448(C_SCHEME_UNDEFINED,((C_word*)t0)[4],t2,t3);
/* scheduler.scm:433: loop */
t5=((C_word*)((C_word*)t0)[5])[1];
f_1743(t5,((C_word*)t0)[6],C_u_i_cdr(((C_word*)t0)[7]));}

/* for-each-loop399 in loop in k1874 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_fcall f_1851(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1851,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1861,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:411: g400 */
t4=((C_word*)t0)[3];
f_1754(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k1859 in for-each-loop399 in loop in k1874 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1861(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1861,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_1851(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k1874 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1876(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1876,c,av);}
a=C_alloc(6);
t2=stub389(C_SCHEME_UNDEFINED,t1);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1743,a[2]=t4,a[3]=((C_word)li7),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_1743(t6,((C_word*)t0)[2],lf[6]);}

/* k1908 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1910(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_1910,c,av);}
a=C_alloc(7);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[22]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1916,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* scheduler.scm:441: ##sys#print */
t4=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[34];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k1914 in k1908 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1916(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1916,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1919,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* scheduler.scm:441: ##sys#print */
t3=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k1917 in k1914 in k1908 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1919(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1919,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1922,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* scheduler.scm:441: ##sys#print */
t3=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[33];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k1920 in k1917 in k1914 in k1908 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1922(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_1922,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1925,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:441: ##sys#print */
t3=*((C_word*)lf[25]+1);{
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
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k1923 in k1920 in k1917 in k1914 in k1908 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1925(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_1925,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1928,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:441: ##sys#print */
t3=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[32];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k1926 in k1923 in k1920 in k1917 in k1914 in k1908 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1928(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_1928,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1931,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:441: ##sys#print */
t3=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k1929 in k1926 in k1923 in k1920 in k1917 in k1914 in k1908 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1931(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_1931,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1934,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:441: ##sys#write-char-0 */
t3=*((C_word*)lf[24]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(41);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k1932 in k1929 in k1926 in k1923 in k1920 in k1917 in k1914 in k1908 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1934(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1934,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1937,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* scheduler.scm:441: chicken.base#get-output-string */
t3=*((C_word*)lf[23]+1);{
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

/* k1935 in k1932 in k1929 in k1926 in k1923 in k1920 in k1917 in k1914 in k1908 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_1937(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1937,c,av);}
t2=((C_word*)t0)[2];
f_2206(t2,C_halt(t1));}

/* ##sys#thread-block-for-i/o! in k917 in k914 */
static void C_ccall f_1955(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_1955,c,av);}
a=C_alloc(14);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1959,a[2]=t2,a[3]=t3,a[4]=t4,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1974,a[2]=t3,a[3]=t2,a[4]=t7,a[5]=((C_word)li32),tmp=(C_word)a,a+=6,tmp));
t9=((C_word*)t7)[1];
f_1974(t9,t5,lf[6]);}

/* k1957 in ##sys#thread-block-for-i/o! in k917 in k914 */
static void C_ccall f_1959(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_1959,c,av);}
a=C_alloc(3);
t2=C_i_setslot(((C_word*)t0)[2],C_fix(3),lf[49]);
t3=C_i_set_i_slot(((C_word*)t0)[2],C_fix(13),C_SCHEME_FALSE);
t4=C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_setslot(((C_word*)t0)[2],C_fix(11),t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* loop in ##sys#thread-block-for-i/o! in k917 in k914 */
static void C_fcall f_1974(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_1974,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t2))){
t3=C_a_i_list2(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t4=C_a_i_cons(&a,2,t3,lf[6]);
t5=C_mutate(&lf[6] /* (set! fd-list ...) */,t4);
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t3=C_u_i_car(t2);
t4=C_u_i_car(t3);
t5=C_eqp(((C_word*)t0)[2],t4);
if(C_truep(t5)){
t6=C_u_i_cdr(t3);
t7=C_a_i_cons(&a,2,((C_word*)t0)[3],t6);
t8=t1;{
C_word av2[2];
av2[0]=t8;
av2[1]=C_i_setslot(t3,C_fix(1),t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
/* scheduler.scm:454: loop */
t9=t1;
t10=C_u_i_cdr(t2);
t1=t9;
t2=t10;
goto loop;}}}

/* k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2022(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_2022,c,av);}
a=C_alloc(11);
t2=C_i_pairp(lf[5]);
t3=C_i_pairp(lf[17]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2031,a[2]=t3,a[3]=t2,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
t5=(C_truep(t2)?C_i_not(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_u_i_caar(lf[5]);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2273,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2284,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
/* scheduler.scm:466: scheme#round */
t9=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t8;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
t6=t4;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_fix(0);
f_2031(2,av2);}}}

/* k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2031(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_2031,c,av);}
a=C_alloc(9);
t2=(C_truep(((C_word*)t0)[2])?stub516(C_SCHEME_UNDEFINED,((C_word*)t0)[2],t1):stub516(C_SCHEME_UNDEFINED,((C_word*)t0)[3],t1));
t3=C_eqp(C_fix(-1),t2);
if(C_truep(t3)){
/* scheduler.scm:476: ##sys#force-primordial */
t4=*((C_word*)lf[19]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_fixnum_greaterp(t2,C_fix(0)))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2055,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2057,a[2]=t6,a[3]=((C_word)li4),tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_2057(t8,t4,t2,C_fix(0),lf[6]);}
else{
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_1007(2,av2);}}}}

/* k2053 in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2055(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2055,c,av);}
t2=C_mutate(&lf[6] /* (set! fd-list ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_1007(2,av2);}}

/* loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_fcall f_2057(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(33,0,4)))){
C_save_and_reclaim_args((void *)trf_2057,5,t0,t1,t2,t3,t4);}
a=C_alloc(33);
t5=C_i_zerop(t2);
t6=(C_truep(t5)?t5:C_i_nullp(t4));
if(C_truep(t6)){
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t7=C_u_i_car(t4);
t8=C_u_i_car(t7);
t9=C_fd_input_ready(t8,t3);
t10=C_fd_output_ready(t8,t3);
t11=(C_truep(t9)?t9:t10);
if(C_truep(t11)){
t12=C_u_i_cdr(t7);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_set_block_item(t14,0,(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_2084,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=t4,a[6]=t8,a[7]=t14,a[8]=t9,a[9]=t10,a[10]=((C_word)li3),tmp=(C_word)a,a+=11,tmp));
t16=((C_word*)t14)[1];
f_2084(t16,t1,t12,C_SCHEME_END_OF_LIST);}
else{
t12=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2253,a[2]=t1,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
t13=C_s_a_i_plus(&a,2,t3,C_fix(1));
/* scheduler.scm:517: loop */
t17=t12;
t18=t2;
t19=t13;
t20=C_u_i_cdr(t4);
t1=t17;
t2=t18;
t3=t19;
t4=t20;
goto loop;}}}

/* loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_fcall f_2084(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_word t17;
C_word t18;
C_word t19;
C_word t20;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(65,0,4)))){
C_save_and_reclaim_args((void *)trf_2084,4,t0,t1,t2,t3);}
a=C_alloc(65);
if(C_truep(C_i_nullp(t2))){
if(C_truep(C_i_nullp(t3))){
t4=C_s_a_i_minus(&a,2,((C_word*)t0)[2],C_fix(1));
t5=C_s_a_i_plus(&a,2,((C_word*)t0)[3],C_fix(1));
/* scheduler.scm:493: loop */
t6=((C_word*)((C_word*)t0)[4])[1];
f_2057(t6,t1,t4,t5,C_u_i_cdr(((C_word*)t0)[5]));}
else{
t4=C_a_i_cons(&a,2,((C_word*)t0)[6],t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2119,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=C_s_a_i_minus(&a,2,((C_word*)t0)[2],C_fix(1));
t7=C_s_a_i_plus(&a,2,((C_word*)t0)[3],C_fix(1));
/* scheduler.scm:495: loop */
t8=((C_word*)((C_word*)t0)[4])[1];
f_2057(t8,t5,t6,t7,C_u_i_cdr(((C_word*)t0)[5]));}}
else{
t4=C_u_i_car(t2);
t5=C_slot(t4,C_fix(11));
if(C_truep(C_slot(t4,C_fix(13)))){
/* scheduler.scm:501: loop2 */
t18=t1;
t19=C_u_i_cdr(t2);
t20=t3;
t1=t18;
t2=t19;
t3=t20;
goto loop;}
else{
t6=C_i_pairp(t5);
if(C_truep(C_i_not(t6))){
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2153,a[2]=((C_word*)t0)[7],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_slot(t4,C_fix(4)))){
/* scheduler.scm:506: ##sys#remove-from-timeout-list */
t8=*((C_word*)lf[21]+1);{
C_word av2[3];
av2[0]=t8;
av2[1]=t7;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
t8=t7;{
C_word av2[2];
av2[0]=t8;
av2[1]=C_SCHEME_UNDEFINED;
f_2153(2,av2);}}}
else{
t7=C_u_i_car(t5);
t8=C_eqp(((C_word*)t0)[6],t7);
if(C_truep(C_i_not(t8))){
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2177,a[2]=t1,a[3]=((C_word*)t0)[6],a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:510: chicken.base#open-output-string */
t10=*((C_word*)lf[28]+1);{
C_word av2[2];
av2[0]=t10;
av2[1]=t9;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t9=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2206,a[2]=((C_word*)t0)[7],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
t10=C_u_i_cdr(t5);
t11=C_eqp(t10,C_SCHEME_TRUE);
t12=(C_truep(t11)?t11:C_eqp(t10,lf[29]));
if(C_truep(t12)){
t13=t9;
f_2206(t13,((C_word*)t0)[8]);}
else{
t13=C_eqp(t10,C_SCHEME_FALSE);
t14=(C_truep(t13)?t13:C_eqp(t10,lf[30]));
if(C_truep(t14)){
t15=t9;
f_2206(t15,((C_word*)t0)[9]);}
else{
t15=C_eqp(t10,lf[31]);
if(C_truep(t15)){
t16=t9;
f_2206(t16,(C_truep(((C_word*)t0)[8])?((C_word*)t0)[8]:((C_word*)t0)[9]));}
else{
t16=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1910,a[2]=t9,a[3]=((C_word*)t0)[9],a[4]=((C_word*)t0)[8],a[5]=t10,tmp=(C_word)a,a+=6,tmp);
/* scheduler.scm:441: chicken.base#open-output-string */
t17=*((C_word*)lf[28]+1);{
C_word av2[2];
av2[0]=t17;
av2[1]=t16;
((C_proc)(void*)(*((C_word*)t17+1)))(2,av2);}}}}}}}}}

/* k2117 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2119(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2119,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2151 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2153(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2153,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2156,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* scheduler.scm:507: ##sys#thread-basic-unblock! */
t3=*((C_word*)lf[20]+1);{
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

/* k2154 in k2151 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2156(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2156,c,av);}
/* scheduler.scm:508: loop2 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2084(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]),((C_word*)t0)[5]);}

/* k2175 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2177(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_2177,c,av);}
a=C_alloc(6);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[22]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2183,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* scheduler.scm:510: ##sys#print */
t4=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[27];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k2181 in k2175 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2183(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_2183,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2186,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:510: ##sys#print */
t3=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_u_i_car(((C_word*)t0)[5]);
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k2184 in k2181 in k2175 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2186(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_2186,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2189,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:510: ##sys#print */
t3=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[26];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k2187 in k2184 in k2181 in k2175 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2189(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_2189,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2192,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:510: ##sys#print */
t3=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k2190 in k2187 in k2184 in k2181 in k2175 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2192(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2192,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2195,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:510: ##sys#write-char-0 */
t3=*((C_word*)lf[24]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(41);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2193 in k2190 in k2187 in k2184 in k2181 in k2175 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2195(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2195,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2198,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* scheduler.scm:510: chicken.base#get-output-string */
t3=*((C_word*)lf[23]+1);{
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

/* k2196 in k2193 in k2190 in k2187 in k2184 in k2181 in k2175 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2198(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2198,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_halt(t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2204 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_fcall f_2206(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_2206,2,t0,t1);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2209,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_slot(((C_word*)t0)[6],C_fix(4)))){
/* scheduler.scm:513: ##sys#remove-from-timeout-list */
t3=*((C_word*)lf[21]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_2209(2,av2);}}}
else{
t2=C_u_i_cdr(((C_word*)t0)[4]);
t3=C_a_i_cons(&a,2,((C_word*)t0)[6],((C_word*)t0)[5]);
/* scheduler.scm:516: loop2 */
t4=((C_word*)((C_word*)t0)[2])[1];
f_2084(t4,((C_word*)t0)[3],t2,t3);}}

/* k2207 in k2204 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2209(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2209,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2212,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* scheduler.scm:514: ##sys#thread-basic-unblock! */
t3=*((C_word*)lf[20]+1);{
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

/* k2210 in k2207 in k2204 in loop2 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2212(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2212,c,av);}
/* scheduler.scm:515: loop2 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2084(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]),((C_word*)t0)[5]);}

/* k2251 in loop in k2029 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2253(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2253,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2271 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2273(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(36,c,3)))){
C_save_and_reclaim((void *)f_2273,c,av);}
a=C_alloc(36);
t2=C_a_i_current_process_milliseconds(&a,1,C_SCHEME_FALSE);
t3=C_s_a_i_minus(&a,2,t1,t2);
/* scheduler.scm:468: scheme#max */
t4=*((C_word*)lf[35]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(0);
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2282 in k2020 in k1002 in loop1 in k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_2284(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2284,c,av);}
/* scheduler.scm:466: scheme#inexact->exact */
t2=*((C_word*)lf[36]+1);{
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

/* ##sys#clear-i/o-state-for-thread! in k917 in k914 */
static void C_fcall f_2289(C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,0,3)))){
C_save_and_reclaim_args((void *)trf_2289,2,t1,t2);}
a=C_alloc(11);
t3=C_slot(t2,C_fix(11));
if(C_truep(C_i_pairp(t3))){
t4=C_slot(t2,C_fix(11));
t5=C_u_i_car(t4);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2303,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2305,a[2]=t5,a[3]=t2,a[4]=t8,a[5]=((C_word)li34),tmp=(C_word)a,a+=6,tmp));
t10=((C_word*)t8)[1];
f_2305(t10,t6,lf[6]);}
else{
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k2301 in ##sys#clear-i/o-state-for-thread! in k917 in k914 */
static void C_ccall f_2303(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2303,c,av);}
t2=C_mutate(&lf[6] /* (set! fd-list ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* loop in ##sys#clear-i/o-state-for-thread! in k917 in k914 */
static void C_fcall f_2305(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_2305,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_u_i_car(t2);
t4=C_u_i_car(t3);
t5=C_eqp(((C_word*)t0)[2],t4);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2327,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:532: delq */
f_921(t6,((C_word*)t0)[3],C_u_i_cdr(t3));}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2346,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:537: loop */
t8=t6;
t9=C_u_i_cdr(t2);
t1=t8;
t2=t9;
goto loop;}}}

/* k2325 in loop in ##sys#clear-i/o-state-for-thread! in k917 in k914 */
static void C_ccall f_2327(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2327,c,av);}
if(C_truep(C_i_nullp(t1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_u_i_cdr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_i_setslot(((C_word*)t0)[4],C_fix(1),t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k2344 in loop in ##sys#clear-i/o-state-for-thread! in k917 in k914 */
static void C_ccall f_2346(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2346,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#all-threads in k917 in k914 */
static void C_ccall f_2358(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,6)))){
C_save_and_reclaim((void *)f_2358,c,av);}
a=C_alloc(10);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2493,a[2]=((C_word)li36),tmp=(C_word)a,a+=3,tmp):C_get_rest_arg(c,2,av,2,t0));
t4=C_rest_nullp(c,2);
t5=C_rest_nullp(c,3);
t6=(C_truep(t5)?C_SCHEME_END_OF_LIST:C_get_rest_arg(c,3,av,2,t0));
t7=C_rest_nullp(c,3);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2376,a[2]=t9,a[3]=t3,a[4]=((C_word)li40),tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_2376(t11,t1,lf[17],t6);}

/* loop in ##sys#all-threads in k917 in k914 */
static void C_fcall f_2376(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,5)))){
C_save_and_reclaim_args((void *)trf_2376,4,t0,t1,t2,t3);}
a=C_alloc(7);
if(C_truep(C_i_pairp(t2))){
t4=C_u_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2392,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* scheduler.scm:550: cns */
t6=((C_word*)t0)[3];{
C_word av2[6];
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[8];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_u_i_car(t2);
av2[5]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(6,av2);}}
else{
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2399,a[2]=t5,a[3]=((C_word*)t0)[3],a[4]=((C_word)li39),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_2399(t7,t1,lf[6],t3);}}

/* k2390 in loop in ##sys#all-threads in k917 in k914 */
static void C_ccall f_2392(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2392,c,av);}
/* scheduler.scm:550: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2376(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* loop in loop in ##sys#all-threads in k917 in k914 */
static void C_fcall f_2399(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,0,4)))){
C_save_and_reclaim_args((void *)trf_2399,4,t0,t1,t2,t3);}
a=C_alloc(14);
if(C_truep(C_i_pairp(t2))){
t4=C_u_i_cdr(t2);
t5=C_u_i_caar(t2);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2418,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t7=C_u_i_car(t2);
t8=C_u_i_cdr(t7);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2423,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=t5,a[5]=t10,a[6]=((C_word)li37),tmp=(C_word)a,a+=7,tmp));
t12=((C_word*)t10)[1];
f_2423(t12,t6,t8);}
else{
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2448,a[2]=t5,a[3]=((C_word*)t0)[3],a[4]=((C_word)li38),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_2448(t7,t1,lf[5],t3);}}

/* k2416 in loop in loop in ##sys#all-threads in k917 in k914 */
static void C_ccall f_2418(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2418,c,av);}
/* scheduler.scm:553: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2399(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* loop in loop in loop in ##sys#all-threads in k917 in k914 */
static void C_fcall f_2423(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_2423,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_u_i_car(t2);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2441,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* scheduler.scm:557: loop */
t6=t4;
t7=C_u_i_cdr(t2);
t1=t6;
t2=t7;
goto loop;}}

/* k2439 in loop in loop in loop in ##sys#all-threads in k917 in k914 */
static void C_ccall f_2441(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2441,c,av);}
/* scheduler.scm:557: cns */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[63];
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* loop in loop in loop in ##sys#all-threads in k917 in k914 */
static void C_fcall f_2448(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,5)))){
C_save_and_reclaim_args((void *)trf_2448,4,t0,t1,t2,t3);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t4=C_u_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2464,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=C_u_i_caar(t2);
t7=C_u_i_car(t2);
/* scheduler.scm:560: cns */
t8=((C_word*)t0)[3];{
C_word av2[6];
av2[0]=t8;
av2[1]=t5;
av2[2]=lf[64];
av2[3]=t6;
av2[4]=C_u_i_cdr(t7);
av2[5]=t3;
((C_proc)(void*)(*((C_word*)t8+1)))(6,av2);}}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k2462 in loop in loop in loop in ##sys#all-threads in k917 in k914 */
static void C_ccall f_2464(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2464,c,av);}
/* scheduler.scm:560: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2448(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* f_2493 in ##sys#all-threads in k917 in k914 */
static void C_ccall f_2493(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2493,c,av);}
a=C_alloc(3);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_cons(&a,2,t4,t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* ##sys#fetch-and-clear-threads in k917 in k914 */
static void C_ccall f_2502(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_2502,c,av);}
a=C_alloc(5);
t2=C_a_i_vector4(&a,4,lf[17],lf[18],lf[6],lf[5]);
t3=lf[17] /* ready-queue-head */ =C_SCHEME_END_OF_LIST;;
t4=lf[18] /* ready-queue-tail */ =C_SCHEME_END_OF_LIST;;
t5=lf[6] /* fd-list */ =C_SCHEME_END_OF_LIST;;
t6=lf[5] /* timeout-list */ =C_SCHEME_END_OF_LIST;;
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* ##sys#restore-threads in k917 in k914 */
static void C_ccall f_2512(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2512,c,av);}
t3=C_slot(t2,C_fix(0));
t4=C_mutate(&lf[17] /* (set! ready-queue-head ...) */,t3);
t5=C_slot(t2,C_fix(1));
t6=C_mutate(&lf[18] /* (set! ready-queue-tail ...) */,t5);
t7=C_slot(t2,C_fix(2));
t8=C_mutate(&lf[6] /* (set! fd-list ...) */,t7);
t9=C_slot(t2,C_fix(3));
t10=C_mutate(&lf[5] /* (set! timeout-list ...) */,t9);
t11=t1;{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}

/* ##sys#thread-unblock! in k917 in k914 */
static void C_ccall f_2531(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2531,c,av);}
a=C_alloc(4);
t3=C_slot(t2,C_fix(3));
t4=C_eqp(lf[49],t3);
t5=(C_truep(t4)?t4:C_eqp(lf[67],C_slot(t2,C_fix(3))));
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2544,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:589: ##sys#remove-from-timeout-list */
t7=*((C_word*)lf[21]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t6=C_SCHEME_UNDEFINED;
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k2542 in ##sys#thread-unblock! in k917 in k914 */
static void C_ccall f_2544(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2544,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2547,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:590: ##sys#clear-i/o-state-for-thread! */
f_2289(t2,((C_word*)t0)[3]);}

/* k2545 in k2542 in ##sys#thread-unblock! in k917 in k914 */
static void C_ccall f_2547(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2547,c,av);}
/* scheduler.scm:591: ##sys#thread-basic-unblock! */
t2=*((C_word*)lf[20]+1);{
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

/* ##sys#thread-sleep! in k917 in k914 */
static void C_ccall f_2563(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2563,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2569,a[2]=t2,a[3]=((C_word)li46),tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:597: ##sys#call-with-current-continuation */{
C_word *av2=av;
av2[0]=0;
av2[1]=t1;
av2[2]=t3;
C_call_cc(3,av2);}}

/* a2568 in ##sys#thread-sleep! in k917 in k914 */
static void C_ccall f_2569(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_2569,c,av);}
a=C_alloc(7);
t3=*((C_word*)lf[3]+1);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2581,a[2]=t2,a[3]=((C_word)li45),tmp=(C_word)a,a+=4,tmp);
t5=C_i_setslot(*((C_word*)lf[3]+1),C_fix(1),t4);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2576,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* scheduler.scm:601: ##sys#thread-block-for-timeout! */
t7=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=*((C_word*)lf[3]+1);
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}

/* k2574 in a2568 in ##sys#thread-sleep! in k917 in k914 */
static void C_ccall f_2576(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2576,c,av);}
/* scheduler.scm:602: ##sys#schedule */
t2=*((C_word*)lf[2]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a2580 in a2568 in ##sys#thread-sleep! in k917 in k914 */
static void C_ccall f_2581(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2581,c,av);}
/* scheduler.scm:600: return */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* chicken.base#sleep-hook in k917 in k914 */
static void C_ccall f_2587(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(69,c,2)))){
C_save_and_reclaim((void *)f_2587,c,av);}
a=C_alloc(69);
t3=C_s_a_i_times(&a,2,lf[70],t2);
t4=C_s_a_i_plus(&a,2,C_a_i_current_process_milliseconds(&a,1,C_SCHEME_FALSE),t3);
/* scheduler.scm:609: ##sys#thread-sleep! */
t5=*((C_word*)lf[68]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* ##sys#kill-other-threads in k917 in k914 */
static void C_ccall f_2601(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(31,c,2)))){
C_save_and_reclaim((void *)f_2601,c,av);}
a=C_alloc(31);
t3=*((C_word*)lf[3]+1);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2604,a[2]=t3,a[3]=((C_word)li49),tmp=(C_word)a,a+=4,tmp);
t5=C_mutate((C_word*)lf[43]+1 /* (set! ##sys#primordial-thread ...) */,*((C_word*)lf[3]+1));
t6=C_a_i_list1(&a,1,*((C_word*)lf[3]+1));
t7=C_mutate(&lf[17] /* (set! ready-queue-head ...) */,t6);
t8=C_mutate(&lf[18] /* (set! ready-queue-tail ...) */,lf[17]);
t9=(
/* scheduler.scm:629: suspend */
  f_2604(t4,*((C_word*)lf[3]+1))
);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2630,a[2]=t4,a[3]=((C_word)li50),tmp=(C_word)a,a+=4,tmp);
t11=lf[5];
t12=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2708,a[2]=t10,a[3]=((C_word)li51),tmp=(C_word)a,a+=4,tmp);
t13=(
  f_2708(t12,lf[5])
);
t14=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2651,a[2]=t4,a[3]=((C_word)li52),tmp=(C_word)a,a+=4,tmp);
t15=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2642,a[2]=t14,a[3]=((C_word)li53),tmp=(C_word)a,a+=4,tmp);
t16=lf[6];
t17=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2685,a[2]=t15,a[3]=((C_word)li54),tmp=(C_word)a,a+=4,tmp);
t18=(
  f_2685(t17,lf[6])
);
t19=lf[5] /* timeout-list */ =C_SCHEME_END_OF_LIST;;
t20=lf[6] /* fd-list */ =C_SCHEME_END_OF_LIST;;
t21=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2680,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:634: thunk */
t22=t2;{
C_word *av2=av;
av2[0]=t22;
av2[1]=t21;
((C_proc)(void*)(*((C_word*)t22+1)))(2,av2);}}

/* suspend in ##sys#kill-other-threads in k917 in k914 */
static C_word C_fcall f_2604(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;{}
t2=C_eqp(t1,((C_word*)t0)[2]);
t3=(C_truep(t2)?C_SCHEME_UNDEFINED:C_i_setslot(t1,C_fix(3),lf[73]));
t4=C_i_set_i_slot(t1,C_fix(11),C_SCHEME_FALSE);
return(C_i_set_i_slot(t1,C_fix(12),C_SCHEME_END_OF_LIST));}

/* g653 in ##sys#kill-other-threads in k917 in k914 */
static C_word C_fcall f_2630(C_word t0,C_word t1){
C_word tmp;
C_word t2;{}
return((
/* scheduler.scm:630: suspend */
  f_2604(((C_word*)t0)[2],C_u_i_cdr(t1))
));}

/* g663 in ##sys#kill-other-threads in k917 in k914 */
static C_word C_fcall f_2642(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;{}
t2=C_u_i_cdr(t1);
return((
  f_2651(((C_word*)t0)[2],t2)
));}

/* for-each-loop685 in ##sys#kill-other-threads in k917 in k914 */
static C_word C_fcall f_2651(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
loop:{}
if(C_truep(C_i_pairp(t1))){
t2=(
/* scheduler.scm:631: g686 */
  f_2604(((C_word*)t0)[2],C_slot(t1,C_fix(0)))
);
t4=C_slot(t1,C_fix(1));
t1=t4;
goto loop;}
else{
t2=C_SCHEME_UNDEFINED;
return(t2);}}

/* k2678 in ##sys#kill-other-threads in k917 in k914 */
static void C_ccall f_2680(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2680,c,av);}
/* scheduler.scm:635: exit */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* for-each-loop662 in ##sys#kill-other-threads in k917 in k914 */
static C_word C_fcall f_2685(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
loop:{}
if(C_truep(C_i_pairp(t1))){
t2=(
/* scheduler.scm:631: g663 */
  f_2642(((C_word*)t0)[2],C_slot(t1,C_fix(0)))
);
t4=C_slot(t1,C_fix(1));
t1=t4;
goto loop;}
else{
t2=C_SCHEME_UNDEFINED;
return(t2);}}

/* for-each-loop652 in ##sys#kill-other-threads in k917 in k914 */
static C_word C_fcall f_2708(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
loop:{}
if(C_truep(C_i_pairp(t1))){
t2=(
/* scheduler.scm:630: g653 */
  f_2630(((C_word*)t0)[2],C_slot(t1,C_fix(0)))
);
t4=C_slot(t1,C_fix(1));
t1=t4;
goto loop;}
else{
t2=C_SCHEME_UNDEFINED;
return(t2);}}

/* k914 */
static void C_ccall f_916(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_916,c,av);}
a=C_alloc(11);
t2=C_a_i_provide(&a,1,lf[0]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_919,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t3;
C_library_toplevel(2,av2);}}

/* k917 in k914 */
static void C_ccall f_919(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(74,c,5)))){
C_save_and_reclaim((void *)f_919,c,av);}
a=C_alloc(74);
t2=C_mutate(&lf[1] /* (set! delq ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_921,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t3=C_mutate((C_word*)lf[2]+1 /* (set! ##sys#schedule ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_964,a[2]=((C_word)li10),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[19]+1 /* (set! ##sys#force-primordial ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1185,a[2]=((C_word)li11),tmp=(C_word)a,a+=3,tmp));
t5=lf[17] /* ready-queue-head */ =C_SCHEME_END_OF_LIST;;
t6=lf[18] /* ready-queue-tail */ =C_SCHEME_END_OF_LIST;;
t7=C_mutate((C_word*)lf[45]+1 /* (set! ##sys#ready-queue ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1196,a[2]=((C_word)li12),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[42]+1 /* (set! ##sys#add-to-ready-queue ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1199,a[2]=((C_word)li13),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate(&lf[4] /* (set! ##sys#update-thread-state-buffer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1244,a[2]=((C_word)li14),tmp=(C_word)a,a+=3,tmp));
t10=*((C_word*)lf[46]+1);
t11=C_mutate((C_word*)lf[46]+1 /* (set! ##sys#interrupt-hook ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1298,a[2]=t10,a[3]=((C_word)li16),tmp=(C_word)a,a+=4,tmp));
t12=lf[5] /* timeout-list */ =C_SCHEME_END_OF_LIST;;
t13=C_mutate((C_word*)lf[47]+1 /* (set! ##sys#timeout-queue ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1323,a[2]=((C_word)li17),tmp=(C_word)a,a+=3,tmp));
t14=C_mutate((C_word*)lf[21]+1 /* (set! ##sys#remove-from-timeout-list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1326,a[2]=((C_word)li19),tmp=(C_word)a,a+=3,tmp));
t15=C_mutate((C_word*)lf[48]+1 /* (set! ##sys#thread-block-for-timeout! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1367,a[2]=((C_word)li21),tmp=(C_word)a,a+=3,tmp));
t16=C_mutate((C_word*)lf[50]+1 /* (set! ##sys#thread-block-for-termination! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1436,a[2]=((C_word)li22),tmp=(C_word)a,a+=3,tmp));
t17=C_mutate((C_word*)lf[53]+1 /* (set! ##sys#thread-kill! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1566,a[2]=((C_word)li27),tmp=(C_word)a,a+=3,tmp));
t18=C_mutate((C_word*)lf[20]+1 /* (set! ##sys#thread-basic-unblock! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1680,a[2]=((C_word)li28),tmp=(C_word)a,a+=3,tmp));
t19=C_mutate((C_word*)lf[56]+1 /* (set! ##sys#default-exception-handler ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1692,a[2]=((C_word)li30),tmp=(C_word)a,a+=3,tmp));
t20=lf[6] /* fd-list */ =C_SCHEME_END_OF_LIST;;
t21=C_mutate((C_word*)lf[60]+1 /* (set! ##sys#fd-queue ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1729,a[2]=((C_word)li31),tmp=(C_word)a,a+=3,tmp));
t22=C_mutate((C_word*)lf[61]+1 /* (set! ##sys#thread-block-for-i/o! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1955,a[2]=((C_word)li33),tmp=(C_word)a,a+=3,tmp));
t23=C_mutate(&lf[41] /* (set! ##sys#clear-i/o-state-for-thread! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2289,a[2]=((C_word)li35),tmp=(C_word)a,a+=3,tmp));
t24=C_mutate((C_word*)lf[62]+1 /* (set! ##sys#all-threads ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2358,a[2]=((C_word)li41),tmp=(C_word)a,a+=3,tmp));
t25=C_mutate((C_word*)lf[65]+1 /* (set! ##sys#fetch-and-clear-threads ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2502,a[2]=((C_word)li42),tmp=(C_word)a,a+=3,tmp));
t26=C_mutate((C_word*)lf[66]+1 /* (set! ##sys#restore-threads ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2512,a[2]=((C_word)li43),tmp=(C_word)a,a+=3,tmp));
t27=C_mutate((C_word*)lf[44]+1 /* (set! ##sys#thread-unblock! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2531,a[2]=((C_word)li44),tmp=(C_word)a,a+=3,tmp));
t28=C_mutate((C_word*)lf[68]+1 /* (set! ##sys#thread-sleep! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2563,a[2]=((C_word)li47),tmp=(C_word)a,a+=3,tmp));
t29=C_mutate((C_word*)lf[69]+1 /* (set! chicken.base#sleep-hook ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2587,a[2]=((C_word)li48),tmp=(C_word)a,a+=3,tmp));
t30=*((C_word*)lf[71]+1);
t31=C_mutate((C_word*)lf[72]+1 /* (set! ##sys#kill-other-threads ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2601,a[2]=t30,a[3]=((C_word)li55),tmp=(C_word)a,a+=4,tmp));
t32=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t32;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t32+1)))(2,av2);}}

/* delq in k917 in k914 */
static void C_fcall f_921(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_921,3,t1,t2,t3);}
a=C_alloc(7);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_927,a[2]=t2,a[3]=t5,a[4]=((C_word)li0),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_927(t7,t1,t3);}

/* loop in delq in k917 in k914 */
static void C_fcall f_927(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_927,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_slot(t2,C_fix(0));
t4=C_eqp(((C_word*)t0)[2],t3);
if(C_truep(t4)){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_slot(t2,C_fix(0));
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_954,a[2]=t1,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* scheduler.scm:162: loop */
t8=t6;
t9=C_slot(t2,C_fix(1));
t1=t8;
t2=t9;
goto loop;}}}

/* k952 in loop in delq in k917 in k914 */
static void C_ccall f_954(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_954,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#schedule in k917 in k914 */
static void C_ccall f_964(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_964,c,av);}
a=C_alloc(7);
t2=*((C_word*)lf[3]+1);
t3=C_SCHEME_FALSE;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_slot(*((C_word*)lf[3]+1),C_fix(3));
t6=(
/* scheduler.scm:180: ##sys#update-thread-state-buffer */
  f_1244(*((C_word*)lf[3]+1))
);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_995,a[2]=t4,a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t8=C_eqp(t5,lf[9]);
t9=(C_truep(t8)?t8:C_eqp(t5,lf[8]));
if(C_truep(t9)){
t10=C_i_set_i_slot(*((C_word*)lf[3]+1),C_fix(13),C_SCHEME_FALSE);
/* scheduler.scm:184: ##sys#add-to-ready-queue */
t11=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t11;
av2[1]=t7;
av2[2]=*((C_word*)lf[3]+1);
((C_proc)(void*)(*((C_word*)t11+1)))(3,av2);}}
else{
t10=t7;{
C_word *av2=av;
av2[0]=t10;
av2[1]=C_SCHEME_UNDEFINED;
f_995(2,av2);}}}

/* k993 in ##sys#schedule in k917 in k914 */
static void C_ccall f_995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_995,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1000,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word)li9),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_1000(t5,((C_word*)t0)[4]);}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_scheduler_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("scheduler"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_scheduler_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(403))){
C_save(t1);
C_rereclaim2(403*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,74);
lf[0]=C_h_intern(&lf[0],9, C_text("scheduler"));
lf[2]=C_h_intern(&lf[2],14, C_text("##sys#schedule"));
lf[3]=C_h_intern(&lf[3],20, C_text("##sys#current-thread"));
lf[7]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010deadlock"));
lf[8]=C_h_intern(&lf[8],5, C_text("ready"));
lf[9]=C_h_intern(&lf[9],7, C_text("running"));
lf[10]=C_h_intern(&lf[10],19, C_text("##sys#dynamic-winds"));
lf[11]=C_h_intern(&lf[11],20, C_text("##sys#standard-input"));
lf[12]=C_h_intern(&lf[12],21, C_text("##sys#standard-output"));
lf[13]=C_h_intern(&lf[13],20, C_text("##sys#standard-error"));
lf[14]=C_h_intern(&lf[14],31, C_text("##sys#current-exception-handler"));
lf[15]=C_h_intern(&lf[15],30, C_text("##sys#current-parameter-vector"));
lf[16]=C_h_intern(&lf[16],23, C_text("##sys#call-with-cthulhu"));
lf[19]=C_h_intern(&lf[19],22, C_text("##sys#force-primordial"));
lf[20]=C_h_intern(&lf[20],27, C_text("##sys#thread-basic-unblock!"));
lf[21]=C_h_intern(&lf[21],30, C_text("##sys#remove-from-timeout-list"));
lf[22]=C_h_intern(&lf[22],6, C_text("format"));
lf[23]=C_h_intern(&lf[23],30, C_text("chicken.base#get-output-string"));
lf[24]=C_h_intern(&lf[24],18, C_text("##sys#write-char-0"));
lf[25]=C_h_intern(&lf[25],11, C_text("##sys#print"));
lf[26]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013 (expected "));
lf[27]=C_decode_literal(C_heaptop,C_text("\376B\000\0009thread is registered for I/O on unknown file-descriptor: "));
lf[28]=C_h_intern(&lf[28],31, C_text("chicken.base#open-output-string"));
lf[29]=C_h_intern_kw(&lf[29],5, C_text("input"));
lf[30]=C_h_intern_kw(&lf[30],6, C_text("output"));
lf[31]=C_h_intern_kw(&lf[31],3, C_text("all"));
lf[32]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006, o = "));
lf[33]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006 (i = "));
lf[34]=C_decode_literal(C_heaptop,C_text("\376B\000\000#fdset-test: invalid i/o direction: "));
lf[35]=C_h_intern(&lf[35],10, C_text("scheme#max"));
lf[36]=C_h_intern(&lf[36],21, C_text("scheme#inexact->exact"));
lf[37]=C_h_intern(&lf[37],12, C_text("scheme#round"));
lf[38]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007 (fd = "));
lf[39]=C_decode_literal(C_heaptop,C_text("\376B\000\000%create-fdset: invalid i/o direction: "));
lf[40]=C_h_intern(&lf[40],12, C_text("##sys#length"));
lf[42]=C_h_intern(&lf[42],24, C_text("##sys#add-to-ready-queue"));
lf[43]=C_h_intern(&lf[43],23, C_text("##sys#primordial-thread"));
lf[44]=C_h_intern(&lf[44],21, C_text("##sys#thread-unblock!"));
lf[45]=C_h_intern(&lf[45],17, C_text("##sys#ready-queue"));
lf[46]=C_h_intern(&lf[46],20, C_text("##sys#interrupt-hook"));
lf[47]=C_h_intern(&lf[47],19, C_text("##sys#timeout-queue"));
lf[48]=C_h_intern(&lf[48],31, C_text("##sys#thread-block-for-timeout!"));
lf[49]=C_h_intern(&lf[49],7, C_text("blocked"));
lf[50]=C_h_intern(&lf[50],35, C_text("##sys#thread-block-for-termination!"));
lf[51]=C_h_intern(&lf[51],4, C_text("dead"));
lf[52]=C_h_intern(&lf[52],10, C_text("terminated"));
lf[53]=C_h_intern(&lf[53],18, C_text("##sys#thread-kill!"));
lf[54]=C_h_intern(&lf[54],18, C_text("condition-variable"));
lf[55]=C_h_intern(&lf[55],6, C_text("thread"));
lf[56]=C_h_intern(&lf[56],31, C_text("##sys#default-exception-handler"));
lf[57]=C_h_intern(&lf[57],24, C_text("chicken.condition#signal"));
lf[58]=C_h_intern(&lf[58],28, C_text("##sys#show-exception-warning"));
lf[59]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011in thread"));
lf[60]=C_h_intern(&lf[60],14, C_text("##sys#fd-queue"));
lf[61]=C_h_intern(&lf[61],27, C_text("##sys#thread-block-for-i/o!"));
lf[62]=C_h_intern(&lf[62],17, C_text("##sys#all-threads"));
lf[63]=C_h_intern(&lf[63],3, C_text("i/o"));
lf[64]=C_h_intern(&lf[64],7, C_text("timeout"));
lf[65]=C_h_intern(&lf[65],29, C_text("##sys#fetch-and-clear-threads"));
lf[66]=C_h_intern(&lf[66],21, C_text("##sys#restore-threads"));
lf[67]=C_h_intern(&lf[67],8, C_text("sleeping"));
lf[68]=C_h_intern(&lf[68],19, C_text("##sys#thread-sleep!"));
lf[69]=C_h_intern(&lf[69],23, C_text("chicken.base#sleep-hook"));
lf[70]=C_decode_literal(C_heaptop,C_text("\376U1000.0\000"));
lf[71]=C_h_intern(&lf[71],17, C_text("chicken.base#exit"));
lf[72]=C_h_intern(&lf[72],24, C_text("##sys#kill-other-threads"));
lf[73]=C_h_intern(&lf[73],9, C_text("suspended"));
C_register_lf2(lf,74,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_916,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[136] = {
{C_text("f_1000:scheduler_2escm"),(void*)f_1000},
{C_text("f_1004:scheduler_2escm"),(void*)f_1004},
{C_text("f_1007:scheduler_2escm"),(void*)f_1007},
{C_text("f_1012:scheduler_2escm"),(void*)f_1012},
{C_text("f_1016:scheduler_2escm"),(void*)f_1016},
{C_text("f_1076:scheduler_2escm"),(void*)f_1076},
{C_text("f_1110:scheduler_2escm"),(void*)f_1110},
{C_text("f_1113:scheduler_2escm"),(void*)f_1113},
{C_text("f_1125:scheduler_2escm"),(void*)f_1125},
{C_text("f_1131:scheduler_2escm"),(void*)f_1131},
{C_text("f_1143:scheduler_2escm"),(void*)f_1143},
{C_text("f_1151:scheduler_2escm"),(void*)f_1151},
{C_text("f_1185:scheduler_2escm"),(void*)f_1185},
{C_text("f_1196:scheduler_2escm"),(void*)f_1196},
{C_text("f_1199:scheduler_2escm"),(void*)f_1199},
{C_text("f_1244:scheduler_2escm"),(void*)f_1244},
{C_text("f_1298:scheduler_2escm"),(void*)f_1298},
{C_text("f_1302:scheduler_2escm"),(void*)f_1302},
{C_text("f_1316:scheduler_2escm"),(void*)f_1316},
{C_text("f_1323:scheduler_2escm"),(void*)f_1323},
{C_text("f_1326:scheduler_2escm"),(void*)f_1326},
{C_text("f_1332:scheduler_2escm"),(void*)f_1332},
{C_text("f_1367:scheduler_2escm"),(void*)f_1367},
{C_text("f_1377:scheduler_2escm"),(void*)f_1377},
{C_text("f_1388:scheduler_2escm"),(void*)f_1388},
{C_text("f_1436:scheduler_2escm"),(void*)f_1436},
{C_text("f_1501:scheduler_2escm"),(void*)f_1501},
{C_text("f_1517:scheduler_2escm"),(void*)f_1517},
{C_text("f_1527:scheduler_2escm"),(void*)f_1527},
{C_text("f_1543:scheduler_2escm"),(void*)f_1543},
{C_text("f_1566:scheduler_2escm"),(void*)f_1566},
{C_text("f_1570:scheduler_2escm"),(void*)f_1570},
{C_text("f_1576:scheduler_2escm"),(void*)f_1576},
{C_text("f_1579:scheduler_2escm"),(void*)f_1579},
{C_text("f_1582:scheduler_2escm"),(void*)f_1582},
{C_text("f_1600:scheduler_2escm"),(void*)f_1600},
{C_text("f_1607:scheduler_2escm"),(void*)f_1607},
{C_text("f_1626:scheduler_2escm"),(void*)f_1626},
{C_text("f_1636:scheduler_2escm"),(void*)f_1636},
{C_text("f_1657:scheduler_2escm"),(void*)f_1657},
{C_text("f_1674:scheduler_2escm"),(void*)f_1674},
{C_text("f_1680:scheduler_2escm"),(void*)f_1680},
{C_text("f_1692:scheduler_2escm"),(void*)f_1692},
{C_text("f_1696:scheduler_2escm"),(void*)f_1696},
{C_text("f_1702:scheduler_2escm"),(void*)f_1702},
{C_text("f_1716:scheduler_2escm"),(void*)f_1716},
{C_text("f_1720:scheduler_2escm"),(void*)f_1720},
{C_text("f_1729:scheduler_2escm"),(void*)f_1729},
{C_text("f_1743:scheduler_2escm"),(void*)f_1743},
{C_text("f_1754:scheduler_2escm"),(void*)f_1754},
{C_text("f_1797:scheduler_2escm"),(void*)f_1797},
{C_text("f_1803:scheduler_2escm"),(void*)f_1803},
{C_text("f_1806:scheduler_2escm"),(void*)f_1806},
{C_text("f_1809:scheduler_2escm"),(void*)f_1809},
{C_text("f_1812:scheduler_2escm"),(void*)f_1812},
{C_text("f_1815:scheduler_2escm"),(void*)f_1815},
{C_text("f_1818:scheduler_2escm"),(void*)f_1818},
{C_text("f_1839:scheduler_2escm"),(void*)f_1839},
{C_text("f_1851:scheduler_2escm"),(void*)f_1851},
{C_text("f_1861:scheduler_2escm"),(void*)f_1861},
{C_text("f_1876:scheduler_2escm"),(void*)f_1876},
{C_text("f_1910:scheduler_2escm"),(void*)f_1910},
{C_text("f_1916:scheduler_2escm"),(void*)f_1916},
{C_text("f_1919:scheduler_2escm"),(void*)f_1919},
{C_text("f_1922:scheduler_2escm"),(void*)f_1922},
{C_text("f_1925:scheduler_2escm"),(void*)f_1925},
{C_text("f_1928:scheduler_2escm"),(void*)f_1928},
{C_text("f_1931:scheduler_2escm"),(void*)f_1931},
{C_text("f_1934:scheduler_2escm"),(void*)f_1934},
{C_text("f_1937:scheduler_2escm"),(void*)f_1937},
{C_text("f_1955:scheduler_2escm"),(void*)f_1955},
{C_text("f_1959:scheduler_2escm"),(void*)f_1959},
{C_text("f_1974:scheduler_2escm"),(void*)f_1974},
{C_text("f_2022:scheduler_2escm"),(void*)f_2022},
{C_text("f_2031:scheduler_2escm"),(void*)f_2031},
{C_text("f_2055:scheduler_2escm"),(void*)f_2055},
{C_text("f_2057:scheduler_2escm"),(void*)f_2057},
{C_text("f_2084:scheduler_2escm"),(void*)f_2084},
{C_text("f_2119:scheduler_2escm"),(void*)f_2119},
{C_text("f_2153:scheduler_2escm"),(void*)f_2153},
{C_text("f_2156:scheduler_2escm"),(void*)f_2156},
{C_text("f_2177:scheduler_2escm"),(void*)f_2177},
{C_text("f_2183:scheduler_2escm"),(void*)f_2183},
{C_text("f_2186:scheduler_2escm"),(void*)f_2186},
{C_text("f_2189:scheduler_2escm"),(void*)f_2189},
{C_text("f_2192:scheduler_2escm"),(void*)f_2192},
{C_text("f_2195:scheduler_2escm"),(void*)f_2195},
{C_text("f_2198:scheduler_2escm"),(void*)f_2198},
{C_text("f_2206:scheduler_2escm"),(void*)f_2206},
{C_text("f_2209:scheduler_2escm"),(void*)f_2209},
{C_text("f_2212:scheduler_2escm"),(void*)f_2212},
{C_text("f_2253:scheduler_2escm"),(void*)f_2253},
{C_text("f_2273:scheduler_2escm"),(void*)f_2273},
{C_text("f_2284:scheduler_2escm"),(void*)f_2284},
{C_text("f_2289:scheduler_2escm"),(void*)f_2289},
{C_text("f_2303:scheduler_2escm"),(void*)f_2303},
{C_text("f_2305:scheduler_2escm"),(void*)f_2305},
{C_text("f_2327:scheduler_2escm"),(void*)f_2327},
{C_text("f_2346:scheduler_2escm"),(void*)f_2346},
{C_text("f_2358:scheduler_2escm"),(void*)f_2358},
{C_text("f_2376:scheduler_2escm"),(void*)f_2376},
{C_text("f_2392:scheduler_2escm"),(void*)f_2392},
{C_text("f_2399:scheduler_2escm"),(void*)f_2399},
{C_text("f_2418:scheduler_2escm"),(void*)f_2418},
{C_text("f_2423:scheduler_2escm"),(void*)f_2423},
{C_text("f_2441:scheduler_2escm"),(void*)f_2441},
{C_text("f_2448:scheduler_2escm"),(void*)f_2448},
{C_text("f_2464:scheduler_2escm"),(void*)f_2464},
{C_text("f_2493:scheduler_2escm"),(void*)f_2493},
{C_text("f_2502:scheduler_2escm"),(void*)f_2502},
{C_text("f_2512:scheduler_2escm"),(void*)f_2512},
{C_text("f_2531:scheduler_2escm"),(void*)f_2531},
{C_text("f_2544:scheduler_2escm"),(void*)f_2544},
{C_text("f_2547:scheduler_2escm"),(void*)f_2547},
{C_text("f_2563:scheduler_2escm"),(void*)f_2563},
{C_text("f_2569:scheduler_2escm"),(void*)f_2569},
{C_text("f_2576:scheduler_2escm"),(void*)f_2576},
{C_text("f_2581:scheduler_2escm"),(void*)f_2581},
{C_text("f_2587:scheduler_2escm"),(void*)f_2587},
{C_text("f_2601:scheduler_2escm"),(void*)f_2601},
{C_text("f_2604:scheduler_2escm"),(void*)f_2604},
{C_text("f_2630:scheduler_2escm"),(void*)f_2630},
{C_text("f_2642:scheduler_2escm"),(void*)f_2642},
{C_text("f_2651:scheduler_2escm"),(void*)f_2651},
{C_text("f_2680:scheduler_2escm"),(void*)f_2680},
{C_text("f_2685:scheduler_2escm"),(void*)f_2685},
{C_text("f_2708:scheduler_2escm"),(void*)f_2708},
{C_text("f_916:scheduler_2escm"),(void*)f_916},
{C_text("f_919:scheduler_2escm"),(void*)f_919},
{C_text("f_921:scheduler_2escm"),(void*)f_921},
{C_text("f_927:scheduler_2escm"),(void*)f_927},
{C_text("f_954:scheduler_2escm"),(void*)f_954},
{C_text("f_964:scheduler_2escm"),(void*)f_964},
{C_text("f_995:scheduler_2escm"),(void*)f_995},
{C_text("toplevel:scheduler_2escm"),(void*)C_scheduler_toplevel},
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
S|  chicken.format#sprintf		3
S|  scheme#for-each		6
S|  ##sys#for-each		1
o|eliminated procedure checks: 137 
o|specializations:
o|  3 (chicken.base#add1 *)
o|  2 (chicken.base#sub1 *)
o|  1 (scheme#zero? *)
o|  3 (##sys#check-output-port * * *)
o|  10 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  3 (scheme#car pair)
o|  20 (scheme#cdr pair)
o|  4 (scheme#cdar (pair pair *))
(o e)|safe calls: 249 
(o e)|assignments to immediate values: 12 
o|inlining procedure: k929 
o|inlining procedure: k929 
o|inlining procedure: k1017 
o|inlining procedure: k1017 
o|contracted procedure: "(scheduler.scm:234) switch166" 
o|contracted procedure: "(scheduler.scm:170) ##sys#restore-thread-state-buffer" 
o|contracted procedure: "(scheduler.scm:229) remove-from-ready-queue" 
o|inlining procedure: k1221 
o|inlining procedure: k1221 
o|propagated global variable: first-pair227 ready-queue-head 
o|inlining procedure: k1060 
o|inlining procedure: k1060 
o|contracted procedure: "(scheduler.scm:226) ##sys#unblock-threads-for-i/o" 
o|inlining procedure: k2037 
o|inlining procedure: k2037 
o|inlining procedure: k2059 
o|inlining procedure: k2059 
o|inlining procedure: k2086 
o|inlining procedure: k2086 
o|inlining procedure: k2145 
o|inlining procedure: k2145 
o|substituted constant variable: a2179 
o|substituted constant variable: a2180 
o|inlining procedure: k2201 
o|inlining procedure: k2201 
o|contracted procedure: "(scheduler.scm:511) fdset-test" 
o|inlining procedure: k1880 
o|inlining procedure: k1880 
o|inlining procedure: k1898 
o|substituted constant variable: a1912 
o|substituted constant variable: a1913 
o|inlining procedure: k1898 
o|substituted constant variable: a1939 
o|substituted constant variable: a1944 
o|substituted constant variable: a1946 
o|substituted constant variable: a1951 
o|substituted constant variable: a1953 
o|contracted procedure: "(scheduler.scm:471) g512513" 
o|contracted procedure: "(scheduler.scm:461) create-fdset" 
o|inlining procedure: k1745 
o|inlining procedure: k1759 
o|inlining procedure: k1776 
o|inlining procedure: k1776 
o|substituted constant variable: a1799 
o|substituted constant variable: a1800 
o|substituted constant variable: a1820 
o|substituted constant variable: a1825 
o|substituted constant variable: a1827 
o|substituted constant variable: a1832 
o|substituted constant variable: a1834 
o|inlining procedure: k1759 
o|inlining procedure: k1745 
o|contracted procedure: "(scheduler.scm:408) g443444" 
o|inlining procedure: k1853 
o|inlining procedure: k1853 
o|contracted procedure: "(scheduler.scm:404) g386387" 
o|inlining procedure: k1078 
o|inlining procedure: k1078 
o|inlining procedure: k1099 
o|inlining procedure: k1099 
o|inlining procedure: k1133 
o|inlining procedure: k1133 
o|inlining procedure: k1155 
o|inlining procedure: k1155 
o|propagated global variable: ct172 ##sys#current-thread 
o|inlining procedure: k1207 
o|inlining procedure: k1207 
o|inlining procedure: k1300 
o|propagated global variable: ct251 ##sys#current-thread 
o|inlining procedure: k1300 
o|inlining procedure: k1334 
o|inlining procedure: k1334 
o|inlining procedure: k1352 
o|inlining procedure: k1352 
o|inlining procedure: k1369 
o|inlining procedure: k1390 
o|inlining procedure: k1390 
o|inlining procedure: k1369 
o|inlining procedure: k1441 
o|inlining procedure: k1441 
o|inlining procedure: k1598 
o|inlining procedure: k1609 
o|inlining procedure: k1609 
o|inlining procedure: k1598 
o|inlining procedure: k1628 
o|inlining procedure: k1628 
o|inlining procedure: k1662 
o|inlining procedure: k1662 
o|contracted procedure: "(scheduler.scm:349) ##sys#abandon-mutexes" 
o|inlining procedure: k1479 
o|inlining procedure: k1479 
o|inlining procedure: k1545 
o|contracted procedure: "(scheduler.scm:332) g293300" 
o|inlining procedure: k1499 
o|inlining procedure: k1499 
o|inlining procedure: k1519 
o|contracted procedure: "(scheduler.scm:339) g307314" 
o|inlining procedure: k1519 
o|inlining procedure: k1545 
o|propagated global variable: pt376 ##sys#primordial-thread 
o|inlining procedure: k1976 
o|inlining procedure: k1976 
o|inlining procedure: k2291 
o|inlining procedure: k2307 
o|inlining procedure: k2307 
o|inlining procedure: k2328 
o|inlining procedure: k2328 
o|inlining procedure: k2291 
o|inlining procedure: k2378 
o|inlining procedure: k2378 
o|inlining procedure: k2401 
o|inlining procedure: k2425 
o|inlining procedure: k2425 
o|inlining procedure: k2401 
o|inlining procedure: k2450 
o|inlining procedure: k2450 
o|inlining procedure: k2533 
o|inlining procedure: k2533 
o|propagated global variable: ct642 ##sys#current-thread 
o|propagated global variable: primordial648 ##sys#current-thread 
o|inlining procedure: k2653 
o|inlining procedure: k2653 
o|inlining procedure: k2687 
o|inlining procedure: k2687 
o|propagated global variable: g669681 fd-list 
o|inlining procedure: k2710 
o|inlining procedure: k2710 
o|propagated global variable: g659674 timeout-list 
o|propagated global variable: primordial648 ##sys#current-thread 
o|replaced variables: 442 
o|removed binding forms: 186 
o|inlining procedure: k1231 
o|inlining procedure: k1231 
o|substituted constant variable: r12222735 
o|inlining procedure: k2262 
o|inlining procedure: k2262 
o|substituted constant variable: r11342766 
o|substituted constant variable: r11562769 
o|substituted constant variable: r23082831 
o|converted assignments to bindings: (suspend649) 
o|simplifications: ((let . 1)) 
o|replaced variables: 69 
o|removed binding forms: 371 
o|inlining procedure: k1026 
o|inlining procedure: k1842 
o|replaced variables: 8 
o|removed binding forms: 52 
o|substituted constant variable: r10272949 
o|contracted procedure: k973 
o|contracted procedure: k1736 
o|removed binding forms: 11 
o|removed conditional forms: 1 
o|removed binding forms: 2 
o|simplifications: ((if . 17) (let . 19) (##core#call . 242)) 
o|  call simplifications:
o|    scheme#*
o|    scheme#+
o|    ##sys#call-with-current-continuation
o|    scheme#vector
o|    scheme#list	2
o|    ##sys#structure?	2
o|    scheme#>
o|    scheme#<
o|    chicken.fixnum#fx=	2
o|    scheme#set-cdr!	3
o|    scheme#equal?
o|    scheme#>=
o|    ##sys#setislot	18
o|    scheme#caar	7
o|    scheme#-	2
o|    chicken.fixnum#fx>
o|    scheme#pair?	16
o|    scheme#car	12
o|    scheme#cdr	8
o|    scheme#not	6
o|    ##sys#setslot	30
o|    scheme#null?	26
o|    scheme#eq?	26
o|    scheme#cons	16
o|    ##sys#slot	57
o|contracted procedure: k932 
o|contracted procedure: k960 
o|contracted procedure: k938 
o|contracted procedure: k948 
o|contracted procedure: k956 
o|contracted procedure: k987 
o|contracted procedure: k1020 
o|contracted procedure: k1032 
o|contracted procedure: k1026 
o|contracted procedure: k1051 
o|contracted procedure: k1041 
o|contracted procedure: k970 
o|contracted procedure: k1270 
o|contracted procedure: k1274 
o|contracted procedure: k1278 
o|contracted procedure: k1282 
o|contracted procedure: k1286 
o|contracted procedure: k1290 
o|contracted procedure: k1294 
o|contracted procedure: k977 
o|contracted procedure: k984 
o|contracted procedure: k1240 
o|contracted procedure: k1224 
o|contracted procedure: k1227 
o|propagated global variable: first-pair227 ready-queue-head 
o|contracted procedure: k1235 
o|contracted procedure: k1063 
o|contracted procedure: k2023 
o|contracted procedure: k2026 
o|contracted procedure: k2034 
o|contracted procedure: k2040 
o|contracted procedure: k2049 
o|contracted procedure: k2063 
o|contracted procedure: k2066 
o|contracted procedure: k2069 
o|contracted procedure: k2075 
o|contracted procedure: k2089 
o|contracted procedure: k2095 
o|contracted procedure: k2106 
o|contracted procedure: k2113 
o|contracted procedure: k2125 
o|contracted procedure: k2128 
o|contracted procedure: k2131 
o|contracted procedure: k2137 
o|contracted procedure: k2244 
o|contracted procedure: k2148 
o|contracted procedure: k2162 
o|contracted procedure: k2240 
o|contracted procedure: k2236 
o|contracted procedure: k2171 
o|contracted procedure: k2218 
o|contracted procedure: k2230 
o|contracted procedure: k1883 
o|contracted procedure: k1886 
o|contracted procedure: k1892 
o|contracted procedure: k1895 
o|contracted procedure: k1901 
o|contracted procedure: k2265 
o|contracted procedure: k2268 
o|contracted procedure: k2278 
o|contracted procedure: k1748 
o|contracted procedure: k1751 
o|contracted procedure: k1756 
o|contracted procedure: k1762 
o|contracted procedure: k1769 
o|contracted procedure: k1772 
o|contracted procedure: k1779 
o|contracted procedure: k1782 
o|contracted procedure: k1789 
o|contracted procedure: k1856 
o|contracted procedure: k1866 
o|contracted procedure: k1870 
o|contracted procedure: k1069 
o|contracted procedure: k1081 
o|contracted procedure: k1085 
o|contracted procedure: k1090 
o|contracted procedure: k1096 
o|contracted procedure: k1102 
o|contracted procedure: k1105 
o|contracted procedure: k1126 
o|contracted procedure: k1136 
o|contracted procedure: k1145 
o|contracted procedure: k1152 
o|contracted procedure: k1158 
o|contracted procedure: k1169 
o|contracted procedure: k1172 
o|contracted procedure: k1175 
o|propagated global variable: ct172 ##sys#current-thread 
o|contracted procedure: k1187 
o|contracted procedure: k1201 
o|contracted procedure: k1204 
o|contracted procedure: k1211 
o|contracted procedure: k1207 
o|contracted procedure: k1246 
o|contracted procedure: k1249 
o|contracted procedure: k1252 
o|contracted procedure: k1255 
o|contracted procedure: k1258 
o|contracted procedure: k1261 
o|contracted procedure: k1306 
o|contracted procedure: k1309 
o|contracted procedure: k1337 
o|contracted procedure: k1340 
o|contracted procedure: k1343 
o|contracted procedure: k1363 
o|contracted procedure: k1349 
o|contracted procedure: k1372 
o|contracted procedure: k1378 
o|contracted procedure: k1381 
o|contracted procedure: k1393 
o|contracted procedure: k1410 
o|contracted procedure: k1406 
o|contracted procedure: k1418 
o|contracted procedure: k1414 
o|contracted procedure: k1425 
o|contracted procedure: k1432 
o|contracted procedure: k1438 
o|contracted procedure: k1444 
o|contracted procedure: k1447 
o|contracted procedure: k1467 
o|contracted procedure: k1463 
o|contracted procedure: k1450 
o|contracted procedure: k1453 
o|contracted procedure: k1456 
o|contracted procedure: k1571 
o|contracted procedure: k1583 
o|contracted procedure: k1586 
o|contracted procedure: k1589 
o|contracted procedure: k1592 
o|contracted procedure: k1595 
o|contracted procedure: k1604 
o|contracted procedure: k1619 
o|contracted procedure: k1612 
o|contracted procedure: k1631 
o|contracted procedure: k1641 
o|contracted procedure: k1645 
o|contracted procedure: k1648 
o|contracted procedure: k1659 
o|contracted procedure: k1665 
o|contracted procedure: k1676 
o|contracted procedure: k1476 
o|contracted procedure: k1482 
o|contracted procedure: k1548 
o|contracted procedure: k1558 
o|contracted procedure: k1562 
o|contracted procedure: k1487 
o|contracted procedure: k1490 
o|contracted procedure: k1493 
o|contracted procedure: k1496 
o|contracted procedure: k1505 
o|contracted procedure: k1522 
o|contracted procedure: k1532 
o|contracted procedure: k1536 
o|contracted procedure: k1682 
o|contracted procedure: k1685 
o|contracted procedure: k1697 
o|contracted procedure: k1706 
o|contracted procedure: k1709 
o|propagated global variable: pt376 ##sys#primordial-thread 
o|propagated global variable: pt376 ##sys#primordial-thread 
o|contracted procedure: k1960 
o|contracted procedure: k1963 
o|contracted procedure: k1970 
o|contracted procedure: k1979 
o|contracted procedure: k1987 
o|contracted procedure: k1983 
o|contracted procedure: k1990 
o|contracted procedure: k2014 
o|contracted procedure: k1996 
o|contracted procedure: k2003 
o|contracted procedure: k2354 
o|contracted procedure: k2294 
o|contracted procedure: k2350 
o|contracted procedure: k2297 
o|contracted procedure: k2310 
o|contracted procedure: k2313 
o|contracted procedure: k2316 
o|contracted procedure: k2322 
o|contracted procedure: k2331 
o|contracted procedure: k2335 
o|contracted procedure: k2490 
o|contracted procedure: k2360 
o|contracted procedure: k2484 
o|contracted procedure: k2363 
o|contracted procedure: k2478 
o|contracted procedure: k2366 
o|contracted procedure: k2472 
o|contracted procedure: k2369 
o|contracted procedure: k2381 
o|contracted procedure: k2404 
o|contracted procedure: k2413 
o|contracted procedure: k2428 
o|contracted procedure: k2435 
o|contracted procedure: k2453 
o|contracted procedure: k2466 
o|contracted procedure: k2504 
o|contracted procedure: k2515 
o|contracted procedure: k2519 
o|contracted procedure: k2523 
o|contracted procedure: k2527 
o|contracted procedure: k2559 
o|contracted procedure: k2536 
o|contracted procedure: k2555 
o|contracted procedure: k2571 
o|propagated global variable: ct642 ##sys#current-thread 
o|contracted procedure: k2597 
o|contracted procedure: k2593 
o|contracted procedure: k2615 
o|contracted procedure: k2606 
o|contracted procedure: k2609 
o|contracted procedure: k2623 
o|contracted procedure: k2636 
o|contracted procedure: k2644 
o|contracted procedure: k2656 
o|contracted procedure: k2666 
o|contracted procedure: k2670 
o|contracted procedure: k2690 
o|contracted procedure: k2700 
o|contracted procedure: k2704 
o|contracted procedure: k2713 
o|contracted procedure: k2723 
o|contracted procedure: k2727 
o|propagated global variable: primordial648 ##sys#current-thread 
o|simplifications: ((if . 2) (let . 67)) 
o|removed binding forms: 217 
o|contracted procedure: k1396 
o|inlining procedure: k1551 
o|inlining procedure: k1551 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest589590 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest589590 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest589590 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest589590 0 
o|contracted procedure: k2539 
o|removed binding forms: 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2364 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r2364 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r2364 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r2364 1 
o|removed binding forms: 1 
o|removed binding forms: 2 
o|direct leaf routine/allocation: ##sys#update-thread-state-buffer 0 
o|direct leaf routine/allocation: loop258 0 
o|direct leaf routine/allocation: suspend649 0 
o|direct leaf routine/allocation: g653673 0 
o|contracted procedure: "(scheduler.scm:180) k990" 
o|contracted procedure: "(scheduler.scm:223) k1054" 
o|propagated global variable: ct172 ##sys#current-thread 
o|propagated global variable: ct172 ##sys#current-thread 
o|converted assignments to bindings: (loop258) 
o|contracted procedure: "(scheduler.scm:629) k2627" 
o|contracted procedure: "(scheduler.scm:631) k2659" 
o|contracted procedure: "(scheduler.scm:630) k2716" 
o|simplifications: ((let . 1)) 
o|removed binding forms: 5 
o|direct leaf routine/allocation: for-each-loop685695 0 
o|direct leaf routine/allocation: for-each-loop652676 0 
o|contracted procedure: k2639 
o|converted assignments to bindings: (for-each-loop685695) 
o|converted assignments to bindings: (for-each-loop652676) 
o|simplifications: ((let . 2)) 
o|removed binding forms: 1 
o|direct leaf routine with hoistable closures/allocation: g663680 (for-each-loop685695) 0 
o|contracted procedure: "(scheduler.scm:631) k2693" 
o|removed binding forms: 2 
o|direct leaf routine/allocation: for-each-loop662699 0 
o|contracted procedure: k2673 
o|converted assignments to bindings: (for-each-loop662699) 
o|simplifications: ((let . 1)) 
o|removed binding forms: 1 
o|customizable procedures: (loop615 loop612 loop608 loop605 loop574 loop496 for-each-loop306317 for-each-loop292325 delq k1574 g341348 for-each-loop340351 loop267 k1123 ##sys#clear-i/o-state-for-thread! loop181 g400407 for-each-loop399439 loop392 k2204 loop2541 loop527 k1014 loop2198 loop1179 loop158) 
o|calls to known targets: 73 
o|identified direct recursive calls: f_927 1 
o|identified direct recursive calls: f_2084 1 
o|identified direct recursive calls: f_2057 1 
o|identified direct recursive calls: f_1076 1 
o|identified direct recursive calls: f_1332 1 
o|identified direct recursive calls: f_1388 1 
o|identified direct recursive calls: f_1543 1 
o|identified direct recursive calls: f_1974 1 
o|identified direct recursive calls: f_2305 1 
o|identified direct recursive calls: f_2423 1 
o|unused rest argument: rest589590 f_2358 
o|identified direct recursive calls: f_2708 1 
o|identified direct recursive calls: f_2651 1 
o|identified direct recursive calls: f_2685 1 
o|fast box initializations: 18 
o|fast global references: 48 
o|fast global assignments: 31 
o|dropping unused closure argument: f_1244 
o|dropping unused closure argument: f_2289 
o|dropping unused closure argument: f_921 
*/
/* end of file */
