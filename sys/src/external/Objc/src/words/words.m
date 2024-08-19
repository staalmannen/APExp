
/*****************************************************************************
 *
 * ObjectPak Test Program - Example of using LEX & Objective C
 *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "objpak.h"

/*
 * yylex() scans and adds words to the global "words" which may be a Set
 * OrdCltn, SortCltn etc.
 */

id words;
extern int yylex();

#define CLTN_MODE (1)
#define SET_MODE  (2)
#define DIC_MODE  (3)
#define SORT_MODE (4)

static void usage()
{
	fprintf(stderr,"usage: words [-cltn][-set][-dic][-sort]\n");exit(1);
}

static int setMode(int argc,STR *argv)
{
    int i;
    
    for(i=1;i<argc;i++) {
	id arg = [String str:argv[i]];
	if ([arg isEqualSTR:"-cltn"]) return CLTN_MODE;
	if ([arg isEqualSTR:"-set"])  return SET_MODE;
	if ([arg isEqualSTR:"-dic"])  return DIC_MODE;
	if ([arg isEqualSTR:"-sort"]) return SORT_MODE;
    }
    
    usage();
    return 0;
}

static void printCltn()
{
    words = [OrdCltn new];yylex();[words printOn:stdout];
}

static void printSet()
{
    words = [Set new];yylex();[words printOn:stdout];
}

static void printSort()
{
    words = [SortCltn newDictCompare];yylex();[words printOn:stdout];
}

static id createDic(id words)
{
    id aStr,aSeq;
    id aDic = [Dictionary new];
    
    aSeq = [words eachElement];
    while ((aStr = [aSeq next])) {
	id value;
	if ((value = [aDic atKey:aStr])) {
	    id x = [aDic atKey:aStr put:[String sprintf:"%i",[value asInt]+1]];
#ifndef OBJC_REFCNT
            x = [x free];
#endif
	} else {
	    [aDic atKey:aStr put:[String sprintf:"%i",1]];
	}
    }
#ifndef OBJC_REFCNT
    aSeq = [aSeq free];
#endif
    
    return aDic;
}

static void printDic()
{
    words = [OrdCltn new];yylex();[createDic(words) printOn:stdout];
}

void main(int argc,STR *argv)
{
    int mode = setMode(argc,argv);
    
    switch(mode) {
	case CLTN_MODE : { printCltn();break; } 
	case SET_MODE  : { printSet(); break; } 
	case DIC_MODE  : { printDic(); break; } 
	case SORT_MODE : { printSort();break; } 
	default        : { break; }
    }

#ifndef OBJC_REFCNT
    words = [[words freeContents] free];
#else
    words = nil;
#endif
}

