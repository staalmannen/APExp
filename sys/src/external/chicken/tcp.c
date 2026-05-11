/* Generated from tcp.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: tcp.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file tcp.c -emit-import-library chicken.tcp
   unit: tcp
   uses: scheduler port library
*/
#include "chicken.h"

#ifdef _WIN32
# include <winsock2.h>
# include <ws2tcpip.h>
/* Beware: winsock2.h must come BEFORE windows.h */
# define socklen_t	 int
static WSADATA wsa;
# ifndef SHUT_RD
#  define SHUT_RD	  SD_RECEIVE
# endif
# ifndef SHUT_WR
#  define SHUT_WR	  SD_SEND
# endif

# define typecorrect_getsockopt(socket, level, optname, optval, optlen)	\
    getsockopt(socket, level, optname, (char *)optval, optlen)

static C_word make_socket_nonblocking (C_word sock) {
  int fd = C_unfix(sock);
  C_return(C_mk_bool(ioctlsocket(fd, FIONBIO, (void *)&fd) != SOCKET_ERROR)) ;
}

/* This is a bit of a hack, but it keeps things simple */
static C_TLS char *last_wsa_errorstring = NULL;

static char *errormsg_from_code(int code) {
  int bufsize;
  if (last_wsa_errorstring != NULL) {
    LocalFree(last_wsa_errorstring);
    last_wsa_errorstring = NULL;
  }
  bufsize = FormatMessage(
	FORMAT_MESSAGE_ALLOCATE_BUFFER |
	FORMAT_MESSAGE_FROM_SYSTEM |
	FORMAT_MESSAGE_IGNORE_INSERTS,
	NULL, code, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
	(LPTSTR) &last_wsa_errorstring, 0, NULL);
  if (bufsize == 0) return "ERROR WHILE FETCHING ERROR";
  return last_wsa_errorstring;
}

# define get_last_socket_error()  WSAGetLastError()
# define should_retry_call()      (WSAGetLastError() == WSAEWOULDBLOCK)
/* Not EINPROGRESS in winsock.  Nonblocking connect returns EWOULDBLOCK... */
# define call_in_progress()       (WSAGetLastError() == WSAEWOULDBLOCK)
# define call_was_interrupted()   (WSAGetLastError() == WSAEINTR) /* ? */

#else
# include <errno.h>
# include <fcntl.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <netinet/in.h>
# include <netdb.h>
# include <signal.h>
# define closesocket     close
# define INVALID_SOCKET  -1
# define SOCKET_ERROR    -1
# define typecorrect_getsockopt getsockopt

static C_word make_socket_nonblocking (C_word sock) {
  int fd = C_unfix(sock);
  int val = fcntl(fd, F_GETFL, 0);
  if(val == -1) C_return(C_SCHEME_FALSE);
  C_return(C_mk_bool(fcntl(fd, F_SETFL, val | O_NONBLOCK) != -1));
}

# define get_last_socket_error()  errno
# define errormsg_from_code(e)    strerror(e)

# define should_retry_call()      (errno == EAGAIN || errno == EWOULDBLOCK)
# define call_was_interrupted()   (errno == EINTR)
# define call_in_progress()       (errno == EINPROGRESS)
#endif

#ifdef ECOS
#include <sys/sockio.h>
#endif

#ifndef h_addr
# define h_addr  h_addr_list[ 0 ]
#endif

static char addr_buffer[ 20 ];

static int C_set_socket_options(int socket)
{
  int yes = 1; 
  int r;

  r = setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (const char *)&yes, sizeof(int));
  
  if(r != 0) return r;

#ifdef SO_NOSIGPIPE
  /*
   * Avoid SIGPIPE (iOS uses *only* SIGPIPE otherwise, not returning EPIPE).
   * For consistency we do this everywhere the option is supported.
   */
  r = setsockopt(socket, SOL_SOCKET, SO_NOSIGPIPE, (const char *)&yes, sizeof(int));
#endif

  return r;
}


static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_scheduler_toplevel)
C_externimport void C_ccall C_scheduler_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_port_toplevel)
C_externimport void C_ccall C_port_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[109];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,50),40,99,104,105,99,107,101,110,46,116,99,112,35,103,101,116,104,111,115,116,97,100,100,114,32,115,97,100,100,114,50,54,52,32,104,111,115,116,50,54,53,32,112,111,114,116,50,54,54,41,0,0,0,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,116,99,112,35,116,99,112,45,108,105,115,116,101,110,32,112,111,114,116,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,29),40,99,104,105,99,107,101,110,46,116,99,112,35,116,99,112,45,108,105,115,116,101,110,101,114,63,32,120,41,0,0,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,28),40,99,104,105,99,107,101,110,46,116,99,112,35,116,99,112,45,99,108,111,115,101,32,116,99,112,108,41,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,10),40,102,95,49,54,50,51,32,120,41,0,0,0,0,0,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,11),40,99,104,101,99,107,32,108,111,99,41,0,0,0,0,0};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,12),40,114,101,97,100,45,105,110,112,117,116,41,0,0,0,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,7),40,97,49,56,51,55,41,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,21),40,108,111,111,112,32,108,101,110,32,111,102,102,115,101,116,32,100,108,119,41,0,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,10),40,111,117,116,112,117,116,32,115,41,0,0,0,0,0,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,10),40,102,95,50,48,50,48,32,115,41,0,0,0,0,0,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,10),40,102,95,50,48,52,48,32,115,41,0,0,0,0,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,7),40,97,49,57,51,51,41,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,8),40,102,95,50,48,48,52,41};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,7),40,97,50,48,53,53,41,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,7),40,97,50,48,55,55,41,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,7),40,97,50,49,49,57,41,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,7),40,97,50,49,54,57,41,0};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,32,110,32,109,32,115,116,97,114,116,41};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,22),40,97,50,49,56,55,32,112,32,110,32,100,101,115,116,32,115,116,97,114,116,41,0,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,11),40,97,50,50,56,48,32,112,111,115,41,0,0,0,0,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,7),40,97,50,50,55,48,41,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,28),40,97,50,51,50,54,32,110,101,120,116,32,108,105,110,101,32,102,117,108,108,45,108,105,110,101,63,41,0,0,0,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,15),40,97,50,50,53,50,32,112,32,108,105,109,105,116,41,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,9),40,97,50,51,55,49,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,29),40,99,104,105,99,107,101,110,46,116,99,112,35,105,111,45,112,111,114,116,115,32,108,111,99,32,102,100,41,0,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,29),40,99,104,105,99,107,101,110,46,116,99,112,35,116,99,112,45,97,99,99,101,112,116,32,116,99,112,108,41,0,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,116,99,112,35,116,99,112,45,97,99,99,101,112,116,45,114,101,97,100,121,63,32,116,99,112,108,41,0,0,0,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,7),40,97,50,56,49,55,41,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,23),40,97,50,56,50,51,32,104,111,115,116,55,48,48,32,112,111,114,116,55,48,49,41,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,116,99,112,35,116,99,112,45,99,111,110,110,101,99,116,32,104,111,115,116,32,46,32,109,111,114,101,41,0,0,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,116,99,112,35,116,99,112,45,112,111,114,116,45,62,102,105,108,101,110,111,32,112,32,108,111,99,41,0,0,0,0};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,29),40,99,104,105,99,107,101,110,46,116,99,112,35,116,99,112,45,97,100,100,114,101,115,115,101,115,32,112,41,0,0,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,32),40,99,104,105,99,107,101,110,46,116,99,112,35,116,99,112,45,112,111,114,116,45,110,117,109,98,101,114,115,32,112,41};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,116,99,112,35,116,99,112,45,108,105,115,116,101,110,101,114,45,112,111,114,116,32,116,99,112,108,41,0,0,0,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,32),40,99,104,105,99,107,101,110,46,116,99,112,35,116,99,112,45,97,98,97,110,100,111,110,45,112,111,114,116,32,112,41};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,35),40,99,104,105,99,107,101,110,46,116,99,112,35,116,99,112,45,108,105,115,116,101,110,101,114,45,102,105,108,101,110,111,32,108,41,0,0,0,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


#define return(x) C_cblock C_r = (C_fix((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub685(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int socket=(int )C_unfix(C_a0);
int err, optlen;
optlen = sizeof(err);
if (typecorrect_getsockopt(socket, SOL_SOCKET, SO_ERROR, &err, (socklen_t *)&optlen) == SOCKET_ERROR)
  C_return(SOCKET_ERROR);
