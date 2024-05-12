/* $Id: esql.em,v 1.1.1.1 2000/06/07 21:09:23 stes Exp $ */

#include <stdio.h>
#include <Object.h>
#include <ocstring.h>
#include <ordcltn.h>

EXEC SQL define FNAME_LEN	15;
EXEC SQL define LNAME_LEN	15;

main()
{
    int i;
    id c,d;

EXEC SQL BEGIN DECLARE SECTION;
    char fname[ FNAME_LEN + 1 ];
    char lname[ LNAME_LEN + 1 ];
EXEC SQL END DECLARE SECTION;

    printf( "Sample Objective-C / ESQL Program.\n\n");
    EXEC SQL connect to 'stores7';

    EXEC SQL declare democursor cursor for
	select fname, lname
	   into :fname, :lname
	   from customer
	   where lname < "C";

    c = [OrdCltn new];
    d = [OrdCltn new];

    EXEC SQL open democursor;
    for (;;)
	{
	EXEC SQL fetch democursor;
	if (strncmp(SQLSTATE, "00", 2) != 0)
	    break;

        [c add:[String str:fname]];
        [d add:[String str:lname]];
	}

    if (strncmp(SQLSTATE, "02", 2) != 0)
        printf("SQLSTATE after fetch is %s\n", SQLSTATE);

    EXEC SQL close democursor;
    EXEC SQL free democursor;

    EXEC SQL disconnect current;

    for(i=0;i<[c size];i++) {    
      id e = [c at:i];
      [e printOn:stdout];
      [[d at:i] printOn:stdout];
      printf("\n");
    }
}

