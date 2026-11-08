#include <npe.h>
#include <tos.h>
#include <sys/stat.h>
#include "_npe.h"

static void
npe_exit(int x)
{
	exits(x == 0 ? nil : "error");
}

int errno = 0;
void (*exit)(int) = npe_exit;

/*
 * nsec() is wallclock and can be adjusted by timesync
 * so need to use cycles() instead, but fall back to
 * nsec() in case we can't
 */
uvlong
npe_nanosec(void)
{
	static uvlong fasthz, xstart;
	uvlong x, div;

	if(fasthz == ~0ULL)
		return nsec() - xstart;

	if(fasthz == 0){
		if(_tos->cyclefreq){
			cycles(&xstart);
			fasthz = _tos->cyclefreq;
		} else {
			xstart = nsec();
			fasthz = ~0ULL;
			fprint(2, "cyclefreq not available, falling back to nsec()\n");
			fprint(2, "you might want to disable aux/timesync\n");
			return 0;
		}
	}
	cycles(&x);
	x -= xstart;

	/* this is ugly */
	for(div = Nsec; x < 0x1999999999999999ULL && div > 1 ; div /= 10ULL, x *= 10ULL);

	return x / (fasthz / div);
}

void
npe_nsleep(uvlong ns)
{
	uvlong start, end;

	start = npe_nanosec();
	end = start + ns;
	ns = start;
	do{
		if(end - ns > 85*Nmsec)
			sleep(80);
		else if (end - ns > 25*Nmsec)
			sleep(20);
		else if (end - ns > 1*Nmsec)
			sleep(1);
		else
			break;
		ns = npe_nanosec();
	}while(ns < end);
}

int
npe_mkdirp(char *s, int perm)
{
	char *p;
	int n;

	for(p = strchr(s+1, '/'); p; p = strchr(p+1, '/')){
		*p = 0;
		n = access(s, AEXIST) == 0 || mkdir(s, perm) == 0 ? 0 : -1;
		*p = '/';
		if(n != 0)
			return n;
	}
	if(access(s, AEXIST) != 0)
		return mkdir(s, perm);

	return 0;
}

float
npe_infinity(void)
{
	union {float f; u32int i;} u;

	u.i = 0x7f800000;

	return u.f;
}

float
npe_nan(void)
{
	union {float f; u32int i;} u;

	u.i = 0x7fbfffff;

	return u.f;
}
