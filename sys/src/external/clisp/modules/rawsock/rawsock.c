/*
 * Module for Raw Sockets / CLISP
 * Fred Cohen, 2003-2004
 * Don Cohen, 2003-2004
 * Sam Steingold 2004-2010
 * Bruno Haible 2004-2008
 * <http://www.opengroup.org/onlinepubs/9699919799/basedefs/sys_socket.h.html>
 */

#include "clisp.h"

#include "config.h"

#if defined(HAVE_SYS_TIME_H)
# include <sys/time.h>
#endif
#if defined(HAVE_TIME_H)
# include <time.h>
#endif
#if defined(HAVE_SYS_TYPES_H)
# include <sys/types.h>
#endif
#include <stdio.h>
#if defined(HAVE_UNISTD_H)
# include <unistd.h>
#endif
#include <string.h>            /* for memcpy(3) */
#include <stddef.h>            /* for offsetof */
#if defined(HAVE_SYS_SOCKET_H)
# include <sys/socket.h>
#endif
#if defined(HAVE_NETINET_IN_H)
# include <netinet/in.h>
#endif
#if defined(HAVE_ARPA_INET_H)
# include <arpa/inet.h>
#endif
#if defined(HAVE_LINUX_IF_PACKET_H)
# include <linux/if_packet.h>
#endif
#if defined(HAVE_ASM_TYPES_H)
# include <asm/types.h>
#endif
#if defined(HAVE_LINUX_NETLINK_H)
# include <linux/netlink.h>
#endif
#if defined(HAVE_NET_IF_H)
# include <net/if.h>
#endif
#if defined(HAVE_NETINET_IF_ETHER_H)
# include <netinet/if_ether.h>
#endif
#if defined(HAVE_SYS_IOCTL_H)
# include <sys/ioctl.h>
#endif
#if defined(HAVE_SYS_UN_H)
# include <sys/un.h>
#endif
#if defined(HAVE_ERRNO_H)
# include <errno.h>
#endif
#if defined(HAVE_STROPS_H)
# include <stropts.h>
#endif
#if defined(HAVE_POLL_H)
# include <poll.h>
#endif
#if defined(HAVE_WINSOCK2_H) /* woe32 suckety sucks */
# include <winsock2.h>
# include <ws2tcpip.h>
# define SETSOCKOPT_ARG_T char*
# define CLOSESOCK  closesocket
# define READ(s,b,l)  recv(s,b,l,0)
# define WRITE(s,b,l)  send(s,b,l,0)
#else
# define CLOSESOCK  close
# define READ  read
# define WRITE  write
#endif
#if defined(HAVE_WS2TCPIP_H)
# include <ws2tcpip.h>
#endif
#if defined(HAVE_NETDB_H)
# include <netdb.h>
#endif
#if defined(HAVE_SYS_UIO_H)
# include <sys/uio.h>
#endif
#if defined(HAVE_IFADDRS_H)
# include <ifaddrs.h>
#endif
typedef SOCKET rawsock_t;

DEFMODULE(rawsock,"RAWSOCK")

/* ================== helpers ================== */
/* DANGER: the return value is invalidated by GC! only used by with_buffer_arg
 <> *arg_: vector; on return: simple byte vector, to be pinned
 > STACK_0, STACK_1: END & START -- removed
 > prot: PROT_READ or PROT_READ_WRITE
 < size: how many bytes to use
 < pointer to the buffer start
 removes 2 elements from STACK
 can trigger GC */
static void* parse_buffer_arg (gcv_object_t *arg_, size_t *size, int prot) {
  stringarg sa;
  *arg_ = check_byte_vector(*arg_);
  sa.offset = 0; sa.len = vector_length(*arg_);
  sa.string = *arg_ = array_displace_check(*arg_,sa.len,&sa.offset);
  test_vector_limits(&sa);
  *size = sa.len;
  { void *start_address =
      (void*)(TheSbvector(sa.string)->data + sa.offset + sa.index);
    handle_fault_range(prot,(aint)start_address,(aint)start_address + sa.len);
    return start_address;
  }
}
#define with_buffer_arg(_buffer,_arg_,_size,_prot,_code)  do {  \
    void *_buffer = parse_buffer_arg(_arg_,_size,_prot);        \
    with_pinned_varobject(*_arg_,_code);                        \
  } while(0)

/* DANGER: the return value is invalidated by GC! only used by with_sockaddr_arg
 > type: the expected type
 > arg: the argument
 < size: the data size
 > prot: PROT_READ or PROT_READ_WRITE
 < returns the address of the data area
 can trigger GC */
static void* check_struct_data (object type, gcv_object_t *arg,
                                CLISP_SOCKLEN_T *size, int prot) {
  object vec = TheStructure(*arg = check_classname(*arg,type))->recdata[1];
  *size = Sbvector_length(vec);
  { void *start_address = (void*)(TheSbvector(vec)->data);
    handle_fault_range(prot,(aint)start_address,(aint)start_address + *size);
    return start_address;
  }
}
#define with_sockaddr_arg(_ptr,_arg_,_size,_prot,_code)  do {           \
    struct sockaddr* _ptr =                                             \
      (struct sockaddr*)check_struct_data(`RAWSOCK::SOCKADDR`,          \
                                          _arg_,_size,_prot);           \
    with_pinned_varobject(*_arg_,_code);                                \
  } while(0)

/* check that the arg is a vector of byte vectors
 > *arg_: vector
 > STACK_0, STACK_1: START & END -- removed on success
 < *arg_: may be modified (bad vector elements replaced with byte vectors)
 < return: how many byte vectors arg contains
 removes 2 elements from STACK if success (returns a positive value)
 can trigger GC */
static int check_iovec_arg (gcv_object_t *arg_, uintL *offset) {
  int ii;
  stringarg sa;
  *arg_ = check_vector(*arg_);
  if (array_atype(*arg_) != Atype_T) return -1; /* cannot contain vectors */
  sa.offset = 0; sa.len = vector_length(*arg_);
  sa.string = array_displace_check(*arg_,sa.len,&sa.offset);
  test_vector_limits(&sa);
  *offset = sa.offset;
  for (ii=*offset; ii<sa.len; ii++)
    TheSvector(*arg_)->data[ii] =
      check_byte_vector(TheSvector(*arg_)->data[ii]);
  return sa.len;
}
#if !defined(HAVE_STRUCT_IOVEC)
struct iovec { void *iov_base; size_t iov_len; };
#endif  /* HAVE_STRUCT_IOVEC */
#if !defined(HAVE_READV)        /* emulate readv using read */
static ssize_t readv (rawsock_t sock, const struct iovec *iov, int len) {
  ssize_t retval = 0;
  for (; len--; iov++)
    retval += READ(sock,iov->iov_base,iov->iov_len);
  return retval;
}
#endif
#if !defined(HAVE_WRITEV)       /* emulate writev using write */
static ssize_t writev (rawsock_t sock, const struct iovec *iov, int len) {
  ssize_t retval = 0;
  for (; len--; iov++)
    retval += WRITE(sock,iov->iov_base,iov->iov_len);
  return retval;
}
#endif
/* DANGER: the return value is invalidated by GC!
 this must be called _after_ check_iovec_arg()
 fill the iovec array from the vector of byte vectors
 < vect: (vector (byte-vector))
 < offset: starting offset into vect
 < veclen: number of vect elements to put into buffer
 < buffer: array of struct iovec of length veclen
 < prot: PROT_READ or PROT_READ_WRITE
 > buffer: filled in with data pointers of elements of vect */
#if defined(MULTITHREAD)
#  define PIN_ARG_USE   ,pcv
#  define PIN_ARG_DECL  , pinned_chain_t *pcv
#  define PIN_DECL      pinned_chain_t *pcv
#  define PIN_INIT(len) pcv = (pinned_chain_t*)alloca((len)*sizeof(pinned_chain_t))
#else
#  define PIN_ARG_USE
#  define PIN_ARG_DECL
#  define PIN_DECL
#  define PIN_INIT(len)
#endif
static void fill_iovec (object vect, size_t offset, ssize_t veclen,
                        struct iovec *buffer, int prot PIN_ARG_DECL) {
  gcv_object_t *vec = TheSvector(vect)->data + offset;
  ssize_t pos = veclen;
  for (;pos--; buffer++, vec++) {
    size_t len = vector_length(*vec);
    uintL index = 0;
    object data_vec = array_displace_check(*vec,len,&index);
    pin_varobject_with_pc(&(pcv[pos]),data_vec);
    buffer->iov_len = len;
    buffer->iov_base= TheSbvector(data_vec)->data + index;
    handle_fault_range(prot,(aint)buffer->iov_base,
                       (aint)buffer->iov_base + len);
  }
}

DEFUN(RAWSOCK:SOCKADDR-FAMILY, sa) {
  CLISP_SOCKLEN_T size;
  with_sockaddr_arg(sa,&STACK_0,&size,PROT_READ,
                    VALUES2(check_socket_domain_reverse(sa->sa_family),
                            fixnum(size)));
  skipSTACK(1);
}
DEFUN(RAWSOCK::SOCKADDR-SLOT,&optional slot) {
  /* return offset & size of the slot in SOCKADDR */
 restart_sockaddr_slot:
  if (missingp(STACK_0)) {
    VALUES1(fixnum(sizeof(struct sockaddr)));
  } else if (eq(STACK_0,`:FAMILY`)) {
    struct sockaddr sa;
    VALUES2(fixnum(offsetof(struct sockaddr,sa_family)),
            fixnum(sizeof(sa.sa_family)));
  } else if (eq(STACK_0,`:DATA`)) {
    struct sockaddr sa;
    VALUES2(fixnum(offsetof(struct sockaddr,sa_data)),
            fixnum(sizeof(sa.sa_data)));
  } else {
    pushSTACK(NIL);             /* no PLACE */
    pushSTACK(STACK_1/*slot*/); /* TYPE-ERROR slot DATUM */
    pushSTACK(`(MEMBER :FAMILY :DATA)`); /* TYPE-ERROR slot EXPECTED-TYPE */
    pushSTACK(`RAWSOCK::SOCKADDR`); pushSTACK(STACK_2/*slot*/);
    pushSTACK(TheSubr(subr_self)->name);
    check_value(type_error,GETTEXT("~S: unknown slot ~S for ~S"));
    STACK_0 = value1;
    goto restart_sockaddr_slot;
  }
  skipSTACK(1);
}

