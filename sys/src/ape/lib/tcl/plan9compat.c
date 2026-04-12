#include "tclPort.h"
#include <stdlib.h>
#include <string.h>

/* mkstemp is in libap.a now */

void
_tclPlan9InitEnv(void)
{
   char buf[512];
   if(getenv("PATH") == 0)
       putenv("PATH=:.:/bin");
   if(getenv("HOME") == 0){
      snprintf(buf, sizeof(buf), "HOME=%s", getenv("home"));
      putenv(buf);
   }
}

