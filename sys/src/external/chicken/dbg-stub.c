/* dbg-stub.c - Client-side interface, lowlevel part
;
; Copyright (c) 2008-2022, The CHICKEN Team
; Copyright (c) 2000-2007, Felix L. Winkelmann
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
; conditions are met:
;
;   Redistributions of source code must retain the above copyright notice, this list of conditions and the following
;     disclaimer.
;   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
;     disclaimer in the documentation and/or other materials provided with the distribution.
;   Neither the name of the author nor the names of its contributors may be used to endorse or promote
;     products derived from this software without specific prior written permission.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
; OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
; AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
; CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
; CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
; OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
; POSSIBILITY OF SUCH DAMAGE.
*/


/* included from debugger-client.scm */

#include <assert.h>

#ifdef _WIN32
# include <winsock2.h>
# include <ws2tcpip.h>
/* Beware: winsock2.h must come BEFORE windows.h */
# define socklen_t	 int
static WSADATA wsa;
#else
# include <errno.h>
# include <fcntl.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <netinet/in.h>
# include <netdb.h>
# include <signal.h>
# define closesocket     close
# define INVALID_SOCKET    (-1)
# define SOCKET_ERROR      (-1)
# ifndef h_addr
#  define h_addr  h_addr_list[ 0 ]
# endif
#endif


#define C_DEBUG_PROTOCOL_VERSION         1

#define C_DEBUG_REPLY_UNUSED             0
#define C_DEBUG_REPLY_SETMASK            1
#define C_DEBUG_REPLY_TERMINATE          2
#define C_DEBUG_REPLY_CONTINUE           3
#define C_DEBUG_REPLY_SET_BREAKPOINT     4
#define C_DEBUG_REPLY_CLEAR_BREAKPOINT   5
#define C_DEBUG_REPLY_LIST_EVENTS        6
#define C_DEBUG_REPLY_GET_BYTES          7
#define C_DEBUG_REPLY_GET_AV             8
#define C_DEBUG_REPLY_GET_SLOTS          9
#define C_DEBUG_REPLY_GET_GLOBAL         10
#define C_DEBUG_REPLY_GET_STATS          11
#define C_DEBUG_REPLY_GET_TRACE          12

#define INPUT_BUFFER_SIZE         4096
#define RW_BUFFER_SIZE            1024
#define DEFAULT_DEBUGGER_PORT     9999

#ifdef C_SIXTY_FOUR
# define C_HEADER_BITS_SHIFT      56
# ifdef C_LLP
#  define UWORD_COUNT_FORMAT_STRING     "%llu"
# else
#  define UWORD_COUNT_FORMAT_STRING     "%lu"
# endif
#else
# define C_HEADER_BITS_SHIFT      24
# define UWORD_COUNT_FORMAT_STRING     "%u"
#endif

#define C_VALUE_CUTOFF_LIMIT      300
#define get_header_bits(x)        ((int)(C_header_bits((x)) >> C_HEADER_BITS_SHIFT))


struct bp_item {
  char *name;
  int len;
  struct bp_item *next;
};

struct dbg_info_list {
  C_DEBUG_INFO *info;
  struct dbg_info_list *next;
};


static long event_mask = 0;
static int socket_fd = 0;
static char input_buffer[ INPUT_BUFFER_SIZE + 1 ];
static char *input_buffer_top = NULL;
static int input_buffer_len = 0;
static char rw_buffer[ RW_BUFFER_SIZE + 1 ];
static struct bp_item *breakpoints = NULL;
static struct dbg_info_list
    *dbg_info_list = NULL,
    *last_dbg_info_list = NULL,
    *unseen_dbg_info_list = NULL;
static C_word current_c = 0;
static C_word *current_av;
static volatile int interrupted = 0;
static int dbg_info_count = 0;


static C_word debug_event_hook(C_DEBUG_INFO *cell, C_word c, C_word *av, C_char *cloc);


void
C_register_debug_info(C_DEBUG_INFO *info)
{
  struct dbg_info_list *node =
    (struct dbg_info_list *)C_malloc(sizeof(struct dbg_info_list));

  /* fprintf(stderr, "Registering: %p (%s/%s)\n", node, info->loc, info->val); */
  assert(node);
  node->info = info;
  node->next = NULL;

  if(last_dbg_info_list != NULL) last_dbg_info_list->next = node;

  last_dbg_info_list = node;

  if(unseen_dbg_info_list == NULL) unseen_dbg_info_list = node;

  if(dbg_info_list == NULL) dbg_info_list = node;

  /* fprintf(stderr, "first: %p, last: %p, unseen: %p\n", dbg_info_list, last_dbg_info_list, unseen_dbg_info_list); */
}


