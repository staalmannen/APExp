/* termcap.c - Work-alike for termcap library. */
/* Adapted from GNU Bash's termcap.c for APExp/Plan9. */

/* Copyright (C) 1985,1986,1993,1994,1995,1998,2001,2003,2005,2006,2008,2009
   Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version. */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define __private_extern__	/* nothing */

#ifndef BUFSIZE
#define BUFSIZE 2048
#endif

#ifndef TERMCAP_FILE
#define TERMCAP_FILE "/sys/lib/ape/termcap"
#endif

static void
memory_out(void)
{
	write(2, "virtual memory exhausted\n", 25);
	exit(1);
}

static void *
xmalloc(size_t size)
{
	void *tem = malloc(size);
	if(!tem)
		memory_out();
	return tem;
}

static void *
xrealloc(void *ptr, size_t size)
{
	void *tem = realloc(ptr, size);
	if(!tem)
		memory_out();
	return tem;
}

/* The pointer to the data made by tgetent is left here
   for tgetnum, tgetflag and tgetstr to find.  */
static char *term_entry;

static char *find_capability(char *, char *);
static char *tgetst1(char *, char **);

/* Search entry BP for capability CAP.
   Return a pointer to the capability (in BP) if found, 0 if not found.  */
static char *
find_capability(char *bp, char *cap)
{
	for(; *bp; bp++)
		if(bp[0] == ':' && bp[1] == cap[0] && bp[2] == cap[1])
			return &bp[4];
	return NULL;
}

__private_extern__
int
tgetnum(char *cap)
{
	char *ptr = find_capability(term_entry, cap);
	if(!ptr || ptr[-1] != '#')
		return -1;
	return atoi(ptr);
}

__private_extern__
int
tgetflag(char *cap)
{
	char *ptr = find_capability(term_entry, cap);
	return ptr && ptr[-1] == ':';
}

/* Look up a string-valued capability CAP.
   If AREA is non-null, it points to a pointer to a block in which
   to store the string.  That pointer is advanced over the space used.
   If AREA is null, space is allocated with malloc.  */
__private_extern__
char *
tgetstr(char *cap, char **area)
{
	char *ptr = find_capability(term_entry, cap);
	if(!ptr || (ptr[-1] != '=' && ptr[-1] != '~'))
		return NULL;
	return tgetst1(ptr, area);
}

/* Table, indexed by a character in range 0100 to 0140 with 0100 subtracted,
   gives meaning of character following \, or a space if no special meaning.  */
static char esctab[] =
  " \007\010  \033\014 \
      \012 \
  \015 \011 \013 \
        ";

/* Copy the string value at PTR, processing \ and ^ abbreviations,
   into the block that *AREA points to, or newly allocated storage if
   AREA is NULL.  */
static char *
tgetst1(char *ptr, char **area)
{
	char *p, *r;
	int c, size;
	char *ret;
	int c1;

	if(!ptr)
		return NULL;

	if(!area){
		p = ptr;
		while((c = *p++) && c != ':' && c != '\n')
			;
		ret = (char *)xmalloc(p - ptr + 1);
	} else
		ret = *area;

	p = ptr;
	r = ret;
	while((c = *p++) && c != ':' && c != '\n'){
		if(c == '^'){
			c = *p++;
			if(c == '?')
				c = 0177;
			else
				c &= 037;
		} else if(c == '\\'){
			c = *p++;
			if(c >= '0' && c <= '7'){
				c -= '0';
				size = 0;
				while(++size < 3 && (c1 = *p) >= '0' && c1 <= '7'){
					c *= 8;
					c += c1 - '0';
					p++;
				}
			} else if(c >= 0100 && c < 0200){
				c1 = esctab[(c & ~040) - 0100];
				if(c1 != ' ')
					c = c1;
			}
		}
		*r++ = c;
	}
	*r = '\0';
	if(area)
		*area = r + 1;
	return ret;
}

