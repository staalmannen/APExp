#include <stdio.h>

FILE *
popen(char *cmd, char *type)
{
	int p[2], r, null, pid;
	FILE *s;

	pipe(p);
	r = type[0] == 'r' || type[1] == 'r';
	if((pid = rfork(RFPROC|RFFDG|RFNOTEG|RFCENVG|RFNOWAIT)) == 0){
		null = open("/dev/null", r ? OWRITE : OREAD);
		dup(null, !r);
		dup(p[r], r);
		close(p[r]);
		close(null);
		execl("/bin/rc", "rc", "-c", cmd, nil);
		sysfatal("popen: execl: %r");
	}else if(pid < 0){
		close(p[0]);
		close(p[1]);
		return nil;
	}
	s = fdopen(p[!r], r ? "r" : "w");
	close(p[r]);
	return s;
}