static int
socket_read()
{
  int p = 0, s = 0, e = 0;
  int n, off = 0;
  char *ptr = rw_buffer;

  /* copy from input_buffer into rw_buffer until newline: */
  for(;;) {
    while(input_buffer_len > 0) {
      *(ptr++) = *input_buffer_top;

      if(*(input_buffer_top++) == '\n') {
        *ptr = '\0';
        --input_buffer_len;
        return 1;
      }

      if(++off >= RW_BUFFER_SIZE) return -1; /* read-buffer overflow */

      --input_buffer_len;
    }

    n = recv(socket_fd, input_buffer, INPUT_BUFFER_SIZE, 0);

    if(n == SOCKET_ERROR) return -1; /* read failed */

    if(n == 0) return 0; /* client disconnect */

    input_buffer_len = n;
    input_buffer_top = input_buffer;
  }
}


static int
socket_write(char *buf, int len)
{
  int n, m = 0, off = 0;

  while(m < len) {
    n = send(socket_fd, buf + off, len, 0);

    if(n == SOCKET_ERROR) return -1; /* write failed */

    off += n;
    m += n;
  }

  return 0;
}


static void
socket_close()
{
  closesocket(socket_fd);
  socket_fd = 0;
}


static void
terminate(char *msg)
{
  fprintf(stderr, "%s\n", msg);
  socket_close();
  C_exit_runtime(C_fix(1));
}


static char *
name_and_length(char *buf, int *len)
{
    char *str, *ptr;

    for(str = buf; *str && *str != '\"'; ++str);

    if(!*str) return "";

    for(ptr = ++str; *ptr != '\"'; ++ptr) {
        if(*ptr == '\\') ++ptr;
    }

    *len = ptr - str;
    return str;
}


static void
enable_debug_info(int n, int f)
{
    int i = 0;
    struct dbg_info_list *dip;
    C_DEBUG_INFO *dinfo;

    for(dip = dbg_info_list; dip != NULL; dip = dip->next) {
        for(dinfo = dip->info; dinfo->event; ++dinfo) {
            if(i++ == n) {
                dinfo->enabled = f;
                return;
            }
        }
    }

    terminate("invalid debug-info index");
}


static void
send_string(C_char *str)
{
  /* fprintf(stderr, "<SENT: %s>\n", str); */
  C_fflush(stderr);

  if(socket_write(str, C_strlen(str)) != 0)
    terminate("write failed");
}

static void
send_string_value(C_char *str) {
  if (str == 0 || *str == 0)
    send_string(" #f");
  else {
    C_snprintf(rw_buffer, sizeof(rw_buffer), " \"%s\"", str);
    send_string(rw_buffer);
  }
}

static void
send_scheme_value(C_word x)
{
  if((x & C_FIXNUM_BIT) != 0)
    C_snprintf(rw_buffer, sizeof(rw_buffer), " %ld", (long)C_unfix(x));
  else if((x & C_IMMEDIATE_MARK_BITS) != 0)
    C_snprintf(rw_buffer, sizeof(rw_buffer), " =%lu", (unsigned long)x);
  else
    C_snprintf(rw_buffer, sizeof(rw_buffer), " @%lu", (unsigned long)x);

  send_string(rw_buffer);
}