C_return(err);
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub396(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
void * saddr=(void * )C_data_pointer(C_a0);
unsigned short port=(unsigned short )(unsigned short)C_unfix(C_a1);
struct sockaddr_in *addr = (struct sockaddr_in *)saddr;
memset(addr, 0, sizeof(struct sockaddr_in));
addr->sin_family = AF_INET;
addr->sin_port = htons(port);
addr->sin_addr.s_addr = htonl(INADDR_ANY);
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_mk_bool((x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub267(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
void * saddr=(void * )C_data_pointer(C_a0);
char * host=(char * )C_string_or_null(C_a1);
unsigned short port=(unsigned short )(unsigned short)C_unfix(C_a2);
struct hostent *he = gethostbyname(host);
struct sockaddr_in *addr = (struct sockaddr_in *)saddr;
if(he == NULL) C_return(0);
memset(addr, 0, sizeof(struct sockaddr_in));
addr->sin_family = AF_INET;
addr->sin_port = htons((short)port);
addr->sin_addr = *((struct in_addr *)he->h_addr);
C_return(1);
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_fix((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub255(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
char * serv=(char * )C_string_or_null(C_a0);
char * proto=(char * )C_string_or_null(C_a1);
struct servent *se;
     if((se = getservbyname(serv, proto)) == NULL) C_return(0);
     else C_return(ntohs(se->s_port));
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_mk_bool((x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub250(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
#ifdef _WIN32
     C_return(WSAStartup(MAKEWORD(1, 1), &wsa) == 0);
#else
     signal(SIGPIPE, SIG_IGN);
     C_return(1);
#endif
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_mpointer(&C_a,(void*)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub245(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int s=(int )C_unfix(C_a0);
struct sockaddr_in sa;
unsigned char *ptr;
unsigned int len = sizeof(struct sockaddr_in);
if(getpeername(s, (struct sockaddr *)&sa, ((socklen_t *)&len)) != 0) C_return(NULL);
ptr = (unsigned char *)&sa.sin_addr;
C_snprintf(addr_buffer, sizeof(addr_buffer), "%d.%d.%d.%d", ptr[ 0 ], ptr[ 1 ], ptr[ 2 ], ptr[ 3 ]);
C_return(addr_buffer);
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_fix((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub240(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int s=(int )C_unfix(C_a0);
struct sockaddr_in sa;
int len = sizeof(struct sockaddr_in);
if(getpeername(s, (struct sockaddr *)&sa, (socklen_t *)(&len)) != 0) C_return(-1);
else C_return(ntohs(sa.sin_port));
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_fix((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub235(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int s=(int )C_unfix(C_a0);
struct sockaddr_in sa;
int len = sizeof(struct sockaddr_in);
if(getsockname(s, (struct sockaddr *)&sa, (socklen_t *)(&len)) != 0) C_return(-1);
else C_return(ntohs(sa.sin_port));
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_mpointer(&C_a,(void*)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub229(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int s=(int )C_unfix(C_a0);
struct sockaddr_in sa;
unsigned char *ptr;
int len = sizeof(struct sockaddr_in);
if(getsockname(s, (struct sockaddr *)&sa, (socklen_t *)&len) != 0) C_return(NULL);
ptr = (unsigned char *)&sa.sin_addr;
C_snprintf(addr_buffer, sizeof(addr_buffer), "%d.%d.%d.%d", ptr[ 0 ], ptr[ 1 ], ptr[ 2 ], ptr[ 3 ]);
C_return(addr_buffer);
C_ret:
#undef return

return C_r;}

#define return(x) C_cblock C_r = (C_fix((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub218(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2,C_word C_a3,C_word C_a4){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int s=(int )C_unfix(C_a0);
void * msg=(void * )C_data_pointer_or_null(C_a1);
int offset=(int )C_unfix(C_a2);
int len=(int )C_unfix(C_a3);
int flags=(int )C_unfix(C_a4);
C_return(send(s, (char *)msg+offset, len, flags));
C_ret:
#undef return

return C_r;}

/* from k1156 */
C_regparm static C_word C_fcall stub209(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_fix((C_word)C_set_socket_options(t0));
return C_r;}

/* from k1149 */
C_regparm static C_word C_fcall stub204(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_fix((C_word)C_check_fd_ready(t0));
return C_r;}

/* from k1139 */
C_regparm static C_word C_fcall stub195(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
void * t1=(void * )C_data_pointer_or_null(C_a1);
int t2=(int )C_unfix(C_a2);
C_r=C_fix((C_word)connect(t0,t1,t2));
return C_r;}

/* from k1124 */
C_regparm static C_word C_fcall stub187(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
int t1=(int )C_unfix(C_a1);
C_r=C_fix((C_word)shutdown(t0,t1));
return C_r;}

/* from k1110 */
C_regparm static C_word C_fcall stub176(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2,C_word C_a3){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
void * t1=(void * )C_data_pointer_or_null(C_a1);
int t2=(int )C_unfix(C_a2);
int t3=(int )C_unfix(C_a3);
C_r=C_fix((C_word)recv(t0,t1,t2,t3));
return C_r;}

/* from k1091 */
C_regparm static C_word C_fcall stub168(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_fix((C_word)closesocket(t0));
return C_r;}

/* from k1078 */
C_regparm static C_word C_fcall stub157(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
void * t1=(void * )C_c_pointer_or_null(C_a1);
void * t2=(void * )C_c_pointer_or_null(C_a2);
C_r=C_fix((C_word)accept(t0,t1,t2));
return C_r;}

/* from k1063 */
C_regparm static C_word C_fcall stub149(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
int t1=(int )C_unfix(C_a1);
C_r=C_fix((C_word)listen(t0,t1));
return C_r;}

/* from k1049 */
C_regparm static C_word C_fcall stub139(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
void * t1=(void * )C_data_pointer_or_null(C_a1);
int t2=(int )C_unfix(C_a2);
C_r=C_fix((C_word)bind(t0,t1,t2));
return C_r;}

/* from k1034 */
C_regparm static C_word C_fcall stub130(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
int t1=(int )C_unfix(C_a1);
int t2=(int )C_unfix(C_a2);
C_r=C_fix((C_word)socket(t0,t1,t2));
return C_r;}

/* from chicken.tcp#interrupted? */
C_regparm static C_word C_fcall stub124(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_mk_bool(call_was_interrupted());
return C_r;}

/* from chicken.tcp#in-progress? */
C_regparm static C_word C_fcall stub121(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_mk_bool(call_in_progress());
return C_r;}

/* from chicken.tcp#retry? */
C_regparm static C_word C_fcall stub118(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_mk_bool(should_retry_call());
return C_r;}

/* from k1010 */
C_regparm static C_word C_fcall stub113(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_mpointer(&C_a,(void*)errormsg_from_code(t0));
return C_r;}

/* from chicken.tcp#last-error-code */
C_regparm static C_word C_fcall stub109(C_word C_buf){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_r=C_fix((C_word)get_last_socket_error());
return C_r;}

C_noret_decl(f3431)
static void C_ccall f3431(C_word c,C_word *av) C_noret;
C_noret_decl(f_1226)
static void C_ccall f_1226(C_word c,C_word *av) C_noret;
C_noret_decl(f_1233)
static void C_ccall f_1233(C_word c,C_word *av) C_noret;
C_noret_decl(f_1237)
static void C_ccall f_1237(C_word c,C_word *av) C_noret;
C_noret_decl(f_1253)
static void C_fcall f_1253(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1262)
static void C_ccall f_1262(C_word c,C_word *av) C_noret;
C_noret_decl(f_1285)
static void C_fcall f_1285(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1308)
static void C_ccall f_1308(C_word c,C_word *av) C_noret;
C_noret_decl(f_1312)
static void C_ccall f_1312(C_word c,C_word *av) C_noret;
C_noret_decl(f_1315)
static void C_fcall f_1315(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1318)
static void C_ccall f_1318(C_word c,C_word *av) C_noret;
C_noret_decl(f_1328)
static void C_ccall f_1328(C_word c,C_word *av) C_noret;
C_noret_decl(f_1332)
static void C_ccall f_1332(C_word c,C_word *av) C_noret;
C_noret_decl(f_1336)
static void C_ccall f_1336(C_word c,C_word *av) C_noret;
C_noret_decl(f_1371)
static void C_ccall f_1371(C_word c,C_word *av) C_noret;
C_noret_decl(f_1374)
static void C_ccall f_1374(C_word c,C_word *av) C_noret;
C_noret_decl(f_1380)
static void C_ccall f_1380(C_word c,C_word *av) C_noret;
C_noret_decl(f_1383)
static void C_ccall f_1383(C_word c,C_word *av) C_noret;
C_noret_decl(f_1386)
static void C_ccall f_1386(C_word c,C_word *av) C_noret;
C_noret_decl(f_1402)
static void C_ccall f_1402(C_word c,C_word *av) C_noret;
C_noret_decl(f_1406)
static void C_ccall f_1406(C_word c,C_word *av) C_noret;
C_noret_decl(f_1410)
static void C_ccall f_1410(C_word c,C_word *av) C_noret;
C_noret_decl(f_1426)
static void C_ccall f_1426(C_word c,C_word *av) C_noret;
C_noret_decl(f_1430)
static void C_ccall f_1430(C_word c,C_word *av) C_noret;
C_noret_decl(f_1434)
static void C_ccall f_1434(C_word c,C_word *av) C_noret;
C_noret_decl(f_1456)
static void C_ccall f_1456(C_word c,C_word *av) C_noret;
C_noret_decl(f_1465)
static void C_ccall f_1465(C_word c,C_word *av) C_noret;
C_noret_decl(f_1481)
static void C_ccall f_1481(C_word c,C_word *av) C_noret;
C_noret_decl(f_1484)
static void C_ccall f_1484(C_word c,C_word *av) C_noret;
C_noret_decl(f_1487)
static void C_ccall f_1487(C_word c,C_word *av) C_noret;
C_noret_decl(f_1490)
static void C_fcall f_1490(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1493)
static void C_ccall f_1493(C_word c,C_word *av) C_noret;
C_noret_decl(f_1512)
static void C_ccall f_1512(C_word c,C_word *av) C_noret;
C_noret_decl(f_1516)
static void C_ccall f_1516(C_word c,C_word *av) C_noret;
C_noret_decl(f_1520)
static void C_ccall f_1520(C_word c,C_word *av) C_noret;
C_noret_decl(f_1564)
static void C_ccall f_1564(C_word c,C_word *av) C_noret;
C_noret_decl(f_1573)
static void C_ccall f_1573(C_word c,C_word *av) C_noret;
C_noret_decl(f_1593)
static void C_ccall f_1593(C_word c,C_word *av) C_noret;
C_noret_decl(f_1597)
static void C_ccall f_1597(C_word c,C_word *av) C_noret;
C_noret_decl(f_1601)
static void C_ccall f_1601(C_word c,C_word *av) C_noret;
C_noret_decl(f_1615)
static void C_ccall f_1615(C_word c,C_word *av) C_noret;
C_noret_decl(f_1621)
static void C_fcall f_1621(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1623)
static void C_ccall f_1623(C_word c,C_word *av) C_noret;
C_noret_decl(f_1627)
static void C_ccall f_1627(C_word c,C_word *av) C_noret;
C_noret_decl(f_1638)
static void C_ccall f_1638(C_word c,C_word *av) C_noret;
C_noret_decl(f_1642)
static void C_ccall f_1642(C_word c,C_word *av) C_noret;
C_noret_decl(f_1646)
static void C_ccall f_1646(C_word c,C_word *av) C_noret;
C_noret_decl(f_1650)
static void C_ccall f_1650(C_word c,C_word *av) C_noret;
C_noret_decl(f_1652)
static void C_fcall f_1652(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1656)
static void C_ccall f_1656(C_word c,C_word *av) C_noret;
C_noret_decl(f_1659)
static void C_ccall f_1659(C_word c,C_word *av) C_noret;
C_noret_decl(f_1665)
static void C_ccall f_1665(C_word c,C_word *av) C_noret;
C_noret_decl(f_1668)
static void C_fcall f_1668(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1669)
static void C_fcall f_1669(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1673)
static void C_ccall f_1673(C_word c,C_word *av) C_noret;
C_noret_decl(f_1676)
static void C_fcall f_1676(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1681)
static void C_ccall f_1681(C_word c,C_word *av) C_noret;
C_noret_decl(f_1700)
static void C_ccall f_1700(C_word c,C_word *av) C_noret;
C_noret_decl(f_1703)
static void C_ccall f_1703(C_word c,C_word *av) C_noret;
C_noret_decl(f_1706)
static void C_ccall f_1706(C_word c,C_word *av) C_noret;
C_noret_decl(f_1709)
static void C_ccall f_1709(C_word c,C_word *av) C_noret;
C_noret_decl(f_1737)
static void C_ccall f_1737(C_word c,C_word *av) C_noret;
C_noret_decl(f_1741)
static void C_ccall f_1741(C_word c,C_word *av) C_noret;
C_noret_decl(f_1745)
static void C_ccall f_1745(C_word c,C_word *av) C_noret;
C_noret_decl(f_1763)
static void C_ccall f_1763(C_word c,C_word *av) C_noret;
C_noret_decl(f_1766)
static void C_ccall f_1766(C_word c,C_word *av) C_noret;
C_noret_decl(f_1767)
static void C_fcall f_1767(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1771)
static void C_ccall f_1771(C_word c,C_word *av) C_noret;
C_noret_decl(f_1782)
static void C_fcall f_1782(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1784)
static void C_fcall f_1784(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_1806)
static void C_ccall f_1806(C_word c,C_word *av) C_noret;
C_noret_decl(f_1809)
static void C_ccall f_1809(C_word c,C_word *av) C_noret;
C_noret_decl(f_1812)
static void C_ccall f_1812(C_word c,C_word *av) C_noret;
C_noret_decl(f_1815)
static void C_ccall f_1815(C_word c,C_word *av) C_noret;
C_noret_decl(f_1838)
static void C_ccall f_1838(C_word c,C_word *av) C_noret;
C_noret_decl(f_1849)
static void C_ccall f_1849(C_word c,C_word *av) C_noret;
C_noret_decl(f_1853)
static void C_ccall f_1853(C_word c,C_word *av) C_noret;
C_noret_decl(f_1857)
static void C_ccall f_1857(C_word c,C_word *av) C_noret;
C_noret_decl(f_1897)
static void C_ccall f_1897(C_word c,C_word *av) C_noret;
C_noret_decl(f_1904)
static void C_ccall f_1904(C_word c,C_word *av) C_noret;
C_noret_decl(f_1907)
static void C_ccall f_1907(C_word c,C_word *av) C_noret;
C_noret_decl(f_1922)
static void C_ccall f_1922(C_word c,C_word *av) C_noret;
C_noret_decl(f_1925)
static void C_ccall f_1925(C_word c,C_word *av) C_noret;
C_noret_decl(f_1934)
static void C_ccall f_1934(C_word c,C_word *av) C_noret;
C_noret_decl(f_1942)
static void C_fcall f_1942(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1945)
static void C_fcall f_1945(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1951)
static void C_fcall f_1951(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1958)
static void C_ccall f_1958(C_word c,C_word *av) C_noret;
C_noret_decl(f_1962)
static void C_ccall f_1962(C_word c,C_word *av) C_noret;
C_noret_decl(f_1966)
static void C_ccall f_1966(C_word c,C_word *av) C_noret;
C_noret_decl(f_1991)
static void C_ccall f_1991(C_word c,C_word *av) C_noret;
C_noret_decl(f_2004)
static void C_ccall f_2004(C_word c,C_word *av) C_noret;
C_noret_decl(f_2014)
static void C_ccall f_2014(C_word c,C_word *av) C_noret;
C_noret_decl(f_2020)
static void C_ccall f_2020(C_word c,C_word *av) C_noret;
C_noret_decl(f_2025)
static void C_ccall f_2025(C_word c,C_word *av) C_noret;
C_noret_decl(f_2034)
static void C_ccall f_2034(C_word c,C_word *av) C_noret;
C_noret_decl(f_2040)
static void C_ccall f_2040(C_word c,C_word *av) C_noret;
C_noret_decl(f_2056)
static void C_ccall f_2056(C_word c,C_word *av) C_noret;
C_noret_decl(f_2060)
static void C_ccall f_2060(C_word c,C_word *av) C_noret;
C_noret_decl(f_2078)
static void C_ccall f_2078(C_word c,C_word *av) C_noret;
C_noret_decl(f_2091)
static void C_ccall f_2091(C_word c,C_word *av) C_noret;
C_noret_decl(f_2104)
static void C_ccall f_2104(C_word c,C_word *av) C_noret;
C_noret_decl(f_2108)
static void C_ccall f_2108(C_word c,C_word *av) C_noret;
C_noret_decl(f_2112)
static void C_ccall f_2112(C_word c,C_word *av) C_noret;
C_noret_decl(f_2120)
static void C_ccall f_2120(C_word c,C_word *av) C_noret;
C_noret_decl(f_2128)
static void C_fcall f_2128(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2134)
static void C_fcall f_2134(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2141)
static void C_ccall f_2141(C_word c,C_word *av) C_noret;
C_noret_decl(f_2145)
static void C_ccall f_2145(C_word c,C_word *av) C_noret;
C_noret_decl(f_2149)
static void C_ccall f_2149(C_word c,C_word *av) C_noret;
C_noret_decl(f_2170)
static void C_ccall f_2170(C_word c,C_word *av) C_noret;
C_noret_decl(f_2174)
static void C_ccall f_2174(C_word c,C_word *av) C_noret;
C_noret_decl(f_2188)
static void C_ccall f_2188(C_word c,C_word *av) C_noret;
C_noret_decl(f_2194)
static void C_fcall f_2194(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_2242)
static void C_ccall f_2242(C_word c,C_word *av) C_noret;
C_noret_decl(f_2253)
static void C_ccall f_2253(C_word c,C_word *av) C_noret;
C_noret_decl(f_2257)
static void C_ccall f_2257(C_word c,C_word *av) C_noret;
C_noret_decl(f_2271)
static void C_ccall f_2271(C_word c,C_word *av) C_noret;
C_noret_decl(f_2281)
static void C_ccall f_2281(C_word c,C_word *av) C_noret;
C_noret_decl(f_2297)
static void C_ccall f_2297(C_word c,C_word *av) C_noret;
C_noret_decl(f_2327)
static void C_ccall f_2327(C_word c,C_word *av) C_noret;
C_noret_decl(f_2372)
static void C_ccall f_2372(C_word c,C_word *av) C_noret;
C_noret_decl(f_2382)
static void C_ccall f_2382(C_word c,C_word *av) C_noret;
C_noret_decl(f_2403)
static void C_ccall f_2403(C_word c,C_word *av) C_noret;
C_noret_decl(f_2407)
static void C_ccall f_2407(C_word c,C_word *av) C_noret;
C_noret_decl(f_2411)
static void C_ccall f_2411(C_word c,C_word *av) C_noret;
C_noret_decl(f_2415)
static void C_ccall f_2415(C_word c,C_word *av) C_noret;
C_noret_decl(f_2425)
static void C_ccall f_2425(C_word c,C_word *av) C_noret;
C_noret_decl(f_2428)
static void C_fcall f_2428(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2433)
static void C_ccall f_2433(C_word c,C_word *av) C_noret;
C_noret_decl(f_2437)
static void C_ccall f_2437(C_word c,C_word *av) C_noret;
C_noret_decl(f_2440)
static void C_ccall f_2440(C_word c,C_word *av) C_noret;
C_noret_decl(f_2443)
static void C_ccall f_2443(C_word c,C_word *av) C_noret;
C_noret_decl(f_2446)
static void C_ccall f_2446(C_word c,C_word *av) C_noret;
C_noret_decl(f_2474)
static void C_ccall f_2474(C_word c,C_word *av) C_noret;
C_noret_decl(f_2478)
static void C_ccall f_2478(C_word c,C_word *av) C_noret;
C_noret_decl(f_2482)
static void C_ccall f_2482(C_word c,C_word *av) C_noret;
C_noret_decl(f_2508)
static void C_ccall f_2508(C_word c,C_word *av) C_noret;
C_noret_decl(f_2510)
static void C_ccall f_2510(C_word c,C_word *av) C_noret;
C_noret_decl(f_2520)
static void C_ccall f_2520(C_word c,C_word *av) C_noret;
C_noret_decl(f_2533)
static void C_ccall f_2533(C_word c,C_word *av) C_noret;
C_noret_decl(f_2537)
static void C_ccall f_2537(C_word c,C_word *av) C_noret;
C_noret_decl(f_2541)
static void C_ccall f_2541(C_word c,C_word *av) C_noret;
C_noret_decl(f_2560)
static void C_ccall f_2560(C_word c,C_word *av) C_noret;
C_noret_decl(f_2567)
static void C_ccall f_2567(C_word c,C_word *av) C_noret;
C_noret_decl(f_2570)
static void C_fcall f_2570(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2573)
static void C_ccall f_2573(C_word c,C_word *av) C_noret;
C_noret_decl(f_2579)
static void C_ccall f_2579(C_word c,C_word *av) C_noret;
C_noret_decl(f_2582)
static void C_ccall f_2582(C_word c,C_word *av) C_noret;
C_noret_decl(f_2585)
static void C_ccall f_2585(C_word c,C_word *av) C_noret;
C_noret_decl(f_2591)
static void C_ccall f_2591(C_word c,C_word *av) C_noret;
C_noret_decl(f_2594)
static void C_ccall f_2594(C_word c,C_word *av) C_noret;
C_noret_decl(f_2597)
static void C_ccall f_2597(C_word c,C_word *av) C_noret;
C_noret_decl(f_2600)
static void C_ccall f_2600(C_word c,C_word *av) C_noret;
C_noret_decl(f_2606)
static void C_ccall f_2606(C_word c,C_word *av) C_noret;
C_noret_decl(f_2625)
static void C_ccall f_2625(C_word c,C_word *av) C_noret;
C_noret_decl(f_2629)
static void C_ccall f_2629(C_word c,C_word *av) C_noret;
C_noret_decl(f_2633)
static void C_ccall f_2633(C_word c,C_word *av) C_noret;
C_noret_decl(f_2651)
static void C_ccall f_2651(C_word c,C_word *av) C_noret;
C_noret_decl(f_2655)
static void C_ccall f_2655(C_word c,C_word *av) C_noret;
C_noret_decl(f_2659)
static void C_ccall f_2659(C_word c,C_word *av) C_noret;
C_noret_decl(f_2663)
static void C_ccall f_2663(C_word c,C_word *av) C_noret;
C_noret_decl(f_2679)
static void C_ccall f_2679(C_word c,C_word *av) C_noret;
C_noret_decl(f_2682)
static void C_ccall f_2682(C_word c,C_word *av) C_noret;
C_noret_decl(f_2710)
static void C_ccall f_2710(C_word c,C_word *av) C_noret;
C_noret_decl(f_2714)
static void C_ccall f_2714(C_word c,C_word *av) C_noret;
C_noret_decl(f_2718)
static void C_ccall f_2718(C_word c,C_word *av) C_noret;
C_noret_decl(f_2737)
static void C_ccall f_2737(C_word c,C_word *av) C_noret;
C_noret_decl(f_2741)
static void C_ccall f_2741(C_word c,C_word *av) C_noret;
C_noret_decl(f_2745)
static void C_ccall f_2745(C_word c,C_word *av) C_noret;
C_noret_decl(f_2763)
static void C_ccall f_2763(C_word c,C_word *av) C_noret;
C_noret_decl(f_2767)
static void C_ccall f_2767(C_word c,C_word *av) C_noret;
C_noret_decl(f_2771)
static void C_ccall f_2771(C_word c,C_word *av) C_noret;
C_noret_decl(f_2787)
static void C_ccall f_2787(C_word c,C_word *av) C_noret;
C_noret_decl(f_2791)
static void C_ccall f_2791(C_word c,C_word *av) C_noret;
C_noret_decl(f_2795)
static void C_ccall f_2795(C_word c,C_word *av) C_noret;
C_noret_decl(f_2804)
static void C_ccall f_2804(C_word c,C_word *av) C_noret;
C_noret_decl(f_2810)
static void C_ccall f_2810(C_word c,C_word *av) C_noret;
C_noret_decl(f_2818)
static void C_ccall f_2818(C_word c,C_word *av) C_noret;
C_noret_decl(f_2824)
static void C_ccall f_2824(C_word c,C_word *av) C_noret;
C_noret_decl(f_2835)
static void C_ccall f_2835(C_word c,C_word *av) C_noret;
C_noret_decl(f_2843)
static void C_fcall f_2843(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2847)
static void C_ccall f_2847(C_word c,C_word *av) C_noret;
C_noret_decl(f_2861)
static void C_ccall f_2861(C_word c,C_word *av) C_noret;
C_noret_decl(f_2867)
static void C_ccall f_2867(C_word c,C_word *av) C_noret;
C_noret_decl(f_2874)
static void C_ccall f_2874(C_word c,C_word *av) C_noret;
C_noret_decl(f_2877)
static void C_ccall f_2877(C_word c,C_word *av) C_noret;
C_noret_decl(f_2881)
static void C_ccall f_2881(C_word c,C_word *av) C_noret;
C_noret_decl(f_2884)
static void C_ccall f_2884(C_word c,C_word *av) C_noret;
C_noret_decl(f_2891)
static void C_ccall f_2891(C_word c,C_word *av) C_noret;
C_noret_decl(f_2895)
static void C_ccall f_2895(C_word c,C_word *av) C_noret;
C_noret_decl(f_2899)
static void C_ccall f_2899(C_word c,C_word *av) C_noret;
C_noret_decl(f_2912)
static void C_ccall f_2912(C_word c,C_word *av) C_noret;
C_noret_decl(f_2916)
static void C_ccall f_2916(C_word c,C_word *av) C_noret;
C_noret_decl(f_2920)
static void C_ccall f_2920(C_word c,C_word *av) C_noret;
C_noret_decl(f_2928)
static void C_ccall f_2928(C_word c,C_word *av) C_noret;
C_noret_decl(f_2934)
static void C_ccall f_2934(C_word c,C_word *av) C_noret;
C_noret_decl(f_2943)
static void C_ccall f_2943(C_word c,C_word *av) C_noret;
C_noret_decl(f_2946)
static void C_ccall f_2946(C_word c,C_word *av) C_noret;
C_noret_decl(f_2959)
static void C_ccall f_2959(C_word c,C_word *av) C_noret;
C_noret_decl(f_2963)
static void C_ccall f_2963(C_word c,C_word *av) C_noret;
C_noret_decl(f_2967)
static void C_ccall f_2967(C_word c,C_word *av) C_noret;
C_noret_decl(f_2983)
static void C_ccall f_2983(C_word c,C_word *av) C_noret;
C_noret_decl(f_2987)
static void C_ccall f_2987(C_word c,C_word *av) C_noret;
C_noret_decl(f_2991)
static void C_ccall f_2991(C_word c,C_word *av) C_noret;
C_noret_decl(f_2999)
static void C_ccall f_2999(C_word c,C_word *av) C_noret;
C_noret_decl(f_3012)
static void C_ccall f_3012(C_word c,C_word *av) C_noret;
C_noret_decl(f_3022)
static void C_ccall f_3022(C_word c,C_word *av) C_noret;
C_noret_decl(f_3026)
static void C_ccall f_3026(C_word c,C_word *av) C_noret;
C_noret_decl(f_3030)
static void C_ccall f_3030(C_word c,C_word *av) C_noret;
C_noret_decl(f_3038)
static void C_ccall f_3038(C_word c,C_word *av) C_noret;
C_noret_decl(f_3048)
static void C_ccall f_3048(C_word c,C_word *av) C_noret;
C_noret_decl(f_3054)
static void C_ccall f_3054(C_word c,C_word *av) C_noret;
C_noret_decl(f_3065)
static void C_ccall f_3065(C_word c,C_word *av) C_noret;
C_noret_decl(f_3069)
static void C_ccall f_3069(C_word c,C_word *av) C_noret;
C_noret_decl(f_3073)
static void C_ccall f_3073(C_word c,C_word *av) C_noret;
C_noret_decl(f_3077)
static void C_ccall f_3077(C_word c,C_word *av) C_noret;
C_noret_decl(f_992)
static void C_ccall f_992(C_word c,C_word *av) C_noret;
C_noret_decl(f_995)
static void C_ccall f_995(C_word c,C_word *av) C_noret;
C_noret_decl(f_998)
static void C_ccall f_998(C_word c,C_word *av) C_noret;
C_noret_decl(C_tcp_toplevel)
C_externexport void C_ccall C_tcp_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_1253)
static void C_ccall trf_1253(C_word c,C_word *av) C_noret;
static void C_ccall trf_1253(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1253(t0,t1,t2,t3);}

C_noret_decl(trf_1285)
static void C_ccall trf_1285(C_word c,C_word *av) C_noret;
static void C_ccall trf_1285(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1285(t0,t1,t2);}

C_noret_decl(trf_1315)
static void C_ccall trf_1315(C_word c,C_word *av) C_noret;
static void C_ccall trf_1315(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1315(t0,t1);}

C_noret_decl(trf_1490)
static void C_ccall trf_1490(C_word c,C_word *av) C_noret;
static void C_ccall trf_1490(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1490(t0,t1);}

C_noret_decl(trf_1621)
static void C_ccall trf_1621(C_word c,C_word *av) C_noret;
static void C_ccall trf_1621(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1621(t0,t1);}

C_noret_decl(trf_1652)
static void C_ccall trf_1652(C_word c,C_word *av) C_noret;
static void C_ccall trf_1652(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1652(t0,t1,t2,t3);}

C_noret_decl(trf_1668)
static void C_ccall trf_1668(C_word c,C_word *av) C_noret;
static void C_ccall trf_1668(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1668(t0,t1);}

C_noret_decl(trf_1669)
static void C_ccall trf_1669(C_word c,C_word *av) C_noret;
static void C_ccall trf_1669(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1669(t0,t1);}

C_noret_decl(trf_1676)
static void C_ccall trf_1676(C_word c,C_word *av) C_noret;
static void C_ccall trf_1676(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1676(t0,t1);}

C_noret_decl(trf_1767)
static void C_ccall trf_1767(C_word c,C_word *av) C_noret;
static void C_ccall trf_1767(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1767(t0,t1,t2);}

C_noret_decl(trf_1782)
static void C_ccall trf_1782(C_word c,C_word *av) C_noret;
static void C_ccall trf_1782(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1782(t0,t1);}

C_noret_decl(trf_1784)
static void C_ccall trf_1784(C_word c,C_word *av) C_noret;
static void C_ccall trf_1784(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_1784(t0,t1,t2,t3,t4);}

C_noret_decl(trf_1942)
static void C_ccall trf_1942(C_word c,C_word *av) C_noret;
static void C_ccall trf_1942(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1942(t0,t1);}

C_noret_decl(trf_1945)
static void C_ccall trf_1945(C_word c,C_word *av) C_noret;
static void C_ccall trf_1945(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1945(t0,t1);}

C_noret_decl(trf_1951)
static void C_ccall trf_1951(C_word c,C_word *av) C_noret;
static void C_ccall trf_1951(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1951(t0,t1);}

C_noret_decl(trf_2128)
static void C_ccall trf_2128(C_word c,C_word *av) C_noret;
static void C_ccall trf_2128(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2128(t0,t1);}

C_noret_decl(trf_2134)
static void C_ccall trf_2134(C_word c,C_word *av) C_noret;
static void C_ccall trf_2134(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2134(t0,t1);}

C_noret_decl(trf_2194)
static void C_ccall trf_2194(C_word c,C_word *av) C_noret;
static void C_ccall trf_2194(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_2194(t0,t1,t2,t3,t4);}

C_noret_decl(trf_2428)
static void C_ccall trf_2428(C_word c,C_word *av) C_noret;
static void C_ccall trf_2428(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2428(t0,t1);}

C_noret_decl(trf_2570)
static void C_ccall trf_2570(C_word c,C_word *av) C_noret;
static void C_ccall trf_2570(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2570(t0,t1);}

C_noret_decl(trf_2843)
static void C_ccall trf_2843(C_word c,C_word *av) C_noret;
static void C_ccall trf_2843(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2843(t0,t1,t2);}

/* f3431 in loop in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f3431(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f3431,c,av);}
/* tcp.scm:610: ##sys#thread-yield! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[36]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[36]+1);
av2[1]=((C_word*)t0)[2];
tp(2,av2);}}

/* k1224 in k996 in k993 in k990 */
static void C_ccall f_1226(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,5)))){
C_save_and_reclaim((void *)f_1226,c,av);}
a=C_alloc(15);
t2=C_mutate(&lf[2] /* (set! chicken.tcp#gethostaddr ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1253,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t3=C_mutate((C_word*)lf[4]+1 /* (set! chicken.tcp#tcp-listen ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1465,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[23]+1 /* (set! chicken.tcp#tcp-listener? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1564,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[24]+1 /* (set! chicken.tcp#tcp-close ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1573,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp));
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1615,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* tcp.scm:345: chicken.base#make-parameter */
t7=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k1231 in k1310 in k1306 in loop in a2817 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1233(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1233,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1237,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)t0)[3])){
/* tcp.scm:240: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=t2;
av2[2]=C_i_foreign_string_argumentp(((C_word*)t0)[3]);
tp(3,av2);}}
else{
t3=((C_word*)t0)[2];
f_1315(t3,stub255(C_SCHEME_UNDEFINED,t1,C_SCHEME_FALSE));}}

/* k1235 in k1231 in k1310 in k1306 in loop in a2817 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1237(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1237,c,av);}
t2=((C_word*)t0)[2];
f_1315(t2,stub255(C_SCHEME_UNDEFINED,((C_word*)t0)[3],t1));}

/* chicken.tcp#gethostaddr in k1224 in k996 in k993 in k990 */
static void C_fcall f_1253(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1253,4,t1,t2,t3,t4);}
a=C_alloc(5);
t5=C_i_foreign_block_argumentp(t2);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1262,a[2]=t1,a[3]=t5,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t3)){
/* tcp.scm:246: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[3]+1);
av2[1]=t6;
av2[2]=C_i_foreign_string_argumentp(t3);
tp(3,av2);}}
else{
t7=C_fix((C_word)sizeof(unsigned short) * CHAR_BIT);
t8=t1;{
C_word av2[2];
av2[0]=t8;
av2[1]=stub267(C_SCHEME_UNDEFINED,t5,C_SCHEME_FALSE,C_i_foreign_unsigned_ranged_integer_argumentp(t4,t7));
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k1260 in chicken.tcp#gethostaddr in k1224 in k996 in k993 in k990 */
static void C_ccall f_1262(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1262,c,av);}
t2=C_fix((C_word)sizeof(unsigned short) * CHAR_BIT);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=stub267(C_SCHEME_UNDEFINED,((C_word*)t0)[3],t1,C_i_foreign_unsigned_ranged_integer_argumentp(((C_word*)t0)[4],t2));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* loop in a2817 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_1285(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_1285,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
/* tcp.scm:282: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_FALSE;
C_values(4,av2);}}
else{
t3=C_subchar(((C_word*)t0)[3],t2);
if(C_truep(C_i_char_equalp(t3,C_make_character(58)))){
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1308,a[2]=t1,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* tcp.scm:286: substring */
t5=*((C_word*)lf[83]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[3];
av2[3]=C_fixnum_plus(t2,C_fix(1));
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
/* tcp.scm:292: loop */
t6=t1;
t7=C_fixnum_plus(t2,C_fix(1));
t1=t6;
t2=t7;
goto loop;}}}

/* k1306 in loop in a2817 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1308(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_1308,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1312,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* tcp.scm:287: substring */
t3=*((C_word*)lf[83]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(0);
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k1310 in k1306 in loop in a2817 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1312(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_1312,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1315,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1233,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t1)){
/* tcp.scm:240: ##sys#make-c-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=t3;
av2[2]=C_i_foreign_string_argumentp(t1);
tp(3,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_1233(2,av2);}}}

/* k1313 in k1310 in k1306 in loop in a2817 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_1315(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_1315,2,t0,t1);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1318,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=C_eqp(C_fix(0),t1);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1328,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1332,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t5;
av2[2]=lf[82];
av2[3]=lf[13];
tp(4,av2);}}
else{
/* tcp.scm:285: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
C_values(4,av2);}}}

/* k1316 in k1313 in k1310 in k1306 in loop in a2817 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1318(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1318,c,av);}
/* tcp.scm:285: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
C_values(4,av2);}}

/* k1326 in k1313 in k1310 in k1306 in loop in a2817 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1328(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_1328,c,av);}
/* tcp.scm:290: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[72];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k1330 in k1313 in k1310 in k1306 in loop in a2817 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1332(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1332,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1336,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k1334 in k1330 in k1313 in k1310 in k1306 in loop in a2817 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1336(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1336,c,av);}
/* tcp.scm:290: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k1369 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1371(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_1371,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1374,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)t0)[4])){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1456,a[2]=t2,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* tcp.scm:305: gethostaddr */
f_1253(t3,t1,((C_word*)t0)[4],((C_word*)t0)[5]);}
else{
t3=C_i_foreign_block_argumentp(t1);
t4=C_fix((C_word)sizeof(unsigned short) * CHAR_BIT);
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=stub396(C_SCHEME_UNDEFINED,t3,C_i_foreign_unsigned_ranged_integer_argumentp(((C_word*)t0)[5],t4));
f_1374(2,av2);}}}

/* k1372 in k1369 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1374(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1374,c,av);}
a=C_alloc(7);
t2=C_fix((C_word)AF_INET);
t3=stub130(C_SCHEME_UNDEFINED,C_i_foreign_fixnum_argumentp(t2),C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]),C_fix(0));
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1380,a[2]=((C_word*)t0)[3],a[3]=t3,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t5=C_eqp(C_fix((C_word)INVALID_SOCKET),t3);
if(C_truep(t5)){
/* tcp.scm:312: ##sys#error */
t6=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t4;
av2[2]=lf[17];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t6=t4;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
f_1380(2,av2);}}}

/* k1378 in k1372 in k1369 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1380(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1380,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1383,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
t4=C_eqp(C_fix((C_word)SOCKET_ERROR),stub209(C_SCHEME_UNDEFINED,t3));
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1426,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1430,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t6;
av2[2]=lf[15];
av2[3]=lf[13];
tp(4,av2);}}
else{
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_1383(2,av2);}}}

/* k1381 in k1378 in k1372 in k1369 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1383(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_1383,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1386,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_fix((C_word)sizeof(struct sockaddr_in));
t4=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
t5=(C_truep(((C_word*)t0)[4])?C_i_foreign_block_argumentp(((C_word*)t0)[4]):C_SCHEME_FALSE);
t6=C_i_foreign_fixnum_argumentp(t3);
t7=C_eqp(C_fix((C_word)SOCKET_ERROR),stub139(C_SCHEME_UNDEFINED,t4,t5,t6));
if(C_truep(t7)){
t8=stub109(C_SCHEME_UNDEFINED);
t9=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
t10=stub168(C_SCHEME_UNDEFINED,t9);
t11=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1402,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
t12=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1406,a[2]=t11,a[3]=t8,tmp=(C_word)a,a+=4,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t12;
av2[2]=lf[14];
av2[3]=lf[13];
tp(4,av2);}}
else{
t8=((C_word*)t0)[2];
f_1490(t8,((C_word*)t0)[3]);}}

/* k1384 in k1381 in k1378 in k1372 in k1369 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1386(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1386,c,av);}
t2=((C_word*)t0)[2];
f_1490(t2,((C_word*)t0)[3]);}

/* k1400 in k1381 in k1378 in k1372 in k1369 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1402(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_1402,c,av);}
/* tcp.scm:317: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[8];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[4];
av2[7]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(8,av2);}}

/* k1404 in k1381 in k1378 in k1372 in k1369 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1406(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_1406,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1410,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
/* tcp.scm:171: ##sys#peek-c-string */
t5=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=stub113(t3,t4);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k1408 in k1404 in k1381 in k1378 in k1372 in k1369 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1410(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1410,c,av);}
/* tcp.scm:317: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k1424 in k1378 in k1372 in k1369 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1426(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_1426,c,av);}
/* tcp.scm:315: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[8];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k1428 in k1378 in k1372 in k1369 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1430(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1430,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1434,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k1432 in k1428 in k1378 in k1372 in k1369 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1434(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1434,c,av);}
/* tcp.scm:315: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k1454 in k1369 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1456(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_1456,c,av);}
if(C_truep(t1)){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_1374(2,av2);}}
else{
/* tcp.scm:306: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[8];
av2[4]=lf[18];
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(7,av2);}}}

/* chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1465(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_1465,c,av);}
a=C_alloc(6);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_fix(100):C_get_rest_arg(c,3,av,3,t0));
t5=C_rest_nullp(c,3);
t6=C_rest_nullp(c,4);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,3,t0));
t8=C_rest_nullp(c,4);
t9=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1481,a[2]=t1,a[3]=t4,a[4]=t2,a[5]=t7,tmp=(C_word)a,a+=6,tmp);
/* tcp.scm:323: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[20]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[20]+1);
av2[1]=t9;
av2[2]=t2;
tp(3,av2);}}

/* k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1481(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_1481,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1484,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_fixnum_lessp(((C_word*)t0)[4],C_fix(0));
if(C_truep(t3)){
if(C_truep(t3)){
/* tcp.scm:325: ##sys#signal-hook */
t4=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[21];
av2[3]=lf[8];
av2[4]=lf[22];
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(6,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_1484(2,av2);}}}
else{
if(C_truep(C_fixnum_greaterp(((C_word*)t0)[4],C_fix(65535)))){
/* tcp.scm:325: ##sys#signal-hook */
t4=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[21];
av2[3]=lf[8];
av2[4]=lf[22];
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(6,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_1484(2,av2);}}}}

