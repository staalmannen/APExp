#include <signal.h>
#include <thread.h>

/* FIXME this only supports a single handler */

static sa_handler last;

static void
_SIG_DFL(int)
{
}

static void
_SIG_IGN(int)
{
}

sa_handler SIG_DFL = _SIG_DFL, SIG_IGN = _SIG_IGN;

static int
handler(void*, char *s)
{
	/* kill is kill */
	if(strcmp(s, "kill") != 0 && strcmp(s, "threadint") != 0){
		fprint(2, "%s: %s\n", threadgetname(), s);
		if(last != nil)
			last(SIGTERM);
	}
	return 0;
}

void
sigaction(int, struct sigaction *act, struct sigaction *)
{
	if(act != nil && act->sa_handler != nil && last == nil){
		last = act->sa_handler;
		atnotify(handler, 1);
	}else if(act == nil){
		atnotify(handler, 0);
	}
}