/* Outputting a string with padding.  */

short ospeed;
/* If OSPEED is 0, we use this as the actual baud rate.  */
int tputs_baud_rate;
__private_extern__ char PC = '\0';

/* Baud rates: positive = chars/10sec, negative = chars/0.1sec. */
static int speeds[] = {
	0, 50, 75, 110, 135, 150, -2, -3, -6, -12,
	-18, -24, -48, -96, -192, -288, -384, -576, -1152
};

__private_extern__
int
tputs(char *str, int nlines, int (*outfun)(int))
{
	int padcount = 0;
	int speed;

	if(ospeed == 0)
		speed = tputs_baud_rate;
	else if(ospeed > 0 && ospeed < (int)(sizeof speeds / sizeof speeds[0]))
		speed = speeds[ospeed];
	else
		speed = 0;

	if(!str)
		return -1;

	while(*str >= '0' && *str <= '9'){
		padcount += *str++ - '0';
		padcount *= 10;
	}
	if(*str == '.'){
		str++;
		padcount += *str++ - '0';
	}
	if(*str == '*'){
		str++;
		padcount *= nlines;
	}
	while(*str)
		(*outfun)(*str++);

	/* PADCOUNT is in units of tenths of msec.  */
	padcount *= speed;
	padcount += 500;
	padcount /= 1000;
	if(speed < 0)
		padcount = -padcount;
	else{
		padcount += 50;
		padcount /= 100;
	}

	while(padcount-- > 0)
		(*outfun)(PC);

	return 0;
}

/* Finding the termcap entry in the termcap data base.  */

struct buffer {
	char *beg;
	int   size;
	char *ptr;
	int   ateof;
	int   full;
};

static int   scan_file(char *, int, struct buffer *);
static char *gobble_line(int, struct buffer *, char *);
static int   compare_contin(char *, char *);
static int   name_match(char *, char *);

/* Return nonzero if fn starts with '/' (a valid absolute path on Plan9/Unix).  */
#define valid_filename_p(fn) (*(fn) == '/')

/* Find the termcap entry for terminal type NAME and store it in BP.
   If BP is null, space is dynamically allocated.
   Returns -1 on I/O error, 0 if terminal type not found, 1 on success.  */
__private_extern__
int
tgetent(char *bp, char *name)
{
	char *termcap_name;
	int   fd;
	struct buffer buf;
	char *bp1;
	char *bp2;
	char *term;
	int   malloc_size = 0;
	int   c;
	char *tcenv = NULL;
	char *indirect = NULL;
	int   filep;

	/* For compatibility: programs may pre-fill bp as a fallback.  */
	if(bp)
		term_entry = bp;

	termcap_name = getenv("TERMCAP");
	if(termcap_name && *termcap_name == '\0')
		termcap_name = NULL;

	filep = termcap_name && valid_filename_p(termcap_name);

	/* If $TERMCAP is set but is not a file path, and the TERM variable
	   matches what the caller wants, use the inline entry.  */
	if(termcap_name && !filep){
		char *t = getenv("TERM");
		if(t && strcmp(name, t) == 0){
			indirect = tgetst1(find_capability(termcap_name, "tc"), (char **)0);
			if(!indirect){
				if(!bp)
					bp = termcap_name;
				else
					strcpy(bp, termcap_name);
				goto ret;
			} else {
				tcenv = termcap_name;
				termcap_name = NULL;
			}
		}
	}

	if(!termcap_name || !filep)
		termcap_name = TERMCAP_FILE;

	fd = open(termcap_name, O_RDONLY, 0);
	if(fd < 0){
		free(indirect);
		return -1;
	}

	buf.size = BUFSIZE;
	buf.beg = (char *)xmalloc(buf.size + 1);
	term = indirect ? indirect : name;

	if(!bp){
		malloc_size = indirect ? strlen(tcenv) + 1 : buf.size;
		bp = (char *)xmalloc(malloc_size);
	}
	bp1 = bp;

	if(indirect){
		strcpy(bp, tcenv);
		bp1 += strlen(tcenv);
	}

	while(term){
		if(scan_file(term, fd, &buf) == 0){
			close(fd);
			free(buf.beg);
			if(malloc_size)
				free(bp);
			return 0;
		}

		if(term != name)
			free(term);

		if(malloc_size){
			malloc_size = bp1 - bp + buf.size;
			termcap_name = (char *)xrealloc(bp, malloc_size);
			bp1 += termcap_name - bp;
			bp = termcap_name;
		}

		bp2 = bp1;

		termcap_name = buf.ptr;
		while((*bp1++ = c = *termcap_name++) && c != '\n')
			if(c == '\\' && *termcap_name == '\n'){
				bp1--;
				termcap_name++;
			}
		*bp1 = '\0';

		term = tgetst1(find_capability(bp2, "tc"), (char **)0);
	}

	close(fd);
	free(buf.beg);

	if(malloc_size)
		bp = (char *)xrealloc(bp, bp1 - bp + 1);

ret:
	term_entry = bp;
	return 1;
}

