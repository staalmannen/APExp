#include <stdlib.h>

int
mkstemp(char *t)
{
	int i, l, n, f;
	char *s;

	s = t;
	n = 0;
	l = strlen(t);
	for(i = l-1; i >= 0 && t[i] == 'X'; i--, n++);
	if(n < 11){
		s = malloc(l+11-n+1);
		strcpy(s, t);
		for(i = l; i < l+11-n; i++)
			s[i] = 'X';
		s[i] = 0;
	}
	f = create(mktemp(s), ORDWR|OEXCL, 0600);
	if(s != t)
		free(s);
	return f;
}