static void
send_event(int event, C_char *loc, C_char *val, C_char *cloc)
{
  int n;
  int reply, mask;
  struct bp_item *bp, *prev;
  C_char *str, *ptr;
  struct dbg_info_list *dip;
  C_DEBUG_INFO *dinfo;
  C_word x;
  void **stats;

  for(;;) {
    C_snprintf(rw_buffer, sizeof(rw_buffer), "(%d", event);
    send_string(rw_buffer);
    send_string_value(loc);
    send_string_value(val);
    send_string_value(cloc);
    send_string(")\n");

    n = socket_read();

    if(n < 0) terminate("read failed");

    if(n == 0) terminate("debugger disconnected");

    /* fprintf(stderr, "<READ: %s>\n", rw_buffer); */
    n = sscanf(rw_buffer, "(%d ", &reply);

    if(n == 0) terminate("invalid reply");

    switch(reply) {
    case C_DEBUG_REPLY_SETMASK:
      n = sscanf(rw_buffer, "(%d %d)", &reply, &mask);

      if(n != 2) terminate("invalid SETMASK reply");

      event_mask = mask;
      break;

    case C_DEBUG_REPLY_TERMINATE:
      terminate("terminated by debugger");

    case C_DEBUG_REPLY_CONTINUE:
      return;

    case C_DEBUG_REPLY_SET_BREAKPOINT:
      n = sscanf(rw_buffer, "(%d %d)", &reply, &mask);

      if(n != 2) terminate("invalid SET BREAKPOINT reply");

      enable_debug_info(mask, 1);
      break;

    case C_DEBUG_REPLY_CLEAR_BREAKPOINT:
      n = sscanf(rw_buffer, "(%d %d)", &reply, &mask);

      if(n != 2) terminate("invalid CLEAR BREAKPOINT reply");

      enable_debug_info(mask, 0);
      break;

    case C_DEBUG_REPLY_LIST_EVENTS:
      str = name_and_length(rw_buffer, &n);
      str[ n ] = '\0';
      str = C_strdup(str);

      for(dip = unseen_dbg_info_list; dip != NULL; dip = dip->next) {
          for(dinfo = dip->info; dinfo->event; ++dinfo) {
              if(*str == '\0' || strstr(dinfo->val, str)) {
                  C_snprintf(rw_buffer, sizeof(rw_buffer), "(* %d %d", dbg_info_count++, dinfo->event);
                  send_string(rw_buffer);
                  send_string_value(dinfo->loc);
                  send_string_value(dinfo->val);
                  send_string(")\n");
              }

              ++n;
          }
      }

      unseen_dbg_info_list = NULL;
      C_free(str);
      break;

    case C_DEBUG_REPLY_GET_BYTES:
      n = sscanf(rw_buffer, "(%d " UWORD_COUNT_FORMAT_STRING " %d)",
                 &reply, &x, &mask);

      if(n != 3) terminate("invalid GET_BYTES reply");

      ptr = (char *)x;

      send_string("(*");

      while(mask--) {
        C_snprintf(rw_buffer, sizeof(rw_buffer), " %u", (unsigned char) *(ptr++));
        send_string(rw_buffer);
      }

      send_string(")\n");
      break;

    case C_DEBUG_REPLY_GET_AV:
      send_string("(*");

      for(n = 0; n < current_c; ++n)
        send_scheme_value(current_av[ n ]);

      send_string(")\n");
      break;

    case C_DEBUG_REPLY_GET_SLOTS:
      sscanf(rw_buffer, "(%d " UWORD_COUNT_FORMAT_STRING ")", &mask, &x);

      if(mask >= C_VALUE_CUTOFF_LIMIT)
        mask = C_VALUE_CUTOFF_LIMIT;

      if((C_header_bits(x) & C_BYTEBLOCK_BIT) != 0) {
        reply = C_header_size(x);
        C_snprintf(rw_buffer, sizeof(rw_buffer), "(* BLOB %d", get_header_bits(x));
        send_string(rw_buffer);

        for(n = 0; n < reply; ++n) {
          C_snprintf(rw_buffer, sizeof(rw_buffer), " %u", ((unsigned char *)C_data_pointer(x))[ n ]);
          send_string(rw_buffer);
        }

        send_string(")\n");
        break;
      }

      n = 0;

      if((C_header_bits(x) & C_SPECIALBLOCK_BIT) != 0) {
        C_snprintf(rw_buffer, sizeof(rw_buffer), "(* SPECIAL %d " UWORD_COUNT_FORMAT_STRING,
            get_header_bits(x), C_block_item(x, 0));
        n = 1;
      }
      else C_snprintf(rw_buffer, sizeof(rw_buffer), "(* VECTOR %d", get_header_bits(x));

      send_string(rw_buffer);

      for(mask = C_header_size(x); n < mask; ++n)
        send_scheme_value(C_block_item(x, n));

      send_string(")\n");
      break;

    case C_DEBUG_REPLY_GET_GLOBAL:
      str = name_and_length(rw_buffer, &n);
      ptr = malloc(sizeof(C_header) + n + 1);
      memcpy(((C_SCHEME_BLOCK*)ptr)->data, str, n + 1);
      ((C_SCHEME_BLOCK *)ptr)->header = C_make_header(C_STRING_TYPE, n);
      x = C_find_symbol((C_word)ptr, NULL);

      if(x == C_SCHEME_FALSE)
        send_string("(* UNKNOWN)\n");
      else {
        send_string("(*");
        send_scheme_value(C_symbol_value(x));
        send_string(")\n");
      }

      break;

    case C_DEBUG_REPLY_GET_STATS:
      stats = C_get_statistics();
      send_string("(*");

      for(n = 0; n < 8; ++n) {
        C_snprintf(rw_buffer, sizeof(rw_buffer), " " UWORD_COUNT_FORMAT_STRING, (C_uword)stats[ n ]);
        send_string(rw_buffer);
      }

      C_snprintf(rw_buffer, sizeof(rw_buffer), " " UWORD_COUNT_FORMAT_STRING ")\n",
          (C_uword)C_stack_pointer);
      send_string(rw_buffer);
      break;

    case C_DEBUG_REPLY_GET_TRACE:
      str = ptr = C_dump_trace(0);

      while((n = C_strcspn(ptr, "\n"))) {
        ptr[ n++ ] = '\0';
        send_string("(* \"");
        send_string(ptr);
        send_string("\")\n");
        ptr += n;
      }

      free(str);
      break;

    default: terminate("invalid reply code");
    }

    event = C_DEBUG_LISTEN;
    val = unseen_dbg_info_list ? "1" : "0";
  }
}