/* k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1484(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_1484,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1487,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* tcp.scm:326: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[20]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[20]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}

/* k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1487(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1487,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1490,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_fix((C_word)SOCK_STREAM);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1371,a[2]=t3,a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t5=C_fix((C_word)sizeof(struct sockaddr_in));
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[19]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[19]+1);
av2[1]=t4;
av2[2]=t5;
av2[3]=C_make_character(32);
tp(4,av2);}}

/* k1488 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_fcall f_1490(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,0,3)))){
C_save_and_reclaim_args((void *)trf_1490,2,t0,t1);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1493,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_i_foreign_fixnum_argumentp(t1);
t4=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
t5=C_eqp(C_fix((C_word)SOCKET_ERROR),stub149(C_SCHEME_UNDEFINED,t3,t4));
if(C_truep(t5)){
t6=stub109(C_SCHEME_UNDEFINED);
t7=C_i_foreign_fixnum_argumentp(t1);
t8=stub168(C_SCHEME_UNDEFINED,t7);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1512,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1516,a[2]=t9,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t10;
av2[2]=lf[12];
av2[3]=lf[13];
tp(4,av2);}}
else{
t6=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t6;
av2[1]=C_a_i_record2(&a,2,lf[5],t1);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k1491 in k1488 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1493(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_1493,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record2(&a,2,lf[5],((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k1510 in k1488 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1512(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_1512,c,av);}
/* tcp.scm:329: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[8];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(7,av2);}}

/* k1514 in k1488 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1516(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_1516,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1520,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
/* tcp.scm:171: ##sys#peek-c-string */
t5=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=stub113(t3,t4);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k1518 in k1514 in k1488 in k1485 in k1482 in k1479 in chicken.tcp#tcp-listen in k1224 in k996 in k993 in k990 */
static void C_ccall f_1520(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1520,c,av);}
/* tcp.scm:329: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* chicken.tcp#tcp-listener? in k1224 in k996 in k993 in k990 */
static void C_ccall f_1564(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1564,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(C_blockp(t2))?C_i_structurep(t2,lf[5]):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.tcp#tcp-close in k1224 in k996 in k993 in k990 */
static void C_ccall f_1573(C_word c,C_word *av){
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
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_1573,c,av);}
a=C_alloc(7);
t3=C_i_check_structure(t2,lf[5]);
t4=C_slot(t2,C_fix(1));
t5=C_i_foreign_fixnum_argumentp(t4);
t6=C_eqp(C_fix((C_word)SOCKET_ERROR),stub168(C_SCHEME_UNDEFINED,t5));
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1593,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1597,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t8;
av2[2]=lf[26];
av2[3]=lf[13];
tp(4,av2);}}
else{
t7=C_SCHEME_UNDEFINED;
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k1591 in chicken.tcp#tcp-close in k1224 in k996 in k993 in k990 */
static void C_ccall f_1593(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_1593,c,av);}
/* tcp.scm:340: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[25];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k1595 in chicken.tcp#tcp-close in k1224 in k996 in k993 in k990 */
static void C_ccall f_1597(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1597,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1601,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k1599 in k1595 in chicken.tcp#tcp-close in k1224 in k996 in k993 in k990 */
static void C_ccall f_1601(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1601,c,av);}
/* tcp.scm:340: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1615(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_1615,c,av);}
a=C_alloc(16);
t2=C_mutate((C_word*)lf[27]+1 /* (set! chicken.tcp#tcp-buffer-size ...) */,t1);
t3=C_set_block_item(lf[28] /* chicken.tcp#tcp-read-timeout */,0,C_SCHEME_UNDEFINED);
t4=C_set_block_item(lf[29] /* chicken.tcp#tcp-write-timeout */,0,C_SCHEME_UNDEFINED);
t5=C_set_block_item(lf[30] /* chicken.tcp#tcp-connect-timeout */,0,C_SCHEME_UNDEFINED);
t6=C_set_block_item(lf[31] /* chicken.tcp#tcp-accept-timeout */,0,C_SCHEME_UNDEFINED);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1621,a[2]=((C_word)li5),tmp=(C_word)a,a+=3,tmp));
t12=C_fixnum_times(C_fix(60),C_fix(1000));
t13=C_set_block_item(t10,0,t12);
t14=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1638,a[2]=((C_word*)t0)[2],a[3]=t8,a[4]=t10,tmp=(C_word)a,a+=5,tmp);
t15=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3077,a[2]=t14,a[3]=t10,tmp=(C_word)a,a+=4,tmp);
/* tcp.scm:356: check */
f_1621(t15,lf[107]);}

/* check in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_1621(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_1621,2,t1,t2);}
a=C_alloc(4);
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1623,a[2]=t2,a[3]=((C_word)li4),tmp=(C_word)a,a+=4,tmp);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* f_1623 in check in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1623(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_1623,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1627,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t2)){
/* tcp.scm:353: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[20]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[20]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[2];
tp(4,av2);}}
else{
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k1625 */
static void C_ccall f_1627(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1627,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1638(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_1638,c,av);}
a=C_alloc(8);
t2=C_mutate((C_word*)lf[28]+1 /* (set! chicken.tcp#tcp-read-timeout ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1642,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3073,a[2]=t3,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* tcp.scm:357: check */
f_1621(t4,lf[106]);}

/* k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1642(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_1642,c,av);}
a=C_alloc(7);
t2=C_mutate((C_word*)lf[29]+1 /* (set! chicken.tcp#tcp-write-timeout ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1646,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3069,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* tcp.scm:358: check */
f_1621(t4,lf[105]);}

/* k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1646(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_1646,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[30]+1 /* (set! chicken.tcp#tcp-connect-timeout ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1650,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3065,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* tcp.scm:359: check */
f_1621(t4,lf[104]);}

/* k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1650(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(31,c,4)))){
C_save_and_reclaim((void *)f_1650,c,av);}
a=C_alloc(31);
t2=C_mutate((C_word*)lf[31]+1 /* (set! chicken.tcp#tcp-accept-timeout ...) */,t1);
t3=*((C_word*)lf[27]+1);
t4=C_mutate(&lf[32] /* (set! chicken.tcp#io-ports ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1652,a[2]=t3,a[3]=((C_word)li26),tmp=(C_word)a,a+=4,tmp));
t5=C_mutate((C_word*)lf[64]+1 /* (set! chicken.tcp#tcp-accept ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2415,a[2]=((C_word)li28),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[68]+1 /* (set! chicken.tcp#tcp-accept-ready? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2510,a[2]=((C_word)li29),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[71]+1 /* (set! chicken.tcp#tcp-connect ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2560,a[2]=((C_word)li34),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate(&lf[84] /* (set! chicken.tcp#tcp-port->fileno ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2843,a[2]=((C_word)li35),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[88]+1 /* (set! chicken.tcp#tcp-addresses ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2861,a[2]=((C_word)li36),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[92]+1 /* (set! chicken.tcp#tcp-port-numbers ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2928,a[2]=((C_word)li37),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[96]+1 /* (set! chicken.tcp#tcp-listener-port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2999,a[2]=((C_word)li38),tmp=(C_word)a,a+=3,tmp));
t12=C_mutate((C_word*)lf[99]+1 /* (set! chicken.tcp#tcp-abandon-port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3038,a[2]=((C_word)li39),tmp=(C_word)a,a+=3,tmp));
t13=C_mutate((C_word*)lf[101]+1 /* (set! chicken.tcp#tcp-listener-fileno ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3054,a[2]=((C_word)li40),tmp=(C_word)a,a+=3,tmp));
t14=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t14;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t14+1)))(2,av2);}}

/* chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_1652(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,0,3)))){
C_save_and_reclaim_args((void *)trf_1652,4,t0,t1,t2,t3);}
a=C_alloc(14);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1656,a[2]=t3,a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
if(C_truep(make_socket_nonblocking(t3))){
t5=t4;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_1656(2,av2);}}
else{
t5=stub109(C_SCHEME_UNDEFINED);
t6=C_i_foreign_fixnum_argumentp(t3);
t7=stub168(C_SCHEME_UNDEFINED,t6);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2403,a[2]=t4,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2407,a[2]=t8,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t9;
av2[2]=lf[63];
av2[3]=lf[13];
tp(4,av2);}}}

/* k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1656(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_1656,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1659,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[19]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[19]+1);
av2[1]=t2;
av2[2]=C_fix(1024);
av2[3]=C_make_character(32);
tp(4,av2);}}

/* k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1659(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,2)))){
C_save_and_reclaim((void *)f_1659,c,av);}
a=C_alloc(24);
t2=C_a_i_vector5(&a,5,((C_word*)t0)[2],C_SCHEME_FALSE,C_SCHEME_FALSE,t1,C_fix(0));
t3=C_fix(0);
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_fix(0);
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_FALSE;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_SCHEME_FALSE;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_1665,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,a[5]=t2,a[6]=t6,a[7]=((C_word*)t0)[3],a[8]=t10,a[9]=t8,tmp=(C_word)a,a+=10,tmp);
/* tcp.scm:372: tbs */
t12=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t12;
av2[1]=t11;
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}

/* k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1665(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_1665,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_1668,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
if(C_truep(t1)){
t3=C_fixnum_greaterp(t1,C_fix(0));
t4=t2;
f_1668(t4,(C_truep(t3)?lf[62]:C_SCHEME_FALSE));}
else{
t3=t2;
f_1668(t3,C_SCHEME_FALSE);}}

/* k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_1668(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(66,0,8)))){
C_save_and_reclaim_args((void *)trf_1668,2,t0,t1);}
a=C_alloc(66);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1669,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word)li7),tmp=(C_word)a,a+=8,tmp);
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1766,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[5],a[5]=t3,a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[9],a[8]=((C_word*)t0)[10],tmp=(C_word)a,a+=9,tmp);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2056,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=t4,a[6]=((C_word)li15),tmp=(C_word)a,a+=7,tmp);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2078,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word)li16),tmp=(C_word)a,a+=6,tmp);
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2120,a[2]=((C_word*)t0)[10],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[9],a[5]=((C_word*)t0)[5],a[6]=((C_word)li17),tmp=(C_word)a,a+=7,tmp);
t9=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2170,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=t4,a[6]=((C_word)li18),tmp=(C_word)a,a+=7,tmp);
t10=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2188,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=t4,a[6]=((C_word)li20),tmp=(C_word)a,a+=7,tmp);
t11=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2253,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=t4,a[6]=((C_word)li24),tmp=(C_word)a,a+=7,tmp);
t12=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2372,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=((C_word)li25),tmp=(C_word)a,a+=6,tmp);
/* tcp.scm:401: chicken.port#make-input-port */
t13=*((C_word*)lf[61]+1);{
C_word av2[9];
av2[0]=t13;
av2[1]=t5;
av2[2]=t6;
av2[3]=t7;
av2[4]=t8;
av2[5]=t9;
av2[6]=t10;
av2[7]=t11;
av2[8]=t12;
((C_proc)(void*)(*((C_word*)t13+1)))(9,av2);}}