/* can trigger GC */
static object make_sockaddr1 (uintL size) {
  pushSTACK(allocate_bit_vector(Atype_8Bit,size));
  funcall(`RAWSOCK::MAKE-SA`,1);
  return value1;
}
#define make_sockaddr()  make_sockaddr1(sizeof(struct sockaddr))

/* can trigger GC */
static object sockaddr_to_lisp (struct sockaddr *sa, uintL size) {
  pushSTACK(allocate_bit_vector(Atype_8Bit,size));
  begin_system_call();
  memcpy(TheSbvector(STACK_0)->data,sa,size);
  end_system_call();
  funcall(`RAWSOCK::MAKE-SA`,1); return value1;
}
#define pushSTACK_sockaddr(sa)  pushSTACK(sa ? sockaddr_to_lisp(sa,sizeof(*sa)) : NIL)

struct pos {
  gcv_object_t *vector;
  unsigned int position;
};
void coerce_into_bytes (void *arg, object element);
void coerce_into_bytes (void *arg, object element) {
  struct pos * pos = (struct pos *)arg;
  uint8 value = I_to_uint8(check_uint8(element));
  TheSbvector(*(pos->vector))->data[pos->position++] = value;
}

DEFUN(RAWSOCK:MAKE-SOCKADDR,family &optional data) {
  int family = check_socket_domain(STACK_1);
  unsigned char *buffer;
  size_t buffer_len, data_start = offsetof(struct sockaddr,sa_data);
  struct pos arg;
  if (missingp(STACK_0)) {      /* standard size */
    buffer_len = sizeof(struct sockaddr) - data_start;
  } else if (posfixnump(STACK_0)) { /* integer data => as if sequence of 0 */
    buffer_len = posfixnum_to_V(STACK_0);
  } else {                      /* data should be a sequence */
    pushSTACK(STACK_0); funcall(L(length),1);
    buffer_len = I_to_uint32(value1);
  }
  pushSTACK(allocate_bit_vector(Atype_8Bit,data_start + buffer_len));
  buffer = (unsigned char *)TheSbvector(STACK_0)->data;
  begin_system_call();
  memset(buffer,0,data_start + buffer_len);
  end_system_call();
  ((struct sockaddr*)buffer)->sa_family = family;
  arg.vector = &(STACK_0); arg.position = data_start;
  if (!missingp(STACK_1) && !posfixnump(STACK_1))
    map_sequence(STACK_1/*data*/,coerce_into_bytes,(void*)&arg);
  funcall(`RAWSOCK::MAKE-SA`,1);
  skipSTACK(2);
}

/* ================== SIGPIPE handling ================== */
#define begin_sock_call()  START_WRITING_TO_SUBPROCESS;  begin_blocking_system_call()
#define end_sock_call()    end_blocking_system_call(); STOP_WRITING_TO_SUBPROCESS

/* report error on the given socket or OS_error if socket<0 */
nonreturning_function(static, rawsock_error, (int socket)) {
  if (socket < 0) OS_error();
  begin_system_call(); {
    int ecode = errno;
    char *msg = strerror(ecode);
    end_system_call();
    pushSTACK(`RAWSOCK::RAWSOCK-ERROR`);    /* error type */
    pushSTACK(S(Kcode));
    pushSTACK(fixnum(errno)); funcall(`OS::ERRNO`,1); pushSTACK(value1);
    pushSTACK(`:MESSAGE`); pushSTACK(safe_to_string(msg));
    pushSTACK(`:SOCKET`); pushSTACK(fixnum(socket));
    funcall(S(make_instance),7);
  }
  pushSTACK(value1); funcall(S(error),1);
  NOTREACHED;
}

/* invoke system call C, place return value in R, report error on socket S */
#define SYSCALL(r,s,c)                                                  \
  do { begin_sock_call(); r = c; end_sock_call();                       \
    if (r == -1) rawsock_error(s);                                      \
  } while(0)

/* ================== arpa/inet.h interface ================== */
/* Define even when the OS lacks the C functions; in that case,
   we emulate the C functions. */
DEFUN(RAWSOCK:HTONL, num) {
  uint32 arg = I_to_uint32(check_uint32(popSTACK()));
  uint32 result;
#if defined(HAVE_HTONL) || defined(WIN32_NATIVE)
  begin_system_call(); result = htonl(arg); end_system_call();
#else
  union { struct { uint8 octet3; uint8 octet2; uint8 octet1; uint8 octet0; } o;
          uint32 all;
        }
        word;
  word.all = arg;
  result = ((uint32)word.o.octet3 << 24) | ((uint32)word.o.octet2 << 16)
           | ((uint32)word.o.octet1 << 8) | (uint32)word.o.octet0;
#endif
  VALUES1(uint32_to_I(result));
}
DEFUN(RAWSOCK:NTOHL, num) {
  uint32 arg = I_to_uint32(check_uint32(popSTACK()));
  uint32 result;
#if defined(HAVE_NTOHL) || defined(WIN32_NATIVE)
  begin_system_call(); result = ntohl(arg); end_system_call();
#else
  union { struct { uint8 octet3; uint8 octet2; uint8 octet1; uint8 octet0; } o;
          uint32 all;
        }
        word;
  word.o.octet3 = (arg >> 24) & 0xff;
  word.o.octet2 = (arg >> 16) & 0xff;
  word.o.octet1 = (arg >> 8) & 0xff;
  word.o.octet0 = arg & 0xff;
  result = word.all;
#endif
  VALUES1(uint32_to_I(result));
}
DEFUN(RAWSOCK:HTONS, num) {
  uint16 arg = I_to_uint16(check_uint16(popSTACK()));
  uint16 result;
#if defined(HAVE_HTONS) || defined(WIN32_NATIVE)
  begin_system_call(); result = htons(arg); end_system_call();
#else
  union { struct { uint8 octet1; uint8 octet0; } o;
          uint16 all;
        }
        word;
  word.all = arg;
  result = ((uint16)word.o.octet1 << 8) | (uint16)word.o.octet0;
#endif
  VALUES1(uint16_to_I(result));
}
DEFUN(RAWSOCK:NTOHS, num) {
  uint16 arg = I_to_uint16(check_uint16(popSTACK()));
  uint16 result;
#if defined(HAVE_NTOHS) || defined(WIN32_NATIVE)
  begin_system_call(); result = ntohs(arg); end_system_call();
#else
  union { struct { uint8 octet1; uint8 octet0; } o;
          uint16 all;
        }
        word;
  word.o.octet1 = (arg >> 8) & 0xff;
  word.o.octet0 = arg & 0xff;
  result = word.all;
#endif
  VALUES1(uint16_to_I(result));
}
DEFUN(RAWSOCK:CONVERT-ADDRESS, family address) {
  int family = check_socket_domain(STACK_1);
 convert_address_restart:
  if (stringp(STACK_0)) {
    with_string_0(STACK_0,Symbol_value(S(utf_8)),ip_address,
                  { value1 = string_to_addr(ip_address); });
  } else if (integerp(STACK_0)) {
    switch (family) {
     #if defined(AF_INET6)
      case AF_INET6: {
        uint64 ip_address;
        UI_to_LEbytes(check_uint64(STACK_0),8*sizeof(uint64),
                      (uintB*)&ip_address);
        value1 = addr_to_string(family,(char*)&ip_address);
      } break;
     #endif
      case AF_INET: {
        uint32 ip_address;
        UI_to_LEbytes(check_uint32(STACK_0),8*sizeof(uint32),
                      (uintB*)&ip_address);
        value1 = addr_to_string(family,(char*)&ip_address);
      } break;
      default: value1 = NIL;
    }
  } else error_string_integer(STACK_0);
  if (nullp(value1)) {
    pushSTACK(NIL);             /* no PLACE */
    pushSTACK(STACK_1);         /* domain */
    pushSTACK(STACK_1);         /* address */
    pushSTACK(TheSubr(subr_self)->name);
    check_value(error_condition,GETTEXT("~S: invalid address ~S for family ~S"));
    STACK_0 = value1;
    goto convert_address_restart;
  }
  skipSTACK(2); mv_count = 1;
}

