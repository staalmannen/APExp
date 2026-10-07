/* Translated by the Edison Design Group C++/C front end (version 7.0) */
/* Wed Oct  7 03:19:53 2026 */
extern int __EDGCPFE__7_0;
void *memcpy(void *,const void *,unsigned long);
void *memset(void *,int,unsigned long);

# 1 "util/edg_prelink.c"
struct __C1; struct __C2; struct __C3; struct __C5; struct __C6; union __C7; struct __C8;
# 49 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3
struct _IO_FILE;
# 11 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 3
struct timespec;
# 26 "/usr/include/x86_64-linux-gnu/bits/struct_stat.h" 3
struct stat;
# 84 "util/edg_prelink.c"
struct a_pl_instantiation_site;
# 100
struct a_pl_assignment;
# 116
struct a_pl_symbol;
# 226
struct a_pl_object_file;
# 258
struct a_pl_input_file;
# 333
struct a_pl_file_list_entry;
# 351
union _ZN17a_pl_cmd_line_argUt_E;
# 344
struct a_pl_cmd_line_arg;
# 464
enum an_nm_format_kind {
nmfk_default,

nmfk_solaris,

nmfk_SGI,

nmfk_SVR4,

nmfk_HPUX,

nmfk_CLIX,

nmfk_gnu,

nmfk_MacOSX,

nmfk_MacOSX64,


nmfk_lst};
# 662
enum a_pl_error_code {
pl_ec_no_longer_needed,
pl_ec_assigned_to_file,
pl_ec_message_prefix,
pl_ec_executing,
pl_ec_unrecognized_option,
pl_ec_error,
pl_ec_out_of_memory,
pl_ec_invalid_input,
pl_ec_bad_instantiation_request_file,
pl_ec_invalid_nm_format_option,
pl_ec_command_line_error,
pl_ec_instantiation_loop,
pl_ec_lib_file_not_found,
pl_ec_error_occurred_during_name_decoding,
pl_ec_warning,
pl_ec_invalid_reserved_request_lines_option,
pl_ec_cannot_open_obj_file_list_file,
pl_ec_cannot_open_request_file,
pl_ec_cannot_chdir,
pl_ec_no_nm_info,
pl_ec_popen_failed,
pl_ec_specialized_and_instantiated,
pl_ec_cannot_open_file_for_update,
pl_ec_nm_returned_error,
pl_ec_multiple_assignments,
pl_ec_no_object_file_name_specified,
pl_ec_invalid_definition_list_option,
pl_ec_cannot_open_temporary_file,
pl_ec_adopted_by_file,
pl_ec_out_of_date,
pl_ec_corrupted_template_info_file,
pl_ec_last};
# 3966 "src/util.h"
enum _ZN3edg6detail16a_text_alignmentE {
_ZN3edg6detail7ta_leftE,
_ZN3edg6detail8ta_rightE}; struct __C3 { struct __C2 *regions; void **obj_table; struct __C1 *array_table; unsigned short saved_region_number;char __dummy[6];}; struct __C6 { long setjmp_buffer[25]; struct __C5 *catch_entries; void *rtinfo; unsigned short region_number;char __dummy[6];}; union __C7
# 3968
 { struct __C6 try_block; struct __C3 function; struct __C5 *throw_spec;}; struct __C8 { struct __C8 *next; unsigned char kind; union __C7 variant;};
# 145 "/usr/include/x86_64-linux-gnu/bits/types.h" 3
typedef unsigned long __dev_t;
typedef unsigned __uid_t;
typedef unsigned __gid_t;
typedef unsigned long __ino_t;

typedef unsigned __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;

typedef int __pid_t;
# 160
typedef long __time_t;
# 175
typedef long __blksize_t;




typedef long __blkcnt_t;
# 197
typedef long __syscall_slong_t;
# 214 "/usr/lib/gcc/x86_64-linux-gnu/13/include/stddef.h" 3
typedef unsigned long size_t;
# 7 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 3
typedef struct _IO_FILE FILE;
# 10 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h" 3
typedef __time_t time_t;
# 11 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 3
struct timespec {




__time_t tv_sec;




__syscall_slong_t tv_nsec;};
# 26 "/usr/include/x86_64-linux-gnu/bits/struct_stat.h" 3
struct stat {




__dev_t st_dev;




__ino_t st_ino;
# 44
__nlink_t st_nlink;
__mode_t st_mode;

__uid_t st_uid;
__gid_t st_gid;

int __pad0;

__dev_t st_rdev;




__off_t st_size;



__blksize_t st_blksize;

__blkcnt_t st_blocks;
# 74
struct timespec st_atim;
struct timespec st_mtim;
struct timespec st_ctim;
# 89
__syscall_slong_t __glibc_reserved[3];};
# 499 "src/basics.h"
typedef void *_ZN3edg10a_void_ptrE;
# 61 "util/edg_prelink.c"
typedef _ZN3edg10a_void_ptrE a_realloc_arg;
# 76
typedef struct a_pl_input_file *a_pl_input_file_ptr;
typedef struct a_pl_object_file *a_pl_object_file_ptr;
typedef struct a_pl_file_list_entry *a_pl_file_list_entry_ptr;




typedef struct a_pl_instantiation_site *a_pl_instantiation_site_ptr;
struct a_pl_instantiation_site {

a_pl_instantiation_site_ptr next;


a_pl_input_file_ptr input_file;};
# 99
typedef struct a_pl_assignment *a_pl_assignment_ptr;
struct a_pl_assignment {

a_pl_assignment_ptr next;

char *name;
int times_assigned;char __dummy[4];};
# 115
typedef struct a_pl_symbol *a_pl_symbol_ptr;
# 200 "src/basics.h"
typedef unsigned char _ZN3edg6a_byteE;
# 220
typedef _ZN3edg6a_byteE _ZN3edg14a_byte_booleanE;
# 116 "util/edg_prelink.c"
struct a_pl_symbol {

a_pl_symbol_ptr next;


a_pl_symbol_ptr next_in_symbol_table;


a_pl_symbol_ptr next_in_request_file;


a_pl_symbol_ptr next_in_specialization_list;



a_pl_input_file_ptr instantiation_file;



a_pl_instantiation_site_ptr possible_instantiation_sites;



a_pl_symbol_ptr global_sym;
# 149
a_pl_symbol_ptr template_sym;
# 156
a_pl_symbol_ptr primary_entry;




char *name;


_ZN3edg14a_byte_booleanE referenced;
# 170
_ZN3edg14a_byte_booleanE defined;




_ZN3edg14a_byte_booleanE definition_seen_in_archive;
# 182
_ZN3edg14a_byte_booleanE tentative_definition;
# 188
_ZN3edg14a_byte_booleanE multiple_definition;



_ZN3edg14a_byte_booleanE is_template;



_ZN3edg14a_byte_booleanE can_be_instantiated;



_ZN3edg14a_byte_booleanE do_not_instantiate;
# 207
_ZN3edg14a_byte_booleanE instantiated;
# 214
_ZN3edg14a_byte_booleanE is_specialization;



a_pl_input_file_ptr defined_in;};
# 226
struct a_pl_object_file {

a_pl_object_file_ptr next;


char *file_name;



a_pl_symbol_ptr symbols;



_ZN3edg14a_byte_booleanE included_in_output;
# 245
_ZN3edg14a_byte_booleanE is_related_file;




time_t modification_time;};
# 515 "src/basics.h"
typedef const char _ZN3edg12a_const_charE;
# 258 "util/edg_prelink.c"
struct a_pl_input_file {

a_pl_input_file_ptr next;

char *file_name;

char *orig_name;




char *request_file_name;



char *template_info_file_name;




char *command_line;

char *compilation_directory;


char *compilation_file_name;


char *secondary_files;



a_pl_file_list_entry_ptr dependencies;




char *instantiation_directory;



_ZN3edg12a_const_charE *reserved_lines[1];
# 305
a_pl_object_file_ptr objects;




a_pl_symbol_ptr request_list;


_ZN3edg14a_byte_booleanE is_archive;


_ZN3edg14a_byte_booleanE request_file_updated;




_ZN3edg14a_byte_booleanE recompile;



_ZN3edg14a_byte_booleanE is_local_file;char __dummy[4];};
# 333
struct a_pl_file_list_entry {

a_pl_file_list_entry_ptr next;

char *name;};
# 343
typedef struct a_pl_cmd_line_arg *a_pl_cmd_line_arg_ptr;
# 351
union _ZN17a_pl_cmd_line_argUt_E {

char *arg_string;



a_pl_input_file_ptr input_file_entry;};
# 219 "src/basics.h"
typedef int _ZN3edg9a_booleanE;
# 344 "util/edg_prelink.c"
struct a_pl_cmd_line_arg {

a_pl_cmd_line_arg_ptr next;

_ZN3edg9a_booleanE is_string;
# 360
union _ZN17a_pl_cmd_line_argUt_E variant;};
# 540
typedef char a_pl_input_line[32767];
# 541 "src/basics.h"
typedef size_t _ZN3edg8sizeof_tE;
# 184 "/usr/include/stdio.h" 3
extern int fclose(FILE *__stream);
# 236
extern int fflush(FILE *__stream);
# 264
extern __attribute__((__malloc__)) FILE *fopen(const char *__filename, const char *__modes);
# 357
extern int fprintf(FILE *__stream, const char *__format, ...);
# 385
extern __attribute__((__nothrow__)) int snprintf(char *__s, size_t __maxlen, const char *__format, ...);
# 576
extern int getc(FILE *__stream);
# 717
extern int fputs(const char *__s, FILE *__stream);
# 897
extern int pclose(FILE *__stream);
# 903
extern __attribute__((__malloc__)) FILE *popen(const char *__command, const char *__modes);
# 105 "/usr/include/stdlib.h" 3
extern __attribute__((__pure__)) __attribute__((__nothrow__)) int atoi(const char *__nptr);
# 672
extern __attribute__((__alloc_size__(1))) __attribute__((__malloc__)) __attribute__((__nothrow__)) void *malloc(size_t __size);
# 683
extern __attribute__((__alloc_size__(2))) __attribute__((__nothrow__)) void *realloc(void *__ptr, size_t __size);



extern __attribute__((__nothrow__)) void free(void *__ptr);
# 730
extern __attribute__((__nothrow__)) __attribute__((__noreturn__)) void abort(void);
# 756
extern __attribute__((__nothrow__)) __attribute__((__noreturn__)) void exit(int __status);
# 773
extern __attribute__((__nothrow__)) char *getenv(const char *__name);
# 923
extern int system(const char *__command);
# 61 "/usr/include/string.h" 3
extern __attribute__((__nothrow__)) void *memset(void *__s, int __c, size_t __n);
# 141
extern __attribute__((__nothrow__)) char *strcpy(char *__dest, const char *__src);


extern __attribute__((__nothrow__)) char *strncpy(char *__dest, const char *__src, size_t __n);
# 152
extern __attribute__((__nothrow__)) char *strncat(char *__dest, const char *__src, size_t __n);



extern __attribute__((__pure__)) __attribute__((__nothrow__)) int strcmp(const char *__s1, const char *__s2);


extern __attribute__((__pure__)) __attribute__((__nothrow__)) int strncmp(const char *__s1, const char *__s2, size_t __n);
# 226
extern __attribute__((__pure__)) __attribute__((__nothrow__)) char *_Z6strchrPci(char *__s, int __c) __asm__("strchr");
# 253
extern __attribute__((__pure__)) __attribute__((__nothrow__)) char *_Z7strrchrPci(char *__s, int __c) __asm__("strrchr");
# 330
extern __attribute__((__pure__)) __attribute__((__nothrow__)) char *_Z6strstrPcPKc(char *__haystack, const char *__needle) __asm__("strstr");
# 407
extern __attribute__((__pure__)) __attribute__((__nothrow__)) size_t strlen(const char *__s);
# 109 "/usr/include/ctype.h" 3
extern __attribute__((__nothrow__)) int isalpha(int);
# 37 "/usr/include/errno.h" 3
extern __attribute__((__nothrow__)) __attribute__((__const__)) int *__errno_location(void);
# 517 "/usr/include/unistd.h" 3
extern __attribute__((__nothrow__)) int chdir(const char *__path);
# 531
extern __attribute__((__nothrow__)) char *getcwd(char *__buf, size_t __size);
# 650
extern __attribute__((__nothrow__)) __pid_t getpid(void);
# 858
extern __attribute__((__nothrow__)) int unlink(const char *__name);
# 205 "/usr/include/x86_64-linux-gnu/sys/stat.h" 3
extern __attribute__((__nothrow__)) int stat(const char *__file, struct stat *__buf);
# 16 "util/decode.h"
extern void _Z17decode_identifierPKcPcmPiS2_Pm(_ZN3edg12a_const_charE *id, char *output_buffer, _ZN3edg8sizeof_tE output_buffer_size, _ZN3edg9a_booleanE *err, _ZN3edg9a_booleanE *buffer_overflow_err, _ZN3edg8sizeof_tE *required_buffer_size);
# 57 "util/getopt.h"
extern __attribute__((__nothrow__)) int getopt(int argc, char *const *argv, const char *optstring);
# 558 "util/edg_prelink.c"
static void _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(_ZN3edg12a_const_charE *error_string);
# 575
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_(_ZN3edg12a_const_charE *filename, int line_number, _ZN3edg12a_const_charE *string1, _ZN3edg12a_const_charE *string2);
# 632
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind24pl_is_absolute_file_nameEPc(char *file_name);
# 647
static void _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_get_curr_dir_nameEv(void);
# 698
static _ZN3edg12a_const_charE *_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(enum a_pl_error_code error_code);
# 810
static void _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_error_with_exitE15a_pl_error_codePci(enum a_pl_error_code error_code, char *insertion_string, _ZN3edg9a_booleanE exit_when_done);
# 829
static void _ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(enum a_pl_error_code error_code, char *insertion_string);
# 841
static void _ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc(enum a_pl_error_code error_code, char *insertion_string);
# 856
static _ZN3edg10a_void_ptrE _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(_ZN3edg8sizeof_tE size);
# 871
static _ZN3edg10a_void_ptrE _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_realloc_with_checkEPvm(_ZN3edg10a_void_ptrE old_ptr, _ZN3edg8sizeof_tE new_size);
# 895
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19reset_pl_input_fileEP15a_pl_input_file(a_pl_input_file_ptr pifp);
# 916
static a_pl_input_file_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_input_fileEv(void);
# 933
static a_pl_object_file_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv(void);
# 957
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19free_pl_object_fileEP16a_pl_object_file(a_pl_object_file_ptr pofp);
# 967
static a_pl_assignment_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_assignmentEv(void);
# 982
static a_pl_file_list_entry_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind24alloc_pl_file_list_entryEv(void);
# 997
static a_pl_symbol_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv(void);
# 1034
static a_pl_instantiation_site_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind27alloc_pl_instantiation_siteEv(void);
# 1054
static void _ZN33_INTERNAL_13_edg_prelink_c_optind26free_pl_instantiation_siteEP23a_pl_instantiation_site(a_pl_instantiation_site_ptr pisp);
# 1064
static void _ZN33_INTERNAL_13_edg_prelink_c_optind14free_pl_symbolEP11a_pl_symbol(a_pl_symbol_ptr psp);
# 1074
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(FILE *f_input);
# 1104
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(_ZN3edg12a_const_charE *source);
# 1117
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind29pl_is_explicit_specializationEPc(char *name);
# 1132
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPc(char *name);
# 1164
static void _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(void);
# 1173
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc(char *encoded_name);
# 1209
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_solaris_nm_lineEPPcS1_S0_S1_(char **name1, char **name2, char *type, char **symbol_name);
# 1319
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_(char **name1, char **name2, char *type, char **symbol_name);
# 1508
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_default_nm_lineEPPcS1_S0_S1_(char **name1, char **name2, char *type, char **symbol_name);
# 1733
static void _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_read_nm_outputEv(void);
# 1908
static void _ZN33_INTERNAL_13_edg_prelink_c_optind31add_possible_instantiation_siteEP11a_pl_symbolP15a_pl_input_file(a_pl_symbol_ptr psp, a_pl_input_file_ptr pifp);
# 1930
static unsigned _ZN33_INTERNAL_13_edg_prelink_c_optind19hash_value_for_nameEPc(char *name);
# 1966
static a_pl_assignment_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_find_assignmentEPc(char *name);
# 1996
static a_pl_symbol_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi(char *name, a_pl_symbol_ptr other_sym, _ZN3edg9a_booleanE add, _ZN3edg9a_booleanE *p_new);
# 2090
static void _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_add_predefined_namesEv(void);
# 2112
static void _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_add_symbols_from_objectEP16a_pl_object_fileP15a_pl_input_file(a_pl_object_file_ptr pofp, a_pl_input_file_ptr input_file);
# 2222
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_any_symbols_referencedEP16a_pl_object_file(a_pl_object_file_ptr pofp);
# 2262
static void _ZN33_INTERNAL_13_edg_prelink_c_optind10pl_prelinkEv(void);
# 2311
static void _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(void);
# 2321
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_suffixEPc(char *name);
# 2334
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_derived_nameEPKcS1_(_ZN3edg12a_const_charE *name, _ZN3edg12a_const_charE *suffix);
# 2366
static void _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_read_template_info_fileEP15a_pl_input_file(a_pl_input_file_ptr pifp);
# 2544
static void _ZN33_INTERNAL_13_edg_prelink_c_optind38pl_read_command_info_from_request_fileEP15a_pl_input_fileP8_IO_FILE(a_pl_input_file_ptr pifp, FILE *f_request);
# 2589
static void _ZN33_INTERNAL_13_edg_prelink_c_optind35pl_read_instantiation_request_filesEv(void);
# 2638
static void _ZN33_INTERNAL_13_edg_prelink_c_optind34pl_create_instantiation_file_namesEP15a_pl_input_filePPcS3_(a_pl_input_file_ptr pifp, char **request_file_name, char **template_info_file_name);
# 2665
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_check_for_template_fileEP15a_pl_input_file(a_pl_input_file_ptr pifp);
# 2700
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_can_instantiateEP15a_pl_input_fileP11a_pl_symbol(a_pl_input_file_ptr pifp, a_pl_symbol_ptr psp);
# 2722
static void _ZN33_INTERNAL_13_edg_prelink_c_optind17record_assignmentEPc(char *name);
# 2745
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_check_dependenciesEP15a_pl_input_file(a_pl_input_file_ptr pifp);
# 2788
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_determine_actionsEi(_ZN3edg9a_booleanE do_local_files);
# 2969
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_change_directoryEPc(char *new_dir);
# 2984
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc(char **dest, _ZN3edg12a_const_charE *source);
# 3030
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind18build_command_lineEPKcS1_S1_S1_(_ZN3edg12a_const_charE *part1, _ZN3edg12a_const_charE *part2, _ZN3edg12a_const_charE *part3, _ZN3edg12a_const_charE *part4);
# 3065
static int _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_recompile_fileEP15a_pl_input_filePKcS3_(a_pl_input_file_ptr pifp, _ZN3edg12a_const_charE *extra_command_args, _ZN3edg12a_const_charE *extra_args_for_display);
# 3125
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind18last_dir_separatorEPc(char *file_name);
# 3148
static void _ZN33_INTERNAL_13_edg_prelink_c_optind29prepare_to_move_nonlocal_fileEP15a_pl_input_file(a_pl_input_file_ptr pifp);
# 3234
static FILE *_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_create_temp_fileEv(void);
# 3266
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEv(void);
# 3305
static void _ZN33_INTERNAL_13_edg_prelink_c_optind35pl_check_for_adopted_instantiationsEP15a_pl_input_file(a_pl_input_file_ptr pifp);
# 3346
static int _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_update_request_filesEv(void);
# 3427
static int _ZN33_INTERNAL_13_edg_prelink_c_optind29pl_remove_instantiation_flagsEv(void);
# 3460
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind34pl_check_for_specialization_errorsEv(void);
# 3507
static void _ZN33_INTERNAL_13_edg_prelink_c_optind12pl_db_symbolEP11a_pl_symbolPKc(a_pl_symbol_ptr psp, _ZN3edg12a_const_charE *prefix_string);
# 3537
static void _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_db_input_filesEv(void);
# 3572
static void _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_db_global_symbolsEi(_ZN3edg9a_booleanE all);
# 3600
static void _ZN33_INTERNAL_13_edg_prelink_c_optind11pl_free_allEv(void);
# 3685
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_init_temp_stringEv(void);
# 3695
static void _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(_ZN3edg12a_const_charE *addition);
# 3713
static void _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_add_two_to_temp_stringEPKcS1_(_ZN3edg12a_const_charE *add1, _ZN3edg12a_const_charE *add2);
# 3725
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_find_library_nameEPc(char *lib_name);
# 3777
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_add_cmd_line_argEPcP15a_pl_input_file(char *str, a_pl_input_file_ptr pifp);
# 3800
extern int main(int argc, char **argv);
# 4193 "src/util.h"
extern  __attribute__((__weak__)) /* COMDAT group: _ZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_ */ int _ZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_(char *dest_buff, size_t dest_buff_size, _ZN3edg12a_const_charE *format_str, unsigned long __1_args);
# 22 "src/host_util.h"
extern unsigned long _ZN3edg6crc_32EPKcm(_ZN3edg12a_const_charE *str, unsigned long prev_crc);
# 55
extern _ZN3edg12a_const_charE *_ZN3edg39generate_instantiation_output_file_nameEPKc(_ZN3edg12a_const_charE *mangled_name);
# 223
extern _ZN3edg9a_booleanE _ZN3edg26get_file_modification_timeEPKcPl(_ZN3edg12a_const_charE *file_name, time_t *p_time);
# 151 "/usr/include/stdio.h" 3
extern FILE *stderr;
# 95 "util/edg_prelink.h"
static char default_nm_command[12];
static char gnu_nm_command[18];
static char solaris_nm_command[8];
static char SGI_nm_command[13];
static char CLIX_nm_command[14];
static char alternate_nm_command[13];
static char nm_command_suffix[1];

