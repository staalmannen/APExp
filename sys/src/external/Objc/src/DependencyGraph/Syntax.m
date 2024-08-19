
/* Parsing Logic */

#define WRD 1
#define EOL 2

yyerror(char *msg) { fprintf(stderr,msg);return 0; }

yyparse()
{ 
    register int c;
    for(;;) { /* for each line */
	switch( (c=yylex()) ) {
	    case WRD : DefAction(yytext); /* define node */
	       for(;;) { /* for each reference in line */
		   switch( (c=yylex()) ) {
		       case WRD: RefAction(yytext); /* reference node */
		          continue;
		       case EOL: break;
		       default : yyerror("syntax error 2");continue;
		   } break;
	       } break;
	    case 0: return 0;
	    case EOL: continue;
	    default: yyerror("syntax error 1");
	}
    }
}

#include "ctype.h"

yylex()
{
    register int c;
    while ( (c=getc(stdin)) != EOF ) {
	if (c == '\n') return EOL;
	else if (isspace(c)) {
	    do { c = getc(stdin); } while (isspace(c));
	    ungetc(c,stdin);continue;
	} else {
	    register char *p = yytext;
	    do { *p++ = c; c = getc(stdin); } while (!isspace(c));
	    ungetc(c,stdin); *p = 0;return WRD;
	}
    }
    return 0;
}

