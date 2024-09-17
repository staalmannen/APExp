/* An emulation for socket.h header for pc/ systems.  */
/*
 * Copyright (C) 2013, 2016, the Free Software Foundation, Inc.
 *
 * This file is part of GAWK, the GNU implementation of the
 * AWK Programming Language.
 *
 * GAWK is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * GAWK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#ifndef GAWK_SOCKET_H
#define GAWK_SOCKET_H

#ifdef __MINGW32__

#include <io.h>

#if !defined _WIN32_WINNT || _WIN32_WINNT < 0x501
# undef _WIN32_WINNT
# define _WIN32_WINNT 0x501
#endif
#include <winsock2.h>
#include <ws2tcpip.h>

#define socket(f,t,p)		w32_socket(f,t,p)
#define setsockopt(f,l,o,v,s)	w32_setsockopt(f,l,o,v,s)
#define bind(f,a,l)		w32_bind(f,a,l)
#define connect(f,a,l)		w32_connect(f,a,l)
#define listen(f,b)		w32_listen(f,b)
#define accept(f,a,l)		w32_accept(f,a,l)
#define closemaybesocket(f)	w32_closesocket(f)
#define recvfrom(f,b,l,fl,fr,ln)	w32_recvfrom(f,b,l,fl,fr,ln)
#define shutdown(f,h)		w32_shutdown(f,h)

#define SOCKET_TO_FD(s)		socket_to_fd(s)
#define FD_TO_SOCKET(fd) \
  ((fd) == INVALID_HANDLE ? INVALID_SOCKET : _get_osfhandle(fd))

int w32_socket (int, int, int);
int w32_setsockopt (int, int, int, const char *, int);
int w32_bind (int, const struct sockaddr *, int);
int w32_connect (int, const struct sockaddr *, int);
int w32_listen (int, int);
int w32_accept (int, struct sockaddr *, int *);
int w32_closesocket (int);
int w32_recvfrom (int, char *, int, int, struct sockaddr *, int *);
int w32_shutdown (int, int);
int socket_to_fd (SOCKET);
SOCKET valid_socket (int);

#endif	/* __MINGW32__ */

#endif	/* GAWK_SOCKET_H */