/* ================== netdb.h interface ================== */
#if defined(HAVE_NETDB_H)
/* return RAWSOCK:PROTOCOL object in value1 */
static Values protoent_to_protocol (struct protoent *pe) {
  pushSTACK(asciz_to_string(pe->p_name,GLO(misc_encoding)));
  push_string_array(pe->p_aliases);
  pushSTACK(sint_to_I(pe->p_proto));
  funcall(`RAWSOCK::MAKE-PROTOCOL`,3);
}
DEFUN(RAWSOCK:PROTOCOL, &optional protocol)
{ /* interface to getprotobyname() et al
     http://www.opengroup.org/onlinepubs/9699919799/functions/getprotoent.html */
  object proto = popSTACK();
  struct protoent *pe = NULL;
  if (missingp(proto)) {        /* get all protocols */
    int count = 0;
    begin_system_call();
#  if defined(HAVE_SETPROTOENT) && defined(HAVE_GETPROTOENT) && defined(HAVE_ENDPROTOENT)
    setprotoent(1);
    while ((pe = getprotoent())) {
      end_system_call();
      protoent_to_protocol(pe); pushSTACK(value1); count++;
      begin_system_call();
    }
    endprotoent();
#  endif
    end_system_call();
    VALUES1(listof(count));
    return;
  } else if (sint_p(proto)) {
#  if defined(HAVE_GETPROTOBYNUMBER) || defined(WIN32_NATIVE)
    begin_system_call();
    pe = getprotobynumber(I_to_sint(proto));
    end_system_call();
#  endif
  } else if (stringp(proto)) {
#  if defined(HAVE_GETPROTOBYNAME) || defined(WIN32_NATIVE)
    with_string_0(proto,GLO(misc_encoding),protoz, {
        begin_system_call();
        pe = getprotobyname(protoz);
        end_system_call();
      });
#  endif
  } else error_string_integer(proto);
  if (pe) protoent_to_protocol(pe);
  else VALUES1(NIL);
}
/* --------------- */
/* return RAWSOCK:NETWORK object in value1 */
static Values netent_to_network (struct netent *ne) {
  pushSTACK(asciz_to_string(ne->n_name,GLO(misc_encoding)));
  push_string_array(ne->n_aliases);
  pushSTACK(sint_to_I(ne->n_addrtype));
  pushSTACK(sint_to_I(ne->n_net));
  funcall(`RAWSOCK::MAKE-NETWORK`,4);
}
DEFUN(RAWSOCK:NETWORK, &optional network type)
{ /* interface to getnetbyname() et al
     http://www.opengroup.org/onlinepubs/9699919799/functions/getnetent.html */
  unsigned int type = check_uint_defaulted(popSTACK(),(unsigned int)-1);
  object net = popSTACK();
  struct netent *ne = NULL;
  if (missingp(net)) {          /* get all networks */
    int count = 0;
#  if defined(HAVE_SETNETENT) && defined(HAVE_GETNETENT) && defined(HAVE_ENDNETENT)
    begin_system_call();
    setnetent(1);
    while ((ne = getnetent())) {
      end_system_call();
      if (type==(unsigned int)-1 || type==ne->n_addrtype) {
        netent_to_network(ne); pushSTACK(value1); count++;
      }
      begin_system_call();
    }
    endnetent();
    end_system_call();
#  endif
    VALUES1(listof(count));
    return;
  } else if (uint_p(net)) {
#  if defined(HAVE_GETNETBYADDR)
    begin_system_call();
    ne = getnetbyaddr(I_to_uint(net),type);
    end_system_call();
#  endif
  } else if (stringp(net)) {
#  if defined(HAVE_GETNETBYNAME)
    with_string_0(net,GLO(misc_encoding),netz, {
        begin_system_call();
        ne = getnetbyname(netz);
        end_system_call();
      });
#  endif
  } else error_string_integer(net);
  if (ne) netent_to_network(ne);
  else VALUES1(NIL);
}
#endif  /* HAVE_NETDB_H */
/* ================== net/if.h interface ================== */
/* http://www.opengroup.org/onlinepubs/9699919799/basedefs/net_if.h.html */
#if defined(HAVE_NET_IF_H)
DEFUN(RAWSOCK:IF-NAME-INDEX, &optional what) {
  if (missingp(STACK_0)) {
    int count = 0;
#  if defined(HAVE_IF_NAMEINDEX) && defined(HAVE_IF_FREENAMEINDEX)
    struct if_nameindex *ifni;
    begin_system_call();
    if ((ifni = if_nameindex()) == NULL) OS_error();
    end_system_call();
    for (; ifni[count].if_index; count++) {
      pushSTACK(allocate_cons());
      Car(STACK_0) = uint_to_I(ifni[count].if_index);
      Cdr(STACK_0) = asciz_to_string(ifni[count].if_name,GLO(misc_encoding));
    }
    begin_system_call(); if_freenameindex(ifni); end_system_call();
#  endif
    VALUES1(listof(count));
  } else if (uint_p(STACK_0)) {
#  if defined(HAVE_IF_INDEXTONAME)
    char name[IF_NAMESIZE];
    begin_system_call();
    if (NULL == if_indextoname(I_to_uint(STACK_0),name)) OS_error();
    end_system_call();
    VALUES1(asciz_to_string(name,GLO(misc_encoding)));
#  else
    pushSTACK(TheSubr(subr_self)->name);
    error(error_condition,GETTEXT("~S: no if_indextoname() at configure time"));
#  endif
  } else if (stringp(STACK_0)) {
#  if defined(HAVE_IF_INDEXTONAME)
    unsigned int idx;
    with_string_0(STACK_0,GLO(misc_encoding),namez, {
        begin_system_call();
        if (0 == (idx = if_nametoindex(namez))) OS_error();
        end_system_call();
      });
    VALUES1(uint_to_I(idx));
#  else
    pushSTACK(TheSubr(subr_self)->name);
    error(error_condition,GETTEXT("~S: no if_nametoindex() at configure time"));
#  endif
  } else error_string_integer(STACK_0);
  skipSTACK(1);
}
#endif  /* net/if.h */
/* ================== ifaddrs.h interface ================== */
#if defined(HAVE_NET_IF_H) && defined(HAVE_IFADDRS_H) && defined(HAVE_GETIFADDRS) && defined(HAVE_FREEIFADDRS)
DEFCHECKER(check_iff,prefix=IFF,bitmasks=both,default=(unsigned)~0,     \
           :UP BROADCAST DEBUG LOOPBACK                                 \
           POINTOPOINT NOTRAILERS RUNNING NOARP PROMISC ALLMULTI        \
           OACTIVE SIMPLEX LINK0 LINK1 LINK2 ALTPHYS POLLING PPROMISC   \
           MONITOR STATICARP NEEDSGIANT                                 \
           MASTER SLAVE MULTICAST PORTSEL AUTOMEDIA DYNAMIC LOWER-UP DORMANT)
DEFUN(RAWSOCK:IFADDRS,&key FLAGS-AND FLAGS-OR) {
  struct ifaddrs *ifap;
  int count = 0;
  unsigned int flags_or = check_iff_of_list(popSTACK());
  unsigned int flags_and = missingp(STACK_0) ? 0 : check_iff_of_list(STACK_0);
  skipSTACK(1);                 /* drop flags_and */
  begin_system_call(); if(-1==getifaddrs(&ifap)) OS_error(); end_system_call();
  for (; ifap; ifap=ifap->ifa_next)
    if ((flags_or & ifap->ifa_flags)
        && ((flags_and & ifap->ifa_flags) == flags_and)) {
      pushSTACK(asciz_to_string(ifap->ifa_name,GLO(misc_encoding)));
      pushSTACK(check_iff_to_list(ifap->ifa_flags));
      pushSTACK_sockaddr(ifap->ifa_addr);
      pushSTACK_sockaddr(ifap->ifa_netmask);
      if (ifap->ifa_flags & IFF_BROADCAST)
        if (ifap->ifa_flags & IFF_POINTOPOINT) {
          pushSTACK(STACK_3);   /* ifa_name */
          pushSTACK(TheSubr(subr_self)->name);
          error(error_condition,GETTEXT("~S: both IFF_BROADCAST and IFF_POINTOPOINT set for ~S"));
        } else pushSTACK_sockaddr(ifap->ifa_broadaddr);
      else if (ifap->ifa_flags & IFF_POINTOPOINT)
        pushSTACK_sockaddr(ifap->ifa_dstaddr);
      else pushSTACK(NIL);
      pushSTACK(ifap->ifa_data ? allocate_fpointer(ifap->ifa_data) : NIL);
      funcall(`RAWSOCK::MAKE-IFADDRS`,6);
      pushSTACK(value1); count++;
    }
  begin_system_call(); freeifaddrs(ifap); end_system_call();
  VALUES1(listof(count));
}
#endif  /* ifaddrs.h */
/* ================== sys/socket.h interface ================== */
DEFCHECKER(check_socket_domain,prefix=AF,default=AF_UNSPEC,             \
           UNSPEC :UNIX LOCAL INET IMPLINK PUP CHAOS AX25 DATAKIT CCITT \
           IPX NS ISO OSI ECMA APPLETALK NETROM BRIDGE ATMPVC X25 INET6 \
           ROSE DECnet NETBEUI SECURITY :KEY NETLINK DLI LAT HYLINK BAN \
           ROUTE PACKET ASH ECONET ATM ATMSVC SNA IRDA NETBIOS VOICEVIEW \
           PPPOX WANPIPE BLUETOOTH FIREFOX CLUSTER 12844 NETDES)
DEFCHECKER(check_socket_type,prefix=SOCK,default=0,   \
           :STREAM DGRAM RAW RDM SEQPACKET PACKET)