/* read-input in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_1669(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_1669,2,t0,t1);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1673,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,tmp=(C_word)a,a+=8,tmp);
/* tcp.scm:376: tcp-read-timeout */
t3=*((C_word*)lf[28]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k1671 in read-input in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1673(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_1673,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1676,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1763,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* tcp.scm:377: chicken.time#current-process-milliseconds */
t4=*((C_word*)lf[42]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=t2;
f_1676(t3,C_SCHEME_FALSE);}}

/* k1674 in k1671 in read-input in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_1676(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,0,2)))){
C_save_and_reclaim_args((void *)trf_1676,2,t0,t1);}
a=C_alloc(13);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_1681,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=((C_word*)t0)[4],a[6]=t1,a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],a[10]=((C_word)li6),tmp=(C_word)a,a+=11,tmp));
t5=((C_word*)t3)[1];{
C_word av2[2];
av2[0]=t5;
av2[1]=((C_word*)t0)[8];
f_1681(2,av2);}}

/* loop in k1674 in k1671 in read-input in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1681(C_word c,C_word *av){
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
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_1681,c,av);}
a=C_alloc(7);
t2=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t3=(C_truep(((C_word*)t0)[3])?C_i_foreign_block_argumentp(((C_word*)t0)[3]):C_SCHEME_FALSE);
t4=C_fix(1024);
t5=C_fix(0);
t6=stub176(C_SCHEME_UNDEFINED,t2,t3,t4,t5);
t7=C_eqp(C_fix((C_word)SOCKET_ERROR),t6);
if(C_truep(t7)){
if(C_truep(stub118(C_SCHEME_UNDEFINED))){
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1700,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[6])){
/* tcp.scm:383: ##sys#thread-block-for-timeout! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[39]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[39]+1);
av2[1]=t8;
av2[2]=*((C_word*)lf[33]+1);
av2[3]=((C_word*)t0)[6];
tp(4,av2);}}
else{
t9=t8;{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_SCHEME_UNDEFINED;
f_1700(2,av2);}}}
else{
if(C_truep(stub124(C_SCHEME_UNDEFINED))){
/* tcp.scm:393: ##sys#dispatch-interrupt */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[40]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[40]+1);
av2[1]=t1;
av2[2]=((C_word*)((C_word*)t0)[4])[1];
tp(3,av2);}}
else{
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1737,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1741,a[2]=t8,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t9;
av2[2]=lf[41];
av2[3]=lf[13];
tp(4,av2);}}}}
else{
t8=C_set_block_item(((C_word*)t0)[7],0,t6);
t9=C_i_set_i_slot(((C_word*)t0)[8],C_fix(4),t6);
t10=C_set_block_item(((C_word*)t0)[9],0,C_fix(0));
t11=t1;{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}}

/* k1698 in loop in k1674 in k1671 in read-input in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1700(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1700,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1703,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* tcp.scm:385: ##sys#thread-block-for-i/o! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[37]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[37]+1);
av2[1]=t2;
av2[2]=*((C_word*)lf[33]+1);
av2[3]=((C_word*)t0)[5];
av2[4]=lf[38];
tp(5,av2);}}

/* k1701 in k1698 in loop in k1674 in k1671 in read-input in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1703(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_1703,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1706,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* tcp.scm:386: ##sys#thread-yield! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[36]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[36]+1);
av2[1]=t2;
tp(2,av2);}}

/* k1704 in k1701 in k1698 in loop in k1674 in k1671 in read-input in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1706(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_1706,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1709,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_slot(*((C_word*)lf[33]+1),C_fix(13)))){
/* tcp.scm:388: ##sys#signal-hook */
t3=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[34];
av2[3]=lf[35];
av2[4]=((C_word*)t0)[4];
av2[5]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}
else{
/* tcp.scm:391: loop */
t3=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
f_1681(2,av2);}}}

/* k1707 in k1704 in k1701 in k1698 in loop in k1674 in k1671 in read-input in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 in ... */
static void C_ccall f_1709(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1709,c,av);}
/* tcp.scm:391: loop */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
f_1681(2,av2);}}

/* k1735 in loop in k1674 in k1671 in read-input in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1737(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_1737,c,av);}
/* tcp.scm:395: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k1739 in loop in k1674 in k1671 in read-input in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1741(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1741,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1745,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k1743 in k1739 in loop in k1674 in k1671 in read-input in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1745(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1745,c,av);}
/* tcp.scm:395: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k1761 in k1671 in read-input in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1763(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,1)))){
C_save_and_reclaim((void *)f_1763,c,av);}
a=C_alloc(29);
t2=((C_word*)t0)[2];
f_1676(t2,C_s_a_i_plus(&a,2,t1,((C_word*)t0)[3]));}

/* k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1766(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(29,c,4)))){
C_save_and_reclaim((void *)f_1766,c,av);}
a=C_alloc(29);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1767,a[2]=((C_word*)t0)[2],a[3]=((C_word)li10),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1907,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t4=(C_truep(((C_word*)((C_word*)t0)[5])[1])?(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2020,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=t2,a[5]=((C_word)li11),tmp=(C_word)a,a+=6,tmp):(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2040,a[2]=t2,a[3]=((C_word)li12),tmp=(C_word)a,a+=4,tmp));
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1934,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=t2,a[8]=((C_word)li13),tmp=(C_word)a,a+=9,tmp);
if(C_truep(((C_word*)((C_word*)t0)[5])[1])){
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2004,a[2]=((C_word*)t0)[5],a[3]=t2,a[4]=((C_word)li14),tmp=(C_word)a,a+=5,tmp);
/* tcp.scm:514: chicken.port#make-output-port */
t7=*((C_word*)lf[54]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t7;
av2[1]=t3;
av2[2]=t4;
av2[3]=t5;
av2[4]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}
else{
/* tcp.scm:514: chicken.port#make-output-port */
t6=*((C_word*)lf[54]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=t4;
av2[3]=t5;
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}}

/* output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_1767(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1767,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1771,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* tcp.scm:484: tcp-write-timeout */
t4=*((C_word*)lf[29]+1);{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k1769 in output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1771(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_1771,c,av);}
a=C_alloc(11);
t2=C_block_size(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1782,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=t2,tmp=(C_word)a,a+=7,tmp);
if(C_truep(t1)){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1904,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* tcp.scm:487: chicken.time#current-process-milliseconds */
t5=*((C_word*)lf[42]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=t3;
f_1782(t4,C_SCHEME_FALSE);}}

/* k1780 in k1769 in output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_1782(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,5)))){
C_save_and_reclaim_args((void *)trf_1782,2,t0,t1);}
a=C_alloc(9);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1784,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=((C_word*)t0)[4],a[6]=((C_word)li9),tmp=(C_word)a,a+=7,tmp));
t5=((C_word*)t3)[1];
f_1784(t5,((C_word*)t0)[5],((C_word*)t0)[6],C_fix(0),t1);}

/* loop in k1780 in k1769 in output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_1784(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(9,0,4)))){
C_save_and_reclaim_args((void *)trf_1784,5,t0,t1,t2,t3,t4);}
a=C_alloc(9);
t5=C_i_fixnum_min(C_fix(8192),t2);
t6=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t7=(C_truep(((C_word*)t0)[3])?C_i_foreign_block_argumentp(((C_word*)t0)[3]):C_SCHEME_FALSE);
t8=C_i_foreign_fixnum_argumentp(t3);
t9=C_i_foreign_fixnum_argumentp(t5);
t10=C_fix(0);
t11=stub218(C_SCHEME_UNDEFINED,t6,t7,t8,t9,t10);
t12=C_eqp(C_fix((C_word)SOCKET_ERROR),t11);
if(C_truep(t12)){
if(C_truep(stub118(C_SCHEME_UNDEFINED))){
t13=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1806,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=t4,a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[2],tmp=(C_word)a,a+=9,tmp);
if(C_truep(t4)){
/* tcp.scm:493: ##sys#thread-block-for-timeout! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[39]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[39]+1);
av2[1]=t13;
av2[2]=*((C_word*)lf[33]+1);
av2[3]=t4;
tp(4,av2);}}
else{
t14=t13;{
C_word av2[2];
av2[0]=t14;
av2[1]=C_SCHEME_UNDEFINED;
f_1806(2,av2);}}}
else{
if(C_truep(stub124(C_SCHEME_UNDEFINED))){
t13=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1838,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=t3,a[5]=t4,a[6]=((C_word)li8),tmp=(C_word)a,a+=7,tmp);
/* tcp.scm:503: ##sys#dispatch-interrupt */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[40]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[40]+1);
av2[1]=t1;
av2[2]=t13;
tp(3,av2);}}
else{
t13=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1849,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t14=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1853,a[2]=t13,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t14;
av2[2]=lf[45];
av2[3]=lf[13];
tp(4,av2);}}}}
else{
if(C_truep(C_fixnum_lessp(t11,t2))){
t13=C_fixnum_difference(t2,t11);
t14=C_fixnum_plus(t3,t11);
t15=C_eqp(t11,C_fix(0));
if(C_truep(t15)){
/* tcp.scm:508: loop */
t18=t1;
t19=t13;
t20=t14;
t21=((C_word*)t0)[5];
t1=t18;
t2=t19;
t3=t20;
t4=t21;
goto loop;}
else{
if(C_truep(((C_word*)t0)[5])){
t16=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1897,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=t1,a[5]=t13,a[6]=t14,tmp=(C_word)a,a+=7,tmp);
/* tcp.scm:512: chicken.time#current-process-milliseconds */
t17=*((C_word*)lf[42]+1);{
C_word av2[2];
av2[0]=t17;
av2[1]=t16;
((C_proc)(void*)(*((C_word*)t17+1)))(2,av2);}}
else{
/* tcp.scm:508: loop */
t18=t1;
t19=t13;
t20=t14;
t21=C_SCHEME_FALSE;
t1=t18;
t2=t19;
t3=t20;
t4=t21;
goto loop;}}}
else{
t13=t1;{
C_word av2[2];
av2[0]=t13;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t13+1)))(2,av2);}}}}

/* k1804 in loop in k1780 in k1769 in output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1806(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_1806,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1809,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* tcp.scm:495: ##sys#thread-block-for-i/o! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[37]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[37]+1);
av2[1]=t2;
av2[2]=*((C_word*)lf[33]+1);
av2[3]=((C_word*)t0)[8];
av2[4]=lf[44];
tp(5,av2);}}

/* k1807 in k1804 in loop in k1780 in k1769 in output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1809(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_1809,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1812,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* tcp.scm:496: ##sys#thread-yield! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[36]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[36]+1);
av2[1]=t2;
tp(2,av2);}}

/* k1810 in k1807 in k1804 in loop in k1780 in k1769 in output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 in ... */
static void C_ccall f_1812(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_1812,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1815,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_slot(*((C_word*)lf[33]+1),C_fix(13)))){
/* tcp.scm:498: ##sys#signal-hook */
t3=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[34];
av2[3]=lf[43];
av2[4]=((C_word*)t0)[7];
av2[5]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}
else{
/* tcp.scm:501: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_1784(t3,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6]);}}

/* k1813 in k1810 in k1807 in k1804 in loop in k1780 in k1769 in output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in ... */
static void C_ccall f_1815(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1815,c,av);}
/* tcp.scm:501: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1784(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6]);}

/* a1837 in loop in k1780 in k1769 in output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1838(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1838,c,av);}
/* tcp.scm:504: g619 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1784(t2,t1,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5]);}

/* k1847 in loop in k1780 in k1769 in output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1849(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_1849,c,av);}
/* tcp.scm:506: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k1851 in loop in k1780 in k1769 in output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1853(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1853,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1857,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k1855 in k1851 in loop in k1780 in k1769 in output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1857(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1857,c,av);}
/* tcp.scm:506: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k1895 in loop in k1780 in k1769 in output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1897(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,4)))){
C_save_and_reclaim((void *)f_1897,c,av);}
a=C_alloc(29);
t2=C_s_a_i_plus(&a,2,t1,((C_word*)t0)[2]);
/* tcp.scm:508: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_1784(t3,((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],t2);}

/* k1902 in k1769 in output in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1904(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,1)))){
C_save_and_reclaim((void *)f_1904,c,av);}
a=C_alloc(29);
t2=((C_word*)t0)[2];
f_1782(t2,C_s_a_i_plus(&a,2,t1,((C_word*)t0)[3]));}

/* k1905 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1907(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_1907,c,av);}
a=C_alloc(6);
t2=C_i_setslot(((C_word*)t0)[2],C_fix(3),lf[46]);
t3=C_i_setslot(t1,C_fix(3),lf[47]);
t4=C_i_setslot(((C_word*)t0)[2],C_fix(7),lf[48]);
t5=C_i_setslot(t1,C_fix(7),lf[48]);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1922,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* tcp.scm:542: ##sys#set-port-data! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[49]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[49]+1);
av2[1]=t6;
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[4];
tp(4,av2);}}

/* k1920 in k1905 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1922(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_1922,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1925,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* tcp.scm:543: ##sys#set-port-data! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[49]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[49]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
tp(4,av2);}}

/* k1923 in k1920 in k1905 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1925(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1925,c,av);}
/* tcp.scm:544: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
C_values(4,av2);}}

/* a1933 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1934(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_1934,c,av);}
a=C_alloc(10);
if(C_truep(((C_word*)((C_word*)t0)[2])[1])){
t2=C_SCHEME_UNDEFINED;
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_TRUE);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1942,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t4=(C_truep(((C_word*)((C_word*)t0)[6])[1])?C_fixnum_greaterp(C_block_size(((C_word*)((C_word*)t0)[6])[1]),C_fix(0)):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1991,a[2]=((C_word*)t0)[6],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* tcp.scm:528: output */
t6=((C_word*)t0)[7];
f_1767(t6,t5,((C_word*)((C_word*)t0)[6])[1]);}
else{
t5=t3;
f_1942(t5,C_SCHEME_UNDEFINED);}}}

/* k1940 in a1933 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_1942(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1942,2,t0,t1);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1945,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_slot(((C_word*)t0)[5],C_fix(2)))){
t3=t2;
f_1945(t3,C_SCHEME_UNDEFINED);}
else{
t3=C_fix((C_word)SHUT_WR);
t4=t2;
f_1945(t4,stub187(C_SCHEME_UNDEFINED,C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]),C_i_foreign_fixnum_argumentp(t3)));}}

/* k1943 in k1940 in a1933 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_1945(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_1945,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1951,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)((C_word*)t0)[4])[1])){
t3=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
t4=t2;
f_1951(t4,C_eqp(C_fix((C_word)SOCKET_ERROR),stub168(C_SCHEME_UNDEFINED,t3)));}
else{
t3=t2;
f_1951(t3,C_SCHEME_FALSE);}}

/* k1949 in k1943 in k1940 in a1933 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_1951(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_1951,2,t0,t1);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1958,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1962,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t3;
av2[2]=lf[51];
av2[3]=lf[13];
tp(4,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k1956 in k1949 in k1943 in k1940 in a1933 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1958(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_1958,c,av);}
/* tcp.scm:532: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k1960 in k1949 in k1943 in k1940 in a1933 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1962(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1962,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1966,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k1964 in k1960 in k1949 in k1943 in k1940 in a1933 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1966(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1966,c,av);}
/* tcp.scm:532: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k1989 in a1933 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_1991(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1991,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,lf[52]);
t3=((C_word*)t0)[3];
f_1942(t3,t2);}

/* f_2004 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2004(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2004,c,av);}
a=C_alloc(4);
t2=C_block_size(((C_word*)((C_word*)t0)[2])[1]);
if(C_truep(C_fixnum_greaterp(t2,C_fix(0)))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2014,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* tcp.scm:536: output */
t4=((C_word*)t0)[3];
f_1767(t4,t3,((C_word*)((C_word*)t0)[2])[1]);}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k2012 */
static void C_ccall f_2014(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2014,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,lf[53]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* f_2020 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2020(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2020,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2025,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* tcp.scm:517: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t3;
av2[2]=((C_word*)((C_word*)t0)[2])[1];
av2[3]=t2;
tp(4,av2);}}

/* k2023 */
static void C_ccall f_2025(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2025,c,av);}
a=C_alloc(4);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_block_size(((C_word*)((C_word*)t0)[2])[1]);
if(C_truep(C_fixnum_greater_or_equal_p(t3,((C_word*)t0)[3]))){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2034,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* tcp.scm:519: output */
t5=((C_word*)t0)[5];
f_1767(t5,t4,((C_word*)((C_word*)t0)[2])[1]);}
else{
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k2032 in k2023 */
static void C_ccall f_2034(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2034,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,lf[50]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* f_2040 in k1764 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2040(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2040,c,av);}
t3=C_block_size(t2);
if(C_truep(C_fixnum_greaterp(t3,C_fix(0)))){
/* tcp.scm:523: output */
t4=((C_word*)t0)[2];
f_1767(t4,t1,t2);}
else{
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* a2055 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2056(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2056,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2060,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]))){
/* tcp.scm:404: read-input */
t3=((C_word*)t0)[5];
f_1669(t3,t2);}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_2060(2,av2);}}}

/* k2058 in a2055 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2060(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2060,c,av);}
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]))){
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_END_OF_FILE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_subchar(((C_word*)t0)[5],((C_word*)((C_word*)t0)[2])[1]);
t3=C_fixnum_plus(((C_word*)((C_word*)t0)[2])[1],C_fix(1));
t4=C_set_block_item(((C_word*)t0)[2],0,t3);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* a2077 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2078(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_2078,c,av);}
a=C_alloc(11);
t2=C_fixnum_lessp(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]);
if(C_truep(t2)){
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_foreign_fixnum_argumentp(((C_word*)t0)[4]);
t4=stub204(C_SCHEME_UNDEFINED,t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2091,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=C_eqp(C_fix((C_word)SOCKET_ERROR),t4);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2104,a[2]=t5,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2108,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t8;
av2[2]=lf[55];
av2[3]=lf[13];
tp(4,av2);}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_eqp(t4,C_fix(1));
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}}

/* k2089 in a2077 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2091(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2091,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(((C_word*)t0)[3],C_fix(1));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2102 in a2077 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2104(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2104,c,av);}
/* tcp.scm:416: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k2106 in a2077 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2108(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2108,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2112,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2110 in k2106 in a2077 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2112(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2112,c,av);}
/* tcp.scm:416: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* a2119 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2120(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_2120,c,av);}
a=C_alloc(5);
if(C_truep(((C_word*)((C_word*)t0)[2])[1])){
t2=C_SCHEME_UNDEFINED;
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_TRUE);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2128,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_slot(((C_word*)t0)[5],C_fix(1)))){
t4=t3;
f_2128(t4,C_SCHEME_UNDEFINED);}
else{
t4=C_fix((C_word)SHUT_RD);
t5=t3;
f_2128(t5,stub187(C_SCHEME_UNDEFINED,C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]),C_i_foreign_fixnum_argumentp(t4)));}}}

/* k2126 in a2119 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_2128(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_2128,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2134,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)((C_word*)t0)[4])[1])){
t3=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
t4=t2;
f_2134(t4,C_eqp(C_fix((C_word)SOCKET_ERROR),stub168(C_SCHEME_UNDEFINED,t3)));}
else{
t3=t2;
f_2134(t3,C_SCHEME_FALSE);}}

/* k2132 in k2126 in a2119 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_2134(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_2134,2,t0,t1);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2141,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2145,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t3;
av2[2]=lf[56];
av2[3]=lf[13];
tp(4,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k2139 in k2132 in k2126 in a2119 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2141(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2141,c,av);}
/* tcp.scm:423: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k2143 in k2132 in k2126 in a2119 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2145(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2145,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2149,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2147 in k2143 in k2132 in k2126 in a2119 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2149(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2149,c,av);}
/* tcp.scm:423: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* a2169 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2170(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2170,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2174,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]))){
/* tcp.scm:426: read-input */
t3=((C_word*)t0)[5];
f_1669(t3,t2);}
else{
t3=C_fixnum_lessp(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?C_subchar(((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]):C_SCHEME_END_OF_FILE);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k2172 in a2169 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2174(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2174,c,av);}
t2=C_fixnum_lessp(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?C_subchar(((C_word*)t0)[5],((C_word*)((C_word*)t0)[2])[1]):C_SCHEME_END_OF_FILE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a2187 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2188(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,5)))){
C_save_and_reclaim((void *)f_2188,c,av);}
a=C_alloc(11);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2194,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t4,a[6]=t7,a[7]=((C_word*)t0)[5],a[8]=((C_word)li19),tmp=(C_word)a,a+=9,tmp));
t9=((C_word*)t7)[1];
f_2194(t9,t1,t3,C_fix(0),t5);}

