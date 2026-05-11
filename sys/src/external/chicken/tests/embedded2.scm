(import chicken.platform chicken.gc chicken.pretty-print)

#>
#include <assert.h>

int main()
{
  static char buffer[ 4096 ];

  void C_toplevel(C_word c, C_word *av);

  CHICKEN_run((void*)C_toplevel);
  assert(CHICKEN_eval_string_to_string("(oink (make-vector 10 'ok))",
				       buffer, sizeof(buffer)));
  printf("--> %s\n", buffer);
  return 0;
}
<#

(gc)
(print "starting...")

(define (oink x)
  (pp x)
  (vector-length x))

(return-to-host)
