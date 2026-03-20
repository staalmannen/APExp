/* getfields3: 3-arg table-driven field splitter (APE/libv origin).
 * The canonical 5-arg UTF-8 aware getfields() is in getfields9.c
 * merged from lib9. Call sites using the 3-arg form should migrate
 * to getfields(str, args, max, mflag, set) when possible.
 */
#include <string.h>

static char is_sep[256] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
static char is_field[256] = {
	0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
static char last_sep[256];

char *
setfields(char *arg)
{
	register unsigned char *s;
	register i;

	for(i = 1, s = (unsigned char *)last_sep; i < 256; i++)
		if(is_sep[i])
			*s++ = i;
	*s = 0;
	memset(is_sep, 0, sizeof is_sep);
	memset(is_field, 1, sizeof is_field);
	for(s = (unsigned char *)arg; *s;){
		is_sep[*s] = 1;
		is_field[*s++] = 0;
	}
	is_field[0] = 0;
	return(last_sep);
}

int
getfields3(char *ss, char **sp, int nptrs)
{
	register unsigned char *s = (unsigned char *)ss;
	register unsigned char **p = (unsigned char **)sp;
	register unsigned c;

	for(;;){
		if(--nptrs < 0) break;
		*p++ = s;
		while(is_field[c = *s++])
			;
		if(c == 0) break;
		s[-1] = 0;
	}
	if(nptrs > 0)
		*p = 0;
	else if(--s >= (unsigned char *)ss)
		*s = c;
	return(p - (unsigned char **)sp);
}

int
getmfields(char *ss, char **sp, int nptrs)
{
	register unsigned char *s = (unsigned char *)ss;
	register unsigned char **p = (unsigned char **)sp;
	register unsigned c;

	if(nptrs <= 0)
		return(0);
	goto flushdelim;
	for(;;){
		*p++ = s;
		if(--nptrs == 0) break;
		while(is_field[c = *s++])
			;
		/*
		 *  s is now pointing 1 past the delimiter of the last field
		 *  c is the delimiter
		 */
		if(c == 0) break;
		s[-1] = 0;
	flushdelim:
		while(is_sep[c = *s++])
			;
		/*
		 *  s is now pointing 1 past the beginning of the next field
		 *  c is the first letter of the field
		 */
		if(c == 0) break;
		s--;
		/*
		 *  s is now pointing to the beginning of the next field
		 *  c is the first letter of the field
		 */
	}
	if(nptrs > 0)
		*p = 0;
	return(p - (unsigned char **)sp);
}