/* loop in a2187 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_2194(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_2194,5,t0,t1,t2,t3,t4);}
a=C_alloc(8);
t5=C_eqp(t2,C_fix(0));
if(C_truep(t5)){
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
if(C_truep(C_fixnum_lessp(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]))){
t6=C_fixnum_difference(((C_word*)((C_word*)t0)[3])[1],((C_word*)((C_word*)t0)[2])[1]);
t7=C_fixnum_lessp(t2,t6);
t8=(C_truep(t7)?t2:t6);
t9=C_fixnum_plus(((C_word*)((C_word*)t0)[2])[1],t8);
t10=C_substring_copy(((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)((C_word*)t0)[2])[1],t9,t4);
t11=C_fixnum_plus(((C_word*)((C_word*)t0)[2])[1],t8);
t12=C_set_block_item(((C_word*)t0)[2],0,t11);
/* tcp.scm:438: loop */
t14=t1;
t15=C_fixnum_difference(t2,t8);
t16=C_fixnum_plus(t3,t8);
t17=C_fixnum_plus(t4,t8);
t1=t14;
t2=t15;
t3=t16;
t4=t17;
goto loop;}
else{
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2242,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t3,a[5]=((C_word*)t0)[6],a[6]=t2,a[7]=t4,tmp=(C_word)a,a+=8,tmp);
/* tcp.scm:440: read-input */
t7=((C_word*)t0)[7];
f_1669(t7,t6);}}}

/* k2240 in loop in a2187 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2242(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2242,c,av);}
t2=C_eqp(((C_word*)((C_word*)t0)[2])[1],C_fix(0));
if(C_truep(t2)){
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* tcp.scm:443: loop */
t3=((C_word*)((C_word*)t0)[5])[1];
f_2194(t3,((C_word*)t0)[3],((C_word*)t0)[6],((C_word*)t0)[4],((C_word*)t0)[7]);}}

/* a2252 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2253(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_2253,c,av);}
a=C_alloc(9);
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2257,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t3,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=t2,tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]))){
/* tcp.scm:446: read-input */
t5=((C_word*)t0)[5];
f_1669(t5,t4);}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_2257(2,av2);}}}

/* k2255 in a2252 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2257(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,5)))){
C_save_and_reclaim((void *)f_2257,c,av);}
a=C_alloc(15);
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]))){
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_END_OF_FILE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(C_truep(((C_word*)t0)[5])?((C_word*)t0)[5]:C_fixnum_difference(*((C_word*)lf[57]+1),((C_word*)((C_word*)t0)[2])[1]));
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2271,a[2]=((C_word*)t0)[2],a[3]=t4,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word)li22),tmp=(C_word)a,a+=8,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2327,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[2],a[4]=((C_word)li23),tmp=(C_word)a,a+=5,tmp);
/* tcp.scm:450: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=t5;
av2[3]=t6;
C_call_with_values(4,av2);}}}

/* a2270 in k2255 in a2252 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2271(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_2271,c,av);}
a=C_alloc(8);
t2=C_fixnum_plus(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]);
t3=C_i_fixnum_min(((C_word*)((C_word*)t0)[4])[1],t2);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2281,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word)li21),tmp=(C_word)a,a+=8,tmp);
/* tcp.scm:451: ##sys#scan-buffer-line */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[58]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[58]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[5];
av2[3]=t3;
av2[4]=((C_word*)((C_word*)t0)[2])[1];
av2[5]=t4;
tp(6,av2);}}

/* a2280 in a2270 in k2255 in a2252 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2281(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_2281,c,av);}
a=C_alloc(8);
t3=C_fixnum_difference(t2,((C_word*)((C_word*)t0)[2])[1]);
if(C_truep(C_fixnum_greater_or_equal_p(t3,((C_word*)((C_word*)t0)[3])[1]))){
/* tcp.scm:458: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t1;
av2[2]=C_SCHEME_FALSE;
av2[3]=t2;
av2[4]=C_SCHEME_FALSE;
C_values(5,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2297,a[2]=((C_word*)t0)[3],a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],a[6]=t1,a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
/* tcp.scm:459: read-input */
t5=((C_word*)t0)[6];
f_1669(t5,t4);}}

/* k2295 in a2280 in a2270 in k2255 in a2252 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2297(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2297,c,av);}
t2=C_fixnum_difference(((C_word*)((C_word*)t0)[2])[1],((C_word*)t0)[3]);
t3=C_set_block_item(((C_word*)t0)[2],0,t2);
if(C_truep(C_fixnum_lessp(((C_word*)((C_word*)t0)[4])[1],((C_word*)((C_word*)t0)[5])[1]))){
t4=C_fixnum_plus(((C_word*)((C_word*)t0)[4])[1],((C_word*)((C_word*)t0)[2])[1]);
/* tcp.scm:462: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[6];
av2[2]=((C_word*)t0)[7];
av2[3]=((C_word*)((C_word*)t0)[4])[1];
av2[4]=C_i_fixnum_min(((C_word*)((C_word*)t0)[5])[1],t4);
C_values(5,av2);}}
else{
/* tcp.scm:465: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[6];
av2[2]=C_SCHEME_FALSE;
av2[3]=((C_word*)((C_word*)t0)[4])[1];
av2[4]=C_SCHEME_FALSE;
C_values(5,av2);}}}

/* a2326 in k2255 in a2252 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2327(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2327,c,av);}
if(C_truep(t4)){
t5=C_slot(((C_word*)t0)[2],C_fix(4));
t6=C_fixnum_plus(t5,C_fix(1));
t7=C_i_set_i_slot(((C_word*)t0)[2],C_fix(4),t6);
t8=C_i_set_i_slot(((C_word*)t0)[2],C_fix(5),C_fix(0));
t9=C_mutate(((C_word *)((C_word*)t0)[3])+1,t2);
t10=t1;{
C_word *av2=av;
av2[0]=t10;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t5=C_slot(((C_word*)t0)[2],C_fix(5));
t6=C_block_size(t3);
t7=C_fixnum_plus(t5,t6);
t8=C_i_set_i_slot(((C_word*)t0)[2],C_fix(5),t7);
t9=C_mutate(((C_word *)((C_word*)t0)[3])+1,t2);
t10=t1;{
C_word *av2=av;
av2[0]=t10;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}}

/* a2371 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2372(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_2372,c,av);}
a=C_alloc(5);
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]))){
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=lf[59];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2382,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* tcp.scm:478: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[60]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[60]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)((C_word*)t0)[2])[1];
av2[4]=((C_word*)((C_word*)t0)[3])[1];
tp(5,av2);}}}

/* k2380 in a2371 in k1666 in k1663 in k1657 in k1654 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2382(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2382,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)((C_word*)t0)[3])[1]);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k2401 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2403(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2403,c,av);}
/* tcp.scm:365: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k2405 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2407(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2407,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2411,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
/* tcp.scm:171: ##sys#peek-c-string */
t5=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=stub113(t3,t4);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2409 in k2405 in chicken.tcp#io-ports in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2411(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2411,c,av);}
/* tcp.scm:365: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* chicken.tcp#tcp-accept in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2415(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_2415,c,av);}
a=C_alloc(5);
t3=C_i_check_structure(t2,lf[5]);
t4=C_slot(t2,C_fix(1));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2425,a[2]=t4,a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* tcp.scm:549: tcp-accept-timeout */
t6=*((C_word*)lf[31]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k2423 in chicken.tcp#tcp-accept in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2425(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_2425,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2428,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2508,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* tcp.scm:550: chicken.time#current-process-milliseconds */
t4=*((C_word*)lf[42]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=t2;
f_2428(t3,C_SCHEME_FALSE);}}

/* k2426 in k2423 in chicken.tcp#tcp-accept in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_2428(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_2428,2,t0,t1);}
a=C_alloc(10);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2433,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=t1,a[7]=((C_word)li27),tmp=(C_word)a,a+=8,tmp));
t5=((C_word*)t3)[1];{
C_word av2[2];
av2[0]=t5;
av2[1]=((C_word*)t0)[5];
f_2433(2,av2);}}

/* loop in k2426 in k2423 in chicken.tcp#tcp-accept in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2433(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_2433,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2437,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)t0)[6])){
/* tcp.scm:553: ##sys#thread-block-for-timeout! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[39]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[39]+1);
av2[1]=t2;
av2[2]=*((C_word*)lf[33]+1);
av2[3]=((C_word*)t0)[6];
tp(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_2437(2,av2);}}}

/* k2435 in loop in k2426 in k2423 in chicken.tcp#tcp-accept in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2437(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_2437,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2440,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* tcp.scm:554: ##sys#thread-block-for-i/o! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[37]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[37]+1);
av2[1]=t2;
av2[2]=*((C_word*)lf[33]+1);
av2[3]=((C_word*)t0)[2];
av2[4]=lf[38];
tp(5,av2);}}

/* k2438 in k2435 in loop in k2426 in k2423 in chicken.tcp#tcp-accept in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2440(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_2440,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2443,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* tcp.scm:555: ##sys#thread-yield! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[36]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[36]+1);
av2[1]=t2;
tp(2,av2);}}

/* k2441 in k2438 in k2435 in loop in k2426 in k2423 in chicken.tcp#tcp-accept in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2443(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,6)))){
C_save_and_reclaim((void *)f_2443,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2446,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_slot(*((C_word*)lf[33]+1),C_fix(13)))){
/* tcp.scm:557: ##sys#signal-hook */
t3=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[34];
av2[3]=lf[65];
av2[4]=lf[67];
av2[5]=((C_word*)t0)[6];
av2[6]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_2446(2,av2);}}}

/* k2444 in k2441 in k2438 in k2435 in loop in k2426 in k2423 in chicken.tcp#tcp-accept in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2446(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_2446,c,av);}
a=C_alloc(7);
t2=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t3=stub157(C_SCHEME_UNDEFINED,t2,C_SCHEME_FALSE,C_SCHEME_FALSE);
t4=C_eqp(C_fix((C_word)INVALID_SOCKET),t3);
if(C_truep(C_i_not(t4))){
/* tcp.scm:563: io-ports */
t5=lf[32];
f_1652(t5,((C_word*)t0)[3],lf[65],t3);}
else{
if(C_truep(stub124(C_SCHEME_UNDEFINED))){
/* tcp.scm:565: ##sys#dispatch-interrupt */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[40]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[40]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)((C_word*)t0)[4])[1];
tp(3,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2474,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2478,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t6;
av2[2]=lf[66];
av2[3]=lf[13];
tp(4,av2);}}}}

/* k2472 in k2444 in k2441 in k2438 in k2435 in loop in k2426 in k2423 in chicken.tcp#tcp-accept in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2474(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2474,c,av);}
/* tcp.scm:567: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[65];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k2476 in k2444 in k2441 in k2438 in k2435 in loop in k2426 in k2423 in chicken.tcp#tcp-accept in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2478(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2478,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2482,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2480 in k2476 in k2444 in k2441 in k2438 in k2435 in loop in k2426 in k2423 in chicken.tcp#tcp-accept in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2482(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2482,c,av);}
/* tcp.scm:567: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k2506 in k2423 in chicken.tcp#tcp-accept in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2508(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,1)))){
C_save_and_reclaim((void *)f_2508,c,av);}
a=C_alloc(29);
t2=((C_word*)t0)[2];
f_2428(t2,C_s_a_i_plus(&a,2,((C_word*)t0)[3],t1));}

/* chicken.tcp#tcp-accept-ready? in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2510(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_2510,c,av);}
a=C_alloc(11);
t3=C_i_check_structure_2(t2,lf[5],lf[69]);
t4=C_slot(t2,C_fix(1));
t5=C_i_foreign_fixnum_argumentp(t4);
t6=stub204(C_SCHEME_UNDEFINED,t5);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2520,a[2]=t1,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
t8=C_eqp(C_fix((C_word)SOCKET_ERROR),t6);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2533,a[2]=t7,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2537,a[2]=t9,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t10;
av2[2]=lf[70];
av2[3]=lf[13];
tp(4,av2);}}
else{
t9=t1;{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_eqp(C_fix(1),t6);
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}

/* k2518 in chicken.tcp#tcp-accept-ready? in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2520(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2520,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(C_fix(1),((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2531 in chicken.tcp#tcp-accept-ready? in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2533(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2533,c,av);}
/* tcp.scm:574: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[69];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k2535 in chicken.tcp#tcp-accept-ready? in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2537(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2537,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2541,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2539 in k2535 in chicken.tcp#tcp-accept-ready? in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2541(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2541,c,av);}
/* tcp.scm:574: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2560(C_word c,C_word *av){
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
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_2560,c,av);}
a=C_alloc(9);
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_rest_nullp(c,3);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2567,a[2]=t3,a[3]=t1,a[4]=t7,tmp=(C_word)a,a+=5,tmp);
/* tcp.scm:587: tcp-connect-timeout */
t9=*((C_word*)lf[30]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}

/* k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2567(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_2567,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2570,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2835,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* tcp.scm:588: chicken.time#current-process-milliseconds */
t4=*((C_word*)lf[42]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=t2;
f_2570(t3,C_SCHEME_FALSE);}}

/* k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_2570(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_2570,2,t0,t1);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2573,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=C_fix((C_word)sizeof(struct sockaddr_in));
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[19]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[19]+1);
av2[1]=t2;
av2[2]=t3;
av2[3]=C_make_character(32);
tp(4,av2);}}

/* k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2573(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,4)))){
C_save_and_reclaim((void *)f_2573,c,av);}
a=C_alloc(21);
t2=C_i_check_string(((C_word*)((C_word*)t0)[2])[1]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2579,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)((C_word*)t0)[5])[1])){
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_2579(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2810,a[2]=((C_word*)t0)[5],a[3]=t3,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2818,a[2]=((C_word*)t0)[2],a[3]=((C_word)li32),tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2824,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[5],a[4]=((C_word)li33),tmp=(C_word)a,a+=5,tmp);
/* tcp.scm:592: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t4;
av2[2]=t5;
av2[3]=t6;
C_call_with_values(4,av2);}}}

/* k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2579(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_2579,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2582,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* tcp.scm:594: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[20]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[20]+1);
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[6])[1];
tp(3,av2);}}

/* k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2582(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_2582,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2585,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2804,a[2]=t2,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* tcp.scm:595: gethostaddr */
f_1253(t3,((C_word*)t0)[3],((C_word*)((C_word*)t0)[5])[1],((C_word*)((C_word*)t0)[6])[1]);}

/* k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2585(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_2585,c,av);}
a=C_alloc(16);
t2=C_fix((C_word)AF_INET);
t3=C_fix((C_word)SOCK_STREAM);
t4=stub130(C_SCHEME_UNDEFINED,C_i_foreign_fixnum_argumentp(t2),C_i_foreign_fixnum_argumentp(t3),C_fix(0));
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2591,a[2]=t4,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t6=C_eqp(C_fix((C_word)INVALID_SOCKET),t4);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2787,a[2]=t5,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2791,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t8;
av2[2]=lf[78];
av2[3]=lf[13];
tp(4,av2);}}
else{
t7=t5;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_UNDEFINED;
f_2591(2,av2);}}}

/* k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2591(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_2591,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2594,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t3=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t4=C_eqp(C_fix((C_word)SOCKET_ERROR),stub209(C_SCHEME_UNDEFINED,t3));
if(C_truep(t4)){
t5=stub109(C_SCHEME_UNDEFINED);
t6=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t7=stub168(C_SCHEME_UNDEFINED,t6);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2763,a[2]=t2,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2767,a[2]=t8,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t9;
av2[2]=lf[77];
av2[3]=lf[13];
tp(4,av2);}}
else{
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_2594(2,av2);}}}

/* k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2594(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2594,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2597,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
if(C_truep(make_socket_nonblocking(((C_word*)t0)[2]))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_2597(2,av2);}}
else{
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t5=stub168(C_SCHEME_UNDEFINED,t4);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2737,a[2]=t2,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2741,a[2]=t6,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t7;
av2[2]=lf[76];
av2[3]=lf[13];
tp(4,av2);}}}

/* k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2597(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_2597,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2600,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2663,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=t4,a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word)li30),tmp=(C_word)a,a+=9,tmp));
t6=((C_word*)t4)[1];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t2;
f_2663(2,av2);}}

/* k2598 in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2600(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_2600,c,av);}
a=C_alloc(12);
t2=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t3=stub685(C_SCHEME_UNDEFINED,t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2606,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t5=C_eqp(C_fix((C_word)SOCKET_ERROR),t3);
if(C_truep(t5)){
t6=stub109(C_SCHEME_UNDEFINED);
t7=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t8=stub168(C_SCHEME_UNDEFINED,t7);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2625,a[2]=t4,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2629,a[2]=t9,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t10;
av2[2]=lf[73];
av2[3]=lf[13];
tp(4,av2);}}
else{
if(C_truep(C_fixnum_greaterp(t3,C_fix(0)))){
t6=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t7=stub168(C_SCHEME_UNDEFINED,t6);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2651,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2655,a[2]=t8,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t9;
av2[2]=lf[74];
av2[3]=lf[13];
tp(4,av2);}}
else{
/* tcp.scm:622: io-ports */
t6=lf[32];
f_1652(t6,((C_word*)t0)[3],lf[72],((C_word*)t0)[2]);}}}

/* k2604 in k2598 in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2606(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2606,c,av);}
/* tcp.scm:622: io-ports */
t2=lf[32];
f_1652(t2,((C_word*)t0)[2],lf[72],((C_word*)t0)[3]);}

/* k2623 in k2598 in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2625(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2625,c,av);}
/* tcp.scm:618: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[72];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k2627 in k2598 in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2629(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2629,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2633,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
/* tcp.scm:171: ##sys#peek-c-string */
t5=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=stub113(t3,t4);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2631 in k2627 in k2598 in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 in ... */
static void C_ccall f_2633(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2633,c,av);}
/* tcp.scm:618: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k2649 in k2598 in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2651(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2651,c,av);}
/* tcp.scm:621: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[72];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k2653 in k2598 in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2655(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2655,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2659,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
/* tcp.scm:171: ##sys#peek-c-string */
t5=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=stub113(t3,t4);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2657 in k2653 in k2598 in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 in ... */
static void C_ccall f_2659(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2659,c,av);}
/* tcp.scm:621: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* loop in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2663(C_word c,C_word *av){
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
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_2663,c,av);}
a=C_alloc(10);
t2=C_fix((C_word)sizeof(struct sockaddr_in));
t3=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t4=(C_truep(((C_word*)t0)[3])?C_i_foreign_block_argumentp(((C_word*)t0)[3]):C_SCHEME_FALSE);
t5=C_i_foreign_fixnum_argumentp(t2);
t6=C_eqp(C_fix((C_word)SOCKET_ERROR),stub195(C_SCHEME_UNDEFINED,t3,t4,t5));
if(C_truep(t6)){
if(C_truep(stub121(C_SCHEME_UNDEFINED))){
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2679,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)t0)[4])){
/* tcp.scm:608: ##sys#thread-block-for-timeout! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[39]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[39]+1);
av2[1]=t7;
av2[2]=*((C_word*)lf[33]+1);
av2[3]=((C_word*)t0)[4];
tp(4,av2);}}
else{
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f3431,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* tcp.scm:609: ##sys#thread-block-for-i/o! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[37]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[37]+1);
av2[1]=t8;
av2[2]=*((C_word*)lf[33]+1);
av2[3]=((C_word*)t0)[2];
av2[4]=lf[44];
tp(5,av2);}}}
else{
if(C_truep(stub124(C_SCHEME_UNDEFINED))){
/* tcp.scm:612: ##sys#dispatch-interrupt */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[40]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[40]+1);
av2[1]=t1;
av2[2]=((C_word*)((C_word*)t0)[5])[1];
tp(3,av2);}}
else{
t7=stub109(C_SCHEME_UNDEFINED);
t8=C_i_foreign_fixnum_argumentp(((C_word*)t0)[2]);
t9=stub168(C_SCHEME_UNDEFINED,t8);
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2710,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],tmp=(C_word)a,a+=6,tmp);
t11=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2714,a[2]=t10,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t11;
av2[2]=lf[75];
av2[3]=lf[13];
tp(4,av2);}}}}
else{
t7=C_SCHEME_UNDEFINED;
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k2677 in loop in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2679(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_2679,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2682,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* tcp.scm:609: ##sys#thread-block-for-i/o! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[37]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[37]+1);
av2[1]=t2;
av2[2]=*((C_word*)lf[33]+1);
av2[3]=((C_word*)t0)[3];
av2[4]=lf[44];
tp(5,av2);}}

