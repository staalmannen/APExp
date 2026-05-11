;;;; tcp.scm - Networking stuff
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


(declare
  (unit tcp)
  (uses port scheduler)
  (disable-interrupts) ; Avoid race conditions around errno/WSAGetLastError
  (foreign-declare #<<EOF
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

EOF
) )

(module chicken.tcp
  (tcp-close tcp-listen tcp-connect tcp-accept tcp-accept-ready?
   tcp-listener? tcp-addresses tcp-abandon-port tcp-listener-port
   tcp-listener-fileno tcp-port-numbers tcp-buffer-size tcp-read-timeout
   tcp-write-timeout tcp-accept-timeout tcp-connect-timeout)

(import scheme
	chicken.base
	chicken.fixnum
	chicken.foreign
	chicken.port
	chicken.time)

(include "common-declarations.scm")


(define-foreign-type sockaddr* (pointer "struct sockaddr"))
(define-foreign-type sockaddr_in* (pointer "struct sockaddr_in"))

(define-foreign-variable _af_inet int "AF_INET")
(define-foreign-variable _sock_stream int "SOCK_STREAM")
(define-foreign-variable _sock_dgram int "SOCK_DGRAM")
(define-foreign-variable _sockaddr_size int "sizeof(struct sockaddr)")
(define-foreign-variable _sockaddr_in_size int "sizeof(struct sockaddr_in)")
(define-foreign-variable _shut_rd int "SHUT_RD")
(define-foreign-variable _shut_wr int "SHUT_WR")
(define-foreign-variable _ipproto_tcp int "IPPROTO_TCP")
(define-foreign-variable _invalid_socket int "INVALID_SOCKET")
(define-foreign-variable _socket_error int "SOCKET_ERROR")

(define last-error-code (foreign-lambda int "get_last_socket_error"))
(define error-code->message (foreign-lambda c-string "errormsg_from_code" int))
(define retry? (foreign-lambda bool "should_retry_call"))
(define in-progress? (foreign-lambda bool "call_in_progress"))
(define interrupted? (foreign-lambda bool "call_was_interrupted"))
(define socket (foreign-lambda int "socket" int int int))
(define bind (foreign-lambda int "bind" int scheme-pointer int))
(define listen (foreign-lambda int "listen" int int))
(define accept (foreign-lambda int "accept" int c-pointer c-pointer))
(define close (foreign-lambda int "closesocket" int))
(define recv (foreign-lambda int "recv" int scheme-pointer int int))
(define shutdown (foreign-lambda int "shutdown" int int))
(define connect (foreign-lambda int "connect" int scheme-pointer int))
(define check-fd-ready (foreign-lambda int "C_check_fd_ready" int))
(define set-socket-options (foreign-lambda int "C_set_socket_options" int))

(define send
  (foreign-lambda* 
      int ((int s) (scheme-pointer msg) (int offset) (int len) (int flags))
    "C_return(send(s, (char *)msg+offset, len, flags));"))

(define getsockname
  (foreign-lambda* c-string ((int s))
    "struct sockaddr_in sa;"
    "unsigned char *ptr;"
    "int len = sizeof(struct sockaddr_in);"
    "if(getsockname(s, (struct sockaddr *)&sa, (socklen_t *)&len) != 0) C_return(NULL);"
    "ptr = (unsigned char *)&sa.sin_addr;"
    "C_snprintf(addr_buffer, sizeof(addr_buffer), \"%d.%d.%d.%d\", ptr[ 0 ], ptr[ 1 ], ptr[ 2 ], ptr[ 3 ]);"
    "C_return(addr_buffer);") )

(define getsockport
  (foreign-lambda* int ((int s))
    "struct sockaddr_in sa;"
    "int len = sizeof(struct sockaddr_in);"
    "if(getsockname(s, (struct sockaddr *)&sa, (socklen_t *)(&len)) != 0) C_return(-1);"
    "else C_return(ntohs(sa.sin_port));") )

(define getpeerport
 (foreign-lambda* int ((int s))
   "struct sockaddr_in sa;"
   "int len = sizeof(struct sockaddr_in);"
   "if(getpeername(s, (struct sockaddr *)&sa, (socklen_t *)(&len)) != 0) C_return(-1);"
   "else C_return(ntohs(sa.sin_port));") )

(define getpeername
  (foreign-lambda* c-string ((int s))
    "struct sockaddr_in sa;"
    "unsigned char *ptr;"
    "unsigned int len = sizeof(struct sockaddr_in);"
    "if(getpeername(s, (struct sockaddr *)&sa, ((socklen_t *)&len)) != 0) C_return(NULL);"
    "ptr = (unsigned char *)&sa.sin_addr;"
    "C_snprintf(addr_buffer, sizeof(addr_buffer), \"%d.%d.%d.%d\", ptr[ 0 ], ptr[ 1 ], ptr[ 2 ], ptr[ 3 ]);"
    "C_return(addr_buffer);") )

(define startup
  (foreign-lambda* bool () #<<EOF
#ifdef _WIN32
     C_return(WSAStartup(MAKEWORD(1, 1), &wsa) == 0);
#else
     signal(SIGPIPE, SIG_IGN);
     C_return(1);
#endif
EOF
) )

(unless (startup)
  (##sys#signal-hook #:network-error "cannot initialize Winsock") )

(define getservbyname
  (foreign-lambda* int ((c-string serv) (c-string proto))
    "struct servent *se;
     if((se = getservbyname(serv, proto)) == NULL) C_return(0);
     else C_return(ntohs(se->s_port));") )     

(define gethostaddr
  (foreign-lambda* bool ((nonnull-scheme-pointer saddr) (c-string host) (unsigned-short port))
    "struct hostent *he = gethostbyname(host);"
    "struct sockaddr_in *addr = (struct sockaddr_in *)saddr;"
    "if(he == NULL) C_return(0);"
    "memset(addr, 0, sizeof(struct sockaddr_in));"
    "addr->sin_family = AF_INET;"
    "addr->sin_port = htons((short)port);"
    "addr->sin_addr = *((struct in_addr *)he->h_addr);"
    "C_return(1);") )

(define-syntax network-error
  (syntax-rules ()
    ((_ loc msg . args)
     (network-error/code loc (last-error-code) msg . args))))

(define-syntax network-error/close
  (syntax-rules ()
    ((_ loc msg socket . args)
     (let ((error-code (last-error-code)))
       (close socket)
       (network-error/code loc error-code msg socket . args)))))

(define-syntax network-error/code
  (syntax-rules ()
    ((_ loc error-code msg . args)
     (##sys#signal-hook #:network-error loc
			(string-append (string-append msg " - ")
				       (error-code->message error-code))
			. args))))

(define parse-host
  (let ((substring substring))
    (lambda (host proto)
      (let ((len (##sys#size host)))
	(let loop ((i 0))
	  (if (fx>= i len)
	      (values host #f)
	      (let ((c (##core#inline "C_subchar" host i)))
		(if (char=? c #\:)		    
		    (values
		     (substring host (fx+ i 1) len)
		     (let* ((s (substring host 0 i))
			    (p (getservbyname s proto)))
		       (when (eq? 0 p)
			 (network-error 'tcp-connect "cannot compute port from service" s) )
		       p) )
		    (loop (fx+ i 1)) ) ) ) ) ) ) ) )

(define fresh-addr
  (foreign-lambda* void ((nonnull-scheme-pointer saddr) (unsigned-short port))
    "struct sockaddr_in *addr = (struct sockaddr_in *)saddr;"
    "memset(addr, 0, sizeof(struct sockaddr_in));"
    "addr->sin_family = AF_INET;"
    "addr->sin_port = htons(port);"
    "addr->sin_addr.s_addr = htonl(INADDR_ANY);") )

(define (bind-socket style host port)
  (let ((addr (make-string _sockaddr_in_size)))
    (if host
	(unless (gethostaddr addr host port)
	  (##sys#signal-hook 
	   #:network-error 'tcp-listen 
	   "getting listener host IP failed" host port) )
	(fresh-addr addr port) )
    (let ((s (socket _af_inet style 0)))
      (when (eq? _invalid_socket s)
	(##sys#error "cannot create socket") )
      ;; PLT makes this an optional arg to tcp-listen. Should we as well?
      (when (eq? _socket_error (set-socket-options s))
	(network-error 'tcp-listen "error while setting up socket" s) )
      (when (eq? _socket_error (bind s addr _sockaddr_in_size))
	(network-error/close 'tcp-listen "cannot bind to socket" s host port) )
      s)) )

(define-constant default-backlog 100)

(define (tcp-listen port #!optional (backlog default-backlog) host)
  (##sys#check-fixnum port)
  (when (or (fx< port 0) (fx> port 65535))
    (##sys#signal-hook #:domain-error 'tcp-listen "invalid port number" port) )
  (##sys#check-fixnum backlog)
  (let ((s (bind-socket _sock_stream host port)))
    (when (eq? _socket_error (listen s backlog))
      (network-error/close 'tcp-listen "cannot listen on socket" s port) )
    (##sys#make-structure 'tcp-listener s) ) )

(define (tcp-listener? x) 
  (and (##core#inline "C_blockp" x)
       (##sys#structure? x 'tcp-listener) ) )

(define (tcp-close tcpl)
  (##sys#check-structure tcpl 'tcp-listener)
  (let ((s (##sys#slot tcpl 1)))
    (when (eq? _socket_error (close s))
      (network-error 'tcp-close "cannot close TCP socket" tcpl) ) ) )

(define-constant +input-buffer-size+ 1024)
(define-constant +output-chunk-size+ 8192)

(define tcp-buffer-size (make-parameter #f))
(define tcp-read-timeout)
(define tcp-write-timeout)
(define tcp-connect-timeout)
(define tcp-accept-timeout)

(let ()
  (define ((check loc) x)
    (when x (##sys#check-fixnum x loc))
    x)
  (define minute (fx* 60 1000))
  (set! tcp-read-timeout (make-parameter minute (check 'tcp-read-timeout)))
  (set! tcp-write-timeout (make-parameter minute (check 'tcp-write-timeout))) 
  (set! tcp-connect-timeout (make-parameter #f (check 'tcp-connect-timeout))) 
  (set! tcp-accept-timeout (make-parameter #f (check 'tcp-accept-timeout))) )

(define io-ports
  (let ((tbs tcp-buffer-size))
    (lambda (loc fd)
      (unless (##core#inline "make_socket_nonblocking" fd)
	(network-error/close loc "cannot create TCP ports" fd) )
      (let* ((buf (make-string +input-buffer-size+))
	     (data (vector fd #f #f buf 0))
	     (buflen 0)
	     (bufindex 0)
	     (iclosed #f) 
	     (oclosed #f)
	     (outbufsize (tbs))
	     (outbuf (and outbufsize (fx> outbufsize 0) ""))
	     (read-input
	      (lambda ()
		(let* ((tmr (tcp-read-timeout))
		       (dlr (and tmr (+ (current-process-milliseconds) tmr))))
		  (let loop ()
		    (let ((n (recv fd buf +input-buffer-size+ 0)))
		      (cond ((eq? _socket_error n)
			     (cond ((retry?)
				    (when dlr
				      (##sys#thread-block-for-timeout!
				       ##sys#current-thread dlr) )
				    (##sys#thread-block-for-i/o! ##sys#current-thread fd #:input)
				    (##sys#thread-yield!)
				    (when (##sys#slot ##sys#current-thread 13)
				      (##sys#signal-hook
				       #:network-timeout-error
				       "read operation timed out" tmr fd) )
				    (loop) )
				   ((interrupted?)
				    (##sys#dispatch-interrupt loop))
				   (else
				    (network-error #f "cannot read from socket" fd) ) ) )
			    (else
			     (set! buflen n)
			     (##sys#setislot data 4 n)
			     (set! bufindex 0) ) ) ) )) ) )
	     (in
	      (make-input-port
	       (lambda ()
		 (when (fx>= bufindex buflen)
		   (read-input))
		 (if (fx>= bufindex buflen)
		     #!eof
		     (let ((c (##core#inline "C_subchar" buf bufindex)))
		       (set! bufindex (fx+ bufindex 1))
		       c) ) )
	       (lambda ()
		 (or (fx< bufindex buflen)
		     ;; XXX: This "knows" that check_fd_ready is
		     ;; implemented using a winsock2 call on Windows
		     (let ((f (check-fd-ready fd)))
		       (when (eq? _socket_error f)
			 (network-error #f "cannot check socket for input" fd) )
		       (eq? f 1) ) ) )
	       (lambda ()
		 (unless iclosed
		   (set! iclosed #t)
		   (unless (##sys#slot data 1) (shutdown fd _shut_rd))
		   (when (and oclosed (eq? _socket_error (close fd)))
		     (network-error #f "cannot close socket input port" fd) ) ) )
	       (lambda ()
		 (when (fx>= bufindex buflen)
		   (read-input))
		 (if (fx< bufindex buflen)
		     (##core#inline "C_subchar" buf bufindex)
		     #!eof))
	       (lambda (p n dest start)	; read-string!
		 (let loop ((n n) (m 0) (start start))
		   (cond ((eq? n 0) m)
			 ((fx< bufindex buflen)
			  (let* ((rest (fx- buflen bufindex))
				 (n2 (if (fx< n rest) n rest)))
			    (##core#inline "C_substring_copy" buf dest bufindex (fx+ bufindex n2) start)
			    (set! bufindex (fx+ bufindex n2))
			    (loop (fx- n n2) (fx+ m n2) (fx+ start n2)) ) )
			 (else
			  (read-input)
			  (if (eq? buflen 0) 
			      m
			      (loop n m start) ) ) ) ) )
	       (lambda (p limit)	; read-line
		 (when (fx>= bufindex buflen)
		   (read-input))
		 (if (fx>= bufindex buflen)
		     #!eof
		     (let ((limit (or limit (fx- most-positive-fixnum bufindex))))
		       (receive (next line full-line?)
			   (##sys#scan-buffer-line
			    buf
			    (fxmin buflen (fx+ bufindex limit))
			    bufindex
			    (lambda (pos)
			      (let ((nbytes (fx- pos bufindex)))
				(cond ((fx>= nbytes limit)
				       (values #f pos #f))
				      (else (read-input)
					    (set! limit (fx- limit nbytes))
					    (if (fx< bufindex buflen)
						(values buf bufindex
							(fxmin buflen
							       (fx+ bufindex limit)))
						(values #f bufindex #f))))) ) )
			 ;; Update row & column position
			 (if full-line?
			     (begin
			       (##sys#setislot p 4 (fx+ (##sys#slot p 4) 1))
			       (##sys#setislot p 5 0))
			     (##sys#setislot p 5 (fx+ (##sys#slot p 5)
						      (##sys#size line))))
			 (set! bufindex next)
			 line) )) )
	       (lambda (p)		; read-buffered
		 (if (fx>= bufindex buflen)
		     ""
		     (let ((str (##sys#substring buf bufindex buflen)))
		       (set! bufindex buflen)
		       str)))
	       ) )
	     (output
	      (lambda (s)
		(let ((tmw (tcp-write-timeout)))
		  (let loop ((len (##sys#size s))
			     (offset 0)
			     (dlw (and tmw (+ (current-process-milliseconds) tmw))))
		    (let* ((count (fxmin +output-chunk-size+ len))
			   (n (send fd s offset count 0)))
		      (cond ((eq? _socket_error n)
			     (cond ((retry?)
				    (when dlw
				      (##sys#thread-block-for-timeout!
				       ##sys#current-thread dlw) )
				    (##sys#thread-block-for-i/o! ##sys#current-thread fd #:output)
				    (##sys#thread-yield!)
				    (when (##sys#slot ##sys#current-thread 13)
				      (##sys#signal-hook
				       #:network-timeout-error
				       "write operation timed out" tmw fd) )
				    (loop len offset dlw) )
				   ((interrupted?)
				    (##sys#dispatch-interrupt
				     (cut loop len offset dlw)))
				   (else
				    (network-error #f "cannot write to socket" fd) ) ) )
			    ((fx< n len)
			     (loop (fx- len n) (fx+ offset n)
				   (if (fx= n 0)
				       tmw
				       ;; If we wrote *something*, reset timeout
				       (and tmw (+ (current-process-milliseconds) tmw)) )) ) ) ) )) ) )
	     (out
	      (make-output-port
	       (if outbuf
		   (lambda (s)
		     (set! outbuf (##sys#string-append outbuf s))
		     (when (fx>= (##sys#size outbuf) outbufsize)
		       (output outbuf)
		       (set! outbuf "") ) )
		   (lambda (s) 
		     (when (fx> (##sys#size s) 0)
		       (output s)) ) )
	       (lambda ()
		 (unless oclosed
		   (set! oclosed #t)
		   (when (and outbuf (fx> (##sys#size outbuf) 0))
		     (output outbuf)
		     (set! outbuf "") )
		   (unless (##sys#slot data 2) (shutdown fd _shut_wr))
		   (when (and iclosed (eq? _socket_error (close fd)))
		     (network-error #f "cannot close socket output port" fd) ) ) )
	       (and outbuf
		    (lambda ()
		      (when (fx> (##sys#size outbuf) 0)
			(output outbuf)
			(set! outbuf "") ) ) ) ) ) )
	(##sys#setslot in 3 "(tcp)")
	(##sys#setslot out 3 "(tcp)")
	(##sys#setslot in 7 'socket)
	(##sys#setslot out 7 'socket)
	(##sys#set-port-data! in data)
	(##sys#set-port-data! out data)
	(values in out) ) ) ) )

(define (tcp-accept tcpl)
  (##sys#check-structure tcpl 'tcp-listener)
  (let* ((fd (##sys#slot tcpl 1))
	 (tma (tcp-accept-timeout))
	 (dla (and tma (+ tma (current-process-milliseconds)))))
    (let loop ()
      (when dla
	(##sys#thread-block-for-timeout! ##sys#current-thread dla) )
      (##sys#thread-block-for-i/o! ##sys#current-thread fd #:input)
      (##sys#thread-yield!)
      (if (##sys#slot ##sys#current-thread 13)
	  (##sys#signal-hook
	   #:network-timeout-error
	   'tcp-accept
	   "accept operation timed out" tma fd) )
      (let ((fd (accept fd #f #f)))
	(cond ((not (eq? _invalid_socket fd))
	       (io-ports 'tcp-accept fd))
	      ((interrupted?)
	       (##sys#dispatch-interrupt loop))
	      (else
	       (network-error 'tcp-accept "could not accept from listener" tcpl)))) ) ) )

(define (tcp-accept-ready? tcpl)
  (##sys#check-structure tcpl 'tcp-listener 'tcp-accept-ready?)
  ;; XXX: This "knows" that check_fd_ready is implemented using a winsock2 call
  (let ((f (check-fd-ready (##sys#slot tcpl 1))))
    (when (eq? _socket_error f)
      (network-error 'tcp-accept-ready? "cannot check socket for input" tcpl) )
    (eq? 1 f) ) )

(define get-socket-error
  (foreign-lambda* int ((int socket))
    "int err, optlen;"
    "optlen = sizeof(err);"
    "if (typecorrect_getsockopt(socket, SOL_SOCKET, SO_ERROR, &err, (socklen_t *)&optlen) == SOCKET_ERROR)"
    "  C_return(SOCKET_ERROR);"
    "C_return(err);"))

(define (tcp-connect host . more)
  (let* ((port (optional more #f))
	 (tmc (tcp-connect-timeout))
	 (dlc (and tmc (+ (current-process-milliseconds) tmc)))
	 (addr (make-string _sockaddr_in_size)))
    (##sys#check-string host)
    (unless port
      (set!-values (host port) (parse-host host "tcp"))
      (unless port (##sys#signal-hook #:domain-error 'tcp-connect "no port specified" host)) )
    (##sys#check-fixnum port)
    (unless (gethostaddr addr host port)
      (##sys#signal-hook #:network-error 'tcp-connect "cannot find host address" host) )
    (let ((s (socket _af_inet _sock_stream 0)))
      (when (eq? _invalid_socket s)
	(network-error 'tcp-connect "cannot create socket" host port) )
      (when (eq? _socket_error (set-socket-options s))
	(network-error/close 'tcp-connect "error while setting up socket" s) )
      (unless (##core#inline "make_socket_nonblocking" s)
	(network-error/close 'tcp-connect "fcntl() failed" s) )
      (let loop ()
	(when (eq? _socket_error (connect s addr _sockaddr_in_size))
	  (cond ((in-progress?) ; Wait till it's available via select/poll
		 (when dlc
		   (##sys#thread-block-for-timeout! ##sys#current-thread dlc))
		 (##sys#thread-block-for-i/o! ##sys#current-thread s #:output)
		 (##sys#thread-yield!)) ; Don't loop: it's connected now
		((interrupted?)
		 (##sys#dispatch-interrupt loop))
		(else
		 (network-error/close
		  'tcp-connect "cannot connect to socket" s host port)))))
      (let ((err (get-socket-error s)))
	(cond ((eq? _socket_error err)
	       (network-error/close 'tcp-connect "getsockopt() failed" s))
	      ((fx> err 0)
	       (close s)
	       (network-error/code 'tcp-connect err "cannot create socket"))))
      (io-ports 'tcp-connect s))) )

(define (tcp-port->fileno p loc)
  (let ((data (##sys#port-data p)))
    (if (vector? data)			; a meagre test, but better than nothing
	(##sys#slot data 0)
	(error loc "argument does not appear to be a TCP port" p))))

(define (tcp-addresses p)
  (##sys#check-open-port p 'tcp-addresses)
  (let ((fd (tcp-port->fileno p 'tcp-addresses)))
    (values 
     (or (getsockname fd)
	 (network-error 'tcp-addresses "cannot compute local address" p) )
     (or (getpeername fd)
	 (network-error 'tcp-addresses "cannot compute remote address" p) ) ) ) )

(define (tcp-port-numbers p)
  (##sys#check-open-port p 'tcp-port-numbers)
  (let ((fd (tcp-port->fileno p 'tcp-port-numbers)))
    (let ((sp (getsockport fd))
	  (pp (getpeerport fd)))
      (when (eq? -1 sp)
	(network-error 'tcp-port-numbers "cannot compute local port" p) )
      (when (eq? -1 pp)
	(network-error 'tcp-port-numbers "cannot compute remote port" p) )
      (values sp pp))))

(define (tcp-listener-port tcpl)
  (##sys#check-structure tcpl 'tcp-listener 'tcp-listener-port)
  (let* ((fd (##sys#slot tcpl 1))
	 (port (getsockport fd)))
    (when (eq? -1 port)
      (network-error 'tcp-listener-port "cannot obtain listener port" tcpl fd) )
    port) )

(define (tcp-abandon-port p)
  (##sys#check-open-port p 'tcp-abandon-port)
  (##sys#setislot (##sys#port-data p) (##sys#slot p 1) #t))

(define (tcp-listener-fileno l)
  (##sys#check-structure l 'tcp-listener 'tcp-listener-fileno)
  (##sys#slot l 1) )

)
