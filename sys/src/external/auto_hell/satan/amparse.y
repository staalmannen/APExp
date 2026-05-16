%{
#include "am.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
extern int yylineno;
%}

%union {
	char *s;
}

%token <s> T_IDENT T_WORD
%token T_EQ T_PLUSEQ T_COLONEQ T_QEQ T_COLON
%token T_INCLUDE T_SINCLUDE T_IF T_ELSE T_ENDIF T_NOT
%token T_NL

%type <s> value words word

%%

file:
	| file line
	;

line:
	T_NL
	| assign T_NL
	| include T_NL
	| ifline T_NL
	| rule T_NL
	| T_ELSE T_NL { if (am_else() != 0) YYABORT; }
	| T_ELSE T_IDENT T_NL { if (am_else() != 0) YYABORT; free($2); }
	| T_ENDIF T_NL { if (am_endif() != 0) YYABORT; }
	| T_ENDIF T_IDENT T_NL { if (am_endif() != 0) YYABORT; free($2); }
	| error T_NL { yyerrok; }
	;

assign:
	word T_EQ value { if (am_assign($1, AM_ASSIGN, $3) != 0) YYABORT; free($1); free($3); }
	| word T_PLUSEQ value { if (am_assign($1, AM_APPEND, $3) != 0) YYABORT; free($1); free($3); }
	| word T_COLONEQ value { if (am_assign($1, AM_IMMEDIATE, $3) != 0) YYABORT; free($1); free($3); }
	| word T_QEQ value { if (am_assign($1, AM_DEFAULT, $3) != 0) YYABORT; free($1); free($3); }
	;

include:
	T_INCLUDE value { if (am_include($2, 0) != 0) YYABORT; free($2); }
	| T_SINCLUDE value { if (am_include($2, 1) != 0) YYABORT; free($2); }
	;

ifline:
	T_IF T_IDENT { if (am_if($2, 0) != 0) YYABORT; free($2); }
	| T_IF T_NOT T_IDENT { if (am_if($3, 1) != 0) YYABORT; free($3); }
	;

rule:
	words T_COLON value { free($1); free($3); }
	;

value:
	{ $$ = xstrdup(""); }
	| words { $$ = $1; }
	;

word:
	T_WORD { $$ = $1; }
	| T_IDENT { $$ = $1; }
	;

words:
	word { $$ = $1; }
	| words word { char *tmp = am_join($1, $2); free($1); free($2); $$ = tmp; }
	;

%%

void yyerror(const char *s)
{
	fprintf(stderr, "satan: %s:%d: %s\n", am_cur_path(), yylineno, s);
}