/* k2680 in k2677 in loop in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 in ... */
static void C_ccall f_2682(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2682,c,av);}
/* tcp.scm:610: ##sys#thread-yield! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[36]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[36]+1);
av2[1]=((C_word*)t0)[2];
tp(2,av2);}}

/* k2708 in loop in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2710(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_2710,c,av);}
/* tcp.scm:614: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[72];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)((C_word*)t0)[4])[1];
av2[7]=((C_word*)((C_word*)t0)[5])[1];
((C_proc)(void*)(*((C_word*)t2+1)))(8,av2);}}

/* k2712 in loop in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2714(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2714,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2718,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
/* tcp.scm:171: ##sys#peek-c-string */
t5=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=stub113(t3,t4);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2716 in k2712 in loop in k2595 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 in ... */
static void C_ccall f_2718(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2718,c,av);}
/* tcp.scm:614: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k2735 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2737(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2737,c,av);}
/* tcp.scm:603: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[72];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k2739 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2741(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2741,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2745,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
/* tcp.scm:171: ##sys#peek-c-string */
t5=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=stub113(t3,t4);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2743 in k2739 in k2592 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2745(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2745,c,av);}
/* tcp.scm:603: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k2761 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2763(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2763,c,av);}
/* tcp.scm:601: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[72];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k2765 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2767(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2767,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2771,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=C_i_foreign_fixnum_argumentp(((C_word*)t0)[3]);
/* tcp.scm:171: ##sys#peek-c-string */
t5=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=stub113(t3,t4);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2769 in k2765 in k2589 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2771(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2771,c,av);}
/* tcp.scm:601: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k2785 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2787(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_2787,c,av);}
/* tcp.scm:599: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[72];
av2[4]=t1;
av2[5]=((C_word*)((C_word*)t0)[3])[1];
av2[6]=((C_word*)((C_word*)t0)[4])[1];
((C_proc)(void*)(*((C_word*)t2+1)))(7,av2);}}

/* k2789 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2791(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2791,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2795,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2793 in k2789 in k2583 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2795(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2795,c,av);}
/* tcp.scm:599: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k2802 in k2580 in k2577 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2804(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2804,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_2585(2,av2);}}
else{
/* tcp.scm:596: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[72];
av2[4]=lf[79];
av2[5]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}

/* k2808 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2810(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2810,c,av);}
if(C_truep(((C_word*)((C_word*)t0)[2])[1])){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_2579(2,av2);}}
else{
/* tcp.scm:593: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[21];
av2[3]=lf[72];
av2[4]=lf[80];
av2[5]=((C_word*)((C_word*)t0)[4])[1];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}

/* a2817 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2818(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2818,c,av);}
a=C_alloc(9);
t2=((C_word*)((C_word*)t0)[2])[1];
t3=lf[81];
t4=C_block_size(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1285,a[2]=t4,a[3]=t2,a[4]=t3,a[5]=t6,a[6]=((C_word)li31),tmp=(C_word)a,a+=7,tmp));
t8=((C_word*)t6)[1];
f_1285(t8,t1,C_fix(0));}

/* a2823 in k2571 in k2568 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2824(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2824,c,av);}
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=C_mutate(((C_word *)((C_word*)t0)[3])+1,t3);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k2833 in k2565 in chicken.tcp#tcp-connect in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2835(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,1)))){
C_save_and_reclaim((void *)f_2835,c,av);}
a=C_alloc(29);
t2=((C_word*)t0)[2];
f_2570(t2,C_s_a_i_plus(&a,2,t1,((C_word*)t0)[3]));}

/* chicken.tcp#tcp-port->fileno in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_fcall f_2843(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_2843,3,t1,t2,t3);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2847,a[2]=t1,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* tcp.scm:625: ##sys#port-data */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[87]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[87]+1);
av2[1]=t4;
av2[2]=t2;
tp(3,av2);}}

/* k2845 in chicken.tcp#tcp-port->fileno in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2847(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2847,c,av);}
if(C_truep(C_i_vectorp(t1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_slot(t1,C_fix(0));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* tcp.scm:628: chicken.base#error */
t2=*((C_word*)lf[85]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[86];
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* chicken.tcp#tcp-addresses in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2861(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2861,c,av);}
a=C_alloc(4);
t3=C_i_check_port_2(t2,C_fix(0),C_SCHEME_TRUE,lf[89]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2867,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* tcp.scm:632: tcp-port->fileno */
f_2843(t4,t2,lf[89]);}

/* k2865 in chicken.tcp#tcp-addresses in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2867(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_2867,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2874,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=C_i_foreign_fixnum_argumentp(t1);
/* tcp.scm:192: ##sys#peek-c-string */
t5=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=stub229(t3,t4);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2872 in k2865 in chicken.tcp#tcp-addresses in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2874(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_2874,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2877,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
f_2877(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2912,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2916,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t4;
av2[2]=lf[91];
av2[3]=lf[13];
tp(4,av2);}}}

/* k2875 in k2872 in k2865 in chicken.tcp#tcp-addresses in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2877(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_2877,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2881,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=C_i_foreign_fixnum_argumentp(((C_word*)t0)[4]);
/* tcp.scm:216: ##sys#peek-c-string */
t5=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=stub245(t3,t4);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2879 in k2875 in k2872 in k2865 in chicken.tcp#tcp-addresses in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2881(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_2881,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2884,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t1)){
/* tcp.scm:633: scheme#values */{
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
C_values(4,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2891,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2895,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t4;
av2[2]=lf[90];
av2[3]=lf[13];
tp(4,av2);}}}

/* k2882 in k2879 in k2875 in k2872 in k2865 in chicken.tcp#tcp-addresses in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2884(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2884,c,av);}
/* tcp.scm:633: scheme#values */{
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
C_values(4,av2);}}

/* k2889 in k2879 in k2875 in k2872 in k2865 in chicken.tcp#tcp-addresses in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2891(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2891,c,av);}
/* tcp.scm:637: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[89];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k2893 in k2879 in k2875 in k2872 in k2865 in chicken.tcp#tcp-addresses in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2895(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2895,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2899,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2897 in k2893 in k2879 in k2875 in k2872 in k2865 in chicken.tcp#tcp-addresses in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2899(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2899,c,av);}
/* tcp.scm:637: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k2910 in k2872 in k2865 in chicken.tcp#tcp-addresses in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2912(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2912,c,av);}
/* tcp.scm:635: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[89];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k2914 in k2872 in k2865 in chicken.tcp#tcp-addresses in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2916(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2916,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2920,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2918 in k2914 in k2872 in k2865 in chicken.tcp#tcp-addresses in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2920(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2920,c,av);}
/* tcp.scm:635: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* chicken.tcp#tcp-port-numbers in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2928(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2928,c,av);}
a=C_alloc(4);
t3=C_i_check_port_2(t2,C_fix(0),C_SCHEME_TRUE,lf[93]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2934,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* tcp.scm:641: tcp-port->fileno */
f_2843(t4,t2,lf[93]);}

/* k2932 in chicken.tcp#tcp-port-numbers in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2934(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_2934,c,av);}
a=C_alloc(13);
t2=C_i_foreign_fixnum_argumentp(t1);
t3=stub235(C_SCHEME_UNDEFINED,t2);
t4=C_i_foreign_fixnum_argumentp(t1);
t5=stub240(C_SCHEME_UNDEFINED,t4);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2943,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=t5,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t7=C_eqp(C_fix(-1),t3);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2983,a[2]=t6,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2987,a[2]=t8,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t9;
av2[2]=lf[95];
av2[3]=lf[13];
tp(4,av2);}}
else{
t8=t6;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_UNDEFINED;
f_2943(2,av2);}}}

/* k2941 in k2932 in chicken.tcp#tcp-port-numbers in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2943(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2943,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2946,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_eqp(C_fix(-1),((C_word*)t0)[4]);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2959,a[2]=t2,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2963,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t5;
av2[2]=lf[94];
av2[3]=lf[13];
tp(4,av2);}}
else{
/* tcp.scm:648: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
C_values(4,av2);}}}

/* k2944 in k2941 in k2932 in chicken.tcp#tcp-port-numbers in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2946(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2946,c,av);}
/* tcp.scm:648: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
C_values(4,av2);}}

/* k2957 in k2941 in k2932 in chicken.tcp#tcp-port-numbers in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2959(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2959,c,av);}
/* tcp.scm:647: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[93];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k2961 in k2941 in k2932 in chicken.tcp#tcp-port-numbers in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2963(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2963,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2967,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2965 in k2961 in k2941 in k2932 in chicken.tcp#tcp-port-numbers in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2967(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2967,c,av);}
/* tcp.scm:647: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* k2981 in k2932 in chicken.tcp#tcp-port-numbers in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2983(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2983,c,av);}
/* tcp.scm:645: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[93];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k2985 in k2932 in chicken.tcp#tcp-port-numbers in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2987(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2987,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2991,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2989 in k2985 in k2932 in chicken.tcp#tcp-port-numbers in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2991(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2991,c,av);}
/* tcp.scm:645: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* chicken.tcp#tcp-listener-port in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_2999(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_2999,c,av);}
a=C_alloc(12);
t3=C_i_check_structure_2(t2,lf[5],lf[97]);
t4=C_slot(t2,C_fix(1));
t5=C_i_foreign_fixnum_argumentp(t4);
t6=stub235(C_SCHEME_UNDEFINED,t5);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3012,a[2]=t1,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
t8=C_eqp(C_fix(-1),t6);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3022,a[2]=t7,a[3]=t2,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3026,a[2]=t9,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[11]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t10;
av2[2]=lf[98];
av2[3]=lf[13];
tp(4,av2);}}
else{
t9=t1;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}

/* k3010 in chicken.tcp#tcp-listener-port in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_3012(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3012,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3020 in chicken.tcp#tcp-listener-port in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_3022(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_3022,c,av);}
/* tcp.scm:655: ##sys#signal-hook */
t2=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=lf[97];
av2[4]=t1;
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(7,av2);}}

/* k3024 in chicken.tcp#tcp-listener-port in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_3026(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3026,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3030,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=stub109(C_SCHEME_UNDEFINED);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=C_i_foreign_fixnum_argumentp(t3);
/* tcp.scm:171: ##sys#peek-c-string */
t6=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub113(t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k3028 in k3024 in chicken.tcp#tcp-listener-port in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_3030(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3030,c,av);}
/* tcp.scm:655: scheme#string-append */
t2=*((C_word*)lf[9]+1);{
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

/* chicken.tcp#tcp-abandon-port in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_3038(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3038,c,av);}
a=C_alloc(4);
t3=C_i_check_port_2(t2,C_fix(0),C_SCHEME_TRUE,lf[100]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3048,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* tcp.scm:660: ##sys#port-data */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[87]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[87]+1);
av2[1]=t4;
av2[2]=t2;
tp(3,av2);}}

/* k3046 in chicken.tcp#tcp-abandon-port in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_3048(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3048,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_set_i_slot(t1,C_slot(((C_word*)t0)[3],C_fix(1)),C_SCHEME_TRUE);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.tcp#tcp-listener-fileno in k1648 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_3054(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3054,c,av);}
t3=C_i_check_structure_2(t2,lf[5],lf[102]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k3063 in k1644 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_3065(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3065,c,av);}
/* tcp.scm:359: chicken.base#make-parameter */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_FALSE;
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k3067 in k1640 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_3069(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3069,c,av);}
/* tcp.scm:358: chicken.base#make-parameter */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_FALSE;
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k3071 in k1636 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_3073(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3073,c,av);}
/* tcp.scm:357: chicken.base#make-parameter */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k3075 in k1613 in k1224 in k996 in k993 in k990 */
static void C_ccall f_3077(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3077,c,av);}
/* tcp.scm:356: chicken.base#make-parameter */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k990 */
static void C_ccall f_992(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_992,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_995,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_scheduler_toplevel(2,av2);}}

/* k993 in k990 */
static void C_ccall f_995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_995,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_998,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

