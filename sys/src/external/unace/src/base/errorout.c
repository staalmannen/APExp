#define INCL_BASE_ERROROUT

#define INCL_BASE_ARCBLK
#define INCL_BASE_CONVERT
#define INCL_BASE_DIRDATA
#define INCL_BASE_ERROR
#define INCL_BASE_ERROROUT
#define INCL_BASE_STATE
#include "base/includes.h"

#define INCL_APPS_EXE_CONVERT
#define INCL_APPS_EXE_MESSAGES
#define INCL_APPS_EXE_OUTPTERR
#define INCL_APPS_EXE_OUTPUT
#include "unace_includes.h"

/*-----------------BASE_ERROROUT_EXTERN_IsNotCompatible------------------*/

void    BASE_ERROROUT_EXTERN_IsNotCompatible(void)
{
  APPS_EXE_OUTPUT_EXTERN_Warning(STR.Warning,
    STR.This_is_not_a_fully_ACE_compatible_archive_,
    STR.Trying_to_decompress_might_fail_);
}

/*-----------------BASE_ERROROUT_EXTERN_BrokenArchive--------------------*/

void    BASE_ERROROUT_EXTERN_BrokenArchive(void)
{
  APPS_EXE_OUTPUT_EXTERN_Warning(STR.Header_broken,
    STR.Error_while_reading_archive,
    STR.Use_repair_function_to_recover_files_of_archive_);
}

/*-----------------BASE_ERROROUT_EXTERN_Write---------------------------*/

void    BASE_ERROROUT_EXTERN_Write(void)
{
CHAR      ShortStr[80];

  APPS_EXE_OUTPTERR_OutputError(STR.Error_while_writing,
    APPS_EXE_CONVERT_MakeStrShorter(ShortStr, BASE_STATE.CurrentFileName, 38));

}

/*-----------------BASE_ERROROUT_EXTERN_OpenArchiveRead------------------*/

void BASE_ERROROUT_EXTERN_OpenArchiveRead(void)
{
CHAR      ShortStr[80];

  APPS_EXE_OUTPTERR_OutputError(STR.Could_not_open_file_,
                           APPS_EXE_CONVERT_MakeStrShorter(ShortStr, BASE_ARCBLK.ArchiveFile, 26));
}

/*-----------------BASE_ERROROUT_EXTERN_IsNotArchive---------------------*/

void    BASE_ERROROUT_EXTERN_IsNotArchive(void)
{
CHAR      ShortStr[80];

  APPS_EXE_OUTPTERR_OutputError(STR.Is_no_ACE_archive_,
    APPS_EXE_CONVERT_MakeStrShorter(ShortStr, BASE_DIRDATA_Dir1.ArchiveName,30));
}

/*-----------------BASE_ERROROUT_EXTERN_NoFiles--------------------------*/

void BASE_ERROROUT_EXTERN_NoFiles(void)
{
  APPS_EXE_OUTPTERR_OutputError(STR.No_files_specified_,
                           STR.Operation_aborted_);
}

/*-----------------BASE_ERROROUT_EXTERN_ManyFilesError-------------------*/

void    BASE_ERROROUT_EXTERN_ManyFilesError(void)
{
  APPS_EXE_OUTPTERR_OutputError(STR.Not_enough_memory_to_handle_filenames_,
                           STR.Make_more_memory_available__Then_try_again_);

  BASE_ERROR.ErrorCode = BASE_ERROR_MEM;
}

/*-----------------BASE_ERROROUT_EXTERN_Mem------------------------------*/

void BASE_ERROROUT_EXTERN_Mem(void)
{
  APPS_EXE_OUTPTERR_OutputError(
    STR.Not_enough_memory_to_perform_operation_ ?
      STR.Not_enough_memory_to_perform_operation_
      : "Not enough memory to perform operation.",
    STR.Select_smaller_dictionary_size_and_try_again_ ?
      STR.Select_smaller_dictionary_size_and_try_again_
      : "Select smaller dictionary size and try again.");

  BASE_ERROR.ErrorCode = BASE_ERROR_MEM;
}

/*-----------------BASE_ERROROUT_EXTERN_UnknownMethod--------------------*/

void    BASE_ERROROUT_EXTERN_UnknownMethod(void)
{
  APPS_EXE_OUTPTERR_OutputError(STR.File_compressed_with_unknown_method_,
                           STR.Decompression_not_possible_);
}

/*-----------------BASE_ERROROUT_EXTERN_ExtractMem-----------------------*/

