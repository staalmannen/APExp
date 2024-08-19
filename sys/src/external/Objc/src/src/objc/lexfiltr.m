/*
 * FILE:    lexfiltr.m
 *
 * AUTHOR:  Lee R. Willis
 *
 * PURPOSE:
 *
 * This code acts as filter between the LEX and YACC code for the POC compiler.
 *
 * Normally, YACC fetches tokens directly, via the function 'yylex()'.
 *
 *          LEX -----------> YACC
 *                tokens
 *
 * But in this case I've used the LEX macro YY_DECL to rename the yylex() function
 * to 'yylex_raw()', and put a new 'yylex()' function here in this file.
 *
 * This code sits between LEX and YACC, and modifies the token stream 
 * to handle special conditions that can't easily be handled within LEX and YACC.
 *
 *          LEX -----------> lexfilter ----------> YACC
 *                tokens                 tokens
 *
 *
 * The problem to be handled is that of typedef names.  Whether a typedef'ed name
 * should be considered an identifier or a typeword is a nasty problem for
 * LALR parsers.  (This is described in the Bison manual chapter "Handling 
 * Context Dependencies")
 *
 * Take the following statements:
 *
 *    LINE
 *    1     typedef int FOO;
 *    2     FOO foo;
 *    3     typedef FOO BAR;
 *    4     typedef int FOO; // legal C syntax!
 *    
 *
 * On line 1, 'FOO' is considered an identifier, b/c it hasn't been
 * encountered before.  On lines 2 and 3, 'FOO' is a typeword, because it was
 * typedef'ed on line 1.  But on line 4, FOO has to be treated as an 
 * identifier again, because it's legal to redefine a typedef.
 *
 * Rather than trying to handle it within the YACC code, this special case is
 * handled here in the filter.  Identifier tokens which have been previously
 * typedef'ed are promoted to 'typeword' tokens, _unless_ the identifier itself 
 * is the target of a typedef declaration.  So on line 4 above, the filter will 
 * recognize that token 'FOO' is the target of a typedef declaration, and 
 * demote it back to an identifier.
 *
 *    HOW TYPEDEF TARGET IDENTIFIERS ARE RECOGNIZED
 *
 * An identifier is treated as the target of a typedef if it meets the
 * following conditions:
 *
 * 1) It must be part of a statement that began with the keyword 'typedef'.
 *
 * 2) It must not be the token immediately following the keyword 'typedef'.
 *
 * 3) For typedefs of data types:
 *
 *      3a) It is immediately followed by a semi-colon or comma, 
 *            AND 
 *      3b) it is at the same nesting level as the 'typedef' keyword (i.e. 
 *          not enclosed by parens, braces, or brackets).
 *
 *    e.g.:
 *
 *            typedef struct FOO { int BAR; } * PFOO, ** PPFOO;
 *
 *    'FOO' is not the target, because it is not followed by a semicolon or comma.
 *
 *    'BAR' is not the target of the typedef because it is nested within {}.
 *
 *    'PFOO' and 'PPFOO' are both targets.
 *
 * 4) For typedefs for pointers-to-functions:
 *
 *      4a) It is immediately followd by a right-paren (')')
 *            AND
 *      4b) It is nested one left-paren deeper than the keyword 'typedef'
 *            AND
 *      4c) There has been exactly one left-paren since the keyword 'typedef', 
 *          or separating comma.
 *
 *    e.g.:
 *
 *            typedef FOO (*BAR)( int BAZ );
 *
 *    'FOO' is not a target, because it is the first token after 'typedef', 
 *    and it is not enclosed in a '('.
 *
 *    'BAR' is the target of the typedef.
 *
 *    'BAZ' is not a target, because there are two left-parens preceding it.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <objc.h>

#include "util.h"
#include "options.h"
#include "yacc.h"

/* This is the output of 'LEX' */
extern int  yylex_raw(void);

extern BOOL isbuiltinfun(id x);
extern BOOL istypeword(id x);

/* global variables declared in "lex.lm */
extern char*  yytext;
extern int    okblock;


/*
 * --------------------------------------------------------------
 * local types
 * --------------------------------------------------------------
 */

/* 
 * This struct is used to count grouping tokens.  e.g. each time a '(' is 
 * encountered, 'parens' is incremented.  Each time a ')' is
 * encountered, 'parens' is decremented.  etc.
 *
 * You can tell if two tokens are within the same scope if their
 * nesting levels are the same.  e.g.
 *
 *  struct FOO { int bar } foo;
 *
 * 'FOO' and 'foo' will be on the same level, but 'bar' will have a 
 * different level.
 */
struct nesting
{
  int braces;   /* '[]' */
  int brackets; /* '{}' */
  int parens;   /* '()' */
};

extern id yylval;

/*
 * This struct stores information about a token.
 * Note that we must store _all_ aspects of a token which
 * are exported from LEX, either explicitly (via 'yylex_raw()') or 
 * indirectly via global variables.  The filter does a one token
 * look-ahead, so the LEX code will be one token ahead of the
 * rest of the parser.
 */
struct token
{
  int   original; /* orginal yylex_raw() value    */
  int   filtered; /* 'filtered' yylex() value     */
  id    yylval;   /* LEX yylval global value      */
  int   okblock;  /* global declared in lex.lm    */
  
#ifdef PRESERVE_YYTEXT
  /*
   * For debugging only.  This preserves the string value of the token.
   * Saving it slows down the parsing, so we only want this here when
   * we're debugging.
   */
  char  yytext[128]; 
#endif /* PRESERVE_YYTEXT */
};



