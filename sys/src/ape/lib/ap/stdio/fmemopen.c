/* copied from haiku patch to tuxpaint by
 * Pere Pujal 
 * http://permalink.gmane.org/gmane.comp.gnu.tuxpaint.devel/1604
 * adjusted to plan9/ape
 */

#define _PLAN9_SOURCE

#include <u.h>
#include <stdlib.h>
#include <stdio.h>


FILE * fmemopen(unsigned char * data, size_t size, const char * mode)
{
  unsigned int i;
  char *fname;
  FILE * fi = tmpfile();

    fname = tmpnam(0);


  fi = fopen(fname, "w");
  if (fi == NULL)
    {
      free(fname);
      return(NULL);
    }

  for (i = 0; i < size; i++)
    {
      fwrite(data, 1, 1, fi);
      data ++;
    }
  
  fclose(fi);
  fi = fopen(fname, mode);
  free(fname);
  return(fi);
}