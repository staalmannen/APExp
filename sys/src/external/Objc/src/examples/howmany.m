
/* old style utmp example - superseded by howmany-utmpx.m for utmpx */

#include <stdio.h>
#include <utmp.h>
#include <stdlib.h>
#include <objpak.h>

#if !defined(UTMP_FILE) && defined(_PATH_UTMP)
#define UTMP_FILE _PATH_UTMP
#endif

#if defined(USER_PROCESS)
#define gooduser(ut) (*ut.ut_name && ut.ut_type == USER_PROCESS)
#else
#define gooduser(ut) (*ut.ut_name && *ut.ut_line)
#endif

id
users(void)
{
  id c;
  FILE *f;
  struct utmp ut;
  int n,m = sizeof(struct utmp);

  if ( (f = fopen(UTMP_FILE,"r")) == NULL) {
     perror("fopen");
     exit(1);
  }

  c = [Set new];
  while (1 == fread(&ut,m,1,f)) {
    if (gooduser(ut)) [c add:[String str:ut.ut_name]];
  }

  if (ferror(f)) perror("read"); fclose(f);
  return c;
}

int main(int argc,char *argv[])
{
  printf("Opening for read: %s\n",UTMP_FILE);
  printf("Number of good users: %i\n",[users() size]);
}