static char *pl_predefined_names[1];
# 45 "util/getopt.h"
char *optarg = 0;


extern int optind;

extern int opterr;
# 76
static char *_ZZ6getoptE7optchar; extern struct __C8 *__curr_eh_stack_entry;
# 365 "util/edg_prelink.c"
static a_pl_object_file_ptr avail_pl_object_files;
static a_pl_symbol_ptr avail_pl_symbols;
static a_pl_instantiation_site_ptr avail_pl_instantiation_sites;


static a_pl_input_file_ptr pl_input_files;


static FILE *f_command_output;




static a_pl_symbol_ptr pl_symbol_table_head;



static a_pl_symbol_ptr specialization_list;
# 389
static char pl_file_name_buffer[4096];



static _ZN3edg9a_booleanE verbose;




static _ZN3edg9a_booleanE suppress_compilation;




static _ZN3edg9a_booleanE mangled_names_in_output;




static _ZN3edg9a_booleanE limit_recursion;
# 414
static _ZN3edg9a_booleanE do_not_assign_to_nonlocal_objects;
# 421
static _ZN3edg9a_booleanE check_specialization_errors;
# 428
static _ZN3edg9a_booleanE suppress_dependency_checking;




static char **L_directories;



static int num_of_L_directories;




static _ZN3edg9a_booleanE one_instantiation_per_object;




static _ZN3edg9a_booleanE use_template_info_file;



static _ZN3edg9a_booleanE use_definition_list;



static char *temporary_file_name;



static FILE *f_informational;
# 488
static enum an_nm_format_kind nm_format;



static _ZN3edg9a_booleanE ignore_invalid_nm_output;



static _ZN3edg12a_const_charE *message_prefix;




static _ZN3edg9a_booleanE skip_underscore_prefix;
# 508
static _ZN3edg9a_booleanE move_nonlocal_objects_to_curr_dir;




static FILE *f_obj_file_list;
# 520
static char curr_dir_name[2048];


static int reserved_request_file_lines;
# 531
static int pl_debug_level;
# 541
static a_pl_input_line pl_input_line;



static a_pl_assignment_ptr pl_assignment_table[599];



static a_pl_symbol_ptr pl_symbol_table[10007];
# 65 "src/host_util.h"
static char _ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer[32];
# 1139 "util/edg_prelink.c"
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer;
# 1181
static char _ZZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPcE13decode_buffer[32767];
# 1410
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer;
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name2_buffer;

static _ZN3edg9a_booleanE _ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E13name2_is_NULL;
# 3275
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEvE22definition_list_option;
# 3667
static char *temp_string;



static _ZN3edg8sizeof_tE temp_string_length;


static _ZN3edg8sizeof_tE pos_in_temp_string;
# 3770
static a_pl_cmd_line_arg_ptr cmd_line_head;



static a_pl_cmd_line_arg_ptr cmd_line_tail; extern  __attribute__((__weak__)) /* COMDAT group: _ZZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_Es */ char _ZZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_Es[94]; extern  __attribute__((__weak__)) /* COMDAT group:  */
# 3774
/* _ZZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_Es_0 */ char _ZZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_Es_0[1];
# 95 "util/edg_prelink.h"
static char default_nm_command[12] = "/bin/nm -og";
static char gnu_nm_command[18] = "nm -og --no-cplus";
static char solaris_nm_command[8] = "nm -pxR";
static char SGI_nm_command[13] = "/bin/nm -Bop";
static char CLIX_nm_command[14] = "/bin/nm -pxre";
static char alternate_nm_command[13] = "/bin/nm -pxr";
static char nm_command_suffix[1] = "";

static char *pl_predefined_names[1] = {((char *)0)};
# 48 "util/getopt.h"
int optind = 1;

int opterr = 1;
# 76
static char *_ZZ6getoptE7optchar = ((char *)0);
# 365 "util/edg_prelink.c"
static a_pl_object_file_ptr avail_pl_object_files = ((a_pl_object_file_ptr)0);
static a_pl_symbol_ptr avail_pl_symbols = ((a_pl_symbol_ptr)0);
static a_pl_instantiation_site_ptr avail_pl_instantiation_sites = ((a_pl_instantiation_site_ptr)0);


static a_pl_input_file_ptr pl_input_files = ((a_pl_input_file_ptr)0);
# 378
static a_pl_symbol_ptr pl_symbol_table_head = ((a_pl_symbol_ptr)0);



static a_pl_symbol_ptr specialization_list = ((a_pl_symbol_ptr)0);
# 393
static _ZN3edg9a_booleanE verbose = 1;




static _ZN3edg9a_booleanE suppress_compilation = 0;




static _ZN3edg9a_booleanE mangled_names_in_output = 0;




static _ZN3edg9a_booleanE limit_recursion = 1;
# 414
static _ZN3edg9a_booleanE do_not_assign_to_nonlocal_objects = 0;
# 421
static _ZN3edg9a_booleanE check_specialization_errors = 0;
# 428
static _ZN3edg9a_booleanE suppress_dependency_checking = 0;
# 437
static int num_of_L_directories = 0;




static _ZN3edg9a_booleanE one_instantiation_per_object = 0;




static _ZN3edg9a_booleanE use_template_info_file = 1;



static _ZN3edg9a_booleanE use_definition_list = 1;



static char *temporary_file_name = ((char *)0);
# 488
static enum an_nm_format_kind nm_format = nmfk_default;



static _ZN3edg9a_booleanE ignore_invalid_nm_output = 0;
# 501
static _ZN3edg9a_booleanE skip_underscore_prefix = 0;
# 508
static _ZN3edg9a_booleanE move_nonlocal_objects_to_curr_dir = 0;




static FILE *f_obj_file_list = ((FILE *)0);
# 523
static int reserved_request_file_lines = 0;
# 531
static int pl_debug_level = 0;
# 1139
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer = ((char *)0);
# 1410
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer = ((char *)0);
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name2_buffer = ((char *)0);

static _ZN3edg9a_booleanE _ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E13name2_is_NULL = 0;
# 3275
static char *_ZZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEvE22definition_list_option = ((char *)0);
# 3770
static a_pl_cmd_line_arg_ptr cmd_line_head = ((a_pl_cmd_line_arg_ptr)0);



static a_pl_cmd_line_arg_ptr cmd_line_tail = ((a_pl_cmd_line_arg_ptr)0);  __attribute__((__weak__)) /* COMDAT group: _ZZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_Es */ char _ZZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_Es[94] = "src/util.h"
# 3774
;  __attribute__((__weak__)) /* COMDAT group: _ZZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_Es_0 */ char _ZZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_Es_0[1] = "";
# 57 "util/getopt.h"
__attribute__((__nothrow__)) int getopt( int __38669_16_argc,  char *const *__38669_37_argv,  const char *__38669_55_optstring)
# 73
{ auto int __T64005536; auto struct __C8 __T64006312;
auto int __38686_15_return_value;
auto char *__38687_16_optpos;
# 73
(__T64006312.next) = __curr_eh_stack_entry; __curr_eh_stack_entry = (&__T64006312); (__T64006312.kind) = ((unsigned char)6U);
# 83
if (_ZZ6getoptE7optchar == ((char *)0)) {
__38696_1_start_new_argument:;
if (optind >= __38669_16_argc) {

__38686_15_return_value = (-1);
goto __38774_1_end_of_routine;
} else  {
_ZZ6getoptE7optchar = (__38669_37_argv[optind]);
if (((int)(*_ZZ6getoptE7optchar)) != 45) {

__38686_15_return_value = (-1);
goto __38774_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptE7optchar + 1))) == 45) {
if (((int)(*(_ZZ6getoptE7optchar + 2))) == 0) {


optind++;
__38686_15_return_value = (-1);
} else  {

__38686_15_return_value = 63;
}
goto __38774_1_end_of_routine;
} else  { if (((int)(*(_ZZ6getoptE7optchar + 1))) == 0) {


__38686_15_return_value = (-1);
goto __38774_1_end_of_routine;
} } }

_ZZ6getoptE7optchar++;
}
}


if (((int)(*_ZZ6getoptE7optchar)) == 0) {

optind++;
goto __38696_1_start_new_argument;
}

__38687_16_optpos = (_Z6strchrPci(((char *)__38669_55_optstring), ((int)(*_ZZ6getoptE7optchar))));
if (__38687_16_optpos == ((char *)0)) {

if (opterr) { fprintf(stderr, ((const char *)"%s: illegal option -- %c\n"), (__38669_37_argv[0]), ((int)(*_ZZ6getoptE7optchar))); }

__38686_15_return_value = 63;
goto __38774_1_end_of_routine;
}

__38686_15_return_value = ((int)(*_ZZ6getoptE7optchar));

if (((int)(*(__38687_16_optpos + 1))) == 58) {
if (((int)(*(_ZZ6getoptE7optchar + 1))) == 0) {


optind++;
if (optind >= __38669_16_argc) {


if (opterr) { fprintf(stderr, ((const char *)"%s: option requires an argument -- %c\n"), (__38669_37_argv[0]), ((int)(*_ZZ6getoptE7optchar))); }

__38686_15_return_value = 63;
goto __38774_1_end_of_routine;
}
optarg = (__38669_37_argv[optind]);
} else  {


optarg = (_ZZ6getoptE7optchar + 1);
}

_ZZ6getoptE7optchar = ((char *)0);
optind++;
} else  {

_ZZ6getoptE7optchar++;
optarg = ((char *)0);
}
__38774_1_end_of_routine:; {
__T64005536 = __38686_15_return_value; { __curr_eh_stack_entry = (__T64006312.next); return __T64005536; } }
}
# 558 "util/edg_prelink.c"
static void _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc( _ZN3edg12a_const_charE *__39265_45_error_string)




{
fprintf(stderr, ((const char *)"%s: internal error: %s\n"), message_prefix, __39265_45_error_string);



fflush(stderr);
abort(); 

}



static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_( _ZN3edg12a_const_charE *__39282_47_filename, 
int __39283_18_line_number, 
_ZN3edg12a_const_charE *__39284_19_string1, 
_ZN3edg12a_const_charE *__39285_19_string2)



{
fprintf(stderr, ((const char *)"assertion failed: %s%s (%s, line %0d)\n"), __39284_19_string1, __39285_19_string2, __39282_47_filename, __39283_18_line_number);

_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"assertion failed")); 
}
# 632
static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind24pl_is_absolute_file_nameEPc( char *__47892_49_file_name)



{
# 642
return (_ZN3edg9a_booleanE)(((int)(__47892_49_file_name[0])) == 47);

}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_get_curr_dir_nameEv(void)



{

if ((getcwd(curr_dir_name, 2048UL)) == ((char *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"getcwd failed"));
} 



}
# 698
static _ZN3edg12a_const_charE *_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code( enum a_pl_error_code __47958_52_error_code)




{
auto _ZN3edg12a_const_charE *__47964_17_m = ((_ZN3edg12a_const_charE *)0);
switch ((int)__47958_52_error_code) {
case 0:
__47964_17_m = ((const char *)"%s: %s no longer needed in %s\n");
goto __T71879448;
case 1:
__47964_17_m = ((const char *)"%s: %s assigned to file %s\n");
goto __T71879448;
case 2:
__47964_17_m = ((const char *)"C++ prelinker");
goto __T71879448;
case 3:
__47964_17_m = ((const char *)"%s: executing: %s\n");
goto __T71879448;
case 4:
__47964_17_m = ((const char *)"unrecognized option: %s\n");
goto __T71879448;
case 5:
__47964_17_m = ((const char *)"%s: error: ");
goto __T71879448;
case 6:
__47964_17_m = ((const char *)"out of memory");
goto __T71879448;
case 7:
__47964_17_m = ((const char *)"invalid input format");
goto __T71879448;
case 8:
__47964_17_m = ((const char *)"bad instantiation request file -- instantiation assigned to more than one file");

goto __T71879448;
case 9:
__47964_17_m = ((const char *)"invalid nm format option");
goto __T71879448;
case 10:
__47964_17_m = ((const char *)"command line error");
goto __T71879448;
case 11:
__47964_17_m = ((const char *)"instantiation loop");
goto __T71879448;
case 12:
__47964_17_m = ((const char *)"library \"%s\" does not exist in the specified library directories\n");
goto __T71879448;
case 13:
__47964_17_m = ((const char *)"an error occurred during name decoding of \"%s\"");
goto __T71879448;
case 14:
__47964_17_m = ((const char *)"%s: warning: ");
goto __T71879448;
case 15:
__47964_17_m = ((const char *)"invalid reserved request file lines option \"%s\"");
goto __T71879448;
case 16:
__47964_17_m = ((const char *)"cannot open object file name list file \"%s\"");
goto __T71879448;
case 17:
__47964_17_m = ((const char *)"cannot create instantiation request file \"%s\"");
goto __T71879448;
case 18:
__47964_17_m = ((const char *)"cannot change to directory \"%s\"");
goto __T71879448;
case 19:
__47964_17_m = ((const char *)"no output produced by nm -- possible configuration problem");
goto __T71879448;
case 20:
__47964_17_m = ((const char *)"unable to create process for nm command");
goto __T71879448;
case 21:
__47964_17_m = ((const char *)"\"%s\" has been referenced as both an explicit specialization and a generated instantiation");

goto __T71879448;
case 22:
__47964_17_m = ((const char *)"file \"%s\" is read-only");
goto __T71879448;
case 23:
__47964_17_m = ((const char *)"nm returned a nonzero error status");
goto __T71879448;
case 24:
__47964_17_m = ((const char *)"%s assigned to %s and %s\n");
goto __T71879448;
case 25:
__47964_17_m = ((const char *)"-O and -N require a new object list file name specified with the -o option");

goto __T71879448;
case 26:
__47964_17_m = ((const char *)"invalid definition list option \"%s\"");
goto __T71879448;
case 27:
__47964_17_m = ((const char *)"cannot create temporary file \"%s\"");
goto __T71879448;
case 28:
__47964_17_m = ((const char *)"%s: %s adopted by file %s\n");
goto __T71879448;
case 29:
__47964_17_m = ((const char *)"%s: rebuilding %s because %s (used by an exported template file) has changed\n");

goto __T71879448;
case 30:
__47964_17_m = ((const char *)"corrupted template information file or instantiation request file");
goto __T71879448;
default:
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"invalid error code"));
} __T71879448:;
return __47964_17_m;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_error_with_exitE15a_pl_error_codePci( enum a_pl_error_code __48070_48_error_code, 
char *__48071_39_insertion_string, 
_ZN3edg9a_booleanE __48072_49_exit_when_done)
# 821
{
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_error)), message_prefix);
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(__48070_48_error_code)), __48071_39_insertion_string);
fprintf(stderr, ((const char *)"\n"));
if (__48072_49_exit_when_done) { exit(2); } 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc( enum a_pl_error_code __48089_38_error_code, 
char *__48090_29_insertion_string)




{

_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_error_with_exitE15a_pl_error_codePci(__48089_38_error_code, __48090_29_insertion_string, 1); 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc( enum a_pl_error_code __48101_40_error_code, 
char *__48102_31_insertion_string)
# 850
{
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_warning)), message_prefix);
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(__48101_40_error_code)), __48102_31_insertion_string);
fprintf(stderr, ((const char *)"\n")); 
}

static _ZN3edg10a_void_ptrE _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm( _ZN3edg8sizeof_tE __48116_49_size)




{
auto _ZN3edg10a_void_ptrE __48122_14_ptr;

if ((__48122_14_ptr = ((_ZN3edg10a_void_ptrE)(malloc(__48116_49_size)))) == ((_ZN3edg10a_void_ptrE)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_out_of_memory, ((char *)0));
}
return __48122_14_ptr;
}


