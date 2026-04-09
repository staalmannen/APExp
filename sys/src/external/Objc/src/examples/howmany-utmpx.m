
/* utmpx example based on the old howmany.m utmp example */

#include <stdio.h>
#include <utmpx.h>
#include <stdlib.h>
#include <objpak.h>

/* should use getutxent() */

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
  struct utmpx ut;
  int n,m = sizeof(struct utmpx);

  if ( (f = fopen(UTMPX_FILE,"r")) == NULL) {
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
  printf("Opening for read: %s\n",UTMPX_FILE);
  printf("Number of good users: %i\n",[users() size]);
}