DEFCHECKER(check_socket_protocol,default=0,                             \
           IPPROTO-IP IPPROTO-IPV6 IPPROTO-ICMP IPPROTO-RAW IPPROTO-TCP \
           IPPROTO-UDP IPPROTO-IGMP IPPROTO-IPIP IPPROTO-EGP IPPROTO-PUP \
           IPPROTO-IDP IPPROTO-GGP IPPROTO-ND IPPROTO-HOPOPTS           \
           IPPROTO-ROUTING IPPROTO-FRAGMENT IPPROTO-ESP IPPROTO-AH      \
           IPPROTO-ICMPV6 IPPROTO-DSTOPTS IPPROTO-NONE                  \
           IPPROTO-RSVP IPPROTO-GRE IPPROTO-PIM IPPROTO-COMP            \
           NSPROTO-IPX NSPROTO-SPX NSPROTO-SPXII                        \
           NETLINK-ROUTE NETLINK-USERSOCK NETLINK-FIREWALL NETLINK-INET-DIAG \
           NETLINK-NFLOG NETLINK-XFRM NETLINK-SELINUX NETLINK-ISCSI     \
           NETLINK-AUDIT NETLINK-FIB-LOOKUP NETLINK-CONNECTOR           \
           NETLINK-NETFILTER NETLINK-IP6-FW NETLINK-DNRTMSG             \
           NETLINK-KOBJECT-UEVENT NETLINK-GENERIC NETLINK-SCSITRANSPORT \
           NETLINK-ECRYPTFS                                             \
           ETH-P-LOOP ETH-P-PUP ETH-P-PUPAT ETH-P-IP ETH-P-X25 ETH-P-ARP \
           ETH-P-BPQ ETH-P-IEEEPUP ETH-P-IEEEPUPAT ETH-P-DEC ETH-P-DNA-DL \
           ETH-P-DNA-RC ETH-P-DNA-RT ETH-P-LAT ETH-P-DIAG ETH-P-CUST    \
           ETH-P-SCA ETH-P-RARP ETH-P-ATALK ETH-P-AARP ETH-P-IPX ETH-P-IPV6 \
           ETH-P-PPP-DISC ETH-P-PPP-SES ETH-P-ATMMPOA ETH-P-ATMFATE     \
           ETH-P-802-3 ETH-P-AX25 ETH-P-ALL ETH-P-802-2 ETH-P-SNAP      \
           ETH-P-DDCMP ETH-P-WAN-PPP ETH-P-PPP-MP ETH-P-LOCALTALK       \
           ETH-P-PPPTALK ETH-P-TR-802-2 ETH-P-MOBITEX ETH-P-CONTROL     \
           ETH-P-IRDA ETH-P-ECONET)

/* check the protocol - number, string, or constant from check_socket_protocol
 can trigger GC */
static int get_socket_protocol (object proto) {
#if defined(HAVE_GETPROTOBYNAME)
 get_socket_protocol_restart:
  if (stringp(proto)) {
    struct protoent *pe;
    with_string_0(proto,GLO(misc_encoding),protoz, {
        begin_system_call(); pe = getprotobyname(protoz); end_system_call();
      });
    if (pe) return pe->p_proto;
    pushSTACK(NIL);             /* no PLACE */
    pushSTACK(proto); pushSTACK(TheSubr(subr_self)->name);
    check_value(error_condition,GETTEXT("~S: invalid protocol name ~S"));
    proto = value1;
    goto get_socket_protocol_restart;
  } else
#endif
    return check_socket_protocol(proto);
}

DEFUN(RAWSOCK:SOCKET,domain type protocol) {
  rawsock_t sock;
  int protocol = get_socket_protocol(popSTACK());
  int type = check_socket_type(popSTACK());
  int domain = check_socket_domain(popSTACK());
  SYSCALL(sock,-1,socket(domain,type,protocol));
  VALUES1(fixnum(sock));
}

DEFUN(RAWSOCK:SOCKETPAIR,domain type protocol) {
  rawsock_t sock[2];
  int retval;
  int protocol = get_socket_protocol(popSTACK());
  int type = check_socket_type(popSTACK());
  int domain = check_socket_domain(popSTACK());
#if defined(HAVE_SOCKETPAIR)
  SYSCALL(retval,-1,socketpair(domain,type,protocol,sock));
#else /* woe32 et al */
  struct sockaddr_in addr;
  CLISP_SOCKLEN_T sa_size = sizeof(struct sockaddr_in);
  rawsock_t newsock;
  addr.sin_family = domain;
  addr.sin_port = 0;            /* OS will assign an available port */
  addr.sin_addr.s_addr = 16777343; /* 127.0.0.1 */
  SYSCALL(sock[0],-1,socket(domain,type,protocol));
  SYSCALL(sock[1],-1,socket(domain,type,protocol));
  SYSCALL(retval,sock[1],bind(sock[1],(struct sockaddr*)&addr,
                              sizeof(struct sockaddr_in)));
  SYSCALL(retval,sock[1],listen(sock[1],1));
  /* figure out what port was assigned: */
  SYSCALL(retval,sock[1],getsockname(sock[1],(struct sockaddr*)&addr,&sa_size));
  SYSCALL(retval,sock[0],connect(sock[0],(struct sockaddr*)&addr,sa_size));
  SYSCALL(newsock,sock[1],accept(sock[1],(struct sockaddr*)&addr,&sa_size));
  /* do not need the server anymore: */
  SYSCALL(retval,sock[1],CLOSESOCK(sock[1]));
  sock[1] = newsock;
#endif
  VALUES2(fixnum(sock[0]),fixnum(sock[1]));
}

#if defined(HAVE_SOCKATMARK)
DEFUN(RAWSOCK:SOCKATMARK, sock) {
  rawsock_t sock = I_to_uint(check_uint(popSTACK()));
  int retval;
  SYSCALL(retval,sock,sockatmark(sock));
  VALUES_IF(retval);
}
#endif

/* process optional (struct sockaddr*) argument:
   NIL: return NULL
   T: allocate
   SOCKADDR: extract data
 the return value is invalidated by GC, only use in with_opt_sa_arg
 can trigger GC */
static /*maygc*/ struct sockaddr* optional_sockaddr_argument
(gcv_object_t *arg, CLISP_SOCKLEN_T *size PIN_ARG_DECL) {
  if (nullp(*arg)) return NULL;
  else {
    if (eq(T,*arg)) *arg = make_sockaddr();
    struct sockaddr* sa =
      (struct sockaddr*)check_struct_data(`RAWSOCK::SOCKADDR`,
                                          arg,size,PROT_READ_WRITE);
    pin_varobject_with_pc(pcv,*arg);
    return sa;
  }
}
#if defined(MULTITHREAD)
#define with_opt_sa_arg(_sa,_arg_,_size,_code)  do {                    \
    pinned_chain_t pc;                                                  \
    struct sockaddr *sa = optional_sockaddr_argument(_arg_,_size,&pc);  \
    _code;                                                              \
    if (sa) unpin_varobject(pc.pc_varobject);                           \
  } while(0)
#else
#define with_opt_sa_arg(_sa,_arg_,_size,_code)  do {                    \
    struct sockaddr *sa = optional_sockaddr_argument(_arg_,_size);      \
    _code;                                                              \
  } while(0)
#endif

DEFUN(RAWSOCK:ACCEPT,socket sockaddr) {
  rawsock_t sock = I_to_uint(check_uint(STACK_1));
  int retval;
  CLISP_SOCKLEN_T sa_size;
  with_opt_sa_arg(sa,&STACK_0,&sa_size,
                  SYSCALL(retval,sock,accept(sock,sa,&sa_size)));
  VALUES3(fixnum(retval),fixnum(sa_size),STACK_0); skipSTACK(2);
}

DEFUN(RAWSOCK:BIND,socket sockaddr) {
  rawsock_t sock = I_to_uint(check_uint(STACK_1));
  int retval;
  CLISP_SOCKLEN_T size;
  with_sockaddr_arg(sa,&STACK_0,&size,PROT_READ,
                    SYSCALL(retval,sock,bind(sock,sa,size)));
  VALUES0; skipSTACK(2);
}

DEFUN(RAWSOCK:CONNECT,socket sockaddr) {
  rawsock_t sock = I_to_uint(check_uint(STACK_1));
  int retval;
  CLISP_SOCKLEN_T size;
  with_sockaddr_arg(sa,&STACK_0,&size,PROT_READ,
                    SYSCALL(retval,sock,connect(sock,sa,size)));
  VALUES0; skipSTACK(2);
}

DEFUN(RAWSOCK:GETPEERNAME,socket sockaddr) {
  rawsock_t sock = I_to_uint(check_uint(STACK_1));
  int retval;
  CLISP_SOCKLEN_T sa_size;
  with_opt_sa_arg(sa,&STACK_0,&sa_size,
                  SYSCALL(retval,sock,getpeername(sock,sa,&sa_size)));
  VALUES2(STACK_0,fixnum(sa_size)); skipSTACK(2);
}

DEFUN(RAWSOCK:GETSOCKNAME,socket sockaddr) {
  rawsock_t sock = I_to_uint(check_uint(STACK_1));
  int retval;
  CLISP_SOCKLEN_T sa_size;
  with_opt_sa_arg(sa,&STACK_0,&sa_size,
                  SYSCALL(retval,sock,getsockname(sock,sa,&sa_size)));
  VALUES2(STACK_0,fixnum(sa_size)); skipSTACK(2);
}

DEFUN(RAWSOCK:SOCK-LISTEN,socket &optional backlog) {
  int backlog = check_uint_defaulted(popSTACK(),SOMAXCONN);
  rawsock_t sock = I_to_uint(check_uint(popSTACK()));
  int retval;
  SYSCALL(retval,sock,listen(sock,backlog));
  VALUES0;
}

#if defined(WIN32_NATIVE)
nonreturning_function(static, error_missing, (object function)) {
  pushSTACK(function); pushSTACK(TheSubr(subr_self)->name);
  error(error_condition,GETTEXT("~S: your ws2_32.dll does not implement ~S"));
}
#endif

#if defined(HAVE_GAI_STRERROR) || defined(WIN32_NATIVE)
#if defined(WIN32_NATIVE)
typedef char* (WSAAPI *gai_strerror_t) (int);
static char* WSAAPI my_gai_strerror (int ecode)
{ error_missing(`"gai_strerror"`); }
static gai_strerror_t gai_strerror_f = &my_gai_strerror;
#else
# define gai_strerror_f gai_strerror
#endif
DEFCHECKER(check_gai_ecode,prefix=EAI,default=,AGAIN BADFLAGS FAIL FAMILY \
           MEMORY NONAME OVERFLOW SERVICE SOCKTYPE SYSTEM NODATA ADDRFAMILY \
           INPROGRESS CANCELED NOTCANCELED INTR IDN_ENCODE)