static _ZN3edg10a_void_ptrE _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_realloc_with_checkEPvm( _ZN3edg10a_void_ptrE __48131_52_old_ptr, 
_ZN3edg8sizeof_tE __48132_50_new_size)
# 878
{
auto _ZN3edg10a_void_ptrE __48139_14_ptr;



if (__48131_52_old_ptr == ((_ZN3edg10a_void_ptrE)0)) {
__48139_14_ptr = (_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(__48132_50_new_size));
} else  {
__48139_14_ptr = ((_ZN3edg10a_void_ptrE)(realloc(((a_realloc_arg)__48131_52_old_ptr), __48132_50_new_size)));
if (__48139_14_ptr == ((_ZN3edg10a_void_ptrE)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_out_of_memory, ((char *)0));
}
}
return __48139_14_ptr;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind19reset_pl_input_fileEP15a_pl_input_file( a_pl_input_file_ptr __48155_53_pifp)




{
(__48155_53_pifp->request_list) = ((a_pl_symbol_ptr)0);
(__48155_53_pifp->objects) = ((a_pl_object_file_ptr)0);
(__48155_53_pifp->is_archive) = ((_ZN3edg14a_byte_booleanE)0U);
(__48155_53_pifp->request_file_updated) = ((_ZN3edg14a_byte_booleanE)0U);
(__48155_53_pifp->recompile) = ((_ZN3edg14a_byte_booleanE)0U);
(__48155_53_pifp->is_local_file) = ((_ZN3edg14a_byte_booleanE)1U);
(__48155_53_pifp->command_line) = ((char *)0);
(__48155_53_pifp->compilation_directory) = ((char *)0);
(__48155_53_pifp->compilation_file_name) = ((char *)0);
(__48155_53_pifp->secondary_files) = ((char *)0);
(__48155_53_pifp->dependencies) = ((a_pl_file_list_entry_ptr)0);
(__48155_53_pifp->instantiation_directory) = ((char *)0); 
}


static a_pl_input_file_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_input_fileEv(void)



{
auto a_pl_input_file_ptr __48181_24_pifp;

__48181_24_pifp = ((a_pl_input_file_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(120UL)));
(__48181_24_pifp->next) = ((a_pl_input_file_ptr)0);
(__48181_24_pifp->file_name) = ((char *)0);
(__48181_24_pifp->request_file_name) = ((char *)0);
(__48181_24_pifp->template_info_file_name) = ((char *)0);
_ZN33_INTERNAL_13_edg_prelink_c_optind19reset_pl_input_fileEP15a_pl_input_file(__48181_24_pifp);
return __48181_24_pifp;
}


static a_pl_object_file_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv(void)



{
auto a_pl_object_file_ptr __48198_25_pofp;

if (avail_pl_object_files != ((a_pl_object_file_ptr)0)) {
__48198_25_pofp = avail_pl_object_files;
avail_pl_object_files = (__48198_25_pofp->next);
} else  {
__48198_25_pofp = ((a_pl_object_file_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(40UL)));

}
(__48198_25_pofp->next) = ((a_pl_object_file_ptr)0);
(__48198_25_pofp->file_name) = ((char *)0);
(__48198_25_pofp->symbols) = ((a_pl_symbol_ptr)0);
(__48198_25_pofp->included_in_output) = ((_ZN3edg14a_byte_booleanE)0U);
(__48198_25_pofp->is_related_file) = ((_ZN3edg14a_byte_booleanE)0U);
(__48198_25_pofp->modification_time) = 0L;
return __48198_25_pofp;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind19free_pl_object_fileEP16a_pl_object_file( a_pl_object_file_ptr __48217_54_pofp)



{
(__48217_54_pofp->next) = avail_pl_object_files;
avail_pl_object_files = __48217_54_pofp; 
}


static a_pl_assignment_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_assignmentEv(void)



{
auto a_pl_assignment_ptr __48232_23_ap;

__48232_23_ap = ((a_pl_assignment_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(24UL)));
(__48232_23_ap->next) = ((a_pl_assignment_ptr)0);
(__48232_23_ap->name) = ((char *)0);
(__48232_23_ap->times_assigned) = 0;
return __48232_23_ap;
}


static a_pl_file_list_entry_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind24alloc_pl_file_list_entryEv(void)



{
auto a_pl_file_list_entry_ptr __48247_28_flep;

__48247_28_flep = ((a_pl_file_list_entry_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(16UL)));

(__48247_28_flep->next) = ((a_pl_file_list_entry_ptr)0);
(__48247_28_flep->name) = ((char *)0);
return __48247_28_flep;
}


static a_pl_symbol_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv(void)



{
auto a_pl_symbol_ptr __48262_20_psp;

if (avail_pl_symbols != ((a_pl_symbol_ptr)0)) {
__48262_20_psp = avail_pl_symbols;
avail_pl_symbols = (__48262_20_psp->next);
} else  {
__48262_20_psp = ((a_pl_symbol_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(104UL)));
}
(__48262_20_psp->name) = ((char *)0);
(__48262_20_psp->next) = ((a_pl_symbol_ptr)0);
(__48262_20_psp->next_in_symbol_table) = ((a_pl_symbol_ptr)0);
(__48262_20_psp->next_in_request_file) = ((a_pl_symbol_ptr)0);
(__48262_20_psp->next_in_specialization_list) = ((a_pl_symbol_ptr)0);
(__48262_20_psp->global_sym) = ((a_pl_symbol_ptr)0);
(__48262_20_psp->template_sym) = ((a_pl_symbol_ptr)0);
(__48262_20_psp->primary_entry) = ((a_pl_symbol_ptr)0);
(__48262_20_psp->instantiation_file) = ((a_pl_input_file_ptr)0);
(__48262_20_psp->possible_instantiation_sites) = ((a_pl_instantiation_site_ptr)0);
(__48262_20_psp->referenced) = ((_ZN3edg14a_byte_booleanE)0U);
(__48262_20_psp->defined) = ((_ZN3edg14a_byte_booleanE)0U);
(__48262_20_psp->definition_seen_in_archive) = ((_ZN3edg14a_byte_booleanE)0U);
(__48262_20_psp->tentative_definition) = ((_ZN3edg14a_byte_booleanE)0U);
(__48262_20_psp->multiple_definition) = ((_ZN3edg14a_byte_booleanE)0U);
(__48262_20_psp->is_template) = ((_ZN3edg14a_byte_booleanE)0U);
(__48262_20_psp->can_be_instantiated) = ((_ZN3edg14a_byte_booleanE)0U);
(__48262_20_psp->do_not_instantiate) = ((_ZN3edg14a_byte_booleanE)0U);
(__48262_20_psp->instantiated) = ((_ZN3edg14a_byte_booleanE)0U);
(__48262_20_psp->defined_in) = ((a_pl_input_file_ptr)0);
return __48262_20_psp;
}


static a_pl_instantiation_site_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind27alloc_pl_instantiation_siteEv(void)



{
auto a_pl_instantiation_site_ptr __48299_32_pisp;

if (avail_pl_instantiation_sites != ((a_pl_instantiation_site_ptr)0)) {
__48299_32_pisp = avail_pl_instantiation_sites;
avail_pl_instantiation_sites = (__48299_32_pisp->next);
} else  {
__48299_32_pisp = ((a_pl_instantiation_site_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(16UL)));

}
(__48299_32_pisp->next) = ((a_pl_instantiation_site_ptr)0);
(__48299_32_pisp->input_file) = ((a_pl_input_file_ptr)0);
return __48299_32_pisp;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind26free_pl_instantiation_siteEP23a_pl_instantiation_site( a_pl_instantiation_site_ptr __48314_68_pisp)



{
(__48314_68_pisp->next) = avail_pl_instantiation_sites;
avail_pl_instantiation_sites = __48314_68_pisp; 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind14free_pl_symbolEP11a_pl_symbol( a_pl_symbol_ptr __48324_44_psp)



{
(__48324_44_psp->next) = avail_pl_symbols;
avail_pl_symbols = __48324_44_psp; 
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE( FILE *__48334_43_f_input)
# 1080
{
auto char *__48341_14_buffer_pos = pl_input_line;
auto int __48342_14_size = 0;
auto int __48343_14_ch;
auto _ZN3edg9a_booleanE __48344_14_result;

while ((__48343_14_ch = (getc(__48334_43_f_input))) , ((__48343_14_ch != (-1)) && (__48343_14_ch != 10))) {
if ((++__48342_14_size) > 32767) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"pl_read_input_line: input line too long."));
}
(*(__48341_14_buffer_pos++)) = ((char)__48343_14_ch);
}


(*(__48341_14_buffer_pos++)) = ((char)0);


__48344_14_result = 1;
if ((__48343_14_ch == (-1)) && (__48342_14_size == 0)) { __48344_14_result = 0; }

return __48344_14_result;
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc( _ZN3edg12a_const_charE *__48364_43_source)




{
auto char *__48370_9_dest;
__48370_9_dest = ((char *)(malloc(((strlen(__48364_43_source)) + 1UL))));
strcpy(__48370_9_dest, __48364_43_source);
return __48370_9_dest;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind29pl_is_explicit_specializationEPc( char *__48377_55_name)



{
auto char *__48382_10_ptr;

__48382_10_ptr = (_Z6strstrPcPKc(__48377_55_name, ((const char *)"__S")));
return (_ZN3edg9a_booleanE)(__48382_10_ptr != ((char *)0));
}
# 1132
static char *_ZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPc( char *__48392_44_name)
# 1138
{

auto char *__48400_10_from;
auto char *__48401_10_to;

if (_ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer == ((char *)0)) {


_ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(32767UL)));
}

__48400_10_from = __48392_44_name;
__48401_10_to = _ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer;
while (((int)(*__48400_10_from)) != 0) {
if (((((int)(*__48400_10_from)) == 95) && (((int)(__48400_10_from[1])) == 95)) && (((int)(__48400_10_from[2])) == 83)) {
__48400_10_from += 3;
goto __T72116464;
}
(*(__48401_10_to++)) = (*(__48400_10_from++)); __T72116464:;
}

(*__48401_10_to) = ((char)0);
return _ZZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPcE11name_buffer;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(void)



{
if (!(ignore_invalid_nm_output)) { _ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_invalid_input, ((char *)0)); } 
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc( char *__48433_36_encoded_name)



{
auto _ZN3edg9a_booleanE __48438_13_error;
auto _ZN3edg9a_booleanE __48439_13_buffer_overflow;
auto char *__48440_10_result;

auto _ZN3edg8sizeof_tE __48442_12_required_buffer_size;

if (mangled_names_in_output) {

__48440_10_result = __48433_36_encoded_name;
# 1194
} else  {
_Z17decode_identifierPKcPcmPiS2_Pm(((_ZN3edg12a_const_charE *)__48433_36_encoded_name), _ZZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPcE13decode_buffer, 32767UL, (&__48438_13_error), (&__48439_13_buffer_overflow), (&__48442_12_required_buffer_size));

__48440_10_result = _ZZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPcE13decode_buffer;
if (__48438_13_error) {


_ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc(pl_ec_error_occurred_during_name_decoding, __48433_36_encoded_name);
__48440_10_result = __48433_36_encoded_name;
}
}
return __48440_10_result;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_solaris_nm_lineEPPcS1_S0_S1_( char **__48469_49_name1, 
char **__48470_21_name2, 
char *__48471_20_type, 
char **__48472_21_symbol_name)
# 1257
{
auto _ZN3edg9a_booleanE __48518_13_result = 1;
auto char *__48519_10_pos;
auto char *__48520_10_rest_of_line;
auto char __48521_9_ch;


(*__48469_49_name1) = ((*__48470_21_name2) = ((*__48472_21_symbol_name) = ((char *)0)));
(*__48471_20_type) = ((char)0);


__48519_10_pos = (_Z6strchrPci(pl_input_line, 58));
if (__48519_10_pos == ((char *)0)) {


if (((int)((pl_input_line)[0])) != 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__48518_13_result = 0;
} else  { if (((int)(*(__48519_10_pos + 1))) == 0) {


__48518_13_result = 0;
} else  {


__48519_10_pos = pl_input_line;
while ((__48521_9_ch = (*__48519_10_pos)) , ((((int)__48521_9_ch) != 32) && (((int)__48521_9_ch) != 0))) { __48519_10_pos++; }

if (((int)(*(__48519_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__48519_10_pos)) == 32) { __48519_10_pos++; }

(*__48471_20_type) = (*(__48519_10_pos++));
if (!(isalpha(((int)((unsigned char)(*__48471_20_type)))))) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

if (((int)(*(__48519_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__48519_10_pos)) == 32) { __48519_10_pos++; }


__48520_10_rest_of_line = __48519_10_pos;
__48519_10_pos = (_Z6strchrPci(__48520_10_rest_of_line, 58));

(*__48519_10_pos) = ((char)0);
(*__48469_49_name1) = __48520_10_rest_of_line;
__48520_10_rest_of_line = (__48519_10_pos + 1);
__48519_10_pos = (_Z6strchrPci(__48520_10_rest_of_line, 58));
if (__48519_10_pos == ((char *)0)) {

(*__48470_21_name2) = ((char *)0);
} else  {


(*__48519_10_pos) = ((char)0);
(*__48470_21_name2) = __48520_10_rest_of_line;
__48520_10_rest_of_line = (__48519_10_pos + 1);
}
(*__48472_21_symbol_name) = __48520_10_rest_of_line;
} }
return __48518_13_result;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_( char **__48579_51_name1, 
char **__48580_18_name2, 
char *__48581_17_type, 
char **__48582_18_symbol_name)
# 1405
{
auto _ZN3edg9a_booleanE __48666_13_result = 1;
auto char *__48667_10_pos;
auto char *__48668_10_rest_of_line;
auto char __48669_9_ch;
# 1417
if (_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer == ((char *)0)) {
_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(32767UL)));
_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name2_buffer = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(32767UL)));
}

(*__48579_51_name1) = ((*__48580_18_name2) = ((*__48582_18_symbol_name) = ((char *)0)));
(*__48581_17_type) = ((char)0);


__48667_10_pos = (_Z6strchrPci(pl_input_line, 58));
if (__48667_10_pos == ((char *)0)) {


if (((int)((pl_input_line)[0])) != 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__48666_13_result = 0;
} else  { if ((_Z6strchrPci(pl_input_line, 32)) == ((char *)0)) {
auto char *__48693_11_bracket_pos;



__48666_13_result = 0;


__48693_11_bracket_pos = (_Z6strchrPci(pl_input_line, 91));
if (__48693_11_bracket_pos != ((char *)0)) { __48667_10_pos = __48693_11_bracket_pos; }

(*__48667_10_pos) = ((char)0);
strcpy(_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer, ((const char *)pl_input_line));
__48668_10_rest_of_line = (__48667_10_pos + 1);
_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E13name2_is_NULL = ((_ZN3edg9a_booleanE)(__48693_11_bracket_pos == ((char *)0)));
if (!(_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E13name2_is_NULL)) {

__48667_10_pos = (_Z6strchrPci(__48668_10_rest_of_line, 93));
(*__48667_10_pos) = ((char)0);
strcpy(_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name2_buffer, ((const char *)__48668_10_rest_of_line));
}
} else  {

(*__48579_51_name1) = _ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name1_buffer;
(*__48580_18_name2) = ((_ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E13name2_is_NULL) ? ((char *)0) : _ZZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_E12name2_buffer);


if ((((int)nm_format) == 4) || (((int)nm_format) == 5)) {
__48668_10_rest_of_line = (__48667_10_pos + 1);
} else  {
__48668_10_rest_of_line = pl_input_line;
}


__48667_10_pos = __48668_10_rest_of_line;
while (((int)(*__48667_10_pos)) == 32) { __48667_10_pos++; }


while ((__48669_9_ch = (*__48667_10_pos)) , ((((int)__48669_9_ch) != 32) && (((int)__48669_9_ch) != 0))) { __48667_10_pos++; }

if (((int)(*(__48667_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__48667_10_pos)) == 32) { __48667_10_pos++; }

(*__48581_17_type) = (*(__48667_10_pos++));
if (!(isalpha(((int)((unsigned char)(*__48581_17_type)))))) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
if (((int)nm_format) == 4) {

switch ((int)(*__48581_17_type)) {
case 99: (*__48581_17_type) = ((char)67); goto __T72277104;
} __T72277104:;
}

if (((int)nm_format) == 4) { while ((((int)(*__48667_10_pos)) != 32) && (((int)(*__48667_10_pos)) != 0)) { __48667_10_pos++; } }

if (((int)(*(__48667_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__48667_10_pos)) == 32) { __48667_10_pos++; }
if (((int)nm_format) == 5) {


if ((skip_underscore_prefix) && (((int)(*__48667_10_pos)) == 95)) { __48667_10_pos++; }
}
__48668_10_rest_of_line = __48667_10_pos;


if ((((int)nm_format) != 4) && (((int)nm_format) != 5)) {
__48667_10_pos = (_Z6strchrPci(__48668_10_rest_of_line, 58));
__48668_10_rest_of_line = (__48667_10_pos + 1);
}
(*__48582_18_symbol_name) = __48668_10_rest_of_line;
} }
return __48666_13_result;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_default_nm_lineEPPcS1_S0_S1_( char **__48768_49_name1, 
char **__48769_14_name2, 
char *__48770_13_type, 
char **__48771_14_symbol_name)
# 1612
{
auto _ZN3edg9a_booleanE __48873_13_result = 1;
auto char *__48874_10_pos;
auto char *__48875_10_rest_of_line;
auto char __48876_9_ch;


(*__48768_49_name1) = ((*__48769_14_name2) = ((*__48771_14_symbol_name) = ((char *)0)));
(*__48770_13_type) = ((char)0);
__48874_10_pos = pl_input_line;
# 1628
__48874_10_pos = (_Z6strchrPci(__48874_10_pos, 58));
if (__48874_10_pos == ((char *)0)) {


if (((int)((pl_input_line)[0])) != 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__48873_13_result = 0;
} else  { if (((int)(*(__48874_10_pos + 1))) == 0) {


__48873_13_result = 0;
} else  {
if (((int)nm_format) == 6) {
auto char *__48900_13_paren_pos;


(*__48874_10_pos) = ((char)0);
__48875_10_rest_of_line = (__48874_10_pos + 1);
__48900_13_paren_pos = (_Z6strchrPci(pl_input_line, 40));
if (__48900_13_paren_pos == ((char *)0)) {

(*__48768_49_name1) = pl_input_line;
(*__48769_14_name2) = ((char *)0);
} else  {
auto char *__48911_15_end_of_name2;

(*__48768_49_name1) = pl_input_line;

(*__48900_13_paren_pos) = ((char)0);

(*__48769_14_name2) = (__48900_13_paren_pos + 1);
__48911_15_end_of_name2 = (_Z6strchrPci((*__48769_14_name2), 41));

(*__48911_15_end_of_name2) = ((char)0);
}
} else  {


(*__48874_10_pos) = ((char)0);
(*__48768_49_name1) = pl_input_line;
__48875_10_rest_of_line = (__48874_10_pos + 1);
__48874_10_pos = (_Z6strchrPci(__48875_10_rest_of_line, 58));
if (__48874_10_pos == ((char *)0)) {

(*__48769_14_name2) = ((char *)0);
} else  {


(*__48874_10_pos) = ((char)0);
(*__48769_14_name2) = __48875_10_rest_of_line;
__48875_10_rest_of_line = (__48874_10_pos + 1);
}
}
__48874_10_pos = __48875_10_rest_of_line;
if (((int)nm_format) == 2) {


while (((int)(*__48874_10_pos)) == 32) { __48874_10_pos++; }
}
if (((int)nm_format) == 7) {


auto int __48949_11_i;
for (__48949_11_i = 0; __48949_11_i < 9; ++__48949_11_i) {
if (((int)(*__48874_10_pos)) == 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__48874_10_pos++;
}
} else  { if (((int)nm_format) == 8) {


auto int __48957_11_i;
for (__48957_11_i = 0; __48957_11_i < 17; ++__48957_11_i) {
if (((int)(*__48874_10_pos)) == 0) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }
__48874_10_pos++;
}
} else  {


while ((__48876_9_ch = (*__48874_10_pos)) , ((((int)__48876_9_ch) != 32) && (((int)__48876_9_ch) != 0))) { __48874_10_pos++; }
} }

if (((int)(*(__48874_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

while (((int)(*__48874_10_pos)) == 32) { __48874_10_pos++; }

(*__48770_13_type) = (*(__48874_10_pos++));
if (!(isalpha(((int)((unsigned char)(*__48770_13_type)))))) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }

if (((int)(*(__48874_10_pos++))) != 32) { _ZN33_INTERNAL_13_edg_prelink_c_optind16pl_invalid_inputEv(); }


if ((skip_underscore_prefix) && (((int)(*__48874_10_pos)) == 95)) { __48874_10_pos++; }
(*__48771_14_symbol_name) = __48874_10_pos;
if (((int)nm_format) == 2) {




while ((__48876_9_ch = (*__48874_10_pos)) , ((((int)__48876_9_ch) != 32) && (((int)__48876_9_ch) != 0))) { __48874_10_pos++; }
if (((int)__48876_9_ch) == 32) { (*__48874_10_pos) = ((char)0); }
}
} }
return __48873_13_result;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_read_nm_outputEv(void)
# 1744
{
auto char *__49005_11_input_file_name = ((char *)0);
auto char *__49006_11_obj_file_name = ((char *)0);
auto _ZN3edg9a_booleanE __49007_14_is_archive = 0;
auto a_pl_object_file_ptr __49008_24_objects_tail = ((a_pl_object_file_ptr)0);
auto a_pl_object_file_ptr __49009_24_pofp = ((a_pl_object_file_ptr)0);
auto a_pl_input_file_ptr __49010_23_pifp = ((a_pl_input_file_ptr)0);
auto _ZN3edg9a_booleanE __49011_14_any_lines_read = 0;

while (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(f_command_output)) { {
auto char *__49014_12_name1;
auto char *__49015_12_name2;
auto char __49016_11_type;
auto char *__49017_12_symbol_name;
auto a_pl_symbol_ptr __49018_21_psp;
auto _ZN3edg9a_booleanE __49019_16_process_line;

if (pl_debug_level >= 4) {
fprintf(stderr, ((const char *)"%s\n"), (pl_input_line));
}

__49011_14_any_lines_read = 1;

if (((int)nm_format) == 1) {
__49019_16_process_line = (_ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_solaris_nm_lineEPPcS1_S0_S1_((&__49014_12_name1), (&__49015_12_name2), (&__49016_11_type), (&__49017_12_symbol_name)));

} else  { if (((((int)nm_format) == 3) || (((int)nm_format) == 4)) || (((int)nm_format) == 5))

{
__49019_16_process_line = (_ZN33_INTERNAL_13_edg_prelink_c_optind25pl_scan_alternate_nm_lineEPPcS1_S0_S1_((&__49014_12_name1), (&__49015_12_name2), (&__49016_11_type), (&__49017_12_symbol_name)));

} else  {

__49019_16_process_line = (_ZN33_INTERNAL_13_edg_prelink_c_optind23pl_scan_default_nm_lineEPPcS1_S0_S1_((&__49014_12_name1), (&__49015_12_name2), (&__49016_11_type), (&__49017_12_symbol_name)));

} }

if (pl_debug_level >= 5) {
fprintf(stderr, ((const char *)"nm info: name1: %s, name2: %s, type: %c, sym: %s\n"), ((__49014_12_name1 == ((char *)0)) ? ((const char *)"<NULL>") : ((const char *)__49014_12_name1)), ((__49015_12_name2 == ((char *)0)) ? ((const char *)"<NULL>") : ((const char *)__49015_12_name2)), ((int)
# 1782
__49016_11_type), ((__49017_12_symbol_name == ((char *)0)) ? ((const char *)"<NULL>") : ((const char *)__49017_12_symbol_name)));




}



if (!(__49019_16_process_line)) { goto __T72385504; }

if ((__49005_11_input_file_name == ((char *)0)) || ((strcmp(((const char *)__49005_11_input_file_name), ((const char *)__49014_12_name1))) != 0))
{



__49007_14_is_archive = ((_ZN3edg9a_booleanE)(__49015_12_name2 != ((char *)0)));
for (__49010_23_pifp = pl_input_files; __49010_23_pifp != ((a_pl_input_file_ptr)0); __49010_23_pifp = (__49010_23_pifp->next)) {
# 1806
if ((__49007_14_is_archive) && ((strcmp(((const char *)(__49010_23_pifp->file_name)), ((const char *)__49014_12_name1))) != 0)) { goto __T72391976; }


if (__49010_23_pifp->is_archive) { goto __T72391976; }


for (__49009_24_pofp = (__49010_23_pifp->objects); __49009_24_pofp != ((a_pl_object_file_ptr)0); __49009_24_pofp = (__49009_24_pofp->next)) {
if ((strcmp(((const char *)(__49009_24_pofp->file_name)), ((const char *)__49014_12_name1))) == 0) { goto __T72396128; }
} __T72396128:;
if (__49009_24_pofp != ((a_pl_object_file_ptr)0)) { goto __T72397320; }



if ((strcmp(((const char *)(__49010_23_pifp->file_name)), ((const char *)__49014_12_name1))) == 0) { goto __T72397320; } __T72391976:;
} __T72397320:;
if (__49010_23_pifp == ((a_pl_input_file_ptr)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"Input file not in list"));
}
__49005_11_input_file_name = (__49010_23_pifp->file_name);
(__49010_23_pifp->is_archive) = ((_ZN3edg14a_byte_booleanE)__49007_14_is_archive);
__49008_24_objects_tail = ((a_pl_object_file_ptr)0);
if (__49007_14_is_archive) {
__49006_11_obj_file_name = ((char *)0);
} else  {
if (__49009_24_pofp == ((a_pl_object_file_ptr)0)) {



__49009_24_pofp = (_ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv());
(__49009_24_pofp->next) = (__49010_23_pifp->objects);
(__49010_23_pifp->objects) = __49009_24_pofp;
(__49009_24_pofp->file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__49005_11_input_file_name)));
}
}
}

if (__49007_14_is_archive) {
if ((__49006_11_obj_file_name == ((char *)0)) || ((strcmp(((const char *)__49006_11_obj_file_name), ((const char *)__49015_12_name2))) != 0))
{

__49006_11_obj_file_name = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__49015_12_name2)));
__49009_24_pofp = (_ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv());
(__49009_24_pofp->file_name) = __49006_11_obj_file_name;


if ((__49010_23_pifp->objects) == ((a_pl_object_file_ptr)0)) { (__49010_23_pifp->objects) = __49009_24_pofp; }
if (__49008_24_objects_tail != ((a_pl_object_file_ptr)0)) { (__49008_24_objects_tail->next) = __49009_24_pofp; }
__49008_24_objects_tail = __49009_24_pofp;
}
}


if ((((((((((((int)__49016_11_type) != 66) && (((int)__49016_11_type) != 68)) && (((int)__49016_11_type) != 76)) && (((int)__49016_11_type) != 82)) && (((int)__49016_11_type) != 83)) && (((int)__49016_11_type) != 84)) && (((int)__49016_11_type) != 85)) && (((int)__49016_11_type) != 86)) && (((int)
# 1858
__49016_11_type) != 87)) && (((int)__49016_11_type) != 67))
# 1867
{


} else  {
__49018_21_psp = (_ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv());
(__49018_21_psp->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__49017_12_symbol_name)));

switch ((int)__49016_11_type) {
case 66:
case 68:
case 76:
case 82:
case 83:
case 84:
case 86:
case 87:
(__49018_21_psp->defined) = ((_ZN3edg14a_byte_booleanE)1U);
goto __T72434152;
case 85:
(__49018_21_psp->referenced) = ((_ZN3edg14a_byte_booleanE)1U);
goto __T72434152;
case 67:
(__49018_21_psp->tentative_definition) = ((_ZN3edg14a_byte_booleanE)1U);
goto __T72434152;
default:
goto __T72434152;
} __T72434152:;

(__49018_21_psp->next) = (__49009_24_pofp->symbols);
(__49009_24_pofp->symbols) = __49018_21_psp;
}
} __T72385504:; }
if (!(__49011_14_any_lines_read)) {


_ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc(pl_ec_no_nm_info, ((char *)0));
}
return;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind31add_possible_instantiation_siteEP11a_pl_symbolP15a_pl_input_file( a_pl_symbol_ptr __49168_61_psp, 
a_pl_input_file_ptr __49169_30_pifp)



{
auto a_pl_instantiation_site_ptr __49174_31_pisp;
# 1920
if (((__49168_61_psp->possible_instantiation_sites) == ((a_pl_instantiation_site_ptr)0)) || (((__49168_61_psp->possible_instantiation_sites)->input_file) != __49169_30_pifp))
{
__49174_31_pisp = (_ZN33_INTERNAL_13_edg_prelink_c_optind27alloc_pl_instantiation_siteEv());
(__49174_31_pisp->input_file) = __49169_30_pifp;
(__49174_31_pisp->next) = (__49168_61_psp->possible_instantiation_sites);
(__49168_61_psp->possible_instantiation_sites) = __49174_31_pisp;
} 
}


static unsigned _ZN33_INTERNAL_13_edg_prelink_c_optind19hash_value_for_nameEPc( char *__49190_47_name)



{
auto unsigned __49195_16_hash_value = 0U;
auto char *__49196_10_ptr;
auto int __49197_8_length;




__49197_8_length = ((int)((unsigned)(strlen(((const char *)__49190_47_name)))));
__49196_10_ptr = __49190_47_name;
if (__49197_8_length > 9) {
__49195_16_hash_value = ((unsigned)(*(__49196_10_ptr++)));
__49195_16_hash_value = ((__49195_16_hash_value * 73U) + ((unsigned)(*(__49196_10_ptr++))));
__49195_16_hash_value = ((__49195_16_hash_value * 73U) + ((unsigned)(*__49196_10_ptr)));
__49196_10_ptr = ((__49190_47_name + (__49197_8_length >> 1)) - 1);
__49195_16_hash_value = ((__49195_16_hash_value * 73U) + ((unsigned)(*(__49196_10_ptr++))));
__49195_16_hash_value = ((__49195_16_hash_value * 73U) + ((unsigned)(*(__49196_10_ptr++))));
__49195_16_hash_value = ((__49195_16_hash_value * 73U) + ((unsigned)(*__49196_10_ptr)));
__49196_10_ptr = ((__49190_47_name + __49197_8_length) - 3);
__49195_16_hash_value = ((__49195_16_hash_value * 73U) + ((unsigned)(*(__49196_10_ptr++))));
__49195_16_hash_value = ((__49195_16_hash_value * 73U) + ((unsigned)(*(__49196_10_ptr++))));
__49195_16_hash_value = ((__49195_16_hash_value * 73U) + ((unsigned)(*__49196_10_ptr)));
} else  {
auto int __49217_9_a;
for (__49217_9_a = 0; __49217_9_a < __49197_8_length; __49217_9_a++) {
__49195_16_hash_value = ((__49195_16_hash_value * 73U) + ((unsigned)(*(__49196_10_ptr++))));
}
}
return __49195_16_hash_value;
}


static a_pl_assignment_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_find_assignmentEPc( char *__49226_53_name)




{
auto unsigned __49232_17_hash_value;
auto a_pl_assignment_ptr __49233_23_ap;
auto int __49234_9_bucket_number;

__49232_17_hash_value = (_ZN33_INTERNAL_13_edg_prelink_c_optind19hash_value_for_nameEPc(__49226_53_name));
__49234_9_bucket_number = ((int)(__49232_17_hash_value % 599U));

for (__49233_23_ap = ((pl_assignment_table)[__49234_9_bucket_number]); __49233_23_ap != ((a_pl_assignment_ptr)0); __49233_23_ap = (__49233_23_ap->next)) {
if ((strcmp(((const char *)(__49233_23_ap->name)), ((const char *)__49226_53_name))) == 0) {
goto __T72480512;
}
} __T72480512:;
if (__49233_23_ap == ((a_pl_assignment_ptr)0)) {

__49233_23_ap = (_ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_assignmentEv());
(__49233_23_ap->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__49226_53_name)));

(__49233_23_ap->next) = ((pl_assignment_table)[__49234_9_bucket_number]);
((pl_assignment_table)[__49234_9_bucket_number]) = __49233_23_ap;
}
return __49233_23_ap;
}


static a_pl_symbol_ptr _ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi( char *__49256_46_name, 
a_pl_symbol_ptr __49257_55_other_sym, 
_ZN3edg9a_booleanE __49258_22_add, 
_ZN3edg9a_booleanE *__49259_23_p_new)
# 2006
{
auto unsigned __49267_24_hash_value;
auto a_pl_symbol_ptr __49268_26_prev_sym_ptr;
auto a_pl_symbol_ptr __49269_32_sym_ptr = ((a_pl_symbol_ptr)0);
auto int __49270_32_bucket_number;
auto _ZN3edg9a_booleanE __49271_21_is_new = 0;




if ((__49257_55_other_sym != ((a_pl_symbol_ptr)0)) && ((__49257_55_other_sym->global_sym) != ((a_pl_symbol_ptr)0))) {
__49269_32_sym_ptr = (__49257_55_other_sym->global_sym);
goto __49330_1_symbol_found;
}
__49267_24_hash_value = (_ZN33_INTERNAL_13_edg_prelink_c_optind19hash_value_for_nameEPc(__49256_46_name));


__49270_32_bucket_number = ((int)(__49267_24_hash_value % 10007U));
if ((__49269_32_sym_ptr = ((pl_symbol_table)[__49270_32_bucket_number])) != ((a_pl_symbol_ptr)0)) {
__49268_26_prev_sym_ptr = ((a_pl_symbol_ptr)0);
do {
if ((strcmp(((const char *)__49256_46_name), ((const char *)(__49269_32_sym_ptr->name)))) == 0) {



if (__49268_26_prev_sym_ptr != ((a_pl_symbol_ptr)0)) {
(__49268_26_prev_sym_ptr->next) = (__49269_32_sym_ptr->next);
(__49269_32_sym_ptr->next) = ((pl_symbol_table)[__49270_32_bucket_number]);
((pl_symbol_table)[__49270_32_bucket_number]) = __49269_32_sym_ptr;
}
goto __49330_1_symbol_found;
}
__49268_26_prev_sym_ptr = __49269_32_sym_ptr;
} while ((__49269_32_sym_ptr = (__49269_32_sym_ptr->next)) != ((a_pl_symbol_ptr)0));
}



if (__49258_22_add) {
__49269_32_sym_ptr = (_ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv());

(__49269_32_sym_ptr->next_in_symbol_table) = pl_symbol_table_head;
pl_symbol_table_head = __49269_32_sym_ptr;



(__49269_32_sym_ptr->next) = ((pl_symbol_table)[__49270_32_bucket_number]);
((pl_symbol_table)[__49270_32_bucket_number]) = __49269_32_sym_ptr;
(__49269_32_sym_ptr->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__49256_46_name)));
if (_ZN33_INTERNAL_13_edg_prelink_c_optind29pl_is_explicit_specializationEPc((__49269_32_sym_ptr->name))) {


(__49269_32_sym_ptr->is_specialization) = ((_ZN3edg14a_byte_booleanE)1U);
(__49269_32_sym_ptr->next_in_specialization_list) = specialization_list;
specialization_list = __49269_32_sym_ptr;
}

if (pl_debug_level >= 5) {
fprintf(stderr, ((const char *)"Adding %s to bucket %d\n"), __49256_46_name, __49270_32_bucket_number);
}

__49271_21_is_new = 1;
}

__49330_1_symbol_found:;


if ((__49269_32_sym_ptr != ((a_pl_symbol_ptr)0)) && ((__49269_32_sym_ptr->primary_entry) != ((a_pl_symbol_ptr)0))) {
__49269_32_sym_ptr = (__49269_32_sym_ptr->primary_entry);
}
if (__49269_32_sym_ptr != ((a_pl_symbol_ptr)0)) {
if ((__49257_55_other_sym != ((a_pl_symbol_ptr)0)) && ((__49257_55_other_sym->global_sym) == ((a_pl_symbol_ptr)0))) {


(__49257_55_other_sym->global_sym) = __49269_32_sym_ptr;
}
}


if (__49259_23_p_new != ((_ZN3edg9a_booleanE *)0)) { (*__49259_23_p_new) = __49271_21_is_new; }
return __49269_32_sym_ptr;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_add_predefined_namesEv(void)
# 2097
{
auto char *__49358_11_name;
auto int __49359_9_pos = 0;
auto a_pl_symbol_ptr __49360_19_sym;

for (; ; ) {
__49358_11_name = ((pl_predefined_names)[(__49359_9_pos++)]);
if (__49358_11_name == ((char *)0)) { goto __T72523288; }
__49360_19_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi(__49358_11_name, ((a_pl_symbol_ptr)0), 1, ((_ZN3edg9a_booleanE *)0)));

(__49360_19_sym->defined) = ((_ZN3edg14a_byte_booleanE)1U);
} __T72523288:; 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_add_symbols_from_objectEP16a_pl_object_fileP15a_pl_input_file( a_pl_object_file_ptr __49372_61_pofp, 
a_pl_input_file_ptr __49373_33_input_file)
# 2123
{
auto a_pl_symbol_ptr __49384_19_psp;

__49384_19_psp = (__49372_61_pofp->symbols);
while (__49384_19_psp != ((a_pl_symbol_ptr)0)) {
auto a_pl_symbol_ptr __49388_21_sym;
auto _ZN3edg9a_booleanE __49389_16_is_special_symbol = 0;
if ((((int)((__49384_19_psp->name)[0])) == 95) && (((int)((__49384_19_psp->name)[1])) == 95)) {
if ((strncmp(((const char *)(__49384_19_psp->name)), ((const char *)"__TIR__"), 7UL)) == 0)
{
# 2141
__49389_16_is_special_symbol = 1;
__49388_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi(((__49384_19_psp->name) + 7), __49384_19_psp, 1, ((_ZN3edg9a_booleanE *)0)));

(__49388_21_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1U);
(__49388_21_sym->referenced) = ((_ZN3edg14a_byte_booleanE)1U);
} else  { if ((strncmp(((const char *)(__49384_19_psp->name)), ((const char *)"__DNI__"), 7UL)) == 0)
{
# 2155
__49389_16_is_special_symbol = 1;
__49388_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi(((__49384_19_psp->name) + 7), __49384_19_psp, 1, ((_ZN3edg9a_booleanE *)0)));

(__49388_21_sym->do_not_instantiate) = ((_ZN3edg14a_byte_booleanE)1U);
} else  { if ((!(__49373_33_input_file->is_archive)) && ((strncmp(((const char *)(__49384_19_psp->name)), ((const char *)"__CBI__"), 7UL)) == 0))

{




__49389_16_is_special_symbol = 1;
__49388_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi(((__49384_19_psp->name) + 7), __49384_19_psp, 1, ((_ZN3edg9a_booleanE *)0)));

(__49388_21_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1U);
if (!(__49373_33_input_file->is_archive)) {
(__49388_21_sym->can_be_instantiated) = ((_ZN3edg14a_byte_booleanE)1U);


_ZN33_INTERNAL_13_edg_prelink_c_optind31add_possible_instantiation_siteEP11a_pl_symbolP15a_pl_input_file(__49388_21_sym, __49373_33_input_file);
}
} } }
}
if (!(__49389_16_is_special_symbol)) {


__49388_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi((__49384_19_psp->name), __49384_19_psp, 1, ((_ZN3edg9a_booleanE *)0)));
if (__49384_19_psp->referenced) {
(__49388_21_sym->referenced) = ((_ZN3edg14a_byte_booleanE)1U);
}




if (__49384_19_psp->defined) {
if ((__49388_21_sym->defined) && ((__49388_21_sym->defined_in) != __49373_33_input_file)) {
(__49388_21_sym->multiple_definition) = ((_ZN3edg14a_byte_booleanE)1U);
} else  {
(__49388_21_sym->defined_in) = __49373_33_input_file;
(__49388_21_sym->defined) = ((_ZN3edg14a_byte_booleanE)1U);
}
}


if ((__49384_19_psp->template_sym) != ((a_pl_symbol_ptr)0)) { (__49388_21_sym->template_sym) = (__49384_19_psp->template_sym); }


if (__49384_19_psp->do_not_instantiate) { (__49388_21_sym->do_not_instantiate) = ((_ZN3edg14a_byte_booleanE)1U); }
if (__49384_19_psp->is_template) { (__49388_21_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1U); }
if ((__49384_19_psp->can_be_instantiated) || (((__49388_21_sym->template_sym) != ((a_pl_symbol_ptr)0)) && ((__49388_21_sym->template_sym)->defined)))
{
(__49388_21_sym->can_be_instantiated) = ((_ZN3edg14a_byte_booleanE)1U);
# 2212
_ZN33_INTERNAL_13_edg_prelink_c_optind31add_possible_instantiation_siteEP11a_pl_symbolP15a_pl_input_file(__49388_21_sym, __49373_33_input_file);
}
(__49388_21_sym->tentative_definition) |= ((int)(__49384_19_psp->tentative_definition));
}
__49384_19_psp = (__49384_19_psp->next);
}
(__49372_61_pofp->included_in_output) = ((_ZN3edg14a_byte_booleanE)1U); 
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_any_symbols_referencedEP16a_pl_object_file( a_pl_object_file_ptr __49482_65_pofp)




