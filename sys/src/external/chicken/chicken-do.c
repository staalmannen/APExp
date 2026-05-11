/* chicken-do
;
; Execute command if dependency changed or target is out of date.
;
; Copyright (c) 2017-2022, The CHICKEN Team
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


#include "chicken.h"

#ifdef WIN32
# include <windows.h>
# include <sys/types.h>
#else
# include <sys/wait.h>
#endif

#include <sys/stat.h>
#include <errno.h>

#define MAX_TARGETS 256
#define MAX_DEPENDS 1024

#ifdef WIN32
# define MAX_COMMAND_LEN 32767
#endif

static char *targets[ MAX_TARGETS ];
static char *depends[ MAX_DEPENDS ];
static struct stat tstats[ MAX_TARGETS ];
static char **cmd;
static int opts = 1;
static int quiet = 0;


static void usage(int code)
{
  fputs("usage: chicken-do [-q] [-h] [--] TARGET ... : DEPENDENCY ... : COMMAND ...\n", stderr);
  exit(code);
}


static void cleanup()
{
  char **t;

  for(t = targets; *t != NULL; ++t)
#ifdef WIN32
    DeleteFile(*t);
#else
    unlink(*t);
#endif
}


static int execute(char **argv)
{
#ifdef WIN32
  static PROCESS_INFORMATION process_info;
  static STARTUPINFO startup_info;
  static TCHAR cmdline[ MAX_COMMAND_LEN ];
  static int len;

  startup_info.cb = sizeof(STARTUPINFO);

  /* quote command arguments */
  while(*argv != NULL) {
    len += snprintf(cmdline + len, sizeof(cmdline) - len, "\"%s\" ", *(argv++));
    if(len > sizeof(cmdline)) {
      fprintf(stderr, "argument list too long\n");
      exit(1);
    }
  }

  if(!CreateProcess(NULL, cmdline, NULL, NULL, TRUE, 
                    NORMAL_PRIORITY_CLASS, NULL, NULL, &startup_info,
                    &process_info)) {
    fprintf(stderr, "creating subprocess failed\n");
    exit(1);
  }

  CloseHandle(process_info.hThread);

  WaitForSingleObject(process_info.hProcess, INFINITE);
  DWORD code;

  if(!GetExitCodeProcess(process_info.hProcess, &code)) {
    fprintf(stderr, "unable to obtain exit status of subprocess\n");
    exit(1);
  }

  return code;
#else
  pid_t child = fork();

  if(child == -1) {
    perror("forking subprocess failed");
    exit(1);
  }

  if(child == 0) {
    execvp(argv[ 0 ], argv);
    /* returns only in case of error */
    perror("executing command failed");
    cleanup();
    exit(1);
  }

  for(;;) {
    int status;
    pid_t w = waitpid(child, &status, 0);

    if(w == -1) {
      perror("waiting for subprocess failed");
      cleanup();
      exit(1);
    }

    if(WIFEXITED(status))
      return WEXITSTATUS(status);

    if(WIFSIGNALED(status)) {
      fprintf(stderr, "subprocess killed by signal %d\n", WTERMSIG(status));
      cleanup();
      exit(1);
    }
  }
#endif
}


int main(int argc, char *argv[]) 
{
  int i, a = 0;
  struct stat *st, sd;
  char **t = targets;
  char **d = depends;

  if(argc < 3) usage(1);

  for(i = 1; i < argc; ++i) {
    if(!strcmp(argv[ i ], ":")) {
      *t = NULL;
      break;
    }

    if(opts && *argv[ i ] == '-') {
      switch(argv[ i ][ 1 ]) {
      case 'q': quiet = 1; break;
      case 'h': usage(0);
      case '-': opts = 0; break;
      default: usage(1);
      }
    }
    else if(t >= targets + MAX_TARGETS) {
      fprintf(stderr, "too many targets\n");
      exit(1);
    }
    else *(t++) = argv[ i ];
  }

  if(i == argc) usage(1);

  while(++i < argc) {
    if(!strcmp(argv[ i ], ":")) {
      *d = NULL;
      break;
    }

    if(d >= depends + MAX_DEPENDS) {
      fprintf(stderr, "too many dependencies\n");
      exit(1);
    }

    *(d++) = argv[ i ];
  }

  if(i == argc) usage(1);

  cmd = argv + i + 1;
  st = tstats;

  for(t = targets; *t != NULL; ++t) {
    if(stat(*t, st++) == -1) {
      if(errno == ENOENT) goto build;

      fprintf(stderr, "%s: %s\n", *t, strerror(errno));
      exit(1);
    }
  }

  for(d = depends; *d != NULL; ++d) {
    if(stat(*d, &sd) == -1) {
      fprintf(stderr, "%s: %s\n", *d, strerror(errno));
      exit(1);
    }      

    st = tstats;

    for(t = targets; *t != NULL; ++t) {
      if(sd.st_mtime > (st++)->st_mtime) goto build;
    }
  }

  return 0;

build:
  if(!quiet) {
    fputs("  ", stdout);

    for(t = cmd; *t != NULL; ++t)
      printf(" %s", *t);

    putchar('\n');
    fflush(stdout);
  }

  int s = execute(cmd);

  if(s != 0) cleanup();

  return s;
}
