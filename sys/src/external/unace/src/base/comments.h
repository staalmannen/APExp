#ifndef _BASE_COMMENTS_H_INCLUDED
#define _BASE_COMMENTS_H_INCLUDED

#include "base/lfn.h"

#define BASE_COMMENTS_HASHFUNC(A, B)    (A + B)

typedef struct
{
  USHORT  CompressedSize;
  CHAR    Comment[32768];
} tBASE_COMMENTS;

extern tBASE_COMMENTS BASE_COMMENTS;

void    BASE_COMMENTS_ReadComment(void);
void    BASE_COMMENTS_EXTERN_Output(void);

#endif
