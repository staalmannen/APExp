%{
#include "am.h"
#include "amparse.h"
#include "util.h"

#include <string.h>

int am_lex_bol = 1;
%}

%option yylineno
%x VAL

%%

<INITIAL>[ \t\r]+    { }
<INITIAL>\n          { am_lex_bol = 1; return T_NL; }

<INITIAL>"-include"  { if (am_lex_bol) { am_lex_bol = 0; BEGIN(VAL); return T_SINCLUDE; } yylval.s = xstrdup(yytext); return T_WORD; }
<INITIAL>"include"   { if (am_lex_bol) { am_lex_bol = 0; BEGIN(VAL); return T_INCLUDE; } yylval.s = xstrdup(yytext); return T_WORD; }
<INITIAL>"if"        { if (am_lex_bol) { am_lex_bol = 0; return T_IF; } yylval.s = xstrdup(yytext); return T_WORD; }
<INITIAL>"else"      { if (am_lex_bol) { am_lex_bol = 0; return T_ELSE; } yylval.s = xstrdup(yytext); return T_WORD; }
<INITIAL>"endif"     { if (am_lex_bol) { am_lex_bol = 0; return T_ENDIF; } yylval.s = xstrdup(yytext); return T_WORD; }

<INITIAL>"+="        { am_lex_bol = 0; BEGIN(VAL); return T_PLUSEQ; }
<INITIAL>":="        { am_lex_bol = 0; BEGIN(VAL); return T_COLONEQ; }
<INITIAL>"?="        { am_lex_bol = 0; BEGIN(VAL); return T_QEQ; }
<INITIAL>":"         { am_lex_bol = 0; BEGIN(VAL); return T_COLON; }
<INITIAL>"="         { am_lex_bol = 0; BEGIN(VAL); return T_EQ; }
<INITIAL>"!"         { am_lex_bol = 0; return T_NOT; }
<INITIAL>[A-Za-z_][A-Za-z0-9_@-]* { am_lex_bol = 0; yylval.s = xstrdup(yytext); return T_IDENT; }

<VAL>[ \t\r]+         { }
<VAL>\n               { am_lex_bol = 1; BEGIN(INITIAL); return T_NL; }
<VAL>\"([^\"\\]|\\.)*\" { yylval.s = xstrdup(yytext); return T_WORD; }
<VAL>\'[^\']*\'      { yylval.s = xstrdup(yytext); return T_WORD; }
<VAL>[^ \t\r\n]+     { yylval.s = xstrdup(yytext); return T_WORD; }

.                    { yylval.s = xstrdup(yytext); return T_WORD; }

%%

int yywrap(void)
{
	return am_pop_input() ? 0 : 1;
}

void am_lex_reset(void)
{
	am_lex_bol = 1;
	BEGIN(INITIAL);
}