{
auto a_pl_symbol_ptr __49488_19_psp;
auto _ZN3edg9a_booleanE __49489_14_result = 0;

__49488_19_psp = (__49482_65_pofp->symbols);
while (__49488_19_psp != ((a_pl_symbol_ptr)0)) {
auto a_pl_symbol_ptr __49493_21_sym;
if ((__49488_19_psp->defined) || (__49488_19_psp->tentative_definition)) {

__49493_21_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi((__49488_19_psp->name), __49488_19_psp, 1, ((_ZN3edg9a_booleanE *)0)));
if (!(__49493_21_sym->defined)) {



if ((__49493_21_sym->referenced) || ((__49493_21_sym->tentative_definition) && (__49488_19_psp->defined)))
{
__49489_14_result = 1;
goto __T72587512;
}
# 2253
(__49493_21_sym->definition_seen_in_archive) = ((_ZN3edg14a_byte_booleanE)1U);
}
}
__49488_19_psp = (__49488_19_psp->next);
} __T72587512:;
return __49489_14_result;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind10pl_prelinkEv(void)




{
auto a_pl_input_file_ptr __49528_23_pifp;

__49528_23_pifp = pl_input_files;
while (__49528_23_pifp != ((a_pl_input_file_ptr)0)) {
auto a_pl_object_file_ptr __49532_26_pofp;
auto _ZN3edg9a_booleanE __49533_17_file_used_from_archive = 0;
__49532_26_pofp = (__49528_23_pifp->objects);
if (!(__49528_23_pifp->is_archive)) {
if (__49532_26_pofp != ((a_pl_object_file_ptr)0)) {




for (; __49532_26_pofp != ((a_pl_object_file_ptr)0); __49532_26_pofp = (__49532_26_pofp->next)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind26pl_add_symbols_from_objectEP16a_pl_object_fileP15a_pl_input_file(__49532_26_pofp, __49528_23_pifp);
}
}
} else  {
while (__49532_26_pofp != ((a_pl_object_file_ptr)0)) {
if (!(__49532_26_pofp->included_in_output)) {



if (_ZN33_INTERNAL_13_edg_prelink_c_optind25pl_any_symbols_referencedEP16a_pl_object_file(__49532_26_pofp)) {



_ZN33_INTERNAL_13_edg_prelink_c_optind26pl_add_symbols_from_objectEP16a_pl_object_fileP15a_pl_input_file(__49532_26_pofp, __49528_23_pifp);
__49533_17_file_used_from_archive = 1;
}
}
__49532_26_pofp = (__49532_26_pofp->next);
}
}




if (!(__49533_17_file_used_from_archive)) { __49528_23_pifp = (__49528_23_pifp->next); }
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(void)




{
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_corrupted_template_info_file, ((char *)0)); 
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_suffixEPc( char *__49581_35_name)




{
auto char *__49587_9_last_dot;

__49587_9_last_dot = (_Z7strrchrPci(__49581_35_name, 46));
return __49587_9_last_dot;
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_derived_nameEPKcS1_( _ZN3edg12a_const_charE *__49594_44_name, 
_ZN3edg12a_const_charE *__49595_23_suffix)
# 2343
{
auto char *__49604_11_last_dot;
# 2351
((pl_file_name_buffer)[0]) = ((char)0);
strncat(pl_file_name_buffer, __49594_44_name, 4085UL);

__49604_11_last_dot = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_suffixEPc(pl_file_name_buffer));
if (__49604_11_last_dot == ((char *)0)) {

__49604_11_last_dot = ((pl_file_name_buffer) + (strlen(((const char *)pl_file_name_buffer))));
}

(*__49604_11_last_dot) = ((char)0);
strncat(__49604_11_last_dot, __49595_23_suffix, 10UL);
return pl_file_name_buffer;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_read_template_info_fileEP15a_pl_input_file( a_pl_input_file_ptr __49626_60_pifp)
# 2373
{
auto _ZN3edg8sizeof_tE __49634_13_instantiation_dir_length = 0UL;
auto _ZN3edg8sizeof_tE __49635_13_compilation_dir_length = 0UL;
auto _ZN3edg8sizeof_tE __49636_13_instantiation_suffix_length;
auto _ZN3edg8sizeof_tE __49637_13_extra_space;
auto FILE *__49638_11_f_template_info = ((FILE *)0);
auto _ZN3edg9a_booleanE __49639_14_instantiation_dir_set = 0;
auto a_pl_object_file_ptr __49640_24_pofp;
auto a_pl_symbol_ptr __49641_19_last_primary_entry = ((a_pl_symbol_ptr)0);

if ((__49626_60_pifp->template_info_file_name) != ((char *)0)) {
__49638_11_f_template_info = (fopen(((const char *)(__49626_60_pifp->template_info_file_name)), ((const char *)"r")));
}
if (__49638_11_f_template_info != ((FILE *)0)) {


__49640_24_pofp = (_ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv());
(__49640_24_pofp->file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(__49626_60_pifp->file_name))));
__49636_13_instantiation_suffix_length = 6UL;
while (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__49638_11_f_template_info)) {
auto char *__49653_14_line_type = pl_input_line;
auto char *__49654_14_info;
auto a_pl_symbol_ptr __49655_23_sym;
# 2394
__49654_14_info = (__49653_14_line_type + 4);


if ((strncmp(((const char *)__49653_14_line_type), ((const char *)"flg:"), 4UL)) == 0) {
# 2403
auto char *__49663_15_flag_pos;
__49663_15_flag_pos = (_Z6strchrPci(__49654_14_info, 58));
if (__49663_15_flag_pos == ((char *)0)) { _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(); }

(*(__49663_15_flag_pos++)) = ((char)0);
__49655_23_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind15alloc_pl_symbolEv());
(__49655_23_sym->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__49654_14_info)));
for (; (((int)(*__49663_15_flag_pos)) != 0) && (((int)(*__49663_15_flag_pos)) != 58); __49663_15_flag_pos++) {
switch ((int)(*__49663_15_flag_pos)) {
case 67:
(__49655_23_sym->can_be_instantiated) = ((_ZN3edg14a_byte_booleanE)1U);
(__49655_23_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1U);
goto __T72649680;
case 68:
(__49655_23_sym->do_not_instantiate) = ((_ZN3edg14a_byte_booleanE)1U);
goto __T72649680;
case 84:
(__49655_23_sym->is_template) = ((_ZN3edg14a_byte_booleanE)1U);
(__49655_23_sym->referenced) = ((_ZN3edg14a_byte_booleanE)1U);
goto __T72649680;
default:
_ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv();
} __T72649680:; ;
}

if (((int)(*__49663_15_flag_pos)) == 58) {
auto char *__49689_17_name_pos; __49689_17_name_pos = (__49663_15_flag_pos + 1);
(__49655_23_sym->template_sym) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi(__49689_17_name_pos, ((a_pl_symbol_ptr)0), 1, ((_ZN3edg9a_booleanE *)0)));

}
(__49655_23_sym->next) = (__49640_24_pofp->symbols);
(__49640_24_pofp->symbols) = __49655_23_sym;


