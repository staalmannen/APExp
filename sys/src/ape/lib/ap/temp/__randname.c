#include <time.h>
#include <stdint.h>
#include <libv.h>

/* This assumes that a check for the
   template size has already been made */
char *__randname(char *template)
{
	int i;
	struct timespec ts;
	unsigned long r;

	clock_gettime(CLOCK_REALTIME, &ts);
	r = (unsigned long) (ts.tv_sec + ts.tv_nsec + lrand() * 65537UL);
	for (i=0; i<6; i++, r>>=5)
		template[i] = 'A'+(r&15)+(r&16)*2;

	return template;
}