/* Scan the file on FD (via BUFP) from the beginning for terminal type STR.
   Return 1 if found (with the line in BUFP), 0 if not found.  */
static int
scan_file(char *str, int fd, struct buffer *bufp)
{
	char *end;

	bufp->ptr  = bufp->beg;
	bufp->full = 0;
	bufp->ateof = 0;
	*bufp->ptr = '\0';

	lseek(fd, 0L, 0);

	while(!bufp->ateof){
		end = NULL;
		do {
			end = gobble_line(fd, bufp, end);
		} while(!bufp->ateof && end[-2] == '\\');

		if(*bufp->ptr != '#' && name_match(bufp->ptr, str))
			return 1;

		bufp->ptr = end;
	}
	return 0;
}

static int
name_match(char *line, char *name)
{
	char *tem;

	if(!compare_contin(line, name))
		return 1;
	for(tem = line; *tem && *tem != '\n' && *tem != ':'; tem++)
		if(*tem == '|' && !compare_contin(tem + 1, name))
			return 1;
	return 0;
}

static int
compare_contin(char *str1, char *str2)
{
	int c1, c2;
	while(1){
		c1 = *str1++;
		c2 = *str2++;
		while(c1 == '\\' && *str1 == '\n'){
			str1++;
			while((c1 = *str1++) == ' ' || c1 == '\t')
				;
		}
		if(c2 == '\0'){
			if(c1 == '|' || c1 == ':')
				return 0;
			else
				return 1;
		} else if(c1 != c2)
			return 1;
	}
}

static char *
gobble_line(int fd, struct buffer *bufp, char *append_end)
{
	char *end;
	int   nread;
	char *buf = bufp->beg;
	char *tem;

	if(!append_end)
		append_end = bufp->ptr;

	while(1){
		end = append_end;
		while(*end && *end != '\n') end++;
		if(*end)
			break;
		if(bufp->ateof)
			return buf + bufp->full;
		if(bufp->ptr == buf){
			if(bufp->full == bufp->size){
				bufp->size *= 2;
				tem = (char *)xrealloc(buf, bufp->size + 1);
				bufp->ptr    = (bufp->ptr    - buf) + tem;
				append_end   = (append_end   - buf) + tem;
				bufp->beg = buf = tem;
			}
		} else {
			append_end -= bufp->ptr - buf;
			memmove(buf, bufp->ptr, bufp->full -= bufp->ptr - buf);
			bufp->ptr = buf;
		}
		if(!(nread = read(fd, buf + bufp->full, bufp->size - bufp->full)))
			bufp->ateof = 1;
		bufp->full += nread;
		buf[bufp->full] = '\0';
	}
	return end + 1;
}
