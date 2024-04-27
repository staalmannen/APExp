#define	CHAR	57346
#define	NUMBER	57347
#define	SECTEND	57348
#define	SCDECL	57349
#define	XSCDECL	57350
#define	NAME	57351
#define	PREVCCL	57352
#define	EOF_OP	57353
#define	OPTION_OP	57354
#define	OPT_OUTFILE	57355
#define	OPT_PREFIX	57356
#define	OPT_YYCLASS	57357
#define	OPT_HEADER	57358
#define	OPT_EXTRA_TYPE	57359
#define	OPT_TABLES	57360
#define	CCE_ALNUM	57361
#define	CCE_ALPHA	57362
#define	CCE_BLANK	57363
#define	CCE_CNTRL	57364
#define	CCE_DIGIT	57365
#define	CCE_GRAPH	57366
#define	CCE_LOWER	57367
#define	CCE_PRINT	57368
#define	CCE_PUNCT	57369
#define	CCE_SPACE	57370
#define	CCE_UPPER	57371
#define	CCE_XDIGIT	57372
#define	CCE_NEG_ALNUM	57373
#define	CCE_NEG_ALPHA	57374
#define	CCE_NEG_BLANK	57375
#define	CCE_NEG_CNTRL	57376
#define	CCE_NEG_DIGIT	57377
#define	CCE_NEG_GRAPH	57378
#define	CCE_NEG_LOWER	57379
#define	CCE_NEG_PRINT	57380
#define	CCE_NEG_PUNCT	57381
#define	CCE_NEG_SPACE	57382
#define	CCE_NEG_UPPER	57383
#define	CCE_NEG_XDIGIT	57384
#define	CCL_OP_DIFF	57385
#define	CCL_OP_UNION	57386
#define	BEGIN_REPEAT_POSIX	57387
#define	END_REPEAT_POSIX	57388
#define	BEGIN_REPEAT_FLEX	57389
#define	END_REPEAT_FLEX	57390

#line	35	"/usr/jens/staging/flex/parse.y"
/*  Copyright (c) 1990 The Regents of the University of California. */
/*  All rights reserved. */

/*  This code is derived from software contributed to Berkeley by */
/*  Vern Paxson. */

/*  The United States Government has rights in this work pursuant */
/*  to contract no. DE-AC03-76SF00098 between the United States */
/*  Department of Energy and the University of California. */

/*  This file is part of flex. */

/*  Redistribution and use in source and binary forms, with or without */
/*  modification, are permitted provided that the following conditions */
/*  are met: */

/*  1. Redistributions of source code must retain the above copyright */
/*     notice, this list of conditions and the following disclaimer. */
/*  2. Redistributions in binary form must reproduce the above copyright */
/*     notice, this list of conditions and the following disclaimer in the */
/*     documentation and/or other materials provided with the distribution. */

/*  Neither the name of the University nor the names of its contributors */
/*  may be used to endorse or promote products derived from this software */
/*  without specific prior written permission. */

/*  THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR */
/*  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED */
/*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR */
/*  PURPOSE. */

#include "flexdef.h"
#include "tables.h"

int pat, scnum, eps, headcnt, trailcnt, lastchar, i, rulelen;
int trlcontxt, xcluflg, currccl, cclsorted, varlength, variable_trail_rule;

int *scon_stk;
int scon_stk_ptr;

static int madeany = false;  /* whether we've made the '.' character class */
static int ccldot, cclany;
int previous_continued_action;	/* whether the previous rule's action was '|' */

#define format_warn3(fmt, a1, a2) \
	do{ \
        char fw3_msg[MAXLINE];\
        snprintf( fw3_msg, MAXLINE,(fmt), (a1), (a2) );\
        warn( fw3_msg );\
	}while(0)

/* Expand a POSIX character class expression. */
#define CCL_EXPR(func) \
	do{ \
	int c; \
	for ( c = 0; c < csize; ++c ) \
		if ( isascii(c) && func(c) ) \
			ccladd( currccl, c ); \
	}while(0)

/* negated class */
#define CCL_NEG_EXPR(func) \
	do{ \
	int c; \
	for ( c = 0; c < csize; ++c ) \
		if ( !func(c) ) \
			ccladd( currccl, c ); \
	}while(0)

/* While POSIX defines isblank(), it's not ANSI C. */
#define IS_BLANK(c) ((c) == ' ' || (c) == '\t')

/* On some over-ambitious machines, such as DEC Alpha's, the default
 * token type is "long" instead of "int"; this leads to problems with
 * declaring yylval in flexdef.h.  But so far, all the yacc's I've seen
 * wrap their definitions of YYSTYPE with "#ifndef YYSTYPE"'s, so the
 * following should ensure that the default token type is "int".
 */
#define YYSTYPE int

extern	int	yyerrflag;
#ifndef	YYMAXDEPTH
#define	YYMAXDEPTH	150
#endif
#ifndef	YYSTYPE
#define	YYSTYPE	int
#endif
YYSTYPE	yylval;
YYSTYPE	yyval;
#define YYEOFCODE 1
#define YYERRCODE 2

#line	949	"/usr/jens/staging/flex/parse.y"



/* build_eof_action - build the "<<EOF>>" action for the active start
 *                    conditions
 */

void build_eof_action()
	{
	register int i;
	char action_text[MAXLINE];

	for ( i = 1; i <= scon_stk_ptr; ++i )
		{
		if ( sceof[scon_stk[i]] )
			format_pinpoint_message(
				"multiple <<EOF>> rules for start condition %s",
				scname[scon_stk[i]] );

		else
			{
			sceof[scon_stk[i]] = true;
			snprintf( action_text, sizeof(action_text), "case YY_STATE_EOF(%s):\n",
				scname[scon_stk[i]] );
			add_action( action_text );
			}
		}

	line_directive_out( (FILE *) 0, 1 );

	/* This isn't a normal rule after all - don't count it as
	 * such, so we don't have any holes in the rule numbering
	 * (which make generating "rule can never match" warnings
	 * more difficult.
	 */
	--num_rules;
	++num_eof_rules;
	}


