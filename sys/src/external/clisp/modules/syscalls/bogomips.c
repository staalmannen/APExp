/* this has to be in a separate file which is compiled without optimizations */

#include <time.h>

double bogomips (void);
double bogomips (void) {
  if (clock() != (clock_t)-1) {
    unsigned long loops = 1;
    while ((loops <<= 1)) {
      unsigned long ticks, ii;
      ticks = clock();
      for (ii = loops; ii > 0; ii--);
      ticks = clock() - ticks;
      if (ticks >= CLOCKS_PER_SEC)
        return (1.0 * loops / ticks) * (CLOCKS_PER_SEC / 500000.0);
    }
  }
  return -1.0;
}
