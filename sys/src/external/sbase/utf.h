/* MIT/X Consortium Copyright (c) 2012 Connor Lane Smith <cls@lubutu.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

// we make a new utf.h that uses system Rune functions

#include <stdio.h>
#include "/sys/include/ape/utf.h"


int charntorune(Rune *, const char *, size_t);
char *utfecpy(char *, char *, const char *);
size_t utfmemlen(const char *, size_t);

int isalnumrune(Rune);
int isalpharune(Rune);
int isblankrune(Rune);
int iscntrlrune(Rune);
int isdigitrune(Rune);
int isgraphrune(Rune);
int isprintrune(Rune);
int ispunctrune(Rune);
int isxdigitrune(Rune);

size_t utftorunestr(const char *, Rune *);
size_t utfntorunestr(const char *, size_t, Rune *);

int fgetrune(Rune *, FILE *);
int efgetrune(Rune *, FILE *, const char *);
int fputrune(const Rune *, FILE *);
int efputrune(const Rune *, FILE *, const char *);