__49641_19_last_primary_entry = __49655_23_sym;
} else  { if ((strncmp(((const char *)__49653_14_line_type), ((const char *)"ent:"), 4UL)) == 0) {


auto char *__49701_15_name_pos;
auto a_pl_symbol_ptr __49702_25_global_for_last_primary;
# 2441
__49701_15_name_pos = (__49653_14_line_type + 4);

if (__49641_19_last_primary_entry == ((a_pl_symbol_ptr)0)) { _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(); }
__49655_23_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi(__49701_15_name_pos, ((a_pl_symbol_ptr)0), 1, ((_ZN3edg9a_booleanE *)0)));

__49702_25_global_for_last_primary = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi((__49641_19_last_primary_entry->name), __49641_19_last_primary_entry, 1, ((_ZN3edg9a_booleanE *)0)));



(__49655_23_sym->primary_entry) = __49702_25_global_for_last_primary;
} else  { if ((strncmp(((const char *)__49653_14_line_type), ((const char *)"tnm:"), 4UL)) == 0) {

auto char *__49713_15_name_pos; __49713_15_name_pos = (__49653_14_line_type + 4);
__49655_23_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi(__49713_15_name_pos, ((a_pl_symbol_ptr)0), 1, ((_ZN3edg9a_booleanE *)0)));

(__49655_23_sym->defined) = ((_ZN3edg14a_byte_booleanE)1U);
} else  { if ((strncmp(((const char *)__49653_14_line_type), ((const char *)"ifn:"), 4UL)) == 0) {
# 2463
auto a_pl_object_file_ptr __49723_30_i_pofp;
auto _ZN3edg9a_booleanE __49724_20_add_compilation_dir = 0;
# 2481
auto size_t __49741_16_file_name_size;
# 2465
__49637_13_extra_space = 3UL;
if (!(__49639_14_instantiation_dir_set)) {


(__49626_60_pifp->instantiation_directory) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((const char *)"Template.dir")));
__49634_13_instantiation_dir_length = (strlen(((const char *)(__49626_60_pifp->instantiation_directory))));
__49639_14_instantiation_dir_set = 1;
}
if ((!(__49626_60_pifp->is_local_file)) && (!(_ZN33_INTERNAL_13_edg_prelink_c_optind24pl_is_absolute_file_nameEPc((__49626_60_pifp->instantiation_directory)))))
{



__49724_20_add_compilation_dir = 1;
}
__49723_30_i_pofp = (_ZN33_INTERNAL_13_edg_prelink_c_optind20alloc_pl_object_fileEv());
__49741_16_file_name_size = (((((strlen(((const char *)__49654_14_info))) + __49634_13_instantiation_dir_length) + __49636_13_instantiation_suffix_length) + ((__49724_20_add_compilation_dir) ? __49635_13_compilation_dir_length : 0UL)) + __49637_13_extra_space);
# 2487
(__49723_30_i_pofp->file_name) = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(__49741_16_file_name_size)));

snprintf((__49723_30_i_pofp->file_name), __49741_16_file_name_size, ((const char *)"%s%s%s/%s%s"), ((__49724_20_add_compilation_dir) ? ((const char *)(__49626_60_pifp->compilation_directory)) : ((const char *)"")), ((__49724_20_add_compilation_dir) ? ((const char *)("/")) : ((const char *)(""))), (
# 2489
__49626_60_pifp->instantiation_directory), __49654_14_info, ((const char *)(".int.o")));




(__49723_30_i_pofp->next) = (__49626_60_pifp->objects);
(__49723_30_i_pofp->is_related_file) = ((_ZN3edg14a_byte_booleanE)1U);
(__49626_60_pifp->objects) = __49723_30_i_pofp;
} else  { if ((strncmp(((const char *)__49653_14_line_type), ((const char *)"dep:"), 4UL)) == 0) {


auto a_pl_file_list_entry_ptr __49760_34_flep;
__49760_34_flep = (_ZN33_INTERNAL_13_edg_prelink_c_optind24alloc_pl_file_list_entryEv());
(__49760_34_flep->name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__49654_14_info)));
(__49760_34_flep->next) = (__49626_60_pifp->dependencies);
(__49626_60_pifp->dependencies) = __49760_34_flep;
} else  { if ((strncmp(((const char *)__49653_14_line_type), ((const char *)"cmd:"), 4UL)) == 0) {

(__49626_60_pifp->command_line) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__49654_14_info)));
} else  { if ((strncmp(((const char *)__49653_14_line_type), ((const char *)"dir:"), 4UL)) == 0) {

(__49626_60_pifp->compilation_directory) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__49654_14_info)));

(__49626_60_pifp->is_local_file) = ((_ZN3edg14a_byte_booleanE)((strcmp(((const char *)(__49626_60_pifp->compilation_directory)), ((const char *)curr_dir_name))) == 0));

__49635_13_compilation_dir_length = (strlen(((const char *)(__49626_60_pifp->compilation_directory))));
} else  { if ((strncmp(((const char *)__49653_14_line_type), ((const char *)"fnm:"), 4UL)) == 0) {

(__49626_60_pifp->compilation_file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__49654_14_info)));
} else  { if ((strncmp(((const char *)__49653_14_line_type), ((const char *)"stu:"), 4UL)) == 0) {


(__49626_60_pifp->secondary_files) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__49654_14_info)));
} else  { if ((strncmp(((const char *)__49653_14_line_type), ((const char *)"idn:"), 4UL)) == 0) {


if (__49639_14_instantiation_dir_set) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"instantiation_dir already set"));
}
(__49626_60_pifp->instantiation_directory) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__49654_14_info)));
__49634_13_instantiation_dir_length = (strlen(((const char *)(__49626_60_pifp->instantiation_directory))));
__49639_14_instantiation_dir_set = 1;
} else  {
_ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv();
} } } } } } } } } }
}
fclose(__49638_11_f_template_info);


(__49640_24_pofp->next) = (__49626_60_pifp->objects);
(__49626_60_pifp->objects) = __49640_24_pofp;
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind38pl_read_command_info_from_request_fileEP15a_pl_input_fileP8_IO_FILE(
a_pl_input_file_ptr __49805_26_pifp, 
FILE *__49806_14_f_request)



{
auto int __49811_7_i;

for (__49811_7_i = 0; __49811_7_i < reserved_request_file_lines; ++__49811_7_i) {
_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__49806_14_f_request);
(((__49805_26_pifp->reserved_lines))[__49811_7_i]) = ((_ZN3edg12a_const_charE *)(_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)pl_input_line))));
}



if (reserved_request_file_lines >= 1) {
(__49805_26_pifp->command_line) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc((((__49805_26_pifp->reserved_lines))[0])));
}
if (!(use_template_info_file)) {
# 2579
}



for (; __49811_7_i < 0; ++__49811_7_i) {
(((__49805_26_pifp->reserved_lines))[__49811_7_i]) = ((const char *)"");
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind35pl_read_instantiation_request_filesEv(void)




{
auto a_pl_input_file_ptr __49855_23_pifp;
auto FILE *__49856_11_f_request;

__49855_23_pifp = pl_input_files;
while (__49855_23_pifp != ((a_pl_input_file_ptr)0)) {
if ((!(__49855_23_pifp->is_archive)) && ((__49855_23_pifp->request_file_name) != ((char *)0))) {
__49856_11_f_request = (fopen(((const char *)(__49855_23_pifp->request_file_name)), ((const char *)"r")));

if (pl_debug_level >= 2) {
fprintf(stderr, ((const char *)"Opening %s, result=%d\n"), (__49855_23_pifp->request_file_name), ((int)(__49856_11_f_request != ((FILE *)0))));

}

if (__49856_11_f_request != ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind38pl_read_command_info_from_request_fileEP15a_pl_input_fileP8_IO_FILE(__49855_23_pifp, __49856_11_f_request);

while (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__49856_11_f_request)) {
auto a_pl_symbol_ptr __49872_27_sym;
__49872_27_sym = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi(pl_input_line, ((a_pl_symbol_ptr)0), 1, ((_ZN3edg9a_booleanE *)0)));

if ((__49872_27_sym->instantiation_file) != ((a_pl_input_file_ptr)0)) {


fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_error)), message_prefix);
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_multiple_assignments)), (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc((__49872_27_sym->name))), (__49855_23_pifp->file_name), ((__49872_27_sym->instantiation_file)->file_name));


_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_bad_instantiation_request_file, ((char *)0));
}
(__49872_27_sym->instantiation_file) = __49855_23_pifp;


(__49872_27_sym->next_in_request_file) = (__49855_23_pifp->request_list);
(__49855_23_pifp->request_list) = __49872_27_sym;
}
fclose(__49856_11_f_request);
}
}
__49855_23_pifp = (__49855_23_pifp->next);
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind34pl_create_instantiation_file_namesEP15a_pl_input_filePPcS3_(
a_pl_input_file_ptr __49899_24_pifp, 
char **__49900_13_request_file_name, 
char **__49901_13_template_info_file_name)




{
auto char *__49907_11_suffix;

(*__49900_13_request_file_name) = ((char *)0);
(*__49901_13_template_info_file_name) = ((char *)0);
__49907_11_suffix = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_suffixEPc((__49899_24_pifp->file_name)));
if ((__49907_11_suffix != ((char *)0)) && ((strcmp(((const char *)__49907_11_suffix), ((const char *)".o"))) == 0)) {


(*__49900_13_request_file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_derived_nameEPKcS1_(((_ZN3edg12a_const_charE *)(__49899_24_pifp->file_name)), ((const char *)".ii"))))));

if ((use_template_info_file) && ((*__49900_13_request_file_name) != ((char *)0))) {
(*__49901_13_template_info_file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_derived_nameEPKcS1_(((_ZN3edg12a_const_charE *)(__49899_24_pifp->file_name)), ((const char *)".ti"))))));

}
} 
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind26pl_check_for_template_fileEP15a_pl_input_file( a_pl_input_file_ptr __49925_65_pifp)




