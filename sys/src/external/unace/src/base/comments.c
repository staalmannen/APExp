#include <string.h>

#define INCL_BASE_COMMENTS

#define INCL_BASE_ACESTRUC
#define INCL_BASE_ARCBLK
#define INCL_BASE_COMMENTS
#define INCL_BASE_DCPR_COMMENTS
#include "base/includes.h"

#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_INPUT
#define INCL_APPS_EXE_OUTPUT
#include "unace_includes.h"

tBASE_COMMENTS BASE_COMMENTS;

/*-----------------APPS_EXE_EXTERN_COMMENTS_StdOutput--------------------*/
static void APPS_EXE_EXTERN_COMMENTS_StdOutput(void)
{
  APPS_EXE_OUTPUT_DeleteRight();

  APPS_EXE_OUTPUT_Write(
    BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_FILE ?
      STR.File_comment : STR.Main_comment);

  printf("\n%s", BASE_COMMENTS.Comment);

  if (strchr(BASE_COMMENTS.Comment, 27))
  {
    printf("[0m");
  }

  APPS_EXE_OUTPUT_KeyWait();
}


/*-----------------BASE_COMMENTS_EXTERN_Output---------------------------*/
void    BASE_COMMENTS_EXTERN_Output(void)
{
  BASE_COMMENTS_ReadComment();

  if (BASE_COMMENTS.Comment[0])
  {
    APPS_EXE_EXTERN_COMMENTS_StdOutput();
  }
}


/*-----------------BASE_COMMENTS_ReadComment---------------------------*/

void    BASE_COMMENTS_ReadComment(void)
{
INT       CommentSize;
PCHAR     CommentPos;

  if (!(BASE_ARCBLK.Header.Basic.HEAD_FLAGS & BASE_ACESTRUC_FLAG_COMMENT))
  {
    CommentSize = 0;
  }
  else
  {
    if (BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_FILE)
    {
      CommentPos  = BASE_ARCBLK_FileHeaderComment(&BASE_ARCBLK.Header);
      CommentSize = BASE_ARCBLK_FileHeaderCommentSize(&BASE_ARCBLK.Header);
    }
    else
    {
      if (BASE_ARCBLK.Header.Basic.HEAD_TYPE == BASE_ACESTRUC_BLOCK_MAIN)
      {
        CommentPos  = BASE_ARCBLK_MainHeaderComment(&BASE_ARCBLK.Header);
        CommentSize = BASE_ARCBLK_MainHeaderCommentSize(&BASE_ARCBLK.Header);
      }
      else
      {
        CommentSize = 0;
      }
    }
  }

  if (CommentSize > sizeof(BASE_COMMENTS.Comment) - 1)
  {
    CommentSize = sizeof(BASE_COMMENTS.Comment) - 1;
  }

  if(CommentSize > 0)
  {
    memcpy(BASE_COMMENTS.Comment, CommentPos, CommentSize);
  }
  
  BASE_COMMENTS.CompressedSize = CommentSize;
  BASE_DCPR_COMMENTS_GetComment();
}