#else
# define check_gai_ecode_reverse L_to_I
#endif
nonreturning_function(static, error_eai, (int ecode)) {
  begin_system_call();
#if defined(HAVE_GAI_STRERROR) || defined(WIN32_NATIVE)
  const char* msg = gai_strerror_f(ecode);
#else
  const char* msg = strerror(ecode);
#endif
  end_system_call();
  pushSTACK(`RAWSOCK::EAI`);    /* error type */
  pushSTACK(S(Kcode)); pushSTACK(check_gai_ecode_reverse(ecode));
  pushSTACK(`:MESSAGE`); pushSTACK(safe_to_string(msg));
  funcall(S(make_instance),5);
  pushSTACK(value1); funcall(S(error),1);
  NOTREACHED;
}

#if defined(HAVE_GETNAMEINFO) || defined(WIN32_NATIVE)
#if defined(WIN32_NATIVE)
typedef int (WSAAPI *getnameinfo_t) (const struct sockaddr*,socklen_t,char*,
                                     DWORD,char*,DWORD,int);
static int WSAAPI my_getnameinfo (const struct sockaddr* sa,socklen_t sl,
                                  char* nd,DWORD ndl,char* sv,DWORD svl,int f)
{ error_missing(`"getnameinfo"`); }
static getnameinfo_t getnameinfo_f = &my_getnameinfo;
#else
# define getnameinfo_f getnameinfo
#endif
DEFFLAGSET(getnameinfo_flags, NI_NOFQDN NI_NUMERICHOST NI_NAMEREQD \
           NI_NUMERICSERV NI_NUMERICSCOPE NI_DGRAM)
DEFUN(RAWSOCK:GETNAMEINFO, sockaddr &key NOFQDN NUMERICHOST NAMEREQD \
      NUMERICSERV NUMERICSCOPE DGRAM) {
  int flags = getnameinfo_flags();
  CLISP_SOCKLEN_T size;
  char node[BUFSIZ], service[BUFSIZ];
  int status;
  with_sockaddr_arg(sa,&STACK_0,&size,PROT_READ, {
      begin_sock_call();
      status = getnameinfo_f(sa,size,node,BUFSIZ,service,BUFSIZ,flags);
      end_sock_call();
    });
  if (status) error_eai(status);
  STACK_0 = asciz_to_string(service,GLO(misc_encoding));
  VALUES2(asciz_to_string(node,GLO(misc_encoding)),popSTACK());
}
#endif
#if (defined(HAVE_GETADDRINFO) && defined(HAVE_FREEADDRINFO)) || defined(WIN32_NATIVE)
#if defined(WIN32_NATIVE)
typedef void (WSAAPI *freeaddrinfo_t) (struct addrinfo*);
static void WSAAPI my_freeaddrinfo (struct addrinfo* ai)
{ error_missing(`"freeaddrinfo"`); }
typedef int (WSAAPI *getaddrinfo_t)
  (const char*,const char*, const struct addrinfo*, struct addrinfo**);
static freeaddrinfo_t freeaddrinfo_f = &my_freeaddrinfo;
static int WSAAPI my_getaddrinfo (const char* nd,const char* sv,
                                  const struct addrinfo* hints,
                                  struct addrinfo** ret)
{ error_missing(`"getaddrinfo"`); }
static getaddrinfo_t getaddrinfo_f = &my_getaddrinfo;
#else
# define getaddrinfo_f getaddrinfo
# define freeaddrinfo_f freeaddrinfo
#endif
DEFFLAGSET(addrinfo_flags,AI_PASSIVE AI_CANONNAME AI_NUMERICHOST \
           AI_NUMERICSERV AI_V4MAPPED AI_ALL AI_ADDRCONFIG)
DEFCHECKER(check_addrinfo_flags,prefix=AI,default=0,bitmasks=both,    \
           PASSIVE CANONNAME NUMERICHOST NUMERICSERV V4MAPPED :ALL ADDRCONFIG)
static void call_getaddrinfo (const char* nd,const char* sv,
                              const struct addrinfo* hints,
                              struct addrinfo** ret) {
  int status;
  begin_system_call();
  if ((status = getaddrinfo_f(nd,sv,hints,ret))) error_eai(status);
  end_system_call();
}
DEFUN(RAWSOCK:GETADDRINFO, &key NODE SERVICE PROTOCOL SOCKTYPE FAMILY \
      PASSIVE CANONNAME NUMERICHOST NUMERICSERV V4MAPPED :ALL ADDRCONFIG) {
  struct addrinfo hints = {addrinfo_flags(),
                           check_socket_domain(popSTACK()),
                           check_socket_type(popSTACK()),
                           get_socket_protocol(popSTACK()),
                           0,NULL,NULL,NULL};
  struct addrinfo *ret = NULL, *tmp;
  int valcount = 0;
  if (missingp(STACK_0)) {
    if (missingp(STACK_1))
      call_getaddrinfo(NULL,NULL,&hints,&ret);
    else
      with_string_0(check_string(STACK_1),GLO(misc_encoding),node, {
          call_getaddrinfo(node,NULL,&hints,&ret);
        });
  } else {
    with_string_0(check_string(STACK_0),GLO(misc_encoding),service, {
        if (missingp(STACK_1))
          call_getaddrinfo(NULL,service,&hints,&ret);
        else
          with_string_0(check_string(STACK_1),GLO(misc_encoding),node, {
              call_getaddrinfo(node,service,&hints,&ret);
            });
      });
  }
  for (tmp = ret; tmp; tmp = tmp->ai_next, valcount++) {
    pushSTACK(check_addrinfo_flags_to_list(tmp->ai_flags));
    pushSTACK(check_socket_domain_reverse(tmp->ai_family));
    pushSTACK(check_socket_type_reverse(tmp->ai_socktype));
    pushSTACK(check_socket_protocol_reverse(tmp->ai_protocol));
    pushSTACK(sockaddr_to_lisp(tmp->ai_addr,tmp->ai_addrlen));
    pushSTACK(safe_to_string(tmp->ai_canonname));
    funcall(`RAWSOCK::MAKE-ADDRINFO`,6); pushSTACK(value1);
  }
  if (ret) { begin_system_call(); freeaddrinfo_f(ret); end_system_call(); }
  VALUES1(listof(valcount)); skipSTACK(2);
}
#endif

/* ================== RECEIVING ================== */
/* FIXME: replace this with a complete autoconf check using CL_PROTO() */
#if defined(WIN32_NATIVE)
# define BUF_TYPE_T char*
#else
# define BUF_TYPE_T void*
#endif

/* remove 3 objects from the STACK and return the RECV flag
   based on MSG_PEEK MSG_OOB MSG_WAITALL */
DEFFLAGSET(recv_flags,MSG_PEEK MSG_OOB MSG_WAITALL)
DEFUN(RAWSOCK:RECV,socket buffer &key :START :END PEEK OOB WAITALL) {
  int flags = recv_flags();
  rawsock_t sock = I_to_uint(check_uint(STACK_3));
  int retval;
  size_t buffer_len;
  with_buffer_arg(buffer,&STACK_2,&buffer_len,PROT_READ_WRITE,
                  SYSCALL(retval,sock,recv(sock,(BUF_TYPE_T)buffer,
                                           buffer_len,flags)));
  VALUES1(fixnum(retval)); skipSTACK(2);
}

DEFUN(RAWSOCK:RECVFROM,socket buffer address &key :START :END PEEK OOB WAITALL){
  int flags = recv_flags();
  rawsock_t sock = I_to_uint(check_uint(STACK_4));
  int retval;
  void *buffer;
  size_t buffer_len;
  CLISP_SOCKLEN_T sa_size;
  if (!missingp(STACK_0)) STACK_0 = check_posfixnum(STACK_0);
  if (!missingp(STACK_1)) STACK_1 = check_posfixnum(STACK_1);
  STACK_3 = check_byte_vector(STACK_3);
  with_opt_sa_arg(sa,&STACK_2,&sa_size,
    with_buffer_arg(buffer,&STACK_3,&buffer_len,PROT_READ_WRITE,
      SYSCALL(retval,sock,recvfrom(sock,(BUF_TYPE_T)buffer,
                                   buffer_len,flags,sa,&sa_size))));
  VALUES3(fixnum(retval),fixnum(sa_size),STACK_0); skipSTACK(3);
}

#if defined(HAVE_RECVMSG) && defined(HAVE_SENDMSG) && defined(HAVE_STRUCT_MSGHDR_MSG_FLAGS) && defined(HAVE_STRUCT_MSGHDR_MSG_CONTROL) && defined(HAVE_SYS_UIO_H)
DEFCHECKER(check_msg_flags,prefix=MSG,bitmasks=both,default=0,          \
           OOB PEEK DONTROUTE TRYHARD CTRUNC PROXY TRUNC DONTWAIT EOR   \
           WAITALL FIN SYN CONFIRM RST ERRQUEUE NOSIGNAL MORE)
/* keep this in sync with sock.lisp */
#define MSG_SOCKADDR 1
#define MSG_IOVEC    2
#define MSG_CONTROL  3
#define MSG_FLAGS    4
/* check message structure, return size/offset for iovec & flags
 < STACK_0, STACK_1: START & END, passed to check_iovec_arg() & removed
 < mho -- MESSAGE structure object
 > mho -- same, checked
 > offset -- offset into the iovec
 > mhp -- filled msg_iovlen, msg_flags
 removes 2 elements from STACK
 can trigger GC */