void    BASE_ERROROUT_EXTERN_ExtractMem(void)
{
  APPS_EXE_OUTPUT_EXTERN_Warning(STR.Extract,
    STR.Not_enough_memory_or_dictionary_of_archive_too_large_,
    STR.Reduce_compression_dictionary_size__Then_try_again_);
}

/*-----------------BASE_ERROROUT_EXTERN_ExcludePath----------------------*/

void    BASE_ERROROUT_EXTERN_ExcludePath(void)
{
  APPS_EXE_OUTPUT_EXTERN_Warning(STR.Exclude_paths,
                         STR.Error_excluding_paths__two_or_more,
                         STR.specified_files_have_the_same_name_);
}

/*-----------------BASE_ERROROUT_EXTERN_ExtractSpace---------------------*/

void    BASE_ERROROUT_EXTERN_ExtractSpace(void)
{
CHAR      ShortStr[80];

  APPS_EXE_OUTPTERR_OutputError(
    STR.Not_enough_space_on_destination_drive_to_extract,
    APPS_EXE_CONVERT_MakeStrShorter(ShortStr,
    	BASE_CONVERT_ToOEM(BASE_STATE.CurrentFileName), 38));
}

/*-----------------BASE_ERROROUT_EXTERN_OverwriteDelete------------------*/

void    BASE_ERROROUT_EXTERN_OverwriteDelete(void)
{
  APPS_EXE_OUTPUT_EXTERN_Warning(STR.Delete_noun,
                        STR.Could_not_delete_file_or_directory_,
                        STR.Access_denied_);
//BASE_STATE.CurrentFileNameName
}

/*-----------------BASE_ERROROUT_EXTERN_MoveDelete-----------------------*/

void    BASE_ERROROUT_EXTERN_MoveDelete(void)
{
  APPS_EXE_OUTPUT_EXTERN_Warning(STR.Delete_noun,
                        STR.Could_not_delete_file_or_directory_,
                        STR.Access_denied_);
//BASE_STATE.CurrentFileNameName
}

/*-----------------BASE_ERROROUT_EXTERN_CreateDir------------------------*/

void    BASE_ERROROUT_EXTERN_CreateDir(PCHAR Dir)
{
CHAR      ShortStr[80];

  APPS_EXE_OUTPTERR_OutputError(STR.Could_not_create_directory_,
    APPS_EXE_CONVERT_MakeStrShorter(ShortStr, Dir, 26));
}

/*-----------------BASE_ERROROUT_EXTERN_NameInUse------------------------*/

void    BASE_ERROROUT_EXTERN_NameInUse(void)
{
  APPS_EXE_OUTPTERR_OutputError(STR.Could_not_create_directory_,
                           STR.Name_is_used_by_a_file_);
}

/*-----------------BASE_ERROROUT_EXTERN_CreateFile-----------------------*/

void    BASE_ERROROUT_EXTERN_CreateFile(void)
{
CHAR      OutputStr[80],
          ShortStr[80];

  snprintf (OutputStr, sizeof(OutputStr), "%s %s", STR.Could_not_create_destination_file_,
    APPS_EXE_CONVERT_MakeStrShorter(ShortStr,
    	BASE_CONVERT_ToOEM(BASE_STATE.CurrentFileName), 20));

  if (BASE_ERROR.HardwareError)
  {
    APPS_EXE_OUTPTERR_OutputError(OutputStr, STR.Disk_access_error_);
  }
  else
  {
    APPS_EXE_OUTPTERR_OutputError(OutputStr,
                             STR.Disk_might_be_write_protected_);
  }
}

/*-----------------BASE_ERROROUT_EXTERN_AVBroken-------------------------*/

void    BASE_ERROROUT_EXTERN_AVBroken(void)
{
  APPS_EXE_OUTPUT_EXTERN_Warning(STR.Warning,
    STR.Authenticity_verification_of_archive_is_broken_,
    STR.Archive_too_old_or_created_with_non_original_program_);
}

/*-----------------BASE_ERROROUT_EXTERN_ReadArchive----------------------*/

void    BASE_ERROROUT_EXTERN_ReadArchive(void)
{
CHAR      ShortStr[80];

  APPS_EXE_OUTPTERR_OutputError(STR.Error_while_reading_archive,
    APPS_EXE_CONVERT_MakeStrShorter(ShortStr, BASE_ARCBLK.ArchiveFile, 36));
}
