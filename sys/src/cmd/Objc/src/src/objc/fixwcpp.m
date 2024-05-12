
/*
 * Portable Object Compiler - Fix WATCOM cpp output.
 * $Id: fixwcpp.m,v 1.1.1.1 2000/06/07 21:09:25 stes Exp $
 */

/*
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Library General Public License as published 
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 *
 * Input  : .P file, WATCOM wcc -pl output 
 * Output : .P file without line continuation (\) characters 
 * to be used as input for objc1. 
 *
 * This is to deal on WATCOM 11.0 with multiline pragmas (such as malloc.h)
 * #pragma ... \
 *         ...
 * where the WATCOM -pl preserves (doesn't expand) the line continuation.
 *
 * Also needed for WATCOM 10.0
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "ocstring.h"

/* translate line continuation sequences (trailing \ + nl/cr) */

void fixEm(FILE *inIOD,FILE *outIOD)
{
    int c;
    BOOL backslashed = NO;

    while ((c = fgetc(inIOD)) && !feof(inIOD)) {
	if (backslashed && (c=='\n'||c=='\r')) {backslashed=NO;continue;}
        if (backslashed) {fputc('\\',outIOD);backslashed=NO;}
	if (c=='\\') {backslashed=YES;continue;}
        fputc(c,outIOD);
    }

    if (backslashed) fputc('\\',outIOD);
}

id inFile;
id outFile;

/*
 * Options
 */

static BOOL isOption(id s)
{
	return [s size] && [s charAt:0] == '-';
}

static void usage(void)
{
	fprintf(stderr,"usage: fixwcpp [options] [-] [infile [outfile]]\n");
	exit(1);
}

static void unknownOption(id option)
{
	fprintf(stderr,"fixwcpp: Illegal option %s\n",[option str]);
	exit(1);
}

static void setOptions(int argc, char *argv[])
{
	int i;
	int fileCount = 0; /* optional inFile and outFile */
	BOOL checkOption = YES; /* YES if filename can't begin with a dash */

	for(i=1;i<argc;i++) {
		id s = [String str:argv[i]];
		if([s isEqualSTR:"-help"]) {usage();}
		else if([s isEqualSTR:"-"]) { checkOption = NO; }
		else if(checkOption && isOption(s)) {unknownOption(s);}
		else if(fileCount==0) {inFile=s;fileCount++;}
		else if(fileCount==1) {outFile=s;fileCount++;}
		else {unknownOption(s);}
	}
}

int main(int argc,char *argv[])
{
	FILE *inIOD = NULL;
	FILE *outIOD = NULL;

	setOptions(argc,argv);
	
	if (inFile) {
	inIOD = fopen([inFile str],"r");
	if(!inIOD)fprintf(stderr,"fixwcpp: can't open %s",[inFile str]);
	}
	
	if (outFile) {
	outIOD = fopen([outFile str],"w");
	if(!outIOD)fprintf(stderr,"fixwcpp: can't open %s",[outFile str]);
	}
	
	fixEm((inIOD)?inIOD:stdin,(outIOD)?outIOD:stdout);
	
	if (inIOD) { fclose(inIOD); }
	if (outIOD) { fclose(outIOD); }
	
	return 0;
}