/* format_synerr - write out formatted syntax error */

void format_synerr( msg, arg )
const char *msg, arg[];
	{
	char errmsg[MAXLINE];

	(void) snprintf( errmsg, sizeof(errmsg), msg, arg );
	synerr( errmsg );
	}


/* synerr - report a syntax error */

void synerr( str )
const char *str;
	{
	syntaxerror = true;
	pinpoint_message( str );
	}


/* format_warn - write out formatted warning */

void format_warn( msg, arg )
const char *msg, arg[];
	{
	char warn_msg[MAXLINE];

	snprintf( warn_msg, sizeof(warn_msg), msg, arg );
	warn( warn_msg );
	}


/* warn - report a warning, unless -w was given */

void warn( str )
const char *str;
	{
	line_warning( str, linenum );
	}

/* format_pinpoint_message - write out a message formatted with one string,
 *			     pinpointing its location
 */

void format_pinpoint_message( msg, arg )
const char *msg, arg[];
	{
	char errmsg[MAXLINE];

	snprintf( errmsg, sizeof(errmsg), msg, arg );
	pinpoint_message( errmsg );
	}


/* pinpoint_message - write out a message, pinpointing its location */

void pinpoint_message( str )
const char *str;
	{
	line_pinpoint( str, linenum );
	}


/* line_warning - report a warning at a given line, unless -w was given */

void line_warning( str, line )
const char *str;
int line;
	{
	char warning[MAXLINE];

	if ( ! nowarn )
		{
		snprintf( warning, sizeof(warning), "warning, %s", str );
		line_pinpoint( warning, line );
		}
	}


/* line_pinpoint - write out a message, pinpointing it at the given line */

void line_pinpoint( str, line )
const char *str;
int line;
	{
	fprintf( stderr, "%s:%d: %s\n", infilename, line, str );
	}


/* yyerror - eat up an error message from the parser;
 *	     currently, messages are ignore
 */

void yyerror( msg )
const char *msg;
	{
	}
short	yyexca[] =
{-1, 1,
	1, -1,
	-2, 0,
-1, 2,
	6, 5,
	7, 5,
	8, 5,
	12, 5,
	-2, 0,
-1, 12,
	1, 25,
	-2, 33,
};
#define	YYNPROD	97
#define	YYPRIVATE 57344
#define	YYLAST	181
short	yyact[] =
{
  98,  46,  57, 130,  83,  54,  71,  70,  71,  72,
  88,  71,  53,  96,  31, 100, 101, 102, 103, 104,
 105, 106, 107, 108, 109, 111, 110, 112, 113, 114,
 115, 116, 117, 122, 118, 119, 120, 123, 121,  45,
  52,  60,  95,  42,  78,  52,  49,  73, 129, 127,
  98,  49,  41,  75,  67,  19,  52, 128,  76,  77,
 126,  86,  49,  87, 131, 100, 101, 102, 103, 104,
 105, 106, 107, 108, 109, 111, 110, 112, 113, 114,
 115, 116, 117, 122, 118, 119, 120, 123, 121, 124,
 125,  73,  92,  93,  39,  84,  85,  74,  19,  47,
  50,  51,  94,  54,  47,  50,  51,  44,  54,  29,
 134,  89,  37,  36,  97,  47,  50,  51,  35,  54,
  34,  33,  32, 138, 132, 137,  79,  80,  40,  17,
  12,  22,  24,  25,  26,  23,  27,   8,   9,  10,
  58,  59,  15,  11,  66,  65,  64,  59,  28,  14,
  63,  69,  62, 135,  61,  20,  91,  90, 136,  82,
  55,   4,  99,  81,  48, 133,  43,  56,  68,  30,
  38,  18,  21,  16,   7,  13,   6,   5,   3,   2,
   1
};
short	yypact[] =
{
-1000,-1000, 159, 131,-1000,-1000, 140,-1000,-1000,-1000,
-1000,-1000,   1, 146,-1000,-1000, 118,-1000,  58, -42,
-1000,-1000,  73,  72,  71,  69,  64,  63,  41,-1000,
 138, -14, 145, 143, 141, 137, 136, 135,   4,  36,
-1000,-1000,-1000,  36, -51,  52,  -3,-1000,  83,-1000,
-1000,  36,-1000,-1000,  42,  44,   6,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000, -48,
-1000,  36,-1000,  -3, 152,-1000,-1000,-1000, 151, -62,
 -62,  38, -53,  46,-1000,-1000,-1000, 132,-1000,  52,
   3,   0,-1000,-1000,-1000,-1000,-1000,-1000, -66,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,-1000,  -4,-1000, 119,-1000, 105,-1000,
 154,-1000,  79,-1000,  75,-1000,-1000,-1000,-1000
};
short	yypgo[] =
{
   0, 180, 179, 178, 177, 130, 129, 176, 175, 174,
 173, 172, 171, 170, 128, 169, 167,   2, 166, 107,
  39,   1, 164, 163,  12,   4, 162
};
short	yyr1[] =
{
   0,   1,   2,   3,   3,   3,   3,   4,   7,   7,
   8,   8,   8,   9,  10,  10,  11,  11,  11,  11,
  11,  11,   5,   5,   5,   6,  13,  13,  13,  13,
  15,  12,  12,  12,  16,  16,  16,  17,  14,  14,
  14,  14,  19,  19,  18,  20,  20,  20,  20,  20,
  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
  21,  21,  22,  22,  22,  24,  24,  25,  25,  25,
  25,  26,  26,  26,  26,  26,  26,  26,  26,  26,
  26,  26,  26,  26,  26,  26,  26,  26,  26,  26,
  26,  26,  26,  26,  26,  23,  23
};
short	yyr2[] =
{
   0,   5,   0,   3,   2,   0,   1,   1,   1,   1,
   2,   1,   1,   2,   2,   0,   3,   3,   3,   3,
   3,   3,   5,   5,   0,   0,   2,   1,   1,   1,
   0,   4,   3,   0,   3,   1,   1,   1,   2,   3,
   2,   1,   3,   1,   2,   2,   1,   6,   5,   4,
   2,   2,   2,   6,   5,   4,   1,   1,   1,   3,
   3,   1,   3,   3,   1,   3,   4,   4,   2,   2,
   0,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   1,   2,   0
};
short	yychk[] =
{
-1000,  -1,  -2,  -3,   2,  -4,  -7,  -9,   6,   7,
   8,  12,  -5,  -8,   9,   2, -10,  -6, -12,  54,
   9, -11,  13,  17,  14,  15,  16,  18,  -6,  51,
 -15,  56,  49,  49,  49,  49,  49,  49, -13,  53,
 -14,  11,   2, -18, -19, -20, -21,  63, -22,  10,
  64,  65,   4, -24,  67,  -5, -16, -17,   2,   9,
  55,   9,   9,   9,   9,   9,   9,  50, -14, -19,
  58,  59,  60, -21,  45,  56,  61,  62,  47,  43,
  44, -23, -19, -25,  53,  52,  55,  57,  58, -20,
   5,   5, -24, -24,  64,   4,  66,  68,   4, -26,
  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,
  30,  29,  31,  32,  33,  34,  35,  36,  38,  39,
  40,  42,  37,  41, -25, -17,  57,  46,  57,  48,
  69,  68,   5,  46,   5,  48,   4,  46,  48
};
short	yydef[] =
{
   2,  -2,  -2,   0,   6,  24,   0,   4,   7,   8,
   9,  15,  -2,   3,  11,  12,  13,   1,  25,  30,
  10,  14,   0,   0,   0,   0,   0,   0,   0,  24,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  27,  28,  29,   0,  41,  43,  46,  56,  57,  58,
  96,   0,  61,  64,  70,  33,   0,  35,  36,  37,
  32,  16,  17,  18,  19,  20,  21,  22,  26,  38,
  40,   0,  44,  45,   0,  50,  51,  52,   0,   0,
   0,   0,   0,   0,  70,  23,  31,   0,  39,  42,
   0,   0,  62,  63,  59,  95,  60,  65,  68,  69,
  71,  72,  73,  74,  75,  76,  77,  78,  79,  80,
  81,  82,  83,  84,  85,  86,  87,  88,  89,  90,
  91,  92,  93,  94,   0,  34,   0,  49,   0,  55,
   0,  66,   0,  48,   0,  54,  67,  47,  53
};
short	yytok1[] =
{
   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  50,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,  64,   0,  58,   0,   0,   0,
  65,  66,  56,  61,  57,  69,  63,  60,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  54,  49,  55,  62,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,  67,   0,  68,  53,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,  51,  59,  52
};
short	yytok2[] =
{
   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,
  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,
  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,
  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,
  42,  43,  44,  45,  46,  47,  48
};
long	yytok3[] =
{
   0
};
#define YYFLAG 		-1000
#define YYERROR		goto yyerrlab
#define YYACCEPT	return(0)
#define YYABORT		return(1)
#define	yyclearin	yychar = -1
#define	yyerrok		yyerrflag = 0