{
auto FILE *__49931_11_f_test = ((FILE *)0);
auto char *__49932_11_request_file_name;
auto char *__49933_11_template_info_file_name;
auto char *__49934_11_file_to_test;


_ZN33_INTERNAL_13_edg_prelink_c_optind34pl_create_instantiation_file_namesEP15a_pl_input_filePPcS3_(__49925_65_pifp, (&__49932_11_request_file_name), (&__49933_11_template_info_file_name));



if (__49932_11_request_file_name != ((char *)0)) {


__49934_11_file_to_test = ((use_template_info_file) ? __49933_11_template_info_file_name : __49932_11_request_file_name);

__49931_11_f_test = (fopen(((const char *)__49934_11_file_to_test), ((const char *)"r")));
if (__49931_11_f_test != ((FILE *)0)) {
fclose(__49931_11_f_test);
(__49925_65_pifp->request_file_name) = __49932_11_request_file_name;
(__49925_65_pifp->template_info_file_name) = __49933_11_template_info_file_name;
} else  {
free(((void *)__49932_11_request_file_name));
if (use_template_info_file) { free(((void *)__49933_11_template_info_file_name)); }
}
}
return (_ZN3edg9a_booleanE)(__49931_11_f_test != ((FILE *)0));
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind18pl_can_instantiateEP15a_pl_input_fileP11a_pl_symbol( a_pl_input_file_ptr __49960_57_pifp, 
a_pl_symbol_ptr __49961_22_psp)




{
auto a_pl_instantiation_site_ptr __49967_31_pisp;
auto _ZN3edg9a_booleanE __49968_15_result = 0;

__49967_31_pisp = (__49961_22_psp->possible_instantiation_sites);
while (__49967_31_pisp != ((a_pl_instantiation_site_ptr)0)) {
if ((__49967_31_pisp->input_file) == __49960_57_pifp) {
__49968_15_result = 1;
goto __T72804888;
}
__49967_31_pisp = (__49967_31_pisp->next);
} __T72804888:;
return __49968_15_result;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind17record_assignmentEPc( char *__49982_37_name)
# 2730
{
auto a_pl_assignment_ptr __49991_23_ap;

__49991_23_ap = (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_find_assignmentEPc(__49982_37_name));




if ((__49991_23_ap->times_assigned) > 3) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"instantiation loop"));
}
(__49991_23_ap->times_assigned)++; 
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_check_dependenciesEP15a_pl_input_file( a_pl_input_file_ptr __50005_60_pifp)
# 2751
{
auto _ZN3edg9a_booleanE __50012_15_result = 0;
auto a_pl_object_file_ptr __50013_25_pofp;
auto a_pl_file_list_entry_ptr __50014_28_flep;
# 2753
__50013_25_pofp = (__50005_60_pifp->objects);



if (__50013_25_pofp == ((a_pl_object_file_ptr)0)) {
goto __50043_1_done;
} else  { if ((__50013_25_pofp->modification_time) == 0L) {


if (!(_ZN3edg26get_file_modification_timeEPKcPl(((_ZN3edg12a_const_charE *)(__50013_25_pofp->file_name)), (&(__50013_25_pofp->modification_time)))))
{


goto __50043_1_done;
}
} }
for (__50014_28_flep = (__50005_60_pifp->dependencies); __50014_28_flep != ((a_pl_file_list_entry_ptr)0); __50014_28_flep = (__50014_28_flep->next)) {
auto time_t __50030_12_dep_time;
if (_ZN3edg26get_file_modification_timeEPKcPl(((_ZN3edg12a_const_charE *)(__50014_28_flep->name)), (&__50030_12_dep_time))) {
if (__50030_12_dep_time > (__50013_25_pofp->modification_time)) {

__50012_15_result = 1;
if (verbose) {
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_out_of_date)), message_prefix, (__50005_60_pifp->file_name), (__50014_28_flep->name));

}
goto __T72824040;
}
}
} __T72824040:;
__50043_1_done:;
return __50012_15_result;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_determine_actionsEi( _ZN3edg9a_booleanE __50048_49_do_local_files)
# 2799
{
auto a_pl_input_file_ptr __50060_23_pifp;
auto _ZN3edg9a_booleanE __50061_14_done = 1;

for (__50060_23_pifp = pl_input_files; __50060_23_pifp != ((a_pl_input_file_ptr)0); __50060_23_pifp = (__50060_23_pifp->next)) { {

if (((int)(__50060_23_pifp->is_local_file)) != __50048_49_do_local_files) { goto __T72829632; }

if ((__50060_23_pifp->objects) == ((a_pl_object_file_ptr)0)) { goto __T72829632; }
if (!(__50060_23_pifp->is_archive)) {
auto a_pl_symbol_ptr __50069_23_psp;
auto a_pl_symbol_ptr __50070_23_prev_psp;


if ((((__50060_23_pifp->dependencies) != ((a_pl_file_list_entry_ptr)0)) && (!(suppress_dependency_checking))) && (_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_check_dependenciesEP15a_pl_input_file(__50060_23_pifp)))

{


(__50060_23_pifp->request_file_updated) = ((_ZN3edg14a_byte_booleanE)1U);
(__50060_23_pifp->recompile) = ((_ZN3edg14a_byte_booleanE)1U);
__50061_14_done = 0;
}


__50069_23_psp = (__50060_23_pifp->request_list);
__50070_23_prev_psp = ((a_pl_symbol_ptr)0);
while (__50069_23_psp != ((a_pl_symbol_ptr)0)) {
auto _ZN3edg9a_booleanE __50087_20_remove_from_request_file = 0;
auto _ZN3edg9a_booleanE __50088_20_recompile_file = 0;
auto _ZN3edg9a_booleanE __50089_20_remove_one_inst_per_obj_file = 0;
if ((__50069_23_psp->multiple_definition) || (__50069_23_psp->do_not_instantiate)) {
# 2837
__50087_20_remove_from_request_file = 1;
__50088_20_recompile_file = 1;
} else  { if (((__50069_23_psp->defined_in) == ((a_pl_input_file_ptr)0)) || ((__50069_23_psp->defined_in) != __50060_23_pifp))
{
# 2849
__50087_20_remove_from_request_file = 1;


__50089_20_remove_one_inst_per_obj_file = ((_ZN3edg9a_booleanE)((__50069_23_psp->defined_in) == ((a_pl_input_file_ptr)0)));
__50088_20_recompile_file = 1;
} else  { if (!(__50069_23_psp->is_template)) {


__50087_20_remove_from_request_file = 1;
__50088_20_recompile_file = 1;
} else  { if (!(__50069_23_psp->referenced)) {
# 2866
__50087_20_remove_from_request_file = 1;
__50088_20_recompile_file = 1;
__50089_20_remove_one_inst_per_obj_file = 1;
} else  {

(__50069_23_psp->instantiated) = ((_ZN3edg14a_byte_booleanE)1U);
} } } }
if (__50087_20_remove_from_request_file) {
# 2880
if (__50070_23_prev_psp != ((a_pl_symbol_ptr)0)) {
(__50070_23_prev_psp->next_in_request_file) = (__50069_23_psp->next_in_request_file);
} else  {
(__50060_23_pifp->request_list) = (__50069_23_psp->next_in_request_file);
}
(__50069_23_psp->instantiation_file) = ((a_pl_input_file_ptr)0);
(__50060_23_pifp->request_file_updated) = ((_ZN3edg14a_byte_booleanE)1U);
(__50060_23_pifp->recompile) = ((_ZN3edg14a_byte_booleanE)__50088_20_recompile_file);
__50061_14_done = 0;




if ((one_instantiation_per_object) && (__50089_20_remove_one_inst_per_obj_file))
{



snprintf(pl_file_name_buffer, 4096UL, ((const char *)"%s/%s%s"), (__50060_23_pifp->instantiation_directory), (_ZN3edg39generate_instantiation_output_file_nameEPKc(((_ZN3edg12a_const_charE *)(__50069_23_psp->name)))), ((const char *)(".int.o")));




unlink(((const char *)pl_file_name_buffer));
}

if (verbose) {
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_no_longer_needed)), message_prefix, (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc((__50069_23_psp->name))), (__50060_23_pifp->file_name));


}
}


if (!(__50087_20_remove_from_request_file)) { __50070_23_prev_psp = __50069_23_psp; }
__50069_23_psp = (__50069_23_psp->next_in_request_file);
}



__50069_23_psp = ((__50060_23_pifp->objects)->symbols);
while (__50069_23_psp != ((a_pl_symbol_ptr)0)) {
auto a_pl_symbol_ptr __50182_25_sym; __50182_25_sym = (__50069_23_psp->global_sym);

if (pl_debug_level >= 4) {
fprintf(stderr, ((const char *)"File: %s, Symbol: %s\n"), (__50060_23_pifp->file_name), ((__50182_25_sym == ((a_pl_symbol_ptr)0)) ? ((const char *)"null") : ((const char *)(__50182_25_sym->name))));

if (__50182_25_sym != ((a_pl_symbol_ptr)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind12pl_db_symbolEP11a_pl_symbolPKc(__50182_25_sym, ((const char *)"        "));
}
}

if (((((((((__50182_25_sym != ((a_pl_symbol_ptr)0)) && (__50182_25_sym->is_template)) && (!(__50182_25_sym->instantiated))) && (!(__50182_25_sym->do_not_instantiate))) && (__50182_25_sym->can_be_instantiated)) && ((__50182_25_sym->referenced) || (__50182_25_sym->tentative_definition))) && (!(
# 2932
__50182_25_sym->defined))) && (!(__50182_25_sym->definition_seen_in_archive))) && (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_can_instantiateEP15a_pl_input_fileP11a_pl_symbol(__50060_23_pifp, __50182_25_sym)))




{




(__50182_25_sym->next_in_request_file) = (__50060_23_pifp->request_list);
(__50060_23_pifp->request_list) = __50182_25_sym;
(__50182_25_sym->instantiated) = ((_ZN3edg14a_byte_booleanE)1U);
(__50060_23_pifp->request_file_updated) = ((_ZN3edg14a_byte_booleanE)1U);
(__50060_23_pifp->recompile) = ((_ZN3edg14a_byte_booleanE)1U);
__50061_14_done = 0;


_ZN33_INTERNAL_13_edg_prelink_c_optind17record_assignmentEPc((__50182_25_sym->name));
if (verbose) {
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_assigned_to_file)), message_prefix, (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc((__50182_25_sym->name))), (__50060_23_pifp->file_name));


}
}
__50069_23_psp = (__50069_23_psp->next);
}
}



if ((__50060_23_pifp->recompile) && (use_definition_list)) { goto __T72891144; }
} __T72829632:; } __T72891144:;
return __50061_14_done;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_change_directoryEPc( char *__50229_39_new_dir)


{

if (pl_debug_level >= 2) {
fprintf(stderr, ((const char *)"Changing to directory %s\n"), __50229_39_new_dir);
}

if ((chdir(((const char *)__50229_39_new_dir))) != 0) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_chdir, __50229_39_new_dir);
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc( char **__50244_48_dest, 
_ZN3edg12a_const_charE *__50245_19_source)
# 2992
{
auto _ZN3edg12a_const_charE *__50253_17_from;
auto char *__50254_10_to;
auto _ZN3edg9a_booleanE __50255_13_in_quote = 0;
auto char __50256_9_quote_char = ((char)0);
auto _ZN3edg9a_booleanE __50257_13_is_escaped = 0;
auto char __50258_9_outer_quote = ((char)0);
# 2994
__50254_10_to = (*__50244_48_dest);
# 3000
for (__50253_17_from = __50245_19_source; ((int)(*__50253_17_from)) != 0; ++__50253_17_from) {
auto char __50261_10_ch;
auto _ZN3edg9a_booleanE __50262_15_is_close_quote = 0;
# 3001
__50261_10_ch = (*__50253_17_from);

if (__50257_13_is_escaped) {
__50257_13_is_escaped = 0;
} else  { if (((int)__50261_10_ch) == 92) {
__50257_13_is_escaped = 1;
} else  { if ((!(__50255_13_in_quote)) && ((((int)__50261_10_ch) == 34) || (((int)__50261_10_ch) == 39))) {
__50255_13_in_quote = 1;
__50256_9_quote_char = __50261_10_ch;
__50258_9_outer_quote = ((((int)__50261_10_ch) == 34) ? ((char)39) : ((char)34));
(*(__50254_10_to++)) = __50258_9_outer_quote;
} else  { if ((__50255_13_in_quote) && (((int)__50261_10_ch) == ((int)__50256_9_quote_char))) {
__50262_15_is_close_quote = 1;
} else  { if (((__50255_13_in_quote) && (((int)__50261_10_ch) == ((int)__50256_9_quote_char))) || ((!(__50255_13_in_quote)) && ((((int)__50261_10_ch) == 40) || (((int)__50261_10_ch) == 41))))
{
(*(__50254_10_to++)) = ((char)92);
} } } } }
(*(__50254_10_to++)) = __50261_10_ch;
if (__50262_15_is_close_quote) {
__50255_13_in_quote = 0;
(*(__50254_10_to++)) = __50258_9_outer_quote;
}
}

if (((int)(*(__50254_10_to - 1))) != 32) { (*(__50254_10_to++)) = ((char)32); }
(*__50244_48_dest) = __50254_10_to; 
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind18build_command_lineEPKcS1_S1_S1_( _ZN3edg12a_const_charE *__50290_47_part1, 
_ZN3edg12a_const_charE *__50291_47_part2, 
_ZN3edg12a_const_charE *__50292_47_part3, 
_ZN3edg12a_const_charE *__50293_19_part4)
# 3040
{
auto char *__50301_10_to;
auto _ZN3edg8sizeof_tE __50302_12_length;
auto char *__50303_10_command;



if (__50291_47_part2 == ((_ZN3edg12a_const_charE *)0)) { __50291_47_part2 = ((const char *)""); }
if (__50292_47_part3 == ((_ZN3edg12a_const_charE *)0)) { __50292_47_part3 = ((const char *)""); }
if (__50293_19_part4 == ((_ZN3edg12a_const_charE *)0)) { __50293_19_part4 = ((const char *)""); }
if (__50290_47_part1 == ((_ZN3edg12a_const_charE *)0)) { _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(); }
__50302_12_length = (((((strlen(__50290_47_part1)) + (strlen(__50291_47_part2))) + (strlen(__50292_47_part3))) + (strlen(__50293_19_part4))) * 2UL);
if (__50302_12_length <= 3UL) { _ZN33_INTERNAL_13_edg_prelink_c_optind31pl_corrupted_template_info_fileEv(); }
__50303_10_command = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(__50302_12_length)));
__50301_10_to = __50303_10_command;
_ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc((&__50301_10_to), __50290_47_part1);
_ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc((&__50301_10_to), __50291_47_part2);
_ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc((&__50301_10_to), __50292_47_part3);
_ZN33_INTERNAL_13_edg_prelink_c_optind19add_to_command_lineEPPcPKc((&__50301_10_to), __50293_19_part4);

(*(__50301_10_to - 1)) = ((char)0);
return __50303_10_command;
}


static int _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_recompile_fileEP15a_pl_input_filePKcS3_( a_pl_input_file_ptr __50325_50_pifp, 
_ZN3edg12a_const_charE *__50326_45_extra_command_args, 
_ZN3edg12a_const_charE *__50327_24_extra_args_for_display)
# 3074
{
auto char *__50335_10_command;
auto char *__50336_10_display_command;
auto int __50337_8_result;
auto _ZN3edg9a_booleanE __50338_13_chdir_needed;




__50338_13_chdir_needed = ((_ZN3edg9a_booleanE)(((__50325_50_pifp->compilation_directory) != ((char *)0)) && ((strcmp(((const char *)(__50325_50_pifp->compilation_directory)), ((const char *)curr_dir_name))) != 0)));

if (__50338_13_chdir_needed) {

_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_change_directoryEPc((__50325_50_pifp->compilation_directory));
}
__50335_10_command = (_ZN33_INTERNAL_13_edg_prelink_c_optind18build_command_lineEPKcS1_S1_S1_(((_ZN3edg12a_const_charE *)(__50325_50_pifp->command_line)), __50326_45_extra_command_args, ((_ZN3edg12a_const_charE *)(__50325_50_pifp->compilation_file_name)), ((_ZN3edg12a_const_charE *)(
# 3089
__50325_50_pifp->secondary_files))));


if (__50327_24_extra_args_for_display != ((_ZN3edg12a_const_charE *)0)) {



__50336_10_display_command = (_ZN33_INTERNAL_13_edg_prelink_c_optind18build_command_lineEPKcS1_S1_S1_(((_ZN3edg12a_const_charE *)(__50325_50_pifp->command_line)), __50327_24_extra_args_for_display, ((_ZN3edg12a_const_charE *)(__50325_50_pifp->compilation_file_name)), ((_ZN3edg12a_const_charE *)(
# 3096
__50325_50_pifp->secondary_files))));



} else  {
__50336_10_display_command = __50335_10_command;
}
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_executing)), message_prefix, __50336_10_display_command);

fflush(f_informational);
__50337_8_result = (system(((const char *)__50335_10_command)));



if (__50337_8_result == (-1)) {
__50337_8_result = (*(__errno_location()));
} else  {
__50337_8_result = (__50337_8_result >> 8);
}
if (__50336_10_display_command != __50335_10_command) { free(((void *)__50336_10_display_command)); }
free(((void *)__50335_10_command));
if (__50338_13_chdir_needed) {

_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_change_directoryEPc(curr_dir_name);
}
return __50337_8_result;
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind18last_dir_separatorEPc( char *__50385_39_file_name)




{
auto char *__50391_9_ptr;

__50391_9_ptr = (_Z7strrchrPci(__50385_39_file_name, 47));
# 3144
return __50391_9_ptr;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind29prepare_to_move_nonlocal_fileEP15a_pl_input_file( a_pl_input_file_ptr __50408_63_pifp)
# 3158
{
auto char *__50419_10_orig_file_name;
auto char *__50420_10_orig_request_file_name;
auto char *__50421_10_orig_template_info_file_name;
auto char *__50422_10_ptr;


__50419_10_orig_file_name = (__50408_63_pifp->file_name);
__50422_10_ptr = (_ZN33_INTERNAL_13_edg_prelink_c_optind18last_dir_separatorEPc((__50408_63_pifp->file_name)));
if (__50422_10_ptr == ((char *)0)) {
fprintf(stderr, ((const char *)"Expected %s to include a directory name\n"), (__50408_63_pifp->file_name));

_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"Directory name missing"));
}
if ((__50408_63_pifp->secondary_files) != ((char *)0)) {


_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"copy if nonlocal cannot be used with secondary trans units"));

}
(__50408_63_pifp->file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(__50422_10_ptr + 1))));
__50420_10_orig_request_file_name = (__50408_63_pifp->request_file_name);
__50421_10_orig_template_info_file_name = (__50408_63_pifp->template_info_file_name);




_ZN33_INTERNAL_13_edg_prelink_c_optind34pl_create_instantiation_file_namesEP15a_pl_input_filePPcS3_(__50408_63_pifp, (&(__50408_63_pifp->request_file_name)), (&(__50408_63_pifp->template_info_file_name)));




if (_ZN33_INTERNAL_13_edg_prelink_c_optind24pl_is_absolute_file_nameEPc((__50408_63_pifp->compilation_file_name))) {

} else  {


snprintf(pl_file_name_buffer, 4096UL, ((const char *)"%s/%s"), (__50408_63_pifp->compilation_directory), (__50408_63_pifp->compilation_file_name));

free(((void *)(__50408_63_pifp->compilation_file_name)));
(__50408_63_pifp->compilation_file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)pl_file_name_buffer)));
}

free(((void *)(__50408_63_pifp->compilation_directory)));
(__50408_63_pifp->compilation_directory) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)curr_dir_name)));

if (pl_debug_level >= 2) {
fprintf(stderr, ((const char *)"Moving %s to %s\n"), __50420_10_orig_request_file_name, (__50408_63_pifp->request_file_name));

fprintf(stderr, ((const char *)"Using %s instead of %s\n"), (__50408_63_pifp->file_name), __50419_10_orig_file_name);

if (use_template_info_file) {
fprintf(stderr, ((const char *)"Using %s instead of %s\n"), (__50408_63_pifp->template_info_file_name), __50421_10_orig_template_info_file_name);

}
}

free(((void *)__50419_10_orig_file_name));
free(((void *)__50420_10_orig_request_file_name));
if (__50421_10_orig_template_info_file_name != ((char *)0)) { free(((void *)__50421_10_orig_template_info_file_name)); }
if (!(use_template_info_file)) {


(((__50408_63_pifp->reserved_lines))[0]) = ((_ZN3edg12a_const_charE *)(_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)(__50408_63_pifp->command_line)))));
# 3228
}

(__50408_63_pifp->is_local_file) = ((_ZN3edg14a_byte_booleanE)1U); 
}


static FILE *_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_create_temp_fileEv(void)
# 3240
{
auto FILE *__50501_10_f_temp;
auto _ZN3edg12a_const_charE *__50502_17_tmpdir;

if (temporary_file_name == ((char *)0)) {

__50502_17_tmpdir = ((_ZN3edg12a_const_charE *)(getenv(((const char *)"TMPDIR"))));
if (__50502_17_tmpdir == ((_ZN3edg12a_const_charE *)0)) {



__50502_17_tmpdir = ((const char *)"/tmp");

}
snprintf(pl_file_name_buffer, 4096UL, ((const char *)"%s/%0dpltf"), __50502_17_tmpdir, (getpid()));

temporary_file_name = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)pl_file_name_buffer)));
}
__50501_10_f_temp = (fopen(((const char *)temporary_file_name), ((const char *)"w")));
if (__50501_10_f_temp == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_open_temporary_file, temporary_file_name);
}
return __50501_10_f_temp;
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEv(void)
# 3274
{

auto FILE *__50536_11_f_temp;
auto a_pl_input_file_ptr __50537_23_pifp;
auto a_pl_object_file_ptr __50538_24_pofp;
auto a_pl_symbol_ptr __50539_19_psp;

__50536_11_f_temp = (_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_create_temp_fileEv());
for (__50537_23_pifp = pl_input_files; __50537_23_pifp != ((a_pl_input_file_ptr)0); __50537_23_pifp = (__50537_23_pifp->next)) {
for (__50538_24_pofp = (__50537_23_pifp->objects); __50538_24_pofp != ((a_pl_object_file_ptr)0); __50538_24_pofp = (__50538_24_pofp->next)) {
for (__50539_19_psp = (__50538_24_pofp->symbols); __50539_19_psp != ((a_pl_symbol_ptr)0); __50539_19_psp = (__50539_19_psp->next)) {
if (__50539_19_psp->defined) {
fputs(((const char *)(__50539_19_psp->name)), __50536_11_f_temp);
fputs(((const char *)"\n"), __50536_11_f_temp);
}
}
}
}
fclose(__50536_11_f_temp);
if (_ZZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEvE22definition_list_option == ((char *)0)) {



snprintf(pl_file_name_buffer, 4096UL, ((const char *)"--definition_list_file=%s"), temporary_file_name);

_ZZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEvE22definition_list_option = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)pl_file_name_buffer)));
}
return _ZZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEvE22definition_list_option;
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind35pl_check_for_adopted_instantiationsEP15a_pl_input_file( a_pl_input_file_ptr __50565_69_pifp)
# 3311
{
auto FILE *__50572_9_f_request;
auto FILE *__50573_9_f_temp;

__50573_9_f_temp = (fopen(((const char *)temporary_file_name), ((const char *)"r")));
if (__50573_9_f_temp != ((FILE *)0)) {




if ((_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__50573_9_f_temp)) && ((strcmp(((const char *)pl_input_line), ((const char *)":add:"))) == 0)) {

__50572_9_f_request = (fopen(((const char *)(__50565_69_pifp->request_file_name)), ((const char *)"a")));
if (__50572_9_f_request == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_open_file_for_update, (__50565_69_pifp->request_file_name));
}
while (_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_read_input_lineEP8_IO_FILE(__50573_9_f_temp)) {
fputs(((const char *)pl_input_line), __50572_9_f_request);
fputs(((const char *)"\n"), __50572_9_f_request);


_ZN33_INTERNAL_13_edg_prelink_c_optind17record_assignmentEPc(pl_input_line);
if (verbose) {
fprintf(f_informational, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_adopted_by_file)), message_prefix, (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc(pl_input_line)), (__50565_69_pifp->file_name));


}
}
fclose(__50572_9_f_request);
}
fclose(__50573_9_f_temp);
} 
}


