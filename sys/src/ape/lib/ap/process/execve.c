#include "lib.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include "sys9.h"

extern char **environ;

int
execve(const char *name, const char *argv[], const char *envp[])
{
	int n, f, i;
	char **e, *ss, *se;
	Fdinfo *fi;
	unsigned long flags;
	char buf[1024];

	/*
	 * RFCENVG IS ALREADY THE CLEAR. The `C' in RFCENVG, RFCNAMEG and
	 * RFCFDG means a new EMPTY group, not a copy -- RFENVG is the one
	 * that copies. So by the line below this process has no
	 * environment at all, and the creates further down are the whole
	 * of the child's environment: exactly envp, which is what POSIX
	 * says execve delivers.
	 *
	 * SAYING SO BECAUSE THIS WAS READ BACKWARDS ONCE. A loop removing
	 * every /env entry was added here, on the reasoning that RFCENVG
	 * copied the parent's group and so leaked any name envp did not
	 * mention. sys/lib/tests/execve-env-test.c asked the machine
	 * instead -- rfork(RFCENVG), create two names, list /env -- and
	 * got two names back, none of them the parent's. The loop was
	 * removing an empty directory on every exec. It is gone.
	 */
	_RFORK(RFCENVG);

	/*
	 * To pass _fdinfo[] across exec, put lines like
	 *   fd flags oflags
	 * in $_fdinfo (for open fd's)
	 */

	f = _CREATE("/env/_fdinfo", OWRITE|OCEXEC, 0666);
	ss = buf;
	for(i = 0; i<OPEN_MAX; i++){
		if(i == f)
			continue;
		fi = &_fdinfo[i];
		flags = fi->flags;
		if(flags&FD_CLOEXEC){
			_CLOSE(i);
			fi->flags = 0;
			fi->oflags = 0;
		}else if(flags&FD_ISOPEN){
			if(f < 0)
				continue;
			ss = _ultoa(ss, i);
			*ss++ = ' ';
			ss = _ultoa(ss, flags);
			*ss++ = ' ';
			ss = _ultoa(ss, fi->oflags);
			*ss++ = '\n';
			n = ss-buf;
			if(n > sizeof(buf)-50){
				if(_WRITE(f, buf, n) != n)
					break;
				ss = buf;
			}
		}
	}
	if(f >= 0){
		if(ss > buf)
			_WRITE(f, buf, ss-buf);
		_CLOSE(f);
	}

	/*
	 * To pass _sighdlr[] across exec, set $_sighdlr
	 * to list of blank separated fd's that have
	 * SIG_IGN (the rest will be SIG_DFL).
	 * We write the variable, even if no signals
	 * are ignored, in case the current value of the
	 * variable ignored some.
	 */
	f = _CREATE("/env/_sighdlr", OWRITE|OCEXEC, 0666);
	if(f >= 0){
		ss = buf;
		for(i = 0; i <=MAXSIG; i++) {
			if(_sighdlr[i] == SIG_IGN) {
				ss = _ultoa(ss, i);
				*ss++ = ' ';
				n = ss-buf;
				if(n > sizeof(buf)-20){
					if(_WRITE(f, buf, n) != n)
						break;
					ss = buf;
				}
			}
		}
		if(ss > buf)
			_WRITE(f, buf, ss-buf);
		_CLOSE(f);
	}
	if(envp){
		for(e = (char**)envp; (ss = *e); e++) {
			if(strncmp(ss, "#()fn ", 6)==0){
				if((se = strchr(ss+6, '{'))==0)
					continue;
				while(se[-1]==' ') se--;
				n = se-(ss+6);
				if(n <= 0 || n >= sizeof(buf)-8)
					continue;	/* name too long */
				memcpy(buf, "/env/fn#", 8);
				memcpy(buf+8, ss+6, n);
				buf[8+n] = '\0';
				f = _CREATE(buf, OWRITE|OCEXEC, 0666);
				if(f < 0)
					continue;
				ss += 3;	/* past #() */
				_WRITE(f, ss, strlen(ss));
				_CLOSE(f);
			} else {
				if((se = strchr(ss, '='))==0)
					continue;
				n = se-ss;
				if(n <= 0 || n >= sizeof(buf)-5)
					continue;	/* name too long */
				memcpy(buf, "/env/", 5);
				memcpy(buf+5, ss, n);
				buf[5+n] = '\0';
				f = _CREATE(buf, OWRITE|OCEXEC, 0666);
				if(f < 0)
					continue;
				ss = ++se;	/* past = */
				se += strlen(se);
				while((n = (se - ss)) > 0){
					if(n > sizeof(buf))
						n = sizeof(buf);
					/* decode nulls (see _envsetup()) */
					for(i=0; i<n; i++)
						if((buf[i] = ss[i]) == 1)
							buf[i] = 0;
					if(_WRITE(f, buf, n) != n)
						break;
					ss += n;
				}
				_CLOSE(f);
			}
		}
	}
	n = _EXEC(name, argv);
	_syserrno();
	return n;
}