#ifdef	yydebug
#include	"y.debug"
#else
#define	yydebug		0
char*	yytoknames[1];		/* for debugging */
char*	yystates[1];		/* for debugging */
#endif

/*	parser for yacc output	*/

int	yynerrs = 0;		/* number of errors */
int	yyerrflag = 0;		/* error recovery flag */

char*
yytokname(int yyc)
{
	static char x[16];

	if(yyc > 0 && yyc <= sizeof(yytoknames)/sizeof(yytoknames[0]))
	if(yytoknames[yyc-1])
		return yytoknames[yyc-1];
	sprintf(x, "<%d>", yyc);
	return x;
}

char*
yystatname(int yys)
{
	static char x[16];

	if(yys >= 0 && yys < sizeof(yystates)/sizeof(yystates[0]))
	if(yystates[yys])
		return yystates[yys];
	sprintf(x, "<%d>\n", yys);
	return x;
}

long
yylex1(void)
{
	long yychar;
	long *t3p;
	int c;

	yychar = yylex();
	if(yychar <= 0) {
		c = yytok1[0];
		goto out;
	}
	if(yychar < sizeof(yytok1)/sizeof(yytok1[0])) {
		c = yytok1[yychar];
		goto out;
	}
	if(yychar >= YYPRIVATE)
		if(yychar < YYPRIVATE+sizeof(yytok2)/sizeof(yytok2[0])) {
			c = yytok2[yychar-YYPRIVATE];
			goto out;
		}
	for(t3p=yytok3;; t3p+=2) {
		c = t3p[0];
		if(c == yychar) {
			c = t3p[1];
			goto out;
		}
		if(c == 0)
			break;
	}
	c = 0;

out:
	if(c == 0)
		c = yytok2[1];	/* unknown char */
	if(yydebug >= 3)
		printf("lex %.4lX %s\n", yychar, yytokname(c));
	return c;
}