static int _ZN33_INTERNAL_13_edg_prelink_c_optind23pl_update_request_filesEv(void)




{

auto a_pl_input_file_ptr __50613_24_pifp;
auto int __50614_10_return_status = 0;
auto int __50615_10_i;

__50613_24_pifp = pl_input_files;
while (__50613_24_pifp != ((a_pl_input_file_ptr)0)) {
if (__50613_24_pifp->request_file_updated) {
auto a_pl_symbol_ptr __50620_23_psp;
auto FILE *__50621_14_f_request;

if ((__50613_24_pifp->request_file_name) == ((char *)0)) {
fprintf(stderr, ((const char *)"Input file %s has instantiations but no instantiation request file.\n"), (__50613_24_pifp->file_name));


_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_internal_errorEPKc(((const char *)"Instantiation request file is missing"));
}
if ((move_nonlocal_objects_to_curr_dir) && (!(__50613_24_pifp->is_local_file))) {



_ZN33_INTERNAL_13_edg_prelink_c_optind29prepare_to_move_nonlocal_fileEP15a_pl_input_file(__50613_24_pifp);
}

__50621_14_f_request = (fopen(((const char *)(__50613_24_pifp->request_file_name)), ((const char *)"w")));
if (__50621_14_f_request == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_open_file_for_update, (__50613_24_pifp->request_file_name));
}

for (__50615_10_i = 0; __50615_10_i < reserved_request_file_lines; ++__50615_10_i) {
fprintf(__50621_14_f_request, ((const char *)"%s\n"), (((__50613_24_pifp->reserved_lines))[__50615_10_i]));
}

__50620_23_psp = (__50613_24_pifp->request_list);
while (__50620_23_psp != ((a_pl_symbol_ptr)0)) {
fprintf(__50621_14_f_request, ((const char *)"%s\n"), (__50620_23_psp->name));
__50620_23_psp = (__50620_23_psp->next_in_request_file);
}
fclose(__50621_14_f_request);
if ((!(suppress_compilation)) && (__50613_24_pifp->recompile)) {
auto char *__50652_23_definition_list_option = ((char *)0);
auto _ZN3edg12a_const_charE *__50653_23_def_list_display_option = ((_ZN3edg12a_const_charE *)0);

unlink(((const char *)(__50613_24_pifp->file_name)));

if (use_definition_list) {
__50652_23_definition_list_option = (_ZN33_INTERNAL_13_edg_prelink_c_optind30pl_create_definition_list_fileEv());
__50653_23_def_list_display_option = ((const char *)"");



if (pl_debug_level != 0) { __50653_23_def_list_display_option = ((_ZN3edg12a_const_charE *)0); }

}
__50614_10_return_status = (_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_recompile_fileEP15a_pl_input_filePKcS3_(__50613_24_pifp, ((_ZN3edg12a_const_charE *)__50652_23_definition_list_option), __50653_23_def_list_display_option));

if (use_definition_list) {
if (__50614_10_return_status == 0) {


_ZN33_INTERNAL_13_edg_prelink_c_optind35pl_check_for_adopted_instantiationsEP15a_pl_input_file(__50613_24_pifp);
}

unlink(((const char *)temporary_file_name));
}

if (__50614_10_return_status != 0) { goto __T73133688; }
}
}
__50613_24_pifp = (__50613_24_pifp->next);
} __T73133688:;
return __50614_10_return_status;
}


static int _ZN33_INTERNAL_13_edg_prelink_c_optind29pl_remove_instantiation_flagsEv(void)




{

auto a_pl_input_file_ptr __50694_24_pifp;
auto int __50695_10_return_status = 0;
auto int __50696_10_max_return_status = 0;

__50694_24_pifp = pl_input_files;
while (__50694_24_pifp != ((a_pl_input_file_ptr)0)) {


if (((!(__50694_24_pifp->is_archive)) && ((__50694_24_pifp->request_file_name) != ((char *)0))) && (__50694_24_pifp->is_local_file))
{



unlink(((const char *)(__50694_24_pifp->file_name)));

__50695_10_return_status = (_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_recompile_fileEP15a_pl_input_filePKcS3_(__50694_24_pifp, ((const char *)"--suppress_instantiation_flags"), ((_ZN3edg12a_const_charE *)0)));


if (__50695_10_return_status > __50696_10_max_return_status) { __50696_10_max_return_status = __50695_10_return_status; }
}
__50694_24_pifp = (__50694_24_pifp->next);
}
return __50696_10_max_return_status;
}


static _ZN3edg9a_booleanE _ZN33_INTERNAL_13_edg_prelink_c_optind34pl_check_for_specialization_errorsEv(void)
# 3466
{
auto a_pl_symbol_ptr __50727_19_psp;
auto _ZN3edg9a_booleanE __50728_14_any_errors = 0;
auto _ZN3edg9a_booleanE __50729_14_is_new;

for (__50727_19_psp = specialization_list; __50727_19_psp != ((a_pl_symbol_ptr)0); __50727_19_psp = (__50727_19_psp->next_in_specialization_list))
{
auto a_pl_symbol_ptr __50733_21_nonspec_psp;
auto char *__50734_12_nonspec_name;


__50734_12_nonspec_name = (_ZN33_INTERNAL_13_edg_prelink_c_optind23get_nonspecialized_nameEPc((__50727_19_psp->name)));

__50733_21_nonspec_psp = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_find_symbolEPcP11a_pl_symboliPi(__50734_12_nonspec_name, ((a_pl_symbol_ptr)0), 1, (&__50729_14_is_new)));


if (pl_debug_level >= 1) {
fprintf(stderr, ((const char *)"original name: %s\n"), (__50727_19_psp->name));
fprintf(stderr, ((const char *)"nonspecialized name: %s\n"), __50734_12_nonspec_name);
}

if ((__50733_21_nonspec_psp != ((a_pl_symbol_ptr)0)) && ((__50733_21_nonspec_psp->referenced) || (__50733_21_nonspec_psp->defined)))
{
_ZN33_INTERNAL_13_edg_prelink_c_optind18pl_error_with_exitE15a_pl_error_codePci(pl_ec_specialized_and_instantiated, (_ZN33_INTERNAL_13_edg_prelink_c_optind15pl_decoded_nameEPc(__50734_12_nonspec_name)), 0);


__50728_14_any_errors = 1;
} else  {




(__50733_21_nonspec_psp->referenced) |= ((int)(__50727_19_psp->referenced));
(__50733_21_nonspec_psp->defined) |= ((int)(__50727_19_psp->defined));
}
}
return __50728_14_any_errors;
}



static void _ZN33_INTERNAL_13_edg_prelink_c_optind12pl_db_symbolEP11a_pl_symbolPKc( a_pl_symbol_ptr __50767_42_psp, 
_ZN3edg12a_const_charE *__50768_43_prefix_string)



{
auto a_pl_instantiation_site_ptr __50773_31_pisp;
fprintf(stderr, ((const char *)"%sSymbol: %s"), __50768_43_prefix_string, (__50767_42_psp->name));
if (__50767_42_psp->defined) { fprintf(stderr, ((const char *)" defined")); }
if (__50767_42_psp->referenced) { fprintf(stderr, ((const char *)" referenced")); }
if (__50767_42_psp->tentative_definition) {
fprintf(stderr, ((const char *)" tentative_definition"));
}
if (__50767_42_psp->multiple_definition) {
fprintf(stderr, ((const char *)" multiple_definition"));
}
if (__50767_42_psp->is_template) { fprintf(stderr, ((const char *)" is_template")); }
if (__50767_42_psp->can_be_instantiated) { fprintf(stderr, ((const char *)" can_be_instantiated")); }
if (__50767_42_psp->do_not_instantiate) { fprintf(stderr, ((const char *)" do_not_instantiate")); }
__50773_31_pisp = (__50767_42_psp->possible_instantiation_sites);
if (__50773_31_pisp != ((a_pl_instantiation_site_ptr)0)) {
fprintf(stderr, ((const char *)" Instantiation sites:"));
for (; __50773_31_pisp != ((a_pl_instantiation_site_ptr)0); __50773_31_pisp = (__50773_31_pisp->next)) {
fprintf(stderr, ((const char *)" %s"), ((__50773_31_pisp->input_file)->file_name));
}
}
fprintf(stderr, ((const char *)"\n")); 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind17pl_db_input_filesEv(void)



{
auto a_pl_input_file_ptr __50802_23_pifp;

__50802_23_pifp = pl_input_files;
while (__50802_23_pifp != ((a_pl_input_file_ptr)0)) {
auto a_pl_object_file_ptr __50806_26_pofp;
auto a_pl_symbol_ptr __50807_22_psp;
fprintf(stderr, ((const char *)"Input file: %s\n"), (__50802_23_pifp->file_name));
__50806_26_pofp = (__50802_23_pifp->objects);
while (__50806_26_pofp != ((a_pl_object_file_ptr)0)) {
fprintf(stderr, ((const char *)"  Object file: %s\n"), (__50806_26_pofp->file_name));
__50807_22_psp = (__50806_26_pofp->symbols);
while (__50807_22_psp != ((a_pl_symbol_ptr)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind12pl_db_symbolEP11a_pl_symbolPKc(__50807_22_psp, ((const char *)"    "));
__50807_22_psp = (__50807_22_psp->next);
}
__50806_26_pofp = (__50806_26_pofp->next);
}
__50807_22_psp = (__50802_23_pifp->request_list);
if (__50807_22_psp != ((a_pl_symbol_ptr)0)) {
fprintf(stderr, ((const char *)"  Instantiation list:\n"));
}
while (__50807_22_psp != ((a_pl_symbol_ptr)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind12pl_db_symbolEP11a_pl_symbolPKc(__50807_22_psp, ((const char *)"    "));
__50807_22_psp = (__50807_22_psp->next_in_request_file);
}
__50802_23_pifp = (__50802_23_pifp->next);
} 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind20pl_db_global_symbolsEi( _ZN3edg9a_booleanE __50832_44_all)



{
auto a_pl_symbol_ptr __50837_19_psp;

fprintf(stderr, ((const char *)"Global symbol table:\n"));
__50837_19_psp = pl_symbol_table_head;
while (__50837_19_psp != ((a_pl_symbol_ptr)0)) {
if ((__50832_44_all) || ((((__50837_19_psp->referenced) && (!((__50837_19_psp->defined) || (__50837_19_psp->tentative_definition)))) || (__50837_19_psp->multiple_definition)) && (__50837_19_psp->is_template)))
# 3591
{
_ZN33_INTERNAL_13_edg_prelink_c_optind12pl_db_symbolEP11a_pl_symbolPKc(__50837_19_psp, ((const char *)"  "));
}
__50837_19_psp = (__50837_19_psp->next_in_symbol_table);
} 
}



static void _ZN33_INTERNAL_13_edg_prelink_c_optind11pl_free_allEv(void)



{
auto a_pl_input_file_ptr __50865_23_pifp;
auto a_pl_symbol_ptr __50866_19_psp;

__50865_23_pifp = pl_input_files;
while (__50865_23_pifp != ((a_pl_input_file_ptr)0)) {
auto a_pl_object_file_ptr __50870_26_pofp;
auto a_pl_object_file_ptr __50871_26_last_pofp;
__50870_26_pofp = (__50865_23_pifp->objects);
while (__50870_26_pofp != ((a_pl_object_file_ptr)0)) {
auto a_pl_symbol_ptr __50874_23_last_psp;
__50866_19_psp = (__50870_26_pofp->symbols);
while (__50866_19_psp != ((a_pl_symbol_ptr)0)) {
__50874_23_last_psp = __50866_19_psp;
__50866_19_psp = (__50866_19_psp->next);
free(((void *)(__50874_23_last_psp->name)));
_ZN33_INTERNAL_13_edg_prelink_c_optind14free_pl_symbolEP11a_pl_symbol(__50874_23_last_psp);
}
__50871_26_last_pofp = __50870_26_pofp;
__50870_26_pofp = (__50870_26_pofp->next);
free(((void *)(__50871_26_last_pofp->file_name)));
_ZN33_INTERNAL_13_edg_prelink_c_optind19free_pl_object_fileEP16a_pl_object_file(__50871_26_last_pofp);
}

{ auto a_pl_file_list_entry_ptr __50888_32_flep;
auto a_pl_file_list_entry_ptr __50889_32_next_flep;
for (__50888_32_flep = (__50865_23_pifp->dependencies); __50888_32_flep != ((a_pl_file_list_entry_ptr)0); __50888_32_flep = __50889_32_next_flep) {
__50889_32_next_flep = (__50888_32_flep->next);
free(((void *)__50888_32_flep));
}
}



if ((__50865_23_pifp->command_line) != ((char *)0)) { free(((void *)(__50865_23_pifp->command_line))); }
if ((__50865_23_pifp->compilation_directory) != ((char *)0)) { free(((void *)(__50865_23_pifp->compilation_directory))); }
if ((__50865_23_pifp->compilation_file_name) != ((char *)0)) { free(((void *)(__50865_23_pifp->compilation_file_name))); }
if ((__50865_23_pifp->secondary_files) != ((char *)0)) { free(((void *)(__50865_23_pifp->secondary_files))); }
if ((__50865_23_pifp->instantiation_directory) != ((char *)0)) {
free(((void *)(__50865_23_pifp->instantiation_directory)));
}
__50865_23_pifp = (__50865_23_pifp->next);
}

__50866_19_psp = pl_symbol_table_head;
while (__50866_19_psp != ((a_pl_symbol_ptr)0)) {
auto a_pl_symbol_ptr __50910_29_last_psp;
auto a_pl_instantiation_site_ptr __50911_33_pisp;
__50911_33_pisp = (__50866_19_psp->possible_instantiation_sites);
while (__50911_33_pisp != ((a_pl_instantiation_site_ptr)0)) {
auto a_pl_instantiation_site_ptr __50914_35_last_pisp;
__50914_35_last_pisp = __50911_33_pisp;
__50911_33_pisp = (__50911_33_pisp->next);
_ZN33_INTERNAL_13_edg_prelink_c_optind26free_pl_instantiation_siteEP23a_pl_instantiation_site(__50914_35_last_pisp);
}
__50910_29_last_psp = __50866_19_psp;
__50866_19_psp = (__50866_19_psp->next_in_symbol_table);
free(((void *)(__50910_29_last_psp->name)));
_ZN33_INTERNAL_13_edg_prelink_c_optind14free_pl_symbolEP11a_pl_symbol(__50910_29_last_psp);
} 
}
# 3685
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_init_temp_stringEv(void)




{
pos_in_temp_string = 0UL; 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc( _ZN3edg12a_const_charE *__50955_49_addition)



{
auto int __50960_7_addition_length;

__50960_7_addition_length = ((int)(strlen(__50955_49_addition)));
if ((pos_in_temp_string + ((unsigned long)__50960_7_addition_length)) >= temp_string_length) {
temp_string_length += 4000UL;
temp_string = ((char *)(_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_realloc_with_checkEPvm(((_ZN3edg10a_void_ptrE)temp_string), temp_string_length)));

}
strcpy((temp_string + pos_in_temp_string), __50955_49_addition);
pos_in_temp_string += ((unsigned long)__50960_7_addition_length); 
}


static void _ZN33_INTERNAL_13_edg_prelink_c_optind25pl_add_two_to_temp_stringEPKcS1_( _ZN3edg12a_const_charE *__50973_53_add1, 
_ZN3edg12a_const_charE *__50974_25_add2)




{
_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(__50973_53_add1);
_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(__50974_25_add2); 
}


static char *_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_find_library_nameEPc( char *__50985_41_lib_name)
# 3734
{


auto char *__50997_17_string_buffer = pl_input_line;
auto _ZN3edg9a_booleanE __50998_13_found = 0;
auto char *__50999_18_result = ((char *)0);
auto int __51000_8_j;

for (__51000_8_j = 0; __51000_8_j < num_of_L_directories; ++__51000_8_j) {
auto FILE *__51003_11_f_lib;
snprintf(__50997_17_string_buffer, 32767UL, ((const char *)"%s/lib%s.a"), (L_directories[__51000_8_j]), __50985_41_lib_name);


if (pl_debug_level >= 3) {
fprintf(stderr, ((const char *)"Looking for %s\n"), __50997_17_string_buffer);
}

if ((__51003_11_f_lib = (fopen(((const char *)__50997_17_string_buffer), ((const char *)"r")))) != ((FILE *)0)) {


__50999_18_result = __50997_17_string_buffer;
__50998_13_found = 1;
fclose(__51003_11_f_lib);
goto __T73258432;
}
} __T73258432:;

if (!(__50998_13_found)) {
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_lib_file_not_found)), __50985_41_lib_name);
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_command_line_error, ((char *)0));
}
return __50999_18_result;
}
# 3777
static void _ZN33_INTERNAL_13_edg_prelink_c_optind19pl_add_cmd_line_argEPcP15a_pl_input_file( char *__51037_41_str, 
a_pl_input_file_ptr __51038_53_pifp)




{
auto a_pl_cmd_line_arg_ptr __51044_25_pclap;
__51044_25_pclap = ((a_pl_cmd_line_arg_ptr)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm(24UL)));

(__51044_25_pclap->is_string) = ((_ZN3edg9a_booleanE)(__51037_41_str != ((char *)0)));
(__51044_25_pclap->next) = ((a_pl_cmd_line_arg_ptr)0);
if (__51044_25_pclap->is_string) {
((__51044_25_pclap->variant).arg_string) = __51037_41_str;
} else  {
((__51044_25_pclap->variant).input_file_entry) = __51038_53_pifp;
}
if (cmd_line_head == ((a_pl_cmd_line_arg_ptr)0)) { cmd_line_head = __51044_25_pclap; }
if (cmd_line_tail != ((a_pl_cmd_line_arg_ptr)0)) { (cmd_line_tail->next) = __51044_25_pclap; }
cmd_line_tail = __51044_25_pclap; 
}