static void check_message (gcv_object_t *mho, uintL *offset, struct msghdr *mhp)
{
  *mho = check_classname(*mho,`RAWSOCK::MESSAGE`);
  TheStructure(*mho)->recdata[MSG_SOCKADDR] =
    check_classname(TheStructure(*mho)->recdata[MSG_SOCKADDR],
                    `RAWSOCK::SOCKADDR`);
  mhp->msg_iovlen =
    check_iovec_arg(&(TheStructure(*mho)->recdata[MSG_IOVEC]),offset);
  TheStructure(*mho)->recdata[MSG_CONTROL] =
    check_byte_vector(TheStructure(*mho)->recdata[MSG_CONTROL]);
  mhp->msg_flags =
    check_msg_flags_of_list(TheStructure(*mho)->recdata[MSG_FLAGS]);
}
/* fill msg_controllen, msg_control, msg_iov, msg_name from mho */
static void fill_msghdr (gcv_object_t *mho, uintL offset, struct msghdr *mhp,
                         int prot  PIN_ARG_DECL) {
  mhp->msg_controllen =
    vector_length(TheStructure(*mho)->recdata[MSG_CONTROL]);
  mhp->msg_control =
    TheSbvector(TheStructure(*mho)->recdata[MSG_CONTROL])->data;
  handle_fault_range(prot,(aint)mhp->msg_control,
                     (aint)mhp->msg_control + mhp->msg_controllen);
  fill_iovec(TheStructure(*mho)->recdata[MSG_IOVEC],offset,mhp->msg_iovlen,
             mhp->msg_iov,prot PIN_ARG_USE);
  pushSTACK(TheStructure(*mho)->recdata[MSG_SOCKADDR]);
  mhp->msg_name = (struct sockaddr*)
    check_struct_data(`RAWSOCK::SOCKADDR`,&STACK_0,&(mhp->msg_namelen),prot);
  pin_varobject_with_pc(&(pcv[mhp->msg_iovlen]),STACK_0);
  TheStructure(*mho)->recdata[MSG_SOCKADDR] = popSTACK();
}
/* POSIX recvmsg() */
DEFUN(RAWSOCK:RECVMSG,socket message &key :START :END PEEK OOB WAITALL) {
  int flags = recv_flags();
  rawsock_t sock = I_to_uint(check_uint(STACK_3));
  int retval;
  struct msghdr message;
  uintL offset;
  PIN_DECL;
  check_message(&STACK_2,&offset,&message);
  message.msg_iov =
    (struct iovec*)alloca(message.msg_iovlen * sizeof(struct iovec));
  PIN_INIT(message.msg_iovlen+1);
  fill_msghdr(&STACK_0,offset,&message,PROT_READ_WRITE PIN_ARG_USE);
  SYSCALL(retval,sock,recvmsg(sock,&message,flags));
  unpin_varobjects(message.msg_iovlen+1);
  TheStructure(STACK_0)->recdata[MSG_FLAGS] =
    check_msg_flags_to_list(message.msg_flags);
  VALUES2(fixnum(retval),fixnum(message.msg_namelen)); skipSTACK(2);
}
#endif  /* HAVE_RECVMSG & HAVE_MSGHDR_MSG_FLAGS & HAVE_MSGHDR_MSG_CONTROL */

DEFUN(RAWSOCK:SOCK-READ,socket buffer &key :START :END)
{ /* http://www.opengroup.org/onlinepubs/9699919799/functions/read.html
     http://www.opengroup.org/onlinepubs/9699919799/functions/readv.html */
  rawsock_t sock = I_to_uint(check_uint(STACK_3));
  ssize_t retval;
  size_t len;
  uintL offset;
  if ((retval = check_iovec_arg(&STACK_2,&offset)) >= 0) { /* READV */
    ssize_t pinned_count = retval;
    struct iovec *buffer = (struct iovec*)alloca(sizeof(struct iovec)*retval);
    PIN_DECL; PIN_INIT(pinned_count);
    fill_iovec(STACK_0,offset,retval,buffer,PROT_READ_WRITE PIN_ARG_USE);
    SYSCALL(retval,sock,readv(sock,buffer,retval));
    unpin_varobjects(pinned_count);
  } else                       /* READ */
    with_buffer_arg(buffer,&STACK_2,&len,PROT_READ_WRITE,
                    SYSCALL(retval,sock,READ(sock,buffer,len)));
  VALUES1(ssize_to_I(retval)); skipSTACK(2);
}

/* ================== SENDING ================== */

/* remove 2 objects from the STACK and return the SEND flag
   based on MSG_OOB MSG_EOR */
DEFFLAGSET(send_flags, MSG_OOB MSG_EOR)
DEFUN(RAWSOCK:SEND,socket buffer &key :START :END OOB EOR) {
  int flags = send_flags();
  rawsock_t sock = I_to_uint(check_uint(STACK_3));
  int retval;
  size_t buffer_len;
  with_buffer_arg(buffer,&STACK_2,&buffer_len,PROT_READ,
                  SYSCALL(retval,sock,send(sock,(const BUF_TYPE_T)buffer,
                                           buffer_len,flags)));
  VALUES1(fixnum(retval)); skipSTACK(2);
}

#if defined(HAVE_RECVMSG) && defined(HAVE_SENDMSG) && defined(HAVE_STRUCT_MSGHDR_MSG_FLAGS) && defined(HAVE_STRUCT_MSGHDR_MSG_CONTROL) && defined(HAVE_SYS_UIO_H)
/* POSIX sendmsg() */
DEFUN(RAWSOCK:SENDMSG,socket message &key :START :END OOB EOR) {
  int flags = send_flags();
  rawsock_t sock = I_to_uint(check_uint(STACK_3));
  int retval;
  struct msghdr message;
  uintL offset;
  PIN_DECL;
  check_message(&STACK_2,&offset,&message);
  message.msg_iov =
    (struct iovec*)alloca(message.msg_iovlen * sizeof(struct iovec));
  PIN_INIT(message.msg_iovlen+1);
  fill_msghdr(&STACK_0,offset,&message,PROT_READ PIN_ARG_USE);
  SYSCALL(retval,sock,sendmsg(sock,&message,flags));
  unpin_varobjects(message.msg_iovlen+1);
  TheStructure(STACK_0)->recdata[MSG_FLAGS] =
    check_msg_flags_to_list(message.msg_flags);
  VALUES1(fixnum(retval)); skipSTACK(2);
}
#endif  /* HAVE_SENDMSG & HAVE_MSGHDR_MSG_FLAGS & HAVE_MSGHDR_MSG_CONTROL */

DEFUN(RAWSOCK:SENDTO, socket buffer address &key :START :END OOB EOR) {
  int flags = send_flags();
  rawsock_t sock = I_to_uint(check_uint(STACK_4));
  int retval;
  size_t buffer_len;
  CLISP_SOCKLEN_T size;
  if (!missingp(STACK_0)) STACK_0 = check_posfixnum(STACK_0);
  if (!missingp(STACK_1)) STACK_1 = check_posfixnum(STACK_1);
  STACK_3 = check_byte_vector(STACK_3);
  with_sockaddr_arg(sa,&STACK_2,&size,PROT_READ,
    with_buffer_arg(buffer,&STACK_3,&buffer_len,PROT_READ,
                    SYSCALL(retval,sock,sendto(sock,(const BUF_TYPE_T)buffer,
                                               buffer_len,flags,sa,size))));
  VALUES1(fixnum(retval)); skipSTACK(3);
}

DEFUN(RAWSOCK:SOCK-WRITE,socket buffer &key :START :END)
{ /* http://www.opengroup.org/onlinepubs/9699919799/functions/write.html
     http://www.opengroup.org/onlinepubs/9699919799/functions/writev.html */
  rawsock_t sock = I_to_uint(check_uint(STACK_3));
  ssize_t retval;
  size_t len;
  uintL offset;
  if ((retval = check_iovec_arg(&STACK_2,&offset)) >= 0) { /* WRITEV */
    ssize_t pinned_count = retval;
    struct iovec *buffer = (struct iovec*)alloca(sizeof(struct iovec)*retval);
    PIN_DECL; PIN_INIT(pinned_count);
    fill_iovec(STACK_0,offset,retval,buffer,PROT_READ PIN_ARG_USE);
    SYSCALL(retval,sock,writev(sock,buffer,retval));
    unpin_varobjects(pinned_count);
  } else                        /* WRITE */
    with_buffer_arg(buffer,&STACK_2,&len,PROT_READ,
                    SYSCALL(retval,sock,WRITE(sock,buffer,len)));
  VALUES1(ssize_to_I(retval)); skipSTACK(2);
}

DEFUN(RAWSOCK:SOCK-CLOSE, socket) {
  rawsock_t sock = I_to_uint(check_uint(popSTACK()));
  int retval;
  SYSCALL(retval,sock,CLOSESOCK(sock));
  VALUES1(fixnum(retval));
}

#if defined(HAVE_NET_IF_H)
/* STACK_1 = ifname, for error reporting */
static void configdev (rawsock_t sock, char* ifname, int ipaddress, int flags) {
  struct ifreq ifrequest;
#if defined(SIOCGIFFLAGS) && defined(SIOCSIFFLAGS)
  memset(&ifrequest, 0, sizeof(struct ifreq));
  strncpy(ifrequest.ifr_name, ifname, IFNAMSIZ);
  if (ioctl(sock, SIOCGIFFLAGS, &ifrequest) < 0)
    OS_file_error(STACK_1);
  ifrequest.ifr_flags |= flags;
  if (ioctl(sock, SIOCSIFFLAGS, &ifrequest) < 0)
    OS_file_error(STACK_1);
#endif
#if defined(SIOCGIFADDR) && defined(SIOCSIFADDR)
  memset(&ifrequest, 0, sizeof(struct ifreq));
  strncpy(ifrequest.ifr_name, ifname, IFNAMSIZ);
  if (ioctl(sock, SIOCGIFADDR, &ifrequest) < 0)
    OS_file_error(STACK_1);
  /* address was 0.0.0.0 -> error */
  if (ipaddress != 0) {
    if (ioctl(sock, SIOCGIFADDR, &ifrequest) < 0)
      OS_file_error(STACK_1);
    else {
      register int j;
      for (j=2;j<6;j++) ifrequest.ifr_addr.sa_data[j] = 0;
      if (ioctl(sock, SIOCSIFADDR, &ifrequest) < 0)
        OS_file_error(STACK_1);
    }
  }
#endif
}

