#ifndef __OSFCN_H
#define __OSFCN_H 1

#ifdef __MINGW32__
#define _INC_MINGW_SECAPI
#define _INC_CRTDEFS
#ifdef __cfront__
#define __cdecl
#endif
#endif

#if !(defined(__MINGW32__) || defined(__APPLE__))
#include <sys/types.h>
#endif
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#ifndef __APPLE__
#include <signal.h>
#endif
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#ifndef __APPLE__
#include <utime.h>
#endif
#if !(defined(_WIN32) || defined(__APPLE__))
#include <sys/wait.h>
#endif
#endif