int main( int __51060_14_argc,  char **__51060_26_argv)
{
auto int __51062_17_arg;
auto int __51063_17_return_status = 0;
auto _ZN3edg9a_booleanE __51064_22_done = 0;
auto _ZN3edg9a_booleanE __51065_22_any_template_files = 0;


auto int __51068_17_optchar;
auto long __51069_18_number_of_iterations = 0L;
auto char *__51070_19_nm_command = ((char *)0);
auto a_pl_cmd_line_arg_ptr __51071_26_last_arg_to_reemit = ((a_pl_cmd_line_arg_ptr)0);
auto _ZN3edg9a_booleanE __51072_15_suppress_instantiation_flags = 0;
auto _ZN3edg9a_booleanE __51073_15_list_object_files = 0;


f_informational = stderr;

message_prefix = (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_message_prefix));


memset(((void *)((char *)pl_assignment_table)), 0, 4792UL);




L_directories = ((char **)(_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_malloc_with_checkEm((((unsigned long)__51060_14_argc) * 8UL))));

_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_get_curr_dir_nameEv();



opterr = 0;

while ((__51068_17_optchar = (getopt(__51060_14_argc, ((char *const *)__51060_26_argv), ((const char *)"a:bc:d:ef:il:mno:qrs:vuB:DL:NOR:SW:")))) != (-1)) {
switch (__51068_17_optchar) {
case 97:

if (((strcmp(((const char *)optarg), ((const char *)"0"))) != 0) && ((strcmp(((const char *)optarg), ((const char *)"1"))) != 0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_invalid_definition_list_option, optarg);
}
use_definition_list = ((_ZN3edg9a_booleanE)((atoi(((const char *)optarg))) != 0));
goto __T73294144;
case 98:




__51073_15_list_object_files = 1;
goto __T73294144;
case 99:


__51070_19_nm_command = optarg;
goto __T73294144;
case 68:

do_not_assign_to_nonlocal_objects = 1;
goto __T73294144;
case 101:


suppress_dependency_checking = 1;
goto __T73294144;
case 102:

if ((strcmp(((const char *)optarg), ((const char *)"solaris"))) == 0) {
nm_format = nmfk_solaris;
} else  { if ((strcmp(((const char *)optarg), ((const char *)"SGI"))) == 0) {
nm_format = nmfk_SGI;
ignore_invalid_nm_output = 1;
skip_underscore_prefix = 0;
} else  { if ((strcmp(((const char *)optarg), ((const char *)"SVR4"))) == 0) {
nm_format = nmfk_SVR4;
} else  { if ((strcmp(((const char *)optarg), ((const char *)"HPUX"))) == 0) {
nm_format = nmfk_HPUX;
} else  { if ((strcmp(((const char *)optarg), ((const char *)"CLIX"))) == 0) {
nm_format = nmfk_CLIX;
} else  { if ((strcmp(((const char *)optarg), ((const char *)"gnu"))) == 0) {
nm_format = nmfk_gnu;
} else  { if ((strcmp(((const char *)optarg), ((const char *)"MacOSX"))) == 0) {
nm_format = nmfk_MacOSX;
} else  { if ((strcmp(((const char *)optarg), ((const char *)"MacOSX64"))) == 0) {
nm_format = nmfk_MacOSX64;
} else  {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_invalid_nm_format_option, ((char *)0));
} } } } } } } }
goto __T73294144;
case 105:

ignore_invalid_nm_output = 1;
goto __T73294144;
case 66:



case 108:
# 3902
optind--;
goto __51265_1_end_of_options;
case 76:

(L_directories[(num_of_L_directories++)]) = optarg;
goto __T73294144;
case 111:



{
auto char *__51173_17_obj_file_list_file_name;
__51173_17_obj_file_list_file_name = optarg;
f_obj_file_list = (fopen(((const char *)__51173_17_obj_file_list_file_name), ((const char *)"w")));
if (f_obj_file_list == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_cannot_open_obj_file_list_file, __51173_17_obj_file_list_file_name);

}
}
goto __T73294144;

case 79:

one_instantiation_per_object = 1;
goto __T73294144;

case 87:


if ((strncmp(((const char *)optarg), ((const char *)"l,-L"), 4UL)) != 0) {
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_unrecognized_option)), optarg);
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_command_line_error, ((char *)0));
}
(L_directories[(num_of_L_directories++)]) = (optarg + 4);
goto __T73294144;
case 109:

mangled_names_in_output = 1;
goto __T73294144;
case 110:


suppress_compilation = 1;
goto __T73294144;
case 78:




move_nonlocal_objects_to_curr_dir = 1;
goto __T73294144;
case 114:

limit_recursion = 0;
goto __T73294144;
case 82:


reserved_request_file_lines = (atoi(((const char *)optarg)));
if ((reserved_request_file_lines < 0) || (reserved_request_file_lines > 0))

{
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_invalid_reserved_request_lines_option, optarg);
}
goto __T73294144;
case 115:


check_specialization_errors = ((_ZN3edg9a_booleanE)((atoi(((const char *)optarg))) != 0));
goto __T73294144;
case 83:



__51072_15_suppress_instantiation_flags = 1;
goto __T73294144;
case 117:


skip_underscore_prefix = 1;
goto __T73294144;
case 113:

verbose = 0;
goto __T73294144;
case 118:

verbose = 1;
goto __T73294144;
case 100:


pl_debug_level = (atoi(((const char *)optarg)));
goto __T73294144;

default:
if (optind >= __51060_14_argc) { optind = (__51060_14_argc - 1); }
optarg = (__51060_26_argv[optind]);
fprintf(stderr, (_ZN33_INTERNAL_13_edg_prelink_c_optind13pl_error_textE15a_pl_error_code(pl_ec_unrecognized_option)), optarg);
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_command_line_error, ((char *)0));
goto __T73294144;
} __T73294144:;
}
__51265_1_end_of_options:;
if (((one_instantiation_per_object) || (move_nonlocal_objects_to_curr_dir)) && (f_obj_file_list == ((FILE *)0)))
{


_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_no_object_file_name_specified, ((char *)0));
}

if (__51070_19_nm_command != ((char *)0)) {

} else  { if (((int)nm_format) == 1) {
__51070_19_nm_command = solaris_nm_command;
} else  { if (((int)nm_format) == 2) {
__51070_19_nm_command = SGI_nm_command;
} else  { if (((int)nm_format) == 5) {
__51070_19_nm_command = CLIX_nm_command;
} else  { if ((((int)nm_format) == 3) || (((int)nm_format) == 4))
{
__51070_19_nm_command = alternate_nm_command;
} else  { if (((int)nm_format) == 6) {
__51070_19_nm_command = gnu_nm_command;
} else  {

__51070_19_nm_command = default_nm_command;
} } } } } }

{
# 4037
auto a_pl_input_file_ptr __51297_25_list_tail = ((a_pl_input_file_ptr)0);
for (__51062_17_arg = optind; __51062_17_arg < __51060_14_argc; ++__51062_17_arg) { {
auto a_pl_input_file_ptr __51299_27_pifp;
auto char *__51300_34_orig_name;
auto char *__51301_34_file_name;
__51300_34_orig_name = (__51060_26_argv[__51062_17_arg]);
if ((strcmp(((const char *)__51300_34_orig_name), ((const char *)"--"))) == 0) {



__51071_26_last_arg_to_reemit = cmd_line_tail;
goto __T73379544;
}
if ((strncmp(((const char *)__51300_34_orig_name), ((const char *)"-B"), 2UL)) == 0) {

_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_add_cmd_line_argEPcP15a_pl_input_file(__51300_34_orig_name, ((a_pl_input_file_ptr)0));
goto __T73379544;
} else  { if ((strncmp(((const char *)__51300_34_orig_name), ((const char *)"-l"), 2UL)) == 0) {

auto char *__51316_16_lib_name; __51316_16_lib_name = (__51300_34_orig_name + 2);
__51301_34_file_name = (_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_find_library_nameEPc(__51316_16_lib_name));
} else  {
__51301_34_file_name = __51300_34_orig_name;
} }
__51299_27_pifp = (_ZN33_INTERNAL_13_edg_prelink_c_optind19alloc_pl_input_fileEv());
(__51299_27_pifp->file_name) = (_ZN33_INTERNAL_13_edg_prelink_c_optind14pl_copy_stringEPKc(((_ZN3edg12a_const_charE *)__51301_34_file_name)));

if (pl_input_files == ((a_pl_input_file_ptr)0)) { pl_input_files = __51299_27_pifp; }
_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_add_cmd_line_argEPcP15a_pl_input_file(((char *)0), __51299_27_pifp);
if (__51297_25_list_tail != ((a_pl_input_file_ptr)0)) { (__51297_25_list_tail->next) = __51299_27_pifp; }
__51297_25_list_tail = __51299_27_pifp;
__51065_22_any_template_files |= (_ZN33_INTERNAL_13_edg_prelink_c_optind26pl_check_for_template_fileEP15a_pl_input_file(__51299_27_pifp));
} __T73379544:; }
}

if (__51065_22_any_template_files) {
do {
auto a_pl_input_file_ptr __51334_27_pifp;
auto _ZN3edg9a_booleanE __51335_19_no_local_changes;
auto _ZN3edg9a_booleanE __51336_19_no_nonlocal_changes;
auto int __51337_13_nm_status;



for (__51334_27_pifp = pl_input_files; __51334_27_pifp != ((a_pl_input_file_ptr)0); __51334_27_pifp = (__51334_27_pifp->next)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind19reset_pl_input_fileEP15a_pl_input_file(__51334_27_pifp);
}

pl_symbol_table_head = ((a_pl_symbol_ptr)0);
specialization_list = ((a_pl_symbol_ptr)0);
memset(((void *)((char *)pl_symbol_table)), 0, 80056UL);


_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_init_temp_stringEv();
_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(((_ZN3edg12a_const_charE *)__51070_19_nm_command));

for (__51334_27_pifp = pl_input_files; __51334_27_pifp != ((a_pl_input_file_ptr)0); __51334_27_pifp = (__51334_27_pifp->next)) {
auto a_pl_object_file_ptr __51354_30_pofp;
_ZN33_INTERNAL_13_edg_prelink_c_optind25pl_add_two_to_temp_stringEPKcS1_(((const char *)" "), ((_ZN3edg12a_const_charE *)(__51334_27_pifp->file_name)));
if (use_template_info_file) {
_ZN33_INTERNAL_13_edg_prelink_c_optind26pl_read_template_info_fileEP15a_pl_input_file(__51334_27_pifp);
}
if (one_instantiation_per_object) {

for (__51354_30_pofp = (__51334_27_pifp->objects); __51354_30_pofp != ((a_pl_object_file_ptr)0); __51354_30_pofp = (__51354_30_pofp->next)) {
if (__51354_30_pofp->is_related_file) {


_ZN33_INTERNAL_13_edg_prelink_c_optind25pl_add_two_to_temp_stringEPKcS1_(((const char *)" "), ((_ZN3edg12a_const_charE *)(__51354_30_pofp->file_name)));
}
}
}
}
_ZN33_INTERNAL_13_edg_prelink_c_optind21pl_add_to_temp_stringEPKc(((_ZN3edg12a_const_charE *)nm_command_suffix));

if (pl_debug_level >= 2) { fprintf(stderr, ((const char *)"%s\n"), temp_string); }


if (!(__51073_15_list_object_files)) {

f_command_output = (popen(((const char *)temp_string), ((const char *)"r")));
if (f_command_output == ((FILE *)0)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_popen_failed, ((char *)0));
}

_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_read_nm_outputEv();
__51337_13_nm_status = (pclose(f_command_output));
if (__51337_13_nm_status != 0) {

_ZN33_INTERNAL_13_edg_prelink_c_optind10pl_warningE15a_pl_error_codePc(pl_ec_nm_returned_error, ((char *)0));
}


_ZN33_INTERNAL_13_edg_prelink_c_optind35pl_read_instantiation_request_filesEv();


if (pl_debug_level >= 4) {
_ZN33_INTERNAL_13_edg_prelink_c_optind17pl_db_input_filesEv();
}



_ZN33_INTERNAL_13_edg_prelink_c_optind23pl_add_predefined_namesEv();

_ZN33_INTERNAL_13_edg_prelink_c_optind10pl_prelinkEv();


if (pl_debug_level >= 4) {
_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_db_global_symbolsEi(0);
}
# 4152
__51335_19_no_local_changes = (_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_determine_actionsEi(1));




if ((do_not_assign_to_nonlocal_objects) || ((use_definition_list) && (!(__51335_19_no_local_changes))))
{

__51336_19_no_nonlocal_changes = 1;
} else  {
__51336_19_no_nonlocal_changes = (_ZN33_INTERNAL_13_edg_prelink_c_optind20pl_determine_actionsEi(0));
}
__51064_22_done = ((_ZN3edg9a_booleanE)((__51335_19_no_local_changes) && (__51336_19_no_nonlocal_changes)));


__51063_17_return_status = (_ZN33_INTERNAL_13_edg_prelink_c_optind23pl_update_request_filesEv());
if ((limit_recursion) && ((++__51069_18_number_of_iterations) == 300L)) {
_ZN33_INTERNAL_13_edg_prelink_c_optind8pl_errorE15a_pl_error_codePc(pl_ec_instantiation_loop, ((char *)0));
}


if (check_specialization_errors) {
if (_ZN33_INTERNAL_13_edg_prelink_c_optind34pl_check_for_specialization_errorsEv()) {


if (__51063_17_return_status == 0) { __51063_17_return_status = 1; }
}
}
if ((__51063_17_return_status != 0) || (suppress_compilation)) { __51064_22_done = 1; }
} else  {

__51064_22_done = 1;
}
if (!(__51064_22_done)) { _ZN33_INTERNAL_13_edg_prelink_c_optind11pl_free_allEv(); }
} while (!(__51064_22_done));
}
if (__51072_15_suppress_instantiation_flags) {


_ZN33_INTERNAL_13_edg_prelink_c_optind29pl_remove_instantiation_flagsEv();
}
if (f_obj_file_list != ((FILE *)0)) {
# 4199
auto a_pl_cmd_line_arg_ptr __51459_27_pclap;
for (__51459_27_pclap = cmd_line_head; __51459_27_pclap != ((a_pl_cmd_line_arg_ptr)0); __51459_27_pclap = (__51459_27_pclap->next)) {
if (__51459_27_pclap->is_string) {
fprintf(f_obj_file_list, ((const char *)" %s"), ((__51459_27_pclap->variant).arg_string));
} else  {
auto a_pl_object_file_ptr __51464_30_pofp;
fprintf(f_obj_file_list, ((const char *)" %s"), (((__51459_27_pclap->variant).input_file_entry)->file_name));



for (__51464_30_pofp = (((__51459_27_pclap->variant).input_file_entry)->objects); __51464_30_pofp != ((a_pl_object_file_ptr)0); __51464_30_pofp = (__51464_30_pofp->next))
{
if (!(__51464_30_pofp->is_related_file)) { goto __T73510936; }
fprintf(f_obj_file_list, ((const char *)" %s"), (__51464_30_pofp->file_name)); __T73510936:;
}
}
if (__51459_27_pclap == __51071_26_last_arg_to_reemit) { goto __T73512832; }
} __T73512832:;
fprintf(f_obj_file_list, ((const char *)"\n"));
fclose(f_obj_file_list);
}
# 4228
return __51063_17_return_status;
}
# 4193 "src/util.h"
 __attribute__((__weak__)) /* COMDAT group: _ZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_ */ int _ZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_( char *__44857_40_dest_buff, 
size_t __44858_39_dest_buff_size, 
_ZN3edg12a_const_charE *__44859_40_format_str, 
unsigned long __1_44860_42_args)
# 4205
{




auto int __44874_7_result;
# 4206
((__44857_40_dest_buff != ((char *)0)) && (__44858_39_dest_buff_size > 0UL)) ? ((void)0) : (_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_(((const char *)_ZZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_Es), 4206, ((const char *)
# 4206
_ZZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_Es_0), ((const char *)_ZZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_Es_0)));



__44874_7_result = (snprintf(__44857_40_dest_buff, __44858_39_dest_buff_size, __44859_40_format_str, __1_44860_42_args));

if ((__44874_7_result >= 0) && (((size_t)__44874_7_result) >= __44858_39_dest_buff_size)) {



__44874_7_result = (-1);
}
return __44874_7_result;

}
# 22 "src/host_util.h"
unsigned long _ZN3edg6crc_32EPKcm( _ZN3edg12a_const_charE *__47606_36_str, 
unsigned long __47607_22_prev_crc)
# 33
{
auto unsigned long __47618_17_crc;



__47618_17_crc = (__47607_22_prev_crc ^ 4294967295UL);
while (((int)(*__47606_36_str)) != 0) {
auto unsigned long __47624_19_ch;
auto int __47625_9_nbit;
# 40
__47624_19_ch = ((unsigned long)((unsigned char)(*(__47606_36_str++))));


for (__47625_9_nbit = 0; __47625_9_nbit < 8; (__47625_9_nbit++) , (__47624_19_ch >>= 1)) {
auto int __47628_11_low_bit; __47628_11_low_bit = ((int)((__47624_19_ch ^ __47618_17_crc) & 1UL));
__47618_17_crc >>= 1;
if (__47628_11_low_bit) { __47618_17_crc ^= 3988292384UL; }
}
}
__47618_17_crc ^= 4294967295UL;
return __47618_17_crc;
}



_ZN3edg12a_const_charE *_ZN3edg39generate_instantiation_output_file_nameEPKc(
_ZN3edg12a_const_charE *__47640_67_mangled_name)
# 63
{


auto long long __47650_22_max_len_without_suffix;
# 83
auto unsigned long __47667_17_crc_value;
auto size_t __47668_17_used_buffer_len;
auto size_t __47669_17_remaining_buffer_len;


auto int __47672_17_chars_written __attribute__((__unused__));
# 73
__47650_22_max_len_without_suffix = 23LL;

__47650_22_max_len_without_suffix -= 7LL;



(__47650_22_max_len_without_suffix > 0LL) ? ((void)0) : (_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_(((const char *)"src/host_util.h"), 79, ((const char *)""), ((const char *)"")));
strncpy(_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer, __47640_67_mangled_name, ((size_t)__47650_22_max_len_without_suffix));
((_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer)[__47650_22_max_len_without_suffix]) = ((char)0);

__47667_17_crc_value = (_ZN3edg6crc_32EPKcm(__47640_67_mangled_name, 0UL));
__47668_17_used_buffer_len = (strlen(((const char *)_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer)));
__47669_17_remaining_buffer_len = (32UL - __47668_17_used_buffer_len);


__47672_17_chars_written = (_ZN3edg6detail13snprintf_implIJmEEEiPcmPKcDpT_((_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer + __47668_17_used_buffer_len), __47669_17_remaining_buffer_len, ((const char *)"_%08lx"), __47667_17_crc_value));



(__47672_17_chars_written > 0) ? ((void)0) : (_ZN33_INTERNAL_13_edg_prelink_c_optind19pl_assertion_failedEPKciS1_S1_(((const char *)"src/host_util.h"), 92, ((const char *)""), ((const char *)"")));

return (_ZN3edg12a_const_charE *)(_ZZN3edg39generate_instantiation_output_file_nameEPKcE6buffer);
}
# 223
_ZN3edg9a_booleanE _ZN3edg26get_file_modification_timeEPKcPl( _ZN3edg12a_const_charE *__47807_52_file_name, 
time_t *__47808_52_p_time)




{
auto _ZN3edg9a_booleanE __47814_13_is_regular = 0;
# 254
{


auto struct stat __47841_17_buf;
# 266
if ((stat(__47807_52_file_name, (&__47841_17_buf))) == 0) {



__47814_13_is_regular = ((_ZN3edg9a_booleanE)(((__47841_17_buf.st_mode) & 61440U) == 32768U));



if ((__47814_13_is_regular) && (__47808_52_p_time != ((time_t *)0))) { (*__47808_52_p_time) = ((__47841_17_buf.st_mtim).tv_sec); }
} else  {

if (__47808_52_p_time != ((time_t *)0)) { (*__47808_52_p_time) = 0L; }
}
}
return __47814_13_is_regular;
}