DEFFLAGSET(configdev_flags,IFF_PROMISC IFF_NOARP)
DEFUN(RAWSOCK:CONFIGDEV, socket ifname ipaddress &key PROMISC NOARP) {
  int flags = configdev_flags();
  uint32 ipaddress = I_to_UL(check_uint32(STACK_0));
  rawsock_t sock = I_to_uint(check_uint(STACK_2));
  with_string_0(check_string(STACK_1),Symbol_value(S(utf_8)),ifname, {
      begin_blocking_system_call();
      configdev(sock, ifname, ipaddress, flags);
      end_blocking_system_call();
    });
  VALUES0; skipSTACK(3);
}
#endif  /* HAVE_NET_IF_H */

/* ================== socket options ================== */
#if defined(HAVE_GETSOCKOPT) || defined(HAVE_SETSOCKOPT) || defined(WIN32_NATIVE)
DEFCHECKER(sockopt_level,default=SOL_SOCKET, :ALL=-1 SOL-SOCKET         \
           SOL-IP SOL-IPX SOL-AX25 SOL-ATALK SOL-NETROM SOL-TCP SOL-UDP \
           IPPROTO-IP IPPROTO-IPV6 IPPROTO-ICMP IPPROTO-RAW IPPROTO-TCP \
           IPPROTO-UDP IPPROTO-IGMP IPPROTO-IPIP IPPROTO-EGP IPPROTO-PUP \
           IPPROTO-IDP IPPROTO-GGP IPPROTO-ND IPPROTO-HOPOPTS           \
           IPPROTO-ROUTING IPPROTO-FRAGMENT IPPROTO-ESP IPPROTO-AH      \
           IPPROTO-ICMPV6 IPPROTO-DSTOPTS IPPROTO-NONE)
DEFCHECKER(sockopt_name,default=-1,prefix=SO,                            \
           DEBUG ACCEPTCONN BROADCAST USELOOPBACK PEERCRED              \
           REUSEADDR KEEPALIVE LINGER OOBINLINE SNDBUF RCVBUF :ERROR :TYPE \
           DONTROUTE RCVLOWAT RCVTIMEO SNDLOWAT SNDTIMEO)
#endif
#if defined(HAVE_GETSOCKOPT) || defined(WIN32_NATIVE)
#define GET_SOCK_OPT(opt_type,retform) do {                             \
    opt_type val;                                                       \
    CLISP_SOCKLEN_T len = sizeof(val);                                  \
    int status;                                                         \
    begin_sock_call();                                                  \
    status = getsockopt(sock,level,name,(SETSOCKOPT_ARG_T)&val,&len);   \
    end_sock_call();                                                    \
    if (status==0) return retform;                                      \
    else return (err_p ? OS_file_error(fixnum(sock)),NIL : S(Kerror));  \
  } while(0)
/* can trigger GC */
static object get_sock_opt (rawsock_t sock, int level, int name, int err_p) {
  switch (name) {
#  if defined(SO_DEBUG)
    case SO_DEBUG:
#  endif
#  if defined(SO_ACCEPTCONN)
    case SO_ACCEPTCONN:
#  endif
#  if defined(SO_BROADCAST)
    case SO_BROADCAST:
#  endif
#  if defined(SO_REUSEADDR)
    case SO_REUSEADDR:
#  endif
#  if defined(SO_KEEPALIVE)
    case SO_KEEPALIVE:
#  endif
#  if defined(SO_OOBINLINE)
    case SO_OOBINLINE:
#  endif
#  if defined(SO_DONTROUTE)
    case SO_DONTROUTE:
#  endif
#  if defined(SO_USELOOPBACK)
    case SO_USELOOPBACK:
#  endif
      GET_SOCK_OPT(int,val ? T : NIL);
#  if defined(SO_PEERCRED)
    case SO_PEERCRED:
#  endif
#  if defined(SO_RCVLOWAT)
    case SO_RCVLOWAT:
#  endif
#  if defined(SO_SNDLOWAT)
    case SO_SNDLOWAT:
#  endif
#  if defined(SO_SNDBUF)
    case SO_SNDBUF:
#  endif
#  if defined(SO_RCVBUF)
    case SO_RCVBUF:
#  endif
#  if defined(SO_ERROR)
    case SO_ERROR:
#  endif
      GET_SOCK_OPT(int,sint_to_I(val));
#  if defined(SO_TYPE)
    case SO_TYPE:
      GET_SOCK_OPT(int,check_socket_type_reverse(val));
#  endif
#  if defined(SO_LINGER)
    case SO_LINGER:
      GET_SOCK_OPT(struct linger,val.l_onoff ? sint_to_I(val.l_linger) : NIL);
#  endif
#  if defined(SO_RCVTIMEO)
    case SO_RCVTIMEO:
#  endif
#  if defined(SO_SNDTIMEO)
    case SO_SNDTIMEO:
#  endif
      GET_SOCK_OPT(struct timeval,sec_usec_number(val.tv_sec,val.tv_usec,0));
    default: NOTREACHED;
  }
}
#undef GET_SOCK_OPT
DEFUN(RAWSOCK:SOCKET-OPTION, sock name &key :LEVEL)
{ /* http://www.opengroup.org/onlinepubs/9699919799/functions/getsockopt.html */
  int level = sockopt_level(popSTACK());
  int name = sockopt_name(popSTACK());
  rawsock_t sock;
  stream_handles(popSTACK(),true,NULL,&sock,NULL);
  if (level == -1) {                      /* :ALL */
    int pos1;
    for (pos1=1; pos1 < sockopt_level_map.size; pos1++) {
      const c_lisp_pair_t *level_clp = &(sockopt_level_map.table[pos1]);
      pushSTACK(*(level_clp->l_const));
      if (name == -1) {
        int pos2;
        for (pos2=0; pos2 < sockopt_name_map.size; pos2++) {
          const c_lisp_pair_t *name_clp = &(sockopt_name_map.table[pos2]);
          pushSTACK(*name_clp->l_const);
          pushSTACK(get_sock_opt(sock,level_clp->c_const,name_clp->c_const,0));
        }
        { object tmp = listof(2*sockopt_name_map.size); pushSTACK(tmp); }
      } else
        pushSTACK(get_sock_opt(sock,level_clp->c_const,name,0));
    }
    VALUES1(listof(2*(sockopt_level_map.size-1))); /* skip :ALL */
  } else {
    if (name == -1) {
      int pos2;
      for (pos2=0; pos2 < sockopt_name_map.size; pos2++) {
        const c_lisp_pair_t *name_clp = &(sockopt_name_map.table[pos2]);
        pushSTACK(*(name_clp->l_const));
        pushSTACK(get_sock_opt(sock,level,name_clp->c_const,0));
      }
      VALUES1(listof(2*sockopt_name_map.size));
    } else
      VALUES1(get_sock_opt(sock,level,name,1));
  }
}
#endif
#if defined(HAVE_SETSOCKOPT) || defined(WIN32_NATIVE)
#define SET_SOCK_OPT(opt_type,valform) do {                             \
    int status;                                                         \
    opt_type val; valform;                                              \
    begin_sock_call();                                                  \
    status = setsockopt(sock,level,name,(SETSOCKOPT_ARG_T)&val,sizeof(val)); \
    end_sock_call();                                                    \
    if (status) OS_file_error(fixnum(sock));                            \
    return;                                                             \
  } while(0)
static void set_sock_opt (rawsock_t sock, int level, int name, object value) {
  if (eq(value,S(Kerror))) return;
  switch (name) {
#  if defined(SO_DEBUG)
    case SO_DEBUG:
#  endif
#  if defined(SO_ACCEPTCONN)
    case SO_ACCEPTCONN:
#  endif
#  if defined(SO_BROADCAST)
    case SO_BROADCAST:
#  endif
#  if defined(SO_REUSEADDR)
    case SO_REUSEADDR:
#  endif
#  if defined(SO_KEEPALIVE)
    case SO_KEEPALIVE:
#  endif
#  if defined(SO_OOBINLINE)
    case SO_OOBINLINE:
#  endif
#  if defined(SO_DONTROUTE)
    case SO_DONTROUTE:
#  endif
#  if defined(SO_USELOOPBACK)
    case SO_USELOOPBACK:
#  endif
      SET_SOCK_OPT(int,val=!nullp(value));
#  if defined(SO_PEERCRED)
    case SO_PEERCRED:
#  endif
#  if defined(SO_RCVLOWAT)
    case SO_RCVLOWAT:
#  endif
#  if defined(SO_SNDLOWAT)
    case SO_SNDLOWAT:
#  endif
#  if defined(SO_SNDBUF)
    case SO_SNDBUF:
#  endif
#  if defined(SO_RCVBUF)
    case SO_RCVBUF:
#  endif
#  if defined(SO_ERROR)
    case SO_ERROR:
#  endif
      SET_SOCK_OPT(int,val=I_to_sint32(check_sint32(value)));
#  if defined(SO_TYPE)
    case SO_TYPE:
      SET_SOCK_OPT(int,val=check_socket_type(value));
#  endif
#  if defined(SO_LINGER)
    case SO_LINGER:
      SET_SOCK_OPT(struct linger,
                   if (nullp(value)) val.l_onoff=0;
                   else { val.l_onoff = 1;
                     val.l_linger = I_to_sint32(check_sint32(value));});
#  endif
#  if defined(SO_RCVTIMEO)
    case SO_RCVTIMEO:
#  endif
#  if defined(SO_SNDTIMEO)
    case SO_SNDTIMEO:
#  endif
      SET_SOCK_OPT(struct timeval,sec_usec(value,NIL,&val));
    default: NOTREACHED;
  }
}
#undef SET_SOCK_OPT
/* name=-1   => set many socket options from the plist
   otherwise => set this option
 can trigger GC */
