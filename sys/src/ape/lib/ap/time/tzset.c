/*
 * tzset() -- now a reporter rather than a second implementation.
 *
 * It used to parse getenv("timezone") itself, into tzname/timezone/
 * altzone/daylight, while localtime_r() separately read /env/timezone
 * into a static of its own. Neither had heard of $TZ and neither could
 * see the other's answer, so tzset() had no effect on localtime(). All
 * of the parsing is in tzone.c now and this just publishes the result in
 * the four globals POSIX names.
 *
 * `timezone' and `altzone' are seconds WEST of Greenwich, which is the
 * opposite sign from what tzone.c carries internally -- hence the
 * negations. POSIX made that choice for these two variables alone and it
 * disagrees with tm_gmtoff four lines away in the same struct.
 */

#include <time.h>
#include <string.h>
#include "tzone.h"

static char std[32] = "GMT0";
static char dst[32];
char *tzname[2] = {
	std, dst
};
long timezone;
long altzone;
int daylight;

void
tzset(void)
{
	const char *sn, *dn;
	long so, dof;
	int hasdst;

	_tzstate(&so, &dof, &sn, &dn, &hasdst);

	strncpy(std, sn, sizeof std - 1);
	std[sizeof std - 1] = 0;
	strncpy(dst, dn, sizeof dst - 1);
	dst[sizeof dst - 1] = 0;
	timezone = -so;
	altzone = -dof;
	daylight = hasdst;
}