int
yyparse(void)
{
	struct
	{
		YYSTYPE	yyv;
		int	yys;
	} yys[YYMAXDEPTH], *yyp, *yypt;
	short *yyxi;
	int yyj, yym, yystate, yyn, yyg;
	YYSTYPE save1, save2;
	int save3, save4;
	long yychar;

	save1 = yylval;
	save2 = yyval;
	save3 = yynerrs;
	save4 = yyerrflag;

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyp = &yys[-1];
	goto yystack;

ret0:
	yyn = 0;
	goto ret;

ret1:
	yyn = 1;
	goto ret;

ret:
	yylval = save1;
	yyval = save2;
	yynerrs = save3;
	yyerrflag = save4;
	return yyn;

yystack:
	/* put a state and value onto the stack */
	if(yydebug >= 4)
		printf("char %s in %s", yytokname(yychar), yystatname(yystate));

	yyp++;
	if(yyp >= &yys[YYMAXDEPTH]) {
		yyerror("yacc stack overflow");
		goto ret1;
	}
	yyp->yys = yystate;
	yyp->yyv = yyval;

yynewstate:
	yyn = yypact[yystate];
	if(yyn <= YYFLAG)
		goto yydefault; /* simple state */
	if(yychar < 0)
		yychar = yylex1();
	yyn += yychar;
	if(yyn < 0 || yyn >= YYLAST)
		goto yydefault;
	yyn = yyact[yyn];
	if(yychk[yyn] == yychar) { /* valid shift */
		yychar = -1;
		yyval = yylval;
		yystate = yyn;
		if(yyerrflag > 0)
			yyerrflag--;
		goto yystack;
	}

yydefault:
	/* default state action */
	yyn = yydef[yystate];
	if(yyn == -2) {
		if(yychar < 0)
			yychar = yylex1();

		/* look through exception table */
		for(yyxi=yyexca;; yyxi+=2)
			if(yyxi[0] == -1 && yyxi[1] == yystate)
				break;
		for(yyxi += 2;; yyxi += 2) {
			yyn = yyxi[0];
			if(yyn < 0 || yyn == yychar)
				break;
		}
		yyn = yyxi[1];
		if(yyn < 0)
			goto ret0;
	}
	if(yyn == 0) {
		/* error ... attempt to resume parsing */
		switch(yyerrflag) {
		case 0:   /* brand new error */
			yyerror("syntax error");
			if(yydebug >= 1) {
				printf("%s", yystatname(yystate));
				printf("saw %s\n", yytokname(yychar));
			}
yyerrlab:
			yynerrs++;

		case 1:
		case 2: /* incompletely recovered error ... try again */
			yyerrflag = 3;

			/* find a state where "error" is a legal shift action */
			while(yyp >= yys) {
				yyn = yypact[yyp->yys] + YYERRCODE;
				if(yyn >= 0 && yyn < YYLAST) {
					yystate = yyact[yyn];  /* simulate a shift of "error" */
					if(yychk[yystate] == YYERRCODE)
						goto yystack;
				}

				/* the current yyp has no shift onn "error", pop stack */
				if(yydebug >= 2)
					printf("error recovery pops state %d, uncovers %d\n",
						yyp->yys, (yyp-1)->yys );
				yyp--;
			}
			/* there is no state on the stack with an error shift ... abort */
			goto ret1;

		case 3:  /* no shift yet; clobber input char */
			if(yydebug >= YYEOFCODE)
				printf("error recovery discards %s\n", yytokname(yychar));
			if(yychar == YYEOFCODE)
				goto ret1;
			yychar = -1;
			goto yynewstate;   /* try again in the same state */
		}
	}

	/* reduction by production yyn */
	if(yydebug >= 2)
		printf("reduce %d in:\n\t%s", yyn, yystatname(yystate));

	yypt = yyp;
	yyp -= yyr2[yyn];
	yyval = (yyp+1)->yyv;
	yym = yyn;

	/* consult goto table to find next state */
	yyn = yyr1[yyn];
	yyg = yypgo[yyn];
	yyj = yyg + yyp->yys + 1;

	if(yyj >= YYLAST || yychk[yystate=yyact[yyj]] != -yyn)
		yystate = yyact[yyg];
	switch(yym) {
		
case 1:
#line	119	"/usr/jens/staging/flex/parse.y"
{ /* add default rule */
			int def_rule;

			pat = cclinit();
			cclnegate( pat );

			def_rule = mkstate( -pat );

			/* Remember the number of the default rule so we
			 * don't generate "can't match" warnings for it.
			 */
			default_rule = num_rules;

			finish_rule( def_rule, false, 0, 0, 0);

			for ( i = 1; i <= lastsc; ++i )
				scset[i] = mkbranch( scset[i], def_rule );

			if ( spprdflt )
				add_action(
				"YY_FATAL_ERROR( \"flex scanner jammed\" )" );
			else
				add_action( "ECHO" );

			add_action( ";\n\tYY_BREAK\n" );
			} break;
case 2:
#line	148	"/usr/jens/staging/flex/parse.y"
{ /* initialize for processing rules */

			/* Create default DFA start condition. */
			scinstal( "INITIAL", false );
			} break;
case 6:
#line	159	"/usr/jens/staging/flex/parse.y"
{ synerr( _("unknown error processing section 1") ); } break;
case 7:
#line	163	"/usr/jens/staging/flex/parse.y"
{
			check_options();
			scon_stk = allocate_integer_array( lastsc + 1 );
			scon_stk_ptr = 0;
			} break;
case 8:
#line	171	"/usr/jens/staging/flex/parse.y"
{ xcluflg = false; } break;
case 9:
#line	174	"/usr/jens/staging/flex/parse.y"
{ xcluflg = true; } break;
case 10:
#line	178	"/usr/jens/staging/flex/parse.y"
{ scinstal( nmstr, xcluflg ); } break;
case 11:
#line	181	"/usr/jens/staging/flex/parse.y"
{ scinstal( nmstr, xcluflg ); } break;
case 12:
#line	184	"/usr/jens/staging/flex/parse.y"
{ synerr( _("bad start condition list") ); } break;
case 16:
#line	195	"/usr/jens/staging/flex/parse.y"
{
			outfilename = copy_string( nmstr );
			did_outfilename = 1;
			} break;
case 17:
#line	200	"/usr/jens/staging/flex/parse.y"
{ extra_type = copy_string( nmstr ); } break;
case 18:
#line	202	"/usr/jens/staging/flex/parse.y"
{ prefix = copy_string( nmstr ); } break;
case 19:
#line	204	"/usr/jens/staging/flex/parse.y"
{ yyclass = copy_string( nmstr ); } break;
case 20:
#line	206	"/usr/jens/staging/flex/parse.y"
{ headerfilename = copy_string( nmstr ); } break;
case 21:
#line	208	"/usr/jens/staging/flex/parse.y"
{ tablesext = true; tablesfilename = copy_string( nmstr ); } break;
case 22:
#line	212	"/usr/jens/staging/flex/parse.y"
{ scon_stk_ptr = yypt[-3].yyv; } break;
case 23:
#line	214	"/usr/jens/staging/flex/parse.y"
{ scon_stk_ptr = yypt[-3].yyv; } break;
case 25:
#line	219	"/usr/jens/staging/flex/parse.y"
{
			/* Initialize for a parse of one rule. */
			trlcontxt = variable_trail_rule = varlength = false;
			trailcnt = headcnt = rulelen = 0;
			current_state_type = STATE_NORMAL;
			previous_continued_action = continued_action;
			in_rule = true;

			new_rule();
			} break;
case 26:
#line	232	"/usr/jens/staging/flex/parse.y"
{
			pat = yypt[-0].yyv;
			finish_rule( pat, variable_trail_rule,
				headcnt, trailcnt , previous_continued_action);

			if ( scon_stk_ptr > 0 )
				{
				for ( i = 1; i <= scon_stk_ptr; ++i )
					scbol[scon_stk[i]] =
						mkbranch( scbol[scon_stk[i]],
								pat );
				}

			else
				{
				/* Add to all non-exclusive start conditions,
				 * including the default (0) start condition.
				 */

				for ( i = 1; i <= lastsc; ++i )
					if ( ! scxclu[i] )
						scbol[i] = mkbranch( scbol[i],
									pat );
				}

			if ( ! bol_needed )
				{
				bol_needed = true;

				if ( performance_report > 1 )
					pinpoint_message(
			"'^' operator results in sub-optimal performance" );
				}
			} break;
case 27:
#line	268	"/usr/jens/staging/flex/parse.y"
{
			pat = yypt[-0].yyv;
			finish_rule( pat, variable_trail_rule,
				headcnt, trailcnt , previous_continued_action);

			if ( scon_stk_ptr > 0 )
				{
				for ( i = 1; i <= scon_stk_ptr; ++i )
					scset[scon_stk[i]] =
						mkbranch( scset[scon_stk[i]],
								pat );
				}

			else
				{
				for ( i = 1; i <= lastsc; ++i )
					if ( ! scxclu[i] )
						scset[i] =
							mkbranch( scset[i],
								pat );
				}
			} break;
case 28:
#line	292	"/usr/jens/staging/flex/parse.y"
{
			if ( scon_stk_ptr > 0 )
				build_eof_action();
	
			else
				{
				/* This EOF applies to all start conditions
				 * which don't already have EOF actions.
				 */
				for ( i = 1; i <= lastsc; ++i )
					if ( ! sceof[i] )
						scon_stk[++scon_stk_ptr] = i;

				if ( scon_stk_ptr == 0 )
					warn(
			"all start conditions already have <<EOF>> rules" );

				else
					build_eof_action();
				}
			} break;
case 29:
#line	315	"/usr/jens/staging/flex/parse.y"
{ synerr( _("unrecognized rule") ); } break;
case 30:
#line	319	"/usr/jens/staging/flex/parse.y"
{ yyval = scon_stk_ptr; } break;
case 31:
#line	323	"/usr/jens/staging/flex/parse.y"
{ yyval = yypt[-2].yyv; } break;
case 32:
#line	326	"/usr/jens/staging/flex/parse.y"
{
			yyval = scon_stk_ptr;

			for ( i = 1; i <= lastsc; ++i )
				{
				int j;

				for ( j = 1; j <= scon_stk_ptr; ++j )
					if ( scon_stk[j] == i )
						break;

				if ( j > scon_stk_ptr )
					scon_stk[++scon_stk_ptr] = i;
				}
			} break;
case 33:
#line	343	"/usr/jens/staging/flex/parse.y"
{ yyval = scon_stk_ptr; } break;
case 36:
#line	351	"/usr/jens/staging/flex/parse.y"
{ synerr( _("bad start condition list") ); } break;
case 37:
#line	355	"/usr/jens/staging/flex/parse.y"
{
			if ( (scnum = sclookup( nmstr )) == 0 )
				format_pinpoint_message(
					"undeclared start condition %s",
					nmstr );
			else
				{
				for ( i = 1; i <= scon_stk_ptr; ++i )
					if ( scon_stk[i] == scnum )
						{
						format_warn(
							"<%s> specified twice",
							scname[scnum] );
						break;
						}

				if ( i > scon_stk_ptr )
					scon_stk[++scon_stk_ptr] = scnum;
				}
			} break;
case 38:
#line	378	"/usr/jens/staging/flex/parse.y"
{
			if ( transchar[lastst[yypt[-0].yyv]] != SYM_EPSILON )
				/* Provide final transition \now/ so it
				 * will be marked as a trailing context
				 * state.
				 */
				yypt[-0].yyv = link_machines( yypt[-0].yyv,
						mkstate( SYM_EPSILON ) );

			mark_beginning_as_normal( yypt[-0].yyv );
			current_state_type = STATE_NORMAL;

			if ( previous_continued_action )
				{
				/* We need to treat this as variable trailing
				 * context so that the backup does not happen
				 * in the action but before the action switch
				 * statement.  If the backup happens in the
				 * action, then the rules "falling into" this
				 * one's action will *also* do the backup,
				 * erroneously.
				 */
				if ( ! varlength || headcnt != 0 )
					warn(
		"trailing context made variable due to preceding '|' action" );

				/* Mark as variable. */
				varlength = true;
				headcnt = 0;

				}

			if ( lex_compat || (varlength && headcnt == 0) )
				{ /* variable trailing context rule */
				/* Mark the first part of the rule as the
				 * accepting "head" part of a trailing
				 * context rule.
				 *
				 * By the way, we didn't do this at the
				 * beginning of this production because back
				 * then current_state_type was set up for a
				 * trail rule, and add_accept() can create
				 * a new state ...
				 */
				add_accept( yypt[-1].yyv,
					num_rules | YY_TRAILING_HEAD_MASK );
				variable_trail_rule = true;
				}
			
			else
				trailcnt = rulelen;

			yyval = link_machines( yypt[-1].yyv, yypt[-0].yyv );
			} break;
case 39:
#line	434	"/usr/jens/staging/flex/parse.y"
{ synerr( _("trailing context used twice") ); } break;
case 40:
#line	437	"/usr/jens/staging/flex/parse.y"
{
			headcnt = 0;
			trailcnt = 1;
			rulelen = 1;
			varlength = false;

			current_state_type = STATE_TRAILING_CONTEXT;

			if ( trlcontxt )
				{
				synerr( _("trailing context used twice") );
				yyval = mkstate( SYM_EPSILON );
				}

			else if ( previous_continued_action )
				{
				/* See the comment in the rule for "re2 re"
				 * above.
				 */
				warn(
		"trailing context made variable due to preceding '|' action" );

				varlength = true;
				}

			if ( lex_compat || varlength )
				{
				/* Again, see the comment in the rule for
				 * "re2 re" above.
				 */
				add_accept( yypt[-1].yyv,
					num_rules | YY_TRAILING_HEAD_MASK );
				variable_trail_rule = true;
				}

			trlcontxt = true;

			eps = mkstate( SYM_EPSILON );
			yyval = link_machines( yypt[-1].yyv,
				link_machines( eps, mkstate( '\n' ) ) );
			} break;
case 41:
#line	480	"/usr/jens/staging/flex/parse.y"
{
			yyval = yypt[-0].yyv;

			if ( trlcontxt )
				{
				if ( lex_compat || (varlength && headcnt == 0) )
					/* Both head and trail are
					 * variable-length.
					 */
					variable_trail_rule = true;
				else
					trailcnt = rulelen;
				}
			} break;
case 42:
#line	498	"/usr/jens/staging/flex/parse.y"
{
			varlength = true;
			yyval = mkor( yypt[-2].yyv, yypt[-0].yyv );
			} break;
case 43:
#line	504	"/usr/jens/staging/flex/parse.y"
{ yyval = yypt[-0].yyv; } break;
case 44:
#line	509	"/usr/jens/staging/flex/parse.y"
{
			/* This rule is written separately so the
			 * reduction will occur before the trailing
			 * series is parsed.
			 */

			if ( trlcontxt )
				synerr( _("trailing context used twice") );
			else
				trlcontxt = true;

			if ( varlength )
				/* We hope the trailing context is
				 * fixed-length.
				 */
				varlength = false;
			else
				headcnt = rulelen;

			rulelen = 0;

			current_state_type = STATE_TRAILING_CONTEXT;
			yyval = yypt[-1].yyv;
			} break;
case 45:
#line	536	"/usr/jens/staging/flex/parse.y"
{
			/* This is where concatenation of adjacent patterns
			 * gets done.
			 */
			yyval = link_machines( yypt[-1].yyv, yypt[-0].yyv );
			} break;
case 46:
#line	544	"/usr/jens/staging/flex/parse.y"
{ yyval = yypt[-0].yyv; } break;
case 47:
#line	547	"/usr/jens/staging/flex/parse.y"
{
			varlength = true;

			if ( yypt[-3].yyv > yypt[-1].yyv || yypt[-3].yyv < 0 )
				{
				synerr( _("bad iteration values") );
				yyval = yypt[-5].yyv;
				}
			else
				{
				if ( yypt[-3].yyv == 0 )
					{
					if ( yypt[-1].yyv <= 0 )
						{
						synerr(
						_("bad iteration values") );
						yyval = yypt[-5].yyv;
						}
					else
						yyval = mkopt(
							mkrep( yypt[-5].yyv, 1, yypt[-1].yyv ) );
					}
				else
					yyval = mkrep( yypt[-5].yyv, yypt[-3].yyv, yypt[-1].yyv );
				}
			} break;
case 48:
#line	575	"/usr/jens/staging/flex/parse.y"
{
			varlength = true;

			if ( yypt[-2].yyv <= 0 )
				{
				synerr( _("iteration value must be positive") );
				yyval = yypt[-4].yyv;
				}

			else
				yyval = mkrep( yypt[-4].yyv, yypt[-2].yyv, INFINITE_REPEAT );
			} break;
case 49:
#line	589	"/usr/jens/staging/flex/parse.y"
{
			/* The series could be something like "(foo)",
			 * in which case we have no idea what its length
			 * is, so we punt here.
			 */
			varlength = true;

			if ( yypt[-1].yyv <= 0 )
				{
				  synerr( _("iteration value must be positive")
					  );
				yyval = yypt[-3].yyv;
				}

			else
				yyval = link_machines( yypt[-3].yyv,
						copysingl( yypt[-3].yyv, yypt[-1].yyv - 1 ) );
			} break;
case 50:
#line	611	"/usr/jens/staging/flex/parse.y"
{
			varlength = true;

			yyval = mkclos( yypt[-1].yyv );
			} break;
case 51:
#line	618	"/usr/jens/staging/flex/parse.y"
{
			varlength = true;
			yyval = mkposcl( yypt[-1].yyv );
			} break;
case 52:
#line	624	"/usr/jens/staging/flex/parse.y"
{
			varlength = true;
			yyval = mkopt( yypt[-1].yyv );
			} break;
case 53:
#line	630	"/usr/jens/staging/flex/parse.y"
{
			varlength = true;

			if ( yypt[-3].yyv > yypt[-1].yyv || yypt[-3].yyv < 0 )
				{
				synerr( _("bad iteration values") );
				yyval = yypt[-5].yyv;
				}
			else
				{
				if ( yypt[-3].yyv == 0 )
					{
					if ( yypt[-1].yyv <= 0 )
						{
						synerr(
						_("bad iteration values") );
						yyval = yypt[-5].yyv;
						}
					else
						yyval = mkopt(
							mkrep( yypt[-5].yyv, 1, yypt[-1].yyv ) );
					}
				else
					yyval = mkrep( yypt[-5].yyv, yypt[-3].yyv, yypt[-1].yyv );
				}
			} break;
case 54:
#line	658	"/usr/jens/staging/flex/parse.y"
{
			varlength = true;

			if ( yypt[-2].yyv <= 0 )
				{
				synerr( _("iteration value must be positive") );
				yyval = yypt[-4].yyv;
				}

			else
				yyval = mkrep( yypt[-4].yyv, yypt[-2].yyv, INFINITE_REPEAT );
			} break;
case 55:
#line	672	"/usr/jens/staging/flex/parse.y"
{
			/* The singleton could be something like "(foo)",
			 * in which case we have no idea what its length
			 * is, so we punt here.
			 */
			varlength = true;

			if ( yypt[-1].yyv <= 0 )
				{
				synerr( _("iteration value must be positive") );
				yyval = yypt[-3].yyv;
				}

			else
				yyval = link_machines( yypt[-3].yyv,
						copysingl( yypt[-3].yyv, yypt[-1].yyv - 1 ) );
			} break;
case 56:
#line	691	"/usr/jens/staging/flex/parse.y"
{
			if ( ! madeany )
				{
				/* Create the '.' character class. */
                    ccldot = cclinit();
                    ccladd( ccldot, '\n' );
                    cclnegate( ccldot );

                    if ( useecs )
                        mkeccl( ccltbl + cclmap[ccldot],
                            ccllen[ccldot], nextecm,
                            ecgroup, csize, csize );

				/* Create the (?s:'.') character class. */
                    cclany = cclinit();
                    cclnegate( cclany );

                    if ( useecs )
                        mkeccl( ccltbl + cclmap[cclany],
                            ccllen[cclany], nextecm,
                            ecgroup, csize, csize );

				madeany = true;
				}

			++rulelen;

            if (sf_dot_all())
                yyval = mkstate( -cclany );
            else
                yyval = mkstate( -ccldot );
			} break;
case 57:
#line	725	"/usr/jens/staging/flex/parse.y"
{
				/* Sort characters for fast searching.  We
				 * use a shell sort since this list could
				 * be large.
				 */
				cshell( ccltbl + cclmap[yypt[-0].yyv], ccllen[yypt[-0].yyv], true );

			if ( useecs )
				mkeccl( ccltbl + cclmap[yypt[-0].yyv], ccllen[yypt[-0].yyv],
					nextecm, ecgroup, csize, csize );

			++rulelen;

			if (ccl_has_nl[yypt[-0].yyv])
				rule_has_nl[num_rules] = true;

			yyval = mkstate( -yypt[-0].yyv );
			} break;
case 58:
#line	745	"/usr/jens/staging/flex/parse.y"
{
			++rulelen;

			if (ccl_has_nl[yypt[-0].yyv])
				rule_has_nl[num_rules] = true;

			yyval = mkstate( -yypt[-0].yyv );
			} break;
case 59:
#line	755	"/usr/jens/staging/flex/parse.y"
{ yyval = yypt[-1].yyv; } break;
case 60:
#line	758	"/usr/jens/staging/flex/parse.y"
{ yyval = yypt[-1].yyv; } break;
case 61:
#line	761	"/usr/jens/staging/flex/parse.y"
{
			++rulelen;

			if (yypt[-0].yyv == nlch)
				rule_has_nl[num_rules] = true;

            if (sf_case_ins() && has_case(yypt[-0].yyv))
                /* create an alternation, as in (a|A) */
                yyval = mkor (mkstate(yypt[-0].yyv), mkstate(reverse_case(yypt[-0].yyv)));
            else
                yyval = mkstate( yypt[-0].yyv );
			} break;
case 62:
#line	775	"/usr/jens/staging/flex/parse.y"
{ yyval = ccl_set_diff  (yypt[-2].yyv, yypt[-0].yyv); } break;
case 63:
#line	776	"/usr/jens/staging/flex/parse.y"
{ yyval = ccl_set_union (yypt[-2].yyv, yypt[-0].yyv); } break;
case 65:
#line	782	"/usr/jens/staging/flex/parse.y"
{ yyval = yypt[-1].yyv; } break;
case 66:
#line	785	"/usr/jens/staging/flex/parse.y"
{
			cclnegate( yypt[-1].yyv );
			yyval = yypt[-1].yyv;
			} break;
case 67:
#line	792	"/usr/jens/staging/flex/parse.y"
{

			if (sf_case_ins())
			  {

			    /* If one end of the range has case and the other
			     * does not, or the cases are different, then we're not
			     * sure what range the user is trying to express.
			     * Examples: [@-z] or [S-t]
			     */
			    if (has_case (yypt[-2].yyv) != has_case (yypt[-0].yyv)
				     || (has_case (yypt[-2].yyv) && (b_islower (yypt[-2].yyv) != b_islower (yypt[-0].yyv)))
				     || (has_case (yypt[-2].yyv) && (b_isupper (yypt[-2].yyv) != b_isupper (yypt[-0].yyv))))
			      format_warn3 (
			      _("the character range [%c-%c] is ambiguous in a case-insensitive scanner"),
					    yypt[-2].yyv, yypt[-0].yyv);

			    /* If the range spans uppercase characters but not
			     * lowercase (or vice-versa), then should we automatically
			     * include lowercase characters in the range?
			     * Example: [@-_] spans [a-z] but not [A-Z]
			     */
			    else if (!has_case (yypt[-2].yyv) && !has_case (yypt[-0].yyv) && !range_covers_case (yypt[-2].yyv, yypt[-0].yyv))
			      format_warn3 (
			      _("the character range [%c-%c] is ambiguous in a case-insensitive scanner"),
					    yypt[-2].yyv, yypt[-0].yyv);
			  }

			if ( yypt[-2].yyv > yypt[-0].yyv )
				synerr( _("negative range in character class") );

			else
				{
				for ( i = yypt[-2].yyv; i <= yypt[-0].yyv; ++i )
					ccladd( yypt[-3].yyv, i );

				/* Keep track if this ccl is staying in
				 * alphabetical order.
				 */
				cclsorted = cclsorted && (yypt[-2].yyv > lastchar);
				lastchar = yypt[-0].yyv;

                /* Do it again for upper/lowercase */
                if (sf_case_ins() && has_case(yypt[-2].yyv) && has_case(yypt[-0].yyv)){
                    yypt[-2].yyv = reverse_case (yypt[-2].yyv);
                    yypt[-0].yyv = reverse_case (yypt[-0].yyv);
                    
                    for ( i = yypt[-2].yyv; i <= yypt[-0].yyv; ++i )
                        ccladd( yypt[-3].yyv, i );

                    cclsorted = cclsorted && (yypt[-2].yyv > lastchar);
                    lastchar = yypt[-0].yyv;
                }

				}

			yyval = yypt[-3].yyv;
			} break;
case 68:
#line	852	"/usr/jens/staging/flex/parse.y"
{
			ccladd( yypt[-1].yyv, yypt[-0].yyv );
			cclsorted = cclsorted && (yypt[-0].yyv > lastchar);
			lastchar = yypt[-0].yyv;

            /* Do it again for upper/lowercase */
            if (sf_case_ins() && has_case(yypt[-0].yyv)){
                yypt[-0].yyv = reverse_case (yypt[-0].yyv);
                ccladd (yypt[-1].yyv, yypt[-0].yyv);

                cclsorted = cclsorted && (yypt[-0].yyv > lastchar);
                lastchar = yypt[-0].yyv;
            }

			yyval = yypt[-1].yyv;
			} break;
case 69:
#line	870	"/usr/jens/staging/flex/parse.y"
{
			/* Too hard to properly maintain cclsorted. */
			cclsorted = false;
			yyval = yypt[-1].yyv;
			} break;
case 70:
#line	877	"/usr/jens/staging/flex/parse.y"
{
			cclsorted = true;
			lastchar = 0;
			currccl = yyval = cclinit();
			} break;
case 71:
#line	885	"/usr/jens/staging/flex/parse.y"
{ CCL_EXPR(isalnum); } break;
case 72:
#line	886	"/usr/jens/staging/flex/parse.y"
{ CCL_EXPR(isalpha); } break;
case 73:
#line	887	"/usr/jens/staging/flex/parse.y"
{ CCL_EXPR(IS_BLANK); } break;
case 74:
#line	888	"/usr/jens/staging/flex/parse.y"
{ CCL_EXPR(iscntrl); } break;
case 75:
#line	889	"/usr/jens/staging/flex/parse.y"
{ CCL_EXPR(isdigit); } break;
case 76:
#line	890	"/usr/jens/staging/flex/parse.y"
{ CCL_EXPR(isgraph); } break;
case 77:
#line	891	"/usr/jens/staging/flex/parse.y"
{ 
                          CCL_EXPR(islower);
                          if (sf_case_ins())
                              CCL_EXPR(isupper);
                        } break;
case 78:
#line	896	"/usr/jens/staging/flex/parse.y"
{ CCL_EXPR(isprint); } break;
case 79:
#line	897	"/usr/jens/staging/flex/parse.y"
{ CCL_EXPR(ispunct); } break;
case 80:
#line	898	"/usr/jens/staging/flex/parse.y"
{ CCL_EXPR(isspace); } break;
case 81:
#line	899	"/usr/jens/staging/flex/parse.y"
{ CCL_EXPR(isxdigit); } break;
case 82:
#line	900	"/usr/jens/staging/flex/parse.y"
{
                    CCL_EXPR(isupper);
                    if (sf_case_ins())
                        CCL_EXPR(islower);
				} break;
case 83:
#line	906	"/usr/jens/staging/flex/parse.y"
{ CCL_NEG_EXPR(isalnum); } break;
case 84:
#line	907	"/usr/jens/staging/flex/parse.y"
{ CCL_NEG_EXPR(isalpha); } break;
case 85:
#line	908	"/usr/jens/staging/flex/parse.y"
{ CCL_NEG_EXPR(IS_BLANK); } break;
case 86:
#line	909	"/usr/jens/staging/flex/parse.y"
{ CCL_NEG_EXPR(iscntrl); } break;
case 87:
#line	910	"/usr/jens/staging/flex/parse.y"
{ CCL_NEG_EXPR(isdigit); } break;
case 88:
#line	911	"/usr/jens/staging/flex/parse.y"
{ CCL_NEG_EXPR(isgraph); } break;
case 89:
#line	912	"/usr/jens/staging/flex/parse.y"
{ CCL_NEG_EXPR(isprint); } break;
case 90:
#line	913	"/usr/jens/staging/flex/parse.y"
{ CCL_NEG_EXPR(ispunct); } break;
case 91:
#line	914	"/usr/jens/staging/flex/parse.y"
{ CCL_NEG_EXPR(isspace); } break;
case 92:
#line	915	"/usr/jens/staging/flex/parse.y"
{ CCL_NEG_EXPR(isxdigit); } break;
case 93:
#line	916	"/usr/jens/staging/flex/parse.y"
{ 
				if ( sf_case_ins() )
					warn(_("[:^lower:] is ambiguous in case insensitive scanner"));
				else
					CCL_NEG_EXPR(islower);
				} break;
case 94:
#line	922	"/usr/jens/staging/flex/parse.y"
{
				if ( sf_case_ins() )
					warn(_("[:^upper:] ambiguous in case insensitive scanner"));
				else
					CCL_NEG_EXPR(isupper);
				} break;
case 95:
#line	931	"/usr/jens/staging/flex/parse.y"
{
			if ( yypt[-0].yyv == nlch )
				rule_has_nl[num_rules] = true;

			++rulelen;

            if (sf_case_ins() && has_case(yypt[-0].yyv))
                yyval = mkor (mkstate(yypt[-0].yyv), mkstate(reverse_case(yypt[-0].yyv)));
            else
                yyval = mkstate (yypt[-0].yyv);

			yyval = link_machines( yypt[-1].yyv, yyval);
			} break;
case 96:
#line	946	"/usr/jens/staging/flex/parse.y"
{ yyval = mkstate( SYM_EPSILON ); } break;
	}
	goto yystack;  /* stack new state and value */
}