/* k996 in k993 in k990 */
static void C_ccall f_998(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_998,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1226,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(stub250(C_SCHEME_UNDEFINED))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_1226(2,av2);}}
else{
/* tcp.scm:237: ##sys#signal-hook */
t3=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[7];
av2[3]=lf[108];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_tcp_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("tcp"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_tcp_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(441))){
C_save(t1);
C_rereclaim2(441*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,109);
lf[0]=C_h_intern(&lf[0],3, C_text("tcp"));
lf[1]=C_h_intern(&lf[1],12, C_text("chicken.tcp#"));
lf[3]=C_h_intern(&lf[3],19, C_text("##sys#make-c-string"));
lf[4]=C_h_intern(&lf[4],22, C_text("chicken.tcp#tcp-listen"));
lf[5]=C_h_intern(&lf[5],12, C_text("tcp-listener"));
lf[6]=C_h_intern(&lf[6],17, C_text("##sys#signal-hook"));
lf[7]=C_h_intern_kw(&lf[7],13, C_text("network-error"));
lf[8]=C_h_intern(&lf[8],10, C_text("tcp-listen"));
lf[9]=C_h_intern(&lf[9],20, C_text("scheme#string-append"));
lf[10]=C_h_intern(&lf[10],19, C_text("##sys#peek-c-string"));
lf[11]=C_h_intern(&lf[11],19, C_text("##sys#string-append"));
lf[12]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027cannot listen on socket"));
lf[13]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003 - "));
lf[14]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025cannot bind to socket"));
lf[15]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035error while setting up socket"));
lf[16]=C_h_intern(&lf[16],11, C_text("##sys#error"));
lf[17]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024cannot create socket"));
lf[18]=C_decode_literal(C_heaptop,C_text("\376B\000\000\037getting listener host IP failed"));
lf[19]=C_h_intern(&lf[19],17, C_text("##sys#make-string"));
lf[20]=C_h_intern(&lf[20],18, C_text("##sys#check-fixnum"));
lf[21]=C_h_intern_kw(&lf[21],12, C_text("domain-error"));
lf[22]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023invalid port number"));
lf[23]=C_h_intern(&lf[23],25, C_text("chicken.tcp#tcp-listener\077"));
lf[24]=C_h_intern(&lf[24],21, C_text("chicken.tcp#tcp-close"));
lf[25]=C_h_intern(&lf[25],9, C_text("tcp-close"));
lf[26]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027cannot close TCP socket"));
lf[27]=C_h_intern(&lf[27],27, C_text("chicken.tcp#tcp-buffer-size"));
lf[28]=C_h_intern(&lf[28],28, C_text("chicken.tcp#tcp-read-timeout"));
lf[29]=C_h_intern(&lf[29],29, C_text("chicken.tcp#tcp-write-timeout"));
lf[30]=C_h_intern(&lf[30],31, C_text("chicken.tcp#tcp-connect-timeout"));
lf[31]=C_h_intern(&lf[31],30, C_text("chicken.tcp#tcp-accept-timeout"));
lf[33]=C_h_intern(&lf[33],20, C_text("##sys#current-thread"));
lf[34]=C_h_intern_kw(&lf[34],21, C_text("network-timeout-error"));
lf[35]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030read operation timed out"));
lf[36]=C_h_intern(&lf[36],19, C_text("##sys#thread-yield!"));
lf[37]=C_h_intern(&lf[37],27, C_text("##sys#thread-block-for-i/o!"));
lf[38]=C_h_intern_kw(&lf[38],5, C_text("input"));
lf[39]=C_h_intern(&lf[39],31, C_text("##sys#thread-block-for-timeout!"));
lf[40]=C_h_intern(&lf[40],24, C_text("##sys#dispatch-interrupt"));
lf[41]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027cannot read from socket"));
lf[42]=C_h_intern(&lf[42],41, C_text("chicken.time#current-process-milliseconds"));
lf[43]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031write operation timed out"));
lf[44]=C_h_intern_kw(&lf[44],6, C_text("output"));
lf[45]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026cannot write to socket"));
lf[46]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005(tcp)"));
lf[47]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005(tcp)"));
lf[48]=C_h_intern(&lf[48],6, C_text("socket"));
lf[49]=C_h_intern(&lf[49],20, C_text("##sys#set-port-data!"));
lf[50]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[51]=C_decode_literal(C_heaptop,C_text("\376B\000\000\037cannot close socket output port"));
lf[52]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[53]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[54]=C_h_intern(&lf[54],29, C_text("chicken.port#make-output-port"));
lf[55]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035cannot check socket for input"));
lf[56]=C_decode_literal(C_heaptop,C_text("\376B\000\000\036cannot close socket input port"));
lf[57]=C_h_intern(&lf[57],35, C_text("chicken.fixnum#most-positive-fixnum"));
lf[58]=C_h_intern(&lf[58],22, C_text("##sys#scan-buffer-line"));
lf[59]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[60]=C_h_intern(&lf[60],15, C_text("##sys#substring"));
lf[61]=C_h_intern(&lf[61],28, C_text("chicken.port#make-input-port"));
lf[62]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[63]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027cannot create TCP ports"));
lf[64]=C_h_intern(&lf[64],22, C_text("chicken.tcp#tcp-accept"));
lf[65]=C_h_intern(&lf[65],10, C_text("tcp-accept"));
lf[66]=C_decode_literal(C_heaptop,C_text("\376B\000\000\036could not accept from listener"));
lf[67]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032accept operation timed out"));
lf[68]=C_h_intern(&lf[68],29, C_text("chicken.tcp#tcp-accept-ready\077"));
lf[69]=C_h_intern(&lf[69],17, C_text("tcp-accept-ready\077"));
lf[70]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035cannot check socket for input"));
lf[71]=C_h_intern(&lf[71],23, C_text("chicken.tcp#tcp-connect"));
lf[72]=C_h_intern(&lf[72],11, C_text("tcp-connect"));
lf[73]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023getsockopt() failed"));
lf[74]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024cannot create socket"));
lf[75]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030cannot connect to socket"));
lf[76]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016fcntl() failed"));
lf[77]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035error while setting up socket"));
lf[78]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024cannot create socket"));
lf[79]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030cannot find host address"));
lf[80]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021no port specified"));
lf[81]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003tcp"));
lf[82]=C_decode_literal(C_heaptop,C_text("\376B\000\000 cannot compute port from service"));
lf[83]=C_h_intern(&lf[83],16, C_text("scheme#substring"));
lf[85]=C_h_intern(&lf[85],18, C_text("chicken.base#error"));
lf[86]=C_decode_literal(C_heaptop,C_text("\376B\000\000)argument does not appear to be a TCP port"));
lf[87]=C_h_intern(&lf[87],15, C_text("##sys#port-data"));
lf[88]=C_h_intern(&lf[88],25, C_text("chicken.tcp#tcp-addresses"));
lf[89]=C_h_intern(&lf[89],13, C_text("tcp-addresses"));
lf[90]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035cannot compute remote address"));
lf[91]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034cannot compute local address"));
lf[92]=C_h_intern(&lf[92],28, C_text("chicken.tcp#tcp-port-numbers"));
lf[93]=C_h_intern(&lf[93],16, C_text("tcp-port-numbers"));
lf[94]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032cannot compute remote port"));
lf[95]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031cannot compute local port"));
lf[96]=C_h_intern(&lf[96],29, C_text("chicken.tcp#tcp-listener-port"));
lf[97]=C_h_intern(&lf[97],17, C_text("tcp-listener-port"));
lf[98]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033cannot obtain listener port"));
lf[99]=C_h_intern(&lf[99],28, C_text("chicken.tcp#tcp-abandon-port"));
lf[100]=C_h_intern(&lf[100],16, C_text("tcp-abandon-port"));
lf[101]=C_h_intern(&lf[101],31, C_text("chicken.tcp#tcp-listener-fileno"));
lf[102]=C_h_intern(&lf[102],19, C_text("tcp-listener-fileno"));
lf[103]=C_h_intern(&lf[103],27, C_text("chicken.base#make-parameter"));
lf[104]=C_h_intern(&lf[104],18, C_text("tcp-accept-timeout"));
lf[105]=C_h_intern(&lf[105],19, C_text("tcp-connect-timeout"));
lf[106]=C_h_intern(&lf[106],17, C_text("tcp-write-timeout"));
lf[107]=C_h_intern(&lf[107],16, C_text("tcp-read-timeout"));
lf[108]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031cannot initialize Winsock"));
C_register_lf2(lf,109,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_992,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_port_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[222] = {
{C_text("f3431:tcp_2escm"),(void*)f3431},
{C_text("f_1226:tcp_2escm"),(void*)f_1226},
{C_text("f_1233:tcp_2escm"),(void*)f_1233},
{C_text("f_1237:tcp_2escm"),(void*)f_1237},
{C_text("f_1253:tcp_2escm"),(void*)f_1253},
{C_text("f_1262:tcp_2escm"),(void*)f_1262},
{C_text("f_1285:tcp_2escm"),(void*)f_1285},
{C_text("f_1308:tcp_2escm"),(void*)f_1308},
{C_text("f_1312:tcp_2escm"),(void*)f_1312},
{C_text("f_1315:tcp_2escm"),(void*)f_1315},
{C_text("f_1318:tcp_2escm"),(void*)f_1318},
{C_text("f_1328:tcp_2escm"),(void*)f_1328},
{C_text("f_1332:tcp_2escm"),(void*)f_1332},
{C_text("f_1336:tcp_2escm"),(void*)f_1336},
{C_text("f_1371:tcp_2escm"),(void*)f_1371},
{C_text("f_1374:tcp_2escm"),(void*)f_1374},
{C_text("f_1380:tcp_2escm"),(void*)f_1380},
{C_text("f_1383:tcp_2escm"),(void*)f_1383},
{C_text("f_1386:tcp_2escm"),(void*)f_1386},
{C_text("f_1402:tcp_2escm"),(void*)f_1402},
{C_text("f_1406:tcp_2escm"),(void*)f_1406},
{C_text("f_1410:tcp_2escm"),(void*)f_1410},
{C_text("f_1426:tcp_2escm"),(void*)f_1426},
{C_text("f_1430:tcp_2escm"),(void*)f_1430},
{C_text("f_1434:tcp_2escm"),(void*)f_1434},
{C_text("f_1456:tcp_2escm"),(void*)f_1456},
{C_text("f_1465:tcp_2escm"),(void*)f_1465},
{C_text("f_1481:tcp_2escm"),(void*)f_1481},
{C_text("f_1484:tcp_2escm"),(void*)f_1484},
{C_text("f_1487:tcp_2escm"),(void*)f_1487},
{C_text("f_1490:tcp_2escm"),(void*)f_1490},
{C_text("f_1493:tcp_2escm"),(void*)f_1493},
{C_text("f_1512:tcp_2escm"),(void*)f_1512},
{C_text("f_1516:tcp_2escm"),(void*)f_1516},
{C_text("f_1520:tcp_2escm"),(void*)f_1520},
{C_text("f_1564:tcp_2escm"),(void*)f_1564},
{C_text("f_1573:tcp_2escm"),(void*)f_1573},
{C_text("f_1593:tcp_2escm"),(void*)f_1593},
{C_text("f_1597:tcp_2escm"),(void*)f_1597},
{C_text("f_1601:tcp_2escm"),(void*)f_1601},
{C_text("f_1615:tcp_2escm"),(void*)f_1615},
{C_text("f_1621:tcp_2escm"),(void*)f_1621},
{C_text("f_1623:tcp_2escm"),(void*)f_1623},
{C_text("f_1627:tcp_2escm"),(void*)f_1627},
{C_text("f_1638:tcp_2escm"),(void*)f_1638},
{C_text("f_1642:tcp_2escm"),(void*)f_1642},
{C_text("f_1646:tcp_2escm"),(void*)f_1646},
{C_text("f_1650:tcp_2escm"),(void*)f_1650},
{C_text("f_1652:tcp_2escm"),(void*)f_1652},
{C_text("f_1656:tcp_2escm"),(void*)f_1656},
{C_text("f_1659:tcp_2escm"),(void*)f_1659},
{C_text("f_1665:tcp_2escm"),(void*)f_1665},
{C_text("f_1668:tcp_2escm"),(void*)f_1668},
{C_text("f_1669:tcp_2escm"),(void*)f_1669},
{C_text("f_1673:tcp_2escm"),(void*)f_1673},
{C_text("f_1676:tcp_2escm"),(void*)f_1676},
{C_text("f_1681:tcp_2escm"),(void*)f_1681},
{C_text("f_1700:tcp_2escm"),(void*)f_1700},
{C_text("f_1703:tcp_2escm"),(void*)f_1703},
{C_text("f_1706:tcp_2escm"),(void*)f_1706},
{C_text("f_1709:tcp_2escm"),(void*)f_1709},
{C_text("f_1737:tcp_2escm"),(void*)f_1737},
{C_text("f_1741:tcp_2escm"),(void*)f_1741},
{C_text("f_1745:tcp_2escm"),(void*)f_1745},
{C_text("f_1763:tcp_2escm"),(void*)f_1763},
{C_text("f_1766:tcp_2escm"),(void*)f_1766},
{C_text("f_1767:tcp_2escm"),(void*)f_1767},
{C_text("f_1771:tcp_2escm"),(void*)f_1771},
{C_text("f_1782:tcp_2escm"),(void*)f_1782},
{C_text("f_1784:tcp_2escm"),(void*)f_1784},
{C_text("f_1806:tcp_2escm"),(void*)f_1806},
{C_text("f_1809:tcp_2escm"),(void*)f_1809},
{C_text("f_1812:tcp_2escm"),(void*)f_1812},
{C_text("f_1815:tcp_2escm"),(void*)f_1815},
{C_text("f_1838:tcp_2escm"),(void*)f_1838},
{C_text("f_1849:tcp_2escm"),(void*)f_1849},
{C_text("f_1853:tcp_2escm"),(void*)f_1853},
{C_text("f_1857:tcp_2escm"),(void*)f_1857},
{C_text("f_1897:tcp_2escm"),(void*)f_1897},
{C_text("f_1904:tcp_2escm"),(void*)f_1904},
{C_text("f_1907:tcp_2escm"),(void*)f_1907},
{C_text("f_1922:tcp_2escm"),(void*)f_1922},
{C_text("f_1925:tcp_2escm"),(void*)f_1925},
{C_text("f_1934:tcp_2escm"),(void*)f_1934},
{C_text("f_1942:tcp_2escm"),(void*)f_1942},
{C_text("f_1945:tcp_2escm"),(void*)f_1945},
{C_text("f_1951:tcp_2escm"),(void*)f_1951},
{C_text("f_1958:tcp_2escm"),(void*)f_1958},
{C_text("f_1962:tcp_2escm"),(void*)f_1962},
{C_text("f_1966:tcp_2escm"),(void*)f_1966},
{C_text("f_1991:tcp_2escm"),(void*)f_1991},
{C_text("f_2004:tcp_2escm"),(void*)f_2004},
{C_text("f_2014:tcp_2escm"),(void*)f_2014},
{C_text("f_2020:tcp_2escm"),(void*)f_2020},
{C_text("f_2025:tcp_2escm"),(void*)f_2025},
{C_text("f_2034:tcp_2escm"),(void*)f_2034},
{C_text("f_2040:tcp_2escm"),(void*)f_2040},
{C_text("f_2056:tcp_2escm"),(void*)f_2056},
{C_text("f_2060:tcp_2escm"),(void*)f_2060},
{C_text("f_2078:tcp_2escm"),(void*)f_2078},
{C_text("f_2091:tcp_2escm"),(void*)f_2091},
{C_text("f_2104:tcp_2escm"),(void*)f_2104},
{C_text("f_2108:tcp_2escm"),(void*)f_2108},
{C_text("f_2112:tcp_2escm"),(void*)f_2112},
{C_text("f_2120:tcp_2escm"),(void*)f_2120},
{C_text("f_2128:tcp_2escm"),(void*)f_2128},
{C_text("f_2134:tcp_2escm"),(void*)f_2134},
{C_text("f_2141:tcp_2escm"),(void*)f_2141},
{C_text("f_2145:tcp_2escm"),(void*)f_2145},
{C_text("f_2149:tcp_2escm"),(void*)f_2149},
{C_text("f_2170:tcp_2escm"),(void*)f_2170},
{C_text("f_2174:tcp_2escm"),(void*)f_2174},
{C_text("f_2188:tcp_2escm"),(void*)f_2188},
{C_text("f_2194:tcp_2escm"),(void*)f_2194},
{C_text("f_2242:tcp_2escm"),(void*)f_2242},
{C_text("f_2253:tcp_2escm"),(void*)f_2253},
{C_text("f_2257:tcp_2escm"),(void*)f_2257},
{C_text("f_2271:tcp_2escm"),(void*)f_2271},
{C_text("f_2281:tcp_2escm"),(void*)f_2281},
{C_text("f_2297:tcp_2escm"),(void*)f_2297},
{C_text("f_2327:tcp_2escm"),(void*)f_2327},
{C_text("f_2372:tcp_2escm"),(void*)f_2372},
{C_text("f_2382:tcp_2escm"),(void*)f_2382},
{C_text("f_2403:tcp_2escm"),(void*)f_2403},
{C_text("f_2407:tcp_2escm"),(void*)f_2407},
{C_text("f_2411:tcp_2escm"),(void*)f_2411},
{C_text("f_2415:tcp_2escm"),(void*)f_2415},
{C_text("f_2425:tcp_2escm"),(void*)f_2425},
{C_text("f_2428:tcp_2escm"),(void*)f_2428},
{C_text("f_2433:tcp_2escm"),(void*)f_2433},
{C_text("f_2437:tcp_2escm"),(void*)f_2437},
{C_text("f_2440:tcp_2escm"),(void*)f_2440},
{C_text("f_2443:tcp_2escm"),(void*)f_2443},
{C_text("f_2446:tcp_2escm"),(void*)f_2446},
{C_text("f_2474:tcp_2escm"),(void*)f_2474},
{C_text("f_2478:tcp_2escm"),(void*)f_2478},
{C_text("f_2482:tcp_2escm"),(void*)f_2482},
{C_text("f_2508:tcp_2escm"),(void*)f_2508},
{C_text("f_2510:tcp_2escm"),(void*)f_2510},
{C_text("f_2520:tcp_2escm"),(void*)f_2520},
{C_text("f_2533:tcp_2escm"),(void*)f_2533},
{C_text("f_2537:tcp_2escm"),(void*)f_2537},
{C_text("f_2541:tcp_2escm"),(void*)f_2541},
{C_text("f_2560:tcp_2escm"),(void*)f_2560},
{C_text("f_2567:tcp_2escm"),(void*)f_2567},
{C_text("f_2570:tcp_2escm"),(void*)f_2570},
{C_text("f_2573:tcp_2escm"),(void*)f_2573},
{C_text("f_2579:tcp_2escm"),(void*)f_2579},
{C_text("f_2582:tcp_2escm"),(void*)f_2582},
{C_text("f_2585:tcp_2escm"),(void*)f_2585},
{C_text("f_2591:tcp_2escm"),(void*)f_2591},
{C_text("f_2594:tcp_2escm"),(void*)f_2594},
{C_text("f_2597:tcp_2escm"),(void*)f_2597},
{C_text("f_2600:tcp_2escm"),(void*)f_2600},
{C_text("f_2606:tcp_2escm"),(void*)f_2606},
{C_text("f_2625:tcp_2escm"),(void*)f_2625},
{C_text("f_2629:tcp_2escm"),(void*)f_2629},
{C_text("f_2633:tcp_2escm"),(void*)f_2633},
{C_text("f_2651:tcp_2escm"),(void*)f_2651},
{C_text("f_2655:tcp_2escm"),(void*)f_2655},
{C_text("f_2659:tcp_2escm"),(void*)f_2659},
{C_text("f_2663:tcp_2escm"),(void*)f_2663},
{C_text("f_2679:tcp_2escm"),(void*)f_2679},
{C_text("f_2682:tcp_2escm"),(void*)f_2682},
{C_text("f_2710:tcp_2escm"),(void*)f_2710},
{C_text("f_2714:tcp_2escm"),(void*)f_2714},
{C_text("f_2718:tcp_2escm"),(void*)f_2718},
{C_text("f_2737:tcp_2escm"),(void*)f_2737},
{C_text("f_2741:tcp_2escm"),(void*)f_2741},
{C_text("f_2745:tcp_2escm"),(void*)f_2745},
{C_text("f_2763:tcp_2escm"),(void*)f_2763},
{C_text("f_2767:tcp_2escm"),(void*)f_2767},
{C_text("f_2771:tcp_2escm"),(void*)f_2771},
{C_text("f_2787:tcp_2escm"),(void*)f_2787},
{C_text("f_2791:tcp_2escm"),(void*)f_2791},
{C_text("f_2795:tcp_2escm"),(void*)f_2795},
{C_text("f_2804:tcp_2escm"),(void*)f_2804},
{C_text("f_2810:tcp_2escm"),(void*)f_2810},
{C_text("f_2818:tcp_2escm"),(void*)f_2818},
{C_text("f_2824:tcp_2escm"),(void*)f_2824},
{C_text("f_2835:tcp_2escm"),(void*)f_2835},
{C_text("f_2843:tcp_2escm"),(void*)f_2843},
{C_text("f_2847:tcp_2escm"),(void*)f_2847},
{C_text("f_2861:tcp_2escm"),(void*)f_2861},
{C_text("f_2867:tcp_2escm"),(void*)f_2867},
{C_text("f_2874:tcp_2escm"),(void*)f_2874},
{C_text("f_2877:tcp_2escm"),(void*)f_2877},
{C_text("f_2881:tcp_2escm"),(void*)f_2881},
{C_text("f_2884:tcp_2escm"),(void*)f_2884},
{C_text("f_2891:tcp_2escm"),(void*)f_2891},
{C_text("f_2895:tcp_2escm"),(void*)f_2895},
{C_text("f_2899:tcp_2escm"),(void*)f_2899},
{C_text("f_2912:tcp_2escm"),(void*)f_2912},
{C_text("f_2916:tcp_2escm"),(void*)f_2916},
{C_text("f_2920:tcp_2escm"),(void*)f_2920},
{C_text("f_2928:tcp_2escm"),(void*)f_2928},
{C_text("f_2934:tcp_2escm"),(void*)f_2934},
{C_text("f_2943:tcp_2escm"),(void*)f_2943},
{C_text("f_2946:tcp_2escm"),(void*)f_2946},
{C_text("f_2959:tcp_2escm"),(void*)f_2959},
{C_text("f_2963:tcp_2escm"),(void*)f_2963},
{C_text("f_2967:tcp_2escm"),(void*)f_2967},
{C_text("f_2983:tcp_2escm"),(void*)f_2983},
{C_text("f_2987:tcp_2escm"),(void*)f_2987},
{C_text("f_2991:tcp_2escm"),(void*)f_2991},
{C_text("f_2999:tcp_2escm"),(void*)f_2999},
{C_text("f_3012:tcp_2escm"),(void*)f_3012},
{C_text("f_3022:tcp_2escm"),(void*)f_3022},
{C_text("f_3026:tcp_2escm"),(void*)f_3026},
{C_text("f_3030:tcp_2escm"),(void*)f_3030},
{C_text("f_3038:tcp_2escm"),(void*)f_3038},
{C_text("f_3048:tcp_2escm"),(void*)f_3048},
{C_text("f_3054:tcp_2escm"),(void*)f_3054},
{C_text("f_3065:tcp_2escm"),(void*)f_3065},
{C_text("f_3069:tcp_2escm"),(void*)f_3069},
{C_text("f_3073:tcp_2escm"),(void*)f_3073},
{C_text("f_3077:tcp_2escm"),(void*)f_3077},
{C_text("f_992:tcp_2escm"),(void*)f_992},
{C_text("f_995:tcp_2escm"),(void*)f_995},
{C_text("f_998:tcp_2escm"),(void*)f_998},
{C_text("toplevel:tcp_2escm"),(void*)C_tcp_toplevel},
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
o|hiding unexported module binding: chicken.tcp#d 
o|hiding unexported module binding: chicken.tcp#define-alias 
o|hiding unexported module binding: chicken.tcp#last-error-code 
o|hiding unexported module binding: chicken.tcp#error-code->message 
o|hiding unexported module binding: chicken.tcp#retry? 
o|hiding unexported module binding: chicken.tcp#in-progress? 
o|hiding unexported module binding: chicken.tcp#interrupted? 
o|hiding unexported module binding: chicken.tcp#socket 
o|hiding unexported module binding: chicken.tcp#bind 
o|hiding unexported module binding: chicken.tcp#listen 
o|hiding unexported module binding: chicken.tcp#accept 
o|hiding unexported module binding: chicken.tcp#close 
o|hiding unexported module binding: chicken.tcp#recv 
o|hiding unexported module binding: chicken.tcp#shutdown 
o|hiding unexported module binding: chicken.tcp#connect 
o|hiding unexported module binding: chicken.tcp#check-fd-ready 
o|hiding unexported module binding: chicken.tcp#set-socket-options 
o|hiding unexported module binding: chicken.tcp#send 
o|hiding unexported module binding: chicken.tcp#getsockname 
o|hiding unexported module binding: chicken.tcp#getsockport 
o|hiding unexported module binding: chicken.tcp#getpeerport 
o|hiding unexported module binding: chicken.tcp#getpeername 
o|hiding unexported module binding: chicken.tcp#startup 
o|hiding unexported module binding: chicken.tcp#getservbyname 
o|hiding unexported module binding: chicken.tcp#gethostaddr 
o|hiding unexported module binding: chicken.tcp#network-error 
o|hiding unexported module binding: chicken.tcp#network-error/close 
o|hiding unexported module binding: chicken.tcp#network-error/code 
o|hiding unexported module binding: chicken.tcp#parse-host 
o|hiding unexported module binding: chicken.tcp#fresh-addr 
o|hiding unexported module binding: chicken.tcp#bind-socket 
o|hiding unexported module binding: chicken.tcp#io-ports 
o|hiding unexported module binding: chicken.tcp#get-socket-error 
o|hiding unexported module binding: chicken.tcp#tcp-port->fileno 
o|eliminated procedure checks: 64 
o|specializations:
o|  3 (##sys#check-open-port * *)
o|  3 (scheme#make-string fixnum)
o|  24 (scheme#string-append string string)
(o e)|safe calls: 343 
(o e)|assignments to immediate values: 6 
o|safe globals: (chicken.tcp#startup chicken.tcp#getpeername chicken.tcp#getpeerport chicken.tcp#getsockport chicken.tcp#getsockname chicken.tcp#send chicken.tcp#set-socket-options chicken.tcp#check-fd-ready chicken.tcp#connect chicken.tcp#shutdown chicken.tcp#recv chicken.tcp#close chicken.tcp#accept chicken.tcp#listen chicken.tcp#bind chicken.tcp#socket chicken.tcp#interrupted? chicken.tcp#in-progress? chicken.tcp#retry? chicken.tcp#error-code->message chicken.tcp#last-error-code) 
o|inlining procedure: k1287 
o|inlining procedure: k1287 
o|inlining procedure: k1316 
o|inlining procedure: "(tcp.scm:290) chicken.tcp#last-error-code" 
o|substituted constant variable: a1341 
o|substituted constant variable: a1342 
o|inlining procedure: k1316 
o|contracted procedure: "(tcp.scm:288) chicken.tcp#getservbyname" 
o|inlining procedure: k1235 
o|inlining procedure: k1235 
o|inlining procedure: k1491 
o|substituted constant variable: a1521 
o|substituted constant variable: a1522 
o|inlining procedure: "(tcp.scm:329) chicken.tcp#close" 
o|inlining procedure: "(tcp.scm:329) chicken.tcp#last-error-code" 
o|inlining procedure: k1491 
o|contracted procedure: "(tcp.scm:328) chicken.tcp#listen" 
o|contracted procedure: "(tcp.scm:327) chicken.tcp#bind-socket" 
o|inlining procedure: k1384 
o|substituted constant variable: a1411 
o|substituted constant variable: a1412 
o|inlining procedure: "(tcp.scm:317) chicken.tcp#close" 
o|inlining procedure: "(tcp.scm:317) chicken.tcp#last-error-code" 
o|inlining procedure: k1384 
o|contracted procedure: "(tcp.scm:316) chicken.tcp#bind" 
o|inlining procedure: "(tcp.scm:315) chicken.tcp#last-error-code" 
o|substituted constant variable: a1439 
o|substituted constant variable: a1440 
o|inlining procedure: "(tcp.scm:314) chicken.tcp#set-socket-options" 
o|inlining procedure: k1451 
o|inlining procedure: k1451 
o|contracted procedure: "(tcp.scm:309) chicken.tcp#fresh-addr" 
o|inlining procedure: k1566 
o|inlining procedure: k1566 
o|inlining procedure: k1581 
o|inlining procedure: "(tcp.scm:340) chicken.tcp#last-error-code" 
o|substituted constant variable: a1606 
o|substituted constant variable: a1607 
o|inlining procedure: k1581 
o|inlining procedure: "(tcp.scm:339) chicken.tcp#close" 
o|inlining procedure: k1625 
o|inlining procedure: k1625 
o|inlining procedure: k1686 
o|inlining procedure: k1707 
o|inlining procedure: k1707 
o|inlining procedure: k1722 
o|inlining procedure: k1722 
o|inlining procedure: "(tcp.scm:395) chicken.tcp#last-error-code" 
o|substituted constant variable: a1750 
o|substituted constant variable: a1751 
o|inlining procedure: "(tcp.scm:392) chicken.tcp#interrupted?" 
o|inlining procedure: "(tcp.scm:381) chicken.tcp#retry?" 
o|inlining procedure: k1686 
o|contracted procedure: "(tcp.scm:379) chicken.tcp#recv" 
o|inlining procedure: k1792 
o|inlining procedure: k1828 
o|inlining procedure: k1828 
o|inlining procedure: "(tcp.scm:506) chicken.tcp#last-error-code" 
o|substituted constant variable: a1862 
o|substituted constant variable: a1863 
o|inlining procedure: "(tcp.scm:502) chicken.tcp#interrupted?" 
o|inlining procedure: "(tcp.scm:491) chicken.tcp#retry?" 
o|inlining procedure: k1792 
o|inlining procedure: k1882 
o|inlining procedure: k1882 
o|contracted procedure: "(tcp.scm:489) chicken.tcp#send" 
o|inlining procedure: k1936 
o|inlining procedure: k1936 
o|inlining procedure: "(tcp.scm:532) chicken.tcp#last-error-code" 
o|substituted constant variable: a1971 
o|substituted constant variable: a1972 
o|inlining procedure: "(tcp.scm:531) chicken.tcp#close" 
o|inlining procedure: k2001 
o|inlining procedure: k2006 
o|inlining procedure: k2006 
o|inlining procedure: k2001 
o|inlining procedure: k2026 
o|inlining procedure: k2026 
o|inlining procedure: k2042 
o|inlining procedure: k2042 
o|inlining procedure: k2061 
o|inlining procedure: k2061 
o|inlining procedure: k2083 
o|inlining procedure: k2083 
o|inlining procedure: "(tcp.scm:416) chicken.tcp#last-error-code" 
o|substituted constant variable: a2117 
o|substituted constant variable: a2118 
o|inlining procedure: "(tcp.scm:414) chicken.tcp#check-fd-ready" 
o|inlining procedure: k2122 
o|inlining procedure: k2122 
o|inlining procedure: "(tcp.scm:423) chicken.tcp#last-error-code" 
o|substituted constant variable: a2154 
o|substituted constant variable: a2155 
o|inlining procedure: "(tcp.scm:422) chicken.tcp#close" 
o|inlining procedure: k2175 
o|inlining procedure: k2175 
o|inlining procedure: k2196 
o|inlining procedure: k2196 
o|inlining procedure: k2243 
o|inlining procedure: k2243 
o|inlining procedure: k2258 
o|inlining procedure: k2258 
o|inlining procedure: k2286 
o|inlining procedure: k2286 
o|inlining procedure: k2329 
o|inlining procedure: k2329 
o|inlining procedure: k2374 
o|inlining procedure: k2374 
o|inlining procedure: k2384 
o|inlining procedure: k2384 
o|substituted constant variable: a2390 
o|substituted constant variable: a2412 
o|substituted constant variable: a2413 
o|inlining procedure: "(tcp.scm:365) chicken.tcp#close" 
o|inlining procedure: "(tcp.scm:365) chicken.tcp#last-error-code" 
o|inlining procedure: k2450 
o|inlining procedure: k2450 
o|inlining procedure: "(tcp.scm:567) chicken.tcp#last-error-code" 
o|substituted constant variable: a2487 
o|substituted constant variable: a2488 
o|inlining procedure: "(tcp.scm:564) chicken.tcp#interrupted?" 
o|contracted procedure: "(tcp.scm:561) chicken.tcp#accept" 
o|inlining procedure: k1078 
o|inlining procedure: k1078 
o|inlining procedure: k2518 
o|inlining procedure: "(tcp.scm:574) chicken.tcp#last-error-code" 
o|substituted constant variable: a2546 
o|substituted constant variable: a2547 
o|inlining procedure: k2518 
o|inlining procedure: "(tcp.scm:572) chicken.tcp#check-fd-ready" 
o|inlining procedure: k2604 
o|substituted constant variable: a2634 
o|substituted constant variable: a2635 
o|inlining procedure: "(tcp.scm:618) chicken.tcp#close" 
o|inlining procedure: "(tcp.scm:618) chicken.tcp#last-error-code" 
o|inlining procedure: k2604 
o|substituted constant variable: a2660 
o|substituted constant variable: a2661 
o|inlining procedure: "(tcp.scm:620) chicken.tcp#close" 
o|contracted procedure: "(tcp.scm:616) chicken.tcp#get-socket-error" 
o|inlining procedure: k2665 
o|inlining procedure: k2689 
o|inlining procedure: k2689 
o|substituted constant variable: a2719 
o|substituted constant variable: a2720 
o|inlining procedure: "(tcp.scm:614) chicken.tcp#close" 
o|inlining procedure: "(tcp.scm:614) chicken.tcp#last-error-code" 
o|inlining procedure: "(tcp.scm:611) chicken.tcp#interrupted?" 
o|contracted procedure: "(tcp.scm:606) chicken.tcp#in-progress?" 
o|inlining procedure: k2665 
o|contracted procedure: "(tcp.scm:605) chicken.tcp#connect" 
o|substituted constant variable: a2746 
o|substituted constant variable: a2747 
o|inlining procedure: "(tcp.scm:603) chicken.tcp#close" 
o|inlining procedure: "(tcp.scm:603) chicken.tcp#last-error-code" 
o|substituted constant variable: a2772 
o|substituted constant variable: a2773 
o|inlining procedure: "(tcp.scm:601) chicken.tcp#close" 
o|inlining procedure: "(tcp.scm:601) chicken.tcp#last-error-code" 
o|inlining procedure: "(tcp.scm:600) chicken.tcp#set-socket-options" 
o|inlining procedure: "(tcp.scm:599) chicken.tcp#last-error-code" 
o|substituted constant variable: a2800 
o|substituted constant variable: a2801 
o|inlining procedure: k2811 
o|inlining procedure: k2811 
o|inlining procedure: k2848 
o|inlining procedure: k2848 
o|substituted constant variable: a2864 
o|inlining procedure: k2882 
o|inlining procedure: k2882 
o|inlining procedure: "(tcp.scm:637) chicken.tcp#last-error-code" 
o|substituted constant variable: a2904 
o|substituted constant variable: a2905 
o|contracted procedure: "(tcp.scm:636) chicken.tcp#getpeername" 
o|inlining procedure: "(tcp.scm:635) chicken.tcp#last-error-code" 
o|substituted constant variable: a2925 
o|substituted constant variable: a2926 
o|contracted procedure: "(tcp.scm:634) chicken.tcp#getsockname" 
o|substituted constant variable: a2931 
o|inlining procedure: k2944 
o|inlining procedure: "(tcp.scm:647) chicken.tcp#last-error-code" 
o|substituted constant variable: a2972 
o|substituted constant variable: a2973 
o|inlining procedure: k2944 
o|inlining procedure: "(tcp.scm:645) chicken.tcp#last-error-code" 
o|substituted constant variable: a2996 
o|substituted constant variable: a2997 
o|contracted procedure: "(tcp.scm:643) chicken.tcp#getpeerport" 
o|inlining procedure: "(tcp.scm:642) chicken.tcp#getsockport" 
o|inlining procedure: k3010 
o|inlining procedure: "(tcp.scm:655) chicken.tcp#last-error-code" 
o|substituted constant variable: a3035 
o|substituted constant variable: a3036 
o|inlining procedure: k3010 
o|inlining procedure: "(tcp.scm:653) chicken.tcp#getsockport" 
o|substituted constant variable: a3041 
o|contracted procedure: "(tcp.scm:236) chicken.tcp#startup" 
o|replaced variables: 547 
o|removed binding forms: 149 
o|removed side-effect free assignment to unused variable: chicken.tcp#last-error-code 
o|removed side-effect free assignment to unused variable: chicken.tcp#retry? 
o|removed side-effect free assignment to unused variable: chicken.tcp#interrupted? 
o|removed side-effect free assignment to unused variable: chicken.tcp#close 
o|removed side-effect free assignment to unused variable: chicken.tcp#check-fd-ready 
o|removed side-effect free assignment to unused variable: chicken.tcp#set-socket-options 
o|removed side-effect free assignment to unused variable: chicken.tcp#getsockport 
o|substituted constant variable: r15673135 
o|substituted constant variable: int175182 
o|substituted constant variable: int174181 
o|inlining procedure: k1882 
o|substituted constant variable: flags217225 
o|substituted constant variable: r20023190 
o|substituted constant variable: r20023190 
o|substituted constant variable: r20623196 
o|inlining procedure: k2089 
o|substituted constant variable: r21763217 
o|substituted constant variable: r22593222 
o|substituted constant variable: r23753234 
o|substituted constant variable: r23853236 
o|substituted constant variable: r23853237 
o|substituted constant variable: c-pointer156163 
o|substituted constant variable: c-pointer156163 
o|substituted constant variable: r10793251 
o|substituted constant variable: r10793251 
o|substituted constant variable: c-pointer155162 
o|substituted constant variable: c-pointer155162 
o|inlining procedure: k2604 
o|contracted procedure: "(tcp.scm:592) chicken.tcp#parse-host" 
o|substituted constant variable: r12363095 
o|substituted constant variable: r12363095 
o|replaced variables: 151 
o|removed binding forms: 476 
o|removed conditional forms: 2 
o|inlining procedure: k1524 
o|inlining procedure: k1414 
o|inlining procedure: k1436 
o|inlining procedure: k1442 
o|inlining procedure: k1530 
o|inlining procedure: k1603 
o|inlining procedure: k1609 
o|inlining procedure: k1747 
o|inlining procedure: k1813 
o|inlining procedure: k1859 
o|substituted constant variable: r18833371 
o|inlining procedure: k1968 
o|inlining procedure: k1977 
o|inlining procedure: k2114 
o|inlining procedure: k2151 
o|inlining procedure: k2160 
o|inlining procedure: k2484 
o|contracted procedure: k1074 
o|inlining procedure: k2543 
o|inlining procedure: k2677 
o|inlining procedure: k2722 
o|inlining procedure: k2775 
o|inlining procedure: k2797 
o|inlining procedure: k1338 
o|inlining procedure: k2901 
o|inlining procedure: k2922 
o|inlining procedure: k2969 
o|inlining procedure: k2993 
o|inlining procedure: k3032 
o|inlining procedure: k3078 
o|replaced variables: 1 
o|removed binding forms: 177 
o|contracted procedure: k1500 
o|contracted procedure: k1503 
o|contracted procedure: k1390 
o|contracted procedure: k1393 
o|contracted procedure: k1683 
o|contracted procedure: k1695 
o|contracted procedure: k1725 
o|contracted procedure: k1789 
o|contracted procedure: k1801 
o|contracted procedure: k1831 
o|contracted procedure: k2086 
o|contracted procedure: k2391 
o|contracted procedure: k2394 
o|contracted procedure: k2447 
o|substituted constant variable: r1075 
o|contracted procedure: k2462 
o|contracted procedure: k2515 
o|contracted procedure: k2601 
o|contracted procedure: k2613 
o|contracted procedure: k2616 
o|contracted procedure: k2642 
o|contracted procedure: k2674 
o|contracted procedure: k2692 
o|contracted procedure: k2698 
o|contracted procedure: k2701 
o|contracted procedure: k2725 
o|contracted procedure: k2728 
o|contracted procedure: k2751 
o|contracted procedure: k2754 
o|contracted procedure: k2935 
o|contracted procedure: k2938 
o|contracted procedure: k3007 
o|simplifications: ((let . 8)) 
o|replaced variables: 1 
o|removed binding forms: 60 
o|removed binding forms: 2 
o|simplifications: ((if . 15) (##core#call . 194) (let . 28)) 
o|  call simplifications:
o|    chicken.fixnum#fx*
o|    scheme#vector?
o|    ##sys#check-string
o|    scheme#char=?
o|    scheme#not
o|    scheme#vector
o|    ##sys#call-with-values	2
o|    chicken.fixnum#fx>=	9
o|    ##sys#setslot	4
o|    scheme#values	11
o|    ##sys#size	7
o|    chicken.fixnum#fxmin	3
o|    chicken.fixnum#fx-	6
o|    chicken.fixnum#fx+	12
o|    chicken.fixnum#fx=
o|    scheme#+	5
o|    ##sys#setislot	5
o|    ##sys#check-structure	5
o|    ##sys#slot	14
o|    ##sys#structure?
o|    scheme#car	3
o|    scheme#null?	5
o|    scheme#cdr	2
o|    chicken.fixnum#fx<	7
o|    chicken.fixnum#fx>	6
o|    scheme#eq?	26
o|    ##sys#make-structure	2
o|    ##sys#foreign-block-argument	6
o|    ##sys#foreign-string-argument	3
o|    ##sys#foreign-unsigned-ranged-integer-argument	2
o|    ##sys#foreign-fixnum-argument	41
o|contracted procedure: k1010 
o|contracted procedure: k1026 
o|contracted procedure: k1030 
o|contracted procedure: k1034 
o|contracted procedure: k1120 
o|contracted procedure: k1124 
o|contracted procedure: k1256 
o|contracted procedure: k1264 
o|contracted procedure: k1272 
o|contracted procedure: k1557 
o|contracted procedure: k1467 
o|contracted procedure: k1551 
o|contracted procedure: k1470 
o|contracted procedure: k1545 
o|contracted procedure: k1473 
o|contracted procedure: k1539 
o|contracted procedure: k1476 
o|contracted procedure: k1059 
o|contracted procedure: k1063 
o|contracted procedure: k1497 
o|contracted procedure: k10913107 
o|contracted procedure: k1041 
o|contracted procedure: k1045 
o|contracted procedure: k1049 
o|contracted procedure: k1387 
o|contracted procedure: k10913121 
o|contracted procedure: k11563131 
o|contracted procedure: k1417 
o|contracted procedure: k1445 
o|contracted procedure: k1358 
o|contracted procedure: k1362 
o|contracted procedure: k1527 
o|contracted procedure: k1530 
o|contracted procedure: k1575 
o|contracted procedure: k1578 
o|contracted procedure: k10913144 
o|contracted procedure: k1584 
o|contracted procedure: k1632 
o|contracted procedure: k1660 
o|contracted procedure: k1098 
o|contracted procedure: k1102 
o|contracted procedure: k1106 
o|contracted procedure: k1110 
o|contracted procedure: k1689 
o|contracted procedure: k1713 
o|contracted procedure: k1753 
o|contracted procedure: k1776 
o|contracted procedure: k1786 
o|contracted procedure: k1163 
o|contracted procedure: k1167 
o|contracted procedure: k1171 
o|contracted procedure: k1175 
o|contracted procedure: k1179 
o|contracted procedure: k1795 
o|contracted procedure: k1819 
o|contracted procedure: k1867 
o|contracted procedure: k1874 
o|contracted procedure: k1878 
o|contracted procedure: k1885 
o|contracted procedure: k1882 
o|contracted procedure: k1908 
o|contracted procedure: k1911 
o|contracted procedure: k1914 
o|contracted procedure: k1917 
o|contracted procedure: k1930 
o|contracted procedure: k2037 
o|contracted procedure: k2029 
o|contracted procedure: k2052 
o|contracted procedure: k2045 
o|contracted procedure: k10913185 
o|contracted procedure: k1980 
o|contracted procedure: k1997 
o|contracted procedure: k2017 
o|contracted procedure: k2009 
o|contracted procedure: k2064 
o|contracted procedure: k2068 
o|contracted procedure: k2071 
o|contracted procedure: k2080 
o|contracted procedure: k11493206 
o|contracted procedure: k2095 
o|contracted procedure: k10913215 
o|contracted procedure: k2163 
o|contracted procedure: k2178 
o|contracted procedure: k2181 
o|contracted procedure: k2199 
o|contracted procedure: k2205 
o|contracted procedure: k2208 
o|contracted procedure: k2237 
o|contracted procedure: k2211 
o|contracted procedure: k2215 
o|contracted procedure: k2219 
o|contracted procedure: k2226 
o|contracted procedure: k2230 
o|contracted procedure: k2234 
o|contracted procedure: k2246 
o|contracted procedure: k2261 
o|contracted procedure: k2264 
o|contracted procedure: k2323 
o|contracted procedure: k2277 
o|contracted procedure: k2283 
o|contracted procedure: k2289 
o|contracted procedure: k2299 
o|contracted procedure: k2305 
o|contracted procedure: k2316 
o|contracted procedure: k2312 
o|contracted procedure: k2344 
o|contracted procedure: k2340 
o|contracted procedure: k2333 
o|inlining procedure: k2329 
o|contracted procedure: k2355 
o|contracted procedure: k2359 
o|contracted procedure: k2351 
o|inlining procedure: k2329 
o|contracted procedure: k2365 
o|contracted procedure: k2377 
o|contracted procedure: k2387 
o|contracted procedure: k10913243 
o|contracted procedure: k2417 
o|contracted procedure: k2420 
o|contracted procedure: k1070 
o|contracted procedure: k2490 
o|contracted procedure: k2453 
o|contracted procedure: k2493 
o|contracted procedure: k2512 
o|contracted procedure: k2549 
o|contracted procedure: k11493269 
o|contracted procedure: k2524 
o|contracted procedure: k2836 
o|contracted procedure: k2562 
o|contracted procedure: k2574 
o|contracted procedure: k2556 
o|contracted procedure: k2610 
o|contracted procedure: k10913280 
o|contracted procedure: k2639 
o|contracted procedure: k10913292 
o|contracted procedure: k1131 
o|contracted procedure: k1135 
o|contracted procedure: k1139 
o|contracted procedure: k2668 
o|contracted procedure: k10913301 
o|contracted procedure: k10913310 
o|contracted procedure: k11563324 
o|contracted procedure: k2748 
o|contracted procedure: k10913317 
o|contracted procedure: k2778 
o|contracted procedure: k1278 
o|contracted procedure: k1290 
o|contracted procedure: k1299 
o|contracted procedure: k1319 
o|contracted procedure: k1242 
o|contracted procedure: k1249 
o|contracted procedure: k1344 
o|contracted procedure: k1351 
o|contracted procedure: k2851 
o|contracted procedure: k1218 
o|contracted procedure: k1193 
o|contracted procedure: k12003353 
o|contracted procedure: k1207 
o|contracted procedure: k2950 
o|contracted procedure: k2974 
o|contracted procedure: k3001 
o|contracted procedure: k3004 
o|contracted procedure: k12003364 
o|contracted procedure: k3013 
o|contracted procedure: k3050 
o|contracted procedure: k3056 
o|simplifications: ((if . 1) (let . 42)) 
o|removed binding forms: 164 
o|inlining procedure: k1260 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest428430 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest428430 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest428430 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest428430 0 
o|inlining procedure: "(tcp.scm:329) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:317) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:315) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:310) chicken.tcp#socket" 
o|inlining procedure: "(tcp.scm:340) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:395) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:506) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:532) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:530) chicken.tcp#shutdown" 
o|contracted procedure: k1986 
o|inlining procedure: "(tcp.scm:416) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:423) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:421) chicken.tcp#shutdown" 
o|inlining procedure: k2172 
o|inlining procedure: "(tcp.scm:365) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:567) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:574) chicken.tcp#error-code->message" 
(o x)|known list op on rest arg sublist: ##core#rest-null? more690 0 
(o x)|known list op on rest arg sublist: ##core#rest-car more690 0 
o|inlining procedure: "(tcp.scm:618) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:621) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:614) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:603) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:601) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:599) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:597) chicken.tcp#socket" 
o|inlining procedure: "(tcp.scm:290) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:637) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:635) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:647) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:645) chicken.tcp#error-code->message" 
o|inlining procedure: "(tcp.scm:655) chicken.tcp#error-code->message" 
o|removed binding forms: 2 
o|removed side-effect free assignment to unused variable: chicken.tcp#error-code->message 
o|removed side-effect free assignment to unused variable: chicken.tcp#socket 
o|removed side-effect free assignment to unused variable: chicken.tcp#shutdown 
o|substituted constant variable: r12613511 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1471 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1471 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1471 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1471 1 
o|substituted constant variable: int1291343528 
o|substituted constant variable: int1291343610 
o|replaced variables: 39 
o|removed binding forms: 1 
o|removed binding forms: 47 
o|contracted procedure: k1375 
o|contracted procedure: k2586 
o|removed binding forms: 2 
o|customizable procedures: (check474 chicken.tcp#tcp-port->fileno k2568 loop382 k1313 k2426 chicken.tcp#io-ports k1666 loop557 k2126 k2132 read-input507 k1940 k1943 k1949 output595 k1780 loop598 k1674 chicken.tcp#gethostaddr k1488) 
o|calls to known targets: 84 
o|unused rest argument: rest428430 f_1465 
o|identified direct recursive calls: f_1784 2 
o|identified direct recursive calls: f_2194 1 
o|identified direct recursive calls: f_1285 1 
o|unused rest argument: more690 f_2560 
o|fast box initializations: 7 
o|fast global references: 7 
o|fast global assignments: 3 
o|dropping unused closure argument: f_1253 
o|dropping unused closure argument: f_1621 
o|dropping unused closure argument: f_2843 
*/
/* end of file */