static void set_sock_opt_many (rawsock_t sock, int level, int name,
                               object opt_or_plist) {
  if (name == -1) {
    pushSTACK(opt_or_plist); pushSTACK(opt_or_plist);
    while (!endp(STACK_0)) {
      int name = sockopt_name(Car(STACK_0));
      STACK_0 = Cdr(STACK_0);
      if (!consp(STACK_0)) error_plist_odd(STACK_1);
      set_sock_opt(sock,level,name,Car(STACK_0));
      STACK_0 = Cdr(STACK_0);
    }
    skipSTACK(2);
  } else
    set_sock_opt(sock,level,name,opt_or_plist);
}

DEFUN(RAWSOCK::SET-SOCKET-OPTION, value sock name &key :LEVEL)
{ /* http://www.opengroup.org/onlinepubs/9699919799/functions/setsockopt.html */
  int level = sockopt_level(popSTACK());
  int name = sockopt_name(popSTACK());
  rawsock_t sock;
  stream_handles(popSTACK(),true,NULL,&sock,NULL);
  if (level == -1) {                      /* :ALL */
    pushSTACK(STACK_0);
    while (!endp(STACK_0)) {
      int level = sockopt_level(Car(STACK_0));
      STACK_0 = Cdr(STACK_0);
      if (!consp(STACK_0)) error_plist_odd(STACK_1);
      set_sock_opt_many(sock,level,name,Car(STACK_0));
      STACK_0 = Cdr(STACK_0);
    }
    skipSTACK(1);
  } else
    set_sock_opt_many(sock,level,name,STACK_0);
  VALUES1(popSTACK());
}
#endif

/* ================== CHECKSUM from Fred Cohen ================== */
/* these check sum functions operate on ethernet _frames_, i.e.:
   - 6 bytes of the destination MAC address
   - 6 bytes of the source MAC address
   - 2 bytes specifying the next level protocol (e.g., 0800 for IP)
   followed by an IP datagram, so the first 14 bytes are ignored. */
static unsigned short ipcsum (unsigned char* buffer, size_t length) {
  register long sum=0;          /* assumes long == 32 bits */
  unsigned short result;
  unsigned char *ptr=&(buffer[14]);
  unsigned int nbytes;
  ASSERT(length >= 26);         /* FIXME: is this right?! */
  buffer[24]=0;buffer[25]=0;nbytes=(buffer[14] & 0xF) << 2; /* checksum=0, headerlen */
  while(nbytes>1){sum += *ptr; ptr++; sum += *ptr <<8; ptr++; nbytes -= 2;}
  if(nbytes==1){sum += *ptr;}     /* mop up an odd byte,  if necessary */
  sum = (sum >> 16) + (sum & 0xFFFF);
  result=~(sum  + (sum >> 16)) & 0xFFFF;
  buffer[24]=(result & 0xFF);
  buffer[25]=((result >> 8) & 0xFF);
  return result;
}
DEFUN(RAWSOCK:IPCSUM, buffer &key :START :END) { /* IP checksum */
  size_t length;
  with_buffer_arg(buffer,&STACK_2,&length,PROT_READ_WRITE,
                  length = ipcsum((unsigned char*)buffer,length));
  VALUES1(fixnum(length)); skipSTACK(1);
}

static unsigned short icmpcsum (unsigned char* buffer, size_t length) {
  register long sum=0;          /* assumes long == 32 bits */
  unsigned short result;
  unsigned char *ptr;
  unsigned int nbytes, off, offset;
  ASSERT(length >= 18);                    /* FIXME: is this right?! */
  off=((buffer[14]&0xF)<<2);offset=off+14; /* start of ICMP header */
  buffer[offset+2]=0;buffer[offset+3]=0;
  nbytes=(((buffer[16])<<8)+(buffer[17]))-off; /* bytes in ICMP part */
  ptr=&(buffer[offset]);
  while(nbytes>1){sum += *ptr; ptr++; sum += *ptr <<8; ptr++; nbytes -= 2;}
  if(nbytes==1){sum += *ptr;}     /* mop up an odd byte,  if necessary */
  sum = (sum >> 16) + (sum & 0xFFFF);
  result=~(sum  + (sum >> 16)) & 0xFFFF;
  buffer[offset+2]=(result & 0xFF);
  buffer[offset+3]=((result >> 8) & 0xFF);
  return result;
}
DEFUN(RAWSOCK:ICMPCSUM, buffer &key :START :END) { /* ICMP checksum */
  size_t length;
  with_buffer_arg(buffer,&STACK_2,&length,PROT_READ,
                  length = icmpcsum((unsigned char*)buffer,length));
  VALUES1(fixnum(length)); skipSTACK(1);
}

static unsigned short tcpcsum (unsigned char* buffer, size_t length) {
  register unsigned long sum;  /* assumes long == 32 bits */
  unsigned short result;
  unsigned char *ptr;
  unsigned int nbytes, packsize, offset;
  ASSERT(length >= 34);         /* FIXME: is this right?! */
  sum = (buffer[26]<<8)+ buffer[27]+(buffer[28]<<8)+ buffer[29]; /* Src IP */
  sum +=(buffer[30]<<8)+ buffer[31]+(buffer[32]<<8)+ buffer[33]; /* Dst IP */
  sum +=(buffer[23]);           /* zero followed by protocol */
  packsize=((buffer[16])<<8)+(buffer[17]); /* packet size - not including ARP area */
  offset=((buffer[14]&0xF)<<2); /* start of TCP header (rel to IP header) */
  sum +=(packsize - offset);    /* size of TCP part of the packet */
  ptr=&(buffer[offset+14]);     /* start of TCP header in buffer */
  nbytes=packsize-offset;       /* number of bytes to checksum */
  buffer[offset+16+14]=0;
  buffer[offset+17+14]=0; /* initialize TCP checksum to 0 */
  while(nbytes>1){sum += *ptr<<8; ptr++; sum += *ptr; ptr++; nbytes -= 2;}
  if (nbytes==1) {sum += *ptr<<8;} /* mop up an odd byte,  if necessary */
  sum = (sum >> 16) + (sum & 0xFFFF);
  result=~(sum  + (sum >> 16)) & 0xFFFF;
  buffer[offset+17+14]=(result & 0xFF);
  buffer[offset+16+14]=((result >> 8) & 0xFF);
  return result;
}
DEFUN(RAWSOCK:TCPCSUM, buffer &key :START :END) { /* TCP checksum */
  size_t length;
  with_buffer_arg(buffer,&STACK_2,&length,PROT_READ_WRITE,
                  length = tcpcsum((unsigned char*)buffer,length));
  VALUES1(fixnum(length)); skipSTACK(1);
}

static unsigned short udpcsum (unsigned char* buffer, size_t length) {
  register unsigned long sum = 0;  /* assumes long == 32 bits */
  unsigned short result;
  unsigned char *ptr;
  unsigned int nbytes, packsize, offset;
  ASSERT(length >= 34);         /* FIXME: is this right?! */
  sum = (buffer[26]<<8)+ buffer[27]+(buffer[28]<<8)+ buffer[29]; /* Src IP */
  sum +=(buffer[30]<<8)+ buffer[31]+(buffer[32]<<8)+ buffer[33]; /* Dst IP */
  sum +=(buffer[23]);           /* zero followed by protocol */
  packsize=((buffer[16])<<8)+(buffer[17]); /* packet size */
  offset=((buffer[14]&0xF)<<2);            /* start of UDP header */
  sum +=(((buffer[16])<<8)+(buffer[17])) -offset;
  ptr=&(buffer[offset+14]);     /* start of TCP header */
  nbytes=packsize-offset;
  buffer[offset+6+14]=0;
  buffer[offset+7+14]=0; /* initialize UDP checksum to 0 */
  while(nbytes>1){sum += *ptr <<8; ptr++; sum += *ptr; ptr++; nbytes -= 2;}
  if (nbytes==1) {sum += *ptr<<8;} /* mop up an odd byte, if necessary */
  sum = (sum >> 16) + (sum & 0xFFFF);
  result=~(sum  + (sum >> 16)) & 0xFFFF;
  buffer[offset+7+14]=(result & 0xFF);
  buffer[offset+6+14]=((result >> 8) & 0xFF);
  return result;
}
DEFUN(RAWSOCK:UDPCSUM, buffer &key :START :END) { /* UDP checksum */
  size_t length;
  with_buffer_arg(buffer,&STACK_2,&length,PROT_READ_WRITE,
                  length = udpcsum((unsigned char*)buffer,length));
  VALUES1(fixnum(length)); skipSTACK(1);
}

#ifdef __GNUC__ /* to prevent a gcc-warning "statement with no effect" */
# define unused  (void)
#else
# define unused
#endif

void module__rawsock__init_function_2 (module_t* module);
void module__rawsock__init_function_2 (module_t* module) {
  unused module;
#if defined(WIN32_NATIVE)
  HMODULE ws2 = LoadLibrary("ws2_32.dll");
  if (ws2 != NULL) {
    freeaddrinfo_f = (freeaddrinfo_t) GetProcAddress(ws2,"freeaddrinfo");
    getaddrinfo_f = (getaddrinfo_t) GetProcAddress(ws2,"getaddrinfo");
    getnameinfo_f = (getnameinfo_t) GetProcAddress(ws2,"getnameinfo");
    gai_strerror_f = (gai_strerror_t) GetProcAddress(ws2,"gai_strerror");
  }
#endif
}
