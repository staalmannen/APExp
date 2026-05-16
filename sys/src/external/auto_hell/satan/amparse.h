#ifndef _yy_defines_h_
#define _yy_defines_h_

#define T_IDENT 257
#define T_WORD 258
#define T_EQ 259
#define T_PLUSEQ 260
#define T_COLONEQ 261
#define T_QEQ 262
#define T_COLON 263
#define T_INCLUDE 264
#define T_SINCLUDE 265
#define T_IF 266
#define T_ELSE 267
#define T_ENDIF 268
#define T_NOT 269
#define T_NL 270
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
	char *s;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
