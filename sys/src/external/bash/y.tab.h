#ifndef _yy_defines_h_
#define _yy_defines_h_

#define IF 257
#define THEN 258
#define ELSE 259
#define ELIF 260
#define FI 261
#define CASE 262
#define ESAC 263
#define FOR 264
#define SELECT 265
#define WHILE 266
#define UNTIL 267
#define DO 268
#define DONE 269
#define FUNCTION 270
#define COPROC 271
#define COND_START 272
#define COND_END 273
#define COND_ERROR 274
#define IN 275
#define BANG 276
#define TIME 277
#define TIMEOPT 278
#define TIMEIGN 279
#define WORD 280
#define ASSIGNMENT_WORD 281
#define REDIR_WORD 282
#define NUMBER 283
#define ARITH_CMD 284
#define ARITH_FOR_EXPRS 285
#define COND_CMD 286
#define AND_AND 287
#define OR_OR 288
#define GREATER_GREATER 289
#define LESS_LESS 290
#define LESS_AND 291
#define LESS_LESS_LESS 292
#define GREATER_AND 293
#define SEMI_SEMI 294
#define SEMI_AND 295
#define SEMI_SEMI_AND 296
#define LESS_LESS_MINUS 297
#define AND_GREATER 298
#define AND_GREATER_GREATER 299
#define LESS_GREATER 300
#define GREATER_BAR 301
#define BAR_AND 302
#define DOLPAREN 303
#define yacc_EOF 304
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
  WORD_DESC *word;		/* the word that we read. */
  int number;			/* the number that we read. */
  WORD_LIST *word_list;
  COMMAND *command;
  REDIRECT *redirect;
  ELEMENT element;
  PATTERN_LIST *pattern;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
