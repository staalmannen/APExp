/* tparam.c - merge parameters into a termcap entry string. */
/* Adapted from GNU Bash's tparam.c for APExp/Plan9. */

/* Copyright (C) 1985,1986,1993,1994,1995,1998,2001,2003,2005,2006,2008,2009
   Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version. */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define __private_extern__	/* nothing */

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

static char *tparam1(char *, char *, int, char *, char *, int *);

/* Merge parameters into termcap string STRING.
   OUTSTRING is the output buffer of length LEN (may be reallocated).
   The value returned is the address of the resulting string.  */
char *
tparam(char *string, char *outstring, int len, int arg0, int arg1, int arg2, int arg3)
{
	int arg[4];
	arg[0] = arg0;
	arg[1] = arg1;
	arg[2] = arg2;
	arg[3] = arg3;
	return tparam1(string, outstring, len, NULL, NULL, arg);
}

__private_extern__ char *BC;
__private_extern__ char *UP;

static char tgoto_buf[50];

__private_extern__
char *
tgoto(char *cm, int hpos, int vpos)
{
	int args[2];
	if(!cm)
		return NULL;
	args[0] = vpos;
	args[1] = hpos;
	return tparam1(cm, tgoto_buf, 50, UP, BC, args);
}

static char *
tparam1(char *string, char *outstring, int len, char *up, char *left, int *argp)
{
	int   c;
	char *p = string;
	char *op = outstring;
	char *outend;
	int   outlen = 0;
	int   tem;
	int  *old_argp = argp;
	int   doleft = 0;
	int   doup = 0;

	outend = outstring + len;

	while(1){
		/* If the buffer might be too short, make it bigger.  */
		if(op + 5 >= outend){
			char *new;
			int offset = op - outstring;
			if(outlen == 0){
				outlen = len + 40;
				new = (char *)xmalloc(outlen);
				memcpy(new, outstring, offset);
			} else {
				outlen *= 2;
				new = (char *)xrealloc(outstring, outlen);
			}
			op = new + offset;
			outend = new + outlen;
			outstring = new;
		}
		c = *p++;
		if(!c)
			break;
		if(c == '%'){
			c = *p++;
			tem = *argp;
			switch(c){
			case 'd':		/* %d means output in decimal.  */
				if(tem < 10)
					goto onedigit;
				if(tem < 100)
					goto twodigit;
			case '3':		/* %3 means output in decimal, 3 digits.  */
				if(tem > 999){
					*op++ = tem / 1000 + '0';
					tem %= 1000;
				}
				*op++ = tem / 100 + '0';
			case '2':		/* %2 means output in decimal, 2 digits.  */
			twodigit:
				tem %= 100;
				*op++ = tem / 10 + '0';
			onedigit:
				*op++ = tem % 10 + '0';
				argp++;
				break;

			case 'C':
				/* For c-100: print quotient of value by 96, if nonzero,
				   then do like %+.  */
				if(tem >= 96){
					*op++ = tem / 96;
					tem %= 96;
				}
			case '+':		/* %+x means add character code of char x.  */
				tem += *p++;
			case '.':		/* %. means output as character.  */
				if(left){
					/* Forbid output of 0, \n, \t; increment instead.  */
					while(tem == 0 || tem == '\n' || tem == '\t'){
						tem++;
						if(argp == old_argp)
							doup++, outend -= strlen(up);
						else
							doleft++, outend -= strlen(left);
					}
				}
				*op++ = tem ? tem : 0200;
			case 'f':		/* %f means discard next arg.  */
				argp++;
				break;

			case 'b':		/* %b means back up one arg.  */
				argp--;
				break;

			case 'r':		/* %r means interchange following two args.  */
				argp[0] = argp[1];
				argp[1] = tem;
				old_argp++;
				break;

			case '>':		/* %>xy means if arg > char(x), add char(y).  */
				if(argp[0] > *p++)
					argp[0] += *p;
				p++;
				break;

			case 'a':		/* %a means arithmetic.  */
				tem = p[2] & 0177;
				if(p[1] == 'p')
					tem = argp[tem - 0100];
				if(p[0] == '-')
					argp[0] -= tem;
				else if(p[0] == '+')
					argp[0] += tem;
				else if(p[0] == '*')
					argp[0] *= tem;
				else if(p[0] == '/')
					argp[0] /= tem;
				else
					argp[0] = tem;
				p += 3;
				break;

			case 'i':		/* %i means add one to each of next two args.  */
				argp[0]++;
				argp[1]++;
				break;

			case '%':		/* %% means output %.  */
				goto ordinary;

			case 'n':		/* %n means xor each of next two args with 140.  */
				argp[0] ^= 0140;
				argp[1] ^= 0140;
				break;

			case 'm':		/* %m means xor each of next two args with 177.  */
				argp[0] ^= 0177;
				argp[1] ^= 0177;
				break;

			case 'B':		/* %B means express arg as BCD char code.  */
				argp[0] += 6 * (tem / 10);
				break;

			case 'D':		/* %D means Delta Data transformation.  */
				argp[0] -= 2 * (tem % 16);
				break;
			}
		} else {
		ordinary:
			*op++ = c;
		}
	}
	*op = 0;
	while(doup-- > 0)
		strcat(op, up);
	while(doleft-- > 0)
		strcat(op, left);
	return outstring;
}