#ifndef _WIN32
static void
interrupt_signal_handler(int signum)
{
    interrupted = 1;
    C_signal(SIGUSR2, interrupt_signal_handler);
}
#endif


static C_word
connect_to_debugger()
{
  char *addr = getenv("CHICKEN_DEBUGGER");
  char *host;
  static char info[ 256 ];
  struct hostent *he;
  struct sockaddr_in sa;
  int i, port = DEFAULT_DEBUGGER_PORT;
  int yes = 1;
  int r;

  C_debugger_hook = debug_event_hook;

  if(addr == NULL) return C_SCHEME_FALSE;      /* no debugger address given */

  /* parse host and port number */
  for(i = C_strlen(addr) - 1; i > 0; --i) {
    if(addr[ i ] == ':') break;
  }

  if(i == 0) host = addr;
  else {
    port = atoi(addr + i + 1);
    host = C_strdup(addr);
    host[i] = '\0';    /* We don't use strndup() for compat reasons */
  }

#ifdef _WIN32
  if(WSAStartup(MAKEWORD(1, 1), &wsa) != 0)
    return C_SCHEME_FALSE; /* failed to init sockets */
#endif

  /* obtain host address */
  he = gethostbyname(host);

  if(he == NULL) return C_SCHEME_FALSE;        /* invalid host */

  C_memset(&sa, 0, sizeof(struct sockaddr_in));
  sa.sin_family = AF_INET;
  sa.sin_port = htons((short)port);
  sa.sin_addr = *((struct in_addr *)he->h_addr);
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);

  if(socket_fd == INVALID_SOCKET)
    return C_SCHEME_FALSE; /* can not create socket */

  /* socket options */
  r = setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, (const char *)&yes, sizeof(int));

  if(r != 0) return C_SCHEME_FALSE;            /* failed to set socket options */

  /* connect */
  if(connect(socket_fd, (struct sockaddr *)&sa, sizeof(struct sockaddr_in)) == SOCKET_ERROR)
    return C_SCHEME_FALSE;                     /* failed to connect */

  C_snprintf(info, sizeof(info), "%s:%d:%d", C_main_argv[ 0 ], getpid(), C_DEBUG_PROTOCOL_VERSION);
  send_event(C_DEBUG_CONNECT, info, NULL, NULL);
#ifndef _WIN32
  C_signal(SIGUSR2, interrupt_signal_handler);
#endif
  return C_SCHEME_TRUE;
}


static C_word
debug_event_hook(C_DEBUG_INFO *cell, C_word c, C_word *av, C_char *cloc)
{
  if(socket_fd != 0) {
    if(cell->enabled || interrupted || ((1 << cell->event) & event_mask) != 0 ) {
      /* fprintf(stderr, "event: %s\n", cloc); */
      current_c = c;
      current_av = av;
      send_event(interrupted ? C_DEBUG_INTERRUPTED : cell->event, cell->loc, cell->val, cloc);
      interrupted = 0;
    }
  }

  return C_SCHEME_UNDEFINED;
}


/* TODO:

    - escape '\"' + '\\' in transmitted strings
    - error-condition (SIGNAL event) doesn't seem to terminate

*/