/*
 * --------------------------------------------------------------
 * local functions
 * --------------------------------------------------------------
 */

/*
 * Fetch a token from LEX and store all the global variables
 * associated with that token.
 */
static void get_token( struct token* token )
{
  token->original = yylex_raw();
  token->filtered = token->original;
  
  /* cache globals associated with current token */
  token->yylval   = yylval;
  token->okblock  = okblock;
  
#ifdef PRESERVE_YYTEXT
  if (yytext == NULL)
    token->yytext[0] = 0;
  else
    strncpy( token->yytext, yytext, 128 );
#endif /* PRESERVE_YYTEXT */
}

/*
 * Restore the global variables associated with a token.
 */
static void restore_globals( const struct token* token )
{
  yylval  = token->yylval;
  okblock = token->okblock;
}

/*
 * Keep track of the nesting level of the current token,
 * i.e. how many parens, braces, or brackets have
 * been encountered.
 */
static void eval_nesting( struct nesting *n, int token )
{
  switch( token )
  {
    case '[':
      n->braces++;
      break;

    case ']':
      n->braces--;
      break;

    case '{':
      n->brackets++;
      break;

    case '}':
      n->brackets--;
      break;

    case '(':
      n->parens++;
      break;

    case ')':
      n->parens--;
      break;
  }
}

/*
 * Returns TRUE is nesting levels 'n0' and 'n1' have the same
 * values, i.e. are within the same lexical scope.
 */
static BOOL same_nesting(
  const struct nesting *n0,
  const struct nesting *n1 )
{
  return ((n0->braces   == n1->braces)    &&
          (n0->brackets == n1->brackets)  &&
          (n0->parens   == n1->parens));
}


/*
 * --------------------------------------------------------------
 * public functions
 * --------------------------------------------------------------
 */

int yylex()
{
  if (!o_duptypedefs) { 
    /* do not allow duplicate typedefs */
    return yylex_raw();
  } 
  else { 
    /* allow duplicate typedefs */
    
    static BOOL first = YES;
    static struct nesting currentlevel;
    static struct nesting typedeflevel;
    /*
     *  typedef_count = # of tokens into a typedef definition.
     *
     *    == 0 --> not in a typedef
     *    == 1 --> the 'typedef' keyword itself.
     *    >  1 --> a token within the typedef.
     */
    static int typedef_count;
    static int lparen_count; /* # of '(' tokens after a typedef */
    static struct token token, nexttoken;

    if (first) { /* do set-up only once */
      get_token( &nexttoken ); /* pre-load the first 'next' token */
      first = NO;
    }

    /* get a token */
    token = nexttoken;
    restore_globals( &nexttoken );
    get_token( &nexttoken );

    if (typedef_count)
      typedef_count++;

    eval_nesting( &currentlevel, token.original );

    switch( token.original ) {

      /* begin a typedef */
      case typedefkeyw:
        typedef_count   = 1;
        lparen_count    = 0;
        typedeflevel    = currentlevel;
        /*
         * 'typedef' keywords are treated as 'storageclass' tokens
         * by the YACC code.
         */
        token.filtered  = storageclass;
        break;

      /* end a typedef */
      case ';':
        if ((typedef_count) &&
          (same_nesting( &currentlevel, &typedeflevel )))
        {
          typedef_count = 0;
        }
        break;

      case identifier:
        if (isbuiltinfun(token.yylval)) {
          token.filtered = builtinfun;
        }
        else if (istypeword(token.yylval)) {

          /*
           * Normally, identifiers which have already been defined
           * via 'typedef' are promoted to 'typeword's.
           */

          token.filtered = typeword;

          /*
           * But there is an exception when we're inside a typedef:
           * It's legal to redefine a typedef. e.g.
           *
           *    typedef int FOO;
           *    typedef int FOO; // redefinition is OK
           *
           * In the above case, 'FOO' needs to be returned as an
           * identifier, not a typeword.
           */
          if (typedef_count > 2) /* not the very first token after 'typedef' */
          {
            /*
             * Typedefs for data-types.
             *
             * Example:   typedef int FOO ,  * PFOO ;
             */
            if ((same_nesting( &currentlevel, &typedeflevel )) &&
              ((nexttoken.original == ';') || (nexttoken.original == ',')))
            {
              token.filtered = identifier; /* demote back to identifier */
            }

            /*
             * Typedefs for pointers-to-functions.
             *
             * Example: typedef int (*FOO)();
             */

            else if (( currentlevel.braces    == typedeflevel.braces )  &&
                     ( currentlevel.brackets  == typedeflevel.brackets )  &&
                     ( currentlevel.parens    == typedeflevel.parens+1 )  &&
                     ( lparen_count           == 1 )            &&
                     ( nexttoken.original     == ')' ))
            {
              token.filtered = identifier; /* demote back to identifier */
            }
          } /* typedef_count>0 */
        } /* identifier is a typeword */
        break;

      case '(':
        if (typedef_count) /* we're in a typedef definition */
          lparen_count++;
        break;

      case ',':
        if ((typedef_count) && 
            (same_nesting( &currentlevel, &typedeflevel )))
          lparen_count = 0;
        break;

    } /* end switch (tok) */


    /* restore the global variables and return the current token value */
    restore_globals( &token );
    return token.filtered;
  }
}

